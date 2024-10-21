#include "volcano/volcano.h"

extern AnimCmd* magmar_modelanim_walk[];
extern AnimCmd* magmar_modelanim_spew_fire[];
extern AnimCmd* magmar_modelanim_run[];
extern AnimCmd* magmar_modelanim_idle[];
extern AnimCmd* magmar_modelanim_lie[];
extern AnimCmd* magmar_modelanim_look_around[];
extern AnimCmd* magmar_modelanim_get_up[];
extern AnimCmd* magmar_modelanim_hit[];
extern AnimCmd* magmar_modelanim_eat[];
extern AnimCmd* magmar_modelanim_fall[];

extern AnimCmd** magmar_matanim_walk[];
extern AnimCmd** magmar_matanim_spew_fire[];
extern AnimCmd** magmar_matanim_idle[];
extern AnimCmd** magmar_matanim_run[];
extern AnimCmd** magmar_matanim_look_around[];
extern AnimCmd** magmar_matanim_get_up[];
extern AnimCmd** magmar_matanim_hit[];
extern AnimCmd** magmar_matanim_eat[];

extern GObj* charmander_Group5Pokemon;

void magmar_InitialState(GObj*);
void magmar_CharmanderEvolved(GObj*);
void magmar_Idle(GObj*);
void magmar_LookAround(GObj*);
void magmar_Walk(GObj*);
void magmar_HitByPesterBall(GObj*);
void magmar_HitByApple(GObj*);
void magmar_AffectedByPesterBall(GObj*);
void magmar_BurnedDown(GObj*);
void magmar_HearsFlute(GObj*);
void magmar_InteractWithPokemon(GObj*);
void magmar_SearchApple(GObj*);
void magmar_AppleNearby(GObj*);
void magmar_LoneInit(GObj*);
void magmar_MoveWalk(GObj*);
void magmar_Recover(GObj*);
void magmar_RunToApple(GObj*);
void magmar_TurnToPlayer(GObj*);
void magmar_BurnCharmander(GObj*);
void magmar_TurnToRival(GObj*);

s32 magmar_animsounds_hit[] = { SOUND_ID_283 };
s32 magmar_animsounds_fall[] = { SOUND_ID_284 };
s32 magmar_animsounds_getup[] = { SOUND_ID_285 };
s32 magmar_animsounds_eat[] = { SOUND_ID_286 };
s32 magmar_animsounds_spewfire[] = { SOUND_ID_287, SOUND_ID_141 };

AnimationHeader magmar_animation_idle = {
    0.45,
    50,
    magmar_modelanim_idle,
    magmar_matanim_idle,
    NULL
};

AnimationHeader magmar_animation_lookaround = {
    0.4,
    60,
    magmar_modelanim_look_around,
    magmar_matanim_look_around,
    NULL
};

AnimationHeader magmar_animation_walk = {
    0.6,
    60,
    magmar_modelanim_walk,
    magmar_matanim_walk,
    NULL
};

AnimationHeader magmar_animation_run = {
    1,
    30,
    magmar_modelanim_run,
    magmar_matanim_run,
    NULL
};

AnimationHeader magmar_animation_hit = {
    0.7,
    90,
    magmar_modelanim_hit,
    magmar_matanim_hit,
    magmar_animsounds_hit
};

AnimationHeader magmar_animation_fall = {
    0.6,
    60,
    magmar_modelanim_fall,
    NULL,
    magmar_animsounds_fall
};

AnimationHeader magmar_animation_lie = {
    0.5,
    20,
    magmar_modelanim_lie,
    NULL,
    NULL
};

AnimationHeader magmar_animation_getup = {
    0.35,
    52,
    magmar_modelanim_get_up,
    magmar_matanim_get_up,
    magmar_animsounds_getup
};

AnimationHeader magmar_animation_eat = {
    0.35,
    60,
    magmar_modelanim_eat,
    magmar_matanim_eat,
    magmar_animsounds_eat
};

AnimationHeader magmar_animation_spewfire = {
    0.5,
    145,
    magmar_modelanim_spew_fire,
    magmar_matanim_spew_fire,
    magmar_animsounds_spewfire
};

