#include "common.h"
#include "beach.h"

void func_beach_802C9AC0(GObj* obj) {
    updatePokemonState(obj, func_beach_802C9AE4);
}

void func_beach_802C9AE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD5A8);
    pokemon->transitionGraph = &D_beach_802CD694;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CD774);
}

void func_beach_802C9B40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD5BC);
    pokemon->transitionGraph = &D_beach_802CD694;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CD774);
}

void func_beach_802C9B9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD60C);
    pokemon->transitionGraph = &D_beach_802CD694;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CD774);
}

void func_beach_802C9BF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD5F8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    runPathProcess(obj, func_beach_802C9C88);
    setPokemonAnimation(obj, &D_beach_802CD5D0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_2);
    updatePokemonState(obj, func_beach_802C9F9C);
}

void func_beach_802C9C88(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon = pokemon;
    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0.0f, 1.0f, 0.05f, 0.1f, 0x80 | 0x1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C9CF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD5A8);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_beach_802CD634;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CD764);
}

void func_beach_802C9D68() {
}

void func_beach_802C9D70(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C9DCC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, NULL);
    setPokemonAnimation(obj, &D_beach_802CD5F8);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    runPathProcess(obj, func_beach_802C9E70);
    setPokemonAnimation(obj, &D_beach_802CD5E4);
    pokemon->transitionGraph = &D_beach_802CD6C4;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802C9CF8);
}

void func_beach_802C9E70(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C9EBC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD620);
    runPathProcess(obj, func_beach_802C9F30);
    pokemon->transitionGraph = &D_beach_802CD6F4;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_2);
    updatePokemonState(obj, func_beach_802C9CF8);
}

void func_beach_802C9F30(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (1) {
        if (!func_80361440_501850(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    pokemon->pathProcess = NULL;
    omEndProcess(NULL);
}

void func_beach_802C9F9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, func_beach_802CA010);
    setPokemonAnimation(obj, &D_beach_802CD5E4);
    pokemon->transitionGraph = &D_beach_802CD6C4;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CD764);
}

void func_beach_802CA010(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802CA05C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CD7A8);
}
