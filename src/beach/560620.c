#include "common.h"
#include "beach.h"

void func_beach_802C85B0(GObj* arg0) {
    arg0->flags |= 1;
    updatePokemonState(arg0, func_beach_802C85E0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560620/func_beach_802C85E0.s")

void func_beach_802C86A8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        updatePokemonState(obj, func_beach_802C8980);
    }

    obj->flags = 0;
    pokemon->processFlags &= ~0x20;
    setPokemonAnimation(obj, &D_beach_802CCFC0);
    pokemon->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CCFD4);
    pokemon->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 2);
    setPokemonAnimation(obj, &D_beach_802CCFE8);
    pokemon->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CCFFC);
    pokemon->pokemonLoopTarget = 1;
    pokemon->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C8828);
}

void func_beach_802C87BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.033333335f, 0.0f, 2);

    pokemon->pathProcess = 0;
    pokemon->processFlags |= 2;
    omEndProcess(0);
}

void func_beach_802C8828(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->field_0x10e = 0;
    pokemon = pokemon;
    runPathProcess(obj, func_beach_802C8894);
    pokemon->transitionGraph = &D_beach_802CD010;
    runInteractionsAndWaitForFlags(obj, 2);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_beach_802C8894(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (FALSE) {
    }

    pokemon->hSpeed = 200.0f;
    pokemon->jumpVel = 90.0f;
    func_80360300_500710(obj, 2000.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C8900(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (FALSE) {
    }

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 150.0f;
    pokemon = pokemon;
    func_80360590_5009A0(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    pokemon->jumpVel = 150.0f;
    func_80360300_500710(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8980(GObj* obj) {
    updatePokemonState(obj, func_beach_802C89A4);
}

void func_beach_802C8BC4(GObj*);
extern idFuncStruct D_beach_802CD064;

void func_beach_802C89A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (FALSE) {
    }

    pokemon->miscVars[0].field1 = 0;
    obj->flags = 0;
    pokemon->processFlags &= ~0x20;
    setPokemonAnimation(obj, &D_beach_802CCFC0);
    pokemon->transitionGraph = &D_beach_802CD064;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CCFD4);
    pokemon->transitionGraph = &D_beach_802CD064;
    runInteractionsAndWaitForFlags(obj, 2);
    func_8035ED90_4FF1A0(obj, func_beach_802C8BC4);
    setPokemonAnimation(obj, &D_beach_802CCFE8);
    pokemon->transitionGraph = &D_beach_802CD064;
    runInteractionsAndWaitForFlags(obj, 1);
    setPokemonAnimation(obj, &D_beach_802CCFFC);
    pokemon->pokemonLoopTarget = 1;
    pokemon->transitionGraph = &D_beach_802CD064;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_beach_802C8828);
}

void func_beach_802C8AAC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (++D_beach_802CD060 == 2) {
        cmdSendCommandToLink(3, 0x24, obj);
    }

    pokemon->miscVars[0].field1 = 1;
    pokemon->field_0x10e = 0;
    setPokemonAnimation(obj, &D_beach_802CCFD4);
    runPathProcess(obj, func_beach_802C8B60);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 2);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_beach_802C8B60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 90.0f;
    func_80360300_500710(obj, 2000.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_beach_802C8BC4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->counter = 0x80;
    pokemon->processFlags &= ~4;
    pokemon = pokemon;
    func_8035FC54_500064(obj, 4);
    if (pokemon->miscVars[0].field1 == 0) {
        cmdSendCommandToLink(3, 0x1D, obj);
    }
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8C30(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    pokemon->field_0x10e = 7;
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8C58(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    pokemon->field_0x10e = 0;
    func_8035EDC8_4FF1D8(obj);
}

void func_beach_802C8C7C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    obj->flags = 0;
    pokemon->transitionGraph = &D_beach_802CD0B4;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C8CC0(GObj* obj) {
    cmdSendCommandToLink(3, 0x1F, obj);
    updatePokemonState(obj, func_beach_802C86A8);
}

void func_beach_802C8CFC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_beach_802CD0E4;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_beach_802C8D3C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}

void func_beach_802C8D74(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}
