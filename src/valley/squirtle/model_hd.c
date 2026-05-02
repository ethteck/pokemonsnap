#include "common.h"

extern u8 squirtle_tex_8017BA58[];
extern u8 squirtle_tex_8017BC60_png[];
extern u8 squirtle_tex_8017C068[];
extern u8 squirtle_tex_8017C090_png[];
extern u8 squirtle_tex_8017C298[];
extern u8 squirtle_tex_8017C4A0_png[];
extern u8 squirtle_tex_8017C8D0[];
extern u8 squirtle_tex_8017CB00[];
extern u8 squirtle_tex_8017CD30[];
extern u8 squirtle_tex_8017CF60[];
extern u8 squirtle_tex_8017D168[];
extern u8 squirtle_tex_8017D190[];
extern u8 squirtle_tex_8017D3C0[];
extern u8 squirtle_tex_8017D5F0[];
extern u8 squirtle_tex_8017D820[];
extern u8 squirtle_tex_8017DA50[];
extern u8 squirtle_tex_8017DC58[];
extern u8 squirtle_tex_8017DC80[];
extern u8 squirtle_tex_8017DE88[];
extern u8 squirtle_tex_8017E090_png[];
extern u8 squirtle_tex_8017E498[];
extern u8 squirtle_tex_8017E4C0_png[];

extern u8 D_8017C038_valley_extra[];
extern u8 D_8017C240_valley_extra[];
extern u8 D_8017C648_valley_extra[];
extern u8 D_8017C670_valley_extra[];
extern u8 D_8017C878_valley_extra[];
extern u8 D_8017CA80_valley_extra[];
extern u8 D_8017D748_valley_extra[];
extern u8 D_8017E238_valley_extra[];
extern u8 D_8017E468_valley_extra[];
extern u8 D_8017E670_valley_extra[];
extern u8 D_8017EA78_valley_extra[];
extern u8 D_8017EAA0_valley_extra[];
extern u8 D_801AF5A0_valley_extra[];
extern u8 D_801AF660_valley_extra[];
extern u8 D_801AF860_river_extra[];
extern u8 D_801AF9F0_volcano_extra[];
extern u8 D_801AFBF0_volcano_extra[];
extern u8 D_801AFC00_volcano_extra[];
extern u8 D_801AFC20_cave_extra[];
extern u8 D_801AFC30_valley_extra[];
extern u8 D_801AFDB0_valley_extra[];
extern u8 D_801AFE70_cave_extra[];
extern u8 D_801AFE80_cave_extra[];
extern u8 D_801AFE90_cave_extra[];
extern u8 D_801AFEA0_cave_extra[];
extern u8 D_801AFEB0_cave_extra[];
extern u8 D_801AFEC0_volcano_extra[];
extern u8 D_801AFED0_cave_extra[];
extern u8 D_801AFEE0_cave_extra[];
extern u8 D_801AFEF0_cave_extra[];
extern u8 D_801AFF00_cave_extra[];
extern u8 D_801AFF10_cave_extra[];
extern u8 D_801AFF20_cave_extra[];
extern u8 D_801AFF30_cave_extra[];
extern u8 D_801AFF40_cave_extra[];
extern u8 D_801AFF50_cave_extra[];
extern u8 D_801AFF60_cave_extra[];
extern u8 D_801AFF70_river_extra[];
extern u8 D_801AFF90_cave_extra[];
extern u8 D_801AFFA0_cave_extra[];
extern u8 D_801AFFD0_cave_extra[];
extern u8 D_801AFFE0_cave_extra[];
extern u8 D_801AFFF0_cave_extra[];
extern u8 D_801B0000_valley_extra[];
extern u8 D_801B0010_cave_extra[];
extern u8 D_801B0030_valley_extra[];
extern u8 D_801B0040_cave_extra[];
extern u8 D_801B0050_cave_extra[];
extern u8 D_801B0070_cave_extra[];
extern u8 D_801B00A0_volcano_extra[];
extern u8 D_801B00C0_volcano_extra[];
extern u8 D_801B00D0_valley_extra[];
extern u8 D_801B00E0_valley_extra[];
extern u8 D_801B00F0_cave_extra[];
extern u8 D_801B0120_cave_extra[];
extern u8 D_801B0130_river_extra[];
extern u8 D_801B0140_cave_extra[];
extern u8 D_801B0150_cave_extra[];
extern u8 D_801B0160_valley_extra[];
extern u8 D_801B0180_cave_extra[];
extern u8 D_801B0190_cave_extra[];
extern u8 D_801B01A0_cave_extra[];
extern u8 D_801B01B0_cave_extra[];
extern u8 D_801B01C0_river_extra[];
extern u8 D_801B01D0_cave_extra[];
extern u8 D_801B01E0_valley_extra[];
extern u8 D_801B01F0_cave_extra[];
extern u8 D_801B0210_cave_extra[];
extern u8 D_801B0240_cave_extra[];
extern u8 D_801B0250_valley_extra[];
extern u8 D_801B0260_cave_extra[];
extern u8 D_801B0270_valley_extra[];
extern u8 D_801B02A0_valley_extra[];
extern u8 D_801B02C0_valley_extra[];
extern u8 D_801B02E0_river_extra[];
extern u8 D_801B0330_valley_extra[];
extern u8 D_801B0350_cave_extra[];
extern u8 D_801B0390_cave_extra[];
extern u8 D_801B03C0_cave_extra[];
extern u8 D_801B03D0_cave_extra[];
extern u8 D_801B03E0_cave_extra[];
extern u8 D_801B03F0_cave_extra[];
extern u8 D_801B0400_valley_extra[];
extern u8 D_801B0420_valley_extra[];
extern u8 D_801B0450_cave_extra[];
extern u8 D_801B0470_cave_extra[];
extern u8 D_801B0490_volcano_extra[];
extern u8 D_801B04A0_cave_extra[];
extern u8 D_801B04C0_cave_extra[];
extern u8 D_801B04D0_volcano_extra[];
extern u8 D_801B04F0_cave_extra[];
extern u8 D_801B0500_cave_extra[];
extern u8 D_801B0510_cave_extra[];
extern u8 D_801B0540_cave_extra[];
extern u8 D_801B0560_cave_extra[];
extern u8 D_801B0570_cave_extra[];
extern u8 D_801B05B0_volcano_extra[];
extern u8 D_801B05C0_cave_extra[];
extern u8 D_801B05E0_cave_extra[];
extern u8 D_801B05F0_volcano_extra[];
extern u8 D_801B0610_cave_extra[];
extern u8 D_801B0660_cave_extra[];
extern u8 D_801B06A0_cave_extra[];
extern u8 D_801B06B0_cave_extra[];
extern u8 D_801B0860_cave_extra[];
extern u8 D_801B0A10_cave_extra[];
extern u8 D_801B0A20_valley_extra[];
extern u8 D_801B0A80_valley_extra[];
extern u8 D_801B0AC0_valley_extra[];
extern u8 D_801B0AD0_valley_extra[];
extern u8 D_801B0B10_valley_extra[];
extern u8 D_801B0BB0_valley_extra[];
extern u8 D_801B0C40_valley_extra[];
extern u8 D_801B0C50_valley_extra[];
extern u8 D_801B0C80_valley_extra[];
extern u8 D_801B0CD0_valley_extra[];
extern u8 D_801B0E10_cave_extra[];
extern u8 D_801B0FF0_valley_extra[];

