#include "common.h"

extern u8 arcanine_tex_eye_frame0_png[];
extern u8 arcanine_tex_eye_frame1_png[];
extern u8 arcanine_tex_eye_frame2_png[];
extern u8 arcanine_tex_skin1_pal[];
extern u8 arcanine_tex_skin1_png[];
extern u8 arcanine_tex_skin2_pal[];
extern u8 arcanine_tex_skin2_png[];
extern u8 arcanine_tex_skin3_pal[];
extern u8 arcanine_tex_skin3_png[];
extern u8 arcanine_tex_skin4_pal[];
extern u8 arcanine_tex_skin4_png[];
extern u8 arcanine_tex_skin5_pal[];
extern u8 arcanine_tex_skin5_png[];
extern u8 arcanine_tex_eye_frame0_pal[];
extern u8 arcanine_tex_fur1_pal[];
extern u8 arcanine_tex_fur1_png[];
extern u8 arcanine_tex_fur2_pal[];
extern u8 arcanine_tex_fur2_png[];
extern u8 arcanine_tex_mouth_pal[];
extern u8 arcanine_tex_mouth_png[];
extern u8 arcanine_tex_nose_pal[];
extern u8 arcanine_tex_nose_png[];
extern u8 arcanine_tex_ear_pal[];
extern u8 arcanine_tex_ear_png[];
extern u8 arcanine_tex_tongue_pal[];
extern u8 arcanine_tex_tongue_png[];
extern u8 arcanine_tex_fingers_pal[];
extern u8 arcanine_tex_fingers_png[];
extern u8 arcanine_tex_foot_pal[];
extern u8 arcanine_tex_foot_png[];

extern Texture* arcanine_hd_part3_mat[];
extern Gfx arcanine_hd_part0_draw[];

Texture** arcanine_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    arcanine_hd_part3_mat,
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
    NULL,
    NULL,
    NULL,
};

u8* arcanine_hd_part3_mat0_textures[] = {
    arcanine_tex_eye_frame0_png,
    arcanine_tex_eye_frame1_png,
    arcanine_tex_eye_frame2_png,
    NULL,
};

Texture arcanine_hd_part3_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    arcanine_hd_part3_mat0_textures,
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

Texture* arcanine_hd_part3_mat[] = {
    &arcanine_hd_part3_mat0,
    NULL,
};
#include "assets/volcano/arcanine/hd_model.vtx.inc.c"
#include "assets/volcano/arcanine/hd_first.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part0_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part1_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part1_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part2_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part2_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part3_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part4_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part5_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part5_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part6_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part7_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part8_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part9_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part9_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part10_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part11_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part12_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part13_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part14_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part15_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part15_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part16_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part16_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part17_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part17_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part18_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part18_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part19_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part19_draw.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part20_pre.gfx.inc.c"
#include "assets/volcano/arcanine/hd_part20_draw.gfx.inc.c"

DObjPayloadTypeI arcanine_hd_gfxdata[] = {
    { NULL, arcanine_hd_first },
    { arcanine_hd_part1_pre, arcanine_hd_part1_draw },
    { arcanine_hd_part2_pre, arcanine_hd_part2_draw },
    { NULL, arcanine_hd_part3_draw },
    { NULL, arcanine_hd_part4_draw },
    { arcanine_hd_part5_pre, arcanine_hd_part5_draw },
    { NULL, arcanine_hd_part6_draw },
    { NULL, arcanine_hd_part7_draw },
    { NULL, arcanine_hd_part8_draw },
    { arcanine_hd_part9_pre, arcanine_hd_part9_draw },
    { NULL, arcanine_hd_part10_draw },
    { NULL, arcanine_hd_part11_draw },
    { NULL, arcanine_hd_part12_draw },
    { NULL, arcanine_hd_part13_draw },
    { NULL, arcanine_hd_part14_draw },
    { arcanine_hd_part15_pre, arcanine_hd_part15_draw },
    { arcanine_hd_part16_pre, arcanine_hd_part16_draw },
    { arcanine_hd_part17_pre, arcanine_hd_part17_draw },
    { arcanine_hd_part18_pre, arcanine_hd_part18_draw },
    { arcanine_hd_part19_pre, arcanine_hd_part19_draw },
    { arcanine_hd_part20_pre, arcanine_hd_part20_draw },
};

UnkEC64Arg3 arcanine_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &arcanine_hd_gfxdata[0],
      { 0.0, 869.0629272460938, -392.8055114746094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &arcanine_hd_gfxdata[1],
      { 0.0, 171.77438354492188, 546.155517578125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_hd_gfxdata[2],
      { 0.0, 207.8206024169922, 346.15972900390625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &arcanine_hd_gfxdata[3],
      { 0.0, 118.42479705810547, 263.98248291015625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_hd_gfxdata[4],
      { 0.0, -313.7087707519531, -79.41708374023438 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_hd_gfxdata[5],
      { 307.91650390625, -323.72918701171875, 292.8978271484375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &arcanine_hd_gfxdata[6],
      { 19.820213317871094, -336.94281005859375, -94.69621276855469 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_hd_gfxdata[7],
      { -72.31950378417969, -393.18951416015625, -46.59190368652344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_hd_gfxdata[8],
      { -19.820213317871094, -39.004302978515625, -35.30380630493164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_hd_gfxdata[9],
      { -307.91650390625, -323.72918701171875, 292.8978271484375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &arcanine_hd_gfxdata[10],
      { -19.820213317871094, -336.94281005859375, -94.69621276855469 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_hd_gfxdata[11],
      { 72.31950378417969, -393.18951416015625, -46.59187698364258 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_hd_gfxdata[12],
      { 19.820213317871094, -39.004302978515625, -35.30380630493164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &arcanine_hd_gfxdata[13],
      { -45.853702545166016, 77.81362915039062, -110.39311981201172 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_hd_gfxdata[14],
      { 45.853702545166016, 592.7210083007812, -342.07049560546875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &arcanine_hd_gfxdata[15],
      { 182.38890075683594, -2.2025110721588135, 2.202296018600464 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_hd_gfxdata[16],
      { 50.209190368652344, -688.4297485351562, -206.26852416992188 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_hd_gfxdata[17],
      { 117.61109924316406, -438.85650634765625, -296.0333251953125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &arcanine_hd_gfxdata[18],
      { -182.38890075683594, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_hd_gfxdata[19],
      { -50.209190368652344, -688.4297485351562, -206.2684783935547 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_hd_gfxdata[20],
      { -117.61109924316406, -438.85650634765625, -296.0333251953125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
