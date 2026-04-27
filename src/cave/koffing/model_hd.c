#include "common.h"

extern u8 koffing_tex_80161B88[];
extern u8 koffing_tex_80161F90[];
extern u8 koffing_tex_80162398[];
extern u8 koffing_tex_801627A0[];
extern u8 koffing_tex_80162BA8[];
extern u8 koffing_tex_80162BD0_png[];
extern u8 koffing_tex_80162DD8[];
extern u8 koffing_tex_80162E00_png[];
extern u8 koffing_tex_80163208[];
extern u8 koffing_tex_80163230[];
extern u8 koffing_tex_80163660[];
extern u8 koffing_tex_80163A90[];
extern u8 koffing_tex_80163EC0[];
extern u8 koffing_tex_801642F0[];
extern u8 koffing_tex_801646F8[];
extern u8 koffing_tex_80164720[];
extern u8 koffing_tex_80164B50[];
extern u8 koffing_tex_80164F80[];
extern u8 koffing_tex_801653B0[];

extern u8 D_80163188_cave_extra[];
extern u8 D_801631B0_cave_extra[];
extern u8 D_801633B8_cave_extra[];
extern u8 D_801633E0_cave_extra[];
extern u8 D_801637E8_cave_extra[];
extern u8 D_80164CD8_cave_extra[];
extern u8 D_801B8248_cave_extra[];
extern u8 D_801B8358_cave_extra[];
extern u8 D_801B83F8_cave_extra[];
extern u8 D_801B8508_cave_extra[];
extern u8 D_801B8518_cave_extra[];
extern u8 D_801B8558_cave_extra[];
extern u8 D_801B8568_cave_extra[];
extern u8 D_801B8598_cave_extra[];
extern u8 D_801B85A8_cave_extra[];
extern u8 D_801B85B8_cave_extra[];
extern u8 D_801B85C8_cave_extra[];
extern u8 D_801B85E8_cave_extra[];
extern u8 D_801B8618_cave_extra[];
extern u8 D_801B8648_cave_extra[];
extern u8 D_801B8658_cave_extra[];
extern u8 D_801B8688_cave_extra[];
extern u8 D_801B8698_cave_extra[];
extern u8 D_801B86A8_cave_extra[];
extern u8 D_801B86C8_cave_extra[];
extern u8 D_801B86E8_cave_extra[];
extern u8 D_801B8708_cave_extra[];
extern u8 D_801B8718_cave_extra[];
extern u8 D_801B8728_cave_extra[];
extern u8 D_801B8748_cave_extra[];
extern u8 D_801B8758_cave_extra[];
extern u8 D_801B8768_cave_extra[];
extern u8 D_801B8778_cave_extra[];
extern u8 D_801B8788_cave_extra[];
extern u8 D_801B87A8_cave_extra[];
extern u8 D_801B87C8_cave_extra[];
extern u8 D_801B87D8_cave_extra[];
extern u8 D_801B87E8_cave_extra[];
extern u8 D_801B87F8_cave_extra[];
extern u8 D_801B8818_cave_extra[];
extern u8 D_801B8828_cave_extra[];
extern u8 D_801B8838_cave_extra[];
extern u8 D_801B8848_cave_extra[];
extern u8 D_801B8858_cave_extra[];
extern u8 D_801B8868_cave_extra[];
extern u8 D_801B8878_cave_extra[];
extern u8 D_801B8888_cave_extra[];
extern u8 D_801B8898_cave_extra[];
extern u8 D_801B88A8_cave_extra[];
extern u8 D_801B88D8_cave_extra[];
extern u8 D_801B88E8_cave_extra[];
extern u8 D_801B8928_cave_extra[];
extern u8 D_801B8938_cave_extra[];
extern u8 D_801B8958_cave_extra[];
extern u8 D_801B8978_cave_extra[];
extern u8 D_801B8988_cave_extra[];
extern u8 D_801B8998_cave_extra[];
extern u8 D_801B89B8_cave_extra[];
extern u8 D_801B89F8_cave_extra[];
extern u8 D_801B8A18_cave_extra[];
extern u8 D_801B8A28_cave_extra[];
extern u8 D_801B8A48_cave_extra[];
extern u8 D_801B8A58_cave_extra[];
extern u8 D_801B8A68_cave_extra[];
extern u8 D_801B8A78_cave_extra[];
extern u8 D_801B8A88_cave_extra[];
extern u8 D_801B8A98_cave_extra[];
extern u8 D_801B8AA8_cave_extra[];
extern u8 D_801B8AD8_cave_extra[];
extern u8 D_801B8AE8_cave_extra[];
extern u8 D_801B8AF8_cave_extra[];
extern u8 D_801B8B08_cave_extra[];
extern u8 D_801B8B38_cave_extra[];
extern u8 D_801B8B48_cave_extra[];
extern u8 D_801B8B58_cave_extra[];
extern u8 D_801B8B68_cave_extra[];
extern u8 D_801B8B78_cave_extra[];
extern u8 D_801B8BA8_cave_extra[];
extern u8 D_801B8BB8_cave_extra[];
extern u8 D_801B8BC8_cave_extra[];
extern u8 D_801B8BE8_cave_extra[];
extern u8 D_801B8C08_cave_extra[];
extern u8 D_801B8C18_cave_extra[];
extern u8 D_801B8C38_cave_extra[];
extern u8 D_801B8C58_cave_extra[];
extern u8 D_801B8C68_cave_extra[];
extern u8 D_801B8C78_cave_extra[];
extern u8 D_801B8C88_cave_extra[];
extern u8 D_801B8CA8_cave_extra[];
extern u8 D_801B8CB8_cave_extra[];
extern u8 D_801B8D18_cave_extra[];
extern u8 D_801B8D28_cave_extra[];
extern u8 D_801B8D48_cave_extra[];
extern u8 D_801B8D58_cave_extra[];
extern u8 D_801B8D68_cave_extra[];
extern u8 D_801B8D78_cave_extra[];
extern u8 D_801B8D88_cave_extra[];
extern u8 D_801B8DA8_cave_extra[];
extern u8 D_801B8DC8_cave_extra[];
extern u8 D_801B8DE8_cave_extra[];
extern u8 D_801B8E08_cave_extra[];
extern u8 D_801B8E18_cave_extra[];
extern u8 D_801B8E48_cave_extra[];
extern u8 D_801B8E58_cave_extra[];
extern u8 D_801B8E68_cave_extra[];
extern u8 D_801B8E78_cave_extra[];
extern u8 D_801B8F48_cave_extra[];
extern u8 D_801B9008_cave_extra[];
extern u8 D_801B9018_cave_extra[];
extern u8 D_801B90A8_cave_extra[];
extern u8 D_801B9148_cave_extra[];
extern u8 D_801B9178_cave_extra[];
extern u8 D_801B9188_cave_extra[];
extern u8 D_801B91D8_cave_extra[];
extern u8 D_801B91F8_cave_extra[];
extern u8 D_801B92C8_cave_extra[];
extern u8 D_801B9378_cave_extra[];
extern u8 D_801B9398_cave_extra[];
extern u8 D_801B93A8_cave_extra[];
extern u8 D_801B9408_cave_extra[];
extern u8 D_801B9438_cave_extra[];
extern u8 D_801B9458_cave_extra[];
extern u8 D_801B9488_cave_extra[];
extern u8 D_801B9558_cave_extra[];
extern u8 D_801B9568_cave_extra[];
extern u8 D_801B9588_cave_extra[];
extern u8 D_801B9648_cave_extra[];
extern u8 D_801B96E8_cave_extra[];
extern u8 D_801B9708_cave_extra[];
extern u8 D_801B9728_cave_extra[];
extern u8 D_801B97C8_cave_extra[];
extern u8 D_801B9888_cave_extra[];
extern u8 D_801B98C8_cave_extra[];
extern u8 D_801B9A08_cave_extra[];
extern u8 D_801B9AC8_cave_extra[];
extern u8 D_801B9B38_cave_extra[];

