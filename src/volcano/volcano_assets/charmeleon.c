#include <common.h>

extern u8 charmeleon_tex0_pal[];
extern u8 charmeleon_tex0_png[];
extern u8 charmeleon_tex1_pal[];
extern u8 charmeleon_tex2_pal[];
extern u8 charmeleon_tex2_png[];
extern u8 charmeleon_tex3_pal[];
extern u8 charmeleon_tex3_png[];
extern u8 charmeleon_tex4_pal[];
extern u8 charmeleon_tex4_png[];
extern u8 charmeleon_tex5_pal[];
extern u8 charmeleon_tex5_png[];
extern u8 charmeleon_tex6_pal[];
extern u8 charmeleon_tex6_png[];
extern u8 charmeleon_tex7_pal[];
extern u8 charmeleon_tex7_png[];
extern u8 charmeleon_tex1_var0_png[];
extern u8 charmeleon_tex1_var1_png[];
extern u8 charmeleon_tex1_var2_png[];
extern u8 charmeleon_tex8_var0_png[];
extern u8 charmeleon_tex8_var1_png[];
extern u8 charmeleon_tex8_var2_png[];
extern u8 charmeleon_tex8_var3_png[];

extern Texture* charmeleon_part7_mat[];
extern Texture* charmeleon_part12_mat[];
extern Gfx charmeleon_part0_draw[];

Texture** charmeleon_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    charmeleon_part7_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    charmeleon_part12_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* charmeleon_part7_mat0_images[] = {
    charmeleon_tex1_var0_png,
    charmeleon_tex1_var1_png,
    charmeleon_tex1_var2_png,
};
u8* charmeleon_part12_mat0_images[] = {
    charmeleon_tex8_var0_png,
    charmeleon_tex8_var1_png,
    charmeleon_tex8_var2_png,
    charmeleon_tex8_var3_png,
    NULL,
};

Texture charmeleon_part7_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    charmeleon_part7_mat0_images,
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
    255,
    255,
    255,
    255,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    0xFFFFFF00,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture charmeleon_part12_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    charmeleon_part12_mat0_images,
    128,
    64,
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
    255,
    234,
    0,
    255,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    0x9F9F9F00,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture* charmeleon_part7_mat[] = {
    &charmeleon_part7_mat0,
    NULL,
};

Texture* charmeleon_part12_mat[] = {
    &charmeleon_part12_mat0,
    NULL,
};

#include "assets/volcano/charmeleon/model.vtx.inc.c"
#include "assets/volcano/charmeleon/first.gfx.inc.c"
#include "assets/volcano/charmeleon/part0_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part0_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part0_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part1_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part1_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part1_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part2_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part2_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part2_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part3_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part3_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part3_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part4_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part4_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part4_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part5_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part5_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part5_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part6_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part6_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part6_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part7_pre_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part7_pre_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part7_pre.gfx.inc.c"
#include "assets/volcano/charmeleon/part7_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part7_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part7_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part8_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part8_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part8_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part9_pre_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part9_pre_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part9_pre.gfx.inc.c"
#include "assets/volcano/charmeleon/part9_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part9_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part9_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part10_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part10_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part10_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part11_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part11_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part11_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part13_pre_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part13_pre_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part13_pre.gfx.inc.c"
#include "assets/volcano/charmeleon/part13_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part13_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part13_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part14_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part14_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part14_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part15_pre_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part15_pre_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part15_pre.gfx.inc.c"
#include "assets/volcano/charmeleon/part15_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part15_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part15_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/part16_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part16_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part16_draw.gfx.inc.c"
#include "assets/volcano/charmeleon/last.gfx.inc.c"
#include "assets/volcano/charmeleon/part12_draw_near.gfx.inc.c"
#include "assets/volcano/charmeleon/part12_draw_far.gfx.inc.c"
#include "assets/volcano/charmeleon/part12_draw.gfx.inc.c"

DObjPayloadTypeJ charmeleon_gfxdata[] = {
    { 0, NULL, charmeleon_first },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part2_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part3_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part6_draw },
    { 4, NULL, NULL },
    { 0, charmeleon_part7_pre, charmeleon_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part8_draw },
    { 4, NULL, NULL },
    { 0, charmeleon_part9_pre, charmeleon_part9_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part11_draw },
    { 4, NULL, NULL },
    { 1, NULL, charmeleon_part12_draw },
    { 4, NULL, NULL },
    { 0, charmeleon_part13_pre, charmeleon_part13_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_part14_draw },
    { 4, NULL, NULL },
    { 0, charmeleon_part15_pre, charmeleon_part15_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmeleon_last },
    { 4, NULL, NULL },
};

UnkEC64Arg3 charmeleon_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &charmeleon_gfxdata[0],
      { 0.0, 359.2000427246094, -25.999990463256836 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_gfxdata[2],
      { 73.20000457763672, -69.20004272460938, -1.2000080347061157 },
      { 0.0, 0.0, -0.3900020122528076 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_gfxdata[4],
      { 148.0618438720703, -64.55595397949219, 48.80000305175781 },
      { 0.0, 0.2640010118484497, 0.39000099897384644 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &charmeleon_gfxdata[6],
      { -15.08016586303711, -60.00048065185547, -63.92626953125 },
      { 0.1674170047044754, 0.0954739972949028, -0.01764499954879284 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_gfxdata[8],
      { -73.20000457763672, -69.20004272460938, -1.2000080347061157 },
      { 0.0, 3.1415929794311523, 0.3900020122528076 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_gfxdata[10],
      { 148.0618438720703, -64.55595397949219, -48.800025939941406 },
      { 0.0, -0.2640010118484497, 0.39000099897384644 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &charmeleon_gfxdata[12],
      { -15.08018970489502, -60.00050354003906, 63.926273345947266 },
      { -0.1674170047044754, -0.0954739972949028, -0.01764499954879284 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_gfxdata[14],
      { 0.0, 314.0001220703125, 206.800048828125 },
      { 0.6460019946098328, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_gfxdata[16],
      { 0.0, 95.91412353515625, 61.44001388549805 },
      { -0.6460019946098328, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_gfxdata[18],
      { 0.0, -105.7728271484375, -155.2276611328125 },
      { -0.4240019917488098, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_gfxdata[20],
      { 0.0, 169.59100341796875, -215.29249572753906 },
      { 0.8939999938011169, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &charmeleon_gfxdata[22],
      { 0.0, 116.30857849121094, -192.3287353515625 },
      { -0.4320000112056732, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32773,
      &charmeleon_gfxdata[24],
      { 0.0, 146.80209350585938, 6.242990016937256 },
      { -1.570796012878418, 1.5327990055084229, -1.570796012878418 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_gfxdata[26],
      { 112.99482727050781, 239.12701416015625, 146.40000915527344 },
      { 0.0, 0.0, 0.36000099778175354 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_gfxdata[28],
      { 46.19469451904297, -201.88421630859375, 5.526543140411377 },
      { 0.09399999678134918, -0.6940029859542847, -1.0280040502548218 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmeleon_gfxdata[30],
      { -112.99482727050781, 239.12701416015625, 146.40000915527344 },
      { 0.0, 3.1415929794311523, -0.36000099778175354 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmeleon_gfxdata[32],
      { 46.194671630859375, -201.88421630859375, -5.526555061340332 },
      { -0.09400100260972977, -5.589181900024414, -1.0280040502548218 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
