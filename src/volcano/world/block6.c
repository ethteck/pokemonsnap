#include <common.h>
#include "../volcano.h"

extern Vtx volcano_block6_vtx[];
extern Texture* volcano_block6_materials_mat[];

#include "assets/volcano/block6/draw.gfx.inc.c"
__ALIGNER
#include "assets/volcano/block6/model.vtx.inc.c"

Texture** volcano_block6_materials[] = {
    volcano_block6_materials_mat,
};

u8* volcano_block6_materials_mat0_textures[] = {
    volcano_world_tex_lava_frame0_png,
    volcano_world_tex_lava_frame1_png,
    volcano_world_tex_lava_frame0_png,
    volcano_world_tex_lava_frame2_png,
    volcano_world_tex_lava_frame2_png,
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
