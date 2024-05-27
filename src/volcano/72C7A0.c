#include "common.h"
#include "world/world.h"

void func_802DBB78_72CD78(GObj*);
void func_802DBDB8_72CFB8(GObj*);
void func_802DBB2C_72CD2C(GObj*);
void func_802DBF4C_72D14C(GObj*);
void func_802DBE8C_72D08C(GObj*);
void func_802DB80C_72CA0C(GObj*);
void func_802DB90C_72CB0C(GObj*);

extern AnimationHeader D_802E2764_733964;
extern AnimationHeader D_802E2778_733978;
extern AnimationHeader D_802E27B4_7339B4;
extern idFuncStruct D_802E2804_733A04;
extern idFuncStruct D_802E2984_733B84;
extern randomTransition D_802E2A64_733C64;
extern PokemonInitData D_802E2AA8_733CA8;
extern AnimationHeader D_802E278C_73398C;
extern AnimationHeader D_802E27A0_7339A0;
extern AnimationHeader D_802E27DC_7339DC;
extern idFuncStruct D_802E29B4_733BB4;
extern idFuncStruct D_802E2A24_733C24;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DB5A0_72C7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DB660_72C860.s")

void func_802DB6F8_72C8F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E2764_733964);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2804_733A04;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2A64_733C64);
}

void func_802DB768_72C968(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E278C_73398C);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802DB80C_72CA0C);
    pokemon->transitionGraph = &D_802E2804_733A04;
    runInteractionsAndWaitForFlags(obj, 3);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802DB6F8_72C8F8);
    }
    weightedRandomStaightTransition(obj, &D_802E2A64_733C64);
}

void func_802DB80C_72CA0C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802DB868_72CA68(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E27A0_7339A0);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802DB90C_72CB0C);
    pokemon->transitionGraph = &D_802E2804_733A04;
    runInteractionsAndWaitForFlags(obj, 3);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802DB6F8_72C8F8);
    }
    weightedRandomStaightTransition(obj, &D_802E2A64_733C64);
}

void func_802DB90C_72CB0C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802DB968_72CB68(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E2778_733978);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2804_733A04;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2A64_733C64);
}

void func_802DB9D8_72CBD8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E27B4_7339B4);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2984_733B84;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DBDB8_72CFB8);
}

void func_802DBA48_72CC48(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E27B4_7339B4);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2984_733B84;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DBDB8_72CFB8);
}

void func_802DBAB8_72CCB8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E27DC_7339DC);
    runPathProcess(obj, func_802DBB2C_72CD2C);
    pokemon->transitionGraph = &D_802E2984_733B84;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DB6F8_72C8F8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBB2C_72CD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBB78_72CD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBC00_72CE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBC84_72CE84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBD34_72CF34.s")

void func_802DBD94_72CF94(GObj* arg0) {
    updatePokemonState(arg0, func_802DBB78_72CD78);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBDB8_72CFB8.s")

void func_802DBE18_72D018(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E278C_73398C);
    runPathProcess(obj, func_802DBE8C_72D08C);
    pokemon->transitionGraph = &D_802E29B4_733BB4;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802DB6F8_72C8F8);
}

void func_802DBE8C_72D08C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2E);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802DBED8_72D0D8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E27A0_7339A0);
    runPathProcess(obj, func_802DBF4C_72D14C);
    pokemon->transitionGraph = &D_802E2A24_733C24;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802DB6F8_72C8F8);
}

void func_802DBF4C_72D14C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    func_8036194C_501D5C(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72C7A0/func_802DBFA8_72D1A8.s")

GObj* func_802DC018_72D218(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E2AA8_733CA8);
}
