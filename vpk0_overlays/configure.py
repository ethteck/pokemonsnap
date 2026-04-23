#!/usr/bin/env python3

from __future__ import annotations

import os
import shutil
import sys
from dataclasses import dataclass
from io import BytesIO
from pathlib import Path
from typing import Iterable

import ninja_syntax
import splat.scripts.split as split
import splat.segtypes.common.group
import splat.segtypes.n64.img
import splat.segtypes.n64.palette

ROOT = Path(__file__).resolve().parent.parent
SCRIPT_DIR = Path(__file__).resolve().parent
BUILD_DIR = SCRIPT_DIR / "build"
ASSET_DIR = SCRIPT_DIR / "assets"
TOOLS_LINK = SCRIPT_DIR / "tools"
YAML_PATH = SCRIPT_DIR / "menu_images.yaml"
NINJA_PATH = SCRIPT_DIR / "build.ninja"
SPLAT_LD_PATH = SCRIPT_DIR / "menu_images.ld"
OVERLAY_LD_PATH = BUILD_DIR / "menu_images_rebuild.ld"
OVERLAY_SYMS_LD_PATH = BUILD_DIR / "menu_images_syms.ld"
OVERLAY_ELF_PATH = BUILD_DIR / "menu_images.elf"
OVERLAY_BIN_PATH = BUILD_DIR / "menu_images.bin"
OVERLAY_MAP_PATH = BUILD_DIR / "menu_images.map"
FINAL_OBJECT_PATH = BUILD_DIR / "A0F830.o"
LOCAL_DECOMPRESSED_PATH = ASSET_DIR / "A0F830.bin"
ROOT_DECOMPRESSED_PATH = ROOT / "assets" / "A0F830.bin"
REFERENCE_DIR = SCRIPT_DIR / "reference"
REFERENCE_VPK0_PATH = REFERENCE_DIR / "A0F830.vpk0"
ROM_PATH = ROOT / "pokemonsnap.z64"
ELF_TO_VPK0_OBJ = SCRIPT_DIR / "elf_to_vpk0_obj.py"

OVERLAY_NAME = "menu_images"
ROM_SYMBOL_PREFIX = "A0F830"
BASE_VRAM = 0x802B5000
COMPRESSED_ROM_START = 0xA0F830
COMPRESSED_ROM_END = 0xA5CC46

PIGMENT64 = "pigment64"
ROOT_INCLUDES = " ".join(
    f"-I ../{d}" for d in [
        "include", "src",
        "ultralib/include", "ultralib/include/ido", "ultralib/include/PR", "ultralib/src",
        "build/include", "build",
    ]
)
COMMON_INCLUDES = f"{ROOT_INCLUDES} -I .. -I . -I build"
IDO_DEFS = "-DF3DEX_GBI_2 -D_LANGUAGE_C -DNDEBUG -D_FINALROM"
CROSS = "mips-linux-gnu-"
CROSS_LD = f"{CROSS}ld"
ROOT_TOOLS_DIR = ROOT / "tools"
IDO_72_CC = ROOT_TOOLS_DIR / "ido7.1" / "cc"
MKSPRITE = ROOT_TOOLS_DIR / "mksprite.py"
VPK0_TOOL = ROOT_TOOLS_DIR / "vpk0.py"
BIN2C = ROOT_TOOLS_DIR / "bin2c.py"
O32_TOOL = ROOT / "ultralib" / "tools" / "set_o32abi_bit.py"
RAW_BUILD_PREAMBLE = f"$ido -G 0 -non_shared -fullwarn -verbose -Wab,-r4300_mul -woff 513,516,649,838,712 -Xcpluscomm -nostdinc $flags {COMMON_INCLUDES} {IDO_DEFS}"
RAW_CC_CMD = f"{RAW_BUILD_PREAMBLE} -DBUILD_VERSION=VERSION_I -c -o $out $in && {O32_TOOL} $out"

sys.path.insert(0, str(ROOT))
from tools.splat_ext.snap_sprite import (  # noqa: E402
    Bitmap,
    FORMAT_INFO,
    SpriteAttributes,
    SpriteHeader,
)

