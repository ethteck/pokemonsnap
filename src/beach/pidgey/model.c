#include "common.h"

extern u8 pidgey_tex_8019E4F8[];
extern u8 pidgey_tex_8019E520_png[];
extern u8 pidgey_tex_8019E728[];
extern u8 pidgey_tex_8019E750_png[];
extern u8 pidgey_tex_8019EB58[];
extern u8 pidgey_tex_8019EB80_png[];
extern u8 pidgey_tex_8019ED88[];
extern u8 pidgey_tex_8019EDB0_png[];
extern u8 pidgey_tex_8019EFB8[];
extern u8 pidgey_tex_8019EFE0_png[];
extern u8 pidgey_tex_8019F3E8[];
extern u8 pidgey_tex_8019F410_png[];
extern u8 pidgey_tex_8019F618[];
extern u8 pidgey_tex_8019F820[];
extern u8 pidgey_tex_8019FE30[];
extern u8 pidgey_tex_801A0238[];
extern u8 pidgey_tex_801A0260_png[];
extern u8 pidgey_tex_801A0468[];
extern u8 pidgey_tex_801A0490_png[];
extern u8 pidgey_tex_801A0698[];
extern u8 pidgey_tex_801A06C0_png[];

extern Texture* pidgey_part9_mat[];
extern Gfx pidgey_part0_draw[];

Texture** pidgey_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    pidgey_part9_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* pidgey_part9_mat0_textures[] = {
    pidgey_tex_8019F820,
    pidgey_tex_8019FE30,
    NULL,
};

Texture pidgey_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    pidgey_part9_mat0_textures,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* pidgey_part9_mat[] = {
    &pidgey_part9_mat0,
    NULL,
};

#include "assets/beach/pidgey/model.vtx.inc.c"
#include "assets/beach/pidgey/first.gfx.inc.c"
#include "assets/beach/pidgey/part0_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part0_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part0_draw.gfx.inc.c"
#include "assets/beach/pidgey/part1_pre_near.gfx.inc.c"
#include "assets/beach/pidgey/part1_pre_far.gfx.inc.c"
#include "assets/beach/pidgey/part1_pre.gfx.inc.c"
#include "assets/beach/pidgey/part1_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part1_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part1_draw.gfx.inc.c"
#include "assets/beach/pidgey/part2_pre_near.gfx.inc.c"
#include "assets/beach/pidgey/part2_pre_far.gfx.inc.c"
#include "assets/beach/pidgey/part2_pre.gfx.inc.c"
#include "assets/beach/pidgey/part2_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part2_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part2_draw.gfx.inc.c"
#include "assets/beach/pidgey/part3_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part3_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part3_draw.gfx.inc.c"
#include "assets/beach/pidgey/part4_pre_near.gfx.inc.c"
#include "assets/beach/pidgey/part4_pre_far.gfx.inc.c"
#include "assets/beach/pidgey/part4_pre.gfx.inc.c"
#include "assets/beach/pidgey/part4_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part4_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part4_draw.gfx.inc.c"
#include "assets/beach/pidgey/part5_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part5_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part5_draw.gfx.inc.c"
#include "assets/beach/pidgey/part6_pre_near.gfx.inc.c"
#include "assets/beach/pidgey/part6_pre_far.gfx.inc.c"
#include "assets/beach/pidgey/part6_pre.gfx.inc.c"
#include "assets/beach/pidgey/part6_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part6_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part6_draw.gfx.inc.c"
#include "assets/beach/pidgey/part7_pre_near.gfx.inc.c"
#include "assets/beach/pidgey/part7_pre_far.gfx.inc.c"
#include "assets/beach/pidgey/part7_pre.gfx.inc.c"
#include "assets/beach/pidgey/part7_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part7_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part7_draw.gfx.inc.c"
#include "assets/beach/pidgey/part8_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part8_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part8_draw.gfx.inc.c"
#include "assets/beach/pidgey/part9_pre_near.gfx.inc.c"
#include "assets/beach/pidgey/part9_pre_far.gfx.inc.c"
#include "assets/beach/pidgey/part9_pre.gfx.inc.c"
#include "assets/beach/pidgey/part9_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part9_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part9_draw.gfx.inc.c"
#include "assets/beach/pidgey/part10_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part10_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part10_draw.gfx.inc.c"
#include "assets/beach/pidgey/part11_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part11_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part11_draw.gfx.inc.c"
#include "assets/beach/pidgey/part12_pre_near.gfx.inc.c"
#include "assets/beach/pidgey/part12_pre_far.gfx.inc.c"
#include "assets/beach/pidgey/part12_pre.gfx.inc.c"
#include "assets/beach/pidgey/part12_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part12_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part12_draw.gfx.inc.c"
#include "assets/beach/pidgey/part13_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part13_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part13_draw.gfx.inc.c"
#include "assets/beach/pidgey/part14_draw_near.gfx.inc.c"
#include "assets/beach/pidgey/part14_draw_far.gfx.inc.c"
#include "assets/beach/pidgey/part14_draw.gfx.inc.c"

