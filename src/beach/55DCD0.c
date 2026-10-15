#include "common.h"
#include "beach.h"

extern AnimCmd* D_801906A0_11CB30[];
extern AnimCmd* D_80191AE0_11DF70[];
extern AnimCmd* D_80192C20_11F0B0[];
extern AnimCmd* D_801949A0_120E30[];
extern AnimCmd* D_80195A70_121F00[];
extern AnimCmd* D_80196070_122500[];
extern AnimCmd* D_80197A00_123E90[];
extern AnimCmd* D_80198BF0_125080[];
extern AnimCmd* D_8019A950_126DE0[];
extern AnimCmd* D_8019C270_128700[];
extern AnimCmd** D_8019D890_129D20[];
extern AnimCmd** D_8019D9E0_129E70[];
extern AnimCmd** D_8019DAF0_129F80[];
extern AnimCmd** D_8019DC60_12A0F0[];
extern AnimCmd** D_8019DD80_12A210[];
extern AnimCmd** D_8019DE50_12A2E0[];
extern AnimCmd** D_8019DFF0_12A480[];
extern AnimCmd** D_8019E110_12A5A0[];
extern AnimCmd** D_8019E260_12A6F0[];
extern AnimCmd** D_8019E3F0_12A880[];
extern Texture** meowth_materials[];
extern UnkEC64Arg3 meowth_model[];

// .data
s32 D_beach_802CC330[] = { SOUND_ID_299 };
s32 D_beach_802CC334[] = { SOUND_ID_300 };
s32 D_beach_802CC338[] = { SOUND_ID_298 };
s32 D_beach_802CC33C[] = { SOUND_ID_302 };
s32 D_beach_802CC340[] = { SOUND_ID_301 };

AnimationHeader D_beach_802CC344 = {
    0.32f,
    50.0f,
    D_801949A0_120E30,
    D_8019DC60_12A0F0,
    NULL
};

AnimationHeader D_beach_802CC358 = {
    0.56f,
    60.0f,
    D_801906A0_11CB30,
    D_8019D890_129D20,
    NULL
};

AnimationHeader D_beach_802CC36C = {
    0.45f,
    24.0f,
    D_80191AE0_11DF70,
    D_8019D9E0_129E70,
    NULL
};

AnimationHeader D_beach_802CC380 = {
    0.33f,
    68.0f,
    D_80192C20_11F0B0,
    D_8019DAF0_129F80,
    D_beach_802CC330
};

AnimationHeader D_beach_802CC394 = {
    0.5f,
    70.0f,
    D_80198BF0_125080,
    D_8019E110_12A5A0,
    D_beach_802CC334
};

AnimationHeader D_beach_802CC3A8 = {
    0.42f,
    59.0f,
    D_8019C270_128700,
    D_8019E3F0_12A880,
    D_beach_802CC338
};

AnimationHeader D_beach_802CC3BC = {
    0.18f,
    30.0f,
    D_80195A70_121F00,
    D_8019DD80_12A210,
    NULL
};

AnimationHeader D_beach_802CC3D0 = {
    0.28f,
    55.0f,
    D_80197A00_123E90,
    D_8019DFF0_12A480,
    D_beach_802CC33C
};

AnimationHeader D_beach_802CC3E4 = {
    0.21f,
    33.0f,
    D_8019A950_126DE0,
    D_8019E260_12A6F0,
    D_beach_802CC340
};

AnimationHeader D_beach_802CC3F8 = {
    1.0f,
    150.0f,
    D_80196070_122500,
    D_8019DE50_12A2E0,
    NULL
};

