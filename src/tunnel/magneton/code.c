#include "../tunnel.h"

extern AnimCmd* magneton_modelanim[];

void magneton_Idle(GObj*);
void magneton_AppleNearby(GObj*);
void magneton_MoveRoam1(GObj*);
void magneton_MoveRoam2(GObj*);
void magneton_WithApple(GObj*);
void magneton_MoveToApple(GObj*);
void magneton_MoveRunAway(GObj*);
void magneton_InitialState(GObj*);
void magneton_Roam1(GObj*);
void magneton_Roam2(GObj*);
void magneton_SearchApple(GObj*);
void magneton_RunAway(GObj*);

s32 magneton_animsounds[] = { 353 };

AnimationHeader magneton_animation = {
    0.5,
    59,
    magneton_modelanim,
    NULL,
    magneton_animsounds
};

InteractionHandler magneton_tg_Normal[] = {
    { POKEMON_CMD_14, magneton_AppleNearby, 0, NULL },
    { POKEMON_CMD_15, magneton_SearchApple, 0, NULL },
    { POKEMON_CMD_16, magneton_RunAway, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState magneton_idleStates[] = {
    { 100, magneton_Idle },
    { 100, magneton_Roam1 },
    { 100, magneton_Roam2 },
    { 0, NULL },
};

InteractionHandler magneton_tg_SearchApple[] = {
    { POKEMON_CMD_14, magneton_AppleNearby, 0, NULL },
    { POKEMON_CMD_16, magneton_RunAway, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magneton_tg_WithApple[] = {
    { POKEMON_CMD_14, magneton_AppleNearby, 0, NULL },
    { POKEMON_CMD_16, magneton_RunAway, 250, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler magneton_tg_RunAway[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup magneton_animSetup = {
    &magneton_animation,
    magneton_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData magneton_initData = {
    magneton_model,
    NULL,
    renderPokemonModelTypeBFogged,
    &magneton_animSetup,
    { 2.2, 2.2, 2.2 },
    { 0, 320, 0 },
    42,
    POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(magneton_InitialState)
    Pokemon_SetState(obj, magneton_Idle);
}

POKEMON_FUNC(magneton_Idle)
    Pokemon_SetAnimation(obj, &magneton_animation);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = magneton_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, magneton_idleStates);
}

POKEMON_FUNC(magneton_Roam1)
    Pokemon_SetAnimation(obj, &magneton_animation);
    Pokemon_StartPathProc(obj, magneton_MoveRoam1);
    pokemon->transitionGraph = magneton_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, magneton_Idle);
    }

    Pokemon_SetStateRandom(obj, magneton_idleStates);
}

POKEMON_FUNC(magneton_MoveRoam1)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCirclesDefault(obj, 500.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magneton_Roam2)
    Pokemon_SetAnimation(obj, &magneton_animation);
    Pokemon_StartPathProc(obj, magneton_MoveRoam2);
    pokemon->transitionGraph = magneton_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, magneton_Idle);
    }

    Pokemon_SetStateRandom(obj, magneton_idleStates);
}

POKEMON_FUNC(magneton_MoveRoam2)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCirclesDefault(obj, 500.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magneton_AppleNearby)
    Pokemon_StartPathProc(obj, magneton_MoveToApple);
    pokemon->transitionGraph = magneton_tg_SearchApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, magneton_Idle);
    }

    Pokemon_SetState(obj, magneton_WithApple);
}

POKEMON_FUNC(magneton_MoveToApple)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(magneton_SearchApple)
    Pokemon_SetState(obj, magneton_AppleNearby);
}

POKEMON_FUNC(magneton_WithApple)
    Pokemon_SetAnimation(obj, &magneton_animation);
    pokemon->transitionGraph = magneton_tg_WithApple;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, magneton_WithApple);
    }

    Pokemon_SetStateRandom(obj, magneton_idleStates);
}

POKEMON_FUNC(magneton_RunAway)
    Pokemon_SetAnimation(obj, &magneton_animation);
    Pokemon_StartPathProc(obj, magneton_MoveRunAway);
    pokemon->transitionGraph = magneton_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED) {
        Pokemon_SetState(obj, magneton_Idle);
    }

    pokemon->transitionGraph = magneton_tg_RunAway;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, magneton_Idle);
}

POKEMON_FUNC(magneton_MoveRunAway)
    pokemon->hSpeed = 160.0f;
    Pokemon_RunAwayDefault(obj, 1500.0f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* magneton_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &magneton_initData);
}

void tunnel_SpawnMagneton(GObj* obj) {
    GObj* var;
    PokemonDef def = {
        PokemonID_MAGNETON,
        magneton_Spawn,
        pokemonChangeBlockOnGround,
        pokemonRemoveOne
    };

    var = Pokemon_AddAtGeo(obj, PokemonID_MAGNETON, &def);
    GET_POKEMON(var)->behavior = 0;
}
