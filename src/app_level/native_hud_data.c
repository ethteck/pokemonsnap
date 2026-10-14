#include "native_data.h"

s32 sMinTimeBetweenPhotos = 10;

MovementState gMovementState = {
    0.0f,
    0.5f,
    NULL,
    { 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f },
    0.0f,
    0.0f,
};

u8 D_80366BD0_506FE0[8] = { 0 };

Gfx D_80366BD8_506FE8[1] = {
#include "build/assets/native/gfx/D_80366BD8_506FE8.dl.inc.c"
};

u8 D_80366BE0_506FF0[512] = {
#include "assets/app_level/native_hud/506FF0.png.bin.c"
};

Bitmap D_80366DE0_5071F0[1] = {
    { 16, 16, 0, 0, D_80366BE0_506FF0, 16, 0 },
};

Sprite D_80366DF0_507200 = {
    0,
    0,
    16,
    16,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
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
    0,
    2,
    D_80366DE0_5071F0,
    D_803AB1C0_54B5D0,
    NULL,
    0,
    0,
};

u8 D_80366E34_507244[4] = { 0 };

Gfx D_80366E38_507248[1] = {
#include "build/assets/native/gfx/D_80366E38_507248.dl.inc.c"
};

u8 D_80366E40_507250[1320] = {
#include "assets/app_level/native_hud/507250.png.bin.c"
};

Gfx D_80367368_507778[1] = {
#include "build/assets/native/gfx/D_80367368_507778.dl.inc.c"
};

u8 D_80367370_507780[512] = {
#include "assets/app_level/native_hud/507780.png.bin.c"
};

Bitmap D_80367570_507980[1] = {
    { 33, 40, 0, 0, D_80366E40_507250, 33, 0 },
};

Sprite D_80367580_507990 = {
    0,
    0,
    33,
    33,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
    4660,
    255,
    255,
    255,
    255,
    0,
    256,
    (int*) D_80367370_507780,
    0,
    1,
    1,
    36,
    33,
    33,
    2,
    1,
    D_80367570_507980,
    D_803AB2E0_54B6F0,
    NULL,
    0,
    0,
};

u8 D_803675C4_5079D4[4] = { 0 };

Gfx D_803675C8_5079D8[1] = {
#include "build/assets/native/gfx/D_803675C8_5079D8.dl.inc.c"
};

u8 D_803675D0_5079E0[1320] = {
#include "assets/app_level/native_hud/5079E0.png.bin.c"
};

Gfx D_80367AF8_507F08[1] = {
#include "build/assets/native/gfx/D_80367AF8_507F08.dl.inc.c"
};

u8 D_80367B00_507F10[512] = {
#include "assets/app_level/native_hud/507F10.png.bin.c"
};

Bitmap D_80367D00_508110[1] = {
    { 33, 40, 0, 0, D_803675D0_5079E0, 33, 0 },
};

Sprite D_80367D10_508120 = {
    0,
    0,
    33,
    33,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
    4660,
    255,
    255,
    255,
    255,
    0,
    256,
    (int*) D_80367B00_507F10,
    0,
    1,
    1,
    36,
    33,
    33,
    2,
    1,
    D_80367D00_508110,
    D_803AB400_54B810,
    NULL,
    0,
    0,
};

u8 D_80367D54_508164[4] = { 0 };

Gfx D_80367D58_508168[1] = {
#include "build/assets/native/gfx/D_80367D58_508168.dl.inc.c"
};

u8 D_80367D60_508170[80] = {
#include "assets/app_level/native_hud/508170.png.bin.c"
};

Bitmap D_80367DB0_5081C0[1] = {
    { 5, 8, 0, 0, D_80367D60_508170, 5, 0 },
};

Sprite D_80367DC0_5081D0 = {
    0,
    0,
    5,
    5,
    1.0f,
    1.0f,
    0,
    0,
    0x201,
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
    5,
    5,
    0,
    2,
    D_80367DB0_5081C0,
    D_803AB520_54B930,
    NULL,
    0,
    0,
};

u8 D_80367E04_508214[4] = { 0 };

Gfx D_80367E08_508218[1] = {
#include "build/assets/native/gfx/D_80367E08_508218.dl.inc.c"
};

u8 D_80367E10_508220[16] = {
#include "assets/app_level/native_hud/508220.png.bin.c"
};

Gfx D_80367E20_508230[1] = {
#include "build/assets/native/gfx/D_80367E20_508230.dl.inc.c"
};

u8 D_80367E28_508238[512] = {
#include "assets/app_level/native_hud/508238.png.bin.c"
};

Bitmap D_80368028_508438[1] = {
    { 2, 8, 0, 0, D_80367E10_508220, 2, 0 },
};

Sprite D_80368038_508448 = {
    0,
    0,
    2,
    2,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
    4660,
    255,
    255,
    255,
    255,
    0,
    256,
    (int*) D_80367E28_508238,
    0,
    1,
    1,
    36,
    2,
    2,
    2,
    1,
    D_80368028_508438,
    D_803AB640_54BA50,
    NULL,
    0,
    0,
};

u8 D_8036807C_50848C[4] = { 0 };

Gfx D_80368080_508490[1] = {
#include "build/assets/native/gfx/D_80368080_508490.dl.inc.c"
};

u8 D_80368088_508498[2048] = {
#include "assets/app_level/native_hud/508498.png.bin.c"
};

Gfx D_80368888_508C98[1] = {
#include "build/assets/native/gfx/D_80368888_508C98.dl.inc.c"
};

