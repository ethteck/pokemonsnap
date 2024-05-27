#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonInitData D_802E45DC_6CC3BC;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C84B0/func_802E06D0_6C84B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C84B0/func_802E0728_6C8508.s")

GObj* func_802E07A4_6C8584(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E45DC_6CC3BC);
}