DF_ALIGNER = bytes.fromhex("df00000000000000")
ZERO_ALIGNER = bytes(8)


@dataclass(frozen=True)
class SpriteBuildInfo:
    name: str
    png_path: Path
    padding_png_path: Path
    inc_path: Path
    tile_width: int
    tile_height: int
    format_name: str
    aligner_mode: str
    has_dl: bool
    dl_addr: int
    has_sp_z: bool
    has_sp_fastcopy: bool
    has_sp_transparent: bool
    has_sp_scale: bool
    has_sp_overlap: bool
    sp_x: int
    sp_y: int
    sp_color: int

    @property
    def sprite_flags(self) -> str:
        flags: list[str] = []
        if self.has_dl:
            flags.append("--dl")
        if not self.has_sp_z:
            flags.append("--no-z")
        if not self.has_sp_fastcopy:
            flags.append("--no-fastcopy")
        if self.has_sp_transparent:
            flags.append("--transparent")
        if self.has_sp_scale:
            flags.append("--scale")
        if self.has_sp_overlap:
            flags.append("--overlap")
        if self.sp_x != 0:
            flags.extend(["--x", str(self.sp_x)])
        if self.sp_y != 0:
            flags.extend(["--y", str(self.sp_y)])
        if self.sp_color != 0xFFFFFFFF:
            flags.extend(["--color", f"{self.sp_color:08X}"])
        return " ".join(flags)

    @property
    def generated_dl_symbol(self) -> str:
        return f"{self.name}_dl"


def rel(path: Path) -> str:
    """Return path relative to SCRIPT_DIR for use in build files."""
    if not path.is_absolute():
        return str(path)
    return path.resolve().relative_to(SCRIPT_DIR.resolve()).as_posix()


def vram_to_rom(vram: int, rom_size: int) -> int:
    rom = vram - BASE_VRAM
    if rom < 0 or rom >= rom_size:
        raise ValueError(f"VRAM address 0x{vram:08X} is outside overlay range")
    return rom


def ensure_local_inputs() -> bool:
    ASSET_DIR.mkdir(parents=True, exist_ok=True)
    BUILD_DIR.mkdir(parents=True, exist_ok=True)
    REFERENCE_DIR.mkdir(parents=True, exist_ok=True)

    if TOOLS_LINK.exists() or TOOLS_LINK.is_symlink():
        if not (TOOLS_LINK.is_symlink() and TOOLS_LINK.resolve() == ROOT_TOOLS_DIR.resolve()):
            if TOOLS_LINK.is_dir() and not TOOLS_LINK.is_symlink():
                shutil.rmtree(TOOLS_LINK)
            else:
                TOOLS_LINK.unlink()
            TOOLS_LINK.symlink_to(ROOT_TOOLS_DIR, target_is_directory=True)
    else:
        TOOLS_LINK.symlink_to(ROOT_TOOLS_DIR, target_is_directory=True)

    shutil.copyfile(ROOT_DECOMPRESSED_PATH, LOCAL_DECOMPRESSED_PATH)

    have_reference_vpk0 = False
    if ROM_PATH.exists():
        rom_bytes = ROM_PATH.read_bytes()
        if len(rom_bytes) >= COMPRESSED_ROM_END:
            REFERENCE_VPK0_PATH.write_bytes(rom_bytes[COMPRESSED_ROM_START:COMPRESSED_ROM_END])
            have_reference_vpk0 = True

    return have_reference_vpk0


def run_splat_split():
    old_cwd = Path.cwd()
    try:
        os.chdir(SCRIPT_DIR)
        split.main([Path(YAML_PATH.name)], modes=["all"], verbose=False, disassemble_all=False)
        return list(split.linker_writer.entries)
    finally:
        os.chdir(old_cwd)


