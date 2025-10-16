#include "common.h"

extern u8 staryu_tex_8013C928[];
extern u8 staryu_tex_8013C950_png[];
extern u8 staryu_tex_8013CB18[];
extern u8 staryu_tex_8013CD20[];
extern u8 staryu_tex_8013D330[];
extern u8 staryu_tex_8013D940[];

extern Texture* staryu_hd_part3_mat[];
extern Gfx staryu_hd_part0_draw[];

Texture** staryu_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    staryu_hd_part3_mat,
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

u8* staryu_hd_part3_mat0_textures[] = {
    staryu_tex_8013CD20,
    staryu_tex_8013D940,
    staryu_tex_8013D330,
    NULL,
};

Texture staryu_hd_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    staryu_hd_part3_mat0_textures,
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

Texture* staryu_hd_part3_mat[] = {
    &staryu_hd_part3_mat0,
    NULL,
};
#include "assets/valley/staryu/hd_model.vtx.inc.c"
#include "assets/valley/staryu/hd_first.gfx.inc.c"
#include "assets/valley/staryu/hd_part0_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part1_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part2_pre.gfx.inc.c"
#include "assets/valley/staryu/hd_part2_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part3_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part4_pre.gfx.inc.c"
#include "assets/valley/staryu/hd_part4_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part5_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part6_pre.gfx.inc.c"
#include "assets/valley/staryu/hd_part6_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part7_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part8_pre.gfx.inc.c"
#include "assets/valley/staryu/hd_part8_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part9_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part10_pre.gfx.inc.c"
#include "assets/valley/staryu/hd_part10_draw.gfx.inc.c"
#include "assets/valley/staryu/hd_part11_draw.gfx.inc.c"

DObjPayloadTypeI staryu_hd_gfxdata[] = {
    { NULL, staryu_hd_first },
    { NULL, staryu_hd_part1_draw },
    { staryu_hd_part2_pre, staryu_hd_part2_draw },
    { NULL, staryu_hd_part3_draw },
    { staryu_hd_part4_pre, staryu_hd_part4_draw },
    { NULL, staryu_hd_part5_draw },
    { staryu_hd_part6_pre, staryu_hd_part6_draw },
    { NULL, staryu_hd_part7_draw },
    { staryu_hd_part8_pre, staryu_hd_part8_draw },
    { NULL, staryu_hd_part9_draw },
    { staryu_hd_part10_pre, staryu_hd_part10_draw },
    { NULL, staryu_hd_part11_draw },
};

UnkEC64Arg3 staryu_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &staryu_hd_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &staryu_hd_gfxdata[1],
      { 0.0, -35.907005310058594, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &staryu_hd_gfxdata[2],
      { 97.16960144042969, -189.17202758789062, 0.0 },
      { 0.0, 0.0, 0.523527979850769 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_hd_gfxdata[3],
      { -3.034353017807007, -143.1813507080078, 0.0 },
      { 0.0, 0.0, -0.06195100024342537 },
      { 0.9999979734420776, 0.9999979734420776, 1.0 } },
    { 2,
      &staryu_hd_gfxdata[4],
      { 177.31399536132812, 28.104877471923828, 0.0 },
      { 0.0, 0.0, 0.17399999499320984 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_hd_gfxdata[5],
      { 140.1194305419922, -2.5462629795074463, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999989867210388, 1.0 } },
    { 2,
      &staryu_hd_gfxdata[6],
      { -97.16539764404297, -189.19102478027344, 0.0 },
      { 0.0, 0.0, -0.4873790144920349 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_hd_gfxdata[7],
      { -3.8938400745391846, -143.07460021972656, 0.0 },
      { 0.0, 0.0, 0.04682900011539459 },
      { 0.9999949932098389, 0.9999949932098389, 1.0 } },
    { 2,
      &staryu_hd_gfxdata[8],
      { -177.3101043701172, 28.096771240234375, 0.0 },
      { 0.0, 0.0, -0.24400000274181366 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_hd_gfxdata[9],
      { -139.62533569335938, -12.050008773803711, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999970197677612, 0.9999970197677612, 1.0 } },
    { 2,
      &staryu_hd_gfxdata[10],
      { 0.0, 133.5110626220703, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_hd_gfxdata[11],
      { 0.8059269785881042, 163.1389617919922, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
