from dataclasses import dataclass
from enum import IntEnum, IntFlag
from io import BytesIO
from pathlib import Path
from struct import unpack

import n64img.image
import numpy
import numpy as np
from splat.segtypes.segment import Segment
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
class SpriteHeader:
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


FORMAT_INFO = {
    (IM_FMT.G_IM_FMT_RGBA, IM_SIZ.G_IM_SIZ_16b): (4, 2, n64img.image.RGBA16, "rgba16"),
    (IM_FMT.G_IM_FMT_RGBA, IM_SIZ.G_IM_SIZ_32b): (4, 4, n64img.image.RGBA32, "rgba32"),
    (IM_FMT.G_IM_FMT_I, IM_SIZ.G_IM_SIZ_8b): (1, 1, n64img.image.I8, "i8"),
    (IM_FMT.G_IM_FMT_IA, IM_SIZ.G_IM_SIZ_16b): (2, 2, n64img.image.IA16, "ia16"),
    (IM_FMT.G_IM_FMT_CI, IM_SIZ.G_IM_SIZ_8b): (1, 1, n64img.image.CI8, "ci8"),
}


class N64SegSnap_sprite(Segment):
    DF_ALIGNER = bytes.fromhex("df00000000000000")
    ZERO_ALIGNER = bytes(8)

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.png"

    def padding_out_path(self) -> Path:
        path = self.out_path()
        return path.with_name(f"{path.stem}.padding.png")

    def _resolve_rom(self, vram_addr: int) -> int | None:
        """Convert VRAM to ROM, falling back to the top-level parent segment."""
        result = self.ram_to_rom(vram_addr)
        if result is None:
            result = self.get_most_parent().ram_to_rom(vram_addr)
        return result

    def _resolve_name(self, vram_addr: int, suffix: str) -> str:
        """Resolve a VRAM address to a symbol name, with fallback."""
        sym = self.get_symbol(vram_addr, in_segment=True)
        if sym:
            return sym.name
        rom = self._resolve_rom(vram_addr)
        if rom is not None:
            return f"D_{vram_addr:08X}_{rom:X}"
        return f"D_{vram_addr:08X}"

    def split(self, rom_bytes: bytes):
        header = SpriteHeader()
        assert self.rom_end is not None
        header_rom = self.rom_end - 0x40
        header.unpack(BytesIO(rom_bytes[header_rom : self.rom_end]))

        fmt = FORMAT_INFO.get((header.bmfmt, header.bmsiz))
        if fmt is None:
            print(
                f"Unsupported format: {header.bmfmt.name} {header.bmsiz.name} "
                f"for {self.name} at ROM 0x{self.rom_start:X}-0x{self.rom_end:X}"
            )
            return
        png_bpp, input_bpp, img_class, format_name = fmt

        if self.rom_start == 0xA9D3E0:
            header.width = 320

        # Parse all bitmap structs
        bitmaps = []
        bm_vram = header.bitmap
        for _ in range(header.nbitmaps):
            bm_rom = self._resolve_rom(bm_vram)
            assert bm_rom is not None
            bitmap = Bitmap()
            bitmap.unpack(BytesIO(rom_bytes[bm_rom : bm_rom + 0x10]))
            bitmaps.append(bitmap)
            bm_vram += 0x10

        # Validate: first pixel should be at rom_start + 8
        if bitmaps:
            first_buf_rom = self._resolve_rom(bitmaps[0].buf)
            assert first_buf_rom is not None
            assert self.rom_start is not None
            expected = self.rom_start + 8
            if first_buf_rom != expected:
                print(
                    f"WARNING: {self.name}: first pixel data at 0x{first_buf_rom:X}, "
                    f"expected 0x{expected:X} (segment starts at 0x{self.rom_start:X})"
                )

        # Resolve symbol names
        sprite_vram = self.get_most_parent().rom_to_ram(header_rom)
        assert sprite_vram is not None
        self.name = self._resolve_name(sprite_vram, "sprite")

        # Store metadata for configure.py build rules
        self.tile_width = bitmaps[0].width if bitmaps else 0
        self.tile_height = header.bmheight
        self.format_name = format_name
        self.aligner_mode = "df"
        self.dl_name = (
            self._resolve_name(header.rsp_dl, "dl") if header.rsp_dl else "NULL"
        )
        self.bitmaps_name = (
            self._resolve_name(header.bitmap, "bitmaps")
            if header.bitmap > 0x80000000
            else f"{self.name}_bitmaps"
        )
        self.has_sp_z = bool(header.attr & SpriteAttributes.SP_Z)
        self.has_sp_fastcopy = bool(header.attr & SpriteAttributes.SP_FASTCOPY)

        # Render the sprite to PNG plus a companion image containing clipped padding texels.
        canvas = bytearray(header.width * header.height * png_bpp)
        canvas = np.array(canvas).reshape(header.height, header.width, png_bpp)

        padding_row_width = 0
        current_row_width = 0
        current_padding_width = 0
        for bitmap in bitmaps:
            current_row_width += bitmap.width
            current_padding_width += max(bitmap.width_img - bitmap.width, 0)
            if current_row_width >= header.width:
                padding_row_width = max(padding_row_width, current_padding_width)
                current_row_width = 0
                current_padding_width = 0
        padding_row_width = max(padding_row_width, current_padding_width)
        padding_row_width = max(padding_row_width, 1)

        padding_canvas = bytearray(padding_row_width * header.height * png_bpp)
        padding_canvas = np.array(padding_canvas).reshape(
            header.height, padding_row_width, png_bpp
        )

        palette = None
        if header.LUT:
            lut_rom = self._resolve_rom(header.LUT)
            assert lut_rom is not None
            palette = bytearray(rom_bytes[lut_rom : lut_rom + header.nTLUT * 2])

        aligners = set()
        for bitmap in bitmaps:
            buf_rom = self._resolve_rom(bitmap.buf)
            assert buf_rom is not None
            aligner = bytes(rom_bytes[buf_rom - 8 : buf_rom])
            aligners.add(aligner)

        if aligners == {self.ZERO_ALIGNER}:
            self.aligner_mode = "zero"
        elif aligners == {self.DF_ALIGNER}:
            self.aligner_mode = "df"
        else:
            print(
                f"WARNING: {self.name}: mixed/unknown sprite aligners "
                f"{[a.hex() for a in sorted(aligners)]}, defaulting to df"
            )

        canvas_y = 0
        canvas_x = 0
        padding_x = 0
        for bitmap in bitmaps:
            buf_rom = self._resolve_rom(bitmap.buf)
            assert buf_rom is not None
            buf_size = bitmap.width_img * bitmap.actual_height * input_bpp
            input_bytes = rom_bytes[buf_rom : buf_rom + buf_size]

            tile = img_class(input_bytes, bitmap.width_img, bitmap.actual_height)
            if palette:
                tile.set_palette(palette, "big")

            pixels = tile.parse()
            pixels = np.array(bytearray(pixels)).reshape(
                bitmap.actual_height, bitmap.width_img, png_bpp
            )

            # un-swap the odd rows (reverse word-swap for TMEM interleaving)
            if input_bpp >= 2:
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

            canvas[
                canvas_y : canvas_y + bitmap.actual_height,
                canvas_x : canvas_x + bitmap.width,
            ] = pixels[0 : bitmap.actual_height, 0 : bitmap.width]

            pad_width = max(bitmap.width_img - bitmap.width, 0)
            if pad_width > 0:
                padding_canvas[
                    canvas_y : canvas_y + bitmap.actual_height,
                    padding_x : padding_x + pad_width,
                ] = pixels[
                    0 : bitmap.actual_height,
                    bitmap.width : bitmap.width_img,
                ]
                padding_x += pad_width

            canvas_x += bitmap.width
            if canvas_x >= header.width:
                canvas_x = 0
                padding_x = 0
                canvas_y += bitmap.actual_height

        canvas_img = img_class(bytearray(), header.width, header.height)
        padding_img = img_class(bytearray(), padding_row_width, header.height)
        if palette:
            canvas_img.set_palette(palette)
            padding_img.set_palette(palette)

        path = self.out_path()
        padding_path = self.padding_out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        with open(path, "wb") as f:
            canvas_img.get_writer().write_array(f, canvas.tobytes())
        with open(padding_path, "wb") as f:
            padding_img.get_writer().write_array(f, padding_canvas.tobytes())
