#include <common.h>

extern u8 moltres_tex0_pal[];
extern u8 moltres_tex0_var0_png[];
extern u8 moltres_tex0_var1_png[];
extern u8 moltres_tex0_var2_png[];
extern u8 moltres_tex0_var3_png[];
extern u8 moltres_tex0_var4_png[];
extern u8 moltres_tex0_var5_png[];
extern u8 moltres_tex0_var6_png[];
extern u8 moltres_tex0_var7_png[];
extern u8 moltres_tex2_pal[];
extern u8 moltres_tex2_png[];
extern u8 moltres_tex3_pal[];
extern u8 moltres_tex3_png[];
extern u8 moltres_tex4_pal[];
extern u8 moltres_tex4_var0_png[];
extern u8 moltres_tex4_var1_png[];
extern u8 moltres_tex5_pal[];
extern u8 moltres_tex5_png[];
extern u8 moltres_tex6_pal[];
extern u8 moltres_tex6_png[];
extern u8 moltres_tex7_pal[];
extern u8 moltres_tex7_png[];

extern Texture* moltres_part6_mat[];
extern Texture* moltres_part8_mat[];
extern Texture* moltres_part9_mat[];
extern Texture* moltres_part10_mat[];
extern Texture* moltres_part11_mat[];
extern Texture* moltres_part12_mat[];
extern Texture* moltres_part13_mat[];
extern Texture* moltres_part14_mat[];
extern Texture* moltres_part15_mat[];
extern Texture* moltres_part16_mat[];
extern Gfx moltres_part0_draw[];

Texture** moltres_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    moltres_part6_mat,
    NULL,
    moltres_part8_mat,
    moltres_part9_mat,
    moltres_part10_mat,
    moltres_part11_mat,
    moltres_part12_mat,
    moltres_part13_mat,
    moltres_part14_mat,
    moltres_part15_mat,
    moltres_part16_mat,
    NULL,
    NULL,
    NULL,
};

u8* moltres_part6_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part6_mat1_images[] = {
    moltres_tex4_var0_png,
    moltres_tex4_var1_png,
};

u8* moltres_part8_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part9_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part10_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part11_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part12_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part13_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part14_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part14_mat1_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part15_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part15_mat1_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part16_mat0_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
};

u8* moltres_part16_mat1_images[] = {
    moltres_tex0_var0_png,
    moltres_tex0_var1_png,
    moltres_tex0_var2_png,
    moltres_tex0_var3_png,
    moltres_tex0_var4_png,
    moltres_tex0_var5_png,
    moltres_tex0_var6_png,
    moltres_tex0_var7_png,
    NULL
};


Texture moltres_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part6_mat0_images,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part6_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part6_mat1_images,
    128,
    64,
    64, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64, 32,
    64, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part8_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part8_mat0_images,
    128,
    64,
    160, 32,
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
    160, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part9_mat0_images,
    128,
    64,
    160, 32,
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
    160, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part10_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part10_mat0_images,
    128,
    64,
    160, 32,
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
    160, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part11_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part11_mat0_images,
    128,
    64,
    160, 32,
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
    160, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part12_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part12_mat0_images,
    128,
    64,
    160, 32,
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
    160, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part13_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part13_mat0_images,
    128,
    64,
    160, 32,
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
    160, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part14_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part14_mat0_images,
    128,
    64,
    192, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    192, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part14_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part14_mat1_images,
    128,
    64,
    128, 32,
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
    128, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part15_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part15_mat0_images,
    128,
    64,
    192, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    192, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part15_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part15_mat1_images,
    128,
    64,
    128, 32,
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
    128, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part16_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part16_mat0_images,
    128,
    64,
    192, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    192, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture moltres_part16_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    moltres_part16_mat1_images,
    128,
    64,
    128, 32,
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
    128, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x32323200,
    0,
    0,
    0,
    0,
};

Texture* moltres_part6_mat[] = {
    &moltres_part6_mat0,
    &moltres_part6_mat1,
    NULL,
};

