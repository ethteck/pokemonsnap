.include "macro.inc"

.section .text, "ax"

nonmatching gspL3DEX2_fifoTextStart, 0x1190

glabel gspL3DEX2_fifoTextStart
.incbin "assets/rsp/gspL3DEX2H.fifo.textbin.bin"
endlabel gspL3DEX2_fifoTextStart
glabel gspL3DEX2_fifoTextEnd
endlabel gspL3DEX2_fifoTextEnd

.section .data, "wa"

nonmatching gspL3DEX2_fifoDataStart, 0x3F0

dlabel gspL3DEX2_fifoDataStart
.incbin "assets/rsp/gspL3DEX2H.fifo.databin.bin"
enddlabel gspL3DEX2_fifoDataStart
dlabel gspL3DEX2_fifoDataEnd
enddlabel gspL3DEX2_fifoDataEnd