InteractionHandler D_beach_802CC40C[] = {
    { POKEMON_CMD_9, func_beach_802C5FF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C60E8, 0.0f, NULL },
    { POKEMON_CMD_10, func_beach_802C6210, 0.0f, NULL },
    { POKEMON_CMD_14, func_beach_802C62E4, 0.0f, NULL },
    { POKEMON_CMD_15, func_beach_802C6478, 0.0f, NULL },
    { POKEMON_CMD_5, func_beach_802C649C, 0.0f, NULL },
    { POKEMON_CMD_6, func_beach_802C649C, 0.0f, NULL },
    { POKEMON_CMD_7, func_beach_802C649C, 0.0f, NULL },
    { POKEMON_CMD_16, func_beach_802C6580, 333.33334f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

RandomState D_beach_802CC4AC[] = {
    { 100, func_beach_802C5E88 },
    { 100, func_beach_802C5EF8 },
    { 0, NULL },
};

InteractionHandler D_beach_802CC4C4[] = {
    { POKEMON_CMD_9, func_beach_802C5FF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C60E8, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC4F4[] = {
    { POKEMON_CMD_9, func_beach_802C5FF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C60E8, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC524[] = {
    { POKEMON_CMD_9, func_beach_802C5FF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C60E8, 0.0f, NULL },
    { POKEMON_CMD_10, func_beach_802C6210, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC564[] = {
    { POKEMON_CMD_9, func_beach_802C5FF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C60E8, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC594[] = {
    { POKEMON_CMD_9, func_beach_802C5FF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C60E8, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC5C4[] = {
    { POKEMON_CMD_9, func_beach_802C5FF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C60E8, 0.0f, NULL },
    { POKEMON_CMD_10, func_beach_802C6210, 0.0f, NULL },
    { POKEMON_CMD_5, func_beach_802C649C, 0.0f, NULL },
    { POKEMON_CMD_6, func_beach_802C649C, 0.0f, NULL },
    { POKEMON_CMD_7, func_beach_802C649C, 0.0f, NULL },
    { POKEMON_CMD_14, func_beach_802C62E4, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC644[] = {
    { POKEMON_CMD_9, func_beach_802C6700, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C67E0, 0.0f, NULL },
    { POKEMON_CMD_16, func_beach_802C6944, 400.0f, NULL },
    { POKEMON_CMD_5, func_beach_802C6854, 0.0f, NULL },
    { POKEMON_CMD_6, func_beach_802C6854, 0.0f, NULL },
    { POKEMON_CMD_7, func_beach_802C6854, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC6B4[] = {
    { POKEMON_CMD_9, func_beach_802C6700, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C67E0, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC6E4[] = {
    { POKEMON_CMD_9, func_beach_802C6A3C, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C6B28, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC714[] = {
    { POKEMON_CMD_9, func_beach_802C6A3C, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C6B28, 0.0f, NULL },
    { POKEMON_CMD_16, func_beach_802C6944, 400.0f, NULL },
    { POKEMON_CMD_5, func_beach_802C6B8C, 0.0f, NULL },
    { POKEMON_CMD_6, func_beach_802C6B8C, 0.0f, NULL },
    { POKEMON_CMD_7, func_beach_802C6B8C, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC784[] = {
    { POKEMON_CMD_9, func_beach_802C6A3C, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C6B28, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC7B4[] = {
    { POKEMON_CMD_9, func_beach_802C6A3C, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C6B28, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC7E4[] = {
    { POKEMON_CMD_28, func_beach_802C6C60, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC804[] = {
    { POKEMON_CMD_16, func_beach_802C6CC4, 700.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC824[] = {
    { POKEMON_CMD_9, func_beach_802C5FF8, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C60E8, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC854[] = {
    { POKEMON_CMD_16, func_beach_802C6D9C, 666.6667f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC874[] = {
    { POKEMON_CMD_9, func_beach_802C6EC0, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C6F6C, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC8A4[] = {
    { POKEMON_CMD_9, func_beach_802C6EC0, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C6F6C, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC8D4[] = {
    { POKEMON_CMD_9, func_beach_802C6EC0, 0.0f, NULL },
    { POKEMON_CMD_13, func_beach_802C6F6C, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC904[] = {
    { POKEMON_CMD_29, func_beach_802C7050, 0.0f, NULL },
    { POKEMON_CMD_36, func_beach_802C70C0, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

InteractionHandler D_beach_802CC934[] = {
    { POKEMON_CMD_9, func_beach_802C7130, 0.0f, NULL },
    { POKEMON_CMD_58, NULL, 0.0f, NULL },
};

PokemonAnimationSetup D_beach_802CC954 = {
    &D_beach_802CC344,
    func_beach_802C5DAC,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CC968 = {
    meowth_model,
    meowth_materials,
    renderPokemonModelTypeBFogged,
    &D_beach_802CC954,
    { 2.4f, 2.4f, 2.4f },
    { 0.0f, 107.0f, -5.0f },
    21.0f,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802C5C60(GObj* obj) {
    UNUSED s32 pad[3];
    DObj* model = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 timer;

    pokemon->miscVars[4].field1 = true;

    timer = 38;
    while (pokemon->miscVars[4].field1 && timer--) {
        ohWait(1);
    }

    if (pokemon->miscVars[4].field1) {
        pokemon->collisionOffset.x = -60.0f / (GET_TRANSFORM(model)->scale.v.x / 0.1f);
        pokemon->collisionOffset.y = 207.0f / (GET_TRANSFORM(model)->scale.v.y / 0.1f);
        pokemon->collisionOffset.z = 31.0f / (GET_TRANSFORM(model)->scale.v.z / 0.1f);
        pokemon->collisionRadius = 38.3f * (GET_TRANSFORM(model)->scale.v.y / 0.1f);
    }

    timer = 42;
    while (pokemon->miscVars[4].field1 && timer--) {
        ohWait(1);
    }

    pokemon->collisionOffset.x = pokemon->miscVars[0].field0;
    pokemon->collisionOffset.y = pokemon->miscVars[1].field0;
    pokemon->collisionOffset.z = pokemon->miscVars[2].field0;
    pokemon->collisionRadius = pokemon->miscVars[3].field0;
    Pokemon_StopAuxProc(obj);
}

void func_beach_802C5DAC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field0 = pokemon->collisionOffset.x;
    pokemon->miscVars[1].field0 = pokemon->collisionOffset.y;
    pokemon->miscVars[2].field0 = pokemon->collisionOffset.z;
    pokemon->miscVars[3].field0 = pokemon->collisionRadius;

    if (pokemon->behavior == 1) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C6658);
    }

    if (pokemon->behavior == 2) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C6C10);
    }

    if (pokemon->behavior == 3) {
        pokemon = pokemon;
        Pokemon_SetState(obj, func_beach_802C6D20);
    }

    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, func_beach_802C6FD4);
    }

    Pokemon_SetState(obj, func_beach_802C5E88);
}

void func_beach_802C5E88(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC344);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_beach_802CC40C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC4AC);
}

void func_beach_802C5EF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC358);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_beach_802C5F9C);
    pokemon->transitionGraph = D_beach_802CC40C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_beach_802C5E88);
    }
    Pokemon_SetStateRandom(obj, D_beach_802CC4AC);
}

void func_beach_802C5F9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C5FF8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = D_beach_802CC4C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_beach_802C619C);
    Pokemon_SetAnimation(obj, &D_beach_802CC36C);
    pokemon->pokemonLoopTarget = 2;
    pokemon->transitionGraph = D_beach_802CC4C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC4AC);
}

void func_beach_802C60E8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &D_beach_802CC394);
    pokemon->transitionGraph = D_beach_802CC4F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_beach_802C619C);
    Pokemon_SetAnimation(obj, &D_beach_802CC36C);
    pokemon->pokemonLoopTarget = 2;
    pokemon->transitionGraph = D_beach_802CC4F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->apple = NULL;
    Pokemon_SetStateRandom(obj, D_beach_802CC4AC);
}

void func_beach_802C619C(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;

    while (true) {
        if (Pokemon_StepWalkInDirectionFacing(obj, MOVEMENT_FLAG_ON_GROUND)) {
            break;
        }

        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C6210(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    pokemon = pokemon;
    Pokemon_SetAnimation(obj, &D_beach_802CC36C);
    Pokemon_StartPathProc(obj, func_beach_802C6288);
    pokemon->transitionGraph = D_beach_802CC524;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC4AC);
}

void func_beach_802C6288(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunAwayFromTarget(obj, 300.0f, 0.1f, MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C62E4(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    Pokemon_SetAnimation(obj, &D_beach_802CC358);
    Pokemon_StartPathProc(obj, func_beach_802C63F4);
    pokemon->transitionGraph = D_beach_802CC564;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_beach_802C5E88);
    }
    Pokemon_SetAnimation(obj, &D_beach_802CC3E4);
    pokemon->counter = 33, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_beach_802CC564;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_beach_802C5E88);
    }
    Pokemon_EatApple(obj);
    pokemon->transitionGraph = D_beach_802CC564;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC4AC);
}

void func_beach_802C63F4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    Pokemon_SetAnimation(obj, &D_beach_802CC36C);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C6478(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802C62E4);
}

void func_beach_802C649C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    Pokemon_SetAnimation(obj, &D_beach_802CC3F8);
    Pokemon_StartPathProc(obj, func_beach_802C6514);
    pokemon->transitionGraph = D_beach_802CC594;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetStateRandom(obj, D_beach_802CC4AC);
}

void func_beach_802C6514(GObj* obj) {
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

void func_beach_802C6580(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_beach_802C660C);
    Pokemon_StartAuxProc(obj, func_beach_802C5C60);
    Pokemon_SetAnimation(obj, &D_beach_802CC380);
    pokemon->transitionGraph = D_beach_802CC5C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->miscVars[4].field1 = 0;
    Pokemon_SetStateRandom(obj, D_beach_802CC4AC);
}

void func_beach_802C660C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_beach_802C6658(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802C667C);
}

void func_beach_802C667C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_beach_802CC344);
    pokemon->transitionGraph = D_beach_802CC644;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C67F8() {
}

void func_beach_802C6700(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 sp24;
    f32 sp20;

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    getLevelProgress(&sp24, &sp20);
    sp20 += sp24;
    if (sp20 > 3.0f) {
        Pokemon_StartPathProc(obj, func_beach_802C660C);
        Pokemon_SetState(obj, func_beach_802C6AA0);
    }
    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_28, obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C67E0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &D_beach_802CC394);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C667C);
}

void func_beach_802C6854(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_beach_802C68D8);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CC3F8);
    pokemon->transitionGraph = D_beach_802CC6B4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C667C);
}

void func_beach_802C68D8(GObj* obj) {
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

// clang-format off
void func_beach_802C6944(GObj* arg0) { \
    Pokemon* pokemon = GET_POKEMON(arg0);
    // clang-format on
    Pokemon_StartPathProc(arg0, func_beach_802C660C);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_StartAuxProc(arg0, func_beach_802C5C60);
    Pokemon_SetAnimation(arg0, &D_beach_802CC380);
    pokemon->transitionGraph = D_beach_802CC6E4;
    Pokemon_WaitForFlag(arg0, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->miscVars[4].field1 = 0;
    Pokemon_SetState(arg0, func_beach_802C69D4);
}

void func_beach_802C69D4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CC344);
    pokemon->transitionGraph = D_beach_802CC714;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C6A3C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_ForceAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C6AA0);
}

void func_beach_802C6AA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_ForceAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = D_beach_802CC784;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C69D4);
}

void func_beach_802C6B28(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[4].field1 = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_ForceAnimation(obj, &D_beach_802CC394);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C69D4);
}

void func_beach_802C6B8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_beach_802C68D8);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CC3F8);
    pokemon->transitionGraph = D_beach_802CC7B4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_beach_802C69D4);
}

void func_beach_802C6C10(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    pokemon->transitionGraph = D_beach_802CC7E4;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C6C60(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    SHOW_POKEMON();
    Pokemon_SetAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = D_beach_802CC804;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C6CC4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = D_beach_802CC824;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C6580);
}

void func_beach_802C6D20(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802C6D44);
}

void func_beach_802C6D44(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC344);
    pokemon->transitionGraph = D_beach_802CC854;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C6D9C(GObj* obj) {
    Pokemon_StartPathProc(obj, func_beach_802C6DD4);
    Pokemon_SetState(obj, func_beach_802C6E40);
}

void func_beach_802C6DD4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1.0f, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(0);
}

void func_beach_802C6E40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CC36C);
    pokemon->transitionGraph = D_beach_802CC874;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CC344);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C6EC0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = D_beach_802CC8A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C6E40);
}

void func_beach_802C6F6C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_ForceAnimation(obj, &D_beach_802CC394);
    pokemon->transitionGraph = D_beach_802CC8D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C6E40);
}

void func_beach_802C6FD4(GObj* obj) {
    Pokemon_SetState(obj, func_beach_802C6FF8);
}

void func_beach_802C6FF8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC344);
    pokemon->transitionGraph = D_beach_802CC904;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C7050(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_beach_802CBDD8(obj);
    Pokemon_SetAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CC3BC);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C70C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_beach_802CC3F8);
    Pokemon_StartPathProc(obj, func_beach_802C660C);
    pokemon->transitionGraph = D_beach_802CC934;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802C7130(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_beach_802CC3A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CC3BC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_beach_802CC3D0);
    pokemon->transitionGraph = D_beach_802CC934;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_beach_802C70C0);
}

void func_beach_802C71E8(GObj* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    Pokemon* pokemon = GET_POKEMON(arg0);

    if (pokemon->behavior == 1) {
        pokemonChangeBlock(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    } else {
        pokemonChangeBlockOnGround(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    }
}

void func_beach_802C7270(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    if (spawn->behavior == 1) {
        // required to match
        if (false) {
        }

        Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CC968);
    } else {
        Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_beach_802CC968);
    }
}
