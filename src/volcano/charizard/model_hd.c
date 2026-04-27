#include "common.h"

extern u8 charizard_tex_eye_frame1_png[];
extern u8 charizard_tex_eye_frame2_png[];
extern u8 charizard_tex_eye_frame0_png[];
extern u8 charizard_tex_claw_pal[];
extern u8 charizard_tex_claw_png[];
extern u8 charizard_tex_eye_frame0_pal[];
extern u8 charizard_tex_mouth1_pal[];
extern u8 charizard_tex_mouth1_png[];
extern u8 charizard_tex_mouth2_pal[];
extern u8 charizard_tex_mouth2_png[];
extern u8 charizard_tex_nostril_pal[];
extern u8 charizard_tex_nostril_png[];
extern u8 charizard_tex_skin_pal[];
extern u8 charizard_tex_skin_png[];
extern u8 charizard_tex_tongue_pal[];
extern u8 charizard_tex_tongue_png[];
extern u8 charizard_tex_wing1_pal[];
extern u8 charizard_tex_wing1_png[];
extern u8 charizard_tex_wing2_pal[];
extern u8 charizard_tex_wing2_png[];
extern u8 charizard_tex_wingshade_png[];

extern u8 D_801C30B0_volcano_extra[];
extern u8 D_801C3170_volcano_extra[];
extern u8 D_801C3210_volcano_extra[];
extern u8 D_801C3220_volcano_extra[];
extern u8 D_801C3240_volcano_extra[];
extern u8 D_801C3250_volcano_extra[];
extern u8 D_801C3260_volcano_extra[];
extern u8 D_801C3280_volcano_extra[];
extern u8 D_801C3290_volcano_extra[];
extern u8 D_801C32A0_volcano_extra[];
extern u8 D_801C32C0_volcano_extra[];
extern u8 D_801C3300_volcano_extra[];
extern u8 D_801C3320_volcano_extra[];
extern u8 D_801C3330_volcano_extra[];
extern u8 D_801C3340_volcano_extra[];
extern u8 D_801C3360_volcano_extra[];
extern u8 D_801C3410_volcano_extra[];
extern u8 D_801C3420_volcano_extra[];
extern u8 D_801C3430_volcano_extra[];
extern u8 D_801C3450_volcano_extra[];
extern u8 D_801C3460_volcano_extra[];
extern u8 D_801C34E0_volcano_extra[];
extern u8 D_801C34F0_volcano_extra[];
extern u8 D_801C3500_volcano_extra[];
extern u8 D_801C3590_volcano_extra[];
extern u8 D_801C35A0_volcano_extra[];
extern u8 D_801C35C0_volcano_extra[];
extern u8 D_801C3680_volcano_extra[];
extern u8 D_801C3700_volcano_extra[];
extern u8 D_801C3780_volcano_extra[];
extern u8 D_801C3790_volcano_extra[];
extern u8 D_801C37A0_volcano_extra[];
extern u8 D_801C3830_volcano_extra[];
extern u8 D_801C3840_volcano_extra[];
extern u8 D_801C3860_volcano_extra[];
extern u8 D_801C3920_volcano_extra[];
extern u8 D_801C39A0_volcano_extra[];
extern u8 D_801C39F0_volcano_extra[];
extern u8 D_801C3A40_volcano_extra[];
extern u8 D_801C3AE0_volcano_extra[];
extern u8 D_801C3B80_volcano_extra[];
extern u8 D_801C3BD0_volcano_extra[];
extern u8 D_801C3BF0_volcano_extra[];
extern u8 D_801C3CD0_volcano_extra[];
extern u8 D_801C3D20_volcano_extra[];
extern u8 D_801C3D30_volcano_extra[];
extern u8 D_801C3D50_volcano_extra[];
extern u8 D_801C3D90_volcano_extra[];
extern u8 D_801C3DB0_volcano_extra[];
extern u8 D_801C3DD0_volcano_extra[];
extern u8 D_801C3E00_volcano_extra[];
extern u8 D_801C3E10_volcano_extra[];
extern u8 D_801C3E20_volcano_extra[];
extern u8 D_801C3E40_volcano_extra[];
extern u8 D_801C3E60_volcano_extra[];
extern u8 D_801C3E80_volcano_extra[];
extern u8 D_801C3E90_volcano_extra[];
extern u8 D_801C3EC0_volcano_extra[];
extern u8 D_801C3F40_volcano_extra[];
extern u8 D_801C3F50_volcano_extra[];
extern u8 D_801C3F80_volcano_extra[];
extern u8 D_801C3F90_volcano_extra[];
extern u8 D_801C3FA0_volcano_extra[];
extern u8 D_801C3FB0_volcano_extra[];
extern u8 D_801C3FD0_volcano_extra[];
extern u8 D_801C3FF0_volcano_extra[];
extern u8 D_801C4000_volcano_extra[];
extern u8 D_801C4010_volcano_extra[];
extern u8 D_801C4020_volcano_extra[];
extern u8 D_801C4040_volcano_extra[];
extern u8 D_801C4050_volcano_extra[];
extern u8 D_801C4060_volcano_extra[];
extern u8 D_801C40A0_volcano_extra[];
extern u8 D_801C40C0_volcano_extra[];
extern u8 D_801C40E0_volcano_extra[];
extern u8 D_801C4120_volcano_extra[];
extern u8 D_801C4140_volcano_extra[];
extern u8 D_801C41C0_volcano_extra[];
extern u8 D_801C41D0_volcano_extra[];
extern u8 D_801C4270_volcano_extra[];
extern u8 D_801C42F0_volcano_extra[];
extern u8 D_801C43D0_volcano_extra[];
extern u8 D_801C4450_volcano_extra[];
extern u8 D_801C4490_volcano_extra[];
extern u8 D_801C44C0_volcano_extra[];
extern u8 D_801C44F0_volcano_extra[];
extern u8 D_801C45E0_volcano_extra[];
extern u8 D_801C4730_volcano_extra[];
extern u8 D_801C4760_volcano_extra[];
extern u8 D_801C4790_volcano_extra[];
extern u8 D_801C4880_volcano_extra[];
extern u8 D_801C4A08_volcano_extra[];

