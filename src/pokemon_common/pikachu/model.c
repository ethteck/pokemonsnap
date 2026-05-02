#include "common.h"

extern Gfx D_0E000000_pikachu_model[];
extern Gfx D_0E000008_pikachu_model[];
extern Gfx D_0E000010_pikachu_model[];

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
extern u8 pikachu_tex_apple_png[];
extern u8 pikachu_tex_ear_png[];
extern u8 pikachu_tex_back_png[];
extern u8 pikachu_tex_tail_png[];
extern u8 pikachu_tex_balloon0_png[];
extern u8 pikachu_tex_balloon1_png[];
extern u8 pikachu_tex_apple_pal[];
extern u8 pikachu_tex_body_png[];
extern u8 pikachu_tex_cheek0_pal[];
extern u8 pikachu_tex_mouth0_pal[];
extern u8 pikachu_tex_eye0_pal[];
extern u8 pikachu_tex_ear_pal[];
extern u8 pikachu_tex_back_pal[];
extern u8 pikachu_tex_tail_pal[];

extern u8 D_80102598_pikachu_model[];
extern u8 D_801035A0_pikachu_model[];
extern u8 D_801045A8_pikachu_model[];
extern u8 D_801047B0_pikachu_model[];
extern u8 D_801053C8_pikachu_model[];
extern u8 D_80105450_pikachu_model[];
extern u8 D_801058B0_pikachu_model[];
extern u8 D_80107700_pikachu_model[];
extern u8 D_80109550_pikachu_model[];
extern u8 D_80109568_pikachu_model[];
extern u8 D_80109670_pikachu_model[];
extern u8 D_80109698_pikachu_model[];
extern u8 D_801097A0_pikachu_model[];
extern u8 D_801097C8_pikachu_model[];
extern u8 D_80346BA0_pikachu_model[];
extern u8 D_80346BB0_pikachu_model[];
extern u8 D_80346BD0_pikachu_model[];
extern u8 D_80346C00_pikachu_model[];
extern u8 D_80346C10_pikachu_model[];
extern u8 D_80346C20_pikachu_model[];
extern u8 D_80346C30_pikachu_model[];
extern u8 D_80346CA0_pikachu_model[];
extern u8 D_80346CC0_pikachu_model[];
extern u8 D_80346CD0_pikachu_model[];
extern u8 D_80346D70_pikachu_model[];
extern u8 D_80346DA0_pikachu_model[];
extern u8 D_80346DB0_pikachu_model[];
extern u8 D_80346E10_pikachu_model[];
extern u8 D_80346E40_pikachu_model[];
extern u8 D_80346E70_pikachu_model[];
extern u8 D_80346E80_pikachu_model[];
extern u8 D_80346E90_pikachu_model[];
extern u8 D_80346EA0_pikachu_model[];
extern u8 D_80346EB0_pikachu_model[];
extern u8 D_80346EC0_pikachu_model[];
extern u8 D_80346FE0_pikachu_model[];
extern u8 D_80347030_pikachu_model[];
extern u8 D_803470F0_pikachu_model[];
extern u8 D_80347200_pikachu_model[];
extern u8 D_80347300_pikachu_model[];
extern u8 D_80347350_pikachu_model[];
extern u8 D_80347410_pikachu_model[];
extern u8 D_80347530_pikachu_model[];
extern u8 D_80347540_pikachu_model[];
extern u8 D_80347550_pikachu_model[];
extern u8 D_80347560_pikachu_model[];
extern u8 D_80347570_pikachu_model[];
extern u8 D_80347580_pikachu_model[];
extern u8 D_80347590_pikachu_model[];
extern u8 D_803475B0_pikachu_model[];
extern u8 D_803475D0_pikachu_model[];
extern u8 D_803475E0_pikachu_model[];
extern u8 D_803475F0_pikachu_model[];
extern u8 D_80347600_pikachu_model[];
extern u8 D_80347610_pikachu_model[];
extern u8 D_80347630_pikachu_model[];
extern u8 D_80347640_pikachu_model[];
extern u8 D_PAL_803476E0_54DA80[];
extern u8 D_PAL_803476F0_54DA90[];
extern u8 D_PAL_803477E0_54DB80[];
extern u8 D_PAL_80347850_54DBF0[];
extern u8 D_PAL_80347870_54DC10[];
extern u8 D_PAL_80347880_54DC20[];
extern u8 D_PAL_803478B0_54DC50[];
extern u8 D_PAL_80347930_54DCD0[];
extern u8 D_PAL_803479B0_54DD50[];
extern u8 D_PAL_803479D0_54DD70[];
extern u8 D_PAL_80347A60_54DE00[];
extern u8 D_PAL_80347AD0_54DE70[];
extern u8 D_PAL_80347B20_54DEC0[];
extern u8 D_PAL_80347B70_54DF10[];
extern u8 D_PAL_80349158_54F4F8[];
extern u8 D_PAL_803492C8_54F668[];
extern u8 D_PAL_80349408_54F7A8[];
extern u8 D_PAL_80349438_54F7D8[];
extern u8 D_PAL_803494A0_54F840[];
extern u8 D_PAL_80349528_54F8C8[];
extern u8 D_PAL_80349658_54F9F8[];
extern u8 D_PAL_80349780_54FB20[];
extern u8 D_PAL_80349880_54FC20[];
extern u8 D_PAL_80349970_54FD10[];
extern u8 D_PAL_80349A48_54FDE8[];
extern u8 D_PAL_80349AE8_54FE88[];
extern u8 D_PAL_80349B58_54FEF8[];
extern u8 D_PAL_80349BE0_54FF80[];
extern u8 D_PAL_80349D10_5500B0[];
extern u8 D_PAL_80349E38_5501D8[];
extern u8 D_PAL_80349F30_5502D0[];
extern u8 D_PAL_8034A010_5503B0[];
extern u8 D_PAL_8034A0F0_550490[];
extern u8 D_PAL_8034A190_550530[];
extern u8 D_PAL_8034A208_5505A8[];
extern u8 D_PAL_8034A2A8_550648[];
extern u8 D_PAL_8034A3E8_550788[];
extern u8 D_PAL_8034A5B8_550958[];
extern u8 D_PAL_8034A610_5509B0[];
extern u8 D_PAL_8034A6A8_550A48[];
extern u8 D_PAL_8034AA00_550DA0[];
extern u8 D_PAL_8034ACE8_551088[];
extern u8 D_PAL_8034AD30_5510D0[];
extern u8 D_PAL_8034ADB8_551158[];
extern u8 D_PAL_8034AE90_551230[];
extern u8 D_PAL_8034AF78_551318[];
extern u8 D_PAL_8034AFD0_551370[];
extern u8 D_PAL_8034B128_5514C8[];
extern u8 D_PAL_8034B210_5515B0[];
extern u8 D_PAL_8034B338_5516D8[];
extern u8 D_PAL_8034B488_551828[];
extern u8 D_PAL_8034B578_551918[];
extern u8 D_PAL_8034B690_551A30[];
extern u8 D_PAL_8034B6F0_551A90[];
extern u8 D_PAL_8034B780_551B20[];
extern u8 D_PAL_8034B8A0_551C40[];
extern u8 D_PAL_8034B9A8_551D48[];
extern u8 D_PAL_8034BAD8_551E78[];
extern u8 D_PAL_8034BBE0_551F80[];
extern u8 D_PAL_8034BC40_551FE0[];
extern u8 D_PAL_8034BCD8_552078[];
extern u8 D_PAL_8034BF00_5522A0[];
extern u8 D_PAL_8034C050_5523F0[];
extern u8 D_PAL_8034C158_5524F8[];
extern u8 D_PAL_8034C238_5525D8[];
extern u8 D_PAL_8034C340_5526E0[];
extern u8 D_PAL_8034C438_5527D8[];
extern u8 D_PAL_8034C540_5528E0[];
extern u8 D_PAL_8034C5A8_552948[];
extern u8 D_PAL_8034C828_552BC8[];
extern u8 D_PAL_8034C970_552D10[];

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
    pikachu_tex_07_png,
    pikachu_tex_08_png,
};

