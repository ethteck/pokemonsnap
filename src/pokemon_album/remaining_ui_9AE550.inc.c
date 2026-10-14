#include "common.h"
#include "ld_addrs.h"
#include "window/window.h"

extern u8 D_801E4300_9AE550[8];
extern u8 D_801E4308_9AE558[512];
extern Bitmap D_801E4508_9AE758[1];
extern Sprite D_801E4518_9AE768;
extern u8 D_801E455C_9AE7AC[12];
extern u8 D_801E4568_9AE7B8[3872];
extern u8 D_801E5488_9AF6D8[8];
extern u8 D_801E5490_9AF6E0[3872];
extern u8 D_801E63B0_9B0600[8];
extern u8 D_801E63B8_9B0608[3872];
extern u8 D_801E72D8_9B1528[8];
extern u8 D_801E72E0_9B1530[3872];
extern u8 D_801E8200_9B2450[8];
extern u8 D_801E8208_9B2458[3872];
extern u8 D_801E9128_9B3378[8];
extern u8 D_801E9130_9B3380[3872];
extern u8 D_801EA050_9B42A0[8];
extern u8 D_801EA058_9B42A8[3872];
extern u8 D_801EAF78_9B51C8[8];
extern u8 D_801EAF80_9B51D0[3872];
extern u8 D_801EBEA0_9B60F0[8];
extern u8 D_801EBEA8_9B60F8[3872];
extern u8 D_801ECDC8_9B7018[8];
extern u8 D_801ECDD0_9B7020[1760];
extern Bitmap D_801ED4B0_9B7700[10];
extern Sprite D_801ED550_9B77A0;
extern u8 D_801ED594_9B77E4[12];
extern u8 D_801ED5A0_9B77F0[3840];
extern u8 D_801EE4A0_9B86F0[8];
extern u8 D_801EE4A8_9B86F8[3840];
extern u8 D_801EF3A8_9B95F8[8];
extern u8 D_801EF3B0_9B9600[3840];
extern u8 D_801F02B0_9BA500[8];
extern u8 D_801F02B8_9BA508[3840];
extern u8 D_801F11B8_9BB408[8];
extern u8 D_801F11C0_9BB410[3840];
extern u8 D_801F20C0_9BC310[8];
extern u8 D_801F20C8_9BC318[3072];
extern Bitmap D_801F2CC8_9BCF18[6];
extern Sprite D_801F2D28_9BCF78;
extern u8 D_801F2D6C_9BCFBC[12];
extern u8 D_801F2D78_9BCFC8[512];
extern Bitmap D_801F2F78_9BD1C8[1];
extern Sprite D_801F2F88_9BD1D8;
extern u8 D_801F2FCC_9BD21C[12];
extern u8 D_801F2FD8_9BD228[288];
extern Bitmap D_801F30F8_9BD348[1];
extern Sprite D_801F3108_9BD358;
extern u8 D_801F314C_9BD39C[12];
extern u8 D_801F3158_9BD3A8[288];
extern Bitmap D_801F3278_9BD4C8[1];
extern Sprite D_801F3288_9BD4D8;
extern u8 D_801F32CC_9BD51C[12];
extern u8 D_801F32D8_9BD528[288];
extern Bitmap D_801F33F8_9BD648[1];
extern Sprite D_801F3408_9BD658;
extern u8 D_801F344C_9BD69C[12];
extern u8 D_801F3458_9BD6A8[288];
extern Bitmap D_801F3578_9BD7C8[1];
extern Sprite D_801F3588_9BD7D8;
extern u8 D_801F35CC_9BD81C[12];
extern u8 D_801F35D8_9BD828[4000];
extern u8 D_801F4578_9BE7C8[8];
extern u8 D_801F4580_9BE7D0[4000];
extern u8 D_801F5520_9BF770[8];
extern u8 D_801F5528_9BF778[4000];
extern u8 D_801F64C8_9C0718[8];
extern u8 D_801F64D0_9C0720[1600];
extern Bitmap D_801F6B10_9C0D60[4];
extern Sprite D_801F6B50_9C0DA0;
extern u8 D_801F6B94_9C0DE4[12];
extern u8 D_801F6BA0_9C0DF0[4032];
extern u8 D_801F7B60_9C1DB0[8];
extern u8 D_801F7B68_9C1DB8[4032];
extern u8 D_801F8B28_9C2D78[8];
extern u8 D_801F8B30_9C2D80[4032];
extern u8 D_801F9AF0_9C3D40[8];
extern u8 D_801F9AF8_9C3D48[4032];
extern u8 D_801FAAB8_9C4D08[8];
extern u8 D_801FAAC0_9C4D10[1728];
extern Bitmap D_801FB180_9C53D0[5];
extern Sprite D_801FB1D0_9C5420;
extern u8 D_801FB214_9C5464[12];
extern u8 D_801FB220_9C5470[3744];
extern u8 D_801FC0C0_9C6310[8];
extern u8 D_801FC0C8_9C6318[3744];
extern u8 D_801FCF68_9C71B8[8];
extern u8 D_801FCF70_9C71C0[3744];
extern u8 D_801FDE10_9C8060[8];
extern u8 D_801FDE18_9C8068[3744];
extern u8 D_801FECB8_9C8F08[8];
extern u8 D_801FECC0_9C8F10[3328];
extern Bitmap D_801FF9C0_9C9C10[5];
extern Sprite D_801FFA10_9C9C60;
extern u8 D_801FFA54_9C9CA4[12];
extern u8 D_801FFA60_9C9CB0[320];
extern Bitmap D_801FFBA0_9C9DF0[1];
extern Sprite D_801FFBB0_9C9E00;
extern u8 D_801FFBF4_9C9E44[12];
extern u8 D_801FFC00_9C9E50[112];
extern Bitmap D_801FFC70_9C9EC0[1];
extern Sprite D_801FFC80_9C9ED0;
extern u8 D_801FFCC4_9C9F14[12];
extern u8 D_801FFCD0_9C9F20[888];
extern Bitmap D_80200048_9CA298[1];
extern Sprite D_80200058_9CA2A8;
extern u8 D_8020009C_9CA2EC[12];
extern u8 D_802000A8_9CA2F8[840];
extern Bitmap D_802003F0_9CA640[1];
extern Sprite D_80200400_9CA650;
extern u8 D_80200444_9CA694[12];
extern u8 D_80200450_9CA6A0[344];
extern Bitmap D_802005A8_9CA7F8[1];
extern Sprite D_802005B8_9CA808;
extern u8 D_802005FC_9CA84C[12];
extern u8 D_80200608_9CA858[208];
extern Bitmap D_802006D8_9CA928[1];
extern Sprite D_802006E8_9CA938;
extern u8 D_8020072C_9CA97C[4];
extern Gfx D_80200730_9CA980[1];
extern u8 D_80200738_9CA988[8];
extern u8 D_80200740_9CA990[4056];
extern Bitmap D_80201718_9CB968[1];
extern Sprite D_80201728_9CB978;
extern u8 D_8020176C_9CB9BC[20];
extern u8 D_80201780_9CB9D0[3920];
extern u8 D_802026D0_9CC920[8];
extern u8 D_802026D8_9CC928[3920];
extern u8 D_80203628_9CD878[8];
extern u8 D_80203630_9CD880[3920];
extern u8 D_80204580_9CE7D0[8];
extern u8 D_80204588_9CE7D8[3920];
extern u8 D_802054D8_9CF728[8];
extern u8 D_802054E0_9CF730[3920];
extern u8 D_80206430_9D0680[8];
extern u8 D_80206438_9D0688[3920];
extern u8 D_80207388_9D15D8[8];
extern u8 D_80207390_9D15E0[3920];
extern u8 D_802082E0_9D2530[8];
extern u8 D_802082E8_9D2538[1960];
extern Bitmap D_80208A90_9D2CE0[8];
extern Sprite D_80208B10_9D2D60;

