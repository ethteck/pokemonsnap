#include "common.h"
#include "ld_addrs.h"
#include "window/window.h"

typedef s32 (*ReportPhotoComparator)(const void*, const void*);

extern u8 D_801E3D30_9DA6A0[8];
extern u8 D_801E3D38_9DA6A8[512];
extern Bitmap D_801E3F38_9DA8A8[1];
extern Sprite D_801E3F48_9DA8B8;
extern u8 D_801E3F8C_9DA8FC[12];
extern u8 D_801E3F98_9DA908[3760];
extern u8 D_801E4E48_9DB7B8[8];
extern u8 D_801E4E50_9DB7C0[3760];
extern u8 D_801E5D00_9DC670[8];
extern u8 D_801E5D08_9DC678[3760];
extern u8 D_801E6BB8_9DD528[8];
extern u8 D_801E6BC0_9DD530[3760];
extern u8 D_801E7A70_9DE3E0[8];
extern u8 D_801E7A78_9DE3E8[3760];
extern u8 D_801E8928_9DF298[8];
extern u8 D_801E8930_9DF2A0[1504];
extern Bitmap D_801E8F10_9DF880[6];
extern Sprite D_801E8F70_9DF8E0;
extern u8 D_801E8FB4_9DF924[12];
extern u8 D_801E8FC0_9DF930[3952];
extern u8 D_801E9F30_9E08A0[8];
extern u8 D_801E9F38_9E08A8[3952];
extern u8 D_801EAEA8_9E1818[8];
extern u8 D_801EAEB0_9E1820[3952];
extern u8 D_801EBE20_9E2790[8];
extern u8 D_801EBE28_9E2798[3952];
extern u8 D_801ECD98_9E3708[8];
extern u8 D_801ECDA0_9E3710[3952];
extern Bitmap D_801EDD10_9E4680[5];
extern Sprite D_801EDD60_9E46D0;
extern u8 D_801EDDA4_9E4714[12];
extern u8 D_801EDDB0_9E4720[304];
extern Bitmap D_801EDEE0_9E4850[1];
extern Sprite D_801EDEF0_9E4860;
extern u8 D_801EDF34_9E48A4[12];
extern u8 D_801EDF40_9E48B0[512];
extern Bitmap D_801EE140_9E4AB0[1];
extern Sprite D_801EE150_9E4AC0;
extern u8 D_801EE194_9E4B04[12];
extern u8 D_801EE1A0_9E4B10[2880];
extern u8 D_801EECE0_9E5650[8];
extern u8 D_801EECE8_9E5658[2760];
extern Bitmap D_801EF7B0_9E6120[2];
extern Sprite D_801EF7D0_9E6140;
extern u8 D_801EF814_9E6184[12];
extern u8 D_801EF820_9E6190[2880];
extern u8 D_801F0360_9E6CD0[8];
extern u8 D_801F0368_9E6CD8[2760];
extern Bitmap D_801F0E30_9E77A0[2];
extern Sprite D_801F0E50_9E77C0;
extern u8 D_801F0E94_9E7804[12];
extern u8 D_801F0EA0_9E7810[3920];
extern u8 D_801F1DF0_9E8760[8];
extern u8 D_801F1DF8_9E8768[1120];
extern Bitmap D_801F2258_9E8BC8[2];
extern Sprite D_801F2278_9E8BE8;
extern u8 D_801F22BC_9E8C2C[12];
extern u8 D_801F22C8_9E8C38[3920];
extern u8 D_801F3218_9E9B88[8];
extern u8 D_801F3220_9E9B90[1120];
extern Bitmap D_801F3680_9E9FF0[2];
extern Sprite D_801F36A0_9EA010;
extern u8 D_801F36E4_9EA054[12];
extern u8 D_801F36F0_9EA060[352];
extern Bitmap D_801F3850_9EA1C0[1];
extern Sprite D_801F3860_9EA1D0;
extern u8 D_801F38A4_9EA214[12];
extern u8 D_801F38B0_9EA220[336];
extern Bitmap D_801F3A00_9EA370[1];
extern Sprite D_801F3A10_9EA380;
extern u8 D_801F3A54_9EA3C4[12];
extern u8 D_801F3A60_9EA3D0[288];
extern Bitmap D_801F3B80_9EA4F0[1];
extern Sprite D_801F3B90_9EA500;
extern u8 D_801F3BD4_9EA544[12];
extern u8 D_801F3BE0_9EA550[4048];
extern u8 D_801F4BB0_9EB520[8];
extern u8 D_801F4BB8_9EB528[368];
extern Bitmap D_801F4D28_9EB698[2];
extern Sprite D_801F4D48_9EB6B8;
extern u8 D_801F4D8C_9EB6FC[12];
extern u8 D_801F4D98_9EB708[888];
extern Bitmap D_801F5110_9EBA80[1];
extern Sprite D_801F5120_9EBA90;
extern u8 D_801F5164_9EBAD4[12];
extern u8 D_801F5170_9EBAE0[840];
extern Bitmap D_801F54B8_9EBE28[1];
extern Sprite D_801F54C8_9EBE38;
extern u8 D_801F550C_9EBE7C[12];
extern u8 D_801F5518_9EBE88[344];
extern Bitmap D_801F5670_9EBFE0[1];
extern Sprite D_801F5680_9EBFF0;
extern u8 D_801F56C4_9EC034[12];
extern u8 D_801F56D0_9EC040[208];
extern Bitmap D_801F57A0_9EC110[1];
extern Sprite D_801F57B0_9EC120;
extern u8 D_801F57F4_9EC164[12];
extern u8 D_801F5800_9EC170[4056];
extern Bitmap D_801F67D8_9ED148[1];
extern Sprite D_801F67E8_9ED158;
extern u8 D_801F682C_9ED19C[12];
extern u8 D_801F6838_9ED1A8[4056];
extern Bitmap D_801F7810_9EE180[1];
extern Sprite D_801F7820_9EE190;
extern u8 D_801F7864_9EE1D4[12];
extern u8 D_801F7870_9EE1E0[4056];
extern Bitmap D_801F8848_9EF1B8[1];
extern Sprite D_801F8858_9EF1C8;
extern u8 D_801F889C_9EF20C[12];
extern u8 D_801F88A8_9EF218[4056];
extern Bitmap D_801F9880_9F01F0[1];
extern Sprite D_801F9890_9F0200;
extern u8 D_801F98D4_9F0244[12];
extern u8 D_801F98E0_9F0250[4056];
extern Bitmap D_801FA8B8_9F1228[1];
extern Sprite D_801FA8C8_9F1238;
extern u8 D_801FA90C_9F127C[12];
extern u8 D_801FA918_9F1288[4056];
extern Bitmap D_801FB8F0_9F2260[1];
extern Sprite D_801FB900_9F2270;
extern u8 D_801FB944_9F22B4[4];
extern Gfx D_801FB948_9F22B8[1];
extern u8 D_801FB950_9F22C0[8];
extern u8 D_801FB958_9F22C8[3920];
extern u8 D_801FC8A8_9F3218[8];
extern u8 D_801FC8B0_9F3220[3920];
extern u8 D_801FD800_9F4170[8];
extern u8 D_801FD808_9F4178[3920];
extern u8 D_801FE758_9F50C8[8];
extern u8 D_801FE760_9F50D0[3920];
extern u8 D_801FF6B0_9F6020[8];
extern u8 D_801FF6B8_9F6028[3920];
extern u8 D_80200608_9F6F78[8];
extern u8 D_80200610_9F6F80[3920];
extern u8 D_80201560_9F7ED0[8];
extern u8 D_80201568_9F7ED8[3920];
extern u8 D_802024B8_9F8E28[8];
extern u8 D_802024C0_9F8E30[1960];
extern Bitmap D_80202C68_9F95D8[8];
extern Sprite D_80202CE8_9F9658;
extern ReportPhotoComparator D_80202D2C_9F969C;
extern s32 D_80202D30_9F96A0;
extern s32 D_80202D34_9F96A4[6];
extern s16 D_80202D4C_9F96BC[66];
extern Sprite* D_80202DD0_9F9740[6];
extern u8* D_80202DE8_9F9758[6];
extern char* D_80202E00_9F9770[3];
extern char* D_80202E0C_9F977C[3];
extern char* D_80202E18_9F9788[3];
extern char* D_80202E24_9F9794[3];
extern char* D_80202E30_9F97A0[2];
extern char* D_80202E38_9F97A8[3];
extern char* D_80202E44_9F97B4[3];
extern char* D_80202E50_9F97C0[3];
extern char* D_80202E5C_9F97CC[3];
extern char* D_80202E68_9F97D8[3];
extern char* D_80202E74_9F97E4[3];
extern char* D_80202E80_9F97F0[3];
extern char** D_80202E8C_9F97FC[6];
extern char** D_80202EA4_9F9814[6];
extern u8 D_80202EBC_9F982C[4];
extern s32 D_80202EC0_9F9830;
extern s32 D_80202EC4_9F9834;
extern UIButton D_80202EC8_9F9838[6];
extern UIButton D_80202EF8_9F9868[5];
extern UIButton D_80202F20_9F9890[5];
extern UIButton D_80202F48_9F98B8[4];
extern UIButton D_80202F68_9F98D8[4];
extern UIButton D_80202F88_9F98F8[4];
extern UIButton D_80202FA8_9F9918[3];
extern UIButton D_80202FC0_9F9930[7];
extern s32 D_80202FF8_9F9968;
extern s32 D_80202FFC_9F996C;
extern s32 D_80203000_9F9970;
extern s32 D_80203004_9F9974;
extern s32 D_80203008_9F9978;
extern s32 D_8020300C_9F997C;
extern s32 D_80203010_9F9980;
extern s32 D_80203014_9F9984;
extern u8 D_80203018_9F9988[8];
extern const char D_80203218_9F9B88[80];
extern const char D_80203268_9F9BD8[92];
extern const char D_802032C4_9F9C34[80];
extern const char D_80203314_9F9C84[56];
extern const char D_8020334C_9F9CBC[64];
extern const char D_8020338C_9F9CFC[48];
extern const char D_802033BC_9F9D2C[88];
extern const char D_80203414_9F9D84[92];
extern const char D_80203470_9F9DE0[60];
extern const char D_802034AC_9F9E1C[88];
extern const char D_80203504_9F9E74[44];
extern const char D_80203530_9F9EA0[76];
extern const char D_8020357C_9F9EEC[96];
extern const char D_802035DC_9F9F4C[84];
extern const char D_80203630_9F9FA0[76];
extern const char D_8020367C_9F9FEC[56];
extern const char D_802036B4_9FA024[56];
extern const char D_802036EC_9FA05C[52];
extern const char D_80203720_9FA090[68];
extern const char D_80203764_9FA0D4[64];
extern const char D_802037A4_9FA114[80];
extern const char D_802037F4_9FA164[76];
extern const char D_80203840_9FA1B0[72];

