#include <common.h>

extern Gfx magnemite_part0_draw[];

extern u8 magnemite_tex_body_frame0_pal[];
extern u8 magnemite_tex_screw_thread_frame0_pal[];
extern u8 magnemite_tex_screw_frame0_pal[];
extern u8 magnemite_tex_magnet_frame0_pal[];
extern u8 magnemite_tex_eye_frame0_pal[];
extern u8 magnemite_tex_wave_png[];

extern u8 magnemite_tex_body_frame0_png[];
extern u8 magnemite_tex_body_frame1_png[];
extern u8 magnemite_tex_body_frame2_png[];
extern u8 magnemite_tex_screw_thread_frame0_png[];
extern u8 magnemite_tex_screw_thread_frame1_png[];
extern u8 magnemite_tex_screw_thread_frame2_png[];
extern u8 magnemite_tex_screw_frame0_png[];
extern u8 magnemite_tex_screw_frame1_png[];
extern u8 magnemite_tex_screw_frame2_png[];
extern u8 magnemite_tex_eye_frame0_png[];

extern u8 magnemite_tex_eye_frame1_png[];
extern u8 magnemite_tex_eye_frame2_png[];
extern u8 magnemite_tex_magnet_frame0_png[];
extern u8 magnemite_tex_magnet_frame1_png[];
extern u8 magnemite_tex_magnet_frame2_png[];

extern Texture* magnemite_part0_mat[];
extern Texture* magnemite_part1_mat[];
extern Texture* magnemite_part2_mat[];
extern Texture* magnemite_part4_mat[];
extern Texture* magnemite_part6_mat[];
extern Texture* magnemite_part7_mat[];
extern Texture* magnemite_part8_mat[];

Texture** magnemite_materials[] = {
    NULL,
    magnemite_part0_mat,
    magnemite_part1_mat,
    magnemite_part2_mat,
    NULL,
    magnemite_part4_mat,
    NULL,
    magnemite_part6_mat,
    magnemite_part7_mat,
    magnemite_part8_mat,
    NULL,
    NULL,
};

u8* magnemite_part0_mat0_textures[] = {
    magnemite_tex_body_frame0_png,
    magnemite_tex_body_frame1_png,
    magnemite_tex_body_frame2_png
};

u8* magnemite_part1_mat0_textures[] = {
    magnemite_tex_screw_thread_frame0_png,
    magnemite_tex_screw_thread_frame1_png,
    magnemite_tex_screw_thread_frame2_png
};

u8* magnemite_part1_mat1_textures[] = {
    magnemite_tex_screw_frame0_png,
    magnemite_tex_screw_frame1_png,
    magnemite_tex_screw_frame2_png,
};

u8* magnemite_part2_mat0_textures[] = {
    magnemite_tex_eye_frame0_png,
    NULL,
    magnemite_tex_eye_frame1_png,
    magnemite_tex_eye_frame2_png,
};

u8* magnemite_part4_mat0_textures[] = {
    magnemite_tex_magnet_frame0_png,
    magnemite_tex_magnet_frame1_png,
    magnemite_tex_magnet_frame2_png
};

u8* magnemite_part6_mat0_textures[] = {
    magnemite_tex_magnet_frame0_png,
    magnemite_tex_magnet_frame1_png,
    magnemite_tex_magnet_frame2_png
};

u8* magnemite_part7_mat0_textures[] = {
    magnemite_tex_screw_thread_frame0_png,
    magnemite_tex_screw_thread_frame1_png,
    magnemite_tex_screw_thread_frame2_png
};

u8* magnemite_part7_mat1_textures[] = {    
    magnemite_tex_screw_frame0_png,
    magnemite_tex_screw_frame1_png,
    magnemite_tex_screw_frame2_png,
    NULL
};

Texture magnemite_part0_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_part0_mat0_textures,
    128,
    64,
    128, 64,
    1,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 64,
    128, 64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    255, 255, 255, 0,
    38, 38, 38, 0,
    0,
    0,
    0,
    0,
};

Texture magnemite_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_part1_mat0_textures,
    128,
    64,
    32, 64,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 64,
    32, 64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    255, 255, 255, 0,
    38, 38, 38, 0,
    0,
    0,
    0,
    0,
};

Texture magnemite_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_part1_mat1_textures,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    255, 255, 255, 0,
    38, 38, 38, 0,
    0,
    0,
    0,
    0,
};

Texture magnemite_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_part2_mat0_textures,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    255, 255, 255, 0,
    38, 38, 38, 0,
    0,
    0,
    0,
    0,
};

