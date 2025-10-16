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

extern Texture* chansey_hd_part3_mat[];
extern Gfx chansey_hd_part0_draw[];

Texture** chansey_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    chansey_hd_part3_mat,
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

u8* chansey_hd_part3_mat0_textures[] = {
    chansey_tex_80184850,
    chansey_tex_801844E0,
    chansey_tex_80184590,
    chansey_tex_80184640,
    chansey_tex_801846F0,
    chansey_tex_801847A0,
};

u8* chansey_hd_part3_mat1_textures[] = {
    chansey_tex_80184E10,
    chansey_tex_801849B0,
    chansey_tex_80184BE0,
};

Texture chansey_hd_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    chansey_hd_part3_mat0_textures,
    32,
    0,
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

Texture chansey_hd_part3_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    chansey_hd_part3_mat1_textures,
    32,
    0,
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

Texture* chansey_hd_part3_mat[] = {
    &chansey_hd_part3_mat0,
    &chansey_hd_part3_mat1,
    NULL,
    NULL,
};
#include "assets/beach/chansey/hd_model.vtx.inc.c"
#include "assets/beach/chansey/hd_first.gfx.inc.c"
#include "assets/beach/chansey/hd_part0_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part1_pre.gfx.inc.c"
#include "assets/beach/chansey/hd_part1_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part2_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part3_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part4_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part5_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part6_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part7_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part8_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part9_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part10_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part11_pre.gfx.inc.c"
#include "assets/beach/chansey/hd_part11_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part12_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part13_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part14_draw.gfx.inc.c"
#include "assets/beach/chansey/hd_part15_draw.gfx.inc.c"

DObjPayloadTypeI chansey_hd_gfxdata[] = {
    { NULL, chansey_hd_first },
    { chansey_hd_part1_pre, chansey_hd_part1_draw },
    { NULL, chansey_hd_part2_draw },
    { NULL, chansey_hd_part3_draw },
    { NULL, chansey_hd_part4_draw },
    { NULL, chansey_hd_part5_draw },
    { NULL, chansey_hd_part6_draw },
    { NULL, chansey_hd_part7_draw },
    { NULL, chansey_hd_part8_draw },
    { NULL, chansey_hd_part9_draw },
    { NULL, chansey_hd_part10_draw },
    { chansey_hd_part11_pre, chansey_hd_part11_draw },
    { NULL, chansey_hd_part12_draw },
    { NULL, chansey_hd_part13_draw },
    { NULL, chansey_hd_part14_draw },
    { NULL, chansey_hd_part15_draw },
};

UnkEC64Arg3 chansey_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &chansey_hd_gfxdata[0],
      { 0.0, 400.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_hd_gfxdata[1],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &chansey_hd_gfxdata[2],
      { 0.0, 294.9999694824219, 35.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_hd_gfxdata[3],
      { 269.9999694824219, 125.0, -55.0 },
      { 0.0, 0.3926990032196045, -0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_hd_gfxdata[4],
      { 285.0000305175781, 119.99998474121094, 0.0 },
      { 0.0, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_hd_gfxdata[5],
      { 269.9999694824219, 110.00003814697266, 45.0 },
      { 0.0, -0.3926990032196045, -0.5235990285873413 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_hd_gfxdata[6],
      { -270.00006103515625, 125.0, -55.0 },
      { 0.0, -0.3926990032196045, 0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_hd_gfxdata[7],
      { -285.0001220703125, 119.99998474121094, 0.0 },
      { 0.0, 0.0, 0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &chansey_hd_gfxdata[8],
      { -270.00006103515625, 110.00003814697266, 45.0 },
      { 0.0, 0.3926990032196045, 0.5235990285873413 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &chansey_hd_gfxdata[9],
      { 225.0, 150.0, 275.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &chansey_hd_gfxdata[10],
      { -225.0, 150.0, 275.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_hd_gfxdata[11],
      { 0.0, -150.0, -325.0 },
      { -0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_hd_gfxdata[12],
      { 224.99996948242188, -300.0, 35.000003814697266 },
      { 0.0, 0.6981319785118103, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_hd_gfxdata[13],
      { 0.0, -150.0, 350.0000305175781 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &chansey_hd_gfxdata[14],
      { 0.0, 150.0, 74.9999771118164 },
      { 0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &chansey_hd_gfxdata[15],
      { -224.99996948242188, -300.0, 35.000003814697266 },
      { 0.0, -0.6981319785118103, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
