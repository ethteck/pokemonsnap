.include "macro.inc"

.section .text, "ax"

nonmatching aspMainTextStart, 0xE20

glabel aspMainTextStart
.incbin "assets/rsp/aspMain.textbin.bin"
endlabel aspMainTextStart
glabel aspMainTextEnd
endlabel aspMainTextEnd

.section .data, "wa"

nonmatching aspMainDataStart, 0x2C0

dlabel aspMainDataStart
.incbin "assets/rsp/aspMain.databin.bin"
enddlabel aspMainDataStart
dlabel aspMainDataEnd
enddlabel aspMainDataEnd
