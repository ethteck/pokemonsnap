#include "common.h"

extern u8 snorlax_tex_80179A20_png[];
extern u8 snorlax_tex_80179C50_png[];
extern u8 snorlax_tex_8017A080[];
extern u8 snorlax_tex_8017A288[];
extern u8 snorlax_tex_8017A490[];
extern u8 snorlax_tex_8017A698[];
extern u8 snorlax_tex_8017A8A0[];
extern u8 snorlax_tex_8017AAA8[];
extern u8 snorlax_tex_8017ACB0[];
extern u8 snorlax_tex_8017AEE0[];
extern u8 snorlax_tex_8017B0E8[];
extern u8 snorlax_tex_8017B318_png[];
extern u8 snorlax_tex_8017B720_png[];
extern u8 snorlax_tex_8801799F8[];
extern u8 snorlax_tex_880179C28[];
extern u8 snorlax_tex_88017A058[];
extern u8 snorlax_tex_88017AEB8[];
extern u8 snorlax_tex_88017B2F0[];

extern Texture* snorlax_hd_part4_mat[];
extern Texture* snorlax_hd_part5_mat[];
extern Gfx snorlax_hd_part0_draw[];

Texture** snorlax_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    snorlax_hd_part4_mat,
    snorlax_hd_part5_mat,
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

u8* snorlax_hd_part4_mat0_textures[] = {
    snorlax_tex_8017A080,
    snorlax_tex_8017A288,
    snorlax_tex_8017A490,
    snorlax_tex_8017A698,
    snorlax_tex_8017A8A0,
    snorlax_tex_8017AAA8,
    snorlax_tex_8017ACB0,
};

Texture snorlax_hd_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    snorlax_hd_part4_mat0_textures,
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
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

u8* snorlax_hd_part4_mat1_textures[] = {
    snorlax_tex_8017AEE0,
    snorlax_tex_8017B0E8,
};

Texture snorlax_hd_part4_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    snorlax_hd_part4_mat1_textures,
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
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

u8* snorlax_hd_part4_mat2_textures[] = {
    snorlax_tex_8017AEE0,
    snorlax_tex_8017B0E8,
};

Texture snorlax_hd_part4_mat2 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    snorlax_hd_part4_mat2_textures,
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
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture snorlax_hd_part5_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    128,
    32,
    128,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0x20,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
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
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* snorlax_hd_part4_mat[] = {
    &snorlax_hd_part4_mat0,
    &snorlax_hd_part4_mat1,
    &snorlax_hd_part4_mat2,
    NULL,
};

Texture* snorlax_hd_part5_mat[] = {
    &snorlax_hd_part5_mat0,
    NULL,
};
#include "assets/beach/snorlax/hd_model.vtx.inc.c"
#include "assets/beach/snorlax/hd_first.gfx.inc.c"
#include "assets/beach/snorlax/hd_part0_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part1_pre.gfx.inc.c"
#include "assets/beach/snorlax/hd_part1_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part2_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part3_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part5_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part6_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part7_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part8_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part9_pre.gfx.inc.c"
#include "assets/beach/snorlax/hd_part9_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part10_pre.gfx.inc.c"
#include "assets/beach/snorlax/hd_part10_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part11_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part12_pre.gfx.inc.c"
#include "assets/beach/snorlax/hd_part12_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part13_draw.gfx.inc.c"
#include "assets/beach/snorlax/hd_part4_draw.gfx.inc.c"

DObjPayloadTypeJ snorlax_hd_gfxdata[] = {
    { 0, NULL, snorlax_hd_first },
    { 4, NULL, NULL },
    { 0, snorlax_hd_part1_pre, snorlax_hd_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_hd_part2_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_hd_part3_draw },
    { 4, NULL, NULL },
    { 1, NULL, snorlax_hd_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_hd_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_hd_part6_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_hd_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_hd_part8_draw },
    { 4, NULL, NULL },
    { 0, snorlax_hd_part9_pre, snorlax_hd_part9_draw },
    { 4, NULL, NULL },
    { 0, snorlax_hd_part10_pre, snorlax_hd_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_hd_part11_draw },
    { 4, NULL, NULL },
    { 0, snorlax_hd_part12_pre, snorlax_hd_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_hd_part13_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 snorlax_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &snorlax_hd_gfxdata[0],
      { 0.0, 819.5799560546875, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &snorlax_hd_gfxdata[2],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &snorlax_hd_gfxdata[4],
      { 0.0, 374.4200134277344, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &snorlax_hd_gfxdata[6],
      { 0.0, 284.0278625488281, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8197,
      &snorlax_hd_gfxdata[8],
      { 0.0, 1478.02783203125, 1.8999999156221747e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.3253999948501587 } },
    { 4,
      &snorlax_hd_gfxdata[10],
      { 462.7723693847656, 6.000804901123047, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &snorlax_hd_gfxdata[12],
      { 376.8357238769531, 5.576515197753906, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &snorlax_hd_gfxdata[14],
      { -462.7723693847656, 6.000804901123047, 0.0 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &snorlax_hd_gfxdata[16],
      { 376.8357238769531, 5.576515197753906, -5.700000110664405e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &snorlax_hd_gfxdata[18],
      { 0.0, -319.3399963378906, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &snorlax_hd_gfxdata[20],
      { 550.0, -180.2430877685547, -50.0 },
      { 0.0, 0.785398006439209, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &snorlax_hd_gfxdata[22],
      { -0.00023799999326001853, -70.00000762939453, 9.500000305706635e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &snorlax_hd_gfxdata[24],
      { -550.0, -180.2430877685547, -50.0 },
      { 0.0, 2.356194019317627, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &snorlax_hd_gfxdata[26],
      { -0.00023799999326001853, -70.00000762939453, -9.500000305706635e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
