#!/usr/bin/env python3
"""Editable grayscale glyph atlas codec for UIText's low-nibble-first coverage.

Each atlas stacks 370 square glyphs vertically in UIText_CharTable order. Gray
levels 0..255 in steps of 17 represent coverage indices 0..15. These are not
hardware CI4 pixels: UIText_PrintChar16/32 read the low nibble before the high
nibble and blend their own foreground/shadow palettes at runtime.
"""
import argparse
from io import BytesIO
from pathlib import Path

import png


def decode(data, glyph_size):
    width, height = glyph_size, glyph_size * 370
    if len(data) != width * height // 2:
        raise ValueError('Incorrect font coverage byte count')
    pixels = [coverage * 17 for byte in data for coverage in (byte & 15, byte >> 4)]
    output = BytesIO()
    png.Writer(width, height, greyscale=True, bitdepth=8).write(
        output, (pixels[row * width:(row + 1) * width] for row in range(height)))
    return output.getvalue()


def encode(path, glyph_size):
    width, height, rows, _ = png.Reader(filename=str(path)).asRGBA8()
    if (width, height) != (glyph_size, glyph_size * 370):
        raise ValueError('Font atlas dimensions must retain all 370 glyphs in order')
    result = bytearray()
    for row in rows:
        coverage = []
        for index in range(0, len(row), 4):
            red, green, blue, alpha = row[index:index + 4]
            if red != green or red != blue or alpha != 255 or red % 17:
                raise ValueError('Font coverage must be opaque grayscale in steps of 17')
            coverage.append(red // 17)
        result.extend(coverage[i] | coverage[i + 1] << 4 for i in range(0, width, 2))
    return bytes(result)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('input', type=Path)
    parser.add_argument('output', type=Path)
    parser.add_argument('--glyph-size', type=int, choices=(8, 12), required=True)
    parser.add_argument('--c', action='store_true', help='write a native C image initializer include')
    args = parser.parse_args()
    data = encode(args.input, args.glyph_size)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    if args.c:
        args.output.write_text(''.join('    ' + ', '.join(f'0x{byte:02X}' for byte in data[i:i + 16]) + ',\n'
                                   for i in range(0, len(data), 16)))
    else:
        args.output.write_bytes(data)


if __name__ == '__main__':
    main()
