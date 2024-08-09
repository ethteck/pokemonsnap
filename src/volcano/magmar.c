#include "volcano/volcano.h"

extern UnkEC64Arg3 volcano_magmar_assetModel[];
extern Texture** volcano_magmar_assetMaterials[];

extern AnimCmd* volcano_magmar_assetAnimModel1[];
extern AnimCmd* volcano_magmar_assetAnimModel2[];
extern AnimCmd* volcano_magmar_assetAnimModel3[];
extern AnimCmd* volcano_magmar_assetAnimModel4[];
extern AnimCmd* volcano_magmar_assetAnimModel5[];
extern AnimCmd* volcano_magmar_assetAnimModel6[];
extern AnimCmd* volcano_magmar_assetAnimModel7[];
extern AnimCmd* volcano_magmar_assetAnimModel8[];
extern AnimCmd* volcano_magmar_assetAnimModel9[];
extern AnimCmd* volcano_magmar_assetAnimModel10[];

extern AnimCmd** volcano_magmar_assetAnimMat1[];
extern AnimCmd** volcano_magmar_assetAnimMat2[];
extern AnimCmd** volcano_magmar_assetAnimMat4[];
extern AnimCmd** volcano_magmar_assetAnimMat3[];
extern AnimCmd** volcano_magmar_assetAnimMat6[];
extern AnimCmd** volcano_magmar_assetAnimMat7[];
extern AnimCmd** volcano_magmar_assetAnimMat8[];
extern AnimCmd** volcano_magmar_assetAnimMat9[];

extern GObj* D_802E1A30_732C30;

void volcano_magmar_StateInitial(GObj*);
void func_802D7E90_729090(GObj*);
void volcano_magmar_Idle1(GObj*);
void volcano_magmar_Idle2(GObj*);
void volcano_magmar_Idle3(GObj*);
void volcano_magmar_HitByPB(GObj*);
void volcano_magmar_HitByApple(GObj*);
void volcano_magmar_AffectedByPB(GObj*);
void func_802D7CB4_728EB4(GObj*);
void volcano_magmar_HearsFlute(GObj*);
void volcano_magmar_InteractWithPokemon(GObj*);
void volcano_magmar_SearchApple(GObj*);
void volcano_magmar_DoSearchApple(GObj*);
void func_802D7458_728658(GObj*);
void volcano_magmar_Walk(GObj*);
void func_802D7A34_728C34(GObj*);
void volcano_magmar_RunToApple(GObj*);
void func_802D7B08_728D08(GObj*);
void volcano_magmar_BurnCharmander(GObj*);
void func_802D7C30_728E30(GObj*);

s32 volcano_magmar_Sounds8[] = { SOUND_ID_283 };
s32 volcano_magmar_Sounds10[] = { SOUND_ID_284 };
s32 volcano_magmar_Sounds7[] = { SOUND_ID_285 };
s32 volcano_magmar_Sounds9[] = { SOUND_ID_286 };
s32 volcano_magmar_Sounds2[] = { SOUND_ID_287, SOUND_ID_141 };

AnimationHeader volcano_magmar_animIdle1 = {
    0.45,
    50,
    volcano_magmar_assetAnimModel4,
    volcano_magmar_assetAnimMat4,
    NULL
};

AnimationHeader volcano_magmar_animIdle2 = {
    0.4,
    60,
    volcano_magmar_assetAnimModel6,
    volcano_magmar_assetAnimMat6,
    NULL
};

AnimationHeader volcano_magmar_animIdle3 = {
    0.6,
    60,
    volcano_magmar_assetAnimModel1,
    volcano_magmar_assetAnimMat1,
    NULL
};

AnimationHeader D_802E1014_732214 = {
    1,
    30,
    volcano_magmar_assetAnimModel3,
    volcano_magmar_assetAnimMat3,
    NULL
};

AnimationHeader D_802E1028_732228 = {
    0.7,
    90,
    volcano_magmar_assetAnimModel8,
    volcano_magmar_assetAnimMat8,
    volcano_magmar_Sounds8
};

AnimationHeader D_802E103C_73223C = {
    0.6,
    60,
    volcano_magmar_assetAnimModel10,
    NULL,
    volcano_magmar_Sounds10
};

AnimationHeader D_802E1050_732250 = {
    0.5,
    20,
    volcano_magmar_assetAnimModel5,
    NULL,
    NULL
};