extern Texture* koffing_hd_part1_mat[];
extern Texture* koffing_hd_part7_mat[];
extern Texture* koffing_hd_part8_mat[];
extern Texture* koffing_hd_part9_mat[];
extern Texture* koffing_hd_part10_mat[];
extern Texture* koffing_hd_part11_mat[];
extern Texture* koffing_hd_part12_mat[];
extern Texture* koffing_hd_part13_mat[];
extern Texture* koffing_hd_part14_mat[];
extern Texture* koffing_hd_part15_mat[];
extern Gfx koffing_hd_part0_draw[];

Texture** koffing_hd_materials[] = {
    NULL,
    koffing_hd_part1_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    koffing_hd_part7_mat,
    koffing_hd_part8_mat,
    koffing_hd_part9_mat,
    koffing_hd_part10_mat,
    koffing_hd_part11_mat,
    koffing_hd_part12_mat,
    koffing_hd_part13_mat,
    koffing_hd_part14_mat,
    koffing_hd_part15_mat,
};

u8* koffing_hd_part1_mat0_textures[] = {
    koffing_tex_80164720,
    koffing_tex_80164B50,
    koffing_tex_80164F80,
    koffing_tex_801653B0,
};

u8* koffing_hd_part1_mat1_textures[] = {
    koffing_tex_80163230,
    koffing_tex_80163660,
    koffing_tex_80163A90,
    koffing_tex_80163EC0,
    koffing_tex_801642F0,
};

u8* koffing_hd_part7_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_hd_part8_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_hd_part9_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_hd_part10_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_hd_part11_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_hd_part12_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_hd_part13_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_hd_part14_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

