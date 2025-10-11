#include "volcano/volcano.h"

extern AnimCmd* charmander_modelanim_walk[];
extern AnimCmd* charmander_modelanim_run[];
extern AnimCmd* charmander_modelanim_roar[];
extern AnimCmd* charmander_modelanim_idle[];
extern AnimCmd* charmander_modelanim_lie[];
extern AnimCmd* charmander_modelanim_howl[];
extern AnimCmd* charmander_modelanim_hit[];
extern AnimCmd* charmander_modelanim_shake_hands[];
extern AnimCmd* charmander_modelanim_fall[];
extern AnimCmd* charmander_modelanim_jump[];

extern AnimCmd** charmander_matanim_walk[];
extern AnimCmd** charmander_matanim_run[];
extern AnimCmd** charmander_matanim_roar[];
extern AnimCmd** charmander_matanim_idle[];
extern AnimCmd** charmander_matanim_lie[];
extern AnimCmd** charmander_matanim_howl[];
extern AnimCmd** charmander_matanim_hit[];
extern AnimCmd** charmander_matanim_shake_hands[];
extern AnimCmd** charmander_matanim_fall[];
extern AnimCmd** charmander_matanim_jump[];

extern GObj* magmar_loneMagmar; // magmar
extern void func_802DED6C_72FF6C(GObj*);
extern void charmeleon_EvolvedSpawn(GObj*);

void charmander_AppleNearby(GObj*);
void charmander_InitialState(GObj*);
void charmander_EvolveIntoCharmeleon(GObj*);
void charmander_SpawnFriend(GObj*);
void charmander_HitOrBurnt(GObj*);
void charmander_HitByApple(GObj*);
void charmander_RunAway(GObj*);
void charmander_BurntWhileFalling(GObj*);
void charmander_LieOnGround(GObj*);
void charmander_Walk(GObj*);
void charmander_Run(GObj*);
void charmander_Howl(GObj*);
void charmander_Dance(GObj*);
void charmander_SearchApple(GObj*);
void charmander_Idle(GObj*);
void charmander_Roar(GObj*);
void charmander_HowlInResponse(GObj*);
void charmander_HowlingEnded(GObj*);
void charmander_InitGroup3(GObj*);
void charmander_InitGroup4(GObj*);
void charmander_MoveWalk(GObj*);
void charmander_MoveRun(GObj*);
void charmander_PlayEvolveEffect(GObj*);
void charmander_MoveRunAway(GObj*);
void charmander_RunToApple(GObj*);
void charmander_WithApple(GObj*);
void charmander_SummonFriend(GObj*);
void charmander_MoveTurnToTarget(GObj*);
void charmander_MoveTurnToPlayer(GObj*);
void charmander_MoveTurnToPlayer2(GObj*);
void charmander_RunToSummoner(GObj*);
void charmander_RunToSummoner2(GObj*);

__ALIGNER2

s32 charmander_animsounds_howl[] = { SOUND_ID_281 };
s32 charmander_animsounds_shakehands[] = { SOUND_ID_282 };
s32 charmander_animsounds_fall[] = { SOUND_ID_279 };
s32 charmander_animsounds_jump[] = { SOUND_ID_280, SOUND_ID_373 };
s32 charmander_animsounds_roar[] = { SOUND_ID_278 };

AnimationHeader charmander_animation_idle = {
    0.5,
    60,
    charmander_modelanim_idle,
    charmander_matanim_idle,
    NULL
};

AnimationHeader charmander_animation_howl = {
    0.7,
    80,
    charmander_modelanim_howl,
    charmander_matanim_howl,
    charmander_animsounds_howl
};

AnimationHeader charmander_animation_walk = {
    0.4,
    32,
    charmander_modelanim_walk,
    charmander_matanim_walk,
    NULL
};

AnimationHeader charmander_animation_run = {
    1,
    32,
    charmander_modelanim_run,
    charmander_matanim_run,
    NULL
};

AnimationHeader charmander_animation_shakehands = {
    0.5,
    30,
    charmander_modelanim_shake_hands,
    charmander_matanim_shake_hands,
    charmander_animsounds_shakehands
};

AnimationHeader charmander_animation_fall = {
    0.4,
    50,
    charmander_modelanim_fall,
    charmander_matanim_fall,
    charmander_animsounds_fall
};

AnimationHeader charmander_animation_lie = {
    0.5,
    48,
    charmander_modelanim_lie,
    charmander_matanim_lie,
    NULL
};

