#include "common.h"

extern u8 jynx_tex_arm_png[];
extern u8 jynx_tex_torso_pal[];
extern u8 jynx_tex_torso_png[];
extern u8 jynx_tex_eye_0_pal[];
extern u8 jynx_tex_eye_0_png[];
extern u8 jynx_tex_eye_1_png[];
extern u8 jynx_tex_eye_2_png[];
extern u8 jynx_tex_hair_png[];
extern u8 jynx_tex_hair_2_png[];
extern u8 jynx_tex_hair_3_png[];
extern u8 jynx_tex_lips_png[];
extern u8 jynx_tex_dress_pal[];
extern u8 jynx_tex_dress_png[];

extern Texture* jynx_hd_part1_mat[];
extern Gfx jynx_hd_part0_draw[];

Texture** jynx_hd_materials[] = {
    NULL,
    jynx_hd_part1_mat,
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

u8* jynx_hd_part1_mat0_textures[] = {
    jynx_tex_eye_0_png,
    jynx_tex_eye_1_png,
    jynx_tex_eye_2_png,
};

Texture jynx_hd_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    jynx_hd_part1_mat0_textures,
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
    { 0, 0, 0, 0 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* jynx_hd_part1_mat[] = {
    &jynx_hd_part1_mat0,
    NULL,
};

#include "assets/cave/jynx/hd_model.vtx.inc.c"
#include "assets/cave/jynx/hd_first.gfx.inc.c"
#include "assets/cave/jynx/hd_part0_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part1_pre.gfx.inc.c"
#include "assets/cave/jynx/hd_part1_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part2_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part3_pre.gfx.inc.c"
#include "assets/cave/jynx/hd_part3_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part4_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part5_pre.gfx.inc.c"
#include "assets/cave/jynx/hd_part5_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part6_pre.gfx.inc.c"
#include "assets/cave/jynx/hd_part6_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part7_pre.gfx.inc.c"
#include "assets/cave/jynx/hd_part7_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part8_pre.gfx.inc.c"
#include "assets/cave/jynx/hd_part8_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part9_pre.gfx.inc.c"
#include "assets/cave/jynx/hd_part9_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part10_pre.gfx.inc.c"
#include "assets/cave/jynx/hd_part10_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part11_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part12_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part13_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part14_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part15_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part16_draw.gfx.inc.c"
#include "assets/cave/jynx/hd_part17_draw.gfx.inc.c"

DObjPayloadTypeI jynx_hd_gfxdata[] = {
    { NULL, jynx_hd_first },
    { jynx_hd_part1_pre, jynx_hd_part1_draw },
    { NULL, jynx_hd_part2_draw },
    { jynx_hd_part3_pre, jynx_hd_part3_draw },
    { NULL, jynx_hd_part4_draw },
    { jynx_hd_part5_pre, jynx_hd_part5_draw },
    { jynx_hd_part6_pre, jynx_hd_part6_draw },
    { jynx_hd_part7_pre, jynx_hd_part7_draw },
    { jynx_hd_part8_pre, jynx_hd_part8_draw },
    { jynx_hd_part9_pre, jynx_hd_part9_draw },
    { jynx_hd_part10_pre, jynx_hd_part10_draw },
    { NULL, jynx_hd_part11_draw },
    { NULL, jynx_hd_part12_draw },
    { NULL, jynx_hd_part13_draw },
    { NULL, jynx_hd_part14_draw },
    { NULL, jynx_hd_part15_draw },
    { NULL, jynx_hd_part16_draw },
    { NULL, jynx_hd_part17_draw },
};

UnkEC64Arg3 jynx_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &jynx_hd_gfxdata[0],
      { 0.0, 600.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_hd_gfxdata[1],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_hd_gfxdata[2],
      { 0.0, -250.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_hd_gfxdata[3],
      { 0.0, 219.99998474121094, -385.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_hd_gfxdata[4],
      { 0.0, -350.0, -50.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_hd_gfxdata[5],
      { 350.0, 150.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_hd_gfxdata[6],
      { 25.0, -325.0, 180.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_hd_gfxdata[7],
      { -70.00000762939453, -300.0, -200.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_hd_gfxdata[8],
      { -350.0, 150.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_hd_gfxdata[9],
      { -25.0, -325.0, 180.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_hd_gfxdata[10],
      { -69.99998474121094, -300.0, -200.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_hd_gfxdata[11],
      { 4.8000001697801054e-05, 450.0, 275.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_hd_gfxdata[12],
      { 340.0, 280.0000305175781, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_hd_gfxdata[13],
      { 254.99996948242188, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &jynx_hd_gfxdata[14],
      { 324.9999084472656, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jynx_hd_gfxdata[15],
      { -340.0, 280.0000305175781, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &jynx_hd_gfxdata[16],
      { -254.99996948242188, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &jynx_hd_gfxdata[17],
      { -324.9999084472656, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
