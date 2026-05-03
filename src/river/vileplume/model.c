#include "common.h"

extern u8 vileplume_tex_8017BEB8[];
extern u8 vileplume_tex_8017BEE0[];
extern u8 vileplume_tex_8017C110[];
extern u8 vileplume_tex_8017C318[];
extern u8 vileplume_tex_8017C340_png[];
extern u8 vileplume_tex_8017C548[];
extern u8 vileplume_tex_8017C570_png[];
extern u8 vileplume_tex_8017C778[];
extern u8 vileplume_tex_8017C7A0_png[];
extern u8 vileplume_tex_8017C9A8[];
extern u8 vileplume_tex_8017C9D0_png[];
extern u8 vileplume_tex_8017CBD8[];
extern u8 vileplume_tex_8017CBF8_png[];
extern u8 vileplume_tex_8017CE00[];
extern u8 vileplume_tex_8017CE28[];
extern u8 vileplume_tex_8017D058[];
extern u8 vileplume_tex_8017D288[];
extern u8 vileplume_tex_8017D4B8[];
extern u8 vileplume_tex_8017D6C0[];
extern u8 vileplume_tex_8017D6E8_png[];
extern u8 vileplume_tex_8017D8F0[];

extern Texture* vileplume_part1_mat[];
extern Texture* vileplume_part19_mat[];
extern Gfx vileplume_part0_draw[];

Texture** vileplume_materials[] = {
    NULL,
    vileplume_part1_mat,
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
    vileplume_part19_mat,
};

u8* vileplume_part1_mat0_textures[] = {
    vileplume_tex_8017BEE0,
    vileplume_tex_8017C110,
};

u8* vileplume_part1_mat1_textures[] = {
    vileplume_tex_8017CE28,
    vileplume_tex_8017D058,
    vileplume_tex_8017D288,
    vileplume_tex_8017D4B8,
};

Texture vileplume_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    vileplume_part1_mat0_textures,
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

Texture vileplume_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    vileplume_part1_mat1_textures,
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

Texture vileplume_part19_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    128,
    32,
    128,
    0,
    0.0,
    0.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0x20,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    32,
    64,
    32,
    128,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* vileplume_part1_mat[] = {
    &vileplume_part1_mat0,
    &vileplume_part1_mat1,
    NULL,
};

Texture* vileplume_part19_mat[] = {
    &vileplume_part19_mat0,
    NULL,
    NULL,
};

#include "assets/river/vileplume/model.vtx.inc.c"
#include "assets/river/vileplume/first.gfx.inc.c"
#include "assets/river/vileplume/part0_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part0_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part0_draw.gfx.inc.c"
#include "assets/river/vileplume/part1_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part1_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part1_draw.gfx.inc.c"
#include "assets/river/vileplume/part2_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part2_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part2_draw.gfx.inc.c"
#include "assets/river/vileplume/part3_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part3_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part3_draw.gfx.inc.c"
#include "assets/river/vileplume/part4_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part4_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part4_draw.gfx.inc.c"
#include "assets/river/vileplume/part5_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part5_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part5_draw.gfx.inc.c"
#include "assets/river/vileplume/part6_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part6_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part6_draw.gfx.inc.c"
#include "assets/river/vileplume/part7_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part7_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part7_draw.gfx.inc.c"
#include "assets/river/vileplume/part8_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part8_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part8_draw.gfx.inc.c"
#include "assets/river/vileplume/part9_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part9_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part9_draw.gfx.inc.c"
#include "assets/river/vileplume/part10_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part10_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part10_draw.gfx.inc.c"
#include "assets/river/vileplume/part11_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part11_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part11_draw.gfx.inc.c"
#include "assets/river/vileplume/part12_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part12_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part12_draw.gfx.inc.c"
#include "assets/river/vileplume/part13_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part13_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part13_draw.gfx.inc.c"
#include "assets/river/vileplume/part14_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part14_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part14_draw.gfx.inc.c"
#include "assets/river/vileplume/part15_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part15_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part15_draw.gfx.inc.c"
#include "assets/river/vileplume/part16_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part16_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part16_draw.gfx.inc.c"
#include "assets/river/vileplume/part17_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part17_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part17_draw.gfx.inc.c"
#include "assets/river/vileplume/last.gfx.inc.c"
#include "assets/river/vileplume/part18_draw_near.gfx.inc.c"
#include "assets/river/vileplume/part18_draw_far.gfx.inc.c"
#include "assets/river/vileplume/part18_draw.gfx.inc.c"

