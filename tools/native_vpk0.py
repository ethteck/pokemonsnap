"""Native VPK0 payload layout and reversible PNG extraction.

Loaded sections are linked at their original VRAM. Writable display-list workspaces
are real NOLOAD BSS and are never included in the compressed image. Native C source,
PNG assets and this layout are the only production inputs; legacy bins are not read.
"""

from pathlib import Path

import n64img.image


def extract_images(data: bytes, layout: dict) -> None:
    if len(data) != layout["size"]:
        raise ValueError("native VPK0 payload size differs from configured layout")
    images = layout.get("images", [])
    by_address = {image.get("address", layout["vram"] + image["offset"]): image for image in images}
    for image in images:
        offset, size = image["offset"], image["size"]
        raw = data[offset:offset + size]
        if len(raw) != size:
            raise ValueError("native payload image exceeds loaded data")
        if image.get("word_swap"):
            raw = bytearray(raw)
            row_size = size // image["height"]
            for row in range(1, image["height"], 2):
                for start in range(row * row_size, (row + 1) * row_size - 7, 8):
                    raw[start:start + 8] = raw[start + 4:start + 8] + raw[start:start + 4]
            raw = bytes(raw)
        decoder = getattr(n64img.image, image["fmt"].upper())
        decoded = decoder(raw, image["width"], image["height"])
        decoded.flip_h = image.get("flip_x", False)
        decoded.flip_v = image.get("flip_y", False)
        if image.get("palette") is not None:
            palette = by_address[image["palette"]]
            decoded.set_palette(data[palette["offset"]:palette["offset"] + palette["size"]])
        output = Path(image["asset"])
        output.parent.mkdir(parents=True, exist_ok=True)
        decoded.write(output)


def linker_script(layout: dict) -> str:
    loaded = [section for section in layout["sections"] if not section.get("noload")]
    bss = [section for section in layout["sections"] if section.get("noload")]
    lines = ["SECTIONS {", f"  .payload 0x{layout['vram']:X} : {{"]
    for section in loaded:
        lines += [f"    . = 0x{section['offset']:X};",
                  f"    {section['object']}({section['name']})"]
    lines += ["  }", f"  ASSERT(SIZEOF(.payload) == 0x{layout['size']:X}, \"native VPK0 loaded size mismatch\")"]
    if bss:
        lines.append(f"  .payload_bss 0x{layout['vram'] + layout['size']:X} (NOLOAD) : {{")
        for section in bss:
            lines += [f"    . = 0x{section['offset'] - layout['size']:X};",
                      f"    {section['object']}({section['name']})"]
        lines.append("  }")
    lines += ["  /DISCARD/ : { *(.text .data .rodata .rdata .bss .reginfo .MIPS.abiflags .mdebug* .comment .note* .pdr .eh_frame) }", "}"]
    return "\n".join(lines) + "\n"
