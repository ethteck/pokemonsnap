#!/usr/bin/env python3
"""
mksprite - Convert a PNG image into an N64 Sprite .inc.h file.

Usage:
    mksprite.py <input.png> -f <format> --tile-width <W> --tile-height <H>
                --padding <input.padding.png> --aligner <df|zero>
                --name <sprite_name> --dl <dl_name> -o <output.inc.h>

Produces a single .inc.h file containing:
  - Pixel data arrays for each tile (via pigment64 --c-array --word-swap)
  - Palette data (for CI formats)
  - Bitmap struct array
  - Display list declaration
  - Sprite struct
"""

import argparse
import math
import subprocess
import sys
import tempfile
from dataclasses import dataclass
from pathlib import Path

import png


FORMAT_INFO = {
    "rgba16": {
        "bpp": 2,
        "c_type": "unsigned short",
        "gbi_fmt": "G_IM_FMT_RGBA",
        "gbi_siz": "G_IM_SIZ_16b",
    },
    "rgba32": {
        "bpp": 4,
        "c_type": "unsigned short",
        "gbi_fmt": "G_IM_FMT_RGBA",
        "gbi_siz": "G_IM_SIZ_32b",
    },
    "i8": {
        "bpp": 1,
        "c_type": "unsigned char",
        "gbi_fmt": "G_IM_FMT_I",
        "gbi_siz": "G_IM_SIZ_8b",
    },
    "ia16": {
        "bpp": 2,
        "c_type": "unsigned short",
        "gbi_fmt": "G_IM_FMT_IA",
        "gbi_siz": "G_IM_SIZ_16b",
    },
    "ci8": {
        "bpp": 1,
        "c_type": "unsigned char",
        "gbi_fmt": "G_IM_FMT_CI",
        "gbi_siz": "G_IM_SIZ_8b",
    },
}


def crop_png(src_path: Path, dst_path: Path, x: int, y: int, w: int, h: int):
    """Crop a region from a PNG and write it to dst_path."""
    reader = png.Reader(filename=str(src_path))
    img_w, img_h, rows, info = reader.read()

    planes = info.get("planes", 3)
    has_alpha = info.get("alpha", False)
    greyscale = info.get("greyscale", False)
    palette = info.get("palette")
    bitdepth = info.get("bitdepth", 8)

    all_rows = list(rows)

    cropped_rows = []
    for row_idx in range(y, min(y + h, img_h)):
        row = all_rows[row_idx]
        if palette:
            row_data = list(row[x : x + w])
            if len(row_data) < w:
                # Pad with last pixel when past image edge
                fill = row_data[-1] if row_data else 0
                row_data.extend([fill] * (w - len(row_data)))
            cropped_rows.append(row_data)
        else:
            row_data = list(row[x * planes : (x + w) * planes])
            if len(row_data) < w * planes:
                # Pad with last pixel when past image edge
                last_pixel = (
                    row_data[-(planes):] if len(row_data) >= planes else [0] * planes
                )
                while len(row_data) < w * planes:
                    row_data.extend(last_pixel)
            cropped_rows.append(row_data)

    writer_kwargs = {
        "width": w,
        "height": len(cropped_rows),
        "bitdepth": bitdepth,
        "greyscale": greyscale,
        "alpha": has_alpha,
    }
    if palette:
        writer_kwargs["palette"] = palette
        writer_kwargs["greyscale"] = False
        writer_kwargs["alpha"] = False

    writer = png.Writer(**writer_kwargs)
    with open(dst_path, "wb") as f:
        writer.write(f, cropped_rows)


def read_png_size(src_path: Path) -> tuple[int, int]:
    """Read a PNG's width and height."""
    reader = png.Reader(filename=str(src_path))
    img_w, img_h, _, _ = reader.read()
    return img_w, img_h


