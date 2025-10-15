#include "common.h"

extern u8 koffing_tex_80161B88[];
extern u8 koffing_tex_80161F90[];
extern u8 koffing_tex_80162398[];
extern u8 koffing_tex_801627A0[];
extern u8 koffing_tex_80162BA8[];
extern u8 koffing_tex_80162BD0_png[];
extern u8 koffing_tex_80162DD8[];
extern u8 koffing_tex_80162E00_png[];
extern u8 koffing_tex_80163208[];
extern u8 koffing_tex_80163230[];
extern u8 koffing_tex_80163660[];
extern u8 koffing_tex_80163A90[];
extern u8 koffing_tex_80163EC0[];
extern u8 koffing_tex_801642F0[];
extern u8 koffing_tex_801646F8[];
extern u8 koffing_tex_80164720[];
extern u8 koffing_tex_80164B50[];
extern u8 koffing_tex_80164F80[];
extern u8 koffing_tex_801653B0[];

extern Texture* koffing_part1_mat[];
extern Texture* koffing_part7_mat[];
extern Texture* koffing_part8_mat[];
extern Texture* koffing_part9_mat[];
extern Texture* koffing_part10_mat[];
extern Texture* koffing_part11_mat[];
extern Texture* koffing_part12_mat[];
extern Texture* koffing_part13_mat[];
extern Texture* koffing_part14_mat[];
extern Texture* koffing_part15_mat[];
extern Gfx koffing_part0_draw[];

Texture** koffing_materials[] = {
    NULL,
    koffing_part1_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    koffing_part7_mat,
    koffing_part8_mat,
    koffing_part9_mat,
    koffing_part10_mat,
    koffing_part11_mat,
    koffing_part12_mat,
    koffing_part13_mat,
    koffing_part14_mat,
    koffing_part15_mat,
};

u8* koffing_part1_mat0_textures[] = {
    koffing_tex_80164720,
    koffing_tex_80164B50,
    koffing_tex_80164F80,
    koffing_tex_801653B0,
};

u8* koffing_part1_mat1_textures[] = {
    koffing_tex_80163230,
    koffing_tex_80163660,
    koffing_tex_80163A90,
    koffing_tex_80163EC0,
    koffing_tex_801642F0,
};

u8* koffing_part7_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_part8_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_part9_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_part10_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_part11_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_part12_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_part13_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_part14_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_part15_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

Texture koffing_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    koffing_part1_mat0_textures,
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
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64,
    32,
    64,
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

Texture koffing_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    koffing_part1_mat1_textures,
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
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64,
    32,
    64,
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

Texture koffing_part7_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part7_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 0 },
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

Texture koffing_part8_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part8_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 96 },
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

Texture koffing_part9_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part9_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_part10_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part10_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 0 },
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

Texture koffing_part11_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part11_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 76 },
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

Texture koffing_part12_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part12_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 230 },
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

Texture koffing_part13_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part13_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 25 },
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

Texture koffing_part14_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part14_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 204 },
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

Texture koffing_part15_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_part15_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 51 },
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

Texture* koffing_part1_mat[] = {
    &koffing_part1_mat0,
    &koffing_part1_mat1,
    NULL,
};

Texture* koffing_part7_mat[] = {
    &koffing_part7_mat0,
    NULL,
};

Texture* koffing_part8_mat[] = {
    &koffing_part8_mat0,
    NULL,
};

Texture* koffing_part9_mat[] = {
    &koffing_part9_mat0,
    NULL,
};

Texture* koffing_part10_mat[] = {
    &koffing_part10_mat0,
    NULL,
};

Texture* koffing_part11_mat[] = {
    &koffing_part11_mat0,
    NULL,
};

Texture* koffing_part12_mat[] = {
    &koffing_part12_mat0,
    NULL,
};

Texture* koffing_part13_mat[] = {
    &koffing_part13_mat0,
    NULL,
};

Texture* koffing_part14_mat[] = {
    &koffing_part14_mat0,
    NULL,
};

Texture* koffing_part15_mat[] = {
    &koffing_part15_mat0,
    NULL,
    NULL,
};

