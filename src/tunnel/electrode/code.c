#include "../tunnel.h"

extern AnimCmd* electrode_modelanim_idle[];
extern AnimCmd* electrode_modelanim_explode[];
extern AnimCmd* electrode_modelanim_dead[];
extern AnimCmd* electrode_modelanim_roll[];

extern AnimCmd** electrode_matanim_explode[];
extern AnimCmd** electrode_matanim_dead[];

void electrode_Behavior1_Move(GObj*);
void electrode_Behavior3_Move(GObj*);
void electrode_HiddenPathGuardIdle(GObj*);
void electrode_Behavior1(GObj*);
void electrode_Behavior2(GObj*);
void electrode_Behavior3(GObj*);
void electrode_Behavior4(GObj*);
void electrode_Behavior5(GObj*);
void electrode_Idle(GObj*);
void electrode_Behavior1_FollowPath(GObj*);
void electrode_Behavior4_Move(GObj*);
void electrode_Behavior4_FollowPath(GObj*);
void electrode_Behavior3_FollowPath(GObj*);
void electrode_WaitForPlayer(GObj*);
void electrode_Remove(GObj*);
void electrode_RevealHiddenPath(GObj*);
void electrode_Behavior3Hit(GObj*);
void electrode_tg_Explode(GObj*);

s32 electrode_animsounds_explode[] = { 0, SOUND_ID_60, SOUND_ID_135 };

AnimationHeader electrode_animation_idle = {
    0.58,
    80,
    electrode_modelanim_idle,
    NULL,
    NULL
};

AnimationHeader electrode_animation_explode = {
    0.8,
    270,
    electrode_modelanim_explode,
    electrode_matanim_explode,
    electrode_animsounds_explode
};

AnimationHeader electrode_animation_dead = {
    0.5,
    30,
    electrode_modelanim_dead,
    electrode_matanim_dead,
    NULL
};

AnimationHeader electrode_animation_roll = {
    0.27,
    80,
    electrode_modelanim_roll,
    NULL,
    NULL
};

InteractionHandler electrode_tg_Idle[] = {
    { POKEMON_CMD_9, electrode_tg_Explode, 0, NULL },
    { POKEMON_CMD_13, electrode_tg_Explode, 0, NULL },
    { POKEMON_CMD_10, electrode_tg_Explode, 0, NULL },
    { TUNNEL_CMD_51, electrode_Remove, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler electrode_tg_Dead[] = {
    { TUNNEL_CMD_51, electrode_Remove, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

GObj* D_802EE8AC_5EB97C = NULL;

InteractionHandler electrode_tg_Behavior3[] = {
    { POKEMON_CMD_9, electrode_Behavior3Hit, 0, NULL },
    { POKEMON_CMD_13, electrode_Behavior3Hit, 0, NULL },
    { POKEMON_CMD_10, electrode_Behavior3Hit, 0, NULL },
    { TUNNEL_CMD_51, electrode_Remove, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler electrode_tg_HiddenPathGuard[] = {
    { POKEMON_CMD_9, electrode_RevealHiddenPath, 0, NULL },
    { POKEMON_CMD_13, electrode_RevealHiddenPath, 0, NULL },
    { POKEMON_CMD_10, electrode_RevealHiddenPath, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

POKEMON_FUNC(electrode_ChangeCollisionOffset)
    ohWait(260);
    pokemon->collisionOffset.x = 54.0f;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(electrode_Remove)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(electrode_InitialState)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, electrode_Behavior1);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, electrode_Behavior2);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, electrode_Behavior3);
    }
    if (pokemon->behavior == 4) {
        Pokemon_SetState(obj, electrode_Behavior4);
    }
    if (pokemon->behavior == 5) {
        Pokemon_SetState(obj, electrode_Behavior5);
    }

    Pokemon_SetState(obj, electrode_Idle);
}

POKEMON_FUNC(electrode_Idle)
    Pokemon_SetAnimation(obj, &electrode_animation_idle);
    pokemon->transitionGraph = electrode_tg_Idle;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(electrode_tg_Explode)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_StartAuxProc(obj, electrode_ChangeCollisionOffset);
    Pokemon_SetAnimation(obj, &electrode_animation_explode);
    pokemon->counter = 159, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    switch (pokemon->behavior) {
        case 1:
            cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_37, obj);
            break;
        case 4:
            cmdSendCommand(D_802EEECC_5EBF9C, TUNNEL_CMD_37, obj);
            break;
        default:
            cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_39, obj);
            break;
    }
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &electrode_animation_dead);
    pokemon->transitionGraph = electrode_tg_Dead;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(electrode_Behavior1)
    Pokemon_SetState(obj, electrode_Behavior1_Move);
}

POKEMON_FUNC(electrode_Behavior1_Move)
    Pokemon_SetAnimation(obj, &electrode_animation_roll);
    Pokemon_StartPathProc(obj, electrode_Behavior1_FollowPath);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, electrode_tg_Explode);
}

POKEMON_FUNC(electrode_Behavior1_FollowPath)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(electrode_Behavior4)
    pokemon->flags |= POKEMON_FLAG_200;
    D_802EE8AC_5EB97C = obj;
    Pokemon_SetState(obj, electrode_Behavior4_Move);
}

