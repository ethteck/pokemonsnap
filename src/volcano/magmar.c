#include "volcano/volcano.h"

extern Texture** D_8031F238[];
extern UnkEC64Arg3 D_80323C30[];

extern AnimCmd* D_80133BF0[];
extern AnimCmd* D_80132FD0[];
extern AnimCmd* D_80136140[];
extern AnimCmd* D_80137800[];
extern AnimCmd* D_80138890[];
extern AnimCmd* D_80138FD0[];
extern AnimCmd* D_80139AD0[];
extern AnimCmd* D_8013AB20[];
extern AnimCmd* D_8013C2B0[];
extern AnimCmd* D_8013D460[];

extern AnimCmd** D_8013E640[];
extern AnimCmd** D_8013E770[];
extern AnimCmd** D_8013EE20[];
extern AnimCmd** D_8013ECF0[];
extern AnimCmd** D_8013F190[];
extern AnimCmd** D_8013F480[];
extern AnimCmd** D_8013F6E0[];
extern AnimCmd** D_8013FA30[];

extern GObj* D_802E1A30_732C30;

void volcano_magmar_StateInitial(GObj*);
void func_802D7E90_729090(GObj*);
void func_802D7510_728710(GObj*);
void func_802D7584_728784(GObj*);
void func_802D75F4_7287F4(GObj*);
void func_802D76F4_7288F4(GObj*);
void func_802D77BC_7289BC(GObj*);
void func_802D7830_728A30(GObj*);
void func_802D7CB4_728EB4(GObj*);
void func_802D7A94_728C94(GObj*);
void func_802D7B54_728D54(GObj*);
void func_802D7A10_728C10(GObj*);
void func_802D78A4_728AA4(GObj*);
void func_802D7458_728658(GObj*);
void func_802D7698_728898(GObj*);
void func_802D7A34_728C34(GObj*);
void func_802D798C_728B8C(GObj*);
void func_802D7B08_728D08(GObj*);
void func_802D7D84_728F84(GObj*);
void func_802D7C30_728E30(GObj*);

s32 D_802E0FC0_7321C0[] = { 0x11b };
s32 D_802E0FC4_7321C4[] = { 0x11c };
s32 D_802E0FC8_7321C8[] = { 0x11d };
s32 D_802E0FCC_7321CC[] = { 0x11e };
s32 D_802E0FD0_7321D0[] = { 0x11f, 0x8d };

AnimationHeader D_802E0FD8_7321D8 = {
    0.45,
    50,
    D_80137800,
    D_8013EE20,
    NULL
};

AnimationHeader D_802E0FEC_7321EC = {
    0.4,
    60,
    D_80138FD0,
    D_8013F190,
    NULL
};

AnimationHeader D_802E1000_732200 = {
    0.6,
    60,
    D_80132FD0,
    D_8013E640,
    NULL
};

AnimationHeader D_802E1014_732214 = {
    1,
    30,
    D_80136140,
    D_8013ECF0,
    NULL
};

AnimationHeader D_802E1028_732228 = {
    0.7,
    90,
    D_8013AB20,
    D_8013F6E0,
    D_802E0FC0_7321C0
};

AnimationHeader D_802E103C_73223C = {
    0.6,
    60,
    D_8013D460,
    NULL,
    D_802E0FC4_7321C4
};

AnimationHeader D_802E1050_732250 = {
    0.5,
    20,
    D_80138890,
    NULL,
    NULL
};

AnimationHeader D_802E1064_732264 = {
    0.35,
    52,
    D_80139AD0,
    D_8013F480,
    D_802E0FC8_7321C8
};

AnimationHeader D_802E1078_732278 = {
    0.35,
    60,
    D_8013C2B0,
    D_8013FA30,
    D_802E0FCC_7321CC
};

AnimationHeader D_802E108C_73228C = {
    0.5,
    145,
    D_80133BF0,
    D_8013E770,
    D_802E0FD0_7321D0
};

GObj* D_802E10A0_7322A0 = NULL;

