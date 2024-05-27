#include "common.h"
#include "world/world.h"

void spawnStaryuAtGeo(GObj* obj) {
    Pokemon_AddAtGeo(obj, PokemonID_STARYU, &extraStaryuDef);
    omEndProcess(NULL);
}

void spawnStarmieAtGeo(GObj* obj) {
    Pokemon_AddAtGeo(obj, PokemonID_STARMIE, &extraStarmieDef);
    omEndProcess(NULL);
}

void func_802D25E0(GObj* obj) {
    Pokemon_SetStateRandom(obj, &D_802ECB00_7C6090);
}

void func_802D2604(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, spawnStaryuAtGeo, 1, 1);

    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_4);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802D2684(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, spawnStarmieAtGeo, 1, 1);
    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_4);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802D2704(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802ECB2C_7C60BC);
}
