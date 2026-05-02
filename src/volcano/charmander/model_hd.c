#include "common.h"

extern u8 charmander_tex_eye_frame1_png[];
extern u8 charmander_tex_eye_frame2_png[];
extern u8 charmander_tex_eye_frame3_png[];
extern u8 charmander_tex_eye_frame4_png[];
extern u8 charmander_tex_eye_frame5_png[];
extern u8 charmander_tex_eye_frame6_png[];
extern u8 charmander_tex_eye_frame7_png[];
extern u8 charmander_tex_eye_frame0_png[];
extern u8 charmander_tex_flame_frame0_png[];
extern u8 charmander_tex_flame_frame1_png[];
extern u8 charmander_tex_flame_frame2_png[];
extern u8 charmander_tex_flame_frame3_png[];
extern u8 D_801BACD8_3E1938[];
extern u8 D_801BAD00_3E1960[];
extern u8 charmander_tex_claw_pal[];
extern u8 charmander_tex_claw_png[];
extern u8 charmander_tex_eye_pal[];
extern u8 charmander_tex_mouth_pal[];
extern u8 charmander_tex_mouth_png[];
extern u8 charmander_tex_nostril_pal[];
extern u8 charmander_tex_nostril_png[];
extern u8 charmander_tex_skin_pal[];
extern u8 charmander_tex_skin_png[];
extern u8 charmander_tex_tongue_pal[];
extern u8 charmander_tex_tongue_png[];

