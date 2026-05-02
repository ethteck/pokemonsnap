#include "common.h"

extern u8 magnemite_tex_screw_frame1_png[];
extern u8 magnemite_tex_screw_frame2_png[];
extern u8 magnemite_tex_screw_frame0_png[];
extern u8 magnemite_tex_body_frame1_png[];
extern u8 magnemite_tex_body_frame2_png[];
extern u8 magnemite_tex_body_frame0_png[];
extern u8 magnemite_tex_eye_frame0_png[];
extern u8 magnemite_tex_eye_frame1_png[];
extern u8 magnemite_tex_eye_frame2_png[];
extern u8 magnemite_tex_magnet_frame1_png[];
extern u8 magnemite_tex_magnet_frame2_png[];
extern u8 magnemite_tex_magnet_frame0_png[];
extern u8 magnemite_tex_screw_thread_frame1_png[];
extern u8 magnemite_tex_screw_thread_frame2_png[];
extern u8 magnemite_tex_screw_thread_frame0_png[];
extern u8 magnemite_tex_body_frame0_pal[];
extern u8 magnemite_tex_eye_frame0_pal[];
extern u8 magnemite_tex_magnet_frame0_pal[];
extern u8 magnemite_tex_screw_frame0_pal[];
extern u8 magnemite_tex_screw_thread_frame0_pal[];
extern u8 magnemite_tex_wave_png[];

extern u8 D_8018EEF8_tunnel_extra[];
extern u8 D_8018EF18_tunnel_extra[];
extern u8 D_8018EF38_tunnel_extra[];
extern u8 D_8018EF48_tunnel_extra[];
extern u8 D_8018EF68_tunnel_extra[];
extern u8 D_8018EF78_tunnel_extra[];
extern u8 D_8018EF88_tunnel_extra[];
extern u8 D_8018EF98_tunnel_extra[];
extern u8 D_8018EFA8_tunnel_extra[];
extern u8 D_8018EFC8_tunnel_extra[];
extern u8 D_8018EFE8_tunnel_extra[];
extern u8 D_8018F008_tunnel_extra[];
extern u8 D_8018F038_tunnel_extra[];
extern u8 D_8018F048_tunnel_extra[];
extern u8 D_8018F098_tunnel_extra[];
extern u8 D_8018F0E8_tunnel_extra[];
extern u8 D_8018F0F8_tunnel_extra[];
extern u8 D_8018F128_tunnel_extra[];
extern u8 D_8018F158_tunnel_extra[];
extern u8 D_8018F188_tunnel_extra[];
extern u8 D_8018F1A8_tunnel_extra[];
extern u8 D_8018F1B8_tunnel_extra[];
extern u8 D_8018F1D8_tunnel_extra[];
extern u8 D_8018F218_tunnel_extra[];
extern u8 D_8018F298_tunnel_extra[];
extern u8 D_8018F398_tunnel_extra[];
extern u8 D_8018F3A8_tunnel_extra[];
extern u8 D_8018F3B8_tunnel_extra[];
extern u8 D_8018F3C8_tunnel_extra[];
extern u8 D_8018F3D8_tunnel_extra[];
extern u8 D_8018F3E8_tunnel_extra[];
extern u8 D_8018F4A8_tunnel_extra[];
extern u8 D_8018F648_tunnel_extra[];
extern u8 D_8018F718_tunnel_extra[];
extern u8 D_8018F918_tunnel_extra[];
extern u8 D_8018FAD8_tunnel_extra[];
extern u8 D_8018FCD8_tunnel_extra[];
extern u8 D_8018FD18_tunnel_extra[];
extern u8 D_8018FF18_tunnel_extra[];
extern u8 D_801900D8_tunnel_extra[];
extern u8 D_801902D8_tunnel_extra[];
extern u8 D_80190318_tunnel_extra[];
extern u8 D_801903E8_tunnel_extra[];
extern u8 D_80190548_tunnel_extra[];
extern u8 D_80190600_tunnel_extra[];

extern Texture* magnemite_hd_part1_mat[];
extern Texture* magnemite_hd_part2_mat[];
extern Texture* magnemite_hd_part3_mat[];
extern Texture* magnemite_hd_part5_mat[];
extern Texture* magnemite_hd_part7_mat[];
extern Texture* magnemite_hd_part8_mat[];
extern Texture* magnemite_hd_part9_mat[];
extern Gfx magnemite_hd_part0_draw[];

__ALIGNER
u8 magnemite_tex_hd_8018E208[] = {
#include "assets/tunnel/magnemite/tex_hd_8018E208.png.bin.c"
};

Texture** magnemite_hd_materials[] = {
    NULL,
    magnemite_hd_part1_mat,
    magnemite_hd_part2_mat,
    magnemite_hd_part3_mat,
    NULL,
    magnemite_hd_part5_mat,
    NULL,
    magnemite_hd_part7_mat,
    magnemite_hd_part8_mat,
    magnemite_hd_part9_mat,
    NULL,
    NULL,
};

u8* magnemite_hd_part1_mat0_textures[] = {
    magnemite_tex_body_frame0_png,
    magnemite_tex_body_frame1_png,
    magnemite_tex_body_frame2_png,
};

u8* magnemite_hd_part2_mat0_textures[] = {
    magnemite_tex_screw_thread_frame0_png,
    magnemite_tex_screw_thread_frame1_png,
    magnemite_tex_screw_thread_frame2_png,
};

u8* magnemite_hd_part2_mat1_textures[] = {
    magnemite_tex_screw_frame0_png,
    magnemite_tex_screw_frame1_png,
    magnemite_tex_screw_frame2_png,
};

