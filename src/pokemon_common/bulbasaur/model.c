#include "common.h"

extern u8 bulbasaur_tex_8011CB58[];
extern u8 bulbasaur_tex_8011CB80_png[];
extern u8 bulbasaur_tex_8011CD88[];
extern u8 bulbasaur_tex_8011CDB0_png[];
extern u8 bulbasaur_tex_8011CFB8[];
extern u8 bulbasaur_tex_8011CFE0[];
extern u8 bulbasaur_tex_8011D210[];
extern u8 bulbasaur_tex_8011D438[];
extern u8 bulbasaur_tex_8011D668[];
extern u8 bulbasaur_tex_8011D870[];
extern u8 bulbasaur_tex_8011DA78_png[];
extern u8 bulbasaur_tex_8011DCA8[];
extern u8 bulbasaur_tex_8011DEB0[];
extern u8 bulbasaur_tex_8011DED8_png[];
extern u8 bulbasaur_tex_8011DFE0[];
extern u8 bulbasaur_tex_8011E008_png[];
extern u8 bulbasaur_tex_8011E0D0[];

extern Texture* bulbasaur_part2_mat[];
extern Gfx bulbasaur_part0_draw[];

Texture** bulbasaur_materials[] = {
    NULL,
    NULL,
    bulbasaur_part2_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* bulbasaur_part2_mat0_textures[] = {
    bulbasaur_tex_8011CFE0,
    bulbasaur_tex_8011D210,
    bulbasaur_tex_8011D438,
    bulbasaur_tex_8011D668,
    bulbasaur_tex_8011DCA8,
};

Texture bulbasaur_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    bulbasaur_part2_mat0_textures,
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
    0xA1,
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
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* bulbasaur_part2_mat[] = {
    &bulbasaur_part2_mat0,
    NULL,
};

#include "assets/pokemon_common/bulbasaur/model.vtx.inc.c"
#include "assets/pokemon_common/bulbasaur/first.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part0_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part0_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part0_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part1_pre_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part1_pre_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part1_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part1_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part1_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part1_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part2_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part2_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part2_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part5_pre_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part5_pre_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part5_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part5_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part5_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part5_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part6_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part6_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part6_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part7_pre_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part7_pre_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part7_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part7_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part7_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part7_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part8_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part8_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part8_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part9_pre_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part9_pre_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part9_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part9_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part9_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part9_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part10_pre_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part10_pre_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part10_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part10_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part10_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part10_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part11_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part11_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part11_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part12_pre_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part12_pre_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part12_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part12_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part12_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part12_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part13_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part13_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part13_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/last.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part3_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part3_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part3_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part4_draw_near.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part4_draw_far.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/part4_draw.gfx.inc.c"

DObjPayloadTypeJ bulbasaur_gfxdata[] = {
    { 0, NULL, bulbasaur_first },
    { 4, NULL, NULL },
    { 0, bulbasaur_part1_pre, bulbasaur_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_part2_draw },
    { 4, NULL, NULL },
    { 1, NULL, bulbasaur_part3_draw },
    { 4, NULL, NULL },
    { 1, NULL, bulbasaur_part4_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_part5_pre, bulbasaur_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_part6_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_part7_pre, bulbasaur_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_part8_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_part9_pre, bulbasaur_part9_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_part10_pre, bulbasaur_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_part11_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_part12_pre, bulbasaur_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_last },
    { 4, NULL, NULL },
};

UnkEC64Arg3 bulbasaur_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &bulbasaur_gfxdata[0],
      { 0.0, 131.853515625, -110.53013610839844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_gfxdata[2],
      { 0.0, 135.11767578125, 290.9105224609375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_gfxdata[4],
      { 0.0, -38.84174728393555, 93.78907775878906 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &bulbasaur_gfxdata[6],
      { 0.0, -131.85357666015625, 110.53021240234375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_gfxdata[8],
      { 0.0, -131.85357666015625, 110.53021240234375 },
      { -1.570796012878418, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_gfxdata[10],
      { 196.7126922607422, 12.61802864074707, 249.01695251464844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_gfxdata[12],
      { 23.287307739257812, -53.96024703979492, 25.600444793701172 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_gfxdata[14],
      { -196.7126922607422, 12.61802864074707, 249.01695251464844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_gfxdata[16],
      { -23.287260055541992, -53.96087646484375, 25.601207733154297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_gfxdata[18],
      { 0.024589000269770622, 205.45623779296875, 42.81279373168945 },
      { -0.47024598717689514, 0.0, -0.00023600000713486224 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_gfxdata[20],
      { 164.2073211669922, -3.8416619300842285, -0.8938789963722229 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_gfxdata[22],
      { 105.7641830444336, 13.533306121826172, 148.10092163085938 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_gfxdata[24],
      { -164.2073211669922, -3.8416619300842285, -0.8938789963722229 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_gfxdata[26],
      { -105.76404571533203, 13.533317565917969, 148.10096740722656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
