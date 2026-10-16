"""Native SDK bank graph; original assets/audio/bankN.bin.o identity retained."""
import yaml
import sys
from pathlib import Path

from splat.segtypes.common.bin import CommonSegBin
from splat.segtypes.linker_entry import LinkerEntry
from splat.util import options

_ROOT = Path(__file__).resolve().parents[1]
if str(_ROOT) not in sys.path:
    sys.path.insert(0, str(_ROOT))

from audio_bank import decode


class N64SegSnap_audio_bank(CommonSegBin):
    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.yaml"

    def get_linker_entries(self):
        if not self.has_linker_entry:
            return []
        source = self.out_path()
        native = source.with_suffix(".bin")
        return [LinkerEntry(self, [source], native,
                            self.get_linker_section_order(),
                            self.get_linker_section_linksection(), self.is_noload())]

    def split(self, rom_bytes):
        if not isinstance(self.yaml, dict):
            raise ValueError("snap_audio_bank requires audio_table_start/audio_table_end options")
        table_start = self.yaml["audio_table_start"]
        table_end = self.yaml["audio_table_end"]
        if not (isinstance(self.rom_start, int) and self.rom_end == table_start
                and self.rom_start < table_start < table_end <= len(rom_bytes)):
            raise ValueError("invalid native bank/table ROM bounds")
        bank, _, _ = decode(rom_bytes[self.rom_start:table_start],
                             rom_bytes[table_start:table_end], f"waves/{self.name}")
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(yaml.safe_dump(bank, sort_keys=False), encoding="utf-8")
        self.log(f"Wrote native bank graph to {path}")
