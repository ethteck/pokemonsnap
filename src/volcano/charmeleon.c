#include "volcano/volcano.h"

extern UnkEC64Arg3 D_8033E520[];
extern Texture** D_8033A2F0[];

extern AnimCmd* D_8017E7F0[];
extern AnimCmd* D_80180830[];
extern AnimCmd* D_8017F660[];
extern AnimCmd* D_8017D930[];
extern AnimCmd* D_8017E0F0[];
extern AnimCmd* D_80182130[];
extern AnimCmd* D_80182CB0[];
extern AnimCmd* D_8017F000[];
extern AnimCmd* D_801815D0[];

extern AnimCmd** D_80183AD0[];
extern AnimCmd** D_80184010[];
extern AnimCmd** D_80183DE0[];
extern AnimCmd** D_80183900[];
extern AnimCmd** D_80183A20[];
extern AnimCmd** D_801843E0[];
extern AnimCmd** D_80184580[];
extern AnimCmd** D_80183CB0[];
extern AnimCmd** D_801841C0[];

GObj* func_802DD214_72E414(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
void func_802DC108_72D308(GObj*);
void func_802DCE40_72E040(GObj*);
void func_802DCF44_72E144(GObj*);
void func_802DCFAC_72E1AC(GObj*);
void func_802DCC40_72DE40(GObj*);
void func_802DCD40_72DF40(GObj*);
void func_802DC170_72D370(GObj*);
void func_802DC1F8_72D3F8(GObj*);
void func_802DC3A0_72D5A0(GObj*);
void func_802DC410_72D610(GObj*);
void func_802DC758_72D958(GObj*);
void func_802DC7A8_72D9A8(GObj*);
void func_802DC99C_72DB9C(GObj*);
void func_802DC590_72D790(GObj*);
void func_802DC4F0_72D6F0(GObj*);
void func_802DC480_72D680(GObj*);
void func_802DCBD0_72DDD0(GObj*);
void func_802DCB44_72DD44(GObj*);
void func_802DC280_72D480(GObj*);
void func_802DC6B4_72D8B4(GObj*);
void func_802DC7F8_72D9F8(GObj*);
void func_802DC6B4_72D8B4(GObj*);
void func_802DC924_72DB24(GObj*);
void func_802DC850_72DA50(GObj*);
void func_802D6CC0_727EC0(GObj*);
void func_802DCA28_72DC28(GObj*);
void func_802DCCE4_72DEE4(GObj*);
void func_802DCDE4_72DFE4(GObj*);
void func_802DD0E8_72E2E8(GObj*);
void func_802DD034_72E234(GObj*);
void func_802DD1C0_72E3C0(GObj*);

s32 D_802E2AE0_733CE0[] = { SOUND_ID_288 };
s32 D_802E2AE4_733CE4[] = { SOUND_ID_289 };
s32 D_802E2AE8_733CE8[] = { SOUND_ID_290 };

AnimationHeader D_802E2AEC_733CEC = {
    0.6,
    60,
    D_8017E7F0,
    D_80183AD0,
    NULL
};

AnimationHeader D_802E2B00_733D00 = {
    0.8,
    100,
    D_80180830,
    D_80184010,
    D_802E2AE0_733CE0
};

AnimationHeader D_802E2B14_733D14 = {
    0.7,
    105,
    D_8017F660,
    D_80183DE0,
    NULL
};

AnimationHeader D_802E2B28_733D28 = {
    0.69,
    40,
    D_8017D930,
    D_80183900,
    NULL
};

AnimationHeader D_802E2B3C_733D3C = {
    0.75,
    16,
    D_8017E0F0,
    D_80183A20,
    NULL
};

AnimationHeader D_802E2B50_733D50 = {
    1.1,
    100,
    D_80182130,
    D_801843E0,
    D_802E2AE4_733CE4
};

AnimationHeader D_802E2B64_733D64 = {
    1.17,
    120,
    D_80182CB0,
    D_80184580,
    NULL
};

AnimationHeader D_802E2B78_733D78 = {
    1.0,
    75,
    D_8017F000,
    D_80183CB0,
    NULL
};

AnimationHeader D_802E2B8C_733D8C = {
    0.7,
    145,
    D_801815D0,
    D_801841C0,
    D_802E2AE8_733CE8
};

InteractionHandler D_802E2BA0_733DA0[] = {
    { POKEMON_CMD_9, func_802DC590_72D790, 0, NULL },
    { POKEMON_CMD_13, func_802DC4F0_72D6F0, 0, NULL },
    { POKEMON_CMD_29, func_802DC99C_72DB9C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2BE0_733DE0[] = {
    { POKEMON_CMD_29, func_802DC99C_72DB9C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2C00_733E00[] = {
    { POKEMON_CMD_9, func_802DC758_72D958, 0, NULL },
    { POKEMON_CMD_13, func_802DC7A8_72D9A8, 0, NULL },
    { POKEMON_CMD_29, func_802DC99C_72DB9C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E2C40_733E40[] = {
    { 1, func_802DC170_72D370 },
    { 1, func_802DC1F8_72D3F8 },
    { 1, func_802DC480_72D680 },
    { 1, func_802DC3A0_72D5A0 },
    { 1, func_802DC410_72D610 },
    { 0, NULL },
};

RandomState D_802E2C70_733E70[] = {
    { 1, func_802DC170_72D370 },
    { 1, func_802DC1F8_72D3F8 },
    { 0, NULL },
};

RandomState D_802E2C88_733E88[] = {
    { 1, func_802DC3A0_72D5A0 },
    { 1, func_802DC410_72D610 },
    { 0, NULL },
};

f32 D_802E2CA0_733EA0[] = { 0 };

InteractionHandler D_802E2CA4_733EA4[] = {
    { POKEMON_CMD_9, func_802DCE40_72E040, 0, NULL },
    { POKEMON_CMD_13, func_802DCF44_72E144, 0, NULL },
    { POKEMON_CMD_10, func_802DCF44_72E144, 0, NULL },
    { POKEMON_CMD_14, func_802DCFAC_72E1AC, 0, NULL },
    { POKEMON_CMD_15, func_802DCFAC_72E1AC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E2D04_733F04[] = {
    { 100, func_802DCBD0_72DDD0 },
    { 100, func_802DCC40_72DE40 },
    { 100, func_802DCD40_72DF40 },
    { 0, NULL },
};

InteractionHandler D_802E2D24_733F24[] = {
    { POKEMON_CMD_9, func_802DCE40_72E040, 0, NULL },
    { POKEMON_CMD_13, func_802DCF44_72E144, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2D54_733F54[] = {
    { POKEMON_CMD_9, func_802DCE40_72E040, 0, NULL },
    { POKEMON_CMD_13, func_802DCF44_72E144, 0, NULL },
    { POKEMON_CMD_10, func_802DCF44_72E144, 0, NULL },
    { POKEMON_CMD_14, func_802DCFAC_72E1AC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2DA4_733FA4[] = {
    { POKEMON_CMD_9, func_802DCE40_72E040, 0, NULL },
    { POKEMON_CMD_13, func_802DCF44_72E144, 0, NULL },
    { POKEMON_CMD_10, func_802DCF44_72E144, 0, NULL },
    { POKEMON_CMD_14, func_802DCFAC_72E1AC, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E2DF4_733FF4 = {
    &D_802E2AEC_733CEC,
    func_802DC108_72D308,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E2E08_734008 = {
    D_8033E520,
    D_8033A2F0,
    renderPokemonModelTypeJFogged,
    &D_802E2DF4_733FF4,
    { 1.8, 1.8, 1.8 },
    { 0, 166, -2.6 },
    53,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

PokemonDef D_802E2E3C_73403C = {
    PokemonID_CHARMELEON,
    func_802DD214_72E414,
    pokemonChangeBlockOnGround,
    pokemonRemoveOne
};

void func_802DC060_72D260(GObj* obj) {
    UNUSED s32 pad[4];
    s32 blockIndex;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 4 || blockIndex == 4 && blockPart >= 0.35) {
            break;
        }
        ohWait(1);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

void func_802DC108_72D308(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802DCB44_72DD44);
    }
    pokemon->forbiddenGround = D_802E2CA0_733EA0;
    pokemon->miscVars[3].field0 = 0.0f;
    Pokemon_SetStateRandom(obj, D_802E2C40_733E40);
}

void func_802DC170_72D370(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[5].field0 = 0.04f;
    Pokemon_ResetPathPos(obj);
    Pokemon_SetAnimation(obj, &D_802E2B28_733D28);
    Pokemon_StartPathProc(obj, func_802DC280_72D480);
    pokemon->transitionGraph = D_802E2C00_733E00;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2C40_733E40);
}

void func_802DC1F8_72D3F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[5].field0 = 0.08f;
    Pokemon_ResetPathPos(obj);
    Pokemon_SetAnimation(obj, &D_802E2B3C_733D3C);
    Pokemon_StartPathProc(obj, func_802DC280_72D480);
    pokemon->transitionGraph = D_802E2C00_733E00;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2C40_733E40);
}

void func_802DC280_72D480(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->miscVars[3].field0 < 0.7) {
        pokemon->miscVars[4].field0 = pokemon->miscVars[3].field0 + 0.3 + randFloat() * 0.3;
        if (pokemon->miscVars[4].field0 > 1.0f) {
            pokemon->miscVars[4].field0 = 1.0f;
        }
    } else {
        pokemon->miscVars[4].field0 = 1.0f;
    }

    func_802D6F68_728168(obj, &pokemon->miscVars[3].field0, pokemon->miscVars[4].field0, pokemon->miscVars[5].field0, 3);

    if (pokemon->miscVars[4].field0 == 1.0f) {
        pokemon->miscVars[3].field0 = 0.0f;
    }

    if (pokemon->miscVars[3].field0 > 1.0f) {
        pokemon->miscVars[3].field0 -= 1.0f;
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DC3A0_72D5A0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E2B14_733D14);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2C00_733E00;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2C70_733E70);
}

void func_802DC410_72D610(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E2B00_733D00);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2C00_733E00;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2C70_733E70);
}

void func_802DC480_72D680(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2AEC_733CEC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2C00_733E00;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E2C70_733E70);
}

// clang-format off
void func_802DC4F0_72D6F0(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_SetAnimation(obj, &D_802E2B50_733D50);
    Pokemon_StartPathProc(obj, func_802DC6B4_72D8B4);
    pokemon->transitionGraph = D_802E2BA0_733DA0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (obj && obj && obj) {
    } // TODO fake match

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E2BE0_733DE0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802DC7F8_72D9F8);
}

// clang-format off
void func_802DC590_72D790(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    Pokemon_SetAnimation(obj, &D_802E2B50_733D50);
    Pokemon_StartPathProc(obj, func_802DC6B4_72D8B4);
    pokemon->transitionGraph = D_802E2BA0_733DA0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E2BE0_733DE0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802E2B64_733D64);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E2B78_733D78);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E2B8C_733D8C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DC7F8_72D9F8);
}

void func_802DC6B4_72D8B4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 300.0f;
    pokemon->jumpVel = 150.0f;
    // TODO check it's an item
    pokemon->facingYaw = atan2f(GET_ITEM(pokemon->interactionTarget)->collisionVelocity.x, GET_ITEM(pokemon->interactionTarget)->collisionVelocity.z);
    Pokemon_FallDownOnGround(obj, -9.8f, true);

    if (pokemon->currGround.surfaceType == SURFACE_TYPE_FF4C19) {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_28, obj);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DC758_72D958(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);

    pokemon->pos1.x = transform->pos.v.x;
    pokemon->pos1.y = transform->pos.v.y;
    pokemon->pos1.z = transform->pos.v.z;
    pokemon->miscVars[6].field1 = 0;
    Pokemon_SetState(obj, func_802DC590_72D790);
}

void func_802DC7A8_72D9A8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(model);

    pokemon->pos1.x = transform->pos.v.x;
    pokemon->pos1.y = transform->pos.v.y;
    pokemon->pos1.z = transform->pos.v.z;
    pokemon->miscVars[6].field1 = 0;
    Pokemon_SetState(obj, func_802DC4F0_72D6F0);
}

void func_802DC7F8_72D9F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2B3C_733D3C);
    Pokemon_StartPathProc(obj, func_802DC924_72DB24);
    pokemon->miscVars[0].field1 = 0;
    Pokemon_SetState(obj, func_802DC850_72DA50);
}

