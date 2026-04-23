#include "common.h"
#include "sys/anim.h"

extern Texture* intro_todd_part16_mat[];
extern Gfx D_0E000000_intro[];

__ALIGNER
u8 intro_todd_tex_803943B8_png[] = {
#include "assets/intro/todd/tex_803943B8.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803947C0_png[] = {
#include "assets/intro/todd/tex_803947C0.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803949C8_pal[] = {
#include "assets/intro/todd/tex_803947C0.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803949D8_png[] = {
#include "assets/intro/todd/tex_803949D8.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80394BE0_pal[] = {
#include "assets/intro/todd/tex_803949D8.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80394BF8_png[] = {
#include "assets/intro/todd/tex_80394BF8.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80395000_pal[] = {
#include "assets/intro/todd/tex_80394BF8.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803950A8_png[] = {
#include "assets/intro/todd/tex_803950A8.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803958B0_png[] = {
#include "assets/intro/todd/tex_803958B0.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803960B8_png[] = {
#include "assets/intro/todd/tex_803960B8.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803968C0_png[] = {
#include "assets/intro/todd/tex_803968C0.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803970C8_png[] = {
#include "assets/intro/todd/tex_803970C8.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803972D0_pal[] = {
#include "assets/intro/todd/tex_803970C8.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_803972F8_png[] = {
#include "assets/intro/todd/tex_803972F8.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80397500_pal[] = {
#include "assets/intro/todd/tex_803972F8.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80397528_png[] = {
#include "assets/intro/todd/tex_80397528.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80397930_pal[] = {
#include "assets/intro/todd/tex_80397528.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80397B38_png[] = {
#include "assets/intro/todd/tex_80397B38.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80397F40_pal[] = {
#include "assets/intro/todd/tex_80397B38.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80398148_png[] = {
#include "assets/intro/todd/tex_80398148.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80398550_pal[] = {
#include "assets/intro/todd/tex_80398148.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80398758_png[] = {
#include "assets/intro/todd/tex_80398758.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80398960_pal[] = {
#include "assets/intro/todd/tex_80398758.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80398988_png[] = {
#include "assets/intro/todd/tex_80398988.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80399190[] = {
#include "assets/intro/todd/tex_80399190.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80399998_pal[] = {
#include "assets/intro/todd/tex_80399190.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_80399BA0[] = {
#include "assets/intro/todd/tex_80399BA0.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039A3A8[] = {
#include "assets/intro/todd/tex_8039A3A8.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039ABB0_png[] = {
#include "assets/intro/todd/tex_8039ABB0.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039ADB8_pal[] = {
#include "assets/intro/todd/tex_8039ABB0.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039ADE0_png[] = {
#include "assets/intro/todd/tex_8039ADE0.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039AFE8_pal[] = {
#include "assets/intro/todd/tex_8039ADE0.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039B010_png[] = {
#include "assets/intro/todd/tex_8039B010.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039B218_pal[] = {
#include "assets/intro/todd/tex_8039B010.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039B228_png[] = {
#include "assets/intro/todd/tex_8039B228.png.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039B430_pal[] = {
#include "assets/intro/todd/tex_8039B228.pal.bin.c"
};
__ALIGNER
u8 intro_todd_tex_8039B448_png[] = {
#include "assets/intro/todd/tex_8039B448.png.bin.c"
};

Texture** intro_todd_materials[] = {
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
    intro_todd_part16_mat,
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

u8* intro_todd_part16_mat0_textures[] = {
    intro_todd_tex_80399190,
    intro_todd_tex_80399BA0,
    intro_todd_tex_8039A3A8,
};

u8 pad_0[] = { 0, 0, 0, 0 };

Texture intro_todd_part16_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    intro_todd_part16_mat0_textures,
    96,
    0,
    64,
    32,
    0,
    0.08416499942541122,
    0.257779985666275,
    0.8246700167655945,
    0.33257800340652466,
    0.08416499942541122,
    0.8246700167655945,
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
    { 179, 179, 179, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 48, 48, 48, 0 },
    0,
    0,
    0,
    0,
};

Texture* intro_todd_part16_mat[] = {
    &intro_todd_part16_mat0,
    NULL,
};

