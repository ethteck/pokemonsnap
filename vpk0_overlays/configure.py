#!/usr/bin/env python3

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
from dataclasses import dataclass
from io import BytesIO
from pathlib import Path
from typing import Iterable

import ninja_syntax
import splat.scripts.split as split

ROOT = Path(__file__).resolve().parent.parent
SCRIPT_DIR = Path(__file__).resolve().parent
BUILD_DIR = SCRIPT_DIR / "build"
ASSET_DIR = SCRIPT_DIR / "assets"
TOOLS_LINK = SCRIPT_DIR / "tools"
SOURCE_C_PATH = SCRIPT_DIR / "src" / "menu_images.c"
YAML_PATH = SCRIPT_DIR / "menu_images.yaml"
NINJA_PATH = SCRIPT_DIR / "build.ninja"
SPLAT_LD_PATH = SCRIPT_DIR / "menu_images.ld"
OVERLAY_LD_PATH = BUILD_DIR / "menu_images_rebuild.ld"
OVERLAY_SYMS_LD_PATH = BUILD_DIR / "menu_images_syms.ld"
OVERLAY_OBJECT_PATH = BUILD_DIR / "menu_images.o"
OVERLAY_ELF_PATH = BUILD_DIR / "menu_images.elf"
OVERLAY_BIN_PATH = BUILD_DIR / "menu_images.bin"
OVERLAY_MAP_PATH = BUILD_DIR / "menu_images.map"
OVERLAY_VPK0_PATH = BUILD_DIR / "menu_images.vpk0"
FINAL_ASM_PATH = BUILD_DIR / "A0F830.s"
FINAL_OBJECT_PATH = BUILD_DIR / "A0F830.o"
SYMBOL_DUMP_PATH = BUILD_DIR / "menu_images_symbols.txt"
COMPARE_BIN_OK_PATH = BUILD_DIR / "menu_images.compare.ok"
COMPARE_VPK0_OK_PATH = BUILD_DIR / "menu_images_vpk0.compare.ok"
LOCAL_DECOMPRESSED_PATH = ASSET_DIR / "A0F830.bin"
ROOT_DECOMPRESSED_PATH = ROOT / "assets" / "A0F830.bin"
REFERENCE_DIR = SCRIPT_DIR / "reference"
REFERENCE_VPK0_PATH = REFERENCE_DIR / "A0F830.vpk0"
ROM_PATH = ROOT / "pokemonsnap.z64"

OVERLAY_NAME = "menu_images"
ROM_SYMBOL_PREFIX = "A0F830"
BASE_VRAM = 0x802B5000
COMPRESSED_ROM_START = 0xA0F830
COMPRESSED_ROM_END = 0xA5CC46

COMMON_INCLUDES = "-I include -I src -I ultralib/include -I ultralib/include/ido -I ultralib/include/PR -I ultralib/src -I build/include -I build -I ."
MINI_INCLUDES = f"{COMMON_INCLUDES} -I vpk0_overlays"
IDO_DEFS = "-DF3DEX_GBI_2 -D_LANGUAGE_C -DNDEBUG -D_FINALROM"
CROSS = "mips-linux-gnu-"
CROSS_AS = f"{CROSS}as"
CROSS_CPP = shutil.which(f"{CROSS}cpp") or shutil.which("cpp") or f"{CROSS}cpp"
CROSS_LD = f"{CROSS}ld"
CROSS_OBJCOPY = f"{CROSS}objcopy"
CROSS_NM = f"{CROSS}nm"
ROOT_TOOLS_DIR = ROOT / "tools"
IDO_72_CC = ROOT_TOOLS_DIR / "ido7.1" / "cc"
MKSPRITE = ROOT_TOOLS_DIR / "mksprite.py"
VPK0_TOOL = ROOT_TOOLS_DIR / "vpk0.py"
O32_TOOL = ROOT / "ultralib" / "tools" / "set_o32abi_bit.py"
RAW_BUILD_PREAMBLE = f"$ido -G 0 -non_shared -fullwarn -verbose -Wab,-r4300_mul -woff 513,516,649,838,712 -Xcpluscomm -nostdinc $flags {MINI_INCLUDES} {IDO_DEFS}"
RAW_CC_CMD = f"{RAW_BUILD_PREAMBLE} -DBUILD_VERSION=VERSION_I -c -o $out $in && {O32_TOOL} $out"
AS_CMD = (
    f"bash -o pipefail -c '{CROSS_CPP} {MINI_INCLUDES} $in -o - | "
    f"iconv -t EUC-JP | {CROSS_AS} -G0 {MINI_INCLUDES} -EB -mtune=vr4300 -march=vr4300 -o $out'"
)

sys.path.insert(0, str(ROOT))
from tools.splat_ext.snap_sprite import (  # noqa: E402
    Bitmap,
    FORMAT_INFO,
    SpriteAttributes,
    SpriteHeader,
)