void func_802DC850_72DA50(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E2BA0_733DA0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->currGround.surfaceType == SURFACE_TYPE_FF4C19) {
        pokemon->miscVars[0].field1++;
        if (pokemon->miscVars[0].field1 > 10) {
            cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_28, obj);
        }
    } else {
        pokemon->miscVars[0].field1 = 0;
    }

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802DC850_72DA50);
    }
    Pokemon_SetStateRandom(obj, D_802E2C88_733E88);
}

void func_802DC924_72DB24(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (!pokemon->miscVars[6].field1) {
        Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
        pokemon->miscVars[6].field1 = true;
    }
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DC99C_72DB9C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, func_802D6CC0_727EC0, 1, 1);
    obj->flags |= GOBJ_FLAG_2;
    Pokemon_StartPathProc(obj, func_802DCA28_72DC28);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    func_802D6A5C_727C5C(obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DCA28_72DC28(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    DObj* model = obj->data.dobj;
    Mtx3Float* position = &GET_TRANSFORM(model)->pos;
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot;
    Mtx3Float* targetPos = &GET_TRANSFORM(pokemon->interactionTarget->data.dobj)->pos;    
    f32 dx, dz;
    s32 i;

    dx = (targetPos->v.x - position->v.x) / 100.0f;
    dz = (targetPos->v.z - position->v.z) / 100.0f;

    for (i = 0; i < 100; i++) {
        position->v.x += dx;
        position->v.z += dz;
        position->v.y -= 6.0f;
        rotation->f[2] += 0.017453292f;
        ohWait(1);
    }

    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DCB44_72DD44(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartAuxProc(obj, func_802DC060_72D260);
    Pokemon_SetAnimation(obj, &D_802E2B8C_733D8C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DCBD0_72DDD0);
}

void func_802DCBD0_72DDD0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2AEC_733CEC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E2CA4_733EA4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E2D04_733F04);
}

