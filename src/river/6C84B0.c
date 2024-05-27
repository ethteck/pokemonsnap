#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E45DC_6CC3BC;
extern AnimationHeader D_802E4580_6CC360;
extern idFuncStruct D_802E45A8_6CC388;

void func_802E06D0_6C84B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E4580_6CC360);
    pokemon->transitionGraph = &D_802E45A8_6CC388;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C84B0/func_802E0728_6C8508.s")

GObj* func_802E07A4_6C8584(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E45DC_6CC3BC);
}
