#include <common.h>

extern Vtx volcano_block2_vtx[];
extern Texture* volcano_block2_materials_mat[];

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
extern u8 volcano_world_tex5_var1_pal[];
extern u8 volcano_world_tex5_var0_png[];
extern u8 volcano_world_tex5_var1_png[];
extern u8 volcano_world_tex5_var2_png[];
extern u8 volcano_world_tex5_var3_png[];

#include "assets/volcano/block2/draw.gfx.inc.c"
// split ?
__ALIGNER
#include "assets/volcano/block2/model.vtx.inc.c"
#include "assets/volcano/block2/unk.gfx.inc.c"

UnkEC64Arg3 volcano_block2_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { -510.21918, 119.34545, -395.70618 },
      { 0.0, -1.908523, 0.0 },
      { 4.35, 1.0, 1.0 } },
    { 1,
      NULL,
      { -485.34793, 119.44345, -506.195 },
      { 0.0, -1.91014, 0.0 },
      { 4.35, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

#include "assets/volcano/block2/movement.modelanim.inc.c"
