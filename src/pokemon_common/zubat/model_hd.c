#include "common.h"

extern u8 D_803AB1C0_54B5D0[]; // TODO: remove after splat is fixed

extern u8 zubat_tex_8011B058[];
extern u8 zubat_tex_8011B080_png[];
extern u8 zubat_tex_8011B288[];
extern u8 zubat_tex_8011B2B0_png[];
extern u8 zubat_tex_8011BAB8[];
extern u8 zubat_tex_8011BAE0_png[];

extern Gfx zubat_hd_part0_draw[];

#include "assets/pokemon_common/zubat/hd_model.vtx.inc.c"
#include "assets/pokemon_common/zubat/hd_first.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part0_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part1_pre.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part1_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part2_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part3_pre.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part3_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part4_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part5_pre.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part5_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part6_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part7_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part8_pre.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part8_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part9_draw.gfx.inc.c"
#include "assets/pokemon_common/zubat/hd_part10_draw.gfx.inc.c"

DObjPayloadTypeI zubat_hd_gfxdata[] = {
    { NULL, zubat_hd_first },
    { zubat_hd_part1_pre, zubat_hd_part1_draw },
    { NULL, zubat_hd_part2_draw },
    { zubat_hd_part3_pre, zubat_hd_part3_draw },
    { NULL, zubat_hd_part4_draw },
    { zubat_hd_part5_pre, zubat_hd_part5_draw },
    { NULL, zubat_hd_part6_draw },
    { NULL, zubat_hd_part7_draw },
    { zubat_hd_part8_pre, zubat_hd_part8_draw },
    { NULL, zubat_hd_part9_draw },
    { NULL, zubat_hd_part10_draw },
};

UnkEC64Arg3 zubat_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &zubat_hd_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zubat_hd_gfxdata[1],
      { -74.60299682617188, -336.51239013671875, -60.77690124511719 },
      { 0.17453299462795258, 0.0, -0.13089999556541443 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zubat_hd_gfxdata[2],
      { 3.000000106112566e-06, -149.9998321533203, 0.0 },
      { 0.0, 0.0, 0.13089999556541443 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zubat_hd_gfxdata[3],
      { 74.60299682617188, -336.5123596191406, -60.77690124511719 },
      { 0.17453299462795258, 0.0, 0.13089999556541443 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 3,
      &zubat_hd_gfxdata[4],
      { 0.0, -149.9998321533203, 0.0 },
      { 0.0, 0.0, -0.13089999556541443 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zubat_hd_gfxdata[5],
      { -58.90999984741211, -65.0, -27.470186233520508 },
      { 0.0, -0.43633198738098145, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zubat_hd_gfxdata[6],
      { -140.00001525878906, 30.000001907348633, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &zubat_hd_gfxdata[7],
      { -180.00001525878906, 70.0000228881836, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zubat_hd_gfxdata[8],
      { 58.90999984741211, -65.0, -27.470186233520508 },
      { 0.0, 0.43633198738098145, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zubat_hd_gfxdata[9],
      { 140.0000457763672, 30.000001907348633, 7.000000096013537e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &zubat_hd_gfxdata[10],
      { 180.0, 70.0000228881836, -2.2000000171829015e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