extern u8 D_80173F88_volcano_extra[];
extern u8 D_801BB2B8_volcano_extra[];
extern u8 D_801BB2E0_volcano_extra[];
extern u8 D_801BB650_volcano_extra[];
extern u8 D_801BB660_volcano_extra[];
extern u8 D_801BB680_volcano_extra[];
extern u8 D_801BB690_volcano_extra[];
extern u8 D_801BB6C0_volcano_extra[];
extern u8 D_801BB6D0_volcano_extra[];
extern u8 D_801BB6E0_volcano_extra[];
extern u8 D_801BB6F0_volcano_extra[];
extern u8 D_801BB700_volcano_extra[];
extern u8 D_801BB710_volcano_extra[];
extern u8 D_801BB720_volcano_extra[];
extern u8 D_801BB790_volcano_extra[];
extern u8 D_801BB7B0_volcano_extra[];
extern u8 D_801BB7D0_volcano_extra[];
extern u8 D_801BB7E0_volcano_extra[];
extern u8 D_801BB850_volcano_extra[];
extern u8 D_801BB870_volcano_extra[];
extern u8 D_801BB880_volcano_extra[];
extern u8 D_801BB8A0_volcano_extra[];
extern u8 D_801BB8C0_volcano_extra[];
extern u8 D_801BB8D0_volcano_extra[];
extern u8 D_801BB8E0_volcano_extra[];
extern u8 D_801BB8F0_volcano_extra[];
extern u8 D_801BB900_volcano_extra[];
extern u8 D_801BB910_volcano_extra[];
extern u8 D_801BB920_volcano_extra[];
extern u8 D_801BB960_volcano_extra[];
extern u8 D_801BBA20_volcano_extra[];
extern u8 D_801BBA30_volcano_extra[];
extern u8 D_801BBA40_volcano_extra[];
extern u8 D_801BBAD0_volcano_extra[];
extern u8 D_801BBAE0_volcano_extra[];
extern u8 D_801BBAF0_volcano_extra[];
extern u8 D_801BBB80_volcano_extra[];
extern u8 D_801BBBE0_volcano_extra[];
extern u8 D_801BBCA0_volcano_extra[];
extern u8 D_801BBD30_volcano_extra[];
extern u8 D_801BBD90_volcano_extra[];
extern u8 D_801BBE50_volcano_extra[];
extern u8 D_801BBEF0_volcano_extra[];
extern u8 D_801BBF90_cave_extra[];
extern u8 D_801BBFF0_cave_extra[];
extern u8 D_801BC0B0_volcano_extra[];
extern u8 D_801BC120_cave_extra[];
extern u8 D_801BC140_volcano_extra[];
extern u8 D_801BC150_volcano_extra[];
extern u8 D_801BC1A0_cave_extra[];
extern u8 D_801BC1C0_volcano_extra[];
extern u8 D_801BC1E0_volcano_extra[];
extern u8 D_801BC200_volcano_extra[];
extern u8 D_801BC220_cave_extra[];
extern u8 D_801BC230_volcano_extra[];
extern u8 D_801BC2B0_volcano_extra[];
extern u8 D_801BC2C0_cave_extra[];
extern u8 D_801BC2D0_volcano_extra[];
extern u8 D_801BC2E0_cave_extra[];
extern u8 D_801BC2F0_volcano_extra[];
extern u8 D_801BC300_volcano_extra[];
extern u8 D_801BC310_volcano_extra[];
extern u8 D_801BC340_cave_extra[];
extern u8 D_801BC350_volcano_extra[];
extern u8 D_801BC360_volcano_extra[];
extern u8 D_801BC390_volcano_extra[];
extern u8 D_801BC3B0_volcano_extra[];
extern u8 D_801BC3C0_volcano_extra[];
extern u8 D_801BC3D0_volcano_extra[];
extern u8 D_801BC3E0_cave_extra[];
extern u8 D_801BC400_volcano_extra[];
extern u8 D_801BC440_cave_extra[];
extern u8 D_801BC470_cave_extra[];
extern u8 D_801BC4A0_volcano_extra[];
extern u8 D_801BC4D0_volcano_extra[];
extern u8 D_801BC4F0_volcano_extra[];
extern u8 D_801BC510_volcano_extra[];
extern u8 D_801BC520_volcano_extra[];
extern u8 D_801BC540_cave_extra[];
extern u8 D_801BC590_volcano_extra[];
extern u8 D_801BC5F0_volcano_extra[];
extern u8 D_801BC650_volcano_extra[];
extern u8 D_801BC6B0_volcano_extra[];
extern u8 D_801BC730_volcano_extra[];
extern u8 D_801BC8D0_cave_extra[];
extern u8 D_801BC8F0_volcano_extra[];
extern u8 D_801BC960_volcano_extra[];
extern u8 D_801BC9C0_cave_extra[];
extern u8 D_801BCBC0_cave_extra[];
extern u8 D_801BCC20_volcano_extra[];
extern u8 D_801BCD10_volcano_extra[];
extern u8 D_801BCED0_volcano_extra[];
extern u8 D_801BCF30_volcano_extra[];
extern u8 D_801BD0D0_volcano_extra[];
extern u8 D_801BD130_volcano_extra[];
extern u8 D_801BD220_volcano_extra[];
extern u8 D_801BD3E0_volcano_extra[];
extern u8 D_801BD470_volcano_extra[];
extern u8 D_801BD4C0_volcano_extra[];
extern u8 D_801BD5C0_cave_extra[];
extern u8 D_801BD638_volcano_extra[];

extern Texture* charmander_hd_part6_mat[];
extern Texture* charmander_hd_part14_mat[];
extern Gfx charmander_hd_part0_draw[];

__ALIGNER
u8 charmander_hd_tex_801BAD00_pal[] = {
#include "assets/volcano/charmander/tex_801BAD00_hd.pal.bin.c"
};

__ALIGNER
u8 charmander_hd_tex_801BAD00_png[] = {
#include "assets/volcano/charmander/tex_801BAD00_hd.png.bin.c"
};

Texture** charmander_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    charmander_hd_part6_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    charmander_hd_part14_mat,
};

u8* charmander_hd_part6_mat0_textures[] = {
    charmander_tex_eye_frame0_png,
    charmander_tex_eye_frame1_png,
    charmander_tex_eye_frame2_png,
    charmander_tex_eye_frame3_png,
    charmander_tex_eye_frame4_png,
    charmander_tex_eye_frame5_png,
    charmander_tex_eye_frame6_png,
    charmander_tex_eye_frame7_png,
};

u8* charmander_hd_part14_mat0_textures[] = {
    charmander_tex_flame_frame0_png,
    charmander_tex_flame_frame1_png,
    charmander_tex_flame_frame2_png,
    charmander_tex_flame_frame3_png,
    NULL,
};

