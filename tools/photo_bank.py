#!/usr/bin/env python3
"""Extract editable PhotoData/AlbumPhotoData scene snapshots and emit native C."""

import argparse
import json
import math
from pathlib import Path
import struct

ROM_START = 0xAE0510
ROM_END = 0xAEFC10
PHOTO_SIZE = 0x3A0
ALBUM_SIZE = 0x3E0
REPORT_COUNT = 4
ALBUM_COUNT = 60
ALBUM_OFFSET = REPORT_COUNT * PHOTO_SIZE
SCENES = ("SCENE_BEACH", "SCENE_TUNNEL", "SCENE_VOLCANO", "SCENE_RIVER",
          "SCENE_CAVE", "SCENE_VALLEY", "SCENE_RAINBOW")

def store(path, content):
    path.parent.mkdir(parents=True, exist_ok=True)
    if isinstance(content, str):
        content = content.encode()
    if not path.exists() or path.read_bytes() != content:
        path.write_bytes(content)


def signed(value, bits):
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def floats(data, offset, count):
    values = list(struct.unpack_from(f">{count}f", data, offset))
    if not all(math.isfinite(value) for value in values):
        raise ValueError(f"Non-finite scene float at ROM {ROM_START + offset:X}")
    return values


def decode_photo(data, offset):
    level, flags, reserved = struct.unpack_from(">BB2s", data, offset)
    if reserved != bytes(2):
        raise ValueError(f"Nonzero photo reserved bytes at ROM {ROM_START + offset + 2:X}")
    time, *camera = floats(data, offset + 4, 7)
    photo = dict(level_id=signed(level >> 1, 7), photo_flag=level & 1,
                 block_and_subject_flags=flags, capture_time=time,
                 camera_eye=camera[:3], camera_at=camera[3:],
                 pokemons=[], items=[], effects=[])
    for slot in range(12):
        address = offset + 0x20 + slot * 24
        word = struct.unpack_from(">I", data, address)[0]
        animation, x, y, z, yaw = floats(data, address + 4, 5)
        photo["pokemons"].append(dict(
            pokemon_id=signed(word >> 19, 13),
            unknown_flags=(word >> 13) & 0x3F,
            special_id=(word >> 8) & 0x1F, pose_id=word & 0xFF,
            animation_time=animation, position=[x, y, z], yaw=yaw))
    for slot in range(6):
        address = offset + 0x140 + slot * 16
        item_type, animation, reserved = struct.unpack_from(">bB2s", data, address)
        if reserved != bytes(2):
            raise ValueError(f"Nonzero ItemPhotoData implicit padding at ROM {ROM_START + address + 2:X}")
        photo["items"].append(dict(item_type=item_type,
                                   animation_time=animation,
                                   position=floats(data, address + 4, 3)))
    for slot in range(32):
        address = offset + 0x1A0 + slot * 16
        texture, data_id, bank, playback, x, y, z, size, r, g, b, a = struct.unpack_from(
            ">bBBBhhhH4B", data, address)
        photo["effects"].append(dict(texture_id=texture, data_id=data_id,
                                     bank_id=bank, packed_playback_flags=playback,
                                     position_eighths=[x, y, z], size_128ths=size,
                                     prim_color=[r, g, b, a]))
    return photo


def float_literal(value):
    # Nine decimal significant digits preserve binary32; retain signed zero.
    value = float(value)
    if not math.isfinite(value):
        raise ValueError("Scene float must be finite")
    text = format(value, ".9g")
    if "." not in text and "e" not in text:
        text += ".0"
    return text + "f"


def vector(values):
    return "{ " + ", ".join(float_literal(value) for value in values) + " }"


