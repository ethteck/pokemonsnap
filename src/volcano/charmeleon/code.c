#include "volcano/volcano.h"

#define CHARMELEON_0 0
#define CHARMELEON_PATH_PARAM 3
#define CHARMELEON_PATH_END 4
#define CHARMELEON_PATH_SPEED 5
#define CHARMELEON_TARGET_SET 6

extern AnimCmd* charmeleon_modelanim_walk[];
extern AnimCmd* charmeleon_modelanim_run[];
extern AnimCmd* charmeleon_modelanim_idle[];
extern AnimCmd* charmeleon_modelanim_lie[];
extern AnimCmd* charmeleon_modelanim_lookaround[];
extern AnimCmd* charmeleon_modelanim_roar[];
extern AnimCmd* charmeleon_modelanim_getup[];
extern AnimCmd* charmeleon_modelanim_hit[];
extern AnimCmd* charmeleon_modelanim_fall[];

extern AnimCmd** charmeleon_matanim_walk[];
extern AnimCmd** charmeleon_matanim_run[];
extern AnimCmd** charmeleon_matanim_idle[];
extern AnimCmd** charmeleon_matanim_lie[];
extern AnimCmd** charmeleon_matanim_lookaround[];
extern AnimCmd** charmeleon_matanim_roar[];
extern AnimCmd** charmeleon_matanim_getup[];
extern AnimCmd** charmeleon_matanim_hit[];
extern AnimCmd** charmeleon_matanim_fall[];

GObj* charmeleon_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
void charmeleon_InitialState(GObj*);
void charmeleon_EvolvedHitByPesterBall(GObj*);
void charmeleon_EvolvedHit(GObj*);
void charmeleon_EvolvedSearchApple(GObj*);
void charmeleon_EvolvedWalk(GObj*);
void charmeleon_EvolvedRun(GObj*);
void charmeleon_Walk(GObj*);
void charmeleon_Run(GObj*);
void charmeleon_LookAround(GObj*);
void charmeleon_Roar(GObj*);
void charmeleon_HitByPesterBall(GObj*);
void charmeleon_HitByApple(GObj*);
void charmeleon_EvolveIntoCharizard(GObj*);
void charmeleon_BounceOfPesterBall(GObj*);
void charmeleon_BounceOfApple(GObj*);
void charmeleon_Idle(GObj*);
void charmeleon_EvolvedIdle(GObj*);
void charmeleon_EvolvedInit(GObj*);
void charmeleon_FollowPath(GObj*);
void charmeleon_BounceBack(GObj*);
void charmeleon_Return(GObj*);
void charmeleon_BounceBack(GObj*);
void charmeleon_RunToOrigPos(GObj*);
void charmeleon_StepToOrigPos(GObj*);
void func_802D6CC0_727EC0(GObj*);
void charmeleon_DiveInLava(GObj*);
void charmeleon_EvolvedMoveWalk(GObj*);
void charmeleon_EvolvedMoveRun(GObj*);
void charmeleon_EvolvedWithApple(GObj*);
void charmeleon_EvolvedRunToApple(GObj*);
void charmeleon_EvolvedTurnToApple(GObj*);

s32 charmeleon_animsounds_roar[] = { SOUND_ID_288 };
s32 charmeleon_animsounds_hit[] = { SOUND_ID_289 };
s32 charmeleon_animsounds_getup[] = { SOUND_ID_290 };

AnimationHeader charmeleon_animation_idle = {
    0.6,
    60,
    charmeleon_modelanim_idle,
    charmeleon_matanim_idle,
    NULL
};

AnimationHeader charmeleon_animation_roar = {
    0.8,
    100,
    charmeleon_modelanim_roar,
    charmeleon_matanim_roar,
    charmeleon_animsounds_roar
};

AnimationHeader charmeleon_animation_lookaround = {
    0.7,
    105,
    charmeleon_modelanim_lookaround,
    charmeleon_matanim_lookaround,
    NULL
};

