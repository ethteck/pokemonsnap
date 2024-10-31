#include "volcano/volcano.h"

extern AnimCmd* vulpix_modelanim_walk[];
extern AnimCmd* vulpix_modelanim_idle[];
extern AnimCmd* vulpix_modelanim_lie[];
extern AnimCmd* vulpix_modelanim_run[];
extern AnimCmd* vulpix_modelanim_get_up[];
extern AnimCmd* vulpix_modelanim_hit[];
extern AnimCmd* vulpix_modelanim_fall[];
extern AnimCmd* vulpix_modelanim_eat[];

extern AnimCmd** vulpix_matanim_idle[];
extern AnimCmd** vulpix_matanim_lie[];
extern AnimCmd** vulpix_matanim_get_up[];
extern AnimCmd** vulpix_matanim_hit[];
extern AnimCmd** vulpix_matanim_fall[];
extern AnimCmd** vulpix_matanim_eat[];

void vulpix_AppleNearby(GObj*);
void vulpix_InitialState(GObj*);
void vulpix_RunningHitByPesterBall(GObj*);
void vulpix_RunningHit(GObj*);
void vulpix_Walk(GObj*);
void vulpix_Run(GObj*);
void vulpix_HitByPesterBall(GObj*);
void vulpix_HitByApple(GObj*);
void vulpix_RunAlongPath(GObj*);
void vulpix_SearchApple(GObj*);
void vulpix_RunAwayFromPlayer(GObj*);
void vulpix_AffectedByPesterBall(GObj*);
void vulpix_Idle(GObj*);
void vulpix_MoveWalk(GObj*);
void vulpix_MoveRun(GObj*);
void vulpix_Recover(GObj*);
void vulpix_RunToApple(GObj*);
void vulpix_EatApple(GObj*);
void vulpix_TurnToApple(GObj*);
void vulpix_MoveRunAway(GObj*);
void vulpix_MoveRunToPathEnd(GObj*);
void vulpix_IdleAtPathEnd(GObj*);
void vulpix_TurnToPlayer(GObj*);

__ALIGNER2

s32 vulpix_animsounds_fall[] = { SOUND_ID_291 };
s32 vulpix_animsounds_eat[] = { SOUND_ID_292 };

AnimationHeader vulpix_animation_idle = {
    0.4,
    40,
    vulpix_modelanim_idle,
    vulpix_matanim_idle,
    NULL
};

AnimationHeader vulpix_animation_walk = {
    0.8,
    40,
    vulpix_modelanim_walk,
    NULL,
    NULL
};

AnimationHeader vulpix_animation_run = {
    1.2,
    37,
    vulpix_modelanim_run,
    NULL,
    NULL
};

AnimationHeader vulpix_animation_hit = {
    0.5,
    15,
    vulpix_modelanim_hit,
    vulpix_matanim_hit,
    NULL
};

AnimationHeader vulpix_animation_fall = {
    0.7,
    52,
    vulpix_modelanim_fall,
    vulpix_matanim_fall,
    vulpix_animsounds_fall
};

AnimationHeader vulpix_animation_lie = {
    0.5,
    10,
    vulpix_modelanim_lie,
    vulpix_matanim_lie,
    NULL
};

AnimationHeader vulpix_animation_get_up = {
    0.35,
    45,
    vulpix_modelanim_get_up,
    vulpix_matanim_get_up,
    NULL
};

AnimationHeader vulpix_animation_eat = {
    0.5,
    54,
    vulpix_modelanim_eat,
    vulpix_matanim_eat,
    vulpix_animsounds_eat
};

