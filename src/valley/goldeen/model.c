#include "common.h"

extern u8 goldeen_tex_801750C0[];
extern u8 goldeen_tex_801756D0[];
extern u8 goldeen_tex_80175AD8[];
extern u8 goldeen_tex_80175CE0[];
extern u8 goldeen_tex_801760E8[];
extern u8 goldeen_tex_801760F8_png[];
extern u8 goldeen_tex_80176300[];
extern u8 goldeen_tex_80176338_png[];
extern u8 goldeen_tex_80176B40[];
extern u8 goldeen_tex_80176CC8_png[];
extern u8 goldeen_tex_801774D0[];
extern u8 goldeen_tex_801775C8_png[];
extern u8 goldeen_tex_801777D0[];
extern u8 goldeen_tex_801779A8_png[];
extern u8 goldeen_tex_801781B0[];
extern u8 goldeen_tex_80178228_png[];
extern u8 goldeen_tex_80178A30[];
extern u8 goldeen_tex_80179A38[];
extern u8 goldeen_tex_80179A48_png[];

extern Texture* goldeen_part1_mat[];
extern Gfx goldeen_part0_draw[];

Texture** goldeen_materials[] = {
    NULL,
    goldeen_part1_mat,
    NULL,
    NULL,
    NULL,
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

u8* goldeen_part1_mat0_textures[] = {
    goldeen_tex_80175CE0,
    goldeen_tex_801750C0,
    goldeen_tex_801756D0,
};

u8* goldeen_part1_mat1_textures[] = {
    goldeen_tex_80175CE0,
    goldeen_tex_801750C0,
    goldeen_tex_801756D0,
};

Texture goldeen_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    goldeen_part1_mat0_textures,
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
    { 255, 254, 254, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 254, 254, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture goldeen_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    goldeen_part1_mat1_textures,
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
    { 255, 254, 254, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 254, 254, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* goldeen_part1_mat[] = {
    &goldeen_part1_mat0,
    &goldeen_part1_mat1,
    NULL,
    NULL,
};

#include "assets/valley/goldeen/model.vtx.inc.c"
#include "assets/valley/goldeen/first.gfx.inc.c"
#include "assets/valley/goldeen/part0_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part0_draw.gfx.inc.c"
#include "assets/valley/goldeen/part1_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part1_draw.gfx.inc.c"
#include "assets/valley/goldeen/part2_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part2_draw.gfx.inc.c"
#include "assets/valley/goldeen/part3_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part3_draw.gfx.inc.c"
#include "assets/valley/goldeen/part4_pre_near.gfx.inc.c"
#include "assets/valley/goldeen/part4_pre.gfx.inc.c"
#include "assets/valley/goldeen/part4_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part4_draw.gfx.inc.c"
#include "assets/valley/goldeen/part5_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part5_draw.gfx.inc.c"
#include "assets/valley/goldeen/part6_pre_near.gfx.inc.c"
#include "assets/valley/goldeen/part6_pre.gfx.inc.c"
#include "assets/valley/goldeen/part6_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part6_draw.gfx.inc.c"
#include "assets/valley/goldeen/part7_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part7_draw.gfx.inc.c"
#include "assets/valley/goldeen/part8_pre_near.gfx.inc.c"
#include "assets/valley/goldeen/part8_pre.gfx.inc.c"
#include "assets/valley/goldeen/part8_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part8_draw.gfx.inc.c"
#include "assets/valley/goldeen/part9_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part9_draw.gfx.inc.c"
#include "assets/valley/goldeen/part10_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part10_draw.gfx.inc.c"
#include "assets/valley/goldeen/part11_draw_near.gfx.inc.c"
#include "assets/valley/goldeen/part11_draw.gfx.inc.c"
#include "assets/valley/goldeen/last.gfx.inc.c"

DObjPayloadTypeI goldeen_gfxdata[] = {
    { NULL, goldeen_first },
    { NULL, goldeen_part1_draw },
    { NULL, goldeen_part2_draw },
    { NULL, goldeen_part3_draw },
    { goldeen_part4_pre, goldeen_part4_draw },
    { NULL, goldeen_part5_draw },
    { goldeen_part6_pre, goldeen_part6_draw },
    { NULL, goldeen_part7_draw },
    { goldeen_part8_pre, goldeen_part8_draw },
    { NULL, goldeen_part9_draw },
    { NULL, goldeen_part10_draw },
    { NULL, goldeen_last },
};

UnkEC64Arg3 goldeen_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &goldeen_gfxdata[0],
      { 0.016534000635147095, 32.4022216796875, 64.663330078125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &goldeen_gfxdata[1],
      { -3.999999989900971e-06, -34.27702331542969, -50.81420135498047 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &goldeen_gfxdata[2],
      { 0.0, 4.167295932769775, -80.84548950195312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &goldeen_gfxdata[3],
      { -0.01653200015425682, 22.09014320373535, -65.6136474609375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &goldeen_gfxdata[4],
      { 64.9417953491211, 24.487049102783203, -42.9142951965332 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &goldeen_gfxdata[5],
      { 107.01005554199219, 17.12641143798828, -39.41822052001953 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &goldeen_gfxdata[6],
      { 0.0, 76.70423126220703, -57.23402404785156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &goldeen_gfxdata[7],
      { -4.999999873689376e-06, 85.97408294677734, -154.43504333496094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &goldeen_gfxdata[8],
      { -64.9417953491211, 24.487049102783203, -42.9142951965332 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &goldeen_gfxdata[9],
      { 107.01005554199219, 17.12641143798828, 39.41822052001953 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &goldeen_gfxdata[10],
      { 91.77922058105469, 1.727977991104126, -13.012833595275879 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &goldeen_gfxdata[11],
      { -93.98472595214844, 3.6027719974517822, -16.423694610595703 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { -0.016534000635147095, -32.4022216796875, -64.663330078125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
