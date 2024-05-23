#include "common.h"
#include "world/world.h"

void spawnStaryuAtGeo(GObj* obj) {
    addPokemonAtGeo(obj, PokemonID_STARYU, &extraStaryuDef);
    omEndProcess(NULL);
}

void spawnStarmieAtGeo(GObj* obj) {
    addPokemonAtGeo(obj, PokemonID_STARMIE, &extraStarmieDef);
    omEndProcess(NULL);
}

void func_802D25E0(GObj* obj) {
    weightedRandomStaightTransition(obj, &D_802ECB00_7C6090);
}

void func_802D2604(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, spawnStaryuAtGeo, 1, 1);

    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_802D2684(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, spawnStarmieAtGeo, 1, 1);
    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_802D2704(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_802ECB2C_7C60BC);
}
