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

ROOT = Path(__file__).parent.resolve()
TOOLS_DIR = ROOT / "tools"

YAML_FILE = "splat.yaml"
BASENAME = "pokemonsnap"
LD_PATH = f"{BASENAME}.ld"
MAP_PATH = f"build/{BASENAME}.map"
ELF_PATH = f"build/{BASENAME}.elf"
Z64_PATH = f"build/{BASENAME}.z64"
OK_PATH = f"build/{BASENAME}.ok"

COMMON_INCLUDES = "-I include"
IDO_DEFS = "-DF3DEX_GBI_2 -D_LANGUAGE_C"

CROSS = "mips-linux-gnu-"
CROSS_AS = f"{CROSS}as"
CROSS_LD = f"{CROSS}ld"
CROSS_OBJCOPY = f"{CROSS}objcopy"
AS_FLAGS = f"-G 0 {COMMON_INCLUDES} -EB -mtune=vr4300 -march=vr4300"

IDO_DIR = TOOLS_DIR / "ido5.3"
IDO_CC = f"{IDO_DIR}/cc"
GAME_CC_CMD = f"python3 tools/asm_processor/build.py {IDO_CC} -- {CROSS_AS} {AS_FLAGS} -- -G 0 -non_shared -fullwarn -verbose -Xcpluscomm -nostdinc -Wab,-r4300_mul $flags {COMMON_INCLUDES} -I build/include -I src {IDO_DEFS} -c -o $out $in"


def clean():
    if os.path.exists(".splache"):
        os.remove(".splache")
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)


def obtain_ido_recomp():

    if IDO_DIR.exists():
        print(f"IDO already exists at {IDO_DIR}, removing and re-downloading")
        shutil.rmtree(IDO_DIR)

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

    ido_tar_name = f"ido-7.1-recomp-{ido_os}.tar.gz"
    url = f"https://github.com/decompals/ido-static-recomp/releases/download/{IDO_RECOMP_VERSION}/{ido_tar_name}"
    target_path = TOOLS_DIR / ido_tar_name

    print(f"Downloading IDO: {url}")
    response = requests.get(url)
    if response.status_code != 200:
        print(f"Failed to download IDO tarball from {url}")
        sys.exit(1)
    with open(target_path, "wb") as f:
        f.write(response.content)

    shutil.unpack_archive(target_path, IDO_DIR)
    os.remove(target_path)


def setup():
    obtain_ido_recomp()
    print("Setup complete!")


def write_permuter_settings():
    with open("permuter_settings.toml", "w") as f:
        # TODO FIX
        f.write(
            f"""compiler_command = "{GAME_COMPILE_CMD} -D__GNUC__"
assembler_command = "mips-linux-gnu-as -march=r5900 -mabi=eabi -Iinclude"
compiler_type = "ido"

[preserve_macros]

[decompme.compilers]
"tools/build/cc/gcc/gcc" = "ido7.1"
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
        command=f"cpp {COMMON_INCLUDES} $in -o - | {CROSS}as -G0 {COMMON_INCLUDES} -EB -mtune=vr4300 -march=vr4300 -o $out",
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{GAME_CC_CMD}",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{CROSS}ld -T undefined_syms.txt -T undefined_syms_auto.txt -T undefined_funcs.txt -T undefined_funcs_auto.txt -Map $mapfile -T $in -o $out",
    )

    ninja.rule(
        "sha1sum",
        description="sha1sum $in",
        command="sha1sum -c $in && touch $out",
    )

    ninja.rule(
        "elf",
        description="elf $out",
        command=f"{CROSS}objcopy $in $out -O binary",
    )

    ninja.rule(
        "z64",
        description="rom $out",
        command=f"{CROSS_OBJCOPY} $in $out -O binary",
    )

    for entry in linker_entries:
        seg = entry.segment

        if seg.type[0] == ".":
            continue

        if entry.object_path is None:
            continue

        if isinstance(seg, splat.segtypes.n64.header.N64SegHeader):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.asm.CommonSegAsm) or isinstance(
            seg, splat.segtypes.common.data.CommonSegData
        ):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.c.CommonSegC):
            flags = "-O2"
            if "src/os/O1" in str(entry.src_paths[0]):
                flags = "-O1"

            build(entry.object_path, entry.src_paths, "cc", variables={"flags": flags})
        elif isinstance(seg, splat.segtypes.common.textbin.CommonSegTextbin):
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.databin.CommonSegDatabin):
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
    args = parser.parse_args()

    if args.clean:
        clean()

    if args.setup:
        setup()
        sys.exit(0)

    split.main([YAML_FILE], modes="all", verbose=False)

    linker_entries = split.linker_writer.entries

    create_build_script(linker_entries)

    # write_permuter_settings()
