#include "common.h"

extern u8 slowbro_tex_80191D88[];
extern u8 slowbro_tex_80191DB0_png[];
extern u8 slowbro_tex_80191FB8[];
extern u8 slowbro_tex_80191FE0_png[];
extern u8 slowbro_tex_801921E8[];
extern u8 slowbro_tex_80192210_png[];
extern u8 slowbro_tex_80192618[];
extern u8 slowbro_tex_80192640_png[];
extern u8 slowbro_tex_80192A48[];
extern u8 slowbro_tex_80192A70_png[];
extern u8 slowbro_tex_80192C78[];
extern u8 slowbro_tex_80192CA0[];
extern u8 slowbro_tex_801930A8[];
extern u8 slowbro_tex_801930D0_png[];
extern u8 slowbro_tex_801932D8[];
extern u8 slowbro_tex_80193300_png[];
extern u8 slowbro_tex_80193708[];
extern u8 slowbro_tex_80193730_png[];
extern u8 slowbro_tex_80193960[];
extern u8 slowbro_tex_80193D68[];
extern u8 slowbro_tex_80193D90_png[];
extern u8 slowbro_tex_80193F98[];
extern u8 slowbro_tex_80193FC0_png[];

extern Texture* slowbro_part10_mat[];
extern Gfx slowbro_part0_draw[];

__ALIGNER
u8 slowbro_tex_80338958[] = {
#include "assets/river/slowbro/tex_80338980.pal.bin.c"
};

__ALIGNER
u8 slowbro_tex_80338980_png[] = {
#include "assets/river/slowbro/tex_80338980.png.bin.c"
};

Texture** slowbro_materials[] = {
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
    slowbro_part10_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* slowbro_part10_mat0_textures[] = {
    slowbro_tex_80192CA0,
    slowbro_tex_80193960,
};

Texture slowbro_part10_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    slowbro_part10_mat0_textures,
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
    0x1,
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
    { 64, 64, 64, 0 },
    0,
    0,
    0,
    0,
};

Texture* slowbro_part10_mat[] = {
    &slowbro_part10_mat0,
    NULL,
};

#include "assets/river/slowbro/model.vtx.inc.c"
#include "assets/river/slowbro/first.gfx.inc.c"
#include "assets/river/slowbro/part0_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part0_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part0_draw.gfx.inc.c"
#include "assets/river/slowbro/part1_pre_near.gfx.inc.c"
#include "assets/river/slowbro/part1_pre.gfx.inc.c"
#include "assets/river/slowbro/part1_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part1_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part1_draw.gfx.inc.c"
#include "assets/river/slowbro/part2_pre_near.gfx.inc.c"
#include "assets/river/slowbro/part2_pre.gfx.inc.c"
#include "assets/river/slowbro/part2_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part2_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part2_draw.gfx.inc.c"
#include "assets/river/slowbro/part3_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part3_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part3_draw.gfx.inc.c"
#include "assets/river/slowbro/part4_pre_near.gfx.inc.c"
#include "assets/river/slowbro/part4_pre.gfx.inc.c"
#include "assets/river/slowbro/part4_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part4_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part4_draw.gfx.inc.c"
#include "assets/river/slowbro/part5_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part5_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part5_draw.gfx.inc.c"
#include "assets/river/slowbro/part6_pre_near.gfx.inc.c"
#include "assets/river/slowbro/part6_pre.gfx.inc.c"
#include "assets/river/slowbro/part6_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part6_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part6_draw.gfx.inc.c"
#include "assets/river/slowbro/part7_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part7_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part7_draw.gfx.inc.c"
#include "assets/river/slowbro/part8_pre_near.gfx.inc.c"
#include "assets/river/slowbro/part8_pre.gfx.inc.c"
#include "assets/river/slowbro/part8_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part8_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part8_draw.gfx.inc.c"
#include "assets/river/slowbro/part9_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part9_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part9_draw.gfx.inc.c"
#include "assets/river/slowbro/part10_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part10_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part10_draw.gfx.inc.c"
#include "assets/river/slowbro/part11_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part11_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part11_draw.gfx.inc.c"
#include "assets/river/slowbro/part12_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part12_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part12_draw.gfx.inc.c"
#include "assets/river/slowbro/part13_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part13_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part13_draw.gfx.inc.c"
#include "assets/river/slowbro/part14_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part14_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part14_draw.gfx.inc.c"
#include "assets/river/slowbro/part15_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part15_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part15_draw.gfx.inc.c"
#include "assets/river/slowbro/part16_draw_near.gfx.inc.c"
#include "assets/river/slowbro/part16_draw_far.gfx.inc.c"
#include "assets/river/slowbro/part16_draw.gfx.inc.c"
#include "assets/river/slowbro/last.gfx.inc.c"

