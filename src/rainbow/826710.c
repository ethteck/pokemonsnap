#include "common.h"
#include "../world/world.h"

void func_80347E44_8275B4(GObj*);
void func_80348540_827CB0(GObj*);
void func_80348994_828104(GObj*);

extern PokemonInitData D_8034AE90_82A600;
extern PokemonInitData D_8034AF78_82A6E8;

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80346FA0_826710.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803470CC_82683C.s")

void func_80347188_8268F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 6.2831855f, 0x20);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803471D4_826944.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347334_826AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347398_826B08.s")

extern AnimationHeader D_8034ACC4_82A434;
extern idFuncStruct D_8034AD50_82A4C0;
extern randomTransition D_8034AE30_82A5A0;

void func_80347574_826CE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034ACC4_82A434);
    pokemon->transitionGraph = &D_8034AD50_82A4C0;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_8034AE30_82A5A0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803475D0_826D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347724_826E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347900_827070.s")

void func_80347900_827070(GObj*);
extern AnimationHeader D_8034ACB0_82A420;
extern idFuncStruct D_8034AD90_82A500;

void func_80347940_8270B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034ACB0_82A420);
    pokemon->transitionGraph = &D_8034AD90_82A500;
    runInteractionsAndWaitForFlags(obj, 2);
    updatePokemonState(obj, func_80347900_827070);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_8034799C_82710C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347B88_8272F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347CC8_827438.s")

void func_80347E0C_82757C(GObj* arg0) {
    func_8035ED90_4FF1A0(arg0, func_80348540_827CB0);
    updatePokemonState(arg0, func_80347E44_8275B4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347E44_8275B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_8034800C_82777C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803480C0_827830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348208_827978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803482EC_827A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803484F0_827C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348540_827CB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_8034877C_827EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803487CC_827F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348850_827FC0.s")

GObj* func_80348938_8280A8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_8034AE90_82A600);
}

void func_80348970_8280E0(GObj* arg0) {
    updatePokemonState(arg0, func_80348994_828104);
}

void func_80348B34_8282A4(GObj*);
extern AnimationHeader D_8034AED0_82A640;
extern idFuncStruct D_8034AF3C_82A6AC;

void func_80348994_828104(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034AED0_82A640);
    runPathProcess(obj, func_80348B34_8282A4);
    pokemon->transitionGraph = &D_8034AF3C_82A6AC;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348A04_828174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348B34_8282A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348BDC_82834C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348C08_828378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348D48_8284B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348DD4_828544.s")

GObj* func_80348FB8_828728(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_8034AF78_82A6E8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348FF0_828760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80349084_8287F4.s")
