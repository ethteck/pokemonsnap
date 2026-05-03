#include "volcano/volcano.h"

extern AnimCmd* rapidash_modelanim_walk[];
extern AnimCmd* rapidash_modelanim_run[];
extern AnimCmd* rapidash_modelanim_idle[];
extern AnimCmd* rapidash_modelanim_rear[];
extern AnimCmd* rapidash_modelanim_shake_head[];
extern AnimCmd* rapidash_modelanim_kick[];

extern AnimCmd** rapidash_matanim_walk[];
extern AnimCmd** rapidash_matanim_run[];
extern AnimCmd** rapidash_matanim_idle[];
extern AnimCmd** rapidash_matanim_rear[];
extern AnimCmd** rapidash_matanim_shake_head[];
extern AnimCmd** rapidash_matanim_kick[];

void rapidash_RunningHit(GObj*);
void rapidash_RunningAffectedByItem(GObj*);
void rapidash_Walk(GObj*);
void rapidash_Run(GObj*);
void rapidash_InitialState(GObj*);
void rapidash_HitByPesterBall(GObj*);
void rapidash_HitByApple(GObj*);
void rapidash_SearchApple(GObj*);
void rapidash_StartRun(GObj*);
void rapidash_Idle(GObj*);
void rapidash_AffectedByPesterBall(GObj*);
void rapidash_HitBeforeRun(GObj*);
void rapidash_AffectedByItemBeforeRun(GObj*);
void rapidash_AppleNearby(GObj*);
void rapidash_Recover(GObj*);
void rapidash_RunAlongPath(GObj*);
void rapidash_MoveRunAlongPath(GObj*);
void rapidash_HearsFlute(GObj*);
void rapidash_IdleBeforeRun(GObj*);
void rapidash_MoveWalk(GObj*);
void rapidash_MoveRun(GObj*);
void rapidash_TurnToApple(GObj*);
void rapidash_RunToApple(GObj*);
void rapidash_EatApple(GObj*);
void rapidash_TurnToPlayer(GObj*);

__ALIGNER2

s32 rapidash_animsounds_idle[] = { 0, SOUND_ID_129, SOUND_ID_130 };
s32 rapidash_animsounds_run[] = { SOUND_ID_128, SOUND_ID_129, SOUND_ID_130, SOUND_ID_131 };
s32 rapidash_animsounds_shake_head[] = { SOUND_ID_347 };
s32 rapidash_animsounds_kick[] = { 0, SOUND_ID_129, SOUND_ID_130 };
s32 rapidash_animsounds_rear[] = { SOUND_ID_347 };

AnimationHeader rapidash_animation_idle = {
    0.5,
    112,
    rapidash_modelanim_idle,
    rapidash_matanim_idle,
    rapidash_animsounds_idle
};

AnimationHeader rapidash_animation_walk = {
    0.5,
    40,
    rapidash_modelanim_walk,
    rapidash_matanim_walk,
    NULL
};

AnimationHeader rapidash_animation_run = {
    0.5,
    16,
    rapidash_modelanim_run,
    rapidash_matanim_run,
    rapidash_animsounds_run
};

AnimationHeader rapidash_animation_shake_head = {
    0.5,
    64,
    rapidash_modelanim_shake_head,
    rapidash_matanim_shake_head,
    rapidash_animsounds_shake_head
};

AnimationHeader rapidash_animation_kick = {
    0.5,
    128,
    rapidash_modelanim_kick,
    rapidash_matanim_kick,
    rapidash_animsounds_kick
};

AnimationHeader rapidash_animation_rear = {
    0.5,
    64,
    rapidash_modelanim_rear,
    rapidash_matanim_rear,
    rapidash_animsounds_rear
};

