#include "common.h"

extern u8 ditto_tex_8017D518[];
extern u8 ditto_tex_8017D550_png[];

extern Gfx ditto_part0_draw[];

#include "assets/cave/ditto/model.vtx.inc.c"
#include "assets/cave/ditto/first.gfx.inc.c"
#include "assets/cave/ditto/part0_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part0_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part0_draw.gfx.inc.c"
#include "assets/cave/ditto/part1_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part1_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part1_pre.gfx.inc.c"
#include "assets/cave/ditto/part1_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part1_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part1_draw.gfx.inc.c"
#include "assets/cave/ditto/part2_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part2_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part2_pre.gfx.inc.c"
#include "assets/cave/ditto/part2_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part2_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part2_draw.gfx.inc.c"
#include "assets/cave/ditto/part3_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part3_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part3_pre.gfx.inc.c"
#include "assets/cave/ditto/part3_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part3_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part3_draw.gfx.inc.c"
#include "assets/cave/ditto/part4_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part4_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part4_pre.gfx.inc.c"
#include "assets/cave/ditto/part4_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part4_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part4_draw.gfx.inc.c"
#include "assets/cave/ditto/part5_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part5_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part5_pre.gfx.inc.c"
#include "assets/cave/ditto/part5_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part5_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part5_draw.gfx.inc.c"
#include "assets/cave/ditto/part6_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part6_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part6_pre.gfx.inc.c"
#include "assets/cave/ditto/part6_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part6_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part6_draw.gfx.inc.c"
#include "assets/cave/ditto/part7_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part7_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part7_pre.gfx.inc.c"
#include "assets/cave/ditto/part7_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part7_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part7_draw.gfx.inc.c"
#include "assets/cave/ditto/part8_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part8_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part8_pre.gfx.inc.c"
#include "assets/cave/ditto/part8_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part8_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part8_draw.gfx.inc.c"
#include "assets/cave/ditto/part9_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part9_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part9_draw.gfx.inc.c"
#include "assets/cave/ditto/part10_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part10_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part10_pre.gfx.inc.c"
#include "assets/cave/ditto/part10_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part10_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part10_draw.gfx.inc.c"
#include "assets/cave/ditto/part11_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part11_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part11_draw.gfx.inc.c"
#include "assets/cave/ditto/part12_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part12_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part12_pre.gfx.inc.c"
#include "assets/cave/ditto/part12_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part12_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part12_draw.gfx.inc.c"
#include "assets/cave/ditto/part13_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part13_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part13_pre.gfx.inc.c"
#include "assets/cave/ditto/part13_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part13_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part13_draw.gfx.inc.c"
#include "assets/cave/ditto/part14_pre_near.gfx.inc.c"
#include "assets/cave/ditto/part14_pre_far.gfx.inc.c"
#include "assets/cave/ditto/part14_pre.gfx.inc.c"
#include "assets/cave/ditto/part14_draw_near.gfx.inc.c"
#include "assets/cave/ditto/part14_draw_far.gfx.inc.c"
#include "assets/cave/ditto/part14_draw.gfx.inc.c"
#include "assets/cave/ditto/last.gfx.inc.c"

DObjPayloadTypeI ditto_gfxdata[] = {
    { NULL, ditto_first },
    { ditto_part1_pre, ditto_part1_draw },
    { ditto_part2_pre, ditto_part2_draw },
    { ditto_part3_pre, ditto_part3_draw },
    { ditto_part4_pre, ditto_part4_draw },
    { ditto_part5_pre, ditto_part5_draw },
    { ditto_part6_pre, ditto_part6_draw },
    { ditto_part7_pre, ditto_part7_draw },
    { ditto_part8_pre, ditto_part8_draw },
    { NULL, ditto_part9_draw },
    { ditto_part10_pre, ditto_part10_draw },
    { NULL, ditto_part11_draw },
    { ditto_part12_pre, ditto_part12_draw },
    { ditto_part13_pre, ditto_part13_draw },
    { ditto_part14_pre, ditto_last },
};

