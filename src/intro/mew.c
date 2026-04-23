#include "common.h"
#include "sys/anim.h"

extern Texture* intro_mew_part4_mat[];

extern u8 D_0E000000_intro[];

__ALIGNER
u8 intro_mew_tex_80385E28_png[] = {
#include "assets/intro/mew/tex_80385E28.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80386E30_png[] = {
#include "assets/intro/mew/tex_80386E30.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80387038_pal[] = {
#include "assets/intro/mew/tex_80386E30.pal.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80387060_png[] = {
#include "assets/intro/mew/tex_80387060.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80387268_pal[] = {
#include "assets/intro/mew/tex_80387060.pal.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80387280_png[] = {
#include "assets/intro/mew/tex_80387280.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80387488_pal[] = {
#include "assets/intro/mew/tex_80387280.pal.bin.c"
};
__ALIGNER
u8 intro_mew_tex_803874A8_png[] = {
#include "assets/intro/mew/tex_803874A8.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80387C30_pal[] = {
#include "assets/intro/mew/tex_803874A8.pal.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80387E38_png[] = {
#include "assets/intro/mew/tex_80387E38.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_803885C0_png[] = {
#include "assets/intro/mew/tex_803885C0.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80388D48_png[] = {
#include "assets/intro/mew/tex_80388D48.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_803894D0_png[] = {
#include "assets/intro/mew/tex_803894D0.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80389C58_png[] = {
#include "assets/intro/mew/tex_80389C58.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80389E60_pal[] = {
#include "assets/intro/mew/tex_80389C58.pal.bin.c"
};
__ALIGNER
u8 intro_mew_tex_80389E88_png[] = {
#include "assets/intro/mew/tex_80389E88.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_8038A290_pal[] = {
#include "assets/intro/mew/tex_80389E88.pal.bin.c"
};
__ALIGNER
u8 intro_mew_tex_8038A2B8_png[] = {
#include "assets/intro/mew/tex_8038A2B8.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_8038A4C0_pal[] = {
#include "assets/intro/mew/tex_8038A2B8.pal.bin.c"
};
__ALIGNER
u8 intro_mew_tex_8038A4E8_png[] = {
#include "assets/intro/mew/tex_8038A4E8.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_8038A8F0_pal[] = {
#include "assets/intro/mew/tex_8038A4E8.pal.bin.c"
};
__ALIGNER
u8 intro_mew_tex_8038A918_png[] = {
#include "assets/intro/mew/tex_8038A918.png.bin.c"
};
__ALIGNER
u8 intro_mew_tex_8038AD20_pal[] = {
#include "assets/intro/mew/tex_8038A918.pal.bin.c"
};

Texture** intro_mew_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    intro_mew_part4_mat,
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

u8* intro_mew_part4_mat0_textures[] = {
    intro_mew_tex_803874A8_png,
    intro_mew_tex_80387E38_png,
    intro_mew_tex_803885C0_png,
    intro_mew_tex_80388D48_png,
    intro_mew_tex_803894D0_png,
};

static u8 pad_0[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

Texture intro_mew_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    intro_mew_part4_mat0_textures,
    32,
    0,
    42,
    40,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
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
    { 48, 48, 48, 0 },
    0,
    0,
    0,
    0,
};

Texture* intro_mew_part4_mat[] = {
    &intro_mew_part4_mat0,
    NULL,
};

