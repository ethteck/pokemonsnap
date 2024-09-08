#include <common.h>

extern u8 moltres_egg_tex_flame_png[];

#include "assets/volcano/moltres_egg/model.vtx.inc.c"
#include "assets/volcano/moltres_egg/draw.gfx.inc.c"

UnkEC64Arg3 moltres_egg_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      moltres_egg_draw,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
