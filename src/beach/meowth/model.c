#include "common.h"

extern u8 meowth_tex_8018A5A8[];
extern u8 meowth_tex_8018A7B0[];
extern u8 meowth_tex_8018B000[];
extern u8 meowth_tex_8018B850[];
extern u8 meowth_tex_8018C0A0[];
extern u8 meowth_tex_8018C6E8[];
extern u8 meowth_tex_8018C710_png[];
extern u8 meowth_tex_8018C998[];
extern u8 meowth_tex_8018C9C0_png[];
extern u8 meowth_tex_8018CA48[];
extern u8 meowth_tex_8018CA70_png[];
extern u8 meowth_tex_8018CCF8[];
extern u8 meowth_tex_8018CD20_png[];
extern u8 meowth_tex_8018CF50[];
extern u8 meowth_tex_8018D380[];
extern u8 meowth_tex_8018D788[];
extern u8 meowth_tex_8018D7B0[];
extern u8 meowth_tex_8018DDC0[];
extern u8 meowth_tex_8018E3D0[];
extern u8 meowth_tex_8018E9E0[];
extern u8 meowth_tex_8018EFF0[];
extern u8 meowth_tex_8018F3F8[];
extern u8 meowth_tex_8018F600[];
extern u8 meowth_tex_8018FC10[];
extern u8 meowth_tex_80190018[];
extern u8 meowth_tex_80190040_png[];
extern u8 meowth_tex_80190248[];
extern u8 meowth_tex_80190270_png[];
extern u8 meowth_tex_80190478[];
extern u8 meowth_tex_80190498_png[];

extern Texture* meowth_part12_mat[];
extern Texture* meowth_part19_mat[];
extern Gfx meowth_part0_draw[];

Texture** meowth_materials[] = {
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
    meowth_part12_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    meowth_part19_mat,
};

u8* meowth_part12_mat0_textures[] = {
    meowth_tex_8018F600,
    meowth_tex_8018E3D0,
    meowth_tex_8018E9E0,
    meowth_tex_8018EFF0,
    meowth_tex_8018DDC0,
    meowth_tex_8018FC10,
};

u8* meowth_part12_mat1_textures[] = {
    meowth_tex_8018D7B0,
    meowth_tex_8018CF50,
    meowth_tex_8018D380,
};

u8* meowth_part19_mat0_textures[] = {
    meowth_tex_8018A7B0,
    meowth_tex_8018B000,
    meowth_tex_8018B850,
    meowth_tex_8018C0A0,
    NULL,
};

Texture meowth_part12_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    meowth_part12_mat0_textures,
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
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 23, 23, 23, 0 },
    0,
    0,
    0,
    0,
};

Texture meowth_part12_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    meowth_part12_mat1_textures,
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
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 23, 23, 23, 0 },
    0,
    0,
    0,
    0,
};

Texture meowth_part19_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    meowth_part19_mat0_textures,
    128,
    64,
    40,
    40,
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
    40,
    40,
    40,
    40,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 0 },
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* meowth_part12_mat[] = {
    &meowth_part12_mat0,
    &meowth_part12_mat1,
    NULL,
};

Texture* meowth_part19_mat[] = {
    &meowth_part19_mat0,
    NULL,
};

