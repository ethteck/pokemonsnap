#include "common.h"

extern u8 dratini_tex_801599E8[];
extern u8 dratini_tex_801599F8_png[];
extern u8 dratini_tex_80159E00[];
extern u8 dratini_tex_8015A008[];
extern u8 dratini_tex_8015AA18[];
extern u8 dratini_tex_8015B428[];
extern u8 dratini_tex_8015BC30[];
extern u8 dratini_tex_8015BCB8_png[];
extern u8 dratini_tex_8015C0C0[];
extern u8 dratini_tex_8015C280_png[];
extern u8 dratini_tex_8015C688[];
extern u8 dratini_tex_8015C6C8_png[];

extern Texture* dratini_part5_mat[];
extern Gfx dratini_part0_draw[];

Texture** dratini_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    dratini_part5_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* dratini_part5_mat0_textures[] = {
    dratini_tex_8015A008,
    dratini_tex_8015AA18,
    dratini_tex_8015B428,
    NULL,
};

Texture dratini_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    dratini_part5_mat0_textures,
    128,
    64,
    32,
    64,
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
    64,
    32,
    64,
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

Texture* dratini_part5_mat[] = {
    &dratini_part5_mat0,
    NULL,
};

#include "assets/valley/dratini/model.vtx.inc.c"
#include "assets/valley/dratini/first.gfx.inc.c"
#include "assets/valley/dratini/part0_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part0_draw.gfx.inc.c"
#include "assets/valley/dratini/part1_pre_near.gfx.inc.c"
#include "assets/valley/dratini/part1_pre.gfx.inc.c"
#include "assets/valley/dratini/part1_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part1_draw.gfx.inc.c"
#include "assets/valley/dratini/part2_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part2_draw.gfx.inc.c"
#include "assets/valley/dratini/part3_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part3_draw.gfx.inc.c"
#include "assets/valley/dratini/part4_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part4_draw.gfx.inc.c"
#include "assets/valley/dratini/part5_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part5_draw.gfx.inc.c"
#include "assets/valley/dratini/part6_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part6_draw.gfx.inc.c"
#include "assets/valley/dratini/part7_pre_near.gfx.inc.c"
#include "assets/valley/dratini/part7_pre.gfx.inc.c"
#include "assets/valley/dratini/part7_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part7_draw.gfx.inc.c"
#include "assets/valley/dratini/part8_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part8_draw.gfx.inc.c"
#include "assets/valley/dratini/part9_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part9_draw.gfx.inc.c"
#include "assets/valley/dratini/part10_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part10_draw.gfx.inc.c"
#include "assets/valley/dratini/part11_draw_near.gfx.inc.c"
#include "assets/valley/dratini/part11_draw.gfx.inc.c"
#include "assets/valley/dratini/last.gfx.inc.c"

DObjPayloadTypeI dratini_gfxdata[] = {
    { NULL, dratini_first },
    { dratini_part1_pre, dratini_part1_draw },
    { NULL, dratini_part2_draw },
    { NULL, dratini_part3_draw },
    { NULL, dratini_part4_draw },
    { NULL, dratini_part5_draw },
    { NULL, dratini_part6_draw },
    { dratini_part7_pre, dratini_part7_draw },
    { NULL, dratini_part8_draw },
    { NULL, dratini_part9_draw },
    { NULL, dratini_part10_draw },
    { NULL, dratini_last },
};

UnkEC64Arg3 dratini_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 1.4999999621068127e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &dratini_gfxdata[0],
      { 0.0, 44.80000305175781, 1.2000010013580322 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &dratini_gfxdata[1],
      { 0.0, 204.39990234375, -6.000000212225132e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dratini_gfxdata[2],
      { 0.0, 164.00010681152344, 1.9999999949504854e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &dratini_gfxdata[3],
      { 0.0, 130.79995727539062, -9.999999974752427e-07 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &dratini_gfxdata[4],
      { 0.0, 78.80005645751953, -3.999999989900971e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &dratini_gfxdata[5],
      { -94.80000305175781, 140.00010681152344, -20.000141143798828 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &dratini_gfxdata[6],
      { 102.39999389648438, 140.00010681152344, -20.00010108947754 },
      { 0.2540000081062317, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &dratini_gfxdata[7],
      { 0.0, -2.7998061180114746, -4.999999873689376e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dratini_gfxdata[8],
      { 0.0, -194.0001983642578, 7.000000096013537e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &dratini_gfxdata[9],
      { 0.0, -172.7999725341797, 1.2000000424450263e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &dratini_gfxdata[10],
      { 0.0, -208.80007934570312, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &dratini_gfxdata[11],
      { 0.0, -161.59986877441406, 1.2000000424450263e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 0.0, -44.80000305175781, -1.2000160217285156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
