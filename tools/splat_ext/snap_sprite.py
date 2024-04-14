from dataclasses import dataclass
from enum import IntEnum, IntFlag
from io import SEEK_END, BytesIO
from pathlib import Path
from pprint import pprint
from struct import unpack

import n64img.image
import numpy as np
from splat.segtypes.n64.segment import N64Segment
from splat.util import options


class IM_FMT(IntEnum):
    G_IM_FMT_RGBA = 0
    G_IM_FMT_YUV = 1
    G_IM_FMT_CI = 2
    G_IM_FMT_IA = 3
    G_IM_FMT_I = 4


class IM_SIZ(IntEnum):
    G_IM_SIZ_4b = 0
    G_IM_SIZ_8b = 1
    G_IM_SIZ_16b = 2
    G_IM_SIZ_32b = 3
    G_IM_SIZ_DD = 5


class SpriteAttributes(IntFlag):
    SP_TRANSPARENT = 0x00000001
    SP_CUTOUT = 0x00000002
    SP_HIDDEN = 0x00000004
    SP_Z = 0x00000008
    SP_SCALE = 0x00000010
    SP_FASTCOPY = 0x00000020
    SP_OVERLAP = 0x00000040
    SP_TEXSHIFT = 0x00000080
    SP_FRACPOS = 0x00000100
    SP_TEXSHUF = 0x00000200
    SP_EXTERN = 0x00000400


@dataclass(init=False)
class Bitmap:
    width: int
    width_img: int
    s: int
    t: int
    buf: int
    actual_height: int
    lut_offset: int

    def unpack(self, io: BytesIO):
        (
            self.width,
            self.width_img,
            self.s,
            self.t,
            self.buf,
            self.actual_height,
            self.lut_offset,
        ) = unpack(">hhhhIhh", io.read(4 * 4))


@dataclass(init=False)
class Sprite:
    x: int
    y: int
    width: int
    height: int
    scalex: float
    scaley: float
    expx: int
    expy: int
    attr: SpriteAttributes
    zdepth: int
    red: int
    green: int
    blue: int
    alpha: int
    startTLUT: int
    nTLUT: int
    LUT: int  # list[int]
    istart: int
    istep: int
    nbitmaps: int
    ndisplist: int
    bmheight: int
    bmHreal: int
    bmfmt: IM_FMT
    bmsiz: IM_SIZ
    bitmap: int  # bitmap
    rsp_dl: int  # gfx
    rsp_dl_next: int  # gfx

    def unpack(self, io: BytesIO):
        (self.x, self.y) = unpack(">hh", io.read(4))
        (self.width, self.height) = unpack(">hh", io.read(4))
        (self.scalex, self.scaley) = unpack(">ff", io.read(8))
        (self.expx, self.expy) = unpack(">hh", io.read(4))
        (attr,) = unpack(">H", io.read(2))
        (self.zdepth,) = unpack(">h", io.read(2))
        (self.red, self.green, self.blue, self.alpha) = unpack(">BBBB", io.read(4))
        (self.startTLUT, self.nTLUT, self.LUT) = unpack(">hhI", io.read(8))
        (self.istart, self.istep) = unpack(">hh", io.read(4))
        (self.nbitmaps,) = unpack(">H", io.read(2))
        (self.ndisplist,) = unpack(">H", io.read(2))
        (self.bmheight, self.bmHreal) = unpack(">hh", io.read(4))
        (bmfmt,) = unpack(">B", io.read(1))
        (bmsiz,) = unpack(">B", io.read(1))
        io.read(2)
        (self.bitmap,) = unpack(">I", io.read(4))
        (self.rsp_dl,) = unpack(">I", io.read(4))
        (self.rsp_dl_next,) = unpack(">I", io.read(4))

        self.attr = SpriteAttributes(attr)
        self.bmfmt = IM_FMT(bmfmt)
        self.bmsiz = IM_SIZ(bmsiz)


class N64SegSnap_sprite(N64Segment):
    def out_path(self) -> Path:
        self.image_type_in_extension = options.opts.image_type_in_extension
        type_extension = f".{self.type}" if self.image_type_in_extension else ""

        return options.opts.asset_path / self.dir / f"{self.name}{type_extension}.png"

    def split(self, rom_bytes: bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)

        data = rom_bytes[self.rom_start : self.rom_end]

        header = Sprite()
        header.unpack(BytesIO(data[-0x40:]))
        pprint(header)

        # get all bitmaps
        bitmaps = []
        offset = header.bitmap
        for i in range(header.nbitmaps):
            print(f"Bitmap {i}: {offset:X} @ 0x{self.ram_to_rom(offset):X}")
            assert offset >= self.vram_start
            assert offset < self.vram_end
            bitmap = Bitmap()
            io = BytesIO(
                rom_bytes[self.ram_to_rom(offset) : self.ram_to_rom(offset) + 0x10]
            )
            bitmap.unpack(io)
            bitmaps.append(bitmap)
            offset += 0x10

        assert header.bmfmt == IM_FMT.G_IM_FMT_RGBA
        assert header.bmsiz == IM_SIZ.G_IM_SIZ_16b

        canvas = bytearray(header.width * header.height * 4)
        canvas = np.array(canvas).reshape(header.height, header.width, 4)

        canvas_y = 0
        canvas_x = 0
        # loop over all bitmaps
        for i, bitmap in enumerate(bitmaps):
            bytes = bytearray()
            input_bytes = rom_bytes[self.ram_to_rom(bitmap.buf) :]
            row_size = bitmap.width_img * 2
            for y in range(bitmap.actual_height):
                row_bytes = input_bytes[y * row_size : y * row_size + row_size]

                # if Y is odd, flip the row
                if y % 2 == 1:
                    row_bytes = bytearray(row_bytes)
                    for x in range(len(row_bytes) // 8):
                        [a, b, c, d, e, f, g, h] = row_bytes[x * 8 : x * 8 + 8]
                        row_bytes[x * 8 : x * 8 + 8] = [e, f, g, h, a, b, c, d]

                bytes += row_bytes

            tile = n64img.image.RGBA16(bytes, bitmap.width_img, bitmap.actual_height)
            pixels = tile.parse()
            pixels = np.array(bytearray(pixels)).reshape(
                bitmap.actual_height, bitmap.width_img, 4
            )

            # copy the pixels to the canvas
            canvas[
                canvas_y : canvas_y + bitmap.actual_height,
                canvas_x : canvas_x + bitmap.width,
            ] = pixels[0 : bitmap.actual_height, 0 : bitmap.width - 0]

            canvas_x += bitmap.width
            if canvas_x >= header.width:
                canvas_x = 0
                canvas_y += bitmap.actual_height

        canvas_img = n64img.image.RGBA16(bytearray(), header.width, header.height)
        with open(path, "wb") as f:
            canvas_img.get_writer().write_array(f, canvas.tobytes())
