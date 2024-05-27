#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802EEA8C_5EBB5C;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E5CB0_5E2D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E5D6C_5E2E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E5D94_5E2E64.s")

extern idFuncStruct D_802EEA38_5EBB08;

void func_802E5F98_5E3068(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802EEA38_5EBB08;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E5FD8_5E30A8.s")

extern idFuncStruct D_802EEA58_5EBB28;

void func_802E61DC_5E32AC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802EEA58_5EBB28;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E621C_5E32EC.s")

GObj* func_802E6420_5E34F0(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802EEA8C_5EBB5C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E6458_5E3528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E6490_5E3560.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E654C_5E361C.s")

extern idFuncStruct D_802EEB48_5EBC18;

void func_802E6574_5E3644(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802EEB48_5EBC18;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E65B4_5E3684.s")

extern idFuncStruct D_802EEB68_5EBC38;

void func_802E67B8_5E3888(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802EEB68_5EBC38;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E67F8_5E38C8.s")

extern idFuncStruct D_802EEB88_5EBC58;

void func_802E6A30_5E3B00(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802EEB88_5EBC58;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E6A70_5E3B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E6C28_5E3CF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E2D80/func_802E6C74_5E3D44.s")
