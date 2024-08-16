#! /usr/bin/env python3

import argparse
import os
import shutil
import sys
from pathlib import Path
from typing import Dict, List, Set, Union

import ninja_syntax
import requests
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry

ROOT = Path(__file__).parent.relative_to(os.getcwd())
TOOLS_DIR = ROOT / "tools"

YAML_FILE = "splat.yaml"
BASENAME = "pokemonsnap"
LD_PATH = f"{BASENAME}.ld"
MAP_PATH = f"build/{BASENAME}.map"
ELF_PATH = f"build/{BASENAME}.elf"
Z64_PATH = f"build/{BASENAME}.z64"
OK_PATH = f"build/{BASENAME}.ok"

COMMON_INCLUDES = "-I include -I src -I ultralib/include -I ultralib/include/ido -I ultralib/include/PR -I ultralib/src -I build/include -I build"
IDO_DEFS = "-DF3DEX_GBI_2 -D_LANGUAGE_C -DNDEBUG -D_FINALROM"

CROSS = "mips-linux-gnu-"
CROSS_AS = f"{CROSS}as"
CROSS_CPP = f"{CROSS}cpp"
CROSS_LD = f"{CROSS}ld"
CROSS_STRIP = f"{CROSS}strip"
CROSS_OBJCOPY = f"{CROSS}objcopy"
AS_FLAGS = f"-G 0 {COMMON_INCLUDES} -EB -mtune=vr4300 -march=vr4300"

IDO_72_CC = TOOLS_DIR / "ido7.1" / "cc"
IDO_53_CC = TOOLS_DIR / "ido5.3" / "cc"

O32_TOOL = ROOT / "ultralib/tools/set_o32abi_bit.py"

GAME_CC_CMD = f"python3 tools/asm_processor/build.py --input-enc=utf-8 --output-enc=EUC-JP {IDO_72_CC} -- {CROSS_AS} {AS_FLAGS} -- -G 0 -non_shared -fullwarn -verbose -Xcpluscomm -nostdinc -Wab,-r4300_mul $flags -mips2 {COMMON_INCLUDES} {IDO_DEFS} -DBUILD_VERSION=VERSION_I -c -o $out $in"

LIBULTRA_CC_CMD = f"$ido -G 0 -non_shared -fullwarn -verbose -Wab,-r4300_mul -woff 513,516,649,838,712 -Xcpluscomm -nostdinc $flags {COMMON_INCLUDES} {IDO_DEFS} -DBUILD_VERSION=$libultra -c -o $out $in && {O32_TOOL} $out"

LIBULTRA_AS_CMD = f"{IDO_53_CC} -G 0 -non_shared -fullwarn -verbose -Wab,-r4300_mul -woff 513,516,649,838,712 $flags {COMMON_INCLUDES} -D_FINALROM -DBUILD_VERSION=VERSION_I -c -o $out $in && {O32_TOOL} $out && {CROSS_STRIP} $out -N asdasdasdasd"

PIGMENT64 = "pigment64"
BIN2C = "tools/bin2c.py"


def clean():
    if os.path.exists(".splache"):
        os.remove(".splache")
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)


def obtain_ido_recomp(version: str):
    download_dir = TOOLS_DIR / f"ido{version}"

    if download_dir.exists():
        print(
            f"IDO {version} already exists at {download_dir}, removing and re-downloading"
        )
        shutil.rmtree(download_dir)

    IDO_RECOMP_VERSION = "v1.1"

    if sys.platform == "darwin":
        ido_os = "macos"
    elif sys.platform == "linux":
        ido_os = "linux"
    elif sys.platform == "win32":
        ido_os = "windows"
    else:
        print(f"Unsupported platform {sys.platform}")
        sys.exit(1)

    ido_tar_name = f"ido-{version}-recomp-{ido_os}.tar.gz"
    url = f"https://github.com/decompals/ido-static-recomp/releases/download/{IDO_RECOMP_VERSION}/{ido_tar_name}"
    target_path = TOOLS_DIR / ido_tar_name

    print(f"Downloading IDO {version}: {url}")
    response = requests.get(url)
    if response.status_code != 200:
        print(f"Failed to download IDO tarball from {url}")
        sys.exit(1)
    with open(target_path, "wb") as f:
        f.write(response.content)

    shutil.unpack_archive(target_path, download_dir)
    os.remove(target_path)


def setup():
    obtain_ido_recomp("5.3")
    obtain_ido_recomp("7.1")
    print("Setup complete!")


def write_permuter_settings():
    with open("permuter_settings.toml", "w") as f:
        f.write(
            f"""build_system = "ninja"
compiler_type = "ido"

[preserve_macros]
"g[DS]P.*" = "void"
"gs[DS]P.*" = "void"
"G_IM_SIZ_.*" = "int"
"G_[AC]C.*" = "int"
ABS = "int"
ABS_ALT = "int"
SQ = "int"
ARRAY_COUNT = "int"
ARRAY_COUNTU = "int"
CLAMP = "int"
NULL = "int"

[decompme.compilers]
"{IDO_72_CC}" = "ido7.1"
"{IDO_53_CC}" = "ido5.3"
"""
        )


