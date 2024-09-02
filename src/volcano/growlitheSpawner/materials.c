#include <common.h>

extern u8 growlitheSpawner_lava_frame0_png[];
extern u8 growlitheSpawner_lava_frame1_png[];
extern u8 growlitheSpawner_lava_frame2_png[];
extern u8 growlitheSpawner_lava_frame3_png[];
extern u8 growlitheSpawner_lava_frame4_png[];

extern Texture* growlitheSpawner_part0_mat[];

Texture** growlitheSpawner_materials[] = {
    NULL,
    growlitheSpawner_part0_mat,
};

u8* growlitheSpawner_part0_mat0_images[] = {
    growlitheSpawner_lava_frame0_png,
    growlitheSpawner_lava_frame1_png,
    growlitheSpawner_lava_frame2_png,
    growlitheSpawner_lava_frame3_png,
    growlitheSpawner_lava_frame4_png,
    NULL,
};

Texture growlitheSpawner_part0_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    growlitheSpawner_part0_mat0_images,
    32,
    0,
    64, 64,
    0,
    0.0, 0.0,
    1.0, 1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64, 64,
    64, 64,
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

Texture* growlitheSpawner_part0_mat[] = {
    &growlitheSpawner_part0_mat0,
    NULL,
};
