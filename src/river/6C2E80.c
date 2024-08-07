#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

void func_802DB1C4_6C2FA4(GObj*);
void func_802DB270_6C3050(GObj*);
void func_802DB4A8_6C3288(GObj*);
void func_802DB554_6C3334(GObj*);
void func_802DB5C0_6C33A0(GObj*);
void func_802DB630_6C3410(GObj*);
void func_802DB71C_6C34FC(GObj*);
void func_802DB85C_6C363C(GObj*);

extern s16 D_802E28B0_6CA690;

extern AnimationHeader D_802E319C_6CAF7C;
extern AnimationHeader D_802E31B0_6CAF90;
extern AnimationHeader D_802E31C4_6CAFA4;
extern AnimationHeader D_802E31EC_6CAFCC;
extern AnimationHeader D_802E3200_6CAFE0;
extern AnimationHeader D_802E3214_6CAFF4;
extern AnimationHeader D_802E3228_6CB008;
extern PokemonInitData D_802E3328_6CB108;
extern InteractionHandler D_802E328C_6CB06C[];
extern InteractionHandler D_802E32E8_6CB0C8[];

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB0A0_6C2E80.s")

void func_802DB11C_6C2EFC(GObj* arg0) {
    Pokemon_SetAnimation(arg0, &D_802E319C_6CAF7C);
    Pokemon_SetState(arg0, func_802DB1C4_6C2FA4);
}

void func_802DB154_6C2F34(GObj* arg0) {
    Pokemon_SetAnimation(arg0, &D_802E31B0_6CAF90);
    Pokemon_SetState(arg0, func_802DB1C4_6C2FA4);
}

void func_802DB18C_6C2F6C(GObj* arg0) {
    Pokemon_SetAnimation(arg0, &D_802E31C4_6CAFA4);
    Pokemon_SetState(arg0, func_802DB1C4_6C2FA4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB1C4_6C2FA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB270_6C3050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB388_6C3168.s")

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

    pokemon->miscVars[0].field1 = 0;
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
    pokemon->miscVars[0].field1 = 1;
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

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB630_6C3410.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB85C_6C363C.s")

void func_802DB8EC_6C36CC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->transitionGraph = D_802E32E8_6CB0C8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C2E80/func_802DB93C_6C371C.s")

GObj* func_802DBB54_6C3934(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E3328_6CB108);
}
