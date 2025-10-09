#include "common.h"

u8 font_8x8[141][8 * 8 / 2] = {
    0
    // #include "assets/window/font_8x8.png.bin.c"
};

u32 aligner = 0;
u8 font_12x12[141][12 * 12 / 2] = {
    0
    // #include "assets/window/font_12x12.png.bin.c"
};

u32 aligner2 = 0;
u8* D_8037EA68_852218[] = {
    font_8x8,
    font_12x12,
};
