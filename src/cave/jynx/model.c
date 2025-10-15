#include "common.h"

extern u8 jynx_tex_80193B48[];
extern u8 jynx_tex_80194B50[];
extern u8 jynx_tex_80194B78_png[];
extern u8 jynx_tex_80194F80[];
extern u8 jynx_tex_80194FA8[];
extern u8 jynx_tex_801951D8[];
extern u8 jynx_tex_80195408[];
extern u8 jynx_tex_80195610[];
extern u8 jynx_tex_80195E18[];
extern u8 jynx_tex_80196E20[];
extern u8 jynx_tex_80197E28[];
extern u8 jynx_tex_80198E30[];
extern u8 jynx_tex_80198E58_png[];

extern Texture* jynx_part1_mat[];
extern Gfx jynx_part0_draw[];

Texture** jynx_materials[] = {
    NULL,
    jynx_part1_mat,
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
    NULL,
    NULL,
};

u8* jynx_part1_mat0_textures[] = {
    jynx_tex_80194FA8,
    jynx_tex_801951D8,
    jynx_tex_80195408,
};

Texture jynx_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    jynx_part1_mat0_textures,
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
    { 0, 0, 0, 0 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* jynx_part1_mat[] = {
    &jynx_part1_mat0,
    NULL,
};

#include "assets/cave/jynx/model.vtx.inc.c"
#include "assets/cave/jynx/first.gfx.inc.c"
#include "assets/cave/jynx/part0_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part0_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part0_draw.gfx.inc.c"
#include "assets/cave/jynx/part1_pre_near.gfx.inc.c"
#include "assets/cave/jynx/part1_pre_far.gfx.inc.c"
#include "assets/cave/jynx/part1_pre.gfx.inc.c"
#include "assets/cave/jynx/part1_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part1_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part1_draw.gfx.inc.c"
#include "assets/cave/jynx/part2_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part2_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part2_draw.gfx.inc.c"
#include "assets/cave/jynx/part3_pre_near.gfx.inc.c"
#include "assets/cave/jynx/part3_pre_far.gfx.inc.c"
#include "assets/cave/jynx/part3_pre.gfx.inc.c"
#include "assets/cave/jynx/part3_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part3_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part3_draw.gfx.inc.c"
#include "assets/cave/jynx/part4_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part4_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part4_draw.gfx.inc.c"
#include "assets/cave/jynx/part5_pre_near.gfx.inc.c"
#include "assets/cave/jynx/part5_pre_far.gfx.inc.c"
#include "assets/cave/jynx/part5_pre.gfx.inc.c"
#include "assets/cave/jynx/part5_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part5_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part5_draw.gfx.inc.c"
#include "assets/cave/jynx/part6_pre_near.gfx.inc.c"
#include "assets/cave/jynx/part6_pre_far.gfx.inc.c"
#include "assets/cave/jynx/part6_pre.gfx.inc.c"
#include "assets/cave/jynx/part6_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part6_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part6_draw.gfx.inc.c"
#include "assets/cave/jynx/part7_pre_near.gfx.inc.c"
#include "assets/cave/jynx/part7_pre_far.gfx.inc.c"
#include "assets/cave/jynx/part7_pre.gfx.inc.c"
#include "assets/cave/jynx/part7_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part7_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part7_draw.gfx.inc.c"
#include "assets/cave/jynx/part8_pre_near.gfx.inc.c"
#include "assets/cave/jynx/part8_pre_far.gfx.inc.c"
#include "assets/cave/jynx/part8_pre.gfx.inc.c"
#include "assets/cave/jynx/part8_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part8_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part8_draw.gfx.inc.c"
#include "assets/cave/jynx/part9_pre_near.gfx.inc.c"
#include "assets/cave/jynx/part9_pre_far.gfx.inc.c"
#include "assets/cave/jynx/part9_pre.gfx.inc.c"
#include "assets/cave/jynx/part9_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part9_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part9_draw.gfx.inc.c"
#include "assets/cave/jynx/part10_pre_near.gfx.inc.c"
#include "assets/cave/jynx/part10_pre_far.gfx.inc.c"
#include "assets/cave/jynx/part10_pre.gfx.inc.c"
#include "assets/cave/jynx/part10_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part10_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part10_draw.gfx.inc.c"
#include "assets/cave/jynx/part11_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part11_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part11_draw.gfx.inc.c"
#include "assets/cave/jynx/part12_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part12_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part12_draw.gfx.inc.c"
#include "assets/cave/jynx/part13_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part13_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part13_draw.gfx.inc.c"
#include "assets/cave/jynx/part14_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part14_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part14_draw.gfx.inc.c"
#include "assets/cave/jynx/part15_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part15_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part15_draw.gfx.inc.c"
#include "assets/cave/jynx/part16_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part16_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part16_draw.gfx.inc.c"
#include "assets/cave/jynx/part17_draw_near.gfx.inc.c"
#include "assets/cave/jynx/part17_draw_far.gfx.inc.c"
#include "assets/cave/jynx/part17_draw.gfx.inc.c"
#include "assets/cave/jynx/last.gfx.inc.c"

DObjPayloadTypeI jynx_gfxdata[] = {
    { NULL, jynx_first },
    { jynx_part1_pre, jynx_part1_draw },
    { NULL, jynx_part2_draw },
    { jynx_part3_pre, jynx_part3_draw },
    { NULL, jynx_part4_draw },
    { jynx_part5_pre, jynx_part5_draw },
    { jynx_part6_pre, jynx_part6_draw },
    { jynx_part7_pre, jynx_part7_draw },
    { jynx_part8_pre, jynx_part8_draw },
    { jynx_part9_pre, jynx_part9_draw },
    { jynx_part10_pre, jynx_part10_draw },
    { NULL, jynx_part11_draw },
    { NULL, jynx_part12_draw },
    { NULL, jynx_part13_draw },
    { NULL, jynx_part14_draw },
    { NULL, jynx_part15_draw },
    { NULL, jynx_part16_draw },
    { NULL, jynx_last },
};

UnkEC64Arg3 jynx_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &jynx_gfxdata[0],
      { -150.0, 450.0, 0.0 },
      { 0.34906598925590515, 0.0, 0.5235990285873413 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_gfxdata[1],
      { 75.0, 4.8000001697801054e-05, 0.0 },
      { -0.43633198738098145, -0.0872659981250763, -0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_gfxdata[2],
      { 48.68977737426758, -153.43670654296875, -15.030780792236328 },
      { 0.09813500195741653, 0.01835699938237667, -0.2474370002746582 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_gfxdata[3],
      { -9.500000305706635e-05, 220.0, -385.0 },
      { -0.17453299462795258, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_gfxdata[4],
      { 0.0, -350.0, -50.0 },
      { -0.0872659981250763, 0.0, -0.17453299462795258 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_gfxdata[5],
      { 349.9999084472656, 150.0, 0.0 },
      { -0.17453299462795258, 0.0, -0.0872659981250763 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_gfxdata[6],
      { 25.0, -325.0, 180.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_gfxdata[7],
      { 69.99998474121094, -300.0, -200.0 },
      { -0.13089999556541443, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_gfxdata[8],
      { -349.9998474121094, 150.0, 0.0 },
      { -0.34906598925590515, -0.17453299462795258, -0.47996601462364197 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_gfxdata[9],
      { -25.0, -325.0, 180.0 },
      { 0.0, 0.0, -0.43633198738098145 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_gfxdata[10],
      { -69.99998474121094, -300.0, -200.0 },
      { 0.0, 0.0, -0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_gfxdata[11],
      { 0.0, 450.0, 275.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_gfxdata[12],
      { 325.0, 350.0, 175.0 },
      { 0.17453299462795258, -1.0471969842910767, -1.7453290224075317 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_gfxdata[13],
      { 255.0, 0.0, 0.0 },
      { 1.0471980571746826, -0.34906598925590515, -1.3962630033493042 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &jynx_gfxdata[14],
      { 325.0, -4.8000001697801054e-05, 0.0 },
      { -0.43633198738098145, 0.17453299462795258, -0.785398006439209 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_gfxdata[15],
      { -345.0, 280.0, -150.0 },
      { 0.0, -0.6981319785118103, 0.9599310159683228 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_gfxdata[16],
      { -255.0, 0.0, 0.0 },
      { 0.0, 2.356194019317627, 0.17453299462795258 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &jynx_gfxdata[17],
      { -325.0, 4.8000001697801054e-05, -4.8000001697801054e-05 },
      { -0.43633198738098145, 0.17453299462795258, 0.21816599369049072 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
