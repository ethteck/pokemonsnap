#include <common.h>

extern u8 evolution_controller_tex0_png[];
extern u8 evolution_controller_tex1_png[];

extern Gfx evolution_controller_part0[];

#include "assets/world/evolution_controller/model.vtx.inc.c"
#include "assets/world/evolution_controller/first.gfx.inc.c"
#include "assets/world/evolution_controller/part0.gfx.inc.c"
#include "assets/world/evolution_controller/part1.gfx.inc.c"
#include "assets/world/evolution_controller/part2.gfx.inc.c"
#include "assets/world/evolution_controller/part3.gfx.inc.c"
#include "assets/world/evolution_controller/part4.gfx.inc.c"
#include "assets/world/evolution_controller/part5.gfx.inc.c"
#include "assets/world/evolution_controller/last.gfx.inc.c"

DObjPayloadTypeC evolution_controller_gfxdata[] = {
    { 1, evolution_controller_first },
    { 4, NULL },
    { 1, evolution_controller_part1 },
    { 4, NULL },
    { 1, evolution_controller_part2 },
    { 4, NULL },
    { 1, evolution_controller_part3 },
    { 4, NULL },
    { 1, evolution_controller_part4 },
    { 4, NULL },
    { 1, evolution_controller_last },
    { 4, NULL },
};

UnkEC64Arg3 evolution_controller_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &evolution_controller_gfxdata[0],
      { 0.0, -510.0001, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &evolution_controller_gfxdata[2],
      { 0.0, 0.0, 0.0 },
      { 0.0, 6.283185, 0.0 },
      { 0.25, 1.0, 0.25 } },
    { 1,
      &evolution_controller_gfxdata[4],
      { 0.0, 250.0, 0.0 },
      { 0.0, 6.283185, 0.0 },
      { 5.0, 2.0, 5.0 } },
    { 1,
      &evolution_controller_gfxdata[6],
      { 0.0, 250.0, 0.0 },
      { 0.0, 6.283185, 0.0 },
      { 5.0, 2.0, 5.0 } },
    { 1,
      &evolution_controller_gfxdata[8],
      { 0.0, 0.0, 0.0 },
      { 0.0, -6.283185, 0.0 },
      { 2.0, 1.0, 2.0 } },
    { 2,
      &evolution_controller_gfxdata[10],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