GObj* magmar_loneMagmar = NULL;

InteractionHandler magmar_tg_WaitMoltres[] = {
    { VOLCANO_CMD_SPAWN_MOLTRES, magmar_Idle, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_Normal[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_10, magmar_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_15, magmar_SearchApple, 0, NULL },
    { POKEMON_CMD_5, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, magmar_HearsFlute, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, magmar_BurnedDown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_Walk[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_10, magmar_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_15, magmar_SearchApple, 0, NULL },
    { POKEMON_CMD_5, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_26, magmar_InteractWithPokemon, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, magmar_BurnedDown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_Running[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_21, magmar_Idle, 0, NULL },
    { POKEMON_CMD_10, magmar_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_5, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_26, magmar_InteractWithPokemon, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, magmar_BurnedDown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_Eating[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_21, magmar_Idle, 0, NULL },
    { POKEMON_CMD_10, magmar_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_5, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, magmar_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, magmar_HearsFlute, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, magmar_BurnedDown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_AfterEating[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_10, magmar_AffectedByPesterBall, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, magmar_BurnedDown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_Recover[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_15, magmar_SearchApple, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, magmar_BurnedDown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_HearsFlute[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_Hit[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, magmar_BurnedDown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magmar_tg_Fighting[] = {
    { POKEMON_CMD_9, magmar_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magmar_HitByApple, 0, NULL },
    { POKEMON_CMD_10, magmar_AffectedByPesterBall, 0, NULL },
    { VOLCANO_CMD_MAGMAR_SPEW_FIRE, magmar_BurnedDown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState magmar_idleStates[] = {
    { 100, magmar_Idle },
    { 100, magmar_LookAround },
    { 100, magmar_Walk },
    { 0, NULL },
};

InteractionHandler magmar_tg_AttackingCharmander[] = {
    { VOLCANO_CMD_CHARMANDER_EVOLVE, magmar_CharmanderEvolved, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup magmar_animSetup = {
    &magmar_animation_idle,
    magmar_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData magmar_initData = {
    magmar_model,
    magmar_materials,
    renderPokemonModelTypeJFogged,
    &magmar_animSetup,
    { 1.3, 1.3, 1.3 },
    { 0, 110, 0 },
    68,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(magmar_DeleteLater)
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

POKEMON_FUNC(magmar_InitialState)
    pokemon->miscVars[0].field1 = false;
    pokemon->flags |= POKEMON_FLAG_200;
    Pokemon_StartAuxProc(obj, magmar_DeleteLater);
    if (pokemon->behavior == 1) {
        // standing alone magmar
        Pokemon_SetState(obj, magmar_LoneInit);
    }
    Pokemon_SetAnimation(obj, &magmar_animation_idle);
    // wait untile moltres spawns
    pokemon->transitionGraph = magmar_tg_WaitMoltres;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(magmar_LoneInit)
    s32 blockIndex;
    f32 blockPart;

    magmar_loneMagmar = obj;
    Pokemon_SetAnimation(obj, &magmar_animation_idle);
    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 3 || blockIndex == 3 && blockPart >= 0.5f) {
            break;
        }
        ohWait(1);
    }
    Pokemon_SetState(obj, magmar_Idle);
}

POKEMON_FUNC(magmar_Idle)
    pokemon->specialPoseID = 0;
    Pokemon_SetAnimation(obj, &magmar_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = magmar_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, magmar_idleStates);
}

POKEMON_FUNC(magmar_LookAround)
    Pokemon_ForceAnimation(obj, &magmar_animation_lookaround);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = magmar_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, magmar_idleStates);
}

POKEMON_FUNC(magmar_Walk)
    Pokemon_SetAnimation(obj, &magmar_animation_walk);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, magmar_MoveWalk);
    pokemon->transitionGraph = magmar_tg_Walk;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, magmar_Idle);
    }
    Pokemon_SetStateRandom(obj, magmar_idleStates);
}

POKEMON_FUNC(magmar_MoveWalk)
    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magmar_HitByPesterBall)
    pokemon->specialPoseID = 0;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &magmar_animation_fall);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &magmar_animation_lie);
    pokemon->transitionGraph = NULL;
    pokemon->flags &= ~POKEMON_FLAG_800;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &magmar_animation_getup);
    pokemon->transitionGraph = magmar_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, magmar_Recover);
    if (obj) { // required to match
    }
}

