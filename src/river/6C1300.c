#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern u8 D_802E2620_6CA400;
extern AnimationHeader D_802E29FC_6CA7DC;
extern AnimationHeader D_802E2A10_6CA7F0;
extern AnimationHeader D_802E2A24_6CA804;
extern AnimationHeader D_802E2A38_6CA818;
extern AnimationHeader D_802E2A4C_6CA82C;
extern AnimationHeader D_802E2A60_6CA840;
extern AnimationHeader D_802E2A74_6CA854;
extern AnimationHeader D_802E2A88_6CA868;
extern AnimationHeader D_802E2A9C_6CA87C;
extern AnimationHeader D_802E2AB0_6CA890;
extern InteractionHandler D_802E2AC4_6CA8A4[];
extern RandomState D_802E2B24_6CA904;
extern InteractionHandler D_802E2B3C_6CA91C[];
extern InteractionHandler D_802E2B7C_6CA95C[];
extern InteractionHandler D_802E2B9C_6CA97C[];
extern Vec3f D_802E2BBC_6CA99C;
extern PokemonInitData D_802E2BDC_6CA9BC;

void func_802D990C_6C16EC(GObj*);
void func_802D9A0C_6C17EC(GObj*);
void func_802D9A58_6C1838(GObj*);
void func_802D9C8C_6C1A6C(GObj*);
void func_802D9D7C_6C1B5C(GObj*);
void func_802D9DD8_6C1BB8(GObj*);

s32 func_802D9520_6C1300(GObj* obj) {
    Vec3f sp2C;
    Pokemon* pokemon;
    WorldBlock* worldBlock;
    DObj* model;
    f32 xDiff;
    f32 zDiff;

    sp2C = D_802E2BBC_6CA99C;
    pokemon = GET_POKEMON(obj);
    model = obj->data.dobj;
    worldBlock = getCurrentWorldBlock();

    pokemon->pos1.x = -(worldBlock->descriptor->worldPos.x * 100.0f);
    pokemon->pos1.y = -(worldBlock->descriptor->worldPos.y * 100.0f);
    pokemon->pos1.z = -(worldBlock->descriptor->worldPos.z * 100.0f);

    GetInterpolatedPosition(&sp2C, pokemon->path, 0.99999f);

    pokemon->pos1.x = pokemon->pos1.x + (sp2C.x * 100.0f);
    pokemon->pos1.y = pokemon->pos1.y + (sp2C.y * 100.0f);
    pokemon->pos1.z = pokemon->pos1.z + (sp2C.z * 100.0f);

    xDiff = pokemon->pos1.x - GET_TRANSFORM(model)->pos.v.x;
    zDiff = pokemon->pos1.z - GET_TRANSFORM(model)->pos.v.z;

    if (SQ(xDiff) + SQ(zDiff) < 225000.0f) {
        return false;
    } else {
        return true;
    }
}

void func_802D9664_6C1444(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field0 = pokemon->collisionOffset.y;
    Pokemon_StartAuxProc(obj, func_802D9DD8_6C1BB8);
    Pokemon_StartAuxProc(obj, func_802D9A58_6C1838);
    Pokemon_SetAnimation(obj, &D_802E29FC_6CA7DC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2AC4_6CA8A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E2B24_6CA904);
}

void func_802D96FC_6C14DC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E29FC_6CA7DC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2AC4_6CA8A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802E2B24_6CA904);
}

void func_802D976C_6C154C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;

    pokemon->collisionOffset.y = 108.0f / (GET_TRANSFORM(model)->scale.v.y / 0.1f);
    Pokemon_ForceAnimation(obj, &D_802E2A10_6CA7F0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2AC4_6CA8A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->collisionOffset.y = pokemon->miscVars[0].field0;
    Pokemon_SetStateRandom(obj, &D_802E2B24_6CA904);
}

void func_802D9808_6C15E8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->collisionOffset.y = pokemon->miscVars[0].field0;
    Pokemon_SetAnimation(obj, &D_802E2A24_6CA804);
    Pokemon_StartPathProc(obj, func_802D990C_6C16EC);
    pokemon->transitionGraph = D_802E2B3C_6CA91C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802D96FC_6C14DC);
    }
    Pokemon_SetAnimation(obj, &D_802E2A4C_6CA82C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 112, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;

    pokemon->transitionGraph = D_802E2B7C_6CA95C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_EatApple(obj);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D96FC_6C14DC);
}

void func_802D990C_6C16EC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    Pokemon_SetAnimation(obj, &D_802E2A38_6CA818);
    pokemon->hSpeed = 100.0f;
    Pokemon_RunToTarget(obj, 90.0f, 0.1f, 3);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D9990_6C1770(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->collisionOffset.y = pokemon->miscVars[0].field0;
    Pokemon_SetAnimation(obj, &D_802E2A24_6CA804);
    Pokemon_StartPathProc(obj, func_802D9A0C_6C17EC);
    pokemon->transitionGraph = D_802E2B9C_6CA97C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802D96FC_6C14DC);
}

void func_802D9A0C_6C17EC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0x2E);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D9A58_6C1838(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[1].field1 = 1;
    do {
        if (func_802D9520_6C1300(obj) == 0) {
            cmdSendCommand(obj, 0x1C, obj);
        }
        ohWait(1);
    } while (pokemon->miscVars[1].field1 != 0);
    Pokemon_StopAuxProc(obj);
}

void func_802D9AC4_6C18A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[1].field1 = 0;
    pokemon->collisionOffset.y = (f32) pokemon->miscVars[0].field0;
    Pokemon_SetAnimation(obj, &D_802E2A9C_6CA87C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E2A38_6CA818);
    pokemon->hSpeed = 100.0f;
    Pokemon_StartPathProc(obj, func_802D9D7C_6C1B5C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_802E2A24_6CA804);
    Pokemon_StartPathProc(obj, func_802D9C8C_6C1A6C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_802E2A60_6CA840);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E2A74_6CA854);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    omCreateProcess(obj, func_802D8A48_6C0828, 1, 1);
    Pokemon_SetAnimation(obj, &D_802E2AB0_6CA890);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    omCreateProcess(obj, func_802DFF94_6C7D74, 1, 1);
    Pokemon_SetAnimation(obj, &D_802E2A88_6CA868);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    func_802D8B34_6C0914(obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802D9C8C_6C1A6C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    f32 temp_f20;
    f32 temp_f2;
    Vec3f sp34;

    GetInterpolatedVelocity(&sp34, pokemon->path, 0.99999f);
    temp_f2 = atan2f(sp34.x, sp34.z) + PI;
    temp_f20 = temp_f2 - ((s32) (temp_f2 / TAU) * TAU);
    while (!Pokemon_Turn(model, temp_f20, PI / 90)) {
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D9D7C_6C1B5C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D9DD8_6C1BB8(GObj* obj) {
    f32 playerDist;
    s32 var_s0;
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    var_s0 = 0;

    while (true) {
        playerDist = pokemon->playerDist;
        if (playerDist < 200.0f) {
            if (playerDist < 100.0f) {
                var_s0 = 127;
            } else {
                var_s0 = (u8) (((200.0f - playerDist) * 127.0f) / 100.0f);
            }
        }
        if (D_802E2620_6CA400 < var_s0) {
            D_802E2620_6CA400 = var_s0;
        }
        ohWait(1);
    }
}

GObj* func_802D9F44_6C1D24(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2BDC_6CA9BC);
}