/* Native storage in original address order, ordinary IDO .data. */

u8 D_801E4300_9AE550[8] = { 0 };

u8 D_801E4308_9AE558[512] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801E4308.rgba16.inc.c"
};

Bitmap D_801E4508_9AE758[1] = {
    { 16, 16, 0, 0, D_801E4308_9AE558, 16, 0 },
};

Sprite D_801E4518_9AE768 = {
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
    D_801E4508_9AE758,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801E455C_9AE7AC[12] = { 0 };

u8 D_801E4568_9AE7B8[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801E4568.ia16.inc.c"
};

u8 D_801E5488_9AF6D8[8] = { 0 };

u8 D_801E5490_9AF6E0[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801E5490.ia16.inc.c"
};

u8 D_801E63B0_9B0600[8] = { 0 };

u8 D_801E63B8_9B0608[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801E63B8.ia16.inc.c"
};

u8 D_801E72D8_9B1528[8] = { 0 };

u8 D_801E72E0_9B1530[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801E72E0.ia16.inc.c"
};

u8 D_801E8200_9B2450[8] = { 0 };

u8 D_801E8208_9B2458[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801E8208.ia16.inc.c"
};

u8 D_801E9128_9B3378[8] = { 0 };

u8 D_801E9130_9B3380[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801E9130.ia16.inc.c"
};

u8 D_801EA050_9B42A0[8] = { 0 };

u8 D_801EA058_9B42A8[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801EA058.ia16.inc.c"
};

u8 D_801EAF78_9B51C8[8] = { 0 };

u8 D_801EAF80_9B51D0[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801EAF80.ia16.inc.c"
};

u8 D_801EBEA0_9B60F0[8] = { 0 };

u8 D_801EBEA8_9B60F8[3872] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801EBEA8.ia16.inc.c"
};

