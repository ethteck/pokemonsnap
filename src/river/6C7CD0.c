#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E43B0_6CC190;
extern PokemonInitData D_802E43D8_6CC1B8;
extern PokemonDef D_802E440C_6CC1EC;

POKEMON_FUNC(func_802DFEF0_6C7CD0)
    Pokemon_ForceAnimation(obj, &D_802E43B0_6CC190);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DFF5C_6C7D3C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E43D8_6CC1B8);
}

void func_802DFF94_6C7D74(GObj* obj) {
    DObj* model;
    Mtx3Float* position;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = D_802E440C_6CC1EC;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_EVOLUTION_CONTROLLER;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = 0.0;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);

    position = &GET_TRANSFORM(obj->data.dobj)->pos;
    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = position->v.x;
    GET_TRANSFORM(model)->pos.v.y = position->v.y;
    GET_TRANSFORM(model)->pos.v.z = position->v.z;
    omEndProcess(NULL);
}
