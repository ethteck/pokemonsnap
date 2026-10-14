.include "macro.inc"

.section .text, "ax"

glabel gspL3DEX2_fifoTextStart
.incbin "assets/rsp/gspL3DEX2H.fifo.textbin.bin"
endlabel gspL3DEX2_fifoTextStart
glabel gspL3DEX2_fifoTextEnd
endlabel gspL3DEX2_fifoTextEnd

.section .data, "wa"

dlabel gspL3DEX2_fifoDataStart
.incbin "assets/rsp/gspL3DEX2H.fifo.databin.bin"
enddlabel gspL3DEX2_fifoDataStart
dlabel gspL3DEX2_fifoDataEnd
enddlabel gspL3DEX2_fifoDataEnd
