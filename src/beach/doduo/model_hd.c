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

extern Texture* doduo_hd_part5_mat[];
extern Texture* doduo_hd_part9_mat[];
extern Gfx doduo_hd_part0_draw[];

Texture** doduo_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    doduo_hd_part5_mat,
    NULL,
    NULL,
    NULL,
    doduo_hd_part9_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* doduo_hd_part5_mat0_textures[] = {
    doduo_tex_80158A30,
    doduo_tex_80158E90,
};

u8* doduo_hd_part9_mat0_textures[] = {
    doduo_tex_80158A30,
    doduo_tex_80158E90,
    NULL,
};

Texture doduo_hd_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    doduo_hd_part5_mat0_textures,
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
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture doduo_hd_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    doduo_hd_part9_mat0_textures,
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
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* doduo_hd_part5_mat[] = {
    &doduo_hd_part5_mat0,
    NULL,
};

Texture* doduo_hd_part9_mat[] = {
    &doduo_hd_part9_mat0,
    NULL,
};
#include "assets/beach/doduo/hd_model.vtx.inc.c"
#include "assets/beach/doduo/hd_first.gfx.inc.c"
#include "assets/beach/doduo/hd_part0_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part1_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part2_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part3_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part4_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part5_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part6_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part7_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part8_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part9_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part10_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part11_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part12_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part13_draw.gfx.inc.c"
#include "assets/beach/doduo/hd_part14_draw.gfx.inc.c"

UnkEC64Arg3 doduo_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      doduo_hd_first,
      { 0.0, 654.6900024414062, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 6.000000212225132e-06, -356.0197448730469, 1.2000000424450263e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      doduo_hd_part1_draw,
      { 75.0000228881836, 103.32064819335938, 49.999996185302734 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      doduo_hd_part2_draw,
      { 0.2577959895133972, 243.8734588623047, -0.15157799422740936 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      doduo_hd_part3_draw,
      { -0.3620089888572693, 141.69558715820312, -0.1315709948539734 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      doduo_hd_part4_draw,
      { 1.6042410135269165, 104.25548553466797, 124.06304168701172 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      doduo_hd_part5_draw,
      { -75.0000228881836, 103.32064819335938, 49.999996185302734 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      doduo_hd_part6_draw,
      { -0.2577959895133972, 243.8734588623047, -0.1515749990940094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      doduo_hd_part7_draw,
      { 0.3620089888572693, 141.69558715820312, -0.13157400488853455 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      doduo_hd_part8_draw,
      { -1.6042410135269165, 104.25548553466797, 124.06304168701172 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      doduo_hd_part9_draw,
      { 92.10008239746094, -139.97373962402344, -4.201457977294922 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      doduo_hd_part10_draw,
      { -23.29520034790039, -192.8758087158203, 11.008604049682617 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      doduo_hd_part11_draw,
      { 25.75908851623535, -253.30264282226562, 7.046672821044922 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      doduo_hd_part12_draw,
      { -92.10008239746094, -139.97373962402344, -4.201457977294922 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      doduo_hd_part13_draw,
      { 23.295188903808594, -192.87591552734375, 11.008605003356934 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      doduo_hd_part14_draw,
      { -25.75908851623535, -253.30259704589844, 7.046669960021973 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