u8 D_801ECDC8_9B7018[8] = { 0 };

u8 D_801ECDD0_9B7020[1760] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801ECDD0.ia16.inc.c"
};

Bitmap D_801ED4B0_9B7700[10] = {
    { 174, 176, 0, 0, D_801E4568_9AE7B8, 11, 0 },
    { 174, 176, 0, 0, D_801E5490_9AF6E0, 11, 0 },
    { 174, 176, 0, 0, D_801E63B8_9B0608, 11, 0 },
    { 174, 176, 0, 0, D_801E72E0_9B1530, 11, 0 },
    { 174, 176, 0, 0, D_801E8208_9B2458, 11, 0 },
    { 174, 176, 0, 0, D_801E9130_9B3380, 11, 0 },
    { 174, 176, 0, 0, D_801EA058_9B42A8, 11, 0 },
    { 174, 176, 0, 0, D_801EAF80_9B51D0, 11, 0 },
    { 174, 176, 0, 0, D_801EBEA8_9B60F8, 11, 0 },
    { 174, 176, 0, 0, D_801ECDD0_9B7020, 5, 0 },
};

Sprite D_801ED550_9B77A0 = {
    0,
    0,
    174,
    104,
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
    10,
    144,
    11,
    11,
    3,
    2,
    D_801ED4B0_9B7700,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801ED594_9B77E4[12] = { 0 };

u8 D_801ED5A0_9B77F0[3840] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801ED5A0.rgba16.inc.c"
};

u8 D_801EE4A0_9B86F0[8] = { 0 };

u8 D_801EE4A8_9B86F8[3840] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801EE4A8.rgba16.inc.c"
};

u8 D_801EF3A8_9B95F8[8] = { 0 };

u8 D_801EF3B0_9B9600[3840] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801EF3B0.rgba16.inc.c"
};

u8 D_801F02B0_9BA500[8] = { 0 };

u8 D_801F02B8_9BA508[3840] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F02B8.rgba16.inc.c"
};

u8 D_801F11B8_9BB408[8] = { 0 };

u8 D_801F11C0_9BB410[3840] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F11C0.rgba16.inc.c"
};

u8 D_801F20C0_9BC310[8] = { 0 };

u8 D_801F20C8_9BC318[3072] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F20C8.rgba16.inc.c"
};

Bitmap D_801F2CC8_9BCF18[6] = {
    { 192, 192, 0, 0, D_801ED5A0_9B77F0, 10, 0 },
    { 192, 192, 0, 0, D_801EE4A8_9B86F8, 10, 0 },
    { 192, 192, 0, 0, D_801EF3B0_9B9600, 10, 0 },
    { 192, 192, 0, 0, D_801F02B8_9BA508, 10, 0 },
    { 192, 192, 0, 0, D_801F11C0_9BB410, 10, 0 },
    { 192, 192, 0, 0, D_801F20C8_9BC318, 8, 0 },
};

