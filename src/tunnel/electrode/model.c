#include <common.h>

extern u8 electrode_tex_bottom_frame0_pal[];
extern u8 electrode_tex_explosion1_png[];
extern u8 electrode_tex_explosion2_code[];
extern u8 electrode_tex_explosion3_png[];
extern u8 electrode_tex_mouth_frame1_pal[];
extern u8 electrode_tex_eyes_frame1_pal[];
extern u8 electrode_tex_bottom_frame0_png[];
extern u8 electore_tex_bright_spot_png[];
extern u8 electrode_tex_mouth_frame0_pal[];
extern u8 electrode_tex_mouth_frame0_png[];
extern u8 electrode_tex_eyebrow_png[];
extern u8 electrode_tex_body1_frame2_png[];
extern u8 electrode_tex_body1_frame1_png[];
extern u8 electrode_tex_body1_frame0_png[];
extern u8 electrode_tex_body2_frame0_png[];
extern u8 electrode_tex_body2_frame2_png[];
extern u8 electrode_tex_body2_frame1_png[];
extern u8 electrode_tex_bottom_frame2_png[];
extern u8 electrode_tex_bottom_frame2_pal[];
extern u8 electrode_tex_bottom_frame1_pal[];
extern u8 electrode_tex_bottom_frame1_png[];
extern u8 electrode_tex_top_frame2_pal[];
extern u8 electrode_tex_top_frame2_png[];
extern u8 electrode_tex_mouth_frame2_pal[];
extern u8 electrode_tex_mouth_frame2_png[];
extern u8 electrode_tex_eyes_frame2_pal[];
extern u8 electrode_tex_eyes_frame2_png[];
extern u8 electrode_tex_mouth_frame1_png[];
extern u8 electrode_tex_eyes_frame0_pal[];
extern u8 electrode_tex_eyes_frame0_png[];
extern u8 electrode_tex_eyes_frame1_png[];
extern u8 electrode_tex_top_frame1_pal[];
extern u8 electrode_tex_top_frame1_png[];
extern u8 electrode_tex_top_frame0_pal[];
extern u8 electrode_tex_top_frame0_png[];

extern Texture* electrode_part1_mat[];
extern Texture* electrode_part2_mat[];
extern Texture* electrode_part3_mat[];
extern Texture* electrode_part5_mat[];
extern Texture* electrode_part6_mat[];
extern Texture* electrode_part7_mat[];
extern Texture* electrode_part8_mat[];
extern Texture* electrode_part9_mat[];
extern Texture* electrode_part11_mat[];
extern Texture* electrode_part12_mat[];
extern Texture* electrode_part16_mat[];

Texture** electrode_materials[] = {
    NULL,
    NULL,
    electrode_part1_mat,
    electrode_part2_mat,
    electrode_part3_mat,
    NULL,
    electrode_part5_mat,
    electrode_part6_mat,
    electrode_part7_mat,
    electrode_part8_mat,
    electrode_part9_mat,
    NULL,
    electrode_part11_mat,
    electrode_part12_mat,
    NULL,
    NULL,
    NULL,
    electrode_part16_mat,
};

u8* electrode_part11_mat0_textures[] = {
    electrode_tex_body1_frame0_png,
    electrode_tex_body1_frame1_png,
    electrode_tex_body1_frame2_png,
    electrode_tex_body1_frame2_png
};

u8* electrode_part11_mat1_textures[] = {
    electrode_tex_eyes_frame0_png,
    electrode_tex_eyes_frame1_png,
    electrode_tex_eyes_frame2_png,
    electrode_tex_eyes_frame2_png
};

u8* electrode_part11_mat1_palettes[] = {
    electrode_tex_eyes_frame0_pal,
    electrode_tex_eyes_frame1_pal,
    electrode_tex_eyes_frame2_pal
};

u8* electrode_part11_mat2_textures[] = {
    electrode_tex_body2_frame0_png,
    electrode_tex_body2_frame1_png,
    electrode_tex_body2_frame2_png,
    electrode_tex_body2_frame2_png
};

u8* electrode_part11_mat3_textures[] = {
    electrode_tex_top_frame0_png,
    electrode_tex_top_frame1_png,
    electrode_tex_top_frame2_png,
    electrode_tex_top_frame2_png
};

u8* electrode_part11_mat3_palettes[] = {
    electrode_tex_top_frame0_pal,
    electrode_tex_top_frame1_pal,
    electrode_tex_top_frame2_pal
};

