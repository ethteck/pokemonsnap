#include "common.h"
#include "sys/anim.h"

extern Texture* intro_fx_part1_mat[];
extern Texture* intro_fx_part2_mat[];
extern Texture* intro_fx_part3_mat[];
extern Gfx D_0E000000_intro[];

__ALIGNER
u8 intro_fx_tex_8034FB28_png[] = {
#include "assets/intro/fx/tex_8034FB28.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80350330_png[] = {
#include "assets/intro/fx/tex_80350330.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80350B38_png[] = {
#include "assets/intro/fx/tex_80350B38.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80351340_png[] = {
#include "assets/intro/fx/tex_80351340.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80352348_png[] = {
#include "assets/intro/fx/tex_80352348.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80353350_png[] = {
#include "assets/intro/fx/tex_80353350.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80354358_png[] = {
#include "assets/intro/fx/tex_80354358.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80355360_png[] = {
#include "assets/intro/fx/tex_80355360.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80356368_png[] = {
#include "assets/intro/fx/tex_80356368.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80357370_png[] = {
#include "assets/intro/fx/tex_80357370.png.bin.c"
};
__ALIGNER
u8 intro_fx_tex_80358378_png[] = {
#include "assets/intro/fx/tex_80358378.png.bin.c"
};

Texture** intro_fx_materials[] = {
    NULL,
    intro_fx_part1_mat,
    intro_fx_part2_mat,
    intro_fx_part3_mat,
    NULL,
};

u8* intro_fx_part1_mat0_textures[] = {
    intro_fx_tex_8034FB28_png,
    intro_fx_tex_80350330_png,
    intro_fx_tex_8034FB28_png,
    intro_fx_tex_80350B38_png,
    intro_fx_tex_80350B38_png,
};

Texture intro_fx_part1_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    intro_fx_part1_mat0_textures,
    32,
    0,
    64,
    64,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x3210,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    64,
    64,
    64,
    64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 255, 255, 0 },
    0,
    0,
    0,
    0,
    { 255, 255, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 48, 48, 48, 0 },
    0,
    0,
    0,
    0,
};

u8* intro_fx_part2_mat0_textures[] = {
    intro_fx_tex_80351340_png,
    intro_fx_tex_80352348_png,
    intro_fx_tex_80353350_png,
    intro_fx_tex_80354358_png,
    intro_fx_tex_80355360_png,
    intro_fx_tex_80356368_png,
};

Texture intro_fx_part2_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    intro_fx_part2_mat0_textures,
    32,
    0,
    64,
    64,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x32A1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 255, 255, 255, 0 },
    0,
    0,
    0,
    0,
    { 255, 228, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 48, 48, 48, 0 },
    0,
    0,
    0,
    0,
};

u8* intro_fx_part3_mat0_textures[] = {
    intro_fx_tex_80357370_png,
    intro_fx_tex_80358378_png,
};

Texture intro_fx_part3_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    intro_fx_part3_mat0_textures,
    32,
    128,
    128,
    256,
    0,
    0.0,
    -0.5,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0x32A1,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    139781,
    { 255, 255, 255, 0 },
    0,
    0,
    0,
    0,
    { 255, 255, 255, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 48, 48, 48, 0 },
    0,
    0,
    0,
    0,
};

Texture* intro_fx_part1_mat[] = {
    &intro_fx_part1_mat0,
    NULL,
};

Texture* intro_fx_part2_mat[] = {
    &intro_fx_part2_mat0,
    NULL,
};

Texture* intro_fx_part3_mat[] = {
    &intro_fx_part3_mat0,
    NULL,
};

#include "assets/intro/fx/model.vtx.inc.c"
#include "assets/intro/fx/part0_draw.gfx.inc.c"
#include "assets/intro/fx/part1_draw.gfx.inc.c"
#include "assets/intro/fx/part2_draw.gfx.inc.c"

DObjPayloadTypeC intro_fx_gfxdata[] = {
    { 1, intro_fx_part0_draw },
    { 4, NULL },
    { 1, intro_fx_part1_draw },
    { 4, NULL },
    { 1, intro_fx_part2_draw },
    { 4, NULL },
};

UnkEC64Arg3 intro_fx_model[] = {
    { 0,
      NULL,
      { -323.335205078125, 2976.75, 236.70001220703125 },
      { 0.0, 0.0, 0.0 },
      { 0.07000000029802322, 0.07000000029802322, 0.07000000029802322 } },
    { 32769,
      &intro_fx_gfxdata[0],
      { 9.999999974752427e-07, -9.999999974752427e-07, 9.999999974752427e-07 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32769,
      &intro_fx_gfxdata[2],
      { 9.999999974752427e-07, -1.9999999949504854e-06, -9.999999974752427e-07 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 32769,
      &intro_fx_gfxdata[4],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 0.0, 20.489852905273438 },
      { 0.0, 0.0, 0.0 },
      { 14.285714149475098, 14.285714149475098, 14.285714149475098 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

static u8 pad_0[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

#include "assets/intro/fx/intro_fx_modelanim.modelanim.inc.c"

static u8 pad_1[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
#include "assets/intro/fx/intro_fx_matanim.matanim.inc.c"