POKEMON_FUNC(electrode_Behavior4_Move)
    Pokemon_SetAnimation(obj, &electrode_animation_roll);
    Pokemon_StartPathProc(obj, electrode_Behavior4_FollowPath);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_40, obj);
    Pokemon_SetState(obj, electrode_tg_Explode);
}

POKEMON_FUNC(electrode_Behavior4_FollowPath)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.043333337f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(electrode_Behavior2)
    Pokemon_SetAnimation(obj, &electrode_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = electrode_tg_Idle;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(electrode_Behavior3)
    Pokemon_SetState(obj, electrode_Behavior3_Move);
}

POKEMON_FUNC(electrode_Behavior3_Move)
    Pokemon_SetAnimation(obj, &electrode_animation_roll);
    Pokemon_StartPathProc(obj, electrode_Behavior3_FollowPath);
    pokemon->transitionGraph = electrode_tg_Behavior3;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(electrode_Behavior3_FollowPath)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 0, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND); // BUG? start = end = 0
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(electrode_Behavior3Hit)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_StartAuxProc(obj, electrode_ChangeCollisionOffset);
    Pokemon_SetAnimation(obj, &electrode_animation_explode);
    pokemon->counter = 159, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_39, obj);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetAnimation(obj, &electrode_animation_dead);
    pokemon->transitionGraph = electrode_tg_Dead;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(electrode_Behavior5)
    Pokemon_SetState(obj, electrode_HiddenPathGuardIdle);
}

POKEMON_FUNC(electrode_HiddenPathGuardIdle)
    Pokemon_SetAnimation(obj, &electrode_animation_idle);
    Pokemon_StartPathProc(obj, electrode_WaitForPlayer);
    pokemon->transitionGraph = electrode_tg_HiddenPathGuard;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, electrode_Idle);
}

POKEMON_FUNC(electrode_WaitForPlayer)
    s32 blockCount;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount < 6 && (blockCount != 5 || !(blockPart >= 0.35f))) {
            ohWait(1);
        } else {
            break;
        }
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

#define SET_ANIM_FRAME(obj, pokemon, frame, flag) \
    pokemon->pokemonLoopTarget = 1;               \
    pokemon->lastAnimationFrame = frame;          \
    pokemon->transitionGraph = NULL;              \
    Pokemon_WaitForFlag(obj, flag);

POKEMON_FUNC(electrode_RevealHiddenPath)
    InterpData* path;
    f32 eyex, eyey, eyez;
    s32 i;
    Vec3f* point;
    WorldBlock* block;
    u16 sp2C[] = { PokemonID_ELECTRODE, PokemonID_1014, PokemonID_GATE, 0 };

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_ForceAnimationAtTime(obj, &electrode_animation_explode, 0.0f);
    SET_ANIM_FRAME(obj, pokemon, 170.0f, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_RemovePokemons(sp2C);
    cmdSendCommand(gObjPlayer, PLAYER_CMD_8, obj);
    ohWait(1);

    path = pokemon->path;
    for (i = 1; i < path->numPoints; i++) {
        block = getCurrentWorldBlock();
        point = path->points;

        gMainCamera->viewMtx.lookAt.at.x = -(block->descriptor->worldPos.x * 100.0f);
        gMainCamera->viewMtx.lookAt.at.y = -(block->descriptor->worldPos.y * 100.0f);
        gMainCamera->viewMtx.lookAt.at.z = -(block->descriptor->worldPos.z * 100.0f);

        gMainCamera->viewMtx.lookAt.at.x += point->x * 100.0f;
        gMainCamera->viewMtx.lookAt.at.y += point->y * 100.0f;
        gMainCamera->viewMtx.lookAt.at.z += point->z * 100.0f;

        eyex = -(block->descriptor->worldPos.x * 100.0f);
        eyey = -(block->descriptor->worldPos.y * 100.0f);
        eyez = -(block->descriptor->worldPos.z * 100.0f);

        point = &path->points[i];
        eyex += (point->x * 100.0f);
        eyey += (point->y * 100.0f);
        eyez += (point->z * 100.0f);

        gMainCamera->viewMtx.lookAt.eye.x = eyex;
        gMainCamera->viewMtx.lookAt.eye.y = eyey;
        gMainCamera->viewMtx.lookAt.eye.z = eyez;

        if (i == path->numPoints - 1) {
            break;
        }

        Pokemon_ForceAnimationAtTime(obj, &electrode_animation_explode, 130.0f);
        SET_ANIM_FRAME(obj, pokemon, 170.0f, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    }

    auPlaySoundWithParams(SOUND_ID_60, 0x7000, 64, 1.0f, 0);
    Pokemon_ForceAnimationAtTime(obj, &electrode_animation_explode, 130.0f);

    SET_ANIM_FRAME(obj, pokemon, 220.0f, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, TUNNEL_CMD_54, obj);
    Pokemon_SetAnimation(obj, &electrode_animation_dead);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, NULL);
}

PokemonAnimationSetup electrode_animSetup = {
    &electrode_animation_idle,
    electrode_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData electrode_initData = {
    electrode_model,
    electrode_materials,
    renderPokemonModelTypeDFogged,
    &electrode_animSetup,
    { 1.4, 1.4, 1.4 },
    { 0, 124, 0 },
    66,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

GObj* electrode_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &electrode_initData);
}