def emit_photo(photo, indent):
    if len(photo["pokemons"]) != 12 or len(photo["items"]) != 6 or len(photo["effects"]) != 32:
        raise ValueError("Photo must retain exactly twelve Pokémon, six items and thirty-two effects")
    level = photo["level_id"]
    scene = SCENES[level] if 0 <= level < len(SCENES) else str(level)
    lines = [indent + "{", indent + "    " +
             f'{scene}, {photo["photo_flag"]}, {photo["block_and_subject_flags"]}, {{ 0, 0 }},',
             indent + "    " + float_literal(photo["capture_time"]) + ",",
             indent + "    " + vector(photo["camera_eye"]) + ",",
             indent + "    " + vector(photo["camera_at"]) + ",",
             indent + "    { /* Pokémon slots, including stored inactive state. */"]
    for p in photo["pokemons"]:
        lines.append(indent + "        " +
                     f'{{ {p["pokemon_id"]}, {p["unknown_flags"]}, {p["special_id"]}, {p["pose_id"]}, '
                     + float_literal(p["animation_time"]) + ", " + vector(p["position"]) + ", "
                     + float_literal(p["yaw"]) + " },")
    lines += [indent + "    },", indent + "    { /* Item slots; native implicit padding is zero. */"]
    for item in photo["items"]:
        lines.append(indent + "        " + f'{{ {item["item_type"]}, {item["animation_time"]}, '
                     + vector(item["position"]) + " },")
    lines += [indent + "    },", indent + "    { /* Effects: position/size use the consumer's quantized units. */"]
    for effect in photo["effects"]:
        values = [effect["texture_id"], effect["data_id"], effect["bank_id"],
                  effect["packed_playback_flags"], *effect["position_eighths"], effect["size_128ths"]]
        lines.append(indent + "        { " + ", ".join(map(str, values)) + ", { "
                     + ", ".join(map(str, effect["prim_color"])) + " } },")
    lines += [indent + "    },", indent + "},"]
    return lines


def generate(args):
    spec = json.loads(args.input.read_text())
    if spec["schema"] != "remaining-ui-ae0510-scenes-v1":
        raise ValueError("Unexpected AE0510 editable scene schema")
    if len(spec["report_photos"]) != REPORT_COUNT or len(spec["album_photos"]) != ALBUM_COUNT:
        raise ValueError("Photo bank requires four report scenes and sixty album scenes")
    lines = ["/* Generated from decoded scenes, never from ROM or a packed blob. */",
             "{ /* reportPhotos[4] */"]
    for index, photo in enumerate(spec["report_photos"]):
        lines.append(f"    /* reportPhotos[{index}] */")
        lines += emit_photo(photo, "    ")
    lines += ["},", "{ /* albumPhotos[60] */"]
    for index, album in enumerate(spec["album_photos"]):
        if len(album["comment"]) != 32:
            raise ValueError("Album comment must retain exactly thirty-two s16 codepoints")
        lines.append(f"    {{ /* albumPhotos[{index}] */")
        lines += emit_photo(album["photo"], "        ")
        lines.append("        { { " + ", ".join(map(str, album["comment"])) + " } },")
        lines.append("    },")
    lines += ["},", ""]
    store(args.output, "\n".join(lines))


def extract(args):
    with args.input.open("rb") as rom:
        rom.seek(ROM_START)
        data = rom.read(ROM_END - ROM_START)
    if len(data) != ROM_END - ROM_START:
        raise ValueError("Truncated photo bank")
    spec = dict(schema="remaining-ui-ae0510-scenes-v1", report_photos=[], album_photos=[])
    for index in range(REPORT_COUNT):
        spec["report_photos"].append(decode_photo(data, index * PHOTO_SIZE))
    for index in range(ALBUM_COUNT):
        offset = ALBUM_OFFSET + index * ALBUM_SIZE
        photo = decode_photo(data, offset)
        comment = list(struct.unpack_from(">32h", data, offset + PHOTO_SIZE))
        spec["album_photos"].append(dict(photo=photo, comment=comment))
    store(args.output, json.dumps(spec, indent=2, allow_nan=False) + "\n")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    for name, action in (("extract", extract), ("generate", generate)):
        command = commands.add_parser(name)
        command.add_argument("--input", required=True, type=Path)
        command.add_argument("--output", required=True, type=Path)
        command.set_defaults(action=action)
    args = parser.parse_args()
    args.action(args)


if __name__ == "__main__":
    main()
