#include "common.h"

extern u8 slowbro_tex_80191D88[];
extern u8 slowbro_tex_80191DB0_png[];
extern u8 slowbro_tex_80191FB8[];
extern u8 slowbro_tex_80191FE0_png[];
extern u8 slowbro_tex_801921E8[];
extern u8 slowbro_tex_80192210_png[];
extern u8 slowbro_tex_80192618[];
extern u8 slowbro_tex_80192640_png[];
extern u8 slowbro_tex_80192A48[];
extern u8 slowbro_tex_80192A70_png[];
extern u8 slowbro_tex_80192C78[];
extern u8 slowbro_tex_80192CA0[];
extern u8 slowbro_tex_801930A8[];
extern u8 slowbro_tex_801930D0_png[];
extern u8 slowbro_tex_801932D8[];
extern u8 slowbro_tex_80193300_png[];
extern u8 slowbro_tex_80193708[];
extern u8 slowbro_tex_80193730_png[];
extern u8 slowbro_tex_80193960[];
extern u8 slowbro_tex_80193D68[];
extern u8 slowbro_tex_80193D90_png[];
extern u8 slowbro_tex_80193F98[];
extern u8 slowbro_tex_80193FC0_png[];

extern u8 D_80192368_river_extra[];
extern u8 D_80192390_river_extra[];
extern u8 D_80192598_river_extra[];
extern u8 D_801925C0_river_extra[];
extern u8 D_801927C8_river_extra[];
extern u8 D_801927F0_river_extra[];
extern u8 D_80192BF8_river_extra[];
extern u8 D_80192C20_river_extra[];
extern u8 D_80193028_river_extra[];
extern u8 D_80193050_river_extra[];
extern u8 D_80193258_river_extra[];
extern u8 D_80193688_river_extra[];
extern u8 D_801936B0_river_extra[];
extern u8 D_801938B8_river_extra[];
extern u8 D_801938E0_river_extra[];
extern u8 D_80193CE8_river_extra[];
extern u8 D_80193D10_river_extra[];
extern u8 D_80194348_river_extra[];
extern u8 D_80194370_river_extra[];
extern u8 D_80194578_river_extra[];
extern u8 D_801945A0_river_extra[];
extern u8 D_801B2510_river_extra[];
extern u8 D_801B2520_river_extra[];
extern u8 D_801B25C0_river_extra[];
extern u8 D_801B25D0_river_extra[];
extern u8 D_801B25F0_river_extra[];
extern u8 D_801B2600_river_extra[];
extern u8 D_801B2620_river_extra[];
extern u8 D_801B2630_river_extra[];
extern u8 D_801B2640_river_extra[];
extern u8 D_801B2650_river_extra[];
extern u8 D_801B2670_river_extra[];
extern u8 D_801B2680_river_extra[];
extern u8 D_801B2690_river_extra[];
extern u8 D_801B26A0_river_extra[];
extern u8 D_801B26C0_river_extra[];
extern u8 D_801B26E0_river_extra[];
extern u8 D_801B26F0_river_extra[];
extern u8 D_801B2700_river_extra[];
extern u8 D_801B2710_river_extra[];
extern u8 D_801B2720_river_extra[];
extern u8 D_801B2730_river_extra[];
extern u8 D_801B2750_river_extra[];
extern u8 D_801B2770_river_extra[];
extern u8 D_801B2780_river_extra[];
extern u8 D_801B2790_river_extra[];
extern u8 D_801B27A0_river_extra[];
extern u8 D_801B27C0_river_extra[];
extern u8 D_801B27E0_river_extra[];
extern u8 D_801B2810_river_extra[];
extern u8 D_801B2820_river_extra[];
extern u8 D_801B2830_river_extra[];
extern u8 D_801B2850_river_extra[];
extern u8 D_801B2860_river_extra[];
extern u8 D_801B2880_river_extra[];
extern u8 D_801B2890_river_extra[];
extern u8 D_801B28B0_river_extra[];
extern u8 D_801B28C0_river_extra[];
extern u8 D_801B28D0_river_extra[];
extern u8 D_801B28E0_river_extra[];
extern u8 D_801B28F0_river_extra[];
extern u8 D_801B2960_river_extra[];
extern u8 D_801B2970_river_extra[];
extern u8 D_801B2980_river_extra[];
extern u8 D_801B29A0_river_extra[];
extern u8 D_801B29B0_river_extra[];
extern u8 D_801B29C0_river_extra[];
extern u8 D_801B29D0_river_extra[];
extern u8 D_801B2AF0_river_extra[];
extern u8 D_801B2B50_river_extra[];
extern u8 D_801B2BA0_river_extra[];
extern u8 D_801B2BC0_river_extra[];
extern u8 D_801B2BE0_river_extra[];
extern u8 D_801B2D00_river_extra[];
extern u8 D_801B2D80_river_extra[];
extern u8 D_801B2EA0_river_extra[];
extern u8 D_801B3000_river_extra[];
extern u8 D_801B3010_river_extra[];
extern u8 D_801B3020_river_extra[];
extern u8 D_801B3030_river_extra[];
extern u8 D_801B3050_river_extra[];
extern u8 D_801B3160_river_extra[];
extern u8 D_801B31C0_river_extra[];
extern u8 D_801B31E0_river_extra[];
extern u8 D_801B31F0_river_extra[];
extern u8 D_801B3220_river_extra[];
extern u8 D_801B3250_river_extra[];
extern u8 D_801B3280_river_extra[];
extern u8 D_801B3290_river_extra[];
extern u8 D_801B33F0_river_extra[];
extern u8 D_801B3460_river_extra[];
extern u8 D_801B3510_river_extra[];
extern u8 D_801B3570_river_extra[];
extern u8 D_801B36B0_river_extra[];
extern u8 D_801B3820_river_extra[];
extern u8 D_801B3880_river_extra[];
extern u8 D_801B39C0_river_extra[];
extern u8 D_801B3B30_river_extra[];
extern u8 D_801B3B90_river_extra[];
extern u8 D_801B3C20_river_extra[];
extern u8 D_801B3C50_river_extra[];
extern u8 D_801B3E10_river_extra[];
extern u8 D_801B3EF0_cave_extra[];
extern u8 D_801B3FC0_cave_extra[];
extern u8 D_801B4170_cave_extra[];
extern u8 D_801B4180_cave_extra[];
extern u8 D_801B4320_river_extra[];
extern u8 D_801B4340_cave_extra[];
extern u8 D_801B44C0_cave_extra[];
extern u8 D_801B4650_cave_extra[];
extern u8 D_801B47F0_cave_extra[];
extern u8 D_801B48B0_cave_extra[];
extern u8 D_801B4930_river_extra[];
extern u8 D_801B4AF0_river_extra[];
extern u8 D_801B4BD0_river_extra[];
extern u8 D_801B4C10_river_extra[];
extern u8 D_801B4C40_cave_extra[];
extern u8 D_801B4D40_cave_extra[];
extern u8 D_801B4D90_cave_extra[];
extern u8 D_801B4E20_river_extra[];
extern u8 D_801B4E40_river_extra[];
extern u8 D_801B4E70_river_extra[];
extern u8 D_801B4EA0_river_extra[];
extern u8 D_801B4EC0_river_extra[];
extern u8 D_801B4F10_river_extra[];
extern u8 D_801B5010_river_extra[];
extern u8 D_801B5060_river_extra[];
extern u8 D_801B50F0_river_extra[];
extern u8 D_801B5110_river_extra[];
extern u8 D_801B5130_river_extra[];
extern u8 D_801B5150_river_extra[];
extern u8 D_801B5180_river_extra[];
extern u8 D_801B5208_river_extra[];

