#include "common.h"
#include "../world/world.h"

void func_802CB614_7A4BA4(GObj*);
void func_802CC08C_7A561C(GObj*);
void func_802CC424_7A59B4(GObj*);
void func_802CC514_7A5AA4(GObj*);
void func_802CB110_7A46A0(GObj*);
void func_802CB238_7A47C8(GObj*);
void func_802CB338_7A48C8(GObj*);
void func_802CB88C_7A4E1C(GObj*);

extern AnimationHeader D_802D34A0_7ACA30;
extern idFuncStruct D_802D369C_7ACC2C;
extern AnimationHeader D_802D348C_7ACA1C;
extern AnimationHeader D_802D3450_7AC9E0;
extern AnimationHeader D_802D3464_7AC9F4;
extern AnimationHeader D_802D3478_7ACA08;
extern AnimationHeader D_802D352C_7ACABC;
extern idFuncStruct D_802D3568_7ACAF8;
extern randomTransition D_802D3608_7ACB98;
extern idFuncStruct D_802D374C_7ACCDC;
extern PokemonInitData D_802D37C0_7ACD50;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB080_7A4610.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB110_7A46A0.s")

void func_802CB194_7A4724(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D348C_7ACA1C);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802CB238_7A47C8);
    pokemon->transitionGraph = &D_802D3568_7ACAF8;
    runInteractionsAndWaitForFlags(obj, 3);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802CB110_7A46A0);
    }
    weightedRandomStaightTransition(obj, &D_802D3608_7ACB98);
}

void func_802CB238_7A47C8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802CB294_7A4824(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D34A0_7ACA30);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802CB338_7A48C8);
    pokemon->transitionGraph = &D_802D3568_7ACAF8;
    runInteractionsAndWaitForFlags(obj, 3);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802CB110_7A46A0);
    }
    weightedRandomStaightTransition(obj, &D_802D3608_7ACB98);
}

void func_802CB338_7A48C8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802CB394_7A4924(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802D3464_7AC9F4);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802D3568_7ACAF8;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802D3608_7ACB98);
}

void func_802CB404_7A4994(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802D3478_7ACA08);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802D3568_7ACAF8;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802D3608_7ACB98);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB474_7A4A04.s")

void func_802CB550_7A4AE0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB5AC_7A4B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB614_7A4BA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB6F8_7A4C88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB79C_7A4D2C.s")

void func_802CB7F4_7A4D84(GObj* arg0) {
    updatePokemonState(arg0, func_802CB614_7A4BA4);
}

void func_802CB818_7A4DA8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D348C_7ACA1C);
    runPathProcess(obj, func_802CB88C_7A4E1C);
    pokemon->transitionGraph = &D_802D369C_7ACC2C;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_802CB110_7A46A0);
}

void func_802CB88C_7A4E1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2E);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB8D8_7A4E68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB92C_7A4EBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CB9BC_7A4F4C.s")

void func_802CBA24_7A4FB4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.033333335f, 0.0f, 0x10U);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBA90_7A5020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBBDC_7A516C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBC74_7A5204.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBCDC_7A526C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBD74_7A5304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBE14_7A53A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBE9C_7A542C.s")

void func_802CBF18_7A54A8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x20);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBF64_7A54F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBFDC_7A556C.s")

void func_802CC068_7A55F8(GObj* arg0) {
    updatePokemonState(arg0, func_802CC08C_7A561C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC08C_7A561C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC104_7A5694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC1E0_7A5770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC250_7A57E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC2B4_7A5844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC320_7A58B0.s")

void func_802CC3B4_7A5944(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D3450_7AC9E0);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802D374C_7ACCDC;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802CC424_7A59B4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC424_7A59B4.s")

void func_802CC4DC_7A5A6C(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802D352C_7ACABC);
    updatePokemonState(arg0, func_802CC514_7A5AA4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC514_7A5AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC5C0_7A5B50.s")

GObj* func_802CC8A8_7A5E38(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802D37C0_7ACD50);
}
#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC8E0_7A5E70.s")