Texture magnemite_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_part4_mat0_textures,
    128,
    64,
    32, 64,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 64,
    32, 64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    255, 255, 255, 0,
    38, 38, 38, 0,
    0,
    0,
    0,
    0,
};

Texture magnemite_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_part6_mat0_textures,
    128,
    64,
    32, 64,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 64,
    32, 64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    255, 255, 255, 0,
    38, 38, 38, 0,
    0,
    0,
    0,
    0,
};

Texture magnemite_part7_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_part7_mat0_textures,
    128,
    64,
    32, 64,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 64,
    32, 64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    255, 255, 255, 0,
    38, 38, 38, 0,
    0,
    0,
    0,
    0,
};

Texture magnemite_part7_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_part7_mat1_textures,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    255, 255, 255, 0,
    38, 38, 38, 0,
    0,
    0,
    0,
    0,
};

Texture magnemite_part8_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    32, 32,
    0,
    0.21628299355506897, 0.08218000084161758,
    0.6074349880218506, 0.7236419916152954,
    0.21628299355506897,
    0.6074349880218506,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32, 32,
    32, 32,
    0.21628299355506897,
    0.08218000084161758,
    0.21628299355506897,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    255, 255, 255, 255,
    0, 0, 0, 8,
    96, 255, 96, 0,
    76, 76, 76, 0,
    0,
    0,
    0,
    0,
};

Texture* magnemite_part0_mat[] = {
    &magnemite_part0_mat0,
    NULL,
};

Texture* magnemite_part1_mat[] = {
    &magnemite_part1_mat0,
    &magnemite_part1_mat1,
    NULL,
};

Texture* magnemite_part2_mat[] = {
    &magnemite_part2_mat0,
    NULL,
};

Texture* magnemite_part4_mat[] = {
    &magnemite_part4_mat0,
    NULL,
};


Texture* magnemite_part6_mat[] = {
    &magnemite_part6_mat0,
    NULL,
};

Texture* magnemite_part7_mat[] = {
    &magnemite_part7_mat0,
    &magnemite_part7_mat1,
    NULL,
};

Texture* magnemite_part8_mat[] = {
    &magnemite_part8_mat0,
    NULL,
};

#include "assets/tunnel/magnemite/model.vtx.inc.c"
#include "assets/tunnel/magnemite/first.gfx.inc.c"
#include "assets/tunnel/magnemite/part0_draw_near.gfx.inc.c"
#include "assets/tunnel/magnemite/part0_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/part1_draw_near.gfx.inc.c"
#include "assets/tunnel/magnemite/part1_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/part2_draw_near.gfx.inc.c"
#include "assets/tunnel/magnemite/part2_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/part3_draw_near.gfx.inc.c"
#include "assets/tunnel/magnemite/part3_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/part4_draw_near.gfx.inc.c"
#include "assets/tunnel/magnemite/part4_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/part5_draw_near.gfx.inc.c"
#include "assets/tunnel/magnemite/part5_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/last.gfx.inc.c"
#include "assets/tunnel/magnemite/part6_draw_near.gfx.inc.c"
#include "assets/tunnel/magnemite/part6_draw.gfx.inc.c"

DObjPayloadTypeC magnemite_gfxdata[] = {
    { 0, magnemite_first },
    { 4, NULL },
    { 0, magnemite_part1_draw },
    { 4, NULL },
    { 0, magnemite_part2_draw },
    { 4, NULL },
    { 0, magnemite_part3_draw },
    { 4, NULL },
    { 0, magnemite_part4_draw },
    { 4, NULL },
    { 0, magnemite_last },
    { 4, NULL },
    { 1, magnemite_part6_draw },
    { 4, NULL },
};

UnkEC64Arg3 magnemite_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &magnemite_gfxdata[0],
      { 0.0, 500.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magnemite_gfxdata[2],
      { -9.000000318337698e-06, -74.30977630615234, 96.37504577636719 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magnemite_gfxdata[4],
      { 9.999999974752427e-07, 0.0, -3.099999958067201e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magnemite_gfxdata[6],
      { 131.62266540527344, 0.441769003868103, 0.0 },
      { 0.0, 0.0, 0.520110011100769 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magnemite_gfxdata[8],
      { -131.6196746826172, -0.8999530076980591, 0.0 },
      { 0.0, 0.0, -2.6179940700531006 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magnemite_gfxdata[10],
      { 9.999999974752427e-07, 0.0, -3.099999958067201e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &magnemite_gfxdata[12],
      { -1.9999999949504854e-06, -0.0001429999974789098, -3.099999958067201e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 700.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { -700.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
