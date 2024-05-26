#include "common.h"
#include "world/world.h"

void func_802ECAE4_5E9BB4(GObj*);

extern GObj* D_802EFFD0_5ED0A0;
extern PokemonInitData D_802F0030_5ED100;
extern GObj* D_802F0070_5ED140;
extern PokemonInitData D_802F00D0_5ED1A0;
extern PokemonInitData D_802F01A0_5ED270;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802EC400_5E94D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802EC4E8_5E95B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802EC5B0_5E9680.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802EC6CC_5E979C.s")

GObj* func_802EC720_5E97F0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802EFFD0_5ED0A0 = func_80362DC4_5031D4(gObjID, id, roomA, roomB, spawn, &D_802F0030_5ED100);

    return D_802EFFD0_5ED0A0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802EC760_5E9830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802EC848_5E9918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802EC910_5E99E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ECA2C_5E9AFC.s")

GObj* func_802ECA80_5E9B50(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802F0070_5ED140 = func_80362DC4_5031D4(gObjID, id, roomA, roomB, spawn, &D_802F00D0_5ED1A0);

    return D_802F0070_5ED140;
}

void func_802ECAC0_5E9B90(GObj* arg0) {
    updatePokemonState(arg0, func_802ECAE4_5E9BB4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ECAE4_5E9BB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ECB3C_5E9C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ECC18_5E9CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ECC44_5E9D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ECD84_5E9E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ECE10_5E9EE0.s")

GObj* func_802ECFC8_5EA098(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return func_80362DC4_5031D4(objID, id, block, blockB, spawn, &D_802F01A0_5ED270);
}

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ED000_5EA0D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ED030_5EA100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ED050_5EA120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ED0C4_5EA194.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ED1BC_5EA28C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ED2E8_5EA3B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5E94D0/func_802ED5C8_5EA698.s")
