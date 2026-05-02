#include "../tunnel.h"

extern u8 D_PAL_8014F3F8_1948C8[];
extern u8 D_PAL_8014F420_1948F0[];
extern u8 D_PAL_8014FC28_1950F8[];
extern u8 D_PAL_8014FC50_195120[];
extern u8 D_PAL_80151CE8_1971B8[];
extern u8 D_PAL_80151D10_1971E0[];
extern u8 D_PAL_80152978_197E48[];
extern u8 D_PAL_801529A0_197E70[];
extern u8 D_PAL_80153A38_198F08[];
extern u8 D_PAL_80153A60_198F30[];
extern u8 D_PAL_80158BA8_19E078[];
extern u8 D_PAL_80158BD0_19E0A0[];

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
