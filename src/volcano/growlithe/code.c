#include "volcano/volcano.h"

extern AnimCmd* growlithe_modelanim_walk[];
extern AnimCmd* growlithe_modelanim_shakehead[];
extern AnimCmd* growlithe_modelanim_run[];
extern AnimCmd* growlithe_modelanim_idle[];
extern AnimCmd* growlithe_modelanim_roar[];
extern AnimCmd* growlithe_modelanim_hit[];
extern AnimCmd* growlithe_modelanim_jump[];
extern AnimCmd* growlithe_modelanim_eat[];

extern AnimCmd** growlithe_matanim_walk[];
extern AnimCmd** growlithe_matanim_shakehead[];
extern AnimCmd** growlithe_matanim_run[];
extern AnimCmd** growlithe_matanim_idle[];
extern AnimCmd** growlithe_matanim_roar[];
extern AnimCmd** growlithe_matanim_hit[];
extern AnimCmd** growlithe_matanim_jump[];
extern AnimCmd** growlithe_matanim_eat[];

void growlithe_AppleNearby(GObj*);
void growlithe_Restore(GObj*);
void growlithe_InitialState(GObj*);
void growlithe_Walk(GObj*);
void growlithe_Run(GObj*);
void growlithe_AffectedByPesterBall(GObj*);
void growlithe_SearchApple(GObj*);
void growlithe_Dance(GObj*);
void growlithe_HitByPesterBall(GObj*);
void growlithe_HitByApple(GObj*);
void growlithe_Idle(GObj*);
void growlithe_Roar(GObj*);
void growlithe_RunAwayFromPlayer(GObj*);
void growlithe_PhotoTaken(GObj*);
void growlithe_MoveJump(GObj*);
void growlithe_MoveWalk(GObj*);
void growlithe_MoveRun(GObj*);
void growlithe_TurnToFume(GObj*);
void growlithe_RunToApple(GObj*);
void growlithe_WithApple(GObj*);
void growlithe_TurnToApple(GObj*);
void growlithe_TurnToPlayer(GObj*);
void growlithe_RunAway(GObj*);

s32 growlithe_animsounds_roar[] = { SOUND_ID_275 };
s32 growlithe_animsounds_hit[] = { SOUND_ID_276 };
s32 growlithe_animsounds_eat[] = { SOUND_ID_274 };
s32 growlithe_animsounds_jump[] = { SOUND_ID_277, SOUND_ID_117 };

AnimationHeader growlithe_animation_idle = {
    0.6,
    140,
    growlithe_modelanim_idle,
    growlithe_matanim_idle,
    NULL
};

AnimationHeader growlithe_animation_roar = {
    0.5,
    36,
    growlithe_modelanim_roar,
    growlithe_matanim_roar,
    growlithe_animsounds_roar
};

AnimationHeader growlithe_animation_walk = {
    0.5,
    24,
    growlithe_modelanim_walk,
    growlithe_matanim_walk,
    NULL
};

AnimationHeader growlithe_animation_run = {
    1.0,
    40,
    growlithe_modelanim_run,
    growlithe_matanim_run,
    NULL
};

AnimationHeader growlithe_animation_hit = {
    0.4,
    90,
    growlithe_modelanim_hit,
    growlithe_matanim_hit,
    growlithe_animsounds_hit
};

AnimationHeader growlithe_animation_eat = {
    0.5,
    120,
    growlithe_modelanim_eat,
    growlithe_matanim_eat,
    growlithe_animsounds_eat
};

AnimationHeader growlithe_animation_shakehead = {
    0.7,
    90,
    growlithe_modelanim_shakehead,
    growlithe_matanim_shakehead,
    NULL
};

AnimationHeader growlithe_animation_jump = {
    0.7,
    55,
    growlithe_modelanim_jump,
    growlithe_matanim_jump,
    growlithe_animsounds_jump
};