DObjPayloadTypeC vileplume_gfxdata[] = {
    { 0, vileplume_first },
    { 4, NULL },
    { 0, vileplume_part1_draw },
    { 4, NULL },
    { 0, vileplume_part2_draw },
    { 4, NULL },
    { 0, vileplume_part3_draw },
    { 4, NULL },
    { 0, vileplume_part4_draw },
    { 4, NULL },
    { 0, vileplume_part5_draw },
    { 4, NULL },
    { 0, vileplume_part6_draw },
    { 4, NULL },
    { 0, vileplume_part7_draw },
    { 4, NULL },
    { 0, vileplume_part8_draw },
    { 4, NULL },
    { 0, vileplume_part9_draw },
    { 4, NULL },
    { 0, vileplume_part10_draw },
    { 4, NULL },
    { 0, vileplume_part11_draw },
    { 4, NULL },
    { 0, vileplume_part12_draw },
    { 4, NULL },
    { 0, vileplume_part13_draw },
    { 4, NULL },
    { 0, vileplume_part14_draw },
    { 4, NULL },
    { 0, vileplume_part15_draw },
    { 4, NULL },
    { 0, vileplume_part16_draw },
    { 4, NULL },
    { 0, vileplume_last },
    { 4, NULL },
    { 1, vileplume_part18_draw },
    { 4, NULL },
};

UnkEC64Arg3 vileplume_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &vileplume_gfxdata[0],
      { 9.999999747378752e-05, 539.0181884765625, 3.341399908065796 },
      { 0.13600000739097595, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[2],
      { -1.5537259578704834, 414.42999267578125, 155.26153564453125 },
      { -0.031279999762773514, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_gfxdata[4],
      { 0.0, -0.00076299998909235, 411.899658203125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[6],
      { 181.72207641601562, 410.74072265625, 36.98261260986328 },
      { -0.1512259989976883, 1.3616770505905151, -0.14798299968242645 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_gfxdata[8],
      { -36.423828125, 0.0008580000139772892, 477.7024230957031 },
      { 0.0, -0.07781500369310379, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[10],
      { 161.2196044921875, 404.12200927734375, -174.40231323242188 },
      { 0.044863998889923096, 2.3425049781799316, 0.03216499835252762 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_gfxdata[12],
      { 14.860153198242188, 0.0, 514.2706909179688 },
      { 0.0, -0.12370800226926804, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[14],
      { -72.71442413330078, 403.75, -186.21136474609375 },
      { 0.032607000321149826, 3.427845001220703, -0.009209999814629555 },
      { 1.0, 1.0, 1.0000009536743164 } },
    { 3,
      &vileplume_gfxdata[16],
      { -19.492530822753906, 0.002002999885007739, 501.7187194824219 },
      { 0.0, 6.283185005187988, 0.0 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 2,
      &vileplume_gfxdata[18],
      { -150.20713806152344, 410.90435791015625, 42.35533905029297 },
      { -2.355736017227173, -1.5265820026397705, 2.3561809062957764 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_gfxdata[20],
      { 15.380996704101562, -0.029944999143481255, 491.90081787109375 },
      { 5.400000009103678e-05, -1.9999999949504854e-06, 1.9999999949504854e-06 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[22],
      { 310.8894348144531, 12.595319747924805, 2.712578058242798 },
      { -0.031279999762773514, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[24],
      { -310.8896179199219, 12.595081329345703, 2.7126190662384033 },
      { 0.031279999762773514, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[26],
      { 180.71804809570312, -179.30653381347656, -29.776769638061523 },
      { -0.21407300233840942, 0.4908030033111572, -0.013470999896526337 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_gfxdata[28],
      { 12.021254539489746, -298.2330322265625, 2.057666063308716 },
      { 0.012004000134766102, 0.007984000258147717, 0.00021499999274965376 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[30],
      { -180.71823120117188, -179.30653381347656, -29.776769638061523 },
      { 0.21407300233840942, 2.650789976119995, 0.013470999896526337 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_gfxdata[32],
      { 12.021254539489746, -298.2330322265625, -2.0576601028442383 },
      { -0.012004000134766102, -0.007984000258147717, 0.00021499999274965376 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_gfxdata[34],
      { 0.0, 383.560791015625, -9.253483772277832 },
      { -0.03400000184774399, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8195,
      &vileplume_gfxdata[36],
      { -9.999999747378752e-05, -920.2105712890625, 47.770225524902344 },
      { -0.10199999809265137, 0.0, 0.0 },
      { 1.0, 1.0, 1.3253999948501587 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
