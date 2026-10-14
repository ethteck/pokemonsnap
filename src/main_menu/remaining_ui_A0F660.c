#include "common.h"
#include "ld_addrs.h"
#include "window/window.h"

#include "main_menu.h"

void func_800E4610_A0BBA0(Gfx**);
void func_800E4634_A0BBC4(void);

extern s8 D_800E80D0_A0F660;
extern ScreenSettings D_800E80FC_A0F68C;
extern Lights1 D_800E8118_A0F6A8;
extern Gfx D_800E8130_A0F6C0[11];
extern SceneSetup D_800E8188_A0F718;
extern u8 D_800E8214_A0F7A4[12];

/* Native storage in original address order, ordinary IDO .data. */

s8 D_800E80D0_A0F660 = 0;

PanData D_800E80D4_A0F664 = { { 0, 42, 84, 127 } };

YValues D_800E80E4_A0F674 = { {
    { 138, 162, 0, 0 },
    { 132, 150, 168, 0 },
    { 120, 138, 155, 174 },
} };

ScreenSettings D_800E80FC_A0F68C = {
    D_803B5000,
    D_803DA800,
    NULL,
    NULL,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0x16A99,
};

Lights1 D_800E8118_A0F6A8 = gdSPDefLights1(97, 97, 97, 207, 207, 207, 26, 77, 127);

Gfx D_800E8130_A0F6C0[11] = {
#include "build/assets/native/gfx/D_800E8130_A0F6C0.dl.inc.c"
};

SceneSetup D_800E8188_A0F718 = {
    {
        0,
        omUpdateAll,
        omDrawAll,
        main_menu_VRAM_END,
        0,
        1,
        2,
        20480,
        8192,
        0,
        0,
        51200,
        0,
        0,
        func_800E4610_A0BBA0,
        contUpdate,
    },
    32,
    1024,
    128,
    0,
    64,
    64,
    92,
    1024,
    NULL,
    NULL,
    16,
    8,
    16,
    136,
    128,
    88,
    8,
    144,
    func_800E4634_A0BBC4,
};

u8 D_800E8214_A0F7A4[12] = { 0 };
