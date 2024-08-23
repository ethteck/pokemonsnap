#include <common.h>

extern u8 magmar_tex0_pal[];
extern u8 magmar_tex0_png[];
extern u8 magmar_tex1_pal[];
extern u8 magmar_tex1_var0_png[];
extern u8 magmar_tex1_var1_png[];
extern u8 magmar_tex1_var2_png[];
extern u8 magmar_tex1_var3_png[];
extern u8 magmar_tex2_pal[];
extern u8 magmar_tex2_png[];
extern u8 magmar_tex3_pal[];
extern u8 magmar_tex3_png[];
extern u8 magmar_tex4_pal[];
extern u8 magmar_tex4_png[];
extern u8 magmar_tex5_pal[];
extern u8 magmar_tex5_png[];
extern u8 magmar_tex6_pal[];
extern u8 magmar_tex6_png[];
extern u8 magmar_tex7_pal[];
extern u8 magmar_tex7_png[];
extern u8 magmar_tex12_var0_png[];
extern u8 magmar_tex12_var1_png[];
extern u8 magmar_tex12_var2_png[];
extern u8 magmar_tex12_var3_png[];

extern Texture* magmar_part3_mat[];
extern Texture* magmar_part5_mat[];
extern Gfx magmar_part0_draw[];

__ALIGNER
u8 magmar_tex8_png[] = {
#include "assets/volcano/magmar/tex8.png.bin.c"
};

__ALIGNER
u8 magmar_tex9_pal[] = {
#include "assets/volcano/magmar/tex9.pal.bin.c"
};

__ALIGNER
u8 magmar_tex9_png[] = {
#include "assets/volcano/magmar/tex9.png.bin.c"
};

__ALIGNER
u8 magmar_tex10_pal[] = {
#include "assets/volcano/magmar/tex10.pal.bin.c"
};

__ALIGNER
u8 magmar_tex10_png[] = {
#include "assets/volcano/magmar/tex10.png.bin.c"
};

__ALIGNER
u8 magmar_tex11_pal[] = {
#include "assets/volcano/magmar/tex11.pal.bin.c"
};

__ALIGNER
u8 magmar_tex11_png[] = {
#include "assets/volcano/magmar/tex11.png.bin.c"
};

Texture** magmar_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    magmar_part3_mat,
    NULL,
    magmar_part5_mat,
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

u8* magmar_part3_mat0_images[] = {
    magmar_tex12_var0_png,
    magmar_tex12_var1_png,
    magmar_tex12_var2_png,
    magmar_tex12_var3_png,
};

u8* magmar_part5_mat0_images[] = {
    magmar_tex1_var0_png,
    magmar_tex1_var1_png,
    magmar_tex1_var2_png,
    magmar_tex1_var3_png,
};

Texture magmar_part3_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    magmar_part3_mat0_images,
    128,
    64,
    16,
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
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    16,
    32,
    16,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    255,
    234,
    0,
    255,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    0x9F9F9F00,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture magmar_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    magmar_part5_mat0_images,
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
    G_IM_SIZ_8b,
    64,
    32,
    64,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    255,
    255,
    255,
    255,
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
    0xFFFFFF00,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture* magmar_part3_mat[] = {
    &magmar_part3_mat0,
    NULL,
};

Texture* magmar_part5_mat[] = {
    &magmar_part5_mat0,
    NULL,
};

#include "assets/volcano/magmar/model.vtx.inc.c"
#include "assets/volcano/magmar/first.gfx.inc.c"
#include "assets/volcano/magmar/part0_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part0_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part0_draw.gfx.inc.c"
#include "assets/volcano/magmar/part1_pre_near.gfx.inc.c"
#include "assets/volcano/magmar/part1_pre_far.gfx.inc.c"
#include "assets/volcano/magmar/part1_pre.gfx.inc.c"
#include "assets/volcano/magmar/part1_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part1_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part1_draw.gfx.inc.c"
#include "assets/volcano/magmar/part2_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part2_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part2_draw.gfx.inc.c"
#include "assets/volcano/magmar/part4_pre_near.gfx.inc.c"
#include "assets/volcano/magmar/part4_pre_far.gfx.inc.c"
#include "assets/volcano/magmar/part4_pre.gfx.inc.c"
#include "assets/volcano/magmar/part4_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part4_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part4_draw.gfx.inc.c"
#include "assets/volcano/magmar/part5_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part5_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part5_draw.gfx.inc.c"
#include "assets/volcano/magmar/part6_pre_near.gfx.inc.c"
#include "assets/volcano/magmar/part6_pre_far.gfx.inc.c"
#include "assets/volcano/magmar/part6_pre.gfx.inc.c"
#include "assets/volcano/magmar/part6_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part6_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part6_draw.gfx.inc.c"
#include "assets/volcano/magmar/part7_pre_near.gfx.inc.c"
#include "assets/volcano/magmar/part7_pre_far.gfx.inc.c"
#include "assets/volcano/magmar/part7_pre.gfx.inc.c"
#include "assets/volcano/magmar/part7_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part7_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part7_draw.gfx.inc.c"
#include "assets/volcano/magmar/part8_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part8_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part8_draw.gfx.inc.c"
#include "assets/volcano/magmar/part9_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part9_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part9_draw.gfx.inc.c"
#include "assets/volcano/magmar/part10_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part10_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part10_draw.gfx.inc.c"
#include "assets/volcano/magmar/part11_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part11_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part11_draw.gfx.inc.c"
#include "assets/volcano/magmar/part12_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part12_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part12_draw.gfx.inc.c"
#include "assets/volcano/magmar/part13_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part13_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part13_draw.gfx.inc.c"
#include "assets/volcano/magmar/part14_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part14_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part14_draw.gfx.inc.c"
#include "assets/volcano/magmar/part15_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part15_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part15_draw.gfx.inc.c"
#include "assets/volcano/magmar/part16_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part16_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part16_draw.gfx.inc.c"
#include "assets/volcano/magmar/part17_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part17_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part17_draw.gfx.inc.c"
#include "assets/volcano/magmar/last.gfx.inc.c"
#include "assets/volcano/magmar/part3_draw_near.gfx.inc.c"
#include "assets/volcano/magmar/part3_draw_far.gfx.inc.c"
#include "assets/volcano/magmar/part3_draw.gfx.inc.c"

