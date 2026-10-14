"""Verified repeated-byte ROM fill, generated from segment size and value."""

from pathlib import Path

from splat.segtypes.common.bin import CommonSegBin
from splat.segtypes.linker_entry import LinkerEntry
from splat.util import options


class N64SegSnap_fill(CommonSegBin):
    def out_path(self) -> Path:
        return options.opts.asm_path / "data" / self.dir / f"{self.name}.fill.s"

    def get_linker_entries(self):
        if not self.has_linker_entry:
            return []
        native = options.opts.asset_path / self.dir / f"{self.name}.bin"
        return [
            LinkerEntry(
                self,
                [self.out_path()],
                native,
                self.get_linker_section_order(),
                ".rom_fill",
                self.is_noload(),
            )
        ]

    def split(self, rom_bytes):
        value = self.yaml.get("value", 0) if isinstance(self.yaml, dict) else 0
        if not isinstance(value, int) or not 0 <= value <= 255:
            raise ValueError("snap_fill value must be a byte")
        if not isinstance(self.rom_start, int) or not isinstance(self.rom_end, int):
            raise ValueError("snap_fill requires known ROM bounds")
        if any(byte != value for byte in rom_bytes[self.rom_start:self.rom_end]):
            raise ValueError(f"{self.name} is not uniform fill 0x{value:02X}")
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(
            f'.section .rom_fill,"a"\n.fill 0x{self.size:X}, 1, 0x{value:02X}\n',
            encoding="utf-8",
        )
        self.log(f"Wrote explicit fill source to {path}")
