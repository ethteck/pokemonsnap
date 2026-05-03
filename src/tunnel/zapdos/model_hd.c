#include "common.h"

extern u8 zapdos_tex_80182968[];
extern u8 zapdos_tex_80182990_png[];
extern u8 zapdos_tex_80182B98[];
extern u8 zapdos_tex_80182BC0[];
extern u8 zapdos_tex_80182FF0[];
extern u8 zapdos_tex_801833F8[];
extern u8 zapdos_tex_80183420_png[];
extern u8 zapdos_tex_80183628[];
extern u8 zapdos_tex_80183650_png[];
extern u8 zapdos_tex_80183858[];
extern u8 zapdos_tex_80183880_png[];
extern u8 zapdos_tex_80183A88[];
extern u8 zapdos_tex_80183AB0_png[];
extern u8 zapdos_tex_80183CB8[];
extern u8 zapdos_tex_80183CE0_png[];

extern Texture* zapdos_hd_part14_mat[];
extern Gfx zapdos_hd_part0_draw[];

Texture** zapdos_hd_materials[] = {
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
    zapdos_hd_part14_mat,
    NULL,
    NULL,
};

u8* zapdos_hd_part14_mat0_textures[] = {
    zapdos_tex_80182BC0,
    zapdos_tex_80182FF0,
    NULL,
};

Texture zapdos_hd_part14_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    zapdos_hd_part14_mat0_textures,
    32,
    0,
    32,
    64,
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
    64,
    32,
    64,
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

Texture* zapdos_hd_part14_mat[] = {
    &zapdos_hd_part14_mat0,
    NULL,
};
#include "assets/tunnel/zapdos/hd_model.vtx.inc.c"
#include "assets/tunnel/zapdos/hd_first.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part0_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part1_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part2_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part3_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part4_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part5_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part6_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part7_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part8_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part9_pre.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part9_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part10_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part11_pre.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part11_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part12_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part13_pre.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part13_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part14_draw.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part15_pre.gfx.inc.c"
#include "assets/tunnel/zapdos/hd_part15_draw.gfx.inc.c"

DObjPayloadTypeI zapdos_hd_gfxdata[] = {
    { NULL, zapdos_hd_first },
    { NULL, zapdos_hd_part1_draw },
    { NULL, zapdos_hd_part2_draw },
    { NULL, zapdos_hd_part3_draw },
    { NULL, zapdos_hd_part4_draw },
    { NULL, zapdos_hd_part5_draw },
    { NULL, zapdos_hd_part6_draw },
    { NULL, zapdos_hd_part7_draw },
    { NULL, zapdos_hd_part8_draw },
    { zapdos_hd_part9_pre, zapdos_hd_part9_draw },
    { NULL, zapdos_hd_part10_draw },
    { zapdos_hd_part11_pre, zapdos_hd_part11_draw },
    { NULL, zapdos_hd_part12_draw },
    { zapdos_hd_part13_pre, zapdos_hd_part13_draw },
    { NULL, zapdos_hd_part14_draw },
    { zapdos_hd_part15_pre, zapdos_hd_part15_draw },
};

UnkEC64Arg3 zapdos_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &zapdos_hd_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { -0.1899999976158142, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zapdos_hd_gfxdata[1],
      { 82.872802734375, -55.99113845825195, 64.18688201904297 },
      { -0.6007009744644165, 0.4701859951019287, 0.2896830141544342 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zapdos_hd_gfxdata[2],
      { -6.82215690612793, -222.85360717773438, -0.6740509867668152 },
      { -0.7771989703178406, 0.29618000984191895, -0.2731480002403259 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &zapdos_hd_gfxdata[3],
      { 2.454828977584839, -274.9916076660156, 14.935794830322266 },
      { -0.0899989977478981, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &zapdos_hd_gfxdata[4],
      { 2.700000004551839e-05, 4.8000001697801054e-05, -2.4000000848900527e-05 },
      { 0.3720000088214874, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zapdos_hd_gfxdata[5],
      { -82.872802734375, -55.99113845825195, 64.18688201904297 },
      { 0.6007009744644165, 2.6714069843292236, -0.2896830141544342 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zapdos_hd_gfxdata[6],
      { -6.82215690612793, -222.85360717773438, 0.6740509867668152 },
      { 0.7771980166435242, -0.29618000984191895, -0.2731480002403259 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &zapdos_hd_gfxdata[7],
      { 2.4548261165618896, -274.9916076660156, -14.935782432556152 },
      { 0.0899989977478981, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &zapdos_hd_gfxdata[8],
      { 9.000000318337698e-06, 0.0, -2.4000000848900527e-05 },
      { -0.3720000088214874, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zapdos_hd_gfxdata[9],
      { 105.61949920654297, 56.316471099853516, -11.021894454956055 },
      { 0.2967059910297394, 0.5826650261878967, 0.4535990059375763 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zapdos_hd_gfxdata[10],
      { 601.9560546875, 274.74755859375, 4.984521865844727 },
      { 0.0, 0.0, 0.0 },
      { 1.1160000562667847, 1.0, 1.0 } },
    { 2,
      &zapdos_hd_gfxdata[11],
      { -105.62000274658203, 56.31999969482422, -11.019998550415039 },
      { 0.2967059910297394, -0.5826650261878967, -0.4535990059375763 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zapdos_hd_gfxdata[12],
      { -614.8348999023438, 275.3126220703125, 11.019963264465332 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zapdos_hd_gfxdata[13],
      { 0.0, 338.2582702636719, 163.797607421875 },
      { 0.48700401186943054, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &zapdos_hd_gfxdata[14],
      { 0.0, -4.528189182281494, 240.2275848388672 },
      { -0.36427998542785645, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &zapdos_hd_gfxdata[15],
      { 0.0, -239.406494140625, -50.560855865478516 },
      { 0.313726007938385, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
