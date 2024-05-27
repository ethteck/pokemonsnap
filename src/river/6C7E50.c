#include "common.h"
#include "world/world.h"

void func_802E0094_6C7E74(GObj*);

extern PokemonInitData D_802E44B4_6CC294;
extern AnimationHeader D_802E4420_6CC200;
extern idFuncStruct D_802E4478_6CC258;

void func_802E0070_6C7E50(GObj* arg0) {
    updatePokemonState(arg0, func_802E0094_6C7E74);
}

void func_802E0094_6C7E74(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E4420_6CC200);
    pokemon->transitionGraph = &D_802E4478_6CC258;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E00EC_6C7ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E01C8_6C7FA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E01F4_6C7FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E0334_6C8114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7E50/func_802E03C0_6C81A0.s")

GObj* func_802E0584_6C8364(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E44B4_6CC294);
}
