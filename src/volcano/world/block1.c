#include <common.h>
#include "../volcano.h"

extern Vtx volcano_block1_vtx[];
extern Texture* volcano_block1_materials_mat[];

#include "assets/volcano/block1/draw.gfx.inc.c"
#include "assets/volcano/block1/model.vtx.inc.c"

Texture** volcano_block1_materials[] = {
    volcano_block1_materials_mat,
};

u8* volcano_block1_materials_mat0_textures[] = {
    volcano_world_tex_lava_frame0_png,
    volcano_world_tex_lava_frame1_png,
    volcano_world_tex_lava_frame2_png,
    volcano_world_tex_lava_frame3_png,
    volcano_world_tex_lava_frame3_png,
};

Texture volcano_block1_materials_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    volcano_block1_materials_mat0_textures,
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

Texture* volcano_block1_materials_mat[] = {
    &volcano_block1_materials_mat0,
    NULL,
    NULL,
    NULL,
};

#include "assets/volcano/block1/anim1.matanim.inc.c"
// split ?
__ALIGNER 
#include "assets/volcano/block1/unk.gfx.inc.c"

UnkEC64Arg3 volcano_block1_road[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { -863.1173, 233.95062, -378.23947 },
      { 0.0, 0.785398, 0.0 },
      { 5.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { -1035.0308, 233.95062, -237.19025 },
      { 0.0, 0.872665, 0.0 },
      { 5.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/volcano/block1/movement.modelanim.inc.c"
