import glob
import struct
import sys
from dataclasses import dataclass
from pathlib import Path
from typing import List

import png
import yaml
from img import Converter


class BinaryBuilder:
    def __init__(self):
        self.data = bytearray()
        self.placeholders: dict[str, int] = {}

    def current_offset(self) -> int:
        return len(self.data)

    def write(self, data: bytes):
        self.data.extend(data)

    def reserve_offset(self, name: str):
        self.placeholders[name] = self.current_offset()
        self.write(b"\0" * 4)

    def fill_offset(self, name: str):
        offset = self.placeholders[name]
        self.data[offset : offset + 4] = struct.pack(
            f"{ENDIAN}I", self.current_offset()
        )


@dataclass
class SpriteData:
    fmt: int
    siz: int
    width: int
    height: int
    flags: int
    frame_data: List[bytearray]
    palette_data: List[bytearray]

    def write(self, sprite_num: int, builder: BinaryBuilder) -> bytes:
        if self.fmt == 2:
            assert self.flags == 0

        builder.write(
            struct.pack(
                f"{ENDIAN}IIIIII",
                len(self.frame_data),
                self.fmt,
                self.siz,
                self.width,
                self.height,
                self.flags,
            )
        )

        for i, frame in enumerate(self.frame_data):
            builder.reserve_offset(f"sprite{sprite_num}_frame{i}")

        if self.fmt == 2:
            for i, palette in enumerate(self.palette_data):
                builder.reserve_offset(f"sprite{sprite_num}_palette{i}")

        if builder.current_offset() % 8 != 0:
            builder.write(b"\0" * (8 - (builder.current_offset() % 8)))

        for i, frame in enumerate(self.frame_data):
            builder.fill_offset(f"sprite{sprite_num}_frame{i}")
            builder.write(frame)

        if self.fmt == 2:
            for i, palette in enumerate(self.palette_data):
                builder.fill_offset(f"sprite{sprite_num}_palette{i}")
                builder.write(palette)


NAME_TO_PARAMS = {
    "CI4": (2, 0),
    "IA4": (3, 0),
    "I4": (4, 0),
    "CI8": (2, 1),
    "IA8": (3, 1),
    "I8": (4, 1),
    "RGBA16": (0, 2),
    "RGBA32": (0, 3),
}

ENDIAN = ">"


def get_format_params(name):
    if name not in NAME_TO_PARAMS:
        raise ValueError(f"Unknown format {name}")
    return NAME_TO_PARAMS[name]


def get_format_name(fmt, siz):
    for name, params in NAME_TO_PARAMS.items():
        if params == (fmt, siz):
            return name
    raise ValueError(f"Unknown format {fmt} {siz}")


def parse_sprites(sprites_dir, config) -> list[SpriteData]:
    sprites = []

    for sprite_config in config:
        sprite_name = sprite_config["name"]
        sprite_type = sprite_config["type"]
        fmt, siz = get_format_params(sprite_type)
        frame_imgs = glob.glob(f"{sprites_dir}/{sprite_name}-*.png")
        frame_imgs.sort()
        frame_data = []
        palette_data = []
        sprite_width = None
        sprite_height = None

        if len(frame_imgs) == 0:
            raise ValueError(f"No frames found for {sprite_name}")

        for img_file in frame_imgs:
            img = png.Reader(img_file)
            width, height, img_data, _ = img.read_flat()

            if sprite_width is None:
                sprite_width = width
                sprite_height = height
            elif width != sprite_width or height != sprite_height:
                raise ValueError(f"Frame {img_file} has different dimensions")

            (out_img, _, _) = Converter(
                mode=sprite_type.lower(), infile=img_file
            ).convert()
            frame_data.append(out_img)
            if fmt == 2:
                (out_pal, _, _) = Converter(mode="palette", infile=img_file).convert()
                palette_data.append(out_pal)

        sprites.append(
            SpriteData(
                fmt=fmt,
                siz=siz,
                width=sprite_width,
                height=sprite_height,
                flags=fmt != 2,
                frame_data=frame_data,
                palette_data=palette_data,
            )
        )

    return sprites


if __name__ == "__main__":
    sprites_dir = sys.argv[1]
    output_file = sys.argv[2]

    with open(Path(sprites_dir) / "config.yaml") as f:
        config = yaml.safe_load(f)

    sprites = parse_sprites(sprites_dir, config)

    builder = BinaryBuilder()
    # num sprites
    builder.write(struct.pack(f"{ENDIAN}I", len(sprites)))

    # sprite offsets
    for i, sprite in enumerate(sprites):
        builder.reserve_offset("sprite" + str(i))

    # align to 0x8
    if builder.current_offset() % 8 != 0:
        builder.write(struct.pack(f"{ENDIAN}I", sprites[0].fmt))

    # sprite data
    for i, sprite in enumerate(sprites):
        builder.fill_offset("sprite" + str(i))
        sprite.write(i, builder)

    if builder.current_offset() % 0x10 != 0:
        builder.write(b"\0" * (0x10 - (builder.current_offset() % 0x10)))

    with open(output_file, "wb") as f:
        f.write(builder.data)