u8 D_80368890_508CA0[2048] = {
#include "assets/app_level/native_hud/508CA0.png.bin.c"
};

Gfx D_80369090_5094A0[1] = {
#include "build/assets/native/gfx/D_80369090_5094A0.dl.inc.c"
};

u8 D_80369098_5094A8[2048] = {
#include "assets/app_level/native_hud/5094A8.png.bin.c"
};

Gfx D_80369898_509CA8[1] = {
#include "build/assets/native/gfx/D_80369898_509CA8.dl.inc.c"
};

u8 D_803698A0_509CB0[2048] = {
#include "assets/app_level/native_hud/509CB0.png.bin.c"
};

Gfx D_8036A0A0_50A4B0[1] = {
#include "build/assets/native/gfx/D_8036A0A0_50A4B0.dl.inc.c"
};

u8 D_8036A0A8_50A4B8[2048] = {
#include "assets/app_level/native_hud/50A4B8.png.bin.c"
};

Gfx D_8036A8A8_50ACB8[1] = {
#include "build/assets/native/gfx/D_8036A8A8_50ACB8.dl.inc.c"
};

u8 D_8036A8B0_50ACC0[2048] = {
#include "assets/app_level/native_hud/50ACC0.png.bin.c"
};

Gfx D_8036B0B0_50B4C0[1] = {
#include "build/assets/native/gfx/D_8036B0B0_50B4C0.dl.inc.c"
};

u8 D_8036B0B8_50B4C8[2048] = {
#include "assets/app_level/native_hud/50B4C8.png.bin.c"
};

Gfx D_8036B8B8_50BCC8[1] = {
#include "build/assets/native/gfx/D_8036B8B8_50BCC8.dl.inc.c"
};

u8 D_8036B8C0_50BCD0[2048] = {
#include "assets/app_level/native_hud/50BCD0.png.bin.c"
};

Gfx D_8036C0C0_50C4D0[1] = {
#include "build/assets/native/gfx/D_8036C0C0_50C4D0.dl.inc.c"
};

u8 D_8036C0C8_50C4D8[2048] = {
#include "assets/app_level/native_hud/50C4D8.png.bin.c"
};

Gfx D_8036C8C8_50CCD8[1] = {
#include "build/assets/native/gfx/D_8036C8C8_50CCD8.dl.inc.c"
};

u8 D_8036C8D0_50CCE0[2048] = {
#include "assets/app_level/native_hud/50CCE0.png.bin.c"
};

Gfx D_8036D0D0_50D4E0[1] = {
#include "build/assets/native/gfx/D_8036D0D0_50D4E0.dl.inc.c"
};

u8 D_8036D0D8_50D4E8[1344] = {
#include "assets/app_level/native_hud/50D4E8.png.bin.c"
};

Gfx D_8036D618_50DA28[1] = {
#include "build/assets/native/gfx/D_8036D618_50DA28.dl.inc.c"
};

u8 D_8036D620_50DA30[1344] = {
#include "assets/app_level/native_hud/50DA30.png.bin.c"
};

Gfx D_8036DB60_50DF70[1] = {
#include "build/assets/native/gfx/D_8036DB60_50DF70.dl.inc.c"
};

u8 D_8036DB68_50DF78[1344] = {
#include "assets/app_level/native_hud/50DF78.png.bin.c"
};

Gfx D_8036E0A8_50E4B8[1] = {
#include "build/assets/native/gfx/D_8036E0A8_50E4B8.dl.inc.c"
};

u8 D_8036E0B0_50E4C0[1344] = {
#include "assets/app_level/native_hud/50E4C0.png.bin.c"
};

Gfx D_8036E5F0_50EA00[1] = {
#include "build/assets/native/gfx/D_8036E5F0_50EA00.dl.inc.c"
};

u8 D_8036E5F8_50EA08[1344] = {
#include "assets/app_level/native_hud/50EA08.png.bin.c"
};

Gfx D_8036EB38_50EF48[1] = {
#include "build/assets/native/gfx/D_8036EB38_50EF48.dl.inc.c"
};

u8 D_8036EB40_50EF50[1344] = {
#include "assets/app_level/native_hud/50EF50.png.bin.c"
};

Gfx D_8036F080_50F490[1] = {
#include "build/assets/native/gfx/D_8036F080_50F490.dl.inc.c"
};

u8 D_8036F088_50F498[1344] = {
#include "assets/app_level/native_hud/50F498.png.bin.c"
};

Gfx D_8036F5C8_50F9D8[1] = {
#include "build/assets/native/gfx/D_8036F5C8_50F9D8.dl.inc.c"
};

u8 D_8036F5D0_50F9E0[1344] = {
#include "assets/app_level/native_hud/50F9E0.png.bin.c"
};

Gfx D_8036FB10_50FF20[1] = {
#include "build/assets/native/gfx/D_8036FB10_50FF20.dl.inc.c"
};

u8 D_8036FB18_50FF28[1344] = {
#include "assets/app_level/native_hud/50FF28.png.bin.c"
};

Gfx D_80370058_510468[1] = {
#include "build/assets/native/gfx/D_80370058_510468.dl.inc.c"
};

u8 D_80370060_510470[1344] = {
#include "assets/app_level/native_hud/510470.png.bin.c"
};