extern Texture* slowbro_hd_part10_mat[];
extern Gfx slowbro_hd_part0_draw[];

Texture** slowbro_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    slowbro_hd_part10_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* slowbro_hd_part10_mat0_textures[] = {
    slowbro_tex_80192CA0,
    slowbro_tex_80193960,
};

Texture slowbro_hd_part10_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    slowbro_hd_part10_mat0_textures,
    32,
    0,
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
    64,
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
    { 64, 64, 64, 0 },
    0,
    0,
    0,
    0,
};

Texture* slowbro_hd_part10_mat[] = {
    &slowbro_hd_part10_mat0,
    NULL,
};
#include "assets/river/slowbro/hd_model.vtx.inc.c"
#include "assets/river/slowbro/hd_first.gfx.inc.c"
#include "assets/river/slowbro/hd_part0_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part1_pre.gfx.inc.c"
#include "assets/river/slowbro/hd_part1_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part2_pre.gfx.inc.c"
#include "assets/river/slowbro/hd_part2_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part3_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part4_pre.gfx.inc.c"
#include "assets/river/slowbro/hd_part4_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part5_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part6_pre.gfx.inc.c"
#include "assets/river/slowbro/hd_part6_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part7_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part8_pre.gfx.inc.c"
#include "assets/river/slowbro/hd_part8_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part9_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part10_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part11_pre.gfx.inc.c"
#include "assets/river/slowbro/hd_part11_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part12_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part13_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part14_pre.gfx.inc.c"
#include "assets/river/slowbro/hd_part14_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part15_draw.gfx.inc.c"
#include "assets/river/slowbro/hd_part16_draw.gfx.inc.c"

