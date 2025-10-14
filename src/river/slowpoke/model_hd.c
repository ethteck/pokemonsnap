#include "common.h"

extern u8 D_801AEDF0[]; // TODO: remove after splat is fixed

extern u8 slowpoke_tex_80185968[];
extern u8 slowpoke_tex_80185990_png[];
extern u8 slowpoke_tex_80185B98[];
extern u8 slowpoke_tex_80185BC0_png[];
extern u8 slowpoke_tex_80185DC8[];
extern u8 slowpoke_tex_80185DF0_png[];
extern u8 slowpoke_tex_80185FF8[];
extern u8 slowpoke_tex_80186020_png[];
extern u8 slowpoke_tex_80186428[];
extern u8 slowpoke_tex_80186450_png[];
extern u8 slowpoke_tex_80186658[];
extern u8 slowpoke_tex_80186680_png[];

extern Gfx slowpoke_hd_part0_draw[];

#include "assets/river/slowpoke/hd_model.vtx.inc.c"
#include "assets/river/slowpoke/hd_first.gfx.inc.c"
#include "assets/river/slowpoke/hd_part0_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part1_pre.gfx.inc.c"
#include "assets/river/slowpoke/hd_part1_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part2_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part3_pre.gfx.inc.c"
#include "assets/river/slowpoke/hd_part3_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part4_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part5_pre.gfx.inc.c"
#include "assets/river/slowpoke/hd_part5_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part6_pre.gfx.inc.c"
#include "assets/river/slowpoke/hd_part6_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part7_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part8_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part9_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part10_pre.gfx.inc.c"
#include "assets/river/slowpoke/hd_part10_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part11_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part12_pre.gfx.inc.c"
#include "assets/river/slowpoke/hd_part12_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part13_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part14_pre.gfx.inc.c"
#include "assets/river/slowpoke/hd_part14_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part15_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part16_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part17_draw.gfx.inc.c"
#include "assets/river/slowpoke/hd_part18_draw.gfx.inc.c"

DObjPayloadTypeI slowpoke_hd_gfxdata[] = {
    { NULL, slowpoke_hd_first },
    { slowpoke_hd_part1_pre, slowpoke_hd_part1_draw },
    { NULL, slowpoke_hd_part2_draw },
    { slowpoke_hd_part3_pre, slowpoke_hd_part3_draw },
    { NULL, slowpoke_hd_part4_draw },
    { slowpoke_hd_part5_pre, slowpoke_hd_part5_draw },
    { slowpoke_hd_part6_pre, slowpoke_hd_part6_draw },
    { NULL, slowpoke_hd_part7_draw },
    { NULL, slowpoke_hd_part8_draw },
    { NULL, slowpoke_hd_part9_draw },
    { slowpoke_hd_part10_pre, slowpoke_hd_part10_draw },
    { NULL, slowpoke_hd_part11_draw },
    { slowpoke_hd_part12_pre, slowpoke_hd_part12_draw },
    { NULL, slowpoke_hd_part13_draw },
    { slowpoke_hd_part14_pre, slowpoke_hd_part14_draw },
    { NULL, slowpoke_hd_part15_draw },
    { NULL, slowpoke_hd_part16_draw },
    { NULL, slowpoke_hd_part17_draw },
    { NULL, slowpoke_hd_part18_draw },
};

UnkEC64Arg3 slowpoke_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &slowpoke_hd_gfxdata[0],
      { 0.0, 419.9999694824219, -300.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowpoke_hd_gfxdata[1],
      { 300.0, -84.00025177001953, 4.8000001697801054e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_hd_gfxdata[2],
      { 0.0, -240.00001525878906, -20.000003814697266 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowpoke_hd_gfxdata[3],
      { -300.0, -84.00022888183594, 2.4000000848900527e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_hd_gfxdata[4],
      { 0.0, -240.00001525878906, -20.000003814697266 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowpoke_hd_gfxdata[5],
      { -9.999999974752427e-07, -70.00003051757812, 300.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_hd_gfxdata[6],
      { 0.0, -15.000000953674316, 400.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowpoke_hd_gfxdata[7],
      { 0.0, -50.0, 140.00001525878906 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowpoke_hd_gfxdata[8],
      { 0.0, 0.0, 150.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &slowpoke_hd_gfxdata[9],
      { 0.0, -25.0, -5.000019073486328 },
      { -0.06981299817562103, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_hd_gfxdata[10],
      { 270.0, -14.000177383422852, 270.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowpoke_hd_gfxdata[11],
      { 0.0, -275.0, 45.000003814697266 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_hd_gfxdata[12],
      { -270.0, -14.000177383422852, 270.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowpoke_hd_gfxdata[13],
      { 0.0, -275.0, 45.000003814697266 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowpoke_hd_gfxdata[14],
      { 0.0, 60.000003814697266, -130.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0000020265579224, 1.0, 1.0 } },
    { 3,
      &slowpoke_hd_gfxdata[15],
      { 0.0, 0.0, -350.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0000040531158447, 0.9999989867210388, 1.0 } },
    { 4,
      &slowpoke_hd_gfxdata[16],
      { -1.4000000192027073e-05, 19.999980926513672, -300.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999949932098389, 1.0000009536743164, 0.9999960064888 } },
    { 5,
      &slowpoke_hd_gfxdata[17],
      { -2.5999999706982635e-05, 0.0, -250.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0000029802322388, 0.9999970197677612, 0.9999989867210388 } },
    { 6,
      &slowpoke_hd_gfxdata[18],
      { 0.0, 0.0, -220.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
