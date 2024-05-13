#include "common.h"

#include "world/world.h"

extern GObj* D_802C7B4C_649FFC;
extern PokemonInitData D_802C7B9C_64A04C;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C46A0_646B50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C46F0_646BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C4820_646CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646B50/func_802C493C_646DEC.s")

GObj* func_802C49A8_646E58(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802C7B4C_649FFC = spawnPokemon(gObjID, id, roomA, roomB, spawn, &D_802C7B9C_64A04C);

    return D_802C7B4C_649FFC;
}
