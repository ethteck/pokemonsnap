#include "common.h"

extern u8 squirtle_tex_8017BA58[];
extern u8 squirtle_tex_8017BC60_png[];
extern u8 squirtle_tex_8017C068[];
extern u8 squirtle_tex_8017C090_png[];
extern u8 squirtle_tex_8017C298[];
extern u8 squirtle_tex_8017C4A0_png[];
extern u8 squirtle_tex_8017C8D0[];
extern u8 squirtle_tex_8017CB00[];
extern u8 squirtle_tex_8017CD30[];
extern u8 squirtle_tex_8017CF60[];
extern u8 squirtle_tex_8017D168[];
extern u8 squirtle_tex_8017D190[];
extern u8 squirtle_tex_8017D3C0[];
extern u8 squirtle_tex_8017D5F0[];
extern u8 squirtle_tex_8017D820[];
extern u8 squirtle_tex_8017DA50[];
extern u8 squirtle_tex_8017DC58[];
extern u8 squirtle_tex_8017DC80[];
extern u8 squirtle_tex_8017DE88[];
extern u8 squirtle_tex_8017E090_png[];
extern u8 squirtle_tex_8017E498[];
extern u8 squirtle_tex_8017E4C0_png[];

extern Texture* squirtle_hd_part2_mat[];
extern Gfx squirtle_hd_part0_draw[];

Texture** squirtle_hd_materials[] = {
    NULL,
    NULL,
    squirtle_hd_part2_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* squirtle_hd_part2_mat0_textures[] = {
    squirtle_tex_8017DC80,
    squirtle_tex_8017D3C0,
    squirtle_tex_8017D5F0,
    squirtle_tex_8017D820,
    squirtle_tex_8017DA50,
};

u8* squirtle_hd_part2_mat1_textures[] = {
    squirtle_tex_8017D190,
    squirtle_tex_8017C8D0,
    squirtle_tex_8017CB00,
    squirtle_tex_8017CD30,
    squirtle_tex_8017CF60,
};

Texture squirtle_hd_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    squirtle_hd_part2_mat0_textures,
    128,
    64,
    64,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    64,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    205317,
    { 255, 255, 254, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 255, 254, 0 },
    { 51, 51, 51, 0 },
    0,
    0,
    0,
    0,
};

Texture squirtle_hd_part2_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    squirtle_hd_part2_mat1_textures,
    128,
    64,
    64,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    32,
    32,
    64,
    32,
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
    { 51, 51, 51, 0 },
    0,
    0,
    0,
    0,
};

Texture* squirtle_hd_part2_mat[] = {
    &squirtle_hd_part2_mat0,
    &squirtle_hd_part2_mat1,
    NULL,
    NULL,
};
#include "assets/valley/squirtle/hd_model.vtx.inc.c"
#include "assets/valley/squirtle/hd_first.gfx.inc.c"
#include "assets/valley/squirtle/hd_part0_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part1_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part2_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part3_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part4_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part5_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part6_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part7_draw.gfx.inc.c"
#include "assets/valley/squirtle/hd_part8_draw.gfx.inc.c"

UnkEC64Arg3 squirtle_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      squirtle_hd_first,
      { 0.0, 200.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part1_draw,
      { 0.0, 151.88722229003906, 35.6209602355957 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part2_draw,
      { -91.47610473632812, 78.3467788696289, 48.934173583984375 },
      { 0.0, 0.785398006439209, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part3_draw,
      { 91.47610473632812, 78.3467788696289, 48.934173583984375 },
      { 0.0, -0.785398006439209, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part4_draw,
      { -90.0, -87.57794952392578, 21.33312225341797 },
      { -0.3441169857978821, -0.16390900313854218, -0.06023399904370308 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      squirtle_hd_part5_draw,
      { 0.0, -30.000001907348633, 0.0 },
      { 0.34906598925590515, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part6_draw,
      { 90.0, -87.57794952392578, 21.33312225341797 },
      { -0.3441169857978821, 0.16390900313854218, 0.06023399904370308 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      squirtle_hd_part7_draw,
      { 0.0, -30.000001907348633, 0.0 },
      { 0.34906598925590515, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      squirtle_hd_part8_draw,
      { 0.0, -171.3300018310547, -19.739999771118164 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
