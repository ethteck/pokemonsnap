#include "common.h"

extern u8 D_8034C8A0_825E30[]; // TODO: remove after splat is fixed

extern u8 mew_tex_80126918[];
extern u8 mew_tex_80126B20[];
extern u8 mew_tex_801274B0[];
extern u8 mew_tex_80127E40[];
extern u8 mew_tex_801287D0[];
extern u8 mew_tex_80129160[];
extern u8 mew_tex_80129AF0[];
extern u8 mew_tex_8012A278[];
extern u8 mew_tex_8012A2A0_png[];
extern u8 mew_tex_8012A6A8[];
extern u8 mew_tex_8012B6B0[];
extern u8 mew_tex_8012B6D0_png[];
extern u8 mew_tex_8012B8D8[];
extern u8 mew_tex_8012B900_png[];
extern u8 mew_tex_8012BD08[];
extern u8 mew_tex_8012BD30_png[];
extern u8 mew_tex_8012BF38[];
extern u8 mew_tex_8012BF60_png[];
extern u8 mew_tex_8012C168[];
extern u8 mew_tex_8012C180_png[];
extern u8 mew_tex_8012C388[];
extern u8 mew_tex_8012C3B0_png[];
extern u8 mew_tex_8012C7B8[];
extern u8 mew_tex_8012C7E0_png[];

extern Texture* mew_part4_mat[];
extern Gfx mew_part0_draw[];

Texture** mew_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    mew_part4_mat,
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

u8* mew_part4_mat0_textures[] = {
    mew_tex_80126B20,
    mew_tex_801274B0,
    mew_tex_80127E40,
    mew_tex_801287D0,
    mew_tex_80129160,
    mew_tex_80129AF0,
    NULL,
};

Texture mew_part4_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    mew_part4_mat0_textures,
    128,
    64,
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
    G_IM_FMT_CI,
    G_IM_SIZ_8b,
    42,
    40,
    42,
    40,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* mew_part4_mat[] = {
    &mew_part4_mat0,
    NULL,
};

