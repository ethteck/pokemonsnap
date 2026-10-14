.include "macro.inc"

.section .text, "ax"

nonmatching rspbootTextStart, 0xD0

glabel rspbootTextStart
.incbin "assets/rsp/rspboot.textbin.bin"
endlabel rspbootTextStart
glabel rspbootTextEnd
endlabel rspbootTextEnd
