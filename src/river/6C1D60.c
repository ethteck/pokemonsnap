#include "common.h"
#include "world/world.h"

extern PokemonInitData D_802E2E04_6CABE4;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802D9F80_6C1D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802D9FDC_6C1DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA04C_6C1E2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA0BC_6C1E9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA12C_6C1F0C.s")

void func_802DA1AC_6C1F8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 100.0f;
    func_80361110_501520(obj, 500.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA208_6C1FE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA30C_6C20EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA390_6C2170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA3F8_6C21D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA46C_6C224C.s")

GObj* func_802DA4B8_6C2298(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E2E04_6CABE4);
}
