#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802C6C64_649114;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802BFDE0_642290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802BFE34_6422E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802BFEF0_6423A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802BFF74_642424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802C0058_642508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/642290/func_802C00B0_642560.s")

GObj* func_802C0104_6425B4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802C6C64_649114);
}
