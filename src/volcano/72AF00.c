#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802DA3A0_72B5A0(GObj*);

extern AnimationHeader D_802E1FF8_7331F8;
extern AnimationHeader D_802E2034_733234;
extern InteractionHandler D_802E2098_733298[];
extern InteractionHandler D_802E21D8_7333D8[];
extern RandomState D_802E22D8_7334D8[];
extern PokemonInitData D_802E2358_733558;

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9D00_72AF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9DFC_72AFFC.s")

void func_802D9E7C_72B07C(GObj* arg0) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (true) {
        getLevelProgress(&sp34, &sp30);
        if (sp34 > 4 || (sp34 == 4 && sp30 >= 0.1)) {
            break;
        }
        ohWait(1);
    }
    Pokemon_RunCleanup(arg0);
    Pokemon_StopAuxProc(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802D9F24_72B124.s")

void func_802D9F90_72B190(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1FF8_7331F8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2098_733298;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E22D8_7334D8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA000_72B200.s")

void func_802DA0A4_72B2A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA100_72B300.s")

void func_802DA1A4_72B3A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA200_72B400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA2C8_72B4C8.s")

void func_802DA330_72B530(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2034_733234);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E21D8_7333D8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D9F90_72B190);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA3A0_72B5A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA428_72B628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA4AC_72B6AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA55C_72B75C.s")

void func_802DA5B4_72B7B4(GObj* arg0) {
    Pokemon_SetState(arg0, func_802DA3A0_72B5A0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA5D8_72B7D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA640_72B840.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA68C_72B88C.s")

void func_802DA748_72B948(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA7A4_72B9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA848_72BA48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA8A4_72BAA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA930_72BB30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DA97C_72BB7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/72AF00/func_802DAA34_72BC34.s")

GObj* func_802DAA9C_72BC9C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2358_733558);
}
