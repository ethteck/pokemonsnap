#include "../tunnel.h"

extern Vtx tunnel_block4_vtx[];

#include "assets/tunnel/block4/draw.gfx.inc.c"
#include "assets/tunnel/block4/model.vtx.inc.c"
#include "assets/tunnel/block4/unk.gfx.inc.c"

UnkEC64Arg3 tunnel_block4_road[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 724.4631, 369.98047, -1918.183472 },
      { 0.122173, 0.349066, 0.0 },
      { 0.81, 1.0, 1.0 } },
    { 1,
      NULL,
      { 553.3895, 369.941437, -1874.550293 },
      { 0.087266, 0.174533, 0.0 },
      { 0.81, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/tunnel/block4/movement.modelanim.inc.c"
