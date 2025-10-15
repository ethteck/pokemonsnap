#include "common.h"

extern u8 jigglypuff_tex_80187828[];
extern u8 jigglypuff_tex_80187850[];
extern u8 jigglypuff_tex_80187A38[];
extern u8 jigglypuff_tex_80187C20[];
extern u8 jigglypuff_tex_80187E08[];
extern u8 jigglypuff_tex_80187FF0[];
extern u8 jigglypuff_tex_801881D8[];
extern u8 jigglypuff_tex_80188200_png[];
extern u8 jigglypuff_tex_80188408[];
extern u8 jigglypuff_tex_80188610[];
extern u8 jigglypuff_tex_80188858[];
extern u8 jigglypuff_tex_80188AA0[];
extern u8 jigglypuff_tex_80188CE8[];
extern u8 jigglypuff_tex_80188F30[];
extern u8 jigglypuff_tex_80189178[];
extern u8 jigglypuff_tex_801893C0[];
extern u8 jigglypuff_tex_80189608[];
extern u8 jigglypuff_tex_80189850[];
extern u8 jigglypuff_tex_80189A98[];
extern u8 jigglypuff_tex_80189AC0_png[];
extern u8 jigglypuff_tex_80189B18[];
extern u8 jigglypuff_tex_80189B40_png[];

extern Texture* jigglypuff_hd_part1_mat[];
extern Gfx jigglypuff_hd_part0_draw[];

Texture** jigglypuff_hd_materials[] = {
    NULL,
    jigglypuff_hd_part1_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* jigglypuff_hd_part1_mat0_textures[] = {
    jigglypuff_tex_80188610,
    jigglypuff_tex_80188858,
    jigglypuff_tex_80188AA0,
    jigglypuff_tex_80188CE8,
    jigglypuff_tex_80188F30,
    jigglypuff_tex_80189850,
};

u8* jigglypuff_hd_part1_mat1_textures[] = {
    jigglypuff_tex_80188610,
    jigglypuff_tex_80188858,
    jigglypuff_tex_80188AA0,
    jigglypuff_tex_80189178,
    jigglypuff_tex_801893C0,
    jigglypuff_tex_80189608,
};

u8* jigglypuff_hd_part1_mat2_textures[] = {
    jigglypuff_tex_80187850,
    jigglypuff_tex_80187A38,
    jigglypuff_tex_80187C20,
    jigglypuff_tex_80187E08,
    jigglypuff_tex_80187FF0,
};

Texture jigglypuff_hd_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    jigglypuff_hd_part1_mat0_textures,
    32,
    0,
    24,
    24,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_8b,
    24,
    24,
    24,
    24,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture jigglypuff_hd_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    jigglypuff_hd_part1_mat1_textures,
    32,
    0,
    24,
    24,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_8b,
    24,
    24,
    24,
    24,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture jigglypuff_hd_part1_mat2 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    jigglypuff_hd_part1_mat2_textures,
    32,
    0,
    40,
    20,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    40,
    20,
    40,
    20,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* jigglypuff_hd_part1_mat[] = {
    &jigglypuff_hd_part1_mat0,
    &jigglypuff_hd_part1_mat1,
    &jigglypuff_hd_part1_mat2,
    NULL,
};

#include "assets/cave/jigglypuff/hd_model.vtx.inc.c"
#include "assets/cave/jigglypuff/hd_first.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part0_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part1_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part2_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part3_pre.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part3_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part4_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part5_pre.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part5_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part6_pre.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part6_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part7_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part8_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part9_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part10_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part11_draw.gfx.inc.c"
#include "assets/cave/jigglypuff/hd_part12_draw.gfx.inc.c"

DObjPayloadTypeI jigglypuff_hd_gfxdata[] = {
    { NULL, jigglypuff_hd_first },
    { NULL, jigglypuff_hd_part1_draw },
    { NULL, jigglypuff_hd_part2_draw },
    { jigglypuff_hd_part3_pre, jigglypuff_hd_part3_draw },
    { NULL, jigglypuff_hd_part4_draw },
    { jigglypuff_hd_part5_pre, jigglypuff_hd_part5_draw },
    { jigglypuff_hd_part6_pre, jigglypuff_hd_part6_draw },
    { NULL, jigglypuff_hd_part7_draw },
    { NULL, jigglypuff_hd_part8_draw },
    { NULL, jigglypuff_hd_part9_draw },
    { NULL, jigglypuff_hd_part10_draw },
    { NULL, jigglypuff_hd_part11_draw },
    { NULL, jigglypuff_hd_part12_draw },
};

UnkEC64Arg3 jigglypuff_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &jigglypuff_hd_gfxdata[0],
      { 1.2499910593032837, 164.99554443359375, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { -1.2499439716339111, -164.99598693847656, 0.0 },
      { 0.0, 0.0, -0.009999999776482582 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jigglypuff_hd_gfxdata[1],
      { 106.78678894042969, -124.67418670654297, -4.999999873689376e-06 },
      { 0.0, 0.6700090169906616, 0.0 },
      { 0.9999979734420776, 1.0, 1.0 } },
    { 2,
      &jigglypuff_hd_gfxdata[2],
      { -112.81515502929688, -123.67808532714844, -1.9999999949504854e-06 },
      { 0.0, -0.6399999856948853, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jigglypuff_hd_gfxdata[3],
      { -16.791135787963867, 296.9588623046875, 147.39981079101562 },
      { 0.12982599437236786, 0.0, 0.0 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      &jigglypuff_hd_gfxdata[4],
      { -7.8576130867004395, -25.685453414916992, 60.7706413269043 },
      { 0.10002399981021881, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jigglypuff_hd_gfxdata[5],
      { 171.34417724609375, 253.7100067138672, 39.199649810791016 },
      { 0.0, 0.0, -0.6799960136413574 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jigglypuff_hd_gfxdata[6],
      { -168.09548950195312, 251.29391479492188, 32.19989013671875 },
      { 0.0, 0.0, 0.6100119948387146 },
      { 0.9999960064888, 0.9999960064888, 1.0 } },
    { 2,
      &jigglypuff_hd_gfxdata[7],
      { 98.79964447021484, -50.49400329589844, 133.08773803710938 },
      { 0.5604659914970398, 0.6019089818000793, 0.04590599983930588 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 3,
      &jigglypuff_hd_gfxdata[8],
      { -14.692532539367676, 18.842864990234375, 79.08174133300781 },
      { 0.0037430000957101583, -0.07649300247430801, -0.0015899999998509884 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &jigglypuff_hd_gfxdata[9],
      { -100.69377136230469, -55.27174377441406, 141.3092041015625 },
      { 0.4086860120296478, -0.3505780100822449, 0.11504500359296799 },
      { 0.9999960064888, 0.9999960064888, 0.9999989867210388 } },
    { 3,
      &jigglypuff_hd_gfxdata[10],
      { -7.306046009063721, 17.29495620727539, 61.17265319824219 },
      { 0.005568999797105789, -0.22057899832725525, -0.02281400002539158 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &jigglypuff_hd_gfxdata[11],
      { -34.47343063354492, -36.19573211669922, 81.00660705566406 },
      { -0.3885439932346344, 0.02433199994266033, -0.8998590111732483 },
      { 1.0000040531158447, 1.0000040531158447, 1.0000009536743164 } },
    { 32773,
      &jigglypuff_hd_gfxdata[12],
      { 9.000000318337698e-06, 211.1033477783203, -7.200000254670158e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
