#include "common.h"

extern u8 goldeen_tex_801750C0[];
extern u8 goldeen_tex_801756D0[];
extern u8 goldeen_tex_80175AD8[];
extern u8 goldeen_tex_80175CE0[];
extern u8 goldeen_tex_801760E8[];
extern u8 goldeen_tex_801760F8_png[];
extern u8 goldeen_tex_80176300[];
extern u8 goldeen_tex_80176338_png[];
extern u8 goldeen_tex_80176B40[];
extern u8 goldeen_tex_80176CC8_png[];
extern u8 goldeen_tex_801774D0[];
extern u8 goldeen_tex_801775C8_png[];
extern u8 goldeen_tex_801777D0[];
extern u8 goldeen_tex_801779A8_png[];
extern u8 goldeen_tex_801781B0[];
extern u8 goldeen_tex_80178228_png[];
extern u8 goldeen_tex_80178A30[];
extern u8 goldeen_tex_80179A38[];
extern u8 goldeen_tex_80179A48_png[];

extern u8 D_801760B8_valley_extra[];
extern u8 D_801766C8_valley_extra[];
extern u8 D_801766D8_valley_extra[];
extern u8 D_801768E0_valley_extra[];
extern u8 D_80176918_valley_extra[];
extern u8 D_80177120_valley_extra[];
extern u8 D_801772A8_valley_extra[];
extern u8 D_80177AB0_valley_extra[];
extern u8 D_80177BA8_valley_extra[];
extern u8 D_80177DB0_valley_extra[];
extern u8 D_80177F88_valley_extra[];
extern u8 D_80178790_valley_extra[];
extern u8 D_80178808_valley_extra[];
extern u8 D_80179010_valley_extra[];
extern u8 D_8017A018_valley_extra[];
extern u8 D_8017A028_valley_extra[];
extern u8 D_801ACE00_valley_extra[];
extern u8 D_801ACF10_tunnel_extra[];
extern u8 D_801AD020_tunnel_extra[];
extern u8 D_801AD0D0_valley_extra[];
extern u8 D_801AD0E0_tunnel_extra[];
extern u8 D_801AD0F0_valley_extra[];
extern u8 D_801AD100_river_extra[];
extern u8 D_801AD1A0_valley_extra[];
extern u8 D_801AD2B0_valley_extra[];
extern u8 D_801AD2C0_valley_extra[];
extern u8 D_801AD340_river_extra[];
extern u8 D_801AD380_river_extra[];
extern u8 D_801AD480_valley_extra[];
extern u8 D_801AD490_river_extra[];
extern u8 D_801AD4A0_river_extra[];
extern u8 D_801AD4B0_valley_extra[];
extern u8 D_801AD4D0_valley_extra[];
extern u8 D_801AD5C0_river_extra[];
extern u8 D_801AD5D0_valley_extra[];
extern u8 D_801AD5E0_valley_extra[];
extern u8 D_801AD5F0_valley_extra[];
extern u8 D_801AD690_valley_extra[];
extern u8 D_801AD6B0_valley_extra[];
extern u8 D_801AD720_valley_extra[];
extern u8 D_801AD730_valley_extra[];
extern u8 D_801AD740_valley_extra[];
extern u8 D_801AD760_valley_extra[];
extern u8 D_801AD770_tunnel_extra[];
extern u8 D_801AD780_valley_extra[];
extern u8 D_801AD790_valley_extra[];
extern u8 D_801AD7A0_valley_extra[];
extern u8 D_801AD7F0_tunnel_extra[];
extern u8 D_801AD800_valley_extra[];
extern u8 D_801AD810_valley_extra[];
extern u8 D_801AD830_valley_extra[];
extern u8 D_801AD860_valley_extra[];
extern u8 D_801AD890_river_extra[];
extern u8 D_801AD8C0_river_extra[];
extern u8 D_801AD8E0_river_extra[];
extern u8 D_801AD8F0_valley_extra[];
extern u8 D_801AD900_valley_extra[];
extern u8 D_801AD920_valley_extra[];
extern u8 D_801AD9A0_valley_extra[];
extern u8 D_801AD9C0_river_extra[];
extern u8 D_801AD9D0_valley_extra[];
extern u8 D_801AD9F0_valley_extra[];
extern u8 D_801ADA00_valley_extra[];
extern u8 D_801ADA50_tunnel_extra[];
extern u8 D_801ADA60_valley_extra[];
extern u8 D_801ADAB0_valley_extra[];
extern u8 D_801ADAC0_valley_extra[];
extern u8 D_801ADAD0_valley_extra[];
extern u8 D_801ADB80_valley_extra[];
extern u8 D_801ADC20_valley_extra[];
extern u8 D_801ADD10_valley_extra[];
extern u8 D_801ADD20_valley_extra[];
extern u8 D_801ADD30_river_extra[];
extern u8 D_801ADD40_tunnel_extra[];
extern u8 D_801ADD50_river_extra[];
extern u8 D_801ADD60_river_extra[];
extern u8 D_801ADD80_valley_extra[];
extern u8 D_801ADD90_valley_extra[];
extern u8 D_801ADDC0_valley_extra[];
extern u8 D_801ADDF0_valley_extra[];
extern u8 D_801ADE40_valley_extra[];
extern u8 D_801ADE80_valley_extra[];
extern u8 D_801ADE90_river_extra[];
extern u8 D_801ADEC0_river_extra[];
extern u8 D_801ADEF0_valley_extra[];
extern u8 D_801ADF70_valley_extra[];
extern u8 D_801AE028_valley_extra[];

