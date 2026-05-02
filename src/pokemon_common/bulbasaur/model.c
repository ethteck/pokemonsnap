#include "common.h"

extern Gfx D_0E000000_bulbasaur_model[];

extern u8 bulbasaur_tex_face_spots_pal[];
extern u8 bulbasaur_tex_face_spots_png[];
extern u8 bulbasaur_tex_spots_pal[];
extern u8 bulbasaur_tex_spots_png[];
extern u8 bulbasaur_tex_eye0_pal[];
extern u8 bulbasaur_tex_eye0_png[];
extern u8 bulbasaur_tex_eye1_png[];
extern u8 bulbasaur_tex_eye2_png[];
extern u8 bulbasaur_tex_eye3_png[];
extern u8 bulbasaur_tex_bud_pal[];
extern u8 bulbasaur_tex_bud_png[];
extern u8 bulbasaur_tex_eye4_png[];
extern u8 bulbasaur_tex_mouth_pal[];
extern u8 bulbasaur_tex_mouth_png[];
extern u8 bulbasaur_tex_nostrils_pal[];
extern u8 bulbasaur_tex_nostrils_png[];
extern u8 bulbasaur_tex_shine_png[];

extern u8 D_8011D138_bulbasaur_model[];
extern u8 D_8011D160_bulbasaur_model[];
extern u8 D_8011D368_bulbasaur_model[];
extern u8 D_8011D390_bulbasaur_model[];
extern u8 D_8011D598_bulbasaur_model[];
extern u8 D_8011DE50_bulbasaur_model[];
extern u8 D_8011E058_bulbasaur_model[];
extern u8 D_8011E490_bulbasaur_model[];
extern u8 D_8011E4B8_bulbasaur_model[];
extern u8 D_8011E5C0_bulbasaur_model[];
extern u8 D_8011E5E8_bulbasaur_model[];
extern u8 D_8011E6B0_bulbasaur_model[];
extern u8 D_8033E750_bulbasaur_model[];
extern u8 D_8033E760_bulbasaur_model[];
extern u8 D_8033E770_bulbasaur_model[];
extern u8 D_8033E780_bulbasaur_model[];
extern u8 D_8033E790_bulbasaur_model[];
extern u8 D_8033E7A0_bulbasaur_model[];
extern u8 D_8033E7B0_bulbasaur_model[];
extern u8 D_8033E7C0_bulbasaur_model[];
extern u8 D_8033E7D0_bulbasaur_model[];
extern u8 D_8033E7E0_bulbasaur_model[];
extern u8 D_8033E7F0_bulbasaur_model[];
extern u8 D_8033E800_bulbasaur_model[];
extern u8 D_8033E820_bulbasaur_model[];
extern u8 D_8033E840_bulbasaur_model[];
extern u8 D_8033E850_bulbasaur_model[];
extern u8 D_8033E860_bulbasaur_model[];
extern u8 D_8033E870_bulbasaur_model[];
extern u8 D_8033E880_bulbasaur_model[];
extern u8 D_8033E890_bulbasaur_model[];
extern u8 D_8033E8A0_bulbasaur_model[];
extern u8 D_8033E8B0_bulbasaur_model[];
extern u8 D_8033E8D0_bulbasaur_model[];
extern u8 D_8033E8E0_bulbasaur_model[];
extern u8 D_8033E910_bulbasaur_model[];
extern u8 D_8033E920_bulbasaur_model[];
extern u8 D_8033E930_bulbasaur_model[];
extern u8 D_8033E940_bulbasaur_model[];
extern u8 D_8033E950_bulbasaur_model[];
extern u8 D_8033E980_bulbasaur_model[];
extern u8 D_8033E990_bulbasaur_model[];
extern u8 D_8033E9B0_bulbasaur_model[];
extern u8 D_8033E9E0_bulbasaur_model[];
extern u8 D_8033E9F0_bulbasaur_model[];
extern u8 D_8033EA00_bulbasaur_model[];
extern u8 D_8033EA10_bulbasaur_model[];
extern u8 D_8033EAD0_bulbasaur_model[];
extern u8 D_8033EB40_bulbasaur_model[];
extern u8 D_8033EC00_bulbasaur_model[];
extern u8 D_8033EC30_bulbasaur_model[];
extern u8 D_8033EC50_bulbasaur_model[];
extern u8 D_8033ED50_bulbasaur_model[];
extern u8 D_8033ED80_bulbasaur_model[];
extern u8 D_8033EDB0_bulbasaur_model[];
extern u8 D_8033EDD0_bulbasaur_model[];
extern u8 D_8033EE10_bulbasaur_model[];
extern u8 D_8033EE50_bulbasaur_model[];
extern u8 D_8033EEA0_bulbasaur_model[];
extern u8 D_8033EED0_bulbasaur_model[];
extern u8 D_8033EF00_bulbasaur_model[];
extern u8 D_8033EF40_bulbasaur_model[];
extern u8 D_8033EFA0_bulbasaur_model[];
extern u8 D_8033F060_bulbasaur_model[];
extern u8 D_8033F090_bulbasaur_model[];
extern u8 D_8033F0D0_bulbasaur_model[];
extern u8 D_8033F110_bulbasaur_model[];
extern u8 D_8033F1D0_bulbasaur_model[];
extern u8 D_8033F220_bulbasaur_model[];
extern u8 D_8033F250_bulbasaur_model[];
extern u8 D_8033F3C0_bulbasaur_model[];
extern u8 D_8033F440_bulbasaur_model[];
extern u8 D_8033F590_bulbasaur_model[];
extern u8 D_8033F5D0_bulbasaur_model[];
extern u8 D_8033F630_bulbasaur_model[];
extern u8 D_PAL_8033F750_557480[];
extern u8 D_PAL_80340760_558490[];
extern u8 D_PAL_80340908_558638[];
extern u8 D_PAL_80340A30_558760[];
extern u8 D_PAL_80340A60_558790[];
extern u8 D_PAL_80340AC8_5587F8[];
extern u8 D_PAL_80340B30_558860[];
extern u8 D_PAL_80340F20_558C50[];
extern u8 D_PAL_80341220_558F50[];
extern u8 D_PAL_80341378_5590A8[];
extern u8 D_PAL_803414C0_5591F0[];
extern u8 D_PAL_80341508_559238[];
extern u8 D_PAL_80341578_5592A8[];
extern u8 D_PAL_80341660_559390[];
extern u8 D_PAL_803418D8_559608[];
extern u8 D_PAL_803419E0_559710[];
extern u8 D_PAL_80341A28_559758[];
extern u8 D_PAL_80341A98_5597C8[];
extern u8 D_PAL_80341B80_5598B0[];
extern u8 D_PAL_80341C98_5599C8[];
extern u8 D_PAL_80341DB8_559AE8[];
extern u8 D_PAL_80341EC0_559BF0[];
extern u8 D_PAL_80341F18_559C48[];
extern u8 D_PAL_80341F98_559CC8[];
extern u8 D_PAL_803421B0_559EE0[];
extern u8 D_PAL_80342418_55A148[];
extern u8 D_PAL_80342470_55A1A0[];
extern u8 D_PAL_803424E0_55A210[];
extern u8 D_PAL_803425F0_55A320[];
extern u8 D_PAL_80342730_55A460[];
extern u8 D_PAL_803428C8_55A5F8[];
extern u8 D_PAL_803429F0_55A720[];
extern u8 D_PAL_80342A48_55A778[];
extern u8 D_PAL_80342AB8_55A7E8[];
extern u8 D_PAL_80342BB8_55A8E8[];
extern u8 D_PAL_80342CD0_55AA00[];
extern u8 D_PAL_80342E60_55AB90[];
extern u8 D_PAL_80342F68_55AC98[];
extern u8 D_PAL_80342FB8_55ACE8[];
extern u8 D_PAL_80343078_55ADA8[];
extern u8 D_PAL_80343168_55AE98[];
extern u8 D_PAL_80343228_55AF58[];

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
    bulbasaur_tex_eye0_png,
    bulbasaur_tex_eye1_png,
    bulbasaur_tex_eye2_png,
    bulbasaur_tex_eye3_png,
    bulbasaur_tex_eye4_png,
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