Bitmap D_803705A0_5109B0[20] = {
    { 32, 32, 0, 0, D_80368088_508498, 32, 0 },
    { 32, 32, 0, 0, D_80368890_508CA0, 32, 0 },
    { 32, 32, 0, 0, D_80369098_5094A8, 32, 0 },
    { 32, 32, 0, 0, D_803698A0_509CB0, 32, 0 },
    { 32, 32, 0, 0, D_8036A0A8_50A4B8, 32, 0 },
    { 32, 32, 0, 0, D_8036A8B0_50ACC0, 32, 0 },
    { 32, 32, 0, 0, D_8036B0B8_50B4C8, 32, 0 },
    { 32, 32, 0, 0, D_8036B8C0_50BCD0, 32, 0 },
    { 32, 32, 0, 0, D_8036C0C8_50C4D8, 32, 0 },
    { 32, 32, 0, 0, D_8036C8D0_50CCE0, 32, 0 },
    { 32, 32, 0, 0, D_8036D0D8_50D4E8, 21, 0 },
    { 32, 32, 0, 0, D_8036D620_50DA30, 21, 0 },
    { 32, 32, 0, 0, D_8036DB68_50DF78, 21, 0 },
    { 32, 32, 0, 0, D_8036E0B0_50E4C0, 21, 0 },
    { 32, 32, 0, 0, D_8036E5F8_50EA08, 21, 0 },
    { 32, 32, 0, 0, D_8036EB40_50EF50, 21, 0 },
    { 32, 32, 0, 0, D_8036F088_50F498, 21, 0 },
    { 32, 32, 0, 0, D_8036F5D0_50F9E0, 21, 0 },
    { 32, 32, 0, 0, D_8036FB18_50FF28, 21, 0 },
    { 32, 32, 0, 0, D_80370060_510470, 21, 0 },
};

Sprite D_803706E0_510AF0 = {
    0,
    0,
    320,
    53,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
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
    32,
    32,
    0,
    2,
    D_803705A0_5109B0,
    D_803AB760_54BB70,
    NULL,
    0,
    0,
};

u8 D_80370724_510B34[4] = { 0 };

Gfx D_80370728_510B38[1] = {
#include "build/assets/native/gfx/D_80370728_510B38.dl.inc.c"
};

u8 D_80370730_510B40[2048] = {
#include "assets/app_level/native_hud/510B40.png.bin.c"
};

Gfx D_80370F30_511340[1] = {
#include "build/assets/native/gfx/D_80370F30_511340.dl.inc.c"
};

u8 D_80370F38_511348[2048] = {
#include "assets/app_level/native_hud/511348.png.bin.c"
};

Gfx D_80371738_511B48[1] = {
#include "build/assets/native/gfx/D_80371738_511B48.dl.inc.c"
};

u8 D_80371740_511B50[2048] = {
#include "assets/app_level/native_hud/511B50.png.bin.c"
};

Gfx D_80371F40_512350[1] = {
#include "build/assets/native/gfx/D_80371F40_512350.dl.inc.c"
};

u8 D_80371F48_512358[2048] = {
#include "assets/app_level/native_hud/512358.png.bin.c"
};

Gfx D_80372748_512B58[1] = {
#include "build/assets/native/gfx/D_80372748_512B58.dl.inc.c"
};

u8 D_80372750_512B60[2048] = {
#include "assets/app_level/native_hud/512B60.png.bin.c"
};

Gfx D_80372F50_513360[1] = {
#include "build/assets/native/gfx/D_80372F50_513360.dl.inc.c"
};

u8 D_80372F58_513368[2048] = {
#include "assets/app_level/native_hud/513368.png.bin.c"
};

Gfx D_80373758_513B68[1] = {
#include "build/assets/native/gfx/D_80373758_513B68.dl.inc.c"
};

u8 D_80373760_513B70[2048] = {
#include "assets/app_level/native_hud/513B70.png.bin.c"
};

Gfx D_80373F60_514370[1] = {
#include "build/assets/native/gfx/D_80373F60_514370.dl.inc.c"
};

u8 D_80373F68_514378[2048] = {
#include "assets/app_level/native_hud/514378.png.bin.c"
};

Gfx D_80374768_514B78[1] = {
#include "build/assets/native/gfx/D_80374768_514B78.dl.inc.c"
};

u8 D_80374770_514B80[2048] = {
#include "assets/app_level/native_hud/514B80.png.bin.c"
};

Gfx D_80374F70_515380[1] = {
#include "build/assets/native/gfx/D_80374F70_515380.dl.inc.c"
};

u8 D_80374F78_515388[2048] = {
#include "assets/app_level/native_hud/515388.png.bin.c"
};

Gfx D_80375778_515B88[1] = {
#include "build/assets/native/gfx/D_80375778_515B88.dl.inc.c"
};

u8 D_80375780_515B90[1344] = {
#include "assets/app_level/native_hud/515B90.png.bin.c"
};

Gfx D_80375CC0_5160D0[1] = {
#include "build/assets/native/gfx/D_80375CC0_5160D0.dl.inc.c"
};

u8 D_80375CC8_5160D8[1344] = {
#include "assets/app_level/native_hud/5160D8.png.bin.c"
};

Gfx D_80376208_516618[1] = {
#include "build/assets/native/gfx/D_80376208_516618.dl.inc.c"
};

u8 D_80376210_516620[1344] = {
#include "assets/app_level/native_hud/516620.png.bin.c"
};

Gfx D_80376750_516B60[1] = {
#include "build/assets/native/gfx/D_80376750_516B60.dl.inc.c"
};

