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

extern u8 D_80170068_cave_extra[];
extern u8 D_80170090_cave_extra[];
extern u8 D_80170290_cave_extra[];
extern u8 D_801702B8_cave_extra[];
extern u8 D_801703C0_cave_extra[];
extern u8 D_80171050_cave_extra[];
extern u8 D_80171078_cave_extra[];
extern u8 D_80171280_cave_extra[];
extern u8 D_801712A8_cave_extra[];
extern u8 D_80171330_cave_extra[];
extern u8 D_80171358_cave_extra[];
extern u8 D_80171760_cave_extra[];
extern u8 D_80171788_cave_extra[];
extern u8 D_80171B90_cave_extra[];
extern u8 D_80171BB8_cave_extra[];
extern u8 D_80171FC0_cave_extra[];
extern u8 D_80171FE8_cave_extra[];
extern u8 D_801720F0_cave_extra[];
extern u8 D_80172118_cave_extra[];
extern u8 D_80172520_cave_extra[];
extern u8 D_80172548_cave_extra[];
extern u8 D_801BBC80_cave_extra[];
extern u8 D_801BBC90_cave_extra[];
extern u8 D_801BBCF0_cave_extra[];
extern u8 D_801BBDA0_cave_extra[];
extern u8 D_801BBE70_cave_extra[];
extern u8 D_801BBED0_cave_extra[];
extern u8 D_801BBEE0_cave_extra[];
extern u8 D_801BBF00_cave_extra[];
extern u8 D_801BBF20_cave_extra[];
extern u8 D_801BBF40_cave_extra[];
extern u8 D_801BBF50_cave_extra[];
extern u8 D_801BBF60_cave_extra[];
extern u8 D_801BBF90_cave_extra[];
extern u8 D_801BBFB0_cave_extra[];
extern u8 D_801BBFD0_cave_extra[];
extern u8 D_801BBFF0_cave_extra[];
extern u8 D_801BC000_cave_extra[];
extern u8 D_801BC010_cave_extra[];
extern u8 D_801BC030_cave_extra[];
extern u8 D_801BC040_cave_extra[];
extern u8 D_801BC050_cave_extra[];
extern u8 D_801BC070_cave_extra[];
extern u8 D_801BC080_cave_extra[];
extern u8 D_801BC0A0_cave_extra[];
extern u8 D_801BC0D0_cave_extra[];
extern u8 D_801BC0E0_cave_extra[];
extern u8 D_801BC0F0_cave_extra[];
extern u8 D_801BC100_cave_extra[];
extern u8 D_801BC110_cave_extra[];
extern u8 D_801BC120_cave_extra[];
extern u8 D_801BC160_cave_extra[];
extern u8 D_801BC1A0_cave_extra[];
extern u8 D_801BC220_cave_extra[];
extern u8 D_801BC260_cave_extra[];
extern u8 D_801BC270_cave_extra[];
extern u8 D_801BC2A0_cave_extra[];
extern u8 D_801BC2C0_cave_extra[];
extern u8 D_801BC2E0_cave_extra[];
extern u8 D_801BC340_cave_extra[];
extern u8 D_801BC370_cave_extra[];
extern u8 D_801BC3E0_cave_extra[];
extern u8 D_801BC440_cave_extra[];
extern u8 D_801BC460_cave_extra[];
extern u8 D_801BC470_cave_extra[];
extern u8 D_801BC480_cave_extra[];
extern u8 D_801BC4B0_cave_extra[];
extern u8 D_801BC540_cave_extra[];
extern u8 D_801BC570_cave_extra[];
extern u8 D_801BC5A0_cave_extra[];
extern u8 D_801BC5D0_cave_extra[];
extern u8 D_801BC640_cave_extra[];
extern u8 D_801BC670_cave_extra[];
extern u8 D_801BC6C0_cave_extra[];
extern u8 D_801BC720_cave_extra[];
extern u8 D_801BC740_cave_extra[];
extern u8 D_801BC810_cave_extra[];
extern u8 D_801BC8D0_cave_extra[];
extern u8 D_801BC8E0_cave_extra[];
extern u8 D_801BC900_cave_extra[];
extern u8 D_801BC940_cave_extra[];
extern u8 D_801BC9B0_cave_extra[];
extern u8 D_801BC9C0_cave_extra[];
extern u8 D_801BCA00_cave_extra[];
extern u8 D_801BCA20_cave_extra[];
extern u8 D_801BCA60_cave_extra[];
extern u8 D_801BCA70_cave_extra[];
extern u8 D_801BCAF0_cave_extra[];
extern u8 D_801BCBC0_cave_extra[];
extern u8 D_801BCBE0_cave_extra[];
extern u8 D_801BCBF0_cave_extra[];
extern u8 D_801BCC00_cave_extra[];
extern u8 D_801BCC10_cave_extra[];
extern u8 D_801BCC40_cave_extra[];
extern u8 D_801BCC70_cave_extra[];
extern u8 D_801BCCC0_cave_extra[];
extern u8 D_801BCD30_cave_extra[];
extern u8 D_801BCD80_cave_extra[];
extern u8 D_801BCE90_cave_extra[];
extern u8 D_801BCEB0_cave_extra[];
extern u8 D_801BCF00_cave_extra[];
extern u8 D_801BCF40_cave_extra[];
extern u8 D_801BCF50_cave_extra[];
extern u8 D_801BCF70_cave_extra[];
extern u8 D_801BCF90_cave_extra[];
extern u8 D_801BCFC0_cave_extra[];
extern u8 D_801BD030_cave_extra[];
extern u8 D_801BD040_cave_extra[];
extern u8 D_801BD080_cave_extra[];
extern u8 D_801BD0A0_cave_extra[];
extern u8 D_801BD0E0_cave_extra[];
extern u8 D_801BD0F0_cave_extra[];
extern u8 D_801BD160_cave_extra[];
extern u8 D_801BD190_cave_extra[];
extern u8 D_801BD240_cave_extra[];
extern u8 D_801BD260_cave_extra[];
extern u8 D_801BD270_cave_extra[];
extern u8 D_801BD280_cave_extra[];
extern u8 D_801BD290_cave_extra[];
extern u8 D_801BD2C0_cave_extra[];
extern u8 D_801BD2F0_cave_extra[];
extern u8 D_801BD330_cave_extra[];
extern u8 D_801BD340_cave_extra[];
extern u8 D_801BD3A0_cave_extra[];
extern u8 D_801BD400_cave_extra[];
extern u8 D_801BD510_cave_extra[];
extern u8 D_801BD530_cave_extra[];
extern u8 D_801BD570_cave_extra[];
extern u8 D_801BD5C0_cave_extra[];
extern u8 D_801BD5D0_cave_extra[];
extern u8 D_801BD6A0_cave_extra[];
extern u8 D_801BD730_cave_extra[];
extern u8 D_801BD870_cave_extra[];
extern u8 D_801BD910_cave_extra[];
extern u8 D_801BD9A0_cave_extra[];
extern u8 D_801BD9B0_cave_extra[];
extern u8 D_801BD9E0_cave_extra[];
extern u8 D_801BDA30_cave_extra[];
extern u8 D_801BDA50_cave_extra[];
extern u8 D_801BDA80_cave_extra[];
extern u8 D_801BDAB0_cave_extra[];
extern u8 D_801BDB20_cave_extra[];
extern u8 D_801BDB30_cave_extra[];
extern u8 D_801BDB40_cave_extra[];
extern u8 D_801BDB50_cave_extra[];
extern u8 D_801BDB90_cave_extra[];
extern u8 D_801BDBA0_cave_extra[];
extern u8 D_801BDBB0_cave_extra[];
extern u8 D_801BDBC0_cave_extra[];
extern u8 D_801BDC20_cave_extra[];
extern u8 D_801BDC60_cave_extra[];
extern u8 D_801BDCE0_cave_extra[];
extern u8 D_801BDD98_cave_extra[];

