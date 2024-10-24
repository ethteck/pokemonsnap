#include <common.h>

extern u8 koffing_smoke_frame0_png[];
extern u8 koffing_smoke_frame1_png[];
extern u8 koffing_smoke_frame2_png[];
extern u8 koffing_smoke_frame3_png[];
extern u8 koffing_smoke_frame4_png[];
extern u8 koffing_smoke_frame5_png[];
extern u8 koffing_smoke_frame6_png[];
extern u8 koffing_smoke_frame7_png[];
extern u8 koffing_smoke_frame8_png[];
extern u8 koffing_smoke_frame9_png[];
extern u8 koffing_smoke_frame10_png[];
extern u8 koffing_smoke_frame11_png[];

extern Texture* koffing_smoke_part0_mat[];

Texture** koffing_smoke_materials[] = {
    koffing_smoke_part0_mat,
    NULL,
};

u8* koffing_smoke_part0_mat0_textures[] = {
    koffing_smoke_frame0_png,
    koffing_smoke_frame1_png,
    koffing_smoke_frame2_png,
    koffing_smoke_frame3_png,
    koffing_smoke_frame4_png,
    koffing_smoke_frame5_png,
    koffing_smoke_frame6_png,
    koffing_smoke_frame7_png,
    koffing_smoke_frame8_png,
    koffing_smoke_frame9_png,
    koffing_smoke_frame10_png,
    koffing_smoke_frame11_png,
    koffing_smoke_frame11_png,
    NULL,
};

Texture koffing_smoke_part0_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    koffing_smoke_part0_mat0_textures,
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
    0xB0,
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

Texture* koffing_smoke_part0_mat[] = {
    &koffing_smoke_part0_mat0,
    NULL,
};