void func_802DCC40_72DE40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2B28_733D28);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802DCCE4_72DEE4);
    pokemon->transitionGraph = D_802E2CA4_733EA4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802DCBD0_72DDD0);
    }

    Pokemon_SetStateRandom(obj, D_802E2D04_733F04);
}

void func_802DCCE4_72DEE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DCD40_72DF40(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2B3C_733D3C);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802DCDE4_72DFE4);
    pokemon->transitionGraph = D_802E2CA4_733EA4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802DCBD0_72DDD0);
    }

    Pokemon_SetStateRandom(obj, D_802E2D04_733F04);
}

void func_802DCDE4_72DFE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DCE40_72E040(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler saved[3] = D_802E2D24_733F24;

    Pokemon_SetAnimation(obj, &D_802E2B64_733D64);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E2B78_733D78);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E2B8C_733D8C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DCBD0_72DDD0);
}

void func_802DCF44_72E144(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2B50_733D50);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802DCBD0_72DDD0);
}

void func_802DCFAC_72E1AC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_802DD034_72E234);
    pokemon->transitionGraph = D_802E2D54_733F54;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802DCBD0_72DDD0);
    }

    Pokemon_SetState(obj, func_802DD0E8_72E2E8);
}

void func_802DD034_72E234(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2B3C_733D3C);
    pokemon->hSpeed = randFloat() * 80.0f * 0.6 + 80.0;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802DD0E8_72E2E8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler saved[5] = D_802E2DA4_733FA4;

    Pokemon_ForceAnimation(obj, &D_802E2B00_733D00);
    Pokemon_StartPathProc(obj, func_802DD1C0_72E3C0);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802DD0E8_72E2E8);
    }

    Pokemon_SetState(obj, func_802DCBD0_72DDD0);
}

void func_802DD1C0_72E3C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

GObj* func_802DD214_72E414(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2E08_734008);
}

void func_802DD24C_72E44C(GObj* obj) {
    PokemonDef def = D_802E2E3C_73403C;
    GObj* var;
    DObj* newModel;    

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &def);
    GET_POKEMON(var)->behavior = 1;
    GET_POKEMON(var)->path = GET_POKEMON(obj)->path;
    newModel = var->data.dobj;
    GET_TRANSFORM(newModel)->rot.f[2] = GET_TRANSFORM(obj->data.dobj)->rot.f[2];
}