/* Native storage in original address order, ordinary IDO .data. */

u8 D_801E3D30_9DA6A0[8] = { 0 };

u8 D_801E3D38_9DA6A8[512] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E3D38.rgba16.inc.c"
};

Bitmap D_801E3F38_9DA8A8[1] = {
    { 16, 16, 0, 0, D_801E3D38_9DA6A8, 16, 0 },
};

Sprite D_801E3F48_9DA8B8 = {
    0,
    0,
    16,
    16,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801E3F38_9DA8A8,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801E3F8C_9DA8FC[12] = { 0 };

u8 D_801E3F98_9DA908[3760] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E3F98.rgba16.inc.c"
};

u8 D_801E4E48_9DB7B8[8] = { 0 };

u8 D_801E4E50_9DB7C0[3760] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E4E50.rgba16.inc.c"
};

u8 D_801E5D00_9DC670[8] = { 0 };

u8 D_801E5D08_9DC678[3760] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E5D08.rgba16.inc.c"
};

u8 D_801E6BB8_9DD528[8] = { 0 };

u8 D_801E6BC0_9DD530[3760] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E6BC0.rgba16.inc.c"
};

u8 D_801E7A70_9DE3E0[8] = { 0 };

u8 D_801E7A78_9DE3E8[3760] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E7A78.rgba16.inc.c"
};

