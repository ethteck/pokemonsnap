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

extern Texture* kangaskhan_hd_part7_mat[];
extern Gfx kangaskhan_hd_part0_draw[];

Texture** kangaskhan_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    kangaskhan_hd_part7_mat,
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

u8* kangaskhan_hd_part7_mat0_textures[] = {
    kangaskhan_tex_8016D530,
    kangaskhan_tex_8016D960,
    kangaskhan_tex_8016CCD0,
    kangaskhan_tex_8016D100,
};

Texture kangaskhan_hd_part7_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    kangaskhan_hd_part7_mat0_textures,
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

Texture* kangaskhan_hd_part7_mat[] = {
    &kangaskhan_hd_part7_mat0,
    NULL,
};
#include "assets/beach/kangaskhan/hd_model.vtx.inc.c"
#include "assets/beach/kangaskhan/hd_first.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part0_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part1_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part1_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part2_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part3_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part3_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part4_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part5_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part5_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part6_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part6_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part7_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part8_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part8_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part9_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part10_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part10_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part11_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part12_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part13_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part13_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part14_pre.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part14_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part15_draw.gfx.inc.c"
#include "assets/beach/kangaskhan/hd_part16_draw.gfx.inc.c"

DObjPayloadTypeI kangaskhan_hd_gfxdata[] = {
    { NULL, kangaskhan_hd_first },
    { kangaskhan_hd_part1_pre, kangaskhan_hd_part1_draw },
    { NULL, kangaskhan_hd_part2_draw },
    { kangaskhan_hd_part3_pre, kangaskhan_hd_part3_draw },
    { NULL, kangaskhan_hd_part4_draw },
    { kangaskhan_hd_part5_pre, kangaskhan_hd_part5_draw },
    { kangaskhan_hd_part6_pre, kangaskhan_hd_part6_draw },
    { NULL, kangaskhan_hd_part7_draw },
    { kangaskhan_hd_part8_pre, kangaskhan_hd_part8_draw },
    { NULL, kangaskhan_hd_part9_draw },
    { kangaskhan_hd_part10_pre, kangaskhan_hd_part10_draw },
    { NULL, kangaskhan_hd_part11_draw },
    { NULL, kangaskhan_hd_part12_draw },
    { kangaskhan_hd_part13_pre, kangaskhan_hd_part13_draw },
    { kangaskhan_hd_part14_pre, kangaskhan_hd_part14_draw },
    { NULL, kangaskhan_hd_part15_draw },
    { NULL, kangaskhan_hd_part16_draw },
};

UnkEC64Arg3 kangaskhan_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &kangaskhan_hd_gfxdata[0],
      { 0.0, 684.7044067382812, -92.33149719238281 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_hd_gfxdata[1],
      { 463.5887145996094, -125.2290267944336, -243.6129608154297 },
      { 0.0, 0.4537859857082367, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_hd_gfxdata[2],
      { -10.330009460449219, -208.87298583984375, 309.10540771484375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_hd_gfxdata[3],
      { -463.5887145996094, -125.2290267944336, -243.6129608154297 },
      { 0.0, -0.4537859857082367, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_hd_gfxdata[4],
      { 10.329961776733398, -208.87298583984375, 309.1054382324219 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_hd_gfxdata[5],
      { 0.0, -20.668983459472656, -44.09180450439453 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_hd_gfxdata[6],
      { 0.8077620267868042, 892.2919921875, 48.166648864746094 },
      { 0.13200099766254425, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &kangaskhan_hd_gfxdata[7],
      { -0.06904599815607071, -51.003170013427734, 224.29588317871094 },
      { 0.48200199007987976, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_hd_gfxdata[8],
      { 303.7603454589844, 582.3997802734375, 32.34148025512695 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &kangaskhan_hd_gfxdata[9],
      { 284.47119140625, -7.547379016876221, -15.129470825195312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_hd_gfxdata[10],
      { -303.7603454589844, 582.3997802734375, 32.34148025512695 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &kangaskhan_hd_gfxdata[11],
      { -284.4711608886719, -7.547379016876221, -15.129470825195312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_hd_gfxdata[12],
      { 0.0, 578.2372436523438, -267.153564453125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_hd_gfxdata[13],
      { 0.0, -386.155517578125, 511.08807373046875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_hd_gfxdata[14],
      { 0.0, -361.6800842285156, -558.6082153320312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &kangaskhan_hd_gfxdata[15],
      { 0.5630490183830261, -190.5764617919922, 621.52734375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &kangaskhan_hd_gfxdata[16],
      { -0.6362299919128418, 178.15904235839844, 31.177520751953125 },
      { 0.18000000715255737, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
