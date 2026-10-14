#!/usr/bin/env python3
"""Editable particle-script banks for src/app_render/effect.c.

A bank contains a signed big-endian count and bank-relative u32 script pointers.
``script_table`` names preserve table order and aliases; ``scripts`` describes
unique records in physical order, with their original bank-relative offsets.
Each record has the 48-byte EffectScript header and semantic ``commands``.
``table_padding`` and each record's ``padding`` contain fill runs (value/length),
not executable bytecode. Record padding starts after the first FE/FF terminal;
its nonzero alignment bytes are intentionally retained, not normalized.

Vector/color dictionaries name components in native x/y/z or r/g/b/a order.
Masked commands emit only named components, including an empty mask. Waits use
0..8191 frames, an optional data_id, and explicit compact/extended encoding.
Interpolation lengths use {frames: 1..32768, encoding: compact|extended}; the
serialized value is frames - 1. Extended encodings remain extended even when
compact would suffice. begin_loop count is the serialized u8 (zero wraps to
256 iterations). attach_dobj slot is the serialized one-based byte minus one.
set_return records the next instruction; restart jumps to that saved position
(initially bytecode offset zero), independently of the counted-loop position.

Finite float32 values are JSON numbers (including -0.0). Infinity is represented
as {infinity: 1|-1}; NaNs use {nan: {negative: bool, fraction: 1..0x7fffff}},
preserving the IEEE-754 sign and quiet/signaling payload without float conversion.
The interpreter ignores reserved opcodes E0..F9; reserved_noop explicitly names
that behavior and its one-byte reserved_opcode. There is no raw-command escape.

Usage: effect_scripts.py extract INPUT OUTPUT_JSON
       effect_scripts.py build INPUT_JSON OUTPUT_BIN
"""

from __future__ import annotations

import argparse
import json
import math
import struct
from pathlib import Path

FORMAT = "snap_effect_scripts"
VERSION = 1
HEADER_SIZE = 0x30
AXES = ("x", "y", "z")
CHANNELS = ("r", "g", "b", "a")

# All operand-bearing and flag-only cases of fx_updateStruct:513-737. The
# component-mask families, waits, and FA..FF control flow are handled below.
_FIXED_COMMANDS = {
    0xA0: ("interpolate_size", (("length", "length"), ("target", "float"))),
    0xA1: ("set_flags", (("flags", "u8"),)),
    0xA2: ("set_gravity", (("value", "float"),)),
    0xA3: ("set_friction", (("value", "float"),)),
    0xA4: ("spawn_particle", (("script_id", "u16"),)),
    0xA5: ("spawn_effect", (("script_id", "u16"),)),
    0xA6: ("random_lifetime", (("base", "u16"), ("range", "u16"))),
    0xA7: ("random_terminate", (("probability", "u8"),)),
    0xA8: ("random_add_position", (("ranges", "vector"),)),
    0xA9: ("rotate_velocity", (("angle", "float"),)),
    0xAA: ("random_spawn_particle", (("script_id", "u16"), ("range", "u16"))),
    0xAB: ("scale_velocity", (("factor", "float"),)),
    0xAC: ("random_interpolate_size", (("length", "length"), ("target", "float"), ("range", "float"))),
    0xAD: ("enable_env_combine", ()),
    0xAE: ("clear_mirroring", ()),
    0xAF: ("mirror_s", ()),
    0xB0: ("mirror_t", ()),
    0xB1: ("mirror_st", ()),
    0xB2: ("enable_env_alpha_threshold", ()),
    0xB3: ("disable_alpha_dither", ()),
    0xB4: ("enable_alpha_dither", ()),
    0xB5: ("enable_noise_combine", ()),
    0xB6: ("disable_noise_combine", ()),
    0xB7: ("aim_velocity_at_dobj", (("dobj_id", "u8"),)),
    0xB8: ("add_velocity_toward_dobj", (("dobj_id", "u8"), ("magnitude", "float"))),
    0xB9: ("spawn_particle_with_velocity", (("script_id", "u16"),)),
    0xBA: ("random_add_prim_color", (("ranges", "color"),)),
    0xBB: ("random_add_env_color", (("ranges", "color"),)),
    0xBC: ("random_data_id", (("base", "u8"), ("range", "u8"))),
    0xBD: ("random_velocity_magnitude", (("base", "float"), ("range", "float"))),
    0xBE: ("scale_velocity_components", (("factors", "vector"),)),
    0xBF: ("attach_dobj", (("slot", "slot"),)),
    0xFA: ("begin_loop", (("count", "u8"),)),
    0xFB: ("end_loop", ()),
    0xFC: ("set_return", ()),
    0xFD: ("restart", ()),
}
_FIXED_BY_NAME = {name: (opcode, fields) for opcode, (name, fields) in _FIXED_COMMANDS.items()}
_VECTOR_COMMANDS = {
    0x80: "set_position",
    0x88: "add_position",
    0x90: "set_velocity",
    0x98: "add_velocity",
}
_VECTOR_BY_NAME = {name: opcode for opcode, name in _VECTOR_COMMANDS.items()}
_COLOR_COMMANDS = {0xC0: "interpolate_prim_color", 0xD0: "interpolate_env_color"}
_COLOR_BY_NAME = {name: opcode for opcode, name in _COLOR_COMMANDS.items()}
_HEADER_FIELDS = (
    ("kind", "u16"),
    ("texture_id", "u16"),
    ("effect_lifetime", "u16"),
    ("particle_lifetime", "u16"),
    ("flags", "u32"),
    ("gravity", "float"),
    ("friction", "float"),
    ("velocity", "vector"),
    ("emit_radius", "float"),
    ("emit_angle", "float"),
    ("emit_rate", "float"),
    ("size", "float"),
)