u8 D_801E8928_9DF298[8] = { 0 };

u8 D_801E8930_9DF2A0[1504] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E8930.rgba16.inc.c"
};

Bitmap D_801E8F10_9DF880[6] = {
    { 188, 188, 0, 0, D_801E3F98_9DA908, 10, 0 },
    { 188, 188, 0, 0, D_801E4E50_9DB7C0, 10, 0 },
    { 188, 188, 0, 0, D_801E5D08_9DC678, 10, 0 },
    { 188, 188, 0, 0, D_801E6BC0_9DD530, 10, 0 },
    { 188, 188, 0, 0, D_801E7A78_9DE3E8, 10, 0 },
    { 188, 188, 0, 0, D_801E8930_9DF2A0, 4, 0 },
};

Sprite D_801E8F70_9DF8E0 = {
    0,
    0,
    188,
    54,
    1.0f,
    1.0f,
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
    6,
    96,
    10,
    10,
    0,
    2,
    D_801E8F10_9DF880,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801E8FB4_9DF924[12] = { 0 };

u8 D_801E8FC0_9DF930[3952] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E8FC0.ia16.inc.c"
};

u8 D_801E9F30_9E08A0[8] = { 0 };

u8 D_801E9F38_9E08A8[3952] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801E9F38.ia16.inc.c"
};

