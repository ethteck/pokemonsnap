#include "common.h"

extern u8 muk_tex_8015C768[];
extern u8 muk_tex_8015D7C0[];
extern u8 muk_tex_8015D7E8[];
extern u8 muk_tex_8015DBF0[];
extern u8 muk_tex_8015DC18[];
extern u8 muk_tex_8015DE20[];
extern u8 muk_tex_8015DE48_png[];

extern Texture* muk_part2_mat[];
extern Texture* muk_part3_mat[];
extern Texture* muk_part4_mat[];
extern Texture* muk_part5_mat[];
extern Texture* muk_part6_mat[];
extern Texture* muk_part7_mat[];
extern Texture* muk_part8_mat[];
extern Texture* muk_part9_mat[];
extern Texture* muk_part10_mat[];
extern Texture* muk_part11_mat[];
extern Texture* muk_part12_mat[];
extern Texture* muk_part13_mat[];
extern Texture* muk_part14_mat[];
extern Texture* muk_part15_mat[];
extern Texture* muk_part16_mat[];
extern Gfx muk_part0_draw[];

__ALIGNER
u8 muk_tex_8031C028[] = {
#include "assets/cave/muk/tex_8031C028.png.bin.c"
};

__ALIGNER
u8 muk_tex_8031C430[] = {
#include "assets/cave/muk/tex_8031C430.png.bin.c"
};

Texture** muk_materials[] = {
    NULL,
    NULL,
    muk_part2_mat,
    muk_part3_mat,
    muk_part4_mat,
    muk_part5_mat,
    muk_part6_mat,
    muk_part7_mat,
    muk_part8_mat,
    muk_part9_mat,
    muk_part10_mat,
    muk_part11_mat,
    muk_part12_mat,
    muk_part13_mat,
    muk_part14_mat,
    muk_part15_mat,
    muk_part16_mat,
};

u8* muk_part2_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part3_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part4_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part5_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part6_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part7_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part8_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part9_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part10_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part11_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part12_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part13_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part14_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part15_mat0_textures[] = {
    muk_tex_8015DC18,
};

u8* muk_part15_mat1_textures[] = {
    muk_tex_8015D7E8,
    muk_tex_8031C028,
    muk_tex_8031C430,
};

u8* muk_part16_mat0_textures[] = {
    muk_tex_8015DC18,
    NULL,
};

Texture muk_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part2_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part3_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part4_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part5_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part6_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part7_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part7_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part8_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part8_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part9_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part10_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part10_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part11_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part11_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part12_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part12_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part13_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part13_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part14_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part14_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part15_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part15_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture muk_part15_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part15_mat1_textures,
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

Texture muk_part16_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    muk_part16_mat0_textures,
    128,
    64,
    128,
    64,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    128,
    64,
    0.0,
    -1.0,
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

Texture* muk_part2_mat[] = {
    &muk_part2_mat0,
    NULL,
};

Texture* muk_part3_mat[] = {
    &muk_part3_mat0,
    NULL,
};

Texture* muk_part4_mat[] = {
    &muk_part4_mat0,
    NULL,
};

Texture* muk_part5_mat[] = {
    &muk_part5_mat0,
    NULL,
};

Texture* muk_part6_mat[] = {
    &muk_part6_mat0,
    NULL,
};

Texture* muk_part7_mat[] = {
    &muk_part7_mat0,
    NULL,
};

Texture* muk_part8_mat[] = {
    &muk_part8_mat0,
    NULL,
};

Texture* muk_part9_mat[] = {
    &muk_part9_mat0,
    NULL,
};

Texture* muk_part10_mat[] = {
    &muk_part10_mat0,
    NULL,
};

Texture* muk_part11_mat[] = {
    &muk_part11_mat0,
    NULL,
};

Texture* muk_part12_mat[] = {
    &muk_part12_mat0,
    NULL,
};

Texture* muk_part13_mat[] = {
    &muk_part13_mat0,
    NULL,
};

Texture* muk_part14_mat[] = {
    &muk_part14_mat0,
    NULL,
};

Texture* muk_part15_mat[] = {
    &muk_part15_mat0,
    &muk_part15_mat1,
    NULL,
};

