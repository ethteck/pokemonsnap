#include <common.h>

extern Gfx lava_splash_part0_draw[];
extern Vtx lava_splash_vtx[];

#include "assets/volcano/lava_splash/first.gfx.inc.c"
#include "assets/volcano/lava_splash/part0_draw.gfx.inc.c"
#include "assets/volcano/lava_splash/part1_draw.gfx.inc.c"
#include "assets/volcano/lava_splash/last.gfx.inc.c"
__ALIGNER
#include "assets/volcano/lava_splash/model.vtx.inc.c"

DObjPayloadTypeC lava_splash_gfxdata[] = {
    { 1, lava_splash_first },
    { 4, NULL },
    { 1, lava_splash_last },
    { 4, NULL },
};

UnkEC64Arg3 lava_splash_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8193,
      &lava_splash_gfxdata[0],
      { 0.0, -199.9999542236328, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.25, 0.5, 1.0 } },
    { 8193,
      &lava_splash_gfxdata[2],
      { 0.0, -400.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
