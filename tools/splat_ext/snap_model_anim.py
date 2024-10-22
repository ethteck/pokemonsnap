import sys
from pathlib import Path
from splat.util import options
from struct import unpack_from

sys.path.insert(0, str(Path(__file__).parent))
from snap_anim_common import SnapAnimSegmentCommon

class N64SegSnap_model_anim(SnapAnimSegmentCommon):    
    def cmd_get_param_name(self, index):
        return ("ROTX", "ROTY", "ROTZ", "PARAM4", "POSX", "POSY", "POSZ", "SCALEX", "SCALEY", "SCALEZ")[index]
    
    def get_header_length(self, data, vram_base):
        pointer, offset = 0, 0
        while pointer == 0:
            pointer, offset = unpack_from(">I", data, offset)[0], offset + 4
        return pointer - vram_base
    
    def parse_header(self, data, name, vram_base):
        self.header_length = self.get_header_length(data, vram_base)
        anim_arrays = unpack_from(f">{self.header_length // 4}I", data, 0)

        header_text = ""
        anim_array_names = {}

        header_text += f"AnimCmd* {name}[] = {{\n"
        for i, addr in enumerate(anim_arrays):
            if addr == 0:
                header_text += f"    NULL,\n"
            else:
                if i == 0:
                    array_name = f"{name}_root"
                else:
                    array_name = f"{name}_{i - 1}"

                header_text += f"    (AnimCmd*)&{array_name},\n"
                anim_array_names[addr] = array_name
        header_text += "};\n\n"

        return header_text, anim_array_names

    def disassemble_data(self, data, name, vram_base):
        header_text, anim_array_names = self.parse_header(data, name, vram_base)
        externs = ""
        cmd_ptr = self.header_length
        
        isFirstLine = True
        animcmd_text = ""
        parsed_array_count = 0
        while parsed_array_count < len(anim_array_names):
            if isFirstLine:
                animationName = anim_array_names[cmd_ptr + vram_base]

            isFirstLine, cmd_ptr, animcmd_text, forward_decl = self.parse_line(data, animationName, cmd_ptr, isFirstLine, animcmd_text)
            externs += forward_decl

            if isFirstLine:
                parsed_array_count += 1
                animcmd_text += "\n"

        return "#include <anim_script.h>\n\n" + externs + "\n" + header_text + animcmd_text

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.modelanim.inc.c"
