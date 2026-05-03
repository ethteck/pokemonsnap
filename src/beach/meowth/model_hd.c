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

extern Texture* meowth_hd_part12_mat[];
extern Texture* meowth_hd_part19_mat[];
extern Gfx meowth_hd_part0_draw[];

__ALIGNER
u8 meowth_hd_tex_801C8A38[] = {
#include "assets/beach/meowth/tex_801C8A50_hd.pal.bin.c"
};

__ALIGNER
u8 meowth_hd_tex_801C8A50[] = {
#include "assets/beach/meowth/tex_801C8A50_hd.png.bin.c"
};

Texture** meowth_hd_materials[] = {
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
    meowth_hd_part12_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    meowth_hd_part19_mat,
};

u8* meowth_hd_part12_mat0_textures[] = {
    meowth_tex_8018F600,
    meowth_tex_8018E3D0,
    meowth_tex_8018E9E0,
    meowth_tex_8018EFF0,
    meowth_tex_8018DDC0,
    meowth_tex_8018FC10,
};

u8* meowth_hd_part12_mat1_textures[] = {
    meowth_tex_8018D7B0,
    meowth_tex_8018CF50,
    meowth_tex_8018D380,
};

u8* meowth_hd_part19_mat0_textures[] = {
    meowth_tex_8018A7B0,
    meowth_tex_8018B000,
    meowth_tex_8018B850,
    meowth_tex_8018C0A0,
    NULL,
};

Texture meowth_hd_part12_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    meowth_hd_part12_mat0_textures,
    128,
    64,
    32,
    32,
    0,
    0.0,
    0.012000000104308128,
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
    0.012000000104308128,
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

Texture meowth_hd_part12_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    meowth_hd_part12_mat1_textures,
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

Texture meowth_hd_part19_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    meowth_hd_part19_mat0_textures,
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

Texture* meowth_hd_part12_mat[] = {
    &meowth_hd_part12_mat0,
    &meowth_hd_part12_mat1,
    NULL,
};

Texture* meowth_hd_part19_mat[] = {
    &meowth_hd_part19_mat0,
    NULL,
    NULL,
};
#include "assets/beach/meowth/hd_model.vtx.inc.c"
#include "assets/beach/meowth/hd_first.gfx.inc.c"
#include "assets/beach/meowth/hd_part0_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part1_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part2_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part3_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part4_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part5_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part6_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part7_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part8_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part9_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part10_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part11_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part12_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part13_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part14_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part15_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part16_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part17_draw.gfx.inc.c"
#include "assets/beach/meowth/hd_part18_draw.gfx.inc.c"

UnkEC64Arg3 meowth_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      meowth_hd_first,
      { 0.0, 172.58839416503906, -14.515995979309082 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      meowth_hd_part1_draw,
      { 0.0, -56.599761962890625, -8.984539031982422 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_hd_part2_draw,
      { 37.653160095214844, 13.549637794494629, 2.879422903060913 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      meowth_hd_part3_draw,
      { 1.1906150579452515, -78.89081573486328, 2.151215076446533 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      meowth_hd_part4_draw,
      { 0.3447529971599579, -26.669403076171875, 2.9758589267730713 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      meowth_hd_part5_draw,
      { 1.1480330228805542, -20.58976936340332, 52.592342376708984 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_hd_part6_draw,
      { -37.653160095214844, 13.549637794494629, 2.879422903060913 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      meowth_hd_part7_draw,
      { -1.1906150579452515, -78.89071655273438, 2.151215076446533 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      meowth_hd_part8_draw,
      { -0.3447529971599579, -26.66950225830078, 2.9758589267730713 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      meowth_hd_part9_draw,
      { -1.1483670473098755, -20.58976936340332, 52.592342376708984 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_hd_part10_draw,
      { 0.0, -23.230606079101562, -34.54350662231445 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      meowth_hd_part11_draw,
      { 0.0, 54.3675422668457, -1.094364047050476 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      meowth_hd_part12_draw,
      { 48.68059158325195, 18.65638542175293, 0.3172529935836792 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_hd_part13_draw,
      { 84.34796142578125, 4.098392009735107, 5.5566630363464355 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      meowth_hd_part14_draw,
      { 64.12544250488281, 4.275929927825928, 1.0665769577026367 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      meowth_hd_part15_draw,
      { -48.68059158325195, 18.65638542175293, 0.3172529935836792 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      meowth_hd_part16_draw,
      { -84.34796142578125, 4.098498821258545, 5.5566630363464355 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      meowth_hd_part17_draw,
      { -64.12544250488281, 4.275929927825928, 1.0665769577026367 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32773,
      meowth_hd_part18_draw,
      { -60.44866943359375, -5.984879016876221, 35.944297790527344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
