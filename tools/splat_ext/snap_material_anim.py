import sys
from pathlib import Path
from splat.util import options
from struct import unpack_from

sys.path.insert(0, str(Path(__file__).parent))
from snap_anim_common import SnapAnimSegmentCommon

class N64SegSnap_material_anim(SnapAnimSegmentCommon):    
    def cmd_get_param_name(self, index):
        return ("IMG_INDEX", "OFFSET_S", "OFFSET_T", "SCALE_S", "SCALE_T", "MAT_PARAM_5", "MAT_PARAM_6", "MAT_PARAM_7", "MAT_PARAM_8", "MAT_PARAM_9")[index]
    
    def cmd_get_extra_param_name(self, index):
        return ("PRIM_COLOR", "ENV_COLOR", "BLEND_COLOR", "LIGHT_COLOR_1", "LIGHT_COLOR_2")[index]

    def get_header_length(self, data, vram_base):
        pointer, offset = 0, 0
        while pointer == 0:
            pointer, offset = unpack_from(">I", data, offset)[0], offset + 4
        pointer = unpack_from(">I", data, pointer - vram_base)[0]
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
    
    def parse_anim_lists(self, data, vram_base):
        offset = min(self.anim_array_names.keys()) - vram_base
        i = 0
        ended = False
        anim_names = {}
        lists_text = ""
        externs = ""

        while True:
            try:
                base_name = self.anim_array_names[offset + vram_base]
                if lists_text != "":
                    lists_text += "};\n\n"
                    ended = True
                lists_text += f"AnimCmd* {base_name}[] = {{\n"
                externs += f"extern AnimCmd* {base_name}[];\n"
                i = 0
            except KeyError:
                pass
            if offset >= len(data):
                break
            value, offset = unpack_from(">I", data, offset)[0], offset + 4
            if value == 0:
                break

            anim_name = f"{base_name}_{i}"
            anim_names[value] = anim_name
            lists_text += f"    (AnimCmd*)&{anim_name},\n"
            ended = False
            i += 1
        if not ended:
            lists_text += "};\n\n"
        
        return lists_text, anim_names, externs

    def disassemble_data(self, data, name, vram_base):        
        header_text, self.anim_array_names = self.parse_header(data, name, vram_base)
        lists_text, self.anim_names, externs = self.parse_anim_lists(data, vram_base)
        
        animcmd_text = ""      

        cmd_ptr = self.header_length
        cmd_end_ptr = min(self.anim_array_names.keys()) - vram_base
        isFirstLine = True
        while cmd_ptr < cmd_end_ptr:
            if isFirstLine:
                animationName = self.anim_names[cmd_ptr + vram_base]

            isFirstLine, cmd_ptr, animcmd_text, _ = self.parse_line(data, animationName, cmd_ptr, isFirstLine, animcmd_text)

            if isFirstLine:
                animcmd_text += "\n"

        return f"#undef __ANIMFILE\n#define __ANIMFILE {name}\n\n" + "#include <anim_script.h>\n\n" + externs + "\n" + header_text + animcmd_text + lists_text

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.matanim.inc.c"
