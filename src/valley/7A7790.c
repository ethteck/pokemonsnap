#include "common.h"
#include "../world/world.h"

void func_802CE224_7A77B4(GObj*);
void func_802CE7D8_7A7D68(GObj*);
void func_802CE440_7A79D0(GObj*);
void func_802CE554_7A7AE4(GObj*);
void func_802CE654_7A7BE4(GObj*);
void func_802CE37C_7A790C(GObj*);

extern AnimationHeader D_802D3C84_7AD214;
extern AnimationHeader D_802D3C70_7AD200;
extern idFuncStruct D_802D3D24_7AD2B4;
extern randomTransition D_802D3D84_7AD314;
extern PokemonInitData D_802D3F38_7AD4C8;
extern AnimationHeader D_802D3D10_7AD2A0;

void func_802CE200_7A7790(GObj* arg0) {
    updatePokemonState(arg0, func_802CE224_7A77B4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE224_7A77B4.s")

void func_802CE2DC_7A786C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2A);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802CE328_7A78B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D3D10_7AD2A0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802CE37C_7A790C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE37C_7A790C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE3CC_7A795C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE440_7A79D0.s")

void func_802CE4B0_7A7A40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D3C70_7AD200);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802CE554_7A7AE4);
    pokemon->transitionGraph = &D_802D3D24_7AD2B4;
    runInteractionsAndWaitForFlags(obj, 3);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802CE440_7A79D0);
    }
    weightedRandomStaightTransition(obj, &D_802D3D84_7AD314);
}

void func_802CE554_7A7AE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

void func_802CE5B0_7A7B40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802D3C84_7AD214);
    pokemon->pokemonLoopTarget = 5;
    runPathProcess(obj, func_802CE654_7A7BE4);
    pokemon->transitionGraph = &D_802D3D24_7AD2B4;
    runInteractionsAndWaitForFlags(obj, 3);
    if (pokemon->processFlags & 2) {
        updatePokemonState(obj, func_802CE440_7A79D0);
    }
    weightedRandomStaightTransition(obj, &D_802D3D84_7AD314);
}

void func_802CE654_7A7BE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE6B0_7A7C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE768_7A7CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE7D8_7A7D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE870_7A7E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE8F4_7A7E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7790/func_802CE978_7A7F08.s")

void func_802CEA34_7A7FC4(GObj* arg0) {
    updatePokemonState(arg0, func_802CE7D8_7A7D68);
}

GObj* func_802CEA58_7A7FE8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802D3F38_7AD4C8);
}
