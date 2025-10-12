#include "common.h"

extern u8 snorlax_tex_8801799F8[];
extern u8 snorlax_tex_80179A20_png[];
extern u8 snorlax_tex_880179C28[];
extern u8 snorlax_tex_80179C50_png[];
extern u8 snorlax_tex_88017A058[];
extern u8 snorlax_tex_88017AEB8[];
extern u8 snorlax_tex_8017B318_png[];
extern u8 snorlax_tex_88017B2F0[];
extern u8 snorlax_tex_8017B720_png[];
extern u8 snorlax_tex_8017A080[];
extern u8 snorlax_tex_8017A288[];
extern u8 snorlax_tex_8017A490[];
extern u8 snorlax_tex_8017A698[];
extern u8 snorlax_tex_8017A8A0[];
extern u8 snorlax_tex_8017AAA8[];
extern u8 snorlax_tex_8017ACB0[];
extern u8 snorlax_tex_8017AEE0[];
extern u8 snorlax_tex_8017B0E8[];

extern Gfx snorlax_part0_draw[];
extern Texture* snorlax_part4_mat[];
extern Texture* snorlax_part5_mat[];

__ALIGNER
u8 snorlax_pal_5C3858[] = {
#include "assets/beach/snorlax/5C3858.png.bin.c"
};

__ALIGNER
u8 snorlax_pal_5C3880[] = {
#include "assets/beach/snorlax/5C3880.png.bin.c"
};

__ALIGNER
u8 snorlax_pal_5C38A8[] = {
#include "assets/beach/snorlax/5C38A8.png.bin.c"
};

__ALIGNER
u8 snorlax_pal_5C38D0[] = {
#include "assets/beach/snorlax/5C38D0.png.bin.c"
};

__ALIGNER
u8 snorlax_pal_5C38F8[] = {
#include "assets/beach/snorlax/5C38F8.png.bin.c"
};

__ALIGNER
u8 snorlax_pal_5C3920[] = {
#include "assets/beach/snorlax/5C3920.png.bin.c"
};

__ALIGNER
u8 snorlax_pal_5C3948[] = {
#include "assets/beach/snorlax/5C3948.png.bin.c"
};

