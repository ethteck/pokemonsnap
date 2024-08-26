#include "volcano/volcano.h"

extern AnimCmd* D_8019F220[];
extern AnimCmd* D_801A0A00[];
extern AnimCmd* D_80199120[];
extern AnimCmd* D_8019E850[];
extern AnimCmd* D_801A3460[];
extern AnimCmd* D_801A7210[];
extern AnimCmd* D_80199FC0[];
extern AnimCmd* D_801A4E60[];

extern AnimCmd** D_801A94C0[];
extern AnimCmd** D_801A95C0[];
extern AnimCmd** D_801A92C0[];
extern AnimCmd** D_801A9420[];
extern AnimCmd** D_801A96C0[];
extern AnimCmd** D_801A9820[];
extern AnimCmd** D_801A9360[];
extern AnimCmd** D_801A9760[];

void func_802DBB78_72CD78(GObj*);
void func_802DBDB8_72CFB8(GObj*);
void func_802DB6F8_72C8F8(GObj*);
void func_802DB768_72C968(GObj*);
void func_802DB868_72CA68(GObj*);
void func_802DB968_72CB68(GObj*);
void func_802DB5A0_72C7A0(GObj*);
void func_802DBAB8_72CCB8(GObj*);
void func_802DBD94_72CF94(GObj*);
void func_802DBE18_72D018(GObj*);
void func_802DBED8_72D0D8(GObj*);
void func_802DBFA8_72D1A8(GObj*);
void func_802DB9D8_72CBD8(GObj*);
void func_802DBA48_72CC48(GObj*);
void func_802DB660_72C860(GObj*);
void func_802DB80C_72CA0C(GObj*);
void func_802DB90C_72CB0C(GObj*);
void func_802DBB2C_72CD2C(GObj*);
void func_802DBC84_72CE84(GObj*);
void func_802DBC00_72CE00(GObj*);
void func_802DBD34_72CF34(GObj*);
void func_802DBE8C_72D08C(GObj*);
void func_802DBF4C_72D14C(GObj*);

s32 D_802E2750_733950[] = { SOUND_ID_271 };
s32 D_802E2754_733954[] = { SOUND_ID_272 };
s32 D_802E2758_733958[] = { SOUND_ID_270 };
s32 D_802E275C_73395C[] = { SOUND_ID_273, SOUND_ID_388 };

AnimationHeader D_802E2764_733964 = {
    0.5,
    135,
    D_8019F220,
    D_801A94C0,
    NULL
};

AnimationHeader D_802E2778_733978 = {
    0.6,
    135,
    D_801A0A00,
    D_801A95C0,
    D_802E2750_733950
};

AnimationHeader D_802E278C_73398C = {
    0.4,
    40,
    D_80199120,
    D_801A92C0,
    NULL
};

AnimationHeader D_802E27A0_7339A0 = {
    0.35,
    20,
    D_8019E850,
    D_801A9420,
    NULL
};

AnimationHeader D_802E27B4_7339B4 = {
    0.5,
    40,
    D_801A3460,
    D_801A96C0,
    D_802E2754_733954
};

AnimationHeader D_802E27C8_7339C8 = {
    0.5,
    90,
    D_801A7210,
    D_801A9820,
    D_802E2758_733958
};

AnimationHeader D_802E27DC_7339DC = {
    0.7,
    55,
    D_80199FC0,
    D_801A9360,
    NULL
};

AnimationHeader D_802E27F0_7339F0 = {
    0.7,
    85,
    D_801A4E60,
    D_801A9760,
    D_802E275C_73395C
};

