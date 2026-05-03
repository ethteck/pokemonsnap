#include "common.h"

extern u8 sandshrew_tex_8015E858[];
extern u8 sandshrew_tex_8015EC60[];
extern u8 sandshrew_tex_8015F468[];
extern u8 sandshrew_tex_8015FC70[];
extern u8 sandshrew_tex_80160478[];
extern u8 sandshrew_tex_80160880[];
extern u8 sandshrew_tex_80160C88[];
extern u8 sandshrew_tex_80161090[];
extern u8 sandshrew_tex_80161498[];
extern u8 sandshrew_tex_801618A0[];
extern u8 sandshrew_tex_80161CA8[];
extern u8 sandshrew_tex_801624B0[];
extern u8 sandshrew_tex_801625B8[];
extern u8 sandshrew_tex_80162640[];
extern u8 sandshrew_tex_801626C8[];
extern u8 sandshrew_tex_801628D0[];
extern u8 sandshrew_tex_801630D8[];

extern Texture* sandshrew_hd_part6_mat[];
extern Gfx sandshrew_hd_part0_draw[];

Texture** sandshrew_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sandshrew_hd_part6_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* sandshrew_hd_part6_mat0_textures[] = {
    sandshrew_tex_80161090,
    sandshrew_tex_80161498,
    sandshrew_tex_801618A0,
    sandshrew_tex_80160478,
    sandshrew_tex_80160880,
    sandshrew_tex_80160C88,
    NULL,
};

Texture sandshrew_hd_part6_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    sandshrew_hd_part6_mat0_textures,
    128,
    64,
    32,
    16,
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
    32,
    16,
    32,
    16,
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

Texture* sandshrew_hd_part6_mat[] = {
    &sandshrew_hd_part6_mat0,
    NULL,
};
#include "assets/valley/sandshrew/hd_model.vtx.inc.c"
#include "assets/valley/sandshrew/hd_part0_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part1_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part2_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part3_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part4_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part5_pre.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part5_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part6_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part7_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part8_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part9_draw.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part10_pre.gfx.inc.c"
#include "assets/valley/sandshrew/hd_part10_draw.gfx.inc.c"

DObjPayloadTypeI sandshrew_hd_gfxdata[] = {
    { NULL, sandshrew_hd_part0_draw },
    { NULL, sandshrew_hd_part1_draw },
    { NULL, sandshrew_hd_part2_draw },
    { NULL, sandshrew_hd_part3_draw },
    { NULL, sandshrew_hd_part4_draw },
    { sandshrew_hd_part5_pre, sandshrew_hd_part5_draw },
    { NULL, sandshrew_hd_part6_draw },
    { NULL, sandshrew_hd_part7_draw },
    { NULL, sandshrew_hd_part8_draw },
    { NULL, sandshrew_hd_part9_draw },
    { sandshrew_hd_part10_pre, sandshrew_hd_part10_draw },
};

UnkEC64Arg3 sandshrew_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &sandshrew_hd_gfxdata[0],
      { 0.0, 200.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandshrew_hd_gfxdata[1],
      { 152.44183349609375, 168.3857879638672, -7.688018798828125 },
      { -0.18303799629211426, -1.004052996635437, -1.3485280275344849 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandshrew_hd_gfxdata[2],
      { 137.3841094970703, 5.999999848427251e-05, 7.200000254670158e-05 },
      { -0.010408000089228153, 0.23561899363994598, -0.8808990120887756 },
      { 0.9999989867210388, 0.9999989867210388, 0.9999989867210388 } },
    { 2,
      &sandshrew_hd_gfxdata[3],
      { -152.44183349609375, 168.3857879638672, -7.688018798828125 },
      { 0.18303799629211426, -2.137540102005005, 1.3485280275344849 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandshrew_hd_gfxdata[4],
      { 137.3841094970703, 5.999999848427251e-05, -7.200000254670158e-05 },
      { 0.010408000089228153, -0.23561899363994598, -0.8808990120887756 },
      { 0.9999989867210388, 0.9999989867210388, 0.9999989867210388 } },
    { 2,
      &sandshrew_hd_gfxdata[5],
      { 0.0, 211.40899658203125, 78.99429321289062 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandshrew_hd_gfxdata[6],
      { 127.19999694824219, -1.4842029809951782, 0.5954999923706055 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandshrew_hd_gfxdata[7],
      { 0.29228898882865906, -163.68580627441406, -0.9589409828186035 },
      { 0.007027999963611364, -2.002798080444336, -3.1448440551757812 },
      { 1.0, 0.9999989867210388, 1.0 } },
    { 2,
      &sandshrew_hd_gfxdata[8],
      { -127.19999694824219, -1.4842029809951782, 0.5954999923706055 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandshrew_hd_gfxdata[9],
      { 0.29228898882865906, -163.68580627441406, 0.9589409828186035 },
      { -0.007027999963611364, 2.002798080444336, -3.1448440551757812 },
      { 1.0, 0.9999989867210388, 1.0 } },
    { 2,
      &sandshrew_hd_gfxdata[10],
      { 9.999999747378752e-05, -61.394500732421875, -153.9875946044922 },
      { -1.5707859992980957, 1.5330979824066162, -1.5707859992980957 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
