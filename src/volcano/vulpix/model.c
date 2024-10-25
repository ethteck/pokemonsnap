#include <common.h>

extern u8 vulpix_tex0_pal[];
extern u8 vulpix_tex0_png[];
extern u8 vulpix_tex1_pal[];
extern u8 vulpix_tex1_png[];
extern u8 vulpix_tex2_pal[];
extern u8 vulpix_tex2_png[];
extern u8 vulpix_tex3_pal[];
extern u8 vulpix_tex3_png[];
extern u8 vulpix_tex4_pal[];
extern u8 vulpix_tex4_png[];
extern u8 vulpix_tex5_pal[];
extern u8 vulpix_tex5_png[];
extern u8 vulpix_tex6_pal[];
extern u8 vulpix_tex6_png[];
extern u8 vulpix_tex7_pal[];
extern u8 vulpix_tex7_png[];
extern u8 vulpix_tex8_var0_pal[];
extern u8 vulpix_tex8_var0_png[];
extern u8 vulpix_tex8_var1_png[];
extern u8 vulpix_tex8_var2_png[];
extern u8 vulpix_tex8_var3_png[];
extern u8 vulpix_tex8_var4_png[];
extern u8 vulpix_tex9_pal[];
extern u8 vulpix_tex9_png[];
extern u8 vulpix_tex10_pal[];
extern u8 vulpix_tex10_png[];
extern u8 vulpix_tex11_pal[];
extern u8 vulpix_tex11_png[];
extern Texture* vulpix_part5_mat[];
extern Gfx vulpix_part0_draw[];

Texture** vulpix_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    vulpix_part5_mat,
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

u8* vulpix_part5_mat0_textures[] = {
    vulpix_tex8_var0_png,
    vulpix_tex8_var1_png,
    vulpix_tex8_var2_png,
    vulpix_tex8_var3_png,
    vulpix_tex8_var4_png,
};

u8* vulpix_part5_mat1_textures[] = {
    vulpix_tex8_var0_png,
    vulpix_tex8_var1_png,
    vulpix_tex8_var2_png,
    vulpix_tex8_var3_png,
    vulpix_tex8_var4_png,
};

Texture vulpix_part5_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    vulpix_part5_mat0_textures,
    128,
    64,
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
    G_IM_SIZ_8b,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture vulpix_part5_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    vulpix_part5_mat1_textures,
    128,
    64,
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
    G_IM_SIZ_8b,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* vulpix_part5_mat[] = {
    &vulpix_part5_mat0,
    &vulpix_part5_mat1,
    NULL,
};

#include "assets/volcano/vulpix/model.vtx.inc.c"
#include "assets/volcano/vulpix/first.gfx.inc.c"
#include "assets/volcano/vulpix/part0_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part0_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part0_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part1_pre_near.gfx.inc.c"
#include "assets/volcano/vulpix/part1_pre_far.gfx.inc.c"
#include "assets/volcano/vulpix/part1_pre.gfx.inc.c"
#include "assets/volcano/vulpix/part1_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part1_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part1_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part2_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part2_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part2_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part3_pre_near.gfx.inc.c"
#include "assets/volcano/vulpix/part3_pre_far.gfx.inc.c"
#include "assets/volcano/vulpix/part3_pre.gfx.inc.c"
#include "assets/volcano/vulpix/part3_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part3_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part3_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part4_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part4_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part4_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part5_pre_near.gfx.inc.c"
#include "assets/volcano/vulpix/part5_pre_far.gfx.inc.c"
#include "assets/volcano/vulpix/part5_pre.gfx.inc.c"
#include "assets/volcano/vulpix/part5_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part5_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part5_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part6_pre_near.gfx.inc.c"
#include "assets/volcano/vulpix/part6_pre_far.gfx.inc.c"
#include "assets/volcano/vulpix/part6_pre.gfx.inc.c"
#include "assets/volcano/vulpix/part6_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part6_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part6_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part7_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part7_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part7_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part8_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part8_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part8_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part9_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part9_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part9_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part10_pre_near.gfx.inc.c"
#include "assets/volcano/vulpix/part10_pre_far.gfx.inc.c"
#include "assets/volcano/vulpix/part10_pre.gfx.inc.c"
#include "assets/volcano/vulpix/part10_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part10_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part10_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part11_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part11_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part11_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part12_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part12_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part12_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part13_pre_near.gfx.inc.c"
#include "assets/volcano/vulpix/part13_pre_far.gfx.inc.c"
#include "assets/volcano/vulpix/part13_pre.gfx.inc.c"
#include "assets/volcano/vulpix/part13_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part13_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part13_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part14_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part14_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part14_draw.gfx.inc.c"
#include "assets/volcano/vulpix/part15_draw_near.gfx.inc.c"
#include "assets/volcano/vulpix/part15_draw_far.gfx.inc.c"
#include "assets/volcano/vulpix/part15_draw.gfx.inc.c"
#include "assets/volcano/vulpix/last.gfx.inc.c"

