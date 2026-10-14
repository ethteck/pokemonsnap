"""CPU-rendered window font coverage; not hardware CI4 texture data."""
from pathlib import Path
import sys

from splat.segtypes.segment import Segment
from splat.util import options

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from window_font import decode


class N64SegSnap_window_font(Segment):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.glyph_size = int(self.yaml['glyph_size'])
        if self.glyph_size not in (8, 12):
            raise ValueError('Window glyph size must be 8 or 12')

    @staticmethod
    def estimate_size(yaml):
        return 370 * yaml['glyph_size'] * yaml['glyph_size'] // 2

    def out_path(self):
        return options.opts.asset_path / self.dir / f'{self.name}.png'

    def should_split(self):
        return options.opts.is_mode_active('img')

    def split(self, rom_bytes):
        if self.rom_end - self.rom_start != self.estimate_size(self.yaml):
            raise ValueError('Window font range must contain exactly 370 glyphs')
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(decode(rom_bytes[self.rom_start:self.rom_end], self.glyph_size))
