#include <common.h>

extern Gfx volcano_effect_part0_draw[];
extern Vtx volcano_effect_vtx[];

#include "assets/volcano/volcano_effect/first.gfx.inc.c"
#include "assets/volcano/volcano_effect/part0_draw.gfx.inc.c"
#include "assets/volcano/volcano_effect/part1_draw.gfx.inc.c"
#include "assets/volcano/volcano_effect/last.gfx.inc.c"
__ALIGNER
#include "assets/volcano/volcano_effect/model.vtx.inc.c"

DObjPayloadTypeC volcano_effect_gfxdata[] = {
    { 1, volcano_effect_first },
    { 4, NULL },
    { 1, volcano_effect_last },
    { 4, NULL },
};

UnkEC64Arg3 volcano_effect_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8193,
      &volcano_effect_gfxdata[0],
      { 0.0, -199.9999542236328, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.25, 0.5, 1.0 } },
    { 8193,
      &volcano_effect_gfxdata[2],
      { 0.0, -400.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
