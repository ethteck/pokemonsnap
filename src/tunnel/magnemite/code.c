#include "../tunnel.h"

#define MAGNEMITE_VAR_ATTRACTED_OBJ 0
#define MAGNEMITE_VAR_IS_ATTRACTED 1
#define MAGNEMITE_VAR_COLLISION_RADIUS 2

extern AnimCmd* magnemite_modelanim_move[];
extern AnimCmd* magnemite_modelanim_idle[];
extern AnimCmd* magnemite_modelanim_pulse[];
extern AnimCmd* magnemite_modelanim_run[];
extern AnimCmd* magnemite_modelanim_hit[];
extern AnimCmd* magnemite_modelanim_react[];

extern AnimCmd** magnemite_matanim_pulse[];

void magnemite_HitByPesterBall(GObj*);
void magnemite_AppleNearby(GObj*);
void magnemite_FindNeighbours(GObj*);
void magnemite_Idle(GObj*);
void magnemite_RecoverFromHit(GObj*);
void magnemite_WithApple(GObj*);
void magnemite_MoveToApple(GObj*);
void magnemite_TurnToPlayer(GObj*);
void magnemite_RunAwayFromPlayer(GObj*);
void magnemite_MoveToAttractedMagnemite(GObj*);
void magnemite_WaitForLeader(GObj*);
void magnemite_CopyLeaderMovement(GObj*);
void magnemite_CopyLeaderBehavior(GObj*);
void magnemite_Delete(GObj*);
void magnemite_AllMagnemitesCombined(GObj*);
void magnemite_PlayerApproaching(GObj*);
void magnemite_Attract(GObj*);
void magnemite_ZoomedIn(GObj*);
void magnemite_InitialState(GObj*);
void magnemite_HitByApple(GObj*);
void magnemite_AffectedByPesterBall(GObj*);
void magnemite_SearchApple(GObj*);
void magnemite_WaitToDelete(GObj*);
void magnemite_HitByPesterBall_SendToLeader(GObj*);
void magnemite_HitByApple_SendToLeader(GObj*);
void magnemite_EvolveIntoMagneton(GObj*);

s32 magnemite_animsounds_pulse[] = { SOUND_ID_220 };
s32 magnemite_animsounds_hit[] = { SOUND_ID_221 };
s32 magnemite_animsounds_react[] = { SOUND_ID_222 };

AnimationHeader magnemite_animation_move = {
    1.0,
    60,
    magnemite_modelanim_move,
    NULL,
    NULL
};

AnimationHeader magnemite_animation_idle = {
    0.6,
    80,
    magnemite_modelanim_idle,
    NULL,
    NULL
};

AnimationHeader magnemite_animation_pulse = {
    1.0,
    60,
    magnemite_modelanim_pulse,
    magnemite_matanim_pulse,
    magnemite_animsounds_pulse
};

AnimationHeader magnemite_animation_run = {
    1.0,
    60,
    magnemite_modelanim_run,
    NULL,
    NULL
};

AnimationHeader magnemite_animation_hit = {
    0.7,
    60,
    magnemite_modelanim_hit,
    NULL,
    magnemite_animsounds_hit
};

AnimationHeader magnemite_animation_react = {
    0.85,
    104,
    magnemite_modelanim_react,
    NULL,
    magnemite_animsounds_react
};

GObj* magnemite_FirstMagnemite = NULL;
GObj* magnemite_SecondMagnemite = NULL;
GObj* magnemite_ThirdMagnemite = NULL;
GObj* magnemite_GroupLeader = NULL;
GObj* D_802EE294_5EB364 = NULL;

s32 D_802EE298_5EB368 = 0;

AnimationHeader* magnemite_GroupLeaderAnimation = NULL;

s32 magnemite_NumConnected = 0;

