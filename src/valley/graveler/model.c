#include "common.h"

extern u8 graveler_tex_8012F0F8[];
extern u8 graveler_tex_8012F118_png[];
extern u8 graveler_tex_8012F320[];
extern u8 graveler_tex_8012F370_png[];
extern u8 graveler_tex_8012FB78[];
extern u8 graveler_tex_8012FBA0[];
extern u8 graveler_tex_8012FDD0[];

extern Texture* graveler_part1_mat[];
extern Gfx graveler_part0_draw[];

Texture** graveler_materials[] = {
    NULL,
    graveler_part1_mat,
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

u8* graveler_part1_mat0_textures[] = {
    graveler_tex_8012FBA0,
    graveler_tex_8012FDD0,
    NULL,
};

Texture graveler_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    graveler_part1_mat0_textures,
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
    139781,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* graveler_part1_mat[] = {
    &graveler_part1_mat0,
    NULL,
};

#include "assets/valley/graveler/model.vtx.inc.c"
#include "assets/valley/graveler/first.gfx.inc.c"
#include "assets/valley/graveler/part0_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part0_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part0_draw.gfx.inc.c"
#include "assets/valley/graveler/part1_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part1_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part1_draw.gfx.inc.c"
#include "assets/valley/graveler/part2_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part2_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part2_draw.gfx.inc.c"
#include "assets/valley/graveler/part3_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part3_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part3_draw.gfx.inc.c"
#include "assets/valley/graveler/part4_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part4_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part4_draw.gfx.inc.c"
#include "assets/valley/graveler/part5_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part5_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part5_draw.gfx.inc.c"
#include "assets/valley/graveler/part6_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part6_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part6_draw.gfx.inc.c"
#include "assets/valley/graveler/part7_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part7_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part7_draw.gfx.inc.c"
#include "assets/valley/graveler/part8_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part8_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part8_draw.gfx.inc.c"
#include "assets/valley/graveler/part9_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part9_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part9_draw.gfx.inc.c"
#include "assets/valley/graveler/part10_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part10_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part10_draw.gfx.inc.c"
#include "assets/valley/graveler/part11_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part11_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part11_draw.gfx.inc.c"
#include "assets/valley/graveler/part12_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part12_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part12_draw.gfx.inc.c"
#include "assets/valley/graveler/part13_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part13_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part13_draw.gfx.inc.c"
#include "assets/valley/graveler/part14_draw_near.gfx.inc.c"
#include "assets/valley/graveler/part14_draw_far.gfx.inc.c"
#include "assets/valley/graveler/part14_draw.gfx.inc.c"
#include "assets/valley/graveler/last.gfx.inc.c"

UnkEC64Arg3 graveler_model[] = {
    { 0,
      NULL,
      { 0.0, -23.583364486694336, 0.0 },
      { 0.0, 0.0, 9.999999974752427e-07 },
      { 0.9999989867210388, 1.0000009536743164, 1.0000009536743164 } },
    { 1,
      graveler_first,
      { -9.40000027185306e-05, 558.0011596679688, -6.901059150695801 },
      { 0.6890659928321838, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      graveler_part1_draw,
      { 406.5003967285156, 17.66519546508789, 174.40945434570312 },
      { -2.925391912460327, 1.3439290523529053, -4.551601886749268 },
      { 0.9999989867210388, 0.9999989867210388, 1.0 } },
    { 3,
      graveler_part2_draw,
      { -6.5146918296813965, 225.59327697753906, -17.40182113647461 },
      { 1.3474249839782715, 3.1415929794311523, 3.1415929794311523 },
      { 1.0, 1.0000009536743164, 0.9999979734420776 } },
    { 4,
      graveler_part3_draw,
      { -18.944740295410156, 251.58514404296875, -3.7335870265960693 },
      { 2.8956100940704346, -0.9331849813461304, -2.5404229164123535 },
      { 1.0, 1.0000020265579224, 0.9999989867210388 } },
    { 2,
      graveler_part4_draw,
      { -406.50201416015625, 17.664432525634766, 174.4095458984375 },
      { 0.3528429865837097, 4.130260944366455, 0.9898849725723267 },
      { 1.0, 0.9999989867210388, 1.0 } },
    { 3,
      graveler_part5_draw,
      { 6.514310836791992, 225.59323120117188, -17.401784896850586 },
      { 1.6720860004425049, -3.1415929794311523, 3.1415929794311523 },
      { 1.0, 1.0000009536743164, 0.9999979734420776 } },
    { 4,
      graveler_part6_draw,
      { 18.944787979125977, 251.58514404296875, -3.7333970069885254 },
      { 2.876246929168701, 0.8550289869308472, 2.937580108642578 },
      { 0.9999979734420776, 1.0000020265579224, 1.0 } },
    { 2,
      graveler_part7_draw,
      { 365.9995422363281, -178.71551513671875, 270.0173034667969 },
      { 3.7428910732269287, -2.9380059242248535, -1.2931230068206787 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      graveler_part8_draw,
      { -0.0003100000030826777, 211.14883422851562, 0.0005249999812804163 },
      { -0.06457100063562393, -0.2254830002784729, 0.10849899798631668 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      graveler_part9_draw,
      { -365.9995422363281, -178.7156524658203, 270.01751708984375 },
      { 0.6028029918670654, 0.4126949906349182, -1.7411680221557617 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      graveler_part10_draw,
      { -4.8000001697801054e-05, 211.1488037109375, 0.0002859999949578196 },
      { -0.09585300087928772, 0.034928999841213226, 0.07976999878883362 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 2,
      graveler_part11_draw,
      { 180.8939666748047, -228.2956085205078, 48.09565734863281 },
      { -0.6890659928321838, 3.1415929794311523, 3.1415929794311523 },
      { 0.9999989867210388, 0.9999989867210388, 1.0 } },
    { 3,
      graveler_part12_draw,
      { 16.006183624267578, 271.0434875488281, 84.580322265625 },
      { 3.151592969894409, 3.1415929794311523, 3.1415929794311523 },
      { 1.0, 0.9999920129776001, 1.0 } },
    { 2,
      graveler_part13_draw,
      { -180.89083862304688, -228.3061981201172, 48.119140625 },
      { -0.6926550269126892, 3.1415929794311523, -3.1415929794311523 },
      { 0.9999989867210388, 0.9999989867210388, 1.0 } },
    { 3,
      graveler_last,
      { -16.00997543334961, 271.0249938964844, 84.59912109375 },
      { 0.020235000178217888, -6.283185005187988, 0.0 },
      { 1.0, 0.999983012676239, 1.0 } },
    { 1,
      NULL,
      { 0.0003000000142492354, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0000009536743164, 1.0, 0.9999989867210388 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
