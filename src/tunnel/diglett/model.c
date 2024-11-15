#include "common.h"

extern u8 diglett_tex_right_eye_frame0_pal[];
extern u8 diglett_tex_right_eye_frame0_png[];
extern u8 diglett_tex_right_eye_frame1_png[];
extern u8 diglett_tex_left_eye_frame1_png[];
extern u8 diglett_tex_left_eye_frame0_pal[];
extern u8 diglett_tex_left_eye_frame0_png[];
extern u8 diglett_tex_head_pal[];
extern u8 diglett_tex_head_png[];
extern u8 diglett_tex_body_pal[];
extern u8 diglett_tex_body_png[];
extern u8 diglett_tex_nose_pal[];
extern u8 diglett_tex_nose_png[];
extern u8 diglett_tex_soil_pal[];
extern u8 diglett_tex_soil_png[];

extern Texture* diglett_part4_mat[];
extern Gfx diglett_part0_draw[];

Texture** diglett_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    diglett_part4_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* diglett_part4_mat0_images[] = {
    diglett_tex_right_eye_frame0_png,
    diglett_tex_right_eye_frame1_png,
};

u8* diglett_part4_mat1_images[] = {
    diglett_tex_left_eye_frame0_png,
    diglett_tex_left_eye_frame1_png,
    NULL
};

Texture diglett_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    diglett_part4_mat0_images,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture diglett_part4_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    diglett_part4_mat1_images,
    128,
    64,
    32, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32, 32,
    32, 32,
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* diglett_part4_mat[] = {
    &diglett_part4_mat0,
    &diglett_part4_mat1,
    NULL,
};

#include "assets/tunnel/diglett/model.vtx.inc.c"
#include "assets/tunnel/diglett/first.gfx.inc.c"
#include "assets/tunnel/diglett/part0_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part0_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part1_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part1_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part2_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part2_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part3_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part3_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part4_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part4_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part5_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part5_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part6_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part6_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part7_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part7_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part8_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part8_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part9_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part9_draw.gfx.inc.c"
#include "assets/tunnel/diglett/part10_draw_near.gfx.inc.c"
#include "assets/tunnel/diglett/part10_draw.gfx.inc.c"
#include "assets/tunnel/diglett/last.gfx.inc.c"

UnkEC64Arg3 diglett_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      diglett_first,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      diglett_part1_draw,
      { 0.0, -0.16426, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      diglett_part2_draw,
      { 0.0, 0.000598, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      diglett_part3_draw,
      { 0.0, 62.174095153808594, -0.000003 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      diglett_part4_draw,
      { 0.0, 31.19747543334961, 0.000003 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 6,
      NULL,
      { 0.0, 126.7921, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      diglett_part5_draw,
      { 0.0, -0.000001, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.01, 0.01, 0.01 }
    },
    { 1,
      diglett_part6_draw,
      { 0.0, -0.000001, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.01, 0.01, 0.01 }
    },
    { 1,
      diglett_part7_draw,
      { 0.0, -0.000001, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.01, 0.01, 0.01 }
    },
    { 1,
      diglett_part8_draw,
      { 0.0, -0.000001, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.01, 0.01, 0.01 }
    },
    { 1,
      diglett_part9_draw,
      { 0.0, -0.000003, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.01, 0.01, 0.01 }
    },
    { 1,
      diglett_last,
      { 0.0, -0.000001, -1.0 },
      { 0.0, 0.0, 0.0 },
      { 0.01, 0.01, 0.01 }
    },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 }
    },
};