AnimationHeader D_802E1064_732264 = {
    0.35,
    52,
    volcano_magmar_assetAnimModel7,
    volcano_magmar_assetAnimMat7,
    volcano_magmar_Sounds7
};

AnimationHeader D_802E1078_732278 = {
    0.35,
    60,
    volcano_magmar_assetAnimModel9,
    volcano_magmar_assetAnimMat9,
    volcano_magmar_Sounds9
};

AnimationHeader D_802E108C_73228C = {
    0.5,
    145,
    volcano_magmar_assetAnimModel2,
    volcano_magmar_assetAnimMat2,
    volcano_magmar_Sounds2
};

GObj* D_802E10A0_7322A0 = NULL;

InteractionHandler volcano_magmar_tgWaitForCmd30[] = {
    { POKEMON_CMD_30, volcano_magmar_Idle1, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler volcano_magmar_tgIdle[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_10, volcano_magmar_AffectedByPB, 0, NULL },
    { POKEMON_CMD_15, volcano_magmar_SearchApple, 0, NULL },
    { POKEMON_CMD_5, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, volcano_magmar_HearsFlute, 0, NULL },
    { VOLCANO_CMD_37, func_802D7CB4_728EB4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler volcano_magmar_tgIdle3[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_10, volcano_magmar_AffectedByPB, 0, NULL },
    { POKEMON_CMD_15, volcano_magmar_SearchApple, 0, NULL },
    { POKEMON_CMD_5, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_26, volcano_magmar_InteractWithPokemon, 0, NULL },
    { VOLCANO_CMD_37, func_802D7CB4_728EB4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler volcano_magmar_tgEatingApple[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_21, volcano_magmar_Idle1, 0, NULL },
    { POKEMON_CMD_10, volcano_magmar_AffectedByPB, 0, NULL },
    { POKEMON_CMD_5, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_26, volcano_magmar_InteractWithPokemon, 0, NULL },
    { VOLCANO_CMD_37, func_802D7CB4_728EB4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1294_732494[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_21, volcano_magmar_Idle1, 0, NULL },
    { POKEMON_CMD_10, volcano_magmar_AffectedByPB, 0, NULL },
    { POKEMON_CMD_5, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, volcano_magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, volcano_magmar_HearsFlute, 0, NULL },
    { VOLCANO_CMD_37, func_802D7CB4_728EB4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1324_732524[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_10, volcano_magmar_AffectedByPB, 0, NULL },
    { VOLCANO_CMD_37, func_802D7CB4_728EB4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1374_732574[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_15, volcano_magmar_SearchApple, 0, NULL },
    { VOLCANO_CMD_37, func_802D7CB4_728EB4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E13C4_7325C4[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E13F4_7325F4[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { VOLCANO_CMD_37, func_802D7CB4_728EB4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E1434_732634[] = {
    { POKEMON_CMD_9, volcano_magmar_HitByPB, 0, NULL },
    { POKEMON_CMD_13, volcano_magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_10, volcano_magmar_AffectedByPB, 0, NULL },
    { VOLCANO_CMD_37, func_802D7CB4_728EB4, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState volcano_magmar_IdleStates[] = {
    { 100, volcano_magmar_Idle1 },
    { 100, volcano_magmar_Idle2 },
    { 100, volcano_magmar_Idle3 },
    { 0, NULL },
};

InteractionHandler D_802E14A4_7326A4[] = {
    { POKEMON_CMD_41, func_802D7E90_729090, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup volcano_magmar_AnimSetup = {
    &volcano_magmar_animIdle1,
    volcano_magmar_StateInitial,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData volcano_magmar_InitData = {
    volcano_magmar_assetModel,
    volcano_magmar_assetMaterials,
    renderPokemonModelTypeJFogged,
    &volcano_magmar_AnimSetup,
    { 1.3, 1.3, 1.3 },
    { 0, 110, 0 },
    68,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void volcano_magmar_DeleteLater(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 blockIndex;
    f32 blockPart;
    s32 blockIndex2;
    f32 blockPart2;

    if (pokemon->behavior == 1) {
        // standing alone magmar
        while (true) {
            getLevelProgress(&blockIndex, &blockPart);
            if (blockIndex > 4 || blockIndex == 4 && blockPart >= 0.35) {
                break;
            }
            ohWait(1);
        }
    } else {
        // pair of magmars
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
    Pokemon_StartAuxProc(obj, volcano_magmar_DeleteLater);
    if (pokemon->behavior == 1) {
        // standing alone magmar
        Pokemon_SetState(obj, func_802D7458_728658);
    }
    Pokemon_SetAnimation(obj, &volcano_magmar_animIdle1);
    pokemon->transitionGraph = volcano_magmar_tgWaitForCmd30;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802D7458_728658(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    s32 blockIndex;
    f32 blockPart;

    D_802E10A0_7322A0 = obj;
    Pokemon_SetAnimation(obj, &volcano_magmar_animIdle1);
    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 3 || blockIndex == 3 && blockPart >= 0.5f) {
            break;
        }
        ohWait(1);
    }
    Pokemon_SetState(obj, volcano_magmar_Idle1);
}

void volcano_magmar_Idle1(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->unk_10E = 0;
    Pokemon_SetAnimation(obj, &volcano_magmar_animIdle1);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = volcano_magmar_tgIdle;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, volcano_magmar_IdleStates);
}

void volcano_magmar_Idle2(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &volcano_magmar_animIdle2);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = volcano_magmar_tgIdle;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, volcano_magmar_IdleStates);
}

void volcano_magmar_Idle3(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &volcano_magmar_animIdle3);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, volcano_magmar_Walk);
    pokemon->transitionGraph = volcano_magmar_tgIdle3;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, volcano_magmar_Idle1);
    }
    Pokemon_SetStateRandom(obj, volcano_magmar_IdleStates);
}

void volcano_magmar_Walk(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void volcano_magmar_HitByPB(GObj* obj) {
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

void volcano_magmar_HitByApple(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->unk_10E = 0;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &D_802E1028_732228);
    pokemon->transitionGraph = D_802E13F4_7325F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, volcano_magmar_IdleStates);
}

void volcano_magmar_AffectedByPB(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->unk_10E = 0;
    Pokemon_SetAnimation(obj, &D_802E1028_732228);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E13F4_7325F4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, volcano_magmar_IdleStates);
}

void volcano_magmar_DoSearchApple(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[0].field1 = 1;
    Pokemon_StartPathProc(obj, volcano_magmar_RunToApple);
    pokemon->transitionGraph = volcano_magmar_tgEatingApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, volcano_magmar_Idle1);
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

void volcano_magmar_RunToApple(GObj* obj) {
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

void volcano_magmar_SearchApple(GObj* arg0) {
    Pokemon_SetState(arg0, volcano_magmar_DoSearchApple);
}

void func_802D7A34_728C34(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E1374_732574;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, volcano_magmar_Idle1);
}

void volcano_magmar_HearsFlute(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &volcano_magmar_animIdle3);
    Pokemon_StartPathProc(obj, func_802D7B08_728D08);
    pokemon->transitionGraph = D_802E13C4_7325C4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, volcano_magmar_Idle1);
}

void func_802D7B08_728D08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void volcano_magmar_InteractWithPokemon(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->behavior == 1) {
        // standing alone magmar
        Pokemon_SetState(obj, volcano_magmar_BurnCharmander);
    }
    pokemon->unk_10E = 11;

    Pokemon_SetAnimation(obj, &D_802E108C_73228C);
    Pokemon_StartPathProc(obj, func_802D7C30_728E30);
    pokemon->counter = 90, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E1434_732634;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommand(pokemon->interactionTarget, VOLCANO_CMD_37, obj);
    pokemon->transitionGraph = D_802E1434_732634;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->unk_10E = 0;
    Pokemon_SetState(obj, volcano_magmar_Idle1);
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
    if (1) {
    } // required to match
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

void volcano_magmar_BurnCharmander(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (pokemon->miscVars[0].field1 == 0) {
        Pokemon_SetState(obj, volcano_magmar_Idle1);
    }

    Pokemon_SetAnimation(obj, &D_802E108C_73228C);
    Pokemon_StartPathProc(obj, func_802D7C30_728E30);
    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E1434_732634;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommand(D_802E1A30_732C30, VOLCANO_CMD_37, obj);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802E14A4_7326A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &volcano_magmar_animIdle1);
    pokemon->transitionGraph = D_802E14A4_7326A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, volcano_magmar_Idle1);
}
// clang-format off
void func_802D7E90_729090(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
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
