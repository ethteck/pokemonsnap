#include "common.h"
#include "beach.h"

void func_beach_802CA0A0(GObj* obj) {
    // TODO: see if this can be inlined
    PokemonDef sp18 = D_beach_802CD838;

    addPokemonAtGeo(obj, PokemonID_PIDGEY, &sp18);
    omEndProcess(NULL);
}

void func_beach_802CA0F4(GObj* obj) {
    // TODO: see if this can be inlined
    PokemonDef sp18 = D_beach_802CD848;

    addPokemonAtGeo(obj, PokemonID_SCYTHER, &sp18);
    omEndProcess(NULL);
}

void func_beach_802CA148(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->transitionGraph = &D_beach_802CD858;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802CA198(GObj* obj) {
    weightedRandomStaightTransition(obj, &D_beach_802CD8B8);
}

void func_beach_802CA1BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, func_beach_802CA0A0, 1, 1);
    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    // clang-format on

    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_beach_802CA23C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, func_beach_802CA0F4, 1, 1);
    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_beach_802CA2BC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CD8E4);
}
