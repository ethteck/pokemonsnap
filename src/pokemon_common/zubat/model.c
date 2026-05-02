#include "common.h"

extern u8 zubat_tex_ear_pal[];
extern u8 zubat_tex_ear_png[];
extern u8 zubat_tex_wing_inside_pal[];
extern u8 zubat_tex_wing_inside_png[];
extern u8 zubat_tex_wing_outside_pal[];
extern u8 zubat_tex_wing_outside_png[];

extern u8 D_8011B638_zubat_model[];
extern u8 D_8011B660_zubat_model[];
extern u8 D_8011B868_zubat_model[];
extern u8 D_8011B890_zubat_model[];
extern u8 D_8011C098_zubat_model[];
extern u8 D_8011C0C0_zubat_model[];
extern u8 D_80343740_zubat_model[];
extern u8 D_80343840_zubat_model[];
extern u8 D_80343880_zubat_model[];
extern u8 D_803438A0_zubat_model[];
extern u8 D_803438B0_zubat_model[];
extern u8 D_803438D0_zubat_model[];
extern u8 D_803438E0_zubat_model[];
extern u8 D_80343930_zubat_model[];
extern u8 D_80343940_zubat_model[];
extern u8 D_80343960_zubat_model[];
extern u8 D_80343970_zubat_model[];
extern u8 D_80343980_zubat_model[];
extern u8 D_80343990_zubat_model[];
extern u8 D_803439D0_zubat_model[];
extern u8 D_80343A00_zubat_model[];
extern u8 D_80343A30_zubat_model[];
extern u8 D_80343A40_zubat_model[];
extern u8 D_80343A50_zubat_model[];
extern u8 D_80343A60_zubat_model[];
extern u8 D_80343B30_zubat_model[];
extern u8 D_80343B50_zubat_model[];
extern u8 D_80343BA0_zubat_model[];
extern u8 D_80343BC0_zubat_model[];
extern u8 D_80343BE0_zubat_model[];
extern u8 D_80343BF0_zubat_model[];
extern u8 D_80343C10_zubat_model[];
extern u8 D_80343C20_zubat_model[];
extern u8 D_80343C70_zubat_model[];
extern u8 D_80343C90_zubat_model[];
extern u8 D_80343CA0_zubat_model[];
extern u8 D_80343D30_zubat_model[];
extern u8 D_80343D70_zubat_model[];
extern u8 D_80343DE0_zubat_model[];
extern u8 D_80343E30_zubat_model[];
extern u8 D_80343E50_zubat_model[];
extern u8 D_80343E60_zubat_model[];
extern u8 D_80343E70_zubat_model[];
extern u8 D_80343EB0_zubat_model[];
extern u8 D_80343ED0_zubat_model[];
extern u8 D_80343EE0_zubat_model[];
extern u8 D_80343EF0_zubat_model[];
extern u8 D_80343F30_zubat_model[];
extern u8 D_80343F40_zubat_model[];
extern u8 D_80343F60_zubat_model[];
extern u8 D_80343F70_zubat_model[];
extern u8 D_80343F80_zubat_model[];
extern u8 D_80343FB0_zubat_model[];
extern u8 D_80343FE0_zubat_model[];
extern u8 D_80343FF0_zubat_model[];
extern u8 D_80344000_zubat_model[];
extern u8 D_80344090_zubat_model[];
extern u8 D_80344100_zubat_model[];
extern u8 D_80344110_zubat_model[];
extern u8 D_80344130_zubat_model[];
extern u8 D_80344140_zubat_model[];
extern u8 D_80344150_zubat_model[];
extern u8 D_80344180_zubat_model[];
extern u8 D_803441B0_zubat_model[];
extern u8 D_803441C0_zubat_model[];
extern u8 D_803441D0_zubat_model[];
extern u8 D_80344260_zubat_model[];
extern u8 D_803442D0_zubat_model[];
extern u8 D_803443B0_zubat_model[];
extern u8 D_803443E0_zubat_model[];
extern u8 D_80344410_zubat_model[];
extern u8 D_80344420_zubat_model[];
extern u8 D_80344490_zubat_model[];
extern u8 D_80344570_zubat_model[];
extern u8 D_803445A0_zubat_model[];
extern u8 D_803445C0_zubat_model[];
extern u8 D_803445E0_zubat_model[];
extern u8 D_80344600_zubat_model[];
extern u8 D_80344610_zubat_model[];
extern u8 D_80344620_zubat_model[];
extern u8 D_80344630_zubat_model[];
extern u8 D_80344640_zubat_model[];
extern u8 D_80344650_zubat_model[];
extern u8 D_80344690_zubat_model[];
extern u8 D_80344750_zubat_model[];
extern u8 D_PAL_80344A68_5547B8[];
extern u8 D_PAL_80344E60_554BB0[];
extern u8 D_PAL_80345130_554E80[];
extern u8 D_PAL_80345160_554EB0[];
extern u8 D_PAL_80345190_554EE0[];
extern u8 D_PAL_803451F0_554F40[];
extern u8 D_PAL_80345248_554F98[];
extern u8 D_PAL_803452D0_555020[];
extern u8 D_PAL_80345328_555078[];
extern u8 D_PAL_803453A0_5550F0[];
extern u8 D_PAL_803453D8_555128[];
extern u8 D_PAL_80345430_555180[];
extern u8 D_PAL_80345488_5551D8[];
extern u8 D_PAL_80345510_555260[];
extern u8 D_PAL_80345568_5552B8[];
extern u8 D_PAL_803455E0_555330[];
extern u8 D_PAL_80345620_555370[];
extern u8 D_PAL_80345748_555498[];
extern u8 D_PAL_80345860_5555B0[];
extern u8 D_PAL_80345978_5556C8[];
extern u8 D_PAL_80345A98_5557E8[];
extern u8 D_PAL_80345BB8_555908[];
extern u8 D_PAL_80345CC8_555A18[];
extern u8 D_PAL_80345D20_555A70[];
extern u8 D_PAL_80345E30_555B80[];
extern u8 D_PAL_80345F38_555C88[];
extern u8 D_PAL_80346050_555DA0[];
extern u8 D_PAL_80346290_555FE0[];
extern u8 D_PAL_80346378_5560C8[];