u8 D_801EAEA8_9E1818[8] = { 0 };

u8 D_801EAEB0_9E1820[3952] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801EAEB0.ia16.inc.c"
};

u8 D_801EBE20_9E2790[8] = { 0 };

u8 D_801EBE28_9E2798[3952] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801EBE28.ia16.inc.c"
};

u8 D_801ECD98_9E3708[8] = { 0 };

u8 D_801ECDA0_9E3710[3952] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801ECDA0.ia16.inc.c"
};

Bitmap D_801EDD10_9E4680[5] = {
    { 103, 104, 0, 0, D_801E8FC0_9DF930, 19, 0 },
    { 103, 104, 0, 0, D_801E9F38_9E08A8, 19, 0 },
    { 103, 104, 0, 0, D_801EAEB0_9E1820, 19, 0 },
    { 103, 104, 0, 0, D_801EBE28_9E2798, 19, 0 },
    { 103, 104, 0, 0, D_801ECDA0_9E3710, 19, 0 },
};

Sprite D_801EDD60_9E46D0 = {
    0,
    0,
    103,
    95,
    1.0f,
    1.0f,
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
    5,
    84,
    19,
    19,
    3,
    2,
    D_801EDD10_9E4680,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801EDDA4_9E4714[12] = { 0 };

u8 D_801EDDB0_9E4720[304] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801EDDB0.rgba16.inc.c"
};

Bitmap D_801EDEE0_9E4850[1] = {
    { 152, 152, 0, 0, D_801EDDB0_9E4720, 1, 0 },
};

Sprite D_801EDEF0_9E4860 = {
    0,
    0,
    152,
    1,
    1.0f,
    1.0f,
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
    1,
    1,
    0,
    2,
    D_801EDEE0_9E4850,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801EDF34_9E48A4[12] = { 0 };

u8 D_801EDF40_9E48B0[512] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801EDF40.rgba16.inc.c"
};

Bitmap D_801EE140_9E4AB0[1] = {
    { 16, 16, 0, 0, D_801EDF40_9E48B0, 16, 0 },
};

Sprite D_801EE150_9E4AC0 = {
    0,
    0,
    16,
    16,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801EE140_9E4AB0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801EE194_9E4B04[12] = { 0 };

u8 D_801EE1A0_9E4B10[2880] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801EE1A0.rgba16.inc.c"
};

u8 D_801EECE0_9E5650[8] = { 0 };

u8 D_801EECE8_9E5658[2760] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801EECE8.rgba16.inc.c"
};

Bitmap D_801EF7B0_9E6120[2] = {
    { 18, 20, 0, 0, D_801EE1A0_9E4B10, 72, 0 },
    { 18, 20, 0, 0, D_801EECE8_9E5658, 69, 0 },
};

Sprite D_801EF7D0_9E6140 = {
    0,
    0,
    18,
    141,
    1.0f,
    1.0f,
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
    2,
    48,
    72,
    72,
    0,
    2,
    D_801EF7B0_9E6120,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801EF814_9E6184[12] = { 0 };

u8 D_801EF820_9E6190[2880] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801EF820.rgba16.inc.c"
};

