#include "common.h"

extern u8 geodude_tex_8013F668[];
extern u8 geodude_tex_8013F690[];
extern u8 geodude_tex_8013FAC0[];
extern u8 geodude_tex_8013FEC8[];
extern u8 geodude_tex_8013FEF0_png[];
extern u8 geodude_tex_801402F8[];
extern u8 geodude_tex_80140318_png[];

extern Texture* geodude_hd_part2_mat[];
extern Gfx geodude_hd_part0_draw[];

Texture** geodude_hd_materials[] = {
    NULL,
    NULL,
    geodude_hd_part2_mat,
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

u8* geodude_hd_part2_mat0_textures[] = {
    geodude_tex_8013F690,
    geodude_tex_8013FAC0,
};

Texture geodude_hd_part2_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    geodude_hd_part2_mat0_textures,
    32,
    0,
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

Texture* geodude_hd_part2_mat[] = {
    &geodude_hd_part2_mat0,
    NULL,
};
#include "assets/valley/geodude/hd_model.vtx.inc.c"
#include "assets/valley/geodude/hd_first.gfx.inc.c"
#include "assets/valley/geodude/hd_part0_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part1_pre.gfx.inc.c"
#include "assets/valley/geodude/hd_part1_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part2_pre.gfx.inc.c"
#include "assets/valley/geodude/hd_part2_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part3_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part4_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part5_pre.gfx.inc.c"
#include "assets/valley/geodude/hd_part5_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part6_pre.gfx.inc.c"
#include "assets/valley/geodude/hd_part6_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part7_pre.gfx.inc.c"
#include "assets/valley/geodude/hd_part7_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part8_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part9_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part10_pre.gfx.inc.c"
#include "assets/valley/geodude/hd_part10_draw.gfx.inc.c"
#include "assets/valley/geodude/hd_part11_pre.gfx.inc.c"
#include "assets/valley/geodude/hd_part11_draw.gfx.inc.c"

DObjPayloadTypeI geodude_hd_gfxdata[] = {
    { NULL, geodude_hd_first },
    { geodude_hd_part1_pre, geodude_hd_part1_draw },
    { geodude_hd_part2_pre, geodude_hd_part2_draw },
    { NULL, geodude_hd_part3_draw },
    { NULL, geodude_hd_part4_draw },
    { geodude_hd_part5_pre, geodude_hd_part5_draw },
    { geodude_hd_part6_pre, geodude_hd_part6_draw },
    { geodude_hd_part7_pre, geodude_hd_part7_draw },
    { NULL, geodude_hd_part8_draw },
    { NULL, geodude_hd_part9_draw },
    { geodude_hd_part10_pre, geodude_hd_part10_draw },
    { geodude_hd_part11_pre, geodude_hd_part11_draw },
};

UnkEC64Arg3 geodude_hd_model[] = {
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
      &geodude_hd_gfxdata[0],
      { 0.0, 190.0, 0.0 },
      { 0.14000000059604645, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &geodude_hd_gfxdata[1],
      { 9.999999974752427e-07, -57.21607208251953, -3.387784957885742 },
      { 0.03490699827671051, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &geodude_hd_gfxdata[2],
      { 175.99851989746094, -23.46843719482422, -6.000000212225132e-06 },
      { -0.07288199663162231, 6.522539138793945, -0.2987689971923828 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &geodude_hd_gfxdata[3],
      { 240.18028259277344, 2.284862995147705, -2.828810930252075 },
      { 0.2370709925889969, -0.6468089818954468, -0.3787800073623657 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &geodude_hd_gfxdata[4],
      { 20.89889144897461, 256.4002990722656, 4.7196149826049805 },
      { 0.6645870208740234, 3.3536479473114014, 0.014456000179052353 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &geodude_hd_gfxdata[5],
      { -2.4852099418640137, -21.171283721923828, -187.85043334960938 },
      { 0.10471999645233154, 0.16054099798202515, 0.09716299921274185 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &geodude_hd_gfxdata[6],
      { 111.67674255371094, -46.66099548339844, -89.25352478027344 },
      { -2.3376410007476807, 0.8832569718360901, 1.6339950561523438 },
      { 0.9999989867210388, 0.9999989867210388, 0.9999989867210388 } },
    { 2,
      &geodude_hd_gfxdata[7],
      { -175.99851989746094, -23.468435287475586, -6.000000212225132e-06 },
      { -3.999999989900971e-06, 2.891592025756836, 0.30000099539756775 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &geodude_hd_gfxdata[8],
      { 240.18028259277344, 2.284862995147705, 2.8288159370422363 },
      { -3.3168749809265137, 2.457637071609497, 2.8036410808563232 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &geodude_hd_gfxdata[9],
      { 20.350528717041016, 257.00006103515625, -2.9212710857391357 },
      { -0.6787260174751282, 2.926137924194336, 0.019507000222802162 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &geodude_hd_gfxdata[10],
      { -2.4851980209350586, -21.171188354492188, 187.85057067871094 },
      { -0.10471999645233154, -0.16054099798202515, 0.09716299921274185 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &geodude_hd_gfxdata[11],
      { 111.67674255371094, -46.660804748535156, 89.25357055664062 },
      { -7.0871381759643555, 4.024848937988281, -1.5075980424880981 },
      { 0.9999989867210388, 0.9999989867210388, 0.9999989867210388 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
