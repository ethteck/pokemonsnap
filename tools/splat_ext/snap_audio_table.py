"""Native audio table placement and standard AIFCs; original .bin.o retained."""
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


class N64SegSnap_audio_table(CommonSegBin):
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
            raise ValueError("snap_audio_table requires audio_bank_start/audio_bank_name options")
        bank_start = self.yaml["audio_bank_start"]
        bank_name = self.yaml["audio_bank_name"]
        if not (isinstance(self.rom_start, int) and isinstance(self.rom_end, int)
                and 0 <= bank_start < self.rom_start < self.rom_end <= len(rom_bytes)):
            raise ValueError("invalid native bank/table ROM bounds")
        _, table, assets = decode(rom_bytes[bank_start:self.rom_start],
                                  rom_bytes[self.rom_start:self.rom_end], f"waves/{bank_name}")
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(yaml.safe_dump(table, sort_keys=False), encoding="utf-8")
        for relative, data in assets.items():
            asset = path.parent / relative
            asset.parent.mkdir(parents=True, exist_ok=True)
            asset.write_bytes(data)
        self.log(f"Wrote native table placement and {len(assets)} AIFCs to {path}")
