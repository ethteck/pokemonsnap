#include "common.h"

extern u8 vileplume_tex_8017BEB8[];
extern u8 vileplume_tex_8017BEE0[];
extern u8 vileplume_tex_8017C110[];
extern u8 vileplume_tex_8017C318[];
extern u8 vileplume_tex_8017C340_png[];
extern u8 vileplume_tex_8017C548[];
extern u8 vileplume_tex_8017C570_png[];
extern u8 vileplume_tex_8017C778[];
extern u8 vileplume_tex_8017C7A0_png[];
extern u8 vileplume_tex_8017C9A8[];
extern u8 vileplume_tex_8017C9D0_png[];
extern u8 vileplume_tex_8017CBD8[];
extern u8 vileplume_tex_8017CBF8_png[];
extern u8 vileplume_tex_8017CE00[];
extern u8 vileplume_tex_8017CE28[];
extern u8 vileplume_tex_8017D058[];
extern u8 vileplume_tex_8017D288[];
extern u8 vileplume_tex_8017D4B8[];
extern u8 vileplume_tex_8017D6C0[];
extern u8 vileplume_tex_8017D6E8_png[];
extern u8 vileplume_tex_8017D8F0[];

extern Texture* vileplume_hd_part1_mat[];
extern Texture* vileplume_hd_part19_mat[];
extern Gfx vileplume_hd_part0_draw[];

Texture** vileplume_hd_materials[] = {
    NULL,
    vileplume_hd_part1_mat,
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
    NULL,
    NULL,
    NULL,
    NULL,
    vileplume_hd_part19_mat,
};

u8* vileplume_hd_part1_mat0_textures[] = {
    vileplume_tex_8017BEE0,
    vileplume_tex_8017C110,
};

u8* vileplume_hd_part1_mat1_textures[] = {
    vileplume_tex_8017CE28,
    vileplume_tex_8017D058,
    vileplume_tex_8017D288,
    vileplume_tex_8017D4B8,
};

Texture vileplume_hd_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    vileplume_hd_part1_mat0_textures,
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
    G_IM_SIZ_4b,
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

Texture vileplume_hd_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    vileplume_hd_part1_mat1_textures,
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
    G_IM_SIZ_4b,
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