u8* koffing_hd_part15_mat0_textures[] = {
    koffing_tex_80161B88,
    koffing_tex_80161F90,
    koffing_tex_80162398,
    koffing_tex_801627A0,
    koffing_tex_801627A0,
};

Texture koffing_hd_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    koffing_hd_part1_mat0_textures,
    32,
    0,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture koffing_hd_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    koffing_hd_part1_mat1_textures,
    32,
    0,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture koffing_hd_part7_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part7_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_hd_part8_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part8_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_hd_part9_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part9_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_hd_part10_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part10_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_hd_part11_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part11_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_hd_part12_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part12_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_hd_part13_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part13_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_hd_part14_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part14_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture koffing_hd_part15_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    koffing_hd_part15_mat0_textures,
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
    0x210,
    G_IM_FMT_I,
    G_IM_SIZ_8b,
    32,
    32,
    32,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 153, 154, 84, 255 },
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

Texture* koffing_hd_part1_mat[] = {
    &koffing_hd_part1_mat0,
    &koffing_hd_part1_mat1,
    NULL,
};

Texture* koffing_hd_part7_mat[] = {
    &koffing_hd_part7_mat0,
    NULL,
};

Texture* koffing_hd_part8_mat[] = {
    &koffing_hd_part8_mat0,
    NULL,
};

Texture* koffing_hd_part9_mat[] = {
    &koffing_hd_part9_mat0,
    NULL,
};

Texture* koffing_hd_part10_mat[] = {
    &koffing_hd_part10_mat0,
    NULL,
};

Texture* koffing_hd_part11_mat[] = {
    &koffing_hd_part11_mat0,
    NULL,
};

Texture* koffing_hd_part12_mat[] = {
    &koffing_hd_part12_mat0,
    NULL,
};

Texture* koffing_hd_part13_mat[] = {
    &koffing_hd_part13_mat0,
    NULL,
};

Texture* koffing_hd_part14_mat[] = {
    &koffing_hd_part14_mat0,
    NULL,
};

Texture* koffing_hd_part15_mat[] = {
    &koffing_hd_part15_mat0,
    NULL,
    NULL,
};

extern Gfx koffing_hd_part0_draw[];

#include "assets/cave/koffing/hd_model.vtx.inc.c"
#include "assets/cave/koffing/hd_first.gfx.inc.c"
#include "assets/cave/koffing/hd_part0_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part1_pre.gfx.inc.c"
#include "assets/cave/koffing/hd_part1_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part2_pre.gfx.inc.c"
#include "assets/cave/koffing/hd_part2_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part3_pre.gfx.inc.c"
#include "assets/cave/koffing/hd_part3_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part4_pre.gfx.inc.c"
#include "assets/cave/koffing/hd_part4_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part5_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part6_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part7_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part8_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part9_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part10_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part11_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part12_draw.gfx.inc.c"
#include "assets/cave/koffing/hd_part13_draw.gfx.inc.c"

DObjPayloadTypeJ koffing_hd_gfxdata[] = {
    { 0, NULL, koffing_hd_first },
    { 4, NULL, NULL },
    { 0, koffing_hd_part1_pre, koffing_hd_part1_draw },
    { 4, NULL, NULL },
    { 0, koffing_hd_part2_pre, koffing_hd_part2_draw },
    { 4, NULL, NULL },
    { 0, koffing_hd_part3_pre, koffing_hd_part3_draw },
    { 4, NULL, NULL },
    { 0, koffing_hd_part4_pre, koffing_hd_part4_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part5_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part6_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part7_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part8_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part9_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part10_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part11_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part12_draw },
    { 4, NULL, NULL },
    { 1, NULL, koffing_hd_part13_draw },
    { 4, NULL, NULL },
};

UnkEC64Arg3 koffing_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &koffing_hd_gfxdata[0],
      { 0.0, 320.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &koffing_hd_gfxdata[2],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &koffing_hd_gfxdata[4],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &koffing_hd_gfxdata[6],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &koffing_hd_gfxdata[8],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 320.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[10],
      { 121.853271484375, -302.0307312011719, 175.6286163330078 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[12],
      { -164.12094116210938, 152.55810546875, -250.7587890625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[14],
      { 207.64553833007812, -78.74152374267578, 277.721435546875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[16],
      { 326.616943359375, -84.74930572509766, -106.62786865234375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[18],
      { 0.6086530089378357, -304.17236328125, -215.35525512695312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[20],
      { -314.60418701171875, -214.2027130126953, 102.09274291992188 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[22],
      { -300.3055114746094, 160.56842041015625, 87.07910919189453 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[24],
      { 308.819580078125, 160.56842041015625, 87.07910919189453 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32770,
      &koffing_hd_gfxdata[26],
      { 0.41495099663734436, 316.90576171875, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