DF_ALIGNER = bytes.fromhex("df00000000000000")
ZERO_ALIGNER = bytes(8)
SPRITE_ALIAS_RE = re.compile(r"^(D_[0-9A-F]{8})_sprite$")


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


def repo_rel(path: Path) -> str:
    if not path.is_absolute():
        path = ROOT / path
    return path.resolve().relative_to(ROOT.resolve()).as_posix()


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


def parse_sprite_info(entry, rom_bytes: bytes) -> SpriteBuildInfo:
    seg = entry.segment
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
    src_png = SCRIPT_DIR / entry.src_paths[0]
    inc_path = BUILD_DIR / Path(str(entry.src_paths[0]) + ".inc.h")

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


def write_overlay_linker_script():
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
        f"        {repo_rel(OVERLAY_OBJECT_PATH)}(.data);\n"
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


def create_build_ninja(infos: list[SpriteBuildInfo], have_reference_vpk0: bool):
    with NINJA_PATH.open("w", encoding="utf-8") as f:
        ninja = ninja_syntax.Writer(f, width=9999)
        ninja.variable("ido", str(IDO_72_CC))

        ninja.rule(
            "mksprite",
            description="mksprite $in",
            command=(
                f"{sys.executable} {repo_rel(MKSPRITE)} $src_png -f $fmt --tile-width $tile_w "
                "--tile-height $tile_h --padding $padding_png --aligner $aligner_mode "
                "--name $sprite_name $sprite_flags -o $out"
            ),
        )
        ninja.rule("cc_raw", description="cc $in", command=RAW_CC_CMD)
        ninja.rule("as", description="as $in", command=AS_CMD)
        ninja.rule(
            "ld_overlay",
            description="link $out",
            command=f"{CROSS_LD} -T {repo_rel(OVERLAY_SYMS_LD_PATH)} -Map $mapfile -T $in -o $out",
        )
        ninja.rule("bin", description="objcopy $out", command=f"{CROSS_OBJCOPY} $in $out -O binary")
        ninja.rule(
            "vpk0_compress",
            description="vpk0 $in",
            command=f"{sys.executable} {repo_rel(VPK0_TOOL)} $in $out",
        )
        ninja.rule(
            "emit_final_asm",
            description="emit-final-asm $out",
            command=(
                f"{sys.executable} {repo_rel(Path(__file__).resolve())} emit-final-asm "
                "--elf $elf --vpk0 $vpk0 --output $out"
            ),
        )
        ninja.rule(
            "compare_bin",
            description="cmp $in",
            command=f"cmp -s $in {repo_rel(LOCAL_DECOMPRESSED_PATH)} && touch $out",
        )
        if have_reference_vpk0:
            ninja.rule(
                "compare_vpk0",
                description="cmp-vpk0 $in",
                command=f"cmp -s $in {repo_rel(REFERENCE_VPK0_PATH)} && touch $out",
            )

        incs: list[str] = []
        for info in infos:
            inc = repo_rel(info.inc_path)
            ninja.build(
                inc,
                "mksprite",
                [repo_rel(info.png_path), repo_rel(info.padding_png_path)],
                variables={
                    "src_png": repo_rel(info.png_path),
                    "padding_png": repo_rel(info.padding_png_path),
                    "fmt": info.format_name,
                    "aligner_mode": info.aligner_mode,
                    "tile_w": str(info.tile_width),
                    "tile_h": str(info.tile_height),
                    "sprite_name": info.name,
                    "sprite_flags": info.sprite_flags,
                },
            )
            incs.append(inc)

        ninja.build(
            repo_rel(OVERLAY_OBJECT_PATH),
            "cc_raw",
            repo_rel(SOURCE_C_PATH),
            implicit=incs,
            variables={"flags": "-O2"},
        )
        ninja.build(
            repo_rel(OVERLAY_ELF_PATH),
            "ld_overlay",
            repo_rel(OVERLAY_LD_PATH),
            implicit=[repo_rel(OVERLAY_OBJECT_PATH)],
            variables={"mapfile": repo_rel(OVERLAY_MAP_PATH)},
        )
        ninja.build(repo_rel(OVERLAY_BIN_PATH), "bin", repo_rel(OVERLAY_ELF_PATH))
        ninja.build(repo_rel(OVERLAY_VPK0_PATH), "vpk0_compress", repo_rel(OVERLAY_BIN_PATH))
        ninja.build(
            repo_rel(FINAL_ASM_PATH),
            "emit_final_asm",
            repo_rel(OVERLAY_VPK0_PATH),
            implicit=[repo_rel(OVERLAY_ELF_PATH)],
            variables={"elf": repo_rel(OVERLAY_ELF_PATH), "vpk0": repo_rel(OVERLAY_VPK0_PATH)},
        )
        ninja.build(repo_rel(FINAL_OBJECT_PATH), "as", repo_rel(FINAL_ASM_PATH))

        ninja.build(repo_rel(COMPARE_BIN_OK_PATH), "compare_bin", repo_rel(OVERLAY_BIN_PATH))
        if have_reference_vpk0:
            ninja.build(repo_rel(COMPARE_VPK0_OK_PATH), "compare_vpk0", repo_rel(OVERLAY_VPK0_PATH))

        ninja.build(
            "all",
            "phony",
            [repo_rel(OVERLAY_BIN_PATH), repo_rel(OVERLAY_VPK0_PATH), repo_rel(FINAL_OBJECT_PATH)],
        )
        ninja.build("compare_menu_images", "phony", [repo_rel(COMPARE_BIN_OK_PATH)])
        if have_reference_vpk0:
            ninja.build("compare_menu_images_vpk0", "phony", [repo_rel(COMPARE_VPK0_OK_PATH)])
        ninja.default("all")


