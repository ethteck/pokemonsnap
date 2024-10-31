#include <common.h>
#include "../volcano.h"

extern Vtx volcano_block2_vtx[];
extern Texture* volcano_block2_materials_mat[];

#include "assets/volcano/block2/draw.gfx.inc.c"
// split ?
__ALIGNER
#include "assets/volcano/block2/model.vtx.inc.c"
#include "assets/volcano/block2/unk.gfx.inc.c"

UnkEC64Arg3 volcano_block2_road[] = {
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
