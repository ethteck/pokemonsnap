#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonInitData D_802E466C_6CC44C;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C85D0/func_802E07F0_6C85D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C85D0/func_802E0848_6C8628.s")

GObj* func_802E08C4_6C86A4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E466C_6CC44C);
}
