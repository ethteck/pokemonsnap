#include "world/world.h"

extern Gfx volcano_block0_gfx_data[];
extern Texture** volcano_block0_materials[];
extern AnimCmd** volcano_block0_uvAnim[];
extern UnkEC64Arg3 volcano_block0_road[];
extern AnimCmd* volcano_block0_movement[];

extern Gfx volcano_block1_gfx_data[];
extern Texture** volcano_block1_materials[];
extern AnimCmd** volcano_block1_uvAnim[];
extern UnkEC64Arg3 volcano_block1_road[];
extern AnimCmd* volcano_block1_movement[];

extern Gfx volcano_block2_gfx_data[];
extern UnkEC64Arg3 volcano_block2_road[];
extern AnimCmd* volcano_block2_movement[];

extern Gfx volcano_block3_gfx_data[];
extern Texture** volcano_block3_materials[];
extern AnimCmd** volcano_block3_uvAnim[];
extern UnkEC64Arg3 volcano_block3_road[];
extern AnimCmd* volcano_block3_movement[];

extern Gfx volcano_block4_gfx_data[];
extern Texture** volcano_block4_materials[];
extern AnimCmd** volcano_block4_uvAnim[];
extern UnkEC64Arg3 volcano_block4_road[];
extern AnimCmd* volcano_block4_movement[];

extern Gfx volcano_block5_gfx_data[];
extern Texture** volcano_block5_materials[];
extern AnimCmd** volcano_block5_uvAnim[];
extern UnkEC64Arg3 volcano_block5_road[];
extern AnimCmd* volcano_block5_movement[];

extern Gfx volcano_block6_gfx_data[];
extern Texture** volcano_block6_materials[];
extern AnimCmd** volcano_block6_uvAnim[];

WorldBlockGFX volcano_block0_gfx = {
    volcano_block0_gfx_data,
    volcano_block0_materials,
    volcano_block0_uvAnim,
    renderModelTypeAFogged,
    volcano_block0_road,
    3,
    volcano_block0_movement,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block1_gfx = {
    volcano_block1_gfx_data,
    volcano_block1_materials,
    volcano_block1_uvAnim,
    renderModelTypeAFogged,
    volcano_block1_road,
    3,
    volcano_block1_movement,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block2_gfx = {
    volcano_block2_gfx_data,
    NULL,
    NULL,
    renderModelTypeAFogged,
    volcano_block2_road,
    3,
    volcano_block2_movement,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block3_gfx = {
    volcano_block3_gfx_data,
    volcano_block3_materials,
    volcano_block3_uvAnim,
    renderModelTypeAFogged,
    volcano_block3_road,
    3,
    volcano_block3_movement,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block4_gfx = {
    volcano_block4_gfx_data,
    volcano_block4_materials,
    volcano_block4_uvAnim,
    renderModelTypeAFogged,
    volcano_block4_road,
    3,
    volcano_block4_movement,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block5_gfx = {
    volcano_block5_gfx_data,
    volcano_block5_materials,
    volcano_block5_uvAnim,
    renderModelTypeAFogged,
    volcano_block5_road,
    3,
    volcano_block5_movement,
    100,
    { 0.0f }
};

WorldBlockGFX volcano_block6_gfx = {
    volcano_block6_gfx_data,
    volcano_block6_materials,
    volcano_block6_uvAnim,
    renderModelTypeAFogged,
    NULL,
    0,
    NULL,
    0,
    { 0.0f }
};
