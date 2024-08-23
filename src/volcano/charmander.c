#include "volcano/volcano.h"

extern AnimCmd* D_80175AE0[];
extern AnimCmd* D_80176030[];
extern AnimCmd* D_80176500[];
extern AnimCmd* D_80177600[];
extern AnimCmd* D_80177BC0[];
extern AnimCmd* D_80178070[];
extern AnimCmd* D_801786F0[];
extern AnimCmd* D_80179210[];
extern AnimCmd* D_80179780[];
extern AnimCmd* D_80179ED0[];

extern AnimCmd* D_8017C080[];

extern AnimCmd** D_8017AB20[];
extern AnimCmd** D_8017ABF0[];
extern AnimCmd** D_8017AC80[];
extern AnimCmd** D_8017ADF0[];
extern AnimCmd** D_8017AF90[];
extern AnimCmd** D_8017B0C0[];
extern AnimCmd** D_8017B280[];
extern AnimCmd** D_8017B400[];
extern AnimCmd** D_8017B500[];
extern AnimCmd** D_8017B630[];

extern GObj* D_802E10A0_7322A0;
extern void func_802DED6C_72FF6C(GObj*);
extern void func_802DD24C_72E44C(GObj*);

void func_802D93DC_72A5DC(GObj*);
void func_802D8BB8_729DB8(GObj*);
void func_802D9C84_72AE84(GObj*);
void func_802D99A0_72ABA0(GObj*);
void func_802D9074_72A274(GObj*);
void func_802D924C_72A44C(GObj*);
void func_802D930C_72A50C(GObj*);
void func_802D9BF4_72ADF4(GObj*);
void func_802D9C30_72AE30(GObj*);
void func_802D8D14_729F14(GObj*);
void func_802D8E14_72A014(GObj*);
void func_802D8F14_72A114(GObj*);
void func_802D96F8_72A8F8(GObj*);
void func_802D9614_72A814(GObj*);
void func_802D8CA4_729EA4(GObj*);
void func_802D9638_72A838(GObj*);
void func_802D8F94_72A194(GObj*);
void func_802D9004_72A204(GObj*);
void func_802D9900_72AB00(GObj*);
void func_802D9950_72AB50(GObj*);
void func_802D8DB8_729FB8(GObj*);
void func_802D8EB8_72A0B8(GObj*);
void func_802D9B8C_72AD8C(GObj*);
void func_802D9380_72A580(GObj*);
void func_802D9464_72A664(GObj*);
void func_802D94E8_72A6E8(GObj*);
void func_802D97B8_72A9B8(GObj*);
void func_802D95AC_72A7AC(GObj*);
void func_802D96AC_72A8AC(GObj*);
void func_802D976C_72A96C(GObj*);
void func_802D9A80_72AC80(GObj*);
void func_802D9B44_72AD44(GObj*);

s32 D_802E1940_732B40[] = { SOUND_ID_281 };
s32 D_802E1944_732B44[] = { SOUND_ID_282 };
s32 D_802E1948_732B48[] = { SOUND_ID_279 };
s32 D_802E194C_732B4C[] = { SOUND_ID_280, SOUND_ID_373 };
s32 D_802E1954_732B54[] = { SOUND_ID_278 };

AnimationHeader D_802E1958_732B58 = {
    0.5,
    60,
    D_80177600,
    D_8017ADF0,
    NULL
};

AnimationHeader D_802E196C_732B6C = {
    0.7,
    80,
    D_80178070,
    D_8017B0C0,
    D_802E1940_732B40
};

AnimationHeader D_802E1980_732B80 = {
    0.4,
    32,
    D_80175AE0,
    D_8017AB20,
    NULL
};

AnimationHeader D_802E1994_732B94 = {
    1,
    32,
    D_80176030,
    D_8017ABF0,
    NULL
};

AnimationHeader D_802E19A8_732BA8 = {
    0.5,
    30,
    D_80179210,
    D_8017B400,
    D_802E1944_732B44
};

AnimationHeader D_802E19BC_732BBC = {
    0.4,
    50,
    D_80179780,
    D_8017B500,
    D_802E1948_732B48
};

