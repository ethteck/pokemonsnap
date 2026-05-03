#include <common.h>

extern u8 smoke_puff_frame0_png[];
extern u8 smoke_puff_frame1_png[];
extern u8 smoke_puff_frame2_png[];
extern u8 smoke_puff_frame3_png[];
extern u8 smoke_puff_frame4_png[];
extern u8 smoke_puff_frame5_png[];
extern u8 smoke_puff_frame6_png[];
extern u8 smoke_puff_frame7_png[];

extern Texture* smoke_puff_part0_mat[];

extern Vtx smoke_puff_vtx[];

#include "assets/volcano/smoke_puff/draw.gfx.inc.c"
__ALIGNER
#include "assets/volcano/smoke_puff/model.vtx.inc.c"

DObjPayloadTypeC smoke_puff_gfxdata[] = {
    { 1, smoke_puff_draw },
    { 4, NULL },
};

UnkEC64Arg3 smoke_puff_model[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 0x8001,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 0x8002,
      smoke_puff_gfxdata,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

Texture** smoke_puff_materials[] = {
    NULL,
    NULL,
    smoke_puff_part0_mat,
};

u8* smoke_puff_part0_mat0_textures[] = {
    smoke_puff_frame0_png,
    smoke_puff_frame1_png,
    smoke_puff_frame2_png,
    smoke_puff_frame3_png,
    smoke_puff_frame4_png,
    smoke_puff_frame5_png,
    smoke_puff_frame6_png,
    smoke_puff_frame7_png,
    smoke_puff_frame7_png,
};

Texture smoke_puff_part0_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    smoke_puff_part0_mat0_textures,
    32,
    0,
    32,
    64,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x10,
    G_IM_FMT_IA,
    G_IM_SIZ_8b,
    32,
    64,
    32,
    64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    { 76, 0, 179, 255 },
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    255,
    0,
    0,
    0,
    8,
    { 76, 0, 179, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* smoke_puff_part0_mat[] = {
    &smoke_puff_part0_mat0,
    NULL,
};
