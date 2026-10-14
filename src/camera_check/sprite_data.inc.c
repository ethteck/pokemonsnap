#include "common.h"
#include "camera_check.h"

extern u32 D_camera_check_801E4110[];
extern u8 D_camera_check_801E4118[];
extern u32 D_801E4FB8_8827A8[];
extern u8 D_camera_check_801E4FC0[];
extern u32 D_801E5E60_883650[];
extern u8 D_camera_check_801E5E68[];
extern u32 D_801E6D08_8844F8[];
extern u8 D_camera_check_801E6D10[];
extern u32 D_801E7BB0_8853A0[];
extern u8 D_camera_check_801E7BB8[];
extern u32 D_801E8A58_886248[];
extern u8 D_camera_check_801E8A60[];
extern u32 D_801E9900_8870F0[];
extern u8 D_camera_check_801E9908[];
extern u32 D_801EA7A8_887F98[];
extern u8 D_camera_check_801EA7B0[];
extern u32 D_801EB650_888E40[];
extern u8 D_camera_check_801EB658[];
extern u32 D_801EC4F8_889CE8[];
extern u8 D_camera_check_801EC500[];
extern u32 D_801ED3A0_88AB90[];
extern u8 D_camera_check_801ED3A8[];
extern u32 D_801EE248_88BA38[];
extern u8 D_camera_check_801EE250[];
extern u32 D_801EF0F0_88C8E0[];
extern u8 D_camera_check_801EF0F8[];
extern u32 D_801EFF98_88D788[];
extern u8 D_camera_check_801EFFA0[];
extern Bitmap D_camera_check_801F0480[];
extern Sprite D_camera_check_801F0560;
extern u32 D_801F05A4_88DD94[];
extern u8 D_camera_check_801F05B0[];
extern u32 D_801F1450_88EC40[];
extern u8 D_camera_check_801F1458[];
extern u32 D_801F22F8_88FAE8[];
extern u8 D_camera_check_801F2300[];
extern u32 D_801F31A0_890990[];
extern u8 D_camera_check_801F31A8[];
extern u32 D_801F4048_891838[];
extern u8 D_camera_check_801F4050[];
extern u32 D_801F4EF0_8926E0[];
extern u8 D_camera_check_801F4EF8[];
extern u32 D_801F5D98_893588[];
extern u8 D_camera_check_801F5DA0[];
extern u32 D_801F6C40_894430[];
extern u8 D_camera_check_801F6C48[];
extern u32 D_801F7AE8_8952D8[];
extern u8 D_camera_check_801F7AF0[];
extern u32 D_801F8990_896180[];
extern u8 D_camera_check_801F8998[];
extern u32 D_801F9838_897028[];
extern u8 D_camera_check_801F9840[];
extern u32 D_801FA6E0_897ED0[];
extern u8 D_camera_check_801FA6E8[];
extern u32 D_801FB588_898D78[];
extern u8 D_camera_check_801FB590[];
extern u32 D_801FC430_899C20[];
extern u8 D_camera_check_801FC438[];
extern Bitmap D_camera_check_801FC918[];
extern Sprite D_801FC9F8_89A1E8;
extern u32 D_801FCA3C_89A22C[];
extern u8 D_camera_check_801FCA48[];
extern Bitmap D_camera_check_801FCC48[];
extern Sprite D_camera_check_801FCC58;
extern u32 D_801FCC9C_89A48C[];
extern u8 D_camera_check_801FCCA8[];
extern Bitmap D_camera_check_801FCE68[];
extern Sprite D_camera_check_801FCE78;
extern u32 D_801FCEBC_89A6AC[];
extern u8 D_camera_check_801FCEC8[];
extern Bitmap D_camera_check_801FD078[];
extern Sprite D_camera_check_801FD088;
extern u32 D_801FD0CC_89A8BC[];
extern u8 D_camera_check_801FD0D8[];
extern Bitmap D_camera_check_801FD158[];
extern Sprite D_801FD168_89A958;
extern u32 D_801FD1AC_89A99C[];
extern u8 D_camera_check_801FD1B8[];
extern Bitmap D_camera_check_801FD238[];
extern Sprite D_801FD248_89AA38;
extern u32 D_801FD28C_89AA7C[];
extern u8 D_camera_check_801FD298[];
extern Bitmap D_camera_check_801FD318[];
extern Sprite D_801FD328_89AB18;
extern u32 D_801FD36C_89AB5C[];
extern u8 D_camera_check_801FD378[];
extern Bitmap D_camera_check_801FD3F8[];
extern Sprite D_camera_check_801FD408;
extern u32 D_801FD44C_89AC3C[];
extern u8 D_camera_check_801FD458[];
extern Bitmap D_camera_check_801FD4D8[];
extern Sprite D_camera_check_801FD4E8;
extern u32 D_801FD52C_89AD1C[];
extern u8 D_camera_check_801FD538[];
extern Bitmap D_camera_check_801FD5B8[];
extern Sprite D_camera_check_801FD5C8;
extern u32 D_801FD60C_89ADFC[];
extern u8 D_camera_check_801FD618[];
extern Bitmap D_camera_check_801FD698[];
extern Sprite D_camera_check_801FD6A8;
extern u32 D_801FD6EC_89AEDC[];
extern u8 D_camera_check_801FD6F8[];
extern Bitmap D_camera_check_801FD9D0[];
extern Sprite D_camera_check_801FD9E0;
extern u32 D_801FDA24_89B214[];
extern u8 D_camera_check_801FDA30[];
extern Bitmap D_camera_check_801FDDA8[];
extern Sprite D_camera_check_801FDDB8;
extern u32 D_801FDDFC_89B5EC[];
extern u8 D_camera_check_801FDE08[];
extern Bitmap D_camera_check_801FE150[];
extern Sprite D_camera_check_801FE160;
extern u32 D_801FE1A4_89B994[];
extern u8 D_camera_check_801FE1B0[];
extern Bitmap D_camera_check_801FE308[];
extern Sprite D_camera_check_801FE318;
extern u32 D_801FE35C_89BB4C[];
extern u8 D_camera_check_801FE368[];
extern Bitmap D_camera_check_801FE438[];
extern Sprite D_camera_check_801FE448;
extern u32 D_801FE48C_89BC7C[];
extern u8 D_camera_check_801FE498[];
extern Bitmap D_camera_check_801FE5B8[];
extern Sprite D_801FE5C8_89BDB8;
extern u32 D_801FE60C_89BDFC[];
extern u8 D_camera_check_801FE618[];
extern Bitmap D_camera_check_801FE738[];
extern Sprite D_801FE748_89BF38;
extern u32 D_801FE78C_89BF7C[];
extern u8 D_camera_check_801FE798[];
extern Bitmap D_camera_check_801FE8B8[];
extern Sprite D_801FE8C8_89C0B8;
extern u32 D_801FE90C_89C0FC[];
extern u8 D_camera_check_801FE918[];
extern Bitmap D_camera_check_801FF118[];
extern Sprite D_camera_check_801FF128;
extern u32 D_801FF16C_89C95C[];
extern u8 D_camera_check_801FF178[];
extern Bitmap D_camera_check_801FF978[];
extern Sprite D_camera_check_801FF988;
extern u32 D_801FF9CC_89D1BC[];
extern u8 D_camera_check_801FF9D8[];
extern Bitmap D_camera_check_801FFAF8[];
extern Sprite D_camera_check_801FFB08;
extern u32 D_801FFB4C_89D33C[];
extern u8 D_camera_check_801FFB58[];
extern Bitmap D_camera_check_801FFC78[];
extern Sprite D_camera_check_801FFC88;
extern u32 D_801FFCCC_89D4BC[];
extern u8 D_camera_check_801FFCD8[];
extern Bitmap D_camera_check_802004D8[];
extern Sprite D_camera_check_802004E8;
extern u32 D_8020052C_89DD1C[];
extern u8 D_camera_check_80200538[];
extern Bitmap D_camera_check_80201510[];
extern Sprite D_camera_check_80201520;
extern u32 D_80201564_89ED54[];
extern u8 D_camera_check_80201570[];
extern u32 D_802024C0_89FCB0[];
extern u8 D_camera_check_802024C8[];
extern u32 D_80203418_8A0C08[];
extern u8 D_camera_check_80203420[];
extern u32 D_80204370_8A1B60[];
extern u8 D_camera_check_80204378[];
extern u32 D_802052C8_8A2AB8[];
extern u8 D_camera_check_802052D0[];
extern u32 D_80206220_8A3A10[];
extern u8 D_camera_check_80206228[];
extern u32 D_80207178_8A4968[];
extern u8 D_camera_check_80207180[];
extern u32 D_802080D0_8A58C0[];
extern u8 D_camera_check_802080D8[];
extern Bitmap D_camera_check_80208880[];
extern Sprite D_camera_check_80208900;

