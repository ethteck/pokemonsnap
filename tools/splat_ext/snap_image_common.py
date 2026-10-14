"""Sprite SP_TEXSHUF word layout shared by native image formats."""

from splat.segtypes.n64.img import N64SegImg


class SnapShuffledImage(N64SegImg):
    bytes_per_pixel: int | float
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.word_swap = (
            bool(self.yaml.get("word_swap", False))
            if isinstance(self.yaml, dict)
            else False
        )

    @classmethod
    def estimate_size(cls, yaml):
        width, height = cls.parse_dimensions(yaml)
        return int(width * height * cls.bytes_per_pixel + 0.5)

    def load_pixels(self, rom_bytes):
        if self.word_swap:
            data = bytearray(rom_bytes[self.rom_start:self.rom_end])
            row_size = int(self.width * self.bytes_per_pixel)
            # This operation is its own inverse; inherited writing applies flips.
            for row in range(1, self.height, 2):
                row_start = row * row_size
                for offset in range(row_start, row_start + row_size - 7, 8):
                    data[offset:offset + 8] = (
                        data[offset + 4:offset + 8] + data[offset:offset + 4]
                    )
            self.n64img.data = bytes(data)
        else:
            self.n64img.data = rom_bytes[self.rom_start:self.rom_end]

    def split(self, rom_bytes):
        self.load_pixels(rom_bytes)
        super().split(rom_bytes)


class SnapIndexedImage(SnapShuffledImage):
    def split(self, rom_bytes):
        start = self.yaml["palette_rom"]
        size = self.yaml["palette_size"]
        if not 0 <= start < start + size <= len(rom_bytes) or size % 2:
            raise ValueError("invalid native indexed-image palette bounds")
        self.n64img.set_palette(rom_bytes[start : start + size])
        super().split(rom_bytes)
