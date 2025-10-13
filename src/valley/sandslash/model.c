#include "common.h"

extern u8 sandslash_tex_80169CF8[];
extern u8 sandslash_tex_80169D20_png[];
extern u8 sandslash_tex_80169F28[];
extern u8 sandslash_tex_80169F50_png[];
extern u8 sandslash_tex_8016A158[];
extern u8 sandslash_tex_8016A180_png[];
extern u8 sandslash_tex_8016A1D0[];
extern u8 sandslash_tex_8016A600[];
extern u8 sandslash_tex_8016AA08[];
extern u8 sandslash_tex_8016AA30[];
extern u8 sandslash_tex_8016AE38[];
extern u8 sandslash_tex_8016AE60_png[];
extern u8 sandslash_tex_8016AEE8[];

extern Texture* sandslash_part9_mat[];
extern Gfx sandslash_part0_draw[];

__ALIGNER
u8 sandslash_tex_8033D3B8[] = {
#include "assets/valley/sandslash/sandslash_tex_8033D3D8.pal.bin.c"
};

__ALIGNER
u8 sandslash_tex_8033D3D8_png[] = {
#include "assets/valley/sandslash/sandslash_tex_8033D3D8.png.bin.c"
};

Texture** sandslash_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sandslash_part9_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* sandslash_part9_mat0_textures[] = {
    sandslash_tex_8016AA30,
    sandslash_tex_8016A600,
    sandslash_tex_8016A1D0,
    NULL,
};

Texture sandslash_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    sandslash_part9_mat0_textures,
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
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* sandslash_part9_mat[] = {
    &sandslash_part9_mat0,
    NULL,
};

#include "assets/valley/sandslash/model.vtx.inc.c"
#include "assets/valley/sandslash/first.gfx.inc.c"
#include "assets/valley/sandslash/part0_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part0_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part0_draw.gfx.inc.c"
#include "assets/valley/sandslash/part1_pre_near.gfx.inc.c"
#include "assets/valley/sandslash/part1_pre_far.gfx.inc.c"
#include "assets/valley/sandslash/part1_pre.gfx.inc.c"
#include "assets/valley/sandslash/part1_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part1_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part1_draw.gfx.inc.c"
#include "assets/valley/sandslash/part2_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part2_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part2_draw.gfx.inc.c"
#include "assets/valley/sandslash/part3_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part3_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part3_draw.gfx.inc.c"
#include "assets/valley/sandslash/part4_pre_near.gfx.inc.c"
#include "assets/valley/sandslash/part4_pre_far.gfx.inc.c"
#include "assets/valley/sandslash/part4_pre.gfx.inc.c"
#include "assets/valley/sandslash/part4_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part4_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part4_draw.gfx.inc.c"
#include "assets/valley/sandslash/part5_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part5_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part5_draw.gfx.inc.c"
#include "assets/valley/sandslash/part6_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part6_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part6_draw.gfx.inc.c"
#include "assets/valley/sandslash/part7_pre_near.gfx.inc.c"
#include "assets/valley/sandslash/part7_pre_far.gfx.inc.c"
#include "assets/valley/sandslash/part7_pre.gfx.inc.c"
#include "assets/valley/sandslash/part7_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part7_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part7_draw.gfx.inc.c"
#include "assets/valley/sandslash/part8_pre_near.gfx.inc.c"
#include "assets/valley/sandslash/part8_pre.gfx.inc.c"
#include "assets/valley/sandslash/part8_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part8_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part8_draw.gfx.inc.c"
#include "assets/valley/sandslash/part9_pre_near.gfx.inc.c"
#include "assets/valley/sandslash/part9_pre.gfx.inc.c"
#include "assets/valley/sandslash/part9_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part9_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part9_draw.gfx.inc.c"
#include "assets/valley/sandslash/part10_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part10_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part10_draw.gfx.inc.c"
#include "assets/valley/sandslash/part11_pre_near.gfx.inc.c"
#include "assets/valley/sandslash/part11_pre.gfx.inc.c"
#include "assets/valley/sandslash/part11_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part11_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part11_draw.gfx.inc.c"
#include "assets/valley/sandslash/part12_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part12_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part12_draw.gfx.inc.c"
#include "assets/valley/sandslash/part13_pre_near.gfx.inc.c"
#include "assets/valley/sandslash/part13_pre_far.gfx.inc.c"
#include "assets/valley/sandslash/part13_pre.gfx.inc.c"
#include "assets/valley/sandslash/part13_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part13_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part13_draw.gfx.inc.c"
#include "assets/valley/sandslash/part14_draw_near.gfx.inc.c"
#include "assets/valley/sandslash/part14_draw_far.gfx.inc.c"
#include "assets/valley/sandslash/part14_draw.gfx.inc.c"
#include "assets/valley/sandslash/last.gfx.inc.c"

DObjPayloadTypeI sandslash_gfxdata[] = {
    { NULL, sandslash_first },
    { sandslash_part1_pre, sandslash_part1_draw },
    { NULL, sandslash_part2_draw },
    { NULL, sandslash_part3_draw },
    { sandslash_part4_pre, sandslash_part4_draw },
    { NULL, sandslash_part5_draw },
    { NULL, sandslash_part6_draw },
    { sandslash_part7_pre, sandslash_part7_draw },
    { sandslash_part8_pre, sandslash_part8_draw },
    { sandslash_part9_pre, sandslash_part9_draw },
    { NULL, sandslash_part10_draw },
    { sandslash_part11_pre, sandslash_part11_draw },
    { NULL, sandslash_part12_draw },
    { sandslash_part13_pre, sandslash_part13_draw },
    { NULL, sandslash_last },
};

UnkEC64Arg3 sandslash_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &sandslash_gfxdata[0],
      { 0.0, 318.14788818359375, -111.77766418457031 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandslash_gfxdata[1],
      { 140.4499969482422, -7.608891010284424, -13.650035858154297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_gfxdata[2],
      { 62.82680130004883, -99.7020034790039, 141.01760864257812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &sandslash_gfxdata[3],
      { -36.976802825927734, -147.6562042236328, -145.8144989013672 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandslash_gfxdata[4],
      { -140.45120239257812, -7.608891010284424, -13.650035858154297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_gfxdata[5],
      { -62.82559585571289, -99.7020034790039, 141.01760864257812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &sandslash_gfxdata[6],
      { 36.978004455566406, -147.6562042236328, -145.8144989013672 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandslash_gfxdata[7],
      { 0.0, 144.34228515625, 87.92866516113281 },
      { 0.46000000834465027, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_gfxdata[8],
      { -0.0006000000284984708, 216.07107543945312, -1.0652780532836914 },
      { 0.11999999731779099, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_gfxdata[9],
      { 166.714599609375, 138.47975158691406, 18.64545440673828 },
      { 0.46000000834465027, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &sandslash_gfxdata[10],
      { 65.04090118408203, -21.04608917236328, 163.25254821777344 },
      { -0.6774920225143433, 0.11164700239896774, 0.3083859980106354 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_gfxdata[11],
      { -166.70999145507812, 138.47975158691406, 18.64545440673828 },
      { 0.46000000834465027, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &sandslash_gfxdata[12],
      { -70.25311279296875, -17.42284393310547, 162.1907501220703 },
      { -0.6787469983100891, -0.042201001197099686, -0.3612389862537384 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandslash_gfxdata[13],
      { 0.0, -90.48609924316406, -177.7487335205078 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_gfxdata[14],
      { 0.0, -67.38800048828125, -212.45338439941406 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