u32 D_camera_check_801E4110[2] = { 0 };

u8 D_camera_check_801E4118[] = {
#include "assets/camera_check/801E4118.png.bin.c"
};

u32 D_801E4FB8_8827A8[2] = { 0 };

u8 D_camera_check_801E4FC0[] = {
#include "assets/camera_check/801E4FC0.png.bin.c"
};

u32 D_801E5E60_883650[2] = { 0 };

u8 D_camera_check_801E5E68[] = {
#include "assets/camera_check/801E5E68.png.bin.c"
};

u32 D_801E6D08_8844F8[2] = { 0 };

u8 D_camera_check_801E6D10[] = {
#include "assets/camera_check/801E6D10.png.bin.c"
};

u32 D_801E7BB0_8853A0[2] = { 0 };

u8 D_camera_check_801E7BB8[] = {
#include "assets/camera_check/801E7BB8.png.bin.c"
};

u32 D_801E8A58_886248[2] = { 0 };

u8 D_camera_check_801E8A60[] = {
#include "assets/camera_check/801E8A60.png.bin.c"
};

u32 D_801E9900_8870F0[2] = { 0 };

u8 D_camera_check_801E9908[] = {
#include "assets/camera_check/801E9908.png.bin.c"
};

u32 D_801EA7A8_887F98[2] = { 0 };