Texture* muk_part16_mat[] = {
    &muk_part16_mat0,
    NULL,
    NULL,
};

#include "assets/cave/muk/model.vtx.inc.c"
#include "assets/cave/muk/first.gfx.inc.c"
#include "assets/cave/muk/part0_draw_near.gfx.inc.c"
#include "assets/cave/muk/part0_draw_far.gfx.inc.c"
#include "assets/cave/muk/part0_draw.gfx.inc.c"
#include "assets/cave/muk/part1_draw_near.gfx.inc.c"
#include "assets/cave/muk/part1_draw_far.gfx.inc.c"
#include "assets/cave/muk/part1_draw.gfx.inc.c"
#include "assets/cave/muk/part2_pre_near.gfx.inc.c"
#include "assets/cave/muk/part2_pre_far.gfx.inc.c"
#include "assets/cave/muk/part2_pre.gfx.inc.c"
#include "assets/cave/muk/part2_draw_near.gfx.inc.c"
#include "assets/cave/muk/part2_draw_far.gfx.inc.c"
#include "assets/cave/muk/part2_draw.gfx.inc.c"
#include "assets/cave/muk/part3_pre_near.gfx.inc.c"
#include "assets/cave/muk/part3_pre_far.gfx.inc.c"
#include "assets/cave/muk/part3_pre.gfx.inc.c"
#include "assets/cave/muk/part3_draw_near.gfx.inc.c"
#include "assets/cave/muk/part3_draw_far.gfx.inc.c"
#include "assets/cave/muk/part3_draw.gfx.inc.c"
#include "assets/cave/muk/part4_pre_near.gfx.inc.c"
#include "assets/cave/muk/part4_pre_far.gfx.inc.c"
#include "assets/cave/muk/part4_pre.gfx.inc.c"
#include "assets/cave/muk/part4_draw_near.gfx.inc.c"
#include "assets/cave/muk/part4_draw_far.gfx.inc.c"
#include "assets/cave/muk/part4_draw.gfx.inc.c"
#include "assets/cave/muk/part5_pre_near.gfx.inc.c"
#include "assets/cave/muk/part5_pre_far.gfx.inc.c"
#include "assets/cave/muk/part5_pre.gfx.inc.c"
#include "assets/cave/muk/part5_draw_near.gfx.inc.c"
#include "assets/cave/muk/part5_draw_far.gfx.inc.c"
#include "assets/cave/muk/part5_draw.gfx.inc.c"
#include "assets/cave/muk/part6_draw_near.gfx.inc.c"
#include "assets/cave/muk/part6_draw_far.gfx.inc.c"
#include "assets/cave/muk/part6_draw.gfx.inc.c"
#include "assets/cave/muk/part7_draw_near.gfx.inc.c"
#include "assets/cave/muk/part7_draw_far.gfx.inc.c"
#include "assets/cave/muk/part7_draw.gfx.inc.c"
#include "assets/cave/muk/part8_draw_near.gfx.inc.c"
#include "assets/cave/muk/part8_draw_far.gfx.inc.c"
#include "assets/cave/muk/part8_draw.gfx.inc.c"
#include "assets/cave/muk/part9_draw_near.gfx.inc.c"
#include "assets/cave/muk/part9_draw_far.gfx.inc.c"
#include "assets/cave/muk/part9_draw.gfx.inc.c"
#include "assets/cave/muk/part10_pre_near.gfx.inc.c"
#include "assets/cave/muk/part10_pre_far.gfx.inc.c"
#include "assets/cave/muk/part10_pre.gfx.inc.c"
#include "assets/cave/muk/part10_draw_near.gfx.inc.c"
#include "assets/cave/muk/part10_draw_far.gfx.inc.c"
#include "assets/cave/muk/part10_draw.gfx.inc.c"
#include "assets/cave/muk/part11_draw_near.gfx.inc.c"
#include "assets/cave/muk/part11_draw_far.gfx.inc.c"
#include "assets/cave/muk/part11_draw.gfx.inc.c"
#include "assets/cave/muk/part12_draw_near.gfx.inc.c"
#include "assets/cave/muk/part12_draw_far.gfx.inc.c"
#include "assets/cave/muk/part12_draw.gfx.inc.c"
#include "assets/cave/muk/part13_draw_near.gfx.inc.c"
#include "assets/cave/muk/part13_draw_far.gfx.inc.c"
#include "assets/cave/muk/part13_draw.gfx.inc.c"
#include "assets/cave/muk/part14_pre_near.gfx.inc.c"
#include "assets/cave/muk/part14_pre_far.gfx.inc.c"
#include "assets/cave/muk/part14_pre.gfx.inc.c"
#include "assets/cave/muk/part14_draw_near.gfx.inc.c"
#include "assets/cave/muk/part14_draw_far.gfx.inc.c"
#include "assets/cave/muk/part14_draw.gfx.inc.c"
#include "assets/cave/muk/part15_draw_near.gfx.inc.c"
#include "assets/cave/muk/part15_draw_far.gfx.inc.c"
#include "assets/cave/muk/part15_draw.gfx.inc.c"
#include "assets/cave/muk/last.gfx.inc.c"

