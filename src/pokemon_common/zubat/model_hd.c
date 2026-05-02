#include "common.h"

extern u8 zubat_tex_ear_pal[];
extern u8 zubat_tex_ear_png[];
extern u8 zubat_tex_wing_inside_pal[];
extern u8 zubat_tex_wing_inside_png[];
extern u8 zubat_tex_wing_outside_pal[];
extern u8 zubat_tex_wing_outside_png[];

extern u8 D_8011B638_zubat_model_hd[];
extern u8 D_8011B660_zubat_model_hd[];
extern u8 D_8011B868_zubat_model_hd[];
extern u8 D_8011B890_zubat_model_hd[];
extern u8 D_8011C098_zubat_model_hd[];
extern u8 D_8011C0C0_zubat_model_hd[];
extern u8 D_803AA700_zubat_model_hd[];
extern u8 D_803AA750_zubat_model_hd[];
extern u8 D_803AA900_zubat_model_hd[];
extern u8 D_803AAA40_zubat_model_hd[];
extern u8 D_803AAA60_zubat_model_hd[];
extern u8 D_803AAAA0_zubat_model_hd[];
extern u8 D_803AAAB0_zubat_model_hd[];
extern u8 D_803AAAD0_zubat_model_hd[];
extern u8 D_803AAAE0_zubat_model_hd[];
extern u8 D_803AAAF0_zubat_model_hd[];
extern u8 D_803AAB00_zubat_model_hd[];
extern u8 D_803AAB10_zubat_model_hd[];
extern u8 D_803AAB20_zubat_model_hd[];
extern u8 D_803AAB30_zubat_model_hd[];
extern u8 D_803AAB40_zubat_model_hd[];
extern u8 D_803AAB60_zubat_model_hd[];
extern u8 D_803AAB70_zubat_model_hd[];
extern u8 D_803AAB90_zubat_model_hd[];
extern u8 D_803AABA0_zubat_model_hd[];
extern u8 D_803AABC0_zubat_model_hd[];
extern u8 D_803AAC00_zubat_model_hd[];
extern u8 D_803AAC10_zubat_model_hd[];
extern u8 D_803AAC40_zubat_model_hd[];
extern u8 D_803AAC60_zubat_model_hd[];
extern u8 D_803AAC90_zubat_model_hd[];
extern u8 D_803AACA0_zubat_model_hd[];
extern u8 D_803AACC0_zubat_model_hd[];
extern u8 D_803AACD0_zubat_model_hd[];
extern u8 D_803AACE0_zubat_model_hd[];
extern u8 D_803AACF0_zubat_model_hd[];
extern u8 D_803AAD00_zubat_model_hd[];
extern u8 D_803AAD10_zubat_model_hd[];
extern u8 D_803AAD20_zubat_model_hd[];
extern u8 D_803AAD30_zubat_model_hd[];
extern u8 D_803AAD40_zubat_model_hd[];
extern u8 D_803AAD50_zubat_model_hd[];
extern u8 D_803AAD60_zubat_model_hd[];
extern u8 D_803AADA0_zubat_model_hd[];
extern u8 D_803AADB0_zubat_model_hd[];
extern u8 D_803AADD0_zubat_model_hd[];
extern u8 D_803AADF0_zubat_model_hd[];
extern u8 D_803AAE00_zubat_model_hd[];
extern u8 D_803AAE10_zubat_model_hd[];
extern u8 D_803AAE20_zubat_model_hd[];
extern u8 D_803AAE30_zubat_model_hd[];
extern u8 D_803AAE40_zubat_model_hd[];
extern u8 D_803AAE60_zubat_model_hd[];
extern u8 D_803AAEA0_zubat_model_hd[];
extern u8 D_803AAEC0_zubat_model_hd[];
extern u8 D_803AAEE0_zubat_model_hd[];
extern u8 D_803AAF00_zubat_model_hd[];
extern u8 D_803AAF30_zubat_model_hd[];
extern u8 D_803AAF40_zubat_model_hd[];
extern u8 D_803AAF50_zubat_model_hd[];
extern u8 D_803AAF90_zubat_model_hd[];
extern u8 D_803AAFB0_zubat_model_hd[];
extern u8 D_803AAFD0_zubat_model_hd[];
extern u8 D_803AAFE0_zubat_model_hd[];
extern u8 D_803AB000_zubat_model_hd[];
extern u8 D_803AB010_zubat_model_hd[];
extern u8 D_803AB040_zubat_model_hd[];
extern u8 D_803AB050_zubat_model_hd[];
extern u8 D_803AB070_zubat_model_hd[];
extern u8 D_803AB090_zubat_model_hd[];
extern u8 D_803AB0A0_zubat_model_hd[];
extern u8 D_803AB0B0_zubat_model_hd[];
extern u8 D_803AB0D0_zubat_model_hd[];
extern u8 D_803AB0E0_zubat_model_hd[];
extern u8 D_803AB0F0_zubat_model_hd[];
extern u8 D_803AB140_zubat_model_hd[];
extern u8 D_803AB1C0_zubat_model_hd[];
extern u8 D_803AB1E0_zubat_model_hd[];
extern u8 D_PAL_803ABE08_8379C8[];

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