Texture* moltres_part8_mat[] = {
    &moltres_part8_mat0,
    NULL,
};

Texture* moltres_part9_mat[] = {
    &moltres_part9_mat0,
    NULL,
};

Texture* moltres_part10_mat[] = {
    &moltres_part10_mat0,
    NULL,
};

Texture* moltres_part11_mat[] = {
    &moltres_part11_mat0,
    NULL,
};

Texture* moltres_part12_mat[] = {
    &moltres_part12_mat0,
    NULL,
};

Texture* moltres_part13_mat[] = {
    &moltres_part13_mat0,
    NULL,
};

Texture* moltres_part14_mat[] = {
    &moltres_part14_mat0,
    &moltres_part14_mat1,
    NULL,
};

Texture* moltres_part15_mat[] = {
    &moltres_part15_mat0,
    &moltres_part15_mat1,
    NULL,
};

Texture* moltres_part16_mat[] = {
    &moltres_part16_mat0,
    &moltres_part16_mat1,
    NULL,
};

#include "assets/volcano/moltres/model.vtx.inc.c"
#include "assets/volcano/moltres/first.gfx.inc.c"
#include "assets/volcano/moltres/part0_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part0_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part0_draw.gfx.inc.c"
#include "assets/volcano/moltres/part1_pre_near.gfx.inc.c"
#include "assets/volcano/moltres/part1_pre_far.gfx.inc.c"
#include "assets/volcano/moltres/part1_pre.gfx.inc.c"
#include "assets/volcano/moltres/part1_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part1_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part1_draw.gfx.inc.c"
#include "assets/volcano/moltres/part2_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part2_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part2_draw.gfx.inc.c"
#include "assets/volcano/moltres/part3_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part3_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part3_draw.gfx.inc.c"
#include "assets/volcano/moltres/part4_pre_near.gfx.inc.c"
#include "assets/volcano/moltres/part4_pre_far.gfx.inc.c"
#include "assets/volcano/moltres/part4_pre.gfx.inc.c"
#include "assets/volcano/moltres/part4_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part4_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part4_draw.gfx.inc.c"
#include "assets/volcano/moltres/part5_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part5_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part5_draw.gfx.inc.c"
#include "assets/volcano/moltres/part6_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part6_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part6_draw.gfx.inc.c"
#include "assets/volcano/moltres/part7_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part7_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part7_draw.gfx.inc.c"
#include "assets/volcano/moltres/part8_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part8_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part8_draw.gfx.inc.c"
#include "assets/volcano/moltres/part9_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part9_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part9_draw.gfx.inc.c"
#include "assets/volcano/moltres/part10_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part10_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part10_draw.gfx.inc.c"
#include "assets/volcano/moltres/part11_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part11_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part11_draw.gfx.inc.c"
#include "assets/volcano/moltres/part12_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part12_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part12_draw.gfx.inc.c"
#include "assets/volcano/moltres/part13_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part13_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part13_draw.gfx.inc.c"
#include "assets/volcano/moltres/part14_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part14_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part14_draw.gfx.inc.c"
#include "assets/volcano/moltres/part15_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part15_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part15_draw.gfx.inc.c"
#include "assets/volcano/moltres/part16_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part16_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part16_draw.gfx.inc.c"
#include "assets/volcano/moltres/part17_pre_near.gfx.inc.c"
#include "assets/volcano/moltres/part17_pre_far.gfx.inc.c"
#include "assets/volcano/moltres/part17_pre.gfx.inc.c"
#include "assets/volcano/moltres/part17_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part17_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part17_draw.gfx.inc.c"
#include "assets/volcano/moltres/part18_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part18_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part18_draw.gfx.inc.c"
#include "assets/volcano/moltres/part19_draw_near.gfx.inc.c"
#include "assets/volcano/moltres/part19_draw_far.gfx.inc.c"
#include "assets/volcano/moltres/part19_draw.gfx.inc.c"
#include "assets/volcano/moltres/last.gfx.inc.c"