u8 D_camera_check_801EA7B0[] = {
#include "assets/camera_check/801EA7B0.png.bin.c"
};

u32 D_801EB650_888E40[2] = { 0 };

u8 D_camera_check_801EB658[] = {
#include "assets/camera_check/801EB658.png.bin.c"
};

u32 D_801EC4F8_889CE8[2] = { 0 };

u8 D_camera_check_801EC500[] = {
#include "assets/camera_check/801EC500.png.bin.c"
};

u32 D_801ED3A0_88AB90[2] = { 0 };

u8 D_camera_check_801ED3A8[] = {
#include "assets/camera_check/801ED3A8.png.bin.c"
};

u32 D_801EE248_88BA38[2] = { 0 };

u8 D_camera_check_801EE250[] = {
#include "assets/camera_check/801EE250.png.bin.c"
};

u32 D_801EF0F0_88C8E0[2] = { 0 };

u8 D_camera_check_801EF0F8[] = {
#include "assets/camera_check/801EF0F8.png.bin.c"
};

u32 D_801EFF98_88D788[2] = { 0 };

u8 D_camera_check_801EFFA0[] = {
#include "assets/camera_check/801EFFA0.png.bin.c"
};

Bitmap D_camera_check_801F0480[] = {
    { 208, 208, 0, 0, D_camera_check_801E4118, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801E4FC0, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801E5E68, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801E6D10, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801E7BB8, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801E8A60, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801E9908, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801EA7B0, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801EB658, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801EC500, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801ED3A8, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801EE250, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801EF0F8, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801EFFA0, 3, 0 },
};

