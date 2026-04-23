#!/usr/bin/env python3
"""Wrap a VPK0 blob in a relocatable object and re-export overlay VRAM symbols."""

from __future__ import annotations

import argparse
import subprocess
from pathlib import Path
from typing import Iterable


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("elf", type=Path)
    parser.add_argument("vpk0", type=Path)
    parser.add_argument("-o", "--output", type=Path, required=True)
    parser.add_argument("--reference-objects-file", type=Path)
    parser.add_argument("--cross", default="mips-linux-gnu-")
    return parser.parse_args()


def get_alloc_vram_range(elf_path: Path, objdump: str) -> tuple[int, int]:
    result = subprocess.run(
        [objdump, "-h", str(elf_path)],
        check=True,
        capture_output=True,
        text=True,
    )

    vram_start: int | None = None
    vram_end = 0
    pending_section: tuple[int, int] | None = None

    for line in result.stdout.splitlines():
        stripped = line.strip()
        if not stripped:
            continue

        if pending_section is None:
            parts = stripped.split()
            if len(parts) < 7 or not parts[0].isdigit():
                continue
            try:
                size = int(parts[2], 16)
                vma = int(parts[3], 16) & 0xFFFFFFFF
            except ValueError:
                continue
            pending_section = (size, vma)
            continue

        size, vma = pending_section
        pending_section = None
        if "ALLOC" not in stripped:
            continue

        if vram_start is None or vma < vram_start:
            vram_start = vma
        if vma + size > vram_end:
            vram_end = vma + size

    if vram_start is None:
        raise RuntimeError(f"Could not find alloc sections in {elf_path}")

    return vram_start, vram_end


def batched(values: list[str], size: int) -> Iterable[list[str]]:
    for i in range(0, len(values), size):
        yield values[i : i + size]



def get_referenced_symbols(reference_objects_file: Path | None, nm: str) -> set[str] | None:
    if reference_objects_file is None:
        return None

    object_paths = [
        line.strip()
        for line in reference_objects_file.read_text(encoding="utf-8").splitlines()
        if line.strip()
    ]
    if not object_paths:
        return set()

    referenced_symbols: set[str] = set()
    for batch in batched(object_paths, 200):
        result = subprocess.run(
            [nm, "--undefined-only", "--format=posix", *batch],
            check=True,
            capture_output=True,
            text=True,
        )
        for line in result.stdout.splitlines():
            parts = line.strip().split()
            if len(parts) >= 2 and parts[1] == "U":
                referenced_symbols.add(parts[0])

    return referenced_symbols



def get_exported_symbols(
    elf_path: Path,
    nm: str,
    vram_start: int,
    vram_end: int,
    referenced_symbols: set[str] | None,
) -> list[tuple[int, str]]:
    result = subprocess.run(
        [nm, "-g", "--defined-only", str(elf_path)],
        check=True,
        capture_output=True,
        text=True,
    )

    available_symbols: dict[str, int] = {}
    for line in result.stdout.splitlines():
        parts = line.strip().split()
        if len(parts) < 3:
            continue

        value_str, _sym_type, name = parts[:3]
        if name.startswith((".", "$")):
            continue

        try:
            value = int(value_str, 16) & 0xFFFFFFFF
        except ValueError:
            continue

        if vram_start <= value < vram_end:
            available_symbols[name] = value

    if referenced_symbols is None:
        symbols = available_symbols
    else:
        symbols = {}
        for name in sorted(referenced_symbols):
            if name in available_symbols:
                symbols[name] = available_symbols[name]
                continue

            sprite_name = f"{name}_sprite"
            if sprite_name in available_symbols:
                symbols[name] = available_symbols[sprite_name]

    return sorted((value, name) for name, value in symbols.items())


def main() -> None:
    args = parse_args()

    objdump = f"{args.cross}objdump"
    nm = f"{args.cross}nm"
    assembler = f"{args.cross}as"

    vram_start, vram_end = get_alloc_vram_range(args.elf, objdump)
    referenced_symbols = get_referenced_symbols(args.reference_objects_file, nm)
    symbols = get_exported_symbols(
        args.elf,
        nm,
        vram_start,
        vram_end,
        referenced_symbols,
    )

    asm_lines = [
        '.section .data, "wa"',
        ".balign 16",
        f'.incbin "{args.vpk0.as_posix()}"',
        "",
    ]

    for value, name in symbols:
        asm_lines.append(f".globl {name}")
        asm_lines.append(f"{name} = 0x{value:08X}")

    asm_lines.append("")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    asm_path = args.output.with_suffix(args.output.suffix + ".s")
    asm_path.write_text("\n".join(asm_lines), encoding="utf-8")

    subprocess.run(
        [
            assembler,
            "-G0",
            "-EB",
            "-mtune=vr4300",
            "-march=vr4300",
            "-o",
            str(args.output),
            str(asm_path),
        ],
        check=True,
    )


if __name__ == "__main__":
    main()
