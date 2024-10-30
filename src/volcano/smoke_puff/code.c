#include "volcano/volcano.h"

extern UnkEC64Arg3 smoke_puff_model[];
extern Texture** smoke_puff_materials[];
extern AnimCmd* smoke_puff_modelanim[];
extern AnimCmd** smoke_puff_matanim[];

void smoke_puff_InitialState(GObj*);
void smoke_puff_Rise(GObj*);

AnimationHeader smoke_puff_animation = {
    1.0,
    100,
    smoke_puff_modelanim,
    smoke_puff_matanim,
    NULL
};

InteractionHandler smoke_puff_tg_Normal[] = {
    { POKEMON_CMD_58, NULL, 0, NULL },
};

PokemonAnimationSetup smoke_puff_animSetup = {
    &smoke_puff_animation,
    smoke_puff_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData smoke_puff_initData = {
    smoke_puff_model,
    smoke_puff_materials,
    renderModelTypeDFogged,
    &smoke_puff_animSetup,
    { 30, 30, 30 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

POKEMON_FUNC(smoke_puff_InitialState)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    Pokemon_StartPathProc(obj, NULL);
    pokemon->counter = 30 + randRange(60), pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &smoke_puff_animation);
    Pokemon_StartPathProc(obj, smoke_puff_Rise);
    pokemon->transitionGraph = smoke_puff_tg_Normal;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    cmdSendCommandToLink(LINK_POKEMON, VOLCANO_CMD_SMOKE_FADED, obj);
    Pokemon_SetState(obj, smoke_puff_InitialState);
}

POKEMON_FUNC(smoke_puff_Rise)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* smoke_puff_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &smoke_puff_initData);
}
