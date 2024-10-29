#include <common.h>

extern u8 rapidash_tex_hoof_pal[];
extern u8 rapidash_tex_hoof_png[];
extern u8 rapidash_tex_ear_pal[];
extern u8 rapidash_tex_ear_png[];
extern u8 rapidash_tex_eye_frame0_pal[];
extern u8 rapidash_tex_eye_frame0_png[];
extern u8 rapidash_tex_eye_frame1_png[];
extern u8 rapidash_tex_eye_frame2_png[];
extern u8 rapidash_tex_flame_frame0_pal[];
extern u8 rapidash_tex_flame_frame0_png[];
extern u8 rapidash_tex_flame_frame1_pal[];
extern u8 rapidash_tex_flame_frame1_png[];
extern u8 rapidash_tex_flame_frame2_png[];
extern u8 rapidash_tex_flame_frame3_png[];
extern u8 rapidash_tex_flame_frame4_png[];
extern u8 rapidash_tex_flame_frame5_png[];
extern u8 rapidash_tex_flame_frame6_png[];
extern u8 rapidash_tex_flame_frame7_png[];
extern u8 rapidash_tex_nostril_pal[];
extern u8 rapidash_tex_nostril_png[];
extern u8 rapidash_tex_skin_pal[];
extern u8 rapidash_tex_skin_png[];

extern Texture* rapidash_part0_mat[];
extern Texture* rapidash_part1_mat[];
extern Texture* rapidash_part2_mat[];
extern Texture* rapidash_part3_mat[];
extern Texture* rapidash_part4_mat[];
extern Texture* rapidash_part6_mat[];
extern Texture* rapidash_part10_mat[];
extern Texture* rapidash_part13_mat[];
extern Texture* rapidash_part17_mat[];
extern Texture* rapidash_part19_mat[];
extern Texture* rapidash_part20_mat[];
extern Gfx rapidash_part0_draw[];

Texture** rapidash_materials[] = {
    NULL,
    rapidash_part0_mat,
    rapidash_part1_mat,
    rapidash_part2_mat,
    rapidash_part3_mat,
    rapidash_part4_mat,
    NULL,
    rapidash_part6_mat,
    NULL,
    NULL,
    NULL,
    rapidash_part10_mat,
    NULL,
    NULL,
    rapidash_part13_mat,
    NULL,
    NULL,
    NULL,
    rapidash_part17_mat,
    NULL,
    rapidash_part19_mat,
    rapidash_part20_mat,
};

u8* rapidash_part0_mat0_textures[] = {
    rapidash_tex_flame_frame0_png,
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
};

u8* rapidash_part1_mat0_textures[] = {
    rapidash_tex_flame_frame0_png,
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
};

u8* rapidash_part2_mat0_textures[] = {
    rapidash_tex_eye_frame0_png,
    rapidash_tex_eye_frame1_png,
    rapidash_tex_eye_frame2_png,
};

u8* rapidash_part3_mat0_textures[] = {
    rapidash_tex_flame_frame0_png,
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
};

u8* rapidash_part4_mat0_textures[] = {
    rapidash_tex_flame_frame0_png,
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
};

u8* rapidash_part6_mat0_textures[] = {
    rapidash_tex_flame_frame0_png,
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
};

u8* rapidash_part10_mat0_textures[] = {
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
    rapidash_tex_flame_frame0_png,
};

u8* rapidash_part13_mat0_textures[] = {
    rapidash_tex_flame_frame0_png,
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
};

u8* rapidash_part17_mat0_textures[] = {
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
    rapidash_tex_flame_frame0_png,
};

u8* rapidash_part19_mat0_textures[] = {
    rapidash_tex_flame_frame0_png,
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
};

u8* rapidash_part20_mat0_textures[] = {
    rapidash_tex_flame_frame0_png,
    rapidash_tex_flame_frame1_png,
    rapidash_tex_flame_frame2_png,
    rapidash_tex_flame_frame3_png,
    rapidash_tex_flame_frame4_png,
    rapidash_tex_flame_frame5_png,
    rapidash_tex_flame_frame6_png,
    rapidash_tex_flame_frame7_png,
    NULL,
};

