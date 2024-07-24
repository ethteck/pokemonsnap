#include "common.h"
#include "beach.h"

void func_beach_802C5620(GObj* arg0) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (true) {
        getLevelProgress(&sp34, &sp30);
        if (sp34 > 3 || (sp34 == 3 && sp30 >= 0.3)) {
            break;
        }
        ohWait(1);
    }
    Pokemon_RunCleanup(arg0);
    Pokemon_StopAuxProc(arg0);
}

void func_beach_802C56C8(GObj* obj) {
    Pokemon_StartAuxProc(obj, func_beach_802C5620);
    Pokemon_SetState(obj, func_beach_802C5700);
}

void func_beach_802C5700(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 8;
    Pokemon_SetAnimation(obj, &D_beach_802CC10C);
    pokemon->transitionGraph = D_beach_802CC1D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC2C4);
}

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D690/func_beach_802C5768.s")
#else
void func_beach_802C5768(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CC120);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_beach_802CC1AC);
    pokemon->flags &= ~0x8;
    pokemon->transitionGraph = D_beach_802CC1D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_beach_802CC1C0);
    pokemon->flags |= 8;
    pokemon->transitionGraph = D_beach_802CC1D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC2C4);
}
#endif

void func_beach_802C5828(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CC134);
    pokemon->transitionGraph = D_beach_802CC1D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C5700);
}

void func_beach_802C5884(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 8;
    Pokemon_SetState(obj, func_beach_802C5768);
}

void func_beach_802C58B8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 8;
    Pokemon_SetState(obj, func_beach_802C5828);
}

void func_beach_802C58EC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags &= ~8;
    Pokemon_SetAnimation(obj, &D_beach_802CC148);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C594C);
}

void func_beach_802C594C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC170);
    Pokemon_StartPathProc(obj, func_beach_802C5B68);
    pokemon->transitionGraph = D_beach_802CC234;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C5BD4);
}

void func_beach_802C59C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags &= ~8;
    Pokemon_SetAnimation(obj, &D_beach_802CC148);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C5A20);
}

void func_beach_802C5A20(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC184);
    Pokemon_StartPathProc(obj, func_beach_802C5B68);
    pokemon->transitionGraph = D_beach_802CC264;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C5BD4);
}

void func_beach_802C5A94(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags &= ~8;
    Pokemon_SetAnimation(obj, &D_beach_802CC148);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C5AF4);
}

void func_beach_802C5AF4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC198);
    Pokemon_StartPathProc(obj, func_beach_802C5B68);
    pokemon->transitionGraph = D_beach_802CC294;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C5BD4);
}

void func_beach_802C5B68(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (1) {
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_beach_802C5BD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC15C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C5700);
}

void func_beach_802C5C28(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CC2F0);
}
