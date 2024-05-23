#include "common.h"

#include "world/world.h"

extern AnimationHeader D_802EC994_7C5F24;
extern AnimationHeader D_802EC9A8_7C5F38;
extern AnimationHeader D_802EC9BC_7C5F4C;
extern idFuncStruct D_802EC9D0_7C5F60;
extern randomTransition D_802EC9F0_7C5F80;
extern PokemonInitData D_802ECA30_7C5FC0;

void func_802D237C_7AB90C(GObj*);

void func_802D2230_7AB7C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 0x2 | 0x1;
    pokemon->counter = 1;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    pokemon->transitionGraph = &D_802EC9D0_7C5F60;
    runInteractionsAndWaitForFlags(obj, POKEMON_PROCESS_FLAG_4);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_802D22A0_7AB830(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 1;
    obj->flags = 0;
    weightedRandomStaightTransition(obj, &D_802EC9F0_7C5F80);
}

void func_802D22D4_7AB864(GObj* obj) {
    forcePokemonAnimation(obj, &D_802EC994_7C5F24);
    updatePokemonState(obj, func_802D237C_7AB90C);
}

void func_802D230C_7AB89C(GObj* obj) {
    forcePokemonAnimation(obj, &D_802EC9A8_7C5F38);
    updatePokemonState(obj, func_802D237C_7AB90C);
}

void func_802D2344_7AB8D4(GObj* obj) {
    forcePokemonAnimation(obj, &D_802EC9BC_7C5F4C);
    updatePokemonState(obj, func_802D237C_7AB90C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AB7C0/func_802D237C_7AB90C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AB7C0/func_802D2428_7AB9B8.s")

void func_802D2540_7ABAD0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemonOnGround(gObjID, id, roomA, roomB, spawn, &D_802ECA30_7C5FC0);
}
