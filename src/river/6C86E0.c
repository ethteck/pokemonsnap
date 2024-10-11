#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E46D0_6CC4B0;
extern AnimationHeader D_802E46E4_6CC4C4;
extern AnimationHeader D_802E46F8_6CC4D8;
extern AnimationHeader D_802E470C_6CC4EC;
extern AnimationHeader D_802E4720_6CC500;
extern AnimationHeader D_802E4734_6CC514;
extern AnimationHeader D_802E4748_6CC528;
extern AnimationHeader D_802E475C_6CC53C;
extern AnimationHeader D_802E4770_6CC550;
extern AnimationHeader D_802E4784_6CC564;
extern InteractionHandler D_802E4838_6CC618[];
extern InteractionHandler D_802E48B8_6CC698[];
extern InteractionHandler D_802E4908_6CC6E8[];
extern InteractionHandler D_802E4938_6CC718[];
extern InteractionHandler D_802E49A0_6CC780[];
extern InteractionHandler D_802E49E0_6CC7C0[];
extern InteractionHandler D_802E4A10_6CC7F0[];
extern InteractionHandler2 D_802E4A40_6CC820;
extern RandomState D_802E4978_6CC758[];
extern f32 D_802E4A60_6CC840;
extern PokemonInitData D_802E4AA8_6CC888;

void func_802E0A48_6C8828(GObj*);
void func_802E0C3C_6C8A1C(GObj*);
void func_802E0E20_6C8C00(GObj*);
void func_802E0F04_6C8CE4(GObj*);
void func_802E0F9C_6C8D7C(GObj*);
void func_802E1030_6C8E10(GObj*);
void func_802E1110_6C8EF0(GObj*);
void func_802E115C_6C8F3C(GObj*);
void func_802E1194_6C8F74(GObj*);
void func_802E12D8_6C90B8(GObj*);
void func_802E1374_6C9154(GObj*);
void func_802E142C_6C920C(GObj*);
void func_802E1488_6C9268(GObj*);
void func_802E1570_6C9350(GObj*);
void func_802E1594_6C9374(GObj*);
void func_802E1604_6C93E4(GObj*);
void func_802E17D4_6C95B4(GObj*);

void func_802E0900_6C86E0(GObj* obj) {
    UNUSED s32 pad[4];
    s32 sp34;
    f32 sp30;

    while (true) {
        getLevelProgress(&sp34, &sp30);
        if ((sp34 < 3) && ((sp34 != 2) || !(sp30 >= 0.9))) {
            ohWait(1);
        } else {
            break;
        }
    }
    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

void func_802E09A8_6C8788(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartAuxProc(obj, func_802E0900_6C86E0);
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802E115C_6C8F3C);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802E1570_6C9350);
    }
    Pokemon_SetState(obj, func_802E0A48_6C8828);
}

void func_802E0A48_6C8828(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E46D0_6CC4B0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E4838_6CC618;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E4978_6CC758);
}

void func_802E0AB8_6C8898(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E46E4_6CC4C4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E4838_6CC618;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E4978_6CC758);
}

void func_802E0B28_6C8908(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E46F8_6CC4D8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E4838_6CC618;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E4978_6CC758);
}

void func_802E0B98_6C8978(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E470C_6CC4EC);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802E0C3C_6C8A1C);
    pokemon->transitionGraph = D_802E4838_6CC618;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802E0A48_6C8828);
    }
    Pokemon_SetStateRandom(obj, D_802E4978_6CC758);
}

void func_802E0C3C_6C8A1C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_802E0C98_6C8A78(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802E4748_6CC528);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E475C_6CC53C);
    pokemon->pokemonLoopTarget = 3;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E4770_6CC550);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802E0A48_6C8828);
}

void func_802E0D44_6C8B24(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802E4734_6CC514);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802E0A48_6C8828);
}

void func_802E0DAC_6C8B8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4720_6CC500);
    Pokemon_StartPathProc(obj, func_802E0E20_6C8C00);
    pokemon->transitionGraph = D_802E4938_6CC718;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802E0A48_6C8828);
}

void func_802E0E20_6C8C00(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunAwayFromTarget(obj, 300.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802E0E7C_6C8C5C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_802E0F04_6C8CE4);
    pokemon->transitionGraph = D_802E4838_6CC618;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802E0A48_6C8828);
    }
    Pokemon_SetState(obj, func_802E0F9C_6C8D7C);
}

