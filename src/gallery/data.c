#include "common.h"
#include "ld_addrs.h"

#include "gallery.h"
void func_801DCDDC_9FAA9C(void);
void func_801DCE90_9FAB50(void*);

/* Native graph declarations; shared image/Bitmap identities remain shared. */
extern Gfx D_801E1620_9FF2E0[14];
extern ScreenSettings D_801E1690_9FF350;
extern SceneSetup D_801E16AC_9FF36C;
extern u32 D_801E1738_9FF3F8[4];
extern u8 D_801E1748_9FF408[3840];
extern u32 D_801E2648_A00308[2];
extern u8 D_801E2650_A00310[3840];
extern u32 D_801E3550_A01210[2];
extern u8 D_801E3558_A01218[3840];
extern u32 D_801E4458_A02118[2];
extern u8 D_801E4460_A02120[3840];
extern u32 D_801E5360_A03020[2];
extern u8 D_801E5368_A03028[3840];
extern u32 D_801E6268_A03F28[2];
extern u8 D_801E6270_A03F30[3840];
extern u32 D_801E7170_A04E30[2];
extern u8 D_801E7178_A04E38[3840];
extern Bitmap D_801E8078_A05D38[7];
extern Sprite D_801E80E8_A05DA8;
extern u32 D_801E812C_A05DEC[3];
extern u8 D_801E8138_A05DF8[344];
extern Bitmap D_801E8290_A05F50[1];
extern Sprite D_801E82A0_A05F60;
extern u32 D_801E82E4_A05FA4[3];
extern u8 D_801E82F0_A05FB0[208];
extern Bitmap D_801E83C0_A06080[1];
extern Sprite D_801E83D0_A06090;
extern u32 D_801E8414_A060D4[3];
extern u8 D_801E8420_A060E0[512];
extern Bitmap D_801E8620_A062E0[1];
extern Sprite D_801E8630_A062F0;
extern u32 D_801E8674_A06334[3];
extern u8 D_801E8680_A06340[512];
extern Bitmap D_801E8880_A06540[1];
extern Sprite D_801E8890_A06550;
extern u32 D_801E88D4_A06594[3];
extern u8 D_801E88E0_A065A0[512];
extern Bitmap D_801E8AE0_A067A0[1];
extern Sprite D_801E8AF0_A067B0;
extern u32 D_801E8B34_A067F4[3];
extern u8 D_801E8B40_A06800[512];
extern Bitmap D_801E8D40_A06A00[1];
extern Sprite D_801E8D50_A06A10;
extern u32 D_801E8D94_A06A54[3];
extern u8 D_801E8DA0_A06A60[512];
extern Bitmap D_801E8FA0_A06C60[1];
extern Sprite D_801E8FB0_A06C70;
extern u32 D_801E8FF4_A06CB4[3];
extern u8 D_801E9000_A06CC0[128];
extern Bitmap D_801E9080_A06D40[1];
extern Sprite D_801E9090_A06D50;
extern u32 D_801E90D4_A06D94[3];
extern u8 D_801E90E0_A06DA0[128];
extern Bitmap D_801E9160_A06E20[1];
extern Sprite D_801E9170_A06E30;
extern u32 D_801E91B4_A06E74[1];
extern Gfx D_801E91B8_A06E78[1];
extern u32 D_801E91C0_A06E80[2];
extern u8 D_801E91C8_A06E88[4056];
extern Bitmap D_801EA1A0_A07E60[1];
extern Sprite D_801EA1B0_A07E70;
extern s32 D_801EA1F4_A07EB4;
extern s32 D_801EA1F8_A07EB8;
extern s32 D_801EA1FC_A07EBC;
extern s32 D_801EA200_A07EC0;
extern s32 D_801EA204_A07EC4;
extern u32 D_801EA208_A07EC8[2];
extern UIButton D_801EA210_A07ED0[7];
extern UIButton D_801EA248_A07F08[8];
extern s32 D_801EA288_A07F48;
extern s32 D_801EA28C_A07F4C;
extern s32 D_801EA290_A07F50;
extern s32 D_801EA294_A07F54;
extern s32 D_801EA298_A07F58;
extern s32 D_801EA29C_A07F5C;
extern s32 D_801EA2A0_A07F60;
extern s32 D_801EA2A4_A07F64;
extern s32 D_801EA2A8_A07F68;
extern s32 D_801EA2AC_A07F6C;
extern s32 D_801EA2B0_A07F70;
extern u32 D_801EA2B4_A07F74[3];

