#include "../tunnel.h"

extern u8 D_PAL_8014F3F8_1948C8[];
extern u8 D_PAL_8014F420_1948F0[];
extern u8 D_PAL_8014FC28_1950F8[];
extern u8 D_PAL_8014FC50_195120[];
extern u8 D_PAL_80150C88_196158[];
extern u8 D_PAL_80150CB0_196180[];
extern u8 D_PAL_80158BA8_19E078[];
extern u8 D_PAL_80158BD0_19E0A0[];

extern Vtx tunnel_block1_vtx[];

#include "assets/tunnel/block1/draw.gfx.inc.c"
__ALIGNER
#include "assets/tunnel/block1/model.vtx.inc.c"
#include "assets/tunnel/block1/unk.gfx.inc.c"

UnkEC64Arg3 tunnel_block1_road[] = {
    { 0,
      NULL,
      { 0.0, 0.0, -0.000381 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 87.49997, 0.000010, -1902.5 },
      { 0.0, -0.349066, 0.0 },
      { 1.2, 1.0, 1.0 } },
    { 1,
      NULL,
      { -37.499966, 0.000010, -1967.4995 },
      { 0.0, -0.296706, 0.0 },
      { 1.2, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/tunnel/block1/movement.modelanim.inc.c"
