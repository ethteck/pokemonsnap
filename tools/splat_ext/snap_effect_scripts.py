"""Splat extraction of native EffectScript banks into semantic JSON sources."""

from __future__ import annotations

import json
import sys
from pathlib import Path

_ROOT = Path(__file__).resolve().parents[1]
if str(_ROOT) not in sys.path:
    sys.path.insert(0, str(_ROOT))

from splat.segtypes.common.bin import CommonSegBin
from splat.segtypes.linker_entry import LinkerEntry
from splat.util import options

from effect_scripts import decode


class N64SegSnap_effect_scripts(CommonSegBin):
    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.json"

    def split(self, rom_bytes: bytes) -> None:
        if not isinstance(self.rom_start, int) or not isinstance(self.rom_end, int):
            raise ValueError(f"Effect script bank {self.name} requires explicit ROM bounds")
        source = decode(rom_bytes[self.rom_start:self.rom_end])
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(json.dumps(source, indent=2, allow_nan=False) + "\n", encoding="utf-8")
        self.log(f"Wrote semantic effect scripts to {path}")

    def get_linker_entries(self) -> list[LinkerEntry]:
        if not self.has_linker_entry:
            return []
        # Retain the former bin segment's object path; JSON is now its only
        # input. The build must encode JSON before the generic CommonSegBin arm.
        return [
            LinkerEntry(
                self,
                [self.out_path()],
                options.opts.asset_path / self.dir / f"{self.name}.bin",
                self.get_linker_section_order(),
                self.get_linker_section_linksection(),
                self.is_noload(),
            )
        ]