/* Original address order in one ordinary IDO .data section. */
Gfx D_801E1620_9FF2E0[14] = {
#include "build/assets/native/gfx/D_801E1620_9FF2E0.dl.inc.c"
};

ScreenSettings D_801E1690_9FF350 = {
    D_803B5000,
    D_803DA800,
    NULL,
    NULL,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0x16A99,
};

SceneSetup D_801E16AC_9FF36C = {
    {
        0,
        omUpdateAll,
        omDrawAll,
        gallery_VRAM_END,
        0,
        1,
        1,
        49152,
        8192,
        0,
        0,
        17408,
        2,
        8192,
        func_800A1A50,
        contUpdate,
    },
    16,
    8192,
    16,
    0,
    32,
    0,
    92,
    1024,
    NULL,
    func_801DCE90_9FAB50,
    0,
    16,
    0,
    136,
    0,
    96,
    0,
    144,
    func_801DCDDC_9FAA9C,
};

u32 D_801E1738_9FF3F8[4] = { 0 };

u8 D_801E1748_9FF408[3840] = {
#include "assets/gallery/801E1748.png.bin.c"
};

u32 D_801E2648_A00308[2] = { 0 };

u8 D_801E2650_A00310[3840] = {
#include "assets/gallery/801E2650.png.bin.c"
};

u32 D_801E3550_A01210[2] = { 0 };

u8 D_801E3558_A01218[3840] = {
#include "assets/gallery/801E3558.png.bin.c"
};

u32 D_801E4458_A02118[2] = { 0 };

u8 D_801E4460_A02120[3840] = {
#include "assets/gallery/801E4460.png.bin.c"
};

u32 D_801E5360_A03020[2] = { 0 };

u8 D_801E5368_A03028[3840] = {
#include "assets/gallery/801E5368.png.bin.c"
};

u32 D_801E6268_A03F28[2] = { 0 };

u8 D_801E6270_A03F30[3840] = {
#include "assets/gallery/801E6270.png.bin.c"
};

u32 D_801E7170_A04E30[2] = { 0 };

u8 D_801E7178_A04E38[3840] = {
#include "assets/gallery/801E7178.png.bin.c"
};

Bitmap D_801E8078_A05D38[7] = {
    { 240, 240, 0, 0, D_801E1748_9FF408, 8, 0 },
    { 240, 240, 0, 0, D_801E2650_A00310, 8, 0 },
    { 240, 240, 0, 0, D_801E3558_A01218, 8, 0 },
    { 240, 240, 0, 0, D_801E4460_A02120, 8, 0 },
    { 240, 240, 0, 0, D_801E5368_A03028, 8, 0 },
    { 240, 240, 0, 0, D_801E6270_A03F30, 8, 0 },
    { 240, 240, 0, 0, D_801E7178_A04E38, 8, 0 },
};