def _integer(value: object, minimum: int, maximum: int, field: str) -> int:
    if type(value) is not int or not minimum <= value <= maximum:
        raise ValueError(f"{field} must be an integer in {minimum}..{maximum}")
    return value


class _Reader:
    def __init__(self, data: bytes, start: int, end: int):
        self.data = data
        self.pos = start
        self.end = end

    def take(self, size: int) -> bytes:
        end = self.pos + size
        if end > self.end:
            raise ValueError(f"Truncated script field at bank offset 0x{self.pos:X}")
        result = self.data[self.pos:end]
        self.pos = end
        return result

    def uint(self, size: int) -> int:
        return int.from_bytes(self.take(size), "big")

    def float(self) -> object:
        data = self.take(4)
        bits = int.from_bytes(data, "big")
        if bits & 0x7F800000 == 0x7F800000:
            fraction = bits & 0x7FFFFF
            if fraction:
                return {"nan": {"negative": bool(bits >> 31), "fraction": fraction}}
            return {"infinity": -1 if bits >> 31 else 1}
        return struct.unpack(">f", data)[0]

    def length(self) -> dict:
        value = self.uint(1)
        encoding = "compact"
        if value & 0x80:
            value = ((value & 0x7F) << 8) | self.uint(1)
            encoding = "extended"
        return {"frames": value + 1, "encoding": encoding}

    def field(self, kind: str) -> object:
        if kind in ("u8", "u16", "u32"):
            return self.uint({"u8": 1, "u16": 2, "u32": 4}[kind])
        if kind == "float":
            return self.float()
        if kind == "length":
            return self.length()
        if kind == "vector":
            return {axis: self.float() for axis in AXES}
        if kind == "color":
            return {channel: self.uint(1) for channel in CHANNELS}
        if kind == "slot":
            return self.uint(1) - 1
        raise ValueError(f"Unknown field grammar {kind!r}")


