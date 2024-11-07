#include "../tunnel.h"

extern Vtx tunnel_block3_vtx[];

#include "assets/tunnel/block3/draw.gfx.inc.c"
__ALIGNER
#include "assets/tunnel/block3/model.vtx.inc.c"
#include "assets/tunnel/block3/unk.gfx.inc.c"

UnkEC64Arg3 tunnel_block3_road[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 1242.781494, 396.164062, 893.078796 },
      { 0.000111, -0.442346, 0.0 },
      { 0.81, 1.0, 1.0 } },
    { 1,
      NULL,
      { 703.802429, 399.969086, 804.614441 },
      { 0.000088, -0.195363, 0.0 },
      { 0.81, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/tunnel/block3/movement.modelanim.inc.c"
