#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

extern AnimationHeader D_802C6870_648D20;
extern AnimationHeader D_802C6884_648D34;
extern AnimationHeader D_802C6898_648D48;
extern AnimationHeader D_802C68AC_648D5C;
extern AnimationHeader D_802C68C0_648D70;
extern AnimationHeader D_802C68D4_648D84;
extern AnimationHeader D_802C68E8_648D98;
extern AnimationHeader D_802C68FC_648DAC;
extern AnimationHeader D_802C6910_648DC0;
extern InteractionHandler D_802C6924_648DD4[];
extern RandomState D_802C6964_648E14;
extern InteractionHandler D_802C697C_648E2C[];
extern PokemonInitData D_802C69C0_648E70;

void func_802BF044_6414F4(GObj*);
void func_802BF0B4_641564(GObj*);
void func_802BF1C4_641674(GObj*);
void func_802BF3D0_641880(GObj*);
void func_802BF454_641904(GObj*);
void func_802BF4E8_641998(GObj*);

void func_802BF020_6414D0(GObj* arg0) {
    Pokemon_SetState(arg0, func_802BF044_6414F4);
}

void func_802BF044_6414F4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    Pokemon_SetAnimation(obj, &D_802C6910_648DC0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_SetState(obj, func_802BF0B4_641564);
}

void func_802BF0B4_641564(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C6870_648D20);
    pokemon->transitionGraph = D_802C6924_648DD4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802C6964_648E14);
}

void func_802BF124_6415D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_802BF1C4_641674);
    Pokemon_SetAnimation(obj, &D_802C6884_648D34);
    pokemon->pokemonLoopTarget = 5;
    pokemon->transitionGraph = D_802C6924_648DD4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802BF0B4_641564);
    }
    Pokemon_SetStateRandom(obj, &D_802C6964_648E14);
}

void func_802BF1C4_641674(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802BF220_6416D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C68C0_648D70);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802C68D4_648D84);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802C68E8_648D98);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802BF0B4_641564);
}

void func_802BF2D0_641780(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C68AC_648D5C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802BF0B4_641564);
}

void func_802BF338_6417E8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6884_648D34);
    Pokemon_StartPathProc(obj, func_802BF3D0_641880);
    pokemon->transitionGraph = D_802C6924_648DD4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802BF0B4_641564);
    }
    Pokemon_SetState(obj, func_802BF454_641904);
}

void func_802BF3D0_641880(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0U);
    Pokemon_SetAnimation(obj, &D_802C6898_648D48);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, 3);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802BF454_641904(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C68FC_648DAC);
    Pokemon_StartPathProc(obj, func_802BF4E8_641998);
    pokemon->transitionGraph = D_802C697C_648E2C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802BF454_641904);
    }
    Pokemon_SetStateRandom(obj, &D_802C6964_648E14);
}

void func_802BF4E8_641998(GObj* obj) {
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

void func_802BF554_641A04(void) {
}

GObj* func_802BF55C_641A0C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C69C0_648E70);
}
