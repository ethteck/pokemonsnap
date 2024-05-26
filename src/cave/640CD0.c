#include "common.h"
#include "world/world.h"

void func_802BED04_6411B4(GObj*);

extern PokemonInitData D_802C6824_648CD4;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BE820_640CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BE898_640D48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BE8D4_640D84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BE944_640DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BE9B4_640E64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BEA24_640ED4.s")

void func_802BEAC8_640F78(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BEB24_640FD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BEBBC_64106C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BEC34_6410E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BECA8_641158.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BED04_6411B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BED8C_64123C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BEE10_6412C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BEEA4_641354.s")

void func_802BEEF4_6413A4(GObj* arg0) {
    updatePokemonState(arg0, func_802BED04_6411B4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BEF18_6413C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BEF8C_64143C.s")

GObj* func_802BEFD8_641488(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802C6824_648CD4);
}
