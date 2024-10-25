#include <common.h>

extern u8 volcano_effect_frame0_png[];
extern u8 volcano_effect_frame1_png[];
extern u8 volcano_effect_frame2_png[];

extern Texture* volcano_effect_part0_mat[];
extern Texture* volcano_effect_part1_mat[];

Texture** volcano_effect_materials[] = {
    NULL,
    volcano_effect_part0_mat,
    volcano_effect_part1_mat,
};

u8* volcano_effect_part0_mat0_textures[] = {
    volcano_effect_frame0_png,
    volcano_effect_frame1_png,
    volcano_effect_frame2_png,
    volcano_effect_frame2_png,
};

u8* volcano_effect_part1_mat0_textures[] = {
    volcano_effect_frame0_png,
    volcano_effect_frame1_png,
    volcano_effect_frame2_png,
    volcano_effect_frame2_png,
    NULL,
};

Texture volcano_effect_part0_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_32b,
    volcano_effect_part0_mat0_textures,
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

Texture volcano_effect_part1_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_32b,
    volcano_effect_part1_mat0_textures,
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

Texture* volcano_effect_part0_mat[] = {
    &volcano_effect_part0_mat0,
    NULL,
};

Texture* volcano_effect_part1_mat[] = {
    &volcano_effect_part1_mat0,
    NULL,
};
