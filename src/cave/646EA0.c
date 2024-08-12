#include "common.h"

#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

extern GObj* D_802C7B4C_649FFC;
extern AnimationHeader D_802C7BD0_64A080;
extern AnimationHeader D_802C7BE4_64A094;
extern AnimationHeader D_802C7BF8_64A0A8;
extern AnimationHeader D_802C7C0C_64A0BC;
extern EggStruct D_802C7C28_64A0D8;
extern GObj* D_802C7C3C_64A0EC;
extern InteractionHandler D_802C7C40_64A0F0[];
extern PokemonInitData D_802C7CCC_64A17C;

void func_802C4A4C_646EFC(GObj*);
void func_802C4C18_6470C8(GObj*);
void func_802C4C70_647120(GObj*);
void func_802C4D60_647210(GObj*);

void func_802C49F0_646EA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7BD0_64A080);
    pokemon->transitionGraph = D_802C7C40_64A0F0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C4A4C_646EFC);
}

void func_802C4A4C_646EFC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7BD0_64A080);
    pokemon->transitionGraph = D_802C7C40_64A0F0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C4A4C_646EFC);
}

void func_802C4AA8_646F58(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7C0C_64A0BC);
    pokemon->transitionGraph = D_802C7C40_64A0F0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C4A4C_646EFC);
}

// clang-format off
void func_802C4B04_646FB4(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_SetAnimation(obj, &D_802C7BE4_64A094);
    Pokemon_StartPathProc(obj, func_802C4C70_647120);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_1000)) {
        Pokemon_SetState(obj, func_802C4A4C_646EFC);
    }
    Pokemon_SetAnimation(obj, &D_802C7BE4_64A094);
    Pokemon_StartPathProc(obj, func_802C4D60_647210);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    cmdSendCommandToLink(3, 0x1C, obj);
    Pokemon_SetAnimation(obj, &D_802C7BF8_64A0A8);
    Pokemon_StartPathProc(obj, func_802C4C18_6470C8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    D_802C7C3C_64A0EC = NULL;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C4C18_6470C8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_80362414_502824(pokemon, &D_802C7C28_64A0D8, 0.0333333333f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_802C4C70_647120(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    f32 speed;
    f32 speedX4;
    f32 inc;

    speed = D_802C7BE4_64A094.speed;
    speedX4 = speed * 4.0f;
    inc = (speedX4 - speed) / 180.0f;

    while (speed < speedX4) {
        animSetModelAndTextureAnimationSpeed(obj, speed);
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }
        ohWait(1);
        speed += inc;
    }

    if (speed < speedX4) {
        pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    } else {
        pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/cave/646EA0/func_802C4D60_647210.s")

GObj* func_802C4E64_647314(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802C7C3C_64A0EC = Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_802C7CCC_64A17C);

    return D_802C7C3C_64A0EC;
}
