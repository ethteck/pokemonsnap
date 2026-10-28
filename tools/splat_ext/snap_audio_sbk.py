import yaml
import sys
from pathlib import Path

from splat.segtypes.common.bin import CommonSegBin
from splat.segtypes.linker_entry import LinkerEntry
from splat.util import options

_ROOT = Path(__file__).resolve().parents[1]
if str(_ROOT) not in sys.path:
    sys.path.insert(0, str(_ROOT))

from audio_sequence_bank import extract


class N64SegSnap_audio_sbk(CommonSegBin):
    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.yaml"

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
        spec = extract(rom_bytes[self.rom_start:self.rom_end], self.rom_start)
        path.write_text(yaml.safe_dump(spec, sort_keys=False), encoding="utf-8")
        self.log(f"Wrote {self.name} to {path}")