AnimationHeader charmeleon_animation_walk = {
    0.69,
    40,
    charmeleon_modelanim_walk,
    charmeleon_matanim_walk,
    NULL
};

AnimationHeader charmeleon_animation_run = {
    0.75,
    16,
    charmeleon_modelanim_run,
    charmeleon_matanim_run,
    NULL
};

AnimationHeader charmeleon_animation_hit = {
    1.1,
    100,
    charmeleon_modelanim_hit,
    charmeleon_matanim_hit,
    charmeleon_animsounds_hit
};

AnimationHeader charmeleon_animation_fall = {
    1.17,
    120,
    charmeleon_modelanim_fall,
    charmeleon_matanim_fall,
    NULL
};

AnimationHeader charmeleon_animation_lie = {
    1.0,
    75,
    charmeleon_modelanim_lie,
    charmeleon_matanim_lie,
    NULL
};

AnimationHeader charmeleon_animation_getup = {
    0.7,
    145,
    charmeleon_modelanim_getup,
    charmeleon_matanim_getup,
    charmeleon_animsounds_getup
};

InteractionHandler charmeleon_tg_Bounce[] = {
    { POKEMON_CMD_9, charmeleon_BounceOfPesterBall, 0, NULL },
    { POKEMON_CMD_13, charmeleon_BounceOfApple, 0, NULL },
    { VOLCANO_CMD_29, charmeleon_EvolveIntoCharizard, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmeleon_tg_Lying[] = {
    { VOLCANO_CMD_29, charmeleon_EvolveIntoCharizard, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmeleon_tg_Normal[] = {
    { POKEMON_CMD_9, charmeleon_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, charmeleon_HitByApple, 0, NULL },
    { VOLCANO_CMD_29, charmeleon_EvolveIntoCharizard, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState charmeleon_idleStates[] = {
    { 1, charmeleon_Walk },
    { 1, charmeleon_Run },
    { 1, charmeleon_Idle },
    { 1, charmeleon_LookAround },
    { 1, charmeleon_Roar },
    { 0, NULL },
};

RandomState charmeleon_moveStates[] = {
    { 1, charmeleon_Walk },
    { 1, charmeleon_Run },
    { 0, NULL },
};

RandomState charmeleon_stopStates[] = {
    { 1, charmeleon_LookAround },
    { 1, charmeleon_Roar },
    { 0, NULL },
};

f32 charmeleon_forbiddenGround[] = { 0 };

InteractionHandler charmeleon_tg_evolved_Normal[] = {
    { POKEMON_CMD_9, charmeleon_EvolvedHitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, charmeleon_EvolvedHit, 0, NULL },
    { POKEMON_CMD_10, charmeleon_EvolvedHit, 0, NULL },
    { POKEMON_CMD_14, charmeleon_EvolvedSearchApple, 0, NULL },
    { POKEMON_CMD_15, charmeleon_EvolvedSearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState charmeleon_evolved_idleStates[] = {
    { 100, charmeleon_EvolvedIdle },
    { 100, charmeleon_EvolvedWalk },
    { 100, charmeleon_EvolvedRun },
    { 0, NULL },
};

InteractionHandler charmeleon_tg_evolved_Hit[] = {
    { POKEMON_CMD_9, charmeleon_EvolvedHitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, charmeleon_EvolvedHit, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmeleon_tg_evolved_SearchApple[] = {
    { POKEMON_CMD_9, charmeleon_EvolvedHitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, charmeleon_EvolvedHit, 0, NULL },
    { POKEMON_CMD_10, charmeleon_EvolvedHit, 0, NULL },
    { POKEMON_CMD_14, charmeleon_EvolvedSearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charmeleon_tg_evolved_WithApple[] = {
    { POKEMON_CMD_9, charmeleon_EvolvedHitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, charmeleon_EvolvedHit, 0, NULL },
    { POKEMON_CMD_10, charmeleon_EvolvedHit, 0, NULL },
    { POKEMON_CMD_14, charmeleon_EvolvedSearchApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup charmeleon_animSetup = {
    &charmeleon_animation_idle,
    charmeleon_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData charmeleon_initData = {
    charmeleon_model,
    charmeleon_materials,
    renderPokemonModelTypeJFogged,
    &charmeleon_animSetup,
    { 1.8, 1.8, 1.8 },
    { 0, 166, -2.6 },
    53,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(charmeleon_DeleteLater)
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

POKEMON_FUNC(charmeleon_InitialState)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, charmeleon_EvolvedInit);
    }
    pokemon->forbiddenGround = charmeleon_forbiddenGround;
    pokemon->miscVars[CHARMELEON_PATH_PARAM].field0 = 0.0f;
    Pokemon_SetStateRandom(obj, charmeleon_idleStates);
}

POKEMON_FUNC(charmeleon_Walk)
    pokemon->miscVars[CHARMELEON_PATH_SPEED].field0 = 0.04f;
    Pokemon_ResetPathPos(obj);
    Pokemon_SetAnimation(obj, &charmeleon_animation_walk);
    Pokemon_StartPathProc(obj, charmeleon_FollowPath);
    pokemon->transitionGraph = charmeleon_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetStateRandom(obj, charmeleon_idleStates);
}

POKEMON_FUNC(charmeleon_Run)
    pokemon->miscVars[CHARMELEON_PATH_SPEED].field0 = 0.08f;
    Pokemon_ResetPathPos(obj);
    Pokemon_SetAnimation(obj, &charmeleon_animation_run);
    Pokemon_StartPathProc(obj, charmeleon_FollowPath);
    pokemon->transitionGraph = charmeleon_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetStateRandom(obj, charmeleon_idleStates);
}

POKEMON_FUNC(charmeleon_FollowPath)
    if (pokemon->miscVars[CHARMELEON_PATH_PARAM].field0 < 0.7) {
        pokemon->miscVars[CHARMELEON_PATH_END].field0 = pokemon->miscVars[CHARMELEON_PATH_PARAM].field0 + 0.3 + randFloat() * 0.3;
        if (pokemon->miscVars[CHARMELEON_PATH_END].field0 > 1.0f) {
            pokemon->miscVars[CHARMELEON_PATH_END].field0 = 1.0f;
        }
    } else {
        pokemon->miscVars[CHARMELEON_PATH_END].field0 = 1.0f;
    }

    func_802D6F68_728168(obj, &pokemon->miscVars[CHARMELEON_PATH_PARAM].field0,
                         pokemon->miscVars[CHARMELEON_PATH_END].field0,
                         pokemon->miscVars[CHARMELEON_PATH_SPEED].field0, 3);

    if (pokemon->miscVars[CHARMELEON_PATH_END].field0 == 1.0f) {
        pokemon->miscVars[CHARMELEON_PATH_PARAM].field0 = 0.0f;
    }

    if (pokemon->miscVars[CHARMELEON_PATH_PARAM].field0 > 1.0f) {
        pokemon->miscVars[CHARMELEON_PATH_PARAM].field0 -= 1.0f;
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmeleon_LookAround)
    Pokemon_ForceAnimation(obj, &charmeleon_animation_lookaround);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charmeleon_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charmeleon_moveStates);
}

POKEMON_FUNC(charmeleon_Roar)
    Pokemon_ForceAnimation(obj, &charmeleon_animation_roar);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charmeleon_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charmeleon_moveStates);
}

POKEMON_FUNC(charmeleon_Idle)
    Pokemon_SetAnimation(obj, &charmeleon_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charmeleon_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charmeleon_moveStates);
}

POKEMON_FUNC(charmeleon_BounceOfApple)
    Pokemon_SetAnimation(obj, &charmeleon_animation_hit);
    Pokemon_StartPathProc(obj, charmeleon_BounceBack);
    pokemon->transitionGraph = charmeleon_tg_Bounce;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (obj && obj && obj) {
    } // TODO fake match

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = charmeleon_tg_Lying;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, charmeleon_Return);
}

POKEMON_FUNC(charmeleon_BounceOfPesterBall)
    Pokemon_SetAnimation(obj, &charmeleon_animation_hit);
    Pokemon_StartPathProc(obj, charmeleon_BounceBack);
    pokemon->transitionGraph = charmeleon_tg_Bounce;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = charmeleon_tg_Lying;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetAnimation(obj, &charmeleon_animation_fall);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &charmeleon_animation_lie);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &charmeleon_animation_getup);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charmeleon_Return);
}

