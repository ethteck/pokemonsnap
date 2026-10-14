"""Finalize stock-size audio ROMs and checksum explicitly authored builds.

Pokémon Snap US uses CIC-6103. Matching builds retain the original header;
only the explicit audio-mod target recalculates its two boot checksums.
"""

import argparse
import os
import struct
import subprocess
import tempfile
import zlib
from pathlib import Path


ROM_SIZE = 0x1000000
IPL3_CRC = 0x0B050EE0
MASK = 0xFFFFFFFF


def calculate_checksums(rom: bytes | bytearray) -> tuple[int, int]:
    if len(rom) != ROM_SIZE or rom[:4] != b"\x80\x37\x12\x40":
        raise ValueError("expected a 16 MiB big-endian Pokémon Snap ROM")
    view = memoryview(rom)
    if zlib.crc32(view[0x40:0x1000]) & MASK != IPL3_CRC:
        raise ValueError("audio-mod requires Pokémon Snap's CIC-6103 bootloader")
    checksum_sum = carry = checksum_xor = rotate_sum = mixed_xor = mixed_sum = 0xA3886759
    for (word,) in struct.iter_unpack(">I", view[0x1000:0x101000]):
        total = checksum_sum + word
        carry = (carry + (total >> 32)) & MASK
        checksum_sum = total & MASK
        checksum_xor ^= word
        shift = word & 31
        rotated = ((word << shift) | (word >> (32 - shift))) & MASK
        mixed_xor ^= rotated if mixed_xor > word else checksum_sum ^ word
        rotate_sum = (rotate_sum + rotated) & MASK
        mixed_sum = (mixed_sum + (rotate_sum ^ word)) & MASK
    return ((checksum_sum ^ carry) + checksum_xor) & MASK, ((rotate_sum ^ mixed_xor) + mixed_sum) & MASK


def build_rom(elf: Path, output: Path, objcopy: str) -> None:
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="audio-rom-", dir=output.parent) as directory:
        temporary = Path(directory) / "rom.z64"
        subprocess.run([objcopy, "-O", "binary", str(elf), str(temporary)], check=True)
        size = temporary.stat().st_size
        if size > ROM_SIZE:
            raise ValueError(f"authored audio exceeds the 16 MiB ROM capacity by {size - ROM_SIZE} bytes")
        with temporary.open("ab") as stream:
            remaining = ROM_SIZE - size
            fill = b"\xff" * min(remaining, 65536)
            while remaining:
                count = min(remaining, len(fill))
                stream.write(fill[:count])
                remaining -= count
        os.replace(temporary, output)


def checksum_rom(source: Path, output: Path) -> None:
    rom = bytearray(source.read_bytes())
    struct.pack_into(">II", rom, 0x10, *calculate_checksums(rom))
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(prefix="audio-mod-", dir=output.parent, delete=False) as stream:
        temporary = Path(stream.name)
        try:
            stream.write(rom)
        except BaseException:
            temporary.unlink(missing_ok=True)
            raise
    try:
        os.replace(temporary, output)
    finally:
        temporary.unlink(missing_ok=True)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    build = commands.add_parser("rom", help="extract ELF and append verified-capacity ROM padding")
    build.add_argument("--objcopy", required=True)
    build.add_argument("input", type=Path)
    build.add_argument("output", type=Path)
    checksum = commands.add_parser("checksum", help="write CIC-6103 checksums for an authored ROM")
    checksum.add_argument("input", type=Path)
    checksum.add_argument("output", type=Path)
    args = parser.parse_args()
    if args.command == "rom":
        build_rom(args.input, args.output, args.objcopy)
    else:
        checksum_rom(args.input, args.output)


if __name__ == "__main__":
    main()
