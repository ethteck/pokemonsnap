#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E466C_6CC44C;
extern AnimationHeader D_802E4610_6CC3F0;
extern idFuncStruct D_802E4638_6CC418;

void func_802E07F0_6C85D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E4610_6CC3F0);
    pokemon->transitionGraph = &D_802E4638_6CC418;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C85D0/func_802E0848_6C8628.s")

GObj* func_802E08C4_6C86A4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E466C_6CC44C);
}
