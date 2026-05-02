#include "common.h"

extern u8 sandslash_tex_80169CF8[];
extern u8 sandslash_tex_80169D20_png[];
extern u8 sandslash_tex_80169F28[];
extern u8 sandslash_tex_80169F50_png[];
extern u8 sandslash_tex_8016A158[];
extern u8 sandslash_tex_8016A180_png[];
extern u8 sandslash_tex_8016A1D0[];
extern u8 sandslash_tex_8016A600[];
extern u8 sandslash_tex_8016AA08[];
extern u8 sandslash_tex_8016AA30[];
extern u8 sandslash_tex_8016AE38[];
extern u8 sandslash_tex_8016AE60_png[];
extern u8 sandslash_tex_8016AEE8[];

extern u8 D_8016A2D8_valley_extra[];
extern u8 D_8016A300_valley_extra[];
extern u8 D_8016A508_valley_extra[];
extern u8 D_8016A530_valley_extra[];
extern u8 D_8016A738_valley_extra[];
extern u8 D_8016A760_valley_extra[];
extern u8 D_8016AFE8_valley_extra[];
extern u8 D_8016B418_valley_extra[];
extern u8 D_8016B440_valley_extra[];
extern u8 D_8016B4C8_valley_extra[];
extern u8 D_801A5EF0_valley_extra[];
extern u8 D_801A60D0_valley_extra[];
extern u8 D_801A61F0_valley_extra[];
extern u8 D_801A6210_valley_extra[];
extern u8 D_801A6220_valley_extra[];
extern u8 D_801A6230_valley_extra[];
extern u8 D_801A6240_valley_extra[];
extern u8 D_801A6260_valley_extra[];
extern u8 D_801A6270_valley_extra[];
extern u8 D_801A62A0_valley_extra[];
extern u8 D_801A62B0_valley_extra[];
extern u8 D_801A62C0_valley_extra[];
extern u8 D_801A62F0_valley_extra[];
extern u8 D_801A6300_valley_extra[];
extern u8 D_801A6310_valley_extra[];
extern u8 D_801A6320_valley_extra[];
extern u8 D_801A6330_valley_extra[];
extern u8 D_801A6340_valley_extra[];
extern u8 D_801A6350_valley_extra[];
extern u8 D_801A6380_valley_extra[];
extern u8 D_801A6390_valley_extra[];
extern u8 D_801A63A0_valley_extra[];
extern u8 D_801A63B0_valley_extra[];
extern u8 D_801A63C0_valley_extra[];
extern u8 D_801A63F0_valley_extra[];
extern u8 D_801A6410_valley_extra[];
extern u8 D_801A6420_valley_extra[];
extern u8 D_801A6430_valley_extra[];
extern u8 D_801A6440_valley_extra[];
extern u8 D_801A6450_valley_extra[];
extern u8 D_801A64A0_valley_extra[];
extern u8 D_801A64F0_valley_extra[];
extern u8 D_801A6550_valley_extra[];
extern u8 D_801A65F0_valley_extra[];
extern u8 D_801A6670_valley_extra[];
extern u8 D_801A66C0_valley_extra[];
extern u8 D_801A6710_valley_extra[];
extern u8 D_801A6770_valley_extra[];
extern u8 D_801A6810_valley_extra[];
extern u8 D_801A6890_valley_extra[];
extern u8 D_801A68A0_valley_extra[];
extern u8 D_801A68C0_valley_extra[];
extern u8 D_801A6910_valley_extra[];
extern u8 D_801A6930_valley_extra[];
extern u8 D_801A6960_valley_extra[];
extern u8 D_801A6980_valley_extra[];
extern u8 D_801A69C0_valley_extra[];
extern u8 D_801A69E0_valley_extra[];
extern u8 D_801A69F0_valley_extra[];
extern u8 D_801A6A20_valley_extra[];
extern u8 D_801A6A30_valley_extra[];
extern u8 D_801A6A70_valley_extra[];
extern u8 D_801A6A80_valley_extra[];
extern u8 D_801A6A90_valley_extra[];
extern u8 D_801A6C20_valley_extra[];
extern u8 D_801A6D80_valley_extra[];
extern u8 D_801A6DB0_valley_extra[];
extern u8 D_801A6EB0_valley_extra[];
extern u8 D_801A6FA0_valley_extra[];
extern u8 D_801A6FD0_valley_extra[];
extern u8 D_801A6FF0_valley_extra[];
extern u8 D_801A7000_valley_extra[];
extern u8 D_801A7070_valley_extra[];
extern u8 D_801A7100_valley_extra[];
extern u8 D_801A71D0_valley_extra[];
extern u8 D_801A7250_valley_extra[];
extern u8 D_801A7280_valley_extra[];
extern u8 D_801A7290_valley_extra[];
extern u8 D_801A72D0_valley_extra[];
extern u8 D_801A7330_valley_extra[];
extern u8 D_801A7410_valley_extra[];
extern u8 D_801A75C0_valley_extra[];
extern u8 D_801A7780_valley_extra[];
extern u8 D_801A77B0_valley_extra[];
extern u8 D_801A77C0_valley_extra[];
extern u8 D_801A77E0_valley_extra[];
extern u8 D_801A7910_valley_extra[];
extern u8 D_801A7920_valley_extra[];
extern u8 D_801A7980_valley_extra[];
extern u8 D_801A79D0_valley_extra[];
extern u8 D_801A7AA0_valley_extra[];
extern u8 D_801A7AE0_valley_extra[];
extern u8 D_801A7B40_valley_extra[];
extern u8 D_801A7B90_valley_extra[];
extern u8 D_801A7C40_valley_extra[];
extern u8 D_801A7C80_valley_extra[];
extern u8 D_801A7CC0_valley_extra[];
extern u8 D_801A7D00_valley_extra[];

