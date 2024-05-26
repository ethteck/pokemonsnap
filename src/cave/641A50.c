#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802C6B5C_64900C;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BF5A0_641A50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BF68C_641B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BF750_641C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BF7B4_641C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BF824_641CD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BF894_641D44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BF9B4_641E64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BFA3C_641EEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BFA8C_641F3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BFB24_641FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BFB9C_64204C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BFBF0_6420A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/641A50/func_802BFC84_642134.s")

GObj* func_802BFDA0_642250(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802C6B5C_64900C);
}
