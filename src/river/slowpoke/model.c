#include "common.h"

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

extern Gfx slowpoke_part0_draw[];

#include "assets/river/slowpoke/model.vtx.inc.c"
#include "assets/river/slowpoke/first.gfx.inc.c"
#include "assets/river/slowpoke/part0_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part0_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part0_draw.gfx.inc.c"
#include "assets/river/slowpoke/part1_pre_near.gfx.inc.c"
#include "assets/river/slowpoke/part1_pre_far.gfx.inc.c"
#include "assets/river/slowpoke/part1_pre.gfx.inc.c"
#include "assets/river/slowpoke/part1_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part1_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part1_draw.gfx.inc.c"
#include "assets/river/slowpoke/part2_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part2_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part2_draw.gfx.inc.c"
#include "assets/river/slowpoke/part3_pre_near.gfx.inc.c"
#include "assets/river/slowpoke/part3_pre_far.gfx.inc.c"
#include "assets/river/slowpoke/part3_pre.gfx.inc.c"
#include "assets/river/slowpoke/part3_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part3_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part3_draw.gfx.inc.c"
#include "assets/river/slowpoke/part4_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part4_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part4_draw.gfx.inc.c"
#include "assets/river/slowpoke/part5_pre_near.gfx.inc.c"
#include "assets/river/slowpoke/part5_pre_far.gfx.inc.c"
#include "assets/river/slowpoke/part5_pre.gfx.inc.c"
#include "assets/river/slowpoke/part5_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part5_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part5_draw.gfx.inc.c"
#include "assets/river/slowpoke/part6_pre_near.gfx.inc.c"
#include "assets/river/slowpoke/part6_pre_far.gfx.inc.c"
#include "assets/river/slowpoke/part6_pre.gfx.inc.c"
#include "assets/river/slowpoke/part6_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part6_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part6_draw.gfx.inc.c"
#include "assets/river/slowpoke/part7_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part7_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part7_draw.gfx.inc.c"
#include "assets/river/slowpoke/part8_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part8_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part8_draw.gfx.inc.c"
#include "assets/river/slowpoke/part9_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part9_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part9_draw.gfx.inc.c"
#include "assets/river/slowpoke/part10_pre_near.gfx.inc.c"
#include "assets/river/slowpoke/part10_pre_far.gfx.inc.c"
#include "assets/river/slowpoke/part10_pre.gfx.inc.c"
#include "assets/river/slowpoke/part10_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part10_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part10_draw.gfx.inc.c"
#include "assets/river/slowpoke/part11_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part11_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part11_draw.gfx.inc.c"
#include "assets/river/slowpoke/part12_pre_near.gfx.inc.c"
#include "assets/river/slowpoke/part12_pre_far.gfx.inc.c"
#include "assets/river/slowpoke/part12_pre.gfx.inc.c"
#include "assets/river/slowpoke/part12_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part12_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part12_draw.gfx.inc.c"
#include "assets/river/slowpoke/part13_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part13_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part13_draw.gfx.inc.c"
#include "assets/river/slowpoke/part14_pre_near.gfx.inc.c"
#include "assets/river/slowpoke/part14_pre_far.gfx.inc.c"
#include "assets/river/slowpoke/part14_pre.gfx.inc.c"
#include "assets/river/slowpoke/part14_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part14_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part14_draw.gfx.inc.c"
#include "assets/river/slowpoke/part15_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part15_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part15_draw.gfx.inc.c"
#include "assets/river/slowpoke/part16_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part16_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part16_draw.gfx.inc.c"
#include "assets/river/slowpoke/part17_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part17_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part17_draw.gfx.inc.c"
#include "assets/river/slowpoke/part18_draw_near.gfx.inc.c"
#include "assets/river/slowpoke/part18_draw_far.gfx.inc.c"
#include "assets/river/slowpoke/part18_draw.gfx.inc.c"
#include "assets/river/slowpoke/last.gfx.inc.c"

DObjPayloadTypeI slowpoke_gfxdata[] = {
    { NULL, slowpoke_first },
    { slowpoke_part1_pre, slowpoke_part1_draw },
    { NULL, slowpoke_part2_draw },
    { slowpoke_part3_pre, slowpoke_part3_draw },
    { NULL, slowpoke_part4_draw },
    { slowpoke_part5_pre, slowpoke_part5_draw },
    { slowpoke_part6_pre, slowpoke_part6_draw },
    { NULL, slowpoke_part7_draw },
    { NULL, slowpoke_part8_draw },
    { NULL, slowpoke_part9_draw },
    { slowpoke_part10_pre, slowpoke_part10_draw },
    { NULL, slowpoke_part11_draw },
    { slowpoke_part12_pre, slowpoke_part12_draw },
    { NULL, slowpoke_part13_draw },
    { slowpoke_part14_pre, slowpoke_part14_draw },
    { NULL, slowpoke_part15_draw },
    { NULL, slowpoke_part16_draw },
    { NULL, slowpoke_part17_draw },
    { NULL, slowpoke_last },
};

UnkEC64Arg3 slowpoke_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &slowpoke_gfxdata[0],
      { 0.0, 419.9999694824219, -300.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowpoke_gfxdata[1],
      { 300.0, -84.00020599365234, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_gfxdata[2],
      { 2.4000000848900527e-05, -240.00001525878906, -20.000028610229492 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowpoke_gfxdata[3],
      { -300.0, -84.00018310546875, 2.4000000848900527e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_gfxdata[4],
      { 20.000003814697266, -240.00001525878906, -20.000028610229492 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowpoke_gfxdata[5],
      { 9.999999974752427e-07, -69.99998474121094, 300.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_gfxdata[6],
      { 0.0, -15.000009536743164, 400.00006103515625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowpoke_gfxdata[7],
      { 0.0, -50.0, 140.00006103515625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowpoke_gfxdata[8],
      { 0.0, 0.0, 150.0000457763672 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &slowpoke_gfxdata[9],
      { 0.0, -25.0, -4.99997091293335 },
      { -0.06981299817562103, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_gfxdata[10],
      { 270.0, -14.000201225280762, 270.0000305175781 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowpoke_gfxdata[11],
      { 0.0, -270.0, 45.000030517578125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowpoke_gfxdata[12],
      { -270.0, -14.000201225280762, 270.0000305175781 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowpoke_gfxdata[13],
      { 0.0, -275.0, 45.000030517578125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowpoke_gfxdata[14],
      { 0.0, 59.99999237060547, -130.00001525878906 },
      { 0.26179900765419006, 0.0, 0.0 },
      { 1.0000020265579224, 1.0, 0.9999989867210388 } },
    { 3,
      &slowpoke_gfxdata[15],
      { 0.0, 9.500000305706635e-05, -350.0001525878906 },
      { 1.0471980571746826, 0.0, 0.0 },
      { 1.0000040531158447, 0.9999979734420776, 0.9999989867210388 } },
    { 4,
      &slowpoke_gfxdata[16],
      { 0.0, 19.99979019165039, -300.00006103515625 },
      { 1.0471980571746826, 0.0, 0.0 },
      { 0.9999949932098389, 1.0, 0.9999960064888 } },
    { 5,
      &slowpoke_gfxdata[17],
      { 0.0, 0.0, -249.9999542236328 },
      { 0.6981319785118103, 0.0, 0.0 },
      { 1.0000029802322388, 1.0, 0.9999960064888 } },
    { 6,
      &slowpoke_gfxdata[18],
      { 0.0, 9.500000305706635e-05, -219.9999542236328 },
      { 0.26179900765419006, 0.0, 0.0 },
      { 1.0, 1.0000009536743164, 0.9999989867210388 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