AnimationHeader charmander_animation_hit = {
    0.4,
    60,
    charmander_modelanim_hit,
    charmander_matanim_hit,
    NULL
};

AnimationHeader charmander_animation_jump = {
    1,
    100,
    charmander_modelanim_jump,
    charmander_matanim_jump,
    charmander_animsounds_jump
};

AnimationHeader charmander_animation_roar = {
    0.5,
    55,
    charmander_modelanim_roar,
    charmander_matanim_roar,
    charmander_animsounds_roar
};

GObj* charmander_Group1Pokemon = NULL;
GObj* charmander_Group2Pokemon = NULL;
GObj* charmander_Group3Pokemon = NULL;
GObj* charmander_Group4Pokemon = NULL;
GObj* charmander_Group5Pokemon = NULL;

InteractionHandler charmander_tg_Normal[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_10, charmander_RunAway, 0, NULL },
    { POKEMON_CMD_14, charmander_AppleNearby, 0, NULL },
    { POKEMON_CMD_15, charmander_SearchApple, 0, NULL },
    { POKEMON_CMD_5, charmander_Dance, 0, NULL },
    { POKEMON_CMD_6, charmander_Dance, 0, NULL },
    { POKEMON_CMD_7, charmander_Dance, 0, NULL },
    { POKEMON_CMD_16, charmander_Roar, 1000.0 / 3.0, NULL },
    { VOLCANO_CMD_ANOTHER_CHARMANDER_HIT, charmander_RunAway, 0, NULL },
    { VOLCANO_CMD_HOWLING_ENDED, NULL, 0, charmander_HowlingEnded },
    { VOLCANO_CMD_HOWL_IN_RESPONSE, charmander_HowlInResponse, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_SearchApple[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_10, charmander_RunAway, 0, NULL },
    { POKEMON_CMD_14, charmander_AppleNearby, 0, NULL },
    { POKEMON_CMD_5, charmander_Dance, 0, NULL },
    { POKEMON_CMD_6, charmander_Dance, 0, NULL },
    { POKEMON_CMD_7, charmander_Dance, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_WithApple[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_10, charmander_RunAway, 0, NULL },
    { POKEMON_CMD_14, charmander_AppleNearby, 0, NULL },
    { POKEMON_CMD_5, charmander_Dance, 0, NULL },
    { POKEMON_CMD_6, charmander_Dance, 0, NULL },
    { POKEMON_CMD_7, charmander_Dance, 0, NULL },
    { VOLCANO_CMD_ANOTHER_CHARMANDER_HIT, charmander_RunAway, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_Hit[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_Dancing[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_Unused[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_15, charmander_SearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_Roar[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_10, charmander_RunAway, 0, NULL },
    { POKEMON_CMD_14, charmander_AppleNearby, 0, NULL },
    { POKEMON_CMD_5, charmander_Dance, 0, NULL },
    { POKEMON_CMD_6, charmander_Dance, 0, NULL },
    { POKEMON_CMD_7, charmander_Dance, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_RunAway[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_10, charmander_RunAway, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_Howling[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_10, charmander_RunAway, 0, NULL },
    { POKEMON_CMD_14, charmander_AppleNearby, 0, NULL },
    { POKEMON_CMD_15, charmander_SearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState charmander_idleStates[] = {
    { 30, charmander_Idle },
    { 30, charmander_Walk },
    { 30, charmander_Run },
    { 10, charmander_Howl },
    { 0, NULL },
};

f32 charmander_forbiddenGround[] = { 0 };

InteractionHandler charmander_tg_FallingDown[] = {
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_BurntWhileFalling, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_LyingOnGround[] = {
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_LieOnGround, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_ShakingHands[] = {
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_BeingSummoned[] = {
    { POKEMON_CMD_9, charmander_HitOrBurnt, 0, NULL },
    { POKEMON_CMD_13, charmander_HitByApple, 0, NULL },
    { POKEMON_CMD_10, charmander_RunAway, 0, NULL },
    { VOLCANO_CMD_ANOTHER_CHARMANDER_HIT, charmander_RunAway, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_InitGroup3[] = {
    { VOLCANO_CMD_GROUP3_SUMMONED, charmander_SpawnFriend, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_InitGroup4[] = {
    { VOLCANO_CMD_GROUP4_SUMMONED, charmander_SpawnFriend, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmander_tg_PlayEvolveEffect[] = {
    { VOLCANO_CMD_CHARMANDER_EVOLVE, charmander_EvolveIntoCharmeleon, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup charmander_animSetup = {
    &charmander_animation_idle,
    charmander_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData charmander_initData = {
    charmander_model,
    charmander_materials,
    renderPokemonModelTypeJFogged,
    &charmander_animSetup,
    { 2, 2, 2 },
    { 0, 112, -15 },
    27,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(charmander_DeleteLater)
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

POKEMON_FUNC(charmander_InitialState)
    pokemon->miscVars[0].field1 = false;
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartAuxProc(obj, charmander_DeleteLater);
    switch (pokemon->behavior) {
        case 1:
            charmander_Group1Pokemon = obj;
            break;
        case 2:
            charmander_Group2Pokemon = obj;
            break;
        case 3:
            charmander_Group3Pokemon = obj;
            Pokemon_SetState(obj, charmander_InitGroup3);
            break;
        case 4:
            charmander_Group4Pokemon = obj;
            Pokemon_SetState(obj, charmander_InitGroup4);
            break;
        case 5:
            charmander_Group5Pokemon = obj;
            break;
    }

    Pokemon_SetState(obj, charmander_Idle);
}

POKEMON_FUNC(charmander_Idle)
    Pokemon_SetAnimation(obj, &charmander_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charmander_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charmander_idleStates);
}

POKEMON_FUNC(charmander_Walk)
    Pokemon_SetAnimation(obj, &charmander_animation_walk);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, charmander_MoveWalk);
    pokemon->transitionGraph = charmander_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, charmander_Idle);
    }
    Pokemon_SetStateRandom(obj, charmander_idleStates);
}

POKEMON_FUNC(charmander_MoveWalk)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmander_Run)
    Pokemon_SetAnimation(obj, &charmander_animation_run);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, charmander_MoveRun);
    pokemon->transitionGraph = charmander_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, charmander_Idle);
    }
    Pokemon_SetStateRandom(obj, charmander_idleStates);
}

POKEMON_FUNC(charmander_MoveRun)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmander_Howl)
    Pokemon_ForceAnimation(obj, &charmander_animation_howl);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charmander_tg_Howling;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_HOWLING_ENDED, obj);
    Pokemon_SetStateRandom(obj, charmander_idleStates);
}

POKEMON_FUNC(charmander_HowlInResponse)
    Pokemon_ForceAnimation(obj, &charmander_animation_howl);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charmander_tg_Howling;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, charmander_idleStates);
}

POKEMON_FUNC(charmander_HowlingEnded)
    if (pokemon->interactionTarget != NULL &&
        pokemon->interactionTarget != obj &&
        Pokemon_GetDistance(obj, pokemon->interactionTarget) < 500.0) {
        cmdSendCommand(obj, VOLCANO_CMD_HOWL_IN_RESPONSE, obj);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(charmander_HitOrBurnt)
    InteractionHandler saved1[2] = charmander_tg_FallingDown;
    InteractionHandler saved2[2] = charmander_tg_LyingOnGround;

    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_ANOTHER_CHARMANDER_HIT, obj);
    Pokemon_SetAnimation(obj, &charmander_animation_fall);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved1;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget == magmar_loneMagmar) {
        Pokemon_SetState(obj, charmander_PlayEvolveEffect);
    }

    Pokemon_SetAnimation(obj, &charmander_animation_lie);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved2;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &charmander_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charmander_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &charmander_animation_run);
    Pokemon_StartPathProc(obj, charmander_MoveRunAway);
    pokemon->transitionGraph = charmander_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, charmander_Idle);
}

static void nullsub(void) {
}

POKEMON_FUNC(charmander_HitByApple)
    InteractionHandler saved1[2] = charmander_tg_ShakingHands;

    Pokemon_SetAnimation(obj, &charmander_animation_shakehands);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved1;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->apple = NULL;
    Pokemon_SetState(obj, charmander_Idle);
}

POKEMON_FUNC(charmander_RunAway)
    Pokemon_SetAnimation(obj, &charmander_animation_run);
    Pokemon_StartPathProc(obj, charmander_MoveRunAway);
    pokemon->transitionGraph = charmander_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, charmander_Idle);
}