extern Texture* sandslash_hd_part9_mat[];
extern Gfx sandslash_hd_part0_draw[];

Texture** sandslash_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    sandslash_hd_part9_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* sandslash_hd_part9_mat0_textures[] = {
    sandslash_tex_8016AA30,
    sandslash_tex_8016A600,
    sandslash_tex_8016A1D0,
    NULL,
};

Texture sandslash_hd_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    sandslash_hd_part9_mat0_textures,
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
    0xA1,
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
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* sandslash_hd_part9_mat[] = {
    &sandslash_hd_part9_mat0,
    NULL,
};
#include "assets/valley/sandslash/hd_model.vtx.inc.c"
#include "assets/valley/sandslash/hd_first.gfx.inc.c"
#include "assets/valley/sandslash/hd_part0_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part1_pre.gfx.inc.c"
#include "assets/valley/sandslash/hd_part1_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part2_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part3_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part4_pre.gfx.inc.c"
#include "assets/valley/sandslash/hd_part4_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part5_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part6_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part7_pre.gfx.inc.c"
#include "assets/valley/sandslash/hd_part7_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part8_pre.gfx.inc.c"
#include "assets/valley/sandslash/hd_part8_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part9_pre.gfx.inc.c"
#include "assets/valley/sandslash/hd_part9_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part10_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part11_pre.gfx.inc.c"
#include "assets/valley/sandslash/hd_part11_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part12_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part13_pre.gfx.inc.c"
#include "assets/valley/sandslash/hd_part13_draw.gfx.inc.c"
#include "assets/valley/sandslash/hd_part14_draw.gfx.inc.c"

DObjPayloadTypeI sandslash_hd_gfxdata[] = {
    { NULL, sandslash_hd_first },
    { sandslash_hd_part1_pre, sandslash_hd_part1_draw },
    { NULL, sandslash_hd_part2_draw },
    { NULL, sandslash_hd_part3_draw },
    { sandslash_hd_part4_pre, sandslash_hd_part4_draw },
    { NULL, sandslash_hd_part5_draw },
    { NULL, sandslash_hd_part6_draw },
    { sandslash_hd_part7_pre, sandslash_hd_part7_draw },
    { sandslash_hd_part8_pre, sandslash_hd_part8_draw },
    { sandslash_hd_part9_pre, sandslash_hd_part9_draw },
    { NULL, sandslash_hd_part10_draw },
    { sandslash_hd_part11_pre, sandslash_hd_part11_draw },
    { NULL, sandslash_hd_part12_draw },
    { sandslash_hd_part13_pre, sandslash_hd_part13_draw },
    { NULL, sandslash_hd_part14_draw },
};

UnkEC64Arg3 sandslash_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &sandslash_hd_gfxdata[0],
      { 0.0, 318.14788818359375, -115.15362548828125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandslash_hd_gfxdata[1],
      { 140.4499969482422, -7.608938217163086, -10.274052619934082 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_hd_gfxdata[2],
      { 62.826751708984375, -99.70198059082031, 141.01756286621094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &sandslash_hd_gfxdata[3],
      { -36.97675323486328, -147.65614318847656, -145.81443786621094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandslash_hd_gfxdata[4],
      { -140.45120239257812, -7.608891010284424, -10.274076461791992 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_hd_gfxdata[5],
      { -62.82559585571289, -99.7020034790039, 141.01760864257812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &sandslash_hd_gfxdata[6],
      { 36.978004455566406, -147.6562042236328, -145.8144989013672 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandslash_hd_gfxdata[7],
      { 0.0, 144.34228515625, 91.30465698242188 },
      { 0.46000000834465027, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_hd_gfxdata[8],
      { -0.0005959999980404973, 216.07107543945312, -1.0653020143508911 },
      { 0.11999999731779099, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_hd_gfxdata[9],
      { 166.71458435058594, 138.47970581054688, 18.645381927490234 },
      { 0.46000000834465027, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &sandslash_hd_gfxdata[10],
      { 65.04095458984375, -21.046018600463867, 163.2525634765625 },
      { -0.6774920225143433, 0.11164700239896774, 0.3083859980106354 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_hd_gfxdata[11],
      { -166.70999145507812, 138.47970581054688, 18.645381927490234 },
      { 0.46000000834465027, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &sandslash_hd_gfxdata[12],
      { -70.25313568115234, -17.422794342041016, 162.1907196044922 },
      { -0.6787469983100891, -0.042201001197099686, -0.3612399995326996 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &sandslash_hd_gfxdata[13],
      { 0.0, -90.48607635498047, -174.37278747558594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &sandslash_hd_gfxdata[14],
      { 0.0, -67.3880615234375, -212.453369140625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
