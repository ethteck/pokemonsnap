#include "common.h"
#include "ld_addrs.h"

/* Native graph declarations; shared image/Bitmap identities remain shared. */
extern Gfx D_801E53A0_994E10[14];
extern ScreenSettings D_801E5410_994E80;
extern SceneSetup D_801E542C_994E9C;
extern u32 D_801E54B8_994F28[4];
extern u8 D_801E54C8_994F38[888];
extern Bitmap D_801E5840_9952B0[1];
extern Sprite D_801E5850_9952C0;
extern u32 D_801E5894_995304[3];
extern u8 D_801E58A0_995310[840];
extern Bitmap D_801E5BE8_995658[1];
extern Sprite D_801E5BF8_995668;
extern u32 D_801E5C3C_9956AC[3];
extern u8 D_801E5C48_9956B8[344];
extern Bitmap D_801E5DA0_995810[1];
extern Sprite D_801E5DB0_995820;
extern u32 D_801E5DF4_995864[3];
extern u8 D_801E5E00_995870[208];
extern Bitmap D_801E5ED0_995940[1];
extern Sprite D_801E5EE0_995950;
extern u32 D_801E5F24_995994[3];
extern u8 D_801E5F30_9959A0[3744];
extern u32 D_801E6DD0_996840[2];
extern u8 D_801E6DD8_996848[3744];
extern u32 D_801E7C78_9976E8[2];
extern u8 D_801E7C80_9976F0[3744];
extern u32 D_801E8B20_998590[2];
extern u8 D_801E8B28_998598[3744];
extern u32 D_801E99C8_999438[2];
extern u8 D_801E99D0_999440[3744];
extern u32 D_801EA870_99A2E0[2];
extern u8 D_801EA878_99A2E8[3744];
extern u32 D_801EB718_99B188[2];
extern u8 D_801EB720_99B190[3744];
extern u32 D_801EC5C0_99C030[2];
extern u8 D_801EC5C8_99C038[3744];
extern u32 D_801ED468_99CED8[2];
extern u8 D_801ED470_99CEE0[3744];
extern u32 D_801EE310_99DD80[2];
extern u8 D_801EE318_99DD88[3744];
extern u32 D_801EF1B8_99EC28[2];
extern u8 D_801EF1C0_99EC30[3744];
extern u32 D_801F0060_99FAD0[2];
extern u8 D_801F0068_99FAD8[3744];
extern u32 D_801F0F08_9A0978[2];
extern u8 D_801F0F10_9A0980[3744];
extern u32 D_801F1DB0_9A1820[2];
extern u8 D_801F1DB8_9A1828[1248];
extern Bitmap D_801F2298_9A1D08[14];
extern Sprite D_801F2378_9A1DE8;
extern u32 D_801F23BC_9A1E2C[3];
extern u8 D_801F23C8_9A1E38[728];
extern Bitmap D_801F26A0_9A2110[1];
extern Sprite D_801F26B0_9A2120;
extern u32 D_801F26F4_9A2164[3];
extern u8 D_801F2700_9A2170[512];
extern Bitmap D_801F2900_9A2370[1];
extern Sprite D_801F2910_9A2380;
extern u32 D_801F2954_9A23C4[3];
extern u8 D_801F2960_9A23D0[128];
extern Bitmap D_801F29E0_9A2450[1];
extern Sprite D_801F29F0_9A2460;
extern u32 D_801F2A34_9A24A4[3];
extern u8 D_801F2A40_9A24B0[128];
extern Bitmap D_801F2AC0_9A2530[1];
extern Sprite D_801F2AD0_9A2540;
extern u32 D_801F2B14_9A2584[1];
extern Gfx D_801F2B18_9A2588[1];
extern u32 D_801F2B20_9A2590[2];
extern u8 D_801F2B28_9A2598[4056];
extern Bitmap D_801F3B00_9A3570[1];
extern Sprite D_801F3B10_9A3580;

/* Original address order in one ordinary IDO .data section. */
Gfx D_801E53A0_994E10[14] = {
#include "build/assets/native/gfx/D_801E53A0_994E10.dl.inc.c"
};

ScreenSettings D_801E5410_994E80 = {
    D_803B5000,
    D_803DA800,
    NULL,
    NULL,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0x16A99,
};

