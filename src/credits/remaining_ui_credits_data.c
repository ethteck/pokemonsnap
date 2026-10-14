#include "common.h"
#include "credits.h"

void func_credits_801DC9FC(void*);
void func_credits_801DC8C4(void);

/* Native credits graph; shared images and repeated Bitmap pointers retain identity. */
extern ScreenSettings D_credits_801DEBA0;
extern u32 D_credits_801DEBBC[1];
extern Ambient D_credits_801DEBC0;
extern Light D_credits_801DEBC8;
extern Gfx D_credits_801DEBD8[11];
extern SceneSetup D_credits_801DEC30;
extern u32 D_credits_801DECBC[3];
extern u8 D_credits_801DECC8[3920];
extern u32 D_credits_801DFC18[2];
extern u8 D_credits_801DFC20[3920];
extern u32 D_credits_801E0B70[2];
extern u8 D_credits_801E0B78[3920];
extern u32 D_credits_801E1AC8[2];
extern u8 D_credits_801E1AD0[3920];
extern u32 D_credits_801E2A20[2];
extern u8 D_credits_801E2A28[3920];
extern u32 D_credits_801E3978[2];
extern u8 D_credits_801E3980[3920];
extern u32 D_credits_801E48D0[2];
extern u8 D_credits_801E48D8[3920];
extern u32 D_credits_801E5828[2];
extern u8 D_credits_801E5830[1960];
extern Bitmap D_credits_801E5FD8[8];
extern Sprite D_credits_801E6058;
extern u32 D_credits_801E609C[3];
extern u8 D_credits_801E60A8[888];
extern Bitmap D_credits_801E6420[1];
extern Sprite D_credits_801E6430;
extern u32 D_credits_801E6474[3];
extern u8 D_credits_801E6480[840];
extern Bitmap D_credits_801E67C8[1];
extern Sprite D_credits_801E67D8;
extern u32 D_credits_801E681C[3];
extern u8 D_credits_801E6828[320];
extern Bitmap D_credits_801E6968[20];
extern Sprite D_credits_801E6AA8;
extern u32 D_credits_801E6AEC[3];
extern u8 D_credits_801E6AF8[2048];
extern u32 D_credits_801E72F8[2];
extern u8 D_credits_801E7300[2048];
extern u32 D_credits_801E7B00[2];
extern u8 D_credits_801E7B08[2048];
extern u32 D_credits_801E8308[2];
extern u8 D_credits_801E8310[2048];
extern Bitmap D_credits_801E8B10[4];
extern Sprite D_credits_801E8B50;
extern u32 D_credits_801E8B94[3];

/* Complete original ROM order in one ordinary IDO .data section. */
ScreenSettings D_credits_801DEBA0 = {
    D_803B5000,
    D_803DA800,
    NULL,
    NULL,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0x16A99,
};

u32 D_credits_801DEBBC[1] = { 0 };

Ambient D_credits_801DEBC0 = {
    { { 100, 100, 100 }, 0, { 100, 100, 100 }, 0 },
};

Light D_credits_801DEBC8 = {
    { { 180, 180, 180 }, 0, { 180, 180, 180 }, 0, { 30, 30, 30 }, 0 },
};

Gfx D_credits_801DEBD8[11] = {
#include "build/assets/native/gfx/D_credits_801DEBD8.dl.inc.c"
};

SceneSetup D_credits_801DEC30 = {
    {
        0,
        omUpdateAll,
        omDrawAll,
        D_801ED020,
        0,
        1,
        1,
        32768,
        8192,
        0,
        0,
        6144,
        0,
        0,
        func_800A1A50,
        contUpdate,
    },
    8,
    10240,
    32,
    0,
    8,
    16,
    92,
    512,
    NULL,
    func_credits_801DC9FC,
    0,
    0,
    0,
    136,
    96,
    88,
    2,
    144,
    func_credits_801DC8C4,
};

u32 D_credits_801DECBC[3] = { 0 };

u8 D_credits_801DECC8[3920] = {
#include "assets/credits/remaining_ui_credits_801DECC8.png.bin.c"
};

u32 D_credits_801DFC18[2] = { 0 };

u8 D_credits_801DFC20[3920] = {
#include "assets/credits/remaining_ui_credits_801DFC20.png.bin.c"
};

u32 D_credits_801E0B70[2] = { 0 };

u8 D_credits_801E0B78[3920] = {
#include "assets/credits/remaining_ui_credits_801E0B78.png.bin.c"
};

u32 D_credits_801E1AC8[2] = { 0 };

u8 D_credits_801E1AD0[3920] = {
#include "assets/credits/remaining_ui_credits_801E1AD0.png.bin.c"
};

u32 D_credits_801E2A20[2] = { 0 };

u8 D_credits_801E2A28[3920] = {
#include "assets/credits/remaining_ui_credits_801E2A28.png.bin.c"
};

u32 D_credits_801E3978[2] = { 0 };