#include "assets/rainbow/mew/model.vtx.inc.c"
#include "assets/rainbow/mew/first.gfx.inc.c"
#include "assets/rainbow/mew/part0_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part0_draw.gfx.inc.c"
#include "assets/rainbow/mew/part1_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part1_pre.gfx.inc.c"
#include "assets/rainbow/mew/part1_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part1_draw.gfx.inc.c"
#include "assets/rainbow/mew/part2_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part2_pre.gfx.inc.c"
#include "assets/rainbow/mew/part2_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part2_draw.gfx.inc.c"
#include "assets/rainbow/mew/part3_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part3_draw.gfx.inc.c"
#include "assets/rainbow/mew/part4_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part4_pre.gfx.inc.c"
#include "assets/rainbow/mew/part4_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part4_draw.gfx.inc.c"
#include "assets/rainbow/mew/part5_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part5_pre.gfx.inc.c"
#include "assets/rainbow/mew/part5_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part5_draw.gfx.inc.c"
#include "assets/rainbow/mew/part6_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part6_pre.gfx.inc.c"
#include "assets/rainbow/mew/part6_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part6_draw.gfx.inc.c"
#include "assets/rainbow/mew/part7_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part7_draw.gfx.inc.c"
#include "assets/rainbow/mew/part8_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part8_draw.gfx.inc.c"
#include "assets/rainbow/mew/part9_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part9_pre.gfx.inc.c"
#include "assets/rainbow/mew/part9_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part9_draw.gfx.inc.c"
#include "assets/rainbow/mew/part10_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part10_draw.gfx.inc.c"
#include "assets/rainbow/mew/part11_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part11_draw.gfx.inc.c"
#include "assets/rainbow/mew/part12_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part12_pre.gfx.inc.c"
#include "assets/rainbow/mew/part12_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part12_draw.gfx.inc.c"
#include "assets/rainbow/mew/part13_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part13_draw.gfx.inc.c"
#include "assets/rainbow/mew/part14_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part14_draw.gfx.inc.c"
#include "assets/rainbow/mew/part15_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part15_draw.gfx.inc.c"
#include "assets/rainbow/mew/part16_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part16_draw.gfx.inc.c"
#include "assets/rainbow/mew/part17_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part17_pre.gfx.inc.c"
#include "assets/rainbow/mew/part17_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part17_draw.gfx.inc.c"
#include "assets/rainbow/mew/part18_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part18_draw.gfx.inc.c"
#include "assets/rainbow/mew/part19_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part19_draw.gfx.inc.c"
#include "assets/rainbow/mew/part20_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part20_draw.gfx.inc.c"
#include "assets/rainbow/mew/part21_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part21_draw.gfx.inc.c"
#include "assets/rainbow/mew/part22_pre_near.gfx.inc.c"
#include "assets/rainbow/mew/part22_pre.gfx.inc.c"
#include "assets/rainbow/mew/part22_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part22_draw.gfx.inc.c"
#include "assets/rainbow/mew/part23_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part23_draw.gfx.inc.c"
#include "assets/rainbow/mew/part24_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part24_draw.gfx.inc.c"
#include "assets/rainbow/mew/part25_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part25_draw.gfx.inc.c"
#include "assets/rainbow/mew/part26_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part26_draw.gfx.inc.c"
#include "assets/rainbow/mew/part27_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part27_draw.gfx.inc.c"
#include "assets/rainbow/mew/part28_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part28_draw.gfx.inc.c"
#include "assets/rainbow/mew/part29_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part29_draw.gfx.inc.c"
#include "assets/rainbow/mew/part30_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part30_draw.gfx.inc.c"
#include "assets/rainbow/mew/part31_draw_near.gfx.inc.c"
#include "assets/rainbow/mew/part31_draw.gfx.inc.c"
#include "assets/rainbow/mew/last.gfx.inc.c"

DObjPayloadTypeI mew_gfxdata[] = {
    { NULL, mew_first },
    { mew_part1_pre, mew_part1_draw },
    { mew_part2_pre, mew_part2_draw },
    { NULL, mew_part3_draw },
    { mew_part4_pre, mew_part4_draw },
    { mew_part5_pre, mew_part5_draw },
    { mew_part6_pre, mew_part6_draw },
    { NULL, mew_part7_draw },
    { NULL, mew_part8_draw },
    { mew_part9_pre, mew_part9_draw },
    { NULL, mew_part10_draw },
    { NULL, mew_part11_draw },
    { mew_part12_pre, mew_part12_draw },
    { NULL, mew_part13_draw },
    { NULL, mew_part14_draw },
    { NULL, mew_part15_draw },
    { NULL, mew_part16_draw },
    { mew_part17_pre, mew_part17_draw },
    { NULL, mew_part18_draw },
    { NULL, mew_part19_draw },
    { NULL, mew_part20_draw },
    { NULL, mew_part21_draw },
    { mew_part22_pre, mew_part22_draw },
    { NULL, mew_part23_draw },
    { NULL, mew_part24_draw },
    { NULL, mew_part25_draw },
    { NULL, mew_part26_draw },
    { NULL, mew_part27_draw },
    { NULL, mew_part28_draw },
    { NULL, mew_part29_draw },
    { NULL, mew_part30_draw },
    { NULL, mew_last },
};

