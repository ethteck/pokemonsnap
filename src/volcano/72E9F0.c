#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E2FD8_7341D8;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E9F0/func_802DD7F0_72E9F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E9F0/func_802DD8F8_72EAF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E9F0/func_802DD954_72EB54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E9F0/func_802DDA0C_72EC0C.s")

GObj* func_802DDA98_72EC98(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E2FD8_7341D8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E9F0/func_802DDAD0_72ECD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E9F0/func_802DDB04_72ED04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72E9F0/func_802DDB60_72ED60.s")
