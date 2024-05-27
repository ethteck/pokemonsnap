#include "common.h"
#include "world/world.h"

extern AnimationHeader D_802E2C1C_6CA9FC;
extern AnimationHeader D_802E2C30_6CAA10;
extern AnimationHeader D_802E2C94_6CAA74;
extern idFuncStruct D_802E2CA8_6CAA88;
extern randomTransition D_802E2D18_6CAAF8;
extern PokemonInitData D_802E2E04_6CABE4;

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802D9F80_6C1D60.s")

void func_802D9FDC_6C1DBC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E2C1C_6CA9FC);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2CA8_6CAA88;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2D18_6CAAF8);
}

void func_802DA04C_6C1E2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E2C30_6CAA10);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2CA8_6CAA88;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2D18_6CAAF8);
}

void func_802DA0BC_6C1E9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E2C94_6CAA74);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802E2CA8_6CAA88;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802E2D18_6CAAF8);
}

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

void func_802DA46C_6C224C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8036148C_50189C(obj, 0.1f, 0x2E);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

GObj* func_802DA4B8_6C2298(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return spawnPokemonOnGround(objID, id, block, blockB, spawn, &D_802E2E04_6CABE4);
}
