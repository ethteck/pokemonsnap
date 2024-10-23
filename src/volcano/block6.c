#include <common.h>

extern Vtx volcano_block6_vtx[];
extern Texture* volcano_block6_materials_mat[];

extern u8 volcano_world_tex0_pal[];
extern u8 volcano_world_tex0_png[];
extern u8 volcano_world_tex1_pal[];
extern u8 volcano_world_tex1_png[];
extern u8 volcano_world_tex2_pal[];
extern u8 volcano_world_tex2_png[];
extern u8 volcano_world_tex3_pal[];
extern u8 volcano_world_tex3_png[];
extern u8 volcano_world_tex4_pal[];
extern u8 volcano_world_tex4_png[];
extern u8 volcano_world_tex5_pal[];
extern u8 volcano_world_tex5_var0_png[];
extern u8 volcano_world_tex5_var1_png[];
extern u8 volcano_world_tex5_var2_png[];
extern u8 volcano_world_tex5_var3_png[];
extern u8 volcano_world_tex5_var0_pal[];
extern u8 volcano_world_tex6_pal[];
extern u8 volcano_world_tex6_png[];
extern u8 volcano_world_tex7_pal[];
extern u8 volcano_world_tex7_png[];
extern u8 D_8012A580_351200[];
extern u8 D_80122ED8_349B58[];
extern u8 D_80122F00_349B80[];
extern u8 volcano_world_tex8_var0_png[];
extern u8 volcano_world_tex8_var1_png[];
extern u8 volcano_world_tex8_var2_png[];
extern u8 volcano_world_tex8_var3_png[];

#include "assets/volcano/block6/draw.gfx.inc.c"
__ALIGNER
#include "assets/volcano/block6/model.vtx.inc.c"

Texture** volcano_block6_materials[] = {
    volcano_block6_materials_mat,
};

u8* volcano_block6_materials_mat0_textures[] = {
    volcano_world_tex5_var0_png,
    volcano_world_tex5_var1_png,
    volcano_world_tex5_var0_png,
    volcano_world_tex5_var2_png,
    volcano_world_tex5_var2_png,
};

Texture volcano_block6_materials_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block6_materials_mat0_textures,
    32,
    128,
    32,
    128,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xF3,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    64,
    32,
    128,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
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

Texture* volcano_block6_materials_mat[] = {
    &volcano_block6_materials_mat0,
    NULL,
    NULL,
    NULL,
};

#include "assets/volcano/block6/anim1.matanim.inc.c"
