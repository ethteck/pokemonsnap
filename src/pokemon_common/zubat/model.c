#include "common.h"

extern u8 zubat_tex_8011B058[];
extern u8 zubat_tex_8011B080_png[];
extern u8 zubat_tex_8011B288[];
extern u8 zubat_tex_8011B2B0_png[];
extern u8 zubat_tex_8011BAB8[];
extern u8 zubat_tex_8011BAE0_png[];

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