extern Texture* goldeen_hd_part1_mat[];
extern Gfx goldeen_hd_part0_draw[];

Texture** goldeen_hd_materials[] = {
    NULL,
    goldeen_hd_part1_mat,
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

u8* goldeen_hd_part1_mat0_textures[] = {
    goldeen_tex_80175CE0,
    goldeen_tex_801750C0,
    goldeen_tex_801756D0,
};

u8* goldeen_hd_part1_mat1_textures[] = {
    goldeen_tex_80175CE0,
    goldeen_tex_801750C0,
    goldeen_tex_801756D0,
};

Texture goldeen_hd_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    goldeen_hd_part1_mat0_textures,
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
    { 255, 254, 254, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 254, 254, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture goldeen_hd_part1_mat1 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    goldeen_hd_part1_mat1_textures,
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
    { 255, 254, 254, 255 },
    0,
    0,
    0,
    0,
    { 0, 0, 0, 255 },
    { 0, 0, 0, 8 },
    { 255, 254, 254, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* goldeen_hd_part1_mat[] = {
    &goldeen_hd_part1_mat0,
    &goldeen_hd_part1_mat1,
    NULL,
    NULL,
};
#include "assets/valley/goldeen/hd_model.vtx.inc.c"
#include "assets/valley/goldeen/hd_first.gfx.inc.c"
#include "assets/valley/goldeen/hd_part0_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part1_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part2_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part3_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part4_pre.gfx.inc.c"
#include "assets/valley/goldeen/hd_part4_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part5_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part6_pre.gfx.inc.c"
#include "assets/valley/goldeen/hd_part6_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part7_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part8_pre.gfx.inc.c"
#include "assets/valley/goldeen/hd_part8_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part9_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part10_draw.gfx.inc.c"
#include "assets/valley/goldeen/hd_part11_draw.gfx.inc.c"

DObjPayloadTypeI goldeen_hd_gfxdata[] = {
    { NULL, goldeen_hd_first },
    { NULL, goldeen_hd_part1_draw },
    { NULL, goldeen_hd_part2_draw },
    { NULL, goldeen_hd_part3_draw },
    { goldeen_hd_part4_pre, goldeen_hd_part4_draw },
    { NULL, goldeen_hd_part5_draw },
    { goldeen_hd_part6_pre, goldeen_hd_part6_draw },
    { NULL, goldeen_hd_part7_draw },
    { goldeen_hd_part8_pre, goldeen_hd_part8_draw },
    { NULL, goldeen_hd_part9_draw },
    { NULL, goldeen_hd_part10_draw },
    { NULL, goldeen_hd_part11_draw },
};

UnkEC64Arg3 goldeen_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &goldeen_hd_gfxdata[0],
      { 0.016534000635147095, 32.4022216796875, 64.663330078125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      &goldeen_hd_gfxdata[1],
      { -3.999999989900971e-06, -34.27702331542969, -50.81420135498047 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &goldeen_hd_gfxdata[2],
      { 0.0, 4.167295932769775, -80.84548950195312 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      &goldeen_hd_gfxdata[3],
      { -0.01653200015425682, 22.09014320373535, -65.6136474609375 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &goldeen_hd_gfxdata[4],
      { 64.9417953491211, 24.487049102783203, -42.9142951965332 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &goldeen_hd_gfxdata[5],
      { 107.01005554199219, 17.12641143798828, -39.41822052001953 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &goldeen_hd_gfxdata[6],
      { 0.0, 76.70423126220703, -57.23402404785156 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &goldeen_hd_gfxdata[7],
      { -4.999999873689376e-06, 85.97408294677734, -154.43504333496094 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      &goldeen_hd_gfxdata[8],
      { -64.9417953491211, 24.487049102783203, -42.9142951965332 },
      { 0.0, 3.1415929794311523, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 6,
      &goldeen_hd_gfxdata[9],
      { 107.01005554199219, 17.12641143798828, 39.41822052001953 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &goldeen_hd_gfxdata[10],
      { 91.77922058105469, 1.727977991104126, -13.012833595275879 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      &goldeen_hd_gfxdata[11],
      { -93.98472595214844, 3.6027719974517822, -16.423694610595703 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      NULL,
      { -0.016534000635147095, -32.4022216796875, -64.663330078125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
