#include "volcano/volcano.h"

void func_802DFA94_730C94(GObj*);

extern PokemonInitData D_802E37B8_7349B8;

void func_802DFA70_730C70(GObj* arg0) {
    Pokemon_SetState(arg0, func_802DFA94_730C94);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730C70/func_802DFA94_730C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730C70/func_802DFAE4_730CE4.s")

GObj* func_802DFB44_730D44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E37B8_7349B8);
}
