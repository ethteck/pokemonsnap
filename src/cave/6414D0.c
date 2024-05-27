#include "common.h"
#include "world/world.h"

void func_802BF044_6414F4(GObj*);

extern PokemonInitData D_802C69C0_648E70;

void func_802BF020_6414D0(GObj* arg0) {
    updatePokemonState(arg0, func_802BF044_6414F4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF044_6414F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF0B4_641564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF124_6415D4.s")

void func_802BF1C4_641674(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF220_6416D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF2D0_641780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF338_6417E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF3D0_641880.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF454_641904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/6414D0/func_802BF4E8_641998.s")

void func_802BF554_641A04(void) {
}

GObj* func_802BF55C_641A0C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802C69C0_648E70);
}
