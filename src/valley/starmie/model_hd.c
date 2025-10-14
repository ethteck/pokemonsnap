#include "common.h"

extern u8 starmie_tex_80171858[];
extern u8 starmie_tex_80171A60[];
extern u8 starmie_tex_80172450[];
extern u8 starmie_tex_80172E40[];
extern u8 starmie_tex_80173628[];
extern u8 starmie_tex_80173650_png[];

extern Texture* starmie_hd_part9_mat[];
extern Gfx starmie_hd_part0_draw[];

Texture** starmie_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    starmie_hd_part9_mat,
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

u8* starmie_hd_part9_mat0_textures[] = {
    starmie_tex_80171A60,
    starmie_tex_80172450,
    starmie_tex_80172E40,
};

u8* starmie_hd_part9_mat1_textures[] = {
    starmie_tex_80171A60,
    starmie_tex_80172450,
    starmie_tex_80172E40,
};

Texture starmie_hd_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    starmie_hd_part9_mat0_textures,
    32,
    0,
    42,
    42,
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
    G_IM_SIZ_8b,
    42,
    42,
    42,
    42,
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

Texture starmie_hd_part9_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    starmie_hd_part9_mat1_textures,
    32,
    0,
    42,
    42,
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
    G_IM_SIZ_8b,
    42,
    42,
    42,
    42,
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

Texture* starmie_hd_part9_mat[] = {
    &starmie_hd_part9_mat0,
    &starmie_hd_part9_mat1,
    NULL,
    NULL,
};
#include "assets/valley/starmie/hd_model.vtx.inc.c"
#include "assets/valley/starmie/hd_first.gfx.inc.c"
#include "assets/valley/starmie/hd_part0_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part1_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part2_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part2_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part3_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part3_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part4_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part4_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part5_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part5_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part6_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part6_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part7_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part8_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part8_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part9_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part10_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part10_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part11_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part12_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part12_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part13_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part14_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part14_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part15_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part16_pre.gfx.inc.c"
#include "assets/valley/starmie/hd_part16_draw.gfx.inc.c"
#include "assets/valley/starmie/hd_part17_draw.gfx.inc.c"

DObjPayloadTypeI starmie_hd_gfxdata[] = {
    { NULL, starmie_hd_first },
    { NULL, starmie_hd_part1_draw },
    { starmie_hd_part2_pre, starmie_hd_part2_draw },
    { starmie_hd_part3_pre, starmie_hd_part3_draw },
    { starmie_hd_part4_pre, starmie_hd_part4_draw },
    { starmie_hd_part5_pre, starmie_hd_part5_draw },
    { starmie_hd_part6_pre, starmie_hd_part6_draw },
    { NULL, starmie_hd_part7_draw },
    { starmie_hd_part8_pre, starmie_hd_part8_draw },
    { NULL, starmie_hd_part9_draw },
    { starmie_hd_part10_pre, starmie_hd_part10_draw },
    { NULL, starmie_hd_part11_draw },
    { starmie_hd_part12_pre, starmie_hd_part12_draw },
    { NULL, starmie_hd_part13_draw },
    { starmie_hd_part14_pre, starmie_hd_part14_draw },
    { NULL, starmie_hd_part15_draw },
    { starmie_hd_part16_pre, starmie_hd_part16_draw },
    { NULL, starmie_hd_part17_draw },
};

UnkEC64Arg3 starmie_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.2967059910297394, -0.17453299462795258, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, -10.768391609191895, 3.0792460441589355 },
      { -0.2825529873371124, 0.166936993598938, -0.0482029989361763 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &starmie_hd_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &starmie_hd_gfxdata[1],
      { 0.0, 0.0, -100.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[2],
      { 217.99330139160156, 300.4295959472656, 0.0 },
      { 0.0, 0.0, -0.6981319785118103 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[3],
      { 352.9992980957031, -114.95439910888672, 0.0 },
      { 0.0, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[4],
      { 0.0, -372.0902099609375, 100.0 },
      { 0.0, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[5],
      { -353.2117004394531, -114.95439910888672, 0.0 },
      { 0.0, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[6],
      { -218.43418884277344, 300.24468994140625, 0.0 },
      { 0.0, 0.0, -0.34906598925590515 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &starmie_hd_gfxdata[7],
      { 14.482519149780273, 24.013784408569336, 78.5455551147461 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &starmie_hd_gfxdata[8],
      { 0.0, 222.58119201660156, 0.0 },
      { 0.3200620114803314, 0.0, -0.06408599764108658 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[9],
      { 0.0, 148.59030151367188, 0.0 },
      { 0.2452619969844818, 0.0, -0.1595340073108673 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &starmie_hd_gfxdata[10],
      { 211.843994140625, 68.68280029296875, 0.0 },
      { 0.42199599742889404, 0.0, -0.7823590040206909 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[11],
      { 0.2935050129890442, 148.73715209960938, 0.0 },
      { 0.5251250267028809, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &starmie_hd_gfxdata[12],
      { 130.86399841308594, -180.6512908935547, 0.0 },
      { 0.42199599742889404, 0.0, -2.4118099212646484 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[13],
      { 0.5568600296974182, 148.52362060546875, 0.0 },
      { 0.2452619969844818, 0.0, -0.07623200118541718 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &starmie_hd_gfxdata[14],
      { -131.08489990234375, -180.3354949951172, 0.0 },
      { 0.42199599742889404, 0.0, -3.866192102432251 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[15],
      { -0.03541100025177002, 148.95834350585938, 0.0 },
      { 0.2452619969844818, 0.0, -6.216949939727783 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &starmie_hd_gfxdata[16],
      { -211.92080688476562, 68.69020080566406, 0.0 },
      { 0.42199599742889404, 0.0, 0.7843589782714844 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &starmie_hd_gfxdata[17],
      { -0.0418040007352829, 148.78280639648438, 0.0 },
      { 0.5251250267028809, 0.0, -0.0020000000949949026 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
