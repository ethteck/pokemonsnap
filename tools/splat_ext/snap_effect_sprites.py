import struct
from pathlib import Path
from typing import List

import n64img.image
import yaml
from splat.segtypes.segment import Segment
from splat.util import options

from effect_sprites import SpriteData, get_format_name

DEBUG = False


def debug_print(*args, **kwargs):
    if DEBUG:
        print(*args, **kwargs)


def check_unaccounted_bytes(data, pos, end_pos, offset_alignment):
    if not DEBUG:
        return

    if pos != end_pos:
        if end_pos > pos:
            unaccounted_bytes = data[pos:end_pos]
            if any(x != 0 for x in unaccounted_bytes):
                debug_print(
                    f"      Unaccounted bytes (0x{pos:X} - 0x{end_pos:X}):"
                    + str(list(unaccounted_bytes))
                )
            else:
                if len(unaccounted_bytes) < 0x10 and end_pos % 0x10 == offset_alignment:
                    debug_print(
                        f"      Alignment zeros from 0x{pos:X} to 0x{end_pos:X} (len 0x{end_pos - pos:X})"
                    )
                    pass
                else:
                    raise ValueError(
                        f"      Zeros from 0x{pos:X} to 0x{end_pos:X} (len 0x{end_pos - pos:X})"
                    )
        else:
            raise ValueError("Nonlinear stuff")


def parse_sprites(data) -> List[SpriteData]:
    sprites = []
    pos = 0

    num_sprites = struct.unpack(">I", data[pos : pos + 4])[0]
    pos += 4

    sprite_offsets = []
    for i in range(num_sprites):
        sprite_offsets.append(struct.unpack(">I", data[pos : pos + 4])[0])
        pos += 4

    for i, offset in enumerate(sprite_offsets):
        debug_print(f"  sprite {i} offset 0x{offset:X}")
        frame_offsets = []
        palette_offsets = []

        if offset != pos:
            if offset > pos:
                leftover_bytes = data[pos:offset]
                debug_print(
                    f"    leftover bytes before sprite (len 0x{len(leftover_bytes):X}):"
                    + str(list(leftover_bytes))
                )
            else:
                raise ValueError("Nonlinear stuff")

        pos = offset
        num_frames, fmt, siz, width, height, flags = struct.unpack(
            ">IIIIII", data[pos : pos + 4 * 6]
        )
        pos += 4 * 6

        for j in range(num_frames):
            frame_offsets.append(struct.unpack(">I", data[pos : pos + 4])[0])
            pos += 4

        particle = SpriteData(fmt, siz, width, height, flags, [], [])
        debug_print(f"    fmt {fmt}, siz {siz}, flags {flags}")

        assert flags == 1 or (flags == 0 and fmt == 2 and siz == 0)

        # flag 0 means non-indexed

        if siz == 0:
            bpp = 0.5
            if fmt == 2:
                # ci4
                pass
            elif fmt == 4:
                # i4
                pass
            else:
                raise ValueError("Unknown fmt")
        elif siz == 1:
            bpp = 1
            if fmt == 3:
                # ia8
                pass
            elif fmt == 4:
                # i8
                pass
            else:
                raise ValueError("Unknown fmt")
        elif siz == 2:
            bpp = 2
            if fmt == 0:
                # rgba16
                pass
            else:
                raise ValueError("Unknown fmt")
        elif siz == 3:
            bpp = 4
            if fmt == 0:
                # rgba32
                pass
            else:
                raise ValueError("Unknown fmt")
        else:
            raise ValueError("Unknown format")

        if fmt == 2:
            for p in range(num_frames):
                palette_offsets.append(struct.unpack(">I", data[pos : pos + 4])[0])
                pos += 4

        frame_offset_alignment = frame_offsets[0] % 0x10

        for o, frame_offset in enumerate(frame_offsets):
            debug_print(f"    frame {o} offset 0x{frame_offset:X}")
            check_unaccounted_bytes(data, pos, frame_offset, frame_offset_alignment)

            pos = frame_offset

            img_end_pos = int(pos + width * height * bpp)

            img_data = data[pos:img_end_pos]
            particle.frame_data.append(img_data)
            pos = img_end_pos

        for p, palette_offset in enumerate(palette_offsets):
            if siz == 0:
                palette_length = 0x20
            else:
                raise ValueError("Unknown format")

            debug_print(f"    palette {p} offset 0x{palette_offset:X}")
            check_unaccounted_bytes(data, pos, palette_offset, frame_offset_alignment)

            palette_end_pos = pos + palette_length

            palette_data = data[pos:palette_end_pos]
            particle.palette_data.append(palette_data)
            pos = palette_end_pos

        sprites.append(particle)

    if pos < len(data):
        debug_print(
            f"  Unaccounted bytes at end of file: (0x{pos:X})" + str(list(data[pos:]))
        )

    return sprites


class N64SegSnap_effect_sprites(Segment):
    def split(self, rom_bytes):
        out_path = options.opts.asset_path / self.dir / self.name
        if not out_path.exists():
            out_path.mkdir(parents=True)

        data = rom_bytes[self.rom_start : self.rom_end]
        sprites = parse_sprites(data)
        names = self.args

        sprites_yaml = []

        if len(sprites) != len(names):
            raise ValueError(
                f"{self.name}: Number of sprites ({len(sprites)}) does not match number of names ({len(names)}) (val '{self.args}')"
            )

        for i, sprite in enumerate(sprites):
            sprite_name = names[i]

            for i, frame_data in enumerate(sprite.frame_data):
                frame_path = Path(out_path / f"{sprite_name}-{i:02d}.png")

                fmt_name = get_format_name(sprite.fmt, sprite.siz)

                if fmt_name not in n64img.image.__dict__:
                    raise ValueError(f"Unknown format {fmt_name}")

                img_cls = n64img.image.__dict__[fmt_name]
                img = img_cls(frame_data, sprite.width, sprite.height)

                if sprite.palette_data:
                    img.set_palette(sprite.palette_data[i])

                img.write(frame_path)

            sprites_yaml.append(
                {
                    "name": sprite_name,
                    "type": get_format_name(sprite.fmt, sprite.siz),
                }
            )

        yaml_path = Path(out_path / "config.yaml")
        with open(yaml_path, "w") as f:
            f.write(yaml.dump(sprites_yaml, sort_keys=False))

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / self.name
