#include "common.h"
#include "beach.h"

void func_beach_802C8DB0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field0 = pokemon->collisionRadius;
    pokemon->collisionRadius = 0;
    updatePokemonState(obj, func_beach_802C8DE8);
}

void func_beach_802C8DE8(GObj* obj) {
    runPathProcess(obj, func_beach_802C8E20);
    updatePokemonState(obj, func_beach_802C8E90);
}

void func_beach_802C8E20(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 0, 0.1f, 0.0f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C8E90.s")

void func_beach_802C8F48(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    obj->flags = 0;
    runPathProcess(obj, func_beach_802C907C);
    setPokemonAnimation(obj, &D_beach_802CD168);
    pokemon->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    setPokemonAnimation(obj, &D_beach_802CD1A4);
    pokemon->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_2);
    setPokemonAnimation(obj, &D_beach_802CD190);
    pokemon->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    cmdSendCommandToLink(3, 0x1E, obj);
    setPokemonAnimation(obj, &D_beach_802CD17C);
    pokemon->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_2);
    runPathProcess(obj, func_beach_802C90E0);
    pokemon->transitionGraph = &D_beach_802CD214;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_2);
    runPokemonCleanup(obj);
    updatePokemonState(obj, func_beach_802C8F48);
}

void func_beach_802C907C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 100.0f;
    func_80360300_500710(obj, 150.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C90E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (FALSE) {
    }

    pokemon->hSpeed = 200.0f;
    pokemon->jumpVel = 90.0f;
    func_80360300_500710(obj, 2000.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C914C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (FALSE) {
    }

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 150.0f;
    func_80360590_5009A0(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    pokemon->jumpVel = 150.0f;
    func_80360300_500710(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C91CC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}

void func_beach_802C9204(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}
