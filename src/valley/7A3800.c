#include "common.h"
#include "../world/world.h"

void func_802CA364_7A38F4(GObj*);

extern AnimationHeader D_802D3084_7AC614;
extern AnimationHeader D_802D3098_7AC628;
extern AnimationHeader D_802D30AC_7AC63C;
extern PokemonInitData D_802D3100_7AC690;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3800/func_802CA270_7A3800.s")

void func_802CA2BC_7A384C(GObj* arg0) {
    forcePokemonAnimation(arg0, &D_802D3084_7AC614);
    updatePokemonState(arg0, func_802CA364_7A38F4);
}

void func_802CA2F4_7A3884(GObj* arg0) {
    forcePokemonAnimation(arg0, &D_802D3098_7AC628);
    updatePokemonState(arg0, func_802CA364_7A38F4);
}

void func_802CA32C_7A38BC(GObj* arg0) {
    forcePokemonAnimation(arg0, &D_802D30AC_7AC63C);
    updatePokemonState(arg0, func_802CA364_7A38F4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3800/func_802CA364_7A38F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3800/func_802CA434_7A39C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3800/func_802CA574_7A3B04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3800/func_802CA5B4_7A3B44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A3800/func_802CA65C_7A3BEC.s")

GObj* func_802CA688_7A3C18(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802D3100_7AC690);
}