InteractionHandler magnemite_tg_Idle[] = {
    { POKEMON_CMD_9, magnemite_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magnemite_HitByApple, 0, NULL },
    { POKEMON_CMD_10, magnemite_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, magnemite_AppleNearby, 0, NULL },
    { POKEMON_CMD_15, magnemite_SearchApple, 0, NULL },
    { POKEMON_CMD_16, magnemite_PlayerApproaching, 250, NULL },
    { TUNNEL_CMD_MAGNEMITE_ZOOMED_IN, magnemite_ZoomedIn, 1000, NULL },
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState magnemite_idleStates[] = {
    { 100, magnemite_Idle },
    { 0, NULL },
};

InteractionHandler magnemite_tg_HitByPesterBall[] = {
    { TUNNEL_CMD_MAGNEMITE_ZOOMED_IN, magnemite_ZoomedIn, 1000, NULL },
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magnemite_tg_HitByApple[] = {
    { TUNNEL_CMD_MAGNEMITE_ZOOMED_IN, magnemite_ZoomedIn, 1000, NULL },
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802EE3D4_5EB4A4[] = {
    { POKEMON_CMD_9, magnemite_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magnemite_HitByApple, 0, NULL },
    { POKEMON_CMD_10, magnemite_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_14, magnemite_AppleNearby, 0, NULL },
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_16, magnemite_PlayerApproaching, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magnemite_tg_WithApple[] = {
    { POKEMON_CMD_9, magnemite_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_13, magnemite_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_14, magnemite_AppleNearby, 0, NULL },
    { POKEMON_CMD_16, magnemite_PlayerApproaching, 250, NULL },
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magnemite_tg_RunAway[] = {
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magnemite_tg_ZoomedInStage1[] = {
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magnemite_tg_ZoomedInStage2[] = {
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_16, magnemite_PlayerApproaching, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magnemite_tg_ZoomedInStage3[] = {
    { TUNNEL_CMD_MAGNEMITE_ZOOMED_IN, magnemite_ZoomedIn, 1000, NULL },
    { TUNNEL_CMD_MAGNEMITE_ATTRACT, magnemite_Attract, 0, NULL },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_AllMagnemitesCombined, 0, NULL },
    { POKEMON_CMD_16, magnemite_PlayerApproaching, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(magnemite_ProcessZoomIn)
    while (true) {
        if (gDirectionIndex < 0) {
            cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_MAGNEMITE_ZOOMED_IN, obj);
        }
        ohWait(1);
    }
}

POKEMON_FUNC(magnemite_InitialState)
    pokemon->miscVars[3].field1 = 0;
    pokemon->miscVars[MAGNEMITE_VAR_ATTRACTED_OBJ].obj = NULL;
    pokemon->miscVars[MAGNEMITE_VAR_IS_ATTRACTED].field1 = false;
    pokemon->miscVars[MAGNEMITE_VAR_COLLISION_RADIUS].field0 = pokemon->collisionRadius;
    Pokemon_StartAuxProc(obj, magnemite_FindNeighbours);

    switch (pokemon->behavior) {
        case 1:
            Pokemon_StartAuxProc(obj, magnemite_ProcessZoomIn);
            magnemite_FirstMagnemite = obj;
            break;
        case 2:
            magnemite_SecondMagnemite = obj;
            break;
        case 3:
            magnemite_ThirdMagnemite = obj;
            break;
    }

    Pokemon_SetState(obj, magnemite_Idle);
}

POKEMON_FUNC(magnemite_Idle)
    pokemon->collisionRadius = pokemon->miscVars[MAGNEMITE_VAR_COLLISION_RADIUS].field0;
    Pokemon_SetAnimation(obj, &magnemite_animation_idle);
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_idle;
    }
    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magnemite_tg_Idle;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->miscVars[3].field1 = 0;
    pokemon->transitionGraph = magnemite_tg_Idle;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, magnemite_idleStates);
}

POKEMON_FUNC(magnemite_HitByPesterBall)
    Pokemon_SetAnimation(obj, &magnemite_animation_hit);
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_hit;
    }
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = magnemite_tg_HitByPesterBall;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, magnemite_RecoverFromHit);
}

POKEMON_FUNC(magnemite_HitByApple)
    Pokemon_SetAnimation(obj, &magnemite_animation_hit);
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_hit;
    }
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = magnemite_tg_HitByApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, magnemite_Idle);
}

POKEMON_FUNC(magnemite_AffectedByPesterBall)
    Pokemon_SetState(obj, magnemite_HitByPesterBall);
}

POKEMON_FUNC(magnemite_AppleNearby)
    pokemon->flags &= ~POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &magnemite_animation_move);
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_move;
    }
    Pokemon_StartPathProc(obj, magnemite_MoveToApple);
    pokemon->transitionGraph = D_802EE3D4_5EB4A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->currGround.surfaceType == SURFACE_TYPE_337FB2) {
        Pokemon_SetState(obj, magnemite_Idle);
    }
    Pokemon_SetState(obj, magnemite_WithApple);
}

POKEMON_FUNC(magnemite_MoveToApple)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    // clang-format off
    Pokemon_SetAnimation(obj, &magnemite_animation_run); \
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_run;
    }
    // clang-format on
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magnemite_SearchApple)
    Pokemon_SetState(obj, magnemite_AppleNearby);
}

POKEMON_FUNC(magnemite_WithApple)
    Pokemon_SetAnimation(obj, &magnemite_animation_react);
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_react;
    }

    pokemon->transitionGraph = magnemite_tg_WithApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, magnemite_WithApple);
    }

    Pokemon_SetStateRandom(obj, magnemite_idleStates);
}

