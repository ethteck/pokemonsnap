#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E33DC_7345DC;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE6F0_72F8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE7DC_72F9DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE8C8_72FAC8.s")

extern idFuncStruct D_802E3378_734578;

void func_802DE91C_72FB1C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802E3378_734578;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE95C_72FB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE9C4_72FBC4.s")

extern idFuncStruct D_802E3398_734598;

void func_802DEA04_72FC04(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = &D_802E3398_734598;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

GObj* func_802DEA44_72FC44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E33DC_7345DC);
}