Texture** D_beach_8032B8F8[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    snorlax_part4_mat,
    snorlax_part5_mat,
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

u8* snorlax_part4_mat0_textures[] = {
    snorlax_tex_8017A080,
    snorlax_tex_8017A288,
    snorlax_tex_8017A490,
    snorlax_tex_8017A698,
    snorlax_tex_8017A8A0,
    snorlax_tex_8017AAA8,
    snorlax_tex_8017ACB0,
};

u8* snorlax_part4_mat1_textures[] = {
    snorlax_tex_8017AEE0,
    snorlax_tex_8017B0E8,
};

u8* snorlax_part4_mat2_textures[] = {
    snorlax_tex_8017AEE0,
    snorlax_tex_8017B0E8,
};

Texture snorlax_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    snorlax_part4_mat0_textures,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture snorlax_part4_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    snorlax_part4_mat1_textures,
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
    0x1,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture snorlax_part4_mat2 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    snorlax_part4_mat2_textures,
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
    0x1,
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
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture snorlax_part5_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    32,
    384,
    32,
    192,
    0,
    0.0,
    0.0,
    1.0,
    3.0,
    0.0,
    1.0,
    NULL,
    0x20,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    32,
    64,
    32,
    192,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
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
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* snorlax_part4_mat[] = {
    &snorlax_part4_mat0,
    &snorlax_part4_mat1,
    &snorlax_part4_mat2,
    NULL,
};

Texture* snorlax_part5_mat[] = {
    &snorlax_part5_mat0,
    NULL,
};

#include "assets/beach/snorlax/model.vtx.inc.c"
#include "assets/beach/snorlax/first.gfx.inc.c"
#include "assets/beach/snorlax/part0_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part0_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part0_draw.gfx.inc.c"
#include "assets/beach/snorlax/part1_pre_near.gfx.inc.c"
#include "assets/beach/snorlax/part1_pre_far.gfx.inc.c"
#include "assets/beach/snorlax/part1_pre.gfx.inc.c"
#include "assets/beach/snorlax/part1_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part1_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part1_draw.gfx.inc.c"
#include "assets/beach/snorlax/part2_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part2_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part2_draw.gfx.inc.c"
#include "assets/beach/snorlax/part3_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part3_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part3_draw.gfx.inc.c"
#include "assets/beach/snorlax/part5_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part5_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part5_draw.gfx.inc.c"
#include "assets/beach/snorlax/part6_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part6_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part6_draw.gfx.inc.c"
#include "assets/beach/snorlax/part7_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part7_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part7_draw.gfx.inc.c"
#include "assets/beach/snorlax/part8_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part8_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part8_draw.gfx.inc.c"
#include "assets/beach/snorlax/part9_pre_near.gfx.inc.c"
#include "assets/beach/snorlax/part9_pre_far.gfx.inc.c"
#include "assets/beach/snorlax/part9_pre.gfx.inc.c"
#include "assets/beach/snorlax/part9_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part9_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part9_draw.gfx.inc.c"
#include "assets/beach/snorlax/part10_pre_near.gfx.inc.c"
#include "assets/beach/snorlax/part10_pre_far.gfx.inc.c"
#include "assets/beach/snorlax/part10_pre.gfx.inc.c"
#include "assets/beach/snorlax/part10_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part10_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part10_draw.gfx.inc.c"
#include "assets/beach/snorlax/part11_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part11_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part11_draw.gfx.inc.c"
#include "assets/beach/snorlax/part12_pre_near.gfx.inc.c"
#include "assets/beach/snorlax/part12_pre_far.gfx.inc.c"
#include "assets/beach/snorlax/part12_pre.gfx.inc.c"
#include "assets/beach/snorlax/part12_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part12_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part12_draw.gfx.inc.c"
#include "assets/beach/snorlax/part26_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part26_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part26_draw.gfx.inc.c"
#include "assets/beach/snorlax/last.gfx.inc.c"
#include "assets/beach/snorlax/part4_draw_near.gfx.inc.c"
#include "assets/beach/snorlax/part4_draw_far.gfx.inc.c"
#include "assets/beach/snorlax/part4_draw.gfx.inc.c"

DObjPayloadTypeJ snorlax_gfxdata[] = {
    { 0, NULL, snorlax_first },
    { 4, NULL, NULL },
    { 0, snorlax_part1_pre, snorlax_part1_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_part2_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_part3_draw },
    { 4, NULL, NULL },
    { 1, NULL, snorlax_part4_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_part6_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_part7_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_part8_draw },
    { 4, NULL, NULL },
    { 0, snorlax_part9_pre, snorlax_part9_draw },
    { 4, NULL, NULL },
    { 0, snorlax_part10_pre, snorlax_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_part11_draw },
    { 4, NULL, NULL },
    { 0, snorlax_part12_pre, snorlax_part12_draw },
    { 4, NULL, NULL },
    { 0, NULL, snorlax_last },
    { 4, NULL, NULL },
};

UnkEC64Arg3 snorlax_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &snorlax_gfxdata[0],
      { 0.0, 684.4000244140625, 60.39999008178711 },
      { -1.4887959957122803, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &snorlax_gfxdata[2],
      { 0.0, 100.46121978759766, -8.255195617675781 },
      { -0.1979999989271164, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &snorlax_gfxdata[4],
      { 0.0, 465.0441589355469, -108.70561218261719 },
      { -0.2199999988079071, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &snorlax_gfxdata[6],
      { 0.0, 284.0278625488281, 0.0 },
      { 0.1120000034570694, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8197,
      &snorlax_gfxdata[8],
      { 50.0, 200.0, 300.0 },
      { 1.7947959899902344, 0.0, 0.0 },
      { 1.0, 1.0, 1.3253999948501587 } },
    { 4,
      &snorlax_gfxdata[10],
      { 462.7724304199219, 6.000853061676025, 0.0 },
      { -0.18060800433158875, 0.42862099409103394, -0.07832799851894379 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &snorlax_gfxdata[12],
      { 376.83563232421875, 5.576539039611816, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &snorlax_gfxdata[14],
      { -462.7724304199219, 6.000853061676025, 0.0 },
      { 0.18060800433158875, 2.7129709720611572, 0.07832899689674377 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &snorlax_gfxdata[16],
      { 376.835693359375, 5.576502799987793, 9.500000305706635e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &snorlax_gfxdata[18],
      { 0.0, -408.1870422363281, -94.63963317871094 },
      { 0.3980009853839874, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &snorlax_gfxdata[20],
      { 550.0, -218.25010681152344, -51.711036682128906 },
      { 0.26282399892807007, 0.7679280042648315, 0.18476299941539764 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &snorlax_gfxdata[22],
      { -0.00017899999511428177, -69.99998474121094, 9.500000305706635e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &snorlax_gfxdata[24],
      { -550.0, -218.25010681152344, -51.711036682128906 },
      { -0.26282399892807007, 2.3736650943756104, -0.18476200103759766 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &snorlax_gfxdata[26],
      { -0.0002500000118743628, -69.99998474121094, -9.500000305706635e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
