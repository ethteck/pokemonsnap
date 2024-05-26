#include "common.h"
#include "../world/world.h"

void func_802C9840_7A2DD0(GObj*);
void func_802C9990_7A2F20(GObj*);

extern PokemonInitData D_802D2F2C_7AC4BC;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9840_7A2DD0.s")

void func_802C9958_7A2EE8(GObj* arg0) {
    func_8035ED90_4FF1A0(arg0, func_802C9840_7A2DD0);
    updatePokemonState(arg0, func_802C9990_7A2F20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9990_7A2F20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9A48_7A2FD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9A94_7A3024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9B0C_7A309C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9B78_7A3108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9BD0_7A3160.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9C84_7A3214.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9D00_7A3290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9DC4_7A3354.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9E60_7A33F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9EC8_7A3458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A2DD0/func_802C9F34_7A34C4.s")

GObj* func_802C9F90_7A3520(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802D2F2C_7AC4BC);
}
