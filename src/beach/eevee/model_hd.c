#include "common.h"

extern u8 eevee_tex_80161AF8[];
extern u8 eevee_tex_80161B20_png[];
extern u8 eevee_tex_80161F50[];
extern u8 eevee_tex_80162380[];
extern u8 eevee_tex_801627B0[];
extern u8 eevee_tex_80162BB8[];
extern u8 eevee_tex_80162BE0[];
extern u8 eevee_tex_80163010[];
extern u8 eevee_tex_80163440[];
extern u8 eevee_tex_80163848[];
extern u8 eevee_tex_80163870[];
extern u8 eevee_tex_80163CA0[];
extern u8 eevee_tex_801640A8[];
extern u8 eevee_tex_801640D0_png[];
extern u8 eevee_tex_801644D8[];
extern u8 eevee_tex_801645D8_png[];
extern u8 eevee_tex_80164BE0[];
extern u8 eevee_tex_80164C08_png[];

extern Texture* eevee_hd_part8_mat[];
extern Gfx eevee_hd_part0_draw[];

Texture** eevee_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    eevee_hd_part8_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* eevee_hd_part8_mat0_textures[] = {
    eevee_tex_80163870,
    eevee_tex_80163010,
    eevee_tex_80163440,
    eevee_tex_80163CA0,
};

u8* eevee_hd_part8_mat1_textures[] = {
    eevee_tex_80162BE0,
    eevee_tex_80162380,
    eevee_tex_80161F50,
    eevee_tex_801627B0,
};

Texture eevee_hd_part8_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    eevee_hd_part8_mat0_textures,
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
    { 23, 23, 23, 0 },
    0,
    0,
    0,
    0,
};

Texture eevee_hd_part8_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    eevee_hd_part8_mat1_textures,
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
    { 23, 23, 23, 0 },
    0,
    0,
    0,
    0,
};

Texture* eevee_hd_part8_mat[] = {
    &eevee_hd_part8_mat0,
    &eevee_hd_part8_mat1,
    NULL,
    NULL,
};
#include "assets/beach/eevee/hd_model.vtx.inc.c"
#include "assets/beach/eevee/hd_first.gfx.inc.c"
#include "assets/beach/eevee/hd_part0_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part1_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part2_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part3_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part4_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part5_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part6_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part7_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part8_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part9_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part10_draw.gfx.inc.c"
#include "assets/beach/eevee/hd_part11_draw.gfx.inc.c"

UnkEC64Arg3 eevee_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.18000000715255737, 0.18000000715255737, 0.18000000715255737 } },
    { 1,
      NULL,
      { 0.0, 966.730712890625, 364.5227966308594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_hd_first,
      { 0.0, -58.600711822509766, 17.599319458007812 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_hd_part1_draw,
      { 239.03274536132812, -38.24605941772461, -705.522216796875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      eevee_hd_part2_draw,
      { 20.738983154296875, -471.87213134765625, -76.29306030273438 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_hd_part3_draw,
      { -242.10357666015625, -38.24605941772461, -705.522216796875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      eevee_hd_part4_draw,
      { -20.742225646972656, -471.87213134765625, -76.2918701171875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_hd_part5_draw,
      { 0.0, -5.901908874511719, -770.6502685546875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_hd_part6_draw,
      { -0.0005879999953322113, 108.0007553100586, -44.71745300292969 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_hd_part7_draw,
      { 240.1630401611328, 358.7537841796875, 149.78443908691406 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_hd_part8_draw,
      { -240.17298889160156, 358.7537841796875, 149.78443908691406 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_hd_part9_draw,
      { 0.0, 38.600921630859375, -88.98639678955078 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_hd_part10_draw,
      { 137.79910278320312, -71.75607299804688, 16.608858108520508 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_hd_part11_draw,
      { -140.8604278564453, -71.75607299804688, 16.608858108520508 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
