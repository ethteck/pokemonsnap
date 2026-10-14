#! /usr/bin/env python3

import argparse
import glob
import json
import os
import shutil
import sys
from pathlib import Path
import platform
from typing import Dict, List, Set, Union

import ninja_syntax
import requests
import splat
import splat.scripts.split as split
from splat.segtypes.linker_entry import LinkerEntry
from tools.native_vpk0 import linker_script as native_payload_linker_script

ROOT = Path(__file__).parent.relative_to(os.getcwd())
TOOLS_DIR = ROOT / "tools"

# Allow importing from the tools/build directory
sys.path.insert(0, str((TOOLS_DIR / "build").resolve()))

YAML_FILE = Path("splat.yaml")
BASENAME = "pokemonsnap"
LD_PATH = f"{BASENAME}.ld"
MAP_PATH = f"build/{BASENAME}.map"
ELF_PATH = f"build/{BASENAME}.elf"
Z64_PATH = f"build/{BASENAME}.z64"
OBJECTS_PATH = f"build/{BASENAME}.objects"
GENERATED_UNDEFINED_SYMS_PATH = f"build/{BASENAME}.undefined_syms.txt"
UNDEFINED_SYMS_GENERATOR = TOOLS_DIR / "build" / "undefined_syms.py"
OK_PATH = f"build/{BASENAME}.ok"

COMMON_INCLUDES = "-I include -I src -I ultralib/include -I ultralib/include/ido -I ultralib/include/PR -I ultralib/src -I build/include -I build -I ."
IDO_DEFS = "-DF3DEX_GBI_2 -D_LANGUAGE_C -DNDEBUG -D_FINALROM"

CROSS = "mips-linux-gnu-"
CROSS_NM = f"{CROSS}nm"
CROSS_AS = f"{CROSS}as"
CROSS_CPP = shutil.which(f"{CROSS}cpp") or shutil.which("cpp") or f"{CROSS}cpp"
CROSS_LD = f"{CROSS}ld"
CROSS_STRIP = f"{CROSS}strip"
CROSS_OBJCOPY = f"{CROSS}objcopy"
AS_FLAGS = f"-G 0 {COMMON_INCLUDES} -EB -mtune=vr4300 -march=vr4300"

IDO_72_CC = TOOLS_DIR / "ido7.1" / "cc"
IDO_53_CC = TOOLS_DIR / "ido5.3" / "cc"

O32_TOOL = ROOT / "ultralib/tools/set_o32abi_bit.py"

RAW_BUILD_PREAMBLE = f"$ido -G 0 -non_shared -fullwarn -verbose -Wab,-r4300_mul -woff 513,516,649,838,712 -Xcpluscomm -nostdinc $flags {COMMON_INCLUDES} {IDO_DEFS}"

GAME_CC_CMD = f"tools/asm_proc/asm-processor --input-enc=utf-8 --output-enc=EUC-JP {IDO_72_CC} -- {CROSS_AS} {AS_FLAGS} -- -G 0 -non_shared -fullwarn -verbose -Xcpluscomm -nostdinc -Wab,-r4300_mul $flags -mips2 {COMMON_INCLUDES} {IDO_DEFS} -DBUILD_VERSION=VERSION_I -c -o $out $in"

RAW_CC_CMD = (
    f"{RAW_BUILD_PREAMBLE} -DBUILD_VERSION=VERSION_I -c -o $out $in && {O32_TOOL} $out"
)

LIBULTRA_CC_CMD = (
    f"{RAW_BUILD_PREAMBLE} -DBUILD_VERSION=$libultra -c -o $out $in && {O32_TOOL} $out"
)

LIBULTRA_AS_CMD = f"{IDO_53_CC} -G 0 -non_shared -fullwarn -verbose -Wab,-r4300_mul -woff 513,516,649,838,712 $flags {COMMON_INCLUDES} -D_FINALROM -DBUILD_VERSION=VERSION_I -c -o $out $in && {O32_TOOL} $out && {CROSS_STRIP} $out -N asdasdasdasd"

PIGMENT64 = "pigment64"
BIN2C = TOOLS_DIR / "bin2c.py"


def clean():
    if os.path.exists(".splache"):
        os.remove(".splache")
    shutil.rmtree("asm", ignore_errors=True)
    shutil.rmtree("assets", ignore_errors=True)
    shutil.rmtree("build", ignore_errors=True)
    shutil.rmtree(".splat", ignore_errors=True)


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

