#include "../tunnel.h"

extern Vtx tunnel_block5_vtx[];

#include "assets/tunnel/block5/draw.gfx.inc.c"
#include "assets/tunnel/block5/model.vtx.inc.c"
#include "assets/tunnel/block5/unk.gfx.inc.c"

UnkEC64Arg3 tunnel_block5_road[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 1328.7618, 0.0, -733.55493 },
      { -0.011933, 1.570855, 0.0 },
      { 0.76, 1.0, 1.0 } },
    { 1,
      NULL,
      { 1336.6719, 0.0, -235.10347 },
      { -0.174616, 1.571921, 0.0 },
      { 0.76, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/tunnel/block5/movement.modelanim.inc.c"
