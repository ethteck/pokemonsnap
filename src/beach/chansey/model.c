#include "common.h"

extern u8 chansey_tex_801844E0[];
extern u8 chansey_tex_80184590[];
extern u8 chansey_tex_80184640[];
extern u8 chansey_tex_801846F0[];
extern u8 chansey_tex_801847A0[];
extern u8 chansey_tex_80184828[];
extern u8 chansey_tex_80184850[];
extern u8 chansey_tex_801848D8[];
extern u8 chansey_tex_80184900[];
extern u8 chansey_tex_801849B0[];
extern u8 chansey_tex_80184BE0[];
extern u8 chansey_tex_80184DE8[];
extern u8 chansey_tex_80184E10[];

extern Gfx chansey_part0_draw[];

Texture* chansey_part3_mat[];

Texture** chansey_materials[] = {
    NULL,
    NULL,
    NULL,
    chansey_part3_mat,
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

u8* chansey_part3_mat0_textures[] = {
    chansey_tex_80184850,
    chansey_tex_801844E0,
    chansey_tex_80184590,
    chansey_tex_80184640,
    chansey_tex_801846F0,
    chansey_tex_801847A0,
};

u8* chansey_part3_mat1_textures[] = {
    chansey_tex_80184E10,
    chansey_tex_801849B0,
    chansey_tex_80184BE0,
};

Texture chansey_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    chansey_part3_mat0_textures,
    128,
    64,
    16,
    16,
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
    G_IM_SIZ_4b,
    16,
    16,
    16,
    16,
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
    { 51, 51, 51, 0 },
    0,
    0,
    0,
    0,
};

Texture chansey_part3_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    chansey_part3_mat1_textures,
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
    0x1,
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
    { 51, 51, 51, 0 },
    0,
    0,
    0,
    0,
};

Texture* chansey_part3_mat[] = {
    &chansey_part3_mat0,
    &chansey_part3_mat1,
    NULL,
    NULL,
};

#include "assets/beach/chansey/model.vtx.inc.c"
#include "assets/beach/chansey/first.gfx.inc.c"
#include "assets/beach/chansey/part0_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part0_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part0_draw.gfx.inc.c"
#include "assets/beach/chansey/part1_pre_near.gfx.inc.c"
#include "assets/beach/chansey/part1_pre.gfx.inc.c"
#include "assets/beach/chansey/part1_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part1_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part1_draw.gfx.inc.c"
#include "assets/beach/chansey/part2_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part2_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part2_draw.gfx.inc.c"
#include "assets/beach/chansey/part3_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part3_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part3_draw.gfx.inc.c"
#include "assets/beach/chansey/part4_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part4_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part4_draw.gfx.inc.c"
#include "assets/beach/chansey/part5_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part5_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part5_draw.gfx.inc.c"
#include "assets/beach/chansey/part6_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part6_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part6_draw.gfx.inc.c"
#include "assets/beach/chansey/part7_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part7_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part7_draw.gfx.inc.c"
#include "assets/beach/chansey/part8_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part8_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part8_draw.gfx.inc.c"
#include "assets/beach/chansey/part9_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part9_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part9_draw.gfx.inc.c"
#include "assets/beach/chansey/part10_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part10_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part10_draw.gfx.inc.c"
#include "assets/beach/chansey/part11_pre_near.gfx.inc.c"
#include "assets/beach/chansey/part11_pre.gfx.inc.c"
#include "assets/beach/chansey/part11_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part11_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part11_draw.gfx.inc.c"
#include "assets/beach/chansey/part12_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part12_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part12_draw.gfx.inc.c"
#include "assets/beach/chansey/part13_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part13_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part13_draw.gfx.inc.c"
#include "assets/beach/chansey/part14_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part14_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part14_draw.gfx.inc.c"
#include "assets/beach/chansey/part15_draw_near.gfx.inc.c"
#include "assets/beach/chansey/part15_draw_far.gfx.inc.c"
#include "assets/beach/chansey/part15_draw.gfx.inc.c"
#include "assets/beach/chansey/last.gfx.inc.c"

DObjPayloadTypeI chansey_gfxdata[] = {
    { NULL, chansey_first },
    { chansey_part1_pre, chansey_part1_draw },
    { NULL, chansey_part2_draw },
    { NULL, chansey_part3_draw },
    { NULL, chansey_part4_draw },
    { NULL, chansey_part5_draw },
    { NULL, chansey_part6_draw },
    { NULL, chansey_part7_draw },
    { NULL, chansey_part8_draw },
    { NULL, chansey_part9_draw },
    { NULL, chansey_part10_draw },
    { chansey_part11_pre, chansey_part11_draw },
    { NULL, chansey_part12_draw },
    { NULL, chansey_part13_draw },
    { NULL, chansey_part14_draw },
    { NULL, chansey_last },
};

UnkEC64Arg3 chansey_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &chansey_gfxdata[0],
      { 0.0, 400.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_gfxdata[1],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &chansey_gfxdata[2],
      { 0.0, 295.0, 35.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_gfxdata[3],
      { 270.00006103515625, 125.0, -55.0 },
      { 0.0, 0.3926990032196045, -0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_gfxdata[4],
      { 285.0, 120.00000762939453, 20.0 },
      { 0.0, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_gfxdata[5],
      { 270.00006103515625, 110.00003814697266, 45.0 },
      { 0.0, -0.3926990032196045, -0.5235990285873413 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_gfxdata[6],
      { -269.9999694824219, 125.0, -55.0 },
      { 0.0, -0.3926990032196045, 0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_gfxdata[7],
      { -284.9999694824219, 119.99998474121094, 0.0 },
      { 0.0, 0.0, 0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_gfxdata[8],
      { -269.9999694824219, 110.00003814697266, 45.0 },
      { 0.0, 0.3926990032196045, 0.5235990285873413 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &chansey_gfxdata[9],
      { 225.0, 150.0, 275.0 },
      { 0.5235990285873413, -0.17453299462795258, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &chansey_gfxdata[10],
      { -225.0, 150.0, 275.0 },
      { 0.5235990285873413, 0.17453299462795258, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_gfxdata[11],
      { 0.0, -150.0, -325.0 },
      { -0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_gfxdata[12],
      { 225.0, -300.0, 35.0 },
      { 0.0, 0.6981319785118103, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_gfxdata[13],
      { 0.0, -150.0, 349.9999694824219 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      &chansey_gfxdata[14],
      { 0.0, 149.9999542236328, 75.0000228881836 },
      { 0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_gfxdata[15],
      { -224.99996948242188, -300.0, 35.0 },
      { 0.0, -0.6981319785118103, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