InteractionHandler rapidash_tg_Normal[] = {
    { POKEMON_CMD_9, rapidash_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, rapidash_HitByApple, 0, NULL },
    { POKEMON_CMD_10, rapidash_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, rapidash_AppleNearby, 0, NULL },
    { POKEMON_CMD_15, rapidash_SearchApple, 0, NULL },
    { POKEMON_CMD_5, rapidash_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, rapidash_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, rapidash_HearsFlute, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler rapidash_tg_SearchingApple[] = {
    { POKEMON_CMD_9, rapidash_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, rapidash_HitByApple, 0, NULL },
    { POKEMON_CMD_10, rapidash_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, rapidash_AppleNearby, 0, NULL },
    { POKEMON_CMD_5, rapidash_HearsFlute, 0, NULL },
    { POKEMON_CMD_6, rapidash_HearsFlute, 0, NULL },
    { POKEMON_CMD_7, rapidash_HearsFlute, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler rapidash_tg_Eating[] = {
    { POKEMON_CMD_9, rapidash_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, rapidash_HitByApple, 0, NULL },
    { POKEMON_CMD_10, rapidash_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, rapidash_AppleNearby, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler rapidash_tg_Distracted[] = {
    { POKEMON_CMD_9, rapidash_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, rapidash_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler rapidash_tg_HearsFlute[] = {
    { POKEMON_CMD_9, rapidash_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, rapidash_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler rapidash_tg_Recover[] = {
    { POKEMON_CMD_9, rapidash_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, rapidash_HitByApple, 0, NULL },
    { POKEMON_CMD_15, rapidash_SearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler rapidash_tg_Unused[] = {
    { POKEMON_CMD_9, rapidash_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, rapidash_HitByApple, 0, NULL },
    { POKEMON_CMD_10, rapidash_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState rapidash_idleStates[] = {
    { 100, rapidash_Idle },
    { 100, rapidash_Walk },
    { 100, rapidash_Run },
    { 0, NULL },
};

InteractionHandler rapidash_tg_IdleBeforeRun[] = {
    { POKEMON_CMD_9, rapidash_HitBeforeRun, 0, NULL },
    { POKEMON_CMD_13, rapidash_HitBeforeRun, 0, NULL },
    { POKEMON_CMD_10, rapidash_AffectedByItemBeforeRun, 0, NULL },
    { POKEMON_CMD_14, rapidash_AffectedByItemBeforeRun, 0, NULL },
    { POKEMON_CMD_16, rapidash_StartRun, 4000, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler rapidash_tg_Running[] = {
    { POKEMON_CMD_9, rapidash_RunningHit, 0, NULL },
    { POKEMON_CMD_13, rapidash_RunningHit, 0, NULL },
    { POKEMON_CMD_10, rapidash_RunningAffectedByItem, 0, NULL },
    { POKEMON_CMD_14, rapidash_RunningAffectedByItem, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(rapidash_InitialState)
    if (pokemon->behavior != 0) {
        Pokemon_SetState(obj, rapidash_IdleBeforeRun);
    }
    Pokemon_SetState(obj, rapidash_Idle);
}

POKEMON_FUNC(rapidash_Idle)
    Pokemon_SetAnimation(obj, &rapidash_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = rapidash_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, rapidash_idleStates);
}

POKEMON_FUNC(rapidash_Walk)
    Pokemon_SetAnimation(obj, &rapidash_animation_walk);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, rapidash_MoveWalk);
    pokemon->transitionGraph = rapidash_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, rapidash_Idle);
    }
    Pokemon_SetStateRandom(obj, rapidash_idleStates);
}

POKEMON_FUNC(rapidash_MoveWalk)
    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(rapidash_Run)
    Pokemon_SetAnimation(obj, &rapidash_animation_run);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, rapidash_MoveRun);
    pokemon->transitionGraph = rapidash_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, rapidash_Idle);
    }
    Pokemon_SetStateRandom(obj, rapidash_idleStates);
}

POKEMON_FUNC(rapidash_MoveRun)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(rapidash_HitByPesterBall)
    Pokemon_SetAnimation(obj, &rapidash_animation_shake_head);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = rapidash_tg_Distracted;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, rapidash_Recover);
}

POKEMON_FUNC(rapidash_HitByApple)
    Pokemon_SetAnimation(obj, &rapidash_animation_shake_head);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = rapidash_tg_Distracted;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, rapidash_Recover);
}

POKEMON_FUNC(rapidash_AffectedByPesterBall)
    Pokemon_ForceAnimation(obj, &rapidash_animation_rear);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = rapidash_tg_Distracted;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, rapidash_Idle);
}

POKEMON_FUNC(rapidash_AppleNearby)
    Pokemon_ForceAnimation(obj, &rapidash_animation_rear);
    Pokemon_StartPathProc(obj, rapidash_TurnToApple);
    pokemon->transitionGraph = rapidash_tg_Distracted;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_StartPathProc(obj, rapidash_RunToApple);
    pokemon->transitionGraph = rapidash_tg_SearchingApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, rapidash_Idle);
    }
    Pokemon_SetState(obj, rapidash_EatApple);
}

