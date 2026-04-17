#!/usr/bin/env -S uv run --script
# /// script
# requires-python = ">=3.11"
# ///
"""
Test harness for reproducing rgb2c's RGBA16 padding algorithm.

Reads sprite headers from ROM, decodes tiles, runs a candidate algorithm
per row, and compares output against the original ROM bytes.
"""
from __future__ import annotations

import argparse
import struct
from dataclasses import dataclass
from enum import IntEnum
from pathlib import Path


class IM_FMT(IntEnum):
    G_IM_FMT_RGBA = 0
    G_IM_FMT_CI = 2
    G_IM_FMT_IA = 3
    G_IM_FMT_I = 4


class IM_SIZ(IntEnum):
    G_IM_SIZ_4b = 0
    G_IM_SIZ_8b = 1
    G_IM_SIZ_16b = 2
    G_IM_SIZ_32b = 3


FORMAT_BPP = {
    (IM_FMT.G_IM_FMT_RGBA, IM_SIZ.G_IM_SIZ_16b): 2,
    (IM_FMT.G_IM_FMT_RGBA, IM_SIZ.G_IM_SIZ_32b): 4,
    (IM_FMT.G_IM_FMT_I, IM_SIZ.G_IM_SIZ_8b): 1,
    (IM_FMT.G_IM_FMT_IA, IM_SIZ.G_IM_SIZ_16b): 2,
    (IM_FMT.G_IM_FMT_CI, IM_SIZ.G_IM_SIZ_8b): 1,
}


@dataclass
class Bitmap:
    width: int
    width_img: int
    s: int
    t: int
    buf: int
    actual_height: int
    lut_offset: int


@dataclass
class SpriteHeader:
    x: int
    y: int
    width: int
    height: int
    scalex: float
    scaley: float
    expx: int
    expy: int
    attr: int
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


def read_sprite_header(rom: bytes, rom_offset: int) -> SpriteHeader:
    """Parse a 0x40-byte Sprite struct from ROM."""
    data = rom[rom_offset : rom_offset + 0x40]
    (x, y) = struct.unpack(">hh", data[0:4])
    (width, height) = struct.unpack(">hh", data[4:8])
    (scalex, scaley) = struct.unpack(">ff", data[8:16])
    (expx, expy) = struct.unpack(">hh", data[16:20])
    (attr,) = struct.unpack(">H", data[20:22])
    (zdepth,) = struct.unpack(">h", data[22:24])
    (red, green, blue, alpha) = struct.unpack(">BBBB", data[24:28])
    (startTLUT, nTLUT, LUT) = struct.unpack(">hhI", data[28:36])
    (istart, istep) = struct.unpack(">hh", data[36:40])
    (nbitmaps,) = struct.unpack(">H", data[40:42])
    (ndisplist,) = struct.unpack(">H", data[42:44])
    (bmheight, bmHreal) = struct.unpack(">hh", data[44:48])
    (bmfmt,) = struct.unpack(">B", data[48:49])
    (bmsiz,) = struct.unpack(">B", data[49:50])
    (bitmap,) = struct.unpack(">I", data[52:56])
    (rsp_dl,) = struct.unpack(">I", data[56:60])
    (rsp_dl_next,) = struct.unpack(">I", data[60:64])

    return SpriteHeader(
        x, y, width, height, scalex, scaley, expx, expy, attr, zdepth,
        red, green, blue, alpha, startTLUT, nTLUT, LUT, istart, istep,
        nbitmaps, ndisplist, bmheight, bmHreal,
        IM_FMT(bmfmt), IM_SIZ(bmsiz), bitmap, rsp_dl, rsp_dl_next,
    )


def read_bitmap(rom: bytes, rom_offset: int) -> Bitmap:
    """Parse a 0x10-byte Bitmap struct from ROM."""
    data = rom[rom_offset : rom_offset + 0x10]
    (width, width_img, s, t, buf, actual_height, lut_offset) = struct.unpack(
        ">hhhhIhh", data
    )
    return Bitmap(width, width_img, s, t, buf, actual_height, lut_offset)


