#include "common.h"

extern u8 psyduck_tex_80160A28[];
extern u8 psyduck_tex_80160A50_png[];
extern u8 psyduck_tex_80160E58[];
extern u8 psyduck_tex_80161060_png[];
extern u8 psyduck_tex_80161468[];
extern u8 psyduck_tex_80161670_png[];
extern u8 psyduck_tex_80161E78[];
extern u8 psyduck_tex_80162080_png[];

extern Gfx psyduck_part0_draw[];

#include "assets/river/psyduck/model.vtx.inc.c"
#include "assets/river/psyduck/first.gfx.inc.c"
#include "assets/river/psyduck/part0_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part0_draw.gfx.inc.c"
#include "assets/river/psyduck/part1_pre_near.gfx.inc.c"
#include "assets/river/psyduck/part1_pre.gfx.inc.c"
#include "assets/river/psyduck/part1_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part1_draw.gfx.inc.c"
#include "assets/river/psyduck/part2_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part2_draw.gfx.inc.c"
#include "assets/river/psyduck/part3_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part3_draw.gfx.inc.c"
#include "assets/river/psyduck/part4_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part4_draw.gfx.inc.c"
#include "assets/river/psyduck/part5_pre_near.gfx.inc.c"
#include "assets/river/psyduck/part5_pre.gfx.inc.c"
#include "assets/river/psyduck/part5_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part5_draw.gfx.inc.c"
#include "assets/river/psyduck/part6_pre_near.gfx.inc.c"
#include "assets/river/psyduck/part6_pre.gfx.inc.c"
#include "assets/river/psyduck/part6_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part6_draw.gfx.inc.c"
#include "assets/river/psyduck/part7_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part7_draw.gfx.inc.c"
#include "assets/river/psyduck/part8_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part8_draw.gfx.inc.c"
#include "assets/river/psyduck/part9_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part9_draw.gfx.inc.c"
#include "assets/river/psyduck/part10_pre_near.gfx.inc.c"
#include "assets/river/psyduck/part10_pre.gfx.inc.c"
#include "assets/river/psyduck/part10_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part10_draw.gfx.inc.c"
#include "assets/river/psyduck/part11_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part11_draw.gfx.inc.c"
#include "assets/river/psyduck/part12_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part12_draw.gfx.inc.c"
#include "assets/river/psyduck/part13_pre_near.gfx.inc.c"
#include "assets/river/psyduck/part13_pre.gfx.inc.c"
#include "assets/river/psyduck/part13_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part13_draw.gfx.inc.c"
#include "assets/river/psyduck/part14_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part14_draw.gfx.inc.c"
#include "assets/river/psyduck/part15_draw_near.gfx.inc.c"
#include "assets/river/psyduck/part15_draw.gfx.inc.c"
#include "assets/river/psyduck/last.gfx.inc.c"

DObjPayloadTypeI psyduck_gfxdata[] = {
    { NULL, psyduck_first },
    { psyduck_part1_pre, psyduck_part1_draw },
    { NULL, psyduck_part2_draw },
    { NULL, psyduck_part3_draw },
    { NULL, psyduck_part4_draw },
    { psyduck_part5_pre, psyduck_part5_draw },
    { psyduck_part6_pre, psyduck_part6_draw },
    { NULL, psyduck_part7_draw },
    { NULL, psyduck_part8_draw },
    { NULL, psyduck_part9_draw },
    { psyduck_part10_pre, psyduck_part10_draw },
    { NULL, psyduck_part11_draw },
    { NULL, psyduck_part12_draw },
    { psyduck_part13_pre, psyduck_part13_draw },
    { NULL, psyduck_part14_draw },
    { NULL, psyduck_last },
};

UnkEC64Arg3 psyduck_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &psyduck_gfxdata[0],
      { 0.0008459999808110297, 169.3431854248047, 7.938241958618164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &psyduck_gfxdata[1],
      { -9.000000318337698e-06, 17.655515670776367, -247.0369110107422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &psyduck_gfxdata[2],
      { -0.60732102394104, 1.3824939727783203, -163.3826904296875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { -0.0008459999808110297, -169.3431854248047, -7.938241958618164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &psyduck_gfxdata[3],
      { 129.9991455078125, -115.96991729736328, -30.938243865966797 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &psyduck_gfxdata[4],
      { -130.00083923339844, -115.96991729736328, -30.938243865966797 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &psyduck_gfxdata[5],
      { 0.0, 99.60861206054688, 9.214317321777344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &psyduck_gfxdata[6],
      { -0.0008290000259876251, 237.31021118164062, -45.80890655517578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &psyduck_gfxdata[7],
      { 3.199999991920777e-05, 269.7709045410156, -12.745001792907715 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &psyduck_gfxdata[8],
      { 2.4000000848900527e-05, 84.42020416259766, 208.39944458007812 },
      { -0.13999900221824646, 0.0, 0.0 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 5,
      &psyduck_gfxdata[9],
      { 2.4000000848900527e-05, -44.44489288330078, -51.49443054199219 },
      { 0.14000099897384644, 0.0, 0.0 },
      { 1.0, 0.9999949932098389, 0.9999949932098389 } },
    { 3,
      &psyduck_gfxdata[10],
      { 203.55825805664062, 160.38351440429688, -52.84589385986328 },
      { 0.0, 0.0, 0.2199999988079071 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &psyduck_gfxdata[11],
      { 122.421142578125, -15.046381950378418, -6.5919880867004395 },
      { 0.0, 0.0, 0.07000000029802322 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &psyduck_gfxdata[12],
      { 158.56199645996094, -7.858275890350342, 5.992317199707031 },
      { 0.0, 0.0, -0.029999999329447746 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 3,
      &psyduck_gfxdata[13],
      { -204.93450927734375, 160.38331604003906, -52.84596633911133 },
      { 0.0, 0.0, -0.25999999046325684 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &psyduck_gfxdata[14],
      { -121.72291564941406, -19.930004119873047, -6.592001914978027 },
      { 0.0, 0.0, -0.029999999329447746 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &psyduck_gfxdata[15],
      { -150.65036010742188, -5.497264862060547, 5.992301940917969 },
      { 0.0, 0.0, 0.05000000074505806 },
      { 1.0, 0.9999989867210388, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
