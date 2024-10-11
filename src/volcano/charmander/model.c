#include <common.h>

extern u8 charmander_tex_eye_pal[];
extern u8 charmander_tex_eye_frame0_png[];
extern u8 charmander_tex_eye_frame1_png[];
extern u8 charmander_tex_eye_frame2_png[];
extern u8 charmander_tex_eye_frame3_png[];
extern u8 charmander_tex_eye_frame4_png[];
extern u8 charmander_tex_eye_frame5_png[];
extern u8 charmander_tex_eye_frame6_png[];
extern u8 charmander_tex_eye_frame7_png[];
extern u8 charmander_tex_nostril_pal[];
extern u8 charmander_tex_nostril_png[];
extern u8 charmander_tex_skin_pal[];
extern u8 charmander_tex_skin_png[];
extern u8 charmander_tex_tongue_pal[];
extern u8 charmander_tex_tongue_png[];
extern u8 charmander_tex_claw_pal[];
extern u8 charmander_tex_claw_png[];
extern u8 charmander_tex_mouth_pal[];
extern u8 charmander_tex_mouth_png[];
extern u8 charmander_tex_flame_frame0_png[];
extern u8 charmander_tex_flame_frame1_png[];
extern u8 charmander_tex_flame_frame2_png[];
extern u8 charmander_tex_flame_frame3_png[];

extern Texture* charmander_part5_mat[];
extern Texture* charmander_part13_mat[];
extern Gfx charmander_part0_draw[];

Texture** charmander_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    charmander_part5_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    charmander_part13_mat,
};

u8* charmander_part5_mat0_textures[] = {
    charmander_tex_eye_frame0_png,
    charmander_tex_eye_frame1_png,
    charmander_tex_eye_frame2_png,
    charmander_tex_eye_frame3_png,
    charmander_tex_eye_frame4_png,
    charmander_tex_eye_frame5_png,
    charmander_tex_eye_frame6_png,
    charmander_tex_eye_frame7_png,
};

u8* charmander_part13_mat0_textures[] = {
    charmander_tex_flame_frame0_png,
    charmander_tex_flame_frame1_png,
    charmander_tex_flame_frame2_png,
    charmander_tex_flame_frame3_png,
    NULL,
};

