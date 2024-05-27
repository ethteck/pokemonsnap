#include "common.h"
#include "../world/world.h"

extern PokemonInitData D_8034B5B8_82AD28;

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829670/func_80349F00_829670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829670/func_80349F88_8296F8.s")

GObj* func_8034A064_8297D4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_8034B5B8_82AD28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/829670/func_8034A09C_82980C.s")
