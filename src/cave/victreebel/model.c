#include "common.h"

extern u8 victreebel_tex_801A04B8[];
extern u8 victreebel_tex_801A08C0[];
extern u8 victreebel_tex_801A10F0[];
extern u8 victreebel_tex_801A1320[];
extern u8 victreebel_tex_801A1550[];
extern u8 victreebel_tex_801A1780[];
extern u8 victreebel_tex_801A19B0[];
extern u8 victreebel_tex_801A1BB8[];
extern u8 victreebel_tex_801A1BE0[];
extern u8 victreebel_tex_801A1DE8[];
extern u8 victreebel_tex_801A1E10_png[];
extern u8 victreebel_tex_801A1E38[];
extern u8 victreebel_tex_801A1E60_png[];
extern u8 victreebel_tex_801A2068[];
extern u8 victreebel_tex_801A2090_png[];
extern u8 victreebel_tex_801A2298[];
extern u8 victreebel_tex_801A22C0_png[];
extern u8 victreebel_tex_801A26C8[];
extern u8 victreebel_tex_801A26F0[];

extern Texture* victreebel_part1_mat[];
extern Texture* victreebel_part2_mat[];
extern Gfx victreebel_part1_draw[];

Texture** victreebel_materials[] = {
    NULL,
    victreebel_part1_mat,
    victreebel_part2_mat,
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
    NULL,
};

u8* victreebel_part2_mat0_textures[] = {
    victreebel_tex_801A1BE0,
    victreebel_tex_801A10F0,
    victreebel_tex_801A1550,
    victreebel_tex_801A1780,
    victreebel_tex_801A1320,
    victreebel_tex_801A19B0,
};

u8* victreebel_part2_mat1_textures[] = {
    victreebel_tex_801A1BE0,
    victreebel_tex_801A10F0,
    victreebel_tex_801A1550,
    victreebel_tex_801A1780,
    victreebel_tex_801A1320,
    victreebel_tex_801A19B0,
};

Texture victreebel_part1_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    192,
    64,
    32,
    0,
    0.0,
    0.0,
    4.0,
    1.0,
    0.0,
    4.0,
    NULL,
    0x2E0,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    64,
    32,
    -3.0,
    0.0,
    -3.0,
    { 0, 0, 0, 0 },
    139781,
    { 255, 255, 255, 0 },
    128,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture victreebel_part1_mat1 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    NULL,
    0,
    0,
    0,
    0,
    0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    NULL,
    0x200,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 255, 255, 0 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture victreebel_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    victreebel_part2_mat0_textures,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture victreebel_part2_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    victreebel_part2_mat1_textures,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* victreebel_part1_mat[] = {
    &victreebel_part1_mat0,
    &victreebel_part1_mat1,
    NULL,
};

Texture* victreebel_part2_mat[] = {
    &victreebel_part2_mat0,
    &victreebel_part2_mat1,
    NULL,
};

#include "assets/cave/victreebel/model.vtx.inc.c"
#include "assets/cave/victreebel/first.gfx.inc.c"
#include "assets/cave/victreebel/part1_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part1_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part1_draw.gfx.inc.c"
#include "assets/cave/victreebel/part2_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part2_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part2_draw.gfx.inc.c"
#include "assets/cave/victreebel/part3_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part3_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part3_draw.gfx.inc.c"
#include "assets/cave/victreebel/part4_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part4_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part4_draw.gfx.inc.c"
#include "assets/cave/victreebel/part5_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part5_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part5_draw.gfx.inc.c"
#include "assets/cave/victreebel/part6_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part6_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part6_draw.gfx.inc.c"
#include "assets/cave/victreebel/part7_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part7_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part7_draw.gfx.inc.c"
#include "assets/cave/victreebel/part8_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part8_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part8_draw.gfx.inc.c"
#include "assets/cave/victreebel/part9_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part9_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part9_draw.gfx.inc.c"
#include "assets/cave/victreebel/part10_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part10_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part10_draw.gfx.inc.c"
#include "assets/cave/victreebel/part11_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part11_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part11_draw.gfx.inc.c"
#include "assets/cave/victreebel/part12_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part12_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part12_draw.gfx.inc.c"
#include "assets/cave/victreebel/part13_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part13_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part13_draw.gfx.inc.c"
#include "assets/cave/victreebel/part14_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part14_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part14_draw.gfx.inc.c"
#include "assets/cave/victreebel/part15_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part15_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part15_draw.gfx.inc.c"
#include "assets/cave/victreebel/part16_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part16_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part16_draw.gfx.inc.c"
#include "assets/cave/victreebel/last.gfx.inc.c"
#include "assets/cave/victreebel/part0_draw_near.gfx.inc.c"
#include "assets/cave/victreebel/part0_draw_far.gfx.inc.c"
#include "assets/cave/victreebel/part0_draw.gfx.inc.c"