u8 D_801F0360_9E6CD0[8] = { 0 };

u8 D_801F0368_9E6CD8[2760] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F0368.rgba16.inc.c"
};

Bitmap D_801F0E30_9E77A0[2] = {
    { 18, 20, 0, 0, D_801EF820_9E6190, 72, 0 },
    { 18, 20, 0, 0, D_801F0368_9E6CD8, 69, 0 },
};

Sprite D_801F0E50_9E77C0 = {
    0,
    0,
    18,
    141,
    1.0f,
    1.0f,
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
    2,
    48,
    72,
    72,
    0,
    2,
    D_801F0E30_9E77A0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F0E94_9E7804[12] = { 0 };

u8 D_801F0EA0_9E7810[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F0EA0.rgba16.inc.c"
};

u8 D_801F1DF0_9E8760[8] = { 0 };

u8 D_801F1DF8_9E8768[1120] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F1DF8.rgba16.inc.c"
};

Bitmap D_801F2258_9E8BC8[2] = {
    { 140, 140, 0, 0, D_801F0EA0_9E7810, 14, 0 },
    { 140, 140, 0, 0, D_801F1DF8_9E8768, 4, 0 },
};

Sprite D_801F2278_9E8BE8 = {
    0,
    0,
    140,
    18,
    1.0f,
    1.0f,
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
    2,
    48,
    14,
    14,
    0,
    2,
    D_801F2258_9E8BC8,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F22BC_9E8C2C[12] = { 0 };

u8 D_801F22C8_9E8C38[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F22C8.rgba16.inc.c"
};

u8 D_801F3218_9E9B88[8] = { 0 };

u8 D_801F3220_9E9B90[1120] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F3220.rgba16.inc.c"
};

Bitmap D_801F3680_9E9FF0[2] = {
    { 140, 140, 0, 0, D_801F22C8_9E8C38, 14, 0 },
    { 140, 140, 0, 0, D_801F3220_9E9B90, 4, 0 },
};

Sprite D_801F36A0_9EA010 = {
    0,
    0,
    140,
    18,
    1.0f,
    1.0f,
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
    2,
    48,
    14,
    14,
    0,
    2,
    D_801F3680_9E9FF0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F36E4_9EA054[12] = { 0 };

u8 D_801F36F0_9EA060[352] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F36F0.rgba16.inc.c"
};

Bitmap D_801F3850_9EA1C0[1] = {
    { 3, 4, 0, 0, D_801F36F0_9EA060, 44, 0 },
};

Sprite D_801F3860_9EA1D0 = {
    0,
    0,
    3,
    44,
    1.0f,
    1.0f,
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
    44,
    44,
    0,
    2,
    D_801F3850_9EA1C0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F38A4_9EA214[12] = { 0 };

u8 D_801F38B0_9EA220[336] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F38B0.rgba16.inc.c"
};

Bitmap D_801F3A00_9EA370[1] = {
    { 168, 168, 0, 0, D_801F38B0_9EA220, 1, 0 },
};

Sprite D_801F3A10_9EA380 = {
    0,
    0,
    168,
    1,
    1.0f,
    1.0f,
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
    1,
    1,
    0,
    2,
    D_801F3A00_9EA370,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F3A54_9EA3C4[12] = { 0 };

u8 D_801F3A60_9EA3D0[288] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F3A60.rgba16.inc.c"
};

Bitmap D_801F3B80_9EA4F0[1] = {
    { 12, 12, 0, 0, D_801F3A60_9EA3D0, 12, 0 },
};

Sprite D_801F3B90_9EA500 = {
    0,
    0,
    12,
    12,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F3B80_9EA4F0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F3BD4_9EA544[12] = { 0 };

u8 D_801F3BE0_9EA550[4048] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F3BE0.rgba16.inc.c"
};

u8 D_801F4BB0_9EB520[8] = { 0 };

u8 D_801F4BB8_9EB528[368] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F4BB8.rgba16.inc.c"
};

Bitmap D_801F4D28_9EB698[2] = {
    { 184, 184, 0, 0, D_801F3BE0_9EA550, 11, 0 },
    { 184, 184, 0, 0, D_801F4BB8_9EB528, 1, 0 },
};

