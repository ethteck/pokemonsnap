#include "common.h"

extern u8 pikachu_tex_800FFF98[];
extern u8 pikachu_tex_801007A0[];
extern u8 pikachu_tex_80100FA8[];
extern u8 pikachu_tex_801017B0[];
extern u8 pikachu_tex_801045D8[];
extern u8 pikachu_tex_801049E0[];
extern u8 pikachu_tex_80104E98[];
extern u8 pikachu_tex_801050C8[];
extern u8 pikachu_tex_801054D8[];
extern u8 pikachu_tex_80105AE8[];
extern u8 pikachu_tex_801060F8[];
extern u8 pikachu_tex_80106708[];
extern u8 pikachu_tex_80106D18[];
extern u8 pikachu_tex_80107328[];
extern u8 pikachu_tex_80107938[];
extern u8 pikachu_tex_80107F48[];
extern u8 pikachu_tex_80108558[];
extern u8 pikachu_tex_80108B68[];
extern u8 pikachu_tex_80109090[];
extern u8 pikachu_tex_801090B8_png[];
extern u8 pikachu_tex_80104DE8[];
extern u8 pikachu_tex_80107120[];
extern u8 pikachu_tex_80104E70[];
extern u8 pikachu_tex_801052D0[];
extern u8 pikachu_tex_80108F70[];
extern u8 pikachu_tex_80108F88_png[];
extern u8 pikachu_tex_80102FC0[];
extern u8 pikachu_tex_80101FB8[];
extern u8 pikachu_tex_80103FC8[];
extern u8 pikachu_tex_801041D0_png[];
extern u8 pikachu_tex_801091C0[];
extern u8 pikachu_tex_801091E8_png[];

extern Texture* pikachu_hd_part1_mat[];
extern Texture* pikachu_hd_part2_mat[];
extern Texture* pikachu_hd_part11_mat[];
extern Texture* pikachu_hd_part14_mat[];
extern Gfx pikachu_hd_part2_draw[];