InteractionHandler D_802E10A4_7322A4[] = {
    { POKEMON_CMD_30, func_802D7510_728710, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E10C4_7322C4[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_15, func_802D7A10_728C10, NULL, NULL },
    { POKEMON_CMD_5, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_6, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_7, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1154_732354[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_15, func_802D7A10_728C10, NULL, NULL },
    { POKEMON_CMD_5, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_6, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_7, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_26, func_802D7B54_728D54, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E11F4_7323F4[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_21, func_802D7510_728710, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_5, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_6, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_7, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_26, func_802D7B54_728D54, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1294_732494[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_21, func_802D7510_728710, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_5, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_6, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_7, func_802D7A94_728C94, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1324_732524[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1374_732574[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_15, func_802D7A10_728C10, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E13C4_7325C4[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E13F4_7325F4[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

InteractionHandler D_802E1434_732634[] = {
    { POKEMON_CMD_9, func_802D76F4_7288F4, NULL, NULL },
    { POKEMON_CMD_13, func_802D77BC_7289BC, NULL, NULL },
    { POKEMON_CMD_10, func_802D7830_728A30, NULL, NULL },
    { POKEMON_CMD_37, func_802D7CB4_728EB4, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

RandomState D_802E1484_732684[] = {
    { 100, func_802D7510_728710 },
    { 100, func_802D7584_728784 },
    { 100, func_802D75F4_7287F4 },
    { 0, NULL },
};

InteractionHandler D_802E14A4_7326A4[] = {
    { POKEMON_CMD_41, func_802D7E90_729090, NULL, NULL },
    { POKEMON_CMD_58, NULL, NULL, NULL },
};

PokemonAnimationSetup volcano_magmar_AnimSetup = {
    &D_802E0FD8_7321D8,
    volcano_magmar_StateInitial,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData volcano_magmar_InitData = {
    D_80323C30,
    D_8031F238,
    renderPokemonModelTypeJFogged,
    &volcano_magmar_AnimSetup,
    { 1.3, 1.3, 1.3 },
    { 0, 110, 0 },
    68,
    0x25,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_802D7290_728490(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 blockIndex;
    f32 blockPart;
    s32 blockIndex2;
    f32 blockPart2;

    if (pokemon->behavior == 1) {
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
            if (blockIndex2 > 5 || blockIndex2 == 5 && blockPart2 >= 0.35) {
                break;
            }
            ohWait(1);
        }
    }

    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

void volcano_magmar_StateInitial(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field1 = 0;
    pokemon->flags |= POKEMON_FLAG_200;
    Pokemon_StartAuxProc(obj, func_802D7290_728490);
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802D7458_728658);
    }
    Pokemon_SetAnimation(obj, &D_802E0FD8_7321D8);
    pokemon->transitionGraph = D_802E10A4_7322A4;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802D7458_728658(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 blockIndex;
    f32 blockPart;

    D_802E10A0_7322A0 = obj;
    Pokemon_SetAnimation(obj, &D_802E0FD8_7321D8);
    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 3 || blockIndex == 3 && blockPart >= 0.5f) {
            break;
        }
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802D7510_728710);
}

void func_802D7510_728710(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->unk_10E = 0;
    Pokemon_SetAnimation(obj, &D_802E0FD8_7321D8);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E10C4_7322C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E1484_732684);
}

void func_802D7584_728784(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802E0FEC_7321EC);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E10C4_7322C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_802E1484_732684);
}

void func_802D75F4_7287F4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1000_732200);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802D7698_728898);
    pokemon->transitionGraph = D_802E1154_732354;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802D7510_728710);
    }
    Pokemon_SetStateRandom(obj, D_802E1484_732684);
}

void func_802D7698_728898(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D76F4_7288F4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->unk_10E = 0;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802E103C_73223C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E1050_732250);
    pokemon->transitionGraph = NULL;
    pokemon->flags &= ~POKEMON_FLAG_800;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E1064_732264);
    pokemon->transitionGraph = D_802E13F4_7325F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D7A34_728C34);
    if (obj) { // required to match
    }
}

void func_802D77BC_7289BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->unk_10E = 0;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &D_802E1028_732228);
    pokemon->transitionGraph = D_802E13F4_7325F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E1484_732684);
}

void func_802D7830_728A30(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->unk_10E = 0;
    Pokemon_SetAnimation(obj, &D_802E1028_732228);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E13F4_7325F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802E1484_732684);
}

void func_802D78A4_728AA4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field1 = 1;
    Pokemon_StartPathProc(obj, func_802D798C_728B8C);
    pokemon->transitionGraph = D_802E11F4_7323F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802D7510_728710);
    }

    Pokemon_SetAnimation(obj, &D_802E1078_732278);
    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E1294_732494;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_EatApple(obj);
    pokemon->transitionGraph = D_802E1324_732524;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D7A34_728C34);
}

void func_802D798C_728B8C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1014_732214);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D7A10_728C10(GObj* arg0) {
    Pokemon_SetState(arg0, func_802D78A4_728AA4);
}

void func_802D7A34_728C34(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E1374_732574;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, func_802D7510_728710);
}

void func_802D7A94_728C94(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E1000_732200);
    Pokemon_StartPathProc(obj, func_802D7B08_728D08);
    pokemon->transitionGraph = D_802E13C4_7325C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802D7510_728710);
}

void func_802D7B08_728D08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D7B54_728D54(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802D7D84_728F84);
    }
    pokemon->unk_10E = 11;

    Pokemon_SetAnimation(obj, &D_802E108C_73228C);
    Pokemon_StartPathProc(obj, func_802D7C30_728E30);
    pokemon->counter = 90, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E1434_732634;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommand(pokemon->interactionTarget, POKEMON_CMD_37, obj);
    pokemon->transitionGraph = D_802E1434_732634;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->unk_10E = 0;
    Pokemon_SetState(obj, func_802D7510_728710);
}

void func_802D7C30_728E30(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    GObj* target = pokemon->interactionTarget;

    do {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    } while (pokemon->interactionTarget == target);

    pokemon->pathProc = NULL;
    if (1) { } // required to match
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802D7CB4_728EB4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->unk_10E = 11;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802E103C_73223C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->unk_10E = 0;
    Pokemon_SetAnimation(obj, &D_802E1050_732250);
    pokemon->transitionGraph = NULL;
    pokemon->flags &= ~POKEMON_FLAG_800;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E1064_732264);
    pokemon->transitionGraph = D_802E13F4_7325F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D7A34_728C34);
}

void func_802D7D84_728F84(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->miscVars[0].field1 == 0) {
        Pokemon_SetState(obj, func_802D7510_728710);
    }

    Pokemon_SetAnimation(obj, &D_802E108C_73228C);
    Pokemon_StartPathProc(obj, func_802D7C30_728E30);
    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E1434_732634;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommand(D_802E1A30_732C30, POKEMON_CMD_37, obj);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E14A4_7326A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E0FD8_7321D8);
    pokemon->transitionGraph = D_802E14A4_7326A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802D7510_728710);
}

void func_802D7E90_729090(GObj* obj) { \
    UNUSED s32 pad[3];  \
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 80, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &D_802E103C_73223C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &D_802E1050_732250);
    Pokemon_SetState(obj, NULL);
}

GObj* volcano_magmar_Init(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &volcano_magmar_InitData);
}
