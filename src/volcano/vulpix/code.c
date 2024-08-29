#include "volcano/volcano.h"

extern AnimCmd* D_80191B20[];
extern AnimCmd* D_80190AC0[];
extern AnimCmd* D_80191260[];
extern AnimCmd* D_801935B0[];
extern AnimCmd* D_80193CD0[];
extern AnimCmd* D_80191F40[];
extern AnimCmd* D_80192340[];
extern AnimCmd* D_801950B0[];

extern AnimCmd** D_801965B0[];
extern AnimCmd** D_80196830[];
extern AnimCmd** D_801968D0[];
extern AnimCmd** D_801966D0[];
extern AnimCmd** D_80196770[];
extern AnimCmd** D_80196960[];

void func_802DA3A0_72B5A0(GObj*);
void func_802D9F24_72B124(GObj*);
void func_802DA97C_72BB7C(GObj*);
void func_802DAA34_72BC34(GObj*);
void func_802DA000_72B200(GObj*);
void func_802DA100_72B300(GObj*);
void func_802DA200_72B400(GObj*);
void func_802DA2C8_72B4C8(GObj*);
void func_802DA7A4_72B9A4(GObj*);
void func_802DA5B4_72B7B4(GObj*);
void func_802DA68C_72B88C(GObj*);
void func_802DA330_72B530(GObj*);
void func_802D9F90_72B190(GObj*);
void func_802DA0A4_72B2A4(GObj*);
void func_802DA1A4_72B3A4(GObj*);
void func_802DA5D8_72B7D8(GObj*);
void func_802DA428_72B628(GObj*);
void func_802DA4AC_72B6AC(GObj*);
void func_802DA55C_72B75C(GObj*);
void func_802DA748_72B948(GObj*);
void func_802DA848_72BA48(GObj*);
void func_802DA8A4_72BAA4(GObj*);
void func_802DA930_72BB30(GObj*);

s32 D_802E1FF0_7331F0[] = { SOUND_ID_291 };
s32 D_802E1FF4_7331F4[] = { SOUND_ID_292 };

AnimationHeader D_802E1FF8_7331F8 = {
    0.4,
    40,
    D_80191B20,
    D_801965B0,
    NULL
};

AnimationHeader D_802E200C_73320C = {
    0.8,
    40,
    D_80190AC0,
    NULL,
    NULL
};

AnimationHeader D_802E2020_733220 = {
    1.2,
    37,
    D_80191260,
    NULL,
    NULL
};

AnimationHeader D_802E2034_733234 = {
    0.5,
    15,
    D_801935B0,
    D_80196830,
    NULL
};

AnimationHeader D_802E2048_733248 = {
    0.7,
    52,
    D_80193CD0,
    D_801968D0,
    D_802E1FF0_7331F0
};

AnimationHeader D_802E205C_73325C = {
    0.5,
    10,
    D_80191F40,
    D_801966D0,
    NULL
};

AnimationHeader D_802E2070_733270 = {
    0.35,
    45,
    D_80192340,
    D_80196770,
    NULL
};

AnimationHeader D_802E2084_733284 = {
    0.5,
    54,
    D_801950B0,
    D_80196960,
    D_802E1FF4_7331F4
};

