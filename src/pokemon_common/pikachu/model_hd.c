#include "common.h"

extern Gfx D_0E000000_pikachu_model_hd[];
extern Gfx D_0E000008_pikachu_model_hd[];
extern Gfx D_0E000010_pikachu_model_hd[];

extern u8 pikachu_tex_lightning0_png[];
extern u8 pikachu_tex_lightning1_png[];
extern u8 pikachu_tex_lightning2_png[];
extern u8 pikachu_tex_lightning3_png[];
extern u8 pikachu_tex_07_png[];
extern u8 pikachu_tex_08_png[];
extern u8 pikachu_tex_cheek0_png[];
extern u8 pikachu_tex_cheek1_png[];
extern u8 pikachu_tex_mouth0_png[];
extern u8 pikachu_tex_mouth1_png[];
extern u8 pikachu_tex_mouth2_png[];
extern u8 pikachu_tex_mouth3_png[];
extern u8 pikachu_tex_mouth4_png[];
extern u8 pikachu_tex_eye0_png[];
extern u8 pikachu_tex_eye1_png[];
extern u8 pikachu_tex_eye2_png[];
extern u8 pikachu_tex_eye3_png[];
extern u8 pikachu_tex_eye4_png[];
extern u8 pikachu_tex_back_pal[];
extern u8 pikachu_tex_back_png[];
extern u8 pikachu_tex_body_png[];
extern u8 pikachu_tex_eye0_pal[];
extern u8 pikachu_tex_cheek0_pal[];
extern u8 pikachu_tex_mouth0_pal[];
extern u8 pikachu_tex_ear_pal[];
extern u8 pikachu_tex_ear_png[];
extern u8 pikachu_tex_balloon1_png[];
extern u8 pikachu_tex_balloon0_png[];
extern u8 pikachu_tex_apple_pal[];
extern u8 pikachu_tex_apple_png[];
extern u8 pikachu_tex_tail_pal[];
extern u8 pikachu_tex_tail_png[];

extern u8 D_80102598_pikachu_model_hd[];
extern u8 D_801035A0_pikachu_model_hd[];
extern u8 D_801045A8_pikachu_model_hd[];
extern u8 D_801047B0_pikachu_model_hd[];
extern u8 D_801053C8_pikachu_model_hd[];
extern u8 D_80105450_pikachu_model_hd[];
extern u8 D_801058B0_pikachu_model_hd[];
extern u8 D_80107700_pikachu_model_hd[];
extern u8 D_80109550_pikachu_model_hd[];
extern u8 D_80109568_pikachu_model_hd[];
extern u8 D_80109670_pikachu_model_hd[];
extern u8 D_80109698_pikachu_model_hd[];
extern u8 D_801097A0_pikachu_model_hd[];
extern u8 D_801097C8_pikachu_model_hd[];
extern u8 D_PAL_803ADAC0_832480[];
extern u8 D_PAL_803ADAE0_8324A0[];
extern u8 D_PAL_803ADB10_8324D0[];
extern u8 D_PAL_803ADB50_832510[];
extern u8 D_PAL_803ADB70_832530[];
extern u8 D_PAL_803ADB80_832540[];
extern u8 D_PAL_803ADBF0_8325B0[];
extern u8 D_PAL_803ADC10_8325D0[];
extern u8 D_PAL_803ADC20_8325E0[];
extern u8 D_PAL_803ADC30_8325F0[];
extern u8 D_PAL_803ADC40_832600[];
extern u8 D_PAL_803ADC50_832610[];
extern u8 D_PAL_803ADC60_832620[];
extern u8 D_PAL_803ADC70_832630[];
extern u8 D_PAL_803ADC90_832650[];
extern u8 D_PAL_803ADCB0_832670[];
extern u8 D_PAL_803ADCC0_832680[];
extern u8 D_PAL_803ADCD0_832690[];
extern u8 D_PAL_803ADCE0_8326A0[];
extern u8 D_PAL_803ADD10_8326D0[];
extern u8 D_PAL_803ADD30_8326F0[];
extern u8 D_PAL_803ADD60_832720[];
extern u8 D_PAL_803ADD70_832730[];
extern u8 D_PAL_803ADD90_832750[];
extern u8 D_PAL_803ADDE0_8327A0[];
extern u8 D_PAL_803ADDF0_8327B0[];
extern u8 D_PAL_803ADE00_8327C0[];
extern u8 D_PAL_803ADE10_8327D0[];
extern u8 D_PAL_803ADE20_8327E0[];
extern u8 D_PAL_803ADE30_8327F0[];
extern u8 D_PAL_803ADE40_832800[];
extern u8 D_PAL_803ADE50_832810[];
extern u8 D_PAL_803ADE60_832820[];
extern u8 D_PAL_803ADE70_832830[];
extern u8 D_PAL_803ADE80_832840[];
extern u8 D_PAL_803ADE90_832850[];
extern u8 D_PAL_803ADF20_8328E0[];
extern u8 D_PAL_803AFB68_834528[];

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
    pikachu_tex_07_png,
    pikachu_tex_08_png,
};

u8* pikachu_hd_part1_mat1_textures[] = {
    pikachu_tex_08_png,
    pikachu_tex_07_png,
};

u8* pikachu_hd_part2_mat0_textures[] = {
    pikachu_tex_lightning0_png,
    pikachu_tex_lightning1_png,
    pikachu_tex_lightning2_png,
    pikachu_tex_lightning3_png,
    pikachu_tex_lightning3_png,
};

u8* pikachu_hd_part2_mat1_textures[] = {
    pikachu_tex_lightning0_png,
    pikachu_tex_lightning1_png,
    pikachu_tex_lightning2_png,
    pikachu_tex_lightning3_png,
    pikachu_tex_lightning3_png,
};

u8* pikachu_hd_part11_mat0_textures[] = {
    pikachu_tex_mouth0_png,
    pikachu_tex_mouth1_png,
    pikachu_tex_mouth2_png,
    pikachu_tex_mouth3_png,
    pikachu_tex_mouth4_png,
};

u8* pikachu_hd_part11_mat1_textures[] = {
    pikachu_tex_cheek0_png,
    pikachu_tex_cheek1_png,
};

u8* pikachu_hd_part11_mat2_textures[] = {
    pikachu_tex_eye0_png,
    pikachu_tex_eye1_png,
    pikachu_tex_eye2_png,
    pikachu_tex_eye3_png,
    pikachu_tex_eye4_png,
};

u8* pikachu_hd_part14_mat0_textures[] = {
    pikachu_tex_07_png,
    pikachu_tex_08_png,
};

u8* pikachu_hd_part14_mat1_textures[] = {
    pikachu_tex_08_png,
    pikachu_tex_07_png,
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
