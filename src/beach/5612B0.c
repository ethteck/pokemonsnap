#include "common.h"
#include "beach.h"

void func_beach_802C9240(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    D_beach_802CD3F4 = pokemon->path;
    updatePokemonState(obj, func_beach_802C9274);
}

void func_beach_802C9274(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 0x200;
    runPathProcess(obj, func_beach_802C9348);
    updatePokemonState(obj, func_beach_802C92BC);
}

void func_beach_802C92BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_20;
    pokemon->flags |= 8;
    func_80360144_500554(obj, 0.5f);

    setPokemonAnimation(obj, &D_beach_802CD2A8);
    pokemon->transitionGraph = &D_beach_802CD3F8;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, func_beach_802C92BC);
}

void func_beach_802C9348(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 0, 0.05f, 0.0f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C93B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // TODO: potentially include data
    idFuncStruct sp18[4] = D_beach_802CD438;

    pokemon->transitionGraph = sp18;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_20;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/5612B0/func_beach_802C943C.s")

void func_beach_802C94F0(GObj* obj) {
    f32 var_f20;

    var_f20 = 0.5f;
    while (var_f20 < 1.0f) {
        var_f20 += 0.016666668f;
        func_80360144_500554(obj, var_f20);
        ohWait(1);
    }
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C9580(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD2E4);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_beach_802CD35C;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CD3DC);
}

void func_beach_802C95F0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD2F8);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_beach_802C9694);
    pokemon->transitionGraph = &D_beach_802CD35C;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1 | POKEMON_PROCESS_FLAG_2);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_2) {
        updatePokemonState(obj, func_beach_802C9580);
    }
    weightedRandomStaightTransition(obj, &D_beach_802CD3DC);
}

void func_beach_802C9694(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 30.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C96F0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD30C);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_beach_802CD478;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802C9580);
}

void func_beach_802C9760(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD320);
    runPathProcess(obj, func_beach_802C97D4);
    pokemon->transitionGraph = &D_beach_802CD4A8;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_2);
    updatePokemonState(obj, func_beach_802C9580);
}

void func_beach_802C97D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C9830(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD2F8);
    runPathProcess(obj, func_beach_802C98F4);
    pokemon->transitionGraph = &D_beach_802CD4E8;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_2);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_10)) {
        updatePokemonState(obj, func_beach_802C9580);
    }
    setPokemonAnimation(obj, &D_beach_802CD334);
    pokemon->transitionGraph = &D_beach_802CD4E8;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CD3DC);
}

void func_beach_802C98F4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0);
    setPokemonAnimation(obj, &D_beach_802CD320);
    pokemon->hSpeed = 80.0f;
    func_80361748_501B58(obj, 100.0f, 0.1f, 3);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802C9978(GObj* obj) {
    updatePokemonState(obj, func_beach_802C9830);
}

void func_beach_802C999C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CD2BC);
    runPathProcess(obj, func_beach_802C9A10);
    pokemon->transitionGraph = &D_beach_802CD518;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_2);
    updatePokemonState(obj, func_beach_802C9580);
}

void func_beach_802C9A10(GObj* obj) {
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

void func_beach_802C9A7C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CD55C);
}
