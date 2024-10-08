#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern PokemonInitData D_802E2EC4_6CACA4;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C22E0/func_802DA500_6C22E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C22E0/func_802DA590_6C2370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C22E0/func_802DA620_6C2400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C22E0/func_802DA674_6C2454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C22E0/func_802DA73C_6C251C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C22E0/func_802DA768_6C2548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C22E0/func_802DA814_6C25F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C22E0/func_802DA864_6C2644.s")

GObj* func_802DA8CC_6C26AC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2EC4_6CACA4);
}