AnimationHeader D_802E19D0_732BD0 = {
    0.5,
    48,
    D_80177BC0,
    D_8017AF90,
    NULL
};

AnimationHeader D_802E19E4_732BE4 = {
    0.4,
    60,
    D_801786F0,
    D_8017B280,
    NULL
};

AnimationHeader D_802E19F8_732BF8 = {
    1,
    100,
    D_80179ED0,
    D_8017B630,
    D_802E194C_732B4C
};

AnimationHeader D_802E1A0C_732C0C = {
    0.5,
    55,
    D_80176500,
    D_8017AC80,
    D_802E1954_732B54
};

GObj* D_802E1A20_732C20 = NULL;
GObj* D_802E1A24_732C24 = NULL;
GObj* D_802E1A28_732C28 = NULL;
GObj* D_802E1A2C_732C2C = NULL;
GObj* D_802E1A30_732C30 = NULL;

InteractionHandler D_802E1A34_732C34[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_10, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_14, func_802D93DC_72A5DC, 0, NULL },
    { POKEMON_CMD_15, func_802D9614_72A814, 0, NULL },
    { POKEMON_CMD_5, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_6, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_7, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_16, func_802D9638_72A838, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_36, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_42, NULL, 0, func_802D9004_72A204 },
    { POKEMON_CMD_43, func_802D8F94_72A194, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1B14_732D14[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_10, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_14, func_802D93DC_72A5DC, 0, NULL },
    { POKEMON_CMD_5, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_6, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_7, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1BA4_732DA4[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_10, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_14, func_802D93DC_72A5DC, 0, NULL },
    { POKEMON_CMD_5, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_6, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_7, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_36, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1C44_732E44[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1C84_732E84[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1CC4_732EC4[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_15, func_802D9614_72A814, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1D14_732F14[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_10, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_14, func_802D93DC_72A5DC, 0, NULL },
    { POKEMON_CMD_5, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_6, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_7, func_802D96F8_72A8F8, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1DA4_732FA4[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_10, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1DF4_732FF4[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_10, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_14, func_802D93DC_72A5DC, 0, NULL },
    { POKEMON_CMD_15, func_802D9614_72A814, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E1E64_733064[] = {
    { 30, func_802D8CA4_729EA4 },
    { 30, func_802D8D14_729F14 },
    { 30, func_802D8E14_72A014 },
    { 10, func_802D8F14_72A114 },
    { 0, NULL },
};

f32 D_802E1E8C_73308C[] = { 0 };

InteractionHandler D_802E1E90_733090[] = {
    { POKEMON_CMD_37, func_802D9BF4_72ADF4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1EB0_7330B0[] = {
    { POKEMON_CMD_37, func_802D9C30_72AE30, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1ED0_7330D0[] = {
    { POKEMON_CMD_37, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1EF0_7330F0[] = {
    { POKEMON_CMD_9, func_802D9074_72A274, 0, NULL },
    { POKEMON_CMD_13, func_802D924C_72A44C, 0, NULL },
    { POKEMON_CMD_10, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_36, func_802D930C_72A50C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1F40_733140[] = {
    { POKEMON_CMD_39, func_802D99A0_72ABA0, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1F60_733160[] = {
    { POKEMON_CMD_40, func_802D99A0_72ABA0, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1F80_733180[] = {
    { POKEMON_CMD_41, func_802D9C84_72AE84, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup D_802E1FA0_7331A0 = {
    &D_802E1958_732B58,
    func_802D8BB8_729DB8,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E1FB4_7331B4 = {
    charmander_model,
    charmander_materials,    
    renderPokemonModelTypeJFogged,
    &D_802E1FA0_7331A0,
    { 2, 2, 2 },
    { 0, 112, -15 },
    27,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_802D8AA0_729CA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 blockIndex;
    f32 blockPart;
    s32 blockIndex2;
    f32 blockPart2;

    if (pokemon->behavior == 5) {
        while (true) {
            getLevelProgress(&blockIndex, &blockPart);
            if (blockIndex > 4 || blockIndex == 4 && blockPart >= 0.35) {
                break;
            }
            ohWait(1);
        }
    } else {
        while (true) {
            getLevelProgress(&blockIndex2, &blockPart2);
            if (blockIndex2 > 5 || blockIndex2 == 5 && blockPart2 >= 0.15) {
                break;
            }
            ohWait(1);
        }
    }

    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

void func_802D8BB8_729DB8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field1 = 0;
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartAuxProc(obj, func_802D8AA0_729CA0);
    switch (pokemon->behavior) {
        case 1:
            D_802E1A20_732C20 = obj;
            break;
        case 2:
            D_802E1A24_732C24 = obj;
            break;
        case 3:
            D_802E1A28_732C28 = obj;
            Pokemon_SetState(obj, func_802D9900_72AB00);
            break;
        case 4:
            D_802E1A2C_732C2C = obj;
            Pokemon_SetState(obj, func_802D9950_72AB50);
            break;
        case 5:
            D_802E1A30_732C30 = obj;
            break;
    }

    Pokemon_SetState(obj, func_802D8CA4_729EA4);
}

void func_802D8CA4_729EA4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1958_732B58);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1A34_732C34;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E1E64_733064);
}

void func_802D8D14_729F14(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1980_732B80);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802D8DB8_729FB8);
    pokemon->transitionGraph = D_802E1A34_732C34;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802D8CA4_729EA4);
    }
    Pokemon_SetStateRandom(obj, D_802E1E64_733064);
}

void func_802D8DB8_729FB8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D8E14_72A014(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1994_732B94);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802D8EB8_72A0B8);
    pokemon->transitionGraph = D_802E1A34_732C34;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802D8CA4_729EA4);
    }
    Pokemon_SetStateRandom(obj, D_802E1E64_733064);
}

void func_802D8EB8_72A0B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D8F14_72A114(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E196C_732B6C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1DF4_732FF4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_42, obj);
    Pokemon_SetStateRandom(obj, D_802E1E64_733064);
}

void func_802D8F94_72A194(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E196C_732B6C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1DF4_732FF4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E1E64_733064);
}

void func_802D9004_72A204(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->interactionTarget != NULL &&
        pokemon->interactionTarget != obj &&
        Pokemon_GetDistance(obj, pokemon->interactionTarget) < 500.0) {
        cmdSendCommand(obj, POKEMON_CMD_43, obj);
    }
    Pokemon_StopAuxProc(obj);
}

void func_802D9074_72A274(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler saved1[2] = D_802E1E90_733090;
    InteractionHandler saved2[2] = D_802E1EB0_7330B0;

    cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_36, obj);
    Pokemon_SetAnimation(obj, &D_802E19BC_732BBC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved1;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget == D_802E10A0_7322A0) {
        Pokemon_SetState(obj, func_802D9B8C_72AD8C);
    }

    Pokemon_SetAnimation(obj, &D_802E19D0_732BD0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved2;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E19E4_732BE4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E1C44_732E44;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E1994_732B94);
    Pokemon_StartPathProc(obj, func_802D9380_72A580);
    pokemon->transitionGraph = D_802E1DA4_732FA4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802D8CA4_729EA4);
}

void func_802D9244_72A444(void) {
}

void func_802D924C_72A44C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler saved1[2] = D_802E1ED0_7330D0;

    Pokemon_SetAnimation(obj, &D_802E19A8_732BA8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved1;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->apple = NULL;
    Pokemon_SetState(obj, func_802D8CA4_729EA4);
}

void func_802D930C_72A50C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1994_732B94);
    Pokemon_StartPathProc(obj, func_802D9380_72A580);
    pokemon->transitionGraph = D_802E1DA4_732FA4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802D8CA4_729EA4);
}

void func_802D9380_72A580(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 80.0f;
    Pokemon_RunAwayFromTarget(obj, 600.0f, 0.1f, MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D93DC_72A5DC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_802D9464_72A664);
    pokemon->transitionGraph = D_802E1B14_732D14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802D8CA4_729EA4);
    }

    Pokemon_SetState(obj, func_802D94E8_72A6E8);
}

void func_802D9464_72A664(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1994_732B94);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 40.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D94E8_72A6E8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->miscVars[0].field1 == 0 && (pokemon->behavior == 1 || pokemon->behavior == 2)) {
        Pokemon_SetState(obj, func_802D97B8_72A9B8);
    }

    Pokemon_SetAnimation(obj, &D_802E19F8_732BF8);
    Pokemon_StartPathProc(obj, func_802D95AC_72A7AC);
    pokemon->transitionGraph = D_802E1BA4_732DA4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802D94E8_72A6E8);
    }
    Pokemon_SetState(obj, func_802D8CA4_729EA4);
}