Texture vileplume_hd_part19_mat0 = {
    0,
    G_IM_FMT_I,
    G_IM_SIZ_16b,
    NULL,
    128,
    128,
    32,
    128,
    0,
    0.0,
    0.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0x20,
    G_IM_FMT_I,
    G_IM_SIZ_4b,
    32,
    64,
    32,
    128,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    { 255, 255, 255, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 179, 179, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* vileplume_hd_part1_mat[] = {
    &vileplume_hd_part1_mat0,
    &vileplume_hd_part1_mat1,
    NULL,
};

Texture* vileplume_hd_part19_mat[] = {
    &vileplume_hd_part19_mat0,
    NULL,
    NULL,
};
#include "assets/river/vileplume/hd_model.vtx.inc.c"
#include "assets/river/vileplume/hd_first.gfx.inc.c"
#include "assets/river/vileplume/hd_part0_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part1_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part2_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part3_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part4_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part5_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part6_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part7_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part8_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part9_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part10_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part11_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part12_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part13_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part14_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part15_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part16_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part17_draw.gfx.inc.c"
#include "assets/river/vileplume/hd_part18_draw.gfx.inc.c"

DObjPayloadTypeC vileplume_hd_gfxdata[] = {
    { 0, vileplume_hd_first },
    { 4, NULL },
    { 0, vileplume_hd_part1_draw },
    { 4, NULL },
    { 0, vileplume_hd_part2_draw },
    { 4, NULL },
    { 0, vileplume_hd_part3_draw },
    { 4, NULL },
    { 0, vileplume_hd_part4_draw },
    { 4, NULL },
    { 0, vileplume_hd_part5_draw },
    { 4, NULL },
    { 0, vileplume_hd_part6_draw },
    { 4, NULL },
    { 0, vileplume_hd_part7_draw },
    { 4, NULL },
    { 0, vileplume_hd_part8_draw },
    { 4, NULL },
    { 0, vileplume_hd_part9_draw },
    { 4, NULL },
    { 0, vileplume_hd_part10_draw },
    { 4, NULL },
    { 0, vileplume_hd_part11_draw },
    { 4, NULL },
    { 0, vileplume_hd_part12_draw },
    { 4, NULL },
    { 0, vileplume_hd_part13_draw },
    { 4, NULL },
    { 0, vileplume_hd_part14_draw },
    { 4, NULL },
    { 0, vileplume_hd_part15_draw },
    { 4, NULL },
    { 0, vileplume_hd_part16_draw },
    { 4, NULL },
    { 0, vileplume_hd_part17_draw },
    { 4, NULL },
    { 1, vileplume_hd_part18_draw },
    { 4, NULL },
};

UnkEC64Arg3 vileplume_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &vileplume_hd_gfxdata[0],
      { 9.500000305706635e-05, 539.0181884765625, 3.341381072998047 },
      { 0.13600000739097595, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[2],
      { -1.5537259578704834, 414.4345703125, 155.2632293701172 },
      { -0.031279999762773514, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_hd_gfxdata[4],
      { 0.0, 0.00019099999917671084, 411.90057373046875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[6],
      { 181.7218780517578, 410.73870849609375, 36.98258972167969 },
      { -0.15122799575328827, 1.3616780042648315, -0.14798200130462646 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_hd_gfxdata[8],
      { -36.42396926879883, 0.0, 477.70196533203125 },
      { 0.0, -0.07781600207090378, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[10],
      { 161.2194061279297, 404.1215515136719, -174.40281677246094 },
      { 0.04486300051212311, 2.3425049781799316, 0.03216499835252762 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_hd_gfxdata[12],
      { 14.864540100097656, 9.500000305706635e-05, 514.2698364257812 },
      { 0.0, -0.12370800226926804, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[14],
      { -72.71461486816406, 403.75238037109375, -186.20945739746094 },
      { 0.032607000321149826, 3.4278459548950195, -0.009209999814629555 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_hd_gfxdata[16],
      { -19.493484497070312, 9.500000305706635e-05, 501.7208251953125 },
      { 0.0, 6.283185005187988, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[18],
      { -150.20713806152344, 410.90435791015625, 42.35509490966797 },
      { -2.355736017227173, -1.526581048965454, 2.3561689853668213 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_hd_gfxdata[20],
      { 15.381267547607422, -0.027084000408649445, 491.9009094238281 },
      { 5.500000042957254e-05, -1.9999999949504854e-06, 1.9999999949504854e-06 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[22],
      { 310.8894348144531, 12.594366073608398, 2.71248197555542 },
      { -0.031279999762773514, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[24],
      { -310.88983154296875, 12.594366073608398, 2.7124760150909424 },
      { 0.031279999762773514, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[26],
      { 180.7178497314453, -179.30650329589844, -29.77674674987793 },
      { -0.21407300233840942, 0.4908030033111572, -0.0134699996560812 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_hd_gfxdata[28],
      { 12.021136283874512, -298.2330017089844, 2.0576720237731934 },
      { 0.012004000134766102, 0.007984999567270279, 0.00021600000036414713 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[30],
      { -180.71823120117188, -179.30650329589844, -29.77674674987793 },
      { 0.21407300233840942, 2.650789976119995, 0.0134699996560812 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &vileplume_hd_gfxdata[32],
      { 12.021112442016602, -298.2330017089844, -2.0576720237731934 },
      { -0.012004000134766102, -0.007984999567270279, 0.00021600000036414713 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &vileplume_hd_gfxdata[34],
      { 0.0, 383.5606994628906, -9.253751754760742 },
      { -0.03400000184774399, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8195,
      &vileplume_hd_gfxdata[36],
      { -9.500000305706635e-05, -920.21044921875, 47.77046203613281 },
      { -0.10199999809265137, 0.0, 0.0 },
      { 1.0, 1.0, 1.3253999948501587 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
