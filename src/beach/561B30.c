#include "common.h"
#include "beach.h"

extern AnimCmd* D_8016E200_FA690[];
extern AnimCmd* D_8016F5B0_FBA40[];
extern AnimCmd* D_80170AD0_FCF60[];
extern AnimCmd* D_80173C30_1000C0[];
extern AnimCmd* D_80175390_101820[];
extern AnimCmd* D_801765D0_102A60[];
extern AnimCmd* D_80177520_1039B0[];
extern AnimCmd** D_80179560_1059F0[];
extern AnimCmd** D_80179600_105A90[];
extern AnimCmd** D_801796A0_105B30[];
extern AnimCmd** D_80179760_105BF0[];
extern AnimCmd** D_80179810_105CA0[];
extern AnimCmd** D_801798B0_105D40[];
extern AnimCmd** D_80179940_105DD0[];
extern Texture** kangaskhan_materials[];
extern UnkEC64Arg3 kangaskhan_model[];

s32 D_beach_802CD590[] = { 0, SOUND_ID_105 };
s32 D_beach_802CD598[] = { SOUND_ID_261, SOUND_ID_104 };
s32 D_beach_802CD5A0[] = { SOUND_ID_260 };
s32 D_beach_802CD5A4[] = { SOUND_ID_262 };

AnimationHeader D_beach_802CD5A8 = {
    0.25f,
    60.0f,
    D_80173C30_1000C0,
    D_80179760_105BF0,
    NULL
};

AnimationHeader D_beach_802CD5BC = {
    0.8f,
    80.0f,
    D_8016E200_FA690,
    D_80179560_1059F0,
    NULL
};

AnimationHeader D_beach_802CD5D0 = {
    0.68f,
    50.0f,
    D_8016F5B0_FBA40,
    D_80179600_105A90,
    D_beach_802CD590
};

AnimationHeader D_beach_802CD5E4 = {
    0.38f,
    107.0f,
    D_80170AD0_FCF60,
    D_801796A0_105B30,
    D_beach_802CD598
};

AnimationHeader D_beach_802CD5F8 = {
    0.45f,
    40.0f,
    D_801765D0_102A60,
    D_801798B0_105D40,
    D_beach_802CD5A0
};

AnimationHeader D_beach_802CD60C = {
    0.5f,
    98.0f,
    D_80177520_1039B0,
    D_80179940_105DD0,
    NULL
};

AnimationHeader D_beach_802CD620 = {
    1.0f,
    120.0f,
    D_80175390_101820,
    D_80179810_105CA0,
    D_beach_802CD5A4
};

InteractionHandler D_beach_802CD634[] = {
    { POKEMON_CMD_9, func_beach_802C9DCC, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C9DCC, 0.0f, NULL },
    { POKEMON_CMD_5, func_beach_802C9EBC, 0.0f, NULL },
    { POKEMON_CMD_6, func_beach_802C9EBC, 0.0f, NULL },
    { POKEMON_CMD_7, func_beach_802C9EBC, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CD694[] = {
    { POKEMON_CMD_9, func_beach_802C9BF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C9BF8, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CD6C4[] = {
    { POKEMON_CMD_9, func_beach_802C9DCC, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C9DCC, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CD6F4[] = {
    { POKEMON_CMD_9, func_beach_802C9DCC, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C9DCC, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CD724[] = {
    { POKEMON_CMD_9, func_beach_802C9DCC, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C9DCC, 0.0f, NULL },
    { POKEMON_CMD_16, func_beach_802C9F9C, 500.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

RandomState D_beach_802CD764[] = {
    { 100, func_beach_802C9CF8 },
    { 0, NULL },
};

RandomState D_beach_802CD774[] = {
    { 100, func_beach_802C9AE4 },
    { 100, func_beach_802C9B40 },
    { 100, func_beach_802C9B9C },
    { 0, NULL },
};

PokemonAnimationSetup D_beach_802CD794 = {
    &D_beach_802CD5A8,
    func_beach_802C9AC0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CD7A8 = {
    kangaskhan_model,
    kangaskhan_materials,
    renderPokemonModelTypeIFogged,
    &D_beach_802CD794,
    { 1.5f, 1.5f, 1.5f },
    { 0.0f, 235.0f, 0.0f },
    104.0f,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802C9AC0(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802C9AE4);
}

void func_beach_802C9AE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD5A8);
    pokemon->transitionGraph = D_beach_802CD694;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CD774);
}

void func_beach_802C9B40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD5BC);
    pokemon->transitionGraph = D_beach_802CD694;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CD774);
}

void func_beach_802C9B9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD60C);
    pokemon->transitionGraph = D_beach_802CD694;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CD774);
}

void func_beach_802C9BF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD5F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_beach_802C9C88);
    Pokemon_SetAnimation(obj, &D_beach_802CD5D0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C9F9C);
}

void func_beach_802C9C88(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon = pokemon;
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 1.0f, 0.05f, 0.1f, MOVEMENT_FLAG_TURN_GRADUALLY | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C9CF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD5A8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CD634;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CD764);
}

void func_beach_802C9D68() {
}

void func_beach_802C9D70(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C9DCC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_beach_802CD5F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_beach_802C9E70);
    Pokemon_SetAnimation(obj, &D_beach_802CD5E4);
    pokemon->transitionGraph = D_beach_802CD6C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C9CF8);
}

void func_beach_802C9E70(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C9EBC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CD620);
    Pokemon_StartPathProc(obj, func_beach_802C9F30);
    pokemon->transitionGraph = D_beach_802CD6F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C9CF8);
}

void func_beach_802C9F30(GObj* obj) {
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

void func_beach_802C9F9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_beach_802CA010);
    Pokemon_SetAnimation(obj, &D_beach_802CD5E4);
    pokemon->transitionGraph = D_beach_802CD6C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CD764);
}

void func_beach_802CA010(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802CA05C(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CD7A8);
}
