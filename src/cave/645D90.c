#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

extern AnimationHeader D_802C7880_649D30;
extern AnimationHeader D_802C7894_649D44;
extern AnimationHeader D_802C78BC_649D6C;
extern AnimationHeader D_802C78D0_649D80;
extern AnimationHeader D_802C78E4_649D94;
extern AnimationHeader D_802C790C_649DBC;
extern AnimationHeader D_802C7934_649DE4;
extern f32 D_802C7980_649E30;
extern Vec3f D_802C79C4_649E74;
extern InteractionHandler8 D_802C79D0_649E80;
extern InteractionHandler5 D_802C7A50_649F00;
extern PokemonInitData D_802C7AB4_649F64;
extern GObj* D_802C7B4C_649FFC;
extern GObj* D_802C7C3C_64A0EC;

void func_802C3A44_645EF4(GObj*);
void func_802C3B34_645FE4(GObj*);
void func_802C3B68_646018(GObj*);
void func_802C3C40_6460F0(GObj*);
void func_802C3D44_6461F4(GObj*);
void func_802C3DFC_6462AC(GObj*);
void func_802C3F6C_64641C(GObj*);
void func_802C4090_646540(GObj*);
void func_802C41D0_646680(GObj*);
void func_802C4264_646714(GObj*);
void func_802C433C_6467EC(GObj*);
void func_802C4378_646828(GObj*);

void func_802C38E0_645D90(GObj* obj) {
    UNUSED s32 pad[2];
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    GroundResult ground;
    PokemonTransform* transform;
    f32 yDist;

    transform = GET_TRANSFORM(dobj);
    pokemon->miscVars[0].field0 = 0.0f;
    do {
        transform->pos.v.y += pokemon->miscVars[0].field0;
        pokemon->miscVars[0].field0 += -0.64680004f;
        getGroundAt(transform->pos.v.x, transform->pos.v.z, &ground);
        yDist = transform->pos.v.y - ground.height;
        ohWait(1);
    } while (yDist > 2100.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C39B8_645E68(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->specialPoseID = 3;
    Pokemon_SetAnimation(obj, &D_802C7934_649DE4);
    Pokemon_StartAuxProc(obj, func_802C3B34_645FE4);
    Pokemon_StartPathProc(obj, func_802C3A44_645EF4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->specialPoseID = 0;
    Pokemon_SetState(obj, func_802C3B68_646018);
}

void func_802C3A44_645EF4(GObj* obj) {
    UNUSED s32 pad[2];
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    GroundResult ground;
    PokemonTransform* transform;
    f32 yDist;

    transform = GET_TRANSFORM(dobj);
    do {
        if (pokemon->miscVars[0].field0 < -1.2f) {
            pokemon->miscVars[0].field0 += 0.8f;
        } else {
            pokemon->miscVars[0].field0 = -1.2f;
        }
        transform->pos.v.y += pokemon->miscVars[0].field0;
        ohWait(1);
        getGroundAt(transform->pos.v.x, transform->pos.v.z, &ground);
        yDist = transform->pos.v.y - ground.height;
    } while (yDist > 0.0f);

    transform->pos.v.y = ground.height;
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C3B34_645FE4(GObj* obj) {
    Pokemon_TurnToTarget(obj, 0.1f, 0x20);
    Pokemon_StopAuxProc(obj);
}

// clang-format off
void func_802C3B68_646018(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_SetAnimation(obj, &D_802C7880_649D30);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802C78BC_649D6C);
    Pokemon_StartPathProc(obj, func_802C3C40_6460F0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->interactionTarget = D_802C7C3C_64A0EC;
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetAnimation(obj, &D_802C790C_649DBC);
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    }
    Pokemon_SetState(obj, func_802C3D44_6461F4);
}

void func_802C3C40_6460F0(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    PokemonTransform* sp48 = GET_TRANSFORM(dobj);
    UNUSED s32 pad[2];
    Vec3f sp34;
    f32 z;
    Pokemon* pokemon = GET_POKEMON(obj);
    f32 x;
    WorldBlockDescriptor* blockDesc;

    sp34 = D_802C79C4_649E74;

    GetInterpolatedPosition(&sp34, pokemon->path, 0.99999f);
    blockDesc = getCurrentWorldBlock()->descriptor;
    x = (sp34.x - blockDesc->worldPos.x) * 100.0f;
    z = (sp34.z - blockDesc->worldPos.z) * 100.0f;
    pokemon->hSpeed = 320.0f;
    Pokemon_SetTargetPos(obj, x, z);
    Pokemon_RunToTargetPos(obj, 0.1f);
    sp48->pos.v.x = x;
    sp48->pos.v.z = z;
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C3D44_6461F4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler8 sp20;

    sp20 = D_802C79D0_649E80;
    Pokemon_ForceAnimation(obj, &D_802C7880_649D30);
    Pokemon_StartPathProc(obj, func_802C3DFC_6462AC);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C3D44_6461F4);
}

void func_802C3DFC_6462AC(GObj* obj) {
    while (true) {
        if (D_8033E138_6C05E8.unk_01_2) {
            cmdSendCommand(obj, 0x23, obj);
        }
        ohWait(1);
    }
}

void func_802C3E74_646324(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C78D0_649D80);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C3D44_6461F4);
}

