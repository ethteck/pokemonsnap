#include "common.h"

extern u8 articuno_tex_8016FA88[];
extern u8 articuno_tex_8016FAB0_png[];
extern u8 articuno_tex_8016FCB0[];
extern u8 articuno_tex_8016FCD8_png[];
extern u8 articuno_tex_8016FDE0[];
extern u8 articuno_tex_8016FE08[];
extern u8 articuno_tex_80170238[];
extern u8 articuno_tex_80170668[];
extern u8 articuno_tex_80170A70[];
extern u8 articuno_tex_80170A98_png[];
extern u8 articuno_tex_80170CA0[];
extern u8 articuno_tex_80170CC8_png[];
extern u8 articuno_tex_80170D50[];
extern u8 articuno_tex_80170D78_png[];
extern u8 articuno_tex_80171180[];
extern u8 articuno_tex_801711A8_png[];
extern u8 articuno_tex_801715B0[];
extern u8 articuno_tex_801715D8_png[];
extern u8 articuno_tex_801719E0[];
extern u8 articuno_tex_80171A08_png[];
extern u8 articuno_tex_80171B10[];
extern u8 articuno_tex_80171B38_png[];
extern u8 articuno_tex_80171F40[];
extern u8 articuno_tex_80171F68_png[];

__ALIGNER
u8 articuno_tex_803264B8[] = {
#include "assets/cave/articuno/tex_803264E0.pal.bin.c"
};

__ALIGNER
u8 articuno_tex_803264E0_png[] = {
#include "assets/cave/articuno/tex_803264E0.png.bin.c"
};

extern Texture* articuno_part16_mat[];
extern Gfx articuno_part0_draw[];

Texture** articuno_materials[] = {
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
    articuno_part16_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* articuno_part16_mat0_textures[] = {
    articuno_tex_8016FE08,
    articuno_tex_80170238,
    articuno_tex_80170668,
};

Texture articuno_part16_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    articuno_part16_mat0_textures,
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
    64,
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
    { 64, 64, 64, 0 },
    0,
    0,
    0,
    0,
};

Texture* articuno_part16_mat[] = {
    &articuno_part16_mat0,
    NULL,
};

#include "assets/cave/articuno/model.vtx.inc.c"
#include "assets/cave/articuno/first.gfx.inc.c"
#include "assets/cave/articuno/part0_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part0_draw.gfx.inc.c"
#include "assets/cave/articuno/part1_pre_near.gfx.inc.c"
#include "assets/cave/articuno/part1_pre.gfx.inc.c"
#include "assets/cave/articuno/part1_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part1_draw.gfx.inc.c"
#include "assets/cave/articuno/part2_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part2_draw.gfx.inc.c"
#include "assets/cave/articuno/part3_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part3_draw.gfx.inc.c"
#include "assets/cave/articuno/part4_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part4_draw.gfx.inc.c"
#include "assets/cave/articuno/part5_pre_near.gfx.inc.c"
#include "assets/cave/articuno/part5_pre.gfx.inc.c"
#include "assets/cave/articuno/part5_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part5_draw.gfx.inc.c"
#include "assets/cave/articuno/part6_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part6_draw.gfx.inc.c"
#include "assets/cave/articuno/part7_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part7_draw.gfx.inc.c"
#include "assets/cave/articuno/part8_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part8_draw.gfx.inc.c"
#include "assets/cave/articuno/part9_pre_near.gfx.inc.c"
#include "assets/cave/articuno/part9_pre.gfx.inc.c"
#include "assets/cave/articuno/part9_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part9_draw.gfx.inc.c"
#include "assets/cave/articuno/part10_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part10_draw.gfx.inc.c"
#include "assets/cave/articuno/part11_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part11_draw.gfx.inc.c"
#include "assets/cave/articuno/part12_pre_near.gfx.inc.c"
#include "assets/cave/articuno/part12_pre.gfx.inc.c"
#include "assets/cave/articuno/part12_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part12_draw.gfx.inc.c"
#include "assets/cave/articuno/part13_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part13_draw.gfx.inc.c"
#include "assets/cave/articuno/part14_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part14_draw.gfx.inc.c"
#include "assets/cave/articuno/part15_pre_near.gfx.inc.c"
#include "assets/cave/articuno/part15_pre.gfx.inc.c"
#include "assets/cave/articuno/part15_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part15_draw.gfx.inc.c"
#include "assets/cave/articuno/part16_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part16_draw.gfx.inc.c"
#include "assets/cave/articuno/part17_pre_near.gfx.inc.c"
#include "assets/cave/articuno/part17_pre.gfx.inc.c"
#include "assets/cave/articuno/part17_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part17_draw.gfx.inc.c"
#include "assets/cave/articuno/part18_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part18_draw.gfx.inc.c"
#include "assets/cave/articuno/part19_draw_near.gfx.inc.c"
#include "assets/cave/articuno/part19_draw.gfx.inc.c"
#include "assets/cave/articuno/last.gfx.inc.c"