u8* pikachu_part1_mat1_textures[] = {
    pikachu_tex_08_png,
    pikachu_tex_07_png,
};

u8* pikachu_part2_mat0_textures[] = {
    pikachu_tex_lightning0_png,
    pikachu_tex_lightning1_png,
    pikachu_tex_lightning2_png,
    pikachu_tex_lightning3_png,
    pikachu_tex_lightning3_png,
};

u8* pikachu_part2_mat1_textures[] = {
    pikachu_tex_lightning0_png,
    pikachu_tex_lightning1_png,
    pikachu_tex_lightning2_png,
    pikachu_tex_lightning3_png,
    pikachu_tex_lightning3_png,
};

u8* pikachu_part11_mat0_textures[] = {
    pikachu_tex_mouth0_png,
    pikachu_tex_mouth1_png,
    pikachu_tex_mouth2_png,
    pikachu_tex_mouth3_png,
    pikachu_tex_mouth4_png,
};

u8* pikachu_part11_mat1_textures[] = {
    pikachu_tex_cheek0_png,
    pikachu_tex_cheek1_png,
};

u8* pikachu_part11_mat2_textures[] = {
    pikachu_tex_eye0_png,
    pikachu_tex_eye1_png,
    pikachu_tex_eye2_png,
    pikachu_tex_eye3_png,
    pikachu_tex_eye4_png,
};

u8* pikachu_part14_mat0_textures[] = {
    pikachu_tex_07_png,
    pikachu_tex_08_png,
};

u8* pikachu_part14_mat1_textures[] = {
    pikachu_tex_08_png,
    pikachu_tex_07_png,
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
