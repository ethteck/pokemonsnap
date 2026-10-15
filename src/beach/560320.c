#include "common.h"
#include "beach.h"

extern AnimCmd* D_80159E60_E62F0[];
extern AnimCmd* D_8015BC10_E80A0[];
extern AnimCmd* D_8015CBC0_E9050[];
extern AnimCmd* D_8015EBA0_EB030[];
extern AnimCmd* D_8015FD10_EC1A0[];
extern AnimCmd** D_801617D0_EDC60[];
extern Texture** doduo_materials[];
extern UnkEC64Arg3 doduo_model[];

// .data
s32 D_beach_802CCE90[] = { SOUND_ID_343, SOUND_ID_143, SOUND_ID_342 };
s32 D_beach_802CCE9C[] = { SOUND_ID_344 };
s32 D_beach_802CCEA0[] = { SOUND_ID_342, SOUND_ID_117, SOUND_ID_142, SOUND_ID_143 };

AnimationHeader D_beach_802CCEB0 = {
    1.0f,
    80.0f,
    D_80159E60_E62F0,
    NULL,
    D_beach_802CCE90
};

AnimationHeader D_beach_802CCEC4 = {
    1.0f,
    120.0f,
    D_8015EBA0_EB030,
    NULL,
    D_beach_802CCE9C
};

AnimationHeader D_beach_802CCED8 = {
    0.5f,
    65.0f,
    D_8015BC10_E80A0,
    D_801617D0_EDC60,
    NULL
};

AnimationHeader D_beach_802CCEEC = {
    1.0f,
    136.0f,
    D_8015CBC0_E9050,
    NULL,
    NULL
};

AnimationHeader D_beach_802CCF00 = {
    1.0f,
    72.0f,
    D_8015FD10_EC1A0,
    NULL,
    D_beach_802CCEA0
};

InteractionHandler D_beach_802CCF14[] = {
    { POKEMON_CMD_9, func_beach_802C84A4, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C84A4, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CCF44[] = {
    { POKEMON_CMD_16, func_beach_802C8354, 1000.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_beach_802CCF64 = {
    &D_beach_802CCEB0,
    func_beach_802C82B0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CCF78 = {
    doduo_model,
    doduo_materials,
    renderPokemonModelTypeBFogged,
    &D_beach_802CCF64,
    { 2.0f, 2.0f, 2.0f },
    { 0.0f, 300.0f, 0.0f },
    40.0f,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802C82B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    obj->flags |= GOBJ_FLAG_HIDDEN;
    Pokemon_StartPathProc(obj, func_beach_802C8438);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    pokemon->transitionGraph = D_beach_802CCF44;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8354(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    obj->flags = 0;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CCF00);
    pokemon->transitionGraph = D_beach_802CCF14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C83D0);
}

void func_beach_802C83D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CCEB0);
    pokemon->transitionGraph = D_beach_802CCF14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, 0);
}

void func_beach_802C8438(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1.0f, 0.1f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(0);
}

void func_beach_802C84A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CCEC4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCED8);
    pokemon->counter = 120, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCEEC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_beach_802C83D0);
}

void func_beach_802C8570(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CCF78);
}
