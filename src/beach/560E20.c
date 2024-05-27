#include "common.h"
#include "beach.h"

void func_beach_802C8DB0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field0 = pokemon->collisionRadius;
    pokemon->collisionRadius = 0;
    Pokemon_SetState(obj, func_beach_802C8DE8);
}

void func_beach_802C8DE8(GObj* obj) {
    Pokemon_StartPathProc(obj, func_beach_802C8E20);
    Pokemon_SetState(obj, func_beach_802C8E90);
}

void func_beach_802C8E20(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 0, 0.1f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/beach/560E20/func_beach_802C8E90.s")

void func_beach_802C8F48(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_beach_802C907C);
    Pokemon_SetAnimation(obj, &D_beach_802CD168);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CD1A4);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CD190);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_30, obj);
    Pokemon_SetAnimation(obj, &D_beach_802CD17C);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_StartPathProc(obj, func_beach_802C90E0);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, func_beach_802C8F48);
}

void func_beach_802C907C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 100.0f;
    Pokemon_Jump(obj, 150.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C90E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (FALSE) {
    }

    pokemon->hSpeed = 200.0f;
    pokemon->jumpVel = 90.0f;
    Pokemon_Jump(obj, 2000.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C914C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (FALSE) {
    }

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 150.0f;
    Pokemon_Fall(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    pokemon->jumpVel = 150.0f;
    Pokemon_Jump(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C91CC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}

void func_beach_802C9204(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}
