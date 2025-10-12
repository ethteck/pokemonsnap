#include "common.h"

extern u8 bulbasaur_tex_8011CB80_png[];
extern u8 bulbasaur_tex_8011CDB0_png[];
extern u8 bulbasaur_tex_8011DA78_png[];
extern u8 bulbasaur_tex_8011DED8_png[];
extern u8 bulbasaur_tex_8011E008_png[];
extern u8 bulbasaur_tex_8011E0D0[];
extern u8 bulbasaur_tex_8011CB58[];
extern u8 bulbasaur_tex_8011CD88[];
extern u8 bulbasaur_tex_8011CFB8[];
extern u8 bulbasaur_tex_8011D870[];
extern u8 bulbasaur_tex_8011DEB0[];
extern u8 bulbasaur_tex_8011DFE0[];
extern u8 bulbasaur_tex_8011CFE0[];
extern u8 bulbasaur_tex_8011D210[];
extern u8 bulbasaur_tex_8011D438[];
extern u8 bulbasaur_tex_8011D668[];
extern u8 bulbasaur_tex_8011DCA8[];

extern Texture* bulbasaur_hd_part2_mat[];
extern Gfx bulbasaur_hd_part0_draw[];
extern Gfx bulbasaur_hd_part3_draw[];

Texture** bulbasaur_hd_materials[] = {
    NULL,
    NULL,
    bulbasaur_hd_part2_mat,
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

u8* bulbasaur_hd_part2_mat0_textures[] = {
    bulbasaur_tex_8011CFE0,
    bulbasaur_tex_8011D210,
    bulbasaur_tex_8011D438,
    bulbasaur_tex_8011D668,
    bulbasaur_tex_8011DCA8,
};

Texture bulbasaur_hd_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    bulbasaur_hd_part2_mat0_textures,
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

Texture* bulbasaur_hd_part2_mat[] = {
    &bulbasaur_hd_part2_mat0,
    NULL,
};

#include "assets/pokemon_common/bulbasaur/hd_model.vtx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_first.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part0_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part1_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part1_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part2_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part5_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part5_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part6_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part7_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part7_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part8_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part9_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part9_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part10_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part10_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part11_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part12_pre.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part12_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part13_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_last.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part3_draw.gfx.inc.c"
#include "assets/pokemon_common/bulbasaur/hd_part4_draw.gfx.inc.c"

DObjPayloadTypeJ bulbasaur_hd_gfxdata[] = {
    { 0, NULL, bulbasaur_hd_first },
    { 4, NULL, NULL },
    { 0, bulbasaur_hd_part1_pre, bulbasaur_hd_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_hd_part2_draw },
    { 4, NULL, NULL },
    { 1, NULL, bulbasaur_hd_last },
    { 4, NULL, NULL },
    { 1, NULL, bulbasaur_hd_part4_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_hd_part5_pre, bulbasaur_hd_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_hd_part6_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_hd_part7_pre, bulbasaur_hd_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_hd_part8_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_hd_part9_pre, bulbasaur_hd_part9_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_hd_part10_pre, bulbasaur_hd_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_hd_part11_draw },
    { 4, NULL, NULL },
    { 0, bulbasaur_hd_part12_pre, bulbasaur_hd_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, bulbasaur_hd_part13_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 bulbasaur_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &bulbasaur_hd_gfxdata[0],
      { 0.0, 131.853515625, -110.53013610839844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_hd_gfxdata[2],
      { 0.0, 135.11767578125, 290.9105224609375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_hd_gfxdata[4],
      { 0.0, -38.84174728393555, 93.78907775878906 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &bulbasaur_hd_gfxdata[6],
      { 0.0, -131.85357666015625, 110.53021240234375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &bulbasaur_hd_gfxdata[8],
      { 0.0, -131.85357666015625, 110.53021240234375 },
      { -1.570796012878418, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_hd_gfxdata[10],
      { 196.7126922607422, 12.61802864074707, 249.01695251464844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_hd_gfxdata[12],
      { 23.287307739257812, -53.96024703979492, 25.600433349609375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_hd_gfxdata[14],
      { -196.7126922607422, 12.61802864074707, 249.01695251464844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_hd_gfxdata[16],
      { -23.287260055541992, -53.96087646484375, 25.601207733154297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_hd_gfxdata[18],
      { 0.02459999918937683, 205.45619201660156, 42.812835693359375 },
      { -0.47024598717689514, 0.0, -0.00023600000713486224 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_hd_gfxdata[20],
      { 164.2073211669922, -3.8416619300842285, -0.8938789963722229 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_hd_gfxdata[22],
      { 105.7641830444336, 13.533306121826172, 148.10092163085938 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &bulbasaur_hd_gfxdata[24],
      { -164.2073211669922, -3.8416619300842285, -0.8938789963722229 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &bulbasaur_hd_gfxdata[26],
      { -105.76404571533203, 13.533317565917969, 148.10096740722656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
