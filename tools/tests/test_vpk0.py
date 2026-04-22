"""Byte-identical round-trip tests for the VPK0 codec against the
original Pokemon Snap ROM.

The only thing that matters here is ``recompress_bit_matches_rom``: our
encoder, given the raw decompressed bytes (and the original trees /
method as reverse-engineered arguments), must produce the exact same
compressed stream that the ROM contains.
"""

from __future__ import annotations

import hashlib
import sys
from pathlib import Path

import pytest

ROOT = Path(__file__).resolve().parents[2]
TOOLS = ROOT / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))

from vpk0_codec import Vpk0Metadata, compress_vpk0, decompress_vpk0  # noqa: E402


ROM_PATH = ROOT / "pokemonsnap.z64"
ROM_SHA1 = "edc7c49cc568c045fe48be0d18011c30f393cbaf"

# (rom_start, rom_end, name) for the three VPK0 segments. rom_end is the
# first byte that is *not* part of the compressed stream.
VPK0_SEGMENTS: list[tuple[int, int, str]] = [
    (0xA0F830, 0xA5CC46, "menu_images_A0F830"),
    (0xAA0B80, 0xAA18D3, "rights_notice_AA0B80"),
    (0xAAA610, 0xAAA65B, "tiny_AAA610"),
]


@pytest.fixture(scope="session")
def rom() -> bytes:
    if not ROM_PATH.exists():
        pytest.skip(f"ROM not available at {ROM_PATH}")
    data = ROM_PATH.read_bytes()
    actual = hashlib.sha1(data).hexdigest()
    if actual != ROM_SHA1:
        pytest.skip(f"ROM sha1 mismatch: expected {ROM_SHA1}, got {actual}")
    return data


@pytest.mark.parametrize(
    "start,end,name", VPK0_SEGMENTS, ids=[s[2] for s in VPK0_SEGMENTS]
)
def test_recompress_bit_matches_rom(
    rom: bytes, start: int, end: int, name: str  # noqa: ARG001
) -> None:
    blob = rom[start:end]
    decompressed, _ = decompress_vpk0(blob)
    metadata = Vpk0Metadata.from_compressed(blob)
    re_encoded = compress_vpk0(decompressed, metadata.method, metadata=metadata)

    if re_encoded == blob:
        return

    # Avoid pytest's default byte-by-byte diff on megabyte inputs — build
    # a concise report ourselves.
    first_diff = next(
        (i for i in range(min(len(blob), len(re_encoded))) if blob[i] != re_encoded[i]),
        min(len(blob), len(re_encoded)),
    )
    pytest.fail(
        "encoder output differs from ROM:\n"
        f"  sizes: orig={len(blob)} new={len(re_encoded)}\n"
        f"  first_diff_byte=0x{first_diff:X}\n"
        f"  orig[first_diff:first_diff+16] = {blob[first_diff:first_diff+16].hex()}\n"
        f"  new [first_diff:first_diff+16] = {re_encoded[first_diff:first_diff+16].hex()}"
    )
