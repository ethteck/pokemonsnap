#!/usr/bin/env python3
"""Diagnose the first divergence between our encoder's LZSS decisions
and the original tool's decisions, for a given VPK0 segment in the ROM.

This is the tool I'll iterate against while reverse-engineering the
original encoder's match-selection heuristic.

Usage:
    uv run python tools/vpk0_diagnose.py <start_hex> <end_hex>

Example:
    uv run python tools/vpk0_diagnose.py 0xAA0B80 0xAA18D3
"""

from __future__ import annotations

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

from vpk0_codec import (  # noqa: E402
    LzToken,
    Vpk0Metadata,
    _lzss_lazy,
    decompress_vpk0_with_tokens,
)


def token_str(t: LzToken, pos: int) -> str:
    if t.is_literal:
        return f"pos={pos}: lit(0x{t.literal:02X})"
    return f"pos={pos}: back(mb={t.move_back}, len={t.length})"


def token_span(t: LzToken) -> int:
    return 1 if t.is_literal else t.length


def diagnose(rom: bytes, start: int, end: int) -> None:
    blob = rom[start:end]
    decompressed, orig_tokens = decompress_vpk0_with_tokens(blob)
    metadata = Vpk0Metadata.from_compressed(blob)

    # Run our LZSS pass with the same budget the encoder would use.
    off_max_bits = max(
        (getattr(e, "bit_size", 0) for e in metadata.offsets_tree.entries), default=1
    )
    len_max_bits = max(
        (getattr(e, "bit_size", 0) for e in metadata.lengths_tree.entries), default=1
    )
    max_tv = (1 << off_max_bits) - 1
    lzss_max_window = max(1, (max_tv << 2) - 8)
    lzss_max_match = min(255, (1 << len_max_bits) - 1)
    our_tokens = _lzss_lazy(decompressed, max_window=lzss_max_window, max_match=lzss_max_match)

    print(f"ROM segment 0x{start:X}..0x{end:X}  (decompressed {len(decompressed)} bytes)")
    print(f"  tree caps: offset bit_size <= {off_max_bits} (move_back <= {lzss_max_window}), "
          f"length bit_size <= {len_max_bits} (match <= {lzss_max_match})")
    print(f"  original tokens: {len(orig_tokens)}  (literals={sum(1 for t in orig_tokens if t.is_literal)}, "
          f"backrefs={sum(1 for t in orig_tokens if not t.is_literal)})")
    print(f"  our tokens     : {len(our_tokens)}  (literals={sum(1 for t in our_tokens if t.is_literal)}, "
          f"backrefs={sum(1 for t in our_tokens if not t.is_literal)})")

    # Walk both token streams side by side by output position.
    pos = 0
    oi = 0
    ti = 0
    while oi < len(orig_tokens) and ti < len(our_tokens):
        o = orig_tokens[oi]
        t = our_tokens[ti]
        if o == t:
            pos += token_span(o)
            oi += 1
            ti += 1
            continue

        # Divergence. Print context.
        print()
        print(f"FIRST DIVERGENCE at output position {pos} (0x{pos:X})")
        print(f"  data[pos-8:pos+16] = {decompressed[max(0, pos-8):pos+16].hex()}")
        print(f"  original chose:  {token_str(o, pos)}")
        print(f"  our encoder chose: {token_str(t, pos)}")

        # Show a bit of the lookback window (what was available to match against).
        window_start = max(0, pos - 32)
        print(f"  lookback[{window_start}..{pos}] = {decompressed[window_start:pos].hex()}")
        print(f"  lookahead[{pos}..{pos + 32}] = {decompressed[pos:pos + 32].hex()}")

        # Enumerate possible matches at this position, within window budget.
        def enumerate_matches(p: int) -> list[tuple[int, int]]:
            if p < 3 or p + 3 > len(decompressed):
                return []
            window_begin = max(0, p - lzss_max_window)
            matches_local: list[tuple[int, int]] = []
            limit = min(lzss_max_match, len(decompressed) - p)
            seen_offsets: set[int] = set()
            for j in range(p - 1, window_begin - 1, -1):
                if (p - j) in seen_offsets:
                    continue
                seen_offsets.add(p - j)
                k = 0
                while k < limit and decompressed[j + k] == decompressed[p + k]:
                    k += 1
                if k >= 3:
                    matches_local.append((p - j, k))
            matches_local.sort(key=lambda m: (-m[1], m[0]))
            return matches_local

        print()
        print(f"  possible 3+ byte matches at pos={pos}:")
        for mb, ml in enumerate_matches(pos)[:10]:
            marker = ""
            if not o.is_literal and mb == o.move_back and ml == o.length:
                marker = " <-- original picked"
            if not t.is_literal and mb == t.move_back and ml == t.length:
                marker += " <-- we picked"
            print(f"    mb={mb:6d}  len={ml:3d}{marker}")

        # If original chose a literal, show what matches are available at
        # pos+1 — this is the natural place to look for "lazy match" rules.
        if o.is_literal:
            print(f"\n  possible 3+ byte matches at pos={pos + 1}:")
            for mb, ml in enumerate_matches(pos + 1)[:10]:
                print(f"    mb={mb:6d}  len={ml:3d}")

        # Print the next few tokens from each side.
        print("\n  next 6 original tokens:")
        p = pos
        for k in range(oi, min(oi + 6, len(orig_tokens))):
            print(f"    {token_str(orig_tokens[k], p)}")
            p += token_span(orig_tokens[k])
        print("\n  next 6 our tokens:")
        p = pos
        for k in range(ti, min(ti + 6, len(our_tokens))):
            print(f"    {token_str(our_tokens[k], p)}")
            p += token_span(our_tokens[k])

        return

    print("\nNo divergence found in overlapping prefix.")
    if len(orig_tokens) != len(our_tokens):
        print(f"  but token counts differ: orig={len(orig_tokens)} ours={len(our_tokens)}")


def main() -> None:
    if len(sys.argv) != 3:
        print(__doc__)
        sys.exit(1)
    start = int(sys.argv[1], 0)
    end = int(sys.argv[2], 0)
    rom = (ROOT / "pokemonsnap.z64").read_bytes()
    diagnose(rom, start, end)


if __name__ == "__main__":
    main()