InteractionHandler D_802E2804_733A04[] = {
    { POKEMON_CMD_9, func_802DB9D8_72CBD8, 0, NULL },
    { POKEMON_CMD_13, func_802DBA48_72CC48, 0, NULL },
    { POKEMON_CMD_10, func_802DBAB8_72CCB8, 0, NULL },
    { POKEMON_CMD_14, func_802DBB78_72CD78, 0, NULL },
    { POKEMON_CMD_15, func_802DBD94_72CF94, 0, NULL },
    { POKEMON_CMD_5, func_802DBE18_72D018, 0, NULL },
    { POKEMON_CMD_6, func_802DBE18_72D018, 0, NULL },
    { POKEMON_CMD_7, func_802DBE18_72D018, 0, NULL },
    { POKEMON_CMD_16, func_802DBED8_72D0D8, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_23, func_802DBFA8_72D1A8, 60, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E28B4_733AB4[] = {
    { POKEMON_CMD_9, func_802DB9D8_72CBD8, 0, NULL },
    { POKEMON_CMD_13, func_802DBA48_72CC48, 0, NULL },
    { POKEMON_CMD_10, func_802DBAB8_72CCB8, 0, NULL },
    { POKEMON_CMD_14, func_802DBB78_72CD78, 0, NULL },
    { POKEMON_CMD_5, func_802DBE18_72D018, 0, NULL },
    { POKEMON_CMD_6, func_802DBE18_72D018, 0, NULL },
    { POKEMON_CMD_7, func_802DBE18_72D018, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2934_733B34[] = {
    { POKEMON_CMD_9, func_802DB9D8_72CBD8, 0, NULL },
    { POKEMON_CMD_13, func_802DBA48_72CC48, 0, NULL },
    { POKEMON_CMD_10, func_802DBAB8_72CCB8, 0, NULL },
    { POKEMON_CMD_14, func_802DBB78_72CD78, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2984_733B84[] = {
    { POKEMON_CMD_9, func_802DB9D8_72CBD8, 0, NULL },
    { POKEMON_CMD_13, func_802DBA48_72CC48, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E29B4_733BB4[] = {
    { POKEMON_CMD_9, func_802DB9D8_72CBD8, 0, NULL },
    { POKEMON_CMD_13, func_802DBA48_72CC48, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E29E4_733BE4[] = {
    { POKEMON_CMD_9, func_802DB9D8_72CBD8, 0, NULL },
    { POKEMON_CMD_13, func_802DBA48_72CC48, 0, NULL },
    { POKEMON_CMD_15, func_802DBD94_72CF94, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2A24_733C24[] = {
    { POKEMON_CMD_9, func_802DB9D8_72CBD8, 0, NULL },
    { POKEMON_CMD_13, func_802DBA48_72CC48, 0, NULL },
    { POKEMON_CMD_10, func_802DBAB8_72CCB8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E2A64_733C64[] = {
    { 100, func_802DB6F8_72C8F8 },
    { 100, func_802DB768_72C968 },
    { 100, func_802DB868_72CA68 },
    { 100, func_802DB968_72CB68 },
    { 0, NULL },
};

f32 D_802E2A8C_733C8C[] = { SURFACE_TYPE_7F6633, 0 };

PokemonAnimationSetup D_802E2A94_733C94 = {
    &D_802E2764_733964,
    func_802DB5A0_72C7A0,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E2AA8_733CA8 = {
    arcanine_model,
    arcanine_materials,
    renderPokemonModelTypeIFogged,
    &D_802E2A94_733C94,
    { 1.4, 1.4, 1.4 },
    { 0, 118, 10 },
    105,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(func_802DB5A0_72C7A0)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->forbiddenGround = D_802E2A8C_733C8C;

    Pokemon_SetAnimation(obj, &D_802E27F0_7339F0);
    Pokemon_StartPathProc(obj, func_802DB660_72C860);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->forbiddenGround = NULL;
    Pokemon_SetAnimation(obj, &D_802E27DC_7339DC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2984_733B84;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DB6F8_72C8F8);
}

POKEMON_FUNC(func_802DB660_72C860)
    GroundResult result;

    Pokemon_TurnToTarget(obj, TAU, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->hSpeed = 150.0f;

    while (true) {
        func_802D6E14_728014(obj);
        getGroundAt(position->v.x, position->v.z, &result);
        position->v.y = result.height;
        ohWait(1);
    }
}

POKEMON_FUNC(func_802DB6F8_72C8F8)
    Pokemon_SetAnimation(obj, &D_802E2764_733964);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2804_733A04;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2A64_733C64);
}

POKEMON_FUNC(func_802DB768_72C968)
    Pokemon_SetAnimation(obj, &D_802E278C_73398C);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802DB80C_72CA0C);
    pokemon->transitionGraph = D_802E2804_733A04;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802DB6F8_72C8F8);
    }

    Pokemon_SetStateRandom(obj, D_802E2A64_733C64);
}

POKEMON_FUNC(func_802DB80C_72CA0C)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DB868_72CA68)
    Pokemon_SetAnimation(obj, &D_802E27A0_7339A0);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802DB90C_72CB0C);
    pokemon->transitionGraph = D_802E2804_733A04;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802DB6F8_72C8F8);
    }

    Pokemon_SetStateRandom(obj, D_802E2A64_733C64);
}

POKEMON_FUNC(func_802DB90C_72CB0C)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DB968_72CB68)
    Pokemon_ForceAnimation(obj, &D_802E2778_733978);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2804_733A04;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2A64_733C64);
}

POKEMON_FUNC(func_802DB9D8_72CBD8)
    Pokemon_SetAnimation(obj, &D_802E27B4_7339B4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2984_733B84;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802DBDB8_72CFB8);
}