Sprite D_801F4D48_9EB6B8 = {
    0,
    0,
    184,
    12,
    1.0f,
    1.0f,
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
    2,
    48,
    11,
    11,
    0,
    2,
    D_801F4D28_9EB698,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F4D8C_9EB6FC[12] = { 0 };

u8 D_801F4D98_9EB708[888] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F4D98.rgba16.inc.c"
};

Bitmap D_801F5110_9EBA80[1] = {
    { 3, 4, 0, 0, D_801F4D98_9EB708, 111, 0 },
};

Sprite D_801F5120_9EBA90 = {
    0,
    0,
    3,
    111,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F5110_9EBA80,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F5164_9EBAD4[12] = { 0 };

u8 D_801F5170_9EBAE0[840] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F5170.rgba16.inc.c"
};

Bitmap D_801F54B8_9EBE28[1] = {
    { 140, 140, 0, 0, D_801F5170_9EBAE0, 3, 0 },
};

Sprite D_801F54C8_9EBE38 = {
    0,
    0,
    140,
    3,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F54B8_9EBE28,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F550C_9EBE7C[12] = { 0 };

u8 D_801F5518_9EBE88[344] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F5518.rgba16.inc.c"
};

Bitmap D_801F5670_9EBFE0[1] = {
    { 2, 4, 0, 0, D_801F5518_9EBE88, 43, 0 },
};

Sprite D_801F5680_9EBFF0 = {
    0,
    0,
    2,
    43,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F5670_9EBFE0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F56C4_9EC034[12] = { 0 };

u8 D_801F56D0_9EC040[208] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F56D0.rgba16.inc.c"
};

Bitmap D_801F57A0_9EC110[1] = {
    { 52, 52, 0, 0, D_801F56D0_9EC040, 2, 0 },
};

Sprite D_801F57B0_9EC120 = {
    0,
    0,
    52,
    2,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F57A0_9EC110,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F57F4_9EC164[12] = { 0 };

u8 D_801F5800_9EC170[4056] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F5800.rgba16.inc.c"
};

Bitmap D_801F67D8_9ED148[1] = {
    { 52, 52, 0, 0, D_801F5800_9EC170, 39, 0 },
};

Sprite D_801F67E8_9ED158 = {
    0,
    0,
    52,
    39,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F67D8_9ED148,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F682C_9ED19C[12] = { 0 };

u8 D_801F6838_9ED1A8[4056] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F6838.rgba16.inc.c"
};

Bitmap D_801F7810_9EE180[1] = {
    { 52, 52, 0, 0, D_801F6838_9ED1A8, 39, 0 },
};

Sprite D_801F7820_9EE190 = {
    0,
    0,
    52,
    39,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F7810_9EE180,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F7864_9EE1D4[12] = { 0 };

u8 D_801F7870_9EE1E0[4056] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F7870.rgba16.inc.c"
};

Bitmap D_801F8848_9EF1B8[1] = {
    { 52, 52, 0, 0, D_801F7870_9EE1E0, 39, 0 },
};

Sprite D_801F8858_9EF1C8 = {
    0,
    0,
    52,
    39,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F8848_9EF1B8,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F889C_9EF20C[12] = { 0 };

u8 D_801F88A8_9EF218[4056] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F88A8.rgba16.inc.c"
};

Bitmap D_801F9880_9F01F0[1] = {
    { 52, 52, 0, 0, D_801F88A8_9EF218, 39, 0 },
};

Sprite D_801F9890_9F0200 = {
    0,
    0,
    52,
    39,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801F9880_9F01F0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F98D4_9F0244[12] = { 0 };

u8 D_801F98E0_9F0250[4056] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801F98E0.rgba16.inc.c"
};

Bitmap D_801FA8B8_9F1228[1] = {
    { 52, 52, 0, 0, D_801F98E0_9F0250, 39, 0 },
};

Sprite D_801FA8C8_9F1238 = {
    0,
    0,
    52,
    39,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801FA8B8_9F1228,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801FA90C_9F127C[12] = { 0 };

u8 D_801FA918_9F1288[4056] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801FA918.rgba16.inc.c"
};

