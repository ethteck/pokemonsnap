#include "common.h"
#include "window.h"

/* Physical ROM order, compiled into one ordinary IDO .data section. */
extern u8 D_80375410_848BC0[11840];
extern u32 D_80378250_84BA00;
extern u8 D_80378254_84BA04[26640];
extern u32 D_8037EA64_852214;
extern u8* D_8037EA68_852218[2];

u8 D_80375410_848BC0[11840] = {
#include "build/assets/window/font8.png.bin.c"
};

u32 D_80378250_84BA00 = 0;

u8 D_80378254_84BA04[26640] = {
#include "build/assets/window/font12.png.bin.c"
};

u32 D_8037EA64_852214 = 0;

u8* D_8037EA68_852218[2] = { D_80375410_848BC0, D_80378254_84BA04 };
