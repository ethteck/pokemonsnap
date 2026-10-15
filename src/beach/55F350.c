#include "common.h"
#include "beach.h"

extern AnimCmd* D_80165010_F14A0[];
extern AnimCmd* D_80165D90_F2220[];
extern AnimCmd* D_80166A90_F2F20[];
extern AnimCmd* D_80167D20_F41B0[];
extern AnimCmd* D_80168D50_F51E0[];
extern AnimCmd** D_8016B190_F7620[];
extern AnimCmd** D_8016B250_F76E0[];
extern AnimCmd** D_8016B300_F7790[];
extern AnimCmd** D_8016B420_F78B0[];
extern AnimCmd** D_8016B4F0_F7980[];
extern Texture** eevee_materials[];
extern UnkEC64Arg3 eevee_model[];
void func_beach_802C72E0(GObj*);
void func_beach_802C73EC(GObj*);
void func_beach_802C74EC(GObj*);
void func_beach_802C755C(GObj*);
void func_beach_802C77CC(GObj*);
void func_beach_802C77F0(GObj*);
void func_beach_802C79DC(GObj*);
void func_beach_802C7A60(GObj*);

// .data
s32 D_beach_802CC9A0[] = { SOUND_ID_254 };
s32 D_beach_802CC9A4[] = { SOUND_ID_255, SOUND_ID_110 };

AnimationHeader D_beach_802CC9AC = {
    0.34,
    70,
    D_80166A90_F2F20,
    D_8016B300_F7790,
    NULL
};

AnimationHeader D_beach_802CC9C0 = {
    1,
    40,
    D_80165010_F14A0,
    D_8016B190_F7620,
    NULL
};

AnimationHeader D_beach_802CC9D4 = {
    1,
    38,
    D_80165D90_F2220,
    D_8016B250_F76E0,
    NULL
};

AnimationHeader D_beach_802CC9E8 = {
    0.53,
    36,
    D_80167D20_F41B0,
    D_8016B420_F78B0,
    D_beach_802CC9A0
};

AnimationHeader D_beach_802CC9FC = {
    0.3,
    66,
    D_80168D50_F51E0,
    D_8016B4F0_F7980,
    D_beach_802CC9A4
};

InteractionHandler D_beach_802CCA10[] = {
    { POKEMON_CMD_9, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_10, func_beach_802C755C, 0, NULL },
    { POKEMON_CMD_14, func_beach_802C762C, 0, NULL },
    { POKEMON_CMD_5, func_beach_802C77F0, 0, NULL },
    { POKEMON_CMD_6, func_beach_802C77F0, 0, NULL },
    { POKEMON_CMD_7, func_beach_802C77F0, 0, NULL },
    { POKEMON_CMD_15, func_beach_802C77CC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_beach_802CCAA0[] = {
    { 100, func_beach_802C737C },
    { 100, func_beach_802C73EC },
    { 0, NULL },
};

InteractionHandler D_beach_802CCAB8[] = {
    { POKEMON_CMD_9, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CCAE8[] = {
    { POKEMON_CMD_9, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_10, func_beach_802C755C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CCB28[] = {
    { POKEMON_CMD_9, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_10, func_beach_802C755C, 0, NULL },
    { POKEMON_CMD_14, func_beach_802C762C, 0, NULL },
    { POKEMON_CMD_5, func_beach_802C77F0, 0, NULL },
    { POKEMON_CMD_6, func_beach_802C77F0, 0, NULL },
    { POKEMON_CMD_7, func_beach_802C77F0, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CCBA8[] = {
    { POKEMON_CMD_9, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_10, func_beach_802C755C, 0, NULL },
    { POKEMON_CMD_14, func_beach_802C762C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CCBF8[] = {
    { POKEMON_CMD_9, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CCC28[] = {
    { POKEMON_CMD_32, func_beach_802C7A60, 0, NULL },
    { POKEMON_CMD_9, func_beach_802C79DC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C79DC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CCC68[] = {
    { POKEMON_CMD_32, func_beach_802C7A60, 0, NULL },
    { POKEMON_CMD_9, func_beach_802C79DC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C79DC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CCCA8[] = {
    { POKEMON_CMD_9, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C74EC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_beach_802CCCD8 = {
    &D_beach_802CC9AC,
    func_beach_802C72E0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CCCEC = {
    eevee_model,
    eevee_materials,
    renderPokemonModelTypeBFogged,
    &D_beach_802CCCD8,
    { 2.4, 2.4, 2.4 },
    { 0, 80, 0 },
    22,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802C72E0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    while (D_beach_802CD3F4 == NULL) {
        ohWait(1);
    }
    pokemon->path = D_beach_802CD3F4;
    ohWait(60);
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_beach_802C78B0);
    }
    Pokemon_SetState(obj, func_beach_802C737C);
}

void func_beach_802C737C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC9AC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CCA10;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CCAA0);
}

void func_beach_802C73EC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC9C0);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_beach_802C7490);
    pokemon->transitionGraph = D_beach_802CCA10;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_beach_802C737C);
    }
    Pokemon_SetStateRandom(obj, D_beach_802CCAA0);
}

void func_beach_802C7490(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C74EC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CC9E8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CCAB8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C737C);
}

void func_beach_802C755C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC9D4);
    Pokemon_StartPathProc(obj, func_beach_802C75D0);
    pokemon->transitionGraph = D_beach_802CCAE8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C737C);
}

void func_beach_802C75D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunAwayFromTarget(obj, 300.0f, 0.1f, MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C762C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC9C0);
    Pokemon_StartPathProc(obj, func_beach_802C76C4);
    pokemon->transitionGraph = D_beach_802CCB28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_beach_802C737C);
    }
    Pokemon_SetState(obj, func_beach_802C7748);
}

void func_beach_802C76C4(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    Pokemon_SetAnimation(obj, &D_beach_802CC9D4);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C7748(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC9FC);
    pokemon->transitionGraph = D_beach_802CCBA8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_beach_802C7748);
    }
    Pokemon_SetStateRandom(obj, D_beach_802CCAA0);
}

void func_beach_802C77CC(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802C762C);
}

void func_beach_802C77F0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC9C0);
    Pokemon_StartPathProc(obj, func_beach_802C7864);
    pokemon->transitionGraph = D_beach_802CCBF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C737C);
}

void func_beach_802C7864(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C78B0(GObj* obj) {
    Pokemon_StartPathProc(obj, func_beach_802C796C);
    Pokemon_SetState(obj, func_beach_802C78E8);
}

void func_beach_802C78E8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_34, obj);
    Pokemon_SetAnimation(obj, &D_beach_802CC9D4);
    pokemon->transitionGraph = D_beach_802CCC28;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C796C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 0, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C79DC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CC9E8);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_33, obj);
    pokemon->transitionGraph = D_beach_802CCC68;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C78E8);
}

void func_beach_802C7A60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_beach_802CC9FC);
    pokemon->transitionGraph = D_beach_802CCCA8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C737C);
}

void func_beach_802C7AD0(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CCCEC);
}