InteractionHandler D_802E2098_733298[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_10, func_802DA330_72B530, 0, NULL },
    { POKEMON_CMD_14, func_802DA3A0_72B5A0, 0, NULL },
    { POKEMON_CMD_15, func_802DA5B4_72B7B4, 0, NULL },
    { POKEMON_CMD_16, func_802DA68C_72B88C, 1000.0 / 3.0, NULL },
    { VOLCANO_CMD_44, func_802DA7A4_72B9A4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2118_733318[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_10, func_802DA330_72B530, 0, NULL },
    { POKEMON_CMD_14, func_802DA3A0_72B5A0, 0, NULL },
    { VOLCANO_CMD_44, func_802DA7A4_72B9A4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2178_733378[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_10, func_802DA330_72B530, 0, NULL },
    { POKEMON_CMD_14, func_802DA3A0_72B5A0, 0, NULL },
    { POKEMON_CMD_16, func_802DA68C_72B88C, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E21D8_7333D8[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2208_733408[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2238_733438[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_15, func_802DA5B4_72B7B4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2278_733478[] = {
    { POKEMON_CMD_9, func_802DA200_72B400, 0, NULL },
    { POKEMON_CMD_13, func_802DA2C8_72B4C8, 0, NULL },
    { POKEMON_CMD_10, func_802DA330_72B530, 0, NULL },
    { POKEMON_CMD_14, func_802DA3A0_72B5A0, 0, NULL },
    { VOLCANO_CMD_44, func_802DA7A4_72B9A4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E22D8_7334D8[] = {
    { 100, func_802D9F90_72B190 },
    { 100, func_802DA000_72B200 },
    { 100, func_802DA100_72B300 },
    { 0, NULL },
};

Vec3f D_802E22F8_7334F8 = { 0, 0, 0 };

InteractionHandler D_802E2304_733504[] = {
    { POKEMON_CMD_9, func_802DA97C_72BB7C, 0, NULL },
    { POKEMON_CMD_13, func_802DAA34_72BC34, 0, NULL },
    { POKEMON_CMD_10, func_802DAA34_72BC34, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E2344_733544 = {
    &D_802E1FF8_7331F8,
    func_802D9F24_72B124,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E2358_733558 = {
    vulpix_model,
    vulpix_materials,
    renderPokemonModelTypeIFogged,
    &D_802E2344_733544,
    { 1.7, 1.7, 1.7 },
    { 0, 60, 0 },
    30,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

s32 func_802D9D00_72AF00(GObj* obj) {
    Vec3f sp2C = D_802E22F8_7334F8;
    Pokemon* pokemon = GET_POKEMON(obj);
    WorldBlock* block;
    DObj* model = obj->data.dobj;
    UNUSED s32 pad[1];

    block = getCurrentWorldBlock();
    func_8001FCA4(&sp2C, pokemon->path, 0.99999f);
    pokemon->pos1.x = (sp2C.x - block->descriptor->worldPos.x) * 100.0f;
    pokemon->pos1.z = (sp2C.z - block->descriptor->worldPos.z) * 100.0f;

    if (SQ(pokemon->pos1.x - GET_TRANSFORM(model)->pos.v.x) + SQ(pokemon->pos1.z - GET_TRANSFORM(model)->pos.v.z) < SQ(1000.0f)) {
        return true;
    } else {
        return false;
    }
}

POKEMON_FUNC(func_802D9DFC_72AFFC)
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    while (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_1000)) {
        if (func_802D9D00_72AF00(obj)) {
            cmdSendCommand(obj, VOLCANO_CMD_44, obj);
        }
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802D9E7C_72B07C)
    s32 blockIndex;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 4 || blockIndex == 4 && blockPart >= 0.1) {
            break;
        }
        ohWait(1);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802D9F24_72B124)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->miscVars[1].field1 = 0;

    Pokemon_StartAuxProc(obj, func_802D9DFC_72AFFC);
    Pokemon_StartAuxProc(obj, func_802D9E7C_72B07C);

    Pokemon_SetState(obj, func_802D9F90_72B190);
}

static void nullsub() {
}

POKEMON_FUNC(func_802D9F90_72B190)
    Pokemon_SetAnimation(obj, &D_802E1FF8_7331F8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2098_733298;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E22D8_7334D8);
}

POKEMON_FUNC(func_802DA000_72B200)
    Pokemon_SetAnimation(obj, &D_802E200C_73320C);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802DA0A4_72B2A4);
    pokemon->transitionGraph = D_802E2098_733298;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802D9F90_72B190);
    }

    Pokemon_SetStateRandom(obj, D_802E22D8_7334D8);
}

POKEMON_FUNC(func_802DA0A4_72B2A4)
    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DA100_72B300)
    Pokemon_SetAnimation(obj, &D_802E2020_733220);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802DA1A4_72B3A4);
    pokemon->transitionGraph = D_802E2098_733298;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802D9F90_72B190);
    }

    Pokemon_SetStateRandom(obj, D_802E22D8_7334D8);
}