#include "assets/intro/mew/model.vtx.inc.c"
#include "assets/intro/mew/part0_draw.gfx.inc.c"
#include "assets/intro/mew/part1_pre.gfx.inc.c"
#include "assets/intro/mew/part1_draw.gfx.inc.c"
#include "assets/intro/mew/part2_pre.gfx.inc.c"
#include "assets/intro/mew/part2_draw.gfx.inc.c"
#include "assets/intro/mew/part3_draw.gfx.inc.c"
#include "assets/intro/mew/part4_pre.gfx.inc.c"
#include "assets/intro/mew/part4_draw.gfx.inc.c"
#include "assets/intro/mew/part5_pre.gfx.inc.c"
#include "assets/intro/mew/part5_draw.gfx.inc.c"
#include "assets/intro/mew/part6_pre.gfx.inc.c"
#include "assets/intro/mew/part6_draw.gfx.inc.c"
#include "assets/intro/mew/part7_draw.gfx.inc.c"
#include "assets/intro/mew/part8_draw.gfx.inc.c"
#include "assets/intro/mew/part9_pre.gfx.inc.c"
#include "assets/intro/mew/part9_draw.gfx.inc.c"
#include "assets/intro/mew/part10_draw.gfx.inc.c"
#include "assets/intro/mew/part11_draw.gfx.inc.c"
#include "assets/intro/mew/part12_pre.gfx.inc.c"
#include "assets/intro/mew/part12_draw.gfx.inc.c"
#include "assets/intro/mew/part13_draw.gfx.inc.c"
#include "assets/intro/mew/part14_draw.gfx.inc.c"
#include "assets/intro/mew/part15_draw.gfx.inc.c"
#include "assets/intro/mew/part16_draw.gfx.inc.c"
#include "assets/intro/mew/part17_pre.gfx.inc.c"
#include "assets/intro/mew/part17_draw.gfx.inc.c"
#include "assets/intro/mew/part18_draw.gfx.inc.c"
#include "assets/intro/mew/part19_draw.gfx.inc.c"
#include "assets/intro/mew/part20_draw.gfx.inc.c"
#include "assets/intro/mew/part21_draw.gfx.inc.c"
#include "assets/intro/mew/part22_pre.gfx.inc.c"
#include "assets/intro/mew/part22_draw.gfx.inc.c"
#include "assets/intro/mew/part23_draw.gfx.inc.c"
#include "assets/intro/mew/part24_draw.gfx.inc.c"
#include "assets/intro/mew/part25_draw.gfx.inc.c"
#include "assets/intro/mew/part26_draw.gfx.inc.c"
#include "assets/intro/mew/part27_draw.gfx.inc.c"
#include "assets/intro/mew/part28_draw.gfx.inc.c"
#include "assets/intro/mew/part29_draw.gfx.inc.c"
#include "assets/intro/mew/part30_draw.gfx.inc.c"
#include "assets/intro/mew/part31_draw.gfx.inc.c"

DObjPayloadTypeI intro_mew_gfxdata[] = {
    { NULL, intro_mew_part0_draw },
    { intro_mew_part1_pre, intro_mew_part1_draw },
    { intro_mew_part2_pre, intro_mew_part2_draw },
    { NULL, intro_mew_part3_draw },
    { intro_mew_part4_pre, intro_mew_part4_draw },
    { intro_mew_part5_pre, intro_mew_part5_draw },
    { intro_mew_part6_pre, intro_mew_part6_draw },
    { NULL, intro_mew_part7_draw },
    { NULL, intro_mew_part8_draw },
    { intro_mew_part9_pre, intro_mew_part9_draw },
    { NULL, intro_mew_part10_draw },
    { NULL, intro_mew_part11_draw },
    { intro_mew_part12_pre, intro_mew_part12_draw },
    { NULL, intro_mew_part13_draw },
    { NULL, intro_mew_part14_draw },
    { NULL, intro_mew_part15_draw },
    { NULL, intro_mew_part16_draw },
    { intro_mew_part17_pre, intro_mew_part17_draw },
    { NULL, intro_mew_part18_draw },
    { NULL, intro_mew_part19_draw },
    { NULL, intro_mew_part20_draw },
    { NULL, intro_mew_part21_draw },
    { intro_mew_part22_pre, intro_mew_part22_draw },
    { NULL, intro_mew_part23_draw },
    { NULL, intro_mew_part24_draw },
    { NULL, intro_mew_part25_draw },
    { NULL, intro_mew_part26_draw },
    { NULL, intro_mew_part27_draw },
    { NULL, intro_mew_part28_draw },
    { NULL, intro_mew_part29_draw },
    { NULL, intro_mew_part30_draw },
    { NULL, intro_mew_part31_draw },
};

