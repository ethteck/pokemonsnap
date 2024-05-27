#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonInitData D_802E2F70_6CAD50;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C26F0/func_802DA910_6C26F0.s")

GObj* func_802DA9A4_6C2784(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2F70_6CAD50);
}