void func_802D95AC_72A7AC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

void func_802D9614_72A814(GObj* arg0) {
    Pokemon_SetState(arg0, func_802D93DC_72A5DC);
}

void func_802D9638_72A838(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, func_802D96AC_72A8AC);
    Pokemon_SetAnimation(obj, &D_802E1A0C_732C0C);
    pokemon->transitionGraph = D_802E1D14_732F14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E1E64_733064);
}

void func_802D96AC_72A8AC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D96F8_72A8F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1980_732B80);
    Pokemon_StartPathProc(obj, func_802D976C_72A96C);
    pokemon->transitionGraph = D_802E1C84_732E84;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802D8CA4_729EA4);
}

void func_802D976C_72A96C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_802D97B8_72A9B8(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    InteractionHandler saved1[5] = D_802E1EF0_7330F0;

    Pokemon_SetAnimation(obj, &D_802E1A0C_732C0C);
    if (pokemon->behavior == 1) {
        pokemon->interactionTarget = D_802E1A28_732C28;
    } else {
        pokemon->interactionTarget = D_802E1A2C_732C2C;
    }
    Pokemon_StartPathProc(obj, func_802D95AC_72A7AC);
    pokemon->transitionGraph = saved1;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->behavior == 1) {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_39, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, POKEMON_CMD_40, obj);
    }
    pokemon->miscVars[0].field1 = 1;
    Pokemon_SetAnimation(obj, &D_802E1A0C_732C0C);
    pokemon->pokemonLoopTarget = 2;
    pokemon->transitionGraph = D_802E1BA4_732DA4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D8CA4_729EA4);
}

