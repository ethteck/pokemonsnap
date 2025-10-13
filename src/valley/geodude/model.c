#include "common.h"

extern u8 geodude_tex_8013F668[];
extern u8 geodude_tex_8013F690[];
extern u8 geodude_tex_8013FAC0[];
extern u8 geodude_tex_8013FEC8[];
extern u8 geodude_tex_8013FEF0_png[];
extern u8 geodude_tex_801402F8[];
extern u8 geodude_tex_80140318_png[];

extern Texture* geodude_part2_mat[];
extern Gfx geodude_part0_draw[];

Texture** geodude_materials[] = {
    NULL,
    NULL,
    geodude_part2_mat,
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

u8* geodude_part2_mat0_textures[] = {
    geodude_tex_8013F690,
    geodude_tex_8013FAC0,
};

Texture geodude_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    geodude_part2_mat0_textures,
    128,
    64,
    32,
    32,
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
    32,
    32,
    32,
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
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* geodude_part2_mat[] = {
    &geodude_part2_mat0,
    NULL,
};

#include "assets/valley/geodude/model.vtx.inc.c"
#include "assets/valley/geodude/first.gfx.inc.c"
#include "assets/valley/geodude/part0_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part0_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part0_draw.gfx.inc.c"
#include "assets/valley/geodude/part1_pre_near.gfx.inc.c"
#include "assets/valley/geodude/part1_pre_far.gfx.inc.c"
#include "assets/valley/geodude/part1_pre.gfx.inc.c"
#include "assets/valley/geodude/part1_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part1_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part1_draw.gfx.inc.c"
#include "assets/valley/geodude/part2_pre_near.gfx.inc.c"
#include "assets/valley/geodude/part2_pre_far.gfx.inc.c"
#include "assets/valley/geodude/part2_pre.gfx.inc.c"
#include "assets/valley/geodude/part2_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part2_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part2_draw.gfx.inc.c"
#include "assets/valley/geodude/part3_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part3_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part3_draw.gfx.inc.c"
#include "assets/valley/geodude/part4_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part4_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part4_draw.gfx.inc.c"
#include "assets/valley/geodude/part5_pre_near.gfx.inc.c"
#include "assets/valley/geodude/part5_pre_far.gfx.inc.c"
#include "assets/valley/geodude/part5_pre.gfx.inc.c"
#include "assets/valley/geodude/part5_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part5_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part5_draw.gfx.inc.c"
#include "assets/valley/geodude/part6_pre_near.gfx.inc.c"
#include "assets/valley/geodude/part6_pre_far.gfx.inc.c"
#include "assets/valley/geodude/part6_pre.gfx.inc.c"
#include "assets/valley/geodude/part6_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part6_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part6_draw.gfx.inc.c"
#include "assets/valley/geodude/part7_pre_near.gfx.inc.c"
#include "assets/valley/geodude/part7_pre_far.gfx.inc.c"
#include "assets/valley/geodude/part7_pre.gfx.inc.c"
#include "assets/valley/geodude/part7_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part7_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part7_draw.gfx.inc.c"
#include "assets/valley/geodude/part8_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part8_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part8_draw.gfx.inc.c"
#include "assets/valley/geodude/part9_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part9_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part9_draw.gfx.inc.c"
#include "assets/valley/geodude/part10_pre_near.gfx.inc.c"
#include "assets/valley/geodude/part10_pre_far.gfx.inc.c"
#include "assets/valley/geodude/part10_pre.gfx.inc.c"
#include "assets/valley/geodude/part10_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part10_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part10_draw.gfx.inc.c"
#include "assets/valley/geodude/part11_pre_near.gfx.inc.c"
#include "assets/valley/geodude/part11_pre_far.gfx.inc.c"
#include "assets/valley/geodude/part11_pre.gfx.inc.c"
#include "assets/valley/geodude/part11_draw_near.gfx.inc.c"
#include "assets/valley/geodude/part11_draw_far.gfx.inc.c"
#include "assets/valley/geodude/part11_draw.gfx.inc.c"
#include "assets/valley/geodude/last.gfx.inc.c"

DObjPayloadTypeI geodude_gfxdata[] = {
    { NULL, geodude_first },
    { geodude_part1_pre, geodude_part1_draw },
    { geodude_part2_pre, geodude_part2_draw },
    { NULL, geodude_part3_draw },
    { NULL, geodude_part4_draw },
    { geodude_part5_pre, geodude_part5_draw },
    { geodude_part6_pre, geodude_part6_draw },
    { geodude_part7_pre, geodude_part7_draw },
    { NULL, geodude_part8_draw },
    { NULL, geodude_part9_draw },
    { geodude_part10_pre, geodude_part10_draw },
    { geodude_part11_pre, geodude_last },
};

UnkEC64Arg3 geodude_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &geodude_gfxdata[0],
      { 0.0, 190.0, 0.0 },
      { 0.14000000059604645, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &geodude_gfxdata[1],
      { 9.999999974752427e-07, -57.21607208251953, -3.387784957885742 },
      { 0.03490699827671051, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &geodude_gfxdata[2],
      { 175.99851989746094, -23.46843719482422, -6.000000212225132e-06 },
      { -0.07286299765110016, 6.522540092468262, -0.2987689971923828 },
      { 1.0, 1.000257968902588, 1.0001929998397827 } },
    { 3,
      &geodude_gfxdata[3],
      { 234.1205596923828, 7.231616973876953, 43.46070098876953 },
      { 0.2370709925889969, -0.6468089818954468, -0.3787800073623657 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &geodude_gfxdata[4],
      { 20.898807525634766, 256.4004821777344, 4.719638824462891 },
      { 1.4005869626998901, 3.3536479473114014, 0.014456000179052353 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &geodude_gfxdata[5],
      { -2.490156888961792, -21.173858642578125, -187.84823608398438 },
      { 0.10473799705505371, 0.1605670005083084, 0.09707599878311157 },
      { 0.9999459981918335, 1.0000640153884888, 0.9999909996986389 } },
    { 5,
      &geodude_gfxdata[6],
      { 111.67669677734375, -46.66118621826172, -89.25337982177734 },
      { -2.3376410007476807, 0.8832569718360901, 1.6339950561523438 },
      { 0.9999989867210388, 0.9999989867210388, 0.9999989867210388 } },
    { 2,
      &geodude_gfxdata[7],
      { -175.99851989746094, -23.468589782714844, 2.4000000848900527e-05 },
      { 0.07286299765110016, 2.902237892150879, 0.298770010471344 },
      { 1.0, 1.0002590417861938, 1.0001939535140991 } },
    { 3,
      &geodude_gfxdata[8],
      { 234.12156677246094, 7.233715057373047, -43.46160125732422 },
      { -0.2370709925889969, -5.636375904083252, -0.3787800073623657 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &geodude_gfxdata[9],
      { 20.898866653442383, 256.400390625, -4.7196269035339355 },
      { -1.4025870561599731, 2.929537057876587, 0.014456000179052353 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &geodude_gfxdata[10],
      { -2.4851200580596924, -21.171092987060547, 187.85076904296875 },
      { -0.10471999645233154, -0.16053999960422516, 0.09716200083494186 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &geodude_gfxdata[11],
      { 111.67666625976562, -46.66099548339844, 89.25342559814453 },
      { -0.8039519786834717, -2.258336067199707, -1.5075969696044922 },
      { 0.9999989867210388, 0.9999989867210388, 0.9999989867210388 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