def obtain_asm_processor():
    download_dir = TOOLS_DIR / "asm_proc"

    if download_dir.exists():
        print(
            f"asm-processor already exists at {download_dir}, removing and re-downloading"
        )
        shutil.rmtree(download_dir)

    ASM_PROC_RECOMP_VERSION = "1.0.1"

    if sys.platform == "darwin":
        if platform.processor() == "arm":
            asm_proc_os = "aarch64-apple-darwin"
        else:
            asm_proc_os = "x86_64-apple-darwin"
    elif sys.platform == "linux":
        if platform.processor() == "arm":
            asm_proc_os = "aarch64-unknown-linux-gnu"
        else:
            asm_proc_os = "x86_64-unknown-linux-gnu"
    elif sys.platform == "win32":
        asm_proc_os = "x86_64-pc-windows-msvc"
    else:
        print(f"Unsupported platform {sys.platform}")
        sys.exit(1)

    asm_proc_triple = f"asm-processor-{asm_proc_os}"
    asm_proc_tar_name = f"{asm_proc_triple}.tar.xz"
    url = f"https://github.com/simonlindholm/asm-processor/releases/download/{ASM_PROC_RECOMP_VERSION}/{asm_proc_tar_name}"
    target_path = TOOLS_DIR / asm_proc_tar_name

    print(f"Downloading asm-processor: {url}")
    response = requests.get(url)
    if response.status_code != 200:
        print(f"Failed to download asm-processor tarball from {url}")
        sys.exit(1)
    with open(target_path, "wb") as f:
        f.write(response.content)

    shutil.unpack_archive(target_path, download_dir)
    os.remove(target_path)

    for each_file in (download_dir / asm_proc_triple).glob('*'):
        each_file.rename(download_dir / each_file.name)
    (download_dir / asm_proc_triple).rmdir()