extern Texture* articuno_hd_part16_mat[];
extern Gfx articuno_hd_part0_draw[];

Texture** articuno_hd_materials[] = {
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
    articuno_hd_part16_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* articuno_hd_part16_mat0_textures[] = {
    articuno_tex_8016FE08,
    articuno_tex_80170238,
    articuno_tex_80170668,
};

Texture articuno_hd_part16_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    articuno_hd_part16_mat0_textures,
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

Texture* articuno_hd_part16_mat[] = {
    &articuno_hd_part16_mat0,
    NULL,
};

#include "assets/cave/articuno/hd_model.vtx.inc.c"
#include "assets/cave/articuno/hd_first.gfx.inc.c"
#include "assets/cave/articuno/hd_part0_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part1_pre.gfx.inc.c"
#include "assets/cave/articuno/hd_part1_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part2_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part3_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part4_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part5_pre.gfx.inc.c"
#include "assets/cave/articuno/hd_part5_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part6_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part7_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part8_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part9_pre.gfx.inc.c"
#include "assets/cave/articuno/hd_part9_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part10_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part11_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part12_pre.gfx.inc.c"
#include "assets/cave/articuno/hd_part12_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part13_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part14_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part15_pre.gfx.inc.c"
#include "assets/cave/articuno/hd_part15_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part16_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part17_pre.gfx.inc.c"
#include "assets/cave/articuno/hd_part17_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part18_draw.gfx.inc.c"
#include "assets/cave/articuno/hd_part19_draw.gfx.inc.c"

DObjPayloadTypeI articuno_hd_gfxdata[] = {
    { NULL, articuno_hd_first },
    { articuno_hd_part1_pre, articuno_hd_part1_draw },
    { NULL, articuno_hd_part2_draw },
    { NULL, articuno_hd_part3_draw },
    { NULL, articuno_hd_part4_draw },
    { articuno_hd_part5_pre, articuno_hd_part5_draw },
    { NULL, articuno_hd_part6_draw },
    { NULL, articuno_hd_part7_draw },
    { NULL, articuno_hd_part8_draw },
    { articuno_hd_part9_pre, articuno_hd_part9_draw },
    { NULL, articuno_hd_part10_draw },
    { NULL, articuno_hd_part11_draw },
    { articuno_hd_part12_pre, articuno_hd_part12_draw },
    { NULL, articuno_hd_part13_draw },
    { NULL, articuno_hd_part14_draw },
    { articuno_hd_part15_pre, articuno_hd_part15_draw },
    { NULL, articuno_hd_part16_draw },
    { articuno_hd_part17_pre, articuno_hd_part17_draw },
    { NULL, articuno_hd_part18_draw },
    { NULL, articuno_hd_part19_draw },
};

UnkEC64Arg3 articuno_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &articuno_hd_gfxdata[0],
      { 0.0, 690.4114990234375, -108.05498504638672 },
      { 1.570796012878418, -0.7022650241851807, 1.570796012878418 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_hd_gfxdata[1],
      { -77.94625854492188, 184.65769958496094, -157.52337646484375 },
      { 0.16439199447631836, -0.06185400113463402, -3.4662070274353027 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_hd_gfxdata[2],
      { 243.8610382080078, 3.600000127335079e-05, -0.00022600000374950469 },
      { 0.0, 0.0, -0.7889270186424255 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &articuno_hd_gfxdata[3],
      { 208.34902954101562, -3.000000106112566e-06, 7.200000254670158e-05 },
      { 0.0, -0.0011690000537782907, -1.1724849939346313 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &articuno_hd_gfxdata[4],
      { 9.999999747378752e-06, 4.199999966658652e-05, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_hd_gfxdata[5],
      { -77.94628143310547, 184.6575927734375, 157.5234832763672 },
      { -0.16439199447631836, 0.06185400113463402, -3.4662070274353027 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_hd_gfxdata[6],
      { 243.86109924316406, 0.0, -8.299999899463728e-05 },
      { 0.0, 0.0, -0.7889279723167419 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &articuno_hd_gfxdata[7],
      { 208.3488006591797, -5.700000110664405e-05, -7.200000254670158e-05 },
      { 0.0, -0.0011690000537782907, -1.1724849939346313 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &articuno_hd_gfxdata[8],
      { -7.000000096013537e-06, 1.8000000636675395e-05, -1.2000000424450263e-05 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_hd_gfxdata[9],
      { 450.5221252441406, -135.21966552734375, -216.54522705078125 },
      { 2.196523904800415, 0.8356419801712036, 0.4600670039653778 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_hd_gfxdata[10],
      { 412.7908630371094, 9.500000305706635e-05, 4.8000001697801054e-05 },
      { 0.33827900886535645, 0.5968170166015625, 0.920536994934082 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &articuno_hd_gfxdata[11],
      { 717.4053955078125, -0.00019099999917671084, 0.00023799999326001853 },
      { 0.49056199193000793, 0.6146029829978943, 0.5363439917564392 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_hd_gfxdata[12],
      { 450.5221252441406, -135.21986389160156, 216.5453643798828 },
      { -2.284632921218872, -0.6738079786300659, 0.5206480026245117 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_hd_gfxdata[13],
      { 412.79095458984375, -9.500000305706635e-05, 0.0 },
      { -0.5195789933204651, -0.24451400339603424, 0.8698660135269165 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &articuno_hd_gfxdata[14],
      { 717.4055786132812, 0.0, 9.500000305706635e-05 },
      { -0.5591340065002441, -0.6245099902153015, 0.22424499690532684 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_hd_gfxdata[15],
      { 601.5830078125, 0.0001429999974789098, 1.9999999494757503e-05 },
      { -3.1415929794311523, -3.1415929794311523, -2.1451900005340576 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &articuno_hd_gfxdata[16],
      { 149.3662109375, -80.62429809570312, 7.000000096013537e-06 },
      { 0.0, 0.0, 0.23558400571346283 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &articuno_hd_gfxdata[17],
      { -394.0039978027344, -240.18020629882812, 3.999999989900971e-06 },
      { 0.0, -0.08726699650287628, -2.355112075805664 },
      { 0.3919999897480011, 0.3919999897480011, 0.3919999897480011 } },
    { 3,
      &articuno_hd_gfxdata[18],
      { 1447.197998046875, -62.56370544433594, -125.37947082519531 },
      { 0.003874999936670065, -0.01845099963247776, 0.05117100104689598 },
      { 0.9999989867210388, 0.9999949932098389, 1.0000009536743164 } },
    { 4,
      &articuno_hd_gfxdata[19],
      { 1421.9976806640625, 0.0, 0.0 },
      { -0.0537399984896183, -0.01459799986332655, -0.5689160227775574 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
