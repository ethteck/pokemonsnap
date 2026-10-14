.include "macro.inc"

.section .text, "ax"

glabel aspMainTextStart
.incbin "assets/rsp/aspMain.textbin.bin"
endlabel aspMainTextStart
glabel aspMainTextEnd
endlabel aspMainTextEnd

.section .data, "wa"

dlabel aspMainDataStart
.incbin "assets/rsp/aspMain.databin.bin"
enddlabel aspMainDataStart
dlabel aspMainDataEnd
enddlabel aspMainDataEnd