DObjPayloadTypeI slowbro_gfxdata[] = {
    { NULL, slowbro_first },
    { slowbro_part1_pre, slowbro_part1_draw },
    { slowbro_part2_pre, slowbro_part2_draw },
    { NULL, slowbro_part3_draw },
    { slowbro_part4_pre, slowbro_part4_draw },
    { NULL, slowbro_part5_draw },
    { slowbro_part6_pre, slowbro_part6_draw },
    { NULL, slowbro_part7_draw },
    { slowbro_part8_pre, slowbro_part8_draw },
    { NULL, slowbro_part9_draw },
    { NULL, slowbro_part10_draw },
    { NULL, slowbro_part11_draw },
    { NULL, slowbro_part12_draw },
    { NULL, slowbro_part13_draw },
    { NULL, slowbro_part14_draw },
    { NULL, slowbro_part15_draw },
    { NULL, slowbro_last },
};

UnkEC64Arg3 slowbro_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &slowbro_gfxdata[0],
      { 0.0, 650.0, 150.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowbro_gfxdata[1],
      { 0.0, -50.0, 20.000003814697266 },
      { -0.03141599893569946, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_gfxdata[2],
      { 0.0, 500.0001525878906, 1.2000000424450263e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_gfxdata[3],
      { 0.0, -70.00016784667969, 250.00003051757812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_gfxdata[4],
      { 300.0, 299.99993896484375, 150.00003051757812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_gfxdata[5],
      { 200.0, -49.99990463256836, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_gfxdata[6],
      { -300.0, 299.99993896484375, 150.00003051757812 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_gfxdata[7],
      { 200.0, -49.99990463256836, 7.200000254670158e-05 },
      { 0.0, -9.999999974752427e-07, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowbro_gfxdata[8],
      { 0.0, -350.0, -350.0 },
      { 0.07853999733924866, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_gfxdata[9],
      { 0.0, -75.0001220703125, -550.0001831054688 },
      { -0.07853999733924866, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_gfxdata[10],
      { 70.0, -50.0, -30.00006675720215 },
      { 0.0872659981250763, -0.9599310159683228, 0.0 },
      { 1.2999999523162842, 1.2999999523162842, 1.3000010251998901 } },
    { 2,
      &slowbro_gfxdata[11],
      { 400.0, -100.0, 100.0 },
      { -0.17453299462795258, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_gfxdata[12],
      { 35.0001335144043, -249.9999542236328, -99.99996185302734 },
      { -0.026179999113082886, 6.283185005187988, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_gfxdata[13],
      { -0.00023799999326001853, -249.99990844726562, 149.99986267089844 },
      { 0.0, 6.283185005187988, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowbro_gfxdata[14],
      { -400.0, -100.0, 100.0 },
      { 0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_gfxdata[15],
      { 35.0001106262207, -249.9999237060547, 99.9999771118164 },
      { 0.026179999113082886, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_gfxdata[16],
      { -0.00021499999274965376, -249.9999237060547, -149.99986267089844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
