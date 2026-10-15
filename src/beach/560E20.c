#include "common.h"
#include "beach.h"

extern AnimCmd* D_801AA9D0_136E60[];
extern AnimCmd* D_801AB610_137AA0[];
extern AnimCmd* D_801AC250_1386E0[];
extern AnimCmd* D_801ACF90_139420[];
extern AnimCmd* D_801AE790_13AC20[];
extern AnimCmd* D_801AF4B0_13B940[];
void func_beach_802C8DB0(GObj*);
void func_beach_802C8F48(GObj*);
void func_beach_802C914C(GObj*);
extern UnkEC64Arg3 scyther_model[];

// .data
s32 D_beach_802CD150[] = { SOUND_ID_304, SOUND_ID_363 };
s32 D_beach_802CD158[] = { SOUND_ID_304, SOUND_ID_388 };
s32 D_beach_802CD160[] = { 0, SOUND_ID_363 };

AnimationHeader D_beach_802CD168 = {
    1,
    129,
    D_801AF4B0_13B940,
    NULL,
    D_beach_802CD150
};

AnimationHeader D_beach_802CD17C = {
    1,
    108,
    D_801AA9D0_136E60,
    NULL,
    NULL
};

AnimationHeader D_beach_802CD190 = {
    0.65,
    111,
    D_801ACF90_139420,
    NULL,
    D_beach_802CD158
};

AnimationHeader D_beach_802CD1A4 = {
    1,
    108,
    D_801AE790_13AC20,
    NULL,
    NULL
};

AnimationHeader D_beach_802CD1B8 = {
    1,
    108,
    D_801AC250_1386E0,
    NULL,
    D_beach_802CD160
};

AnimationHeader D_beach_802CD1CC = {
    1,
    108,
    D_801AB610_137AA0,
    NULL,
    NULL
};

u32 D_beach_802CD1E0 = 0x00000000;

InteractionHandler D_beach_802CD1E4[] = {
    { POKEMON_CMD_9, func_beach_802C8F48, 0, NULL },
    { POKEMON_CMD_10, func_beach_802C8F48, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD214[] = {
    { POKEMON_CMD_9, NULL, 0, func_beach_802C914C },
    { POKEMON_CMD_13, NULL, 0, func_beach_802C914C },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_beach_802CD244 = {
    &D_beach_802CD17C,
    func_beach_802C8DB0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CD258 = {
    scyther_model,
    NULL,
    renderPokemonModelTypeDFogged,
    &D_beach_802CD244,
    { 0.9, 0.9, 0.9 },
    { 0, 60, 0 },
    63,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802C8DB0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field0 = pokemon->collisionRadius;
    pokemon->collisionRadius = 0;
    Pokemon_SetState(obj, func_beach_802C8DE8);
}

void func_beach_802C8DE8(GObj* obj) {
    Pokemon_StartPathProc(obj, func_beach_802C8E20);
    Pokemon_SetState(obj, func_beach_802C8E90);
}

void func_beach_802C8E20(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 0, 0.1f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_beach_802C8E90(GObj* arg0) { \
    Pokemon* pokemon = GET_POKEMON(arg0);
    // clang-format on
    Pokemon_SetAnimation(arg0, &D_beach_802CD1B8);
    pokemon->counter = 240, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_beach_802CD1E4;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetAnimation(arg0, &D_beach_802CD1CC);
    pokemon->counter = 240, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_beach_802CD1E4;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetState(arg0, func_beach_802C8E90);
}

void func_beach_802C8F48(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->collisionRadius = pokemon->miscVars[0].field0;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_beach_802C907C);
    Pokemon_SetAnimation(obj, &D_beach_802CD168);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CD1A4);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CD190);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_30, obj);
    Pokemon_SetAnimation(obj, &D_beach_802CD17C);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_StartPathProc(obj, func_beach_802C90E0);
    pokemon->transitionGraph = D_beach_802CD214;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, func_beach_802C8F48);
}

void func_beach_802C907C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 100.0f;
    Pokemon_Jump(obj, 150.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C90E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (false) {
    }

    pokemon->hSpeed = 200.0f;
    pokemon->jumpVel = 90.0f;
    Pokemon_Jump(obj, 2000.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C914C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (false) {
    }

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 150.0f;
    Pokemon_Fall(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    pokemon->jumpVel = 150.0f;
    Pokemon_Jump(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C91CC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}

void func_beach_802C9204(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CD258);
}