def create_build_script(linker_entries: List[LinkerEntry]):
    built_objects: Set[Path] = set()

    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        variables: Dict[str, str] = {},
        implicit_outputs: List[str] = [],
    ):
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        object_strs = [str(obj) for obj in object_paths]

        for object_path in object_paths:
            if object_path.suffix == ".o":
                built_objects.add(object_path)
            ninja.build(
                outputs=object_strs,
                rule=task,
                inputs=[str(s) for s in src_paths],
                variables=variables,
                implicit_outputs=implicit_outputs,
            )

    ninja = ninja_syntax.Writer(open(str(ROOT / "build.ninja"), "w"), width=9999)

    # Rules
    ninja.rule(
        "bin",
        description="bin $in",
        command=f"{CROSS_LD} -r -b binary $in -o $out",
    )

    ninja.rule(
        "as",
        description="as $in",
        command=f"{CROSS_CPP} {COMMON_INCLUDES} $in -o - | iconv -t EUC-JP | {CROSS_AS} -G0 {COMMON_INCLUDES} -EB -mtune=vr4300 -march=vr4300 -o $out",
    )

    ninja.rule(
        "as_libultra",
        description="as $in",
        command=f"{LIBULTRA_AS_CMD}",
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{GAME_CC_CMD}",
    )

    ninja.rule(
        "cc_libultra",
        description="cc $in",
        command=f"{LIBULTRA_CC_CMD}",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{CROSS_LD} -T undefined_syms.txt -T undefined_syms_auto.txt -Map $mapfile -T $in -o $out",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    ninja.rule(
        "elf",
        description="elf $out",
        command=f"{CROSS_OBJCOPY} $in $out -O binary",
    )

    ninja.rule(
        "z64",
        description="rom $out",
        command=f"{CROSS_OBJCOPY} $in $out -O binary",
    )

    ninja.rule(
        "pigment",
        description="img($img_type) $in",
        command=f"{PIGMENT64} to-bin $img_flags -f $img_type -o $out $in",
    )

    ninja.rule(
        "bin2c",
        description="bin2c $in",
        command=f"{BIN2C} $in $out",
    )

    for entry in linker_entries:
        seg = entry.segment

        if entry.object_path is None:
            continue
        
        # images embedded inside data aren't linked, but they do need to be built into .bin files
        if seg.type == ".data" and isinstance(seg, splat.segtypes.common.group.CommonSegGroup):
            for seg in seg.subsegments:
                if isinstance(seg, splat.segtypes.n64.img.N64SegImg):
                    flags = ""
                    if seg.n64img.flip_h:
                        flags += "--flip-x "
                    if seg.n64img.flip_v:
                        flags += "--flip-y "

                    bin_path = Path("build/" + str(seg.out_path()) + ".bin")
                    inc_path = Path(str(bin_path) + ".c")
                    src_path = seg.out_path()

                    build(bin_path, [src_path], "pigment", variables={ "img_type": seg.type, "img_flags": flags })
                    build(inc_path, [bin_path], "bin2c")
                elif isinstance(seg, splat.segtypes.n64.palette.N64SegPalette):
                    bin_path = Path("build/" + str(seg.out_path().with_suffix(".pal")) + ".bin")
                    inc_path = Path(str(bin_path) + ".c")
                    src_path = seg.out_path()
                    build(bin_path, [src_path], "pigment", variables={ "img_type": seg.type, "img_flags": "" })
                    build(inc_path, [bin_path], "bin2c")

    for entry in linker_entries:
        seg = entry.segment

        if entry.object_path is None:
            continue

        if seg.type[0] == ".":
            continue
        
        if isinstance(seg, splat.segtypes.n64.header.N64SegHeader):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            s_path = entry.src_paths[0]
            if "ultralib" in str(s_path):
                opt_level = "-O2"

                if "/os/" in str(s_path):
                    opt_level = "-O1"

                if s_path.stem in ["exceptasm"]:
                    mips = "-mips3 -32"
                else:
                    mips = "-mips2 -32"

                build(
                    entry.object_path,
                    entry.src_paths,
                    "as_libultra",
                    variables={"flags": f"{opt_level} {mips}"},
                )
            else:
                build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            c_path = entry.src_paths[0]
            opt_level = "-O2"

            if c_path.stem in ["5E630", "98C330", "98D0F0", "993F80", "993C50", "9A6B10", "9A6F70", "9ABB50", "9ADAD0", "9D3230", "9D3660", "9D91C0", "A084B0", "9FAC10", "9FA580", "9FD510", "9FEC10"]:
                opt_level = "-g"

            if "ultralib" not in str(c_path):
                build(
                    entry.object_path,
                    entry.src_paths,
                    "cc",
                    variables={"flags": opt_level},
                )
            else:
                opt_level = "-O2"
                mips = "-mips2"
                ido = "5.3"
                libultra = "VERSION_I"

                if (
                    c_path.stem
                    in [
                        "pigetcmdq",
                        "controller",
                    ]
                    or "ultralib/src/os" in str(c_path)
                    or "ultralib/src/io" in str(c_path)
                ):
                    opt_level = "-O1"
                elif "ultralib/src/gu" in str(c_path) or "ultralib/src/sp" in str(
                    c_path
                ):
                    opt_level = "-O3"
                    if "color" in str(c_path):
                        ido = "7.1"
                    if c_path.stem == "spriteex2":
                        opt_level = "-O2"
                        ido = "7.1"
                elif "ultralib/src/libc" in str(c_path):
                    opt_level = "-O3"
                    mips = "-mips2 -32"

                    if c_path.stem in ["ll", "llbit", "llcvt"]:
                        opt_level = "-O1"
                        mips = "-mips3 -32"
                elif "ultralib/src/audio" in str(c_path):
                    ido = "7.1"

                if c_path.stem in [
                    "aisetfreq",
                    "cartrominit",
                    "contpfs",
                    "contramread",
                    "contramwrite",
                    "contreaddata",
                    "crc",
                    "epirawdma",
                    "epirawread",
                    "epirawwrite",
                    "gbpakcheckconnector",
                    "gbpakgetstatus",
                    "gbpakinit",
                    "gbpakpower",
                    "gbpakreadid",
                    "gbpakreadwrite",
                    "gbpaksetbank",
                    "motor",
                    "pfschecker",
                    "pfsfilestate",
                    "pfsgetstatus",
                    "pfsinitpak",
                    "pimgr",
                    "pfsselectbank",
                    "sirawdma",
                    "vimgr",
                    "viswapcontext",
                ]:
                    opt_level = "-O2"
                    libultra = "VERSION_J"
                elif c_path.stem in [
                    "devmgr",
                    "epiread",
                    "epiwrite",
                    "initialize",
                    "pirawdma",
                    "pirawread",
                    "sirawread",
                ]:
                    opt_level = "-O1"
                    libultra = "VERSION_J"

                build(
                    entry.object_path,
                    entry.src_paths,
                    "cc_libultra",
                    variables={
                        "flags": f"{opt_level} {mips}",
                        "ido": TOOLS_DIR / ("ido" + ido) / "cc",
                        "libultra": libultra,
                    },
                )
        elif isinstance(seg, splat.segtypes.common.textbin.CommonSegTextbin):
            if seg.sibling is None:
                build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.bin.CommonSegBin):
            build(entry.object_path, entry.src_paths, "bin")
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    ninja.build(
        ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[str(obj) for obj in built_objects],
        variables={"mapfile": MAP_PATH},
    )

    ninja.build(
        Z64_PATH,
        "z64",
        ELF_PATH,
    )

    ninja.build(
        OK_PATH,
        "sha1sum",
        "checksum.sha1",
        implicit=[Z64_PATH],
    )


