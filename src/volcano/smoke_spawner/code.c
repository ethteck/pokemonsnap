#include "volcano/volcano.h"

void smoke_spawner_InitialState(GObj*);
void smoke_spawner_SpawnKoffingSmoke(GObj*);
void smoke_spawner_Idle(GObj*);
void smoke_spawner_PesterBallThrown(GObj*);
void smoke_spawner_WaitSmokeFade(GObj*);

__ALIGNER2

UnkEC64Arg3 smoke_spawner_model[] = {
    { 0,
      NULL,
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 1.0f, 1.0f, 1.0f } },
    { 18,
      NULL,
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f },
      { 0.0f, 0.0f, 0.0f } }
};

PokemonDef volcano_smoke_puff_def = {
    PokemonID_SMOKE_PUFF,
    smoke_puff_Spawn,
    pokemonChangeBlock,
    pokemonRemoveOne
};

PokemonDef volcano_koffing_smoke_def = {
    PokemonID_KOFFING_SMOKE,
    koffing_smoke_Spawn,
    pokemonChangeBlock,
    pokemonRemoveOne
};

InteractionHandler smoke_spawner_tg_Idle[] = {
    { POKEMON_CMD_10, smoke_spawner_PesterBallThrown, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler smoke_spawner_tg_WaitSmokeFade[] = {
    { VOLCANO_CMD_SMOKE_FADED, smoke_spawner_Idle, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState smoke_spawner_randomStates[] = {
    { 30, smoke_spawner_SpawnKoffingSmoke },
    { 0, NULL },
};

PokemonAnimationSetup smoke_spawner_animSetup = {
    NULL,
    smoke_spawner_InitialState,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData smoke_spawner_initData = {
    smoke_spawner_model,
    NULL,
    renRenderModelTypeB,
    &smoke_spawner_animSetup,
    { 10, 10, 10 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void smoke_spawner_CreateSmokePuff(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonDef def = volcano_smoke_puff_def;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_SMOKE_PUFF;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;
    spawn.path = pokemon->path;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

void smoke_spawner_CreateKoffingSmoke(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonDef def = volcano_koffing_smoke_def;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_KOFFING_SMOKE;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;
    spawn.path = pokemon->path;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}

POKEMON_FUNC(smoke_spawner_InitialState)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    omCreateProcess(obj, smoke_spawner_CreateSmokePuff, 1, 1);
    Pokemon_SetState(obj, smoke_spawner_Idle);
}

POKEMON_FUNC(smoke_spawner_Idle)
    pokemon->transitionGraph = smoke_spawner_tg_Idle;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(smoke_spawner_PesterBallThrown)
    GroundResult result;
    DObj* itemModel = pokemon->interactionTarget->data.dobj;

    getGroundAt(itemModel->position.v.x, itemModel->position.v.z, &result);
    if (result.surfaceType != SURFACE_TYPE_FF4C19) {
        Pokemon_SetState(obj, smoke_spawner_Idle);
    }

    Pokemon_SetStateRandom(obj, smoke_spawner_randomStates);
}

POKEMON_FUNC(smoke_spawner_SpawnKoffingSmoke)
    omCreateProcess(obj, smoke_spawner_CreateKoffingSmoke, 1, 1);
    Pokemon_SetState(obj, smoke_spawner_WaitSmokeFade);
}

POKEMON_FUNC(smoke_spawner_WaitSmokeFade)
    pokemon->transitionGraph = smoke_spawner_tg_WaitSmokeFade;
    Pokemon_WaitForFlag(obj, 0);

    Pokemon_SetState(obj, NULL);
}

GObj* smoke_spawner_Spawn(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &smoke_spawner_initData);
}
