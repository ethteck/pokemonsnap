#include <common.h>

extern u8 gate_tex3_png[];
extern u8 gate_tex4_png[];

extern Texture* gate_part1_mat[];
extern Texture* gate_part2_mat[];
extern Texture* gate_part3_mat[];

Texture** gate_materials[] = {
    NULL,
    gate_part1_mat,
    gate_part2_mat,
    gate_part3_mat,    
};

u8* gate_part1_mat0_textures[] = {
    gate_tex4_png,
};

u8* gate_part2_mat0_textures[] = {
    gate_tex3_png,
};

Texture gate_part1_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    gate_part1_mat0_textures,
    32,
    256,
    256,
    16,
    0,
    0.0,
    0.0,
    2.0,
    1.0,
    0.0,
    2.0,
    NULL,
    0xA1,
    G_IM_FMT_IA,
    G_IM_SIZ_8b,
    128,
    16,
    256,
    16,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    255,
    255,
    255,
    255,
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
    0xB3B3B300,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture gate_part2_mat0 = {
    0,
    G_IM_FMT_IA,
    G_IM_SIZ_16b,
    gate_part2_mat0_textures,
    32,
    128,
    64,
    128,
    0,
    0.0,
    -1.0,
    1.0,
    2.0,
    0.0,
    1.0,
    NULL,
    0xA1,
    G_IM_FMT_IA,
    G_IM_SIZ_8b,
    64,
    64,
    64,
    128,
    0.0,
    -1.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    255,
    255,
    255,
    255,
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
    0xFFFFFF00,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture gate_part3_mat0 = {
    0,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    NULL,
    0,
    0,
    0,
    0,
    0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    0.0,
    NULL,
    0x200,
    G_IM_FMT_RGBA,
    G_IM_SIZ_16b,
    0,
    0,
    0,
    0,
    0.0,
    0.0,
    0.0,
    { 0, 0, 0, 0 },
    8709,
    102,
    0,
    102,
    255,
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
    0xFFFFFF00,
    0x26262600,
    0,
    0,
    0,
    0,
};

Texture* gate_part1_mat[] = {
    &gate_part1_mat0,
    NULL,
};

Texture* gate_part2_mat[] = {
    &gate_part2_mat0,
    NULL,
};

Texture* gate_part3_mat[] = {
    &gate_part3_mat0,
    NULL,
};