void func_802D9900_72AB00(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->transitionGraph = D_802E1F40_733140;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

void func_802D9950_72AB50(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
    pokemon->transitionGraph = D_802E1F60_733160;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

void func_802D99A0_72ABA0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->flags &= ~POKEMON_FLAG_800;
    pokemon->flags &= ~POKEMON_FLAG_200;
    pokemon->forbiddenGround = D_802E1E8C_73308C;
    pokemon->tangible = true;
    obj->flags = 0;
    
    Pokemon_SetAnimation(obj, &D_802E1994_732B94);
    pokemon->hSpeed = 80.0f;
    Pokemon_StartPathProc(obj, func_802D9A80_72AC80);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    pokemon->forbiddenGround = NULL;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->flags |= POKEMON_FLAG_200;

    Pokemon_StartPathProc(obj, func_802D9B44_72AD44);
    pokemon->transitionGraph = D_802E1A34_732C34;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802D8CA4_729EA4);
}

void func_802D9A80_72AC80(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    Mtx3Float* targetPos = &(GET_TRANSFORM(pokemon->interactionTarget->data.dobj)->pos);

    Pokemon_SetTargetPos(obj, targetPos->v.x, targetPos->v.z);
    while (!Pokemon_StepToTargetPos(obj, 0.1f, MOVEMENT_FLAG_ON_GROUND)) {
        if (pokemon->currGround.surfaceType != SURFACE_TYPE_7F6633) {
            break;
        }
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D9B44_72AD44(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D9B8C_72AD8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_802DED6C_72FF6C(obj);
    Pokemon_SetAnimation(obj, &D_802E19D0_732BD0);    
    pokemon->transitionGraph = D_802E1F80_733180;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

void func_802D9BF4_72ADF4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
 
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D9C30_72AE30);
}

void func_802D9C30_72AE30(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    
    Pokemon_ForceAnimation(obj, &D_802E19D0_732BD0);  
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D9B8C_72AD8C);
}

void func_802D9C84_72AE84(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    
    func_802DD24C_72E44C(obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802D9CB8_72AEB8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E1FB4_7331B4);
}