DObjPayloadTypeI moltres_gfxdata[] = {
    { NULL, moltres_first },
    { moltres_part1_pre, moltres_part1_draw },
    { NULL, moltres_part2_draw },
    { NULL, moltres_part3_draw },
    { moltres_part4_pre, moltres_part4_draw },
    { NULL, moltres_part5_draw },
    { NULL, moltres_part6_draw },
    { NULL, moltres_part7_draw },
    { NULL, moltres_part8_draw },
    { NULL, moltres_part9_draw },
    { NULL, moltres_part10_draw },
    { NULL, moltres_part11_draw },
    { NULL, moltres_part12_draw },
    { NULL, moltres_part13_draw },
    { NULL, moltres_part14_draw },
    { NULL, moltres_part15_draw },
    { NULL, moltres_part16_draw },
    { moltres_part17_pre, moltres_part17_draw },
    { NULL, moltres_part18_draw },
    { NULL, moltres_last },
};

UnkEC64Arg3 moltres_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      &moltres_gfxdata[0],
      { 0.0, 40.07395935058594, 67.68778228759766 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &moltres_gfxdata[1],
      { 85.44719696044922, -143.39645385742188, -67.9181900024414 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &moltres_gfxdata[2],
      { 20.050209045410156, -82.9202880859375, -195.12811279296875 },
      { 0.9599999785423279, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &moltres_gfxdata[3],
      { 6.8317060470581055, -316.7787170410156, -13.435393333435059 },
      { 0.15000000596046448, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &moltres_gfxdata[4],
      { -1.2000000424450263e-05, 30.02573013305664, -4.6862359046936035 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &moltres_gfxdata[5],
      { 1.2000000424450263e-05, 102.69036102294922, 391.9020690917969 },
      { -0.27000001072883606, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &moltres_gfxdata[6],
      { -0.15850000083446503, 13.019359588623047, 174.6279754638672 },
      { 0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      &moltres_gfxdata[7],
      { 1.9999999494757503e-05, -73.68474578857422, 279.638427734375 },
      { 0.25, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &moltres_gfxdata[8],
      { 109.76765441894531, 107.9880142211914, 239.9661102294922 },
      { 1.570796012878418, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &moltres_gfxdata[9],
      { 484.4931640625, -94.54905700683594, -211.7694854736328 },
      { -0.4498409926891327, 0.49111300706863403, -0.16409200429916382 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      &moltres_gfxdata[10],
      { 777.4695434570312, 168.34754943847656, -54.22877502441406 },
      { -0.040323998779058456, -0.11225499957799911, 0.19667500257492065 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &moltres_gfxdata[11],
      { -109.76762390136719, 107.9880142211914, 239.9661102294922 },
      { -1.570796012878418, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &moltres_gfxdata[12],
      { 484.4931640625, -94.54896545410156, 211.7694854736328 },
      { 0.4498409926891327, 5.79207181930542, -0.16409100592136383 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      &moltres_gfxdata[13],
      { 777.4696044921875, 168.34732055664062, 54.228878021240234 },
      { -3.101269006729126, -3.2538468837738037, -2.944917917251587 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &moltres_gfxdata[14],
      { 0.0, -87.6506576538086, -256.04510498046875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &moltres_gfxdata[15],
      { 0.0, 40.05759811401367, -416.606201171875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &moltres_gfxdata[16],
      { 0.0, 7.17819881439209, -527.4954833984375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &moltres_gfxdata[17],
      { -85.44719696044922, -143.39645385742188, -67.9181900024414 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &moltres_gfxdata[18],
      { 20.050222396850586, -82.9202880859375, 195.12811279296875 },
      { -0.9599999785423279, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &moltres_gfxdata[19],
      { 6.83169412612915, -316.7787170410156, 13.435393333435059 },
      { -0.15000000596046448, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 }
    },
};