POKEMON_FUNC(charmeleon_BounceBack)
    pokemon->hSpeed = 300.0f;
    pokemon->jumpVel = 150.0f;
    // TODO check it's an item
    pokemon->facingYaw = atan2f(GET_ITEM(pokemon->interactionTarget)->collisionVelocity.x, GET_ITEM(pokemon->interactionTarget)->collisionVelocity.z);
    Pokemon_FallDownOnGround(obj, -9.8f, true);

    if (pokemon->currGround.surfaceType == SURFACE_TYPE_FF4C19) {
        cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_28, obj);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmeleon_HitByPesterBall)
    pokemon->pos1.x = position->v.x;
    pokemon->pos1.y = position->v.y;
    pokemon->pos1.z = position->v.z;
    pokemon->miscVars[CHARMELEON_TARGET_SET].field1 = 0;
    Pokemon_SetState(obj, charmeleon_BounceOfPesterBall);
}

POKEMON_FUNC(charmeleon_HitByApple)
    pokemon->pos1.x = position->v.x;
    pokemon->pos1.y = position->v.y;
    pokemon->pos1.z = position->v.z;
    pokemon->miscVars[CHARMELEON_TARGET_SET].field1 = 0;
    Pokemon_SetState(obj, charmeleon_BounceOfApple);
}