Texture charmander_hd_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    charmander_hd_part6_mat0_textures,
    32,
    0,
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

Texture charmander_hd_part14_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    charmander_hd_part14_mat0_textures,
    32,
    0,
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

Texture* charmander_hd_part6_mat[] = {
    &charmander_hd_part6_mat0,
    NULL,
};

Texture* charmander_hd_part14_mat[] = {
    &charmander_hd_part14_mat0,
    NULL,
};
#include "assets/volcano/charmander/hd_model.vtx.inc.c"
#include "assets/volcano/charmander/hd_first.gfx.inc.c"
#include "assets/volcano/charmander/hd_part0_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part1_pre.gfx.inc.c"
#include "assets/volcano/charmander/hd_part1_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part2_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part3_pre.gfx.inc.c"
#include "assets/volcano/charmander/hd_part3_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part4_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part5_pre.gfx.inc.c"
#include "assets/volcano/charmander/hd_part5_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part6_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part7_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part8_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part9_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part10_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part11_pre.gfx.inc.c"
#include "assets/volcano/charmander/hd_part11_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part12_draw.gfx.inc.c"
#include "assets/volcano/charmander/hd_part13_draw.gfx.inc.c"

DObjPayloadTypeJ charmander_hd_gfxdata[] = {
    { 0, NULL, charmander_hd_first },
    { 4, NULL, NULL },
    { 0, charmander_hd_part1_pre, charmander_hd_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_hd_part2_draw },
    { 4, NULL, NULL },
    { 0, charmander_hd_part3_pre, charmander_hd_part3_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_hd_part4_draw },
    { 4, NULL, NULL },
    { 0, charmander_hd_part5_pre, charmander_hd_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_hd_part6_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_hd_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_hd_part8_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_hd_part9_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_hd_part10_draw },
    { 4, NULL, NULL },
    { 0, charmander_hd_part11_pre, charmander_hd_part11_draw },
    { 4, NULL, NULL },
    { 0, NULL, charmander_hd_part12_draw },
    { 4, NULL, NULL },
    { 1, NULL, charmander_hd_part13_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 charmander_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &charmander_hd_gfxdata[0],
      { 0.0, 213.17660522460938, -98.34188842773438 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_hd_gfxdata[2],
      { 66.38373565673828, 98.26638793945312, 33.040077209472656 },
      { 0.6482020020484924, 0.009318999946117401, -0.8015779852867126 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_hd_gfxdata[4],
      { 92.92838287353516, 2.8384690284729004, -4.012178897857666 },
      { 0.6184830069541931, 0.14751100540161133, 0.15039999783039093 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_hd_gfxdata[6],
      { -66.38373565673828, 98.26638793945312, 33.040077209472656 },
      { -0.6482020020484924, 3.1322739124298096, 0.8015779852867126 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_hd_gfxdata[8],
      { 92.92838287353516, 2.8384690284729004, 4.012178897857666 },
      { 2.5231099128723145, -2.9940810203552246, -2.991192102432251 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_hd_gfxdata[10],
      { 0.0, 160.51719665527344, 44.111610412597656 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_hd_gfxdata[12],
      { 1.700000029813964e-05, -6.167579174041748, -59.011138916015625 },
      { -0.11999999731779099, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_hd_gfxdata[14],
      { 69.44670104980469, -83.53793334960938, -14.114421844482422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_hd_gfxdata[16],
      { 32.59682083129883, -72.57569122314453, 49.05435562133789 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_hd_gfxdata[18],
      { -69.44670104980469, -83.53793334960938, -14.114421844482422 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_hd_gfxdata[20],
      { 32.5968132019043, -72.57569122314453, -49.054359436035156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charmander_hd_gfxdata[22],
      { -1.0431950092315674, -118.13738250732422, -89.087158203125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charmander_hd_gfxdata[24],
      { 0.0, -28.175527572631836, -149.53558349609375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32772,
      &charmander_hd_gfxdata[26],
      { 1.0431950092315674, 167.42236328125, -113.64752960205078 },
      { -1.5707950592041016, 1.570796012878418, -1.5707950592041016 },
      { 0.23999999463558197, 0.23999999463558197, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