Texture rapidash_part0_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part0_mat0_textures,
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
    32,
    32,
    64,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part1_mat0_textures,
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
    32,
    32,
    64,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part2_mat0_textures,
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
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part3_mat0_textures,
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
    0x1,
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
    8709,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part4_mat0_textures,
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
    0x1,
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
    8709,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part6_mat0_textures,
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
    0x1,
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
    8709,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part10_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part10_mat0_textures,
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
    0x1,
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
    8709,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part13_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part13_mat0_textures,
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
    0x1,
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
    8709,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part17_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part17_mat0_textures,
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
    0x1,
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
    8709,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part19_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part19_mat0_textures,
    128,
    64,
    128,
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
    32,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture rapidash_part20_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    rapidash_part20_mat0_textures,
    128,
    64,
    128,
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
    32,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255,
      255,
      255,
      255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* rapidash_part0_mat[] = {
    &rapidash_part0_mat0,
    NULL,
};

Texture* rapidash_part1_mat[] = {
    &rapidash_part1_mat0,
    NULL,
};

Texture* rapidash_part2_mat[] = {
    &rapidash_part2_mat0,
    NULL,
};

Texture* rapidash_part3_mat[] = {
    &rapidash_part3_mat0,
    NULL,
};

Texture* rapidash_part4_mat[] = {
    &rapidash_part4_mat0,
    NULL,
};

Texture* rapidash_part6_mat[] = {
    &rapidash_part6_mat0,
    NULL,
};

Texture* rapidash_part10_mat[] = {
    &rapidash_part10_mat0,
    NULL,
};

Texture* rapidash_part13_mat[] = {
    &rapidash_part13_mat0,
    NULL,
};

Texture* rapidash_part17_mat[] = {
    &rapidash_part17_mat0,
    NULL,
};

Texture* rapidash_part19_mat[] = {
    &rapidash_part19_mat0,
    NULL,
};

Texture* rapidash_part20_mat[] = {
    &rapidash_part20_mat0,
    NULL,
};

#include "assets/volcano/rapidash/model.vtx.inc.c"
#include "assets/volcano/rapidash/first.gfx.inc.c"
#include "assets/volcano/rapidash/part0_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part0_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part0_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part1_pre_near.gfx.inc.c"
#include "assets/volcano/rapidash/part1_pre.gfx.inc.c"
#include "assets/volcano/rapidash/part1_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part1_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part1_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part2_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part2_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part2_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part3_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part3_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part3_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part4_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part4_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part4_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part5_pre_near.gfx.inc.c"
#include "assets/volcano/rapidash/part5_pre.gfx.inc.c"
#include "assets/volcano/rapidash/part5_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part5_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part5_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part6_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part6_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part6_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part7_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part7_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part7_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part8_pre_near.gfx.inc.c"
#include "assets/volcano/rapidash/part8_pre.gfx.inc.c"
#include "assets/volcano/rapidash/part8_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part8_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part8_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part9_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part9_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part9_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part10_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part10_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part10_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part11_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part11_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part11_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part12_pre_near.gfx.inc.c"
#include "assets/volcano/rapidash/part12_pre.gfx.inc.c"
#include "assets/volcano/rapidash/part12_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part12_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part12_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part13_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part13_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part13_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part14_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part14_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part14_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part15_pre_near.gfx.inc.c"
#include "assets/volcano/rapidash/part15_pre.gfx.inc.c"
#include "assets/volcano/rapidash/part15_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part15_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part15_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part16_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part16_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part16_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part17_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part17_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part17_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part18_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part18_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part18_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part19_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part19_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part19_draw.gfx.inc.c"
#include "assets/volcano/rapidash/part20_draw_near.gfx.inc.c"
#include "assets/volcano/rapidash/part20_draw_far.gfx.inc.c"
#include "assets/volcano/rapidash/part20_draw.gfx.inc.c"
#include "assets/volcano/rapidash/last.gfx.inc.c"