u8 D_80376758_516B68[1344] = {
#include "assets/app_level/native_hud/516B68.png.bin.c"
};

Gfx D_80376C98_5170A8[1] = {
#include "build/assets/native/gfx/D_80376C98_5170A8.dl.inc.c"
};

u8 D_80376CA0_5170B0[1344] = {
#include "assets/app_level/native_hud/5170B0.png.bin.c"
};

Gfx D_803771E0_5175F0[1] = {
#include "build/assets/native/gfx/D_803771E0_5175F0.dl.inc.c"
};

u8 D_803771E8_5175F8[1344] = {
#include "assets/app_level/native_hud/5175F8.png.bin.c"
};

Gfx D_80377728_517B38[1] = {
#include "build/assets/native/gfx/D_80377728_517B38.dl.inc.c"
};

u8 D_80377730_517B40[1344] = {
#include "assets/app_level/native_hud/517B40.png.bin.c"
};

Gfx D_80377C70_518080[1] = {
#include "build/assets/native/gfx/D_80377C70_518080.dl.inc.c"
};

u8 D_80377C78_518088[1344] = {
#include "assets/app_level/native_hud/518088.png.bin.c"
};

Gfx D_803781B8_5185C8[1] = {
#include "build/assets/native/gfx/D_803781B8_5185C8.dl.inc.c"
};

u8 D_803781C0_5185D0[1344] = {
#include "assets/app_level/native_hud/5185D0.png.bin.c"
};

Gfx D_80378700_518B10[1] = {
#include "build/assets/native/gfx/D_80378700_518B10.dl.inc.c"
};

u8 D_80378708_518B18[1344] = {
#include "assets/app_level/native_hud/518B18.png.bin.c"
};

Bitmap D_80378C48_519058[20] = {
    { 32, 32, 0, 0, D_80370730_510B40, 32, 0 },
    { 32, 32, 0, 0, D_80370F38_511348, 32, 0 },
    { 32, 32, 0, 0, D_80371740_511B50, 32, 0 },
    { 32, 32, 0, 0, D_80371F48_512358, 32, 0 },
    { 32, 32, 0, 0, D_80372750_512B60, 32, 0 },
    { 32, 32, 0, 0, D_80372F58_513368, 32, 0 },
    { 32, 32, 0, 0, D_80373760_513B70, 32, 0 },
    { 32, 32, 0, 0, D_80373F68_514378, 32, 0 },
    { 32, 32, 0, 0, D_80374770_514B80, 32, 0 },
    { 32, 32, 0, 0, D_80374F78_515388, 32, 0 },
    { 32, 32, 0, 0, D_80375780_515B90, 21, 0 },
    { 32, 32, 0, 0, D_80375CC8_5160D8, 21, 0 },
    { 32, 32, 0, 0, D_80376210_516620, 21, 0 },
    { 32, 32, 0, 0, D_80376758_516B68, 21, 0 },
    { 32, 32, 0, 0, D_80376CA0_5170B0, 21, 0 },
    { 32, 32, 0, 0, D_803771E8_5175F8, 21, 0 },
    { 32, 32, 0, 0, D_80377730_517B40, 21, 0 },
    { 32, 32, 0, 0, D_80377C78_518088, 21, 0 },
    { 32, 32, 0, 0, D_803781C0_5185D0, 21, 0 },
    { 32, 32, 0, 0, D_80378708_518B18, 21, 0 },
};

Sprite D_80378D88_519198 = {
    0,
    0,
    320,
    53,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
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
    32,
    32,
    0,
    2,
    D_80378C48_519058,
    D_803ABFA0_54C3B0,
    NULL,
    0,
    0,
};

u8 D_80378DCC_5191DC[4] = { 0 };

Gfx D_80378DD0_5191E0[1] = {
#include "build/assets/native/gfx/D_80378DD0_5191E0.dl.inc.c"
};

u8 D_80378DD8_5191E8[240] = {
#include "assets/app_level/native_hud/5191E8.png.bin.c"
};

Bitmap D_80378EC8_5192D8[1] = {
    { 10, 12, 0, 0, D_80378DD8_5191E8, 10, 0 },
};

Sprite D_80378ED8_5192E8 = {
    0,
    0,
    10,
    10,
    1.0f,
    1.0f,
    0,
    0,
    0x259,
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
    10,
    10,
    0,
    2,
    D_80378EC8_5192D8,
    D_803AC7E0_54CBF0,
    NULL,
    0,
    0,
};

u8 D_80378F1C_51932C[4] = { 0 };

Gfx D_80378F20_519330[1] = {
#include "build/assets/native/gfx/D_80378F20_519330.dl.inc.c"
};

u8 D_80378F28_519338[512] = {
#include "assets/app_level/native_hud/519338.png.bin.c"
};

Gfx D_80379128_519538[1] = {
#include "build/assets/native/gfx/D_80379128_519538.dl.inc.c"
};

u8 D_80379130_519540[512] = {
#include "assets/app_level/native_hud/519540.png.bin.c"
};

Gfx D_80379330_519740[1] = {
#include "build/assets/native/gfx/D_80379330_519740.dl.inc.c"
};

u8 D_80379338_519748[512] = {
#include "assets/app_level/native_hud/519748.png.bin.c"
};

Gfx D_80379538_519948[1] = {
#include "build/assets/native/gfx/D_80379538_519948.dl.inc.c"
};

u8 D_80379540_519950[512] = {
#include "assets/app_level/native_hud/519950.png.bin.c"
};

