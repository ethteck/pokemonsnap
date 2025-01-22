#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "app_render/particle.h"
#include "river.h"

void func_802DB1C4_6C2FA4(GObj*);
void func_802DB270_6C3050(GObj*);
void func_802DB4A8_6C3288(GObj*);
void func_802DB554_6C3334(GObj*);
void func_802DB5C0_6C33A0(GObj*);
void func_802DB630_6C3410(GObj*);
void func_802DB71C_6C34FC(GObj*);
void func_802DB85C_6C363C(GObj*);

extern AnimationHeader D_802E319C_6CAF7C;
extern AnimationHeader D_802E31B0_6CAF90;
extern AnimationHeader D_802E31C4_6CAFA4;
extern AnimationHeader D_802E31D8_6CAFB8;
extern AnimationHeader D_802E31EC_6CAFCC;
extern AnimationHeader D_802E3200_6CAFE0;
extern AnimationHeader D_802E3214_6CAFF4;
extern AnimationHeader D_802E3228_6CB008;
extern InteractionHandler D_802E324C_6CB02C[];
extern RandomState D_802E32BC_6CB09C;
extern Vec3f D_802E32DC_6CB0BC;
extern Vec3f D_802E3308_6CB0E8;
extern PokemonInitData D_802E3328_6CB108;
extern InteractionHandler D_802E328C_6CB06C[];
extern InteractionHandler D_802E32E8_6CB0C8[];

void func_802DB270_6C3050(GObj*);
void func_802DB388_6C3168(GObj*);
void func_802DB41C_6C31FC(GObj*);
void func_802DB8EC_6C36CC(GObj*);

void func_802DB0A0_6C2E80(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    switch (pokemon->behavior) {
        case 1:
        case 2:
            Pokemon_SetState(obj, func_802DB388_6C3168);
            break;
        case 3:
            Pokemon_SetState(obj, func_802DB8EC_6C36CC);
            break;
    }
    Pokemon_SetStateRandom(obj, &D_802E32BC_6CB09C);
}

void func_802DB11C_6C2EFC(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E319C_6CAF7C);
    Pokemon_SetState(obj, func_802DB1C4_6C2FA4);
}

void func_802DB154_6C2F34(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E31B0_6CAF90);
    Pokemon_SetState(obj, func_802DB1C4_6C2FA4);
}

void func_802DB18C_6C2F6C(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E31C4_6CAFA4);
    Pokemon_SetState(obj, func_802DB1C4_6C2FA4);
}

void func_802DB1C4_6C2FA4(GObj* obj) {
    UNUSED s32 pad;
    DObj* model = obj->data.dobj;
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot;
    Pokemon* pokemon = GET_POKEMON(obj);

    rotation->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802DB270_6C3050);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    D_802E28AC_6CA68C = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DB270_6C3050(GObj* obj) {
    DObj* model = obj->data.dobj;
    f32 sp50;
    DObj* temp_s1;
    Pokemon* pokemon = GET_POKEMON(obj);
    Vec3f pos;
    Vec3f vel;
    UNUSED s32 pad[1];
    GroundResult sp28;

    vel = D_802E32DC_6CB0BC;
    temp_s1 = model->firstChild->firstChild->next;
    ohWait(10);

    while (true) {
        fx_getPosVelDObj(&pos, &vel, temp_s1);
        getGroundAt(pos.x, pos.z, &sp28);
        if (!(pos.y < sp28.height)) {
            ohWait(1);
        } else {
            break;
        }
    }
    pos.y = sp28.height;
    if ((sp28.surfaceType == SURFACE_TYPE_337FB2) || (sp28.surfaceType == SURFACE_TYPE_007F66)) {
        func_8035E174_4FE584(obj, &pos);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DB388_6C3168)
    Pokemon_SetAnimation(obj, &D_802E31D8_6CAFB8);
    Pokemon_StartPathProc(obj, func_802DB41C_6C31FC);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->transitionGraph = D_802E324C_6CB02C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DB41C_6C31FC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, TAU, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_802DB468_6C3248(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field1 = false;
    Pokemon_StartAuxProc(obj, func_802DB630_6C3410);
    Pokemon_SetState(obj, func_802DB4A8_6C3288);
}

void func_802DB4A8_6C3288(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E31EC_6CAFCC);
    if (pokemon->behavior == 2) {
        Pokemon_StartPathProc(obj, func_802DB5C0_6C33A0);
    } else {
        Pokemon_StartPathProc(obj, func_802DB554_6C3334);
    }
    pokemon->transitionGraph = D_802E328C_6CB06C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->miscVars[0].field1 = true;
    Pokemon_SetState(obj, func_802DB71C_6C34FC);
}

void func_802DB554_6C3334(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DB5C0_6C33A0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 0, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DB630_6C3410(GObj* obj) {
    f32 temp_f2;
    f32 var_f20;
    f32 var_f22;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);

    var_f20 = 0.0f;
    var_f22 = 0.0f;
    while (!pokemon->miscVars[0].field1) {
        temp_f2 = (-__sinf(var_f20)) * 7.0f;
        transform->pos.v.y += temp_f2 - var_f22;
        var_f22 = temp_f2;
        var_f20 += 2 * PI / 45;
        var_f20 -= (s32) (var_f20 / TAU) * TAU;
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

void func_802DB71C_6C34FC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E3228_6CB008);
    Pokemon_StartPathProc(obj, func_802DB270_6C3050);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DB78C_6C356C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 val = 2;

    Pokemon_SetAnimation(obj, &D_802E3200_6CAFE0);
    Pokemon_StartPathProc(obj, func_802DB270_6C3050);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E3214_6CAFF4);
    Pokemon_StartPathProc(obj, func_802DB85C_6C363C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    D_802E28B0_6CA690 = val;
    if (pokemon->behavior == 2) {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_39, obj);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DB85C_6C363C(GObj* obj) {
    s32 i;
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);

    pokemon->miscVars[0].field1 = true;

    for (i = 59; i > 0; i--) {
        transform->pos.v.y -= 1.0f;
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DB8EC_6C36CC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    pokemon->transitionGraph = D_802E32E8_6CB0C8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802DB93C_6C371C(GObj* obj) {
    DObj* model = obj->data.dobj;
    Mtx3Float* position = &GET_TRANSFORM(model)->pos;
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot;
    Pokemon* pokemon = GET_POKEMON(obj);
    Vec3f sp84 = D_802E3308_6CB0E8;
    GroundResult ground;
    WorldBlock* block;
    s32 i;

    for (i = 0; i < pokemon->path->numPoints; i++) {
        HIDE_POKEMON();
        ohWait(75);
        SHOW_POKEMON();
        block = getCurrentWorldBlock();
        position->v.x = -(block->descriptor->worldPos.x * 100.0f);
        position->v.z = -(block->descriptor->worldPos.z * 100.0f);
        GetInterpolatedPosition(&sp84, pokemon->path, pokemon->path->paramPoints[i]);
        position->v.x = (position->v.x + (sp84.x * 100.0f));
        position->v.z = (position->v.z + (sp84.z * 100.0f));
        getGroundAt(position->v.x, position->v.z, &ground);
        position->v.y = ground.height;
        func_8035E174_4FE584(obj, &position->v);
        Pokemon_ForceAnimation(obj, &D_802E319C_6CAF7C);
        rotation->v.y = (randRange(360) * PI) / 180.0f;
        Pokemon_StartPathProc(obj, func_802DB270_6C3050);
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DBB54_6C3934(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E3328_6CB108);
}