def _encode_float(value: object) -> bytes:
    if isinstance(value, dict):
        if set(value) == {"infinity"}:
            sign = _integer(value["infinity"], -1, 1, "infinity sign")
            if sign == 0:
                raise ValueError("infinity sign must be -1 or 1")
            return (0xFF800000 if sign < 0 else 0x7F800000).to_bytes(4, "big")
        if set(value) == {"nan"}:
            nan = value["nan"]
            if not isinstance(nan, dict) or set(nan) != {"negative", "fraction"}:
                raise ValueError("nan requires negative and fraction fields")
            if type(nan["negative"]) is not bool:
                raise ValueError("nan negative must be a boolean")
            fraction = _integer(nan["fraction"], 1, 0x7FFFFF, "nan fraction")
            bits = (int(nan["negative"]) << 31) | 0x7F800000 | fraction
            return bits.to_bytes(4, "big")
        raise ValueError("Float objects must describe IEEE-754 infinity or nan")
    if type(value) not in (int, float) or not math.isfinite(value):
        raise ValueError("Float fields require finite numbers or explicit infinity/nan objects")
    return struct.pack(">f", value)


def _encode_length(spec: dict) -> bytes:
    frames = _integer(spec["frames"], 1, 32768, "interpolation frames")
    value = frames - 1
    encoding = spec["encoding"]
    if encoding == "compact":
        if value > 0x7F:
            raise ValueError("Compact interpolation length exceeds 128 frames")
        return bytes([value])
    if encoding == "extended":
        return (0x8000 | value).to_bytes(2, "big")
    raise ValueError(f"Unknown interpolation encoding {encoding!r}")


def _components(values: dict, names: tuple[str, ...], masked: bool) -> None:
    if not isinstance(values, dict) or set(values) - set(names):
        raise ValueError(f"Components must be a dictionary using {', '.join(names)}")
    if not masked and set(values) != set(names):
        raise ValueError(f"All {', '.join(names)} components are required")


def _encode_field(kind: str, value: object) -> bytes:
    if kind in ("u8", "u16", "u32"):
        size = {"u8": 1, "u16": 2, "u32": 4}[kind]
        return _integer(value, 0, (1 << (size * 8)) - 1, kind).to_bytes(size, "big")
    if kind == "float":
        return _encode_float(value)
    if kind == "length":
        return _encode_length(value)
    if kind == "vector":
        _components(value, AXES, masked=False)
        return b"".join(_encode_float(value[axis]) for axis in AXES)
    if kind == "color":
        _components(value, CHANNELS, masked=False)
        return bytes(_integer(value[channel], 0, 255, channel) for channel in CHANNELS)
    if kind == "slot":
        return bytes([_integer(value, -1, 254, "attachment slot") + 1])
    raise ValueError(f"Unknown field grammar {kind!r}")


def _decode_command(reader: _Reader) -> dict:
    opcode = reader.uint(1)
    if opcode < 0x80:
        frames = opcode & 0x1F
        encoding = "compact"
        if opcode & 0x20:
            frames = (frames << 8) | reader.uint(1)
            encoding = "extended"
        command = {"op": "wait", "frames": frames, "encoding": encoding}
        if opcode & 0x40:
            command["data_id"] = reader.uint(1)
        return command
    if opcode < 0xA0:
        return {
            "op": _VECTOR_COMMANDS[opcode & 0xF8],
            "components": {axis: reader.float() for bit, axis in enumerate(AXES) if opcode & (1 << bit)},
        }
    if 0xC0 <= opcode < 0xE0:
        return {
            "op": _COLOR_COMMANDS[opcode & 0xF0],
            "length": reader.length(),
            "components": {channel: reader.uint(1) for bit, channel in enumerate(CHANNELS) if opcode & (1 << bit)},
        }
    if opcode in _FIXED_COMMANDS:
        name, fields = _FIXED_COMMANDS[opcode]
        return {"op": name, **{name: reader.field(kind) for name, kind in fields}}
    if 0xE0 <= opcode <= 0xF9:
        # No switch case: sp94 stays zero, and the runtime continues immediately.
        return {"op": "reserved_noop", "reserved_opcode": opcode}
    if opcode in (0xFE, 0xFF):
        return {"op": "terminate", "encoding": "fe" if opcode == 0xFE else "ff"}
    raise ValueError(f"Unknown script opcode 0x{opcode:02X}")


