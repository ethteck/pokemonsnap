from splat.segtypes.segment import Segment
from splat.util import options
from pathlib import Path
import struct

class N64SegSnap_height_map_patches(Segment):
    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start : self.rom_end]
        self.file_text = self.disassemble_data(data)

    def disassemble_data(self, data):
        lines = []
        num_patches = len(data) // 20
        data = data[:20 * num_patches]
        for patch in struct.iter_unpack(">ffffI", data):
            A, B, C, D, surface = patch
            assert (surface & 0xFF) == 0
            surface_enum_name = f"SURFACE_TYPE_{(surface >> 8):06X}"
            lines.append(f"{{ {A:12.6f}, {B:12.6f}, {C:12.6f}, {D:12.6f}, {surface_enum_name} << 8 }},")
        return "\n".join(lines) + "\n"

    def split(self, rom_bytes):
        self.out_path().parent.mkdir(parents=True, exist_ok=True)
        with open(self.out_path(), "w") as f:
            f.write(self.file_text)

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.hm.inc.c"