Sprite D_801F2D28_9BCF78 = {
    0,
    0,
    192,
    58,
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
    D_801F2CC8_9BCF18,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F2D6C_9BCFBC[12] = { 0 };

u8 D_801F2D78_9BCFC8[512] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F2D78.rgba16.inc.c"
};

Bitmap D_801F2F78_9BD1C8[1] = {
    { 16, 16, 0, 0, D_801F2D78_9BCFC8, 16, 0 },
};

Sprite D_801F2F88_9BD1D8 = {
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
    D_801F2F78_9BD1C8,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F2FCC_9BD21C[12] = { 0 };

u8 D_801F2FD8_9BD228[288] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F2FD8.rgba16.inc.c"
};

Bitmap D_801F30F8_9BD348[1] = {
    { 12, 12, 0, 0, D_801F2FD8_9BD228, 12, 0 },
};

Sprite D_801F3108_9BD358 = {
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
    D_801F30F8_9BD348,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F314C_9BD39C[12] = { 0 };

u8 D_801F3158_9BD3A8[288] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F3158.rgba16.inc.c"
};

Bitmap D_801F3278_9BD4C8[1] = {
    { 12, 12, 0, 0, D_801F3158_9BD3A8, 12, 0 },
};

Sprite D_801F3288_9BD4D8 = {
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
    D_801F3278_9BD4C8,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F32CC_9BD51C[12] = { 0 };

u8 D_801F32D8_9BD528[288] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F32D8.rgba16.inc.c"
};

Bitmap D_801F33F8_9BD648[1] = {
    { 12, 12, 0, 0, D_801F32D8_9BD528, 12, 0 },
};

Sprite D_801F3408_9BD658 = {
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
    D_801F33F8_9BD648,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F344C_9BD69C[12] = { 0 };

u8 D_801F3458_9BD6A8[288] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F3458.rgba16.inc.c"
};

Bitmap D_801F3578_9BD7C8[1] = {
    { 12, 12, 0, 0, D_801F3458_9BD6A8, 12, 0 },
};

Sprite D_801F3588_9BD7D8 = {
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
    D_801F3578_9BD7C8,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F35CC_9BD81C[12] = { 0 };

u8 D_801F35D8_9BD828[4000] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F35D8.rgba16.inc.c"
};

u8 D_801F4578_9BE7C8[8] = { 0 };

u8 D_801F4580_9BE7D0[4000] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F4580.rgba16.inc.c"
};

u8 D_801F5520_9BF770[8] = { 0 };

u8 D_801F5528_9BF778[4000] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F5528.rgba16.inc.c"
};

u8 D_801F64C8_9C0718[8] = { 0 };

u8 D_801F64D0_9C0720[1600] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F64D0.rgba16.inc.c"
};

Bitmap D_801F6B10_9C0D60[4] = {
    { 198, 200, 0, 0, D_801F35D8_9BD828, 10, 0 },
    { 198, 200, 0, 0, D_801F4580_9BE7D0, 10, 0 },
    { 198, 200, 0, 0, D_801F5528_9BF778, 10, 0 },
    { 198, 200, 0, 0, D_801F64D0_9C0720, 4, 0 },
};

Sprite D_801F6B50_9C0DA0 = {
    0,
    0,
    198,
    34,
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
    4,
    72,
    10,
    10,
    0,
    2,
    D_801F6B10_9C0D60,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801F6B94_9C0DE4[12] = { 0 };

u8 D_801F6BA0_9C0DF0[4032] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F6BA0.rgba16.inc.c"
};

u8 D_801F7B60_9C1DB0[8] = { 0 };

u8 D_801F7B68_9C1DB8[4032] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F7B68.rgba16.inc.c"
};

u8 D_801F8B28_9C2D78[8] = { 0 };

u8 D_801F8B30_9C2D80[4032] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F8B30.rgba16.inc.c"
};