extern Texture* charizard_hd_part8_mat[];
extern Gfx charizard_hd_part0_draw[];

Texture** charizard_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    charizard_hd_part8_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* charizard_hd_part8_mat0_textures[] = {
    charizard_tex_eye_frame0_png,
    charizard_tex_eye_frame1_png,
    charizard_tex_eye_frame2_png,
};

Texture charizard_hd_part8_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    charizard_hd_part8_mat0_textures,
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

Texture* charizard_hd_part8_mat[] = {
    &charizard_hd_part8_mat0,
    NULL,
};
#include "assets/volcano/charizard/hd_model.vtx.inc.c"
#include "assets/volcano/charizard/hd_first.gfx.inc.c"
#include "assets/volcano/charizard/hd_part0_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part1_pre.gfx.inc.c"
#include "assets/volcano/charizard/hd_part1_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part2_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part3_pre.gfx.inc.c"
#include "assets/volcano/charizard/hd_part3_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part4_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part5_pre.gfx.inc.c"
#include "assets/volcano/charizard/hd_part5_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part6_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part7_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part8_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part9_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part10_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part11_pre.gfx.inc.c"
#include "assets/volcano/charizard/hd_part11_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part12_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part13_pre.gfx.inc.c"
#include "assets/volcano/charizard/hd_part13_draw.gfx.inc.c"
#include "assets/volcano/charizard/hd_part14_draw.gfx.inc.c"

DObjPayloadTypeI charizard_hd_gfxdata[] = {
    { NULL, charizard_hd_first },
    { charizard_hd_part1_pre, charizard_hd_part1_draw },
    { NULL, charizard_hd_part2_draw },
    { charizard_hd_part3_pre, charizard_hd_part3_draw },
    { NULL, charizard_hd_part4_draw },
    { charizard_hd_part5_pre, charizard_hd_part5_draw },
    { NULL, charizard_hd_part6_draw },
    { NULL, charizard_hd_part7_draw },
    { NULL, charizard_hd_part8_draw },
    { NULL, charizard_hd_part9_draw },
    { NULL, charizard_hd_part10_draw },
    { charizard_hd_part11_pre, charizard_hd_part11_draw },
    { NULL, charizard_hd_part12_draw },
    { charizard_hd_part13_pre, charizard_hd_part13_draw },
    { NULL, charizard_hd_part14_draw },
};

UnkEC64Arg3 charizard_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &charizard_hd_gfxdata[0],
      { 0.0, 539.1506958007812, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charizard_hd_gfxdata[1],
      { 100.0, 260.8492736816406, -130.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charizard_hd_gfxdata[2],
      { 370.0, 900.0, 200.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charizard_hd_gfxdata[3],
      { -100.0, 260.8492736816406, -130.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charizard_hd_gfxdata[4],
      { -370.0, 900.0, 200.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charizard_hd_gfxdata[5],
      { 9.999999974752427e-07, 435.3652038574219, 133.00120544433594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charizard_hd_gfxdata[6],
      { 0.0005990000208839774, 126.9460678100586, 175.01779174804688 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &charizard_hd_gfxdata[7],
      { -10.129862785339355, 112.89939880371094, 164.89312744140625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &charizard_hd_gfxdata[8],
      { 6.481238842010498, 19.333267211914062, 175.32391357421875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &charizard_hd_gfxdata[9],
      { 0.000455000001238659, -0.004004999995231628, 0.01740499958395958 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &charizard_hd_gfxdata[10],
      { 3.8220560550689697, -28.90605926513672, 153.51870727539062 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      NULL,
      { 10.129262924194336, -49.28140640258789, 325.33392333984375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charizard_hd_gfxdata[11],
      { 196.88031005859375, 242.62876892089844, 43.79399871826172 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charizard_hd_gfxdata[12],
      { 153.11968994140625, -81.77947998046875, -103.79400634765625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &charizard_hd_gfxdata[13],
      { -196.9364013671875, 242.62876892089844, 43.79399871826172 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &charizard_hd_gfxdata[14],
      { -153.0635986328125, -81.77947998046875, -103.79400634765625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
