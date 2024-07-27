#include "common.h"
#include "beach.h"

#pragma GLOBAL_ASM("asm/nonmatchings/beach/55FB80/func_beach_802C7B10.s")

// clang-format off
void func_beach_802C7BB8(GObj* arg0) { \
    Pokemon* pokemon = GET_POKEMON(arg0);
    // clang-format on
    Pokemon_SetAnimation(arg0, &D_beach_802CCD24);
    pokemon->counter = randRange(600) + 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_beach_802CCD60;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(arg0, &D_beach_802CCD38);
    pokemon->transitionGraph = D_beach_802CCD60;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(arg0, func_beach_802C7BB8);
}

void func_beach_802C7C7C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, randFloat(), 0, 0.1f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C7CF0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_StartAuxProc(obj, func_beach_802C7DA0);
    Pokemon_SetAnimation(obj, &D_beach_802CCD4C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED);
    Pokemon_StartAuxProc(obj, func_beach_802C7DEC);
    Pokemon_SetAnimation(obj, &D_beach_802CCD24);
    pokemon->transitionGraph = D_beach_802CCD60;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED);
    Pokemon_SetState(obj, func_beach_802C7BB8);
}

void func_beach_802C7DA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->jumpVel = 300.0f;
    Pokemon_Jump(obj, 400, 0, 0, 0);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C7DEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->jumpVel = 90.0f;
    Pokemon_Fall(obj, 400, 0, 0, 0);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C7E38(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CCDA4);
}

// TODO: potential file split

void func_beach_802C7E70(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 2 | 1;
    if (pokemon->behavior == 2) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C816C);
    }
    if (pokemon->behavior == 4) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C81C4);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, func_beach_802C821C);
    }
    Pokemon_SetState(obj, func_beach_802C7F1C);
}

void func_beach_802C7F1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartAuxProc(obj, func_beach_802C7F74);
    pokemon->transitionGraph = D_beach_802CCE1C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C7F74(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = 0;
    obj->flags |= 2 | 1;
    Pokemon_ForceAnimation(obj, &D_beach_802CCE08);

    // clang-format off
    pokemon->counter = randRange(600) + 1; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    // clang-format on

    Pokemon_WaitForFlagNoInteraction(obj, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->tangible = 1;
    obj->flags = 0;
    Pokemon_ForceAnimation(obj, &D_beach_802CCDE8);
    Pokemon_WaitForFlagNoInteraction(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartAuxProc(obj, func_beach_802C7F74);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C8028(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 0) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C80BC);
    }
    if (pokemon->behavior == 1) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C80F0);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_beach_802C8124);
    }
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C80BC(GObj* obj) {
    D_beach_802CCDFC++;
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C80F0(GObj* obj) {
    D_beach_802CCE00++;
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8124(GObj* obj) {
    D_beach_802CCE00++;
    D_beach_802CCE04++;
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C816C(GObj* obj) {
    while (true) {
        if (D_beach_802CCDFC > 0) {
            break;
        }

        ohWait(1);
    }

    Pokemon_SetState(obj, func_beach_802C7F1C);
}

void func_beach_802C81C4(GObj* obj) {
    while (true) {
        if (D_beach_802CCE00 > 0) {
            break;
        }

        ohWait(1);
    }

    Pokemon_SetState(obj, func_beach_802C7F1C);
}

void func_beach_802C821C(GObj* obj) {
    while (true) {
        if (D_beach_802CCE04 > 0) {
            break;
        }

        ohWait(1);
    }

    Pokemon_SetState(obj, func_beach_802C7F1C);
}

void func_beach_802C8274(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CCE50);
}
