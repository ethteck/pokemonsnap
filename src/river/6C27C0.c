#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern RandomState D_802E3048_6CAE28[];
extern PokemonInitData D_802E3074_6CAE54;
extern PokemonInitData D_802E312C_6CAF0C;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DA9E0_6C27C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DAACC_6C28AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DABB8_6C2998.s")

void func_802DAC04_6C29E4(GObj* obj) {
    Pokemon_SetStateRandom(obj, D_802E3048_6CAE28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DAC28_6C2A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DACA8_6C2A88.s")

GObj* func_802DAD28_6C2B08(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E3074_6CAE54);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DAD60_6C2B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DADD8_6C2BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DAE68_6C2C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DAED4_6C2CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C27C0/func_802DAFB8_6C2D98.s")

GObj* func_802DB064_6C2E44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E312C_6CAF0C);
}
