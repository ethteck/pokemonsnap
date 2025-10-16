#include "common.h"

extern u8 growlithe_tex_eye_frame0_png[];
extern u8 growlithe_tex_eye_frame1_png[];
extern u8 growlithe_tex_ear_pal[];
extern u8 growlithe_tex_ear_png[];
extern u8 growlithe_tex_eye_frame0_pal[];
extern u8 growlithe_tex_fingers_pal[];
extern u8 growlithe_tex_fingers_png[];
extern u8 growlithe_tex_foot_pal[];
extern u8 growlithe_tex_foot_png[];
extern u8 growlithe_tex_fur1_pal[];
extern u8 growlithe_tex_fur1_png[];
extern u8 growlithe_tex_fur2_pal[];
extern u8 growlithe_tex_fur2_png[];
extern u8 growlithe_tex_fur3_pal[];
extern u8 growlithe_tex_fur3_png[];
extern u8 growlithe_tex_mouth_pal[];
extern u8 growlithe_tex_mouth_png[];
extern u8 growlithe_tex_nose_pal[];
extern u8 growlithe_tex_nose_png[];
extern u8 growlithe_tex_skin1_pal[];
extern u8 growlithe_tex_skin1_png[];
extern u8 growlithe_tex_skin2_pal[];
extern u8 growlithe_tex_skin2_png[];
extern u8 growlithe_tex_tongue_pal[];
extern u8 growlithe_tex_tongue_png[];

extern Texture* growlithe_hd_part3_mat[];
extern Gfx growlithe_hd_part0_draw[];

Texture** growlithe_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    growlithe_hd_part3_mat,
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
    NULL,
    NULL,
    NULL,
};

u8* growlithe_hd_part3_mat0_textures[] = {
    growlithe_tex_eye_frame0_png,
    growlithe_tex_eye_frame1_png,
    NULL,
};

Texture growlithe_hd_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    growlithe_hd_part3_mat0_textures,
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
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64,
    32,
    64,
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

Texture* growlithe_hd_part3_mat[] = {
    &growlithe_hd_part3_mat0,
    NULL,
};
#include "assets/volcano/growlithe/hd_model.vtx.inc.c"
#include "assets/volcano/growlithe/hd_first.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part0_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part1_pre.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part1_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part2_pre.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part2_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part3_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part4_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part5_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part6_pre.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part6_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part7_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part8_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part9_pre.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part9_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part10_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part11_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part12_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part13_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part14_pre.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part14_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part15_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part16_pre.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part16_draw.gfx.inc.c"
#include "assets/volcano/growlithe/hd_part17_draw.gfx.inc.c"

DObjPayloadTypeI growlithe_hd_gfxdata[] = {
    { NULL, growlithe_hd_first },
    { growlithe_hd_part1_pre, growlithe_hd_part1_draw },
    { growlithe_hd_part2_pre, growlithe_hd_part2_draw },
    { NULL, growlithe_hd_part3_draw },
    { NULL, growlithe_hd_part4_draw },
    { NULL, growlithe_hd_part5_draw },
    { growlithe_hd_part6_pre, growlithe_hd_part6_draw },
    { NULL, growlithe_hd_part7_draw },
    { NULL, growlithe_hd_part8_draw },
    { growlithe_hd_part9_pre, growlithe_hd_part9_draw },
    { NULL, growlithe_hd_part10_draw },
    { NULL, growlithe_hd_part11_draw },
    { NULL, growlithe_hd_part12_draw },
    { NULL, growlithe_hd_part13_draw },
    { growlithe_hd_part14_pre, growlithe_hd_part14_draw },
    { NULL, growlithe_hd_part15_draw },
    { growlithe_hd_part16_pre, growlithe_hd_part16_draw },
    { NULL, growlithe_hd_part17_draw },
};

UnkEC64Arg3 growlithe_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &growlithe_hd_gfxdata[0],
      { 0.0, 374.2489013671875, -117.2646255493164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &growlithe_hd_gfxdata[1],
      { 0.0, 2.4950270652770996, 209.579345703125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &growlithe_hd_gfxdata[2],
      { 0.0, 69.8597412109375, 32.434906005859375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &growlithe_hd_gfxdata[3],
      { 0.0, 152.19454956054688, 109.77960968017578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &growlithe_hd_gfxdata[4],
      { 0.0, -9.979915618896484, 202.0944061279297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &growlithe_hd_gfxdata[5],
      { 0.0, 4.990005016326904, -62.50572204589844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &growlithe_hd_gfxdata[6],
      { -148.8628692626953, -53.219459533691406, 72.35480499267578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &growlithe_hd_gfxdata[7],
      { 33.400962829589844, -169.64454650878906, -49.89987564086914 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &growlithe_hd_gfxdata[8],
      { 9.85558032989502, -153.8799285888672, 39.59441375732422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &growlithe_hd_gfxdata[9],
      { 148.8628692626953, -53.219459533691406, 72.35480499267578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &growlithe_hd_gfxdata[10],
      { -33.400962829589844, -169.64454650878906, -49.89987564086914 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &growlithe_hd_gfxdata[11],
      { -9.85558032989502, -153.8799285888672, 39.59441375732422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &growlithe_hd_gfxdata[12],
      { 0.0, 44.90983581542969, -92.31478881835938 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &growlithe_hd_gfxdata[13],
      { 0.0, 159.67955017089844, -124.74966430664062 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &growlithe_hd_gfxdata[14],
      { -93.63237762451172, -45.840145111083984, -19.904624938964844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &growlithe_hd_gfxdata[15],
      { -13.194012641906738, -195.96359252929688, -48.388816833496094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &growlithe_hd_gfxdata[16],
      { 93.63237762451172, -45.840145111083984, -19.904624938964844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &growlithe_hd_gfxdata[17],
      { 13.194012641906738, -195.96359252929688, -48.388816833496094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
