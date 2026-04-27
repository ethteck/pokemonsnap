#include "common.h"

extern u8 kakuna_tex_80159608[];
extern u8 kakuna_tex_80159630[];
extern u8 kakuna_tex_80159838[];
extern u8 kakuna_tex_80159860[];
extern u8 kakuna_tex_80159A68[];
extern u8 kakuna_tex_80159A78[];
extern u8 kakuna_tex_80159A88[];
extern u8 kakuna_tex_80159C90[];
extern u8 kakuna_tex_80159E98[];
extern u8 kakuna_tex_80159EB0[];
extern u8 kakuna_tex_8015A0B8[];

extern u8 D_80159BE8_tunnel_extra[];
extern u8 D_80159C10_tunnel_extra[];
extern u8 D_80159E18_tunnel_extra[];
extern u8 D_80159E40_tunnel_extra[];
extern u8 D_8015A048_tunnel_extra[];
extern u8 D_8015A058_tunnel_extra[];
extern u8 D_8015A068_tunnel_extra[];
extern u8 D_8015A270_tunnel_extra[];
extern u8 D_8015A478_tunnel_extra[];
extern u8 D_8015A490_tunnel_extra[];
extern u8 D_8018C2D0_tunnel_extra[];
extern u8 D_8018C340_tunnel_extra[];
extern u8 D_8018C3B0_tunnel_extra[];
extern u8 D_8018C530_tunnel_extra[];
extern u8 D_8018C5E0_tunnel_extra[];
extern u8 D_8018C6A0_tunnel_extra[];
extern u8 D_8018C760_tunnel_extra[];
extern u8 D_8018C770_tunnel_extra[];
extern u8 D_8018C8C0_tunnel_extra[];
extern u8 D_8018CA00_tunnel_extra[];
extern u8 D_8018CA10_tunnel_extra[];
extern u8 D_8018CA20_tunnel_extra[];
extern u8 D_8018CA30_tunnel_extra[];
extern u8 D_8018CA50_tunnel_extra[];
extern u8 D_8018CA60_tunnel_extra[];
extern u8 D_8018CA70_tunnel_extra[];
extern u8 D_8018CAA0_tunnel_extra[];
extern u8 D_8018CAC0_tunnel_extra[];
extern u8 D_8018CAD0_tunnel_extra[];
extern u8 D_8018CB00_tunnel_extra[];
extern u8 D_8018CB20_tunnel_extra[];
extern u8 D_8018CB50_tunnel_extra[];
extern u8 D_8018CB60_tunnel_extra[];
extern u8 D_8018CB90_tunnel_extra[];
extern u8 D_8018CBD0_tunnel_extra[];
extern u8 D_8018CBF0_tunnel_extra[];
extern u8 D_8018CC10_tunnel_extra[];
extern u8 D_8018CC30_tunnel_extra[];
extern u8 D_8018CC40_tunnel_extra[];
extern u8 D_8018CC70_tunnel_extra[];
extern u8 D_8018CC80_tunnel_extra[];
extern u8 D_8018CCA0_tunnel_extra[];
extern u8 D_8018CCB0_tunnel_extra[];
extern u8 D_8018CCD0_tunnel_extra[];
extern u8 D_8018CD20_tunnel_extra[];
extern u8 D_8018CD40_tunnel_extra[];
extern u8 D_8018CD50_tunnel_extra[];
extern u8 D_8018CDC0_tunnel_extra[];
extern u8 D_8018CDD0_tunnel_extra[];
extern u8 D_8018CE90_tunnel_extra[];
extern u8 D_8018CEB0_tunnel_extra[];
extern u8 D_8018CFD0_tunnel_extra[];
extern u8 D_8018D030_tunnel_extra[];
extern u8 D_8018D060_tunnel_extra[];
extern u8 D_8018D0B0_tunnel_extra[];
extern u8 D_8018D120_tunnel_extra[];
extern u8 D_8018D140_tunnel_extra[];
extern u8 D_8018D150_tunnel_extra[];
extern u8 D_8018D1A0_tunnel_extra[];
extern u8 D_8018D200_tunnel_extra[];
extern u8 D_8018D210_tunnel_extra[];
extern u8 D_8018D240_tunnel_extra[];
extern u8 D_8018D290_tunnel_extra[];
extern u8 D_8018D370_tunnel_extra[];
extern u8 D_8018D440_tunnel_extra[];
extern u8 D_8018D640_tunnel_extra[];
extern u8 D_8018D670_tunnel_extra[];
extern u8 D_8018D680_tunnel_extra[];
extern u8 D_8018D880_tunnel_extra[];
extern u8 D_8018D890_tunnel_extra[];
extern u8 D_8018D8A0_tunnel_extra[];
extern u8 D_8018D8B0_tunnel_extra[];
extern u8 D_8018D9A8_tunnel_extra[];

extern Texture* kakuna_hd_part1_mat[];
extern Gfx kakuna_hd_part0_draw[];

Texture** kakuna_hd_materials[] = {
    NULL,
    kakuna_hd_part1_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* kakuna_hd_part1_mat0_textures[] = {
    kakuna_tex_8015A0B8,
    NULL,
};

Texture kakuna_hd_part1_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    kakuna_hd_part1_mat0_textures,
    32,
    114,
    4,
    128,
    0,
    0.0,
    0.7728700041770935,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    4,
    128,
    4,
    128,
    0.0,
    0.7728700041770935,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 76, 76, 76, 0 },
    0,
    0,
    0,
    0,
};

Texture* kakuna_hd_part1_mat[] = {
    &kakuna_hd_part1_mat0,
    NULL,
};
#include "assets/tunnel/kakuna/hd_model.vtx.inc.c"
#include "assets/tunnel/kakuna/hd_first.gfx.inc.c"
#include "assets/tunnel/kakuna/hd_part0_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/hd_part1_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/hd_part2_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/hd_part3_draw.gfx.inc.c"
#include "assets/tunnel/kakuna/hd_part4_draw.gfx.inc.c"

UnkEC64Arg3 kakuna_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8193,
      kakuna_hd_first,
      { 0.0, 486.79998779296875, -235.1999969482422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      kakuna_hd_part1_draw,
      { 0.0, 56.199981689453125, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      kakuna_hd_part2_draw,
      { -4.70000013592653e-05, -210.15997314453125, 169.14002990722656 },
      { 0.0, 0.0, 0.0 },
      { 0.9900000095367432, 1.0, 1.0 } },
    { 4,
      kakuna_hd_part3_draw,
      { -3.000000106112566e-06, -79.9999008178711, 35.20009994506836 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      kakuna_hd_part4_draw,
      { 0.0, -170.84402465820312, -20.52519989013672 },
      { -0.9440010190010071, 0.0, 0.0 },
      { 0.9999970197677612, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