u8 D_801F9AF0_9C3D40[8] = { 0 };

u8 D_801F9AF8_9C3D48[4032] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801F9AF8.rgba16.inc.c"
};

u8 D_801FAAB8_9C4D08[8] = { 0 };

u8 D_801FAAC0_9C4D10[1728] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FAAC0.rgba16.inc.c"
};

Bitmap D_801FB180_9C53D0[5] = {
    { 72, 72, 0, 0, D_801F6BA0_9C0DF0, 28, 0 },
    { 72, 72, 0, 0, D_801F7B68_9C1DB8, 28, 0 },
    { 72, 72, 0, 0, D_801F8B30_9C2D80, 28, 0 },
    { 72, 72, 0, 0, D_801F9AF8_9C3D48, 28, 0 },
    { 72, 72, 0, 0, D_801FAAC0_9C4D10, 12, 0 },
};

Sprite D_801FB1D0_9C5420 = {
    0,
    0,
    72,
    124,
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
    28,
    28,
    0,
    2,
    D_801FB180_9C53D0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801FB214_9C5464[12] = { 0 };

u8 D_801FB220_9C5470[3744] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FB220.rgba16.inc.c"
};

u8 D_801FC0C0_9C6310[8] = { 0 };

u8 D_801FC0C8_9C6318[3744] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FC0C8.rgba16.inc.c"
};

u8 D_801FCF68_9C71B8[8] = { 0 };

u8 D_801FCF70_9C71C0[3744] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FCF70.rgba16.inc.c"
};

u8 D_801FDE10_9C8060[8] = { 0 };

u8 D_801FDE18_9C8068[3744] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FDE18.rgba16.inc.c"
};

u8 D_801FECB8_9C8F08[8] = { 0 };

u8 D_801FECC0_9C8F10[3328] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FECC0.rgba16.inc.c"
};

Bitmap D_801FF9C0_9C9C10[5] = {
    { 208, 208, 0, 0, D_801FB220_9C5470, 9, 0 },
    { 208, 208, 0, 0, D_801FC0C8_9C6318, 9, 0 },
    { 208, 208, 0, 0, D_801FCF70_9C71C0, 9, 0 },
    { 208, 208, 0, 0, D_801FDE18_9C8068, 9, 0 },
    { 208, 208, 0, 0, D_801FECC0_9C8F10, 8, 0 },
};

Sprite D_801FFA10_9C9C60 = {
    0,
    0,
    208,
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
    5,
    84,
    9,
    9,
    0,
    2,
    D_801FF9C0_9C9C10,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801FFA54_9C9CA4[12] = { 0 };

u8 D_801FFA60_9C9CB0[320] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FFA60.rgba16.inc.c"
};

Bitmap D_801FFBA0_9C9DF0[1] = {
    { 16, 16, 0, 0, D_801FFA60_9C9CB0, 10, 0 },
};

Sprite D_801FFBB0_9C9E00 = {
    0,
    0,
    16,
    10,
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
    10,
    10,
    0,
    2,
    D_801FFBA0_9C9DF0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801FFBF4_9C9E44[12] = { 0 };

u8 D_801FFC00_9C9E50[112] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FFC00.rgba16.inc.c"
};

Bitmap D_801FFC70_9C9EC0[1] = {
    { 4, 4, 0, 0, D_801FFC00_9C9E50, 14, 0 },
};

Sprite D_801FFC80_9C9ED0 = {
    0,
    0,
    4,
    14,
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
    14,
    14,
    0,
    2,
    D_801FFC70_9C9EC0,
    NULL,
    NULL,
    0,
    0,
};

u8 D_801FFCC4_9C9F14[12] = { 0 };

u8 D_801FFCD0_9C9F20[888] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/801FFCD0.rgba16.inc.c"
};

Bitmap D_80200048_9CA298[1] = {
    { 3, 4, 0, 0, D_801FFCD0_9C9F20, 111, 0 },
};

Sprite D_80200058_9CA2A8 = {
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
    D_80200048_9CA298,
    NULL,
    NULL,
    0,
    0,
};

u8 D_8020009C_9CA2EC[12] = { 0 };