Gfx D_80379740_519B50[1] = {
#include "build/assets/native/gfx/D_80379740_519B50.dl.inc.c"
};

u8 D_80379748_519B58[512] = {
#include "assets/app_level/native_hud/519B58.png.bin.c"
};

Gfx D_80379948_519D58[1] = {
#include "build/assets/native/gfx/D_80379948_519D58.dl.inc.c"
};

u8 D_80379950_519D60[512] = {
#include "assets/app_level/native_hud/519D60.png.bin.c"
};

Gfx D_80379B50_519F60[1] = {
#include "build/assets/native/gfx/D_80379B50_519F60.dl.inc.c"
};

u8 D_80379B58_519F68[256] = {
#include "assets/app_level/native_hud/519F68.png.bin.c"
};

Gfx D_80379C58_51A068[1] = {
#include "build/assets/native/gfx/D_80379C58_51A068.dl.inc.c"
};

u8 D_80379C60_51A070[480] = {
#include "assets/app_level/native_hud/51A070.png.bin.c"
};

Gfx D_80379E40_51A250[1] = {
#include "build/assets/native/gfx/D_80379E40_51A250.dl.inc.c"
};

u8 D_80379E48_51A258[480] = {
#include "assets/app_level/native_hud/51A258.png.bin.c"
};

Gfx D_8037A028_51A438[1] = {
#include "build/assets/native/gfx/D_8037A028_51A438.dl.inc.c"
};

u8 D_8037A030_51A440[480] = {
#include "assets/app_level/native_hud/51A440.png.bin.c"
};

Gfx D_8037A210_51A620[1] = {
#include "build/assets/native/gfx/D_8037A210_51A620.dl.inc.c"
};

u8 D_8037A218_51A628[480] = {
#include "assets/app_level/native_hud/51A628.png.bin.c"
};

Gfx D_8037A3F8_51A808[1] = {
#include "build/assets/native/gfx/D_8037A3F8_51A808.dl.inc.c"
};

u8 D_8037A400_51A810[480] = {
#include "assets/app_level/native_hud/51A810.png.bin.c"
};

Gfx D_8037A5E0_51A9F0[1] = {
#include "build/assets/native/gfx/D_8037A5E0_51A9F0.dl.inc.c"
};

u8 D_8037A5E8_51A9F8[480] = {
#include "assets/app_level/native_hud/51A9F8.png.bin.c"
};

Gfx D_8037A7C8_51ABD8[1] = {
#include "build/assets/native/gfx/D_8037A7C8_51ABD8.dl.inc.c"
};

u8 D_8037A7D0_51ABE0[240] = {
#include "assets/app_level/native_hud/51ABE0.png.bin.c"
};

Bitmap D_8037A8C0_51ACD0[14] = {
    { 16, 16, 0, 0, D_80378F28_519338, 16, 0 },
    { 16, 16, 0, 0, D_80379130_519540, 16, 0 },
    { 16, 16, 0, 0, D_80379338_519748, 16, 0 },
    { 16, 16, 0, 0, D_80379540_519950, 16, 0 },
    { 16, 16, 0, 0, D_80379748_519B58, 16, 0 },
    { 16, 16, 0, 0, D_80379950_519D60, 16, 0 },
    { 7, 8, 0, 0, D_80379B58_519F68, 16, 0 },
    { 16, 16, 0, 0, D_80379C60_51A070, 15, 0 },
    { 16, 16, 0, 0, D_80379E48_51A258, 15, 0 },
    { 16, 16, 0, 0, D_8037A030_51A440, 15, 0 },
    { 16, 16, 0, 0, D_8037A218_51A628, 15, 0 },
    { 16, 16, 0, 0, D_8037A400_51A810, 15, 0 },
    { 16, 16, 0, 0, D_8037A5E8_51A9F8, 15, 0 },
    { 7, 8, 0, 0, D_8037A7D0_51ABE0, 15, 0 },
};

Sprite D_8037A9A0_51ADB0 = {
    0,
    0,
    103,
    31,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
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
    16,
    16,
    0,
    2,
    D_8037A8C0_51ACD0,
    D_803AC900_54CD10,
    NULL,
    0,
    0,
};

u8 D_8037A9E4_51ADF4[4] = { 0 };

Gfx D_8037A9E8_51ADF8[1] = {
#include "build/assets/native/gfx/D_8037A9E8_51ADF8.dl.inc.c"
};

u8 D_8037A9F0_51AE00[512] = {
#include "assets/app_level/native_hud/51AE00.png.bin.c"
};

Gfx D_8037ABF0_51B000[1] = {
#include "build/assets/native/gfx/D_8037ABF0_51B000.dl.inc.c"
};

u8 D_8037ABF8_51B008[512] = {
#include "assets/app_level/native_hud/51B008.png.bin.c"
};

Gfx D_8037ADF8_51B208[1] = {
#include "build/assets/native/gfx/D_8037ADF8_51B208.dl.inc.c"
};

u8 D_8037AE00_51B210[512] = {
#include "assets/app_level/native_hud/51B210.png.bin.c"
};

Gfx D_8037B000_51B410[1] = {
#include "build/assets/native/gfx/D_8037B000_51B410.dl.inc.c"
};

u8 D_8037B008_51B418[512] = {
#include "assets/app_level/native_hud/51B418.png.bin.c"
};

Gfx D_8037B208_51B618[1] = {
#include "build/assets/native/gfx/D_8037B208_51B618.dl.inc.c"
};