Sprite D_camera_check_801F0560 = {
    0,
    0,
    208,
    120,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801F0480,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801F05A4_88DD94[3] = { 0 };

u8 D_camera_check_801F05B0[] = {
#include "assets/camera_check/801F05B0.png.bin.c"
};

u32 D_801F1450_88EC40[2] = { 0 };

u8 D_camera_check_801F1458[] = {
#include "assets/camera_check/801F1458.png.bin.c"
};

u32 D_801F22F8_88FAE8[2] = { 0 };

u8 D_camera_check_801F2300[] = {
#include "assets/camera_check/801F2300.png.bin.c"
};

u32 D_801F31A0_890990[2] = { 0 };

u8 D_camera_check_801F31A8[] = {
#include "assets/camera_check/801F31A8.png.bin.c"
};

u32 D_801F4048_891838[2] = { 0 };

u8 D_camera_check_801F4050[] = {
#include "assets/camera_check/801F4050.png.bin.c"
};

u32 D_801F4EF0_8926E0[2] = { 0 };

u8 D_camera_check_801F4EF8[] = {
#include "assets/camera_check/801F4EF8.png.bin.c"
};

u32 D_801F5D98_893588[2] = { 0 };

u8 D_camera_check_801F5DA0[] = {
#include "assets/camera_check/801F5DA0.png.bin.c"
};

u32 D_801F6C40_894430[2] = { 0 };

u8 D_camera_check_801F6C48[] = {
#include "assets/camera_check/801F6C48.png.bin.c"
};

u32 D_801F7AE8_8952D8[2] = { 0 };

u8 D_camera_check_801F7AF0[] = {
#include "assets/camera_check/801F7AF0.png.bin.c"
};

u32 D_801F8990_896180[2] = { 0 };

u8 D_camera_check_801F8998[] = {
#include "assets/camera_check/801F8998.png.bin.c"
};

u32 D_801F9838_897028[2] = { 0 };

u8 D_camera_check_801F9840[] = {
#include "assets/camera_check/801F9840.png.bin.c"
};

u32 D_801FA6E0_897ED0[2] = { 0 };

u8 D_camera_check_801FA6E8[] = {
#include "assets/camera_check/801FA6E8.png.bin.c"
};

u32 D_801FB588_898D78[2] = { 0 };

u8 D_camera_check_801FB590[] = {
#include "assets/camera_check/801FB590.png.bin.c"
};

u32 D_801FC430_899C20[2] = { 0 };

u8 D_camera_check_801FC438[] = {
#include "assets/camera_check/801FC438.png.bin.c"
};

Bitmap D_camera_check_801FC918[] = {
    { 208, 208, 0, 0, D_camera_check_801F05B0, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F1458, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F2300, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F31A8, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F4050, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F4EF8, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F5DA0, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F6C48, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F7AF0, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F8998, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801F9840, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801FA6E8, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801FB590, 9, 0 },
    { 208, 208, 0, 0, D_camera_check_801FC438, 3, 0 },
};

Sprite D_801FC9F8_89A1E8 = {
    0,
    0,
    208,
    120,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FC918,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FCA3C_89A22C[3] = { 0 };

u8 D_camera_check_801FCA48[] = {
#include "assets/camera_check/801FCA48.png.bin.c"
};

Bitmap D_camera_check_801FCC48[] = {
    { 16, 16, 0, 0, D_camera_check_801FCA48, 16, 0 },
};

Sprite D_camera_check_801FCC58 = {
    0,
    0,
    16,
    16,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FCC48,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FCC9C_89A48C[3] = { 0 };

u8 D_camera_check_801FCCA8[] = {
#include "assets/camera_check/801FCCA8.png.bin.c"
};

Bitmap D_camera_check_801FCE68[] = {
    { 7, 8, 0, 0, D_camera_check_801FCCA8, 28, 0 },
};

Sprite D_camera_check_801FCE78 = {
    0,
    0,
    7,
    28,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    28,
    28,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FCE68,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FCEBC_89A6AC[3] = { 0 };

u8 D_camera_check_801FCEC8[] = {
#include "assets/camera_check/801FCEC8.png.bin.c"
};

Bitmap D_camera_check_801FD078[] = {
    { 24, 24, 0, 0, D_camera_check_801FCEC8, 9, 0 },
};

Sprite D_camera_check_801FD088 = {
    0,
    0,
    24,
    9,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    9,
    9,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FD078,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FD0CC_89A8BC[3] = { 0 };

u8 D_camera_check_801FD0D8[] = {
#include "assets/camera_check/801FD0D8.png.bin.c"
};

Bitmap D_camera_check_801FD158[] = {
    { 8, 8, 0, 0, D_camera_check_801FD0D8, 8, 0 },
};

Sprite D_801FD168_89A958 = {
    0,
    0,
    8,
    8,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FD158,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FD1AC_89A99C[3] = { 0 };

u8 D_camera_check_801FD1B8[] = {
#include "assets/camera_check/801FD1B8.png.bin.c"
};

Bitmap D_camera_check_801FD238[] = {
    { 8, 8, 0, 0, D_camera_check_801FD1B8, 8, 0 },
};

Sprite D_801FD248_89AA38 = {
    0,
    0,
    8,
    8,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FD238,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FD28C_89AA7C[3] = { 0 };

u8 D_camera_check_801FD298[] = {
#include "assets/camera_check/801FD298.png.bin.c"
};

Bitmap D_camera_check_801FD318[] = {
    { 8, 8, 0, 0, D_camera_check_801FD298, 8, 0 },
};

Sprite D_801FD328_89AB18 = {
    0,
    0,
    8,
    8,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FD318,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FD36C_89AB5C[3] = { 0 };

u8 D_camera_check_801FD378[] = {
#include "assets/camera_check/801FD378.png.bin.c"
};

Bitmap D_camera_check_801FD3F8[] = {
    { 8, 8, 0, 0, D_camera_check_801FD378, 8, 0 },
};

Sprite D_camera_check_801FD408 = {
    0,
    0,
    8,
    8,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FD3F8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FD44C_89AC3C[3] = { 0 };

u8 D_camera_check_801FD458[] = {
#include "assets/camera_check/801FD458.png.bin.c"
};

Bitmap D_camera_check_801FD4D8[] = {
    { 8, 8, 0, 0, D_camera_check_801FD458, 8, 0 },
};

Sprite D_camera_check_801FD4E8 = {
    0,
    0,
    8,
    8,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FD4D8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FD52C_89AD1C[3] = { 0 };

u8 D_camera_check_801FD538[] = {
#include "assets/camera_check/801FD538.png.bin.c"
};

Bitmap D_camera_check_801FD5B8[] = {
    { 8, 8, 0, 0, D_camera_check_801FD538, 8, 0 },
};

Sprite D_camera_check_801FD5C8 = {
    0,
    0,
    8,
    8,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FD5B8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FD60C_89ADFC[3] = { 0 };

u8 D_camera_check_801FD618[] = {
#include "assets/camera_check/801FD618.png.bin.c"
};

Bitmap D_camera_check_801FD698[] = {
    { 8, 8, 0, 0, D_camera_check_801FD618, 8, 0 },
};

Sprite D_camera_check_801FD6A8 = {
    0,
    0,
    8,
    8,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FD698,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FD6EC_89AEDC[3] = { 0 };

u8 D_camera_check_801FD6F8[] = {
#include "assets/camera_check/801FD6F8.png.bin.c"
};

Bitmap D_camera_check_801FD9D0[] = {
    { 26, 28, 0, 0, D_camera_check_801FD6F8, 13, 0 },
};

Sprite D_camera_check_801FD9E0 = {
    0,
    0,
    26,
    13,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FD9D0,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FDA24_89B214[3] = { 0 };

u8 D_camera_check_801FDA30[] = {
#include "assets/camera_check/801FDA30.png.bin.c"
};

Bitmap D_camera_check_801FDDA8[] = {
    { 3, 4, 0, 0, D_camera_check_801FDA30, 111, 0 },
};

Sprite D_camera_check_801FDDB8 = {
    0,
    0,
    3,
    111,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FDDA8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FDDFC_89B5EC[3] = { 0 };

u8 D_camera_check_801FDE08[] = {
#include "assets/camera_check/801FDE08.png.bin.c"
};

Bitmap D_camera_check_801FE150[] = {
    { 140, 140, 0, 0, D_camera_check_801FDE08, 3, 0 },
};

Sprite D_camera_check_801FE160 = {
    0,
    0,
    140,
    3,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FE150,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FE1A4_89B994[3] = { 0 };

u8 D_camera_check_801FE1B0[] = {
#include "assets/camera_check/801FE1B0.png.bin.c"
};

Bitmap D_camera_check_801FE308[] = {
    { 2, 4, 0, 0, D_camera_check_801FE1B0, 43, 0 },
};

Sprite D_camera_check_801FE318 = {
    0,
    0,
    2,
    43,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FE308,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FE35C_89BB4C[3] = { 0 };

u8 D_camera_check_801FE368[] = {
#include "assets/camera_check/801FE368.png.bin.c"
};

Bitmap D_camera_check_801FE438[] = {
    { 52, 52, 0, 0, D_camera_check_801FE368, 2, 0 },
};

Sprite D_camera_check_801FE448 = {
    0,
    0,
    52,
    2,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_801FE438,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FE48C_89BC7C[3] = { 0 };

u8 D_camera_check_801FE498[] = {
#include "assets/camera_check/801FE498.png.bin.c"
};

Bitmap D_camera_check_801FE5B8[] = {
    { 12, 12, 0, 0, D_camera_check_801FE498, 12, 0 },
};

Sprite D_801FE5C8_89BDB8 = {
    0,
    0,
    12,
    12,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    12,
    12,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FE5B8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FE60C_89BDFC[3] = { 0 };

u8 D_camera_check_801FE618[] = {
#include "assets/camera_check/801FE618.png.bin.c"
};

Bitmap D_camera_check_801FE738[] = {
    { 12, 12, 0, 0, D_camera_check_801FE618, 12, 0 },
};

Sprite D_801FE748_89BF38 = {
    0,
    0,
    12,
    12,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    12,
    12,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FE738,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FE78C_89BF7C[3] = { 0 };

u8 D_camera_check_801FE798[] = {
#include "assets/camera_check/801FE798.png.bin.c"
};

Bitmap D_camera_check_801FE8B8[] = {
    { 12, 12, 0, 0, D_camera_check_801FE798, 12, 0 },
};

Sprite D_801FE8C8_89C0B8 = {
    0,
    0,
    12,
    12,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    12,
    12,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FE8B8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FE90C_89C0FC[3] = { 0 };

u8 D_camera_check_801FE918[] = {
#include "assets/camera_check/801FE918.png.bin.c"
};

Bitmap D_camera_check_801FF118[] = {
    { 32, 32, 0, 0, D_camera_check_801FE918, 32, 0 },
};

Sprite D_camera_check_801FF128 = {
    0,
    0,
    32,
    32,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    32,
    32,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FF118,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FF16C_89C95C[3] = { 0 };

u8 D_camera_check_801FF178[] = {
#include "assets/camera_check/801FF178.png.bin.c"
};

Bitmap D_camera_check_801FF978[] = {
    { 32, 32, 0, 0, D_camera_check_801FF178, 32, 0 },
};

Sprite D_camera_check_801FF988 = {
    0,
    0,
    32,
    32,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    32,
    32,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FF978,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FF9CC_89D1BC[3] = { 0 };

u8 D_camera_check_801FF9D8[] = {
#include "assets/camera_check/801FF9D8.png.bin.c"
};

Bitmap D_camera_check_801FFAF8[] = {
    { 12, 12, 0, 0, D_camera_check_801FF9D8, 12, 0 },
};

Sprite D_camera_check_801FFB08 = {
    0,
    0,
    12,
    12,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    12,
    12,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FFAF8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FFB4C_89D33C[3] = { 0 };

u8 D_camera_check_801FFB58[] = {
#include "assets/camera_check/801FFB58.png.bin.c"
};

Bitmap D_camera_check_801FFC78[] = {
    { 12, 12, 0, 0, D_camera_check_801FFB58, 12, 0 },
};

Sprite D_camera_check_801FFC88 = {
    0,
    0,
    12,
    12,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    12,
    12,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_801FFC78,
    NULL,
    NULL,
    0,
    0,
};

u32 D_801FFCCC_89D4BC[3] = { 0 };

u8 D_camera_check_801FFCD8[] = {
#include "assets/camera_check/801FFCD8.png.bin.c"
};

Bitmap D_camera_check_802004D8[] = {
    { 32, 32, 0, 0, D_camera_check_801FFCD8, 32, 0 },
};

Sprite D_camera_check_802004E8 = {
    0,
    0,
    32,
    32,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    32,
    32,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    D_camera_check_802004D8,
    NULL,
    NULL,
    0,
    0,
};

u32 D_8020052C_89DD1C[3] = { 0 };

u8 D_camera_check_80200538[] = {
#include "assets/camera_check/80200538.png.bin.c"
};

Bitmap D_camera_check_80201510[] = {
    { 52, 52, 0, 0, D_camera_check_80200538, 39, 0 },
};

Sprite D_camera_check_80201520 = {
    0,
    0,
    52,
    39,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_80201510,
    NULL,
    NULL,
    0,
    0,
};

u32 D_80201564_89ED54[3] = { 0 };

u8 D_camera_check_80201570[] = {
#include "assets/camera_check/80201570.png.bin.c"
};

u32 D_802024C0_89FCB0[2] = { 0 };

u8 D_camera_check_802024C8[] = {
#include "assets/camera_check/802024C8.png.bin.c"
};

u32 D_80203418_8A0C08[2] = { 0 };

u8 D_camera_check_80203420[] = {
#include "assets/camera_check/80203420.png.bin.c"
};

u32 D_80204370_8A1B60[2] = { 0 };

u8 D_camera_check_80204378[] = {
#include "assets/camera_check/80204378.png.bin.c"
};

u32 D_802052C8_8A2AB8[2] = { 0 };

u8 D_camera_check_802052D0[] = {
#include "assets/camera_check/802052D0.png.bin.c"
};

u32 D_80206220_8A3A10[2] = { 0 };

u8 D_camera_check_80206228[] = {
#include "assets/camera_check/80206228.png.bin.c"
};

u32 D_80207178_8A4968[2] = { 0 };

u8 D_camera_check_80207180[] = {
#include "assets/camera_check/80207180.png.bin.c"
};

u32 D_802080D0_8A58C0[2] = { 0 };

u8 D_camera_check_802080D8[] = {
#include "assets/camera_check/802080D8.png.bin.c"
};

Bitmap D_camera_check_80208880[] = {
    { 140, 140, 0, 0, D_camera_check_80201570, 14, 0 },
    { 140, 140, 0, 0, D_camera_check_802024C8, 14, 0 },
    { 140, 140, 0, 0, D_camera_check_80203420, 14, 0 },
    { 140, 140, 0, 0, D_camera_check_80204378, 14, 0 },
    { 140, 140, 0, 0, D_camera_check_802052D0, 14, 0 },
    { 140, 140, 0, 0, D_camera_check_80206228, 14, 0 },
    { 140, 140, 0, 0, D_camera_check_80207180, 14, 0 },
    { 140, 140, 0, 0, D_camera_check_802080D8, 7, 0 },
};

Sprite D_camera_check_80208900 = {
    0,
    0,
    140,
    105,
    1.000000000f,
    1.000000000f,
    0,
    0,
    512,
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
    D_camera_check_80208880,
    NULL,
    NULL,
    0,
    0,
};
