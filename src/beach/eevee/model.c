#include "common.h"

extern u8 eevee_tex_80163870[];
extern u8 eevee_tex_80163010[];
extern u8 eevee_tex_80163440[];
extern u8 eevee_tex_80163CA0[];
extern u8 eevee_tex_80162BE0[];
extern u8 eevee_tex_80162380[];
extern u8 eevee_tex_80161F50[];
extern u8 eevee_tex_801627B0[];
extern u8 eevee_tex_80161B20_png[];
extern u8 eevee_tex_801640D0_png[];
extern u8 eevee_tex_801645D8_png[];
extern u8 eevee_tex_80164C08_png[];
extern u8 eevee_tex_80161AF8[];
extern u8 eevee_tex_80162BB8[];
extern u8 eevee_tex_80163848[];
extern u8 eevee_tex_801640A8[];
extern u8 eevee_tex_801644D8[];
extern u8 eevee_tex_80164BE0[];

Gfx eevee_part0_draw[];

Texture* eevee_part8_mat[];

Texture** D_beach_803200D0[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    eevee_part8_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* eevee_part8_mat0_textures[] = {
    eevee_tex_80163870,
    eevee_tex_80163010,
    eevee_tex_80163440,
    eevee_tex_80163CA0,
};

u8* eevee_part8_mat1_textures[] = {
    eevee_tex_80162BE0,
    eevee_tex_80162380,
    eevee_tex_80161F50,
    eevee_tex_801627B0,
};

Texture eevee_part8_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    eevee_part8_mat0_textures,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 23, 23, 23, 0 },
    0,
    0,
    0,
    0,
};

Texture eevee_part8_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    eevee_part8_mat1_textures,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 23, 23, 23, 0 },
    0,
    0,
    0,
    0,
};

Texture* eevee_part8_mat[] = {
    &eevee_part8_mat0,
    &eevee_part8_mat1,
    NULL,
    NULL,
};

#include "assets/beach/eevee/model.vtx.inc.c"
#include "assets/beach/eevee/first.gfx.inc.c"
#include "assets/beach/eevee/part0_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part0_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part0_draw.gfx.inc.c"
#include "assets/beach/eevee/part1_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part1_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part1_draw.gfx.inc.c"
#include "assets/beach/eevee/part2_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part2_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part2_draw.gfx.inc.c"
#include "assets/beach/eevee/part3_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part3_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part3_draw.gfx.inc.c"
#include "assets/beach/eevee/part4_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part4_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part4_draw.gfx.inc.c"
#include "assets/beach/eevee/part5_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part5_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part5_draw.gfx.inc.c"
#include "assets/beach/eevee/part6_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part6_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part6_draw.gfx.inc.c"
#include "assets/beach/eevee/part7_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part7_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part7_draw.gfx.inc.c"
#include "assets/beach/eevee/part8_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part8_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part8_draw.gfx.inc.c"
#include "assets/beach/eevee/part9_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part9_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part9_draw.gfx.inc.c"
#include "assets/beach/eevee/part10_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part10_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part10_draw.gfx.inc.c"
#include "assets/beach/eevee/part11_draw_near.gfx.inc.c"
#include "assets/beach/eevee/part11_draw_far.gfx.inc.c"
#include "assets/beach/eevee/part11_draw.gfx.inc.c"
#include "assets/beach/eevee/last.gfx.inc.c"

UnkEC64Arg3 eevee_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.18000000715255737, 0.18000000715255737, 0.18000000715255737 } },
    { 1,
      NULL,
      { 0.0, 966.7305908203125, 364.5227966308594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_first,
      { 0.0, -58.600616455078125, 23.936485290527344 },
      { 0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_part1_draw,
      { 239.0373992919922, -74.10125732421875, -712.4563598632812 },
      { -0.03999999910593033, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      eevee_part2_draw,
      { 20.74141502380371, -471.8727111816406, -76.2919921875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_part3_draw,
      { -242.0983123779297, -74.10125732421875, -712.4563598632812 },
      { -0.03999999910593033, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      eevee_part4_draw,
      { -20.741771697998047, -471.8727111816406, -76.2919921875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_part5_draw,
      { 0.0018129999516531825, -44.38676834106445, -778.8237915039062 },
      { -0.03999999910593033, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_part6_draw,
      { 0.0018129999516531825, 100.49858093261719, -47.552085876464844 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_part7_draw,
      { 240.1652374267578, 358.7564392089844, 149.77981567382812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      eevee_part8_draw,
      { -240.16905212402344, 358.7564392089844, 149.77981567382812 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_part9_draw,
      { 0.0018129999516531825, 31.104183197021484, -91.82343292236328 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_part10_draw,
      { 137.79920959472656, -79.25262451171875, 13.77856731414795 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      eevee_last,
      { -137.79920959472656, -79.25262451171875, 13.77856731414795 },
      { 0.019999999552965164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
