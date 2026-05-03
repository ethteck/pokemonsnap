#include "common.h"

extern u8 electabuzz_tex_80167B58[];
extern u8 electabuzz_tex_80168360[];
extern u8 electabuzz_tex_80168B68[];
extern u8 electabuzz_tex_80169370[];
extern u8 electabuzz_tex_80169B78[];
extern u8 electabuzz_tex_8016A380[];
extern u8 electabuzz_tex_8016A3A8[];
extern u8 electabuzz_tex_8016A7B0[];
extern u8 electabuzz_tex_8016A7C0[];
extern u8 electabuzz_tex_8016A7E8[];
extern u8 electabuzz_tex_8016A810[];
extern u8 electabuzz_tex_8016B018[];
extern u8 electabuzz_tex_8016B040[];
extern u8 electabuzz_tex_8016B848[];
extern u8 electabuzz_tex_8016B870[];
extern u8 electabuzz_tex_8016BC78[];
extern u8 electabuzz_tex_8016BCA0[];
extern u8 electabuzz_tex_8016C4D0[];
extern u8 electabuzz_tex_8016CD00[];
extern u8 electabuzz_tex_8016D508[];
extern u8 electabuzz_tex_8016D530[];
extern u8 electabuzz_tex_8016DD38[];
extern u8 electabuzz_tex_8016DD48[];
extern u8 electabuzz_tex_8016DD70[];
extern u8 electabuzz_tex_8016DD98[];
extern u8 electabuzz_tex_8016DEA0[];
extern u8 electabuzz_tex_8016DEC8[];
extern u8 electabuzz_tex_8016DFD0[];
extern u8 electabuzz_tex_8016DFF8[];
extern u8 electabuzz_tex_8016E100[];
extern u8 electabuzz_tex_8016E128[];
extern u8 electabuzz_tex_8016E230[];
extern u8 electabuzz_tex_8016E240[];
extern u8 electabuzz_tex_8016E298[];
extern u8 electabuzz_tex_8016E2C0[];

extern Texture* electabuzz_part5_mat[];
extern Texture* electabuzz_part8_mat[];
extern Texture* electabuzz_part9_mat[];
extern Gfx electabuzz_part0_draw[];

extern u8 D_80330938_62DA08[];
extern u8 D_80330948_62DA18[];
extern u8 D_803309A0_62DA70[];
extern u8 D_803309C8_62DA98[];
extern u8 D_80330A10_62DAE0[];
extern u8 D_80330A38_62DB08[];
extern u8 D_80330E40_62DF10[];
extern u8 D_80330E68_62DF38[];

__ALIGNER
u8 electabuzz_tex_80330938[] = {
#include "assets/tunnel/electabuzz/tex_80330948.pal.bin.c"
};

__ALIGNER
u8 electabuzz_tex_80330948_png[] = {
#include "assets/tunnel/electabuzz/tex_80330948.png.bin.c"
};

__ALIGNER
u8 electabuzz_tex_803309A0[] = {
#include "assets/tunnel/electabuzz/tex_803309C8.pal.bin.c"
};

__ALIGNER
u8 electabuzz_tex_803309C8_png[] = {
#include "assets/tunnel/electabuzz/tex_803309C8.png.bin.c"
};

__ALIGNER
u8 electabuzz_tex_80330A10[] = {
#include "assets/tunnel/electabuzz/tex_80330A38.pal.bin.c"
};

__ALIGNER
u8 electabuzz_tex_80330A38_png[] = {
#include "assets/tunnel/electabuzz/tex_80330A38.png.bin.c"
};

__ALIGNER
u8 electabuzz_tex_80330E40[] = {
#include "assets/tunnel/electabuzz/tex_80330E68.pal.bin.c"
};

__ALIGNER
u8 electabuzz_tex_80330E68_png[] = {
#include "assets/tunnel/electabuzz/tex_80330E68.png.bin.c"
};