Texture** pikachu_hd_materials[] = {
    NULL,
    pikachu_hd_part1_mat,
    pikachu_hd_part2_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    pikachu_hd_part11_mat,
    NULL,
    NULL,
    pikachu_hd_part14_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* pikachu_hd_part1_mat0_textures[] = {
    pikachu_tex_801045D8,
    pikachu_tex_801049E0,
};

u8* pikachu_hd_part1_mat1_textures[] = {
    pikachu_tex_801049E0,
    pikachu_tex_801045D8,
};

u8* pikachu_hd_part2_mat0_textures[] = {
    pikachu_tex_800FFF98,
    pikachu_tex_801007A0,
    pikachu_tex_80100FA8,
    pikachu_tex_801017B0,
    pikachu_tex_801017B0,
};

u8* pikachu_hd_part2_mat1_textures[] = {
    pikachu_tex_800FFF98,
    pikachu_tex_801007A0,
    pikachu_tex_80100FA8,
    pikachu_tex_801017B0,
    pikachu_tex_801017B0,
};

u8* pikachu_hd_part11_mat0_textures[] = {
    pikachu_tex_801054D8,
    pikachu_tex_80105AE8,
    pikachu_tex_801060F8,
    pikachu_tex_80106708,
    pikachu_tex_80106D18,
};

u8* pikachu_hd_part11_mat1_textures[] = {
    pikachu_tex_80104E98,
    pikachu_tex_801050C8,
};

u8* pikachu_hd_part11_mat2_textures[] = {
    pikachu_tex_80107328,
    pikachu_tex_80107938,
    pikachu_tex_80107F48,
    pikachu_tex_80108558,
    pikachu_tex_80108B68,
};

u8* pikachu_hd_part14_mat0_textures[] = {
    pikachu_tex_801045D8,
    pikachu_tex_801049E0,
};

u8* pikachu_hd_part14_mat1_textures[] = {
    pikachu_tex_801049E0,
    pikachu_tex_801045D8,
};

Texture pikachu_hd_part1_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_hd_part1_mat0_textures,
    32,
    1,
    64,
    32,
    0,
    -0.004999999888241291,
    -0.004000000189989805,
    1.0,
    1.0,
    -0.004999999888241291,
    1.0,
    NULL,
    0x201,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    64,
    32,
    64,
    32,
    -0.004999999888241291,
    -0.004000000189989805,
    -0.004999999888241291,
    { 0, 0, 0, 0 },
    8193,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 255, 127, 31, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture pikachu_hd_part1_mat1 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_hd_part1_mat1_textures,
    32,
    1,
    64,
    32,
    0,
    -0.004999999888241291,
    -0.004000000189989805,
    1.0,
    1.0,
    -0.004999999888241291,
    1.0,
    NULL,
    0x201,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    64,
    32,
    64,
    32,
    -0.004999999888241291,
    -0.004000000189989805,
    -0.004999999888241291,
    { 0, 0, 0, 0 },
    8193,
    { 255, 159, 64, 255 },
    0,
    0,
    0,
    0,
    { 255, 117, 29, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture pikachu_hd_part2_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_hd_part2_mat0_textures,
    32,
    0,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 255, 0, 255 },
    0,
    0,
    0,
    0,
    { 255, 255, 255, 204 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture pikachu_hd_part2_mat1 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_hd_part2_mat1_textures,
    32,
    0,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 255, 255, 0, 0 },
    0,
    0,
    0,
    0,
    { 255, 255, 255, 192 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture pikachu_hd_part11_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    pikachu_hd_part11_mat0_textures,
    32,
    0,
    32,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture pikachu_hd_part11_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    pikachu_hd_part11_mat1_textures,
    32,
    0,
    32,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture pikachu_hd_part11_mat2 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    pikachu_hd_part11_mat2_textures,
    32,
    0,
    32,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture pikachu_hd_part14_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_hd_part14_mat0_textures,
    32,
    0,
    64,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x201,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    64,
    32,
    64,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8193,
    { 255, 255, 164, 255 },
    0,
    0,
    0,
    0,
    { 255, 172, 79, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture pikachu_hd_part14_mat1 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_hd_part14_mat1_textures,
    32,
    0,
    64,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x201,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    64,
    32,
    64,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8193,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 255, 179, 91, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* pikachu_hd_part1_mat[] = {
    &pikachu_hd_part1_mat0,
    &pikachu_hd_part1_mat1,
    NULL,
};

Texture* pikachu_hd_part2_mat[] = {
    &pikachu_hd_part2_mat0,
    &pikachu_hd_part2_mat1,
    NULL,
};

Texture* pikachu_hd_part11_mat[] = {
    &pikachu_hd_part11_mat0,
    &pikachu_hd_part11_mat1,
    &pikachu_hd_part11_mat2,
    NULL,
};

Texture* pikachu_hd_part14_mat[] = {
    &pikachu_hd_part14_mat0,
    &pikachu_hd_part14_mat1,
    NULL,
    NULL,
};

#include "assets/pokemon_common/pikachu/hd_model.vtx.inc.c"
#include "assets/pokemon_common/pikachu/hd_first.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part2_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part3_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part3_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part4_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part5_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part6_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part6_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part7_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part8_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part9_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part9_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part10_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part10_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part11_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part11_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part12_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part12_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part13_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part14_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part15_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part15_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part16_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part17_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part17_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part18_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part19_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part20_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part0_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/hd_part1_draw.gfx.inc.c"

DObjPayloadTypeJ pikachu_hd_gfxdata[] = {
    { 1, NULL, pikachu_hd_part0_draw },
    { 4, NULL, NULL },
    { 1, NULL, pikachu_hd_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_first },
    { 4, NULL, NULL },
    { 0, pikachu_hd_part3_pre, pikachu_hd_part3_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part5_draw },
    { 4, NULL, NULL },
    { 0, pikachu_hd_part6_pre, pikachu_hd_part6_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part8_draw },
    { 4, NULL, NULL },
    { 0, pikachu_hd_part9_pre, pikachu_hd_part9_draw },
    { 4, NULL, NULL },
    { 0, pikachu_hd_part10_pre, pikachu_hd_part10_draw },
    { 4, NULL, NULL },
    { 0, pikachu_hd_part11_pre, pikachu_hd_part11_draw },
    { 4, NULL, NULL },
    { 0, pikachu_hd_part12_pre, pikachu_hd_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part13_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part14_draw },
    { 4, NULL, NULL },
    { 0, pikachu_hd_part15_pre, pikachu_hd_part15_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part16_draw },
    { 4, NULL, NULL },
    { 0, pikachu_hd_part17_pre, pikachu_hd_part17_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part18_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part19_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_hd_part20_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 pikachu_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &pikachu_hd_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &pikachu_hd_gfxdata[2],
      { 0.0, -44.76970291137695, -35.951087951660156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.5 } },
    { 1,
      &pikachu_hd_gfxdata[4],
      { 0.0, 138.40377807617188, -41.69654083251953 },
      { 0.33080199360847473, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pikachu_hd_gfxdata[6],
      { 93.83614349365234, -17.212188720703125, 32.83231735229492 },
      { 2.851106882095337, 0.15676000714302063, 0.05162300169467926 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_hd_gfxdata[8],
      { -17.67426109313965, 64.5759506225586, -70.194091796875 },
      { -5.030538082122803, -0.06969799846410751, 0.006132000125944614 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_hd_gfxdata[10],
      { -2.318614959716797, 81.50891876220703, 2.0397210121154785 },
      { -4.1898579597473145, -3.106484889984131, 3.146878957748413 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pikachu_hd_gfxdata[12],
      { -93.83614349365234, -17.212223052978516, 32.832252502441406 },
      { -0.2904849946498871, -2.9848320484161377, 3.089970111846924 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_hd_gfxdata[14],
      { 17.674213409423828, 64.57587432861328, -70.19412994384766 },
      { -1.8889449834823608, 3.071894884109497, -3.1477251052856445 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_hd_gfxdata[16],
      { 2.3186209201812744, 81.50892639160156, 2.0397250652313232 },
      { 2.093327045440674, 3.106484889984131, 3.136306047439575 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pikachu_hd_gfxdata[18],
      { -3.000000106112566e-06, 61.8001594543457, 21.765613555908203 },
      { 0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_hd_gfxdata[20],
      { 7.999999979801942e-06, 67.48809814453125, -10.178316116333008 },
      { -0.06810200214385986, 1.9999999949504854e-06, -9.999999974752427e-07 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_hd_gfxdata[22],
      { 73.8786849975586, 108.0729751586914, -4.5952558517456055 },
      { 1.1116750240325928, -1.9170860052108765, -2.150857925415039 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 4,
      &pikachu_hd_gfxdata[24],
      { -73.87841033935547, 107.21485900878906, -3.857862949371338 },
      { 1.1516200304031372, -4.347515106201172, 2.172128915786743 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 4,
      &pikachu_hd_gfxdata[26],
      { -1.2000000424450263e-05, 27.6944637298584, 81.45343780517578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8195,
      &pikachu_hd_gfxdata[28],
      { 3.000000106112566e-06, -16.672325134277344, -113.29735565185547 },
      { -0.4560549855232239, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_hd_gfxdata[30],
      { 83.26800537109375, 33.24196243286133, 44.594322204589844 },
      { -1.215994954109192, -3.8306219577789307, 4.004708766937256 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_hd_gfxdata[32],
      { -0.035321999341249466, 44.27967834472656, 0.035346001386642456 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_hd_gfxdata[34],
      { -83.03949737548828, 33.24196243286133, 44.594322204589844 },
      { 5.067191123962402, 3.8306219577789307, 2.2784759998321533 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_hd_gfxdata[36],
      { 0.03528600186109543, 44.279693603515625, 0.03531000018119812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32773,
      &pikachu_hd_gfxdata[38],
      { 22.201560974121094, 91.90438842773438, -12.546659469604492 },
      { -2.2537410259246826, 0.6052389740943909, -0.914546012878418 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pikachu_hd_gfxdata[40],
      { 0.016579000279307365, -74.57996368408203, -42.38225173950195 },
      { 2.3109469413757324, 3.1415929794311523, 3.1415929794311523 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
