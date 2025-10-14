#include "common.h"

extern u8 psyduck_tex_80160A28[];
extern u8 psyduck_tex_80160A50_png[];
extern u8 psyduck_tex_80160E58[];
extern u8 psyduck_tex_80161060_png[];
extern u8 psyduck_tex_80161468[];
extern u8 psyduck_tex_80161670_png[];
extern u8 psyduck_tex_80161E78[];
extern u8 psyduck_tex_80162080_png[];

extern Gfx psyduck_hd_part0_draw[];

#include "assets/river/psyduck/hd_model.vtx.inc.c"
#include "assets/river/psyduck/hd_first.gfx.inc.c"
#include "assets/river/psyduck/hd_part0_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part1_pre.gfx.inc.c"
#include "assets/river/psyduck/hd_part1_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part2_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part3_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part4_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part5_pre.gfx.inc.c"
#include "assets/river/psyduck/hd_part5_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part6_pre.gfx.inc.c"
#include "assets/river/psyduck/hd_part6_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part7_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part8_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part9_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part10_pre.gfx.inc.c"
#include "assets/river/psyduck/hd_part10_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part11_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part12_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part13_pre.gfx.inc.c"
#include "assets/river/psyduck/hd_part13_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part14_draw.gfx.inc.c"
#include "assets/river/psyduck/hd_part15_draw.gfx.inc.c"

DObjPayloadTypeI psyduck_hd_gfxdata[] = {
    { NULL, psyduck_hd_first },
    { psyduck_hd_part1_pre, psyduck_hd_part1_draw },
    { NULL, psyduck_hd_part2_draw },
    { NULL, psyduck_hd_part3_draw },
    { NULL, psyduck_hd_part4_draw },
    { psyduck_hd_part5_pre, psyduck_hd_part5_draw },
    { psyduck_hd_part6_pre, psyduck_hd_part6_draw },
    { NULL, psyduck_hd_part7_draw },
    { NULL, psyduck_hd_part8_draw },
    { NULL, psyduck_hd_part9_draw },
    { psyduck_hd_part10_pre, psyduck_hd_part10_draw },
    { NULL, psyduck_hd_part11_draw },
    { NULL, psyduck_hd_part12_draw },
    { psyduck_hd_part13_pre, psyduck_hd_part13_draw },
    { NULL, psyduck_hd_part14_draw },
    { NULL, psyduck_hd_part15_draw },
};

UnkEC64Arg3 psyduck_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &psyduck_hd_gfxdata[0],
      { 0.0008459999808110297, 169.3431854248047, 7.938241958618164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &psyduck_hd_gfxdata[1],
      { -9.000000318337698e-06, 17.655515670776367, -248.52374267578125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &psyduck_hd_gfxdata[2],
      { -0.60732102394104, 1.3824939727783203, -160.4215850830078 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { -0.0008459999808110297, -169.3431854248047, -7.938241958618164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &psyduck_hd_gfxdata[3],
      { 129.9991455078125, -127.12538146972656, -30.938243865966797 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &psyduck_hd_gfxdata[4],
      { -130.00083923339844, -127.12538146972656, -30.938243865966797 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &psyduck_hd_gfxdata[5],
      { 0.0, 99.60861206054688, 9.214317321777344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &psyduck_hd_gfxdata[6],
      { -0.0008290000259876251, 237.31021118164062, -45.80890655517578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &psyduck_hd_gfxdata[7],
      { 3.199999991920777e-05, 269.7709045410156, -12.745001792907715 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &psyduck_hd_gfxdata[8],
      { 2.4000000848900527e-05, 84.42020416259766, 208.39944458007812 },
      { 0.0200009997934103, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &psyduck_hd_gfxdata[9],
      { 2.4000000848900527e-05, -52.080963134765625, -43.75619888305664 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 0.9999979734420776, 0.9999979734420776 } },
    { 3,
      &psyduck_hd_gfxdata[10],
      { 203.55825805664062, 160.38351440429688, -52.84589385986328 },
      { 0.0, 0.0, 0.2199999988079071 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &psyduck_hd_gfxdata[11],
      { 122.421142578125, -15.046381950378418, -6.5919880867004395 },
      { 0.0, 0.0, 0.07000000029802322 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &psyduck_hd_gfxdata[12],
      { 158.5621795654297, -7.858372211456299, 5.992301940917969 },
      { 0.0, 0.0, -0.029999999329447746 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &psyduck_hd_gfxdata[13],
      { -204.93450927734375, 160.38331604003906, -52.84596633911133 },
      { 0.0, 0.0, -0.25999999046325684 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &psyduck_hd_gfxdata[14],
      { -121.72291564941406, -19.930004119873047, -6.592001914978027 },
      { 0.0, 0.0, -0.029999999329447746 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &psyduck_hd_gfxdata[15],
      { -150.65040588378906, -5.497169017791748, 5.992290019989014 },
      { 0.0, 0.0, 0.05000000074505806 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
