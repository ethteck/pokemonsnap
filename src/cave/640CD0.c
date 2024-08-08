#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"

extern AnimationHeader D_802C6538_6489E8;
extern AnimationHeader D_802C654C_6489FC;
extern AnimationHeader D_802C6560_648A10;
extern AnimationHeader D_802C6574_648A24;
extern AnimationHeader D_802C6588_648A38;
extern AnimationHeader D_802C659C_648A4C;
extern AnimationHeader D_802C65B0_648A60;
extern AnimationHeader D_802C65C4_648A74;
extern PokemonDef D_802C65D8_648A88;
extern InteractionHandler D_802C65E8_648A98[];
extern InteractionHandler D_802C6678_648B28[];
extern InteractionHandler D_802C66F8_648BA8[];
extern InteractionHandler D_802C6728_648BD8[];
extern InteractionHandler D_802C6778_648C28[];
extern InteractionHandler D_802C67A8_648C58[];
extern RandomState D_802C67E8_648C98[];
extern PokemonInitData D_802C6824_648CD4;

void func_802BE8D4_640D84(GObj*);
void func_802BEAC8_640F78(GObj*);
void func_802BECA8_641158(GObj*);
void func_802BED04_6411B4(GObj*);
void func_802BED8C_64123C(GObj*);
void func_802BEE10_6412C0(GObj*);
void func_802BEEA4_641354(GObj*);
void func_802BEF8C_64143C(GObj*);

void func_802BE820_640CD0(GObj* obj) {
    GObj* pokemon;

    PokemonDef def = D_802C65D8_648A88;

    pokemon = Pokemon_AddAtGeo(obj, PokemonID_DITTO, &def);

    GET_TRANSFORM_BASE(pokemon->data.dobj)->xform.rot.f[2] = GET_TRANSFORM_BASE(obj->data.dobj)->xform.rot.f[2];

    omEndProcess(NULL);
}

void func_802BE898_640D48(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_SetState(obj, func_802BE8D4_640D84);
}

void func_802BE8D4_640D84(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6538_6489E8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802C65E8_648A98;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802C67E8_648C98);
}

void func_802BE944_640DF4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802C654C_6489FC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802C65E8_648A98;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802C67E8_648C98);
}

void func_802BE9B4_640E64(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802C6560_648A10);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802C65E8_648A98;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802C67E8_648C98);
}

void func_802BEA24_640ED4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6574_648A24);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802BEAC8_640F78);
    pokemon->transitionGraph = D_802C65E8_648A98;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802BE8D4_640D84);
    }
    Pokemon_SetStateRandom(obj, D_802C67E8_648C98);
}

void func_802BEAC8_640F78(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_802BEB24_640FD4(GObj* obj) { \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    omCreateProcess(obj, func_802BE820_640CD0, 1, 1);
    pokemon->flags &= ~POKEMON_FLAG_200;
    pokemon->flags &= ~POKEMON_FLAG_800;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802C65C4_648A74);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, func_802BE8D4_640D84);
}

void func_802BEBBC_64106C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &D_802C659C_648A4C);
    pokemon->transitionGraph = D_802C66F8_648BA8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->apple = NULL;
    Pokemon_SetState(obj, func_802BE8D4_640D84);
}

void func_802BEC34_6410E4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6588_648A38);
    Pokemon_StartPathProc(obj, func_802BECA8_641158);
    pokemon->transitionGraph = D_802C67A8_648C58;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802BE8D4_640D84);
}

void func_802BECA8_641158(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunAwayFromTarget(obj, 300.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802BED04_6411B4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_802BED8C_64123C);
    pokemon->transitionGraph = D_802C6678_648B28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802BE8D4_640D84);
    }
    Pokemon_SetState(obj, func_802BEE10_6412C0);
}

void func_802BED8C_64123C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6588_648A38);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, 3);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802BEE10_6412C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C65B0_648A60);
    Pokemon_StartPathProc(obj, func_802BEEA4_641354);
    pokemon->transitionGraph = D_802C6728_648BD8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802BEE10_6412C0);
    }
    Pokemon_SetStateRandom(obj, D_802C67E8_648C98);
}

void func_802BEEA4_641354(GObj* obj) {
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

void func_802BEEF4_6413A4(GObj* obj) {
    Pokemon_SetState(obj, func_802BED04_6411B4);
}

void func_802BEF18_6413C8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C6574_648A24);
    Pokemon_StartPathProc(obj, func_802BEF8C_64143C);
    pokemon->transitionGraph = D_802C6778_648C28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802BE8D4_640D84);
}

void func_802BEF8C_64143C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0x2E);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802BEFD8_641488(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C6824_648CD4);
}
