#include <common.h>

extern Vtx koffingSmoke_vtx[];

#include "assets/volcano/koffingSmoke/part1.gfx.inc.c"
#include "assets/volcano/koffingSmoke/part0.gfx.inc.c"
__ALIGNER
// file split here ??
#include "assets/volcano/koffingSmoke/model.vtx.inc.c"

DObjPayloadTypeC koffingSmoke_gfxdata[] = {
    { 1, koffingSmoke_part0 },
    { 4, NULL },
    { 0, koffingSmoke_part1 },
    { 4, NULL },
};

UnkEC64Arg3 koffingSmoke_model[] = {
    { 32768,
      &koffingSmoke_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32769,
      &koffingSmoke_gfxdata[2],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