#include "assets/intro/todd/model.vtx.inc.c"
#include "assets/intro/todd/part1_draw.gfx.inc.c"
#include "assets/intro/todd/part2_pre.gfx.inc.c"
#include "assets/intro/todd/part2_draw.gfx.inc.c"
#include "assets/intro/todd/part3_draw.gfx.inc.c"
#include "assets/intro/todd/part4_draw.gfx.inc.c"
#include "assets/intro/todd/part5_draw.gfx.inc.c"
#include "assets/intro/todd/part6_pre.gfx.inc.c"
#include "assets/intro/todd/part6_draw.gfx.inc.c"
#include "assets/intro/todd/part7_draw.gfx.inc.c"
#include "assets/intro/todd/part8_draw.gfx.inc.c"
#include "assets/intro/todd/part9_draw.gfx.inc.c"
#include "assets/intro/todd/part10_draw.gfx.inc.c"
#include "assets/intro/todd/part11_draw.gfx.inc.c"
#include "assets/intro/todd/part12_draw.gfx.inc.c"
#include "assets/intro/todd/part13_draw.gfx.inc.c"
#include "assets/intro/todd/part14_pre.gfx.inc.c"
#include "assets/intro/todd/part14_draw.gfx.inc.c"
#include "assets/intro/todd/part15_draw.gfx.inc.c"
#include "assets/intro/todd/part16_draw.gfx.inc.c"
#include "assets/intro/todd/part17_draw.gfx.inc.c"
#include "assets/intro/todd/part18_pre.gfx.inc.c"
#include "assets/intro/todd/part18_draw.gfx.inc.c"
#include "assets/intro/todd/part19_draw.gfx.inc.c"
#include "assets/intro/todd/part20_draw.gfx.inc.c"
#include "assets/intro/todd/part21_pre.gfx.inc.c"
#include "assets/intro/todd/part21_draw.gfx.inc.c"
#include "assets/intro/todd/part22_draw.gfx.inc.c"
#include "assets/intro/todd/part23_draw.gfx.inc.c"
#include "assets/intro/todd/part24_draw.gfx.inc.c"
#include "assets/intro/todd/part0_draw.gfx.inc.c"

