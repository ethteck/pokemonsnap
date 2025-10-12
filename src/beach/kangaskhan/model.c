#include "common.h"

extern u8 kangaskhan_tex_8016B648[];
extern u8 kangaskhan_tex_8016B670_png[];
extern u8 kangaskhan_tex_8016BA78[];
extern u8 kangaskhan_tex_8016BAA0_png[];
extern u8 kangaskhan_tex_8016BB28[];
extern u8 kangaskhan_tex_8016BB50_png[];
extern u8 kangaskhan_tex_8016BBD8[];
extern u8 kangaskhan_tex_8016BC00_png[];
extern u8 kangaskhan_tex_8016BF08[];
extern u8 kangaskhan_tex_8016BF30_png[];
extern u8 kangaskhan_tex_8016C0B8[];
extern u8 kangaskhan_tex_8016C0E0_png[];
extern u8 kangaskhan_tex_8016C3E8[];
extern u8 kangaskhan_tex_8016C410_png[];
extern u8 kangaskhan_tex_8016C618[];
extern u8 kangaskhan_tex_8016C640_png[];
extern u8 kangaskhan_tex_8016CAC8[];
extern u8 kangaskhan_tex_8016CAF0_png[];
extern u8 kangaskhan_tex_8016CBF8[];
extern u8 kangaskhan_tex_8016CC20_png[];
extern u8 kangaskhan_tex_8016CCD0[];
extern u8 kangaskhan_tex_8016D100[];
extern u8 kangaskhan_tex_8016D508[];
extern u8 kangaskhan_tex_8016D530[];
extern u8 kangaskhan_tex_8016D960[];
extern u8 kangaskhan_tex_8016DD68[];
extern u8 kangaskhan_tex_8016DD90_png[];
extern u8 kangaskhan_tex_8016DE18[];
extern u8 kangaskhan_tex_8016DE40_png[];
extern u8 kangaskhan_tex_8016DEC8[];
extern u8 kangaskhan_tex_8016DEF0_png[];
extern u8 kangaskhan_tex_8016DF78[];
extern u8 kangaskhan_tex_8016DFA0_png[];
extern u8 kangaskhan_tex_8016E028[];
extern u8 kangaskhan_tex_8016E050_png[];
extern u8 kangaskhan_tex_8016E158[];
extern u8 kangaskhan_tex_8016E180_png[];

Texture* kangaskhan_part7_mat[];
Gfx kangaskhan_part0_draw[];

Texture** D_beach_80324E40[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    kangaskhan_part7_mat,
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

u8* kangaskhan_part7_mat0_textures[] = {
    kangaskhan_tex_8016D530,
    kangaskhan_tex_8016D960,
    kangaskhan_tex_8016CCD0,
    kangaskhan_tex_8016D100,
};

Texture kangaskhan_part7_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    kangaskhan_part7_mat0_textures,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* kangaskhan_part7_mat[] = {
    &kangaskhan_part7_mat0,
    NULL,
};

#include "assets/beach/kangaskhan/model.vtx.inc.c"
#include "assets/beach/kangaskhan/first.gfx.inc.c"
#include "assets/beach/kangaskhan/part0_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part0_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part0_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part1_pre_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part1_pre_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part1_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/part1_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part1_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part1_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part2_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part2_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part2_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part3_pre_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part3_pre_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part3_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/part3_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part3_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part3_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part4_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part4_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part4_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part5_pre_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part5_pre_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part5_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/part5_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part5_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part5_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part6_pre_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part6_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/part6_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part6_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part6_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part7_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part7_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part7_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part8_pre_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part8_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/part8_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part8_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part8_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part9_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part9_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part9_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part10_pre_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part10_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/part10_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part10_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part10_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part11_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part11_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part11_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part12_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part12_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part12_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part13_pre_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part13_pre_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part13_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/part13_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part13_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part13_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part14_pre_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part14_pre_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part14_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/part14_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part14_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part14_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part15_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part15_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part15_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/part16_draw_near.gfx.inc.c"
#include "assets/beach/kangaskhan/part16_draw_far.gfx.inc.c"
#include "assets/beach/kangaskhan/part16_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/last.gfx.inc.c"

DObjPayloadTypeI kangaskhan_gfxdata[] = {
    { NULL, kangaskhan_first },
    { kangaskhan_part1_pre, kangaskhan_part1_draw },
    { NULL, kangaskhan_part2_draw },
    { kangaskhan_part3_pre, kangaskhan_part3_draw },
    { NULL, kangaskhan_part4_draw },
    { kangaskhan_part5_pre, kangaskhan_part5_draw },
    { kangaskhan_part6_pre, kangaskhan_part6_draw },
    { NULL, kangaskhan_part7_draw },
    { kangaskhan_part8_pre, kangaskhan_part8_draw },
    { NULL, kangaskhan_part9_draw },
    { kangaskhan_part10_pre, kangaskhan_part10_draw },
    { NULL, kangaskhan_part11_draw },
    { NULL, kangaskhan_part12_draw },
    { kangaskhan_part13_pre, kangaskhan_part13_draw },
    { kangaskhan_part14_pre, kangaskhan_part14_draw },
    { NULL, kangaskhan_part15_draw },
    { NULL, kangaskhan_last },
};

UnkEC64Arg3 kangaskhan_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &kangaskhan_gfxdata[0],
      { 0.0, 684.7044067382812, -92.33149719238281 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_gfxdata[1],
      { 463.5887145996094, -125.22907257080078, -243.6129150390625 },
      { 0.0, 0.4537850022315979, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_gfxdata[2],
      { -10.329961776733398, -208.87298583984375, 309.1054382324219 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_gfxdata[3],
      { -463.5887145996094, -125.22907257080078, -243.6129150390625 },
      { 0.0, -0.4537850022315979, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_gfxdata[4],
      { 10.330009460449219, -208.87298583984375, 309.1054382324219 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_gfxdata[5],
      { 0.0, -20.668935775756836, -44.09180450439453 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_gfxdata[6],
      { 0.8077620267868042, 892.2918090820312, 48.16659164428711 },
      { 0.13200099766254425, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &kangaskhan_gfxdata[7],
      { -0.06886900216341019, -73.14024353027344, 218.08404541015625 },
      { 0.46000000834465027, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_gfxdata[8],
      { 303.7607116699219, 582.3997802734375, 32.34148025512695 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &kangaskhan_gfxdata[9],
      { 284.4712219238281, -7.547760009765625, -15.129470825195312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_gfxdata[10],
      { -303.7607116699219, 582.3997802734375, 32.34148025512695 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &kangaskhan_gfxdata[11],
      { -284.4712219238281, -7.547760009765625, -15.12948226928711 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_gfxdata[12],
      { 0.0, 578.2371826171875, -267.1535949707031 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_gfxdata[13],
      { 0.0, -386.1555480957031, 511.08819580078125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_gfxdata[14],
      { 0.0, -361.67999267578125, -558.6078491210938 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_gfxdata[15],
      { 0.5630490183830261, -190.57635498046875, 621.5274047851562 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_gfxdata[16],
      { -0.636231005191803, 178.15904235839844, 31.177568435668945 },
      { 0.18000000715255737, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
