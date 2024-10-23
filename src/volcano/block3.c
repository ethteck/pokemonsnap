#include <common.h>

extern Vtx volcano_block3_vtx[];
extern Texture* volcano_block3_materials_mat[];

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

#include "assets/volcano/block3/draw.gfx.inc.c"
#include "assets/volcano/block3/model.vtx.inc.c"

Texture** volcano_block3_materials[] = {
    volcano_block3_materials_mat,
};

u8* volcano_block3_materials_mat0_textures[] = {
    volcano_world_tex5_var0_png,
    volcano_world_tex5_var1_png,
    volcano_world_tex5_var0_png,
    volcano_world_tex5_var2_png,
    volcano_world_tex5_var2_png,
};

u8* volcano_block3_materials_mat1_textures[] = {
    volcano_world_tex5_var0_png,
    volcano_world_tex5_var1_png,
    volcano_world_tex5_var2_png,
    volcano_world_tex5_var3_png,
    volcano_world_tex5_var3_png,
    NULL,
};

Texture volcano_block3_materials_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block3_materials_mat0_textures,
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

Texture volcano_block3_materials_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block3_materials_mat1_textures,
    32,
    0,
    512,
    1024,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    64,
    512,
    1024,
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

Texture* volcano_block3_materials_mat[] = {
    &volcano_block3_materials_mat0,
    &volcano_block3_materials_mat1,
    NULL,
    NULL,
};

#include "assets/volcano/block3/anim1.matanim.inc.c"
// split ?
__ALIGNER 
#include "assets/volcano/block3/unk.gfx.inc.c"

UnkEC64Arg3 volcano_block3_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 165.74583, 114.75801, -391.05057 },
      { 0.061176, -1.115626, 0.0 },
      { 0.68, 1.0, 1.0 } },
    { 1,
      NULL,
      { 108.339165, 93.307915, -601.555 },
      { 0.061176, -1.108209, 0.0 },
      { 0.68, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/volcano/block3/movement.modelanim.inc.c"
