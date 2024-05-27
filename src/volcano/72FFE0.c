#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E3590_734790;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FFE0/func_802DEDE0_72FFE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FFE0/func_802DEEE0_7300E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FFE0/func_802DEF4C_73014C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FFE0/func_802DEFB8_7301B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FFE0/func_802DF028_730228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FFE0/func_802DF0B4_7302B4.s")

extern idFuncStruct D_802E354C_73474C;

void func_802DF164_730364(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 3;
    pokemon->transitionGraph = &D_802E354C_73474C;
    runInteractionsAndWaitForFlags(obj, 0);
    updatePokemonState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FFE0/func_802DF1B4_7303B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72FFE0/func_802DF214_730414.s")

GObj* func_802DF240_730440(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E3590_734790);
}
