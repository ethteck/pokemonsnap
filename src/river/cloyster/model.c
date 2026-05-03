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

extern Gfx cloyster_part0_draw[];

#include "assets/river/cloyster/model.vtx.inc.c"
#include "assets/river/cloyster/first.gfx.inc.c"
#include "assets/river/cloyster/part0_draw_near.gfx.inc.c"
#include "assets/river/cloyster/part0_draw.gfx.inc.c"
#include "assets/river/cloyster/part1_draw_near.gfx.inc.c"
#include "assets/river/cloyster/part1_draw.gfx.inc.c"
#include "assets/river/cloyster/part2_draw_near.gfx.inc.c"
#include "assets/river/cloyster/part2_draw.gfx.inc.c"
#include "assets/river/cloyster/part3_draw_near.gfx.inc.c"
#include "assets/river/cloyster/part3_draw.gfx.inc.c"
#include "assets/river/cloyster/part4_draw_near.gfx.inc.c"
#include "assets/river/cloyster/part4_draw.gfx.inc.c"
#include "assets/river/cloyster/part5_draw_near.gfx.inc.c"
#include "assets/river/cloyster/part5_draw.gfx.inc.c"
#include "assets/river/cloyster/last.gfx.inc.c"

UnkEC64Arg3 cloyster_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 750.0, 0.0 },
      { 0.10306400060653687, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_first,
      { 0.0, 103.96995544433594, 311.5775146484375 },
      { 0.03089199960231781, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_part1_draw,
      { 0.0, 23.198890686035156, -587.8619384765625 },
      { 0.0, 0.22689299285411835, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_part2_draw,
      { 0.0, 23.198890686035156, -587.8619384765625 },
      { 0.0, 2.9147000312805176, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_part3_draw,
      { 0.0, 415.43035888671875, 234.3208770751953 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      cloyster_part4_draw,
      { 1.5999999959603883e-05, 547.4850463867188, -33.62914276123047 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      cloyster_last,
      { -3.600000127335079e-05, 0.0020979999098926783, 8.299999899463728e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0920000076293945, 0.9999989867210388, 0.9999989867210388 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