def parse_sprite_info(seg, rom_bytes: bytes) -> SpriteBuildInfo:
    header_rom = int(seg.header_rom)

    header = SpriteHeader()
    header.unpack(BytesIO(rom_bytes[header_rom : header_rom + 0x44]))

    fmt_info = FORMAT_INFO.get((header.bmfmt, header.bmsiz))
    if fmt_info is None:
        raise ValueError(
            f"Unsupported sprite format for header ROM 0x{header_rom:X}: {header.bmfmt} {header.bmsiz}"
        )

    bitmaps: list[Bitmap] = []
    bm_vram = header.bitmap
    for _ in range(header.nbitmaps):
        bm_rom = vram_to_rom(bm_vram, len(rom_bytes))
        bitmap = Bitmap()
        bitmap.unpack(BytesIO(rom_bytes[bm_rom : bm_rom + 0x10]))
        bitmaps.append(bitmap)
        bm_vram += 0x10

    if not bitmaps:
        raise ValueError(f"Sprite at header ROM 0x{header_rom:X} has no bitmaps")

    aligners = set()
    for bitmap in bitmaps:
        buf_rom = vram_to_rom(bitmap.buf, len(rom_bytes))
        aligners.add(bytes(rom_bytes[buf_rom - 8 : buf_rom]))

    aligner_mode = "zero" if aligners == {ZERO_ALIGNER} else "df"
    out = seg.out_path()
    src_png = SCRIPT_DIR / out
    inc_path = BUILD_DIR / Path(str(out) + ".inc.h")

    return SpriteBuildInfo(
        name=str(seg.name),
        png_path=src_png,
        padding_png_path=src_png.with_name(f"{src_png.stem}.padding.png"),
        inc_path=inc_path,
        tile_width=int(bitmaps[0].width),
        tile_height=int(header.bmheight),
        format_name=str(fmt_info[3]),
        aligner_mode=aligner_mode,
        has_dl=bool(header.rsp_dl),
        dl_addr=int(header.rsp_dl),
        has_sp_z=bool(header.attr & SpriteAttributes.SP_Z),
        has_sp_fastcopy=bool(header.attr & SpriteAttributes.SP_FASTCOPY),
        has_sp_transparent=bool(header.attr & SpriteAttributes.SP_TRANSPARENT),
        has_sp_scale=bool(header.attr & SpriteAttributes.SP_SCALE),
        has_sp_overlap=bool(header.attr & SpriteAttributes.SP_OVERLAP),
        sp_x=int(header.x),
        sp_y=int(header.y),
        sp_color=(
            (header.red << 24)
            | (header.green << 16)
            | (header.blue << 8)
            | header.alpha
        ),
    )


def write_overlay_linker_script(object_paths: list[Path]):
    object_lines = "".join(
        f"        {rel(obj)}(.data);\n" for obj in object_paths
    )
    OVERLAY_LD_PATH.write_text(
        "SECTIONS\n"
        "{\n"
        "    __romPos = 0;\n"
        f"    {OVERLAY_NAME}_ROM_START = __romPos;\n"
        f"    {OVERLAY_NAME}_VRAM = ADDR(.{OVERLAY_NAME});\n"
        f"    .{OVERLAY_NAME} 0x{BASE_VRAM:08X} : AT({OVERLAY_NAME}_ROM_START) SUBALIGN(16)\n"
        "    {\n"
        "        FILL(0x00000000);\n"
        f"        {OVERLAY_NAME}_DATA_START = .;\n"
        f"{object_lines}"
        "        . = ALIGN(., 16);\n"
        f"        {OVERLAY_NAME}_DATA_END = .;\n"
        f"        {OVERLAY_NAME}_DATA_SIZE = ABSOLUTE({OVERLAY_NAME}_DATA_END - {OVERLAY_NAME}_DATA_START);\n"
        "    }\n"
        f"    __romPos += SIZEOF(.{OVERLAY_NAME});\n"
        "    __romPos = ALIGN(__romPos, 16);\n"
        "    . = ALIGN(., 16);\n"
        f"    {OVERLAY_NAME}_ROM_END = __romPos;\n"
        f"    {OVERLAY_NAME}_VRAM_END = .;\n\n"
        "    /DISCARD/ :\n"
        "    {\n"
        "        *(*);\n"
        "    }\n"
        "}\n",
        encoding="utf-8",
    )


