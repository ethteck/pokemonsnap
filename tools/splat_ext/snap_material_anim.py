from splat.segtypes.segment import Segment
from pathlib import Path
from splat.util import options
from struct import unpack_from
import random, string

class N64SegSnap_material_anim(Segment):
    def cmd_get_param_number(self, cmd):
        if cmd in (7, 8, 9, 10, 11):
            return 1
        elif cmd in (0, 2, 12, 14, 16):
            return 0
        elif cmd in (5, 6):
            return 2
        raise ValueError(cmd)
    
    def cmd_get_param_name(self, index):
        return ("MAT_0", "MAT_1", "MAT_2", "MAT_3", "MAT_4", "MAT_5", "MAT_6", "MAT_7", "MAT_8", "MAT_9")[index]

    def cmd_require_pointer(self, cmd):
        return cmd in (14,)

    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start : self.rom_end]
        anim_name = self.get_symbol(self.vram_start, create=True)
        self.file_text = self.disassemble_data(data, anim_name, self.vram_start)

    def split_cmd(self, value):
        binStr = '{:032b}'.format(value)
        return int(binStr[:7], 2), int(binStr[7:17], 2), int(binStr[17:], 2)
    
    def get_random_name(self):
        return ''.join(random.choices(string.ascii_uppercase, k=10))

    def disassemble_data(self, data, name, vram):        
        part, offset = 0, 0
        while part == 0:
            part, offset = unpack_from(">I", data, offset)[0], offset + 4
        part = unpack_from(">I", data, part - vram)[0]

        header_length = part - vram
        part_vrams = unpack_from(f">{header_length // 4}I", data, 0)

        part_names = {}
        subpart_names = {}
        
        externs = ""
        lines = ""
        lines3 = ""

        lines += f"AnimCmd** {name}[] = {{\n"
        for i, part in enumerate(part_vrams):
            if part != 0:
                lines += f"    {name}_{i},\n"
                part_names[part] = f"{name}_{i}"
                externs += f"extern AnimCmd* {name}_{i}[];\n"
            else:
                lines += f"    NULL,\n"
        lines += "};\n\n"

        offset = min(part_names.keys()) - vram
        i = 0
        ended = False
        while True:
            try:
                if lines3 != "":
                    lines3 += "};\n\n"
                    ended = True
                base_name = part_names[offset + vram]
                lines3 += f"AnimCmd* {base_name}[] = {{\n"
                i = 0
            except KeyError:
                pass
            if offset >= len(data):
                break
            value, offset = unpack_from(">I", data, offset)[0], offset + 4
            if value == 0:
                break
            name = f"{base_name}_{i}"
            subpart_names[value] = name
            lines3 += f"    (AnimCmd*)&{name},\n"
            ended = False
            i += 1
        if not ended:
            lines3 += "};\n\n"

        cmd_ptr = header_length
        cmd_end_ptr = min(part_names.keys()) - vram
        firstLine = True
        while cmd_ptr < cmd_end_ptr:
            line_ptr = cmd_ptr
            value, cmd_ptr = unpack_from(">I", data, cmd_ptr)[0], cmd_ptr + 4
            cmd, mask, duration = self.split_cmd(value)
            
            numFloats = mask.bit_count()
            floats = []
            pointer = None
            for j in range(numFloats):
                value, cmd_ptr = unpack_from(">f", data, cmd_ptr)[0], cmd_ptr + 4
                floats.append(value)
            if self.cmd_require_pointer(cmd):
                value, cmd_ptr = unpack_from(">I", data, cmd_ptr)[0], cmd_ptr + 4
                pointer = value
            
            #print(cmd, mask, duration, pointer, floats)

            if firstLine:
                prevname = name = subpart_names[line_ptr + vram]
            else:
                name = self.get_random_name()

            if pointer is not None:
                if cmd == 14:
                    pass
                else:
                    lines += f"AnimLinePtr {name} = {{ "
                    if firstLine:
                        externs += f"static AnimLinePtr {name};\n"
            else:
                if cmd in (0, 2, 5, 6, 7, 8, 9, 10, 11, 12, 16):
                    pass
                else:
                    raise ValueError(cmd)

            if cmd == 2:
                if firstLine:
                    lines += f"asBegin_0({name})\n"
                    lines += f"    asWait_f({duration});\n"
                else:
                    lines += f"    asWait({duration});\n"
                firstLine = False
            elif cmd == 0:
                lines += f"asEnd();\n\n"
                firstLine = True
            elif cmd == 14:
                lines += f"asRestart({prevname});\n\n"
                firstLine = True
            elif cmd == 16:
                if prevname[-2:] == "_0":
                    lines += f"    asPlaySound({duration}, {mask >> 8}, {mask & 0xFF});\n"
                else:
                    lines += f"    asPlayEffect({duration}, {mask >> 8}, {(mask & 0xFF) - 1});\n"
                firstLine = False
            elif cmd in (5, 6):
                cmdNames = { 5: "asSetWithRateBlock", 6: "asSetWithRate"}
                if firstLine:
                    lines += f"asBegin_{len(floats)}({name})\n"
                    lines += f"    {cmdNames[cmd]}_{len(floats) // 2}f({duration}"
                else:
                    lines += f"    {cmdNames[cmd]}_{len(floats) // 2}({duration}"
                paramNames = []
                for i in range(10):
                    if mask & (1 << i):
                        paramNames.append(self.cmd_get_param_name(i))
                for j in range(len(paramNames)):
                    lines += f", {paramNames[j]}, {str(floats[2 * j])}, {str(floats[2 * j + 1])}"
                lines += ");\n"
                firstLine = False
            elif cmd in (7, 8, 9, 10, 11):
                cmdNames = { 7: "asSetTargetRate", 8: "asSetZeroRateBlock", 9: "asSetZeroRate", 10: "asSetAfterBlock", 11: "asSetAfter"}
                if firstLine:
                    lines += f"asBegin_{len(floats)}({name})\n"
                    lines += f"    {cmdNames[cmd]}_{len(floats)}f({duration}"
                else:
                    lines += f"    {cmdNames[cmd]}_{len(floats)}({duration}"
                paramNames = []
                for i in range(10):
                    if mask & (1 << i):
                        paramNames.append(self.cmd_get_param_name(i))
                for parName, parValue in zip(paramNames, floats):
                    lines += f", {parName}, {str(parValue)}"
                lines += ");\n"
                firstLine = False
            elif cmd == 12:
                lines += f"    asSkip_{mask.bit_count()}({duration}"
                paramNames = []
                for i in range(10):
                    if mask & (1 << i):
                        paramNames.append(self.cmd_get_param_name(i))
                for j in range(len(paramNames)):
                    lines += f", {paramNames[j]}"
                lines += ");\n"
                firstLine = False
            else:
                lines += f" (({cmd} << 25) | ({mask} << 15) | {duration})"

                if floats:
                    lines += ", { "
                    for f in floats:
                        lines += f"{str(f)}, "
                    lines += "}"
                elif pointer:
                    lines += f", {pointer:#x}"
            
                lines += " };\n"
                firstLine = False

        return "#include <anim_script.h>\n\n" + externs + "\n" + lines + lines3

    def split(self, rom_bytes):
        self.out_path().parent.mkdir(parents=True, exist_ok=True)
        with open(self.out_path(), "w") as f:
            f.write(self.file_text)

    def out_path(self) -> Path:
        return options.opts.asset_path / self.dir / f"{self.name}.matanim.inc.c"