def _encode_command(command: dict) -> bytes:
    name = command["op"]
    if name == "wait":
        frames = _integer(command["frames"], 0, 8191, "wait frames")
        encoding = command["encoding"]
        if encoding == "compact":
            if frames > 31:
                raise ValueError("Compact wait exceeds 31 frames")
            encoded = bytearray([frames])
        elif encoding == "extended":
            encoded = bytearray([0x20 | (frames >> 8), frames & 0xFF])
        else:
            raise ValueError(f"Unknown wait encoding {encoding!r}")
        if "data_id" in command:
            encoded[0] |= 0x40
            encoded.append(_integer(command["data_id"], 0, 255, "wait data_id"))
        return bytes(encoded)
    if name in _VECTOR_BY_NAME:
        values = command["components"]
        _components(values, AXES, masked=True)
        mask = sum(1 << bit for bit, axis in enumerate(AXES) if axis in values)
        return bytes([_VECTOR_BY_NAME[name] | mask]) + b"".join(
            _encode_float(values[axis]) for axis in AXES if axis in values
        )
    if name in _COLOR_BY_NAME:
        values = command["components"]
        _components(values, CHANNELS, masked=True)
        mask = sum(1 << bit for bit, channel in enumerate(CHANNELS) if channel in values)
        return bytes([_COLOR_BY_NAME[name] | mask]) + _encode_length(command["length"]) + bytes(
            _integer(values[channel], 0, 255, channel) for channel in CHANNELS if channel in values
        )
    if name in _FIXED_BY_NAME:
        opcode, fields = _FIXED_BY_NAME[name]
        return bytes([opcode]) + b"".join(_encode_field(kind, command[field]) for field, kind in fields)
    if name == "reserved_noop":
        return bytes([_integer(command["reserved_opcode"], 0xE0, 0xF9, "reserved opcode")])
    if name == "terminate":
        if command["encoding"] not in ("fe", "ff"):
            raise ValueError("Termination encoding must be fe or ff")
        return bytes([0xFE if command["encoding"] == "fe" else 0xFF])
    raise ValueError(f"Unknown script command {name!r}")


def _decode_padding(data: bytes) -> list[dict]:
    runs = []
    for value in data:
        if runs and runs[-1]["value"] == value:
            runs[-1]["length"] += 1
        else:
            runs.append({"value": value, "length": 1})
    return runs


def _encode_padding(runs: list[dict], maximum: int) -> bytes:
    result = bytearray()
    for run in runs:
        value = _integer(run["value"], 0, 255, "padding fill value")
        length = _integer(run["length"], 1, maximum - len(result), "padding fill length")
        result.extend(bytes([value]) * length)
    return bytes(result)


def decode(data: bytes) -> dict:
    """Decode every bank record, alias, command operand, and alignment byte."""
    if len(data) < 4:
        raise ValueError("Script bank is missing its count")
    count = struct.unpack_from(">i", data)[0]
    if count < 0 or count > (len(data) - 4) // 4:
        raise ValueError("Script count exceeds the bank-relative pointer table")
    table_end = 4 + 4 * count
    table_reader = _Reader(data, 4, table_end)
    pointers = [table_reader.uint(4) for _ in range(count)]
    offsets = sorted(set(pointers))
    names = {offset: f"script_{index}" for index, offset in enumerate(offsets)}
    for offset in offsets:
        if offset < table_end or offset + HEADER_SIZE > len(data):
            raise ValueError(f"Script pointer 0x{offset:X} does not address a complete header")
    scripts = []
    for offset, end in zip(offsets, offsets[1:] + [len(data)]):
        if offset + HEADER_SIZE > end:
            raise ValueError(f"Overlapping EffectScript headers at offset 0x{offset:X}")
        reader = _Reader(data, offset, end)
        header = {name: reader.field(kind) for name, kind in _HEADER_FIELDS}
        commands = []
        while reader.pos < end:
            command = _decode_command(reader)
            commands.append(command)
            if command["op"] == "terminate":
                break
        scripts.append({
            "name": names[offset],
            "offset": offset,
            "header": header,
            "commands": commands,
            "padding": _decode_padding(data[reader.pos:end]),
        })
    first_offset = offsets[0] if offsets else len(data)
    return {
        "format": FORMAT,
        "version": VERSION,
        "size": len(data),
        "script_table": [names[offset] for offset in pointers],
        "table_padding": _decode_padding(data[table_end:first_offset]),
        "scripts": scripts,
    }


