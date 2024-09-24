#include <common.h>
#include "world/world.h"

extern SkyBox D_800FFFE0_326C60;

extern WorldBlockGFX D_80101510_328190;
extern WorldBlockGFX D_80101534_3281B4;
extern WorldBlockGFX D_80101558_3281D8;
extern WorldBlockGFX D_8010157C_3281FC;
extern WorldBlockGFX D_801015A0_328220;
extern WorldBlockGFX D_801015C4_328244;
extern WorldBlockGFX D_801015E8_328268;

s32 todo_remove = 0x80112CF8;

ObjectSpawn volcano_block0_spawn[] = {
    { PokemonID_SMOKE_SPAWNER, 0, { 26.5703, 2.19223, 10.7438 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, 0x801123AC },
    { PokemonID_RAPIDASH, 0, { 34.2705, 0.169739, 2.61987 }, { 0.0, 0.046, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_RAPIDASH, 0, { 19.1184, -0.345276, 4.54273 }, { 0.0, -0.038, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { -1, 0, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, NULL }
};

ObjectSpawn volcano_block1_spawn[] = {
    { PokemonID_VOLCANO_EFFECT, 3, { 6.31607, 2.06901, -2.76967 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_VOLCANO_EFFECT, 3, { 5.20564, 2.06901, -4.77762 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_VOLCANO_EFFECT, 3, { 7.36789, 2.06901, -4.93974 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_RAPIDASH, 1, { -22.7383, -1.58203, 7.81985 }, { 0.0, 1.004, 0.0 }, { 1.0, 1.0, 1.0 }, 0x80112578 },
    { PokemonID_RAPIDASH, 1, { -4.27519, 0.683594, 11.3401 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, 0x80112720 },
    { PokemonID_RAPIDASH, 1, { -23.4573, -1.58203, 4.48179 }, { 0.0, 1.004, 0.0 }, { 1.0, 1.0, 1.0 }, 0x80112910 },
    { -1, 0, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, NULL }
};

ObjectSpawn volcano_block2_spawn[] = {
    { PokemonID_VULPIX, 1, { 2.08328, 0.449219, 2.87712 }, { 0.0, 2.794, 0.0 }, { 1.0, 1.0, 1.0 }, 0x80112948 },
    { -1, 0, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, NULL }
};

ObjectSpawn volcano_block3_spawn[] = {
    { PokemonID_MAGMAR, 1, { -19.9109, 4.07471, 15.3729 }, { 0.0, -8.95802, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_CHARMANDER, 5, { -23.9742, 0.0, 13.7256 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, 0x80112980 },
    { PokemonID_VULPIX, 1, { 20.7217, 2.17188, -3.90524 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, 0x801129B8 },
    { PokemonID_VULPIX, 1, { 24.686, 1.57812, 3.2358 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, 0x801129F0 },
    { PokemonID_1031, 0, { -20.0, 25.0, -35.0 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { -1, 0, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, NULL }
};

ObjectSpawn volcano_block4_spawn[] = {
    { PokemonID_MAGMAR, 0, { -10.4394, 4.07471, -9.71333 }, { 0.0, -5.80801, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_MAGMAR, 0, { -6.34335, 3.71422, -12.5297 }, { 0.0, -5.606, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_MOLTRES_EGG, 0, { 4.74962, 1.5, 1.84203 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_MOLTRES, 0, { 4.58704, -2.23438, -4.88134 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, 0x80112C28 },
    { PokemonID_CHARMANDER, 1, { 1.84956, 1.15484, 7.33554 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_CHARMANDER, 2, { -4.35545, 1.52299, 0.678629 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_CHARMANDER, 3, { -10.0561, 6.64637, 17.2347 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_CHARMANDER, 3, { -12.1999, 6.64637, 17.0698 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_CHARMANDER, 4, { -10.8806, 6.64637, 14.7611 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_CHARMANDER, 4, { -12.794, 6.64637, 14.7611 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { -1, 0, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, NULL }
};

ObjectSpawn volcano_block5_spawn[] = {
    { PokemonID_GATE, 0, { 19.7892, 8.24216, 24.4197 }, { 0.0, -3.21359, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_GROWLITHE_SPAWNER, 0, { -10.3015, 2.61608, -6.84823 }, { 0.0, 1.3, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_GROWLITHE_SPAWNER, 0, { -5.66958, 2.83189, -20.8215 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_GROWLITHE_SPAWNER, 0, { -11.0348, 2.81804, -13.4768 }, { 0.0, 0.528, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { PokemonID_CHARMELEON, 0, { 14.247, 5.14299, -0.895836 }, { 0.0, 0.0, 0.0 }, { 1.0, 1.0, 1.0 }, 0x80112DAC },
    { PokemonID_EVOLUTION_CONTROLLER, 0, { 10.8459, 3.85002, 1.70108 }, { 0.0, -1.9, 0.0 }, { 1.0, 1.0, 1.0 }, NULL },
    { -1, 0, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, NULL }
};

StaticObject volcano_block5_staticObjects[] = {
    { PokemonID_GATE, { 19.789238, 8.242157, 24.419727 }, { 0.0, -3.213589, 0.0 }, { 1.0, 1.0, 1.0 } },
    { -1, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } }
};

WorldBlockDescriptor volcano_block0 = {
    &D_80101510_328190,
    { 0.0, 0.0, 0.0 },
    0.0,
    0,
    NULL,
    volcano_block0_spawn,
    NULL,
};

WorldBlockDescriptor volcano_block1 = {
    &D_80101534_3281B4,
    { 20.0, 0.0, 15.0 },
    0.0,
    0,
    NULL,
    volcano_block1_spawn,
    NULL,
};

WorldBlockDescriptor volcano_block2 = {
    &D_80101558_3281D8,
    { 10.0, 0.0, 35.0 },
    0.0,
    0,
    NULL,
    volcano_block2_spawn,
    NULL,
};

WorldBlockDescriptor volcano_block3 = {
    &D_8010157C_3281FC,
    { -25.0, 0.0, 20.0 },
    0.0,
    0,
    NULL,
    volcano_block3_spawn,
    NULL,
};

WorldBlockDescriptor volcano_block4 = {
    &D_801015A0_328220,
    { -70.0, 0.0, 10.0 },
    0.0,
    0,
    NULL,
    volcano_block4_spawn,
    NULL,
};

WorldBlockDescriptor volcano_block5 = {
    &D_801015C4_328244,
    { -100.0, 0.0, 30.0 },
    0.0,
    0,
    NULL,
    volcano_block5_spawn,
    volcano_block5_staticObjects,
};

WorldBlockDescriptor volcano_uvBlock0 = {
    &D_801015E8_328268,
    { -45.0, 0.0, -10.0 },
    0.0,
    0,
    NULL,
    NULL,
    NULL,
};

WorldBlockDescriptor* volcano_modelBlocks[] = {
    &volcano_block0,
    &volcano_block1,
    &volcano_block2,
    &volcano_block3,
    &volcano_block4,
    &volcano_block5,
    NULL,
};

WorldBlockDescriptor* volcano_uvScrollBlocks[] = {
    &volcano_uvBlock0,
    NULL,
};

WorldBlockSetup volcano_blocksSetup = {
    volcano_modelBlocks,
    volcano_uvScrollBlocks,
    &D_800FFFE0_326C60,
};