def _read_png_rgba_rows(png_path: Path) -> list[list[tuple[int, int, int, int]]]:
    """Read a PNG into rows of 8-bit RGBA tuples."""
    reader = png.Reader(filename=str(png_path))
    _, _, rows, info = reader.read()

    palette = info.get("palette")
    greyscale = info.get("greyscale", False)
    has_alpha = info.get("alpha", False)
    planes = info.get("planes", 1)

    rgba_rows = []
    for row in rows:
        row_values = list(row)
        rgba_row = []

        if palette:
            for idx in row_values:
                color = palette[idx]
                if len(color) == 4:
                    r, g, b, a = color
                else:
                    r, g, b = color
                    a = 0xFF
                rgba_row.append((r, g, b, a))
        elif greyscale:
            step = 2 if has_alpha else 1
            for i in range(0, len(row_values), step):
                g = row_values[i]
                a = row_values[i + 1] if has_alpha else 0xFF
                rgba_row.append((g, g, g, a))
        else:
            step = planes
            for i in range(0, len(row_values), step):
                r = row_values[i]
                g = row_values[i + 1]
                b = row_values[i + 2]
                a = row_values[i + 3] if has_alpha and step > 3 else 0xFF
                rgba_row.append((r, g, b, a))

        rgba_rows.append(rgba_row)

    return rgba_rows


def _rgb2c_rgba16_tile(tile_png: Path, actual_w: int, padded_w: int) -> bytes:
    """Recreate rgb2c's readtex+printdata path for RGBA16 with -S 2 padding."""
    rgba_rows = _read_png_rgba_rows(tile_png)
    result = bytearray()

    odd_line = False
    for rgba_row in rgba_rows:
        red = [pixel[0] for pixel in rgba_row[:actual_w]]
        green = [pixel[1] for pixel in rgba_row[:actual_w]]
        blue = [pixel[2] for pixel in rgba_row[:actual_w]]
        alpha = [pixel[3] for pixel in rgba_row[:actual_w]]

        while len(red) < padded_w:
            red.append(red[-1])
            green.append(green[-1])
            blue.append(blue[-1])
            alpha.append(alpha[-1])

        shuffle_mask = 2 if odd_line else 0
        red_prev = 0
        green_prev = 0
        blue_prev = 0
        r_acc = 4
        g_acc = 4
        b_acc = 4

        for x in range(padded_w):
            src = shuffle_mask ^ x

            if red[src] == red_prev:
                r_acc = 4
            if green[src] == green_prev:
                g_acc = 4
            if blue[src] == blue_prev:
                b_acc = 4

            r_acc = min((r_acc & 7) + red[src], 0xFF)
            g_acc = min((g_acc & 7) + green[src], 0xFF)
            b_acc = min((b_acc & 7) + blue[src], 0xFF)

            red_prev = red[src]
            green_prev = green[src]
            blue_prev = blue[src]

            texel = (
                ((r_acc >> 3) << 11)
                | ((g_acc >> 3) << 6)
                | ((b_acc >> 3) << 1)
                | (alpha[src] >> 7)
            )
            result.extend(texel.to_bytes(2, "big"))

        odd_line = not odd_line

    return bytes(result)


def _concat_pngs_h(left_path: Path, right_path: Path, out_path: Path):
    """Concatenate two PNGs of the same height horizontally."""
    left_w, left_h, left_rows, left_info = png.Reader(filename=str(left_path)).read()
    right_w, right_h, right_rows, right_info = png.Reader(
        filename=str(right_path)
    ).read()

    if left_h != right_h:
        raise ValueError(f"PNG height mismatch: {left_h} != {right_h}")
    left_format = {k: v for k, v in left_info.items() if k != "size"}
    right_format = {k: v for k, v in right_info.items() if k != "size"}
    if left_format != right_format:
        raise ValueError("PNG format mismatch while concatenating tile padding")

    writer_kwargs = {
        "width": left_w + right_w,
        "height": left_h,
        "bitdepth": left_info.get("bitdepth", 8),
        "greyscale": left_info.get("greyscale", False),
        "alpha": left_info.get("alpha", False),
    }
    palette = left_info.get("palette")
    if palette:
        writer_kwargs["palette"] = palette
        writer_kwargs["greyscale"] = False
        writer_kwargs["alpha"] = False

    merged_rows = [
        list(left_row) + list(right_row)
        for left_row, right_row in zip(left_rows, right_rows)
    ]
    with open(out_path, "wb") as f:
        png.Writer(**writer_kwargs).write(f, merged_rows)


