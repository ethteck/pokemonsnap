#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "sys/om.h"
#include "cave.h"

extern AnimationHeader D_802C6A18_648EC8;
extern AnimationHeader D_802C6A2C_648EDC;
extern AnimationHeader D_802C6A40_648EF0;
extern AnimationHeader D_802C6A54_648F04;
extern AnimationHeader D_802C6A68_648F18;
extern AnimationHeader D_802C6A7C_648F2C;
extern AnimationHeader D_802C6A90_648F40;
extern f32 D_802C6AA4_648F54;
extern InteractionHandler D_802C6AA8_648F58[];
extern InteractionHandler D_802C6AD8_648F88[];
extern InteractionHandler D_802C6B08_648FB8[];
extern RandomState D_802C6B28_648FD8;
extern PokemonInitData D_802C6B5C_64900C;

void func_802BF68C_641B3C(GObj*);
void func_802BF750_641C00(GObj*);
void func_802BF9B4_641E64(GObj*);
void func_802BFA8C_641F3C(GObj*);
void func_802BFB24_641FD4(GObj*);
void func_802BFB9C_64204C(GObj*);
void func_802BFC84_642134(GObj*);

void func_802BF5A0_641A50(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 sp3C;
    f32 sp38;

    HIDE_POKEMON();

    while (true) {
        getLevelProgress(&sp3C, &sp38);
        if (sp3C >= 3 || (sp3C == 2 && sp38 >= 0.02)) {
            break;
        }
        ohWait(1);
    }

    SHOW_POKEMON();
    pokemon->forbiddenGround = &D_802C6AA4_648F54;
    if (obj) {
        // TODO required to match
    }
    pokemon->pathParam = 0.0f;
    Pokemon_SetState(obj, func_802BF68C_641B3C);
}

void func_802BF68C_641B3C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[1].field0 = 0.08f;
    Pokemon_ResetPathPos(obj);
    Pokemon_SetAnimation(obj, &D_802C6A40_648EF0);
    Pokemon_StartPathProc(obj, func_802BF750_641C00);
    pokemon->counter = randRange(120) + 120, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802C6AD8_648F88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802BF68C_641B3C);
    }
    Pokemon_SetStateRandom(obj, &D_802C6B28_648FD8);

    if (pokemon) {
        // TODO required to match
    }
}

void func_802BF750_641C00(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_FollowPath(obj, pokemon->pathParam, 0, pokemon->miscVars[1].field0, 0.0f, 3);
    pokemon->pathProc = NULL;
    pokemon->pathParam = 0.0f;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802BF7B4_641C64(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802C6A2C_648EDC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802C6AD8_648F88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802BF68C_641B3C);
}

void func_802BF824_641CD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6A18_648EC8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802C6AD8_648F88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802BF68C_641B3C);
}

// clang-format off
void func_802BF894_641D44(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_SetAnimation(obj, &D_802C6A54_648F04);
    Pokemon_StartPathProc(obj, func_802BF9B4_641E64);
    pokemon->transitionGraph = D_802C6AA8_648F58;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_802C6A68_648F18);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802C6A7C_648F2C);
    if (pokemon->currGround.surfaceType == 0x7F66) {
        cmdSendCommandToLink(3, 0x1D, obj);
        Pokemon_SetState(obj, func_802BFB9C_64204C);
    }
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802C6A90_648F40);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802BFA8C_641F3C);
}

void func_802BF9B4_641E64(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonTransform* temp_v1; // TODO is this a transform?

    pokemon->hSpeed = 200.0f;
    pokemon->jumpVel = 300.0f;
    temp_v1 = (PokemonTransform*) pokemon->interactionTarget->userData;
    pokemon->facingYaw = atan2f(temp_v1->rot.a, temp_v1->rot.v.y);
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802BFA3C_641EEC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* dobj = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(dobj);

    pokemon->pos1.x = transform->pos.v.x;
    pokemon->pos1.y = transform->pos.v.y;
    pokemon->pos1.z = transform->pos.v.z;
    pokemon->miscVars[2].field1 = 0;
    Pokemon_SetState(obj, func_802BF894_641D44);
}

void func_802BFA8C_641F3C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6A40_648EF0);
    Pokemon_StartPathProc(obj, func_802BFB24_641FD4);
    pokemon->transitionGraph = D_802C6AA8_648F58;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802BFA8C_641F3C);
    }
    Pokemon_SetState(obj, func_802BF7B4_641C64);
}

void func_802BFB24_641FD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->miscVars[2].field1 == 0) {
        Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
        pokemon->miscVars[2].field1 = 1;
    }
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802BFB9C_64204C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802C6B08_648FB8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

// clang-format off
void func_802BFBF0_6420A0(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_StartPathProc(obj, func_802BFC84_642134);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    cmdSendCommand(pokemon->interactionTarget, 0x1F, obj);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802BFC84_642134)
    s32 i;
    f32 f20, f22;
    Mtx3Float* targetPos = &(GET_TRANSFORM(pokemon->interactionTarget->data.dobj)->pos);

    f20 = (targetPos->v.x - position->v.x) / 100.0f;
    f22 = (targetPos->v.z - position->v.z) / 100.0f;
    for (i = 0; i < 100; i++) {
        position->v.x += f20;
        position->v.z += f22;
        position->v.y -= 3.0f;
        rotation->v.y += PI / 180.0f;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802BFDA0_642250(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C6B5C_64900C);
}
