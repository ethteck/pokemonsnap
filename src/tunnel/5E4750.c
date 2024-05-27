#include "common.h"
#include "world/world.h"

void func_802E796C_5E4A3C(GObj*);
void func_802E7DDC_5E4EAC(GObj*);
void func_802E7E94_5E4F64(GObj*);
void func_802E80CC_5E519C(GObj*);
void func_802E9150_5E6220(GObj*);

extern idFuncStruct D_802EF280_5EC350;
extern idFuncStruct D_802EF0A0_5EC170;
extern AnimationHeader D_802EEDD0_5EBEA0;
extern idFuncStruct D_802EEED8_5EBFA8;
extern randomTransition D_802EEF78_5EC048;
extern PokemonInitData D_802EF2D0_5EC3A0;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7680_5E4750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7718_5E47E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E77B0_5E4880.s")

void func_802E782C_5E48FC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802EEDD0_5EBEA0);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802EEED8_5EBFA8;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802EEF78_5EC048);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E789C_5E496C.s")

void func_802E7948_5E4A18(GObj* arg0) {
    updatePokemonState(arg0, func_802E796C_5E4A3C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E796C_5E4A3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7AC8_5E4B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7B3C_5E4C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7C1C_5E4CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7CA4_5E4D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7D04_5E4DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7DDC_5E4EAC.s")

void func_802E7E5C_5E4F2C(GObj* arg0) {
    runPathProcess(arg0, func_802E7DDC_5E4EAC);
    updatePokemonState(arg0, func_802E7E94_5E4F64);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7E94_5E4F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E7F64_5E5034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8008_5E50D8.s")

void func_802E8058_5E5128(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802EEDD0_5EBEA0);
    runPathProcess(obj, func_802E80CC_5E519C);
    pokemon->transitionGraph = &D_802EF0A0_5EC170;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802E8058_5E5128);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E80CC_5E519C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E818C_5E525C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E823C_5E530C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8290_5E5360.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8330_5E5400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8398_5E5468.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8428_5E54F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E849C_5E556C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E853C_5E560C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E85BC_5E568C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8628_5E56F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E867C_5E574C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E86C4_5E5794.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8754_5E5824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E87F4_5E58C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8868_5E5938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E88EC_5E59BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8990_5E5A60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8A24_5E5AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8AA4_5E5B74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8B1C_5E5BEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8C94_5E5D64.s")

void func_802E8D38_5E5E08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.2f, 0x2A);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8D84_5E5E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8E34_5E5F04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8EAC_5E5F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E8F44_5E6014.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E9098_5E6168.s")

void func_802E90DC_5E61AC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802EEDD0_5EBEA0);
    runPathProcess(obj, func_802E9150_5E6220);
    pokemon->transitionGraph = &D_802EF280_5EC350;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802E90DC_5E61AC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E9150_5E6220.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E91A8_5E6278.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E91FC_5E62CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E4750/func_802E9288_5E6358.s")

GObj* func_802E9390_5E6460(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802EF2D0_5EC3A0);
}
