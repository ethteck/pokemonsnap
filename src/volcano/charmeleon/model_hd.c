#include "common.h"

extern u8 charmeleon_tex_eye_frame0_png[];
extern u8 charmeleon_tex_eye_frame1_png[];
extern u8 charmeleon_tex_eye_frame2_png[];
extern u8 charmeleon_tex_flame_frame0_png[];
extern u8 charmeleon_tex_flame_frame1_png[];
extern u8 charmeleon_tex_flame_frame2_png[];
extern u8 charmeleon_tex_flame_frame3_png[];
extern u8 charmeleon_tex_claw_pal[];
extern u8 charmeleon_tex_claw_png[];
extern u8 charmeleon_tex_eye_frame0_pal[];
extern u8 charmeleon_tex_foot_pal[];
extern u8 charmeleon_tex_foot_png[];
extern u8 charmeleon_tex_mouth_pal[];
extern u8 charmeleon_tex_mouth_png[];
extern u8 charmeleon_tex_nostrils_pal[];
extern u8 charmeleon_tex_nostrils_png[];
extern u8 charmeleon_tex_skin_pal[];
extern u8 charmeleon_tex_skin_png[];
extern u8 charmeleon_tex_tail_pal[];
extern u8 charmeleon_tex_tail_png[];
extern u8 charmeleon_tex_tongue_pal[];
extern u8 charmeleon_tex_tongue_png[];

extern Texture* charmeleon_hd_part8_mat[];
extern Texture* charmeleon_hd_part13_mat[];
extern Gfx charmeleon_hd_part0_draw[];

Texture** charmeleon_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    charmeleon_hd_part8_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    charmeleon_hd_part13_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* charmeleon_hd_part8_mat0_textures[] = {
    charmeleon_tex_eye_frame0_png,
    charmeleon_tex_eye_frame1_png,
    charmeleon_tex_eye_frame2_png,
};

u8* charmeleon_hd_part13_mat0_textures[] = {
    charmeleon_tex_flame_frame0_png,
    charmeleon_tex_flame_frame1_png,
    charmeleon_tex_flame_frame2_png,
    charmeleon_tex_flame_frame3_png,
    NULL,
};

Texture charmeleon_hd_part8_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    charmeleon_hd_part8_mat0_textures,
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

Texture charmeleon_hd_part13_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    charmeleon_hd_part13_mat0_textures,
    32,
    0,
    16,
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
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    16,
    32,
    16,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 255, 234, 0, 255 },
    0,
    0,
    0,
    0,
    { 255, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 159, 159, 159, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* charmeleon_hd_part8_mat[] = {
    &charmeleon_hd_part8_mat0,
    NULL,
};

Texture* charmeleon_hd_part13_mat[] = {
    &charmeleon_hd_part13_mat0,
    NULL,
};
#include "assets/volcano/charmeleon/hd_model.vtx.inc.c"
#include "assets/volcano/charmeleon/hd_first.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part0_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part1_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part2_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part3_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part4_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part5_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part6_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part7_pre.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part7_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part8_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part9_pre.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part9_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part10_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part11_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part13_pre.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part13_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part14_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part15_pre.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part15_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part16_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/hd_part12_draw.gfx.inc.c"

DObjPayloadTypeJ charmeleon_hd_gfxdata[] = {
    { 0, NULL, charmeleon_hd_first },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part2_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part3_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part6_draw },
    { 4, NULL, NULL },
    { 0, charmeleon_hd_part7_pre, charmeleon_hd_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part8_draw },
    { 4, NULL, NULL },
    { 0, charmeleon_hd_part9_pre, charmeleon_hd_part9_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part11_draw },
    { 4, NULL, NULL },
    { 1, NULL, charmeleon_hd_part12_draw },
    { 4, NULL, NULL },
    { 0, charmeleon_hd_part13_pre, charmeleon_hd_part13_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part14_draw },
    { 4, NULL, NULL },
    { 0, charmeleon_hd_part15_pre, charmeleon_hd_part15_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_hd_part16_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 charmeleon_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &charmeleon_hd_gfxdata[0],
      { 0.0, 359.2000427246094, -25.999990463256836 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_hd_gfxdata[2],
      { 73.20000457763672, -69.20004272460938, -1.2000080347061157 },
      { 0.0, 0.0, -0.3900020122528076 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_hd_gfxdata[4],
      { 148.0618438720703, -64.55595397949219, 48.80000305175781 },
      { 0.0, 0.2640010118484497, 0.39000099897384644 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &charmeleon_hd_gfxdata[6],
      { -15.08016586303711, -60.00048065185547, -63.92626953125 },
      { 0.1674170047044754, 0.0954739972949028, -0.01764499954879284 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_hd_gfxdata[8],
      { -73.20000457763672, -69.20004272460938, -1.2000080347061157 },
      { 0.0, 3.1415929794311523, 0.3900020122528076 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_hd_gfxdata[10],
      { 148.06187438964844, -64.55595397949219, -48.800025939941406 },
      { 0.0, -0.2640010118484497, 0.39000099897384644 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &charmeleon_hd_gfxdata[12],
      { -15.080202102661133, -60.00048065185547, 63.9262809753418 },
      { -0.1674170047044754, -0.0954739972949028, -0.01764499954879284 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_hd_gfxdata[14],
      { 0.0, 314.0001220703125, 206.800048828125 },
      { 0.6460019946098328, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_hd_gfxdata[16],
      { 0.0, 95.91403198242188, 61.44000244140625 },
      { -0.6460019946098328, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_hd_gfxdata[18],
      { 0.0, -105.7728271484375, -155.2276611328125 },
      { -0.4240019917488098, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_hd_gfxdata[20],
      { 0.0, 169.59100341796875, -215.29249572753906 },
      { 0.8939999938011169, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &charmeleon_hd_gfxdata[22],
      { 0.0, 116.30857849121094, -192.3287353515625 },
      { -0.4320000112056732, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32773,
      &charmeleon_hd_gfxdata[24],
      { 0.0, 146.80209350585938, 6.242990016937256 },
      { -1.570796012878418, 1.5327990055084229, -1.570796012878418 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_hd_gfxdata[26],
      { 112.99482727050781, 239.12701416015625, 146.40000915527344 },
      { 0.0, 0.0, 0.36000099778175354 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_hd_gfxdata[28],
      { 46.19469451904297, -201.88421630859375, 5.526543140411377 },
      { 0.09399999678134918, -0.6940029859542847, -1.0280040502548218 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_hd_gfxdata[30],
      { -112.99482727050781, 239.12701416015625, 146.40000915527344 },
      { 0.0, 3.1415929794311523, -0.36000099778175354 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_hd_gfxdata[32],
      { 46.194671630859375, -201.88421630859375, -5.526555061340332 },
      { -0.09400100260972977, -5.589181900024414, -1.0280040502548218 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
