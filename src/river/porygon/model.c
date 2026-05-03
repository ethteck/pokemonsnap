#include "common.h"

extern u8 porygon_tex_80171C50[];
extern u8 porygon_tex_80171E58[];
extern u8 porygon_tex_80172060[];
extern u8 porygon_tex_80172268[];
extern u8 porygon_tex_80172470[];
extern u8 porygon_tex_801726A0[];
extern u8 porygon_tex_801728A8[];
extern u8 porygon_tex_801728D0[];
extern u8 porygon_tex_80172B00[];

extern Texture* porygon_part1_mat[];
extern Texture* porygon_part2_mat[];
extern Texture* porygon_part3_mat[];
extern Texture* porygon_part4_mat[];
extern Texture* porygon_part5_mat[];
extern Texture* porygon_part6_mat[];
extern Texture* porygon_part7_mat[];
extern Texture* porygon_part8_mat[];
extern Texture* porygon_part9_mat[];
extern Gfx porygon_part0_draw[];

Texture** porygon_materials[] = {
    NULL,
    porygon_part1_mat,
    porygon_part2_mat,
    porygon_part3_mat,
    porygon_part4_mat,
    porygon_part5_mat,
    porygon_part6_mat,
    porygon_part7_mat,
    porygon_part8_mat,
    porygon_part9_mat,
};

u8* porygon_part1_mat0_textures[] = {
    porygon_tex_801728D0,
    porygon_tex_801726A0,
    porygon_tex_80172B00,
};

u8* porygon_part1_mat1_textures[] = {
    porygon_tex_801728D0,
    porygon_tex_801726A0,
    porygon_tex_80171C50,
};

u8* porygon_part2_mat0_textures[] = {
    porygon_tex_801728D0,
    porygon_tex_801726A0,
    porygon_tex_80171C50,
};

u8* porygon_part3_mat0_textures[] = {
    porygon_tex_801728D0,
    porygon_tex_801726A0,
    porygon_tex_80171C50,
};

u8* porygon_part4_mat0_textures[] = {
    porygon_tex_801728D0,
    porygon_tex_801726A0,
    porygon_tex_80172B00,
};

u8* porygon_part5_mat0_textures[] = {
    porygon_tex_801728D0,
    porygon_tex_801726A0,
    porygon_tex_80171C50,
};

u8* porygon_part6_mat0_textures[] = {
    porygon_tex_801728D0,
    porygon_tex_801726A0,
    porygon_tex_80171C50,
};

u8* porygon_part7_mat0_textures[] = {
    porygon_tex_80171E58,
    porygon_tex_80172060,
    porygon_tex_80172268,
    porygon_tex_80172470,
};

u8* porygon_part8_mat0_textures[] = {
    porygon_tex_80171E58,
    porygon_tex_80172060,
    porygon_tex_80172268,
    porygon_tex_80172470,
};

u8* porygon_part9_mat0_textures[] = {
    porygon_tex_801728D0,
    porygon_tex_801726A0,
    porygon_tex_80171C50,
};

Texture porygon_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    porygon_part1_mat0_textures,
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