u8 D_8037B210_51B620[512] = {
#include "assets/app_level/native_hud/51B620.png.bin.c"
};

Gfx D_8037B410_51B820[1] = {
#include "build/assets/native/gfx/D_8037B410_51B820.dl.inc.c"
};

u8 D_8037B418_51B828[512] = {
#include "assets/app_level/native_hud/51B828.png.bin.c"
};

Gfx D_8037B618_51BA28[1] = {
#include "build/assets/native/gfx/D_8037B618_51BA28.dl.inc.c"
};

u8 D_8037B620_51BA30[256] = {
#include "assets/app_level/native_hud/51BA30.png.bin.c"
};

Gfx D_8037B720_51BB30[1] = {
#include "build/assets/native/gfx/D_8037B720_51BB30.dl.inc.c"
};

u8 D_8037B728_51BB38[480] = {
#include "assets/app_level/native_hud/51BB38.png.bin.c"
};

Gfx D_8037B908_51BD18[1] = {
#include "build/assets/native/gfx/D_8037B908_51BD18.dl.inc.c"
};

u8 D_8037B910_51BD20[480] = {
#include "assets/app_level/native_hud/51BD20.png.bin.c"
};

Gfx D_8037BAF0_51BF00[1] = {
#include "build/assets/native/gfx/D_8037BAF0_51BF00.dl.inc.c"
};

u8 D_8037BAF8_51BF08[480] = {
#include "assets/app_level/native_hud/51BF08.png.bin.c"
};

Gfx D_8037BCD8_51C0E8[1] = {
#include "build/assets/native/gfx/D_8037BCD8_51C0E8.dl.inc.c"
};

u8 D_8037BCE0_51C0F0[480] = {
#include "assets/app_level/native_hud/51C0F0.png.bin.c"
};

Gfx D_8037BEC0_51C2D0[1] = {
#include "build/assets/native/gfx/D_8037BEC0_51C2D0.dl.inc.c"
};

u8 D_8037BEC8_51C2D8[480] = {
#include "assets/app_level/native_hud/51C2D8.png.bin.c"
};

Gfx D_8037C0A8_51C4B8[1] = {
#include "build/assets/native/gfx/D_8037C0A8_51C4B8.dl.inc.c"
};

u8 D_8037C0B0_51C4C0[480] = {
#include "assets/app_level/native_hud/51C4C0.png.bin.c"
};

Gfx D_8037C290_51C6A0[1] = {
#include "build/assets/native/gfx/D_8037C290_51C6A0.dl.inc.c"
};

u8 D_8037C298_51C6A8[240] = {
#include "assets/app_level/native_hud/51C6A8.png.bin.c"
};

Bitmap D_8037C388_51C798[14] = {
    { 16, 16, 0, 0, D_8037A9F0_51AE00, 16, 0 },
    { 16, 16, 0, 0, D_8037ABF8_51B008, 16, 0 },
    { 16, 16, 0, 0, D_8037AE00_51B210, 16, 0 },
    { 16, 16, 0, 0, D_8037B008_51B418, 16, 0 },
    { 16, 16, 0, 0, D_8037B210_51B620, 16, 0 },
    { 16, 16, 0, 0, D_8037B418_51B828, 16, 0 },
    { 7, 8, 0, 0, D_8037B620_51BA30, 16, 0 },
    { 16, 16, 0, 0, D_8037B728_51BB38, 15, 0 },
    { 16, 16, 0, 0, D_8037B910_51BD20, 15, 0 },
    { 16, 16, 0, 0, D_8037BAF8_51BF08, 15, 0 },
    { 16, 16, 0, 0, D_8037BCE0_51C0F0, 15, 0 },
    { 16, 16, 0, 0, D_8037BEC8_51C2D8, 15, 0 },
    { 16, 16, 0, 0, D_8037C0B0_51C4C0, 15, 0 },
    { 7, 8, 0, 0, D_8037C298_51C6A8, 15, 0 },
};

Sprite D_8037C468_51C878 = {
    0,
    0,
    103,
    31,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
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
    16,
    16,
    0,
    2,
    D_8037C388_51C798,
    D_803ACF00_54D310,
    NULL,
    0,
    0,
};

u8 D_8037C4AC_51C8BC[4] = { 0 };

Gfx D_8037C4B0_51C8C0[1] = {
#include "build/assets/native/gfx/D_8037C4B0_51C8C0.dl.inc.c"
};

u8 D_8037C4B8_51C8C8[1216] = {
#include "assets/app_level/native_hud/51C8C8.png.bin.c"
};

Gfx D_8037C978_51CD88[1] = {
#include "build/assets/native/gfx/D_8037C978_51CD88.dl.inc.c"
};

u8 D_8037C980_51CD90[1216] = {
#include "assets/app_level/native_hud/51CD90.png.bin.c"
};

Gfx D_8037CE40_51D250[1] = {
#include "build/assets/native/gfx/D_8037CE40_51D250.dl.inc.c"
};

u8 D_8037CE48_51D258[1064] = {
#include "assets/app_level/native_hud/51D258.png.bin.c"
};

Bitmap D_8037D270_51D680[3] = {
    { 32, 32, 0, 0, D_8037C4B8_51C8C8, 19, 0 },
    { 32, 32, 0, 0, D_8037C980_51CD90, 19, 0 },
    { 25, 28, 0, 0, D_8037CE48_51D258, 19, 0 },
};