SceneSetup D_801E542C_994E9C = {
    {
        0,
        omUpdateAll,
        omDrawAll,
        photo_check_VRAM_END,
        0,
        1,
        1,
        49152,
        8192,
        0,
        0,
        12288,
        2,
        12288,
        func_800A1A50,
        contUpdate,
    },
    32,
    8192,
    32,
    0,
    64,
    0,
    92,
    1024,
    NULL,
    NULL,
    0,
    16,
    0,
    136,
    0,
    96,
    0,
    144,
    func_801DCBF4_98C664,
};

u32 D_801E54B8_994F28[4] = { 0 };

u8 D_801E54C8_994F38[888] = {
#include "assets/photo_check/801E54C8.png.bin.c"
};

Bitmap D_801E5840_9952B0[1] = {
    { 3, 4, 0, 0, D_801E54C8_994F38, 111, 0 },
};

Sprite D_801E5850_9952C0 = {
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
    D_801E5840_9952B0,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E5894_995304[3] = { 0 };

u8 D_801E58A0_995310[840] = {
#include "assets/photo_check/801E58A0.png.bin.c"
};

Bitmap D_801E5BE8_995658[1] = {
    { 140, 140, 0, 0, D_801E58A0_995310, 3, 0 },
};

Sprite D_801E5BF8_995668 = {
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
    D_801E5BE8_995658,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E5C3C_9956AC[3] = { 0 };

u8 D_801E5C48_9956B8[344] = {
#include "assets/photo_check/801E5C48.png.bin.c"
};

Bitmap D_801E5DA0_995810[1] = {
    { 2, 4, 0, 0, D_801E5C48_9956B8, 43, 0 },
};

Sprite D_801E5DB0_995820 = {
    0,
    0,
    2,
    43,
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
    43,
    43,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801E5DA0_995810,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E5DF4_995864[3] = { 0 };

u8 D_801E5E00_995870[208] = {
#include "assets/photo_check/801E5E00.png.bin.c"
};

Bitmap D_801E5ED0_995940[1] = {
    { 52, 52, 0, 0, D_801E5E00_995870, 2, 0 },
};

Sprite D_801E5EE0_995950 = {
    0,
    0,
    52,
    2,
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
    2,
    2,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801E5ED0_995940,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E5F24_995994[3] = { 0 };

u8 D_801E5F30_9959A0[3744] = {
#include "assets/photo_check/801E5F30.png.bin.c"
};

u32 D_801E6DD0_996840[2] = { 0 };

u8 D_801E6DD8_996848[3744] = {
#include "assets/photo_check/801E6DD8.png.bin.c"
};

u32 D_801E7C78_9976E8[2] = { 0 };

u8 D_801E7C80_9976F0[3744] = {
#include "assets/photo_check/801E7C80.png.bin.c"
};

u32 D_801E8B20_998590[2] = { 0 };

u8 D_801E8B28_998598[3744] = {
#include "assets/photo_check/801E8B28.png.bin.c"
};

u32 D_801E99C8_999438[2] = { 0 };

u8 D_801E99D0_999440[3744] = {
#include "assets/photo_check/801E99D0.png.bin.c"
};

u32 D_801EA870_99A2E0[2] = { 0 };

u8 D_801EA878_99A2E8[3744] = {
#include "assets/photo_check/801EA878.png.bin.c"
};

u32 D_801EB718_99B188[2] = { 0 };

u8 D_801EB720_99B190[3744] = {
#include "assets/photo_check/801EB720.png.bin.c"
};

u32 D_801EC5C0_99C030[2] = { 0 };

u8 D_801EC5C8_99C038[3744] = {
#include "assets/photo_check/801EC5C8.png.bin.c"
};

u32 D_801ED468_99CED8[2] = { 0 };

u8 D_801ED470_99CEE0[3744] = {
#include "assets/photo_check/801ED470.png.bin.c"
};

u32 D_801EE310_99DD80[2] = { 0 };

u8 D_801EE318_99DD88[3744] = {
#include "assets/photo_check/801EE318.png.bin.c"
};

u32 D_801EF1B8_99EC28[2] = { 0 };

u8 D_801EF1C0_99EC30[3744] = {
#include "assets/photo_check/801EF1C0.png.bin.c"
};

u32 D_801F0060_99FAD0[2] = { 0 };

u8 D_801F0068_99FAD8[3744] = {
#include "assets/photo_check/801F0068.png.bin.c"
};

u32 D_801F0F08_9A0978[2] = { 0 };

u8 D_801F0F10_9A0980[3744] = {
#include "assets/photo_check/801F0F10.png.bin.c"
};

u32 D_801F1DB0_9A1820[2] = { 0 };

u8 D_801F1DB8_9A1828[1248] = {
#include "assets/photo_check/801F1DB8.png.bin.c"
};

Bitmap D_801F2298_9A1D08[14] = {
    { 208, 208, 0, 0, D_801E5F30_9959A0, 9, 0 },
    { 208, 208, 0, 0, D_801E6DD8_996848, 9, 0 },
    { 208, 208, 0, 0, D_801E7C80_9976F0, 9, 0 },
    { 208, 208, 0, 0, D_801E8B28_998598, 9, 0 },
    { 208, 208, 0, 0, D_801E99D0_999440, 9, 0 },
    { 208, 208, 0, 0, D_801EA878_99A2E8, 9, 0 },
    { 208, 208, 0, 0, D_801EB720_99B190, 9, 0 },
    { 208, 208, 0, 0, D_801EC5C8_99C038, 9, 0 },
    { 208, 208, 0, 0, D_801ED470_99CEE0, 9, 0 },
    { 208, 208, 0, 0, D_801EE318_99DD88, 9, 0 },
    { 208, 208, 0, 0, D_801EF1C0_99EC30, 9, 0 },
    { 208, 208, 0, 0, D_801F0068_99FAD8, 9, 0 },
    { 208, 208, 0, 0, D_801F0F10_9A0980, 9, 0 },
    { 208, 208, 0, 0, D_801F1DB8_9A1828, 3, 0 },
};

Sprite D_801F2378_9A1DE8 = {
    0,
    0,
    208,
    120,
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
    14,
    192,
    9,
    9,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801F2298_9A1D08,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801F23BC_9A1E2C[3] = { 0 };

u8 D_801F23C8_9A1E38[728] = {
#include "assets/photo_check/801F23C8.png.bin.c"
};

Bitmap D_801F26A0_9A2110[1] = {
    { 26, 28, 0, 0, D_801F23C8_9A1E38, 13, 0 },
};

Sprite D_801F26B0_9A2120 = {
    0,
    0,
    26,
    13,
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
    13,
    13,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801F26A0_9A2110,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801F26F4_9A2164[3] = { 0 };

u8 D_801F2700_9A2170[512] = {
#include "assets/photo_check/801F2700.png.bin.c"
};

Bitmap D_801F2900_9A2370[1] = {
    { 16, 16, 0, 0, D_801F2700_9A2170, 16, 0 },
};

Sprite D_801F2910_9A2380 = {
    0,
    0,
    16,
    16,
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
    16,
    16,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801F2900_9A2370,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801F2954_9A23C4[3] = { 0 };

u8 D_801F2960_9A23D0[128] = {
#include "assets/photo_check/801F2960.png.bin.c"
};

Bitmap D_801F29E0_9A2450[1] = {
    { 8, 8, 0, 0, D_801F2960_9A23D0, 8, 0 },
};

Sprite D_801F29F0_9A2460 = {
    0,
    0,
    8,
    8,
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
    8,
    8,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801F29E0_9A2450,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801F2A34_9A24A4[3] = { 0 };

u8 D_801F2A40_9A24B0[128] = {
#include "assets/photo_check/801F2A40.png.bin.c"
};

Bitmap D_801F2AC0_9A2530[1] = {
    { 8, 8, 0, 0, D_801F2A40_9A24B0, 8, 0 },
};

Sprite D_801F2AD0_9A2540 = {
    0,
    0,
    8,
    8,
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
    8,
    8,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801F2AC0_9A2530,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801F2B14_9A2584[1] = { 0 };

Gfx D_801F2B18_9A2588[1] = {
#include "build/assets/native/gfx/D_801F2B18_9A2588.dl.inc.c"
};

u32 D_801F2B20_9A2590[2] = { 0 };

u8 D_801F2B28_9A2598[4056] = {
#include "assets/photo_check/801F2B28.png.bin.c"
};

Bitmap D_801F3B00_9A3570[1] = {
    { 52, 52, 0, 0, D_801F2B28_9A2598, 39, 0 },
};

Sprite D_801F3B10_9A3580 = {
    0,
    0,
    52,
    39,
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
    39,
    39,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801F3B00_9A3570,
    NULL,
    NULL,
    0,
    0,
};