Texture porygon_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    porygon_part1_mat1_textures,
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
    { 255, 255, 254, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 254, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture porygon_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    porygon_part2_mat0_textures,
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

Texture porygon_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    porygon_part3_mat0_textures,
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
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture porygon_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    porygon_part4_mat0_textures,
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

Texture porygon_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    porygon_part5_mat0_textures,
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

Texture porygon_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    porygon_part6_mat0_textures,
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

Texture porygon_part7_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    porygon_part7_mat0_textures,
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
    G_IM_FMT_I,
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

Texture porygon_part8_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    porygon_part8_mat0_textures,
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
    G_IM_FMT_I,
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

Texture porygon_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    porygon_part9_mat0_textures,
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

Texture* porygon_part1_mat[] = {
    &porygon_part1_mat0,
    &porygon_part1_mat1,
    NULL,
};

Texture* porygon_part2_mat[] = {
    &porygon_part2_mat0,
    NULL,
};

Texture* porygon_part3_mat[] = {
    &porygon_part3_mat0,
    NULL,
};

Texture* porygon_part4_mat[] = {
    &porygon_part4_mat0,
    NULL,
};

Texture* porygon_part5_mat[] = {
    &porygon_part5_mat0,
    NULL,
};

Texture* porygon_part6_mat[] = {
    &porygon_part6_mat0,
    NULL,
};

Texture* porygon_part7_mat[] = {
    &porygon_part7_mat0,
    NULL,
};

Texture* porygon_part8_mat[] = {
    &porygon_part8_mat0,
    NULL,
};

Texture* porygon_part9_mat[] = {
    &porygon_part9_mat0,
    NULL,
    NULL,
};

#include "assets/river/porygon/model.vtx.inc.c"
#include "assets/river/porygon/first.gfx.inc.c"
#include "assets/river/porygon/part0_draw_near.gfx.inc.c"
#include "assets/river/porygon/part0_draw.gfx.inc.c"
#include "assets/river/porygon/part1_draw_near.gfx.inc.c"
#include "assets/river/porygon/part1_draw.gfx.inc.c"
#include "assets/river/porygon/part2_draw_near.gfx.inc.c"
#include "assets/river/porygon/part2_draw.gfx.inc.c"
#include "assets/river/porygon/part3_draw_near.gfx.inc.c"
#include "assets/river/porygon/part3_draw.gfx.inc.c"
#include "assets/river/porygon/part4_pre_near.gfx.inc.c"
#include "assets/river/porygon/part4_pre.gfx.inc.c"
#include "assets/river/porygon/part4_draw_near.gfx.inc.c"
#include "assets/river/porygon/part4_draw.gfx.inc.c"
#include "assets/river/porygon/part5_pre_near.gfx.inc.c"
#include "assets/river/porygon/part5_pre.gfx.inc.c"
#include "assets/river/porygon/part5_draw_near.gfx.inc.c"
#include "assets/river/porygon/part5_draw.gfx.inc.c"
#include "assets/river/porygon/part6_draw_near.gfx.inc.c"
#include "assets/river/porygon/part6_draw.gfx.inc.c"
#include "assets/river/porygon/part7_draw_near.gfx.inc.c"
#include "assets/river/porygon/part7_draw.gfx.inc.c"
#include "assets/river/porygon/part8_draw_near.gfx.inc.c"
#include "assets/river/porygon/part8_draw.gfx.inc.c"
#include "assets/river/porygon/last.gfx.inc.c"

DObjPayloadTypeI porygon_gfxdata[] = {
    { NULL, porygon_first },
    { NULL, porygon_part1_draw },
    { NULL, porygon_part2_draw },
    { NULL, porygon_part3_draw },
    { porygon_part4_pre, porygon_part4_draw },
    { porygon_part5_pre, porygon_part5_draw },
    { NULL, porygon_part6_draw },
    { NULL, porygon_part7_draw },
    { NULL, porygon_last },
};

UnkEC64Arg3 porygon_model[] = {
    { 0,
      NULL,
      { 0.0, 100.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &porygon_gfxdata[0],
      { 0.0, 201.00003051757812, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &porygon_gfxdata[1],
      { 300.0, -101.37000274658203, -129.25 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &porygon_gfxdata[2],
      { -300.0, -101.37000274658203, -129.25 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &porygon_gfxdata[3],
      { 0.0, 264.9999694824219, -37.119998931884766 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &porygon_gfxdata[4],
      { 0.0, 5.150032043457031, 380.1499938964844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &porygon_gfxdata[5],
      { 0.0, 5.152130126953125, 380.15350341796875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &porygon_gfxdata[6],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &porygon_gfxdata[7],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &porygon_gfxdata[8],
      { 0.0, -194.42872619628906, -301.7813720703125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