u8 D_credits_801E3980[3920] = {
#include "assets/credits/remaining_ui_credits_801E3980.png.bin.c"
};

u32 D_credits_801E48D0[2] = { 0 };

u8 D_credits_801E48D8[3920] = {
#include "assets/credits/remaining_ui_credits_801E48D8.png.bin.c"
};

u32 D_credits_801E5828[2] = { 0 };

u8 D_credits_801E5830[1960] = {
#include "assets/credits/remaining_ui_credits_801E5830.png.bin.c"
};

Bitmap D_credits_801E5FD8[8] = {
    { 140, 140, 0, 0, D_credits_801DECC8, 14, 0 },
    { 140, 140, 0, 0, D_credits_801DFC20, 14, 0 },
    { 140, 140, 0, 0, D_credits_801E0B78, 14, 0 },
    { 140, 140, 0, 0, D_credits_801E1AD0, 14, 0 },
    { 140, 140, 0, 0, D_credits_801E2A28, 14, 0 },
    { 140, 140, 0, 0, D_credits_801E3980, 14, 0 },
    { 140, 140, 0, 0, D_credits_801E48D8, 14, 0 },
    { 140, 140, 0, 0, D_credits_801E5830, 7, 0 },
};

Sprite D_credits_801E6058 = {
    0,
    0,
    140,
    105,
    1.0f,
    1.0f,
    0,
    0,
    SP_TEXSHUF,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    8,
    120,
    14,
    14,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_credits_801E5FD8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_credits_801E609C[3] = { 0 };

u8 D_credits_801E60A8[888] = {
#include "assets/credits/remaining_ui_credits_801E60A8.png.bin.c"
};

Bitmap D_credits_801E6420[1] = {
    { 3, 4, 0, 0, D_credits_801E60A8, 111, 0 },
};

Sprite D_credits_801E6430 = {
    0,
    0,
    3,
    111,
    1.0f,
    1.0f,
    0,
    0,
    SP_TEXSHUF,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    111,
    111,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_credits_801E6420,
    NULL,
    NULL,
    0,
    0,
};

u32 D_credits_801E6474[3] = { 0 };

u8 D_credits_801E6480[840] = {
#include "assets/credits/remaining_ui_credits_801E6480.png.bin.c"
};

Bitmap D_credits_801E67C8[1] = {
    { 140, 140, 0, 0, D_credits_801E6480, 3, 0 },
};

Sprite D_credits_801E67D8 = {
    0,
    0,
    140,
    3,
    1.0f,
    1.0f,
    0,
    0,
    SP_TEXSHUF,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    1,
    36,
    3,
    3,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_credits_801E67C8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_credits_801E681C[3] = { 0 };

u8 D_credits_801E6828[320] = {
#include "assets/credits/remaining_ui_credits_801E6828.png.bin.c"
};

Bitmap D_credits_801E6968[20] = {
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
    { 16, 16, 0, 0, D_credits_801E6828, 10, 0 },
};

Sprite D_credits_801E6AA8 = {
    0,
    0,
    16,
    10,
    1.0f,
    1.0f,
    0,
    0,
    SP_TEXSHUF,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    20,
    264,
    10,
    10,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_credits_801E6968,
    NULL,
    NULL,
    0,
    0,
};

u32 D_credits_801E6AEC[3] = { 0 };

u8 D_credits_801E6AF8[2048] = {
#include "assets/credits/remaining_ui_credits_801E6AF8.png.bin.c"
};

u32 D_credits_801E72F8[2] = { 0 };

u8 D_credits_801E7300[2048] = {
#include "assets/credits/remaining_ui_credits_801E7300.png.bin.c"
};

u32 D_credits_801E7B00[2] = { 0 };

u8 D_credits_801E7B08[2048] = {
#include "assets/credits/remaining_ui_credits_801E7B08.png.bin.c"
};

u32 D_credits_801E8308[2] = { 0 };

u8 D_credits_801E8310[2048] = {
#include "assets/credits/remaining_ui_credits_801E8310.png.bin.c"
};

Bitmap D_credits_801E8B10[4] = {
    { 32, 32, 0, 0, D_credits_801E6AF8, 32, 0 },
    { 32, 32, 0, 0, D_credits_801E7300, 32, 0 },
    { 32, 32, 0, 0, D_credits_801E7B08, 32, 0 },
    { 32, 32, 0, 0, D_credits_801E8310, 32, 0 },
};

Sprite D_credits_801E8B50 = {
    0,
    0,
    128,
    32,
    1.0f,
    1.0f,
    0,
    0,
    SP_TEXSHUF,
    4660,
    255,
    255,
    255,
    255,
    0,
    0,
    NULL,
    0,
    1,
    4,
    72,
    32,
    32,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    D_credits_801E8B10,
    NULL,
    NULL,
    0,
    0,
};

u32 D_credits_801E8B94[3] = { 0 };
