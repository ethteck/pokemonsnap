#include "volcano/volcano.h"

extern AnimCmd* arcanine_modelanim_walk[];
extern AnimCmd* arcanine_modelanim_shake_head[];
extern AnimCmd* arcanine_modelanim_run[];
extern AnimCmd* arcanine_modelanim_idle[];
extern AnimCmd* arcanine_modelanim_roar[];
extern AnimCmd* arcanine_modelanim_hit[];
extern AnimCmd* arcanine_modelanim_jump[];
extern AnimCmd* arcanine_modelanim_eat[];

extern AnimCmd** arcanine_matanim_walk[];
extern AnimCmd** arcanine_matanim_shake_head[];
extern AnimCmd** arcanine_matanim_run[];
extern AnimCmd** arcanine_matanim_idle[];
extern AnimCmd** arcanine_matanim_roar[];
extern AnimCmd** arcanine_matanim_hit[];
extern AnimCmd** arcanine_matanim_jump[];
extern AnimCmd** arcanine_matanim_eat[];

void arcanine_AppleNearby(GObj*);
void arcanine_Restore(GObj*);
void arcanine_Idle(GObj*);
void arcanine_Walk(GObj*);
void arcanine_Run(GObj*);
void arcanine_Roar(GObj*);
void arcanine_InitialState(GObj*);
void arcanine_AffectedByPesterBall(GObj*);
void arcanine_SearchApple(GObj*);
void arcanine_Dance(GObj*);
void arcanine_RunAwayFromPlayer(GObj*);
void arcanine_PhotoTaken(GObj*);
void arcanine_HitByPesterBall(GObj*);
void arcanine_HitByApple(GObj*);
void arcanine_MoveJump(GObj*);
void arcanine_MoveWalk(GObj*);
void arcanine_MoveRun(GObj*);
void arcanine_TurnToFume(GObj*);
void arcanine_WithApple(GObj*);
void arcanine_RunToApple(GObj*);
void arcanine_TurnToApple(GObj*);
void arcanine_TurnToPlayer(GObj*);
void arcanine_RunAway(GObj*);

s32 arcanine_animsounds_roar[] = { SOUND_ID_271 };
s32 arcanine_animsounds_hit[] = { SOUND_ID_272 };
s32 arcanine_animsounds_eat[] = { SOUND_ID_270 };
s32 arcanine_animsounds_jump[] = { SOUND_ID_273, SOUND_ID_388 };

AnimationHeader arcanine_animation_idle = {
    0.5,
    135,
    arcanine_modelanim_idle,
    arcanine_matanim_idle,
    NULL
};

AnimationHeader arcanine_animation_roar = {
    0.6,
    135,
    arcanine_modelanim_roar,
    arcanine_matanim_roar,
    arcanine_animsounds_roar
};

AnimationHeader arcanine_animation_walk = {
    0.4,
    40,
    arcanine_modelanim_walk,
    arcanine_matanim_walk,
    NULL
};

AnimationHeader arcanine_animation_run = {
    0.35,
    20,
    arcanine_modelanim_run,
    arcanine_matanim_run,
    NULL
};

AnimationHeader arcanine_animation_hit = {
    0.5,
    40,
    arcanine_modelanim_hit,
    arcanine_matanim_hit,
    arcanine_animsounds_hit
};

AnimationHeader arcanine_animation_eat = {
    0.5,
    90,
    arcanine_modelanim_eat,
    arcanine_matanim_eat,
    arcanine_animsounds_eat
};

AnimationHeader arcanine_animation_shakehead = {
    0.7,
    55,
    arcanine_modelanim_shake_head,
    arcanine_matanim_shake_head,
    NULL
};

AnimationHeader arcanine_animation_jump = {
    0.7,
    85,
    arcanine_modelanim_jump,
    arcanine_matanim_jump,
    arcanine_animsounds_jump
};

