#include <common.h>

extern u8 magikarp_tex_scales_png[];
extern u8 magikarp_tex_tongue_png[];
extern u8 magikarp_tex_barbel_png[];
extern u8 magikarp_tex_arm_fin_pal[];
extern u8 magikarp_tex_arm_fin_png[];
extern u8 magikarp_tex_belly_fin_pal[];
extern u8 magikarp_tex_belly_fin_png[];
extern u8 magikarp_tex_skin1_pal[];
extern u8 magikarp_tex_skin1_png[];
extern u8 magikarp_tex_mouth_png[];
extern u8 magikarp_tex_eye_pal[];
extern u8 magikarp_tex_eye_png[];
extern u8 magikarp_tex_skin2_pal[];
extern u8 magikarp_tex_skin2_png[];
extern u8 magikarp_tex_tail_fin_pal[];
extern u8 magikarp_tex_tail_fin_png[];
extern u8 magikarp_tex_skin3_pal[];
extern u8 magikarp_tex_skin3_png[];

extern Gfx magikarp_part0[];

#include "assets/pokemon_common/magikarp/model.vtx.inc.c"
#include "assets/pokemon_common/magikarp/first.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part0_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part0.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part1_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part1.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part2_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part2.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part3_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part3.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part4_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part4.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part5_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part5.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part6_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part6.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part7_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part7.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part8_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part8.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part9_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part9.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part10_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part10.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part11_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part11.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part12_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part12.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part13_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part13.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part14_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part14.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part15_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/part15.gfx.inc.c"
#include "assets/pokemon_common/magikarp/last.gfx.inc.c"

UnkEC64Arg3 magikarp_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 42.79996871948242 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 1,
      magikarp_first,
      { -3.111345052719116, 3.257154941558838, 128.33934020996094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magikarp_part1,
      { 2.908905029296875, 0.729852020740509, -126.41014862060547 },
      { 0.0007789999945089221, -0.025395000353455544, 0.03621099889278412 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magikarp_part2,
      { -1.116433024406433, -3.5000000934815034e-05, -107.8675765991211 },
      { -0.0032210000790655613, 0.026697000488638878, 0.004935000091791153 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      magikarp_part3,
      { 0.0520239993929863, -0.6030200123786926, -116.55269622802734 },
      { 0.002618999918922782, -0.0011909999884665012, -0.04116800054907799 },
      { 1.0, 1.0, 1.0 }
    },
    { 5,
      magikarp_part4,
      { -1.3544319868087769, -3.224087953567505, -123.91679382324219 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 6,
      magikarp_part5,
      { 0.0, -9.999999974752427e-07, 1.599979043006897 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magikarp_part6,
      { -7.25779914855957, -6.284588813781738, -88.97238159179688 },
      { -0.0016980000073090196, 0.02535099908709526, -0.036242999136447906 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      NULL,
      { 3.111345052719116, -3.257154941558838, -171.13926696777344 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magikarp_part7,
      { 56.93937683105469, -10.556208610534668, 50.57380294799805 },
      { -0.1884640008211136, 0.005193999968469143, -0.3985059857368469 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magikarp_part8,
      { 104.39999389648438, -1.600000023841858, -2.4000000848900527e-05 },
      { -0.040240999311208725, 0.12219599634408951, -0.6910219788551331 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      magikarp_part9,
      { 101.99998474121094, -0.39990198612213135, 0.0 },
      { -0.009182999841868877, -0.05338500067591667, 0.28517600893974304 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magikarp_part10,
      { -50.7166862487793, -10.556208610534668, 50.57380294799805 },
      { 0.1884640008211136, 3.136399030685425, 0.43850600719451904 },
      { 1.0, 1.0, 1.0 }
    },
    { 3,
      magikarp_part11,
      { 104.39999389648438, -1.600000023841858, -2.4000000848900527e-05 },
      { 0.040240999311208725, -0.12219599634408951, -0.6910200119018555 },
      { 1.0, 1.0, 1.0 }
    },
    { 4,
      magikarp_part12,
      { 101.99998474121094, -0.3998990058898926, 0.0 },
      { 0.010995999909937382, 0.058708999305963516, 0.31474798917770386 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magikarp_part13,
      { 114.8488998413086, -69.09553527832031, -42.32538986206055 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magikarp_part14,
      { -108.626220703125, -69.095458984375, -42.325496673583984 },
      { 0.0, 3.141592025756836, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 2,
      magikarp_last,
      { 0.7704650163650513, -1.9586379528045654, 111.12895202636719 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 }
    },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 }
    },
};
