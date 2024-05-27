#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonInitData D_802E33DC_7345DC;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE6F0_72F8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE7DC_72F9DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE8C8_72FAC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE91C_72FB1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE95C_72FB5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DE9C4_72FBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72F8F0/func_802DEA04_72FC04.s")
GObj* func_802DEA44_72FC44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E33DC_7345DC);
}
