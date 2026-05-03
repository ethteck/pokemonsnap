#include "common.h"

extern u8 shellder2_tex_80182E58[];
extern u8 shellder2_tex_80182E80_png[];
extern u8 shellder2_tex_80183088[];
extern u8 shellder2_tex_80183290[];
extern u8 shellder2_tex_801832B8_png[];

extern Texture* shellder2_part2_mat[];
extern Gfx shellder2_part0_draw[];

Texture** shellder2_materials[] = {
    NULL,
    NULL,
    shellder2_part2_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* shellder2_part2_mat0_textures[] = {
    shellder2_tex_80183088,
    NULL,
};

Texture shellder2_part2_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    shellder2_part2_mat0_textures,
    128,
    64,
    64,
    32,
    0,
    0.10000000149011612,
    -0.01360000018030405,
    0.800000011920929,
    0.7200000286102295,
    0.10000000149011612,
    0.800000011920929,
    NULL,
    0xA1,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    32,
    32,
    64,
    32,
    0.10000000149011612,
    -0.01360000018030405,
    0.10000000149011612,
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
    { 64, 64, 64, 0 },
    0,
    0,
    0,
    0,
};

Texture* shellder2_part2_mat[] = {
    &shellder2_part2_mat0,
    NULL,
};

#include "assets/river/shellder2/model.vtx.inc.c"
#include "assets/river/shellder2/first.gfx.inc.c"
#include "assets/river/shellder2/part0_draw_near.gfx.inc.c"
#include "assets/river/shellder2/part0_draw.gfx.inc.c"
#include "assets/river/shellder2/part1_draw_near.gfx.inc.c"
#include "assets/river/shellder2/part1_draw.gfx.inc.c"
#include "assets/river/shellder2/part2_draw_near.gfx.inc.c"
#include "assets/river/shellder2/part2_draw.gfx.inc.c"
#include "assets/river/shellder2/part3_draw_near.gfx.inc.c"
#include "assets/river/shellder2/part3_draw.gfx.inc.c"
#include "assets/river/shellder2/part4_draw_near.gfx.inc.c"
#include "assets/river/shellder2/part4_draw.gfx.inc.c"
#include "assets/river/shellder2/part5_draw_near.gfx.inc.c"
#include "assets/river/shellder2/part5_draw.gfx.inc.c"
#include "assets/river/shellder2/part6_draw_near.gfx.inc.c"
#include "assets/river/shellder2/part6_draw.gfx.inc.c"
#include "assets/river/shellder2/last.gfx.inc.c"

UnkEC64Arg3 shellder2_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      shellder2_first,
      { 0.00010699999984353781, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      shellder2_part1_draw,
      { 0.0, 149.99998474121094, 30.000001907348633 },
      { -0.04363299906253815, 0.0, 0.0 },
      { 1.0, 1.0, 0.9999979734420776 } },
    { 3,
      shellder2_part2_draw,
      { -0.00033099998836405575, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999970197677612, 0.9999979734420776 } },
    { 4,
      shellder2_part3_draw,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0000020265579224, 1.0000009536743164 } },
    { 5,
      shellder2_part4_draw,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 0.9999960064888, 0.9999970197677612 } },
    { 6,
      shellder2_part5_draw,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999979734420776, 0.9999970197677612, 0.9999960064888 } },
    { 2,
      shellder2_last,
      { 0.0, 94.99999237060547, -110.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999979734420776, 0.9999979734420776 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
