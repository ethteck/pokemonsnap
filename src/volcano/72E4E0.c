#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E2F54_734154;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD2E0_72E4E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD328_72E528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD3B0_72E5B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD4A4_72E6A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD500_72E700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD570_72E770.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD5E0_72E7E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD67C_72E87C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD6D4_72E8D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E4E0/func_802DD740_72E940.s")

GObj* func_802DD7AC_72E9AC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E2F54_734154);
}
