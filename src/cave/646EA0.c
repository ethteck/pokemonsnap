#include "common.h"

#include "world/world.h"
#include "app_level/app_level.h"

extern GObj* D_802C7C3C_64A0EC;
extern PokemonInitData D_802C7CCC_64A17C;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646EA0/func_802C49F0_646EA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646EA0/func_802C4A4C_646EFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646EA0/func_802C4AA8_646F58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646EA0/func_802C4B04_646FB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646EA0/func_802C4C18_6470C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646EA0/func_802C4C70_647120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646EA0/func_802C4D60_647210.s")

GObj* func_802C4E64_647314(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802C7C3C_64A0EC = Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_802C7CCC_64A17C);

    return D_802C7C3C_64A0EC;
}
