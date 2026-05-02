#include "common.h"

extern u8 vulpix_tex_eye_frame4_png[];
extern u8 vulpix_tex_eye_frame0_png[];
extern u8 vulpix_tex_eye_frame1_png[];
extern u8 vulpix_tex_eye_frame2_png[];
extern u8 vulpix_tex_eye_frame3_png[];
extern u8 D_801C5E98_3ECAF8[];
extern u8 D_801C5EC0_3ECB20[];
extern u8 vulpix_tex_bang_pal[];
extern u8 vulpix_tex_bang_png[];
extern u8 vulpix_tex_belly_pal[];
extern u8 vulpix_tex_belly_png[];
extern u8 vulpix_tex_claw_pal[];
extern u8 vulpix_tex_claw_png[];
extern u8 vulpix_tex_curl_pal[];
extern u8 vulpix_tex_curl_png[];
extern u8 vulpix_tex_ear_pal[];
extern u8 vulpix_tex_ear_png[];
extern u8 vulpix_tex_eye_frame0_pal[];
extern u8 vulpix_tex_hair_pal[];
extern u8 vulpix_tex_hair_png[];
extern u8 vulpix_tex_nose_pal[];
extern u8 vulpix_tex_nose_png[];
extern u8 vulpix_tex_pad_pal[];
extern u8 vulpix_tex_pad_png[];
extern u8 vulpix_tex_paw_pal[];
extern u8 vulpix_tex_paw_png[];
extern u8 vulpix_tex_tail_pal[];
extern u8 vulpix_tex_tail_png[];

extern u8 D_801C6478_volcano_extra[];
extern u8 D_801C64A0_volcano_extra[];
extern u8 D_801C6810_volcano_extra[];
extern u8 D_801C6870_volcano_extra[];
extern u8 D_801C6880_volcano_extra[];
extern u8 D_801C6890_volcano_extra[];
extern u8 D_801C68A0_volcano_extra[];
extern u8 D_801C68B0_volcano_extra[];
extern u8 D_801C68C0_volcano_extra[];
extern u8 D_801C68D0_volcano_extra[];
extern u8 D_801C68E0_volcano_extra[];
extern u8 D_801C68F0_volcano_extra[];
extern u8 D_801C6910_volcano_extra[];
extern u8 D_801C6930_volcano_extra[];
extern u8 D_801C6940_volcano_extra[];
extern u8 D_801C6970_volcano_extra[];
extern u8 D_801C6980_volcano_extra[];
extern u8 D_801C6990_volcano_extra[];
extern u8 D_801C69B0_volcano_extra[];
extern u8 D_801C69E0_volcano_extra[];
extern u8 D_801C6A00_volcano_extra[];
extern u8 D_801C6A20_volcano_extra[];
extern u8 D_801C6A50_volcano_extra[];
extern u8 D_801C6A90_volcano_extra[];
extern u8 D_801C6AF0_volcano_extra[];
extern u8 D_801C6B00_volcano_extra[];
extern u8 D_801C6B10_volcano_extra[];
extern u8 D_801C6B20_volcano_extra[];
extern u8 D_801C6B30_volcano_extra[];
extern u8 D_801C6B40_volcano_extra[];
extern u8 D_801C6B60_volcano_extra[];
extern u8 D_801C6B80_volcano_extra[];
extern u8 D_801C6B90_volcano_extra[];
extern u8 D_801C6BE0_volcano_extra[];
extern u8 D_801C6C30_volcano_extra[];
extern u8 D_801C6D40_volcano_extra[];
extern u8 D_801C6DC0_volcano_extra[];
extern u8 D_801C6EB0_volcano_extra[];
extern u8 D_801C6F00_volcano_extra[];
extern u8 D_801C6F40_volcano_extra[];
extern u8 D_801C7020_volcano_extra[];
extern u8 D_801C70B0_volcano_extra[];
extern u8 D_801C7180_volcano_extra[];
extern u8 D_801C71E0_volcano_extra[];
extern u8 D_801C7240_volcano_extra[];
extern u8 D_801C72B0_volcano_extra[];
extern u8 D_801C7430_volcano_extra[];
extern u8 D_801C7540_volcano_extra[];
extern u8 D_801C7620_volcano_extra[];
extern u8 D_801C7710_volcano_extra[];
extern u8 D_801C7720_volcano_extra[];
extern u8 D_801C7750_volcano_extra[];
extern u8 D_801C7770_volcano_extra[];
extern u8 D_801C7780_volcano_extra[];
extern u8 D_801C7790_volcano_extra[];
extern u8 D_801C77A0_volcano_extra[];
extern u8 D_801C77C0_volcano_extra[];
extern u8 D_801C7800_volcano_extra[];
extern u8 D_801C7840_volcano_extra[];
extern u8 D_801C7860_volcano_extra[];
extern u8 D_801C7890_volcano_extra[];
extern u8 D_801C78A0_volcano_extra[];
extern u8 D_801C78F0_volcano_extra[];
extern u8 D_801C7920_volcano_extra[];
extern u8 D_801C7960_volcano_extra[];
extern u8 D_801C7970_volcano_extra[];
extern u8 D_801C7980_volcano_extra[];
extern u8 D_801C7990_volcano_extra[];
extern u8 D_801C79C0_volcano_extra[];
extern u8 D_801C79D0_volcano_extra[];
extern u8 D_801C79E0_volcano_extra[];
extern u8 D_801C7A20_volcano_extra[];
extern u8 D_801C7A90_volcano_extra[];
extern u8 D_801C7AF0_volcano_extra[];
extern u8 D_801C7B00_volcano_extra[];
extern u8 D_801C7B10_volcano_extra[];
extern u8 D_801C7B40_volcano_extra[];
extern u8 D_801C7B50_volcano_extra[];
extern u8 D_801C7B60_volcano_extra[];
extern u8 D_801C7B90_volcano_extra[];
extern u8 D_801C7BD0_volcano_extra[];
extern u8 D_801C7C20_volcano_extra[];
extern u8 D_801C7C40_volcano_extra[];
extern u8 D_801C7C60_volcano_extra[];
extern u8 D_801C7C70_volcano_extra[];
extern u8 D_801C7C80_volcano_extra[];
extern u8 D_801C7C90_volcano_extra[];
extern u8 D_801C7D50_volcano_extra[];
extern u8 D_801C7E10_volcano_extra[];
extern u8 D_801C7F70_volcano_extra[];
extern u8 D_801C8030_volcano_extra[];
extern u8 D_801C80F0_volcano_extra[];
extern u8 D_801C8100_volcano_extra[];
extern u8 D_801C82F0_volcano_extra[];
extern u8 D_801C8470_volcano_extra[];
extern u8 D_801C8530_volcano_extra[];
extern u8 D_801C85F0_volcano_extra[];
extern u8 D_801C8750_volcano_extra[];
extern u8 D_801C87B0_volcano_extra[];
extern u8 D_801C8800_volcano_extra[];
extern u8 D_801C88A0_volcano_extra[];
extern u8 D_801C8930_cave_extra[];
extern u8 D_801C8AA0_volcano_extra[];
extern u8 D_801C8B30_volcano_extra[];
extern u8 D_801C8B90_volcano_extra[];
extern u8 D_801C8BE0_volcano_extra[];
extern u8 D_801C8C80_volcano_extra[];
extern u8 D_801C8D10_volcano_extra[];
extern u8 D_801C8E80_cave_extra[];
extern u8 D_801C8F40_volcano_extra[];

