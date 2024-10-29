#include "volcano/volcano.h"

extern UnkEC64Arg3 moltres_egg_model[];
extern AnimCmd* moltres_egg_modelanim_idle[];
extern AnimCmd* moltres_egg_modelanim_drown[];

void moltres_egg_InitialState(GObj*);
void moltres_egg_Hit(GObj*);
void moltres_egg_Idle(GObj*);
void moltres_egg_FallIntoLava(GObj*);
void moltres_egg_Jump(GObj*);
void moltres_egg_SpawnMoltres(GObj*);
void volcano_CreateSplashFromMoltresEgg(GObj*);
void moltres_egg_DrownInLava(GObj*);
void volcano_CreateSplashFromMoltres(GObj*);

AnimationHeader moltres_egg_animation_idle = {
    0.5,
    60,
    moltres_egg_modelanim_idle,
    NULL,
    NULL
};

AnimationHeader moltres_egg_animation_drown = {
    0.5,
    60,
    moltres_egg_modelanim_drown,
    NULL,
    NULL
};

InteractionHandler moltres_egg_tg_Normal[] = {
    { POKEMON_CMD_9, moltres_egg_Hit, 0, NULL },
    { POKEMON_CMD_13, moltres_egg_Hit, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

f32 moltres_egg_forbiddenGround[] = { 0 };

PokemonAnimationSetup moltres_egg_animSetup = {
    &moltres_egg_animation_idle,
    moltres_egg_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData moltres_egg_initData = {
    moltres_egg_model,
    NULL,
    renderPokemonModelTypeBFogged,
    &moltres_egg_animSetup,
    { 1.7, 1.7, 1.7 },
    { 0, 123, 0 },
    60,
    POKEMON_FLAG_40 | POKEMON_FLAG_20 | POKEMON_FLAG_4 | POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(moltres_egg_InitialState)
    pokemon->forbiddenGround = moltres_egg_forbiddenGround;
    Pokemon_SetState(obj, moltres_egg_Idle);
}

POKEMON_FUNC(moltres_egg_Idle)
    Pokemon_SetAnimation(obj, &moltres_egg_animation_idle);
    pokemon->transitionGraph = moltres_egg_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, moltres_egg_Idle);
}

POKEMON_FUNC(moltres_egg_Hit)
    if (pokemon->playerDist < 1200.0f) {
        Pokemon_SetAnimation(obj, &moltres_egg_animation_drown);
        Pokemon_StartPathProc(obj, moltres_egg_FallIntoLava);
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    } else {
        Pokemon_SetAnimation(obj, &moltres_egg_animation_idle);
        Pokemon_StartPathProc(obj, moltres_egg_Jump);
        pokemon->transitionGraph = NULL;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

        Pokemon_SetState(obj, moltres_egg_Idle);
    }

    Pokemon_SetState(obj, moltres_egg_SpawnMoltres);
}

POKEMON_FUNC(moltres_egg_FallIntoLava)
    pokemon->hSpeed = 200.0f;
    pokemon->jumpVel = 300.0f;
    pokemon->facingYaw = PI;
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(moltres_egg_Jump)
    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 100.0f;
    pokemon->facingYaw = 0.0f;
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(moltres_egg_SpawnMoltres)
    omCreateProcess(obj, volcano_CreateSplashFromMoltresEgg, 1, 1);
    Pokemon_SetAnimation(obj, &moltres_egg_animation_drown);
    Pokemon_StartPathProc(obj, moltres_egg_DrownInLava);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    omCreateProcess(obj, volcano_CreateSplashFromMoltres, 1, 1);
    pokemon->counter = 6, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_SPAWN_MOLTRES, obj);

    pokemon->counter = 2, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(moltres_egg_DrownInLava)
    s32 i;

    for (i = 0; i < 100; i++) {
        position->v.y -= 3.0f;
        rotation->f[2] += PI / 180.0f;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

GObj* moltres_egg_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &moltres_egg_initData);
}
