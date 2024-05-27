#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E43D8_6CC1B8;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7CD0/func_802DFEF0_6C7CD0.s")

GObj* func_802DFF5C_6C7D3C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E43D8_6CC1B8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C7CD0/func_802DFF94_6C7D74.s")