def _build_tile_from_padding_image(
    tile_png: Path,
    padding_png: Path,
    fmt: str,
    padded_w: int,
    actual_h: int,
    padding_x: int,
    padding_y: int,
    tmpdir: Path,
) -> bytes:
    """Build a tile using explicit padding texels extracted from snap_sprite."""
    pad_w = padded_w - read_png_size(tile_png)[0]
    merged_tile_png = tile_png
    if pad_w > 0:
        pad_tile_png = tmpdir / f"{tile_png.stem}.padding.png"
        crop_png(padding_png, pad_tile_png, padding_x, padding_y, pad_w, actual_h)
        merged_tile_png = tmpdir / f"{tile_png.stem}.merged.png"
        _concat_pngs_h(tile_png, pad_tile_png, merged_tile_png)

    tile_bin = tmpdir / f"{tile_png.stem}.bin"
    pigment64_to_bin(merged_tile_png, fmt, tile_bin, word_swap=True)
    return tile_bin.read_bytes()


def pigment64_to_bin(
    png_path: Path, fmt: str, output_path: Path, word_swap: bool = False
):
    """Run pigment64 to convert a PNG tile to raw binary."""
    command = ["pigment64", "to-bin", "-f", fmt, "-o", str(output_path)]
    if word_swap:
        command.append("--word-swap")
    command.append(str(png_path))
    result = subprocess.run(
        command,
        capture_output=True,
        text=True,
    )
    if result.returncode != 0:
        print(f"pigment64 error: {result.stderr}", file=sys.stderr)
        sys.exit(1)


def pigment64_palette(png_path: Path, output_path: Path):
    """Extract palette from a CI PNG as raw binary."""
    pigment64_to_bin(png_path, "palette", output_path)


def format_bin_as_u16_array(bin_path: Path) -> str:
    """Format raw binary as a u16 C array."""
    with open(bin_path, "rb") as f:
        data = f.read()
    words = []
    for i in range(0, len(data), 2):
        val = (data[i] << 8) | data[i + 1] if i + 1 < len(data) else data[i] << 8
        words.append(f"0x{val:04X}")
    lines = []
    for i in range(0, len(words), 8):
        lines.append("    " + ", ".join(words[i : i + 8]) + ",")
    return "\n".join(lines)


@dataclass
class TileData:
    """Raw tile data produced by build_sprite_tiles."""

    actual_w: int
    padded_w: int
    actual_h: int
    data: bytes  # raw pixel data, padded_w * actual_h * bpp bytes


@dataclass
class SpriteData:
    """Structured sprite data, ready for formatting."""

    img_w: int
    img_h: int
    tile_w: int
    tile_h: int
    fmt: str
    tiles: list  # list of TileData
    palette: bytes | None  # raw palette bytes, or None


