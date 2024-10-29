#include <common.h>

extern u8 lava_splash_frame0_png[];
extern u8 lava_splash_frame1_png[];
extern u8 lava_splash_frame2_png[];

extern Texture* lava_splash_part0_mat[];
extern Texture* lava_splash_part1_mat[];

Texture** lava_splash_materials[] = {
    NULL,
    lava_splash_part0_mat,
    lava_splash_part1_mat,
};

u8* lava_splash_part0_mat0_textures[] = {
    lava_splash_frame0_png,
    lava_splash_frame1_png,
    lava_splash_frame2_png,
    lava_splash_frame2_png,
};

u8* lava_splash_part1_mat0_textures[] = {
    lava_splash_frame0_png,
    lava_splash_frame1_png,
    lava_splash_frame2_png,
    lava_splash_frame2_png,
    NULL,
};

Texture lava_splash_part0_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_32b,
    lava_splash_part0_mat0_textures,
    32,
    0,
    16,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xF3,
    G_IM_FMT_RGBA,
    G_IM_SIZ_32b,
    16,
    32,
    16,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    { 255, 255, 255, 255 },
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture lava_splash_part1_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_32b,
    lava_splash_part1_mat0_textures,
    32,
    0,
    16,
    32,
    0,
    0.0,
    0.0,
    1.0,
    1.0,
    0.0,
    1.0,
    NULL,
    0xF3,
    G_IM_FMT_RGBA,
    G_IM_SIZ_32b,
    16,
    32,
    16,
    32,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    74245,
    { 255, 255, 255, 255 },
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
    { 255, 255, 255, 0 },
    { 38, 38, 38, 0 },
    0,
    0,
    0,
    0,
};

Texture* lava_splash_part0_mat[] = {
    &lava_splash_part0_mat0,
    NULL,
};

Texture* lava_splash_part1_mat[] = {
    &lava_splash_part1_mat0,
    NULL,
};
