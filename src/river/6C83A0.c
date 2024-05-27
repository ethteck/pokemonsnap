#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern PokemonInitData D_802E454C_6CC32C;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C83A0/func_802E05C0_6C83A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C83A0/func_802E0618_6C83F8.s")

GObj* func_802E0694_6C8474(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E454C_6CC32C);
}