DObjPayloadTypeI articuno_gfxdata[] = {
    { NULL, articuno_first },
    { articuno_part1_pre, articuno_part1_draw },
    { NULL, articuno_part2_draw },
    { NULL, articuno_part3_draw },
    { NULL, articuno_part4_draw },
    { articuno_part5_pre, articuno_part5_draw },
    { NULL, articuno_part6_draw },
    { NULL, articuno_part7_draw },
    { NULL, articuno_part8_draw },
    { articuno_part9_pre, articuno_part9_draw },
    { NULL, articuno_part10_draw },
    { NULL, articuno_part11_draw },
    { articuno_part12_pre, articuno_part12_draw },
    { NULL, articuno_part13_draw },
    { NULL, articuno_part14_draw },
    { articuno_part15_pre, articuno_part15_draw },
    { NULL, articuno_part16_draw },
    { articuno_part17_pre, articuno_part17_draw },
    { NULL, articuno_part18_draw },
    { NULL, articuno_last },
};

UnkEC64Arg3 articuno_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &articuno_gfxdata[0],
      { 0.0, 690.4114990234375, -108.05498504638672 },
      { 1.570796012878418, -0.7022650241851807, 1.570796012878418 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_gfxdata[1],
      { -77.94625854492188, 184.65769958496094, -157.52337646484375 },
      { 0.16439199447631836, -0.06185400113463402, -3.4662070274353027 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_gfxdata[2],
      { 243.8610382080078, 3.600000127335079e-05, -0.00022600000374950469 },
      { 0.0, 0.0, -0.7889270186424255 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &articuno_gfxdata[3],
      { 208.34902954101562, -3.000000106112566e-06, 7.200000254670158e-05 },
      { 0.0, -0.0011690000537782907, -1.1724849939346313 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &articuno_gfxdata[4],
      { 9.999999747378752e-06, 4.199999966658652e-05, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_gfxdata[5],
      { -77.94628143310547, 184.6575927734375, 157.5234832763672 },
      { -0.16439199447631836, 0.06185400113463402, -3.4662070274353027 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_gfxdata[6],
      { 243.86109924316406, 0.0, -8.299999899463728e-05 },
      { 0.0, 0.0, -0.7889279723167419 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &articuno_gfxdata[7],
      { 208.3488006591797, -5.700000110664405e-05, -7.200000254670158e-05 },
      { 0.0, -0.0011690000537782907, -1.1724849939346313 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &articuno_gfxdata[8],
      { -7.000000096013537e-06, 1.8000000636675395e-05, -1.2000000424450263e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_gfxdata[9],
      { 450.5221252441406, -135.21966552734375, -216.54522705078125 },
      { 2.196523904800415, 0.8356419801712036, 0.4600670039653778 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_gfxdata[10],
      { 412.7908630371094, 9.500000305706635e-05, 4.8000001697801054e-05 },
      { 0.33827900886535645, 0.5968170166015625, 0.920536994934082 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &articuno_gfxdata[11],
      { 717.4053955078125, -0.00019099999917671084, 0.00023799999326001853 },
      { 0.49056199193000793, 0.6146029829978943, 0.5363439917564392 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_gfxdata[12],
      { 450.5221252441406, -135.21986389160156, 216.5453643798828 },
      { -2.284632921218872, -0.6738079786300659, 0.5206480026245117 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_gfxdata[13],
      { 412.79095458984375, -9.500000305706635e-05, 0.0 },
      { -0.5195789933204651, -0.24451400339603424, 0.8698660135269165 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &articuno_gfxdata[14],
      { 717.4055786132812, 0.0, 9.500000305706635e-05 },
      { -0.5591340065002441, -0.6245099902153015, 0.22424499690532684 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_gfxdata[15],
      { 601.5830078125, 0.0001429999974789098, 1.9999999494757503e-05 },
      { -3.1415929794311523, -3.1415929794311523, -2.1451900005340576 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_gfxdata[16],
      { 149.3662109375, -80.62429809570312, 7.000000096013537e-06 },
      { 0.0, 0.0, 0.23558400571346283 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_gfxdata[17],
      { -394.0039978027344, -240.18020629882812, 3.999999989900971e-06 },
      { 0.0, -0.08726699650287628, -2.355112075805664 },
      { 0.3919999897480011, 0.3919999897480011, 0.3919999897480011 } },
    { 3,
      &articuno_gfxdata[18],
      { 1447.197998046875, -62.56370544433594, -125.37947082519531 },
      { 0.003874999936670065, -0.01845099963247776, 0.05117100104689598 },
      { 0.9999989867210388, 0.9999949932098389, 1.0000009536743164 } },
    { 4,
      &articuno_gfxdata[19],
      { 1421.9976806640625, 0.0, 0.0 },
      { -0.0537399984896183, -0.01459799986332655, -0.5689160227775574 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
