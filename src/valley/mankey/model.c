#include "common.h"

extern u8 mankey_tex_8014DB08[];
extern u8 mankey_tex_8014DB18_png[];
extern u8 mankey_tex_8014DC20[];
extern u8 mankey_tex_8014DCF0_png[];
extern u8 mankey_tex_8014E0F8[];
extern u8 mankey_tex_8014E300[];
extern u8 mankey_tex_8014E708[];
extern u8 mankey_tex_8014E8F8[];
extern u8 mankey_tex_8014EEB0[];
extern u8 mankey_tex_8014F460[];
extern u8 mankey_tex_8014FA68[];
extern u8 mankey_tex_80150060[];
extern u8 mankey_tex_80150670[];
extern u8 mankey_tex_80150C68[];
extern u8 mankey_tex_80151220[];
extern u8 mankey_tex_801517D0[];
extern u8 mankey_tex_80151BD8[];
extern u8 mankey_tex_80151CC0_png[];
extern u8 mankey_tex_801520C8[];
extern u8 mankey_tex_80152168_png[];
extern u8 mankey_tex_80152570[];
extern u8 mankey_tex_801525A8_png[];

extern Texture* mankey_part1_mat[];
extern Gfx mankey_part0_draw[];

Texture** mankey_materials[] = {
    NULL,
    mankey_part1_mat,
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
};

u8* mankey_part1_mat0_textures[] = {
    mankey_tex_8014E300,
    mankey_tex_8014EEB0,
    mankey_tex_8014FA68,
    mankey_tex_80150670,
    mankey_tex_80151220,
};

u8* mankey_part1_mat1_textures[] = {
    mankey_tex_8014E8F8,
    mankey_tex_8014F460,
    mankey_tex_80150060,
    mankey_tex_80150C68,
    mankey_tex_801517D0,
    NULL,
};