InteractionHandler growlithe_tg_Normal[] = {
    { POKEMON_CMD_9, growlithe_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, growlithe_HitByApple, 0, NULL },
    { POKEMON_CMD_10, growlithe_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, growlithe_AppleNearby, 0, NULL },
    { POKEMON_CMD_15, growlithe_SearchApple, 0, NULL },
    { POKEMON_CMD_5, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_6, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_7, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_16, growlithe_RunAwayFromPlayer, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_23, growlithe_PhotoTaken, 60, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler growlithe_tg_SearchApple[] = {
    { POKEMON_CMD_9, growlithe_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, growlithe_HitByApple, 0, NULL },
    { POKEMON_CMD_10, growlithe_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, growlithe_AppleNearby, 0, NULL },
    { POKEMON_CMD_5, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_6, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_7, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler growlithe_tg_WithApple[] = {
    { POKEMON_CMD_9, growlithe_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, growlithe_HitByApple, 0, NULL },
    { POKEMON_CMD_10, growlithe_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, growlithe_AppleNearby, 0, NULL },
    { POKEMON_CMD_5, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_6, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_7, growlithe_Dance, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler growlithe_tg_shakehead[] = {
    { POKEMON_CMD_9, growlithe_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, growlithe_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler growlithe_tg_Dance[] = {
    { POKEMON_CMD_9, growlithe_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, growlithe_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler growlithe_tg_Restore[] = {
    { POKEMON_CMD_9, growlithe_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, growlithe_HitByApple, 0, NULL },
    { POKEMON_CMD_15, growlithe_SearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler growlithe_tg_RunAway[] = {
    { POKEMON_CMD_9, growlithe_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, growlithe_HitByApple, 0, NULL },
    { POKEMON_CMD_10, growlithe_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState growlithe_idleStates[] = {
    { 100, growlithe_Idle },
    { 100, growlithe_Walk },
    { 100, growlithe_Run },
    { 100, growlithe_Roar },
    { 0, NULL },
};

PokemonAnimationSetup growlithe_animSetup = {
    &growlithe_animation_idle,
    growlithe_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData growlithe_initData = {
    growlithe_model,
    growlithe_materials,
    renderPokemonModelTypeIFogged,
    &growlithe_animSetup,
    { 2.2, 2.2, 2.2 },
    { 0, 127, 4 },
    37,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(growlithe_InitialState)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;

    Pokemon_SetAnimation(obj, &growlithe_animation_jump);
    Pokemon_StartPathProc(obj, growlithe_MoveJump);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &growlithe_animation_shakehead);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = growlithe_tg_shakehead;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, growlithe_Idle);
}

POKEMON_FUNC(growlithe_MoveJump)
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

POKEMON_FUNC(growlithe_Idle)
    Pokemon_SetAnimation(obj, &growlithe_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = growlithe_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, growlithe_idleStates);
}

POKEMON_FUNC(growlithe_Walk)
    Pokemon_SetAnimation(obj, &growlithe_animation_walk);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, growlithe_MoveWalk);
    pokemon->transitionGraph = growlithe_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, growlithe_Idle);
    }

    Pokemon_SetStateRandom(obj, growlithe_idleStates);
}

POKEMON_FUNC(growlithe_MoveWalk)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(growlithe_Run)
    Pokemon_SetAnimation(obj, &growlithe_animation_run);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, growlithe_MoveRun);
    pokemon->transitionGraph = growlithe_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, growlithe_Idle);
    }

    Pokemon_SetStateRandom(obj, growlithe_idleStates);
}

POKEMON_FUNC(growlithe_MoveRun)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(growlithe_Roar)
    Pokemon_ForceAnimation(obj, &growlithe_animation_roar);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = growlithe_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, growlithe_idleStates);
}

POKEMON_FUNC(growlithe_HitByPesterBall)
    Pokemon_SetAnimation(obj, &growlithe_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = growlithe_tg_shakehead;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, growlithe_Restore);
}

POKEMON_FUNC(growlithe_HitByApple)
    Pokemon_SetAnimation(obj, &growlithe_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = growlithe_tg_shakehead;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, growlithe_Restore);
}

POKEMON_FUNC(growlithe_AffectedByPesterBall)
    Pokemon_SetAnimation(obj, &growlithe_animation_shakehead);
    Pokemon_StartPathProc(obj, growlithe_TurnToFume);
    pokemon->transitionGraph = growlithe_tg_shakehead;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, growlithe_Idle);
}

POKEMON_FUNC(growlithe_TurnToFume)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(growlithe_AppleNearby)
    Pokemon_StartPathProc(obj, growlithe_RunToApple);
    pokemon->transitionGraph = growlithe_tg_SearchApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, growlithe_Idle);
    }

    Pokemon_SetState(obj, growlithe_WithApple);
}

POKEMON_FUNC(growlithe_RunToApple)
    Pokemon_SetAnimation(obj, &growlithe_animation_run);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 100.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(growlithe_WithApple)
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, growlithe_Idle);
    }

    Pokemon_StartPathProc(obj, growlithe_TurnToApple);
    Pokemon_SetAnimation(obj, &growlithe_animation_eat);
    pokemon->transitionGraph = growlithe_tg_WithApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, growlithe_WithApple);
    }

    Pokemon_SetState(obj, growlithe_Restore);
}

POKEMON_FUNC(growlithe_TurnToApple)
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

POKEMON_FUNC(growlithe_SearchApple)
    Pokemon_SetState(obj, growlithe_AppleNearby);
}

POKEMON_FUNC(growlithe_Restore)
    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = growlithe_tg_Restore;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, growlithe_Idle);
}

POKEMON_FUNC(growlithe_Dance)
    Pokemon_SetAnimation(obj, &growlithe_animation_walk);
    Pokemon_StartPathProc(obj, growlithe_TurnToPlayer);
    pokemon->transitionGraph = growlithe_tg_Dance;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, growlithe_Idle);
}

POKEMON_FUNC(growlithe_TurnToPlayer)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(growlithe_RunAwayFromPlayer)
    Pokemon_SetAnimation(obj, &growlithe_animation_run);
    Pokemon_StartPathProc(obj, growlithe_RunAway);
    pokemon->transitionGraph = growlithe_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, growlithe_Idle);
}

POKEMON_FUNC(growlithe_RunAway)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(growlithe_PhotoTaken)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &growlithe_animation_roar);
    pokemon->transitionGraph = growlithe_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, growlithe_idleStates);
}

GObj* growlithe_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &growlithe_initData);
}