DObjPayloadTypeI vulpix_gfxdata[] = {
    { NULL, vulpix_first },
    { vulpix_part1_pre, vulpix_part1_draw },
    { NULL, vulpix_part2_draw },
    { vulpix_part3_pre, vulpix_part3_draw },
    { NULL, vulpix_part4_draw },
    { vulpix_part5_pre, vulpix_part5_draw },
    { vulpix_part6_pre, vulpix_part6_draw },
    { NULL, vulpix_part7_draw },
    { NULL, vulpix_part8_draw },
    { NULL, vulpix_part9_draw },
    { vulpix_part10_pre, vulpix_part10_draw },
    { NULL, vulpix_part11_draw },
    { NULL, vulpix_part12_draw },
    { vulpix_part13_pre, vulpix_part13_draw },
    { NULL, vulpix_part14_draw },
    { NULL, vulpix_last },
};

UnkEC64Arg3 vulpix_model[] = {
    { 0,
      NULL,
      { 0.0, 3.0369279384613037, 4.8000001697801054e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &vulpix_gfxdata[0],
      { 0.0, 236.1630859375, 104.4000015258789 },
      { 0.0, 0.0, -0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vulpix_gfxdata[1],
      { 91.48157501220703, -51.45460510253906, 40.6544075012207 },
      { 0.0, 0.0, 0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vulpix_gfxdata[2],
      { -21.764713287353516, -93.23331451416016, -18.254423141479492 },
      { 0.0, 0.0, 0.0 },
      { 0.9760000109672546, 1.0, 1.0 } },
    { 2,
      &vulpix_gfxdata[3],
      { -97.47077941894531, -54.48998260498047, 40.6544075012207 },
      { 0.0, 0.0, 0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vulpix_gfxdata[4],
      { 20.810626983642578, -92.0882339477539, -18.254411697387695 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vulpix_gfxdata[5],
      { 2.3919599056243896, 104.011962890625, 59.1999397277832 },
      { 0.0, 0.0, 0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vulpix_gfxdata[6],
      { -0.08000600337982178, 7.045077800750732, -96.87527465820312 },
      { 0.010001000016927719, 9.999999747378752e-05, 0.009999999776482582 },
      { 0.9999970197677612, 0.9999909996986389, 1.0 } },
    { 3,
      &vulpix_gfxdata[7],
      { 0.02519400045275688, 74.58519744873047, -157.47764587402344 },
      { -0.010001000016927719, -9.999999747378752e-05, 1.9999999949504854e-06 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      &vulpix_gfxdata[8],
      { 0.024925999343395233, 50.21278762817383, -154.43434143066406 },
      { -0.030000999569892883, -9.999999747378752e-05, 1.9999999949504854e-06 },
      { 1.0, 0.9999979734420776, 0.9999979734420776 } },
    { 3,
      &vulpix_gfxdata[9],
      { 0.024354999884963036, 71.8697280883789, -149.05068969726562 },
      { -0.010001000016927719, -9.999999747378752e-05, 1.9999999949504854e-06 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      &vulpix_gfxdata[10],
      { 103.67137145996094, -6.291698932647705, -125.5379638671875 },
      { 0.010781999677419662, -0.03580600023269653, -0.042764998972415924 },
      { 1.0, 1.0, 1.0000009536743164 } },
    { 4,
      &vulpix_gfxdata[11],
      { -12.799811363220215, -113.42813110351562, -5.497490882873535 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 0.9999989867210388, 1.0000009536743164, 1.0000009536743164 } },
    { 5,
      &vulpix_gfxdata[12],
      { -20.398759841918945, -44.924129486083984, -48.892330169677734 },
      { -0.11999999731779099, 0.0, 1.9999999949504854e-06 },
      { 0.9740149974822998, 1.0000100135803223, 1.0000029802322388 } },
    { 3,
      &vulpix_gfxdata[13],
      { -97.2000503540039, -3.599261999130249, -128.399658203125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &vulpix_gfxdata[14],
      { -0.00016700000560376793, -118.7983169555664, -3.1993510723114014 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &vulpix_gfxdata[15],
      { 22.00057601928711, -41.99986267089844, -51.600765228271484 },
      { 0.009999999776482582, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 2.3919599056243896, -239.18804931640625, -104.4000473022461 },
      { 0.0, 0.0, 0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
