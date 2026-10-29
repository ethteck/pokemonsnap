import math
import sys
from dataclasses import dataclass
from enum import IntEnum, IntFlag
from io import BytesIO
from pathlib import Path
from struct import unpack

import n64img.image
import numpy as np
from splat.segtypes.segment import Segment
from splat.util import options

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from rgb2c import decode_rgba16_row  # noqa: E402


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
    LUT: int
    istart: int
    istep: int
    nbitmaps: int
    ndisplist: int
    bmheight: int
    bmHreal: int
    bmfmt: IM_FMT
    bmsiz: IM_SIZ
    bitmap: int
    rsp_dl: int
    rsp_dl_next: int
    frac_s: int
    frac_t: int

    def unpack(self, io: BytesIO):
        self.x, self.y = unpack(">hh", io.read(4))
        self.width, self.height = unpack(">hh", io.read(4))
        self.scalex, self.scaley = unpack(">ff", io.read(8))
        self.expx, self.expy = unpack(">hh", io.read(4))
        (attr,) = unpack(">H", io.read(2))
        (self.zdepth,) = unpack(">h", io.read(2))
        self.red, self.green, self.blue, self.alpha = unpack(">BBBB", io.read(4))
        self.startTLUT, self.nTLUT, self.LUT = unpack(">hhI", io.read(8))
        self.istart, self.istep = unpack(">hh", io.read(4))
        (self.nbitmaps,) = unpack(">H", io.read(2))
        (self.ndisplist,) = unpack(">H", io.read(2))
        self.bmheight, self.bmHreal = unpack(">hh", io.read(4))
        (bmfmt,) = unpack(">B", io.read(1))
        (bmsiz,) = unpack(">B", io.read(1))
        io.read(2)
        (self.bitmap,) = unpack(">I", io.read(4))
        (self.rsp_dl,) = unpack(">I", io.read(4))
        (self.rsp_dl_next,) = unpack(">I", io.read(4))
        self.frac_s, self.frac_t = unpack(">hh", io.read(4))

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

    def __init__(self, rom_start, rom_end, type, name, vram_start, args, yaml, **kwargs):
        super().__init__(rom_start, rom_end, type, name, vram_start, args, yaml, **kwargs)
        assert (
            isinstance(yaml, dict) and "header_rom" in yaml
        ), f"snap_sprite segment at 0x{rom_start:X} missing required 'header_rom' in YAML"
        self.header_rom: int = yaml["header_rom"]
        self.override_name = yaml.get("name")
        self._metadata = None

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.png"

    def _resolve_rom(self, vram_addr: int) -> int | None:
        """Convert VRAM to ROM, falling back to the top-level parent segment."""
        result = self.ram_to_rom(vram_addr)
        if result is None:
            result = self.get_most_parent().ram_to_rom(vram_addr)
        return result

    def _resolve_name(self, vram_addr: int) -> str:
        """Resolve a VRAM address to a symbol name, with fallback."""
        sym = self.get_symbol(vram_addr, in_segment=True)
        if sym:
            return sym.name
        rom = self._resolve_rom(vram_addr)
        if rom is not None:
            return f"D_{vram_addr:08X}_{rom:X}"
        return f"D_{vram_addr:08X}"

    def load_metadata(self, rom_bytes: bytes) -> bool:
        """Parse the sprite header and bitmap table and set the attributes
        configure.py needs for build rules (tile size, format, flags, ...).

        Separate from split() because splat skips split() for cached segments,
        while configure.py needs this metadata on every run. Returns False if
        the sprite format is unsupported (no metadata is set then)."""
        if self._metadata is not None:
            return True

        header = SpriteHeader()
        header_rom = self.header_rom
        header.unpack(BytesIO(rom_bytes[header_rom : header_rom + 0x44]))

        fmt = FORMAT_INFO.get((header.bmfmt, header.bmsiz))
        if fmt is None:
            print(
                f"Unsupported format: {header.bmfmt.name} {header.bmsiz.name} "
                f"for {self.name} at ROM 0x{self.rom_start:X}-0x{self.rom_end:X}"
            )
            return False

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

        # Resolve the name before anything derives names from it
        sprite_vram = self.get_most_parent().rom_to_ram(header_rom)
        assert sprite_vram is not None
        self.name = self._resolve_name(sprite_vram)
        if self.override_name:
            self.name = self.override_name

        self.tile_width = bitmaps[0].width if bitmaps else 0
        self.tile_height = header.bmheight
        self.format_name = fmt[3]
        self.has_dl = bool(header.rsp_dl)
        self.bitmaps_name = f"{self.name}_bitmaps"
        self.has_sp_z = bool(header.attr & SpriteAttributes.SP_Z)
        self.has_sp_fastcopy = bool(header.attr & SpriteAttributes.SP_FASTCOPY)
        self.has_sp_transparent = bool(header.attr & SpriteAttributes.SP_TRANSPARENT)
        self.has_sp_scale = bool(header.attr & SpriteAttributes.SP_SCALE)
        self.has_sp_overlap = bool(header.attr & SpriteAttributes.SP_OVERLAP)
        self.sp_x = int(header.x)
        self.sp_y = int(header.y)
        self.sp_color = (
            (header.red << 24)
            | (header.green << 16)
            | (header.blue << 8)
            | header.alpha
        )

        aligners = set()
        for bitmap in bitmaps:
            buf_rom = self._resolve_rom(bitmap.buf)
            assert buf_rom is not None
            aligners.add(bytes(rom_bytes[buf_rom - 8 : buf_rom]))
        if aligners == {self.ZERO_ALIGNER}:
            self.aligner_mode = "zero"
        elif aligners == {self.DF_ALIGNER}:
            self.aligner_mode = "df"
        else:
            self.aligner_mode = "df"
            print(
                f"WARNING: {self.name}: mixed/unknown sprite aligners "
                f"{[a.hex() for a in sorted(aligners)]}, defaulting to df"
            )

        self._metadata = (header, bitmaps, fmt)
        return True

    def split(self, rom_bytes: bytes):
        if not self.load_metadata(rom_bytes):
            return
        header, bitmaps, fmt = self._metadata
        png_bpp, input_bpp, img_class, format_name = fmt

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

        if header.bitmap > 0x80000000:
            sym = self.create_symbol(
                header.bitmap, in_segment=True, type="data", define=True
            )
            sym.given_name = self.bitmaps_name
        cols = math.ceil(header.width / self.tile_width) if self.tile_width > 0 else 1
        for i, bitmap in enumerate(bitmaps):
            row = i // cols
            col = i % cols
            sym = self.create_symbol(
                bitmap.buf, in_segment=True, type="data", define=True
            )
            sym.given_name = f"{self.name}_bm{row}_{col}"

        canvas = np.zeros((header.height, header.width, png_bpp), dtype=np.uint8)

        palette = None
        if header.LUT:
            lut_rom = self._resolve_rom(header.LUT)
            assert lut_rom is not None
            palette = bytearray(rom_bytes[lut_rom : lut_rom + header.nTLUT * 2])

        canvas_y = 0
        canvas_x = 0
        for bitmap in bitmaps:
            buf_rom = self._resolve_rom(bitmap.buf)
            assert buf_rom is not None
            buf_size = bitmap.width_img * bitmap.actual_height * input_bpp
            input_bytes = rom_bytes[buf_rom : buf_rom + buf_size]

            if format_name == "rgba16":
                pixels = self._decode_rgba16_tile(input_bytes, bitmap)
            else:
                pixels = self._decode_tile(
                    input_bytes, bitmap, img_class, palette, png_bpp, input_bpp
                )

            canvas[
                canvas_y : canvas_y + bitmap.actual_height,
                canvas_x : canvas_x + bitmap.width,
            ] = pixels[0 : bitmap.actual_height, 0 : bitmap.width]

            canvas_x += bitmap.width
            if canvas_x >= header.width:
                canvas_x = 0
                canvas_y += bitmap.actual_height

        canvas_img = img_class(bytearray(), header.width, header.height)
        if palette:
            canvas_img.set_palette(palette)

        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        with open(path, "wb") as f:
            canvas_img.get_writer().write_array(f, canvas.tobytes())

    def _decode_rgba16_tile(self, input_bytes: bytes, bitmap: Bitmap):
        """Recover 8-bit pixels that rgb2c turns back into these exact texels,
        padding and dither included."""
        w, W = bitmap.width, bitmap.width_img
        texels = unpack(f">{W * bitmap.actual_height}H", input_bytes)
        pixels = np.zeros((bitmap.actual_height, W, 4), dtype=np.uint8)
        for y in range(bitmap.actual_height):
            row = list(texels[y * W : (y + 1) * W])
            try:
                decoded = decode_rgba16_row(row, w, 2 if y % 2 else 0)
            except ValueError as e:
                raise ValueError(f"{self.name}: tile row {y}: {e}") from e
            pixels[y, :w] = decoded
        return pixels

    def _decode_tile(self, input_bytes, bitmap, img_class, palette, png_bpp, input_bpp):
        """Decode a dither-free tile and check its padding repeats the last
        texel of each row, as rgb2c generates it."""
        tile = img_class(input_bytes, bitmap.width_img, bitmap.actual_height)
        if palette:
            tile.set_palette(palette, "big")

        pixels = tile.parse()
        pixels = np.array(bytearray(pixels)).reshape(
            bitmap.actual_height, bitmap.width_img, png_bpp
        )

        # un-swap the odd rows (reverse word-swap for TMEM interleaving)
        group = 4 if input_bpp >= 2 else 8
        half = group // 2
        for y in range(1, len(pixels), 2):
            for x in range(0, len(pixels[0]), group):
                temp = np.copy(pixels[y][x : x + group])
                pixels[y][x : x + half] = temp[half:]
                pixels[y][x + half : x + group] = temp[:half]

        w = bitmap.width
        for y, row in enumerate(pixels):
            if not (row[w:] == row[w - 1]).all():
                raise ValueError(
                    f"{self.name}: padding of tile row {y} does not repeat the last pixel"
                )
        return pixels
