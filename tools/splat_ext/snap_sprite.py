from dataclasses import dataclass
from enum import IntEnum, IntFlag
from io import BytesIO
from pathlib import Path
from struct import unpack

import n64img.image
import numpy
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

        # get all bitmaps
        bitmaps = []
        offset = header.bitmap
        for i in range(header.nbitmaps):
            assert offset >= self.vram_start
            assert offset < self.vram_end
            bitmap = Bitmap()
            io = BytesIO(
                rom_bytes[self.ram_to_rom(offset) : self.ram_to_rom(offset) + 0x10]
            )
            bitmap.unpack(io)
            bitmaps.append(bitmap)
            offset += 0x10

        if header.bmfmt == IM_FMT.G_IM_FMT_RGBA and header.bmsiz == IM_SIZ.G_IM_SIZ_16b:
            png_bpp = 4
            input_bpp = 2
            img_class = n64img.image.RGBA16
        elif (
            header.bmfmt == IM_FMT.G_IM_FMT_RGBA and header.bmsiz == IM_SIZ.G_IM_SIZ_32b
        ):
            png_bpp = 4
            input_bpp = 4
            img_class = n64img.image.RGBA32
        elif header.bmfmt == IM_FMT.G_IM_FMT_I and header.bmsiz == IM_SIZ.G_IM_SIZ_8b:
            png_bpp = 1
            input_bpp = 1
            img_class = n64img.image.I8
        elif header.bmfmt == IM_FMT.G_IM_FMT_IA and header.bmsiz == IM_SIZ.G_IM_SIZ_16b:
            png_bpp = 2
            input_bpp = 2
            img_class = n64img.image.IA16
        elif header.bmfmt == IM_FMT.G_IM_FMT_CI and header.bmsiz == IM_SIZ.G_IM_SIZ_8b:
            png_bpp = 1
            input_bpp = 1
            img_class = n64img.image.CI8
        else:
            print(f"Unsupported format: {header.bmfmt.name} {header.bmsiz.name}")
            return

        canvas = bytearray(header.width * header.height * png_bpp)
        canvas = np.array(canvas).reshape(header.height, header.width, png_bpp)

        palette = None
        if header.LUT:
            palette = rom_bytes[
                self.ram_to_rom(header.LUT) : self.ram_to_rom(header.LUT)
                + header.nTLUT * 2
            ]
            palette = bytearray(palette)

        canvas_y = 0
        canvas_x = 0
        # loop over all bitmaps
        for i, bitmap in enumerate(bitmaps):
            input_bytes = rom_bytes[
                self.ram_to_rom(bitmap.buf) : self.ram_to_rom(bitmap.buf)
                + bitmap.width_img * bitmap.actual_height * input_bpp
            ]

            tile = img_class(input_bytes, bitmap.width_img, bitmap.actual_height)

            if palette:
                tile.set_palette(palette, "big")
                pass

            pixels = tile.parse()
            pixels = np.array(bytearray(pixels)).reshape(
                bitmap.actual_height, bitmap.width_img, png_bpp
            )

            # swap the odd rows
            if input_bpp == 2 or input_bpp == 4:
                for y in range(len(pixels)):
                    if y % 2 == 1:
                        for x in range(0, len(pixels[0]), 4):
                            temp = numpy.copy(pixels[y][x : x + 4])
                            pixels[y][x] = temp[2]
                            pixels[y][x + 1] = temp[3]
                            pixels[y][x + 2] = temp[0]
                            pixels[y][x + 3] = temp[1]
            elif input_bpp == 1:
                for y in range(len(pixels)):
                    if y % 2 == 1:
                        for x in range(0, len(pixels[0]), 8):
                            temp = numpy.copy(pixels[y][x : x + 8])
                            pixels[y][x + 0] = temp[4]
                            pixels[y][x + 1] = temp[5]
                            pixels[y][x + 2] = temp[6]
                            pixels[y][x + 3] = temp[7]
                            pixels[y][x + 4] = temp[0]
                            pixels[y][x + 5] = temp[1]
                            pixels[y][x + 6] = temp[2]
                            pixels[y][x + 7] = temp[3]

            # copy the pixels to the canvas
            canvas[
                canvas_y : canvas_y + bitmap.actual_height,
                canvas_x : canvas_x + bitmap.width,
            ] = pixels[0 : bitmap.actual_height, 0 : bitmap.width - 0]

            canvas_x += bitmap.width
            if canvas_x >= header.width:
                canvas_x = 0
                canvas_y += bitmap.actual_height

        canvas_img = img_class(bytearray(), header.width, header.height)
        if palette:
            canvas_img.set_palette(palette)
        with open(path, "wb") as f:
            canvas_img.get_writer().write_array(f, canvas.tobytes())
