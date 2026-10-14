#include "common.h"
#include "ld_addrs.h"
#include "window/window.h"

void func_801DCCDC_AA1D1C(void);

extern u8 D_801DD060_AA20A0[8];
extern u8 D_801DD068_AA20A8[4080];
extern u8 D_801DE058_AA3098[8];
extern u8 D_801DE060_AA30A0[4080];
extern u8 D_801DF050_AA4090[8];
extern u8 D_801DF058_AA4098[4080];
extern u8 D_801E0048_AA5088[8];
extern u8 D_801E0050_AA5090[4080];
extern u8 D_801E1040_AA6080[8];
extern u8 D_801E1048_AA6088[4080];
extern u8 D_801E2038_AA7078[8];
extern u8 D_801E2040_AA7080[4080];
extern u8 D_801E3030_AA8070[8];
extern u8 D_801E3038_AA8078[4080];
extern u8 D_801E4028_AA9068[8];
extern u8 D_801E4030_AA9070[4080];
extern u8 D_801E5020_AAA060[8];
extern u8 D_801E5028_AAA068[960];
extern Bitmap D_801E53E8_AAA428[9];
extern Sprite D_801E5478_AAA4B8;
extern u8 D_801E54BC_AAA4FC;
extern u8 D_801E54C0_AAA500;
extern u8 D_801E54C4_AAA504;
extern s32 D_801E54C8_AAA508[17];
extern s32 D_801E550C_AAA54C;
extern ScreenSettings D_801E5510_AAA550;
extern SceneSetup D_801E552C_AAA56C;
extern u8 D_801E55B8_AAA5F8[8];
extern f32 D_801E55C0_AAA600;
extern u8 D_801E55C4_AAA604[12];
extern u16 D_806D4000[640 * 480];
extern u16 D_8076A000[640 * 480];
extern u8 D_80400000[];

/* Native storage in original address order, ordinary IDO .data. */

u8 D_801DD060_AA20A0[8] = { 0 };

u8 D_801DD068_AA20A8[4080] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801DD068.ia16.inc.c"
};

u8 D_801DE058_AA3098[8] = { 0 };

u8 D_801DE060_AA30A0[4080] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801DE060.ia16.inc.c"
};

u8 D_801DF050_AA4090[8] = { 0 };

u8 D_801DF058_AA4098[4080] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801DF058.ia16.inc.c"
};

u8 D_801E0048_AA5088[8] = { 0 };

u8 D_801E0050_AA5090[4080] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801E0050.ia16.inc.c"
};

u8 D_801E1040_AA6080[8] = { 0 };

u8 D_801E1048_AA6088[4080] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801E1048.ia16.inc.c"
};

u8 D_801E2038_AA7078[8] = { 0 };

u8 D_801E2040_AA7080[4080] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801E2040.ia16.inc.c"
};

u8 D_801E3030_AA8070[8] = { 0 };

u8 D_801E3038_AA8078[4080] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801E3038.ia16.inc.c"
};

u8 D_801E4028_AA9068[8] = { 0 };

u8 D_801E4030_AA9070[4080] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801E4030.ia16.inc.c"
};

u8 D_801E5020_AAA060[8] = { 0 };

u8 D_801E5028_AAA068[960] = {
#include "build/assets/remaining_ui_print/remaining_ui_AA20A0/801E5028.ia16.inc.c"
};

Bitmap D_801E53E8_AAA428[9] = {
    { 68, 68, 0, 0, D_801DD068_AA20A8, 30, 0 },
    { 68, 68, 0, 0, D_801DE060_AA30A0, 30, 0 },
    { 68, 68, 0, 0, D_801DF058_AA4098, 30, 0 },
    { 68, 68, 0, 0, D_801E0050_AA5090, 30, 0 },
    { 68, 68, 0, 0, D_801E1048_AA6088, 30, 0 },
    { 68, 68, 0, 0, D_801E2040_AA7080, 30, 0 },
    { 68, 68, 0, 0, D_801E3038_AA8078, 30, 0 },
    { 68, 68, 0, 0, D_801E4030_AA9070, 30, 0 },
    { 13, 16, 0, 0, D_801E5028_AAA068, 30, 0 },
};

Sprite D_801E5478_AAA4B8 = {
    41,
    445,
    557,
    30,
    1.0f,
    1.0f,
    0,
    0,
    512,
    4660,
    0,
    0,
    0,
    255,
    0,
    0,
    NULL,
    0,
    1,
    9,
    132,
    30,
    30,
    3,
    2,
    D_801E53E8_AAA428,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801E54BC_AAA4FC = 5;

u8 D_801E54C0_AAA500 = 9;

u8 D_801E54C4_AAA504 = 3;

s32 D_801E54C8_AAA508[17] = { -1, 0, 0, 1, 1, 0, 0, 1, 1, 2, 2, 3, 3, 2, 2, 3, 3 };

s32 D_801E550C_AAA54C = 0;

ScreenSettings D_801E5510_AAA550 = {
    D_806D4000,
    D_8076A000,
    NULL,
    NULL,
    640,
    480,
    0x695,
};

SceneSetup D_801E552C_AAA56C = {
    {
        0,
        omUpdateAll,
        omDrawAll,
        D_80400000,
        0,
        1,
        2,
        51200,
        51200,
        1024,
        0,
        102400,
        2,
        16384,
        func_800A1A50,
        contUpdate,
    },
    0,
    1280,
    0,
    0,
    0,
    0,
    92,
    0,
    NULL,
    NULL,
    0,
    0,
    0,
    136,
    0,
    88,
    0,
    144,
    func_801DCCDC_AA1D1C,
};

u8 D_801E55B8_AAA5F8[8] = { 0 };

f32 D_801E55C0_AAA600 = 1.39068115f;

u8 D_801E55C4_AAA604[12] = { 0 };
