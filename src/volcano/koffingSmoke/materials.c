#include <common.h>

extern u8 koffingSmoke_part0_mat0_image0[];
extern u8 koffingSmoke_part0_mat0_image1[];
extern u8 koffingSmoke_part0_mat0_image2[];
extern u8 koffingSmoke_part0_mat0_image3[];
extern u8 koffingSmoke_part0_mat0_image4[];
extern u8 koffingSmoke_part0_mat0_image5[];
extern u8 koffingSmoke_part0_mat0_image6[];
extern u8 koffingSmoke_part0_mat0_image7[];
extern u8 koffingSmoke_part0_mat0_image8[];
extern u8 koffingSmoke_part0_mat0_image9[];
extern u8 koffingSmoke_part0_mat0_image10[];
extern u8 koffingSmoke_part0_mat0_image11[];

extern Texture* koffingSmoke_part0_mat[];

Texture** koffingSmoke_materials[] = {
    koffingSmoke_part0_mat,
    NULL,
};

u8* koffingSmoke_part0_mat0_images[] = {
    koffingSmoke_part0_mat0_image0,
    koffingSmoke_part0_mat0_image1,
    koffingSmoke_part0_mat0_image2,
    koffingSmoke_part0_mat0_image3,
    koffingSmoke_part0_mat0_image4,
    koffingSmoke_part0_mat0_image5,
    koffingSmoke_part0_mat0_image6,
    koffingSmoke_part0_mat0_image7,
    koffingSmoke_part0_mat0_image8,
    koffingSmoke_part0_mat0_image9,
    koffingSmoke_part0_mat0_image10,
    koffingSmoke_part0_mat0_image11,
    koffingSmoke_part0_mat0_image11,
    NULL,
};

Texture koffingSmoke_part0_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    koffingSmoke_part0_mat0_images,
    32,
    0,
    32, 64,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0xB0,
    G_IM_FMT_IA,
    G_IM_SIZ_8b,
    32, 64,
    32, 64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    76, 0, 179, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 8,
    0x4C00B300,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture* koffingSmoke_part0_mat[] = {
    &koffingSmoke_part0_mat0,
    NULL,
};
