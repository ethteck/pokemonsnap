#include "common.h"

extern u8 doduo_tex_80158A08[];
extern u8 doduo_tex_80158A30[];
extern u8 doduo_tex_80158C38[];
extern u8 doduo_tex_80158C60_png[];
extern u8 doduo_tex_80158E90[];
extern u8 doduo_tex_80159098[];
extern u8 doduo_tex_801590C0_png[];
extern u8 doduo_tex_801591C8[];
extern u8 doduo_tex_801593D0_png[];
extern u8 doduo_tex_80159BD8[];
extern u8 doduo_tex_80159C00_png[];
extern u8 doduo_tex_80159D08[];
extern u8 doduo_tex_80159D30_png[];
extern u8 doduo_tex_80159DB8[];
extern u8 doduo_tex_80159DE0_png[];

Texture* doduo_part5_mat[];
Texture* doduo_part9_mat[];
Gfx doduo_part0_draw[];

Texture** D_beach_8031C220[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    doduo_part5_mat,
    NULL,
    NULL,
    NULL,
    doduo_part9_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* doduo_part5_mat0_textures[] = {
    doduo_tex_80158A30,
    doduo_tex_80158E90,
};

u8* doduo_part9_mat0_textures[] = {
    doduo_tex_80158A30,
    doduo_tex_80158E90,
    NULL,
};

Texture doduo_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    doduo_part5_mat0_textures,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture doduo_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    doduo_part9_mat0_textures,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* doduo_part5_mat[] = {
    &doduo_part5_mat0,
    NULL,
};

Texture* doduo_part9_mat[] = {
    &doduo_part9_mat0,
    NULL,
};

#include "assets/beach/doduo/model.vtx.inc.c"
#include "assets/beach/doduo/first.gfx.inc.c"
#include "assets/beach/doduo/part0_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part0_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part0_draw.gfx.inc.c"
#include "assets/beach/doduo/part1_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part1_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part1_draw.gfx.inc.c"
#include "assets/beach/doduo/part2_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part2_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part2_draw.gfx.inc.c"
#include "assets/beach/doduo/part3_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part3_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part3_draw.gfx.inc.c"
#include "assets/beach/doduo/part4_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part4_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part4_draw.gfx.inc.c"
#include "assets/beach/doduo/part5_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part5_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part5_draw.gfx.inc.c"
#include "assets/beach/doduo/part6_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part6_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part6_draw.gfx.inc.c"
#include "assets/beach/doduo/part7_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part7_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part7_draw.gfx.inc.c"
#include "assets/beach/doduo/part8_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part8_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part8_draw.gfx.inc.c"
#include "assets/beach/doduo/part9_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part9_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part9_draw.gfx.inc.c"
#include "assets/beach/doduo/part10_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part10_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part10_draw.gfx.inc.c"
#include "assets/beach/doduo/part11_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part11_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part11_draw.gfx.inc.c"
#include "assets/beach/doduo/part12_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part12_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part12_draw.gfx.inc.c"
#include "assets/beach/doduo/part13_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part13_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part13_draw.gfx.inc.c"
#include "assets/beach/doduo/part14_draw_near.gfx.inc.c"
#include "assets/beach/doduo/part14_draw_far.gfx.inc.c"
#include "assets/beach/doduo/part14_draw.gfx.inc.c"
#include "assets/beach/doduo/last.gfx.inc.c"

UnkEC64Arg3 doduo_model[] = {
    { 0,
      NULL,
      { 0.0, 4.8000001697801054e-05, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      doduo_first,
      { 0.0, 653.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 0.0, -354.3297424316406, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      doduo_part1_draw,
      { 75.0, 105.01065063476562, 49.99999237060547 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      doduo_part2_draw,
      { -0.1228329986333847, 243.3926544189453, -0.15151500701904297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      doduo_part3_draw,
      { -0.16517600417137146, 144.18038940429688, 0.30356600880622864 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      doduo_part4_draw,
      { 0.2534390091896057, 105.71890258789062, 113.2711181640625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      doduo_part5_draw,
      { -75.0, 105.01065063476562, 49.99999237060547 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      doduo_part6_draw,
      { 0.1228329986333847, 243.3926544189453, -0.15151500701904297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      doduo_part7_draw,
      { 0.16517600417137146, 144.18038940429688, 0.30357199907302856 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      doduo_part8_draw,
      { -0.2534390091896057, 105.71890258789062, 113.27110290527344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      doduo_part9_draw,
      { 92.0999984741211, -138.28372192382812, -4.201444149017334 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      doduo_part10_draw,
      { -20.78542709350586, -186.84532165527344, 10.921311378479004 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      doduo_part11_draw,
      { 26.70116424560547, -253.40818786621094, 7.001473903656006 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      doduo_part12_draw,
      { -92.0999984741211, -138.28372192382812, -4.201444149017334 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      doduo_part13_draw,
      { 20.78542709350586, -186.84527587890625, 10.921313285827637 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      doduo_last,
      { -26.70111656188965, -253.40902709960938, 7.001471042633057 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
