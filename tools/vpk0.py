#!/usr/bin/env python3
"""Compress raw data into the VPK0 format.

Usage:
    python tools/vpk0.py input.bin output.vpk0
    python tools/vpk0.py input.bin output.vpk0 --verify reference.vpk0
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT))

from vpk0_codec import Vpk0CompressionError, compress_vpk0


def _parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Compress raw data using the VPK0 format")
    parser.add_argument("input", type=Path, help="Path to uncompressed input data")
    parser.add_argument("output", type=Path, help="Path to write the compressed output")
    parser.add_argument(
        "--verify",
        type=Path,
        help="Reference compressed data to compare against",
    )
    return parser.parse_args()


def main() -> None:
    args = _parse_args()

    raw = args.input.read_bytes()

    try:
        compressed = compress_vpk0(raw)
    except Vpk0CompressionError as err:
        raise SystemExit(f"Failed to compress {args.input}: {err}") from err

    args.output.write_bytes(compressed)

    if args.verify is not None:
        reference = args.verify.read_bytes()
        if compressed != reference:
            raise SystemExit(
                "Verification failed: compressed output does not match reference data"
            )


if __name__ == "__main__":
    main()