Sprite D_8037D2A0_51D6B0 = {
    0,
    0,
    89,
    19,
    1.0f,
    1.0f,
    0,
    0,
    0x201,
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
    3,
    60,
    19,
    19,
    0,
    2,
    D_8037D270_51D680,
    D_803AD500_54D910,
    NULL,
    0,
    0,
};

u8 D_8037D2E4_51D6F4[4] = { 0 };

Gfx D_8037D2E8_51D6F8[1] = {
#include "build/assets/native/gfx/D_8037D2E8_51D6F8.dl.inc.c"
};

u8 D_8037D2F0_51D700[1216] = {
#include "assets/app_level/native_hud/51D700.png.bin.c"
};

Gfx D_8037D7B0_51DBC0[1] = {
#include "build/assets/native/gfx/D_8037D7B0_51DBC0.dl.inc.c"
};

u8 D_8037D7B8_51DBC8[1216] = {
#include "assets/app_level/native_hud/51DBC8.png.bin.c"
};

Gfx D_8037DC78_51E088[1] = {
#include "build/assets/native/gfx/D_8037DC78_51E088.dl.inc.c"
};

u8 D_8037DC80_51E090[1064] = {
#include "assets/app_level/native_hud/51E090.png.bin.c"
};

Bitmap D_8037E0A8_51E4B8[3] = {
    { 32, 32, 0, 0, D_8037D2F0_51D700, 19, 0 },
    { 32, 32, 0, 0, D_8037D7B8_51DBC8, 19, 0 },
    { 25, 28, 0, 0, D_8037DC80_51E090, 19, 0 },
};

Sprite D_8037E0D8_51E4E8 = {
    0,
    0,
    89,
    19,
    1.0f,
    1.0f,
    0,
    0,
    0x201,
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
    3,
    60,
    19,
    19,
    0,
    2,
    D_8037E0A8_51E4B8,
    D_803AD6E0_54DAF0,
    NULL,
    0,
    0,
};

u8 D_8037E11C_51E52C[4] = { 0 };

Gfx D_8037E120_51E530[1] = {
#include "build/assets/native/gfx/D_8037E120_51E530.dl.inc.c"
};

u8 D_8037E128_51E538[1216] = {
#include "assets/app_level/native_hud/51E538.png.bin.c"
};

Gfx D_8037E5E8_51E9F8[1] = {
#include "build/assets/native/gfx/D_8037E5E8_51E9F8.dl.inc.c"
};

u8 D_8037E5F0_51EA00[1216] = {
#include "assets/app_level/native_hud/51EA00.png.bin.c"
};

Gfx D_8037EAB0_51EEC0[1] = {
#include "build/assets/native/gfx/D_8037EAB0_51EEC0.dl.inc.c"
};

u8 D_8037EAB8_51EEC8[1064] = {
#include "assets/app_level/native_hud/51EEC8.png.bin.c"
};

Bitmap D_8037EEE0_51F2F0[3] = {
    { 32, 32, 0, 0, D_8037E128_51E538, 19, 0 },
    { 32, 32, 0, 0, D_8037E5F0_51EA00, 19, 0 },
    { 25, 28, 0, 0, D_8037EAB8_51EEC8, 19, 0 },
};

Sprite D_8037EF10_51F320 = {
    0,
    0,
    89,
    19,
    1.0f,
    1.0f,
    0,
    0,
    0x201,
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
    3,
    60,
    19,
    19,
    0,
    2,
    D_8037EEE0_51F2F0,
    D_803AD8C0_54DCD0,
    NULL,
    0,
    0,
};

u8 D_8037EF54_51F364[4] = { 0 };

Gfx D_8037EF58_51F368[1] = {
#include "build/assets/native/gfx/D_8037EF58_51F368.dl.inc.c"
};

u8 D_8037EF60_51F370[1216] = {
#include "assets/app_level/native_hud/51F370.png.bin.c"
};

Gfx D_8037F420_51F830[1] = {
#include "build/assets/native/gfx/D_8037F420_51F830.dl.inc.c"
};

u8 D_8037F428_51F838[1216] = {
#include "assets/app_level/native_hud/51F838.png.bin.c"
};

Gfx D_8037F8E8_51FCF8[1] = {
#include "build/assets/native/gfx/D_8037F8E8_51FCF8.dl.inc.c"
};

u8 D_8037F8F0_51FD00[1064] = {
#include "assets/app_level/native_hud/51FD00.png.bin.c"
};

Bitmap D_8037FD18_520128[3] = {
    { 32, 32, 0, 0, D_8037EF60_51F370, 19, 0 },
    { 32, 32, 0, 0, D_8037F428_51F838, 19, 0 },
    { 25, 28, 0, 0, D_8037F8F0_51FD00, 19, 0 },
};

Sprite D_8037FD48_520158 = {
    0,
    0,
    89,
    19,
    1.0f,
    1.0f,
    0,
    0,
    0x201,
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
    3,
    60,
    19,
    19,
    0,
    2,
    D_8037FD18_520128,
    D_803ADAA0_54DEB0,
    NULL,
    0,
    0,
};

u8 D_8037FD8C_52019C[4] = { 0 };

Gfx D_8037FD90_5201A0[1] = {
#include "build/assets/native/gfx/D_8037FD90_5201A0.dl.inc.c"
};

u8 D_8037FD98_5201A8[1216] = {
#include "assets/app_level/native_hud/5201A8.png.bin.c"
};

