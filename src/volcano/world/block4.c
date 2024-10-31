#include <common.h>
#include "../volcano.h"

extern Vtx volcano_block4_vtx[];
extern Texture* volcano_block4_materials_mat[];

#include "assets/volcano/block4/draw.gfx.inc.c"
#include "assets/volcano/block4/model.vtx.inc.c"

Texture** volcano_block4_materials[] = {
    volcano_block4_materials_mat,
};

u8* volcano_block4_materials_mat0_textures[] = {
    volcano_world_tex_lava_frame0_png,
    volcano_world_tex_lava_frame1_png,
    volcano_world_tex_lava_frame2_png,
    volcano_world_tex_lava_frame3_png,
    volcano_world_tex_lava_frame3_png,
};

u8* volcano_block4_materials_mat1_textures[] = {
    volcano_world_tex_lava_frame0_png,
    volcano_world_tex_lava_frame1_png,
    volcano_world_tex_lava_frame2_png,
    volcano_world_tex_lava_frame3_png,
    volcano_world_tex_lava_frame3_png,
};

u8* volcano_block4_materials_mat2_textures[] = {
    volcano_world_tex_lava_frame0_png,
    volcano_world_tex_lava_frame1_png,
    volcano_world_tex_lava_frame2_png,
    volcano_world_tex_lava_frame3_png,
    volcano_world_tex_lava_frame3_png,
};

Texture volcano_block4_materials_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block4_materials_mat0_textures,
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

Texture volcano_block4_materials_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block4_materials_mat1_textures,
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

Texture volcano_block4_materials_mat2 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block4_materials_mat2_textures,
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

Texture* volcano_block4_materials_mat[] = {
    &volcano_block4_materials_mat0,
    &volcano_block4_materials_mat1,
    &volcano_block4_materials_mat2,
    NULL,
    NULL,
    NULL,
};

#include "assets/volcano/block4/anim1.matanim.inc.c"
// split ?
__ALIGNER 
#include "assets/volcano/block4/unk.gfx.inc.c"

UnkEC64Arg3 volcano_block4_road[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 268.42133 , 45.405537, 49.282925 },
      { 0.096, -2.356194, 0.0 },
      { 1.45, 1.0, 1.0 } },
    { 1,
      NULL,
      { 315.00873, 43.35329, -41.9216 },
      { 0.096, -2.356194, 0.0 },
      { 1.45, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/volcano/block4/movement.modelanim.inc.c"
