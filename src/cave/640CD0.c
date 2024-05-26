#include "common.h"
#include "world/world.h"

void func_802BED04_6411B4(GObj*);

extern AnimationHeader D_802C6538_6489E8;
extern AnimationHeader D_802C654C_6489FC;
extern AnimationHeader D_802C6560_648A10;
extern idFuncStruct D_802C65E8_648A98;
extern randomTransition D_802C67E8_648C98;
extern PokemonInitData D_802C6824_648CD4;

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BE820_640CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/cave/640CD0/func_802BE898_640D48.s")

void func_802BE8D4_640D84(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802C6538_6489E8);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802C65E8_648A98;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802C67E8_648C98);
}

void func_802BE944_640DF4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802C654C_6489FC);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802C65E8_648A98;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802C67E8_648C98);
}

void func_802BE9B4_640E64(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802C6560_648A10);
    runPathProcess(obj, NULL);
    pokemon->transitionGraph = &D_802C65E8_648A98;
    runInteractionsAndWaitForFlags(obj, 1);
    weightedRandomStaightTransition(obj, &D_802C67E8_648C98);
}

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

void func_802BECA8_641158(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    func_8036194C_501D5C(obj, 300.0f, 0.1f, 1);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= 2;
    omEndProcess(NULL);
}

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
