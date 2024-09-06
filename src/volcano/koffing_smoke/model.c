#include <common.h>

extern Vtx koffing_smoke_vtx[];

#include "assets/volcano/koffing_smoke/part1.gfx.inc.c"
#include "assets/volcano/koffing_smoke/part0.gfx.inc.c"
__ALIGNER
// file split here ??
#include "assets/volcano/koffing_smoke/model.vtx.inc.c"

DObjPayloadTypeC koffing_smoke_gfxdata[] = {
    { 1, koffing_smoke_part0 },
    { 4, NULL },
    { 0, koffing_smoke_part1 },
    { 4, NULL },
};

UnkEC64Arg3 koffing_smoke_model[] = {
    { 32768,
      &koffing_smoke_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32769,
      &koffing_smoke_gfxdata[2],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
