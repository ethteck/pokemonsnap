#include <common.h>

extern u8 growlithe_spawner_lava_frame0_png[];
extern u8 growlithe_spawner_lava_frame1_png[];
extern u8 growlithe_spawner_lava_frame2_png[];
extern u8 growlithe_spawner_lava_frame3_png[];
extern u8 growlithe_spawner_lava_frame4_png[];

extern Texture* growlithe_spawner_part0_mat[];

Texture** growlithe_spawner_materials[] = {
    NULL,
    growlithe_spawner_part0_mat,
};

u8* growlithe_spawner_part0_mat0_textures[] = {
    growlithe_spawner_lava_frame0_png,
    growlithe_spawner_lava_frame1_png,
    growlithe_spawner_lava_frame2_png,
    growlithe_spawner_lava_frame3_png,
    growlithe_spawner_lava_frame4_png,
    NULL,
};

Texture growlithe_spawner_part0_mat0 = {
    0,
    G_IM_FMT_CI,
    G_IM_SIZ_16b,
    growlithe_spawner_part0_mat0_textures,
    32,
    0,
    64,
    64,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0x1,
    G_IM_FMT_CI,
    G_IM_SIZ_4b,
    64,
    64,
    64,
    64,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    { 76,
      0,
      179,
      255 },
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

Texture* growlithe_spawner_part0_mat[] = {
    &growlithe_spawner_part0_mat0,
    NULL,
};
