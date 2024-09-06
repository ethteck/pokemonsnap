#include <common.h>

extern u8 growlithe_tex_nose_pal[];
extern u8 growlithe_tex_nose_png[];
extern u8 growlithe_tex_eye_frame0_pal[];
extern u8 growlithe_tex_eye_frame0_png[];
extern u8 growlithe_tex_eye_frame1_png[];
extern u8 growlithe_tex_fur1_pal[];
extern u8 growlithe_tex_fur1_png[];
extern u8 growlithe_tex_fur2_pal[];
extern u8 growlithe_tex_fur2_png[];
extern u8 growlithe_tex_mouth_pal[];
extern u8 growlithe_tex_mouth_png[];
extern u8 growlithe_tex_skin1_pal[];
extern u8 growlithe_tex_skin1_png[];
extern u8 growlithe_tex_ear_pal[];
extern u8 growlithe_tex_ear_png[];
extern u8 growlithe_tex_fur3_pal[];
extern u8 growlithe_tex_fur3_png[];
extern u8 growlithe_tex_tongue_pal[];
extern u8 growlithe_tex_tongue_png[];
extern u8 growlithe_tex_skin2_pal[];
extern u8 growlithe_tex_skin2_png[];
extern u8 growlithe_tex_fingers_pal[];
extern u8 growlithe_tex_fingers_png[];
extern u8 growlithe_tex_foot_pal[];
extern u8 growlithe_tex_foot_png[];

extern Texture* growlithe_part2_mat[];
extern Gfx growlithe_part0_draw[];

Texture** growlithe_materials[] = {
    NULL,
    NULL,
    NULL,
    growlithe_part2_mat,
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

u8* growlithe_part2_mat0_textures[] = {
    growlithe_tex_eye_frame0_png,
    growlithe_tex_eye_frame1_png,
    NULL,
};

Texture growlithe_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    growlithe_part2_mat0_textures,
    128,
    64,
    64, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64, 32,
    64, 32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    0xFFFFFF00,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture* growlithe_part2_mat[] = {
    &growlithe_part2_mat0,
    NULL,
};


#include "assets/volcano/growlithe/model.vtx.inc.c"
#include "assets/volcano/growlithe/first.gfx.inc.c"
#include "assets/volcano/growlithe/part0_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part0_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part0_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part1_pre_near.gfx.inc.c"
#include "assets/volcano/growlithe/part1_pre_far.gfx.inc.c"
#include "assets/volcano/growlithe/part1_pre.gfx.inc.c"
#include "assets/volcano/growlithe/part1_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part1_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part1_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part2_pre_near.gfx.inc.c"
#include "assets/volcano/growlithe/part2_pre_far.gfx.inc.c"
#include "assets/volcano/growlithe/part2_pre.gfx.inc.c"
#include "assets/volcano/growlithe/part2_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part2_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part2_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part3_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part3_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part3_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part4_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part4_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part4_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part5_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part5_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part5_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part6_pre_near.gfx.inc.c"
#include "assets/volcano/growlithe/part6_pre_far.gfx.inc.c"
#include "assets/volcano/growlithe/part6_pre.gfx.inc.c"
#include "assets/volcano/growlithe/part6_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part6_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part6_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part7_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part7_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part7_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part8_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part8_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part8_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part9_pre_near.gfx.inc.c"
#include "assets/volcano/growlithe/part9_pre_far.gfx.inc.c"
#include "assets/volcano/growlithe/part9_pre.gfx.inc.c"
#include "assets/volcano/growlithe/part9_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part9_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part9_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part10_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part10_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part10_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part11_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part11_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part11_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part12_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part12_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part12_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part13_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part13_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part13_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part14_pre_near.gfx.inc.c"
#include "assets/volcano/growlithe/part14_pre_far.gfx.inc.c"
#include "assets/volcano/growlithe/part14_pre.gfx.inc.c"
#include "assets/volcano/growlithe/part14_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part14_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part14_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part15_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part15_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part15_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part16_pre_near.gfx.inc.c"
#include "assets/volcano/growlithe/part16_pre_far.gfx.inc.c"
#include "assets/volcano/growlithe/part16_pre.gfx.inc.c"
#include "assets/volcano/growlithe/part16_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part16_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part16_draw.gfx.inc.c"
#include "assets/volcano/growlithe/part17_draw_near.gfx.inc.c"
#include "assets/volcano/growlithe/part17_draw_far.gfx.inc.c"
#include "assets/volcano/growlithe/part17_draw.gfx.inc.c"
#include "assets/volcano/growlithe/last.gfx.inc.c"

DObjPayloadTypeI growlithe_gfxdata[] = {
    { NULL, growlithe_first },
    { growlithe_part1_pre, growlithe_part1_draw },
    { growlithe_part2_pre, growlithe_part2_draw },
    { NULL, growlithe_part3_draw },
    { NULL, growlithe_part4_draw },
    { NULL, growlithe_part5_draw },
    { growlithe_part6_pre, growlithe_part6_draw },
    { NULL, growlithe_part7_draw },
    { NULL, growlithe_part8_draw },
    { growlithe_part9_pre, growlithe_part9_draw },
    { NULL, growlithe_part10_draw },
    { NULL, growlithe_part11_draw },
    { NULL, growlithe_part12_draw },
    { NULL, growlithe_part13_draw },
    { growlithe_part14_pre, growlithe_part14_draw },
    { NULL, growlithe_part15_draw },
    { growlithe_part16_pre, growlithe_part16_draw },
    { NULL, growlithe_last },
};

UnkEC64Arg3 growlithe_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      &growlithe_gfxdata[0],
      { 0.0, 374.2489013671875, -117.2646255493164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &growlithe_gfxdata[1],
      { 0.0, 2.4991509914398193, 209.5782470703125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &growlithe_gfxdata[2],
      { 0.0, 69.8597412109375, 32.434906005859375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &growlithe_gfxdata[3],
      { 0.0, 152.19454956054688, 109.77960968017578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &growlithe_gfxdata[4],
      { 0.0, -9.979915618896484, 202.0944061279297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      &growlithe_gfxdata[5],
      { 0.0, 4.990005016326904, -62.50572204589844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &growlithe_gfxdata[6],
      { -148.8628692626953, -53.219459533691406, 72.35480499267578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &growlithe_gfxdata[7],
      { 33.400962829589844, -169.64454650878906, -49.89987564086914 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      &growlithe_gfxdata[8],
      { 9.85558032989502, -153.8799285888672, 39.59441375732422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &growlithe_gfxdata[9],
      { 148.8628692626953, -53.219459533691406, 72.35480499267578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &growlithe_gfxdata[10],
      { -33.400962829589844, -169.64454650878906, -49.89987564086914 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      &growlithe_gfxdata[11],
      { -9.85558032989502, -153.8799285888672, 39.59441375732422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &growlithe_gfxdata[12],
      { 0.0, 44.90983581542969, -92.31478881835938 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &growlithe_gfxdata[13],
      { 0.0, 159.67955017089844, -124.74966430664062 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &growlithe_gfxdata[14],
      { -93.63237762451172, -45.840145111083984, -19.904624938964844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &growlithe_gfxdata[15],
      { -13.194012641906738, -195.96359252929688, -48.388816833496094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &growlithe_gfxdata[16],
      { 93.63237762451172, -45.840145111083984, -19.904624938964844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &growlithe_gfxdata[17],
      { 13.194012641906738, -195.96359252929688, -48.388816833496094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 }
    },
};

