#include "valley.h"

void func_802CF864_7A8DF4(GObj*);
void func_802D0344_7A98D4(GObj*);

extern GObj* D_802D41A4_7AD734;
extern PokemonInitData D_802D41E8_7AD778;
extern GObj* D_802EC644_7C5BD4;
extern PokemonInitData D_802EC68C_7C5C1C;

void func_802CF840_7A8DD0(GObj* arg0) {
    Pokemon_SetState(arg0, func_802CF864_7A8DF4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802CF864_7A8DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802CF8BC_7A8E4C.s")

GObj* func_802CFA00_7A8F90(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802D41A4_7AD734 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802D41E8_7AD778);

    return D_802D41A4_7AD734;
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802CFA40_7A8FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802CFC6C_7A91FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802CFE8C_7A941C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D017C_7A970C.s")

void func_802D0320_7A98B0(GObj* arg0) {
    Pokemon_SetState(arg0, func_802D0344_7A98D4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D0344_7A98D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D039C_7A992C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D03D0_7A9960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D0420_7A99B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D04BC_7A9A4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D04CC_7A9A5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D0700_7A9C90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D0754_7A9CE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A8DD0/func_802D07BC_7A9D4C.s")

GObj* func_802D0B3C_7AA0CC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802EC644_7C5BD4 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802EC68C_7C5C1C);

    return D_802EC644_7C5BD4;
}
