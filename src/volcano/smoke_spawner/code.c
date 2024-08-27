#include "volcano/volcano.h"

void func_802DE8C8_72FAC8(GObj*);
void func_802DE9C4_72FBC4(GObj*);
void func_802DE91C_72FB1C(GObj*);
void func_802DE95C_72FB5C(GObj*);
void func_802DEA04_72FC04(GObj*);

UnkEC64Arg3 D_802E3300_734500[] = {
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

PokemonDef D_802E3358_734558 = {
    PokemonID_SMOKE_PUFF,
    func_802DE6B4_72F8B4,
    pokemonChangeBlock,
    pokemonRemoveOne
};

PokemonDef D_802E3368_734568 = {
    PokemonID_KOFFING_SMOKE,
    func_802DE52C_72F72C,
    pokemonChangeBlock,
    pokemonRemoveOne
};

InteractionHandler D_802E3378_734578[] = {
    { POKEMON_CMD_10, func_802DE95C_72FB5C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

InteractionHandler D_802E3398_734598[] = {
    { POKEMON_CMD_33, func_802DE91C_72FB1C, 0, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_802E33B8_7345B8[] = {
    { 30, func_802DE9C4_72FBC4 },
    { 0, NULL },
};

PokemonAnimationSetup D_802E33C8_7345C8 = {
    NULL,
    func_802DE8C8_72FAC8,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_802E33DC_7345DC = {
    D_802E3300_734500,
    NULL,
    renRenderModelTypeB,
    &D_802E33C8_7345C8,
    { 10, 10, 10 },
    { 0, 0, 0 },
    0,
    0,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_802DE6F0_72F8F0(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonDef def = D_802E3358_734558;

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

void func_802DE7DC_72F9DC(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonDef def = D_802E3368_734568;

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

POKEMON_FUNC(func_802DE8C8_72FAC8)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;

    omCreateProcess(obj, func_802DE6F0_72F8F0, 1, 1);
    Pokemon_SetState(obj, func_802DE91C_72FB1C);
}

POKEMON_FUNC(func_802DE91C_72FB1C)
    pokemon->transitionGraph = D_802E3378_734578;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802DE95C_72FB5C)
    GroundResult result;
    DObj* targetModel = pokemon->interactionTarget->data.dobj;

    getGroundAt(targetModel->position.v.x, targetModel->position.v.z, &result);
    if (result.surfaceType != SURFACE_TYPE_FF4C19) {
        Pokemon_SetState(obj, func_802DE91C_72FB1C);
    }

    Pokemon_SetStateRandom(obj, D_802E33B8_7345B8);
}

POKEMON_FUNC(func_802DE9C4_72FBC4)
    omCreateProcess(obj, func_802DE7DC_72F9DC, 1, 1);
    Pokemon_SetState(obj, func_802DEA04_72FC04);
}

POKEMON_FUNC(func_802DEA04_72FC04)
    pokemon->transitionGraph = D_802E3398_734598;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DEA44_72FC44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E33DC_7345DC);
}
