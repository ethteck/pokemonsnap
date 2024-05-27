#include "common.h"
#include "beach.h"

void func_beach_802C82B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    obj->flags |= GOBJ_FLAG_HIDDEN;
    Pokemon_StartPathProc(obj, func_beach_802C8438);
    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_4);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_ENDED;
    pokemon->transitionGraph = D_beach_802CCF44;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8354(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= 0x200;
    obj->flags = 0;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_ENDED;
    Pokemon_SetAnimation(obj, &D_beach_802CCF00);
    pokemon->transitionGraph = D_beach_802CCF14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C83D0);
}

void func_beach_802C83D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CCEB0);
    pokemon->transitionGraph = D_beach_802CCF14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, 0);
}

void func_beach_802C8438(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1.0f, 0.1f, 0.0f, WALK_FLAG_2 | WALK_FLAG_1);
    pokemon->pathProc = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(0);
}

void func_beach_802C84A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_ENDED;
    Pokemon_SetAnimation(obj, &D_beach_802CCEC4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCED8);
    // clang-format off
    pokemon->counter = 120; pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_4;
    // clang-format on
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_4);
    Pokemon_SetAnimation(obj, &D_beach_802CCEEC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_ENDED;
    Pokemon_SetState(obj, func_beach_802C83D0);
}

void func_beach_802C8570(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CCF78);
}