DObjPayloadTypeI rapidash_gfxdata[] = {
    { NULL, rapidash_first },
    { rapidash_part1_pre, rapidash_part1_draw },
    { NULL, rapidash_part2_draw },
    { NULL, rapidash_part3_draw },
    { NULL, rapidash_part4_draw },
    { rapidash_part5_pre, rapidash_part5_draw },
    { NULL, rapidash_part6_draw },
    { NULL, rapidash_part7_draw },
    { rapidash_part8_pre, rapidash_part8_draw },
    { NULL, rapidash_part9_draw },
    { NULL, rapidash_part10_draw },
    { NULL, rapidash_part11_draw },
    { rapidash_part12_pre, rapidash_part12_draw },
    { NULL, rapidash_part13_draw },
    { NULL, rapidash_part14_draw },
    { rapidash_part15_pre, rapidash_part15_draw },
    { NULL, rapidash_part16_draw },
    { NULL, rapidash_part17_draw },
    { NULL, rapidash_part18_draw },
    { NULL, rapidash_part19_draw },
    { NULL, rapidash_last },
};

UnkEC64Arg3 rapidash_model[] = {
    { 0,
      NULL,
      { 0.0, -9.500000305706635e-05, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &rapidash_gfxdata[0],
      { 0.0, 998.4064331054688, -323.7532653808594 },
      { 1.4299999475479126, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &rapidash_gfxdata[1],
      { 0.0, 710.1245727539062, -15.657711029052734 },
      { -0.9064019918441772, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &rapidash_gfxdata[2],
      { 0.0, 405.7889099121094, -113.79773712158203 },
      { 0.30000001192092896, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &rapidash_gfxdata[3],
      { 0.0, 169.9923553466797, -75.58255004882812 },
      { -1.833598017692566, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &rapidash_gfxdata[4],
      { 0.0, 567.833984375, -105.14240264892578 },
      { -0.6499999761581421, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &rapidash_gfxdata[5],
      { 175.0000457763672, 558.2944946289062, 327.6741943359375 },
      { -1.4251019954681396, -0.2591480016708374, -0.03758399933576584 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &rapidash_gfxdata[6],
      { 12.526270866394043, -278.5713195800781, 20.000028610229492 },
      { 0.0, 0.0, 0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &rapidash_gfxdata[7],
      { 3.233181953430176, -338.5957336425781, 22.914291381835938 },
      { -0.32999899983406067, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &rapidash_gfxdata[8],
      { 164.99996948242188, -5.960953235626221, -2.454472064971924 },
      { -1.4299999475479126, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &rapidash_gfxdata[9],
      { -14.999961853027344, -397.4956970214844, -21.64232635498047 },
      { 0.7281320095062256, 0.0, 0.04363299906253815 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &rapidash_gfxdata[10],
      { -9.091341018676758, -271.6986083984375, 8.150768280029297 },
      { 2.299999952316284, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &rapidash_gfxdata[11],
      { -1.1974929571151733, 258.9296875, -4.998445987701416 },
      { -0.4186980128288269, -0.004821000155061483, 0.043081000447273254 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &rapidash_gfxdata[12],
      { -175.0, 558.2944946289062, 327.6741943359375 },
      { -1.4251019954681396, 0.2591480016708374, 0.03758399933576584 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &rapidash_gfxdata[13],
      { -12.526655197143555, -278.570556640625, 20.000028610229492 },
      { 0.0, 0.0, -0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &rapidash_gfxdata[14],
      { -3.2332420349121094, -338.59576416015625, 22.914337158203125 },
      { -0.32999899983406067, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &rapidash_gfxdata[15],
      { -164.99996948242188, -5.960953235626221, -2.454472064971924 },
      { -1.4299999475479126, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &rapidash_gfxdata[16],
      { 14.999961853027344, -396.90032958984375, -21.639705657958984 },
      { 0.7281320095062256, 0.0, -0.04363299906253815 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &rapidash_gfxdata[17],
      { 9.116613388061523, -272.1441650390625, 8.543539047241211 },
      { 2.299999952316284, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &rapidash_gfxdata[18],
      { 1.197553038597107, 258.9307556152344, -4.998970031738281 },
      { -0.4710560142993927, 0.004821000155061483, -0.043081000447273254 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &rapidash_gfxdata[19],
      { 0.0, -117.92118835449219, -133.58802795410156 },
      { -2.6509339809417725, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &rapidash_gfxdata[20],
      { 0.0, 572.4385375976562, -8.258532524108887 },
      { -0.31906598806381226, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
