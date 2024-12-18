#include "valley.h"

void func_802CDEA4_7A7434(GObj*);

extern GObj* D_802D3B34_7AD0C4;
extern PokemonInitData D_802D3C0C_7AD19C;

void func_802CDE80_7A7410(GObj* arg0) {
    Pokemon_SetState(arg0, func_802CDEA4_7A7434);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7410/func_802CDEA4_7A7434.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7410/func_802CDEFC_7A748C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7410/func_802CDF68_7A74F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7410/func_802CDFFC_7A758C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7410/func_802CE090_7A7620.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A7410/func_802CE124_7A76B4.s")

GObj* func_802CE1B8_7A7748(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802D3B34_7AD0C4 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802D3C0C_7AD19C);

    return D_802D3B34_7AD0C4;
}
