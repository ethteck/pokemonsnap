#include "common.h"
#include "beach.h"

void func_beach_802C82B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    obj->flags |= GOBJ_FLAG_HIDDEN;
    runPathProcess(obj, func_beach_802C8438);
    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    pokemon->processFlags |= 0x20;
    pokemon->transitionGraph = &D_beach_802CCF44;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C8354(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 0x200;
    obj->flags = 0;
    pokemon->processFlags &= ~0x20;
    setPokemonAnimation(obj, &D_beach_802CCF00);
    pokemon->transitionGraph = &D_beach_802CCF14;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C83D0);
}

void func_beach_802C83D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CCEB0);
    pokemon->transitionGraph = &D_beach_802CCF14;
    runInteractionsAndWaitForFlags(obj, 2);
    runPokemonCleanup(obj);
    updatePokemonState(obj, 0);
}

void func_beach_802C8438(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1.0f, 0.1f, 0.0f, 3);
    pokemon->pathProcess = 0;
    pokemon->processFlags |= 2;
    omEndProcess(0);
}

void func_beach_802C84A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= 0x20;
    setPokemonAnimation(obj, &D_beach_802CCEC4);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CCED8);
    // clang-format off
    pokemon->counter = 120; pokemon->processFlags &= ~4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 4);
    setPokemonAnimation(obj, &D_beach_802CCEEC);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    pokemon->processFlags &= ~0x20;
    updatePokemonState(obj, func_beach_802C83D0);
}

void func_beach_802C8570(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CCF78);
}
