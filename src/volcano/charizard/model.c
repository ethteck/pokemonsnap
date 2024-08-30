#include <common.h>

extern u8 charizard_tex_mouth1_pal[];
extern u8 charizard_tex_mouth1_png[];
extern u8 charizard_tex_mouth2_pal[];
extern u8 charizard_tex_mouth2_png[];
extern u8 charizard_tex_eye_frame0_pal[];
extern u8 charizard_tex_eye_frame0_png[];
extern u8 charizard_tex_eye_frame1_png[];
extern u8 charizard_tex_eye_frame2_png[];
extern u8 charizard_tex_nostril_pal[];
extern u8 charizard_tex_nostril_png[];
extern u8 charizard_tex_wingshade_pal[];
extern u8 charizard_tex_wingshade_png[];
extern u8 charizard_tex_wing1_pal[];
extern u8 charizard_tex_wing1_png[];
extern u8 charizard_tex_wing2_pal[];
extern u8 charizard_tex_wing2_png[];
extern u8 charizard_tex_skin_pal[];
extern u8 charizard_tex_skin_png[];
extern u8 charizard_tex_tongue_pal[];
extern u8 charizard_tex_tongue_png[];
extern u8 charizard_tex_claw_pal[];
extern u8 charizard_tex_claw_png[];


extern Texture* charizard_part7_mat[];
extern Gfx charizard_part0_draw[];

Texture** charizard_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    charizard_part7_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* charizard_part7_mat0_images[] = {
    charizard_tex_eye_frame0_png,
    charizard_tex_eye_frame1_png,
    charizard_tex_eye_frame2_png,
};

Texture charizard_part7_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    charizard_part7_mat0_images,
    128,
    64,
    64, 32,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
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

Texture* charizard_part7_mat[] = {
    &charizard_part7_mat0,
    NULL,
};


#include "assets/volcano/charizard/model.vtx.inc.c"
#include "assets/volcano/charizard/first.gfx.inc.c"
#include "assets/volcano/charizard/part0_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part0_draw.gfx.inc.c"
#include "assets/volcano/charizard/part1_pre_near.gfx.inc.c"
#include "assets/volcano/charizard/part1_pre.gfx.inc.c"
#include "assets/volcano/charizard/part1_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part1_draw.gfx.inc.c"
#include "assets/volcano/charizard/part2_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part2_draw.gfx.inc.c"
#include "assets/volcano/charizard/part3_pre_near.gfx.inc.c"
#include "assets/volcano/charizard/part3_pre.gfx.inc.c"
#include "assets/volcano/charizard/part3_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part3_draw.gfx.inc.c"
#include "assets/volcano/charizard/part4_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part4_draw.gfx.inc.c"
#include "assets/volcano/charizard/part5_pre_near.gfx.inc.c"
#include "assets/volcano/charizard/part5_pre.gfx.inc.c"
#include "assets/volcano/charizard/part5_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part5_draw.gfx.inc.c"
#include "assets/volcano/charizard/part6_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part6_draw.gfx.inc.c"
#include "assets/volcano/charizard/part7_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part7_draw.gfx.inc.c"
#include "assets/volcano/charizard/part8_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part8_draw.gfx.inc.c"
#include "assets/volcano/charizard/part9_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part9_draw.gfx.inc.c"
#include "assets/volcano/charizard/part10_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part10_draw.gfx.inc.c"
#include "assets/volcano/charizard/part11_pre_near.gfx.inc.c"
#include "assets/volcano/charizard/part11_pre.gfx.inc.c"
#include "assets/volcano/charizard/part11_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part11_draw.gfx.inc.c"
#include "assets/volcano/charizard/part12_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part12_draw.gfx.inc.c"
#include "assets/volcano/charizard/part13_pre_near.gfx.inc.c"
#include "assets/volcano/charizard/part13_pre.gfx.inc.c"
#include "assets/volcano/charizard/part13_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part13_draw.gfx.inc.c"
#include "assets/volcano/charizard/part14_draw_near.gfx.inc.c"
#include "assets/volcano/charizard/part14_draw.gfx.inc.c"
#include "assets/volcano/charizard/last.gfx.inc.c"

DObjPayloadTypeI charizard_gfxdata[] = {
    { NULL, charizard_first },
    { charizard_part1_pre, charizard_part1_draw },
    { NULL, charizard_part2_draw },
    { charizard_part3_pre, charizard_part3_draw },
    { NULL, charizard_part4_draw },
    { charizard_part5_pre, charizard_part5_draw },
    { NULL, charizard_part6_draw },
    { NULL, charizard_part7_draw },
    { NULL, charizard_part8_draw },
    { NULL, charizard_part9_draw },
    { NULL, charizard_part10_draw },
    { charizard_part11_pre, charizard_part11_draw },
    { NULL, charizard_part12_draw },
    { charizard_part13_pre, charizard_part13_draw },
    { NULL, charizard_last },
};

UnkEC64Arg3 charizard_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      &charizard_gfxdata[0],
      { 0.0, 539.1506958007812, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &charizard_gfxdata[1],
      { 100.0, 260.8492736816406, -130.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &charizard_gfxdata[2],
      { 369.9999694824219, 900.0, 200.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &charizard_gfxdata[3],
      { -100.0, 260.8492736816406, -130.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &charizard_gfxdata[4],
      { -369.9999694824219, 900.0, 199.99998474121094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &charizard_gfxdata[5],
      { 9.999999974752427e-07, 435.3652038574219, 133.00120544433594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &charizard_gfxdata[6],
      { 0.0005990000208839774, 126.9460678100586, 175.01779174804688 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      &charizard_gfxdata[7],
      { -10.129862785339355, 112.89939880371094, 164.89312744140625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      &charizard_gfxdata[8],
      { 6.481265068054199, 19.333171844482422, 175.32386779785156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 6,
      &charizard_gfxdata[9],
      { -5.572700023651123, 0.011443999595940113, 0.01692800037562847 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 7,
      &charizard_gfxdata[10],
      { 3.3485000133514404, -43.667030334472656, 150.00047302246094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      NULL,
      { 10.129262924194336, -49.28140640258789, 325.33392333984375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &charizard_gfxdata[11],
      { 196.88031005859375, 242.62876892089844, 43.79399871826172 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &charizard_gfxdata[12],
      { 153.11968994140625, -81.77947998046875, -103.79400634765625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      &charizard_gfxdata[13],
      { -196.9364013671875, 242.62876892089844, 43.79399871826172 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      &charizard_gfxdata[14],
      { -153.0635986328125, -81.77947998046875, -103.79400634765625 },
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