Sprite D_801E80E8_A05DA8 = {
    0,
    0,
    240,
    56,
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
    7,
    108,
    8,
    8,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_801E8078_A05D38,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E812C_A05DEC[3] = { 0 };

u8 D_801E8138_A05DF8[344] = {
#include "assets/gallery/801E8138.png.bin.c"
};

Bitmap D_801E8290_A05F50[1] = {
    { 2, 4, 0, 0, D_801E8138_A05DF8, 43, 0 },
};

Sprite D_801E82A0_A05F60 = {
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
    D_801E8290_A05F50,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E82E4_A05FA4[3] = { 0 };

u8 D_801E82F0_A05FB0[208] = {
#include "assets/gallery/801E82F0.png.bin.c"
};

Bitmap D_801E83C0_A06080[1] = {
    { 52, 52, 0, 0, D_801E82F0_A05FB0, 2, 0 },
};

Sprite D_801E83D0_A06090 = {
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
    D_801E83C0_A06080,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E8414_A060D4[3] = { 0 };

u8 D_801E8420_A060E0[512] = {
#include "assets/gallery/801E8420.png.bin.c"
};

Bitmap D_801E8620_A062E0[1] = {
    { 16, 16, 0, 0, D_801E8420_A060E0, 16, 0 },
};

Sprite D_801E8630_A062F0 = {
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
    D_801E8620_A062E0,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E8674_A06334[3] = { 0 };

u8 D_801E8680_A06340[512] = {
#include "assets/gallery/801E8680.png.bin.c"
};

Bitmap D_801E8880_A06540[1] = {
    { 16, 16, 0, 0, D_801E8680_A06340, 16, 0 },
};

Sprite D_801E8890_A06550 = {
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
    D_801E8880_A06540,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E88D4_A06594[3] = { 0 };

u8 D_801E88E0_A065A0[512] = {
#include "assets/gallery/801E88E0.png.bin.c"
};

Bitmap D_801E8AE0_A067A0[1] = {
    { 16, 16, 0, 0, D_801E88E0_A065A0, 16, 0 },
};

Sprite D_801E8AF0_A067B0 = {
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
    D_801E8AE0_A067A0,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E8B34_A067F4[3] = { 0 };

u8 D_801E8B40_A06800[512] = {
#include "assets/gallery/801E8B40.png.bin.c"
};

Bitmap D_801E8D40_A06A00[1] = {
    { 16, 16, 0, 0, D_801E8B40_A06800, 16, 0 },
};

Sprite D_801E8D50_A06A10 = {
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
    D_801E8D40_A06A00,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E8D94_A06A54[3] = { 0 };

u8 D_801E8DA0_A06A60[512] = {
#include "assets/gallery/801E8DA0.png.bin.c"
};

Bitmap D_801E8FA0_A06C60[1] = {
    { 16, 16, 0, 0, D_801E8DA0_A06A60, 16, 0 },
};

Sprite D_801E8FB0_A06C70 = {
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
    D_801E8FA0_A06C60,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E8FF4_A06CB4[3] = { 0 };

u8 D_801E9000_A06CC0[128] = {
#include "assets/gallery/801E9000.png.bin.c"
};

Bitmap D_801E9080_A06D40[1] = {
    { 8, 8, 0, 0, D_801E9000_A06CC0, 8, 0 },
};

Sprite D_801E9090_A06D50 = {
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
    D_801E9080_A06D40,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E90D4_A06D94[3] = { 0 };

u8 D_801E90E0_A06DA0[128] = {
#include "assets/gallery/801E90E0.png.bin.c"
};

Bitmap D_801E9160_A06E20[1] = {
    { 8, 8, 0, 0, D_801E90E0_A06DA0, 8, 0 },
};

Sprite D_801E9170_A06E30 = {
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
    D_801E9160_A06E20,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801E91B4_A06E74[1] = { 0 };

Gfx D_801E91B8_A06E78[1] = {
#include "build/assets/native/gfx/D_801E91B8_A06E78.dl.inc.c"
};

u32 D_801E91C0_A06E80[2] = { 0 };

u8 D_801E91C8_A06E88[4056] = {
#include "assets/gallery/801E91C8.png.bin.c"
};

Bitmap D_801EA1A0_A07E60[1] = {
    { 52, 52, 0, 0, D_801E91C8_A06E88, 39, 0 },
};

Sprite D_801EA1B0_A07E70 = {
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
    D_801EA1A0_A07E60,
    NULL,
    NULL,
    0,
    0,
};

s32 D_801EA1F4_A07EB4 = 1;

s32 D_801EA1F8_A07EB8 = 0;

s32 D_801EA1FC_A07EBC = 0;

s32 D_801EA200_A07EC0 = -1;

s32 D_801EA204_A07EC4 = 0;

u32 D_801EA208_A07EC8[2] = { 0 };

UIButton D_801EA210_A07ED0[7] = {
    { 2, NULL },
    { 3, NULL },
    { 26, NULL },
    { 20, NULL },
    { 34, NULL },
    { 4, NULL },
    { 35, NULL },
};

UIButton D_801EA248_A07F08[8] = {
    { 2, NULL },
    { 3, NULL },
    { 26, NULL },
    { 20, NULL },
    { 34, NULL },
    { 32, NULL },
    { 4, NULL },
    { 35, NULL },
};

s32 D_801EA288_A07F48 = 0;

s32 D_801EA28C_A07F4C = 0;

s32 D_801EA290_A07F50 = 0;

s32 D_801EA294_A07F54 = 0;

s32 D_801EA298_A07F58 = -1;

s32 D_801EA29C_A07F5C = -1;

s32 D_801EA2A0_A07F60 = -1;

s32 D_801EA2A4_A07F64 = -1;

s32 D_801EA2A8_A07F68 = -1;

s32 D_801EA2AC_A07F6C = -1;

s32 D_801EA2B0_A07F70 = -1;

u32 D_801EA2B4_A07F74[3] = { 0 };
