#include "volcano/volcano.h"

void func_802DF3D4_7305D4(GObj*);

extern PokemonInitData D_802E3740_734940;

void func_802DF3B0_7305B0(GObj* arg0) {
    Pokemon_SetState(arg0, func_802DF3D4_7305D4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7305B0/func_802DF3D4_7305D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7305B0/func_802DF42C_73062C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7305B0/func_802DF508_730708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7305B0/func_802DF534_730734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7305B0/func_802DF7F4_7309F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/7305B0/func_802DF880_730A80.s")

GObj* func_802DFA38_730C38(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E3740_734940);
}
