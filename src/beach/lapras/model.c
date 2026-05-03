#include "common.h"

extern u8 lapras_tex_80182518[];
extern u8 lapras_tex_80182540_png[];
extern u8 lapras_tex_80182748[];
extern u8 lapras_tex_80182770_png[];
extern u8 lapras_tex_80182978[];
extern u8 lapras_tex_801829A0_png[];
extern u8 lapras_tex_80182BA8[];
extern u8 lapras_tex_80182BD0_png[];
extern u8 lapras_tex_80182DD8[];
extern u8 lapras_tex_80182E00[];
extern u8 lapras_tex_80183030[];
extern u8 lapras_tex_80183260[];
extern u8 lapras_tex_80183468[];
extern u8 lapras_tex_80183490_png[];
extern u8 lapras_tex_80183698[];
extern u8 lapras_tex_801836C0_png[];
extern u8 lapras_tex_801838C8[];
extern u8 lapras_tex_801838F0_png[];
extern u8 lapras_tex_80183AF8[];
extern u8 lapras_tex_80183B20_png[];

Texture* lapras_part6_mat[];

extern Gfx lapras_part0_draw[];

Texture** lapras_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    lapras_part6_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* lapras_part6_mat0_textures[] = {
    lapras_tex_80182E00,
    lapras_tex_80183030,
    lapras_tex_80183260,
};

Texture lapras_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    lapras_part6_mat0_textures,
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

Texture* lapras_part6_mat[] = {
    &lapras_part6_mat0,
    NULL,
};

#include "assets/beach/lapras/model.vtx.inc.c"
#include "assets/beach/lapras/first.gfx.inc.c"
#include "assets/beach/lapras/part0_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part0_draw.gfx.inc.c"
#include "assets/beach/lapras/part1_pre_near.gfx.inc.c"
#include "assets/beach/lapras/part1_pre.gfx.inc.c"
#include "assets/beach/lapras/part1_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part1_draw.gfx.inc.c"
#include "assets/beach/lapras/part2_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part2_draw.gfx.inc.c"
#include "assets/beach/lapras/part3_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part3_draw.gfx.inc.c"
#include "assets/beach/lapras/part4_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part4_draw.gfx.inc.c"
#include "assets/beach/lapras/part5_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part5_draw.gfx.inc.c"
#include "assets/beach/lapras/part6_pre_near.gfx.inc.c"
#include "assets/beach/lapras/part6_pre.gfx.inc.c"
#include "assets/beach/lapras/part6_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part6_draw.gfx.inc.c"
#include "assets/beach/lapras/part7_pre_near.gfx.inc.c"
#include "assets/beach/lapras/part7_pre.gfx.inc.c"
#include "assets/beach/lapras/part7_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part7_draw.gfx.inc.c"
#include "assets/beach/lapras/part8_pre_near.gfx.inc.c"
#include "assets/beach/lapras/part8_pre.gfx.inc.c"
#include "assets/beach/lapras/part8_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part8_draw.gfx.inc.c"
#include "assets/beach/lapras/part9_pre_near.gfx.inc.c"
#include "assets/beach/lapras/part9_pre.gfx.inc.c"
#include "assets/beach/lapras/part9_draw_near.gfx.inc.c"
#include "assets/beach/lapras/part9_draw.gfx.inc.c"
#include "assets/beach/lapras/last.gfx.inc.c"

DObjPayloadTypeI lapras_gfxdata[] = {
    { NULL, lapras_first },
    { lapras_part1_pre, lapras_part1_draw },
    { NULL, lapras_part2_draw },
    { NULL, lapras_part3_draw },
    { NULL, lapras_part4_draw },
    { NULL, lapras_part5_draw },
    { lapras_part6_pre, lapras_part6_draw },
    { lapras_part7_pre, lapras_part7_draw },
    { lapras_part8_pre, lapras_part8_draw },
    { lapras_part9_pre, lapras_last },
};

UnkEC64Arg3 lapras_model[] = {
    { 0,
      NULL,
      { 0.0, -1200.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &lapras_gfxdata[0],
      { 0.0, 0.0, -246.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &lapras_gfxdata[1],
      { 0.0, 86.3300552368164, 395.981201171875 },
      { 0.25200000405311584, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &lapras_gfxdata[2],
      { 0.0, 113.85841369628906, 452.3713684082031 },
      { 0.30399999022483826, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &lapras_gfxdata[3],
      { 0.0, 514.5902709960938, -24.73883628845215 },
      { 0.3880000114440918, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &lapras_gfxdata[4],
      { 0.0, 296.4652099609375, 87.48635864257812 },
      { 0.23999999463558197, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &lapras_gfxdata[5],
      { 1.9999999949504854e-06, 467.7742004394531, 108.8674545288086 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &lapras_gfxdata[6],
      { 180.0, 307.31317138671875, -113.4481430053711 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &lapras_gfxdata[7],
      { 0.0, -105.68466186523438, 178.54161071777344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &lapras_gfxdata[8],
      { -180.0, 307.31317138671875, -113.4481430053711 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &lapras_gfxdata[9],
      { 0.0, -220.27960205078125, -894.485107421875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
