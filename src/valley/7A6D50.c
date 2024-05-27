#include "common.h"
#include "../world/world.h"
#include "app_level/app_level.h"

void func_802CD914_7A6EA4(GObj*);

extern AnimationHeader D_802D3958_7ACEE8;
extern AnimationHeader D_802D396C_7ACEFC;
extern PokemonInitData D_802D3A44_7ACFD4;

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CD7C0_7A6D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CD84C_7A6DDC.s")

void func_802CD8A4_7A6E34(GObj* arg0) {
    Pokemon_SetAnimation(arg0, &D_802D3958_7ACEE8);
    Pokemon_SetState(arg0, func_802CD914_7A6EA4);
}

void func_802CD8DC_7A6E6C(GObj* arg0) {
    Pokemon_SetAnimation(arg0, &D_802D396C_7ACEFC);
    Pokemon_SetState(arg0, func_802CD914_7A6EA4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CD914_7A6EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CD98C_7A6F1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CD9F8_7A6F88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CDA94_7A7024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CDB40_7A70D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CDBD4_7A7164.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CDC68_7A71F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A6D50/func_802CDCFC_7A728C.s")

GObj* func_802CDE04_7A7394(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802D3A44_7ACFD4);
}

GObj* func_802CDE3C_7A73CC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802D3A44_7ACFD4);
}
