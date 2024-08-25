#include <common.h>

extern u8 arcanine_tex0_png[];
extern u8 arcanine_tex1_png[];
extern u8 arcanine_tex2_png[];
extern u8 arcanine_tex3_png[];
extern u8 arcanine_tex4_png[];
extern u8 arcanine_tex5_png[];
extern u8 arcanine_tex6_png[];
extern u8 arcanine_tex7_png[];
extern u8 arcanine_tex8_var0_png[];
extern u8 arcanine_tex8_var1_png[];
extern u8 arcanine_tex8_var2_png[];
extern u8 arcanine_tex9_png[];
extern u8 arcanine_tex10_png[];
extern u8 arcanine_tex11_png[];
extern u8 arcanine_tex12_png[];
extern u8 arcanine_tex13_png[];
extern u8 arcanine_tex0_pal[];
extern u8 arcanine_tex1_pal[];
extern u8 arcanine_tex2_pal[];
extern u8 arcanine_tex3_pal[];
extern u8 arcanine_tex4_pal[];
extern u8 arcanine_tex5_pal[];
extern u8 arcanine_tex6_pal[];
extern u8 arcanine_tex7_pal[];
extern u8 arcanine_tex8_pal[];
extern u8 arcanine_tex9_pal[];
extern u8 arcanine_tex10_pal[];
extern u8 arcanine_tex11_pal[];
extern u8 arcanine_tex12_pal[];
extern u8 arcanine_tex13_pal[];

extern Texture* arcanine_part2_mat[];
extern Gfx arcanine_part0_draw[];

__ALIGNER
u8 arcanine_tex14_pal[] = {
#include "assets/volcano/arcanine/tex14.pal.bin.c"
};

__ALIGNER
u8 arcanine_tex14_png[] = {
#include "assets/volcano/arcanine/tex14.png.bin.c"
};

Texture** arcanine_materials[] = {
    NULL,
    NULL,
    NULL,
    arcanine_part2_mat,
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

u8* arcanine_part2_mat0_images[] = {
    arcanine_tex8_var0_png,
    arcanine_tex8_var1_png,
    arcanine_tex8_var2_png,
    NULL,
};

Texture arcanine_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    arcanine_part2_mat0_images,
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

Texture* arcanine_part2_mat[] = {
    &arcanine_part2_mat0,
    NULL,
};

#include "assets/volcano/arcanine/model.vtx.inc.c"

#include "assets/volcano/arcanine/first.gfx.inc.c"
#include "assets/volcano/arcanine/part0_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part0_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part0_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part1_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part1_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part1_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part1_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part1_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part1_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part2_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part2_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part2_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part2_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part2_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part2_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part3_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part3_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part3_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part4_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part4_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part4_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part5_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part5_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part5_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part5_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part5_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part5_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part6_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part6_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part6_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part7_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part7_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part7_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part8_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part8_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part8_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part9_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part9_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part9_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part9_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part9_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part9_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part10_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part10_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part10_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part11_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part11_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part11_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part12_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part12_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part12_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part13_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part13_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part13_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part14_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part14_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part14_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part15_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part15_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part15_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part15_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part15_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part15_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part16_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part16_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part16_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part16_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part16_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part16_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part17_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part17_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part17_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part17_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part17_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part17_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part18_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part18_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part18_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part18_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part18_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part18_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part19_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part19_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part19_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part19_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part19_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part19_draw.gfx.inc.c"
#include "assets/volcano/arcanine/part20_pre_near.gfx.inc.c"
#include "assets/volcano/arcanine/part20_pre_far.gfx.inc.c"
#include "assets/volcano/arcanine/part20_pre.gfx.inc.c"
#include "assets/volcano/arcanine/part20_draw_near.gfx.inc.c"
#include "assets/volcano/arcanine/part20_draw_far.gfx.inc.c"
#include "assets/volcano/arcanine/part20_draw.gfx.inc.c"
#include "assets/volcano/arcanine/last.gfx.inc.c"

DObjPayloadTypeI arcanine_gfxdata[] = {
    { NULL, arcanine_first },
    { arcanine_part1_pre, arcanine_part1_draw },
    { arcanine_part2_pre, arcanine_part2_draw },
    { NULL, arcanine_part3_draw },
    { NULL, arcanine_part4_draw },
    { arcanine_part5_pre, arcanine_part5_draw },
    { NULL, arcanine_part6_draw },
    { NULL, arcanine_part7_draw },
    { NULL, arcanine_part8_draw },
    { arcanine_part9_pre, arcanine_part9_draw },
    { NULL, arcanine_part10_draw },
    { NULL, arcanine_part11_draw },
    { NULL, arcanine_part12_draw },
    { NULL, arcanine_part13_draw },
    { NULL, arcanine_part14_draw },
    { arcanine_part15_pre, arcanine_part15_draw },
    { arcanine_part16_pre, arcanine_part16_draw },
    { arcanine_part17_pre, arcanine_part17_draw },
    { arcanine_part18_pre, arcanine_part18_draw },
    { arcanine_part19_pre, arcanine_part19_draw },
    { arcanine_part20_pre, arcanine_last },
};

UnkEC64Arg3 arcanine_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &arcanine_gfxdata[0],
      { 0.0, 869.0629272460938, -392.8055114746094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &arcanine_gfxdata[1],
      { 0.0, 171.77438354492188, 546.155517578125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_gfxdata[2],
      { 0.0, 207.8206024169922, 346.15972900390625 },
      { -0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &arcanine_gfxdata[3],
      { 0.0, 118.42479705810547, 263.98248291015625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_gfxdata[4],
      { 0.0, -313.7088623046875, -79.41712951660156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_gfxdata[5],
      { 307.91650390625, -323.72918701171875, 292.8978271484375 },
      { -0.26179900765419006, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &arcanine_gfxdata[6],
      { 19.820213317871094, -336.94281005859375, -94.69621276855469 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_gfxdata[7],
      { -72.31950378417969, -377.88330078125, -56.202125549316406 },
      { 0.26179900765419006, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_gfxdata[8],
      { -19.820213317871094, -39.004302978515625, -35.30380630493164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_gfxdata[9],
      { -307.91650390625, -323.72918701171875, 292.8978576660156 },
      { -0.26179900765419006, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &arcanine_gfxdata[10],
      { -19.820213317871094, -336.94281005859375, -94.69625854492188 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_gfxdata[11],
      { 72.31950378417969, -377.88311767578125, -56.20207977294922 },
      { 0.26179900765419006, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &arcanine_gfxdata[12],
      { 19.820213317871094, -39.004302978515625, -35.30380630493164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &arcanine_gfxdata[13],
      { -45.853702545166016, 77.81362915039062, -110.39311981201172 },
      { -0.785398006439209, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_gfxdata[14],
      { 45.853702545166016, 592.7210083007812, -342.07049560546875 },
      { -0.785398006439209, 0.26179900765419006, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &arcanine_gfxdata[15],
      { 182.38890075683594, -2.2025110721588135, 2.202296018600464 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_gfxdata[16],
      { 50.209190368652344, -688.4296875, -206.26849365234375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_gfxdata[17],
      { 117.61109924316406, -438.8564453125, -296.033203125 },
      { -0.34906598925590515, 0.26179900765419006, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &arcanine_gfxdata[18],
      { -182.38890075683594, -2.2025110721588135, 2.202296018600464 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_gfxdata[19],
      { -50.209190368652344, -688.4296875, -206.26844787597656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &arcanine_gfxdata[20],
      { -117.61109924316406, -438.8564453125, -296.033203125 },
      { -0.34906598925590515, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
