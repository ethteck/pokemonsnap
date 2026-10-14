#!/usr/bin/env python3

import argparse
import re
import subprocess
from pathlib import Path

ASSIGNMENT_RE = re.compile(
    r"^([^\s=]+)\s*=\s*(0x[0-9A-Fa-f]+);",
    re.MULTILINE,
)
ADDRESS_RE = re.compile(r"(?:^|_)([0-9A-Fa-f]{6,8})(?:_|$)")


def read_assignments(path: Path) -> dict[str, int]:
    return {
        match.group(1): int(match.group(2), 16)
        for match in ASSIGNMENT_RE.finditer(path.read_text())
    }


def read_objects(path: Path) -> list[str]:
    return [line for line in path.read_text().splitlines() if line]


def read_object_symbols(nm: str, objects: list[str]) -> tuple[set[str], set[str]]:
    defined_output = subprocess.run(
        [nm, "-g", "--defined-only", *objects],
        check=True,
        capture_output=True,
        text=True,
    ).stdout
    undefined_output = subprocess.run(
        [nm, "-u", *objects],
        check=True,
        capture_output=True,
        text=True,
    ).stdout

    defined = set()
    for line in defined_output.splitlines():
        fields = line.split()
        if len(fields) >= 3 and len(fields[-2]) == 1:
            defined.add(fields[-1])

    undefined = set()
    for line in undefined_output.splitlines():
        fields = line.split()
        if len(fields) >= 2 and fields[-2] == "U":
            undefined.add(fields[-1])

    return defined, undefined


def address_from_name(name: str) -> int:
    match = ADDRESS_RE.search(name)
    if match is None:
        raise ValueError(f"cannot derive an address for undefined symbol {name}")
    return int(match.group(1), 16)


def generate_symbols(
    auto_symbols: dict[str, int],
    manual_symbols: dict[str, int],
    defined: set[str],
    undefined: set[str],
) -> dict[str, int]:
    generated = {
        name: address
        for name, address in auto_symbols.items()
        if name not in defined and name not in manual_symbols
    }

    for name in undefined - defined:
        if name in manual_symbols or name in generated:
            continue
        if name.startswith("D_"):
            generated[name] = address_from_name(name)

    return generated


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--nm", required=True)
    parser.add_argument("--objects", required=True, type=Path)
    parser.add_argument("--auto", required=True, type=Path)
    parser.add_argument("--manual", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()

    objects = read_objects(args.objects)
    defined, undefined = read_object_symbols(args.nm, objects)
    generated = generate_symbols(
        read_assignments(args.auto),
        read_assignments(args.manual),
        defined,
        undefined,
    )

    lines = [
        f"{name} = 0x{address:X};"
        for name, address in sorted(
            generated.items(), key=lambda item: (item[1], item[0])
        )
    ]
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text("\n".join(lines) + "\n")


if __name__ == "__main__":
    main()