// clang-format off
void func_802E0F04_6C8CE4(GObj* obj) { \
    UNUSED s32 pad[3]; \
    DObj* model = obj->data.dobj; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_SetAnimation(obj, &D_802E4720_6CC500);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 70.0f, 0.1f, 3);
    Pokemon_SetAnimation(obj, &D_802E470C_6CC4EC);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802E0F9C_6C8D7C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4784_6CC564);
    Pokemon_StartPathProc(obj, func_802E1030_6C8E10);
    pokemon->transitionGraph = D_802E48B8_6CC698;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802E0F9C_6C8D7C);
    }
    Pokemon_SetStateRandom(obj, D_802E4978_6CC758);
}

void func_802E1030_6C8E10(GObj* obj) {
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

void func_802E1094_6C8E74(void) {
}

void func_802E109C_6C8E7C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E470C_6CC4EC);
    Pokemon_StartPathProc(obj, func_802E1110_6C8EF0);
    pokemon->transitionGraph = D_802E4908_6CC6E8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802E0A48_6C8828);
}

void func_802E1110_6C8EF0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0x2E);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802E115C_6C8F3C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    Pokemon_SetState(obj, func_802E1194_6C8F74);
}

void func_802E1194_6C8F74(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = D_802E49E0_6CC7C0;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C86E0/func_802E11D4_6C8FB4.s")

void func_802E12D8_6C90B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802E4720_6CC500);
    Pokemon_StartPathProc(obj, func_802E1374_6C9154);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->apple != NULL && pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802E0E7C_6C8C5C);
    }
    Pokemon_SetState(obj, func_802E0A48_6C8828);
}

void func_802E1374_6C9154(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, pokemon->path->paramPoints[1], 0.05f, 0.0f, 2);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

static void nullsub2(void) {
}

void func_802E13F4_6C91D4(GObj* obj) {
    Pokemon_StartPathProc(obj, func_802E1488_6C9268);
    Pokemon_SetState(obj, func_802E142C_6C920C);
}

void func_802E142C_6C920C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4720_6CC500);
    pokemon->transitionGraph = D_802E49A0_6CC780;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802E13F4_6C91D4);
}

void func_802E1488_6C9268(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802E14F4_6C92D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802E4734_6CC514);
    pokemon->transitionGraph = D_802E49A0_6CC780;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802E142C_6C920C);
}

void func_802E1570_6C9350(GObj* obj) {
    Pokemon_SetState(obj, func_802E1594_6C9374);
}

void func_802E1594_6C9374(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E46D0_6CC4B0);
    Pokemon_StartPathProc(obj, func_802E1604_6C93E4);
    pokemon->transitionGraph = D_802E4A10_6CC7F0;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802E1604_6C93E4(GObj* obj) {
    UNUSED s32 pad[3];
    DObj* model = obj->data.dobj;
    GroundResult sp2C;
    PokemonTransform* transform = GET_TRANSFORM(model);

    while (true) {
        getGroundAt(transform->pos.v.x, transform->pos.v.z, &sp2C);
        transform->pos.v.y = sp2C.height - 80.0f;
        ohWait(1);
    }
}

void func_802E1678_6C9458(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler2 sp18;

    sp18 = D_802E4A40_6CC820;
    Pokemon_SetAnimation(obj, &D_802E4734_6CC514);
    pokemon->transitionGraph = sp18.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802E1594_6C9374);
}

void func_802E171C_6C94FC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->forbiddenGround = &D_802E4A60_6CC840;
    Pokemon_SetAnimation(obj, &D_802E4748_6CC528);
    Pokemon_StartPathProc(obj, func_802E17D4_6C95B4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E475C_6CC53C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E4770_6CC550);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->forbiddenGround = NULL;
    Pokemon_SetState(obj, func_802E0A48_6C8828);
}

void func_802E17D4_6C95B4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 400.0f;
    pokemon->jumpVel = 300.0f;
    pokemon->facingYaw = atan2f(GET_ITEM(pokemon->interactionTarget)->collisionVelocity.x, GET_ITEM(pokemon->interactionTarget)->collisionVelocity.z);
    Pokemon_FallDownOnGround(obj, -19.6f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

static void nullsub() {
}

GObj* func_802E1864_6C9644(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E4AA8_6CC888);
}