POKEMON_FUNC(charmeleon_Return)
    Pokemon_SetAnimation(obj, &charmeleon_animation_run);
    Pokemon_StartPathProc(obj, charmeleon_RunToOrigPos);
    pokemon->miscVars[CHARMELEON_0].field1 = 0;
    Pokemon_SetState(obj, charmeleon_StepToOrigPos);
}

POKEMON_FUNC(charmeleon_StepToOrigPos)
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = charmeleon_tg_Bounce;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->currGround.surfaceType == SURFACE_TYPE_FF4C19) {
        pokemon->miscVars[CHARMELEON_0].field1++;
        // 10 steps on lava
        if (pokemon->miscVars[CHARMELEON_0].field1 > 10) {
            cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_28, obj);
        }
    } else {
        pokemon->miscVars[CHARMELEON_0].field1 = 0;
    }

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, charmeleon_StepToOrigPos);
    }
    Pokemon_SetStateRandom(obj, charmeleon_stopStates);
}

POKEMON_FUNC(charmeleon_RunToOrigPos)
    if (!pokemon->miscVars[CHARMELEON_TARGET_SET].field1) {
        Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
        pokemon->miscVars[CHARMELEON_TARGET_SET].field1 = true;
    }
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmeleon_EvolveIntoCharizard)
    omCreateProcess(obj, func_802D6CC0_727EC0, 1, 1);
    obj->flags |= GOBJ_FLAG_2;
    Pokemon_StartPathProc(obj, charmeleon_DiveInLava);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    func_802D6A5C_727C5C(obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(charmeleon_DiveInLava)
    Mtx3Float* targetPos = &GET_TRANSFORM(pokemon->interactionTarget->data.dobj)->pos;
    f32 dx, dz;
    s32 i;

    dx = (targetPos->v.x - position->v.x) / 100.0f;
    dz = (targetPos->v.z - position->v.z) / 100.0f;

    for (i = 0; i < 100; i++) {
        position->v.x += dx;
        position->v.z += dz;
        position->v.y -= 6.0f;
        rotation->f[2] += PI / 180.0f;
        ohWait(1);
    }

    pokemon->pathProc = FALSE;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmeleon_EvolvedInit)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    Pokemon_StartAuxProc(obj, charmeleon_DeleteLater);
    Pokemon_SetAnimation(obj, &charmeleon_animation_getup);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charmeleon_EvolvedIdle);
}

