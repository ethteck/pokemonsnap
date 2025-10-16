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
extern u8 pikachu_tex_801041D0_png[];
extern u8 pikachu_tex_80108F88_png[];
extern u8 pikachu_tex_801090B8_png[];
extern u8 pikachu_tex_801091E8_png[];
extern u8 pikachu_tex_80101FB8[];
extern u8 pikachu_tex_80102FC0[];
extern u8 pikachu_tex_80103FC8[];
extern u8 pikachu_tex_80104DE8[];
extern u8 pikachu_tex_80104E70[];
extern u8 pikachu_tex_801052D0[];
extern u8 pikachu_tex_80107120[];
extern u8 pikachu_tex_80108F70[];
extern u8 pikachu_tex_80109090[];
extern u8 pikachu_tex_801091C0[];

extern Texture* pikachu_part1_mat[];
extern Texture* pikachu_part2_mat[];
extern Texture* pikachu_part11_mat[];
extern Texture* pikachu_part14_mat[];
extern Gfx pikachu_part2_draw[];

Texture** pikachu_materials[] = {
    NULL,
    pikachu_part1_mat,
    pikachu_part2_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    pikachu_part11_mat,
    NULL,
    NULL,
    pikachu_part14_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* pikachu_part1_mat0_textures[] = {
    pikachu_tex_801045D8,
    pikachu_tex_801049E0,
};

u8* pikachu_part1_mat1_textures[] = {
    pikachu_tex_801049E0,
    pikachu_tex_801045D8,
};

u8* pikachu_part2_mat0_textures[] = {
    pikachu_tex_800FFF98,
    pikachu_tex_801007A0,
    pikachu_tex_80100FA8,
    pikachu_tex_801017B0,
    pikachu_tex_801017B0,
};

u8* pikachu_part2_mat1_textures[] = {
    pikachu_tex_800FFF98,
    pikachu_tex_801007A0,
    pikachu_tex_80100FA8,
    pikachu_tex_801017B0,
    pikachu_tex_801017B0,
};

u8* pikachu_part11_mat0_textures[] = {
    pikachu_tex_801054D8,
    pikachu_tex_80105AE8,
    pikachu_tex_801060F8,
    pikachu_tex_80106708,
    pikachu_tex_80106D18,
};

u8* pikachu_part11_mat1_textures[] = {
    pikachu_tex_80104E98,
    pikachu_tex_801050C8,
};

u8* pikachu_part11_mat2_textures[] = {
    pikachu_tex_80107328,
    pikachu_tex_80107938,
    pikachu_tex_80107F48,
    pikachu_tex_80108558,
    pikachu_tex_80108B68,
};

u8* pikachu_part14_mat0_textures[] = {
    pikachu_tex_801045D8,
    pikachu_tex_801049E0,
};

u8* pikachu_part14_mat1_textures[] = {
    pikachu_tex_801049E0,
    pikachu_tex_801045D8,
};

Texture pikachu_part1_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_part1_mat0_textures,
    128,
    64,
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
    { 255, 255, 255, 179 },
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

Texture pikachu_part1_mat1 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_part1_mat1_textures,
    128,
    64,
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
    { 255, 159, 64, 179 },
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

Texture pikachu_part2_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_part2_mat0_textures,
    128,
    64,
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

Texture pikachu_part2_mat1 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_part2_mat1_textures,
    128,
    64,
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

Texture pikachu_part11_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    pikachu_part11_mat0_textures,
    128,
    64,
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

Texture pikachu_part11_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    pikachu_part11_mat1_textures,
    128,
    64,
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

Texture pikachu_part11_mat2 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    pikachu_part11_mat2_textures,
    128,
    64,
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

Texture pikachu_part14_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_part14_mat0_textures,
    128,
    64,
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

Texture pikachu_part14_mat1 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    pikachu_part14_mat1_textures,
    128,
    64,
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

Texture* pikachu_part1_mat[] = {
    &pikachu_part1_mat0,
    &pikachu_part1_mat1,
    NULL,
};

Texture* pikachu_part2_mat[] = {
    &pikachu_part2_mat0,
    &pikachu_part2_mat1,
    NULL,
};

Texture* pikachu_part11_mat[] = {
    &pikachu_part11_mat0,
    &pikachu_part11_mat1,
    &pikachu_part11_mat2,
    NULL,
};

Texture* pikachu_part14_mat[] = {
    &pikachu_part14_mat0,
    &pikachu_part14_mat1,
    NULL,
    NULL,
};

#include "assets/pokemon_common/pikachu/model.vtx.inc.c"
#include "assets/pokemon_common/pikachu/first.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part2_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part2_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part2_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part3_pre_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part3_pre_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part3_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part3_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part3_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part3_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part4_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part4_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part4_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part5_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part5_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part5_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part6_pre_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part6_pre_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part6_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part6_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part6_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part6_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part7_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part7_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part7_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part8_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part8_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part8_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part9_pre_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part9_pre_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part9_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part9_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part9_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part9_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part10_pre_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part10_pre_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part10_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part10_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part10_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part10_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part11_pre_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part11_pre_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part11_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part11_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part11_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part11_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part12_pre_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part12_pre_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part12_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part12_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part12_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part12_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part13_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part13_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part13_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part14_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part14_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part14_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part15_pre_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part15_pre_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part15_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part15_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part15_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part15_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part16_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part16_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part16_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part17_pre_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part17_pre_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part17_pre.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part17_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part17_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part17_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part18_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part18_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part18_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part19_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part19_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part19_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part20_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part20_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part20_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/last.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part0_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part0_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part0_draw.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part1_draw_near.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part1_draw_far.gfx.inc.c"
#include "assets/pokemon_common/pikachu/part1_draw.gfx.inc.c"

DObjPayloadTypeJ pikachu_gfxdata[] = {
    { 1, NULL, pikachu_part0_draw },
    { 4, NULL, NULL },
    { 1, NULL, pikachu_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_first },
    { 4, NULL, NULL },
    { 0, pikachu_part3_pre, pikachu_part3_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part5_draw },
    { 4, NULL, NULL },
    { 0, pikachu_part6_pre, pikachu_part6_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part8_draw },
    { 4, NULL, NULL },
    { 0, pikachu_part9_pre, pikachu_part9_draw },
    { 4, NULL, NULL },
    { 0, pikachu_part10_pre, pikachu_part10_draw },
    { 4, NULL, NULL },
    { 0, pikachu_part11_pre, pikachu_part11_draw },
    { 4, NULL, NULL },
    { 0, pikachu_part12_pre, pikachu_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part13_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part14_draw },
    { 4, NULL, NULL },
    { 0, pikachu_part15_pre, pikachu_part15_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part16_draw },
    { 4, NULL, NULL },
    { 0, pikachu_part17_pre, pikachu_part17_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part18_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_part19_draw },
    { 4, NULL, NULL },
    { 0, NULL, pikachu_last },
    { 4, NULL, NULL },
};

UnkEC64Arg3 pikachu_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &pikachu_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 1.1862000226974487, 0.0 },
      { 0.7266420125961304, 1.1526060104370117, 1.1288809776306152 } },
    { 1,
      &pikachu_gfxdata[2],
      { 0.0, -44.76969528198242, -35.951087951660156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.5 } },
    { 1,
      &pikachu_gfxdata[4],
      { 0.0, 138.40377807617188, -41.69654083251953 },
      { 0.33080199360847473, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pikachu_gfxdata[6],
      { 93.83614349365234, -17.212188720703125, 32.83232498168945 },
      { 2.851106882095337, 0.15676000714302063, 0.05162300169467926 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_gfxdata[8],
      { -17.674238204956055, 64.57586669921875, -70.19403839111328 },
      { -5.030538082122803, -0.06969799846410751, 0.006132000125944614 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_gfxdata[10],
      { -2.318603038787842, 81.50890350341797, 2.039720058441162 },
      { -4.1898579597473145, -3.106484889984131, 3.146878957748413 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pikachu_gfxdata[12],
      { -93.83615112304688, -17.212223052978516, 32.832252502441406 },
      { -0.2904849946498871, -2.9848320484161377, 3.089970111846924 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_gfxdata[14],
      { 17.67426109313965, 64.57586669921875, -70.19415283203125 },
      { -1.8889460563659668, 3.071894884109497, -3.1477251052856445 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_gfxdata[16],
      { 2.318627119064331, 81.5089340209961, 2.0397191047668457 },
      { 2.0933279991149902, 3.106484889984131, 3.136306047439575 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pikachu_gfxdata[18],
      { -9.999999747378752e-06, 61.8001708984375, 21.765613555908203 },
      { 0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_gfxdata[20],
      { 3.000000106112566e-06, 67.48808288574219, -10.178303718566895 },
      { -0.06810099631547928, 1.9999999949504854e-06, -9.999999974752427e-07 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_gfxdata[22],
      { 73.878662109375, 108.07316589355469, -4.595160007476807 },
      { 1.1116739511489868, -1.9170869588851929, -2.1508569717407227 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_gfxdata[24],
      { -73.87837982177734, 107.21480560302734, -3.8579230308532715 },
      { 1.1516200304031372, -4.3475141525268555, 2.1721279621124268 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 4,
      &pikachu_gfxdata[26],
      { 0.0, 27.6944637298584, 81.45345306396484 },
      { -4.8099188804626465, 3.018270969390869, -3.1843690872192383 },
      { 1.1938740015029907, 0.40268799662590027, 0.8363710045814514 } },
    { 8195,
      &pikachu_gfxdata[28],
      { 3.000000106112566e-06, -16.672325134277344, -113.29735565185547 },
      { -0.4560549855232239, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_gfxdata[30],
      { 83.26799774169922, 33.24195098876953, 44.59433364868164 },
      { -1.2159940004348755, -3.8306219577789307, 4.004708766937256 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_gfxdata[32],
      { -0.0352259986102581, 44.2796630859375, 0.03533399850130081 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pikachu_gfxdata[34],
      { -83.03948974609375, 33.24192810058594, 44.59432601928711 },
      { 5.067191123962402, 3.8306219577789307, 2.2784759998321533 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &pikachu_gfxdata[36],
      { 0.03531600162386894, 44.27967071533203, 0.035346001386642456 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32773,
      &pikachu_gfxdata[38],
      { 22.2015380859375, 91.90440368652344, -12.546682357788086 },
      { -2.2537410259246826, 0.6052380204200745, -0.914546012878418 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pikachu_gfxdata[40],
      { 0.016579000279307365, -73.92396545410156, -43.530399322509766 },
      { 2.3109469413757324, 3.1415929794311523, 3.1415929794311523 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
