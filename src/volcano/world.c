#include <common.h>
#include "world/world.h"

extern WorldBlockSetup volcano_blocksSetup[];

CollisionModel volcano_collisionModels[] = {
    { PokemonID_GATE, D_800EDF78, 1.0 },
    { -1, NULL, 0 }
};

WorldSetup volcano_WorldSetup = {
    volcano_blocksSetup,
    NULL,
    0,
    volcano_collisionModels,
    0.4f,
    989,
    1000,
    121,
    77,
    23,
    150,
    90,
    57,
};

void volcano_stub() {
}