DObjPayloadTypeI slowbro_hd_gfxdata[] = {
    { NULL, slowbro_hd_first },
    { slowbro_hd_part1_pre, slowbro_hd_part1_draw },
    { slowbro_hd_part2_pre, slowbro_hd_part2_draw },
    { NULL, slowbro_hd_part3_draw },
    { slowbro_hd_part4_pre, slowbro_hd_part4_draw },
    { NULL, slowbro_hd_part5_draw },
    { slowbro_hd_part6_pre, slowbro_hd_part6_draw },
    { NULL, slowbro_hd_part7_draw },
    { slowbro_hd_part8_pre, slowbro_hd_part8_draw },
    { NULL, slowbro_hd_part9_draw },
    { NULL, slowbro_hd_part10_draw },
    { slowbro_hd_part11_pre, slowbro_hd_part11_draw },
    { NULL, slowbro_hd_part12_draw },
    { NULL, slowbro_hd_part13_draw },
    { slowbro_hd_part14_pre, slowbro_hd_part14_draw },
    { NULL, slowbro_hd_part15_draw },
    { NULL, slowbro_hd_part16_draw },
};

UnkEC64Arg3 slowbro_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &slowbro_hd_gfxdata[0],
      { 0.0, 650.0, 150.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowbro_hd_gfxdata[1],
      { 0.0, -50.0, 20.0 },
      { -0.03141599893569946, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_hd_gfxdata[2],
      { 0.0, 500.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_hd_gfxdata[3],
      { 0.0, -69.9990234375, 250.00018310546875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_hd_gfxdata[4],
      { 300.0, 300.00006103515625, 150.00001525878906 },
      { -0.09285800158977509, -0.9820240139961243, 0.38953500986099243 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_hd_gfxdata[5],
      { 200.00003051757812, -50.0, -2.4000000848900527e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_hd_gfxdata[6],
      { -300.0, 300.0, 150.0 },
      { 0.19162799417972565, 4.1255059242248535, -0.6041319966316223 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_hd_gfxdata[7],
      { 200.0, -50.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowbro_hd_gfxdata[8],
      { 0.0, -350.0, -350.0 },
      { 0.07853999733924866, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_hd_gfxdata[9],
      { 0.0, -75.0, -550.0 },
      { -0.07853999733924866, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_hd_gfxdata[10],
      { 70.0, -50.0, -30.000001907348633 },
      { 0.0872659981250763, -0.9599310159683228, 0.0 },
      { 1.2999999523162842, 1.2999999523162842, 1.2999999523162842 } },
    { 2,
      &slowbro_hd_gfxdata[11],
      { 400.0, -100.0, 100.0 },
      { -0.17453299462795258, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_hd_gfxdata[12],
      { 35.00006103515625, -250.0, -100.0 },
      { -0.026179999113082886, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_hd_gfxdata[13],
      { -9.500000305706635e-05, -250.0, 150.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &slowbro_hd_gfxdata[14],
      { -400.0, -100.0, 100.0 },
      { 0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &slowbro_hd_gfxdata[15],
      { 35.000083923339844, -250.0, 100.0 },
      { 0.026179999113082886, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &slowbro_hd_gfxdata[16],
      { -0.0001429999974789098, -250.0, -150.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
