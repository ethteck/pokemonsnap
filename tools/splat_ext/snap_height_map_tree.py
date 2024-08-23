from splat.segtypes.n64.segment import N64Segment
from splat.util import options
from pathlib import Path
import struct

class N64SegSnap_height_map_tree(N64Segment):
    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start : self.rom_end]
        self.file_text = self.disassemble_data(data)

    def disassemble_data(self, data):
        lines = []
        num_entries = len(data) // 28
        data = data[:28 * num_entries]
        for entry in struct.iter_unpack(">fffiiii", data):
            A, B, C, leftchild, rightchild, leftpatch, rightpatch = entry
            lines.append(f"{{ {A:12.6f}, {B:12.6f}, {C:12.6f}, (void*){leftchild:5}, (void*){rightchild:5}, (void*){leftpatch:5}, (void*){rightpatch:5} }},")
        return "\n".join(lines)

    def split(self, rom_bytes):
        self.out_path().parent.mkdir(parents=True, exist_ok=True)
        with open(self.out_path(), "w") as f:
            f.write(self.file_text)

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.hm.inc.c"
