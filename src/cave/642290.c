#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802C6C64_649114;
extern AnimationHeader D_802C6BA4_649054;
extern idFuncStruct D_802C6BE0_649090;
extern AnimationHeader D_802C6BCC_64907C;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802BFDE0_642290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802BFE34_6422E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802BFEF0_6423A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802BFF74_642424.s")

void func_802C0058_642508(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802C6BA4_649054);
    pokemon->transitionGraph = &D_802C6BE0_649090;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

void func_802C00B0_642560(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802C6BCC_64907C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802C0058_642508);
}

GObj* func_802C0104_6425B4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802C6C64_649114);
}
