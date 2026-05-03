#include "common.h"

extern u8 metapod_tex_80184228[];
extern u8 metapod_tex_80184250_png[];
extern u8 metapod_tex_80184458[];
extern u8 metapod_tex_80184468_png[];
extern u8 metapod_tex_80184570[];
extern u8 metapod_tex_80184580_png[];
extern u8 metapod_tex_80184788[];
extern u8 metapod_tex_801847B0[];
extern u8 metapod_tex_80184BB8[];
extern u8 metapod_tex_80184BC8_png[];
extern u8 metapod_tex_80184DD0[];
extern u8 metapod_tex_80184DE0_png[];
extern u8 metapod_tex_80331DC8[];
extern u8 metapod_tex_80331DD8_png[];
extern u8 metapod_tex_80331FE0[];
extern u8 metapod_tex_80331FF0_png[];

extern Texture* metapod_part1_mat[];
extern Gfx metapod_part0_draw[];

__ALIGNER
u8 metapod_tex_80331DC8[] = {
#include "assets/river/metapod/tex_80331DD8.pal.bin.c"
};

__ALIGNER
u8 metapod_tex_80331DD8_png[] = {
#include "assets/river/metapod/tex_80331DD8.png.bin.c"
};

__ALIGNER
u8 metapod_tex_80331FE0[] = {
#include "assets/river/metapod/tex_80331FF0.pal.bin.c"
};

__ALIGNER
u8 metapod_tex_80331FF0_png[] = {
#include "assets/river/metapod/tex_80331FF0.png.bin.c"
};

Texture** metapod_materials[] = {
    NULL,
    metapod_part1_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* metapod_part1_mat0_textures[] = {
    metapod_tex_801847B0,
    NULL,
};

Texture metapod_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    metapod_part1_mat0_textures,
    128,
    114,
    4,
    128,
    0,
    0.0,
    0.7988939881324768,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    4,
    128,
    4,
    128,
    0.0,
    0.7988939881324768,
    0.0,
    { 0, 0, 0, 0 },
    74245,
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

Texture* metapod_part1_mat[] = {
    &metapod_part1_mat0,
    NULL,
};

#include "assets/river/metapod/model.vtx.inc.c"
#include "assets/river/metapod/first.gfx.inc.c"
#include "assets/river/metapod/part0_draw_near.gfx.inc.c"
#include "assets/river/metapod/part0_draw_far.gfx.inc.c"
#include "assets/river/metapod/part0_draw.gfx.inc.c"
#include "assets/river/metapod/part1_draw_near.gfx.inc.c"
#include "assets/river/metapod/part1_draw_far.gfx.inc.c"
#include "assets/river/metapod/part1_draw.gfx.inc.c"
#include "assets/river/metapod/part2_draw_near.gfx.inc.c"
#include "assets/river/metapod/part2_draw_far.gfx.inc.c"
#include "assets/river/metapod/part2_draw.gfx.inc.c"
#include "assets/river/metapod/part3_draw_near.gfx.inc.c"
#include "assets/river/metapod/part3_draw_far.gfx.inc.c"
#include "assets/river/metapod/part3_draw.gfx.inc.c"
#include "assets/river/metapod/part4_draw_near.gfx.inc.c"
#include "assets/river/metapod/part4_draw_far.gfx.inc.c"
#include "assets/river/metapod/part4_draw.gfx.inc.c"
#include "assets/river/metapod/last.gfx.inc.c"

UnkEC64Arg3 metapod_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8193,
      metapod_first,
      { 0.0, 712.6742553710938, 72.1060791015625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      metapod_part1_draw,
      { 0.0, -0.004244000185281038, 0.0039160000160336494 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      metapod_part2_draw,
      { 0.0, -390.9142150878906, 24.629337310791016 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      metapod_part3_draw,
      { 0.0, -107.6243667602539, -161.07260131835938 },
      { 0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      metapod_last,
      { 0.0, -91.35403442382812, -62.30620193481445 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