def vram_to_rom(vram: int, header_vram: int, header_rom: int) -> int:
    """Convert VRAM address to ROM offset using header as anchor."""
    return header_rom + (vram - header_vram)


# --- RGBA16 codec ---

def decode_rgba16_texel(hi: int, lo: int) -> tuple[int, int, int, int]:
    """Decode one RGBA16 texel to (r5, g5, b5, a1)."""
    texel = (hi << 8) | lo
    r = (texel >> 11) & 0x1F
    g = (texel >> 6) & 0x1F
    b = (texel >> 1) & 0x1F
    a = texel & 0x01
    return (r, g, b, a)


def encode_rgba16_row_rgb2c(
    source_8bit: list[tuple[int, int, int, int]],
    padded_w: int,
    odd_row: bool,
) -> bytes:
    """
    Encode a row via rgb2c's accumulator algorithm with -S 2 shuffle.

    source_8bit: list of (r8, g8, b8, a8) for visible pixels.
    Returns padded_w * 2 bytes.
    """
    red = [p[0] for p in source_8bit]
    green = [p[1] for p in source_8bit]
    blue = [p[2] for p in source_8bit]
    alpha = [p[3] for p in source_8bit]

    while len(red) < padded_w:
        red.append(red[-1])
        green.append(green[-1])
        blue.append(blue[-1])
        alpha.append(alpha[-1])

    shuffle_mask = 2 if odd_row else 0
    r_prev = g_prev = b_prev = 0
    r_acc = g_acc = b_acc = 4

    result = bytearray()
    for x in range(padded_w):
        src = shuffle_mask ^ x
        if red[src] == r_prev:
            r_acc = 4
        if green[src] == g_prev:
            g_acc = 4
        if blue[src] == b_prev:
            b_acc = 4
        r_acc = min((r_acc & 7) + red[src], 0xFF)
        g_acc = min((g_acc & 7) + green[src], 0xFF)
        b_acc = min((b_acc & 7) + blue[src], 0xFF)
        r_prev = red[src]
        g_prev = green[src]
        b_prev = blue[src]

        texel = (
            ((r_acc >> 3) << 11)
            | ((g_acc >> 3) << 6)
            | ((b_acc >> 3) << 1)
            | ((alpha[src] >> 7) & 1)
        )
        result.extend(texel.to_bytes(2, "big"))
    return bytes(result)


def unshuffle_row(row_5bit: list[tuple[int, int, int, int]]) -> list[tuple[int, int, int, int]]:
    """Reverse rgb2c's -S 2 shuffle on an odd row (swap pairs of 2 in each group of 4)."""
    out = list(row_5bit)
    for i in range(0, len(out), 4):
        if i + 3 < len(out):
            out[i], out[i + 1], out[i + 2], out[i + 3] = out[i + 2], out[i + 3], out[i], out[i + 1]
    return out


def upscale_5to8(r5: int, g5: int, b5: int, a1: int) -> tuple[int, int, int, int]:
    """Upscale 5-bit RGB + 1-bit alpha to 8-bit via bit replication."""
    return (
        (r5 << 3) | (r5 >> 2),
        (g5 << 3) | (g5 >> 2),
        (b5 << 3) | (b5 >> 2),
        0xFF if a1 else 0x00,
    )


# --- Algorithm stub ---

def tweak_row(
    visible_8bit: list[tuple[int, int, int, int]],
    target_row_bytes: bytes,
    padded_w: int,
    odd_row: bool,
) -> bytes:
    """
    Produce candidate encoding for this row.

    visible_8bit: visible pixels upscaled from decoded 5-bit (high 5 bits known, low 3 unknown).
    target_row_bytes: the actual bytes from ROM (what rgb2c produced).
    padded_w: column-aligned width.
    odd_row: whether shuffle_mask is 2.

    Returns our candidate output bytes for comparison.
    """
    return encode_rgba16_row_rgb2c(visible_8bit, padded_w, odd_row)


# --- Sprite data from snap_sprite dump ---

