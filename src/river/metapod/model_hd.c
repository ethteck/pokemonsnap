#include "common.h"

extern u8 metapod_tex_80184228[];
extern u8 metapod_tex_80184250_png[];
extern u8 metapod_tex_80184458[];
extern u8 metapod_tex_80184468_png[];
extern u8 metapod_tex_80184570[];
extern u8 metapod_tex_80184580_png[];
extern u8 metapod_tex_80184788[];
extern u8 metapod_tex_801847B0[];
extern u8 metapod_tex_80184BB8[];
extern u8 metapod_tex_80184BC8_png[];
extern u8 metapod_tex_80184DD0[];
extern u8 metapod_tex_80184DE0_png[];

extern u8 D_80184808_river_extra[];
extern u8 D_80184830_river_extra[];
extern u8 D_80184A38_river_extra[];
extern u8 D_80184A48_river_extra[];
extern u8 D_80184B50_river_extra[];
extern u8 D_80184B60_river_extra[];
extern u8 D_80184D68_river_extra[];
extern u8 D_80185198_river_extra[];
extern u8 D_801851A8_river_extra[];
extern u8 D_801853B0_river_extra[];
extern u8 D_801853C0_river_extra[];
extern u8 D_801AD090_tunnel_extra[];
extern u8 D_801AD100_river_extra[];
extern u8 D_801AD200_river_extra[];
extern u8 D_801AD210_river_extra[];
extern u8 D_801AD220_river_extra[];
extern u8 D_801AD230_river_extra[];
extern u8 D_801AD2E0_river_extra[];
extern u8 D_801AD2F0_river_extra[];
extern u8 D_801AD310_river_extra[];
extern u8 D_801AD320_river_extra[];
extern u8 D_801AD330_river_extra[];
extern u8 D_801AD340_river_extra[];
extern u8 D_801AD350_river_extra[];
extern u8 D_801AD380_river_extra[];
extern u8 D_801AD390_river_extra[];
extern u8 D_801AD3A0_river_extra[];
extern u8 D_801AD3E0_river_extra[];
extern u8 D_801AD400_river_extra[];
extern u8 D_801AD440_river_extra[];
extern u8 D_801AD450_river_extra[];
extern u8 D_801AD460_river_extra[];
extern u8 D_801AD490_river_extra[];
extern u8 D_801AD4A0_river_extra[];
extern u8 D_801AD510_river_extra[];
extern u8 D_801AD550_river_extra[];
extern u8 D_801AD5A0_river_extra[];
extern u8 D_801AD5C0_river_extra[];
extern u8 D_801AD610_river_extra[];
extern u8 D_801AD640_river_extra[];
extern u8 D_801AD650_river_extra[];
extern u8 D_801AD660_river_extra[];
extern u8 D_801AD670_tunnel_extra[];
extern u8 D_801AD6C0_river_extra[];
extern u8 D_801AD6F0_river_extra[];
extern u8 D_801AD7F0_tunnel_extra[];
extern u8 D_801AD880_river_extra[];
extern u8 D_801AD890_river_extra[];
extern u8 D_801AD8C0_river_extra[];
extern u8 D_801AD8E0_river_extra[];
extern u8 D_801AD9C0_river_extra[];
extern u8 D_801ADB20_tunnel_extra[];
extern u8 D_801ADB30_river_extra[];
extern u8 D_801ADBB0_river_extra[];
extern u8 D_801ADC50_tunnel_extra[];
extern u8 D_801ADC70_river_extra[];
extern u8 D_801ADC80_river_extra[];
extern u8 D_801ADCB0_river_extra[];
extern u8 D_801ADD30_river_extra[];
extern u8 D_801ADD50_river_extra[];
extern u8 D_801ADD60_river_extra[];
extern u8 D_801ADD70_river_extra[];
extern u8 D_801ADDB0_river_extra[];
extern u8 D_801ADE90_river_extra[];
extern u8 D_801ADEA0_river_extra[];
extern u8 D_801ADEC0_river_extra[];
extern u8 D_801ADFA0_river_extra[];
extern u8 D_801ADFB0_river_extra[];
extern u8 D_801AE0B0_river_extra[];
extern u8 D_801AE1E0_tunnel_extra[];
extern u8 D_801AE340_river_extra[];

extern Texture* metapod_hd_part1_mat[];
extern Gfx metapod_hd_part0_draw[];

Texture** metapod_hd_materials[] = {
    NULL,
    metapod_hd_part1_mat,
    NULL,
    NULL,
    NULL,
    NULL,
};

u8* metapod_hd_part1_mat0_textures[] = {
    metapod_tex_801847B0,
    NULL,
};

Texture metapod_hd_part1_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    metapod_hd_part1_mat0_textures,
    32,
    114,
    4,
    128,
    0,
    0.0,
    0.7988939881324768,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    4,
    128,
    4,
    128,
    0.0,
    0.7988939881324768,
    0.0,
    { 0, 0, 0, 0 },
    74245,
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

Texture* metapod_hd_part1_mat[] = {
    &metapod_hd_part1_mat0,
    NULL,
};
#include "assets/river/metapod/hd_model.vtx.inc.c"
#include "assets/river/metapod/hd_first.gfx.inc.c"
#include "assets/river/metapod/hd_part0_draw.gfx.inc.c"
#include "assets/river/metapod/hd_part1_draw.gfx.inc.c"
#include "assets/river/metapod/hd_part2_draw.gfx.inc.c"
#include "assets/river/metapod/hd_part3_draw.gfx.inc.c"
#include "assets/river/metapod/hd_part4_draw.gfx.inc.c"

UnkEC64Arg3 metapod_hd_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 8193,
      metapod_hd_first,
      { 0.0, 712.6742553710938, 72.1060791015625 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 2,
      metapod_hd_part1_draw,
      { 0.0, -0.004244000185281038, 0.0039160000160336494 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 3,
      metapod_hd_part2_draw,
      { 0.0, -390.90997314453125, 24.6300048828125 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 4,
      metapod_hd_part3_draw,
      { 0.0, -107.6243667602539, -161.07260131835938 },
      { 0.17453299462795258, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 5,
      metapod_hd_part4_draw,
      { 0.0, -91.35403442382812, -62.30620193481445 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