void func_802C3EDC_64638C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802C7894_649D44);
    Pokemon_StartPathProc(obj, func_802C3F6C_64641C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802C3D44_6461F4);
    }
    Pokemon_SetState(obj, func_802C3EDC_64638C);
}

void func_802C3F6C_64641C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (true) {
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_802C3FD8_646488(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler5 sp20 = D_802C7A50_649F00;

    Pokemon_ForceAnimation(obj, &D_802C78E4_649D94);
    Pokemon_StartPathProc(obj, func_802C4090_646540);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C3FD8_646488);
}

void func_802C4090_646540(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (true) {
        if (D_802C7B4C_649FFC != NULL && Pokemon_GetDistance(obj, D_802C7B4C_649FFC) < 160.0f) {
            break;
        }
        ohWait(1);
    }

    cmdSendCommand(obj, 0x24, obj);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_802C413C_6465EC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->forbiddenGround = &D_802C7980_649E30;
    Pokemon_SetAnimation(obj, &D_802C78BC_649D6C);
    Pokemon_StartPathProc(obj, func_802C4378_646828);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->specialPoseID = 6;
    Pokemon_StartPathProc(obj, func_802C4264_646714);
    Pokemon_SetState(obj, func_802C41D0_646680);
}

void func_802C41D0_646680(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802C790C_649DBC);
    Pokemon_StartAuxProc(obj, func_802C433C_6467EC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802C41D0_646680);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802C4264_646714)
    Mtx3Float* targetPos = &(GET_TRANSFORM(D_802C7B4C_649FFC->data.dobj)->pos);
    Mtx4Float* targetRot = &(GET_TRANSFORM(D_802C7B4C_649FFC->data.dobj)->rot);

    while (D_802C7B4C_649FFC != NULL) {
        position->v.x = targetPos->v.x;
        position->v.y = targetPos->v.y + 150.0f;
        position->v.z = targetPos->v.z;
        rotation->v.y = targetRot->v.y;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C433C_6467EC(GObj* obj) {
    ohWait(2);
    EnvSound_PlaySound(obj, 0, 0x109);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802C4378_646828)
    Mtx3Float* targetPos = &(GET_TRANSFORM(D_802C7B4C_649FFC->data.dobj)->pos);
    f32 dx, dy, dz;

    dx = targetPos->v.x - position->v.x;
    dy = targetPos->v.y + 150.0f - position->v.y;
    dz = targetPos->v.z - position->v.z;

    while (dx != 0 || dy != 0 || dz != 0) {
        if (ABS(dx) < 3.0f) {
            dx = 0;
        } else if (dx > 0) {
            dx -= 3.0f;
        } else {
            dx += 3.0f;
        }

        if (ABS(dy) < 15.0f) {
            dy = 0;
        } else if (dy > 0) {
            dy -= 15.0f;
        } else {
            dy += 15.0f;
        }

        if (ABS(dz) < 3.0f) {
            dz = 0;
        } else if (dz > 0) {
            dz -= 3.0f;
        } else {
            dz += 3.0f;
        }

        position->v.x = targetPos->v.x - dx;
        position->v.y = targetPos->v.y + 150.0f - dy;
        position->v.z = targetPos->v.z - dz;
        ohWait(1);
    }

    position->v.x = targetPos->v.x;
    position->v.z = targetPos->v.z;
    position->v.y = targetPos->v.y + 150.0f;

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_802C45EC_646A9C(void) {
}

void func_802C45F4_646AA4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 1.0f, 0.016666668f, 0, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802C465C_646B0C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C7AB4_649F64);
}
