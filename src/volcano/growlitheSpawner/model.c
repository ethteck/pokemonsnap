#include <common.h>

extern u8 growlitheSpawner_lava_frame0_pal[];

extern Vtx growlitheSpawner_vtx[];

#include "assets/volcano/growlitheSpawner/draw.gfx.inc.c"
__ALIGNER
// file split here ??
#include "assets/volcano/growlitheSpawner/model.vtx.inc.c"

UnkEC64Arg3 growlitheSpawner_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      growlitheSpawner_gfx,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
