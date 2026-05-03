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

extern Texture* pidgey_hd_part9_mat[];
extern Gfx pidgey_hd_part0_draw[];

Texture** pidgey_hd_materials[] = {
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    pidgey_hd_part9_mat,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* pidgey_hd_part9_mat0_textures[] = {
    pidgey_tex_8019F820,
    pidgey_tex_8019FE30,
    NULL,
};

Texture pidgey_hd_part9_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    pidgey_hd_part9_mat0_textures,
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
    { 50, 50, 50, 0 },
    0,
    0,
    0,
    0,
};

Texture* pidgey_hd_part9_mat[] = {
    &pidgey_hd_part9_mat0,
    NULL,
};
#include "assets/beach/pidgey/hd_model.vtx.inc.c"
#include "assets/beach/pidgey/hd_first.gfx.inc.c"
#include "assets/beach/pidgey/hd_part0_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part1_pre.gfx.inc.c"
#include "assets/beach/pidgey/hd_part1_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part2_pre.gfx.inc.c"
#include "assets/beach/pidgey/hd_part2_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part3_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part4_pre.gfx.inc.c"
#include "assets/beach/pidgey/hd_part4_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part5_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part6_pre.gfx.inc.c"
#include "assets/beach/pidgey/hd_part6_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part7_pre.gfx.inc.c"
#include "assets/beach/pidgey/hd_part7_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part8_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part9_pre.gfx.inc.c"
#include "assets/beach/pidgey/hd_part9_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part10_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part11_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part12_pre.gfx.inc.c"
#include "assets/beach/pidgey/hd_part12_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part13_draw.gfx.inc.c"
#include "assets/beach/pidgey/hd_part14_draw.gfx.inc.c"

DObjPayloadTypeI pidgey_hd_gfxdata[] = {
    { NULL, pidgey_hd_first },
    { pidgey_hd_part1_pre, pidgey_hd_part1_draw },
    { pidgey_hd_part2_pre, pidgey_hd_part2_draw },
    { NULL, pidgey_hd_part3_draw },
    { pidgey_hd_part4_pre, pidgey_hd_part4_draw },
    { NULL, pidgey_hd_part5_draw },
    { pidgey_hd_part6_pre, pidgey_hd_part6_draw },
    { pidgey_hd_part7_pre, pidgey_hd_part7_draw },
    { NULL, pidgey_hd_part8_draw },
    { pidgey_hd_part9_pre, pidgey_hd_part9_draw },
    { NULL, pidgey_hd_part10_draw },
    { NULL, pidgey_hd_part11_draw },
    { pidgey_hd_part12_pre, pidgey_hd_part12_draw },
    { NULL, pidgey_hd_part13_draw },
    { NULL, pidgey_hd_part14_draw },
};

UnkEC64Arg3 pidgey_hd_model[] = {
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
      &pidgey_hd_gfxdata[0],
      { 0.0, 138.3363037109375, -47.450008392333984 },
      { 0.1899999976158142, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pidgey_hd_gfxdata[1],
      { 0.0, -2.0051419734954834, -100.41917419433594 },
      { -0.5199999809265137, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pidgey_hd_gfxdata[2],
      { 44.577178955078125, -4.849983215332031, -5.068727016448975 },
      { 0.020850999280810356, -0.012764999642968178, -0.04415300115942955 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pidgey_hd_gfxdata[3],
      { -7.906351089477539, -63.476966857910156, -3.640397071838379 },
      { -0.38999998569488525, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pidgey_hd_gfxdata[4],
      { -44.577178955078125, -4.849983215332031, -5.068727016448975 },
      { 0.0424249991774559, -0.012834000401198864, 0.004019999876618385 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pidgey_hd_gfxdata[5],
      { 7.906346797943115, -63.476966857910156, -3.640393018722534 },
      { -0.38999998569488525, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &pidgey_hd_gfxdata[6],
      { 0.0, 37.0413703918457, 15.974145889282227 },
      { 0.8360059857368469, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pidgey_hd_gfxdata[7],
      { 0.0, 68.044677734375, 4.767518997192383 },
      { -0.1402669996023178, 0.0, 0.0 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 4,
      &pidgey_hd_gfxdata[8],
      { -9.999999974752427e-07, 63.6733283996582, 33.177703857421875 },
      { -0.8512849807739258, 0.0, 0.0 },
      { 1.0, 0.9999989867210388, 0.9999989867210388 } },
    { 3,
      &pidgey_hd_gfxdata[9],
      { 43.4669189453125, 75.26123046875, 4.019867897033691 },
      { -1.3133519887924194, -0.49281200766563416, 1.5722270011901855 },
      { 0.9999960064888, 1.0, 1.0 } },
    { 4,
      &pidgey_hd_gfxdata[10],
      { -22.13124656677246, 11.303877830505371, -54.1849250793457 },
      { -0.2199999988079071, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &pidgey_hd_gfxdata[11],
      { 4.096538066864014, -1.6917109489440918, -55.255985260009766 },
      { -0.019999999552965164, -0.09000000357627869, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &pidgey_hd_gfxdata[12],
      { -44.24760818481445, 75.2551040649414, 4.030538082122803 },
      { 1.828245997428894, -3.634406089782715, 1.5693659782409668 },
      { 0.9999960064888, 1.0, 1.0 } },
    { 4,
      &pidgey_hd_gfxdata[13],
      { 22.129627227783203, 11.514842987060547, -53.43318176269531 },
      { -3.361593008041382, -9.42477798461914, 3.1415929794311523 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &pidgey_hd_gfxdata[14],
      { -4.096531867980957, -1.6916990280151367, -55.25599670410156 },
      { -0.019999999552965164, -6.193184852600098, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
