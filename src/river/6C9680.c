#include "common.h"

#include "world/world.h"

void func_802E18C4_6C96A4(GObj*);

extern GObj* D_802E4B00_6CC8E0;
extern PokemonInitData D_802E4B48_6CC928;

void func_802E18A0_6C9680(GObj* arg0) {
    updatePokemonState(arg0, func_802E18C4_6C96A4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E18C4_6C96A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E191C_6C96FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E1950_6C9730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E19A0_6C9780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E1A3C_6C981C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E1A4C_6C982C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E1CBC_6C9A9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E1D10_6C9AF0.s")

GObj* func_802E2084_6C9E64(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802E4B00_6CC8E0 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802E4B48_6CC928);

    return D_802E4B00_6CC8E0;
}
