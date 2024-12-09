#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

void func_802C33E4_645894(GObj*);

extern s16 D_802C6354_648804;
extern GObj* D_802C75EC_649A9C;
extern GObj* D_802C75F0_649AA0;
extern AnimationHeader D_802C779C_649C4C;
extern PokemonInitData D_802C77FC_649CAC;
extern AnimationHeader D_802C7880_649D30;
extern AnimationHeader D_802C78BC_649D6C;
extern AnimationHeader D_802C78D0_649D80;
extern f32 D_802C7980_649E30;
extern InteractionHandler4 D_802C7984_649E34;

void func_802C3348_6457F8(GObj*);
void func_802C34E0_645990(GObj*);
void func_802C3494_645944(GObj*);
void func_802C3580_645A30(GObj*);
void func_802C3658_645B08(GObj*);
void func_802C36F0_645BA0(GObj*);
void func_802C3784_645C34(GObj*);

void func_802C3290_645740(GObj* obj) {
    UNUSED s32 pad[1];
    DObj* dobj = obj->data.dobj;
    Mtx4Float* rot = &GET_TRANSFORM(dobj)->rot;
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C779C_649C4C);
    rot->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802C3348_6457F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    D_802C6354_648804 = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C3348_6457F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035E298_4FE6A8(obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802C3388_645838(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C77FC_649CAC);
}

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

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3580_645A30.s")
#else
void func_802C3580_645A30(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon;
    PokemonTransform* transform1; // TODO likely not transforms
    PokemonTransform* transform2; // TODO likely not transforms
    Mtx3Float* pos1;
    Mtx3Float* pos2;
    Mtx4Float* rot1;
    Mtx4Float* rot2;

    transform1 = GET_TRANSFORM(dobj);                         // TODO likely not transforms
    transform2 = GET_TRANSFORM(D_802C75EC_649A9C->data.dobj); // TODO likely not transforms

    pokemon = GET_POKEMON(obj);

    pos1 = &transform1->pos;
    rot1 = &transform1->rot;

    pos2 = &transform2->pos;
    rot2 = &transform2->rot;

    while (D_802C75EC_649A9C != NULL) {
        pos1->v.x = pos2->v.x;
        pos1->v.y = pos2->v.y - 50.0f;
        pos1->v.z = pos2->v.z;
        rot1->v.y = rot2->v.y;
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}
#endif

void func_802C3658_645B08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon = obj->userData;
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    while (D_802C75F0_649AA0 == NULL) {
        ohWait(1);
    }
    pokemon->tangible = true;
    obj->flags = 0;
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

#ifndef NON_MATCHING
#pragma GLOBAL_ASM("asm/nonmatchings/cave/645740/func_802C3784_645C34.s")
#else
void func_802C3784_645C34(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon;
    PokemonTransform* transform1; // TODO likely not transforms
    PokemonTransform* transform2; // TODO likely not transforms
    Mtx3Float* pos1;
    Mtx3Float* pos2;
    Mtx4Float* rot1;
    Mtx4Float* rot2;

    transform1 = GET_TRANSFORM(dobj);                         // TODO likely not transforms
    transform2 = GET_TRANSFORM(D_802C75F0_649AA0->data.dobj); // TODO likely not transforms

    pokemon = GET_POKEMON(obj);

    pos1 = &transform1->pos;
    rot1 = &transform1->rot;

    pos2 = &transform2->pos;
    rot2 = &transform2->rot;

    while (true) {
        pos1->v.x = pos2->v.x;
        pos1->v.y = pos2->v.y - 50.0f;
        pos1->v.z = pos2->v.z;
        rot1->v.y = rot2->v.y;
        ohWait(1);
    }
}
#endif

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
