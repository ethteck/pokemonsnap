from typing import TYPE_CHECKING, Optional
from segtypes.n64.rgba16 import N64SegRgba16
import png
from util import log
from util import options

if TYPE_CHECKING:
    from segtypes.n64.palette import N64SegPalette as Palette

class N64SegCi8(N64SegRgba16):
    def __init__(self, segment, rom_start, rom_end):
        super().__init__(segment, rom_start, rom_end)

        self.palette: 'Optional[Palette]' = None
        self.palette_name = self.name

    def split(self, rom_bytes):
        path = options.get_asset_path() / self.dir / (self.name + ".png")
        path.parent.mkdir(parents=True, exist_ok=True)

        data = rom_bytes[self.rom_start:self.rom_end]

        if self.palette is None:
            # TODO: output with blank palette
            log.error(f"no palette sibling segment exists\n(hint: add a segment with type 'palette' and name '{self.name}')")
            return

        w = png.Writer(self.width, self.height, palette=self.palette.parse_palette(rom_bytes))
        image = self.__class__.parse_image(data, self.width, self.height, self.flip_horizontal, self.flip_vertical)

        with open(self.out_path(), "wb") as f:
            w.write_array(f, image)
        
        self.palette.extract = False

    @staticmethod
    def parse_image(data, width, height, flip_h=False, flip_v=False):
        return data

    def max_length(self):
        return self.width * self.height