Texture** electabuzz_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    electabuzz_part5_mat,
    NULL,
    NULL,
    electabuzz_part8_mat,
    electabuzz_part9_mat,
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

u8* electabuzz_part5_mat0_textures[] = {
    electabuzz_tex_80167B58,
    electabuzz_tex_80168360,
    electabuzz_tex_80168B68,
    electabuzz_tex_80169370,
    electabuzz_tex_80169B78,
    electabuzz_tex_80167B58,
    electabuzz_tex_80167B58,
};

u8* electabuzz_part5_mat1_textures[] = {
    electabuzz_tex_80167B58,
    electabuzz_tex_80168360,
    electabuzz_tex_80168B68,
    electabuzz_tex_80169370,
    electabuzz_tex_80169B78,
    electabuzz_tex_80167B58,
    electabuzz_tex_80167B58,
};

u8* electabuzz_part5_mat2_textures[] = {
    electabuzz_tex_80167B58,
    electabuzz_tex_80168360,
    electabuzz_tex_80168B68,
    electabuzz_tex_80169370,
    electabuzz_tex_80169B78,
    electabuzz_tex_80167B58,
    electabuzz_tex_80167B58,
};

u8* electabuzz_part5_mat3_textures[] = {
    electabuzz_tex_80167B58,
    electabuzz_tex_80168360,
    electabuzz_tex_80168B68,
    electabuzz_tex_80169370,
    electabuzz_tex_80169B78,
    electabuzz_tex_80167B58,
    electabuzz_tex_80167B58,
};

u8* electabuzz_part8_mat0_textures[] = {
    electabuzz_tex_80167B58,
    electabuzz_tex_80168360,
    electabuzz_tex_80168B68,
    electabuzz_tex_80169370,
    electabuzz_tex_80169B78,
    electabuzz_tex_80167B58,
    electabuzz_tex_80167B58,
};

u8* electabuzz_part8_mat1_textures[] = {
    electabuzz_tex_80167B58,
    electabuzz_tex_80168360,
    electabuzz_tex_80168B68,
    electabuzz_tex_80169370,
    electabuzz_tex_80169B78,
    electabuzz_tex_80167B58,
    electabuzz_tex_80167B58,
};

u8* electabuzz_part8_mat2_textures[] = {
    electabuzz_tex_80167B58,
    electabuzz_tex_80168360,
    electabuzz_tex_80168B68,
    electabuzz_tex_80169370,
    electabuzz_tex_80169B78,
    electabuzz_tex_80167B58,
    electabuzz_tex_80167B58,
};

u8* electabuzz_part8_mat3_textures[] = {
    electabuzz_tex_80167B58,
    electabuzz_tex_80168360,
    electabuzz_tex_80168B68,
    electabuzz_tex_80169370,
    electabuzz_tex_80169B78,
    electabuzz_tex_80167B58,
    electabuzz_tex_80167B58,
};

u8* electabuzz_part9_mat0_textures[] = {
    electabuzz_tex_8016D530,
    electabuzz_tex_8016C4D0,
    electabuzz_tex_8016CD00,
    NULL,
};

