#include "common.h"
#include "beach.h"

void func_beach_802CAF90(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CDBD4);
    pokemon->transitionGraph = &D_beach_802CDCD0;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802CAF90);
}

void func_beach_802CAFEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CDBC0);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802CAF90);
}

void func_beach_802CB054(GObj* obj) {
    runPathProcess(obj, func_beach_802CB128);
    updatePokemonState(obj, func_beach_802CB08C);
}

void func_beach_802CB08C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CDB84);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1 | POKEMON_PROCESS_FLAG_2);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_1) {
        updatePokemonState(obj, func_beach_802CB08C);
    }
    pokemon->transitionGraph = &D_beach_802CDD40;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802CAF90);
}

void func_beach_802CB128(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (TRUE) {
        if (!func_80361440_501850(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    pokemon->pathProcess = NULL;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB194.s")

void func_beach_802CB2D8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 0x200;
    pokemon->flags |= 0x800;
    func_8035ED90_4FF1A0(obj, func_beach_802CB814);
    setPokemonAnimation(obj, &D_beach_802CDB5C);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_beach_802CDD80;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CDE30);
}

void func_beach_802CB36C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CDB5C);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_beach_802CDD80;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CDE30);
}

void func_beach_802CB3DC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CDB70);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_beach_802CDD80;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    weightedRandomStaightTransition(obj, &D_beach_802CDE30);
}

void func_beach_802CB44C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CDBC0);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_beach_802CDE48;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802CB3DC);
}

void func_beach_802CB4BC() {
}

void func_beach_802CB4C4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802CB520(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_beach_802CDBD4);
    runPathProcess(obj, func_beach_802CB6B4);
    pokemon->transitionGraph = &D_beach_802CDE78;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802CB594);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB594.s")

void func_beach_802CB6B4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    ohWait(60);
    func_8036148C_50189C(obj, 0.1f, 0);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802CB710(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_80361748_501B58(obj, 50, 0.1f, 3);
    func_8036148C_50189C(obj, 0.1f, 0);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802CB784(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CDB84);
    runPathProcess(obj, func_beach_802CB128);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1 | POKEMON_PROCESS_FLAG_2);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_1) {
        updatePokemonState(obj, func_beach_802CB784);
    }
    updatePokemonState(obj, func_beach_802CB3DC);
}

void func_beach_802CB814(GObj* obj) {
    while (func_beach_802CB194(obj)) {
        ohWait(1);
    }

    cmdSendCommand(obj, 0x23, obj);
    func_8035EDC8_4FF1D8(obj);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/563000/func_beach_802CB874.s")

void func_beach_802CB9E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CDBC0);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802CB874);
}

void func_beach_802CBA48(GObj* obj) {
    f32 temp_f0;
    f32 temp_f20;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model;
    Vec3f sp34;

    model = obj->data.dobj;
    ohWait(0x3C);
    func_8001FCE8(&sp34, pokemon->path, 0.99999f);
    temp_f0 = atan2f(sp34.x, sp34.z);
    temp_f20 = temp_f0 - ((s32) (temp_f0 / 6.2831855f) * 6.2831855f);
    while (func_80360FC8_5013D8(model, temp_f20, 0.13962634f) == 0) {
        ohWait(1);
    }
    pokemon->pathProcess = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802CBB34(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_80361B50_501F60(obj, pokemon->pos1.x, pokemon->pos1.z);
    func_80361E58_502268(obj, 0.1f);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void func_beach_802CBB90(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CDBD4);
    pokemon->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    setPokemonAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    forcePokemonAnimation(obj, &D_beach_802CDBFC);
    pokemon->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802CBB90);
}

void func_beach_802CBC4C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_beach_802CDBC0);
    pokemon->transitionGraph = &D_beach_802CDFD8;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    updatePokemonState(obj, func_beach_802CBB90);
}

void func_beach_802CBCA8(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CE038);
}

void func_beach_802CBCE0(GObj* obj) {
    updatePokemonState(obj, func_beach_802CBD04);
}

void func_beach_802CBD04(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    cmdSendCommandToLink(3, 0x25, obj);
    ohWait(1);
    func_803667C0_506BD0(obj, 1, 0x34);
    forcePokemonAnimation(obj, &D_beach_802CE070);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_1);
    cmdSendCommandToLink(3, 0x26, obj);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_beach_802CBDA0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    func_80362DC4_5031D4(gObjID, id, roomA, roomB, spawn, &D_beach_802CE0A8);
}

void func_beach_802CBDD8(GObj* obj) {
    GObj* var;

    var = addPokemonAtGeo(obj, 0x3EEU, &D_beach_802CE0DC);
    GET_POKEMON(var)->behavior = 0;
}
