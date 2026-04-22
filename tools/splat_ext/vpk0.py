"""Splat segment type that decompresses VPK0 blobs using tools.vpk0_codec."""

from __future__ import annotations

import sys
from pathlib import Path

_ROOT = Path(__file__).resolve().parents[1]
if str(_ROOT) not in sys.path:
    sys.path.insert(0, str(_ROOT))

from splat.segtypes.n64.decompressor import CommonSegDecompressor  # type: ignore
from splat.util import log  # type: ignore

from vpk0_codec import Vpk0DecompressionError, decompress_vpk0  # noqa: E402


class N64SegVpk0(CommonSegDecompressor):
    compression_error_hint = "(hint: add a 'bin' segment after it)"

    @property
    def compression_type(self) -> str:
        return "Vpk0"

    def decompress(self, compressed_bytes: bytes) -> bytes:
        try:
            decompressed, consumed = decompress_vpk0(compressed_bytes)
        except Vpk0DecompressionError as err:
            log.error(f"Error decompressing {self.name}: {err}")

        assert isinstance(self.rom_start, int)
        assert isinstance(self.rom_end, int)

        expected_end = self.rom_start + consumed
        actual_end = self.rom_end

        if expected_end != actual_end:
            log.error(
                f"Error: {self.name} should end at 0x{expected_end:X}, but it ends at 0x{actual_end:X}\n{self.compression_error_hint}"
            )

        return decompressed