SPRITE_HEADERS = [
    (10001112, 2149335736),
    (10005472, 2149340096),
    (10048192, 2149472336),
    (10049128, 2149473272),
    (10049568, 2149473712),
    (10049872, 2149474016),
    (10100200, 2149524344),
    (10101024, 2149525168),
    (10101632, 2149525776),
    (10101856, 2149526000),
    (10102080, 2149526224),
    (10106240, 2149530384),
    (10151784, 2149467416),
    (10188704, 2149504336),
    (10211192, 2149526824),
    (10211800, 2149527432),
    (10212184, 2149527816),
    (10212568, 2149528200),
    (10212952, 2149528584),
    (10213336, 2149528968),
    (10227104, 2149542736),
    (10245152, 2149560784),
    (10263648, 2149579280),
    (10264064, 2149579696),
    (10264272, 2149579904),
    (10265256, 2149580888),
    (10266192, 2149581824),
    (10266632, 2149582264),
    (10266936, 2149582568),
    (10271096, 2149586728),
    (10300768, 2149616400),
    (10332344, 2149465928),
    (10352864, 2149486448),
    (10372816, 2149506400),
    (10373216, 2149506800),
    (10373824, 2149507408),
    (10379584, 2149513168),
    (10385344, 2149518928),
    (10390504, 2149524088),
    (10395664, 2149529248),
    (10396112, 2149529696),
    (10396544, 2149530128),
    (10396928, 2149530512),
    (10401464, 2149535048),
    (10402448, 2149536032),
    (10403384, 2149536968),
    (10403824, 2149537408),
    (10404128, 2149537712),
    (10408280, 2149541864),
    (10412432, 2149546016),
    (10416584, 2149550168),
    (10420736, 2149554320),
    (10424888, 2149558472),
    (10429040, 2149562624),
    (10458712, 2149592296),
    (10509736, 2149482728),
    (10510176, 2149483168),
    (10510480, 2149483472),
    (10511088, 2149484080),
    (10511696, 2149484688),
    (10512304, 2149485296),
    (10512912, 2149485904),
    (10513520, 2149486512),
    (10513744, 2149486736),
    (10513968, 2149486960),
    (10518128, 2149491120),
    (11029552, 2148571264),
    (11088712, 2148630424),
    (11088920, 2148630632),
    (11127832, 2149474392),
    (11128816, 2149475376),
    (11129752, 2149476312),
    (11138832, 2149485392),
    (11183288, 2149471352),
    (5272064, 2151050736),
    (5274000, 2151052672),
    (5275936, 2151054608),
    (5276112, 2151054784),
    (5276744, 2151055416),
    (5311216, 2151089888),
    (5345688, 2151124360),
    (5346024, 2151124696),
    (5352880, 2151131552),
    (5359736, 2151138408),
    (5363376, 2151142048),
    (5367016, 2151145688),
    (5370656, 2151149328),
    (5374296, 2151152968),
    (5377936, 2151156608),
    (5381576, 2151160248),
    (5381992, 2151160664),
    (5386184, 2151164856),
    (5390168, 2151168840),
    (5391832, 2151170504),
    (5395064, 2151173736),
    (5398296, 2151176968),
    (5401528, 2151180200),
    (5404760, 2151183432),
    (5407992, 2151186664),
    (5411344, 2151190016),
    (5411696, 2151190368),
    (5412048, 2151190720),
    (5412400, 2151191072),
    (5412752, 2151191424),
    (5413104, 2151191776),
    (5413456, 2151192128),
    (5413808, 2151192480),
    (5414160, 2151192832),
    (5414512, 2151193184),
    (5414864, 2151193536),
    (5415216, 2151193888),
    (5415568, 2151194240),
    (5415920, 2151194592),
    (5424160, 2151202832),
    (5454392, 2151233064),
    (8126632, 2150525720),
    (8128168, 2150527256),
    (8129704, 2150528792),
    (8131240, 2150530328),
    (8132776, 2150531864),
    (8134312, 2150533400),
    (8135848, 2150534936),
    (8138056, 2150537144),
    (8140264, 2150539352),
    (8142472, 2150541560),
    (8144680, 2150543768),
    (8146888, 2150545976),
    (8149096, 2150548184),
    (8149608, 2150548696),
    (8727128, 2151150248),
    (8733752, 2151156872),
    (8737256, 2151160376),
    (8742032, 2151165152),
    (8866576, 2151289696),
    (8868544, 2151291664),
    (8870512, 2151293632),
    (8882512, 2151305632),
    (8882896, 2151306016),
    (8883280, 2151306400),
    (8883664, 2151306784),
    (8884048, 2151307168),
    (8884432, 2151307552),
    (8884816, 2151307936),
    (8885200, 2151308320),
    (8885584, 2151308704),
    (8885968, 2151309088),
    (8886352, 2151309472),
    (8886736, 2151309856),
    (8887120, 2151310240),
    (8887504, 2151310624),
    (8969552, 2149516640),
    (9019880, 2149566968),
    (9020488, 2149567576),
    (9021032, 2149568120),
    (9021560, 2149568648),
    (9021784, 2149568872),
    (9022008, 2149569096),
    (9022232, 2149569320),
    (9022456, 2149569544),
    (9022680, 2149569768),
    (9022904, 2149569992),
    (9023128, 2149570216),
    (9023952, 2149571040),
    (9024936, 2149572024),
    (9025872, 2149572960),
    (9026312, 2149573400),
    (9026616, 2149573704),
    (9027000, 2149574088),
    (9027384, 2149574472),
    (9027768, 2149574856),
    (9029912, 2149577000),
    (9032056, 2149579144),
    (9032440, 2149579528),
    (9032824, 2149579912),
    (9034968, 2149582056),
    (9039120, 2149586208),
    (9068784, 2149615872),
    (9248176, 2148582800),
    (9324224, 2148658848),
    (9338216, 2148672840),
    (9365336, 2148699960),
    (9374440, 2148709064),
    (9383544, 2148718168),
    (9392648, 2148727272),
    (9401752, 2148736376),
    (9410856, 2148745480),
    (9419960, 2148754584),
    (9429064, 2148763688),
    (9432856, 2148767480),
    (9441960, 2148776584),
    (9451064, 2148785688),
    (9460168, 2148794792),
    (9463960, 2148798584),
    (9467752, 2148802376),
    (9471544, 2148806168),
    (9475336, 2148809960),
    (9484440, 2148819064),
    (9486648, 2148821272),
    (9488856, 2148823480),
    (9491064, 2148825688),
    (9493272, 2148827896),
    (9495480, 2148830104),
    (9497688, 2148832312),
    (9499224, 2148833848),
    (9500760, 2148835384),
    (9502296, 2148836920),
    (9503832, 2148838456),
    (9505368, 2148839992),
    (9506904, 2148841528),
    (9508440, 2148843064),
    (9509976, 2148844600),
    (9511512, 2148846136),
    (9513048, 2148847672),
    (9514584, 2148849208),
    (9516120, 2148850744),
    (9517656, 2148852280),
    (9519192, 2148853816),
    (9527472, 2148862096),
    (9535752, 2148870376),
    (9544032, 2148878656),
    (9552312, 2148886936),
    (9560592, 2148895216),
    (9568872, 2148903496),
    (9577152, 2148911776),
    (9585432, 2148920056),
    (9589792, 2148924416),
    (9594152, 2148928776),
    (9598512, 2148933136),
    (9602872, 2148937496),
    (9607232, 2148941856),
    (9611592, 2148946216),
    (9615952, 2148950576),
    (9620312, 2148954936),
    (9624672, 2148959296),
    (9629032, 2148963656),
    (9633392, 2148968016),
    (9788504, 2149123128),
    (9796784, 2149131408),
    (9801144, 2149135768),
    (9805504, 2149140128),
    (9809864, 2149144488),
    (9819856, 2149154480),
    (9824216, 2149158840),
    (9828576, 2149163200),
    (9832936, 2149167560),
    (9837296, 2149171920),
    (9841656, 2149176280),
    (9846016, 2149180640),
    (9850376, 2149185000),
    (9854736, 2149189360),
    (9859096, 2149193720),
    (9863456, 2149198080),
    (9867816, 2149202440),
    (9872176, 2149206800),
    (9876536, 2149211160),
    (9880896, 2149215520),
    (9885256, 2149219880),
    (9889616, 2149224240),
    (9893976, 2149228600),
    (9898336, 2149232960),
    (9906616, 2149241240),
    (9914896, 2149249520),
    (9923176, 2149257800),
    (9931456, 2149266080),
    (9939736, 2149274360),
    (9948016, 2149282640),
    (9956296, 2149290920),
    (9964576, 2149299200),
    (9972856, 2149307480),
    (9979312, 2149313936),
    (9983672, 2149318296),
    (9988032, 2149322656),
    (9992392, 2149327016),
    (9996752, 2149331376),
]


