#!/usr/bin/env python3
"""Editable Pokemon Snap demo recordings, serialized in native big-endian order.

The 16-byte header contains dataSize (u32), the reserved word at 0x04
(u32), randSeed (s32), and playerFlags (u32). Each input is the native
ControllerInput: four u16 button masks, then signed stickX and stickY bytes.
YAML field names follow include/sys/cont.h; header.reserved preserves unk_04.

The physical input count is independent of header.dataSize. In particular,
the original tunnel segment ends with only the first three button masks of
another input. partialInput represents this native record prefix, not a
complete fabricated frame or an opaque payload. If a prefix ends halfway
through a u16 mask, its value is {"highByte": N}. Neither encoder nor decoder
repairs the header, completes a partial input, or adds alignment padding.
"""

import argparse
import struct
from pathlib import Path

import yaml


HEADER = struct.Struct(">IIiI")
INPUT = struct.Struct(">HHHHbb")
INPUT_FIELDS = (
    ("buttons", ">H"),
    ("pressedButtons", ">H"),
    ("heldButtons", ">H"),
    ("releasedButtons", ">H"),
    ("stickX", ">b"),
    ("stickY", ">b"),
)


def decode(data: bytes) -> dict:
    """Decode all physical native fields without interpreting dataSize as length."""
    data_size, reserved, rand_seed, player_flags = HEADER.unpack_from(data)
    spec = {
        "header": {
            "dataSize": data_size,
            "reserved": reserved,
            "randSeed": rand_seed,
            "playerFlags": player_flags,
        },
        "inputs": [],
    }
    complete_end = HEADER.size + (len(data) - HEADER.size) // INPUT.size * INPUT.size
    for offset in range(HEADER.size, complete_end, INPUT.size):
        values = INPUT.unpack_from(data, offset)
        spec["inputs"].append(
            {name: value for (name, _), value in zip(INPUT_FIELDS, values)}
        )

    if complete_end < len(data):
        partial = {}
        offset = complete_end
        for name, fmt in INPUT_FIELDS:
            if offset == len(data):
                break
            size = struct.calcsize(fmt)
            if len(data) - offset < size:
                partial[name] = {"highByte": data[offset]}
                break
            partial[name] = struct.unpack_from(fmt, data, offset)[0]
            offset += size
        spec["partialInput"] = partial
    return spec


def _encode_partial(partial: dict) -> bytes:
    """Serialize only a contiguous, incomplete prefix of a ControllerInput."""
    result = bytearray()
    remaining = set(partial)
    for name, fmt in INPUT_FIELDS:
        if name not in partial:
            break
        remaining.remove(name)
        value = partial[name]
        if isinstance(value, dict):
            if fmt != ">H" or set(value) != {"highByte"}:
                raise ValueError(f"{name}: only a u16 highByte may be incomplete")
            result.extend(struct.pack(">B", value["highByte"]))
            break
        result.extend(struct.pack(fmt, value))
    if remaining or not 0 < len(result) < INPUT.size:
        raise ValueError("partialInput must be a nonempty, incomplete native record prefix")
    return bytes(result)


def encode(spec: dict) -> bytes:
    """Serialize header and ordered inputs exactly, preserving the native size quirk."""
    header = spec["header"]
    result = bytearray(
        HEADER.pack(
            header["dataSize"],
            header["reserved"],
            header["randSeed"],
            header["playerFlags"],
        )
    )
    for record in spec["inputs"]:
        result.extend(INPUT.pack(*(record[name] for name, _ in INPUT_FIELDS)))
    if "partialInput" in spec:
        result.extend(_encode_partial(spec["partialInput"]))
    return bytes(result)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    extract = commands.add_parser("extract", help="decode a native recording into editable YAML")
    extract.add_argument("input", type=Path)
    extract.add_argument("output_yaml", type=Path)
    build = commands.add_parser("build", help="encode YAML into a native recording")
    build.add_argument("input_yaml", type=Path)
    build.add_argument("output_bin", type=Path)
    args = parser.parse_args()

    if args.command == "extract":
        spec = decode(args.input.read_bytes())
        args.output_yaml.parent.mkdir(parents=True, exist_ok=True)
        args.output_yaml.write_text(yaml.safe_dump(spec, sort_keys=False), encoding="utf-8")
    else:
        spec = yaml.safe_load(args.input_yaml.read_text(encoding="utf-8"))
        args.output_bin.parent.mkdir(parents=True, exist_ok=True)
        args.output_bin.write_bytes(encode(spec))


if __name__ == "__main__":
    main()
