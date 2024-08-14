#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

extern AnimationHeader D_802C75D8_649A88;
extern GObj* D_802C75EC_649A9C;
extern GObj* D_802C75F0_649AA0;
extern InteractionHandler D_802C7614_649AC4[];
extern InteractionHandler D_802C7634_649AE4[];
extern InteractionHandler2 D_802C7674_649B24;
extern InteractionHandler D_802C7694_649B44[];
extern InteractionHandler4 D_802C76D4_649B84;
extern PokemonInitData D_802C7728_649BD8;

void func_802C2AC4_644F74(GObj* obj);
void func_802C2B0C_644FBC(GObj* obj);
void func_802C2B54_645004(GObj* obj);
void func_802C2B9C_64504C(GObj* obj);
void func_802C2BDC_64508C(GObj* obj);
void func_802C2C90_645140(GObj* obj);
void func_802C2D00_6451B0(GObj* obj);
void func_802C2D6C_64521C(GObj* obj);
void func_802C2E24_6452D4(GObj* obj);
void func_802C2EBC_64536C(GObj* obj);
void func_802C2F48_6453F8(GObj* obj);
void func_802C2FB4_645464(GObj* obj);

void func_802C29D0_644E80(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802C2E24_6452D4);
    }
    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, func_802C2AC4_644F74);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, func_802C2B0C_644FBC);
    }
    if (pokemon->behavior == 6) {
        Pokemon_SetState(obj, func_802C2B54_645004);
    }
    if (pokemon->behavior == 7) {
        Pokemon_SetState(obj, func_802C2FB4_645464);
    }
    Pokemon_SetState(obj, func_802C2BDC_64508C);
}

void func_802C2AC4_644F74(GObj* obj) {
    if (D_8033E138_6C05E8.unk_00_0) {
        Pokemon_SetState(obj, func_802C2B9C_64504C);
    }
    Pokemon_SetState(obj, func_802C2D6C_64521C);
}

void func_802C2B0C_644FBC(GObj* obj) {
    if (D_8033E138_6C05E8.unk_00_1) {
        Pokemon_SetState(obj, func_802C2B9C_64504C);
    }
    Pokemon_SetState(obj, func_802C2D6C_64521C);
}

void func_802C2B54_645004(GObj* obj) {
    if (D_8033E138_6C05E8.unk_00_2) {
        Pokemon_SetState(obj, func_802C2B9C_64504C);
    }
    Pokemon_SetState(obj, func_802C2D6C_64521C);
}

void func_802C2B9C_64504C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = D_802C7614_649AC4;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802C2BDC_64508C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon = obj->userData;
    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_SetAnimation(obj, &D_802C75D8_649A88);

    if (pokemon->behavior == 4 || pokemon->behavior == 5) {
        Pokemon_StartPathProc(obj, func_802C2D00_6451B0);
    } else {
        Pokemon_StartPathProc(obj, func_802C2C90_645140);
    }

    pokemon->transitionGraph = D_802C7634_649AE4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C2D6C_64521C);
}

void func_802C2C90_645140(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 0.0f, 0.13333334f, 0, 2);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C2D00_6451B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C2D6C_64521C(GObj* obj) {
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C2D98_645248(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    switch (pokemon->behavior) {
        case 1:
            D_8033E138_6C05E8.unk_00_0 = true;
            break;
        case 2:
            D_8033E138_6C05E8.unk_00_1 = true;
            break;
        case 3:
            D_8033E138_6C05E8.unk_00_2 = true;
            break;
    }
    Pokemon_StopAuxProc(obj);
}

void func_802C2E24_6452D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler2 sp18 = D_802C7674_649B24;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = sp18.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, func_802C2EBC_64536C);
}

void func_802C2EBC_64536C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    D_802C75EC_649A9C = obj;
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802C75D8_649A88);
    Pokemon_StartPathProc(obj, func_802C2F48_6453F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    D_802C75EC_649A9C = NULL;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C2F48_6453F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C2FB4_645464(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = D_802C7694_649B44;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

// clang-format off
void func_802C2FF4_6454A4(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    InteractionHandler4 sp20 = D_802C76D4_649B84;

    D_802C75F0_649AA0 = obj;
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802C75D8_649A88);
    Pokemon_StartPathProc(obj, func_802C2C90_645140);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C2D6C_64521C);
}

void func_802C30B8_645568(GObj* obj) {
    UNUSED s32 pad[3];
    DObj* dobj = obj->data.dobj;
    GroundResult ground;
    PokemonTransform* transform;

    transform = GET_TRANSFORM(dobj);
    EnvSound_PlaySound(obj, 0, 0x107);
    do {
        getGroundAt(transform->pos.v.x, transform->pos.v.z, &ground);
        transform->pos.v.y += 10.0f;
        ohWait(1);
    } while (transform->pos.v.y - ground.height < 3500.0f);

    cmdSendCommandToLink(3, 0x22, obj);

    do {
        getGroundAt(transform->pos.v.x, transform->pos.v.z, &ground);
        transform->pos.v.y += 10.0f;
        ohWait(1);
    } while (transform->pos.v.y - ground.height < 6000.0f);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

// clang-format off
void func_802C31D0_645680(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 300.0f;
    Pokemon_Fall(obj, 120.0f, 0.0f, 0.0f, 0.0f);
    pokemon->jumpVel = 300.0f;
    Pokemon_Jump(obj, 120.0f, 0.0f, 0.0f, 0.0f);
    Pokemon_StopAuxProc(obj);
}

GObj* func_802C3250_645700(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802C7728_649BD8);
}