def build_sprite_tiles(
    input_png: Path,
    fmt: str,
    tile_w: int,
    tile_h: int,
    padding_png: Path | None = None,
) -> SpriteData:
    """Convert a PNG into structured sprite tile data."""
    fmt_info = FORMAT_INFO[fmt]
    bpp = fmt_info["bpp"]
    is_ci = fmt.startswith("ci")

    reader = png.Reader(filename=str(input_png))
    img_w, img_h, _, _ = reader.read()

    padding_img_w = padding_img_h = 0
    if padding_png is not None:
        padding_img_w, padding_img_h = read_png_size(padding_png)
        if padding_img_h != img_h:
            raise ValueError(
                f"Padding image height mismatch: {padding_img_h} != {img_h}"
            )

    cols = math.ceil(img_w / tile_w)
    rows = math.ceil(img_h / tile_h)

    palette = None
    tiles = []

    with tempfile.TemporaryDirectory() as tmpdir:
        tmpdir = Path(tmpdir)

        if is_ci:
            pal_bin = tmpdir / "palette.bin"
            pigment64_palette(input_png, pal_bin)
            with open(pal_bin, "rb") as f:
                palette = f.read()

        for row in range(rows):
            padding_x = 0
            for col in range(cols):
                x = col * tile_w
                y = row * tile_h
                actual_w = min(tile_w, img_w - x)
                actual_h = min(tile_h, img_h - y)
                # Round to 64-bit row alignment: 4 texels for 2bpp, 8 for 1bpp
                align = 8 // bpp
                padded_w = (actual_w + align - 1) // align * align
                pad_w = padded_w - actual_w

                tile_png = tmpdir / f"tile_{row}_{col}.png"
                crop_png(input_png, tile_png, x, y, actual_w, actual_h)

                if padding_png is not None:
                    assert padding_png is not None
                    if padding_x + pad_w > padding_img_w:
                        raise ValueError(
                            f"Padding image too narrow for tile {row},{col}: need {padding_x + pad_w}, have {padding_img_w}"
                        )
                    tile_bytes = _build_tile_from_padding_image(
                        tile_png,
                        padding_png,
                        fmt,
                        padded_w,
                        actual_h,
                        padding_x,
                        y,
                        tmpdir,
                    )
                elif fmt == "rgba16":
                    tile_bytes = _rgb2c_rgba16_tile(tile_png, actual_w, padded_w)
                else:
                    padded_tile_png = tmpdir / f"tile_{row}_{col}.padded.png"
                    crop_png(input_png, padded_tile_png, x, y, padded_w, actual_h)
                    tile_bin = tmpdir / f"tile_{row}_{col}.bin"
                    pigment64_to_bin(padded_tile_png, fmt, tile_bin, word_swap=True)
                    tile_bytes = tile_bin.read_bytes()

                tiles.append(TileData(actual_w, padded_w, actual_h, tile_bytes))
                padding_x += pad_w

    return SpriteData(img_w, img_h, tile_w, tile_h, fmt, tiles, palette)