POKEMON_FUNC(charmeleon_EvolvedIdle)
    Pokemon_SetAnimation(obj, &charmeleon_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charmeleon_tg_evolved_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, charmeleon_evolved_idleStates);
}

POKEMON_FUNC(charmeleon_EvolvedWalk)
    Pokemon_SetAnimation(obj, &charmeleon_animation_walk);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, charmeleon_EvolvedMoveWalk);
    pokemon->transitionGraph = charmeleon_tg_evolved_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, charmeleon_EvolvedIdle);
    }

    Pokemon_SetStateRandom(obj, charmeleon_evolved_idleStates);
}

POKEMON_FUNC(charmeleon_EvolvedMoveWalk)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmeleon_EvolvedRun)
    Pokemon_SetAnimation(obj, &charmeleon_animation_run);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, charmeleon_EvolvedMoveRun);
    pokemon->transitionGraph = charmeleon_tg_evolved_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, charmeleon_EvolvedIdle);
    }

    Pokemon_SetStateRandom(obj, charmeleon_evolved_idleStates);
}

POKEMON_FUNC(charmeleon_EvolvedMoveRun)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmeleon_EvolvedHitByPesterBall)
    InteractionHandler saved[3] = charmeleon_tg_evolved_Hit;

    Pokemon_SetAnimation(obj, &charmeleon_animation_fall);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &charmeleon_animation_lie);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &charmeleon_animation_getup);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charmeleon_EvolvedIdle);
}

POKEMON_FUNC(charmeleon_EvolvedHit)
    Pokemon_SetAnimation(obj, &charmeleon_animation_hit);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charmeleon_EvolvedIdle);
}

POKEMON_FUNC(charmeleon_EvolvedSearchApple)
    Pokemon_StartPathProc(obj, charmeleon_EvolvedRunToApple);
    pokemon->transitionGraph = charmeleon_tg_evolved_SearchApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, charmeleon_EvolvedIdle);
    }

    Pokemon_SetState(obj, charmeleon_EvolvedWithApple);
}

POKEMON_FUNC(charmeleon_EvolvedRunToApple)
    Pokemon_SetAnimation(obj, &charmeleon_animation_run);
    pokemon->hSpeed = randFloat() * 80.0f * 0.6 + 80.0;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(charmeleon_EvolvedWithApple)
    InteractionHandler saved[5] = charmeleon_tg_evolved_WithApple;

    Pokemon_ForceAnimation(obj, &charmeleon_animation_roar);
    Pokemon_StartPathProc(obj, charmeleon_EvolvedTurnToApple);
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, charmeleon_EvolvedWithApple);
    }

    Pokemon_SetState(obj, charmeleon_EvolvedIdle);
}

POKEMON_FUNC(charmeleon_EvolvedTurnToApple)
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

GObj* charmeleon_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &charmeleon_initData);
}

void charmeleon_EvolvedSpawn(GObj* obj) {
    PokemonDef def = {
        PokemonID_CHARMELEON,
        charmeleon_Spawn,
        pokemonChangeBlockOnGround,
        pokemonRemoveOne
    };
    GObj* var;
    DObj* newModel;

    var = Pokemon_AddAtGeo(obj, PokemonID_1030, &def);
    GET_POKEMON(var)->behavior = 1;
    GET_POKEMON(var)->path = GET_POKEMON(obj)->path;
    newModel = var->data.dobj;
    GET_TRANSFORM(newModel)->rot.f[2] = GET_TRANSFORM(obj->data.dobj)->rot.f[2];
}
