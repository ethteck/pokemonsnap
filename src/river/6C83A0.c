#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E454C_6CC32C;
extern AnimationHeader D_802E44F0_6CC2D0;
extern idFuncStruct D_802E4518_6CC2F8;

void func_802E05C0_6C83A0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E44F0_6CC2D0);
    pokemon->transitionGraph = &D_802E4518_6CC2F8;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C83A0/func_802E0618_6C83F8.s")

GObj* func_802E0694_6C8474(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E454C_6CC32C);
}
