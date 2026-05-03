#include "common.h"

extern u8 weepinbell_tex_801A56B8[];
extern u8 weepinbell_tex_801A56E0[];
extern u8 weepinbell_tex_801A5708[];
extern u8 weepinbell_tex_801A5730[];
extern u8 weepinbell_tex_801A5758_png[];
extern u8 weepinbell_tex_801A5988[];
extern u8 weepinbell_tex_801A61B8[];
extern u8 weepinbell_tex_801A69E8[];
extern u8 weepinbell_tex_801A7218[];
extern u8 weepinbell_tex_801A7A20[];
extern u8 weepinbell_tex_801A7A48[];

__ALIGNER
u8 weepinbell_tex_8033A0F8[] = {
#include "assets/cave/weepinbell/tex_8033A120.pal.bin.c"
};

__ALIGNER
u8 weepinbell_tex_8033A120_png[] = {
#include "assets/cave/weepinbell/tex_8033A120.png.bin.c"
};

__ALIGNER
u8 weepinbell_tex_8033A528[] = {
#include "assets/cave/weepinbell/tex_8033A550.pal.bin.c"
};

__ALIGNER
u8 weepinbell_tex_8033A550_png[] = {
#include "assets/cave/weepinbell/tex_8033A550.png.bin.c"
};

__ALIGNER
u8 weepinbell_tex_8033A758[] = {
#include "assets/cave/weepinbell/tex_8033A780.pal.bin.c"
};

__ALIGNER
u8 weepinbell_tex_8033A780_png[] = {
#include "assets/cave/weepinbell/tex_8033A780.png.bin.c"
};

extern Texture* weepinbell_part14_mat[];
extern Gfx weepinbell_part0_draw[];

Texture** weepinbell_materials[] = {
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
    NULL,
    NULL,
    weepinbell_part14_mat,
    NULL,
    NULL,
};

u8* weepinbell_part14_mat0_textures[] = {
    weepinbell_tex_801A7A48,
    weepinbell_tex_801A5988,
    weepinbell_tex_801A7218,
    weepinbell_tex_801A69E8,
    weepinbell_tex_801A61B8,
};

u8* weepinbell_part14_mat1_textures[] = {
    weepinbell_tex_801A7A48,
    weepinbell_tex_801A5988,
    weepinbell_tex_801A61B8,
    weepinbell_tex_801A69E8,
    weepinbell_tex_801A7218,
    NULL,
};

Texture weepinbell_part14_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    weepinbell_part14_mat0_textures,
    128,
    64,
    64,
    64,
    0,
    -0.5,
    -0.5,
    2.0,
    2.0,
    -0.5,
    2.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64,
    64,
    64,
    64,
    -0.5,
    -0.5,
    -0.5,
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

Texture weepinbell_part14_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    weepinbell_part14_mat1_textures,
    128,
    64,
    64,
    64,
    0,
    -0.5,
    -0.5,
    2.0,
    2.0,
    -0.5,
    2.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64,
    64,
    64,
    64,
    -0.5,
    -0.5,
    -0.5,
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

Texture* weepinbell_part14_mat[] = {
    &weepinbell_part14_mat0,
    &weepinbell_part14_mat1,
    NULL,
    NULL,
};

#include "assets/cave/weepinbell/model.vtx.inc.c"
#include "assets/cave/weepinbell/first.gfx.inc.c"
#include "assets/cave/weepinbell/part0_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part0_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part0_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part1_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part1_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part1_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part2_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part2_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part2_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part3_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part3_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part3_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part4_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part4_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part4_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part5_pre_near.gfx.inc.c"
#include "assets/cave/weepinbell/part5_pre_far.gfx.inc.c"
#include "assets/cave/weepinbell/part5_pre.gfx.inc.c"
#include "assets/cave/weepinbell/part5_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part5_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part5_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part6_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part6_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part6_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part7_pre_near.gfx.inc.c"
#include "assets/cave/weepinbell/part7_pre_far.gfx.inc.c"
#include "assets/cave/weepinbell/part7_pre.gfx.inc.c"
#include "assets/cave/weepinbell/part7_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part7_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part7_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part8_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part8_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part8_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part9_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part9_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part9_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part10_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part10_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part10_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part11_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part11_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part11_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part12_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part12_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part12_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part13_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part13_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part13_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part14_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part14_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part14_draw.gfx.inc.c"
#include "assets/cave/weepinbell/part15_draw_near.gfx.inc.c"
#include "assets/cave/weepinbell/part15_draw_far.gfx.inc.c"
#include "assets/cave/weepinbell/part15_draw.gfx.inc.c"
#include "assets/cave/weepinbell/last.gfx.inc.c"

DObjPayloadTypeI weepinbell_gfxdata[] = {
    { NULL, weepinbell_first },
    { NULL, weepinbell_part1_draw },
    { NULL, weepinbell_part2_draw },
    { NULL, weepinbell_part3_draw },
    { NULL, weepinbell_part4_draw },
    { weepinbell_part5_pre, weepinbell_part5_draw },
    { NULL, weepinbell_part6_draw },
    { weepinbell_part7_pre, weepinbell_part7_draw },
    { NULL, weepinbell_part8_draw },
    { NULL, weepinbell_part9_draw },
    { NULL, weepinbell_part10_draw },
    { NULL, weepinbell_part11_draw },
    { NULL, weepinbell_part12_draw },
    { NULL, weepinbell_part13_draw },
    { NULL, weepinbell_part14_draw },
    { NULL, weepinbell_last },
};

UnkEC64Arg3 weepinbell_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &weepinbell_gfxdata[0],
      { 0.0, 195.35000610351562, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &weepinbell_gfxdata[1],
      { 0.0, -50.349998474121094, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &weepinbell_gfxdata[2],
      { -9.999999974752427e-07, -145.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &weepinbell_gfxdata[3],
      { 0.0, -235.00001525878906, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9927499890327454, 1.0, 0.9024999737739563 } },
    { 5,
      &weepinbell_gfxdata[4],
      { -3.000000106112566e-06, -40.00000762939453, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9545459747314453, 1.0, 1.0499999523162842 } },
    { 6,
      &weepinbell_gfxdata[5],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &weepinbell_gfxdata[6],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &weepinbell_gfxdata[7],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &weepinbell_gfxdata[8],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &weepinbell_gfxdata[9],
      { 200.0, -145.0, 6.0000410079956055 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &weepinbell_gfxdata[10],
      { 305.0000305175781, -2.700000004551839e-05, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &weepinbell_gfxdata[11],
      { -200.0, -145.0, 6.0000410079956055 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &weepinbell_gfxdata[12],
      { -305.0, -2.2000000171829015e-05, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &weepinbell_gfxdata[13],
      { 0.0, -185.0, 179.5 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &weepinbell_gfxdata[14],
      { 0.0, 199.8402557373047, 25.642061233520508 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &weepinbell_gfxdata[15],
      { 0.0, 200.63323974609375, 17.553239822387695 },
      { 0.0872659981250763, 0.0, 0.0 },
      { 1.100000023841858, 1.100000023841858, 1.100000023841858 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