def format_bytes_as_c(data: bytes, c_type: str) -> str:
    """Format raw bytes as a C array body."""
    if c_type == "unsigned short":
        words = []
        for i in range(0, len(data), 2):
            val = (data[i] << 8) | data[i + 1] if i + 1 < len(data) else data[i] << 8
            words.append(f"0x{val:04X}")
        lines = []
        for i in range(0, len(words), 8):
            lines.append("    " + ", ".join(words[i : i + 8]) + ",")
        return "\n".join(lines)
    else:
        bytes_list = [f"0x{b:02X}" for b in data]
        lines = []
        for i in range(0, len(bytes_list), 16):
            lines.append("    " + ", ".join(bytes_list[i : i + 16]) + ",")
        return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description="Convert PNG to N64 Sprite .inc.h")
    parser.add_argument("input", type=Path, help="Input PNG file")
    parser.add_argument("-f", "--format", required=True, choices=FORMAT_INFO.keys())
    parser.add_argument("--tile-width", type=int, required=True)
    parser.add_argument("--tile-height", type=int, required=True)
    parser.add_argument("--padding", type=Path, required=True, help="Padding PNG file")
    parser.add_argument("--aligner", choices=("df", "zero"), default="df")
    parser.add_argument("--name", required=True, help="Sprite variable name")
    parser.add_argument("--dl", required=True, help="Display list variable name")
    parser.add_argument("--fastcopy", action=argparse.BooleanOptionalAction, default=True)
    parser.add_argument("--z", action=argparse.BooleanOptionalAction, default=True)
    parser.add_argument("--transparent", action=argparse.BooleanOptionalAction, default=False)
    parser.add_argument("-o", "--output", type=Path, required=True)
    args = parser.parse_args()

    fmt_info = FORMAT_INFO[args.format]
    is_ci = args.format.startswith("ci")

    sprite = build_sprite_tiles(
        args.input, args.format, args.tile_width, args.tile_height, args.padding
    )

    out_lines = []
    out_lines.append(f"/* Generated by mksprite from {args.input.name} */")
    out_lines.append("")

    if sprite.palette is not None:
        out_lines.append(f"static unsigned short {args.name}_pal[] = {{")
        out_lines.append(format_bytes_as_c(sprite.palette, "unsigned short"))
        out_lines.append("};")
        out_lines.append("")

    tile_names = []
    for i, tile in enumerate(sprite.tiles):
        row = i // math.ceil(sprite.img_w / sprite.tile_w)
        col = i % math.ceil(sprite.img_w / sprite.tile_w)
        tile_name = f"{args.name}_bm{row}_{col}"
        tile_names.append((tile_name, tile))

        c_array = format_bytes_as_c(tile.data, fmt_info["c_type"])
        if args.aligner == "df":
            out_lines.append(
                f"static Gfx {tile_name}_C_dummy_aligner[] = {{ gsSPEndDisplayList() }};"
            )
        else:
            out_lines.append(
                f"static u8 {tile_name}_C_dummy_aligner[] = {{ 0, 0, 0, 0, 0, 0, 0, 0 }};"
            )
        out_lines.append(f"{fmt_info['c_type']} {tile_name}[] = {{")
        out_lines.append(c_array)
        out_lines.append("};")
        out_lines.append("")

    # Bitmap struct array
    out_lines.append(f"Bitmap {args.name}_bitmaps[] = {{")
    for tile_name, tile in tile_names:
        out_lines.append(
            f"    {{ {tile.actual_w}, {tile.padded_w}, 0, 0, (u8*){tile_name}, {tile.actual_h}, 0 }},"
        )
    out_lines.append("};")
    out_lines.append("")

    nbitmaps = len(tile_names)
    out_lines.append(
        f"#define NUM_{args.name}_BMS  (sizeof({args.name}_bitmaps) / sizeof(Bitmap))"
    )
    out_lines.append("")

    # Display list
    if args.dl != "NULL" and args.dl != "D_00000000":
        out_lines.append(f"extern Gfx {args.dl}[];")
        out_lines.append("")
        dl_ref = args.dl
    else:
        dl_ref = "NULL"

    # Sprite struct
    bmHreal = sprite.tile_h

    lut_line = f"0, 0, NULL" if not is_ci else f"0, 256, (u8*){args.name}_pal"

    out_lines.append(f"Sprite {args.name} = {{")
    out_lines.append(f"    0, 0,                          /* Position: x, y */")
    out_lines.append(
        f"    {sprite.img_w}, {sprite.img_h},                      /* Sprite size in texels (x, y) */"
    )
    out_lines.append(f"    1.0, 1.0,                      /* Sprite Scale: x, y */")
    out_lines.append(
        f"    0, 0,                          /* Sprite Explosion Spacing: x, y */"
    )
    attr_parts = ["SP_TEXSHUF"]
    if args.transparent:
        attr_parts.append("SP_TRANSPARENT")
    if args.z:
        attr_parts.append("SP_Z")
    if args.fastcopy:
        attr_parts.append("SP_FASTCOPY")
    out_lines.append(f"    {' | '.join(attr_parts)}, /* Sprite Attributes */")
    out_lines.append(f"    0x1234,                        /* Sprite Depth: Z */")
    out_lines.append(
        f"    255, 255, 255, 255,            /* Sprite Coloration: RGBA */"
    )
    out_lines.append(f"    {lut_line},  /* CLUT: start, length, address */")
    out_lines.append(
        f"    0, 1,                          /* Bitmap index: start, step */"
    )
    out_lines.append(f"    NUM_{args.name}_BMS,              /* Number of bitmaps */")
    out_lines.append(
        f"    NUM_DL(NUM_{args.name}_BMS),      /* Number of display list locations */"
    )
    out_lines.append(
        f"    {sprite.tile_h}, {bmHreal},                      /* Bitmap Height: used, physical */"
    )
    out_lines.append(f"    {fmt_info['gbi_fmt']},             /* Bitmap Format */")
    out_lines.append(f"    {fmt_info['gbi_siz']},            /* Bitmap Texel Size */")
    out_lines.append(f"    {args.name}_bitmaps,              /* Pointer to bitmaps */")
    out_lines.append(f"    {dl_ref},                        /* Display list memory */")
    out_lines.append(f"    NULL                           /* next_dl pointer */")
    out_lines.append(f"}};")
    out_lines.append("")

    args.output.parent.mkdir(parents=True, exist_ok=True)
    with open(args.output, "w") as f:
        f.write("\n".join(out_lines))

    print(
        f"Generated {args.output} ({len(sprite.tiles)} tiles, {sprite.img_w}x{sprite.img_h}, {args.format})"
    )


if __name__ == "__main__":
    main()
