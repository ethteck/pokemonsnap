#include "world/world.h"

extern Gfx tunnel_block0_gfx_data[];
extern UnkEC64Arg3 tunnel_block0_road[];
extern AnimCmd* tunnel_block0_movement[];

extern Gfx tunnel_block1_gfx_data[];
extern UnkEC64Arg3 tunnel_block1_road[];
extern AnimCmd* tunnel_block1_movement[];

extern Gfx tunnel_block2_gfx_data[];
extern Texture** tunnel_block2_materials[];
extern AnimCmd** tunnel_block2_uvAnim[];
extern UnkEC64Arg3 tunnel_block2_road[];
extern AnimCmd* tunnel_block2_movement[];

extern Gfx tunnel_block3_gfx_data[];
extern UnkEC64Arg3 tunnel_block3_road[];
extern AnimCmd* tunnel_block3_movement[];

extern Gfx tunnel_block4_gfx_data[];
extern UnkEC64Arg3 tunnel_block4_road[];
extern AnimCmd* tunnel_block4_movement[];

extern Gfx tunnel_block5_gfx_data[];
extern UnkEC64Arg3 tunnel_block5_road[];
extern AnimCmd* tunnel_block5_movement[];

WorldBlockGFX tunnel_block0_gfx = {
    tunnel_block0_gfx_data,
    NULL,
    NULL,
    renderModelTypeAFogged,
    tunnel_block0_road,
    3,
    tunnel_block0_movement,
    100,
    { 0.0f }
};

WorldBlockGFX tunnel_block1_gfx = {
    tunnel_block1_gfx_data,
    NULL,
    NULL,
    renderModelTypeAFogged,
    tunnel_block1_road,
    3,
    tunnel_block1_movement,
    100,
    { 0.0f }
};

WorldBlockGFX tunnel_block2_gfx = {
    tunnel_block2_gfx_data,
    tunnel_block2_materials,
    tunnel_block2_uvAnim,
    renderModelTypeAFogged,
    tunnel_block2_road,
    3,
    tunnel_block2_movement,
    100,
    { 0.0f }
};

WorldBlockGFX tunnel_block3_gfx = {
    tunnel_block3_gfx_data,
    NULL,
    NULL,
    renderModelTypeAFogged,
    tunnel_block3_road,
    3,
    tunnel_block3_movement,
    100,
    { 0.0f }
};

WorldBlockGFX tunnel_block4_gfx = {
    tunnel_block4_gfx_data,
    NULL,
    NULL,
    renderModelTypeAFogged,
    tunnel_block4_road,
    3,
    tunnel_block4_movement,
    100,
    { 0.0f }
};

WorldBlockGFX tunnel_block5_gfx = {
    tunnel_block5_gfx_data,
    NULL,
    NULL,
    renderModelTypeAFogged,
    tunnel_block5_road,
    3,
    tunnel_block5_movement,
    100,
    { 0.0f }
};