POKEMON_FUNC(magnemite_RecoverFromHit)
    Pokemon_StartPathProc(obj, magnemite_TurnToPlayer);
    Pokemon_SetAnimation(obj, &magnemite_animation_pulse);
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_pulse;
    }
    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magnemite_tg_Idle;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, magnemite_Idle);
}

POKEMON_FUNC(magnemite_TurnToPlayer)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magnemite_PlayerApproaching)
    pokemon->flags |= POKEMON_FLAG_8;
    if (pokemon->miscVars[3].field1 >= 5) {
        pokemon->collisionRadius = 0.0f;
    } else {
        pokemon->miscVars[3].field1++;
    }
    Pokemon_SetAnimation(obj, &magnemite_animation_pulse);
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_pulse;
    }
    Pokemon_StartPathProc(obj, magnemite_RunAwayFromPlayer);
    pokemon->transitionGraph = magnemite_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED) {
        Pokemon_SetState(obj, magnemite_Idle);
    }
    // clang-format off
    pokemon->transitionGraph = magnemite_tg_RunAway; \
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    // clang-format on

    Pokemon_SetState(obj, magnemite_Idle);
}

POKEMON_FUNC(magnemite_RunAwayFromPlayer)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayDefault(obj, 1000.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magnemite_ZoomedIn)
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_StartPathProc(obj, magnemite_TurnToPlayer);
    Pokemon_SetAnimation(obj, &magnemite_animation_pulse);
    if (obj == magnemite_GroupLeader) {
        magnemite_GroupLeaderAnimation = &magnemite_animation_pulse;
    }

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magnemite_tg_ZoomedInStage1;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magnemite_tg_ZoomedInStage2;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magnemite_tg_ZoomedInStage3;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, magnemite_Idle);
}

POKEMON_FUNC(magnemite_FindNeighbours)
    s32 i;
    bool neighbour_found = false;
    s32 unused;
    GObj** pokemons[] = { &magnemite_FirstMagnemite, &magnemite_SecondMagnemite, &magnemite_ThirdMagnemite };

    while (!neighbour_found) {
        if (magnemite_GroupLeader == NULL) {
            for (i = 0; i < ARRAY_COUNT(pokemons); i++) {
                GObj* curObj = *(pokemons[i]);
                if (obj != curObj && curObj != NULL && Pokemon_GetDistance(obj, curObj) < 300.0f) {
                    magnemite_GroupLeader = obj;
                    pokemon->miscVars[MAGNEMITE_VAR_ATTRACTED_OBJ].obj = curObj;
                    neighbour_found = true;
                    GET_POKEMON(curObj)->miscVars[MAGNEMITE_VAR_ATTRACTED_OBJ].obj = obj;
                }
            }
        } else if (pokemon->miscVars[MAGNEMITE_VAR_ATTRACTED_OBJ].obj != NULL) {
            neighbour_found = true;
            while (!pokemon->miscVars[MAGNEMITE_VAR_IS_ATTRACTED].field1) {
                cmdSendCommand(obj, TUNNEL_CMD_MAGNEMITE_ATTRACT, obj);
                ohWait(1);
            }
        } else if (Pokemon_GetDistance(magnemite_GroupLeader, obj) < 300.0f) {
            pokemon->miscVars[MAGNEMITE_VAR_ATTRACTED_OBJ].obj = magnemite_GroupLeader;
        }
        ohWait(1);
    }

    Pokemon_StopAuxProc(obj);
}

void magnemite_CalcTargetPos(GObj* obj, Vec3f* targetPos) {
    Vec3f offset = { 0, 0, 0 };
    DObj* modelNode;

    if (obj == D_802EE294_5EB364) {
        modelNode = magnemite_GroupLeader->data.dobj->firstChild->next->next;
    } else {
        modelNode = magnemite_GroupLeader->data.dobj->firstChild;
    }

    func_800A5E98(targetPos, &offset, modelNode);
}

POKEMON_FUNC(magnemite_Attract)
    pokemon->miscVars[MAGNEMITE_VAR_IS_ATTRACTED].field1 = true;
    pokemon->collisionRadius = pokemon->miscVars[MAGNEMITE_VAR_COLLISION_RADIUS].field0;
    Pokemon_SetAnimation(obj, &magnemite_animation_pulse);
    Pokemon_StartPathProc(obj, magnemite_MoveToAttractedMagnemite);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    magnemite_NumConnected++;
    if (magnemite_NumConnected == 2) {
        cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_3_MAGNEMITES_COMBINED, obj);
    }

    Pokemon_SetState(obj, magnemite_WaitForLeader);
}

