#include "common.h"

extern u8 magmar_tex_arm1_pal[];
extern u8 magmar_tex_arm1_png[];
extern u8 magmar_tex_beak_pal[];
extern u8 magmar_tex_beak_png[];
extern u8 magmar_tex_claw_pal[];
extern u8 magmar_tex_claw_png[];
extern u8 magmar_tex_eye_frame0_pal[];
extern u8 magmar_tex_mouth_pal[];
extern u8 magmar_tex_mouth_png[];
extern u8 magmar_tex_shackles_pal[];
extern u8 magmar_tex_shackles_png[];
extern u8 magmar_tex_skin1_pal[];
extern u8 magmar_tex_skin1_png[];
extern u8 magmar_tex_skin2_pal[];
extern u8 magmar_tex_skin2_png[];
extern u8 magmar_tex_eye_frame0_png[];
extern u8 magmar_tex_eye_frame1_png[];
extern u8 magmar_tex_eye_frame2_png[];
extern u8 magmar_tex_eye_frame3_png[];
extern u8 magmar_tex_flame_frame0_png[];
extern u8 magmar_tex_flame_frame1_png[];
extern u8 magmar_tex_flame_frame2_png[];
extern u8 magmar_tex_flame_frame3_png[];

extern Texture* magmar_hd_part4_mat[];
extern Texture* magmar_hd_part6_mat[];
extern Gfx magmar_hd_part0_draw[];

__ALIGNER
u8 magmar_hd_tex_801A9930_pal[] = {
#include "assets/volcano/magmar/tex_801A9930_hd.pal.bin.c"
};

__ALIGNER
u8 magmar_hd_tex_801A9930_png[] = {
#include "assets/volcano/magmar/tex_801A9930_hd.png.bin.c"
};

Texture** magmar_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    magmar_hd_part4_mat,
    NULL,
    magmar_hd_part6_mat,
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

u8* magmar_hd_part4_mat0_textures[] = {
    magmar_tex_flame_frame0_png,
    magmar_tex_flame_frame1_png,
    magmar_tex_flame_frame2_png,
    magmar_tex_flame_frame3_png,
};

u8* magmar_hd_part6_mat0_textures[] = {
    magmar_tex_eye_frame0_png,
    magmar_tex_eye_frame1_png,
    magmar_tex_eye_frame2_png,
    magmar_tex_eye_frame3_png,
};

Texture magmar_hd_part4_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    magmar_hd_part4_mat0_textures,
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

Texture magmar_hd_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magmar_hd_part6_mat0_textures,
    128,
    64,
    64,
    32,
    0,
    -0.07805199921131134,
    -0.042486999183893204,
    1.1289039850234985,
    1.1809730529785156,
    -0.07805199921131134,
    1.1289039850234985,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_8b,
    64,
    32,
    64,
    32,
    -0.07805199921131134,
    -0.042486999183893204,
    -0.07805199921131134,
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

Texture* magmar_hd_part4_mat[] = {
    &magmar_hd_part4_mat0,
    NULL,
};

Texture* magmar_hd_part6_mat[] = {
    &magmar_hd_part6_mat0,
    NULL,
};
#include "assets/volcano/magmar/hd_model.vtx.inc.c"
#include "assets/volcano/magmar/hd_first.gfx.inc.c"
#include "assets/volcano/magmar/hd_part0_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part1_pre.gfx.inc.c"
#include "assets/volcano/magmar/hd_part1_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part2_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part4_pre.gfx.inc.c"
#include "assets/volcano/magmar/hd_part4_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part5_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part6_pre.gfx.inc.c"
#include "assets/volcano/magmar/hd_part6_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part7_pre.gfx.inc.c"
#include "assets/volcano/magmar/hd_part7_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part8_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part9_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part10_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part11_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part12_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part13_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part14_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part15_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part16_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part17_draw.gfx.inc.c"
#include "assets/volcano/magmar/hd_part3_draw.gfx.inc.c"

DObjPayloadTypeJ magmar_hd_gfxdata[] = {
    { 0, NULL, magmar_hd_first },
    { 4, NULL, NULL },
    { 0, magmar_hd_part1_pre, magmar_hd_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part2_draw },
    { 4, NULL, NULL },
    { 1, NULL, magmar_hd_part3_draw },
    { 4, NULL, NULL },
    { 0, magmar_hd_part4_pre, magmar_hd_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part5_draw },
    { 4, NULL, NULL },
    { 0, magmar_hd_part6_pre, magmar_hd_part6_draw },
    { 4, NULL, NULL },
    { 0, magmar_hd_part7_pre, magmar_hd_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part8_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part9_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part11_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part13_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part14_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part15_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part16_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_hd_part17_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 magmar_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &magmar_hd_gfxdata[0],
      { 0.0, 424.3455505371094, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magmar_hd_gfxdata[2],
      { 0.0, -210.57264709472656, -298.1397399902344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_hd_gfxdata[4],
      { -3.3151628971099854, 30.517078399658203, -267.0002746582031 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32772,
      &magmar_hd_gfxdata[6],
      { 3.315221071243286, 375.7101135253906, -374.8599548339844 },
      { 0.0, 1.570796012878418, 0.0 },
      { 0.5, 0.5, 1.0 } },
    { 2,
      &magmar_hd_gfxdata[8],
      { 0.0016210000030696392, 0.004482000134885311, -9.500000305706635e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_hd_gfxdata[10],
      { -2.803230047225952, 606.449951171875, 126.79962921142578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      NULL,
      { 0.0015879999846220016, -182.20425415039062, 214.5935516357422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &magmar_hd_gfxdata[12],
      { 152.00001525878906, 399.8900451660156, -160.4499969482422 },
      { -0.2530730068683624, 0.22689299285411835, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &magmar_hd_gfxdata[14],
      { -151.99998474121094, 399.8900451660156, -160.44998168945312 },
      { -0.2530730068683624, -0.22689299285411835, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_hd_gfxdata[16],
      { 231.3234100341797, 329.9699401855469, 16.660118103027344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &magmar_hd_gfxdata[18],
      { 212.6752166748047, -13.170051574707031, -2.5387139320373535 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_hd_gfxdata[20],
      { -231.33001708984375, 329.9699401855469, 16.660140991210938 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &magmar_hd_gfxdata[22],
      { -212.67184448242188, -13.170051574707031, -2.5387380123138428 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magmar_hd_gfxdata[24],
      { 229.44000244140625, -86.62557983398438, -149.17999267578125 },
      { 0.0, 0.2932150065898895, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_hd_gfxdata[26],
      { -0.5410190224647522, -196.60000610351562, 33.69159698486328 },
      { 0.0, -0.06544999778270721, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &magmar_hd_gfxdata[28],
      { -10.953545570373535, -107.3600082397461, 19.223148345947266 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magmar_hd_gfxdata[30],
      { -229.4400177001953, -86.62557983398438, -149.17999267578125 },
      { 0.0, -0.2932150065898895, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_hd_gfxdata[32],
      { 0.5412579774856567, -196.59999084472656, 33.69157409667969 },
      { 0.0, 0.06544999778270721, 0.0 },
      { 0.9999989867210388, 1.0, 0.9999989867210388 } },
    { 4,
      &magmar_hd_gfxdata[34],
      { 10.953235626220703, -107.3600082397461, 19.223182678222656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