DObjPayloadTypeJ intro_todd_gfxdata[] = {
    { 1, NULL, intro_todd_part0_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part1_draw },
    { 4, NULL, NULL },
    { 0, intro_todd_part2_pre, intro_todd_part2_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part3_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part5_draw },
    { 4, NULL, NULL },
    { 0, intro_todd_part6_pre, intro_todd_part6_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part8_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part9_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part11_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part13_draw },
    { 4, NULL, NULL },
    { 0, intro_todd_part14_pre, intro_todd_part14_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part15_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part16_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part17_draw },
    { 4, NULL, NULL },
    { 0, intro_todd_part18_pre, intro_todd_part18_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part19_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part20_draw },
    { 4, NULL, NULL },
    { 0, intro_todd_part21_pre, intro_todd_part21_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part22_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part23_draw },
    { 4, NULL, NULL },
    { 0, NULL, intro_todd_part24_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 intro_todd_model[] = {
    { 0,
      NULL,
      { 1.4484699964523315, -3.000000106112566e-06, 199.89125061035156 },
      { 0.0, 0.0, 0.0 },
      { 0.10000000149011612, 0.10000000149011612, 0.10000000149011612 } },
    { 1,
      &intro_todd_gfxdata[0],
      { 15.754072189331055, -50.730567932128906, 95.47052001953125 },
      { 0.0, 0.06498099863529205, 0.0 },
      { 1.0, 1.0, 0.9962090253829956 } },
    { 1,
      &intro_todd_gfxdata[2],
      { -48.426963806152344, 105.0426025390625, 100.26402282714844 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &intro_todd_gfxdata[4],
      { -41.961341857910156, -49.614356994628906, 9.999999747378752e-06 },
      { -0.8622859716415405, 0.09647499769926071, -0.6640409827232361 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_todd_gfxdata[6],
      { 0.43309900164604187, -187.7835693359375, -0.6122589707374573 },
      { 3.0985798835754395, -0.41475799679756165, -0.19644799828529358 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_todd_gfxdata[8],
      { -0.3467249870300293, -146.0999298095703, -4.6510701179504395 },
      { 0.20955100655555725, -0.17453299462795258, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_todd_gfxdata[10],
      { -0.7987980246543884, -29.063987731933594, 72.18255615234375 },
      { -0.06708499789237976, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &intro_todd_gfxdata[12],
      { 41.961341857910156, -49.614356994628906, 1.8999999156221747e-05 },
      { -1.9976470470428467, 0.8657619953155518, 0.16306599974632263 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_todd_gfxdata[14],
      { 0.06271599978208542, -187.9726104736328, -0.3705019950866699 },
      { 1.870331048965454, 0.002389000030234456, -0.019857000559568405 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_todd_gfxdata[16],
      { 0.11176200211048126, -146.45285034179688, -0.026785999536514282 },
      { 0.4584510028362274, -0.004224000032991171, 0.004910999909043312 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_todd_gfxdata[18],
      { 2.9999999242136255e-05, -28.134071350097656, 69.23815155029297 },
      { 0.0057069999165833, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &intro_todd_gfxdata[20],
      { 0.0, -31.17966651916504, 0.0 },
      { -0.24119800329208374, -0.6461690068244934, 0.32445400953292847 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &intro_todd_gfxdata[22],
      { -1.3991559743881226, 1.9704339504241943, -0.1974489986896515 },
      { 0.09126999974250793, 0.32372498512268066, -0.11817499995231628 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_todd_gfxdata[24],
      { -60.482479095458984, 229.06594848632812, -27.295133590698242 },
      { -0.03999999910593033, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_todd_gfxdata[26],
      { 97.3902359008789, -239.16688537597656, -46.750701904296875 },
      { 1.1231789588928223, 1.008802056312561, 1.0740950107574463 },
      { 0.7672780156135559, 0.9269999861717224, 0.9269999861717224 } },
    { 4,
      &intro_todd_gfxdata[28],
      { -0.8693130016326904, 221.93698120117188, -9.698667526245117 },
      { -0.035955000668764114, 0.019130000844597816, 0.01166599988937378 },
      { 1.0204399824142456, 1.0204399824142456, 1.0204399824142456 } },
    { 5,
      &intro_todd_gfxdata[30],
      { 7.000000096013537e-06, 29.728031158447266, 10.49966812133789 },
      { -0.9731400012969971, 0.564769983291626, -0.21624399721622467 },
      { 1.243710994720459, 1.2448110580444336, 1.2239179611206055 } },
    { 6,
      &intro_todd_gfxdata[32],
      { -6.000000212225132e-06, 12.090492248535156, 0.12142699956893921 },
      { 0.0, 0.0, 0.0 },
      { 0.9399999976158142, 0.9045590162277222, 1.0 } },
    { 7,
      &intro_todd_gfxdata[34],
      { 3.000000106112566e-06, -27.932310104370117, -0.9715880155563354 },
      { 0.05235999822616577, 0.0, 0.0 },
      { 0.8691999912261963, 0.8969770073890686, 0.8170480132102966 } },
    { 4,
      &intro_todd_gfxdata[36],
      { 85.98593139648438, 189.9503173828125, -18.118667602539062 },
      { -0.26259100437164307, -0.01869400031864643, 0.4147830009460449 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_todd_gfxdata[38],
      { 2.994083881378174, -144.59776306152344, 0.00016700000560376793 },
      { -0.9214059710502625, 0.045976001769304276, 0.010722000151872635 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &intro_todd_gfxdata[40],
      { 0.13589900732040405, -90.44389343261719, 3.126966953277588 },
      { 0.6278820037841797, 0.4289669990539551, 0.05150299891829491 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &intro_todd_gfxdata[42],
      { -85.38592529296875, 192.4813232421875, -17.039676666259766 },
      { 0.08551699668169022, 0.17467999458312988, -0.50102299451828 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &intro_todd_gfxdata[44],
      { -3.5445570945739746, -147.24331665039062, -1.4018770456314087 },
      { -0.6032990217208862, -0.062341999262571335, -0.08393900096416473 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &intro_todd_gfxdata[46],
      { -0.1513960063457489, -90.44723510742188, -0.3824709951877594 },
      { 0.634850025177002, 0.08527500182390213, -0.14615699648857117 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &intro_todd_gfxdata[48],
      { 41.288394927978516, -95.4848861694336, 37.83963394165039 },
      { 1.380288004875183, -0.4038270115852356, -0.8263970017433167 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

u8 pad_1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#include "assets/intro/todd/intro_todd_modelanim.modelanim.inc.c"
u8 pad_2[] = { 0, 0, 0, 0 };
#include "assets/intro/todd/intro_todd_matanim.matanim.inc.c"
u8 pad_3[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#include "intro_todd_camera_anim.inc.c"