def graph_segments():

    import pandas as pd
    import numpy as np
    import matplotlib.pyplot as plt
    from splat.segtypes.segment import Segment

    graph_items = []
    vram_start = 0x80000400

    for item in split.segment_rams.items():
        segment: Segment = item[2]
        graph_items.append(
            dict(
                Segment=segment.name,
                VRAMStart=segment.vram_start,
                VRAMEnd=segment.vram_end,
                VRAMLength=segment.vram_end - segment.vram_start,
                PosFromStart=segment.vram_start - vram_start,
            )
        )

    # Sort graph_items by VRAMStart
    graph_items = sorted(graph_items, key=lambda x: x["VRAMStart"])

    df = pd.DataFrame(graph_items)
    plt.barh(y=df["Segment"], width=df["VRAMLength"], left=df["PosFromStart"])
    plt.grid(axis="x")

    axes = plt.gca()
    xlabels = map(lambda t: "0x%08X" % (int(t) + vram_start), axes.get_xticks())
    axes.set_xticklabels(xlabels)

    plt.show()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Configure the project")
    parser.add_argument(
        "-c",
        "--clean",
        help="Clean extraction and build artifacts",
        action="store_true",
    )
    parser.add_argument(
        "-s",
        "--setup",
        help="Download and extract IDO compiler",
        action="store_true",
    )
    parser.add_argument(
        "-d",
        "--disassemble-all",
        help="Download and extract IDO compiler",
        action="store_true",
    )
    args = parser.parse_args()

    if args.clean:
        clean()

    if args.setup:
        setup()
        sys.exit(0)

    if not Path(f"{BASENAME}.z64").exists():
        print(f"{BASENAME}.z64 is missing!")
        sys.exit(1)

    split.main([YAML_FILE], modes="all", verbose=False, disassemble_all=args.disassemble_all)

    linker_entries = split.linker_writer.entries

    # graph_segments()

    create_build_script(linker_entries)

    write_permuter_settings()
