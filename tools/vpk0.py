#!/usr/bin/env python3
from __future__ import annotations

import argparse
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from vpk0_codec import Vpk0CompressionError, compress_vpk0


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Compress raw data using the VPK0 format"
    )
    parser.add_argument("input", type=Path, help="Path to uncompressed input data")
    parser.add_argument("output", type=Path, help="Path to write the compressed output")
    args = parser.parse_args()

    try:
        compressed = compress_vpk0(args.input.read_bytes())
    except Vpk0CompressionError as err:
        raise SystemExit(f"Failed to compress {args.input}: {err}") from err

    args.output.write_bytes(compressed)


if __name__ == "__main__":
    main()
