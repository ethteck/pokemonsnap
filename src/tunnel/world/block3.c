#include "../tunnel.h"

extern u8 D_PAL_8014F3F8_1948C8[];
extern u8 D_PAL_8014F420_1948F0[];
extern u8 D_PAL_8014FC28_1950F8[];
extern u8 D_PAL_8014FC50_195120[];
extern u8 D_PAL_80150C88_196158[];
extern u8 D_PAL_80150CB0_196180[];
extern u8 D_PAL_80151CE8_1971B8[];
extern u8 D_PAL_80151D10_1971E0[];
extern u8 D_PAL_80152118_1975E8[];
extern u8 D_PAL_80152140_197610[];
extern u8 D_PAL_80152548_197A18[];
extern u8 D_PAL_80152570_197A40[];
extern u8 D_PAL_80152978_197E48[];
extern u8 D_PAL_801529A0_197E70[];
extern u8 D_PAL_80152DA8_198278[];
extern u8 D_PAL_80152DD0_1982A0[];
extern u8 D_PAL_801531D8_1986A8[];
extern u8 D_PAL_80153200_1986D0[];
extern u8 D_PAL_80153608_198AD8[];
extern u8 D_PAL_80153630_198B00[];
extern u8 D_PAL_80153A38_198F08[];
extern u8 D_PAL_80153A60_198F30[];
extern u8 D_PAL_80158BA8_19E078[];
extern u8 D_PAL_80158BD0_19E0A0[];

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