Bitmap D_801FB8F0_9F2260[1] = {
    { 52, 52, 0, 0, D_801FA918_9F1288, 39, 0 },
};

Sprite D_801FB900_9F2270 = {
    0,
    0,
    52,
    39,
    1.0f,
    1.0f,
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
    0,
    2,
    D_801FB8F0_9F2260,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801FB944_9F22B4[4] = { 0 };

Gfx D_801FB948_9F22B8[1] = {
#include "build/assets/native/gfx/D_801FB948_9F22B8.dl.inc.c"
};

u8 D_801FB950_9F22C0[8] = { 0 };

u8 D_801FB958_9F22C8[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801FB958.rgba16.inc.c"
};

u8 D_801FC8A8_9F3218[8] = { 0 };

u8 D_801FC8B0_9F3220[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801FC8B0.rgba16.inc.c"
};

u8 D_801FD800_9F4170[8] = { 0 };

u8 D_801FD808_9F4178[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801FD808.rgba16.inc.c"
};

u8 D_801FE758_9F50C8[8] = { 0 };

u8 D_801FE760_9F50D0[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801FE760.rgba16.inc.c"
};

u8 D_801FF6B0_9F6020[8] = { 0 };

u8 D_801FF6B8_9F6028[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/801FF6B8.rgba16.inc.c"
};

u8 D_80200608_9F6F78[8] = { 0 };

u8 D_80200610_9F6F80[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/80200610.rgba16.inc.c"
};

u8 D_80201560_9F7ED0[8] = { 0 };

u8 D_80201568_9F7ED8[3920] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/80201568.rgba16.inc.c"
};

u8 D_802024B8_9F8E28[8] = { 0 };

u8 D_802024C0_9F8E30[1960] = {
#include "build/assets/pokemon_report/remaining_ui_9DA6A0/802024C0.rgba16.inc.c"
};

Bitmap D_80202C68_9F95D8[8] = {
    { 140, 140, 0, 0, D_801FB958_9F22C8, 14, 0 },
    { 140, 140, 0, 0, D_801FC8B0_9F3220, 14, 0 },
    { 140, 140, 0, 0, D_801FD808_9F4178, 14, 0 },
    { 140, 140, 0, 0, D_801FE760_9F50D0, 14, 0 },
    { 140, 140, 0, 0, D_801FF6B8_9F6028, 14, 0 },
    { 140, 140, 0, 0, D_80200610_9F6F80, 14, 0 },
    { 140, 140, 0, 0, D_80201568_9F7ED8, 14, 0 },
    { 140, 140, 0, 0, D_802024C0_9F8E30, 7, 0 },
};

Sprite D_80202CE8_9F9658 = {
    0,
    0,
    140,
    105,
    1.0f,
    1.0f,
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
    0,
    2,
    D_80202C68_9F95D8,
    NULL,
    NULL,
    0,
    0,
};

ReportPhotoComparator D_80202D2C_9F969C = NULL;

s32 D_80202D30_9F96A0 = -1;

s32 D_80202D34_9F96A4[6] = { 1004, 1010, 1028, 1022, 1018, 1035 };

s16 D_80202D4C_9F96BC[66] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 2, 2, 3, 1, 1, 3, 3, 2, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 3, 3, 1, 1, 1, 1, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, -1, -1 };

Sprite* D_80202DD0_9F9740[6] = {
    &D_801F67E8_9ED158,
    &D_801F7820_9EE190,
    &D_801F8858_9EF1C8,
    &D_801F9890_9F0200,
    &D_801FA8C8_9F1238,
    &D_801FB900_9F2270,
};

u8* D_80202DE8_9F9758[6] = {
    D_801F5800_9EC170,
    D_801F6838_9ED1A8,
    D_801F7870_9EE1E0,
    D_801F88A8_9EF218,
    D_801F98E0_9F0250,
    D_801FA918_9F1288,
};

char* D_80202E00_9F9770[3] = {
    (char*) D_80203218_9F9B88,
    (char*) D_80203268_9F9BD8,
    NULL,
};

char* D_80202E0C_9F977C[3] = {
    (char*) D_802032C4_9F9C34,
    (char*) D_80203314_9F9C84,
    NULL,
};

