from splat.segtypes.segment import Segment
from struct import unpack_from
from typing import Tuple

class SnapAnimSegmentCommon(Segment):
    def scan(self, rom_bytes):
        data = rom_bytes[self.rom_start : self.rom_end]
        anim_name = self.get_symbol(self.vram_start, create=True)
        self.file_text = self.disassemble_data(data, anim_name, self.vram_start)

    def split(self, rom_bytes):
        self.out_path().parent.mkdir(parents=True, exist_ok=True)
        with open(self.out_path(), "w") as f:
            f.write(self.file_text)

    def cmd_get_param_count(self, cmd):
        if cmd in (7, 8, 9, 10, 11):
            return 1
        elif cmd in (0, 2, 12, 14, 16):
            return 0
        elif cmd in (5, 6):
            return 2
        raise ValueError(cmd)
    
    def cmd_require_pointer(self, cmd):
        return cmd in (14,)

    def cmd_split(self, value):
        binStr = '{:032b}'.format(value)
        return int(binStr[:7], 2), int(binStr[7:17], 2), int(binStr[17:], 2)
    
    CMD_NAMES = {
        0: "asEnd",
        2: "asWait",
        5: "asSetWithRateBlock",
        6: "asSetWithRate",
        7: "asSetTargetRate",
        8: "asSetZeroRateBlock",
        9: "asSetZeroRate",
        10: "asSetAfterBlock",
        11: "asSetAfter",
        12: "asSkip",
        14: "asRestart",
        16: ("asPlaySound", "asPlayEffect")
    }

    def parse_line(self, data, name, offset, isFirstLine, text) -> Tuple[bool, int, str, str]:
        value, offset = unpack_from(">I", data, offset)[0], offset + 4
        cmd, mask, duration = self.cmd_split(value)
        
        numParams = mask.bit_count()
        floatsPerParam = self.cmd_get_param_count(cmd)
        floats = []
        if cmd != 12:            
            for j in range(numParams * floatsPerParam):
                value, offset = unpack_from(">f", data, offset)[0], offset + 4
                floats.append(value)
        if self.cmd_require_pointer(cmd):
            value, offset = unpack_from(">I", data, offset)[0], offset + 4

        try:
            cmdName = self.CMD_NAMES[cmd]
            if cmd == 16:
                if "_root" in name:
                    cmdName = cmdName[0]
                else:
                    cmdName = cmdName[1]
        except KeyError:
            raise ValueError(f"Unknown animation command {cmd}")
        
        firstLineText = ""
        forwardDecl = ""
        if isFirstLine:
            firstLineText = f"asBegin_{numParams * floatsPerParam}({name})\n"
            forwardDecl = f"static AnimLine{numParams * floatsPerParam} {name};\n"
        
        lineText = ""

        if cmd not in (0, 14):
            lineText += "    "

        lineText += cmdName

        if cmd not in (0, 2, 14, 16):
            if cmd == 12:
                lineText += f"_{numParams}"
            else:    
                lineText += f"_{numParams * floatsPerParam}"

        if isFirstLine:
            lineText += "f"
        
        lineText += "("

        if cmd == 0:
            pass
        elif cmd == 14:
            lineText += f"{name}"
        elif cmd == 16:
            if "_root" in name:
                lineText += f"{duration}, {mask >> 8}, {mask & 0xFF}"
            else:
                lineText += f"{duration}, {mask >> 8}, {(mask - 1) & 0xFF}"
        else:
            lineText += f"{duration}"

            paramNames = [self.cmd_get_param_name(i) for i in range(10) if (mask & (1 << i))]
            floatsPerParam = self.cmd_get_param_count(cmd)
            for i in range(numParams):
                lineText += f", {paramNames[i]}"
                for j in range(floatsPerParam):
                    lineText += f", {floats[i * floatsPerParam + j]}"
            
        lineText += ");\n"

        text += firstLineText + lineText

        isLastLine = (cmd in (0, 14))
        return isLastLine, offset, text, forwardDecl