def run_tests(rom_path: Path, verbose: bool = False) -> int:
    """Load ROM, parse sprites, run per-row tests, print stats."""
    rom = rom_path.read_bytes()

    total_rows = 0
    matching_rows = 0
    sprites_with_padding = 0
    failing_sprites: dict[int, int] = {}

    for header_rom, header_vram in SPRITE_HEADERS:
        header = read_sprite_header(rom, header_rom)

        if (header.bmfmt, header.bmsiz) != (IM_FMT.G_IM_FMT_RGBA, IM_SIZ.G_IM_SIZ_16b):
            continue

        bitmaps = []
        for i in range(header.nbitmaps):
            bm_vram = header.bitmap + i * 0x10
            bm_rom = vram_to_rom(bm_vram, header_vram, header_rom)
            bitmaps.append(read_bitmap(rom, bm_rom))

        has_padding = any(bm.width != bm.width_img for bm in bitmaps)
        if not has_padding:
            continue

        sprites_with_padding += 1
        sprite_fails = 0

        for bm in bitmaps:
            actual_w = bm.width
            padded_w = bm.width_img
            actual_h = bm.actual_height
            buf_rom = vram_to_rom(bm.buf, header_vram, header_rom)
            stride = padded_w * 2

            for y in range(actual_h):
                row_bytes = rom[buf_rom + y * stride : buf_rom + (y + 1) * stride]
                odd_row = y % 2 == 1

                decoded_row = []
                for x in range(padded_w):
                    decoded_row.append(decode_rgba16_texel(row_bytes[2 * x], row_bytes[2 * x + 1]))

                if odd_row:
                    decoded_row = unshuffle_row(decoded_row)

                visible_5bit = decoded_row[:actual_w]
                visible_8bit = [upscale_5to8(*p) for p in visible_5bit]

                output = tweak_row(visible_8bit, row_bytes, padded_w, odd_row)

                total_rows += 1
                if output == row_bytes:
                    matching_rows += 1
                else:
                    sprite_fails += 1
                    if verbose:
                        print(f"FAIL: header_rom=0x{header_rom:X} y={y} actual_w={actual_w} padded_w={padded_w}")
                        print(f"  expected: {row_bytes.hex()}")
                        print(f"  got:      {output.hex()}")

        if sprite_fails > 0:
            failing_sprites[header_rom] = sprite_fails

    print(f"RGBA16 sprites with padding: {sprites_with_padding}")
    print(f"Rows matched: {matching_rows}/{total_rows} ({matching_rows * 100 // max(total_rows, 1)}%)")
    if failing_sprites:
        print(f"Failing sprites: {len(failing_sprites)}")
        if verbose:
            for rom_off, count in sorted(failing_sprites.items(), key=lambda kv: -kv[1])[:20]:
                print(f"  0x{rom_off:X}: {count} rows")
    return 0 if matching_rows == total_rows else 1


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path, help="Path to baserom.z64")
    parser.add_argument("-v", "--verbose", action="store_true", help="Show per-row failures")
    args = parser.parse_args()
    raise SystemExit(run_tests(args.rom, args.verbose))


if __name__ == "__main__":
    main()
