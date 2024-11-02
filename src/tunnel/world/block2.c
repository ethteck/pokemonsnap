#include "../tunnel.h"

extern Vtx tunnel_block2_vtx[];
extern Texture* tunnel_block1_materials_mat[];

#include "assets/tunnel/block2/draw.gfx.inc.c"
__ALIGNER
#include "assets/tunnel/block2/model.vtx.inc.c"

Texture** tunnel_block1_materials[] = {
    tunnel_block1_materials_mat,
};

u8* tunnel_block1_materials_mat0_textures[] = {
    0x80158DF8, //tunnel_world_tex_lava_frame0_png,
    0x8014DDE0, //tunnel_world_tex_lava_frame0_png,
    NULL, //tunnel_world_tex_lava_frame0_png,
};

Texture tunnel_block1_materials_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    tunnel_block1_materials_mat0_textures,
    32,
    39,
    192,
    160,
    0,
    0.0,
    0.0,
    1.2,
    1.0,
    0.0,
    1.2,
    NULL,
    0xEB,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    32,
    32,
    192,
    160,
    -0.2,
    0.0,
    -0.2,
    { 0, 0, 0, 0 },
    74245,
    { 255, 255, 255, 255 },
    128,
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

Texture* tunnel_block1_materials_mat[] = {
    &tunnel_block1_materials_mat0,
    NULL,
};

#include "assets/tunnel/block2/anim1.matanim.inc.c"
__ALIGNER
#include "assets/tunnel/block2/unk.gfx.inc.c"

UnkEC64Arg3 tunnel_block2_road[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 579.022339, 249.801971, 148.988632 },
      { -0.109113, 0.140282, 0.0 },
      { 0.81, 1.0, 1.0 } },
    { 1,
      NULL,
      { 430.904816, 245.818802, 199.904266 },
      { -0.129018, 0.036786, 0.0 },
      { 0.81, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/tunnel/block2/movement.modelanim.inc.c"
