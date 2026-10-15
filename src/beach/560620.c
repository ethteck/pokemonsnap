#include "common.h"
#include "beach.h"

void func_beach_802C85E0(GObj* arg0);
void func_beach_802C87BC(GObj* obj);
void func_beach_802C8C7C(GObj* obj);
void func_beach_802C8CFC(GObj* obj);

extern AnimCmd* D_801A08C0_12CD50[];
extern AnimCmd* D_801A2280_12E710[];
extern AnimCmd* D_801A4A80_130F10[];
extern AnimCmd* D_801A66D0_132B60[];
extern AnimCmd** D_801A8CC0_135150[];
extern AnimCmd** D_801A8D50_1351E0[];
extern AnimCmd** D_801A8DF0_135280[];
void func_beach_802C85B0(GObj*);
void func_beach_802C8900(GObj*);
void func_beach_802C8AAC(GObj*);
void func_beach_802C8C30(GObj*);
void func_beach_802C8C58(GObj*);
void func_beach_802C8CC0(GObj*);
extern Texture** pidgey_materials[];
extern UnkEC64Arg3 pidgey_model[];

// .data
s32 D_beach_802CCFB0[] = { SOUND_ID_256, SOUND_ID_124 };
s32 D_beach_802CCFB8[] = { SOUND_ID_257, SOUND_ID_124 };

AnimationHeader D_beach_802CCFC0 = {
    0.4,
    50,
    D_801A66D0_132B60,
    NULL,
    D_beach_802CCFB0
};

AnimationHeader D_beach_802CCFD4 = {
    0.3,
    51,
    D_801A08C0_12CD50,
    D_801A8CC0_135150,
    NULL
};

AnimationHeader D_beach_802CCFE8 = {
    0.33,
    48,
    D_801A2280_12E710,
    D_801A8D50_1351E0,
    D_beach_802CCFB8
};

AnimationHeader D_beach_802CCFFC = {
    0.33,
    32,
    D_801A4A80_130F10,
    D_801A8DF0_135280,
    NULL
};

InteractionHandler D_beach_802CD010[] = {
    { POKEMON_CMD_9, NULL, 0, func_beach_802C8900 },
    { POKEMON_CMD_13, NULL, 0, func_beach_802C8900 },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD040[] = {
    { POKEMON_CMD_16, func_beach_802C86A8, 1000, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

s32 D_beach_802CD060 = 0;

InteractionHandler D_beach_802CD064[] = {
    { POKEMON_CMD_9, func_beach_802C8AAC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C8AAC, 0, NULL },
    { POKEMON_CMD_37, NULL, 0, func_beach_802C8C30 },
    { POKEMON_CMD_38, NULL, 0, func_beach_802C8C58 },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD0B4[] = {
    { POKEMON_CMD_9, func_beach_802C8CC0, 0, NULL },
    { POKEMON_CMD_31, func_beach_802C86A8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD0E4[] = {
    { POKEMON_CMD_16, func_beach_802C86A8, 666.6667f, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_beach_802CD104 = {
    &D_beach_802CCFD4,
    func_beach_802C85B0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CD118 = {
    pidgey_model,
    pidgey_materials,
    renderPokemonModelTypeIFogged,
    &D_beach_802CD104,
    { 2, 2, 2 },
    { 0, 74, -2 },
    30,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802C85B0(GObj* arg0) {
    arg0->flags |= 1;
    Pokemon_SetState(arg0, func_beach_802C85E0);
}

// clang-format off
void func_beach_802C85E0(GObj* arg0) { \
    Pokemon* pokemon = GET_POKEMON(arg0);
    // clang-format on

    Pokemon_StartPathProc(arg0, func_beach_802C87BC);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(arg0, 4);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    if (pokemon->behavior == 2) {
        Pokemon_SetState(arg0, func_beach_802C8C7C);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(arg0, func_beach_802C8CFC);
    }
    pokemon->transitionGraph = D_beach_802CD040;
    Pokemon_WaitForFlag(arg0, 0);
    Pokemon_SetState(arg0, NULL);
}

void func_beach_802C86A8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_beach_802C8980);
    }

    obj->flags = 0;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CCFC0);
    pokemon->transitionGraph = D_beach_802CD010;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCFD4);
    pokemon->transitionGraph = D_beach_802CD010;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCFE8);
    pokemon->transitionGraph = D_beach_802CD010;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCFFC);
    pokemon->pokemonLoopTarget = 1;
    pokemon->transitionGraph = D_beach_802CD010;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C8828);
}

void func_beach_802C87BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);

    pokemon->pathProc = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(0);
}

void func_beach_802C8828(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->specialPoseID = 0;
    Pokemon_StartPathProc(obj, func_beach_802C8894);
    pokemon->transitionGraph = D_beach_802CD010;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8894(GObj* obj) {
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

void func_beach_802C8900(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (false) {
    }

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 150.0f;
    pokemon = pokemon;
    Pokemon_Fall(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    pokemon->jumpVel = 150.0f;
    Pokemon_Jump(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C8980(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802C89A4);
}

void func_beach_802C8BC4(GObj*); /* extern */

void func_beach_802C89A4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // required to match
    if (false) {
    }

    pokemon->miscVars[0].field1 = 0;
    obj->flags = 0;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CCFC0);
    pokemon->transitionGraph = D_beach_802CD064;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCFD4);
    pokemon->transitionGraph = D_beach_802CD064;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_StartAuxProc(obj, func_beach_802C8BC4);
    Pokemon_SetAnimation(obj, &D_beach_802CCFE8);
    pokemon->transitionGraph = D_beach_802CD064;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CCFFC);
    pokemon->pokemonLoopTarget = 1;
    pokemon->transitionGraph = D_beach_802CD064;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C8828);
}

void func_beach_802C8AAC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (++D_beach_802CD060 == 2) {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_36, obj);
    }

    pokemon->miscVars[0].field1 = 1;
    pokemon->specialPoseID = 0;
    Pokemon_SetAnimation(obj, &D_beach_802CCFD4);
    Pokemon_StartPathProc(obj, func_beach_802C8B60);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8B60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 90.0f;
    Pokemon_Jump(obj, 2000.0f, 0.0f, 0.0f, 0.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C8BC4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->counter = 128;
    pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon = pokemon;
    Pokemon_WaitForFlagNoInteraction(obj, POKEMON_PROCESS_WAIT_ENDED);
    if (pokemon->miscVars[0].field1 == 0) {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_29, obj);
    }
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C8C30(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    pokemon->specialPoseID = 7;
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C8C58(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    pokemon->specialPoseID = 0;
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C8C7C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    obj->flags = 0;
    pokemon->transitionGraph = D_beach_802CD0B4;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8CC0(GObj* obj) {
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_31, obj);
    Pokemon_SetState(obj, func_beach_802C86A8);
}

void func_beach_802C8CFC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->transitionGraph = D_beach_802CD0E4;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C8D3C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}

void func_beach_802C8D74(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CD118);
}
