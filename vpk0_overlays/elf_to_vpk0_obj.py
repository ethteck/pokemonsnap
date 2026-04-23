#!/usr/bin/env python3
"""Convert a linked overlay ELF into a relocatable .o containing the VPK0-compressed binary and all exported symbols."""

from __future__ import annotations

import argparse
import subprocess
import sys
import tempfile
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("elf", type=Path)
    parser.add_argument("-o", "--output", type=Path, required=True)
    parser.add_argument("--vpk0-tool", type=Path, required=True)
    parser.add_argument("--label", required=True, help="Symbol prefix for _ROM_START/_ROM_END")
    parser.add_argument("--cross", default="mips-linux-gnu-")
    args = parser.parse_args()

    objcopy = f"{args.cross}objcopy"
    nm = f"{args.cross}nm"
    assembler = f"{args.cross}as"

    with tempfile.TemporaryDirectory() as tmpdir:
        tmp = Path(tmpdir)
        bin_path = tmp / "overlay.bin"
        vpk0_path = tmp / "overlay.vpk0"
        asm_path = tmp / "overlay.s"

        subprocess.run(
            [objcopy, str(args.elf), str(bin_path), "-O", "binary"],
            check=True,
        )

        subprocess.run(
            [sys.executable, str(args.vpk0_tool), str(bin_path), str(vpk0_path)],
            check=True,
        )

        result = subprocess.run(
            [nm, "-g", "--defined-only", str(args.elf)],
            check=True, capture_output=True, text=True,
        )
        symbols: dict[str, int] = {}
        for line in result.stdout.splitlines():
            parts = line.strip().split()
            if len(parts) >= 3:
                try:
                    symbols[parts[2]] = int(parts[0], 16) & 0xFFFFFFFF
                except ValueError:
                    continue

        lines = [
            '.section .data, "wa"',
            ".balign 16",
            f".globl {args.label}_ROM_START",
            f"{args.label}_ROM_START:",
            f'.incbin "{vpk0_path}"',
            f".globl {args.label}_ROM_END",
            f"{args.label}_ROM_END:",
            "",
        ]
        for name, value in sorted(symbols.items(), key=lambda x: (x[1], x[0])):
            lines.append(f".globl {name}")
            lines.append(f"{name} = 0x{value:08X}")
        lines.append("")
        asm_path.write_text("\n".join(lines))

        args.output.parent.mkdir(parents=True, exist_ok=True)
        subprocess.run(
            [assembler, "-G0", "-EB", "-mtune=vr4300", "-march=vr4300",
             "-o", str(args.output), str(asm_path)],
            check=True,
        )


if __name__ == "__main__":
    main()