extern Texture* vulpix_hd_part6_mat[];
extern Gfx vulpix_hd_part0_draw[];

__ALIGNER
u8 vulpix_hd_tex_801C5EC0_pal[] = {
#include "assets/volcano/vulpix/tex_801C5EC0_hd.pal.bin.c"
};

__ALIGNER
u8 vulpix_hd_tex_801C5EC0_png[] = {
#include "assets/volcano/vulpix/tex_801C5EC0_hd.png.bin.c"
};

Texture** vulpix_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    vulpix_hd_part6_mat,
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

u8* vulpix_hd_part6_mat0_textures[] = {
    vulpix_tex_eye_frame0_png,
    vulpix_tex_eye_frame1_png,
    vulpix_tex_eye_frame2_png,
    vulpix_tex_eye_frame3_png,
    vulpix_tex_eye_frame4_png,
};

u8* vulpix_hd_part6_mat1_textures[] = {
    vulpix_tex_eye_frame0_png,
    vulpix_tex_eye_frame1_png,
    vulpix_tex_eye_frame2_png,
    vulpix_tex_eye_frame3_png,
    vulpix_tex_eye_frame4_png,
};

Texture vulpix_hd_part6_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    vulpix_hd_part6_mat0_textures,
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
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture vulpix_hd_part6_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    vulpix_hd_part6_mat1_textures,
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
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* vulpix_hd_part6_mat[] = {
    &vulpix_hd_part6_mat0,
    &vulpix_hd_part6_mat1,
    NULL,
    NULL,
};
#include "assets/volcano/vulpix/hd_model.vtx.inc.c"
#include "assets/volcano/vulpix/hd_first.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part0_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part1_pre.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part1_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part2_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part3_pre.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part3_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part4_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part5_pre.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part5_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part6_pre.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part6_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part7_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part8_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part9_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part10_pre.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part10_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part11_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part12_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part13_pre.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part13_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part14_draw.gfx.inc.c"
#include "assets/volcano/vulpix/hd_part15_draw.gfx.inc.c"

