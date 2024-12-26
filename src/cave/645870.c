#include "common.h"
//#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

extern GObj* D_802C75EC_649A9C;
extern GObj* D_802C75F0_649AA0;
extern AnimationHeader D_802C7880_649D30;
extern AnimationHeader D_802C78BC_649D6C;
extern AnimationHeader D_802C78D0_649D80;
extern f32 D_802C7980_649E30;
extern InteractionHandler4 D_802C7984_649E34;

void func_802C33E4_645894(GObj*);
void func_802C34E0_645990(GObj*);
void func_802C3494_645944(GObj*);
void func_802C3580_645A30(GObj*);
void func_802C3658_645B08(GObj*);
void func_802C36F0_645BA0(GObj*);
void func_802C3784_645C34(GObj*);

void func_802C33C0_645870(GObj* arg0) {
    Pokemon_SetState(arg0, func_802C33E4_645894);
}

void func_802C33E4_645894(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->forbiddenGround = &D_802C7980_649E30;
    Pokemon_SetAnimation(obj, &D_802C7880_649D30);
    Pokemon_StartPathProc(obj, func_802C3494_645944);

    while (true) {
        if (D_802C75EC_649A9C != NULL) {
            if (Pokemon_GetDistance(obj, D_802C75EC_649A9C) < 100.0f) {
                break;
            }
        }
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C34E0_645990);
}

void func_802C3494_645944(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_802C34E0_645990(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_SetAnimation(obj, &D_802C78BC_649D6C);
    Pokemon_StartPathProc(obj, func_802C3580_645A30);
    pokemon->counter = 2, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    EnvSound_PlaySound(obj, 0, 0x107);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C3658_645B08);
}

POKEMON_FUNC(func_802C3580_645A30)
    Mtx3Float* pos2 = &GET_TRANSFORM(D_802C75EC_649A9C->data.dobj)->pos;
    Mtx4Float* rot2 = &GET_TRANSFORM(D_802C75EC_649A9C->data.dobj)->rot;

    while (D_802C75EC_649A9C != NULL) {
        position->v.x = pos2->v.x;
        position->v.y = pos2->v.y - 50.0f;
        position->v.z = pos2->v.z;
        rotation->v.y = rot2->v.y;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C3658_645B08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    while (D_802C75F0_649AA0 == NULL) {
        ohWait(1);
    }
    SHOW_POKEMON();
    Pokemon_StartPathProc(obj, func_802C3784_645C34);
    Pokemon_SetState(obj, func_802C36F0_645BA0);
}

void func_802C36F0_645BA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler4 sp18;

    sp18 = D_802C7984_649E34;

    Pokemon_ForceAnimation(obj, &D_802C7880_649D30);
    pokemon->transitionGraph = sp18.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C36F0_645BA0);
}

POKEMON_FUNC(func_802C3784_645C34)
    Mtx3Float* pos2 = &GET_TRANSFORM(D_802C75F0_649AA0->data.dobj)->pos;
    Mtx4Float* rot2 = &GET_TRANSFORM(D_802C75F0_649AA0->data.dobj)->rot;

    while (true) {
        position->v.x = pos2->v.x;
        position->v.y = pos2->v.y - 50.0f;
        position->v.z = pos2->v.z;
        rotation->v.y = rot2->v.y;
        ohWait(1);
    }
}

void func_802C3840_645CF0(GObj* obj) {
    cmdSendCommandToLink(3, 0x21, obj);
    Pokemon_StopAuxProc(obj);
}

void func_802C3874_645D24(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C78D0_649D80);
    Pokemon_StartPathProc(obj, func_802C38E0_645D90);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C39B8_645E68);
}