UnkEC64Arg3 ditto_model[] = {
    { 0,
      NULL,
      { 0.0, -4.019655227661133, 0.0 },
      { -0.011818000115454197, 0.0, 0.0 },
      { 0.9672989845275879, 1.019068956375122, 1.0022059679031372 } },
    { 1,
      &ditto_gfxdata[0],
      { 0.0, 164.67515563964844, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &ditto_gfxdata[1],
      { 173.74069213867188, -109.61438751220703, 11.953519821166992 },
      { 0.0, 1.570024013519287, 0.0 },
      { 1.0001970529556274, 1.0001319646835327, 1.0 } },
    { 2,
      &ditto_gfxdata[2],
      { -177.54244995117188, -106.2831039428711, 7.14743709564209 },
      { 0.0, -1.5219999551773071, 0.017517000436782837 },
      { 0.9999979734420776, 0.9987170100212097, 0.9982900023460388 } },
    { 2,
      &ditto_gfxdata[3],
      { 76.91291046142578, -101.07161712646484, 104.81304168701172 },
      { 0.021159999072551727, 0.20800000429153442, 0.0 },
      { 1.0004609823226929, 1.0002599954605103, 1.0 } },
    { 2,
      &ditto_gfxdata[4],
      { -49.58608627319336, -102.41853332519531, 92.5594253540039 },
      { 0.021159999072551727, -0.36000001430511475, 0.0 },
      { 1.00075101852417, 1.0004609823226929, 1.0 } },
    { 2,
      &ditto_gfxdata[5],
      { 74.8672103881836, -108.41856384277344, -130.8936767578125 },
      { 0.021159999072551727, 2.9240009784698486, 0.0 },
      { 1.0000499486923218, 1.0002939701080322, 1.0 } },
    { 2,
      &ditto_gfxdata[6],
      { -74.6078872680664, -101.25878143310547, -120.41338348388672 },
      { 0.021159999072551727, 3.492000102996826, 0.0 },
      { 1.0003340244293213, 1.0003390312194824, 1.0 } },
    { 2,
      &ditto_gfxdata[7],
      { -0.3854460120201111, 8.059202194213867, 21.61354637145996 },
      { 0.05117499828338623, 0.005927999969571829, 0.025310000404715538 },
      { 0.9988300204277039, 1.0393719673156738, 0.9910100102424622 } },
    { 3,
      &ditto_gfxdata[8],
      { 142.93875122070312, 31.626876831054688, -1.9742670059204102 },
      { 0.0, -0.041836999356746674, 0.8188160061836243 },
      { 1.0589449405670166, 0.9905779957771301, 0.9897580146789551 } },
    { 4,
      &ditto_gfxdata[9],
      { 25.297170639038086, 2.1983649730682373, 1.07053804397583 },
      { 0.0, -0.03446999937295914, -0.018735000863671303 },
      { 1.0068639516830444, 0.9991639852523804, 1.0006120204925537 } },
    { 3,
      &ditto_gfxdata[10],
      { -132.4351806640625, 71.2631607055664, -0.9949939846992493 },
      { 0.0, -0.04181800037622452, 2.5309500694274902 },
      { 1.0118329524993896, 0.9988899827003479, 0.9902610182762146 } },
    { 4,
      &ditto_gfxdata[11],
      { 27.011743545532227, -5.939838886260986, 0.053734999150037766 },
      { 0.0, -0.03464699909090996, -0.4060100018978119 },
      { 1.0098880529403687, 1.0004949569702148, 1.0003869533538818 } },
    { 3,
      &ditto_gfxdata[12],
      { -0.05795799940824509, 101.6337661743164, 1.0590260028839111 },
      { 0.018813999369740486, 0.0, -0.002078999998047948 },
      { 1.0011179447174072, 1.099208950996399, 1.0007189512252808 } },
    { 4,
      &ditto_gfxdata[13],
      { 50.72459030151367, 33.431087493896484, 9.999999747378752e-06 },
      { 0.018585000187158585, 0.0, -0.17268399894237518 },
      { 1.0033990144729614, 1.0064170360565186, 1.0 } },
    { 4,
      &ditto_gfxdata[14],
      { -44.82487487792969, 48.044891357421875, -2.1177830696105957 },
      { 0.016888000071048737, 0.0, -0.004209000151604414 },
      { 1.0006049871444702, 0.9852920174598694, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
