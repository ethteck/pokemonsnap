#include <common.h>

extern Vtx volcano_block0_vtx[];
extern Texture* volcano_block0_materials_mat[];

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

#include "assets/volcano/block0/draw.gfx.inc.c"
#include "assets/volcano/block0/model.vtx.inc.c"

Texture** volcano_block0_materials[] = {
    volcano_block0_materials_mat,
};

u8* volcano_block0_materials_mat0_textures[] = {
    volcano_world_tex5_var0_png,
    volcano_world_tex5_var1_png,
    volcano_world_tex5_var2_png,
    volcano_world_tex5_var3_png,
    volcano_world_tex5_var3_png,
};

u8* volcano_block0_materials_mat1_textures[] = {
    volcano_world_tex5_var0_png,
    volcano_world_tex5_var1_png,
    volcano_world_tex5_var2_png,
    volcano_world_tex5_var3_png,
    volcano_world_tex5_var3_png,
    NULL,
};

Texture volcano_block0_materials_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block0_materials_mat0_textures,
    32,
    0,
    192,
    384,
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
    192,
    384,
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

Texture volcano_block0_materials_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block0_materials_mat1_textures,
    32,
    0,
    96,
    192,
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
    96,
    192,
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

Texture* volcano_block0_materials_mat[] = {
    &volcano_block0_materials_mat0,
    &volcano_block0_materials_mat1,
    NULL,
    NULL,
};

#include "assets/volcano/block0/anim1.matanim.inc.c"
// split ?
__ALIGNER 
#include "assets/volcano/block0/unk.gfx.inc.c"

UnkEC64Arg3 volcano_block0_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 1136.8828, 233.95064, 1121.7606 },
      { 0.0, 0.785398, 0.0 },
      { 5.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 964.96906, 233.95064, 1262.8098 },
      { 0.0, 0.872665, 0.0 },
      { 5.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/volcano/block0/movement.modelanim.inc.c"
