import json
import sys
from pathlib import Path

from splat.segtypes.common.bin import CommonSegBin
from splat.segtypes.linker_entry import LinkerEntry
from splat.util import options

_ROOT = Path(__file__).resolve().parents[1]
if str(_ROOT) not in sys.path:
    sys.path.insert(0, str(_ROOT))

from idle_script import decode


class N64SegSnap_idle_script(CommonSegBin):
    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.json"

    def get_linker_entries(self):
        if not self.has_linker_entry:
            return []
        source = self.out_path()
        return [
            LinkerEntry(
                self, [source], source.with_suffix(".bin"),
                self.get_linker_section_order(),
                self.get_linker_section_linksection(), self.is_noload(),
            )
        ]

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        spec = decode(rom_bytes[self.rom_start : self.rom_end])
        path.write_text(json.dumps(spec, indent=2) + "\n", encoding="utf-8")
        self.log(f"Wrote {self.name} to {path}")
