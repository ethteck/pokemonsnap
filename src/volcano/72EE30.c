#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonInitData D_802E3080_734280;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72EE30/func_802DDC30_72EE30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72EE30/func_802DDCA0_72EEA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72EE30/func_802DDD04_72EF04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72EE30/func_802DDE00_72F000.s")

GObj* func_802DDEC0_72F0C0(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E3080_734280);
}