POKEMON_FUNC(rapidash_TurnToApple)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(rapidash_RunToApple)
    Pokemon_SetAnimation(obj, &rapidash_animation_run);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);

    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(rapidash_EatApple)
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, rapidash_Idle);
    }

    Pokemon_SetAnimation(obj, &rapidash_animation_kick);
    pokemon->transitionGraph = rapidash_tg_Eating;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, rapidash_EatApple);
    }
    Pokemon_SetState(obj, rapidash_Recover);
}

POKEMON_FUNC(rapidash_SearchApple)
    Pokemon_SetState(obj, rapidash_AppleNearby);
}

POKEMON_FUNC(rapidash_Recover)
    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = rapidash_tg_Recover;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, rapidash_Idle);
}

POKEMON_FUNC(rapidash_HearsFlute)
    Pokemon_SetAnimation(obj, &rapidash_animation_walk);
    Pokemon_StartPathProc(obj, rapidash_TurnToPlayer);
    pokemon->transitionGraph = rapidash_tg_HearsFlute;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, rapidash_Idle);
}

POKEMON_FUNC(rapidash_TurnToPlayer)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(rapidash_IdleBeforeRun)
    Pokemon_SetAnimation(obj, &rapidash_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = rapidash_tg_IdleBeforeRun;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, rapidash_IdleBeforeRun);
}

POKEMON_FUNC(rapidash_HitBeforeRun)
    Pokemon_SetAnimation(obj, &rapidash_animation_shake_head);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = rapidash_tg_IdleBeforeRun;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, rapidash_StartRun);
}

POKEMON_FUNC(rapidash_AffectedByItemBeforeRun)
    Pokemon_ForceAnimation(obj, &rapidash_animation_rear);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = rapidash_tg_IdleBeforeRun;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, rapidash_StartRun);
}

POKEMON_FUNC(rapidash_StartRun)
    Pokemon_StartPathProc(obj, rapidash_MoveRunAlongPath);
    Pokemon_SetState(obj, rapidash_RunAlongPath);
}

POKEMON_FUNC(rapidash_RunAlongPath)
    Pokemon_SetAnimation(obj, &rapidash_animation_run);
    pokemon->transitionGraph = rapidash_tg_Running;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(rapidash_MoveRunAlongPath)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.15f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(rapidash_RunningHit)
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_ForceAnimation(obj, &rapidash_animation_shake_head);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, rapidash_RunAlongPath);
}

POKEMON_FUNC(rapidash_RunningAffectedByItem)
    InteractionHandler saved[3] = {
        { POKEMON_CMD_9, rapidash_RunningHit, 0, NULL },
        { POKEMON_CMD_13, rapidash_RunningHit, 0, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_ForceAnimation(obj, &rapidash_animation_rear);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, rapidash_RunAlongPath);
}

PokemonAnimationSetup rapidash_animSetup = {
    &rapidash_animation_idle,
    rapidash_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData rapidash_initData = {
    rapidash_model,
    rapidash_materials,
    renderPokemonModelTypeI,
    &rapidash_animSetup,
    { 1.2, 1.2, 1.2 },
    { 0, 140, 0 },
    75,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

GObj* rapidash_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &rapidash_initData);
}
