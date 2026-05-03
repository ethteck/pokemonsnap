#include "common.h"

extern u8 staryu_tex_8013C928[];
extern u8 staryu_tex_8013C950_png[];
extern u8 staryu_tex_8013CB18[];
extern u8 staryu_tex_8013CD20[];
extern u8 staryu_tex_8013D330[];
extern u8 staryu_tex_8013D940[];

extern Texture* staryu_part3_mat[];
extern Gfx staryu_part0_draw[];

Texture** staryu_materials[] = {
    NULL,
    NULL,
    NULL,
    staryu_part3_mat,
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

u8* staryu_part3_mat0_textures[] = {
    staryu_tex_8013CD20,
    staryu_tex_8013D940,
    staryu_tex_8013D330,
    NULL,
};

Texture staryu_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    staryu_part3_mat0_textures,
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

Texture* staryu_part3_mat[] = {
    &staryu_part3_mat0,
    NULL,
};

#include "assets/valley/staryu/model.vtx.inc.c"
#include "assets/valley/staryu/first.gfx.inc.c"
#include "assets/valley/staryu/part0_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part0_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part0_draw.gfx.inc.c"
#include "assets/valley/staryu/part1_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part1_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part1_draw.gfx.inc.c"
#include "assets/valley/staryu/part2_pre_near.gfx.inc.c"
#include "assets/valley/staryu/part2_pre_far.gfx.inc.c"
#include "assets/valley/staryu/part2_pre.gfx.inc.c"
#include "assets/valley/staryu/part2_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part2_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part2_draw.gfx.inc.c"
#include "assets/valley/staryu/part3_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part3_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part3_draw.gfx.inc.c"
#include "assets/valley/staryu/part4_pre_near.gfx.inc.c"
#include "assets/valley/staryu/part4_pre_far.gfx.inc.c"
#include "assets/valley/staryu/part4_pre.gfx.inc.c"
#include "assets/valley/staryu/part4_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part4_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part4_draw.gfx.inc.c"
#include "assets/valley/staryu/part5_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part5_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part5_draw.gfx.inc.c"
#include "assets/valley/staryu/part6_pre_near.gfx.inc.c"
#include "assets/valley/staryu/part6_pre_far.gfx.inc.c"
#include "assets/valley/staryu/part6_pre.gfx.inc.c"
#include "assets/valley/staryu/part6_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part6_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part6_draw.gfx.inc.c"
#include "assets/valley/staryu/part7_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part7_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part7_draw.gfx.inc.c"
#include "assets/valley/staryu/part8_pre_near.gfx.inc.c"
#include "assets/valley/staryu/part8_pre_far.gfx.inc.c"
#include "assets/valley/staryu/part8_pre.gfx.inc.c"
#include "assets/valley/staryu/part8_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part8_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part8_draw.gfx.inc.c"
#include "assets/valley/staryu/part9_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part9_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part9_draw.gfx.inc.c"
#include "assets/valley/staryu/part10_pre_near.gfx.inc.c"
#include "assets/valley/staryu/part10_pre_far.gfx.inc.c"
#include "assets/valley/staryu/part10_pre.gfx.inc.c"
#include "assets/valley/staryu/part10_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part10_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part10_draw.gfx.inc.c"
#include "assets/valley/staryu/part11_draw_near.gfx.inc.c"
#include "assets/valley/staryu/part11_draw_far.gfx.inc.c"
#include "assets/valley/staryu/part11_draw.gfx.inc.c"
#include "assets/valley/staryu/last.gfx.inc.c"

DObjPayloadTypeI staryu_gfxdata[] = {
    { NULL, staryu_first },
    { NULL, staryu_part1_draw },
    { staryu_part2_pre, staryu_part2_draw },
    { NULL, staryu_part3_draw },
    { staryu_part4_pre, staryu_part4_draw },
    { NULL, staryu_part5_draw },
    { staryu_part6_pre, staryu_part6_draw },
    { NULL, staryu_part7_draw },
    { staryu_part8_pre, staryu_part8_draw },
    { NULL, staryu_part9_draw },
    { staryu_part10_pre, staryu_part10_draw },
    { NULL, staryu_last },
};

UnkEC64Arg3 staryu_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, -84.49191284179688, -4.038791179656982 },
      { 0.04776500165462494, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &staryu_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &staryu_gfxdata[1],
      { 0.0, -35.907005310058594, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &staryu_gfxdata[2],
      { 97.16960144042969, -189.17202758789062, 0.0 },
      { -0.016256999224424362, 0.2916249930858612, 0.5643489956855774 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_gfxdata[3],
      { -3.034353017807007, -143.18133544921875, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999979734420776, 0.9999979734420776, 1.0 } },
    { 2,
      &staryu_gfxdata[4],
      { 177.31399536132812, 28.104877471923828, 0.0 },
      { 0.0, 0.0, 0.17399999499320984 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_gfxdata[5],
      { 140.1194610595703, -2.546215057373047, -6.000000212225132e-06 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999989867210388, 1.0 } },
    { 2,
      &staryu_gfxdata[6],
      { -97.16539764404297, -189.19102478027344, 0.0 },
      { -0.023468999192118645, -0.29211801290512085, -0.5288299918174744 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_gfxdata[7],
      { -3.8938400745391846, -143.0745849609375, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999949932098389, 0.9999949932098389, 1.0 } },
    { 2,
      &staryu_gfxdata[8],
      { -177.3101043701172, 28.096771240234375, 0.0 },
      { 0.0, 0.0, -0.24400000274181366 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_gfxdata[9],
      { -139.62525939941406, -12.050104141235352, -3.000000106112566e-06 },
      { 0.0, 0.0, 0.0 },
      { 0.9999970197677612, 0.9999970197677612, 1.0 } },
    { 2,
      &staryu_gfxdata[10],
      { 0.0, 133.5111083984375, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &staryu_gfxdata[11],
      { 0.8059269785881042, 163.1389617919922, 6.000000212225132e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
