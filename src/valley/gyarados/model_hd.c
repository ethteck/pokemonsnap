#include "common.h"

extern u8 gyarados_tex_801347D8[];
extern u8 gyarados_tex_80134898_png[];
extern u8 gyarados_tex_801350A0[];
extern u8 gyarados_tex_80135280_png[];
extern u8 gyarados_tex_80135A88[];
extern u8 gyarados_tex_80135AA8_png[];
extern u8 gyarados_tex_80135EB0[];
extern u8 gyarados_tex_80135ED0_png[];
extern u8 gyarados_tex_801362D8[];
extern u8 gyarados_tex_801364E0_png[];
extern u8 gyarados_tex_80136CE8[];
extern u8 gyarados_tex_80136EF0_png[];
extern u8 gyarados_tex_801376F8[];
extern u8 gyarados_tex_80137720_png[];
extern u8 gyarados_tex_80137928[];
extern u8 gyarados_tex_80137950_png[];
extern u8 gyarados_tex_80137A58[];
extern u8 gyarados_tex_80137A78_png[];
extern u8 gyarados_tex_80137B00[];
extern u8 gyarados_tex_80137B28_png[];
extern u8 gyarados_tex_80137C30[];
extern u8 gyarados_tex_80137C58_png[];

extern Texture* gyarados_hd_part7_mat[];
extern Gfx gyarados_hd_part0_draw[];

Texture** gyarados_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    gyarados_hd_part7_mat,
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

Texture gyarados_hd_part7_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    NULL,
    32,
    0,
    64,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
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

Texture gyarados_hd_part7_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    NULL,
    32,
    0,
    64,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
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

Texture* gyarados_hd_part7_mat[] = {
    &gyarados_hd_part7_mat0,
    &gyarados_hd_part7_mat1,
    NULL,
    NULL,
};
#include "assets/valley/gyarados/hd_model.vtx.inc.c"
#include "assets/valley/gyarados/hd_first.gfx.inc.c"
#include "assets/valley/gyarados/hd_part0_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part1_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part2_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part3_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part4_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part5_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part6_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part7_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part8_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part9_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part10_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part11_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part12_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part13_draw.gfx.inc.c"
#include "assets/valley/gyarados/hd_part14_draw.gfx.inc.c"

UnkEC64Arg3 gyarados_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      gyarados_hd_first,
      { 0.00015700000221841037, 996.9083862304688, -279.1653747558594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      gyarados_hd_part1_draw,
      { 0.0, 326.0002136230469, 486.00006103515625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      gyarados_hd_part2_draw,
      { -5.199999941396527e-05, 301.0667724609375, 265.2615661621094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      gyarados_hd_part3_draw,
      { 3.9999998989515007e-05, 477.01739501953125, 18.594694137573242 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      gyarados_hd_part4_draw,
      { -0.0007120000082068145, 297.7149963378906, 41.49675369262695 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      gyarados_hd_part5_draw,
      { 0.0003370000049471855, 225.13369750976562, 151.21231079101562 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      gyarados_hd_part6_draw,
      { 0.00011899999663000926, 2.793694019317627, 575.1640014648438 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8,
      gyarados_hd_part7_draw,
      { -0.00056900002527982, -246.57803344726562, 723.859619140625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 9,
      gyarados_hd_part8_draw,
      { 1.100229024887085, -421.9140930175781, -144.5392608642578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 10,
      gyarados_hd_part9_draw,
      { -1.0994549989700317, 89.60323333740234, -173.30303955078125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 11,
      gyarados_hd_part10_draw,
      { -0.001167000038549304, -69.09008026123047, 243.25637817382812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 9,
      NULL,
      { 0.0009539999882690609, -272.4756164550781, -137.8589630126953 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 9,
      gyarados_hd_part11_draw,
      { 138.0005645751953, -189.42242431640625, -461.85980224609375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 9,
      gyarados_hd_part12_draw,
      { -138.79946899414062, -189.42242431640625, -461.85980224609375 },
      { 0.0, 0.0, 0.0 },
      { -1.0, 1.0, 1.0 } },
    { 8,
      NULL,
      { 0.0, 526.1419067382812, 117.76866912841797 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8,
      gyarados_hd_part13_draw,
      { 257.79931640625, -275.5609436035156, 244.3067626953125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8,
      gyarados_hd_part14_draw,
      { -257.80059814453125, -275.5605773925781, 244.3067626953125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
