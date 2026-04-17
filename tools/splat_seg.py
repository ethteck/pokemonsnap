#!/usr/bin/env -S uv run --script
# /// script
# requires-python = ">=3.11"
# dependencies = [
#   "pyyaml",
#   "rich",
# ]
# ///
"""Print a table of subsegments (offset / size / type / name) for a named splat segment."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path
from typing import Any

import yaml
from rich.console import Console
from rich.table import Table


def _to_int(v: Any) -> int | None:
    if isinstance(v, bool):
        return None
    if isinstance(v, int):
        return v
    if isinstance(v, str):
        try:
            return int(v, 0)
        except ValueError:
            return None
    return None


def get_start(sub: Any) -> int | None:
    """ROM offset of a (sub)segment entry, or None when absent/auto."""
    if isinstance(sub, list) and sub:
        return _to_int(sub[0])
    if isinstance(sub, dict):
        return _to_int(sub.get("start"))
    return None


def get_type(sub: Any) -> str:
    if isinstance(sub, list) and len(sub) >= 2:
        return str(sub[1])
    if isinstance(sub, dict):
        return str(sub.get("type", ""))
    return ""


def get_name(sub: Any) -> str:
    if isinstance(sub, list):
        return str(sub[2]) if len(sub) >= 3 else ""
    if isinstance(sub, dict):
        return str(sub.get("name", ""))
    return ""


def has_children(sub: Any) -> bool:
    return isinstance(sub, dict) and bool(sub.get("subsegments"))


def find_segment(segments: list, name: str) -> dict | None:
    for seg in segments:
        if isinstance(seg, dict):
            if seg.get("name") == name:
                return seg
            if "subsegments" in seg:
                hit = find_segment(seg["subsegments"], name)
                if hit is not None:
                    return hit
    return None


def collect_named(segments: list, out: list[str] | None = None) -> list[str]:
    if out is None:
        out = []
    for seg in segments:
        if isinstance(seg, dict):
            n = seg.get("name")
            if n:
                out.append(str(n))
            if "subsegments" in seg:
                collect_named(seg["subsegments"], out)
    return out


def parent_end_of(root: list, target: dict) -> int | None:
    """Find the start offset of the entry that follows `target` in its parent list."""
    stack: list[list] = [root]
    while stack:
        lst = stack.pop()
        for i, s in enumerate(lst):
            if s is target:
                for j in range(i + 1, len(lst)):
                    nxt = get_start(lst[j])
                    if nxt is not None:
                        return nxt
                return None
            if isinstance(s, dict) and "subsegments" in s:
                stack.append(s["subsegments"])
    return None


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("name", nargs="?", help="segment name to inspect")
    ap.add_argument("-f", "--file", default="splat.yaml", help="path to splat.yaml")
    ap.add_argument("-l", "--list", action="store_true", help="list all named segments and exit")
    args = ap.parse_args()

    try:
        data = yaml.safe_load(Path(args.file).read_text())
    except FileNotFoundError:
        print(f"error: {args.file} not found", file=sys.stderr)
        return 2

    segments = data.get("segments", []) if isinstance(data, dict) else []

    if args.list or not args.name:
        for n in collect_named(segments):
            print(n)
        return 0

    seg = find_segment(segments, args.name)
    if seg is None:
        print(f"error: segment {args.name!r} not found", file=sys.stderr)
        return 1

    subs = seg.get("subsegments") or []
    if not subs:
        print(f"segment {args.name!r} has no subsegments", file=sys.stderr)
        return 1

    tail = parent_end_of(segments, seg) or _to_int(seg.get("end"))

    rows: list[tuple[int, Any, int | None, int | None]] = []
    _walk(subs, tail, 0, rows)

    console = Console()
    title = args.name
    seg_start = _to_int(seg.get("start"))
    if seg_start is not None:
        title += f"  (start=0x{seg_start:X}"
        if tail is not None:
            title += f", end=0x{tail:X}, size=0x{tail - seg_start:X}"
        title += ")"

    table = Table(title=title, title_justify="left")
    table.add_column("offset", justify="right", style="cyan")
    table.add_column("size", justify="right", style="magenta")
    table.add_column("type")
    table.add_column("name")

    for depth, sub, off, nxt in rows:
        off_s = f"0x{off:X}" if off is not None else "auto"
        if off is not None and nxt is not None and nxt >= off:
            size_s = f"0x{nxt - off:X}"
        else:
            size_s = "-"
        name = get_name(sub)
        if not name and off is not None:
            name = f"{off:X}"
        if has_children(sub):
            name = f"{name} [+{len(sub['subsegments'])}]"
        indent = "  " * depth
        table.add_row(off_s, size_s, get_type(sub), f"{indent}{name}")

    console.print(table)
    return 0


def _walk(
    subs: list,
    parent_tail: int | None,
    depth: int,
    out: list[tuple[int, Any, int | None, int | None]],
) -> None:
    offsets = [get_start(s) for s in subs]
    for i, sub in enumerate(subs):
        off = offsets[i]
        nxt: int | None = None
        for j in range(i + 1, len(offsets)):
            if offsets[j] is not None:
                nxt = offsets[j]
                break
        if nxt is None:
            nxt = parent_tail
        out.append((depth, sub, off, nxt))
        if has_children(sub):
            _walk(sub["subsegments"], nxt, depth + 1, out)


if __name__ == "__main__":
    sys.exit(main())
