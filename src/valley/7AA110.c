#include "common.h"
#include "../world/world.h"

void func_802D0BA4_7AA134(GObj*);

extern PokemonInitData D_802EC750_7C5CE0;
extern AnimationHeader D_802EC6C0_7C5C50;
extern idFuncStruct D_802EC718_7C5CA8;

void func_802D0B80_7AA110(GObj* arg0) {
    updatePokemonState(arg0, func_802D0BA4_7AA134);
}

void func_802D0BA4_7AA134(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802EC6C0_7C5C50);
    pokemon->transitionGraph = &D_802EC718_7C5CA8;
    runInteractionsAndWaitForFlags(obj, 0U);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA110/func_802D0BFC_7AA18C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA110/func_802D0CD8_7AA268.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA110/func_802D0D0C_7AA29C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA110/func_802D0F0C_7AA49C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7AA110/func_802D0F98_7AA528.s")

GObj* func_802D1154_7AA6E4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802EC750_7C5CE0);
}
