#include "common.h"

extern u8 shellder_tex_80181D18[];
extern u8 shellder_tex_80181D40_png[];
extern u8 shellder_tex_80181F48[];
extern u8 shellder_tex_80182150[];
extern u8 shellder_tex_80182178_png[];

extern Gfx shellder_part0_draw[];

#include "assets/river/shellder/model.vtx.inc.c"
#include "assets/river/shellder/first.gfx.inc.c"
#include "assets/river/shellder/part0_draw_near.gfx.inc.c"
#include "assets/river/shellder/part0_draw.gfx.inc.c"
#include "assets/river/shellder/part1_draw_near.gfx.inc.c"
#include "assets/river/shellder/part1_draw.gfx.inc.c"
#include "assets/river/shellder/part2_draw_near.gfx.inc.c"
#include "assets/river/shellder/part2_draw.gfx.inc.c"
#include "assets/river/shellder/part3_draw_near.gfx.inc.c"
#include "assets/river/shellder/part3_draw.gfx.inc.c"
#include "assets/river/shellder/part4_draw_near.gfx.inc.c"
#include "assets/river/shellder/part4_draw.gfx.inc.c"
#include "assets/river/shellder/part5_draw_near.gfx.inc.c"
#include "assets/river/shellder/part5_draw.gfx.inc.c"
#include "assets/river/shellder/part6_draw_near.gfx.inc.c"
#include "assets/river/shellder/part6_draw.gfx.inc.c"
#include "assets/river/shellder/last.gfx.inc.c"

UnkEC64Arg3 shellder_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      shellder_first,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      shellder_part1_draw,
      { 0.0, 149.99998474121094, 30.000001907348633 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 0.9999979734420776 } },
    { 3,
      shellder_part2_draw,
      { 0.0, -14.55533504486084, 121.25611114501953 },
      { 0.24835500121116638, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999979734420776, 1.0 } },
    { 4,
      shellder_part3_draw,
      { -0.016891999170184135, -6.486690044403076, 75.96707153320312 },
      { 0.05739400163292885, 0.0, 0.0 },
      { 1.0, 1.0000020265579224, 1.0000009536743164 } },
    { 5,
      shellder_part4_draw,
      { 0.016891000792384148, -8.125031471252441, 77.00171661376953 },
      { 0.1305920034646988, 0.0, 0.0 },
      { 1.0, 0.9999960064888, 0.9999970197677612 } },
    { 6,
      shellder_part5_draw,
      { 0.0, -15.441333770751953, 73.78752136230469 },
      { 0.1152300015091896, 0.0, 0.0 },
      { 0.9999979734420776, 0.9999970197677612, 0.9999960064888 } },
    { 2,
      shellder_last,
      { 0.0, 94.99999237060547, -110.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999979734420776, 0.9999979734420776 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