InteractionHandler arcanine_tg_Normal[] = {
    { POKEMON_CMD_9, arcanine_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, arcanine_HitByApple, 0, NULL },
    { POKEMON_CMD_10, arcanine_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, arcanine_AppleNearby, 0, NULL },
    { POKEMON_CMD_15, arcanine_SearchApple, 0, NULL },
    { POKEMON_CMD_5, arcanine_Dance, 0, NULL },
    { POKEMON_CMD_6, arcanine_Dance, 0, NULL },
    { POKEMON_CMD_7, arcanine_Dance, 0, NULL },
    { POKEMON_CMD_16, arcanine_RunAwayFromPlayer, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_23, arcanine_PhotoTaken, 60, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler arcanine_tg_SearchApple[] = {
    { POKEMON_CMD_9, arcanine_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, arcanine_HitByApple, 0, NULL },
    { POKEMON_CMD_10, arcanine_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, arcanine_AppleNearby, 0, NULL },
    { POKEMON_CMD_5, arcanine_Dance, 0, NULL },
    { POKEMON_CMD_6, arcanine_Dance, 0, NULL },
    { POKEMON_CMD_7, arcanine_Dance, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler arcanine_tg_WithApple[] = {
    { POKEMON_CMD_9, arcanine_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, arcanine_HitByApple, 0, NULL },
    { POKEMON_CMD_10, arcanine_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, arcanine_AppleNearby, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler arcanine_tg_Hit[] = {
    { POKEMON_CMD_9, arcanine_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, arcanine_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler arcanine_tg_Dance[] = {
    { POKEMON_CMD_9, arcanine_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, arcanine_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler arcanine_tg_Restore[] = {
    { POKEMON_CMD_9, arcanine_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, arcanine_HitByApple, 0, NULL },
    { POKEMON_CMD_15, arcanine_SearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler arcanine_tg_RunAway[] = {
    { POKEMON_CMD_9, arcanine_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, arcanine_HitByApple, 0, NULL },
    { POKEMON_CMD_10, arcanine_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState arcanine_idleStates[] = {
    { 100, arcanine_Idle },
    { 100, arcanine_Walk },
    { 100, arcanine_Run },
    { 100, arcanine_Roar },
    { 0, NULL },
};

f32 arcanine_forbiddenGround[] = { SURFACE_TYPE_7F6633, 0 };

PokemonAnimationSetup arcanine_animSetup = {
    &arcanine_animation_idle,
    arcanine_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData arcanine_initData = {
    arcanine_model,
    arcanine_materials,
    renderPokemonModelTypeIFogged,
    &arcanine_animSetup,
    { 1.4, 1.4, 1.4 },
    { 0, 118, 10 },
    105,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(arcanine_InitialState)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->forbiddenGround = arcanine_forbiddenGround;

    Pokemon_SetAnimation(obj, &arcanine_animation_jump);
    Pokemon_StartPathProc(obj, arcanine_MoveJump);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    pokemon->forbiddenGround = NULL;
    Pokemon_SetAnimation(obj, &arcanine_animation_shakehead);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = arcanine_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, arcanine_Idle);
}

POKEMON_FUNC(arcanine_MoveJump)
    GroundResult result;

    Pokemon_TurnToTarget(obj, TAU, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->hSpeed = 150.0f;

    while (true) {
        volcano_PokemonMove(obj);
        getGroundAt(position->v.x, position->v.z, &result);
        position->v.y = result.height;
        ohWait(1);
    }
}

POKEMON_FUNC(arcanine_Idle)
    Pokemon_SetAnimation(obj, &arcanine_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = arcanine_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, arcanine_idleStates);
}

POKEMON_FUNC(arcanine_Walk)
    Pokemon_SetAnimation(obj, &arcanine_animation_walk);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, arcanine_MoveWalk);
    pokemon->transitionGraph = arcanine_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, arcanine_Idle);
    }

    Pokemon_SetStateRandom(obj, arcanine_idleStates);
}

POKEMON_FUNC(arcanine_MoveWalk)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(arcanine_Run)
    Pokemon_SetAnimation(obj, &arcanine_animation_run);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, arcanine_MoveRun);
    pokemon->transitionGraph = arcanine_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, arcanine_Idle);
    }

    Pokemon_SetStateRandom(obj, arcanine_idleStates);
}

POKEMON_FUNC(arcanine_MoveRun)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(arcanine_Roar)
    Pokemon_ForceAnimation(obj, &arcanine_animation_roar);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = arcanine_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, arcanine_idleStates);
}

POKEMON_FUNC(arcanine_HitByPesterBall)
    Pokemon_SetAnimation(obj, &arcanine_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = arcanine_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, arcanine_Restore);
}

POKEMON_FUNC(arcanine_HitByApple)
    Pokemon_SetAnimation(obj, &arcanine_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = arcanine_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, arcanine_Restore);
}

POKEMON_FUNC(arcanine_AffectedByPesterBall)
    Pokemon_SetAnimation(obj, &arcanine_animation_shakehead);
    Pokemon_StartPathProc(obj, arcanine_TurnToFume);
    pokemon->transitionGraph = arcanine_tg_Hit;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, arcanine_Idle);
}

POKEMON_FUNC(arcanine_TurnToFume)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(arcanine_AppleNearby)
    Pokemon_StartPathProc(obj, arcanine_RunToApple);
    pokemon->transitionGraph = arcanine_tg_SearchApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, arcanine_Idle);
    }

    Pokemon_SetState(obj, arcanine_WithApple);
}

POKEMON_FUNC(arcanine_RunToApple)
    Pokemon_SetAnimation(obj, &arcanine_animation_run);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 250.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(arcanine_WithApple)
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, arcanine_Idle);
    }

    Pokemon_StartPathProc(obj, arcanine_TurnToApple);
    Pokemon_SetAnimation(obj, &arcanine_animation_eat);
    pokemon->transitionGraph = arcanine_tg_WithApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, arcanine_WithApple);
    }

    Pokemon_SetState(obj, arcanine_Restore);
}

POKEMON_FUNC(arcanine_TurnToApple)
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

POKEMON_FUNC(arcanine_SearchApple)
    Pokemon_SetState(obj, arcanine_AppleNearby);
}

POKEMON_FUNC(arcanine_Restore)
    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = arcanine_tg_Restore;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, arcanine_Idle);
}

POKEMON_FUNC(arcanine_Dance)
    Pokemon_SetAnimation(obj, &arcanine_animation_walk);
    Pokemon_StartPathProc(obj, arcanine_TurnToPlayer);
    pokemon->transitionGraph = arcanine_tg_Dance;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, arcanine_Idle);
}

POKEMON_FUNC(arcanine_TurnToPlayer)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(arcanine_RunAwayFromPlayer)
    Pokemon_SetAnimation(obj, &arcanine_animation_run);
    Pokemon_StartPathProc(obj, arcanine_RunAway);
    pokemon->transitionGraph = arcanine_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, arcanine_Idle);
}

POKEMON_FUNC(arcanine_RunAway)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(arcanine_PhotoTaken)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimation(obj, &arcanine_animation_roar);
    pokemon->transitionGraph = arcanine_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, arcanine_idleStates);
}

GObj* arcanine_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &arcanine_initData);
}
