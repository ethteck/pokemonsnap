#include "../tunnel.h"

extern Vtx tunnel_block0_vtx[];

#include "assets/tunnel/block0/draw.gfx.inc.c"
__ALIGNER
#include "assets/tunnel/block0/model.vtx.inc.c"
#include "assets/tunnel/block0/unk.gfx.inc.c"

UnkEC64Arg3 tunnel_block0_road[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 858.814, 0.075471, 249.95508 },
      { 0.0, 0.431968, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 129.92752, 0.391066, 443.83078 },
      { 0.0, 0.708441, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/tunnel/block0/movement.modelanim.inc.c"
