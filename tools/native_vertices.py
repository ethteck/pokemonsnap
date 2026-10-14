"""Extract SDK Vtx initializer bodies from the original big-endian N64 ROM.

The recipe contains locations and declarations only. Each 16-byte vertex uses
signed position/texture halfwords, an unsigned flag, and four unsigned bytes;
using the SDK's color member also preserves normal bytes without sign conversion.
"""

import argparse
import json
import struct
from pathlib import Path

from vpk0_codec import decompress_vpk0


VERTEX = struct.Struct(">hhhHhhBBBB")


def vertex_initializers(data: bytes, offset: int, count: int) -> str:
    if offset < 0 or count < 0 or offset + count * VERTEX.size > len(data):
        raise ValueError("vertex range exceeds input container")
    lines = []
    for index in range(count):
        x, y, z, flag, s, t, r, g, b, a = VERTEX.unpack_from(
            data, offset + index * VERTEX.size
        )
        lines.append(
            f"    {{ {{ {{ {x}, {y}, {z} }}, {flag}, "
            f"{{ {s}, {t} }}, {{ {r}, {g}, {b}, {a} }} }} }},"
        )
    return "\n".join(lines) + "\n"


def extract(rom: bytes, layout: dict, output_root: Path) -> None:
    if rom[:4] != bytes.fromhex("80371240"):
        raise ValueError("expected original big-endian .z64 ROM")
    if layout["format"] != "n64-vtx":
        raise ValueError("unsupported vertex recipe format")
    containers = {}
    for name, recipe in layout["containers"].items():
        if recipe["kind"] == "rom":
            containers[name] = rom
        elif recipe["kind"] == "vpk0":
            start, end = recipe["rom_offset"], recipe["rom_end"]
            if not 0 <= start < end <= len(rom):
                raise ValueError("VPK0 container exceeds original ROM")
            data, consumed = decompress_vpk0(rom[start:end])
            if len(data) != recipe["size"]:
                raise ValueError("VPK0 container size differs from vertex recipe")
            containers[name] = data
        else:
            raise ValueError(f"unsupported vertex container: {recipe['kind']}")
    for vertex in layout["vertices"]:
        body = vertex_initializers(
            containers[vertex["container"]], vertex["offset"], vertex["count"]
        )
        destination = output_root / vertex["include"]
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_text(body)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("recipe", type=Path)
    parser.add_argument("--output-root", type=Path, default=Path("."))
    args = parser.parse_args()
    extract(args.rom.read_bytes(), json.loads(args.recipe.read_text()), args.output_root)


if __name__ == "__main__":
    main()