POKEMON_FUNC(magmar_HitByApple)
    pokemon->specialPoseID = 0;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &magmar_animation_hit);
    pokemon->transitionGraph = magmar_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, magmar_idleStates);
}

POKEMON_FUNC(magmar_AffectedByPesterBall)
    pokemon->specialPoseID = 0;
    Pokemon_SetAnimation(obj, &magmar_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = magmar_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, magmar_idleStates);
}

POKEMON_FUNC(magmar_AppleNearby)
    pokemon->miscVars[0].field1 = true;
    Pokemon_StartPathProc(obj, magmar_RunToApple);
    pokemon->transitionGraph = magmar_tg_Running;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, magmar_Idle);
    }

    Pokemon_SetAnimation(obj, &magmar_animation_eat);
    pokemon->counter = 48, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magmar_tg_Eating;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_EatApple(obj);
    pokemon->transitionGraph = magmar_tg_AfterEating;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, magmar_Recover);
}

POKEMON_FUNC(magmar_RunToApple)
    Pokemon_SetAnimation(obj, &magmar_animation_run);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magmar_SearchApple)
    Pokemon_SetState(obj, magmar_AppleNearby);
}

POKEMON_FUNC(magmar_Recover)
    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magmar_tg_Recover;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, magmar_Idle);
}

POKEMON_FUNC(magmar_HearsFlute)
    Pokemon_SetAnimation(obj, &magmar_animation_walk);
    Pokemon_StartPathProc(obj, magmar_TurnToPlayer);
    pokemon->transitionGraph = magmar_tg_HearsFlute;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, magmar_Idle);
}

POKEMON_FUNC(magmar_TurnToPlayer)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magmar_InteractWithPokemon)
    if (pokemon->behavior == 1) {
        // standing alone magmar
        Pokemon_SetState(obj, magmar_BurnCharmander);
    }
    pokemon->specialPoseID = 11;

    Pokemon_SetAnimation(obj, &magmar_animation_spewfire);
    Pokemon_StartPathProc(obj, magmar_TurnToRival);
    pokemon->counter = 90, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magmar_tg_Fighting;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommand(pokemon->interactionTarget, VOLCANO_CMD_MAGMAR_SPEW_FIRE, obj);
    pokemon->transitionGraph = magmar_tg_Fighting;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->specialPoseID = 0;
    Pokemon_SetState(obj, magmar_Idle);
}

POKEMON_FUNC(magmar_TurnToRival)
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

POKEMON_FUNC(magmar_BurnedDown)
    pokemon->specialPoseID = 11;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &magmar_animation_fall);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->specialPoseID = 0;
    Pokemon_SetAnimation(obj, &magmar_animation_lie);
    pokemon->transitionGraph = NULL;
    pokemon->flags &= ~POKEMON_FLAG_800;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &magmar_animation_getup);
    pokemon->transitionGraph = magmar_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, magmar_Recover);
}

POKEMON_FUNC(magmar_BurnCharmander)
    if (!pokemon->miscVars[0].field1) {
        Pokemon_SetState(obj, magmar_Idle);
    }

    Pokemon_SetAnimation(obj, &magmar_animation_spewfire);
    Pokemon_StartPathProc(obj, magmar_TurnToRival);
    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magmar_tg_Fighting;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommand(charmander_Group5Pokemon, VOLCANO_CMD_MAGMAR_SPEW_FIRE, obj);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = magmar_tg_AttackingCharmander;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &magmar_animation_idle);
    pokemon->transitionGraph = magmar_tg_AttackingCharmander;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, magmar_Idle);
}

POKEMON_FUNC(magmar_CharmanderEvolved)
    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 80, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &magmar_animation_fall);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &magmar_animation_lie);
    Pokemon_SetState(obj, NULL);
}

GObj* magmar_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &magmar_initData);
}
