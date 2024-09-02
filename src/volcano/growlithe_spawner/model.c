#include <common.h>

extern u8 growlithe_spawner_lava_frame0_pal[];

extern Vtx growlithe_spawner_vtx[];

#include "assets/volcano/growlithe_spawner/draw.gfx.inc.c"
__ALIGNER // file split here ??
#include "assets/volcano/growlithe_spawner/model.vtx.inc.c"

UnkEC64Arg3 growlithe_spawner_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      growlithe_spawner_gfx,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 }
    },
};