InteractionHandler vulpix_tg_Normal[] = {
    { POKEMON_CMD_9, vulpix_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, vulpix_HitByApple, 0, NULL },
    { POKEMON_CMD_10, vulpix_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, vulpix_AppleNearby, 0, NULL },
    { POKEMON_CMD_15, vulpix_SearchApple, 0, NULL },
    { POKEMON_CMD_16, vulpix_RunAwayFromPlayer, 1000.0 / 3.0, NULL },
    { VOLCANO_CMD_VULPIX_RUN, vulpix_RunAlongPath, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2118_733318[] = {
    { POKEMON_CMD_9, vulpix_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, vulpix_HitByApple, 0, NULL },
    { POKEMON_CMD_10, vulpix_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, vulpix_AppleNearby, 0, NULL },
    { VOLCANO_CMD_VULPIX_RUN, vulpix_RunAlongPath, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler vulpix_tg_Eating[] = {
    { POKEMON_CMD_9, vulpix_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, vulpix_HitByApple, 0, NULL },
    { POKEMON_CMD_10, vulpix_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, vulpix_AppleNearby, 0, NULL },
    { POKEMON_CMD_16, vulpix_RunAwayFromPlayer, 1000.0 / 3.0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler vulpix_tg_Distracted[] = {
    { POKEMON_CMD_9, vulpix_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, vulpix_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2208_733408[] = {
    { POKEMON_CMD_9, vulpix_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, vulpix_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E2238_733438[] = {
    { POKEMON_CMD_9, vulpix_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, vulpix_HitByApple, 0, NULL },
    { POKEMON_CMD_15, vulpix_SearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler vulpix_tg_RunningAway[] = {
    { POKEMON_CMD_9, vulpix_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, vulpix_HitByApple, 0, NULL },
    { POKEMON_CMD_10, vulpix_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, vulpix_AppleNearby, 0, NULL },
    { VOLCANO_CMD_VULPIX_RUN, vulpix_RunAlongPath, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState vulpix_idleStates[] = {
    { 100, vulpix_Idle },
    { 100, vulpix_Walk },
    { 100, vulpix_Run },
    { 0, NULL },
};

Vec3f vulpix_ZeroVector = { 0, 0, 0 };

InteractionHandler vulpix_tg_Running[] = {
    { POKEMON_CMD_9, vulpix_RunningHitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, vulpix_RunningHit, 0, NULL },
    { POKEMON_CMD_10, vulpix_RunningHit, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup vulpix_animSetup = {
    &vulpix_animation_idle,
    vulpix_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData vulpix_initData = {
    vulpix_model,
    vulpix_materials,
    renderPokemonModelTypeIFogged,
    &vulpix_animSetup,
    { 1.7, 1.7, 1.7 },
    { 0, 60, 0 },
    30,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

s32 vulpix_CloseToPathEnd(GObj* obj) {
    Vec3f endPos = vulpix_ZeroVector;
    Pokemon* pokemon = GET_POKEMON(obj);
    WorldBlock* block;
    DObj* model = obj->data.dobj;
    UNUSED s32 pad[1];

    block = getCurrentWorldBlock();
    GetInterpolatedPosition(&endPos, pokemon->path, 0.99999f);
    pokemon->pos1.x = (endPos.x - block->descriptor->worldPos.x) * 100.0f;
    pokemon->pos1.z = (endPos.z - block->descriptor->worldPos.z) * 100.0f;

    if (SQ(pokemon->pos1.x - GET_TRANSFORM(model)->pos.v.x) + SQ(pokemon->pos1.z - GET_TRANSFORM(model)->pos.v.z) < SQ(1000.0f)) {
        return true;
    } else {
        return false;
    }
}

POKEMON_FUNC(vulpix_SendRunCommand)
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    while (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_1000)) {
        if (vulpix_CloseToPathEnd(obj)) {
            cmdSendCommand(obj, VOLCANO_CMD_VULPIX_RUN, obj);
        }
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(vulpix_DeleteLater)
    s32 blockIndex;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockIndex, &blockPart);
        if (blockIndex > 4 || blockIndex == 4 && blockPart >= 0.1) {
            break;
        }
        ohWait(1);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(vulpix_InitialState)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->miscVars[1].field1 = false;

    Pokemon_StartAuxProc(obj, vulpix_SendRunCommand);
    Pokemon_StartAuxProc(obj, vulpix_DeleteLater);

    Pokemon_SetState(obj, vulpix_Idle);
}

static void nullsub() {
}

POKEMON_FUNC(vulpix_Idle)
    Pokemon_SetAnimation(obj, &vulpix_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = vulpix_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, vulpix_idleStates);
}

POKEMON_FUNC(vulpix_Walk)
    Pokemon_SetAnimation(obj, &vulpix_animation_walk);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, vulpix_MoveWalk);
    pokemon->transitionGraph = vulpix_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, vulpix_Idle);
    }

    Pokemon_SetStateRandom(obj, vulpix_idleStates);
}

POKEMON_FUNC(vulpix_MoveWalk)
    pokemon->hSpeed = 40.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(vulpix_Run)
    Pokemon_SetAnimation(obj, &vulpix_animation_run);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, vulpix_MoveRun);
    pokemon->transitionGraph = vulpix_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, vulpix_Idle);
    }

    Pokemon_SetStateRandom(obj, vulpix_idleStates);
}

POKEMON_FUNC(vulpix_MoveRun)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(vulpix_HitByPesterBall)
    Pokemon_SetAnimation(obj, &vulpix_animation_fall);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &vulpix_animation_lie);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &vulpix_animation_get_up);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, vulpix_Recover);
}

POKEMON_FUNC(vulpix_HitByApple)
    Pokemon_SetAnimation(obj, &vulpix_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, vulpix_Recover);
}

POKEMON_FUNC(vulpix_AffectedByPesterBall)
    Pokemon_SetAnimation(obj, &vulpix_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = vulpix_tg_Distracted;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, vulpix_Idle);
}

POKEMON_FUNC(vulpix_AppleNearby)
    Pokemon_StartPathProc(obj, vulpix_RunToApple);
    pokemon->transitionGraph = D_802E2118_733318;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, vulpix_Idle);
    }

    Pokemon_SetState(obj, vulpix_EatApple);
}

