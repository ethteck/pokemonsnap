#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E32C8_7344C8;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F770/func_802DE570_72F770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F770/func_802DE648_72F848.s")

GObj* func_802DE6B4_72F8B4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E32C8_7344C8);
}
