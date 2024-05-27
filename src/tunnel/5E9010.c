#include "common.h"

#include "world/world.h"

void func_802EC078_5E9148(GObj*);

extern AnimationHeader D_802EFEF8_5ECFC8;
extern GObj* D_802EFF28_5ECFF8;
extern PokemonInitData D_802EFF94_5ED064;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E9010/func_802EBF40_5E9010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E9010/func_802EBFDC_5E90AC.s")

void func_802EC040_5E9110(GObj* arg0) {
    setPokemonAnimation(arg0, &D_802EFEF8_5ECFC8);
    updatePokemonState(arg0, func_802EC078_5E9148);
}
#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E9010/func_802EC078_5E9148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E9010/func_802EC178_5E9248.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E9010/func_802EC23C_5E930C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E9010/func_802EC294_5E9364.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E9010/func_802EC398_5E9468.s")

GObj* func_802EC3BC_5E948C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802EFF28_5ECFF8 = Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802EFF94_5ED064);

    return D_802EFF28_5ECFF8;
}