Texture mankey_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    mankey_part1_mat0_textures,
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
    { 0, 0, 0, 0 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture mankey_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    mankey_part1_mat1_textures,
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
    { 0, 0, 0, 0 },
    { 255, 255, 255, 0 },
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* mankey_part1_mat[] = {
    &mankey_part1_mat0,
    &mankey_part1_mat1,
    NULL,
    NULL,
};

#include "assets/valley/mankey/model.vtx.inc.c"
#include "assets/valley/mankey/first.gfx.inc.c"
#include "assets/valley/mankey/part0_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part0_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part0_draw.gfx.inc.c"
#include "assets/valley/mankey/part1_pre_near.gfx.inc.c"
#include "assets/valley/mankey/part1_pre_far.gfx.inc.c"
#include "assets/valley/mankey/part1_pre.gfx.inc.c"
#include "assets/valley/mankey/part1_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part1_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part1_draw.gfx.inc.c"
#include "assets/valley/mankey/part2_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part2_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part2_draw.gfx.inc.c"
#include "assets/valley/mankey/part3_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part3_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part3_draw.gfx.inc.c"
#include "assets/valley/mankey/part4_pre_near.gfx.inc.c"
#include "assets/valley/mankey/part4_pre_far.gfx.inc.c"
#include "assets/valley/mankey/part4_pre.gfx.inc.c"
#include "assets/valley/mankey/part4_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part4_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part4_draw.gfx.inc.c"
#include "assets/valley/mankey/part5_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part5_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part5_draw.gfx.inc.c"
#include "assets/valley/mankey/part6_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part6_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part6_draw.gfx.inc.c"
#include "assets/valley/mankey/part7_pre_near.gfx.inc.c"
#include "assets/valley/mankey/part7_pre_far.gfx.inc.c"
#include "assets/valley/mankey/part7_pre.gfx.inc.c"
#include "assets/valley/mankey/part7_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part7_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part7_draw.gfx.inc.c"
#include "assets/valley/mankey/part8_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part8_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part8_draw.gfx.inc.c"
#include "assets/valley/mankey/part9_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part9_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part9_draw.gfx.inc.c"
#include "assets/valley/mankey/part10_pre_near.gfx.inc.c"
#include "assets/valley/mankey/part10_pre_far.gfx.inc.c"
#include "assets/valley/mankey/part10_pre.gfx.inc.c"
#include "assets/valley/mankey/part10_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part10_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part10_draw.gfx.inc.c"
#include "assets/valley/mankey/part11_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part11_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part11_draw.gfx.inc.c"
#include "assets/valley/mankey/part12_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part12_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part12_draw.gfx.inc.c"
#include "assets/valley/mankey/part13_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part13_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part13_draw.gfx.inc.c"
#include "assets/valley/mankey/part14_draw_near.gfx.inc.c"
#include "assets/valley/mankey/part14_draw_far.gfx.inc.c"
#include "assets/valley/mankey/part14_draw.gfx.inc.c"
#include "assets/valley/mankey/last.gfx.inc.c"

DObjPayloadTypeI mankey_gfxdata[] = {
    { NULL, mankey_first },
    { mankey_part1_pre, mankey_part1_draw },
    { NULL, mankey_part2_draw },
    { NULL, mankey_part3_draw },
    { mankey_part4_pre, mankey_part4_draw },
    { NULL, mankey_part5_draw },
    { NULL, mankey_part6_draw },
    { mankey_part7_pre, mankey_part7_draw },
    { NULL, mankey_part8_draw },
    { NULL, mankey_part9_draw },
    { mankey_part10_pre, mankey_part10_draw },
    { NULL, mankey_part11_draw },
    { NULL, mankey_part12_draw },
    { NULL, mankey_part13_draw },
    { NULL, mankey_last },
};

UnkEC64Arg3 mankey_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &mankey_gfxdata[0],
      { 0.0, 195.20266723632812, 0.0 },
      { 0.5860180258750916, -0.030995000153779984, -0.010885999538004398 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &mankey_gfxdata[1],
      { 139.37110900878906, 114.81459045410156, 8.855825424194336 },
      { -0.3125559985637665, 0.035698000341653824, 0.8655059933662415 },
      { 1.0, 0.9999989867210388, 0.9999979734420776 } },
    { 3,
      &mankey_gfxdata[2],
      { 132.64520263671875, 11.311226844787598, 9.812450408935547 },
      { 0.07645899802446365, -0.09966299682855606, 0.9166479706764221 },
      { 1.0000150203704834, 1.0, 0.9999979734420776 } },
    { 4,
      &mankey_gfxdata[3],
      { 131.85243225097656, 11.112093925476074, -4.208563804626465 },
      { -0.25137999653816223, -6.610135078430176, 0.027302000671625137 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 2,
      &mankey_gfxdata[4],
      { -139.3711700439453, 114.81454467773438, 8.85580825805664 },
      { 0.03246700018644333, 2.9226489067077637, -0.6495760083198547 },
      { 1.0, 0.9999989867210388, 0.9999979734420776 } },
    { 3,
      &mankey_gfxdata[5],
      { 132.6451873779297, 11.311234474182129, -9.812453269958496 },
      { -0.049897998571395874, 0.09328100085258484, 1.0453380346298218 },
      { 1.0000150203704834, 1.0, 0.9999979734420776 } },
    { 4,
      &mankey_gfxdata[6],
      { 131.85243225097656, 11.112081527709961, 4.208566188812256 },
      { 0.04025200009346008, -6.651749134063721, 0.2839770019054413 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 2,
      &mankey_gfxdata[7],
      { 106.4142074584961, -25.244544982910156, -5.42703914642334 },
      { -3.096484899520874, -0.9213830232620239, 0.15185999870300293 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &mankey_gfxdata[8],
      { 131.56292724609375, -1.8480420112609863, 6.231964111328125 },
      { 0.0, 9.999999974752427e-07, 2.0008749961853027 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 4,
      &mankey_gfxdata[9],
      { 117.2496109008789, 8.351486206054688, 12.704521179199219 },
      { -0.12818600237369537, 0.5605419874191284, -0.7208989858627319 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &mankey_gfxdata[10],
      { -106.41423797607422, -25.244510650634766, -5.4270148277282715 },
      { 0.21442599594593048, -0.9133430123329163, -3.3491408824920654 },
      { 1.0, 1.0, 0.9999979734420776 } },
    { 3,
      &mankey_gfxdata[11],
      { 131.56292724609375, -1.8480379581451416, -6.231956958770752 },
      { -9.999999974752427e-07, 0.0, 2.065124988555908 },
      { 1.0, 1.0, 0.9999989867210388 } },
    { 4,
      &mankey_gfxdata[12],
      { 117.2496337890625, 8.351496696472168, -12.704497337341309 },
      { -0.03700700029730797, -0.3720499873161316, -0.6891300082206726 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &mankey_gfxdata[13],
      { 3.999999989900971e-06, -19.29945945739746, -136.21714782714844 },
      { -1.1151740550994873, 0.3509419858455658, -0.28606200218200684 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &mankey_gfxdata[14],
      { 0.4752010107040405, -1.5830830335617065, -281.2263488769531 },
      { 0.23476600646972656, 0.3435800075531006, 0.07989700138568878 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