#include "assets/cave/koffing/model.vtx.inc.c"
#include "assets/cave/koffing/first.gfx.inc.c"
#include "assets/cave/koffing/part0_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part0_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part0_draw.gfx.inc.c"
#include "assets/cave/koffing/part1_pre_near.gfx.inc.c"
#include "assets/cave/koffing/part1_pre_far.gfx.inc.c"
#include "assets/cave/koffing/part1_pre.gfx.inc.c"
#include "assets/cave/koffing/part1_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part1_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part1_draw.gfx.inc.c"
#include "assets/cave/koffing/part2_pre_near.gfx.inc.c"
#include "assets/cave/koffing/part2_pre_far.gfx.inc.c"
#include "assets/cave/koffing/part2_pre.gfx.inc.c"
#include "assets/cave/koffing/part2_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part2_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part2_draw.gfx.inc.c"
#include "assets/cave/koffing/part3_pre_near.gfx.inc.c"
#include "assets/cave/koffing/part3_pre_far.gfx.inc.c"
#include "assets/cave/koffing/part3_pre.gfx.inc.c"
#include "assets/cave/koffing/part3_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part3_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part3_draw.gfx.inc.c"
#include "assets/cave/koffing/part4_pre_near.gfx.inc.c"
#include "assets/cave/koffing/part4_pre_far.gfx.inc.c"
#include "assets/cave/koffing/part4_pre.gfx.inc.c"
#include "assets/cave/koffing/part4_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part4_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part4_draw.gfx.inc.c"
#include "assets/cave/koffing/last.gfx.inc.c"
#include "assets/cave/koffing/part5_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part5_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part5_draw.gfx.inc.c"
#include "assets/cave/koffing/part6_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part6_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part6_draw.gfx.inc.c"
#include "assets/cave/koffing/part7_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part7_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part7_draw.gfx.inc.c"
#include "assets/cave/koffing/part8_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part8_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part8_draw.gfx.inc.c"
#include "assets/cave/koffing/part9_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part9_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part9_draw.gfx.inc.c"
#include "assets/cave/koffing/part10_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part10_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part10_draw.gfx.inc.c"
#include "assets/cave/koffing/part11_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part11_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part11_draw.gfx.inc.c"
#include "assets/cave/koffing/part12_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part12_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part12_draw.gfx.inc.c"
#include "assets/cave/koffing/part13_draw_near.gfx.inc.c"
#include "assets/cave/koffing/part13_draw_far.gfx.inc.c"
#include "assets/cave/koffing/part13_draw.gfx.inc.c"

DObjPayloadTypeJ koffing_gfxdata[] = {
    { 0, NULL, koffing_first },
    { 4, NULL, NULL },
    { 0, koffing_part1_pre, koffing_part1_draw },
    { 4, NULL, NULL },
    { 0, koffing_part2_pre, koffing_part2_draw },
    { 4, NULL, NULL },
    { 0, koffing_part3_pre, koffing_part3_draw },
    { 4, NULL, NULL },
    { 0, koffing_part4_pre, koffing_last },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part5_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part6_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part7_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part8_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part9_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part10_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part11_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part12_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_part13_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 koffing_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &koffing_gfxdata[0],
      { 0.0, 320.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &koffing_gfxdata[2],
      { -3.999999989900971e-06, 7.200000254670158e-05, 9.999999747378752e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &koffing_gfxdata[4],
      { -3.999999989900971e-06, 7.200000254670158e-05, 9.999999747378752e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &koffing_gfxdata[6],
      { -3.999999989900971e-06, 7.200000254670158e-05, 9.999999747378752e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &koffing_gfxdata[8],
      { -3.999999989900971e-06, 7.200000254670158e-05, 9.999999747378752e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 320.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_gfxdata[10],
      { 216.38201904296875, -15.281696319580078, 340.2915344238281 },
      { 0.0, 0.0, 0.0 },
      { 5.101853847503662, 5.101853847503662, 1.0 } },
    { 32770,
      &koffing_gfxdata[12],
      { -166.2443389892578, 257.2479248046875, -248.35577392578125 },
      { 0.0, 0.0, 0.0 },
      { 2.7142720222473145, 2.7142720222473145, 2.7142720222473145 } },
    { 32770,
      &koffing_gfxdata[14],
      { 215.11106872558594, -44.59986877441406, 290.5195007324219 },
      { 0.0, 0.0, 0.0 },
      { 1.3972489833831787, 1.3972489833831787, 1.0 } },
    { 32770,
      &koffing_gfxdata[16],
      { 327.00177001953125, -76.89423370361328, -104.22534942626953 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_gfxdata[18],
      { -2.090765953063965, 36.08890914916992, -380.01983642578125 },
      { 0.0, 0.0, 0.0 },
      { 4.618472099304199, 4.5892109870910645, 1.0 } },
    { 32770,
      &koffing_gfxdata[20],
      { -299.6809997558594, -206.5702667236328, 104.49517822265625 },
      { 0.0, 0.0, 0.0 },
      { 1.1098910570144653, 1.1098910570144653, 1.1098910570144653 } },
    { 32770,
      &koffing_gfxdata[22],
      { -472.88818359375, 450.4916076660156, 171.74232482910156 },
      { 0.0, 0.0, 0.0 },
      { 5.537463188171387, 5.537463188171387, 1.0 } },
    { 32770,
      &koffing_gfxdata[24],
      { 306.69659423828125, 187.98208618164062, 89.48147583007812 },
      { 0.0, 0.0, 0.0 },
      { 1.407480001449585, 1.407480001449585, 1.407480001449585 } },
    { 32770,
      &koffing_gfxdata[26],
      { 0.41495001316070557, 554.8464965820312, 54.88767623901367 },
      { 0.0, 0.0, 0.0 },
      { 6.0940728187561035, 6.140738010406494, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