UnkEC64Arg3 intro_mew_model[] = {
    { 0,
      NULL,
      { 55.3311882019043, 116.775146484375, 236.70001220703125 },
      { 0.010816000401973724, -17.833049774169922, 0.0 },
      { 0.13009999692440033, 0.13009999692440033, 0.13030000030994415 } },
    { 1,
      &intro_mew_gfxdata[0],
      { -32.68198013305664, 100.65042114257812, 34.47640609741211 },
      { -0.6963649988174438, -0.33274099230766296, -0.19526299834251404 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &intro_mew_gfxdata[1],
      { -7.076396942138672, 25.52637481689453, 6.703574180603027 },
      { 0.27434200048446655, 0.16562700271606445, 0.3988809883594513 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_mew_gfxdata[2],
      { 0.0, 48.82252883911133, 3.755579948425293 },
      { -0.4992139935493469, 0.0784280002117157, -0.1934169977903366 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_mew_gfxdata[3],
      { 0.0, 5.007445812225342, 8.763011932373047 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_mew_gfxdata[4],
      { -42.93499755859375, 42.394996643066406, -1.8799999952316284 },
      { 0.0, 0.34906598925590515, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_mew_gfxdata[5],
      { 42.9348258972168, 42.39533996582031, -1.874770998954773 },
      { 0.0, 0.34906598925590515, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_mew_gfxdata[6],
      { 23.408702850341797, 23.305213928222656, 9.067778587341309 },
      { 0.2547059953212738, -0.6000000238418579, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_mew_gfxdata[7],
      { 10.22005558013916, -3.6099939346313477, 7.185986042022705 },
      { 0.0, -1.0613700151443481, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_mew_gfxdata[8],
      { 10.572179794311523, -3.279944896697998, 6.576368808746338 },
      { -0.3400000035762787, -0.28999999165534973, 0.36000001430511475 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_mew_gfxdata[9],
      { -23.40999984741211, 23.30499839782715, 9.069999694824219 },
      { -0.217058002948761, 0.38999998569488525, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_mew_gfxdata[10],
      { -10.220000267028809, -3.609999895095825, 7.184999942779541 },
      { 0.0, 1.0613700151443481, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_mew_gfxdata[11],
      { -10.719999313354492, -3.279999017715454, 6.574999809265137 },
      { 0.0, 0.5099999904632568, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &intro_mew_gfxdata[12],
      { 38.30906295776367, -3.131624937057495, 3.7584590911865234 },
      { 0.10000000149011612, 0.2736690044403076, -0.10000000149011612 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_mew_gfxdata[13],
      { -2.890000104904175, -38.42499923706055, 31.484996795654297 },
      { -0.09272100031375885, 0.055128999054431915, -0.013528999872505665 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_mew_gfxdata[14],
      { 0.0, -4.749060153961182, 5.936330795288086 },
      { -0.28123098611831665, 0.03514900058507919, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_mew_gfxdata[15],
      { 0.0, -5.144807815551758, 11.08112907409668 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &intro_mew_gfxdata[16],
      { 0.0, -13.653558731079102, 35.222198486328125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &intro_mew_gfxdata[17],
      { -38.310001373291016, -3.1299989223480225, 3.755000114440918 },
      { 0.1899999976158142, -0.2736690044403076, 0.10999999940395355 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_mew_gfxdata[18],
      { 2.8890879154205322, -38.42457962036133, 31.487396240234375 },
      { -0.09272100031375885, 0.06119000166654587, -0.003315000096336007 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_mew_gfxdata[19],
      { 0.0, -4.75, 5.934999942779541 },
      { -0.09019199758768082, 0.03514900058507919, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_mew_gfxdata[20],
      { 0.0, -5.144999980926514, 11.079999923706055 },
      { 0.15000000596046448, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &intro_mew_gfxdata[21],
      { 0.0, -13.654999732971191, 35.220001220703125 },
      { -0.06027600169181824, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &intro_mew_gfxdata[22],
      { 0.0, -20.16834259033203, -34.13105392456055 },
      { 0.57914799451828, 0.08636300265789032, -0.25422799587249756 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_mew_gfxdata[23],
      { 0.0, -1.5514110326766968, -25.5982666015625 },
      { -0.017014000564813614, 0.4654709994792938, -0.05073099955916405 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_mew_gfxdata[24],
      { 0.0, -1.7285230159759521, -37.766151428222656 },
      { 0.0021069999784231186, 0.31381699442863464, -0.000813000020571053 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_mew_gfxdata[25],
      { 0.0, -0.8227440118789673, -34.55530548095703 },
      { 0.0009480000007897615, 0.4814220070838928, 3.400000059627928e-05 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &intro_mew_gfxdata[26],
      { 0.0, -6.000000212225132e-06, -34.14399719238281 },
      { 0.0004440000047907233, 0.41751301288604736, 0.0007130000158213079 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &intro_mew_gfxdata[27],
      { 0.0, 0.0, -35.37814712524414 },
      { 0.00010800000018207356, 0.5690289735794067, 0.00039000000106170774 },
      { 1.0, 1.0, 1.0 } },
    { 8,
      &intro_mew_gfxdata[28],
      { 0.0, 0.0, -33.73260498046875 },
      { 0.00028899998869746923, 0.3074359893798828, -3.9999998989515007e-05 },
      { 1.0, 1.0, 1.0 } },
    { 9,
      &intro_mew_gfxdata[29],
      { 0.0, 0.0, -24.68247413635254 },
      { -0.0003319999959785491, 0.186831995844841, -0.0005649999948218465 },
      { 1.0, 1.0, 1.0 } },
    { 10,
      &intro_mew_gfxdata[30],
      { 0.0, -0.41137298941612244, -17.27757453918457 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 11,
      &intro_mew_gfxdata[31],
      { 0.0, 0.41137298941612244, -39.49174880981445 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

static u8 pad_1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
#include "assets/intro/mew/intro_mew_modelanim.modelanim.inc.c"

static u8 pad_2[] = {
    0,
    0,
    0,
    0,
};
#include "assets/intro/mew/intro_mew_matanim.matanim.inc.c"