POKEMON_FUNC(charmander_MoveRunAway)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunAwayFromTarget(obj, 600.0f, 0.1f, MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmander_AppleNearby)
    Pokemon_StartPathProc(obj, charmander_RunToApple);
    pokemon->transitionGraph = charmander_tg_SearchApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, charmander_Idle);
    }

    Pokemon_SetState(obj, charmander_WithApple);
}

POKEMON_FUNC(charmander_RunToApple)
    Pokemon_SetAnimation(obj, &charmander_animation_run);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 40.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmander_WithApple)
    if (!pokemon->miscVars[0].field1 && (pokemon->behavior == 1 || pokemon->behavior == 2)) {
        Pokemon_SetState(obj, charmander_SummonFriend);
    }

    Pokemon_SetAnimation(obj, &charmander_animation_jump);
    Pokemon_StartPathProc(obj, charmander_MoveTurnToTarget);
    pokemon->transitionGraph = charmander_tg_WithApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, charmander_WithApple);
    }
    Pokemon_SetState(obj, charmander_Idle);
}

POKEMON_FUNC(charmander_MoveTurnToTarget)
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

POKEMON_FUNC(charmander_SearchApple)
    Pokemon_SetState(obj, charmander_AppleNearby);
}

POKEMON_FUNC(charmander_Roar)
    Pokemon_StartPathProc(obj, charmander_MoveTurnToPlayer);
    Pokemon_SetAnimation(obj, &charmander_animation_roar);
    pokemon->transitionGraph = charmander_tg_Roar;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charmander_idleStates);
}