DObjPayloadTypeI muk_gfxdata[] = {
    { NULL, muk_first },
    { NULL, muk_part1_draw },
    { muk_part2_pre, muk_part2_draw },
    { muk_part3_pre, muk_part3_draw },
    { muk_part4_pre, muk_part4_draw },
    { muk_part5_pre, muk_part5_draw },
    { NULL, muk_part6_draw },
    { NULL, muk_part7_draw },
    { NULL, muk_part8_draw },
    { NULL, muk_part9_draw },
    { muk_part10_pre, muk_part10_draw },
    { NULL, muk_part11_draw },
    { NULL, muk_part12_draw },
    { NULL, muk_part13_draw },
    { muk_part14_pre, muk_part14_draw },
    { NULL, muk_last },
};

UnkEC64Arg3 muk_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32769,
      &muk_gfxdata[0],
      { 912.8660888671875, 947.6915283203125, 283.7594909667969 },
      { 0.0, 0.0, 0.0 },
      { 9.999999747378752e-06, 9.999999747378752e-06, 9.999999747378752e-06 } },
    { 1,
      &muk_gfxdata[1],
      { 0.0, 0.0, -300.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &muk_gfxdata[2],
      { 0.0, 0.0, -100.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0590150356292725, 1.0, 1.0590150356292725 } },
    { 2,
      &muk_gfxdata[3],
      { 0.0, 400.0, 100.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &muk_gfxdata[4],
      { 0.0, -43.58808898925781, 336.9822082519531 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &muk_gfxdata[5],
      { 1043.51904296875, -0.37820300459861755, -252.81309509277344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &muk_gfxdata[6],
      { 18.738937377929688, 100.37820434570312, 221.88160705566406 },
      { 0.13808299601078033, 0.0, -0.09663700312376022 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &muk_gfxdata[7],
      { 0.0, 249.2998046875, -20.84488868713379 },
      { 0.14416499435901642, 0.0, -0.025306999683380127 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &muk_gfxdata[8],
      { -28.2318115234375, 337.8968811035156, -9.180688858032227 },
      { -0.4320249855518341, 0.0, 0.05021600052714348 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &muk_gfxdata[9],
      { -28.023052215576172, -120.42112731933594, 143.00540161132812 },
      { -0.03278400003910065, -0.16738399863243103, -0.052602000534534454 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &muk_gfxdata[10],
      { -1043.51904296875, 62.52178955078125, -5.553842067718506 },
      { -0.44999998807907104, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &muk_gfxdata[11],
      { 18.738842010498047, 50.10340118408203, -246.1670684814453 },
      { -1.3388010263442993, 0.2815690040588379, 0.08785200119018555 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &muk_gfxdata[12],
      { -2.849102020263672, 136.78363037109375, 62.46135330200195 },
      { -0.3541649878025055, 0.0, -0.025307999923825264 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &muk_gfxdata[13],
      { -32.61585235595703, 322.01214599609375, -6.61773681640625 },
      { 0.282025009393692, 6.258878231048584, 0.43052101135253906 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &muk_gfxdata[14],
      { 0.0, 176.4119110107422, 186.98220825195312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &muk_gfxdata[15],
      { 0.0, 250.0, 0.0 },
      { 0.0, 0.0, 0.005584999918937683 },
      { 0.9999989867210388, 0.9999989867210388, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