Gfx D_80380258_520668[1] = {
#include "build/assets/native/gfx/D_80380258_520668.dl.inc.c"
};

u8 D_80380260_520670[1216] = {
#include "assets/app_level/native_hud/520670.png.bin.c"
};

Gfx D_80380720_520B30[1] = {
#include "build/assets/native/gfx/D_80380720_520B30.dl.inc.c"
};

u8 D_80380728_520B38[1064] = {
#include "assets/app_level/native_hud/520B38.png.bin.c"
};

Bitmap D_80380B50_520F60[3] = {
    { 32, 32, 0, 0, D_8037FD98_5201A8, 19, 0 },
    { 32, 32, 0, 0, D_80380260_520670, 19, 0 },
    { 25, 28, 0, 0, D_80380728_520B38, 19, 0 },
};

Sprite D_80380B80_520F90 = {
    0,
    0,
    89,
    19,
    1.0f,
    1.0f,
    0,
    0,
    0x201,
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
    3,
    60,
    19,
    19,
    0,
    2,
    D_80380B50_520F60,
    D_803ADC80_54E090,
    NULL,
    0,
    0,
};

u8 D_80380BC4_520FD4[4] = { 0 };

Gfx D_80380BC8_520FD8[1] = {
#include "build/assets/native/gfx/D_80380BC8_520FD8.dl.inc.c"
};

u8 D_80380BD0_520FE0[1216] = {
#include "assets/app_level/native_hud/520FE0.png.bin.c"
};

Gfx D_80381090_5214A0[1] = {
#include "build/assets/native/gfx/D_80381090_5214A0.dl.inc.c"
};

u8 D_80381098_5214A8[1216] = {
#include "assets/app_level/native_hud/5214A8.png.bin.c"
};

Gfx D_80381558_521968[1] = {
#include "build/assets/native/gfx/D_80381558_521968.dl.inc.c"
};

u8 D_80381560_521970[1064] = {
#include "assets/app_level/native_hud/521970.png.bin.c"
};

Bitmap D_80381988_521D98[3] = {
    { 32, 32, 0, 0, D_80380BD0_520FE0, 19, 0 },
    { 32, 32, 0, 0, D_80381098_5214A8, 19, 0 },
    { 25, 28, 0, 0, D_80381560_521970, 19, 0 },
};

Sprite D_803819B8_521DC8 = {
    0,
    0,
    89,
    19,
    1.0f,
    1.0f,
    0,
    0,
    0x201,
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
    3,
    60,
    19,
    19,
    0,
    2,
    D_80381988_521D98,
    D_803ADE60_54E270,
    NULL,
    0,
    0,
};

u8 D_803819FC_521E0C[4] = { 0 };

Gfx D_80381A00_521E10[1] = {
#include "build/assets/native/gfx/D_80381A00_521E10.dl.inc.c"
};

u8 D_80381A08_521E18[320] = {
#include "assets/app_level/native_hud/521E18.png.bin.c"
};

Bitmap D_80381B48_521F58[1] = {
    { 20, 20, 0, 0, D_80381A08_521E18, 8, 0 },
};

Sprite D_80381B58_521F68 = {
    0,
    0,
    20,
    8,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
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
    0,
    2,
    D_80381B48_521F58,
    D_803AE040_54E450,
    NULL,
    0,
    0,
};

u8 D_80381B9C_521FAC[4] = { 0 };

Gfx D_80381BA0_521FB0[1] = {
#include "build/assets/native/gfx/D_80381BA0_521FB0.dl.inc.c"
};

u8 D_80381BA8_521FB8[800] = {
#include "assets/app_level/native_hud/521FB8.png.bin.c"
};

Gfx D_80381EC8_5222D8[1] = {
#include "build/assets/native/gfx/D_80381EC8_5222D8.dl.inc.c"
};

u8 D_80381ED0_5222E0[800] = {
#include "assets/app_level/native_hud/5222E0.png.bin.c"
};

Gfx D_803821F0_522600[1] = {
#include "build/assets/native/gfx/D_803821F0_522600.dl.inc.c"
};

u8 D_803821F8_522608[800] = {
#include "assets/app_level/native_hud/522608.png.bin.c"
};

Gfx D_80382518_522928[1] = {
#include "build/assets/native/gfx/D_80382518_522928.dl.inc.c"
};

u8 D_80382520_522930[800] = {
#include "assets/app_level/native_hud/522930.png.bin.c"
};

Gfx D_80382840_522C50[1] = {
#include "build/assets/native/gfx/D_80382840_522C50.dl.inc.c"
};

u8 D_80382848_522C58[800] = {
#include "assets/app_level/native_hud/522C58.png.bin.c"
};

Bitmap D_80382B68_522F78[5] = {
    { 20, 20, 0, 0, D_80381BA8_521FB8, 20, 0 },
    { 20, 20, 0, 0, D_80381ED0_5222E0, 20, 0 },
    { 20, 20, 0, 0, D_803821F8_522608, 20, 0 },
    { 20, 20, 0, 0, D_80382520_522930, 20, 0 },
    { 20, 20, 0, 0, D_80382848_522C58, 20, 0 },
};

Sprite D_80382BB8_522FC8 = {
    0,
    0,
    100,
    20,
    1.0f,
    1.0f,
    0,
    0,
    0x209,
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
    5,
    84,
    20,
    20,
    0,
    2,
    D_80382B68_522F78,
    D_803AE160_54E570,
    NULL,
    0,
    0,
};

s32 gDirectionIndex = 2;