def encode(spec: dict) -> bytes:
    """Build from semantic source alone; no ROM or reference asset is consulted."""
    if spec["format"] != FORMAT or spec["version"] != VERSION:
        raise ValueError("Unsupported effect script source format/version")
    size = _integer(spec["size"], 4, 0xFFFFFFFF, "bank size")
    scripts = spec["scripts"]
    table = spec["script_table"]
    count = _integer(len(table), 0, 0x7FFFFFFF, "script count")
    records = {}
    previous_offset = -1
    for script in scripts:
        name = script["name"]
        if not isinstance(name, str) or not name or name in records:
            raise ValueError("Script names must be unique nonempty strings")
        offset = _integer(script["offset"], 0, size, "script offset")
        if offset <= previous_offset:
            raise ValueError("Scripts must be listed in physical offset order")
        previous_offset = offset
        records[name] = script
    if set(table) != set(records):
        raise ValueError("The table must reference all and only the declared scripts")
    result = bytearray(struct.pack(">i", count))
    for name in table:
        result.extend(_encode_field("u32", records[name]["offset"]))
    if len(result) > size:
        raise ValueError("Script pointer table exceeds bank size")
    result.extend(_encode_padding(spec["table_padding"], size - len(result)))
    for script in scripts:
        if len(result) != script["offset"]:
            raise ValueError(f"Padding/previous script does not end at {script['name']}'s offset")
        header = script["header"]
        result.extend(b"".join(_encode_field(kind, header[name]) for name, kind in _HEADER_FIELDS))
        terminated = False
        for command in script["commands"]:
            if terminated:
                raise ValueError("Commands after a terminal belong to non-executable record padding")
            result.extend(_encode_command(command))
            terminated = command["op"] == "terminate"
        if script["padding"] and not terminated:
            raise ValueError("Record padding requires a preceding terminal command")
        if len(result) > size:
            raise ValueError(f"Script {script['name']} exceeds bank size")
        result.extend(_encode_padding(script["padding"], size - len(result)))
    if len(result) != size:
        raise ValueError(f"Declared bank size is {size}, but source describes {len(result)} bytes")
    return bytes(result)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    for name, help_text in (("extract", "Decode a bank into editable JSON"), ("build", "Encode JSON into a native bank")):
        command = commands.add_parser(name, help=help_text)
        command.add_argument("input", type=Path)
        command.add_argument("output", type=Path)
    args = parser.parse_args()
    try:
        if args.command == "extract":
            spec = decode(args.input.read_bytes())
            content = json.dumps(spec, indent=2, allow_nan=False) + "\n"
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_text(content, encoding="utf-8")
        else:
            spec = json.loads(args.input.read_text(encoding="utf-8"))
            data = encode(spec)
            args.output.parent.mkdir(parents=True, exist_ok=True)
            args.output.write_bytes(data)
    except (OSError, ValueError, KeyError, TypeError, OverflowError, struct.error) as error:
        parser.exit(1, f"{args.command}: {error}\n")


if __name__ == "__main__":
    main()
