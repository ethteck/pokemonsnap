#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E2C1C_6CA9FC;
extern AnimationHeader D_802E2C30_6CAA10;
extern AnimationHeader D_802E2C44_6CAA24;
extern AnimationHeader D_802E2C58_6CAA38;
extern AnimationHeader D_802E2C6C_6CAA4C;
extern AnimationHeader D_802E2C94_6CAA74;
extern InteractionHandler D_802E2CA8_6CAA88[];
extern InteractionHandler D_802E2D80_6CAB60[];
extern RandomState D_802E2D18_6CAAF8[];
extern PokemonInitData D_802E2E04_6CABE4;

void func_802DA1AC_6C1F8C(GObj* obj);
void func_802DA30C_6C20EC(GObj* obj);
void func_802DA46C_6C224C(GObj* obj);

void func_802D9F80_6C1D60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2C1C_6CA9FC);
    pokemon->transitionGraph = D_802E2CA8_6CAA88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2D18_6CAAF8);
}

void func_802D9FDC_6C1DBC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2C1C_6CA9FC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2CA8_6CAA88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2D18_6CAAF8);
}

void func_802DA04C_6C1E2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E2C30_6CAA10);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2CA8_6CAA88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2D18_6CAAF8);
}

void func_802DA0BC_6C1E9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E2C94_6CAA74);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2CA8_6CAA88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2D18_6CAAF8);
}

void func_802DA12C_6C1F0C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2C44_6CAA24);
    pokemon->pokemonLoopTarget = 3;
    Pokemon_StartPathProc(obj, func_802DA1AC_6C1F8C);
    pokemon->transitionGraph = D_802E2CA8_6CAA88;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2D18_6CAAF8);
}

void func_802DA1AC_6C1F8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 100.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/river/6C1D60/func_802DA208_6C1FE8.s")

void func_802DA30C_6C20EC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    Pokemon_SetAnimation(obj, &D_802E2C58_6CAA38);
    pokemon->hSpeed = 200.0f;
    Pokemon_RunToTarget(obj, 100.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DA390_6C2170(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2C6C_6CAA4C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D9FDC_6C1DBC);
}

void func_802DA3F8_6C21D8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2C44_6CAA24);
    Pokemon_StartPathProc(obj, &func_802DA46C_6C224C);
    pokemon->transitionGraph = D_802E2D80_6CAB60;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802D9FDC_6C1DBC);
}

void func_802DA46C_6C224C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

GObj* func_802DA4B8_6C2298(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2E04_6CABE4);
}