POKEMON_FUNC(vulpix_RunToApple)
    Pokemon_SetAnimation(obj, &vulpix_animation_run);
    pokemon->hSpeed = 160.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(vulpix_EatApple)
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, vulpix_Idle);
    }

    Pokemon_SetAnimation(obj, &vulpix_animation_eat);
    Pokemon_StartPathProc(obj, vulpix_TurnToApple);
    pokemon->transitionGraph = vulpix_tg_Eating;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, vulpix_EatApple);
    }

    Pokemon_SetState(obj, vulpix_Recover);
}

POKEMON_FUNC(vulpix_TurnToApple)
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

POKEMON_FUNC(vulpix_SearchApple)
    Pokemon_SetState(obj, vulpix_AppleNearby);
}

POKEMON_FUNC(vulpix_Recover)
    pokemon->apple = NULL;
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802E2238_733438;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, vulpix_Idle);
}

static void nullsub2() {
}

POKEMON_FUNC(vulpix_unused_TurnToPlayer)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(vulpix_RunAwayFromPlayer)
    Pokemon_SetAnimation(obj, &vulpix_animation_run);
    Pokemon_StartPathProc(obj, vulpix_MoveRunAway);
    pokemon->transitionGraph = vulpix_tg_RunningAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED) {
        Pokemon_SetState(obj, vulpix_Idle);
    }

    pokemon->transitionGraph = vulpix_tg_RunningAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, vulpix_Idle);
}

POKEMON_FUNC(vulpix_MoveRunAway)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayFromTarget(obj, 1000.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(vulpix_RunAlongPath)
    pokemon->flags &= ~POKEMON_FLAG_200;
    pokemon->flags &= ~POKEMON_FLAG_800;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;

    Pokemon_SetAnimation(obj, &vulpix_animation_run);
    pokemon->hSpeed = 160.0f;
    Pokemon_StartPathProc(obj, vulpix_MoveRunToPathEnd);
    pokemon->transitionGraph = vulpix_tg_Running;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, vulpix_IdleAtPathEnd);
}

POKEMON_FUNC(vulpix_MoveRunToPathEnd)
    Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(vulpix_IdleAtPathEnd)
    Pokemon_SetAnimation(obj, &vulpix_animation_eat);
    if (!pokemon->miscVars[1].field1) {
        pokemon->miscVars[1].field1 = true;
        Pokemon_StartPathProc(obj, vulpix_TurnToPlayer);
    }
    pokemon->transitionGraph = vulpix_tg_Running;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, vulpix_IdleAtPathEnd);
}

POKEMON_FUNC(vulpix_TurnToPlayer)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(vulpix_RunningHitByPesterBall)
    Pokemon_SetAnimation(obj, &vulpix_animation_fall);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &vulpix_animation_lie);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &vulpix_animation_get_up);
    pokemon->transitionGraph = vulpix_tg_Running;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, vulpix_RunAlongPath);
}

POKEMON_FUNC(vulpix_RunningHit)
    Pokemon_SetAnimation(obj, &vulpix_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, vulpix_RunAlongPath);
}

GObj* vulpix_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &vulpix_initData);
}
