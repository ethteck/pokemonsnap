#include "common.h"
#include "beach.h"

void func_beach_802C94F0(GObj* obj);

extern AnimCmd* D_80185010_1114A0[];
extern AnimCmd* D_80185D90_112220[];
extern AnimCmd* D_801866A0_112B30[];
extern AnimCmd* D_80186E20_1132B0[];
extern AnimCmd* D_80187230_1136C0[];
extern AnimCmd* D_80187BD0_114060[];
extern AnimCmd* D_80188260_1146F0[];
extern AnimCmd* D_80188ED0_115360[];
extern AnimCmd* D_801895E0_115A70[];
extern AnimCmd** D_8018A270_116700[];
extern AnimCmd** D_8018A370_116800[];
extern AnimCmd** D_8018A410_1168A0[];
extern AnimCmd** D_8018A4C0_116950[];
extern Texture** chansey_materials[];
extern UnkEC64Arg3 chansey_model[];
void func_beach_802C9240(GObj*);
void func_beach_802C93B8(GObj*);
void func_beach_802C943C(GObj*);
void func_beach_802C95F0(GObj*);
void func_beach_802C96F0(GObj*);
void func_beach_802C9760(GObj*);
void func_beach_802C9978(GObj*);
void func_beach_802C999C(GObj*);

// .data
s32 D_beach_802CD290[] = { 0, SOUND_ID_121 };
s32 D_beach_802CD298[] = { SOUND_ID_252, SOUND_ID_366 };
s32 D_beach_802CD2A0[] = { SOUND_ID_251, SOUND_ID_122 };

AnimationHeader D_beach_802CD2A8 = {
    0.5,
    28,
    D_80186E20_1132B0,
    NULL,
    NULL
};

AnimationHeader D_beach_802CD2BC = {
    1,
    60,
    D_80187230_1136C0,
    NULL,
    NULL
};

AnimationHeader D_beach_802CD2D0 = {
    0.4,
    20,
    D_80188ED0_115360,
    D_8018A4C0_116950,
    NULL
};

AnimationHeader D_beach_802CD2E4 = {
    0.5,
    40,
    D_801866A0_112B30,
    D_8018A270_116700,
    NULL
};

AnimationHeader D_beach_802CD2F8 = {
    0.5,
    36,
    D_80185010_1114A0,
    NULL,
    NULL
};

AnimationHeader D_beach_802CD30C = {
    0.5,
    42,
    D_80187BD0_114060,
    D_8018A370_116800,
    D_beach_802CD290
};

AnimationHeader D_beach_802CD320 = {
    0.4,
    16,
    D_80185D90_112220,
    NULL,
    NULL
};

AnimationHeader D_beach_802CD334 = {
    0.5,
    60,
    D_801895E0_115A70,
    NULL,
    D_beach_802CD298
};

AnimationHeader D_beach_802CD348 = {
    0.4,
    24,
    D_80188260_1146F0,
    D_8018A410_1168A0,
    D_beach_802CD2A0
};

InteractionHandler D_beach_802CD35C[] = {
    { POKEMON_CMD_9, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_10, func_beach_802C9760, 0, NULL },
    { POKEMON_CMD_15, func_beach_802C9978, 0, NULL },
    { POKEMON_CMD_5, func_beach_802C999C, 0, NULL },
    { POKEMON_CMD_6, func_beach_802C999C, 0, NULL },
    { POKEMON_CMD_7, func_beach_802C999C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_beach_802CD3DC[] = {
    { 100, func_beach_802C9580 },
    { 100, func_beach_802C95F0 },
    { 0, NULL },
};

InterpData* D_beach_802CD3F4 = NULL;

InteractionHandler D_beach_802CD3F8[] = {
    { POKEMON_CMD_9, func_beach_802C943C, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C943C, 0, NULL },
    { POKEMON_CMD_33, func_beach_802C93B8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD438[] = {
    { POKEMON_CMD_9, func_beach_802C943C, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C943C, 0, NULL },
    { POKEMON_CMD_34, func_beach_802C92BC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD478[] = {
    { POKEMON_CMD_9, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD4A8[] = {
    { POKEMON_CMD_9, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_10, func_beach_802C9760, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD4E8[] = {
    { POKEMON_CMD_9, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_beach_802CD518[] = {
    { POKEMON_CMD_9, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_13, func_beach_802C96F0, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_beach_802CD548 = {
    &D_beach_802CD2E4,
    func_beach_802C9240,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CD55C = {
    chansey_model,
    chansey_materials,
    renderPokemonModelTypeIFogged,
    &D_beach_802CD548,
    { 2, 2, 2 },
    { 0, 210, 0 },
    50,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802C9240(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    D_beach_802CD3F4 = pokemon->path;
    Pokemon_SetState(obj, func_beach_802C9274);
}

void func_beach_802C9274(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    Pokemon_StartPathProc(obj, func_beach_802C9348);
    Pokemon_SetState(obj, func_beach_802C92BC);
}

void func_beach_802C92BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetScale(obj, 0.5f);

    Pokemon_SetAnimation(obj, &D_beach_802CD2A8);
    pokemon->transitionGraph = D_beach_802CD3F8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, func_beach_802C92BC);
}

void func_beach_802C9348(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 0, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C93B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    // TODO: potentially include data
    InteractionHandler sp18[4] = D_beach_802CD438;

    pokemon->transitionGraph = sp18;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

// clang-format off
void func_beach_802C943C(GObj* arg0) { Pokemon* pokemon = GET_POKEMON(arg0);
    // clang-format on
    cmdSendCommandToLink(3, 0x20, arg0);
    Pokemon_StartAuxProc(arg0, func_beach_802C94F0);
    Pokemon_StartPathProc(arg0, NULL);
    Pokemon_SetAnimation(arg0, &D_beach_802CD2D0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(arg0, &D_beach_802CD348);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(arg0, func_beach_802C9580);
}

void func_beach_802C94F0(GObj* obj) {
    f32 var_f20;

    var_f20 = 0.5f;
    while (var_f20 < 1.0f) {
        var_f20 += 0.016666668f;
        Pokemon_SetScale(obj, var_f20);
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C9580(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD2E4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CD35C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CD3DC);
}

void func_beach_802C95F0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD2F8);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_beach_802C9694);
    pokemon->transitionGraph = D_beach_802CD35C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_beach_802C9580);
    }
    Pokemon_SetStateRandom(obj, D_beach_802CD3DC);
}

void func_beach_802C9694(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 30.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C96F0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD30C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CD478;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C9580);
}

void func_beach_802C9760(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD320);
    Pokemon_StartPathProc(obj, func_beach_802C97D4);
    pokemon->transitionGraph = D_beach_802CD4A8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C9580);
}

void func_beach_802C97D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunAwayFromTarget(obj, 300.0f, 0.1f, MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C9830(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD2F8);
    Pokemon_StartPathProc(obj, func_beach_802C98F4);
    pokemon->transitionGraph = D_beach_802CD4E8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_beach_802C9580);
    }
    Pokemon_SetAnimation(obj, &D_beach_802CD334);
    pokemon->transitionGraph = D_beach_802CD4E8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CD3DC);
}

void func_beach_802C98F4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    Pokemon_SetAnimation(obj, &D_beach_802CD320);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 100.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C9978(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802C9830);
}

void func_beach_802C999C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD2BC);
    Pokemon_StartPathProc(obj, func_beach_802C9A10);
    pokemon->transitionGraph = D_beach_802CD518;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C9580);
}

void func_beach_802C9A10(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (1) {
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

void func_beach_802C9A7C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CD55C);
}