extern Gfx zubat_part0_draw[];

#include "assets/pokemon_common/zubat/model.vtx.inc.c"
#include "assets/pokemon_common/zubat/first.gfx.inc.c"
#include "assets/pokemon_common/zubat/part0_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part0_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part0_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part1_pre_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part1_pre_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part1_pre.gfx.inc.c"
#include "assets/pokemon_common/zubat/part1_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part1_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part1_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part2_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part2_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part2_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part3_pre_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part3_pre_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part3_pre.gfx.inc.c"
#include "assets/pokemon_common/zubat/part3_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part3_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part3_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part4_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part4_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part4_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part5_pre_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part5_pre.gfx.inc.c"
#include "assets/pokemon_common/zubat/part5_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part5_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part5_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part6_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part6_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part6_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part7_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part7_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part7_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part8_pre_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part8_pre.gfx.inc.c"
#include "assets/pokemon_common/zubat/part8_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part8_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part8_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part9_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part9_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part9_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/part10_draw_near.gfx.inc.c"
#include "assets/pokemon_common/zubat/part10_draw_far.gfx.inc.c"
#include "assets/pokemon_common/zubat/part10_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/last.gfx.inc.c"

DObjPayloadTypeI zubat_gfxdata[] = {
    { NULL, zubat_first },
    { zubat_part1_pre, zubat_part1_draw },
    { NULL, zubat_part2_draw },
    { zubat_part3_pre, zubat_part3_draw },
    { NULL, zubat_part4_draw },
    { zubat_part5_pre, zubat_part5_draw },
    { NULL, zubat_part6_draw },
    { NULL, zubat_part7_draw },
    { zubat_part8_pre, zubat_part8_draw },
    { NULL, zubat_part9_draw },
    { NULL, zubat_last },
};

UnkEC64Arg3 zubat_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &zubat_gfxdata[0],
      { -7.4218668937683105, 7.8124871253967285, 0.0 },
      { 1.0471980571746826, 0.0, 0.038860999047756195 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zubat_gfxdata[1],
      { -74.60298156738281, -336.5123291015625, -60.77685546875 },
      { 0.17453299462795258, 0.0, -0.13089999556541443 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zubat_gfxdata[2],
      { 0.0, -150.00009155273438, 0.0 },
      { 0.0, 0.0, 0.13089999556541443 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zubat_gfxdata[3],
      { 74.60298156738281, -336.5123291015625, -60.77685546875 },
      { 0.17453299462795258, 0.0, 0.13089999556541443 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zubat_gfxdata[4],
      { -9.000000318337698e-06, -150.00013732910156, 9.999999974752427e-07 },
      { 0.0, 0.0, -0.13089999556541443 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zubat_gfxdata[5],
      { -58.90999984741211, -65.0, -27.470186233520508 },
      { 0.0, -1.0471980571746826, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zubat_gfxdata[6],
      { -139.99996948242188, 29.999996185302734, 0.0 },
      { 0.0, 0.0, -0.17453299462795258 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &zubat_gfxdata[7],
      { -180.0, 70.00001525878906, -2.099999983329326e-05 },
      { 0.0, 0.0, -0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zubat_gfxdata[8],
      { 58.90999984741211, -65.0, -27.470186233520508 },
      { 0.0, 1.0471980571746826, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zubat_gfxdata[9],
      { 139.99996948242188, 29.999996185302734, 9.999999974752427e-07 },
      { 0.0, 0.0, 0.17453299462795258 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &zubat_gfxdata[10],
      { 180.0000457763672, 70.00001525878906, -2.9999999242136255e-05 },
      { 0.0, 0.0, 0.26179900765419006 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
