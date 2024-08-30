#include "volcano/volcano.h"

extern AnimCmd* charizard_modelanim_spewfire[];
extern AnimCmd* charizard_modelanim_idle[];
extern AnimCmd* charizard_modelanim_roar[];
extern AnimCmd* charizard_modelanim_spin[];
extern AnimCmd* charizard_modelanim_appear[];

extern AnimCmd** charizard_matanim_spewfire[];
extern AnimCmd** charizard_matanim_idle[];
extern AnimCmd** charizard_matanim_roar[];
extern AnimCmd** charizard_matanim_spin[];
extern AnimCmd** charizard_matanim_appear[];

void charizard_InititalState(GObj*);
void charizard_Idle(GObj*);
void charizard_Roar(GObj*);
void charizard_HitByPesterBall(GObj*);
void charizard_AffectedByPesterBall(GObj*);
void charizard_HitByApple(GObj*);
void charizard_Appear(GObj*);
void charizard_MoveOutOfLava(GObj*);
void func_802DD4A4_72E6A4(GObj*);
void charizard_TurnToPlayer(GObj*);

s32 charizard_animsounds_appear[] = { SOUND_ID_190 };
s32 charizard_animsounds_roar[] = { SOUND_ID_190 };
s32 charizard_animsounds_spin[] = { SOUND_ID_191 };
s32 charizard_animsounds_spewfire[] = { 0, SOUND_ID_140 };

AnimationHeader charizard_animation_appear = {
    0.45,
    135,
    charizard_modelanim_appear,
    charizard_matanim_appear,
    charizard_animsounds_appear
};

AnimationHeader charizard_animation_idle = {
    0.6,
    60,
    charizard_modelanim_idle,
    charizard_matanim_idle,
    NULL
};

AnimationHeader charizard_animation_roar = {
    0.55,
    125,
    charizard_modelanim_roar,
    charizard_matanim_roar,
    charizard_animsounds_roar
};

AnimationHeader charizard_animation_spin = {
    0.45,
    60,
    charizard_modelanim_spin,
    charizard_matanim_spin,
    charizard_animsounds_spin
};

AnimationHeader charizard_animation_spewfire = {
    0.6,
    150,
    charizard_modelanim_spewfire,
    charizard_matanim_spewfire,
    charizard_animsounds_spewfire
};

InteractionHandler charizard_tg_Normal[] = {
    { POKEMON_CMD_9, charizard_HitByPesterBall, 0, NULL },
    { POKEMON_CMD_10, charizard_AffectedByPesterBall, 0, NULL },
    { POKEMON_CMD_13, charizard_HitByApple, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler charizard_tg_Unused[] = {
    { VOLCANO_CMD_31, charizard_Appear, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState charizard_idleStates[] = {
    { 1, charizard_Idle },
    { 1, charizard_Roar },
    { 0, NULL },
};

PokemonAnimationSetup charizard_animSetup = {
    &charizard_animation_idle,
    charizard_InititalState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData charizard_initData = {
    charizard_model,
    charizard_materials,
    renderPokemonModelTypeIFogged,
    &charizard_animSetup,
    { 3.5, 3.5, 3.5 },
    { 0, 1088, 0 },
    76,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(charizard_InititalState)
    obj->flags |= GOBJ_FLAG_HIDDEN;
    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_32, obj);
    Pokemon_SetState(obj, charizard_Appear);
}

POKEMON_FUNC(charizard_Appear)
    cmdSendCommand(gObjPlayer, PLAYER_CMD_SHAKE_CAMERA, obj);
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &charizard_animation_appear);
    Pokemon_StartPathProc(obj, charizard_MoveOutOfLava);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charizard_Idle);
}

POKEMON_FUNC(charizard_MoveOutOfLava)
    GroundResult result;

    Pokemon_TurnToTarget(obj, TAU, MOVEMENT_FLAG_TURN_TO_PLAYER);
    Pokemon_StartAuxProc(obj, func_802DD4A4_72E6A4);
    getGroundAt(position->v.x, position->v.z, &result);
    while (position->v.y + 50.0f < result.height) {
        position->v.y += 5.0f;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802DD4A4_72E6A4)
    s32 waitTimer = 48;

    while (waitTimer--) {
        ohWait(1);
    }

    omCreateProcess(obj, func_802D6CFC_727EFC, 1, 1);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(charizard_Idle)
    Pokemon_ForceAnimation(obj, &charizard_animation_idle);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charizard_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charizard_idleStates);
}

POKEMON_FUNC(charizard_Roar)
    Pokemon_ForceAnimation(obj, &charizard_animation_roar);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = charizard_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charizard_idleStates);
}

POKEMON_FUNC(charizard_HitByPesterBall)
    Pokemon_SetAnimation(obj, &charizard_animation_spin);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    
    Pokemon_SetAnimation(obj, &charizard_animation_spewfire);
    Pokemon_StartPathProc(obj, charizard_TurnToPlayer);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charizard_idleStates);
}

POKEMON_FUNC(charizard_TurnToPlayer)
    while (true) {
        Pokemon_TurnToTarget(obj, PI / 180, MOVEMENT_FLAG_TURN_TO_PLAYER);
        ohWait(1);
    }
}

POKEMON_FUNC(charizard_HitByApple)
    Pokemon_SetAnimation(obj, &charizard_animation_spewfire);
    Pokemon_StartPathProc(obj, charizard_TurnToPlayer);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, charizard_idleStates);
}

POKEMON_FUNC(charizard_AffectedByPesterBall)
    Pokemon_SetAnimation(obj, &charizard_animation_spewfire);
    Pokemon_StartPathProc(obj, charizard_TurnToPlayer);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, charizard_Idle);
}

GObj* charizard_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &charizard_initData);
}
