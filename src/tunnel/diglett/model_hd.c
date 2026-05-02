#include "common.h"

extern u8 diglett_tex_right_eye_frame0_png[];
extern u8 diglett_tex_right_eye_frame1_png[];
extern u8 diglett_tex_left_eye_frame1_png[];
extern u8 diglett_tex_left_eye_frame0_png[];
extern u8 diglett_tex_body_pal[];
extern u8 diglett_tex_body_png[];
extern u8 diglett_tex_head_pal[];
extern u8 diglett_tex_head_png[];
extern u8 diglett_tex_left_eye_frame0_pal[];
extern u8 diglett_tex_nose_pal[];
extern u8 diglett_tex_nose_png[];
extern u8 diglett_tex_right_eye_frame0_pal[];
extern u8 diglett_tex_soil_pal[];
extern u8 diglett_tex_soil_png[];

extern u8 D_80191498_tunnel_extra[];
extern u8 D_801914C8_tunnel_extra[];
extern u8 D_801914D8_tunnel_extra[];
extern u8 D_801914F8_tunnel_extra[];
extern u8 D_80191508_tunnel_extra[];
extern u8 D_80191558_tunnel_extra[];
extern u8 D_80191578_tunnel_extra[];
extern u8 D_80191598_tunnel_extra[];
extern u8 D_801915B8_tunnel_extra[];
extern u8 D_801915D8_tunnel_extra[];
extern u8 D_801915E8_tunnel_extra[];
extern u8 D_801915F8_tunnel_extra[];
extern u8 D_80191648_tunnel_extra[];
extern u8 D_80191668_tunnel_extra[];
extern u8 D_80191678_tunnel_extra[];
extern u8 D_80191698_tunnel_extra[];
extern u8 D_80191728_tunnel_extra[];
extern u8 D_80191768_tunnel_extra[];
extern u8 D_80191778_tunnel_extra[];
extern u8 D_801917A8_tunnel_extra[];
extern u8 D_801917B8_tunnel_extra[];
extern u8 D_801917D8_tunnel_extra[];
extern u8 D_801917F8_tunnel_extra[];
extern u8 D_80191808_tunnel_extra[];
extern u8 D_80191848_tunnel_extra[];
extern u8 D_80191888_tunnel_extra[];
extern u8 D_801918E8_tunnel_extra[];
extern u8 D_80191968_tunnel_extra[];
extern u8 D_801919E8_tunnel_extra[];
extern u8 D_80191A68_tunnel_extra[];
extern u8 D_80191B68_tunnel_extra[];
extern u8 D_80191BD8_tunnel_extra[];
extern u8 D_80191C48_tunnel_extra[];
extern u8 D_80191D58_tunnel_extra[];
extern u8 D_80191EA8_tunnel_extra[];
extern u8 D_80192028_tunnel_extra[];
extern u8 D_80192038_tunnel_extra[];
extern u8 D_80192048_tunnel_extra[];
extern u8 D_80192058_tunnel_extra[];
extern u8 D_80192258_tunnel_extra[];
extern u8 D_80192278_tunnel_extra[];
extern u8 D_80192298_tunnel_extra[];
extern u8 D_80192318_tunnel_extra[];
extern u8 D_80192518_tunnel_extra[];
extern u8 D_80192528_tunnel_extra[];
extern u8 D_80192538_tunnel_extra[];
extern u8 D_80192558_tunnel_extra[];
extern u8 D_801925D8_tunnel_extra[];
extern u8 D_801925F8_tunnel_extra[];
extern u8 D_80192618_tunnel_extra[];
extern u8 D_80192818_tunnel_extra[];
extern u8 D_80192828_tunnel_extra[];
extern u8 D_80192958_tunnel_extra[];
extern u8 D_80192B38_tunnel_extra[];
extern u8 D_80192D18_tunnel_extra[];
extern u8 D_80192F28_tunnel_extra[];

extern Texture* diglett_hd_part5_mat[];
extern Gfx diglett_hd_part0_draw[];

Texture** diglett_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    diglett_hd_part5_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* diglett_hd_part5_mat0_textures[] = {
    diglett_tex_right_eye_frame0_png,
    diglett_tex_right_eye_frame1_png,
};

u8* diglett_hd_part5_mat1_textures[] = {
    diglett_tex_left_eye_frame0_png,
    diglett_tex_left_eye_frame1_png,
    NULL,
};

Texture diglett_hd_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    diglett_hd_part5_mat0_textures,
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

Texture diglett_hd_part5_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    diglett_hd_part5_mat1_textures,
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

Texture* diglett_hd_part5_mat[] = {
    &diglett_hd_part5_mat0,
    &diglett_hd_part5_mat1,
    NULL,
    NULL,
};
#include "assets/tunnel/diglett/hd_model.vtx.inc.c"
#include "assets/tunnel/diglett/hd_first.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part0_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part1_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part2_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part3_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part4_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part5_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part6_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part7_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part8_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part9_draw.gfx.inc.c"
#include "assets/tunnel/diglett/hd_part10_draw.gfx.inc.c"

UnkEC64Arg3 diglett_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      diglett_hd_first,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      diglett_hd_part1_draw,
      { 0.0, -0.16425999999046326, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      diglett_hd_part2_draw,
      { 0.0, 0.000598000013269484, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      diglett_hd_part3_draw,
      { 0.0, 62.174095153808594, -3.000000106112566e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      diglett_hd_part4_draw,
      { 0.0, 31.19747543334961, 3.000000106112566e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      NULL,
      { 0.0, 126.79209899902344, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      diglett_hd_part5_draw,
      { 0.0, -9.999999974752427e-07, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      diglett_hd_part6_draw,
      { 0.0, -9.999999974752427e-07, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      diglett_hd_part7_draw,
      { 0.0, -9.999999974752427e-07, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      diglett_hd_part8_draw,
      { 0.0, 0.0, -1.0000009536743164 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      diglett_hd_part9_draw,
      { 0.0, 0.0, -1.0000009536743164 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 1,
      diglett_hd_part10_draw,
      { 0.0, 0.0, -0.9999989867210388 },
      { 0.0, 0.0, 0.0 },
      { 0.009999999776482582, 0.009999999776482582, 0.009999999776482582 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