def write_overlay_symbols_script(infos: Iterable[SpriteBuildInfo]):
    lines = [
        f"{info.generated_dl_symbol} = 0x{info.dl_addr:08X};"
        for info in infos
        if info.has_dl and info.dl_addr != 0
    ]
    OVERLAY_SYMS_LD_PATH.write_text("\n".join(lines) + ("\n" if lines else ""), encoding="utf-8")


def collect_data_group_builds(linker_entries):
    """First pass: collect image/palette/sprite builds from .data group subsegments."""
    image_builds: list[tuple[str, str, dict]] = []
    sprite_segs = []
    for entry in linker_entries:
        seg = entry.segment
        if entry.object_path is None:
            continue
        if seg.type != ".data" or not isinstance(seg, splat.segtypes.common.group.CommonSegGroup):
            continue
        for sub in seg.subsegments:
            if isinstance(sub, splat.segtypes.n64.img.N64SegImg):
                out = sub.out_path()
                if out is None:
                    continue
                flags = ""
                if sub.n64img.flip_h:
                    flags += "--flip-x "
                if sub.n64img.flip_v:
                    flags += "--flip-y "
                src_path = str(out)
                bin_path = "build/" + src_path + ".bin"
                image_builds.append((src_path, bin_path, {"img_type": sub.type, "img_flags": flags}))
            elif isinstance(sub, splat.segtypes.n64.palette.N64SegPalette):
                out = sub.out_path()
                if out is None:
                    continue
                src_path = str(out)
                bin_path = "build/" + str(out.with_suffix(".pal")) + ".bin"
                image_builds.append((src_path, bin_path, {"img_type": sub.type, "img_flags": ""}))
            elif hasattr(sub, "header_rom"):
                sprite_segs.append(sub)
    return image_builds, sprite_segs


def create_build_ninja(
    sprite_infos: list[SpriteBuildInfo],
    image_builds: list[tuple[str, str, dict]],
    c_sources: list[tuple[Path, Path]],
):
    with NINJA_PATH.open("w", encoding="utf-8") as f:
        ninja = ninja_syntax.Writer(f, width=9999)
        ninja.variable("ido", str(IDO_72_CC))

        ninja.rule(
            "pigment",
            description="img($img_type) $in",
            command=f"{PIGMENT64} to-bin $img_flags -f $img_type -o $out $in",
        )
        ninja.rule(
            "bin2c",
            description="bin2c $in",
            command=f"{sys.executable} {BIN2C} $in $out",
        )
        ninja.rule(
            "mksprite",
            description="mksprite $in",
            command=(
                f"{sys.executable} {MKSPRITE} $src_png -f $fmt --tile-width $tile_w "
                "--tile-height $tile_h --padding $padding_png --aligner $aligner_mode "
                "--name $sprite_name $sprite_flags -o $out"
            ),
        )
        ninja.rule("cc_raw", description="cc $in", command=RAW_CC_CMD)
        ninja.rule(
            "ld_overlay",
            description="link $out",
            command=f"{CROSS_LD} -T undefined_syms.txt -T undefined_syms_auto.txt -T {rel(OVERLAY_SYMS_LD_PATH)} -Map $mapfile -T $in -o $out",
        )
        ninja.rule(
            "elf_to_vpk0_obj",
            description="elf->vpk0->obj $out",
            command=(
                f"{sys.executable} {ELF_TO_VPK0_OBJ} $in -o $out "
                f"--vpk0-tool {VPK0_TOOL} --label {ROM_SYMBOL_PREFIX}"
            ),
        )
        ninja.rule(
            "objcopy_bin",
            description="objcopy $out",
            command=f"{CROSS}objcopy $in $out -O binary",
        )
        ninja.rule(
            "compare_bin",
            description="compare $in",
            command=f"cmp -s $in $reference && echo 'OK: $in matches' && touch $out || (echo 'DIFF: $in differs from $reference'; false)",
        )

        img_incs: list[str] = []

        for src_path, bin_path, variables in image_builds:
            ninja.build(bin_path, "pigment", src_path, variables=variables)
            inc_path = bin_path + ".c"
            ninja.build(inc_path, "bin2c", bin_path)
            img_incs.append(inc_path)

        for info in sprite_infos:
            inc = rel(info.inc_path)
            ninja.build(
                inc,
                "mksprite",
                [rel(info.png_path), rel(info.padding_png_path)],
                variables={
                    "src_png": rel(info.png_path),
                    "padding_png": rel(info.padding_png_path),
                    "fmt": info.format_name,
                    "aligner_mode": info.aligner_mode,
                    "tile_w": str(info.tile_width),
                    "tile_h": str(info.tile_height),
                    "sprite_name": info.name,
                    "sprite_flags": info.sprite_flags,
                },
            )
            img_incs.append(inc)

        ninja.build("img_incs", "phony", img_incs)

        all_objects: list[str] = []
        for src, obj in c_sources:
            ninja.build(
                rel(obj),
                "cc_raw",
                rel(src),
                implicit=["img_incs"],
                variables={"flags": "-O2"},
            )
            all_objects.append(rel(obj))

        ninja.build(
            rel(OVERLAY_ELF_PATH),
            "ld_overlay",
            rel(OVERLAY_LD_PATH),
            implicit=all_objects,
            variables={"mapfile": rel(OVERLAY_MAP_PATH)},
        )

        ninja.build(
            rel(FINAL_OBJECT_PATH),
            "elf_to_vpk0_obj",
            rel(OVERLAY_ELF_PATH),
        )

        ninja.build(
            rel(OVERLAY_BIN_PATH),
            "objcopy_bin",
            rel(OVERLAY_ELF_PATH),
        )

        compare_ok = rel(BUILD_DIR / "compare.ok")
        ninja.build(
            compare_ok,
            "compare_bin",
            rel(OVERLAY_BIN_PATH),
            variables={"reference": rel(LOCAL_DECOMPRESSED_PATH)},
        )

        ninja.build("all", "phony", [rel(FINAL_OBJECT_PATH)])
        ninja.build("compare", "phony", [compare_ok])
        ninja.default("compare")


