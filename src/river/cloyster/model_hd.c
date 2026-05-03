#include "common.h"

extern u8 cloyster_tex_80170538[];
extern u8 cloyster_tex_80170550_png[];
extern u8 cloyster_tex_80170758[];
extern u8 cloyster_tex_80170780_png[];
extern u8 cloyster_tex_80170B88[];
extern u8 cloyster_tex_80170BB0_png[];
extern u8 cloyster_tex_80170DB8[];
extern u8 cloyster_tex_80170DE0_png[];
extern u8 cloyster_tex_801711E8[];
extern u8 cloyster_tex_80171210_png[];
extern u8 cloyster_tex_80171318[];
extern u8 cloyster_tex_80171340_png[];
extern u8 cloyster_tex_80171388[];
extern u8 cloyster_tex_801713D0[];
extern u8 cloyster_tex_80171418[];
extern u8 cloyster_tex_80171440_png[];

extern Gfx cloyster_hd_part0_draw[];

#include "assets/river/cloyster/hd_model.vtx.inc.c"
#include "assets/river/cloyster/hd_first.gfx.inc.c"
#include "assets/river/cloyster/hd_part0_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part1_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part2_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part3_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part4_draw.gfx.inc.c"
#include "assets/river/cloyster/hd_part5_draw.gfx.inc.c"

UnkEC64Arg3 cloyster_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 1246.9437255859375, 0.0 },
      { 0.10306400060653687, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_first,
      { 0.0, 103.96995544433594, 311.5775146484375 },
      { 0.03089199960231781, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_part1_draw,
      { 0.0, 23.198890686035156, -587.8619384765625 },
      { 0.0, 0.22689299285411835, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_part2_draw,
      { 0.0, 23.198890686035156, -587.8619384765625 },
      { 0.0, 2.9147000312805176, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_part3_draw,
      { 0.0, 428.43121337890625, 232.9755859375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_hd_part4_draw,
      { 1.5999999959603883e-05, 547.4850463867188, -33.62914276123047 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      cloyster_hd_part5_draw,
      { 3.600000127335079e-05, 0.0, -2.4000000848900527e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0920000076293945, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
