#include "common.h"

extern u8 graveler_tex_8012F0F8[];
extern u8 graveler_tex_8012F118_png[];
extern u8 graveler_tex_8012F320[];
extern u8 graveler_tex_8012F370_png[];
extern u8 graveler_tex_8012FB78[];
extern u8 graveler_tex_8012FBA0[];
extern u8 graveler_tex_8012FDD0[];

extern Texture* graveler_hd_part1_mat[];
extern Gfx graveler_hd_part0_draw[];

Texture** graveler_hd_materials[] = {
    NULL,
    graveler_hd_part1_mat,
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
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* graveler_hd_part1_mat0_textures[] = {
    graveler_tex_8012FBA0,
    graveler_tex_8012FDD0,
    NULL,
};

Texture graveler_hd_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    graveler_hd_part1_mat0_textures,
    32,
    0,
    32,
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
    32,
    32,
    32,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* graveler_hd_part1_mat[] = {
    &graveler_hd_part1_mat0,
    NULL,
};
#include "assets/valley/graveler/hd_model.vtx.inc.c"
#include "assets/valley/graveler/hd_first.gfx.inc.c"
#include "assets/valley/graveler/hd_part0_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part1_pre.gfx.inc.c"
#include "assets/valley/graveler/hd_part1_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part2_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part3_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part4_pre.gfx.inc.c"
#include "assets/valley/graveler/hd_part4_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part5_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part6_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part7_pre.gfx.inc.c"
#include "assets/valley/graveler/hd_part7_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part8_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part9_pre.gfx.inc.c"
#include "assets/valley/graveler/hd_part9_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part10_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part11_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part12_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part13_draw.gfx.inc.c"
#include "assets/valley/graveler/hd_part14_draw.gfx.inc.c"

DObjPayloadTypeI graveler_hd_gfxdata[] = {
    { NULL, graveler_hd_first },
    { graveler_hd_part1_pre, graveler_hd_part1_draw },
    { NULL, graveler_hd_part2_draw },
    { NULL, graveler_hd_part3_draw },
    { graveler_hd_part4_pre, graveler_hd_part4_draw },
    { NULL, graveler_hd_part5_draw },
    { NULL, graveler_hd_part6_draw },
    { graveler_hd_part7_pre, graveler_hd_part7_draw },
    { NULL, graveler_hd_part8_draw },
    { graveler_hd_part9_pre, graveler_hd_part9_draw },
    { NULL, graveler_hd_part10_draw },
    { NULL, graveler_hd_part11_draw },
    { NULL, graveler_hd_part12_draw },
    { NULL, graveler_hd_part13_draw },
    { NULL, graveler_hd_part14_draw },
};

UnkEC64Arg3 graveler_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, -1.2999999853491317e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &graveler_hd_gfxdata[0],
      { -9.40000027185306e-05, 558.0011596679688, -6.901059150695801 },
      { 0.34906598925590515, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &graveler_hd_gfxdata[1],
      { 406.5014343261719, 17.664623260498047, 174.40945434570312 },
      { 3.1415929794311523, 0.17453299462795258, 1.7453290224075317 },
      { 0.9999989867210388, 0.9999979734420776, 0.9999989867210388 } },
    { 3,
      &graveler_hd_gfxdata[2],
      { -6.516408920288086, 225.59237670898438, -17.401683807373047 },
      { 2.007128953933716, 3.1415929794311523, 3.1415929794311523 },
      { 0.9999970197677612, 0.9999989867210388, 0.9999970197677612 } },
    { 4,
      &graveler_hd_gfxdata[3],
      { -18.943357467651367, 251.58377075195312, -3.7327771186828613 },
      { 1.483530044555664, -1.3962630033493042, -1.0471980571746826 },
      { 0.9999960064888, 0.9999979734420776, 0.9999949932098389 } },
    { 2,
      &graveler_hd_gfxdata[4],
      { -406.5014343261719, 17.66486167907715, 174.40939331054688 },
      { 0.0, 3.3161261081695557, 1.3962639570236206 },
      { 0.9999989867210388, 0.9999979734420776, 0.9999989867210388 } },
    { 3,
      &graveler_hd_gfxdata[5],
      { 6.516408920288086, 225.5923309326172, -17.40171241760254 },
      { 2.0071280002593994, -3.1415929794311523, 3.1415929794311523 },
      { 0.9999970197677612, 0.9999989867210388, 0.9999979734420776 } },
    { 4,
      &graveler_hd_gfxdata[6],
      { 18.943262100219727, 251.58372497558594, -3.7327771186828613 },
      { 1.483530044555664, 1.3962630033493042, 1.0471969842910767 },
      { 0.9999960064888, 0.9999989867210388, 0.9999949932098389 } },
    { 2,
      &graveler_hd_gfxdata[7],
      { 365.99945068359375, -178.71559143066406, 270.0173034667969 },
      { 4.71238899230957, -3.1415929794311523, -1.3962630033493042 },
      { 0.9999989867210388, 1.0, 0.9999989867210388 } },
    { 3,
      &graveler_hd_gfxdata[8],
      { -2.4000000848900527e-05, 211.14895629882812, -0.00076299998909235 },
      { 0.0, 0.1745319962501526, -0.43633198738098145 },
      { 0.9999979734420776, 0.9999939799308777, 0.9999979734420776 } },
    { 2,
      &graveler_hd_gfxdata[9],
      { -365.9993591308594, -178.71560668945312, 270.01739501953125 },
      { 1.570796012878418, -9.999999974752427e-07, -1.7453290224075317 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      &graveler_hd_gfxdata[10],
      { 7.200000254670158e-05, 211.14891052246094, -0.0006200000061653554 },
      { 0.0, -6.4577178955078125, 0.43633198738098145 },
      { 0.9999989867210388, 0.9999939799308777, 0.9999979734420776 } },
    { 2,
      &graveler_hd_gfxdata[11],
      { 180.89324951171875, -230.0587921142578, 48.700260162353516 },
      { -0.34906598925590515, 3.1415929794311523, 3.1415929794311523 },
      { 0.9999989867210388, 0.9999979734420776, 0.9999989867210388 } },
    { 3,
      &graveler_hd_gfxdata[12],
      { 15.999210357666016, 269.79693603515625, 85.08988952636719 },
      { 3.1415929794311523, 3.1415929794311523, 3.1415929794311523 },
      { 0.9999960064888, 1.0, 1.0 } },
    { 2,
      &graveler_hd_gfxdata[13],
      { -180.8923797607422, -230.21762084960938, 48.537315368652344 },
      { -0.34906598925590515, 3.1415929794311523, -3.1415929794311523 },
      { 0.9999989867210388, 0.9999979734420776, 0.9999989867210388 } },
    { 3,
      &graveler_hd_gfxdata[14],
      { -16.003631591796875, 269.7023010253906, 84.88247680664062 },
      { 0.0, -6.283185005187988, 0.0 },
      { 0.9999960064888, 1.0, 1.0 } },
    { 1,
      NULL,
      { -0.00037900000461377203, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