Texture electabuzz_part5_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    electabuzz_part5_mat0_textures,
    128,
    64,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 250, 144, 255 },
    0,
    0,
    0,
    0,
    { 0, 27, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture electabuzz_part5_mat1 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    electabuzz_part5_mat1_textures,
    128,
    64,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 250, 144, 255 },
    0,
    0,
    0,
    0,
    { 0, 27, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture electabuzz_part5_mat2 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    electabuzz_part5_mat2_textures,
    128,
    64,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 250, 144, 255 },
    0,
    0,
    0,
    0,
    { 0, 27, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture electabuzz_part5_mat3 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    electabuzz_part5_mat3_textures,
    128,
    64,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 250, 144, 255 },
    0,
    0,
    0,
    0,
    { 0, 27, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture electabuzz_part8_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    electabuzz_part8_mat0_textures,
    128,
    64,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 250, 144, 255 },
    0,
    0,
    0,
    0,
    { 0, 27, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture electabuzz_part8_mat1 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    electabuzz_part8_mat1_textures,
    128,
    64,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 250, 144, 255 },
    0,
    0,
    0,
    0,
    { 0, 27, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture electabuzz_part8_mat2 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    electabuzz_part8_mat2_textures,
    128,
    64,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 250, 144, 255 },
    0,
    0,
    0,
    0,
    { 0, 27, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture electabuzz_part8_mat3 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    electabuzz_part8_mat3_textures,
    128,
    64,
    128,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    128,
    32,
    128,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 250, 144, 255 },
    0,
    0,
    0,
    0,
    { 0, 27, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture electabuzz_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    electabuzz_part9_mat0_textures,
    128,
    64,
    64,
    64,
    0,
    0.004999999888241291,
    0.0,
    0.9900000095367432,
    1.0,
    0.004999999888241291,
    0.9900000095367432,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64,
    64,
    64,
    64,
    0.004999999888241291,
    0.0,
    0.004999999888241291,
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

Texture* electabuzz_part5_mat[] = {
    &electabuzz_part5_mat0,
    &electabuzz_part5_mat1,
    &electabuzz_part5_mat2,
    &electabuzz_part5_mat3,
    NULL,
};

Texture* electabuzz_part8_mat[] = {
    &electabuzz_part8_mat0,
    &electabuzz_part8_mat1,
    &electabuzz_part8_mat2,
    &electabuzz_part8_mat3,
    NULL,
};

Texture* electabuzz_part9_mat[] = {
    &electabuzz_part9_mat0,
    NULL,
};

#include "assets/tunnel/electabuzz/model.vtx.inc.c"
#include "assets/tunnel/electabuzz/first.gfx.inc.c"
#include "assets/tunnel/electabuzz/part0_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part0_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part0_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part1_pre_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part1_pre.gfx.inc.c"
#include "assets/tunnel/electabuzz/part1_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part1_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part1_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part2_pre_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part2_pre.gfx.inc.c"
#include "assets/tunnel/electabuzz/part2_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part2_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part2_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part3_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part3_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part3_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part5_pre_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part5_pre.gfx.inc.c"
#include "assets/tunnel/electabuzz/part5_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part5_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part5_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part6_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part6_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part6_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part8_pre_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part8_pre.gfx.inc.c"
#include "assets/tunnel/electabuzz/part8_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part8_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part8_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part9_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part9_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part9_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part10_pre_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part10_pre.gfx.inc.c"
#include "assets/tunnel/electabuzz/part10_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part10_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part10_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part11_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part11_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part11_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part12_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part12_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part12_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part13_pre_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part13_pre.gfx.inc.c"
#include "assets/tunnel/electabuzz/part13_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part13_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part13_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part14_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part14_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part14_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part15_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part15_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part15_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part16_pre_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part16_pre.gfx.inc.c"
#include "assets/tunnel/electabuzz/part16_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part16_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part16_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part17_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part17_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part17_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part18_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part18_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part18_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/last.gfx.inc.c"
#include "assets/tunnel/electabuzz/part4_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part4_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part4_draw.gfx.inc.c"
#include "assets/tunnel/electabuzz/part7_draw_near.gfx.inc.c"
#include "assets/tunnel/electabuzz/part7_draw_far.gfx.inc.c"
#include "assets/tunnel/electabuzz/part7_draw.gfx.inc.c"

DObjPayloadTypeJ electabuzz_gfxdata[] = {
    { 0, NULL, electabuzz_first },
    { 4, NULL, NULL },
    { 0, electabuzz_part1_pre, electabuzz_part1_draw },
    { 4, NULL, NULL },
    { 0, electabuzz_part2_pre, electabuzz_part2_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_part3_draw },
    { 4, NULL, NULL },
    { 1, NULL, electabuzz_part4_draw },
    { 4, NULL, NULL },
    { 0, electabuzz_part5_pre, electabuzz_part5_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_part6_draw },
    { 4, NULL, NULL },
    { 1, NULL, electabuzz_part7_draw },
    { 4, NULL, NULL },
    { 0, electabuzz_part8_pre, electabuzz_part8_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_part9_draw },
    { 4, NULL, NULL },
    { 0, electabuzz_part10_pre, electabuzz_part10_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_part11_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_part12_draw },
    { 4, NULL, NULL },
    { 0, electabuzz_part13_pre, electabuzz_part13_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_part14_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_part15_draw },
    { 4, NULL, NULL },
    { 0, electabuzz_part16_pre, electabuzz_part16_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_part17_draw },
    { 4, NULL, NULL },
    { 0, NULL, electabuzz_last },
    { 4, NULL, NULL },
};

UnkEC64Arg3 electabuzz_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &electabuzz_gfxdata[0],
      { 0.0, 272.5633239746094, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &electabuzz_gfxdata[2],
      { 0.0, 217.73757934570312, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.9999979734420776, 0.9999979734420776, 0.9999989867210388 } },
    { 3,
      &electabuzz_gfxdata[4],
      { 169.7408905029297, 226.6346435546875, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &electabuzz_gfxdata[6],
      { 314.93170166015625, -11.573171615600586, -0.00019099999917671084 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8197,
      &electabuzz_gfxdata[8],
      { -692.6661376953125, 357.8220520019531, 974.1244506835938 },
      { 0.007588000036776066, 0.006471000146120787, -1.9090160131454468 },
      { 2.0, 2.0, 2.0 } },
    { 3,
      &electabuzz_gfxdata[10],
      { -169.7408905029297, 226.6346435546875, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &electabuzz_gfxdata[12],
      { -314.931640625, -11.573171615600586, -9.500000305706635e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8197,
      &electabuzz_gfxdata[14],
      { 650.6747436523438, 421.12158203125, 859.5652465820312 },
      { 0.007588000036776066, 0.006471000146120787, 1.8930449485778809 },
      { 2.0, 2.0, 2.0 } },
    { 3,
      &electabuzz_gfxdata[16],
      { 0.0, 251.1399688720703, 66.14999389648438 },
      { -0.13524800539016724, 0.11802899837493896, 0.007290000095963478 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &electabuzz_gfxdata[18],
      { 3.000000106112566e-06, 86.51981353759766, 102.37722778320312 },
      { 9.999999974752427e-07, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &electabuzz_gfxdata[20],
      { 0.0, 80.66092681884766, -170.72982788085938 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &electabuzz_gfxdata[22],
      { 0.0, 0.0, -256.0945739746094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &electabuzz_gfxdata[24],
      { -4.364186763763428, 5.544447898864746, -281.6252136230469 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &electabuzz_gfxdata[26],
      { 148.01187133789062, 31.85764503479004, -0.569724977016449 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 0.9999989867210388, 1.0000009536743164 } },
    { 3,
      &electabuzz_gfxdata[28],
      { -3.5930159091949463, -123.60364532470703, 19.911945343017578 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &electabuzz_gfxdata[30],
      { -15.565925598144531, -92.7495346069336, -38.37335205078125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 2,
      &electabuzz_gfxdata[32],
      { -144.93988037109375, 18.305992126464844, 8.09382152557373 },
      { 0.0, 0.0, 0.0 },
      { 0.9999989867210388, 1.0, 1.0000029802322388 } },
    { 3,
      &electabuzz_gfxdata[34],
      { 0.0, -122.37725067138672, 1.8251420259475708 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &electabuzz_gfxdata[36],
      { 5.539178848266602, -83.44506072998047, -34.08803939819336 },
      { 0.0, 0.0, 0.0 },
      { 0.9999970197677612, 0.9999960064888, 0.9999979734420776 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