DObjPayloadTypeC victreebel_gfxdata[] = {
    { 1, victreebel_part0_draw },
    { 4, NULL },
    { 0, victreebel_first },
    { 4, NULL },
    { 0, victreebel_part2_draw },
    { 4, NULL },
    { 0, victreebel_part3_draw },
    { 4, NULL },
    { 0, victreebel_part4_draw },
    { 4, NULL },
    { 0, victreebel_part5_draw },
    { 4, NULL },
    { 0, victreebel_part6_draw },
    { 4, NULL },
    { 0, victreebel_part7_draw },
    { 4, NULL },
    { 0, victreebel_part8_draw },
    { 4, NULL },
    { 0, victreebel_part9_draw },
    { 4, NULL },
    { 0, victreebel_part10_draw },
    { 4, NULL },
    { 0, victreebel_part11_draw },
    { 4, NULL },
    { 0, victreebel_part12_draw },
    { 4, NULL },
    { 0, victreebel_part13_draw },
    { 4, NULL },
    { 0, victreebel_part14_draw },
    { 4, NULL },
    { 0, victreebel_part15_draw },
    { 4, NULL },
    { 0, victreebel_last },
    { 4, NULL },
};

UnkEC64Arg3 victreebel_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &victreebel_gfxdata[0],
      { 0.0, 600.5308227539062, 100.08841705322266 },
      { 0.0, 0.0, 0.0 },
      { 5.0, 1.0, 5.0 } },
    { 1,
      &victreebel_gfxdata[2],
      { 0.0, 213.87997436523438, 189.05075073242188 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &victreebel_gfxdata[4],
      { 0.0, -385.9199523925781, -222.50242614746094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &victreebel_gfxdata[6],
      { 0.0, -120.18000030517578, -254.23336791992188 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 4,
      &victreebel_gfxdata[8],
      { -407.80047607421875, -52.939605712890625, -100.77979278564453 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &victreebel_gfxdata[10],
      { -377.14471435546875, -24.692916870117188, -66.16133117675781 },
      { 0.0, 0.0, 0.0 },
      { 0.9999979734420776, 0.9999989867210388, 0.9999989867210388 } },
    { 4,
      &victreebel_gfxdata[12],
      { 407.80047607421875, -52.53009796142578, -100.6429443359375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &victreebel_gfxdata[14],
      { 383.6999816894531, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &victreebel_gfxdata[16],
      { 0.0, 208.76998901367188, 104.64926147460938 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &victreebel_gfxdata[18],
      { 0.0, 214.06002807617188, -150.72003173828125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &victreebel_gfxdata[20],
      { 0.0, -38.02051544189453, 86.48849487304688 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.000167965888977 } },
    { 3,
      &victreebel_gfxdata[22],
      { 0.0, 200.0, -300.0 },
      { -0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &victreebel_gfxdata[24],
      { 0.0, 177.49671936035156, -341.3999938964844 },
      { -0.43633198738098145, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &victreebel_gfxdata[26],
      { 0.0, 170.24688720703125, -349.9793395996094 },
      { -0.6981319785118103, 0.0, 0.0 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 6,
      &victreebel_gfxdata[28],
      { 0.0, 177.6031494140625, -345.85589599609375 },
      { -0.43633198738098145, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &victreebel_gfxdata[30],
      { 0.0, 168.33229064941406, -330.1126403808594 },
      { -0.3926990032196045, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8,
      &victreebel_gfxdata[32],
      { 1.6824740171432495, 125.0, -228.68060302734375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.000167965888977 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
