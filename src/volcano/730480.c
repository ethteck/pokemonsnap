#include "common.h"
#include "world/world.h"

void func_802DF3D4_7305D4(GObj*);
void func_802DFA94_730C94(GObj*);

extern PokemonInitData D_802E3674_734874;
extern PokemonInitData D_802E3740_734940;
extern PokemonInitData D_802E37B8_7349B8;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DF280_730480.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DF338_730538.s")

GObj* func_802DF378_730578(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E3674_734874);
}

void func_802DF3B0_7305B0(GObj* arg0) {
    updatePokemonState(arg0, func_802DF3D4_7305D4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DF3D4_7305D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DF42C_73062C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DF508_730708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DF534_730734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DF7F4_7309F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DF880_730A80.s")

GObj* func_802DFA38_730C38(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E3740_734940);
}

void func_802DFA70_730C70(GObj* arg0) {
    updatePokemonState(arg0, func_802DFA94_730C94);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DFA94_730C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/730480/func_802DFAE4_730CE4.s")

GObj* func_802DFB44_730D44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802E37B8_7349B8);
}
