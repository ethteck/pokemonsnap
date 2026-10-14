.include "macro.inc"

.section .text, "ax"

glabel gspF3DEX2_NoN_fifoTextStart
.incbin "assets/rsp/gspF3DEX2H.NoN.fifo.textbin.bin"
endlabel gspF3DEX2_NoN_fifoTextStart
glabel gspF3DEX2_NoN_fifoTextEnd
endlabel gspF3DEX2_NoN_fifoTextEnd

.section .data, "wa"

dlabel gspF3DEX2_NoN_fifoDataStart
.incbin "assets/rsp/gspF3DEX2H.NoN.fifo.databin.bin"
enddlabel gspF3DEX2_NoN_fifoDataStart
dlabel gspF3DEX2_NoN_fifoDataEnd
enddlabel gspF3DEX2_NoN_fifoDataEnd