UnkEC64Arg3 mew_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { -0.10000000149011612, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &mew_gfxdata[0],
      { 0.0, 225.8209991455078, 0.0 },
      { -0.10000000149011612, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &mew_gfxdata[1],
      { 0.0, 50.629188537597656, 11.337536811828613 },
      { 0.22007200121879578, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &mew_gfxdata[2],
      { 0.0, 97.64505767822266, 7.511159896850586 },
      { 0.5699999928474426, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &mew_gfxdata[3],
      { 0.0, 10.014891624450684, 17.526023864746094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &mew_gfxdata[4],
      { -85.8699951171875, 84.78999328613281, -3.759999990463257 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &mew_gfxdata[5],
      { 85.8696517944336, 84.79067993164062, -3.749541997909546 },
      { 0.0, -0.5299999713897705, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &mew_gfxdata[6],
      { 46.817405700683594, 46.61042785644531, 18.135557174682617 },
      { 0.3499999940395355, -0.6000000238418579, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &mew_gfxdata[7],
      { 20.44011116027832, -7.219987869262695, 14.37197208404541 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &mew_gfxdata[8],
      { 21.144359588623047, -6.559891223907471, 13.152737617492676 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &mew_gfxdata[9],
      { -46.81999969482422, 46.6099967956543, 18.139999389648438 },
      { -0.09000000357627869, 0.38999998569488525, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &mew_gfxdata[10],
      { -20.440000534057617, -7.21999979019165, 14.370000839233398 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &mew_gfxdata[11],
      { -21.439998626708984, -6.559998035430908, 13.15000057220459 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &mew_gfxdata[12],
      { 76.61812591552734, -6.263250827789307, 7.516918182373047 },
      { 0.10000000149011612, 0.0, -0.10000000149011612 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &mew_gfxdata[13],
      { -5.78000020980835, -76.8499984741211, 62.969993591308594 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &mew_gfxdata[14],
      { 0.0, -9.498119354248047, 11.872661590576172 },
      { -0.2800000011920929, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &mew_gfxdata[15],
      { 0.0, -10.289615631103516, 22.16225814819336 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &mew_gfxdata[16],
      { 0.0, -27.307117462158203, 70.44439697265625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &mew_gfxdata[17],
      { -76.62000274658203, -6.259998798370361, 7.510000228881836 },
      { 0.1899999976158142, 0.0, 0.10999999940395355 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &mew_gfxdata[18],
      { 5.778174877166748, -76.84915924072266, 62.97479248046875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &mew_gfxdata[19],
      { 0.0, -9.5, 11.869999885559082 },
      { -0.09000000357627869, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &mew_gfxdata[20],
      { 0.0, -10.289999961853027, 22.15999984741211 },
      { 0.15000000596046448, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &mew_gfxdata[21],
      { 0.0, -27.309999465942383, 70.44000244140625 },
      { 0.3400000035762787, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &mew_gfxdata[22],
      { 0.0, -40.33668518066406, -68.2621078491211 },
      { -0.3199999928474426, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &mew_gfxdata[23],
      { 0.0, -3.102821111679077, -51.196533203125 },
      { 0.3799999952316284, -0.14000000059604645, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &mew_gfxdata[24],
      { 0.0, -3.4570460319519043, -75.53230285644531 },
      { 0.3199999928474426, -0.08028499782085419, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &mew_gfxdata[25],
      { 0.0, -1.6454880237579346, -69.11061096191406 },
      { 0.38999998569488525, -0.05235999822616577, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &mew_gfxdata[26],
      { 0.0, -1.2000000424450263e-05, -68.28799438476562 },
      { -0.03999999910593033, -0.10000000149011612, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 7,
      &mew_gfxdata[27],
      { 0.0, 0.0, -70.75629425048828 },
      { -0.3799999952316284, -0.0872659981250763, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8,
      &mew_gfxdata[28],
      { 0.0, 0.0, -67.4652099609375 },
      { -0.4099999964237213, -0.10471999645233154, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 9,
      &mew_gfxdata[29],
      { 0.0, 0.0, -49.36494827270508 },
      { -0.3179999887943268, -0.17453299462795258, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 10,
      &mew_gfxdata[30],
      { 0.0, -0.822746992111206, -34.55514907836914 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 11,
      &mew_gfxdata[31],
      { 0.0, 0.822746992111206, -78.9834976196289 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