DObjPayloadTypeI vulpix_hd_gfxdata[] = {
    { NULL, vulpix_hd_first },
    { vulpix_hd_part1_pre, vulpix_hd_part1_draw },
    { NULL, vulpix_hd_part2_draw },
    { vulpix_hd_part3_pre, vulpix_hd_part3_draw },
    { NULL, vulpix_hd_part4_draw },
    { vulpix_hd_part5_pre, vulpix_hd_part5_draw },
    { vulpix_hd_part6_pre, vulpix_hd_part6_draw },
    { NULL, vulpix_hd_part7_draw },
    { NULL, vulpix_hd_part8_draw },
    { NULL, vulpix_hd_part9_draw },
    { vulpix_hd_part10_pre, vulpix_hd_part10_draw },
    { NULL, vulpix_hd_part11_draw },
    { NULL, vulpix_hd_part12_draw },
    { vulpix_hd_part13_pre, vulpix_hd_part13_draw },
    { NULL, vulpix_hd_part14_draw },
    { NULL, vulpix_hd_part15_draw },
};

UnkEC64Arg3 vulpix_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 3.0369279384613037, 4.8000001697801054e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &vulpix_hd_gfxdata[0],
      { 0.0, 236.1630859375, 103.20000457763672 },
      { -0.009999999776482582, 0.0, -0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vulpix_hd_gfxdata[1],
      { 91.48163604736328, -51.4547233581543, 41.85440444946289 },
      { 0.0, 0.0, 0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vulpix_hd_gfxdata[2],
      { -21.764713287353516, -93.23331451416016, -18.254423141479492 },
      { 0.0, 0.0, 0.0 },
      { 0.9760000109672546, 1.0, 1.0 } },
    { 2,
      &vulpix_hd_gfxdata[3],
      { -97.47077941894531, -54.48998260498047, 41.85440444946289 },
      { 0.0, 0.0, 0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vulpix_hd_gfxdata[4],
      { 20.810626983642578, -92.0882339477539, -18.254411697387695 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vulpix_hd_gfxdata[5],
      { 2.3919599056243896, 104.011962890625, 60.39993667602539 },
      { 0.0, 0.0, 0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vulpix_hd_gfxdata[6],
      { -0.07999800145626068, 7.999873161315918, -95.60006713867188 },
      { 0.019999999552965164, 0.0, 0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vulpix_hd_gfxdata[7],
      { -3.000000106112566e-06, 75.20024871826172, -156.79925537109375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vulpix_hd_gfxdata[8],
      { -3.000000106112566e-06, 50.79851150512695, -153.99974060058594 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 1.0, 0.9999979734420776, 0.9999979734420776 } },
    { 3,
      &vulpix_hd_gfxdata[9],
      { -3.000000106112566e-06, 72.40052032470703, -148.39979553222656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vulpix_hd_gfxdata[10],
      { 103.67153930664062, -6.29153299331665, -125.53780364990234 },
      { 0.010781999677419662, -0.03580600023269653, -0.042764998972415924 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &vulpix_hd_gfxdata[11],
      { -12.799811363220215, -113.42813110351562, -5.497490882873535 },
      { -0.019999999552965164, 0.0, 0.0 },
      { 0.9999989867210388, 1.0000009536743164, 1.0000009536743164 } },
    { 5,
      &vulpix_hd_gfxdata[12],
      { -20.398759841918945, -44.924129486083984, -48.892330169677734 },
      { -0.11999999731779099, 0.0, 1.9999999949504854e-06 },
      { 0.9740149974822998, 1.0000100135803223, 1.0000029802322388 } },
    { 3,
      &vulpix_hd_gfxdata[13],
      { -97.20005798339844, -3.59942889213562, -128.399658203125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &vulpix_hd_gfxdata[14],
      { -0.00016700000560376793, -118.7983169555664, -3.1993510723114014 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &vulpix_hd_gfxdata[15],
      { 22.00057601928711, -41.99986267089844, -51.600765228271484 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 2.3919599056243896, -238.14413452148438, -105.58670806884766 },
      { 0.009998999536037445, -9.999999747378752e-05, 0.009998999536037445 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