#include "assets/beach/meowth/model.vtx.inc.c"
#include "assets/beach/meowth/first.gfx.inc.c"
#include "assets/beach/meowth/part0_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part0_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part0_draw.gfx.inc.c"
#include "assets/beach/meowth/part1_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part1_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part1_draw.gfx.inc.c"
#include "assets/beach/meowth/part2_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part2_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part2_draw.gfx.inc.c"
#include "assets/beach/meowth/part3_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part3_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part3_draw.gfx.inc.c"
#include "assets/beach/meowth/part4_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part4_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part4_draw.gfx.inc.c"
#include "assets/beach/meowth/part5_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part5_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part5_draw.gfx.inc.c"
#include "assets/beach/meowth/part6_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part6_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part6_draw.gfx.inc.c"
#include "assets/beach/meowth/part7_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part7_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part7_draw.gfx.inc.c"
#include "assets/beach/meowth/part8_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part8_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part8_draw.gfx.inc.c"
#include "assets/beach/meowth/part9_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part9_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part9_draw.gfx.inc.c"
#include "assets/beach/meowth/part10_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part10_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part10_draw.gfx.inc.c"
#include "assets/beach/meowth/part11_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part11_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part11_draw.gfx.inc.c"
#include "assets/beach/meowth/part12_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part12_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part12_draw.gfx.inc.c"
#include "assets/beach/meowth/part13_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part13_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part13_draw.gfx.inc.c"
#include "assets/beach/meowth/part14_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part14_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part14_draw.gfx.inc.c"
#include "assets/beach/meowth/part15_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part15_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part15_draw.gfx.inc.c"
#include "assets/beach/meowth/part16_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part16_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part16_draw.gfx.inc.c"
#include "assets/beach/meowth/part17_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part17_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part17_draw.gfx.inc.c"
#include "assets/beach/meowth/last.gfx.inc.c"
#include "assets/beach/meowth/part18_draw_near.gfx.inc.c"
#include "assets/beach/meowth/part18_draw_far.gfx.inc.c"
#include "assets/beach/meowth/part18_draw.gfx.inc.c"

UnkEC64Arg3 meowth_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      meowth_first,
      { 0.0, 169.39224243164062, -14.465350151062012 },
      { 0.19078099727630615, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      meowth_part1_draw,
      { 2.017836093902588, -60.585838317871094, -22.744281768798828 },
      { -0.27000001072883606, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_part2_draw,
      { 37.521785736083984, 13.502860069274902, 2.8693320751190186 },
      { 0.15000000596046448, 0.699999988079071, 0.28999999165534973 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      meowth_part3_draw,
      { 1.1864540576934814, -78.61558532714844, 2.1437020301818848 },
      { 0.36000001430511475, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      meowth_part4_draw,
      { 0.3435400128364563, -26.576438903808594, 2.9655160903930664 },
      { -0.25999999046325684, 0.0, -0.1899999976158142 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      meowth_part5_draw,
      { 1.1440579891204834, -20.517919540405273, 52.408878326416016 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_part6_draw,
      { -37.521785736083984, 13.502860069274902, 2.8693320751190186 },
      { 0.15000000596046448, -0.699999988079071, -0.28999999165534973 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      meowth_part7_draw,
      { -1.1864540576934814, -78.61557006835938, 2.1437020301818848 },
      { 0.36000001430511475, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      meowth_part8_draw,
      { -0.3435460031032562, -26.576440811157227, 2.965522050857544 },
      { -0.25, 0.0, 0.15000000596046448 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      meowth_part9_draw,
      { -1.1443639993667603, -20.5179443359375, 52.40889358520508 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_part10_draw,
      { 0.0, -23.14934730529785, -34.42304611206055 },
      { 0.020739000290632248, -0.6063809990882874, -0.015571000054478645 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      meowth_part11_draw,
      { 0.0, 54.177974700927734, -1.0905519723892212 },
      { 0.7799999713897705, -0.0031250000465661287, 0.032708000391721725 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      meowth_part12_draw,
      { 48.51081848144531, 18.591249465942383, 0.3160969913005829 },
      { 0.0, -0.8783550262451172, -0.1599999964237213 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_part13_draw,
      { 84.05374145507812, 4.084194183349609, 5.53736686706543 },
      { 0.5449659824371338, -0.060552000999450684, 1.279999017715454 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      meowth_part14_draw,
      { 63.901771545410156, 4.261016845703125, 1.0627659559249878 },
      { 0.03323199972510338, -0.00024199999461416155, -2.490818977355957 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      meowth_part15_draw,
      { -48.51081848144531, 18.591249465942383, 0.3160969913005829 },
      { 0.0, 0.6608859896659851, 0.1599999964237213 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_part16_draw,
      { -84.05374145507812, 4.084240913391113, 5.537361145019531 },
      { 0.0, -0.07616999745368958, -1.2799999713897705 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      meowth_last,
      { -63.901771545410156, 4.260993003845215, 1.0627670288085938 },
      { 0.0, 0.0, 2.26542592048645 },
      { 1.0, 1.0, 1.0 } },
    { 32773,
      meowth_part18_draw,
      { -61.1363410949707, -5.288516998291016, 35.91791915893555 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
