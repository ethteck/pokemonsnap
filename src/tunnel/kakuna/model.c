#include "common.h"

extern u8 kakuna_tex_80159608[];
extern u8 kakuna_tex_80159630[];
extern u8 kakuna_tex_80159838[];
extern u8 kakuna_tex_80159860[];
extern u8 kakuna_tex_80159A68[];
extern u8 kakuna_tex_80159A78[];
extern u8 kakuna_tex_80159A88[];
extern u8 kakuna_tex_80159C90[];
extern u8 kakuna_tex_80159E98[];
extern u8 kakuna_tex_80159EB0[];
extern u8 kakuna_tex_8015A0B8[];
extern u8 kakuna_tex_80326EF8[];
extern u8 kakuna_tex_80326F10[];

__ALIGNER
u8 kakuna_tex_80326F10[] = {
#include "assets/tunnel/kakuna/tex_80326F10.pal.bin.c"
};

__ALIGNER
u8 kakuna_tex_80326EF8[] = {
#include "assets/tunnel/kakuna/tex_80326F10.png.bin.c"
};

extern Texture* kakuna_part1_mat[];
extern Gfx kakuna_part0_draw[];

__ALIGNER
u8 kakuna_tex_80326F10_pal[] = {
#include "assets/tunnel/kakuna/tex_80326F10.pal.bin.c"
};

__ALIGNER
u8 kakuna_tex_80326F10_png[] = {
#include "assets/tunnel/kakuna/tex_80326F10.png.bin.c"
};

Texture** kakuna_materials[] = {
    NULL,
    kakuna_part1_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* kakuna_part1_mat0_textures[] = {
    kakuna_tex_8015A0B8,
};

Texture kakuna_part1_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    kakuna_part1_mat0_textures,
    128,
    114,
    4,
    128,
    0,
    0.0,
    0.7728700041770935,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    4,
    128,
    4,
    128,
    0.0,
    0.7728700041770935,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 76, 76, 76, 0 },
    0,
    0,
    0,
    0,
};

Texture* kakuna_part1_mat[] = {
    &kakuna_part1_mat0,
    NULL,
};

#include "assets/tunnel/kakuna/model.vtx.inc.c"
#include "assets/tunnel/kakuna/first.gfx.inc.c"
#include "assets/tunnel/kakuna/part0_draw_near.gfx.inc.c"
#include "assets/tunnel/kakuna/part0_draw_far.gfx.inc.c"
#include "assets/tunnel/kakuna/part0_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/part1_draw_near.gfx.inc.c"
#include "assets/tunnel/kakuna/part1_draw_far.gfx.inc.c"
#include "assets/tunnel/kakuna/part1_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/part2_draw_near.gfx.inc.c"
#include "assets/tunnel/kakuna/part2_draw_far.gfx.inc.c"
#include "assets/tunnel/kakuna/part2_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/part3_draw_near.gfx.inc.c"
#include "assets/tunnel/kakuna/part3_draw_far.gfx.inc.c"
#include "assets/tunnel/kakuna/part3_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/part4_draw_near.gfx.inc.c"
#include "assets/tunnel/kakuna/part4_draw_far.gfx.inc.c"
#include "assets/tunnel/kakuna/part4_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/last.gfx.inc.c"

UnkEC64Arg3 kakuna_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8193,
      kakuna_first,
      { 0.0, 486.79998779296875, -235.1999969482422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      kakuna_part1_draw,
      { 0.0, 56.199981689453125, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      kakuna_part2_draw,
      { -4.70000013592653e-05, -210.15997314453125, 169.14002990722656 },
      { 0.0, 0.0, 0.0 },
      { 0.9900000095367432, 1.0, 1.0 } },
    { 4,
      kakuna_part3_draw,
      { -3.000000106112566e-06, -79.9999008178711, 35.20009994506836 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      kakuna_last,
      { 0.0, -170.84402465820312, -20.52519989013672 },
      { -0.9440010190010071, 0.0, 0.0 },
      { 0.9999970197677612, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