def parse_nm_symbols(elf_path: Path) -> dict[str, int]:
    result = subprocess.run(
        [CROSS_NM, "-g", "--defined-only", str(elf_path)],
        check=True,
        capture_output=True,
        text=True,
    )
    symbols: dict[str, int] = {}
    for raw_line in result.stdout.splitlines():
        parts = raw_line.strip().split()
        if len(parts) < 3:
            continue
        value_str, _kind, name = parts[0], parts[1], parts[2]
        try:
            value = int(value_str, 16) & 0xFFFFFFFF
        except ValueError:
            continue
        symbols[name] = value
    return symbols


def emit_final_asm(elf_path: Path, vpk0_path: Path, output: Path):
    symbols = parse_nm_symbols(elf_path)
    exported: dict[str, int] = {}
    for name, value in symbols.items():
        if not name.startswith("D_"):
            continue
        if value < BASE_VRAM or value >= BASE_VRAM + 0x200000:
            continue
        exported[name] = value
        alias_match = SPRITE_ALIAS_RE.match(name)
        if alias_match:
            exported.setdefault(alias_match.group(1), value)

    lines = [
        '.section .data, "wa"',
        ".balign 16",
        f".globl {ROM_SYMBOL_PREFIX}_ROM_START",
        f"{ROM_SYMBOL_PREFIX}_ROM_START:",
        f'.incbin "{repo_rel(vpk0_path)}"',
        f".globl {ROM_SYMBOL_PREFIX}_ROM_END",
        f"{ROM_SYMBOL_PREFIX}_ROM_END:",
        "",
    ]

    symbol_dump_lines = []
    for name, value in sorted(exported.items(), key=lambda item: (item[1], item[0])):
        lines.append(f".globl {name}")
        lines.append(f"{name} = 0x{value:08X}")
        symbol_dump_lines.append(f"{name} 0x{value:08X}")
    lines.append("")

    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("\n".join(lines), encoding="utf-8")
    SYMBOL_DUMP_PATH.write_text("\n".join(symbol_dump_lines) + "\n", encoding="utf-8")


def run_configure():
    shutil.rmtree(BUILD_DIR, ignore_errors=True)
    have_reference_vpk0 = ensure_local_inputs()
    linker_entries = run_splat_split()
    rom_bytes = LOCAL_DECOMPRESSED_PATH.read_bytes()
    infos = [parse_sprite_info(entry, rom_bytes) for entry in linker_entries]

    missing = [
        path
        for info in infos
        for path in (info.png_path, info.padding_png_path)
        if not path.exists()
    ]
    if missing:
        missing_str = "\n".join(repo_rel(path) for path in missing)
        raise FileNotFoundError(f"Missing extracted sprite files:\n{missing_str}")

    write_overlay_linker_script()
    write_overlay_symbols_script(infos)
    create_build_ninja(infos, have_reference_vpk0)

    print(f"Wrote {repo_rel(NINJA_PATH)}")
    print(f"Splat linker script: {repo_rel(SPLAT_LD_PATH)}")
    print(f"Overlay linker script: {repo_rel(OVERLAY_LD_PATH)}")
    print(f"Overlay source: {repo_rel(SOURCE_C_PATH)}")
    print(f"Final object: {repo_rel(FINAL_OBJECT_PATH)}")


def main():
    parser = argparse.ArgumentParser(description="Configure the standalone VPK0 overlay rebuild")
    subparsers = parser.add_subparsers(dest="command")

    emit_parser = subparsers.add_parser("emit-final-asm")
    emit_parser.add_argument("--elf", type=Path, required=True)
    emit_parser.add_argument("--vpk0", type=Path, required=True)
    emit_parser.add_argument("--output", type=Path, required=True)

    args = parser.parse_args()
    if args.command == "emit-final-asm":
        emit_final_asm(args.elf, args.vpk0, args.output)
        return

    run_configure()


if __name__ == "__main__":
    main()
