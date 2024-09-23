#include <common.h>

extern u8 gate_tex0_pal[];
extern u8 gate_tex1_pal[];
extern u8 gate_tex2_pal[];
extern u8 gate_tex0_png[];
extern u8 gate_tex1_png[];
extern u8 gate_tex2_png[];

extern Gfx gate_part0[];

#include "assets/world/model.vtx.inc.c"
#include "assets/world/first.gfx.inc.c"
#include "assets/world/part0.gfx.inc.c"
#include "assets/world/part1.gfx.inc.c"
#include "assets/world/part3.gfx.inc.c"
#include "assets/world/last.gfx.inc.c"
#include "assets/world/part2.gfx.inc.c"

DObjPayloadTypeC gate_gfxdata[] = {
    { 0, gate_first },
    { 4, NULL },
    { 0, gate_part1 },
    { 4, NULL },
    { 1, gate_part2 },
    { 4, NULL },
    { 0, gate_last },
    { 4, NULL },
};

UnkEC64Arg3 gate_model[] = {
    { 0,
      &gate_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &gate_gfxdata[2],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &gate_gfxdata[4],
      { 0.0, 449.2, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 0.02239 } },
    { 1,
      &gate_gfxdata[6],
      { 0.0, 528.6123, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