POKEMON_FUNC(magnemite_MoveToAttractedMagnemite)
    Vec3f targetPos;

    do {
        ohWait(1);
        pokemon->hSpeed = 320.0f;
        magnemite_CalcTargetPos(pokemon->miscVars[MAGNEMITE_VAR_ATTRACTED_OBJ].obj, &targetPos);
        Pokemon_SetTargetPos(obj, targetPos.x, targetPos.z);
    } while (!Pokemon_StepToTargetPos(obj, 0.1f, MOVEMENT_FLAG_ON_GROUND));

    position->v.x = targetPos.x;
    position->v.z = targetPos.z;
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

InteractionHandler magnemite_tg_CopyLeader[] = {
    { POKEMON_CMD_9, NULL, 0, magnemite_HitByPesterBall_SendToLeader },
    { POKEMON_CMD_13, NULL, 0, magnemite_HitByApple_SendToLeader },
    { TUNNEL_CMD_3_MAGNEMITES_COMBINED, magnemite_WaitToDelete, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(magnemite_WaitForLeader)
    Pokemon_StartPathProc(obj, magnemite_CopyLeaderMovement);

    while (magnemite_GroupLeaderAnimation == NULL) {
        pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        pokemon->transitionGraph = magnemite_tg_CopyLeader;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    }
    Pokemon_SetState(obj, magnemite_CopyLeaderBehavior);
}

POKEMON_FUNC(magnemite_CopyLeaderBehavior)
    pokemon->flags &= ~POKEMON_FLAG_8;
    if (GET_POKEMON(magnemite_GroupLeader)->flags & POKEMON_FLAG_8) {
        pokemon->flags |= POKEMON_FLAG_8;
    }
    Pokemon_SetAnimation(obj, magnemite_GroupLeaderAnimation);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = magnemite_tg_CopyLeader;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, magnemite_CopyLeaderBehavior);
}

POKEMON_FUNC(magnemite_CopyLeaderMovement)
    bool sameDirection = false;
    Vec3f targetPos;
    Mtx4Float* leaderRotation = &GET_TRANSFORM(pokemon->miscVars[MAGNEMITE_VAR_ATTRACTED_OBJ].obj->data.dobj)->rot;

    while (true) {
        magnemite_CalcTargetPos(pokemon->miscVars[MAGNEMITE_VAR_ATTRACTED_OBJ].obj, &targetPos);
        position->v.x = targetPos.x;
        position->v.y = targetPos.y;
        position->v.z = targetPos.z;
        if (sameDirection) {
            rotation->f[2] = leaderRotation->f[2];
        } else if (Pokemon_Turn(model, leaderRotation->f[2], 0.034906585f)) {
            sameDirection = true;
        }
        ohWait(1);
    }
}

POKEMON_FUNC(magnemite_HitByPesterBall_SendToLeader)
    cmdSendCommand(magnemite_GroupLeader, POKEMON_CMD_9, obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(magnemite_HitByApple_SendToLeader)
    cmdSendCommand(magnemite_GroupLeader, POKEMON_CMD_13, obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(magnemite_AllMagnemitesCombined)
    InteractionHandler saved[] = {
        { POKEMON_CMD_16, magnemite_EvolveIntoMagneton, 250, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    pokemon->collisionRadius = pokemon->miscVars[MAGNEMITE_VAR_COLLISION_RADIUS].field0;
    Pokemon_StartPathProc(obj, NULL);
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &magnemite_animation_pulse);
    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, magnemite_EvolveIntoMagneton);
}

POKEMON_FUNC(magnemite_EvolveIntoMagneton)
    func_802E5094_5E2164();
    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_DELETE_MAGNEMITE, obj);
    Pokemon_SetState(obj, magnemite_Delete);
}

POKEMON_FUNC(magnemite_WaitToDelete)
    InteractionHandler saved[] = {
        { TUNNEL_CMD_DELETE_MAGNEMITE, magnemite_Delete, 0, NULL },
        { POKEMON_CMD_58, NULL, 0, NULL },
    };

    Pokemon_StartPathProc(obj, NULL);
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &magnemite_animation_pulse);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = saved;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_SetState(obj, magnemite_WaitToDelete);
}

POKEMON_FUNC(magnemite_Delete)
    switch (pokemon->behavior) {
        case 1:
            magnemite_FirstMagnemite = NULL;
            break;
        case 2:
            magnemite_SecondMagnemite = NULL;
            break;
        case 3:
            magnemite_ThirdMagnemite = NULL;
            break;
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

PokemonAnimationSetup magnemite_animSetup = {
    &magnemite_animation_move,
    magnemite_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData magnemite_initData = {
    magnemite_model,
    magnemite_materials,
    renderPokemonModelTypeDFogged,
    &magnemite_animSetup,
    { 2.2, 2.2, 2.2 },
    { 0, 250, 0 },
    20,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

GObj* magnemite_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &magnemite_initData);
}