def setup():
    obtain_ido_recomp("5.3")
    obtain_ido_recomp("7.1")
    obtain_asm_processor()
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
    img_incs = []

    def build(
        object_paths: Union[Path, List[Path]],
        src_paths: List[Path],
        task: str,
        implicit=[],
        variables: Dict[str, str] = {},
        implicit_outputs: List[str] = [],
    ):
        if not isinstance(object_paths, list):
            object_paths = [object_paths]

        object_strs = [str(obj) for obj in object_paths]

        if task == "cc":
            implicit = ["img_incs"]  # all standard c files depend on all image incs

        for object_path in object_paths:
            if object_path.suffix == ".o":
                built_objects.add(object_path)
            ninja.build(
                outputs=object_strs,
                rule=task,
                inputs=[str(s) for s in src_paths],
                implicit=implicit,
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
        command=f"bash -o pipefail -c '{CROSS_CPP} {COMMON_INCLUDES} $in -o - | iconv -f UTF-8 -t EUC-JP | {CROSS_AS} -G0 {COMMON_INCLUDES} -EB -mtune=vr4300 -march=vr4300 -o $out'",
    )

    ninja.rule(
        "as_libultra",
        description="as $in",
        command=f"{LIBULTRA_AS_CMD}",
    )

    ninja.rule(
        "cc",
        description="cc $in",
        command=f"{CROSS_CPP} -M {COMMON_INCLUDES} {IDO_DEFS} -DBUILD_VERSION=VERSION_I -MT $out -MF $out.d $in && {GAME_CC_CMD}",
        depfile="$out.d",
        deps="gcc",
    )

    ninja.rule(
        "cc_raw",
        description="cc $in",
        command=f"{RAW_CC_CMD}",
    )

    ninja.rule(
        "cc_libultra",
        description="cc $in",
        command=f"{LIBULTRA_CC_CMD}",
    )

    ninja.rule(
        "undefined_syms",
        description="undefined_syms $out",
        command=f"{sys.executable} {UNDEFINED_SYMS_GENERATOR} --nm {CROSS_NM} --objects $objects --auto undefined_syms_auto.txt --manual undefined_syms.txt --output $out",
    )

    ninja.rule(
        "ld",
        description="link $out",
        command=f"{CROSS_LD} -T undefined_syms.txt -T $undefined_syms -Map $mapfile -T $in -o $out",
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

    ninja.rule(
        "effect_sprites",
        description="effect_sprites $in",
        command=f"{sys.executable} tools/build/effect_sprites.py $in $out",
    )

    ninja.rule(
        "vpk0_compress",
        description="vpk0 $in",
        command=f"{sys.executable} tools/vpk0.py $in $out",
    )

    ninja.rule(
        "idle_script",
        description="idle_script $in",
        command=f"{sys.executable} tools/idle_script.py build $in $out",
    )

    ninja.rule(
        "effect_scripts",
        description="effect_scripts $in",
        command=f"{sys.executable} tools/effect_scripts.py build $in $out",
    )

    ninja.rule(
        "audio_seq",
        description="audio_seq $in",
        command=f"{sys.executable} tools/audio_seq.py build $in $out",
    )

    ninja.rule(
        "audio_pair",
        description="audio_pair $in",
        command=f"{sys.executable} tools/audio_bank.py build $in $bank_bin $table_bin",
    )

    ninja.rule(
        "native_payload_link",
        description="native_payload $out",
        command=f"{CROSS_LD} -T $script -o $out $in",
    )

    ninja.rule(
        "native_payload_bin",
        description="native_payload_bin $out",
        command=f"{CROSS_OBJCOPY} -O binary -j .payload $in $out",
    )

    ninja.rule(
        "window_font",
        description="window_font $in",
        command=f"{sys.executable} tools/window_font.py $in $out --glyph-size $glyph_size --c",
    )

    ninja.rule(
        "native_photos_extract",
        description="native_photos_extract $in",
        command=f"{sys.executable} tools/photo_bank.py extract --input $in --output $out",
        restat=True,
    )
    ninja.build(
        "assets/remaining_ui_ae0510/photos.json",
        "native_photos_extract",
        "pokemonsnap.z64",
        implicit=["tools/photo_bank.py"],
    )

    ninja.rule(
        "native_photos",
        description="native_photos $in",
        command=f"{sys.executable} tools/photo_bank.py generate --input $in --output $out",
        restat=True,
    )

    photo_include = Path("build/assets/remaining_ui_ae0510/photos.inc.c")
    build(
        photo_include,
        ["assets/remaining_ui_ae0510/photos.json"],
        "native_photos",
        implicit=["tools/photo_bank.py"],
    )
    img_incs.append(str(photo_include))

    vertex_layout = Path("tools/native_layouts/vertices.json")
    vertex_outputs = [
        record["include"] for record in json.loads(vertex_layout.read_text())["vertices"]
    ]
    ninja.rule(
        "native_vertices",
        description="native_vertices $in",
        command=f"{sys.executable} tools/native_vertices.py pokemonsnap.z64 {vertex_layout}",
    )
    ninja.build(
        vertex_outputs,
        "native_vertices",
        ["pokemonsnap.z64", str(vertex_layout)],
        implicit=["tools/native_vertices.py", "tools/vpk0_codec.py"],
    )
    img_incs.extend(vertex_outputs)

    gfx_layout = Path("tools/native_layouts/gfx.json")
    gfx_outputs = [
        record["include"] for record in json.loads(gfx_layout.read_text())["display_lists"]
    ]
    ninja.rule(
        "native_gfx",
        description="native_gfx $in",
        command=f"{sys.executable} tools/native_gfx.py pokemonsnap.z64 {gfx_layout}",
    )
    ninja.build(
        gfx_outputs,
        "native_gfx",
        ["pokemonsnap.z64", str(gfx_layout)],
        implicit=["tools/native_gfx.py", "tools/vpk0_codec.py"],
    )
    img_incs.extend(gfx_outputs)

    for entry in linker_entries:
        seg = entry.segment

        if entry.object_path is None:
            continue

        # images embedded inside data aren't linked, but they do need to be built into .bin files
        if seg.type == ".data" and isinstance(
            seg, splat.segtypes.common.group.CommonSegGroup
        ):
            for seg in seg.subsegments:
                if seg.type == "snap_window_font":
                    inc_path = Path("build/" + str(seg.out_path()) + ".bin.c")
                    build(
                        inc_path, [seg.out_path()], "window_font",
                        implicit=["tools/window_font.py"],
                        variables={"glyph_size": str(seg.glyph_size)},
                    )
                    img_incs.append(str(inc_path))
                    continue
                if isinstance(seg, splat.segtypes.n64.img.N64SegImg):
                    flags = ""
                    if seg.n64img.flip_h:
                        flags += "--flip-x "
                    if seg.n64img.flip_v:
                        flags += "--flip-y "
                    if getattr(seg, "word_swap", False):
                        flags += "--word-swap "

                    include = seg.yaml.get("native_include") if isinstance(seg.yaml, dict) else None
                    inc_path = Path("build") / include if include else Path("build/" + str(seg.out_path()) + ".bin.c")
                    bin_path = inc_path.with_suffix(".bin")
                    src_path = seg.out_path()

                    build(
                        bin_path,
                        [src_path],
                        "pigment",
                        variables={
                            "img_type": getattr(seg, "image_type", seg.type),
                            "img_flags": flags,
                        },
                    )
                    build(inc_path, [bin_path], "bin2c")
                    img_incs.append(str(inc_path))
                elif isinstance(seg, splat.segtypes.n64.palette.N64SegPalette):
                    bin_path = Path(
                        "build/" + str(seg.out_path().with_suffix(".pal")) + ".bin"
                    )
                    inc_path = Path(str(bin_path) + ".c")
                    src_path = seg.out_path()
                    build(
                        bin_path,
                        [src_path],
                        "pigment",
                        variables={"img_type": seg.type, "img_flags": ""},
                    )
                    build(inc_path, [bin_path], "bin2c")
                    img_incs.append(str(inc_path))

    for entry in linker_entries:
        if entry.segment.type != "vpk0":
            continue
        layout = json.loads(entry.src_paths[0].read_text())
        for image in layout["images"]:
            flags = ""
            if image.get("flip_x"):
                flags += "--flip-x "
            if image.get("flip_y"):
                flags += "--flip-y "
            if image.get("word_swap"):
                flags += "--word-swap "
            inc_path = Path("build") / image["include"]
            bin_path = inc_path.with_suffix(".bin")
            build(
                bin_path, [Path(image["asset"])], "pigment",
                variables={"img_type": image["fmt"], "img_flags": flags},
            )
            build(inc_path, [bin_path], "bin2c")
            img_incs.append(str(inc_path))

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

            if c_path.stem == "osFlash":
                opt_level = "-O0"
                ido = "5.3"
                build(
                    entry.object_path,
                    entry.src_paths,
                    "cc_raw",
                    variables={
                        "flags": opt_level,
                        "ido": TOOLS_DIR / ("ido" + ido) / "cc",
                    },
                )
                continue

            if "ultralib" not in str(c_path):
                opt_level = "-O2"
                ido = "7.1"

                extra_flags = ""
                if c_path.stem in ["26D80", "8456E0"]:
                    extra_flags = " -acpp -Wp,-+"

                if c_path.stem in [
                    "98C330",
                    "98D0F0",
                    "993F80",
                    "993C50",
                    "9A6B10",
                    "9A6F70",
                    "9ABB50",
                    "9ADAD0",
                    "9D3230",
                    "9D3660",
                    "9D91C0",
                    "A084B0",
                    "9FAC10",
                    "9FA580",
                    "9FD510",
                    "9FEC10",
                ]:
                    opt_level = "-g"
                elif c_path.stem in ["848B50"]:
                    opt_level = "-O2 -g3"
                elif c_path.stem in ["847B60"]:
                    opt_level = "-O2 -Wo,-unrolllimit,500"

                build(
                    entry.object_path,
                    entry.src_paths,
                    "cc",
                    variables={
                        "flags": f"{opt_level} {extra_flags}",
                    },
                )
                continue

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
            elif "ultralib/src/gu" in str(c_path) or "ultralib/src/sp" in str(c_path):
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
            elif seg.get_linker_section() == ".text":
                # Only build the .text section file for a textbin with siblings
                build(entry.object_path, entry.src_paths, "as")
        elif seg.type == "vpk0":
            layout_path = entry.src_paths[0]
            layout = json.loads(layout_path.read_text())
            native_bin = entry.object_path.with_suffix(".native.bin")
            native_elf = native_bin.with_suffix(".elf")
            native_script = native_bin.with_suffix(".ld")
            native_script.parent.mkdir(parents=True, exist_ok=True)
            script = native_payload_linker_script(layout)
            if not native_script.exists() or native_script.read_text() != script:
                native_script.write_text(script)
            objects = []
            for source in layout["sources"]:
                objects.append(source["object"])
                ninja.build(
                    source["object"], "cc", source["path"],
                    implicit=["img_incs", *source.get("implicit", [])],
                    variables={"flags": source["flags"]},
                )
            ninja.build(
                str(native_elf), "native_payload_link", objects,
                implicit=[str(native_script), str(layout_path)],
                variables={"script": str(native_script)},
            )
            build(native_bin, [native_elf], "native_payload_bin")
            compressed = entry.object_path.with_suffix(".vpk0")
            build(
                compressed, [native_bin], "vpk0_compress",
                implicit=["tools/vpk0.py", "tools/vpk0_codec.py"],
            )
            build(entry.object_path, [compressed], "bin")
        elif seg.type == "snap_idle_script":
            raw_bin = entry.object_path.with_suffix("")
            build(raw_bin, entry.src_paths, "idle_script", implicit=["tools/idle_script.py"])
            build(entry.object_path, [raw_bin], "bin")
        elif seg.type == "snap_effect_scripts":
            raw_bin = entry.object_path.with_suffix("")
            build(raw_bin, entry.src_paths, "effect_scripts", implicit=["tools/effect_scripts.py"])
            build(entry.object_path, [raw_bin], "bin")
        elif seg.type in ("snap_audio_sbk", "snap_audio_seq"):
            raw_bin = entry.object_path.with_suffix("")
            build(raw_bin, entry.src_paths, "audio_seq", implicit=["tools/audio_seq.py"])
            build(entry.object_path, [raw_bin], "bin")
        elif seg.type in ("snap_audio_bank", "snap_audio_table"):
            raw_bin = entry.object_path.with_suffix("")
            if seg.type == "snap_audio_bank":
                table_entry = next(
                    item for item in linker_entries
                    if item.segment.type == "snap_audio_table"
                    and item.segment.rom_start == seg.yaml["audio_table_start"]
                )
                table_json = table_entry.src_paths[0]
                table_bin = table_entry.object_path.with_suffix("")
                table = json.loads(table_json.read_text())
                implicit = ["tools/audio_bank.py"] + [
                    str(table_json.parent / sample["asset"])
                    for sample in table["samples"]
                ]
                ninja.build(
                    outputs=[str(raw_bin), str(table_bin)],
                    rule="audio_pair",
                    inputs=[str(entry.src_paths[0]), str(table_json)],
                    implicit=implicit,
                    variables={"bank_bin": str(raw_bin), "table_bin": str(table_bin)},
                )
            build(entry.object_path, [raw_bin], "bin")
        elif seg.type == "snap_fill":
            build(entry.object_path, entry.src_paths, "as")
        elif isinstance(seg, splat.segtypes.common.bin.CommonSegBin):
            build(entry.object_path, entry.src_paths, "bin")
        elif seg.type == "snap_effect_sprites":
            raw_bin = entry.object_path.with_suffix(".bin")
            build(
                raw_bin,
                entry.src_paths,
                "effect_sprites",
                implicit=glob.glob(str(entry.src_paths[0]) + "/*"),
            )
            build(entry.object_path, [raw_bin], "bin")
        else:
            print(f"ERROR: Unsupported build segment type {seg.type}")
            sys.exit(1)

    object_strs = sorted(str(obj) for obj in built_objects)
    objects_path = Path(OBJECTS_PATH)
    objects_path.parent.mkdir(parents=True, exist_ok=True)
    objects_path.write_text("\n".join(object_strs) + "\n")

    ninja.build(
        GENERATED_UNDEFINED_SYMS_PATH,
        "undefined_syms",
        [
            str(UNDEFINED_SYMS_GENERATOR),
            OBJECTS_PATH,
            "undefined_syms_auto.txt",
            "undefined_syms.txt",
        ],
        implicit=object_strs,
        variables={"objects": OBJECTS_PATH},
    )

    ninja.build(
        ELF_PATH,
        "ld",
        LD_PATH,
        implicit=[GENERATED_UNDEFINED_SYMS_PATH, *object_strs],
        variables={
            "mapfile": MAP_PATH,
            "undefined_syms": GENERATED_UNDEFINED_SYMS_PATH,
        },
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

    ninja.build("img_incs", "phony", img_incs)


def graph_segments():

    import matplotlib.pyplot as plt
    import numpy as np
    import pandas as pd
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

    split.main(
        [YAML_FILE], modes=["all"], verbose=False, disassemble_all=args.disassemble_all
    )

    linker_entries = split.linker_writer.entries

    # graph_segments()

    create_build_script(linker_entries)

    write_permuter_settings()