POKEMON_FUNC(charmander_MoveTurnToPlayer)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmander_Dance)
    Pokemon_SetAnimation(obj, &charmander_animation_walk);
    Pokemon_StartPathProc(obj, charmander_MoveTurnToPlayer2);
    pokemon->transitionGraph = charmander_tg_Dancing;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, charmander_Idle);
}

POKEMON_FUNC(charmander_MoveTurnToPlayer2)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmander_SummonFriend)
    InteractionHandler saved1[5] = charmander_tg_BeingSummoned;

    Pokemon_SetAnimation(obj, &charmander_animation_roar);
    if (pokemon->behavior == 1) {
        pokemon->interactionTarget = charmander_Group3Pokemon;
    } else {
        pokemon->interactionTarget = charmander_Group4Pokemon;
    }
    Pokemon_StartPathProc(obj, charmander_MoveTurnToTarget);
    pokemon->transitionGraph = saved1;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->behavior == 1) {
        cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_GROUP3_SUMMONED, obj);
    } else {
        cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_GROUP4_SUMMONED, obj);
    }
    pokemon->miscVars[0].field1 = true;
    Pokemon_SetAnimation(obj, &charmander_animation_roar);
    pokemon->pokemonLoopTarget = 2;
    pokemon->transitionGraph = charmander_tg_WithApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charmander_Idle);
}

POKEMON_FUNC(charmander_InitGroup3)
    HIDE_POKEMON();
    pokemon->transitionGraph = charmander_tg_InitGroup3;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(charmander_InitGroup4)
    HIDE_POKEMON();
    pokemon->transitionGraph = charmander_tg_InitGroup4;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(charmander_SpawnFriend)
    pokemon->flags &= ~POKEMON_FLAG_800;
    pokemon->flags &= ~POKEMON_FLAG_200;
    pokemon->forbiddenGround = charmander_forbiddenGround;
    SHOW_POKEMON();
    Pokemon_SetAnimation(obj, &charmander_animation_run);
    pokemon->hSpeed = 80.0f;
    Pokemon_StartPathProc(obj, charmander_RunToSummoner);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    pokemon->forbiddenGround = NULL;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->flags |= POKEMON_FLAG_200;

    Pokemon_StartPathProc(obj, charmander_RunToSummoner2);
    pokemon->transitionGraph = charmander_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, charmander_Idle);
}

POKEMON_FUNC(charmander_RunToSummoner)
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

POKEMON_FUNC(charmander_RunToSummoner2)
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmander_PlayEvolveEffect)
    func_802DED6C_72FF6C(obj);
    Pokemon_SetAnimation(obj, &charmander_animation_lie);
    pokemon->transitionGraph = charmander_tg_PlayEvolveEffect;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(charmander_BurntWhileFalling)
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charmander_LieOnGround);
}

POKEMON_FUNC(charmander_LieOnGround)
    Pokemon_ForceAnimation(obj, &charmander_animation_lie);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charmander_PlayEvolveEffect);
}

POKEMON_FUNC(charmander_EvolveIntoCharmeleon)
    charmeleon_EvolvedSpawn(obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* charmander_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &charmander_initData);
}
