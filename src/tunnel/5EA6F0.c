#include "common.h"

#include "world/world.h"

extern GObj* D_802F0210_5ED2E0;
extern PokemonInitData D_802F025C_5ED32C;

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802ED620_5EA6F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802ED644_5EA714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802ED69C_5EA76C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802ED6D0_5EA7A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802ED720_5EA7F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802ED7BC_5EA88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802ED7CC_5EA89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802EDAE8_5EABB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/tunnel/5EA6F0/func_802EDB3C_5EAC0C.s")

GObj* func_802EDEC0_5EAF90(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802F0210_5ED2E0 = func_80362DC4_5031D4(gObjID, id, roomA, roomB, spawn, &D_802F025C_5ED32C);

    return D_802F0210_5ED2E0;
}
