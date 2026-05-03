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

extern Texture* sandshrew_part6_mat[];

Texture** sandshrew_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sandshrew_part6_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* sandshrew_part6_mat0_textures[] = {
    sandshrew_tex_80161090,
    sandshrew_tex_80161498,
    sandshrew_tex_801618A0,
    sandshrew_tex_80160478,
    sandshrew_tex_80160880,
    sandshrew_tex_80160C88,
    NULL,
};

Texture sandshrew_part6_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    sandshrew_part6_mat0_textures,
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

Texture* sandshrew_part6_mat[] = {
    &sandshrew_part6_mat0,
    NULL,
};

#include "assets/valley/sandshrew/model.vtx.inc.c"
#include "assets/valley/sandshrew/part0_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part0_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part0_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part1_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part1_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part1_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part2_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part2_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part2_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part3_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part3_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part3_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part4_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part4_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part4_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part5_pre_near.gfx.inc.c"
#include "assets/valley/sandshrew/part5_pre_far.gfx.inc.c"
#include "assets/valley/sandshrew/part5_pre.gfx.inc.c"
#include "assets/valley/sandshrew/part5_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part5_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part5_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part6_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part6_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part6_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part7_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part7_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part7_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part8_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part8_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part8_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part9_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part9_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part9_draw.gfx.inc.c"
#include "assets/valley/sandshrew/part10_pre_near.gfx.inc.c"
#include "assets/valley/sandshrew/part10_pre_far.gfx.inc.c"
#include "assets/valley/sandshrew/part10_pre.gfx.inc.c"
#include "assets/valley/sandshrew/part10_draw_near.gfx.inc.c"
#include "assets/valley/sandshrew/part10_draw_far.gfx.inc.c"
#include "assets/valley/sandshrew/part10_draw.gfx.inc.c"
#include "assets/valley/sandshrew/last.gfx.inc.c"

DObjPayloadTypeI sandshrew_gfxdata[] = {
    { NULL, sandshrew_part0_draw },
    { NULL, sandshrew_part1_draw },
    { NULL, sandshrew_part2_draw },
    { NULL, sandshrew_part3_draw },
    { NULL, sandshrew_part4_draw },
    { sandshrew_part5_pre, sandshrew_part5_draw },
    { NULL, sandshrew_part6_draw },
    { NULL, sandshrew_part7_draw },
    { NULL, sandshrew_part8_draw },
    { NULL, sandshrew_part9_draw },
    { sandshrew_part10_pre, sandshrew_last },
};

UnkEC64Arg3 sandshrew_model[] = {
    { 0,
      NULL,
      { -2.4000000848900527e-05, 2.4000000848900527e-05, -5.900000178371556e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &sandshrew_gfxdata[0],
      { 0.0, 200.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandshrew_gfxdata[1],
      { 152.4418182373047, 168.38577270507812, -7.687963008880615 },
      { -0.18303799629211426, -1.004052996635437, -1.3485289812088013 },
      { 1.0000009536743164, 0.9999979734420776, 0.9999989867210388 } },
    { 3,
      &sandshrew_gfxdata[2],
      { 137.3840789794922, 1.2000000424450263e-05, 9.500000305706635e-05 },
      { -0.01040599960833788, 0.23561899363994598, -0.8808979988098145 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 2,
      &sandshrew_gfxdata[3],
      { -152.4418182373047, 168.38577270507812, -7.687934875488281 },
      { 0.18303799629211426, -2.137540102005005, 1.3485289812088013 },
      { 1.0000009536743164, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      &sandshrew_gfxdata[4],
      { 137.38406372070312, 1.2000000424450263e-05, -0.00011899999663000926 },
      { 0.01040400005877018, -0.23561899363994598, -0.8808979988098145 },
      { 0.9999979734420776, 1.0000009536743164, 1.0 } },
    { 2,
      &sandshrew_gfxdata[5],
      { 0.0, 211.40896606445312, 78.99430084228516 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandshrew_gfxdata[6],
      { 127.19998168945312, -1.4842150211334229, 0.5955529808998108 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandshrew_gfxdata[7],
      { 0.29231300950050354, -163.68580627441406, -0.9589570164680481 },
      { 0.007027000188827515, -2.002798080444336, -3.1448450088500977 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 2,
      &sandshrew_gfxdata[8],
      { -127.19995880126953, -1.484226942062378, 0.5955759882926941 },
      { 0.0, -3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandshrew_gfxdata[9],
      { 0.29231300950050354, -163.68580627441406, 0.9589570164680481 },
      { -0.007027000188827515, -4.280386924743652, -3.1448450088500977 },
      { 0.9999989867210388, 0.9999989867210388, 0.9999989867210388 } },
    { 2,
      &sandshrew_gfxdata[10],
      { 0.00010099999781232327, -61.39452362060547, -153.9875030517578 },
      { -1.570788025856018, 1.5330979824066162, -1.570788025856018 },
      { 1.0000009536743164, 1.0, 0.9999989867210388 } },
    { 1,
      NULL,
      { 2.4000000848900527e-05, -2.4000000848900527e-05, 5.900000178371556e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