#include "assets/beach/pidgey/last.gfx.inc.c"

DObjPayloadTypeI pidgey_gfxdata[] = {
    { NULL, pidgey_first },
    { pidgey_part1_pre, pidgey_part1_draw },
    { pidgey_part2_pre, pidgey_part2_draw },
    { NULL, pidgey_part3_draw },
    { pidgey_part4_pre, pidgey_part4_draw },
    { NULL, pidgey_part5_draw },
    { pidgey_part6_pre, pidgey_part6_draw },
    { pidgey_part7_pre, pidgey_part7_draw },
    { NULL, pidgey_part8_draw },
    { pidgey_part9_pre, pidgey_part9_draw },
    { NULL, pidgey_part10_draw },
    { NULL, pidgey_part11_draw },
    { pidgey_part12_pre, pidgey_part12_draw },
    { NULL, pidgey_part13_draw },
    { NULL, pidgey_last },
};

UnkEC64Arg3 pidgey_model[] = {
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
      &pidgey_gfxdata[0],
      { 0.0, 138.3363037109375, -47.450008392333984 },
      { -0.011402999982237816, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pidgey_gfxdata[1],
      { 0.0, -2.005139112472534, -100.41917419433594 },
      { -0.699999988079071, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pidgey_gfxdata[2],
      { 44.577178955078125, -4.849983215332031, -5.068727970123291 },
      { -0.6624370217323303, 0.4001460075378418, 0.1757189929485321 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pidgey_gfxdata[3],
      { -7.906383991241455, -63.47696304321289, -3.640388011932373 },
      { -0.983132004737854, 0.0, 0.0 },
      { 0.9999989867210388, 1.0, 1.0 } },
    { 2,
      &pidgey_gfxdata[4],
      { -44.577178955078125, -4.849983215332031, -5.068727970123291 },
      { -0.8240439891815186, -0.13785399496555328, 0.050383999943733215 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pidgey_gfxdata[5],
      { 7.906373977661133, -63.47697830200195, -3.6403870582580566 },
      { -0.362199991941452, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pidgey_gfxdata[6],
      { 0.0, 37.041378021240234, 15.974148750305176 },
      { 1.0393290519714355, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pidgey_gfxdata[7],
      { 0.0, 68.044677734375, 4.767516136169434 },
      { -0.2509140074253082, 0.0, 0.0 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 4,
      &pidgey_gfxdata[8],
      { -9.999999974752427e-07, 63.6733283996582, 33.17770767211914 },
      { -0.8212850093841553, 0.0, 0.0 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      &pidgey_gfxdata[9],
      { 43.4669303894043, 75.2618637084961, 4.020345211029053 },
      { -2.042546033859253, -0.3325749933719635, 1.771859049797058 },
      { 0.9999960064888, 0.9999989867210388, 1.0000050067901611 } },
    { 4,
      &pidgey_gfxdata[10],
      { -22.13178253173828, 11.304044723510742, -54.18474578857422 },
      { -0.8285620212554932, -0.15262100100517273, 0.017988000065088272 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &pidgey_gfxdata[11],
      { 4.096538066864014, -1.6917109489440918, -55.255985260009766 },
      { -0.5216540098190308, -0.3091779947280884, 0.09216900169849396 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pidgey_gfxdata[12],
      { -44.247615814208984, 75.2556381225586, 4.030858993530273 },
      { 1.0268889665603638, -3.4401960372924805, 1.5318670272827148 },
      { 0.9999960064888, 0.9999989867210388, 1.0000059604644775 } },
    { 4,
      &pidgey_gfxdata[13],
      { 22.130495071411133, 11.514949798583984, -53.43356704711914 },
      { -3.9488260746002197, -9.660379409790039, 3.211055040359497 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &pidgey_gfxdata[14],
      { -4.096538066864014, -1.6917049884796143, -55.256004333496094 },
      { -0.5154809951782227, -5.946709156036377, 0.057638999074697495 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