POKEMON_FUNC(func_802DA1A4_72B3A4)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DA200_72B400)
    Pokemon_SetAnimation(obj, &D_802E2048_733248);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E205C_73325C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E2070_733270);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DA5D8_72B7D8);
}

POKEMON_FUNC(func_802DA2C8_72B4C8)
    Pokemon_SetAnimation(obj, &D_802E2034_733234);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DA5D8_72B7D8);
}

POKEMON_FUNC(func_802DA330_72B530)
    Pokemon_SetAnimation(obj, &D_802E2034_733234);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E21D8_7333D8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D9F90_72B190);
}

POKEMON_FUNC(func_802DA3A0_72B5A0)
    Pokemon_StartPathProc(obj, func_802DA428_72B628);
    pokemon->transitionGraph = D_802E2118_733318;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802D9F90_72B190);
    }

    Pokemon_SetState(obj, func_802DA4AC_72B6AC);
}

POKEMON_FUNC(func_802DA428_72B628)
    Pokemon_SetAnimation(obj, &D_802E2020_733220);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DA4AC_72B6AC)
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802D9F90_72B190);
    }

    Pokemon_SetAnimation(obj, &D_802E2084_733284);
    Pokemon_StartPathProc(obj, func_802DA55C_72B75C);
    pokemon->transitionGraph = D_802E2178_733378;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802DA4AC_72B6AC);
    }

    Pokemon_SetState(obj, func_802DA5D8_72B7D8);
}

POKEMON_FUNC(func_802DA55C_72B75C)
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

POKEMON_FUNC(func_802DA5B4_72B7B4)
    Pokemon_SetState(obj, func_802DA3A0_72B5A0);
}

POKEMON_FUNC(func_802DA5D8_72B7D8)
    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E2238_733438;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802D9F90_72B190);
}

static void nullsub2() {
}

POKEMON_FUNC(func_802DA640_72B840)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DA68C_72B88C)
    Pokemon_SetAnimation(obj, &D_802E2020_733220);
    Pokemon_StartPathProc(obj, func_802DA748_72B948);
    pokemon->transitionGraph = D_802E2278_733478;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED) {
        Pokemon_SetState(obj, func_802D9F90_72B190);
    }

    pokemon->transitionGraph = D_802E2278_733478;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D9F90_72B190);
}

POKEMON_FUNC(func_802DA748_72B948)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DA7A4_72B9A4)
    pokemon->flags &= ~POKEMON_FLAG_200;
    pokemon->flags &= ~POKEMON_FLAG_800;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;

    Pokemon_SetAnimation(obj, &D_802E2020_733220);
    pokemon->hSpeed = 160.0f;
    Pokemon_StartPathProc(obj, func_802DA848_72BA48);
    pokemon->transitionGraph = D_802E2304_733504;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802DA8A4_72BAA4);
}

POKEMON_FUNC(func_802DA848_72BA48)
    Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DA8A4_72BAA4)
    Pokemon_SetAnimation(obj, &D_802E2084_733284);
    if (pokemon->miscVars[1].field1 == 0) {
        pokemon->miscVars[1].field1 = 1;
        Pokemon_StartPathProc(obj, func_802DA930_72BB30);
    }
    pokemon->transitionGraph = D_802E2304_733504;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, func_802DA8A4_72BAA4);
}

POKEMON_FUNC(func_802DA930_72BB30)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DA97C_72BB7C)
    Pokemon_SetAnimation(obj, &D_802E2048_733248);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E205C_73325C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E2070_733270);
    pokemon->transitionGraph = D_802E2304_733504;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DA7A4_72B9A4);
}

POKEMON_FUNC(func_802DAA34_72BC34)
    Pokemon_SetAnimation(obj, &D_802E2034_733234);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DA7A4_72B9A4);
}

GObj* func_802DAA9C_72BC9C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2358_733558);
}
