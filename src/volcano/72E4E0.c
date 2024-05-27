#include "common.h"
#include "world/world.h"

extern AnimationHeader D_802E2E78_734078;
extern AnimationHeader D_802E2E8C_73408C;
extern idFuncStruct D_802E2EC8_7340C8;
extern randomTransition D_802E2F28_734128;
extern PokemonInitData D_802E2F54_734154;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD2E0_72E4E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD328_72E528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD3B0_72E5B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD4A4_72E6A4.s")

void func_802DD500_72E700(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E2E78_734078);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2EC8_7340C8;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2F28_734128);
}

void func_802DD570_72E770(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E2E8C_73408C);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2EC8_7340C8;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2F28_734128);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD5E0_72E7E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD67C_72E87C.s")

void func_802DD67C_72E87C(GObj*);
extern AnimationHeader D_802E2EB4_7340B4;
extern randomTransition D_802E2F28_734128;

void func_802DD6D4_72E8D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E2EB4_7340B4);
    runPathProcess(obj, func_802DD67C_72E87C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1U);
    weightedRandomStaightTransition(obj, &D_802E2F28_734128);
}

void func_802DD67C_72E87C(GObj*);
extern AnimationHeader D_802E2EB4_7340B4;

void func_802DD740_72E940(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E2EB4_7340B4);
    runPathProcess(obj, func_802DD67C_72E87C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1U);
    updatePokemonState(obj, func_802DD500_72E700);
}

GObj* func_802DD7AC_72E9AC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E2F54_734154);
}