POKEMON_FUNC(func_802DBA48_72CC48)
    Pokemon_SetAnimation(obj, &D_802E27B4_7339B4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2984_733B84;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DBDB8_72CFB8);
}

POKEMON_FUNC(func_802DBAB8_72CCB8)
    Pokemon_SetAnimation(obj, &D_802E27DC_7339DC);
    Pokemon_StartPathProc(obj, func_802DBB2C_72CD2C);
    pokemon->transitionGraph = D_802E2984_733B84;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DB6F8_72C8F8);
}

POKEMON_FUNC(func_802DBB2C_72CD2C)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DBB78_72CD78)
    Pokemon_StartPathProc(obj, func_802DBC00_72CE00);
    pokemon->transitionGraph = D_802E28B4_733AB4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802DB6F8_72C8F8);
    }

    Pokemon_SetState(obj, func_802DBC84_72CE84);
}

POKEMON_FUNC(func_802DBC00_72CE00)
    Pokemon_SetAnimation(obj, &D_802E27A0_7339A0);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 250.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DBC84_72CE84)
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802DB6F8_72C8F8);
    }

    Pokemon_StartPathProc(obj, func_802DBD34_72CF34);
    Pokemon_SetAnimation(obj, &D_802E27C8_7339C8);
    pokemon->transitionGraph = D_802E2934_733B34;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802DBC84_72CE84);
    }

    Pokemon_SetState(obj, func_802DBDB8_72CFB8);
}

POKEMON_FUNC(func_802DBD34_72CF34)
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

POKEMON_FUNC(func_802DBD94_72CF94)
    Pokemon_SetState(obj, func_802DBB78_72CD78);
}

POKEMON_FUNC(func_802DBDB8_72CFB8)
    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E29E4_733BE4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802DB6F8_72C8F8);
}

POKEMON_FUNC(func_802DBE18_72D018)
    Pokemon_SetAnimation(obj, &D_802E278C_73398C);
    Pokemon_StartPathProc(obj, func_802DBE8C_72D08C);
    pokemon->transitionGraph = D_802E29B4_733BB4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802DB6F8_72C8F8);
}

POKEMON_FUNC(func_802DBE8C_72D08C)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DBED8_72D0D8)
    Pokemon_SetAnimation(obj, &D_802E27A0_7339A0);
    Pokemon_StartPathProc(obj, func_802DBF4C_72D14C);
    pokemon->transitionGraph = D_802E2A24_733C24;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802DB6F8_72C8F8);
}

POKEMON_FUNC(func_802DBF4C_72D14C)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DBFA8_72D1A8)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &D_802E2778_733978);
    pokemon->transitionGraph = D_802E2A24_733C24;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2A64_733C64);
}

GObj* func_802DC018_72D218(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2AA8_733CA8);
}
