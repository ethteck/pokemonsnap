#include "valley.h"

POKEMON_FUNC(spawnStaryuAtGeo)
    Pokemon_AddAtGeo(obj, PokemonID_STARYU, &extraStaryuDef);
    omEndProcess(NULL);
}

POKEMON_FUNC(spawnStarmieAtGeo)
    Pokemon_AddAtGeo(obj, PokemonID_STARMIE, &extraStarmieDef);
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D25E0)
    Pokemon_SetStateRandom(obj, D_802ECB00_7C6090);
}

POKEMON_FUNC(func_802D2604)
    omCreateProcess(obj, spawnStaryuAtGeo, 1, 1);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D2684)
    omCreateProcess(obj, spawnStarmieAtGeo, 1, 1);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802D2704(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802ECB2C_7C60BC);
}
