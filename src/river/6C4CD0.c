#include "common.h"
#include "world/world.h"

void func_802DCFBC_6C4D9C(GObj*);

extern AnimationHeader D_802E36FC_6CB4DC;
extern AnimationHeader D_802E3710_6CB4F0;
extern AnimationHeader D_802E3724_6CB504;
extern randomTransition D_802E3748_6CB528;
extern PokemonInitData D_802E377C_6CB55C;

void func_802DCEF0_6C4CD0(GObj* arg0) {
    weightedRandomStaightTransition(arg0, &D_802E3748_6CB528);
}

void func_802DCF14_6C4CF4(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802E36FC_6CB4DC);
    updatePokemonState(arg0, func_802DCFBC_6C4D9C);
}

void func_802DCF4C_6C4D2C(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802E3710_6CB4F0);
    updatePokemonState(arg0, func_802DCFBC_6C4D9C);
}

void func_802DCF84_6C4D64(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802E3724_6CB504);
    updatePokemonState(arg0, func_802DCFBC_6C4D9C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4CD0/func_802DCFBC_6C4D9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C4CD0/func_802DD068_6C4E48.s")

GObj* func_802DD0A8_6C4E88(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E377C_6CB55C);
}
