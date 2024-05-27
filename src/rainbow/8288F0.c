#include "common.h"
#include "../world/world.h"

extern PokemonInitData D_8034B554_82ACC4;
extern AnimationHeader D_8034B0FC_82A86C;
extern idFuncStruct D_8034B238_82A9A8;
extern idFuncStruct D_8034B298_82AA08;
extern idFuncStruct D_8034B2C8_82AA38;
extern AnimationHeader D_8034B174_82A8E4;
extern idFuncStruct D_8034B3E8_82AB58;
extern idFuncStruct D_8034B448_82ABB8;
extern idFuncStruct D_8034B478_82ABE8;

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349180_8288F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_803491D4_828944.s")

extern idFuncStruct D_8034B188_82A8F8;

void func_8034930C_828A7C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 3;
    pokemon->transitionGraph = &D_8034B188_82A8F8;
    runInteractionsAndWaitForFlags(obj, 0U);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_8034935C_828ACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_803493F4_828B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349480_828BF0.s")

void func_80349514_828C84(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = &D_8034B238_82A9A8;
    runInteractionsAndWaitForFlags(obj, 0U);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_8034956C_828CDC.s")

void func_803495FC_828D6C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = &D_8034B298_82AA08;
    runInteractionsAndWaitForFlags(obj, 0U);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349654_828DC4.s")

void func_803496BC_828E2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034B0FC_82A86C);
    pokemon->transitionGraph = &D_8034B2C8_82AA38;
    runInteractionsAndWaitForFlags(obj, 0U);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349714_828E84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_8034977C_828EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349814_828F84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_803498A0_829010.s")

void func_80349934_8290A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = &D_8034B3E8_82AB58;
    runInteractionsAndWaitForFlags(obj, 0U);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_8034998C_8290FC.s")

void func_80349A1C_82918C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = &D_8034B448_82ABB8;
    runInteractionsAndWaitForFlags(obj, 0U);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349A74_8291E4.s")

void func_80349ADC_82924C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_8034B174_82A8E4);
    pokemon->transitionGraph = &D_8034B478_82ABE8;
    runInteractionsAndWaitForFlags(obj, 0U);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349B34_8292A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349B98_829308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349C18_829388.s")

void func_803491D4_828944(GObj*);
extern AnimationHeader D_8034B110_82A880;
extern idFuncStruct D_8034B4E8_82AC58;

void func_80349D40_8294B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    runPathProcess(obj, func_803491D4_828944);
    setPokemonAnimation(obj, &D_8034B110_82A880);
    pokemon->transitionGraph = &D_8034B4E8_82AC58;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349DB0_829520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349DE8_829558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/8288F0/func_80349E28_829598.s")

GObj* func_80349EB8_829628(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_8034B554_82ACC4);
}