u8 D_802000A8_9CA2F8[840] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/802000A8.rgba16.inc.c"
};

Bitmap D_802003F0_9CA640[1] = {
    { 140, 140, 0, 0, D_802000A8_9CA2F8, 3, 0 },
};

Sprite D_80200400_9CA650 = {
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
    D_802003F0_9CA640,
    NULL,
    NULL,
    0,
    0,
};

u8 D_80200444_9CA694[12] = { 0 };

u8 D_80200450_9CA6A0[344] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/80200450.rgba16.inc.c"
};

Bitmap D_802005A8_9CA7F8[1] = {
    { 2, 4, 0, 0, D_80200450_9CA6A0, 43, 0 },
};

Sprite D_802005B8_9CA808 = {
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
    D_802005A8_9CA7F8,
    NULL,
    NULL,
    0,
    0,
};

u8 D_802005FC_9CA84C[12] = { 0 };

u8 D_80200608_9CA858[208] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/80200608.rgba16.inc.c"
};

Bitmap D_802006D8_9CA928[1] = {
    { 52, 52, 0, 0, D_80200608_9CA858, 2, 0 },
};

Sprite D_802006E8_9CA938 = {
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
    D_802006D8_9CA928,
    NULL,
    NULL,
    0,
    0,
};

u8 D_8020072C_9CA97C[4] = { 0 };

Gfx D_80200730_9CA980[1] = {
#include "build/assets/native/gfx/D_80200730_9CA980.dl.inc.c"
};

u8 D_80200738_9CA988[8] = { 0 };

u8 D_80200740_9CA990[4056] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/80200740.rgba16.inc.c"
};

Bitmap D_80201718_9CB968[1] = {
    { 52, 52, 0, 0, D_80200740_9CA990, 39, 0 },
};

Sprite D_80201728_9CB978 = {
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
    D_80201718_9CB968,
    NULL,
    NULL,
    0,
    0,
};

u8 D_8020176C_9CB9BC[20] = { 0 };

u8 D_80201780_9CB9D0[3920] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/80201780.rgba16.inc.c"
};

u8 D_802026D0_9CC920[8] = { 0 };

u8 D_802026D8_9CC928[3920] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/802026D8.rgba16.inc.c"
};

u8 D_80203628_9CD878[8] = { 0 };

u8 D_80203630_9CD880[3920] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/80203630.rgba16.inc.c"
};

u8 D_80204580_9CE7D0[8] = { 0 };

u8 D_80204588_9CE7D8[3920] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/80204588.rgba16.inc.c"
};

u8 D_802054D8_9CF728[8] = { 0 };

u8 D_802054E0_9CF730[3920] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/802054E0.rgba16.inc.c"
};

u8 D_80206430_9D0680[8] = { 0 };

u8 D_80206438_9D0688[3920] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/80206438.rgba16.inc.c"
};

u8 D_80207388_9D15D8[8] = { 0 };

u8 D_80207390_9D15E0[3920] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/80207390.rgba16.inc.c"
};

u8 D_802082E0_9D2530[8] = { 0 };

u8 D_802082E8_9D2538[1960] = {
#include "build/assets/pokemon_album/remaining_ui_9AE550/802082E8.rgba16.inc.c"
};

Bitmap D_80208A90_9D2CE0[8] = {
    { 140, 140, 0, 0, D_80201780_9CB9D0, 14, 0 },
    { 140, 140, 0, 0, D_802026D8_9CC928, 14, 0 },
    { 140, 140, 0, 0, D_80203630_9CD880, 14, 0 },
    { 140, 140, 0, 0, D_80204588_9CE7D8, 14, 0 },
    { 140, 140, 0, 0, D_802054E0_9CF730, 14, 0 },
    { 140, 140, 0, 0, D_80206438_9D0688, 14, 0 },
    { 140, 140, 0, 0, D_80207390_9D15E0, 14, 0 },
    { 140, 140, 0, 0, D_802082E8_9D2538, 7, 0 },
};

Sprite D_80208B10_9D2D60 = {
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
    D_80208A90_9D2CE0,
    NULL,
    NULL,
    0,
    0,
};
