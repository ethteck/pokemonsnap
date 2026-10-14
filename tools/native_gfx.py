"""Extract native F3DEX2 initializer bodies from the original big-endian ROM.

Recipes contain display-list ranges and source-local symbolic relocation operands,
not command words or saved macro text. libgfxd supplies the semantic GBI macros;
segmented RSP addresses remain numeric, while CPU pointers retain their original
symbols, array indices and structure members. Unknown commands or unresolved CPU
pointers are errors, never raw-word initializer fallbacks.
"""

import argparse
import json
from pathlib import Path

import pygfxd as gd

from vpk0_codec import decompress_vpk0


POINTER_TYPES = {
    gd.GfxdArgType.Tlut,
    gd.GfxdArgType.Timg,
    gd.GfxdArgType.Cimg,
    gd.GfxdArgType.Zimg,
    gd.GfxdArgType.Dl,
    gd.GfxdArgType.Mtxptr,
    gd.GfxdArgType.Uctext,
    gd.GfxdArgType.Ucdata,
    gd.GfxdArgType.Lookatptr,
    gd.GfxdArgType.Segptr,
    gd.GfxdArgType.Lightsn,
    gd.GfxdArgType.Lightptr,
    gd.GfxdArgType.Vtxptr,
    gd.GfxdArgType.Vpptr,
    gd.GfxdArgType.Dram,
}
SPLIT_MACROS = {
    getattr(gd.GfxdMacroId, f"SPSetLights{count}") for count in range(1, 8)
} | {gd.GfxdMacroId.SPLookAt}


def gfx_initializers(data: bytes, offset: int, count: int, relocations: list) -> str:
    size = count * 8
    if offset < 0 or count <= 0 or offset + size > len(data):
        raise ValueError("display-list range exceeds input container")
    operands = {relocation["address"]: relocation["operand"] for relocation in relocations}
    chunks = []
    errors = []
    consumed = 0
    emitted = 0

    def output(buf, length):
        chunks.append(buf[:length])
        return length

    def argument(index):
        kind = gd.gfxd_arg_type(index)
        if kind not in POINTER_TYPES:
            gd.gfxd_arg_dflt(index)
            return
        address = gd.gfxd_arg_value(index)[1]
        if address in operands:
            gd.gfxd_puts(operands[address])
        elif address < 0x10000000:
            # RSP segment offsets are not CPU symbol aliases.
            gd.gfxd_puts(f"(void*)0x{address:X}")
        else:
            errors.append(
                f"unresolved {kind.name} pointer 0x{address:08X} "
                f"at display-list offset 0x{gd.gfxd_macro_offset():X}"
            )

    def emit():
        nonlocal emitted
        if gd.gfxd_macro_id() == gd.GfxdMacroId.Invalid:
            errors.append(f"unsupported command at display-list offset 0x{gd.gfxd_macro_offset():X}")
            return 1
        emitted += gd.gfxd_macro_packets() * 8
        gd.gfxd_puts("    ")
        gd.gfxd_macro_dflt()
        gd.gfxd_puts(",\n")
        return int(bool(errors))

    def macro():
        nonlocal consumed
        consumed = gd.gfxd_macro_offset() + gd.gfxd_macro_packets() * 8
        if gd.gfxd_macro_id() in SPLIT_MACROS:
            # Adjacent Ambient/Light globals need not be a single LightsN object.
            # libgfxd's packet iterator continues on zero, unlike the Python
            # binding's docstring; keep their individual symbolic operands.
            return gd.gfxd_foreach_pkt(emit)
        return emit()

    gd.gfxd_input_buffer(data[offset:offset + size])
    gd.gfxd_output_callback(output)
    gd.gfxd_target(gd.gfxd_f3dex2)
    gd.gfxd_endian(gd.GfxdEndian.big, 4)
    gd.gfxd_disable(gd.GfxdCap.stop_on_end)
    gd.gfxd_disable(gd.GfxdCap.stop_on_invalid)
    gd.gfxd_disable(gd.GfxdCap.emit_ext_macro)
    gd.gfxd_disable(gd.GfxdCap.emit_q_macro)
    gd.gfxd_arg_fn(argument)
    gd.gfxd_macro_fn(macro)
    result = gd.gfxd_execute()
    if errors:
        raise ValueError("; ".join(errors))
    if result != 0 or consumed != size or emitted != size:
        raise ValueError("semantic decoder did not consume the complete display-list range")
    return b"".join(chunks).decode("ascii")


def extract(rom: bytes, layout: dict, output_root: Path) -> None:
    if rom[:4] != bytes.fromhex("80371240"):
        raise ValueError("expected original big-endian .z64 ROM")
    if layout["format"] != "n64-gfx":
        raise ValueError("unsupported display-list recipe format")
    containers = {}
    for name, recipe in layout["containers"].items():
        if recipe["kind"] == "rom":
            containers[name] = rom
        elif recipe["kind"] == "vpk0":
            start, end = recipe["rom_offset"], recipe["rom_end"]
            if not 0 <= start < end <= len(rom):
                raise ValueError("VPK0 container exceeds original ROM")
            data, consumed = decompress_vpk0(rom[start:end])
            if len(data) != recipe["size"]:
                raise ValueError("VPK0 container size differs from display-list recipe")
            containers[name] = data
        else:
            raise ValueError(f"unsupported display-list container: {recipe['kind']}")
    for display_list in layout["display_lists"]:
        try:
            body = gfx_initializers(
                containers[display_list["container"]],
                display_list["offset"],
                display_list["count"],
                display_list["relocations"],
            )
        except ValueError as error:
            raise ValueError(f"{display_list['symbol']}: {error}") from error
        destination = output_root / display_list["include"]
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_text(body)


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("recipe", type=Path)
    parser.add_argument("--output-root", type=Path, default=Path("."))
    args = parser.parse_args()
    extract(args.rom.read_bytes(), json.loads(args.recipe.read_text()), args.output_root)


if __name__ == "__main__":
    main()