extern Texture* squirtle_hd_part2_mat[];
extern Gfx squirtle_hd_part0_draw[];

Texture** squirtle_hd_materials[] = {
    NULL,
    NULL,
    squirtle_hd_part2_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* squirtle_hd_part2_mat0_textures[] = {
    squirtle_tex_8017DC80,
    squirtle_tex_8017D3C0,
    squirtle_tex_8017D5F0,
    squirtle_tex_8017D820,
    squirtle_tex_8017DA50,
};

u8* squirtle_hd_part2_mat1_textures[] = {
    squirtle_tex_8017D190,
    squirtle_tex_8017C8D0,
    squirtle_tex_8017CB00,
    squirtle_tex_8017CD30,
    squirtle_tex_8017CF60,
};

Texture squirtle_hd_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    squirtle_hd_part2_mat0_textures,
    128,
    64,
    64,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    64,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 254, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 254, 0 },
    { 51, 51, 51, 0 },
    0,
    0,
    0,
    0,
};

Texture squirtle_hd_part2_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    squirtle_hd_part2_mat1_textures,
    128,
    64,
    64,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    64,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 51, 51, 51, 0 },
    0,
    0,
    0,
    0,
};

Texture* squirtle_hd_part2_mat[] = {
    &squirtle_hd_part2_mat0,
    &squirtle_hd_part2_mat1,
    NULL,
    NULL,
};
#include "assets/valley/squirtle/hd_model.vtx.inc.c"
#include "assets/valley/squirtle/hd_first.gfx.inc.c"
#include "assets/valley/squirtle/hd_part0_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part1_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part2_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part3_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part4_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part5_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part6_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part7_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part8_draw.gfx.inc.c"

UnkEC64Arg3 squirtle_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      squirtle_hd_first,
      { 0.0, 200.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part1_draw,
      { 0.0, 151.88722229003906, 35.6209602355957 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part2_draw,
      { -91.47610473632812, 78.3467788696289, 48.934173583984375 },
      { 0.0, 0.785398006439209, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part3_draw,
      { 91.47610473632812, 78.3467788696289, 48.934173583984375 },
      { 0.0, -0.785398006439209, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part4_draw,
      { -90.0, -87.57794952392578, 21.33312225341797 },
      { -0.3441169857978821, -0.16390900313854218, -0.06023399904370308 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      squirtle_hd_part5_draw,
      { 0.0, -30.000001907348633, 0.0 },
      { 0.34906598925590515, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part6_draw,
      { 90.0, -87.57794952392578, 21.33312225341797 },
      { -0.3441169857978821, 0.16390900313854218, 0.06023399904370308 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      squirtle_hd_part7_draw,
      { 0.0, -30.000001907348633, 0.0 },
      { 0.34906598925590515, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part8_draw,
      { 0.0, -171.3300018310547, -19.739999771118164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