Texture charmander_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    charmander_part5_mat0_textures,
    128,
    64,
    32,
    64,
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
    64,
    32,
    64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255,
      255,
      255,
      255 },
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture charmander_part13_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    charmander_part13_mat0_textures,
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
    0x1,
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
    { 255,
      234,
      0,
      255 },
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
    { 159, 159, 159, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* charmander_part5_mat[] = {
    &charmander_part5_mat0,
    NULL,
};

Texture* charmander_part13_mat[] = {
    &charmander_part13_mat0,
    NULL,
};

#include "assets/volcano/charmander/model.vtx.inc.c"
#include "assets/volcano/charmander/first.gfx.inc.c"
#include "assets/volcano/charmander/part0_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part0_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part0_draw.gfx.inc.c"
#include "assets/volcano/charmander/part1_pre_near.gfx.inc.c"
#include "assets/volcano/charmander/part1_pre_far.gfx.inc.c"
#include "assets/volcano/charmander/part1_pre.gfx.inc.c"
#include "assets/volcano/charmander/part1_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part1_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part1_draw.gfx.inc.c"
#include "assets/volcano/charmander/part2_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part2_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part2_draw.gfx.inc.c"
#include "assets/volcano/charmander/part3_pre_near.gfx.inc.c"
#include "assets/volcano/charmander/part3_pre_far.gfx.inc.c"
#include "assets/volcano/charmander/part3_pre.gfx.inc.c"
#include "assets/volcano/charmander/part3_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part3_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part3_draw.gfx.inc.c"
#include "assets/volcano/charmander/part4_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part4_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part4_draw.gfx.inc.c"
#include "assets/volcano/charmander/part5_pre_near.gfx.inc.c"
#include "assets/volcano/charmander/part5_pre_far.gfx.inc.c"
#include "assets/volcano/charmander/part5_pre.gfx.inc.c"
#include "assets/volcano/charmander/part5_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part5_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part5_draw.gfx.inc.c"
#include "assets/volcano/charmander/part6_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part6_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part6_draw.gfx.inc.c"
#include "assets/volcano/charmander/part7_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part7_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part7_draw.gfx.inc.c"
#include "assets/volcano/charmander/part8_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part8_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part8_draw.gfx.inc.c"
#include "assets/volcano/charmander/part9_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part9_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part9_draw.gfx.inc.c"
#include "assets/volcano/charmander/part10_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part10_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part10_draw.gfx.inc.c"
#include "assets/volcano/charmander/part11_pre_near.gfx.inc.c"
#include "assets/volcano/charmander/part11_pre_far.gfx.inc.c"
#include "assets/volcano/charmander/part11_pre.gfx.inc.c"
#include "assets/volcano/charmander/part11_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part11_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part11_draw.gfx.inc.c"
#include "assets/volcano/charmander/part12_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part12_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part12_draw.gfx.inc.c"
#include "assets/volcano/charmander/last.gfx.inc.c"
#include "assets/volcano/charmander/part13_draw_near.gfx.inc.c"
#include "assets/volcano/charmander/part13_draw_far.gfx.inc.c"
#include "assets/volcano/charmander/part13_draw.gfx.inc.c"

DObjPayloadTypeJ charmander_gfxdata[] = {
    { 0, NULL, charmander_first },
    { 4, NULL, NULL },
    { 0, charmander_part1_pre, charmander_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_part2_draw },
    { 4, NULL, NULL },
    { 0, charmander_part3_pre, charmander_part3_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_part4_draw },
    { 4, NULL, NULL },
    { 0, charmander_part5_pre, charmander_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_part6_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_part8_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_part9_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_part10_draw },
    { 4, NULL, NULL },
    { 0, charmander_part11_pre, charmander_part11_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_last },
    { 4, NULL, NULL },
    { 1, NULL, charmander_part13_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 charmander_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &charmander_gfxdata[0],
      { 0.0, 213.17660522460938, -98.34190368652344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_gfxdata[2],
      { 66.38370513916016, 98.26639556884766, 33.04010009765625 },
      { 0.6482020020484924, 0.009318999946117401, -0.8015779852867126 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_gfxdata[4],
      { 92.92838287353516, 2.8384690284729004, -4.012178897857666 },
      { 0.6184830069541931, 0.14751100540161133, 0.15039999783039093 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_gfxdata[6],
      { -66.38370513916016, 98.26639556884766, 33.04010009765625 },
      { -0.6482020020484924, 3.1322739124298096, 0.7989599704742432 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_gfxdata[8],
      { 92.92840576171875, 2.838444948196411, 4.012178897857666 },
      { 2.5231099128723145, -2.9940810203552246, -2.991192102432251 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_gfxdata[10],
      { 0.0, 160.51719665527344, 44.111610412597656 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_gfxdata[12],
      { 1.700000029813964e-05, -6.167507171630859, -59.01110076904297 },
      { -0.11999999731779099, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_gfxdata[14],
      { 69.44670104980469, -83.53791046142578, -14.114398002624512 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_gfxdata[16],
      { 32.596797943115234, -72.57569122314453, 49.054359436035156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_gfxdata[18],
      { -69.44670104980469, -83.53791046142578, -14.114398002624512 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_gfxdata[20],
      { 32.5967903137207, -72.57569122314453, -49.05436706542969 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_gfxdata[22],
      { -1.0432000160217285, -118.13740539550781, -89.08711242675781 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_gfxdata[24],
      { 0.0, -28.17550277709961, -149.53561401367188 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32772,
      &charmander_gfxdata[26],
      { 1.0432000160217285, 167.42236328125, -113.64755249023438 },
      { 0.0, 1.570796012878418, 0.0 },
      { 0.23999999463558197, 0.23999999463558197, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