char* D_80202E18_9F9788[3] = {
    (char*) D_8020334C_9F9CBC,
    (char*) D_8020338C_9F9CFC,
    NULL,
};

char* D_80202E24_9F9794[3] = {
    (char*) D_802033BC_9F9D2C,
    (char*) D_80203414_9F9D84,
    NULL,
};

char* D_80202E30_9F97A0[2] = {
    (char*) D_80203470_9F9DE0,
    NULL,
};

char* D_80202E38_9F97A8[3] = {
    (char*) D_802034AC_9F9E1C,
    (char*) D_80203504_9F9E74,
    NULL,
};

char* D_80202E44_9F97B4[3] = {
    (char*) D_80203530_9F9EA0,
    (char*) D_8020357C_9F9EEC,
    NULL,
};

char* D_80202E50_9F97C0[3] = {
    (char*) D_802035DC_9F9F4C,
    (char*) D_80203630_9F9FA0,
    NULL,
};

char* D_80202E5C_9F97CC[3] = {
    (char*) D_8020367C_9F9FEC,
    (char*) D_802036B4_9FA024,
    NULL,
};

char* D_80202E68_9F97D8[3] = {
    (char*) D_802036EC_9FA05C,
    (char*) D_80203720_9FA090,
    NULL,
};

char* D_80202E74_9F97E4[3] = {
    (char*) D_80203764_9FA0D4,
    (char*) D_802037A4_9FA114,
    NULL,
};

char* D_80202E80_9F97F0[3] = {
    (char*) D_802037F4_9FA164,
    (char*) D_80203840_9FA1B0,
    NULL,
};

char** D_80202E8C_9F97FC[6] = {
    D_80202E00_9F9770,
    D_80202E0C_9F977C,
    D_80202E18_9F9788,
    D_80202E24_9F9794,
    D_80202E30_9F97A0,
    D_80202E38_9F97A8,
};

char** D_80202EA4_9F9814[6] = {
    D_80202E44_9F97B4,
    D_80202E50_9F97C0,
    D_80202E5C_9F97CC,
    D_80202E68_9F97D8,
    D_80202E74_9F97E4,
    D_80202E80_9F97F0,
};

u8 D_80202EBC_9F982C[4] = { 0 };

s32 D_80202EC0_9F9830 = 0;

s32 D_80202EC4_9F9834 = 0;

UIButton D_80202EC8_9F9838[6] = {
    { 2, NULL },
    { 25, NULL },
    { 18, NULL },
    { 34, NULL },
    { 17, NULL },
    { 35, NULL },
};

UIButton D_80202EF8_9F9868[5] = {
    { 2, NULL },
    { 25, NULL },
    { 34, NULL },
    { 17, NULL },
    { 35, NULL },
};

UIButton D_80202F20_9F9890[5] = {
    { 29, NULL },
    { 0, NULL },
    { 34, NULL },
    { 31, NULL },
    { 35, NULL },
};

UIButton D_80202F48_9F98B8[4] = {
    { 28, NULL },
    { 34, NULL },
    { 5, NULL },
    { 35, NULL },
};

UIButton D_80202F68_9F98D8[4] = {
    { 29, NULL },
    { 34, NULL },
    { 31, NULL },
    { 35, NULL },
};

UIButton D_80202F88_9F98F8[4] = {
    { 28, NULL },
    { 34, NULL },
    { 31, NULL },
    { 35, NULL },
};

UIButton D_80202FA8_9F9918[3] = {
    { 34, NULL },
    { 5, NULL },
    { 35, NULL },
};

UIButton D_80202FC0_9F9930[7] = {
    { 13, NULL },
    { 14, NULL },
    { 15, NULL },
    { 16, NULL },
    { 34, NULL },
    { 5, NULL },
    { 35, NULL },
};

s32 D_80202FF8_9F9968 = -1;

s32 D_80202FFC_9F996C = -1;

s32 D_80203000_9F9970 = -1;

s32 D_80203004_9F9974 = -1;

s32 D_80203008_9F9978 = 0;

s32 D_8020300C_9F997C = 0;

s32 D_80203010_9F9980 = -1;

s32 D_80203014_9F9984 = 0;

u8 D_80203018_9F9988[8] = { 0 };
