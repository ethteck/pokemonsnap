import sys
from pathlib import Path
from splat.util import options
from struct import unpack_from

sys.path.insert(0, str(Path(__file__).parent))
from snap_anim_common import SnapAnimSegmentCommon

class N64SegSnap_model_anim(SnapAnimSegmentCommon):    
    def cmd_get_param_name(self, index):
        return ("ROTX", "ROTY", "ROTZ", "PATH_PARAM", "POSX", "POSY", "POSZ", "SCALEX", "SCALEY", "SCALEZ")[index]
    
    def get_header_length(self, data, vram_base):
        pointer, offset = 0, 0
        while pointer == 0:
            pointer, offset = unpack_from(">I", data, offset)[0], offset + 4
        if pointer - vram_base > 200:
            pointer = unpack_from(">I", data, pointer - 0x18 + 0x8 - vram_base)[0]
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
    
    def parse_path(self, name, data, offset, size, vram_base):
        self.pathnames[vram_base + offset + size - 0x18] = f"{name}_path"
        interp_offset = offset + size - 0x18
        interp_data = unpack_from(f">BBhfIfII", data, interp_offset)
        interp_data_text = f"InterpData {name}_path = {{\n"
        interp_data_text += f"    {('HAL_INTERP_LINEAR', 'HAL_INTERP_BEZIER_S3', 'HAL_INTERP_BEZIER', 'HAL_INTERP_CATROM')[interp_data[0]]},\n"
        interp_data_text += f"    {interp_data[2]},\n"
        interp_data_text += f"    {interp_data[3]},\n"
        interp_data_text += f"    {name}_path_points,\n"
        interp_data_text += f"    {interp_data[5]:.6f},\n"
        interp_data_text += f"    {name}_path_timestamps,\n"
        interp_data_text += f"    {name}_path_speed_data,\n"
        interp_data_text += f"}};\n"

        numPoints = interp_data[2]

        path_points = unpack_from(f">{3 * (numPoints + 2)}f", data, offset)
        path_points_text = f"Vec3f {name}_path_points[] = {{\n"
        for i in range(numPoints + 2):
            path_points_text += f"    {{ {path_points[i * 3]:.6f}, {path_points[i * 3 + 1]:.6f}, {path_points[i * 3 + 2]:.6f} }},\n"
        path_points_text += f"}};\n\n"

        timestamps = unpack_from(f">{numPoints}f", data, offset + 4 * (3 * (numPoints + 2)))
        timestamps_text = f"f32 {name}_path_timestamps[] = {{\n"
        for i in range(numPoints):
            timestamps_text += f"    {timestamps[i]:.6f},\n"
        timestamps_text += f"}};\n\n"

        speed_data = unpack_from(f">{5 * (numPoints - 1)}f", data, offset + 4 * (3 * (numPoints + 2)) + 4 * numPoints)
        speed_data_text = f"FittingParams {name}_path_speed_data[] = {{\n"
        for i in range(numPoints - 1):
            speed_data_text += f"    {{ {speed_data[i * 5]:.6f}, {speed_data[i * 5 + 1]:.6f}, {speed_data[i * 5 + 2]:.6f}, {speed_data[i * 5 + 3]:.6f}, {speed_data[i * 5 + 4]:.6f} }},\n"
        speed_data_text += f"}};\n\n"

        return path_points_text + timestamps_text + speed_data_text + interp_data_text

    def disassemble_data(self, data, name, vram_base):
        header_text, anim_array_names = self.parse_header(data, name, vram_base)
        externs = ""
        cmd_ptr = self.header_length
        self.pathnames = {}
        
        isFirstLine = True
        animcmd_text = ""
        parsed_array_count = 0
        while parsed_array_count < len(anim_array_names):
            if isFirstLine:
                # skip possible interp data 
                skipped = 0
                while True:
                    try:
                        animationName = anim_array_names[cmd_ptr + vram_base]
                        break
                    except KeyError:
                        cmd_ptr += 4
                        skipped += 4
            
                if skipped:
                    animcmd_text += self.parse_path(animationName, data, cmd_ptr - skipped, skipped, vram_base) + "\n"

            isFirstLine, cmd_ptr, animcmd_text, forward_decl = self.parse_line(data, animationName, cmd_ptr, isFirstLine, animcmd_text)
            externs += forward_decl

            if isFirstLine:
                parsed_array_count += 1
                animcmd_text += "\n"

        return f"#undef __ANIMFILE\n#define __ANIMFILE {name}\n\n" + "#include <anim_script.h>\n\n" + externs + "\n" + header_text + animcmd_text

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.modelanim.inc.c"
