#include "common.h"
#include "sys/anim.h"

#include "assets/intro/unk/model.vtx.inc.c"
#include "assets/intro/unk/part0_draw.gfx.inc.c"

UnkEC64Arg3 intro_unk_model[] = {
    { 0,
      NULL,
      { -25.957372665405273, 183.3184051513672, 528.2341918945312 },
      { -0.275177001953125, -0.6038399934768677, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      intro_unk_part0_draw,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

static u8 pad_0[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#include "assets/intro/unk/intro_unk_modelanim.modelanim.inc.c"