u8* electrode_part11_mat4_textures[] = {
    electrode_tex_mouth_frame0_png,
    electrode_tex_mouth_frame1_png,
    electrode_tex_mouth_frame2_png,
    electrode_tex_mouth_frame2_png
};

u8* electrode_part11_mat4_palettes[] = {
    electrode_tex_mouth_frame0_pal,
    electrode_tex_mouth_frame1_pal,
    electrode_tex_mouth_frame2_pal
};

u8* electrode_part11_mat5_textures[] = {
    electrode_tex_bottom_frame0_png,
    electrode_tex_bottom_frame1_png,
    electrode_tex_bottom_frame2_png,
    electrode_tex_bottom_frame2_png
};

u8* electrode_part11_mat5_palettes[] = {
    electrode_tex_bottom_frame0_pal,
    electrode_tex_bottom_frame1_pal,
    electrode_tex_bottom_frame2_pal
};

Texture electrode_part1_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 0, 0, 126,
    0,
    0,
    0,
    0,
    54, 0, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part2_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x3200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 185, 255,
    0,
    0,
    0,
    0,
    212, 0, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part3_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 63, 255,
    0,
    0,
    0,
    0,
    150, 0, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part5_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    2, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    2, 32,
    2, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 0, 255,
    0,
    0,
    0,
    0,
    252, 255, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part6_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    2, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    2, 32,
    2, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 0, 255,
    0,
    0,
    0,
    0,
    255, 255, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part7_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    2, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    2, 32,
    2, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 0, 255,
    0,
    0,
    0,
    0,
    255, 254, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part8_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    2, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    2, 32,
    2, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 0, 255,
    0,
    0,
    0,
    0,
    255, 254, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part9_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    2, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    2, 32,
    2, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 0, 255,
    0,
    0,
    0,
    0,
    255, 252, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part11_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    electrode_part11_mat0_textures,
    128,
    64,
    4, 8,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    4, 8,
    4, 8,
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part11_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    electrode_part11_mat1_textures,
    128,
    64,
    64, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    electrode_part11_mat1_palettes,
    0x15,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64, 32,
    64, 32,
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part11_mat2 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    electrode_part11_mat2_textures,
    128,
    64,
    4, 8,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    4, 8,
    4, 8,
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part11_mat3 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    electrode_part11_mat3_textures,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    electrode_part11_mat3_palettes,
    0x15,
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part11_mat4 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    electrode_part11_mat4_textures,
    128,
    64,
    64, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    electrode_part11_mat4_palettes,
    0x15,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64, 32,
    64, 32,
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part11_mat5 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    electrode_part11_mat5_textures,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    electrode_part11_mat5_palettes,
    0x15,
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part12_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    255, 255, 0, 255,
    0, 0, 0, 8,
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture electrode_part16_mat0 = {
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
    { 96, 255, 96, 0 },
    { 76, 76, 76, 0 },
    0,
    0,
    0,
    0,
};

Texture* electrode_part1_mat[] = {
    &electrode_part1_mat0,
    NULL,
};

Texture* electrode_part2_mat[] = {
    &electrode_part2_mat0,
    NULL,
};

Texture* electrode_part3_mat[] = {
    &electrode_part3_mat0,
    NULL,
};

Texture* electrode_part5_mat[] = {
    &electrode_part5_mat0,
    NULL,
};

Texture* electrode_part6_mat[] = {
    &electrode_part6_mat0,
    NULL,
};

Texture* electrode_part7_mat[] = {
    &electrode_part7_mat0,
    NULL,
};

Texture* electrode_part8_mat[] = {
    &electrode_part8_mat0,
    NULL,
};

Texture* electrode_part9_mat[] = {
    &electrode_part9_mat0,
    NULL,
};

Texture* electrode_part11_mat[] = {
    &electrode_part11_mat0,
    &electrode_part11_mat1,
    &electrode_part11_mat2,
    &electrode_part11_mat3,
    &electrode_part11_mat4,
    &electrode_part11_mat5,
    NULL,
};

Texture* electrode_part12_mat[] = {
    &electrode_part12_mat0,
    NULL,
};

Texture* electrode_part16_mat[] = {
    &electrode_part16_mat0,
    NULL,
};

