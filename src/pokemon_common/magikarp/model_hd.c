#include "common.h"

extern u8 magikarp_tex_arm_fin_pal[];
extern u8 magikarp_tex_arm_fin_png[];
extern u8 magikarp_tex_barbel_png[];
extern u8 magikarp_tex_belly_fin_pal[];
extern u8 magikarp_tex_belly_fin_png[];
extern u8 magikarp_tex_eye_pal[];
extern u8 magikarp_tex_eye_png[];
extern u8 magikarp_tex_mouth_png[];
extern u8 magikarp_tex_scales_png[];
extern u8 magikarp_tex_skin1_pal[];
extern u8 magikarp_tex_skin1_png[];
extern u8 magikarp_tex_skin2_pal[];
extern u8 magikarp_tex_skin2_png[];
extern u8 magikarp_tex_skin3_pal[];
extern u8 magikarp_tex_skin3_png[];
extern u8 magikarp_tex_tail_fin_pal[];
extern u8 magikarp_tex_tail_fin_png[];
extern u8 magikarp_tex_tongue_png[];

extern Gfx magikarp_hd_part0_draw[];

#include "assets/pokemon_common/magikarp/hd_model.vtx.inc.c"
#include "assets/pokemon_common/magikarp/hd_first.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part0_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part1_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part2_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part3_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part4_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part5_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part6_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part7_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part8_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part9_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part10_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part11_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part12_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part13_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part14_draw.gfx.inc.c"
#include "assets/pokemon_common/magikarp/hd_part15_draw.gfx.inc.c"

UnkEC64Arg3 magikarp_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, -6.000000212225132e-06 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      magikarp_hd_first,
      { -1.6053440570831299, 3.2572150230407715, 171.1348114013672 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      magikarp_hd_part1_draw,
      { 1.4044610261917114, 0.7301599979400635, -126.8056640625 },
      { 0.0007789999945089221, -0.025395000353455544, 0.03621099889278412 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      magikarp_hd_part2_draw,
      { -1.1078540086746216, -3.9999998989515007e-05, -107.46794128417969 },
      { -0.0032210000790655613, 0.026697000488638878, 0.004935000091791153 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      magikarp_hd_part3_draw,
      { 0.05203799903392792, -0.6030210256576538, -117.352783203125 },
      { 0.002618999918922782, -0.0011909999884665012, -0.04116800054907799 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      magikarp_hd_part4_draw,
      { -1.3534760475158691, -3.2220029830932617, -123.11698150634766 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      magikarp_hd_part5_draw,
      { 0.0, 0.0, 4.8000102043151855 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      magikarp_hd_part6_draw,
      { -7.249183177947998, 4.515417098999023, -88.57254791259766 },
      { -0.0016980000073090196, 0.02535099908709526, -0.036242999136447906 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 1.6053440570831299, -3.2572150230407715, -171.13478088378906 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      magikarp_hd_part7_draw,
      { 55.43337631225586, -10.556267738342285, 50.57830810546875 },
      { -0.1884640008211136, 0.005193999968469143, -0.3985059857368469 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      magikarp_hd_part8_draw,
      { 104.39999389648438, -1.600000023841858, -2.4000000848900527e-05 },
      { -0.040240999311208725, 0.12219599634408951, -0.6910219788551331 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      magikarp_hd_part9_draw,
      { 101.99998474121094, -0.39990198612213135, 0.0 },
      { -0.009182999841868877, -0.05338500067591667, 0.28517600893974304 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      magikarp_hd_part10_draw,
      { -52.222686767578125, -10.556267738342285, 50.57830810546875 },
      { 0.1884640008211136, 3.136399030685425, 0.43850600719451904 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      magikarp_hd_part11_draw,
      { 104.39999389648438, -1.600000023841858, -2.4000000848900527e-05 },
      { 0.040240999311208725, -0.12219599634408951, -0.6910200119018555 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      magikarp_hd_part12_draw,
      { 101.99998474121094, -0.3998990058898926, 0.0 },
      { 0.010995999909937382, 0.058708999305963516, 0.31474798917770386 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      magikarp_hd_part13_draw,
      { 113.34295654296875, -69.09555053710938, -42.32093048095703 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      magikarp_hd_part14_draw,
      { -110.13226318359375, -69.09552001953125, -42.32099151611328 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      magikarp_hd_part15_draw,
      { -0.7682120203971863, -2.103537082672119, 108.6902847290039 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