DObjPayloadTypeJ magmar_gfxdata[] = {
    { 0, NULL, magmar_first },
    { 4, NULL, NULL },
    { 0, magmar_part1_pre, magmar_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part2_draw },
    { 4, NULL, NULL },
    { 1, NULL, magmar_part3_draw },
    { 4, NULL, NULL },
    { 0, magmar_part4_pre, magmar_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part5_draw },
    { 4, NULL, NULL },
    { 0, magmar_part6_pre, magmar_part6_draw },
    { 4, NULL, NULL },
    { 0, magmar_part7_pre, magmar_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part8_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part9_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part11_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part13_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part14_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part15_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_part16_draw },
    { 4, NULL, NULL },
    { 0, NULL, magmar_last },
    { 4, NULL, NULL },
};

UnkEC64Arg3 magmar_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &magmar_gfxdata[0],
      { 0.0, 424.3455505371094, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magmar_gfxdata[2],
      { 0.0, -210.57264709472656, -298.1397399902344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_gfxdata[4],
      { -3.315152883529663, 30.517101287841797, -267.0002746582031 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32772,
      &magmar_gfxdata[6],
      { 3.315211057662964, 375.7100830078125, -374.8599548339844 },
      { 0.0, 1.570796012878418, 0.0 },
      { 0.5, 0.5, 1.0 } },
    { 2,
      &magmar_gfxdata[8],
      { 0.001636000000871718, 0.004482000134885311, -9.200000204145908e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_gfxdata[10],
      { -2.7339699268341064, 606.449951171875, 126.80000305175781 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 4,
      NULL,
      { -0.0016449999529868364, -182.20425415039062, 214.59317016601562 },
      { 0.0, 0.0, 0.0 },
      { 1.0000009536743164, 1.0, 1.0 } },
    { 4,
      &magmar_gfxdata[12],
      { 151.99977111816406, 399.8900451660156, -160.4530029296875 },
      { -0.2530730068683624, 0.22689299285411835, 0.0 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 4,
      &magmar_gfxdata[14],
      { -152.0, 399.8900451660156, -160.45001220703125 },
      { -0.2530730068683624, -0.22689299285411835, 0.0 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 3,
      &magmar_gfxdata[16],
      { 231.32290649414062, 329.969970703125, 16.660093307495117 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 4,
      &magmar_gfxdata[18],
      { 212.67501831054688, -13.170003890991211, -2.5399999618530273 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_gfxdata[20],
      { -231.32620239257812, 329.969970703125, 16.660093307495117 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 4,
      &magmar_gfxdata[22],
      { -212.67501831054688, -13.170003890991211, -2.5399999618530273 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magmar_gfxdata[24],
      { 229.44000244140625, -86.62554931640625, -149.18002319335938 },
      { 0.0, 0.2932150065898895, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_gfxdata[26],
      { -0.5412099957466125, -196.6002197265625, 33.691490173339844 },
      { 0.0, -0.06544999778270721, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &magmar_gfxdata[28],
      { -10.953497886657715, -107.3598861694336, 19.223134994506836 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &magmar_gfxdata[30],
      { -229.44000244140625, -86.62554931640625, -149.17999267578125 },
      { 0.0, -0.2932150065898895, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &magmar_gfxdata[32],
      { 0.5412099957466125, -196.6002197265625, 33.69145202636719 },
      { 0.0, 0.06544999778270721, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &magmar_gfxdata[34],
      { 10.953474044799805, -107.3598861694336, 19.223134994506836 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