u8* magnemite_hd_part3_mat0_textures[] = {
    magnemite_tex_eye_frame0_png,
    magnemite_tex_hd_8018E208,
    magnemite_tex_eye_frame1_png,
    magnemite_tex_eye_frame2_png,
};

u8* magnemite_hd_part5_mat0_textures[] = {
    magnemite_tex_magnet_frame0_png,
    magnemite_tex_magnet_frame1_png,
    magnemite_tex_magnet_frame2_png,
};

u8* magnemite_hd_part7_mat0_textures[] = {
    magnemite_tex_magnet_frame0_png,
    magnemite_tex_magnet_frame1_png,
    magnemite_tex_magnet_frame2_png,
};

u8* magnemite_hd_part8_mat0_textures[] = {
    magnemite_tex_screw_thread_frame0_png,
    magnemite_tex_screw_thread_frame1_png,
    magnemite_tex_screw_thread_frame2_png,
};

u8* magnemite_hd_part8_mat1_textures[] = {
    magnemite_tex_screw_frame0_png,
    magnemite_tex_screw_frame1_png,
    magnemite_tex_screw_frame2_png,
    NULL,
};

Texture magnemite_hd_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_hd_part1_mat0_textures,
    64,
    0,
    128,
    64,
    1,
    0.0,
    0.004999999888241291,
    1.0,
    0.9900000095367432,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    64,
    128,
    64,
    0.0,
    0.004999999888241291,
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

Texture magnemite_hd_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_hd_part2_mat0_textures,
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
    0x1,
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

Texture magnemite_hd_part2_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_hd_part2_mat1_textures,
    32,
    0,
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

Texture magnemite_hd_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_hd_part3_mat0_textures,
    32,
    0,
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

Texture magnemite_hd_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_hd_part5_mat0_textures,
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
    0x1,
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

Texture magnemite_hd_part7_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_hd_part7_mat0_textures,
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
    0x1,
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

Texture magnemite_hd_part8_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_hd_part8_mat0_textures,
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
    0x1,
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

Texture magnemite_hd_part8_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magnemite_hd_part8_mat1_textures,
    32,
    0,
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

Texture magnemite_hd_part9_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    52,
    7,
    32,
    32,
    0,
    0.21628299355506897,
    0.08218000084161758,
    0.6074349880218506,
    0.7236419916152954,
    0.21628299355506897,
    0.6074349880218506,
    NULL,
    0x200,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.21628299355506897,
    0.08218000084161758,
    0.21628299355506897,
    { 0, 0, 0, 0 },
    139781,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 255, 255, 255, 255 },
    { 0, 0, 0, 8 },
    { 96, 255, 96, 0 },
    { 76, 76, 76, 0 },
    0,
    0,
    0,
    0,
};

Texture* magnemite_hd_part1_mat[] = {
    &magnemite_hd_part1_mat0,
    NULL,
};

Texture* magnemite_hd_part2_mat[] = {
    &magnemite_hd_part2_mat0,
    &magnemite_hd_part2_mat1,
    NULL,
};

Texture* magnemite_hd_part3_mat[] = {
    &magnemite_hd_part3_mat0,
    NULL,
};

Texture* magnemite_hd_part5_mat[] = {
    &magnemite_hd_part5_mat0,
    NULL,
};

Texture* magnemite_hd_part7_mat[] = {
    &magnemite_hd_part7_mat0,
    NULL,
};

Texture* magnemite_hd_part8_mat[] = {
    &magnemite_hd_part8_mat0,
    &magnemite_hd_part8_mat1,
    NULL,
};

Texture* magnemite_hd_part9_mat[] = {
    &magnemite_hd_part9_mat0,
    NULL,
};
#include "assets/tunnel/magnemite/hd_model.vtx.inc.c"
#include "assets/tunnel/magnemite/hd_first.gfx.inc.c"
#include "assets/tunnel/magnemite/hd_part0_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/hd_part1_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/hd_part2_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/hd_part3_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/hd_part4_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/hd_part5_draw.gfx.inc.c"
#include "assets/tunnel/magnemite/hd_part6_draw.gfx.inc.c"

DObjPayloadTypeC magnemite_hd_gfxdata[] = {
    { 0, magnemite_hd_first },
    { 4, NULL },
    { 0, magnemite_hd_part1_draw },
    { 4, NULL },
    { 0, magnemite_hd_part2_draw },
    { 4, NULL },
    { 0, magnemite_hd_part3_draw },
    { 4, NULL },
    { 0, magnemite_hd_part4_draw },
    { 4, NULL },
    { 0, magnemite_hd_part5_draw },
    { 4, NULL },
    { 1, magnemite_hd_part6_draw },
    { 4, NULL },
};

UnkEC64Arg3 magnemite_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &magnemite_hd_gfxdata[0],
      { 9.999999974752427e-07, 500.0, -3.099999958067201e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magnemite_hd_gfxdata[2],
      { -9.999999747378752e-06, -74.30977630615234, 96.37507629394531 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magnemite_hd_gfxdata[4],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { -9.999999974752427e-07, 0.0, 3.099999958067201e-05 },
      { 0.0, 0.0, 0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magnemite_hd_gfxdata[6],
      { 131.62266540527344, 0.441769003868103, 0.0 },
      { 0.0, 0.0, 0.520110011100769 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { -9.999999974752427e-07, 0.0, 3.099999958067201e-05 },
      { 0.0, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magnemite_hd_gfxdata[8],
      { -131.6196746826172, -0.8999530076980591, 0.0 },
      { 0.0, 0.0, -2.6179940700531006 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magnemite_hd_gfxdata[10],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &magnemite_hd_gfxdata[12],
      { -3.000000106112566e-06, -0.0001429999974789098, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 700.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { -700.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