#include "assets/tunnel/electrode/model.vtx.inc.c"
#include "assets/tunnel/electrode/part8_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part8_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part10_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part10_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part11_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part11_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part12_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part12_draw.gfx.inc.c"
#include "assets/tunnel/electrode/last.gfx.inc.c"
#include "assets/tunnel/electrode/part0_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part0_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part1_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part1_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part2_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part2_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part3_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part3_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part4_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part4_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part5_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part5_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part6_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part6_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part7_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part7_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part9_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part9_draw.gfx.inc.c"
#include "assets/tunnel/electrode/part13_draw_near.gfx.inc.c"
#include "assets/tunnel/electrode/part13_draw.gfx.inc.c"

DObjPayloadTypeC electrode_gfxdata[] = {
    { 1, electrode_part0_draw },
    { 4, NULL },
    { 1, electrode_part1_draw },
    { 4, NULL },
    { 1, electrode_part2_draw },
    { 4, NULL },
    { 1, electrode_part3_draw },
    { 4, NULL },
    { 1, electrode_part4_draw },
    { 4, NULL },
    { 1, electrode_part5_draw },
    { 4, NULL },
    { 1, electrode_part6_draw },
    { 4, NULL },
    { 1, electrode_part7_draw },
    { 4, NULL },
    { 0, electrode_part8_draw },
    { 4, NULL },
    { 1, electrode_part9_draw },
    { 4, NULL },
    { 0, electrode_part10_draw },
    { 4, NULL },
    { 0, electrode_part11_draw },
    { 4, NULL },
    { 0, electrode_last },
    { 4, NULL },
    { 1, electrode_part13_draw },
    { 4, NULL },
};

UnkEC64Arg3 electrode_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 584.9125366210938, -76.46989440917969 },
      { -0.12999999523162842, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &electrode_gfxdata[0],
      { 0.0, 0.0, 3.999999989900971e-06 },
      { -0.32600000500679016, 0.0, 0.0 },
      { 1.6546909809112549, 1.6546909809112549, 1.6546909809112549 } },
    { 32770,
      &electrode_gfxdata[2],
      { 0.0, 0.0, 3.999999989900971e-06 },
      { -0.32600000500679016, 0.0, -0.14286600053310394 },
      { 1.2793949842453003, 1.2768570184707642, 1.2768570184707642 } },
    { 32770,
      &electrode_gfxdata[4],
      { 0.0, 0.0, 3.999999989900971e-06 },
      { -0.32600000500679016, 0.0, 0.0 },
      { 1.4193580150604248, 1.4193580150604248, 1.4211599826812744 } },
    { 1,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &electrode_gfxdata[6],
      { 0.0, 0.0, 0.0 },
      { -0.8899999856948853, 0.23000000417232513, 0.3199999928474426 },
      { 50.0, 45.0, 1.0 } },
    { 2,
      &electrode_gfxdata[8],
      { 0.0, 0.0, 0.0 },
      { 0.1899999976158142, 0.15000000596046448, 0.15000000596046448 },
      { 50.0, 28.0, 1.0 } },
    { 2,
      &electrode_gfxdata[10],
      { 0.0, 0.0, 0.0 },
      { 0.3100000023841858, 0.1599999964237213, -0.8299999833106995 },
      { 50.0, 28.0, 1.0 } },
    { 2,
      &electrode_gfxdata[12],
      { 0.0, 0.0, 0.0 },
      { -0.6299999952316284, 1.2200000286102295, -0.8899999856948853 },
      { 100.0, 27.0, 1.0 } },
    { 2,
      &electrode_gfxdata[14],
      { 0.0, 0.0, 0.0 },
      { 0.23000000417232513, -0.3199999928474426, 0.8899999856948853 },
      { 100.0, 30.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &electrode_gfxdata[16],
      { 9.999999974752427e-07, 589.8902587890625, -3.099999958067201e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32771,
      &electrode_gfxdata[18],
      { -5.999999848427251e-05, 161.122314453125, 895.4742431640625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &electrode_gfxdata[20],
      { 39.23773956298828, 166.5072479248047, 615.1376953125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &electrode_gfxdata[22],
      { -39.30617141723633, 166.5069580078125, 615.1376342773438 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &electrode_gfxdata[24],
      { -43.93198013305664, 164.96600341796875, 586.6491088867188 },
      { -0.22588999569416046, 0.009719000197947025, 0.07994800060987473 },
      { 1.0, 1.0, 1.0 } },
    { 32771,
      &electrode_gfxdata[26],
      { -1.2000000424450263e-05, -0.0001429999974789098, -9.999999974752427e-07 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