def run_configure():
    shutil.rmtree(BUILD_DIR, ignore_errors=True)
    splat_cache = SCRIPT_DIR / ".splache"
    if splat_cache.exists():
        splat_cache.unlink()
    ensure_local_inputs()
    linker_entries = run_splat_split()
    rom_bytes = LOCAL_DECOMPRESSED_PATH.read_bytes()

    c_sources: list[tuple[Path, Path]] = []
    for entry in linker_entries:
        seg = entry.segment
        if getattr(seg, "type", None) == "c" and entry.object_path is not None:
            src = SCRIPT_DIR / entry.src_paths[0]
            obj = SCRIPT_DIR / entry.object_path
            c_sources.append((src, obj))

    image_builds, sprite_segs = collect_data_group_builds(linker_entries)
    sprite_infos = [parse_sprite_info(seg, rom_bytes) for seg in sprite_segs]

    missing = [
        path
        for info in sprite_infos
        for path in (info.png_path, info.padding_png_path)
        if not path.exists()
    ]
    if missing:
        missing_str = "\n".join(rel(path) for path in missing)
        raise FileNotFoundError(f"Missing extracted sprite files:\n{missing_str}")

    for _, obj in c_sources:
        obj.parent.mkdir(parents=True, exist_ok=True)
    for info in sprite_infos:
        info.inc_path.parent.mkdir(parents=True, exist_ok=True)

    object_paths = [obj for _, obj in c_sources]
    write_overlay_linker_script(object_paths)
    write_overlay_symbols_script(sprite_infos)
    create_build_ninja(sprite_infos, image_builds, c_sources)

    print(f"Wrote {rel(NINJA_PATH)}")
    print(f"  {len(c_sources)} C sources, {len(sprite_infos)} sprites, {len(image_builds)} images")
    print(f"  Final object: {rel(FINAL_OBJECT_PATH)}")


if __name__ == "__main__":
    run_configure()
