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

extern Texture* weepinbell_hd_part14_mat[];
extern Gfx weepinbell_hd_part0_draw[];

Texture** weepinbell_hd_materials[] = {
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
    weepinbell_hd_part14_mat,
    NULL,
    NULL,
};

u8* weepinbell_hd_part14_mat0_textures[] = {
    weepinbell_tex_801A7A48,
    weepinbell_tex_801A5988,
    weepinbell_tex_801A7218,
    weepinbell_tex_801A69E8,
    weepinbell_tex_801A61B8,
};

u8* weepinbell_hd_part14_mat1_textures[] = {
    weepinbell_tex_801A7A48,
    weepinbell_tex_801A5988,
    weepinbell_tex_801A61B8,
    weepinbell_tex_801A69E8,
    weepinbell_tex_801A7218,
    NULL,
};

Texture weepinbell_hd_part14_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    weepinbell_hd_part14_mat0_textures,
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

Texture weepinbell_hd_part14_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    weepinbell_hd_part14_mat1_textures,
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

Texture* weepinbell_hd_part14_mat[] = {
    &weepinbell_hd_part14_mat0,
    &weepinbell_hd_part14_mat1,
    NULL,
    NULL,
};

#include "assets/cave/weepinbell/hd_model.vtx.inc.c"
#include "assets/cave/weepinbell/hd_first.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part0_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part1_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part2_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part3_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part4_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part5_pre.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part5_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part6_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part7_pre.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part7_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part8_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part9_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part10_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part11_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part12_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part13_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part14_draw.gfx.inc.c"
#include "assets/cave/weepinbell/hd_part15_draw.gfx.inc.c"

DObjPayloadTypeI weepinbell_hd_gfxdata[] = {
    { NULL, weepinbell_hd_first },
    { NULL, weepinbell_hd_part1_draw },
    { NULL, weepinbell_hd_part2_draw },
    { NULL, weepinbell_hd_part3_draw },
    { NULL, weepinbell_hd_part4_draw },
    { weepinbell_hd_part5_pre, weepinbell_hd_part5_draw },
    { NULL, weepinbell_hd_part6_draw },
    { weepinbell_hd_part7_pre, weepinbell_hd_part7_draw },
    { NULL, weepinbell_hd_part8_draw },
    { NULL, weepinbell_hd_part9_draw },
    { NULL, weepinbell_hd_part10_draw },
    { NULL, weepinbell_hd_part11_draw },
    { NULL, weepinbell_hd_part12_draw },
    { NULL, weepinbell_hd_part13_draw },
    { NULL, weepinbell_hd_part14_draw },
    { NULL, weepinbell_hd_part15_draw },
};

UnkEC64Arg3 weepinbell_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &weepinbell_hd_gfxdata[0],
      { 0.0, 195.35000610351562, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &weepinbell_hd_gfxdata[1],
      { 0.0, -50.349998474121094, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &weepinbell_hd_gfxdata[2],
      { -9.999999974752427e-07, -145.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &weepinbell_hd_gfxdata[3],
      { 0.0, -235.00001525878906, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9927499890327454, 1.0, 0.9024999737739563 } },
    { 5,
      &weepinbell_hd_gfxdata[4],
      { -3.000000106112566e-06, -40.00000762939453, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9545459747314453, 1.0, 1.0499999523162842 } },
    { 6,
      &weepinbell_hd_gfxdata[5],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &weepinbell_hd_gfxdata[6],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &weepinbell_hd_gfxdata[7],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &weepinbell_hd_gfxdata[8],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &weepinbell_hd_gfxdata[9],
      { 200.0, -145.0, 6.0000410079956055 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &weepinbell_hd_gfxdata[10],
      { 305.0000305175781, -2.700000004551839e-05, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &weepinbell_hd_gfxdata[11],
      { -200.0, -145.0, 6.0000410079956055 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &weepinbell_hd_gfxdata[12],
      { -305.0, -2.2000000171829015e-05, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &weepinbell_hd_gfxdata[13],
      { 0.0, -184.99989318847656, 179.5 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &weepinbell_hd_gfxdata[14],
      { 0.0, 199.8402557373047, 25.642061233520508 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &weepinbell_hd_gfxdata[15],
      { 0.0, 200.63323974609375, 17.553239822387695 },
      { 0.0872659981250763, 0.0, 0.0 },
      { 1.100000023841858, 1.100000023841858, 1.100000023841858 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
