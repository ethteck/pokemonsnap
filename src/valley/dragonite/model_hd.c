#include "common.h"

extern u8 dragonite_tex_80142AE0[];
extern u8 dragonite_tex_80142B08_png[];
extern u8 dragonite_tex_80142C90[];
extern u8 dragonite_tex_80142E80_png[];
extern u8 dragonite_tex_80143088[];
extern u8 dragonite_tex_801431A0_png[];
extern u8 dragonite_tex_80143628[];
extern u8 dragonite_tex_80143820_png[];
extern u8 dragonite_tex_80144028[];
extern u8 dragonite_tex_801440C0_png[];
extern u8 dragonite_tex_801441C8[];
extern u8 dragonite_tex_801441F0_png[];
extern u8 dragonite_tex_80144378[];
extern u8 dragonite_tex_80144580_png[];
extern u8 dragonite_tex_80144988[];
extern u8 dragonite_tex_80144B28_png[];
extern u8 dragonite_tex_80145330[];
extern u8 dragonite_tex_80145358_png[];

extern Gfx dragonite_hd_part0_draw[];

#include "assets/valley/dragonite/hd_model.vtx.inc.c"
#include "assets/valley/dragonite/hd_first.gfx.inc.c"
#include "assets/valley/dragonite/hd_part0_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part1_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part1_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part2_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part3_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part4_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part4_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part5_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part6_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part7_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part7_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part8_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part8_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part9_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part10_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part10_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part11_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part12_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part12_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part13_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part14_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part14_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part15_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part16_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part16_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part17_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part18_pre.gfx.inc.c"
#include "assets/valley/dragonite/hd_part18_draw.gfx.inc.c"
#include "assets/valley/dragonite/hd_part19_draw.gfx.inc.c"

DObjPayloadTypeI dragonite_hd_gfxdata[] = {
    { NULL, dragonite_hd_first },
    { dragonite_hd_part1_pre, dragonite_hd_part1_draw },
    { NULL, dragonite_hd_part2_draw },
    { NULL, dragonite_hd_part3_draw },
    { dragonite_hd_part4_pre, dragonite_hd_part4_draw },
    { NULL, dragonite_hd_part5_draw },
    { NULL, dragonite_hd_part6_draw },
    { dragonite_hd_part7_pre, dragonite_hd_part7_draw },
    { dragonite_hd_part8_pre, dragonite_hd_part8_draw },
    { NULL, dragonite_hd_part9_draw },
    { dragonite_hd_part10_pre, dragonite_hd_part10_draw },
    { NULL, dragonite_hd_part11_draw },
    { dragonite_hd_part12_pre, dragonite_hd_part12_draw },
    { NULL, dragonite_hd_part13_draw },
    { dragonite_hd_part14_pre, dragonite_hd_part14_draw },
    { NULL, dragonite_hd_part15_draw },
    { dragonite_hd_part16_pre, dragonite_hd_part16_draw },
    { NULL, dragonite_hd_part17_draw },
    { dragonite_hd_part18_pre, dragonite_hd_part18_draw },
    { NULL, dragonite_hd_part19_draw },
};

UnkEC64Arg3 dragonite_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &dragonite_hd_gfxdata[0],
      { 0.0, 684.70166015625, 179.64540100097656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 0.0, -684.70166015625, -179.64540100097656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &dragonite_hd_gfxdata[1],
      { 596.4125366210938, -86.1360092163086, -179.64540100097656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dragonite_hd_gfxdata[2],
      { -66.58301544189453, -428.4089050292969, 185.2106170654297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &dragonite_hd_gfxdata[3],
      { -74.3336181640625, -303.2908020019531, -332.3872985839844 },
      { 0.8899999856948853, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &dragonite_hd_gfxdata[4],
      { -596.4125366210938, -86.1360092163086, -179.64540100097656 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dragonite_hd_gfxdata[5],
      { 66.58301544189453, -428.4089050292969, 185.2106170654297 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &dragonite_hd_gfxdata[6],
      { 74.3336181640625, -303.2908020019531, -332.3872985839844 },
      { 0.8899999856948853, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &dragonite_hd_gfxdata[7],
      { 0.0, 74.81698608398438, -45.54722213745117 },
      { 0.1599999964237213, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dragonite_hd_gfxdata[8],
      { -0.17004500329494476, 1071.2354736328125, -97.07357025146484 },
      { -0.02178799919784069, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      NULL,
      { 0.17004500329494476, -1843.846923828125, 45.5337028503418 },
      { -0.13821199536323547, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &dragonite_hd_gfxdata[9],
      { -0.00024199999461416155, 67.19989776611328, 11.567521095275879 },
      { 2.9177629947662354, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      NULL,
      { -8.203045845031738, 173.182861328125, 320.7017822265625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dragonite_hd_gfxdata[10],
      { 137.70169067382812, 585.759521484375, -361.98724365234375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.3489999771118164 } },
    { 4,
      &dragonite_hd_gfxdata[11],
      { 140.2578887939453, 200.41522216796875, -496.5789794921875 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dragonite_hd_gfxdata[12],
      { -137.70169067382812, 585.759521484375, -361.98724365234375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.3489999771118164 } },
    { 4,
      &dragonite_hd_gfxdata[13],
      { -140.2578887939453, 200.41522216796875, -496.57904052734375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dragonite_hd_gfxdata[14],
      { 278.16217041015625, 585.6237182617188, -72.08075714111328 },
      { -1.309999942779541, 0.0, -0.8599990010261536 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &dragonite_hd_gfxdata[15],
      { 301.4996643066406, 34.17081832885742, -14.485886573791504 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dragonite_hd_gfxdata[16],
      { -278.5025634765625, 585.6237182617188, -72.08075714111328 },
      { 9.999999974752427e-07, 9.999999974752427e-07, 0.8699989914894104 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &dragonite_hd_gfxdata[17],
      { -301.49951171875, 34.17081832885742, -14.486059188842773 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &dragonite_hd_gfxdata[18],
      { 0.0, -486.5635986328125, -542.3568115234375 },
      { -0.23999999463558197, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &dragonite_hd_gfxdata[19],
      { 0.0, 376.7765197753906, -628.5648193359375 },
      { 0.23999999463558197, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
