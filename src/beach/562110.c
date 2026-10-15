#include "common.h"
#include "beach.h"

void func_beach_802C8D74(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
void func_beach_802C9204(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
void func_beach_802CA148(GObj*);
void func_beach_802CA198(GObj*);
void func_beach_802CA1BC(GObj*);
void func_beach_802CA23C(GObj*);

// .data
UnkEC64Arg3 D_beach_802CD7E0[] = {
    { 0,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};

PokemonDef D_beach_802CD838 = {
    PokemonID_PIDGEY,
    (pokemonInit) func_beach_802C8D74,
    pokemonChangeBlock,
    pokemonRemoveOne
};

PokemonDef D_beach_802CD848 = {
    PokemonID_SCYTHER,
    (pokemonInit) func_beach_802C9204,
    pokemonChangeBlock,
    pokemonRemoveOne
};

InteractionHandler D_beach_802CD858[] = {
    { POKEMON_CMD_9, func_beach_802CA198, 0, NULL },
    { POKEMON_CMD_13, func_beach_802CA198, 0, NULL },
    { POKEMON_CMD_10, func_beach_802CA198, 0, NULL },
    { POKEMON_CMD_14, func_beach_802CA198, 0, NULL },
    { POKEMON_CMD_16, func_beach_802CA198, 1000, NULL },
    { POKEMON_CMD_58, NULL, 0, NULL },
};

RandomState D_beach_802CD8B8[] = {
    { 70, func_beach_802CA1BC },
    { 30, func_beach_802CA23C },
    { 0, NULL },
};

PokemonAnimationSetup D_beach_802CD8D0 = {
    NULL,
    func_beach_802CA148,
    0,
    { 0, 0, 0 },
    NULL,
    NULL
};

PokemonInitData D_beach_802CD8E4 = {
    D_beach_802CD7E0,
    NULL,
    renRenderModelTypeB,
    &D_beach_802CD8D0,
    { 2, 2, 2 },
    { 0, 17, -2 },
    17,
    POKEMON_FLAG_1,
    0,
    0,
    0,
    { 0, 0, 0 }
};

void func_beach_802CA0A0(GObj* obj) {
    // TODO: see if this can be inlined
    PokemonDef sp18 = D_beach_802CD838;

    Pokemon_AddAtGeo(obj, PokemonID_PIDGEY, &sp18);
    omEndProcess(NULL);
}

void func_beach_802CA0F4(GObj* obj) {
    // TODO: see if this can be inlined
    PokemonDef sp18 = D_beach_802CD848;

    Pokemon_AddAtGeo(obj, PokemonID_SCYTHER, &sp18);
    omEndProcess(NULL);
}

void func_beach_802CA148(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    HIDE_POKEMON();
    pokemon->transitionGraph = D_beach_802CD858;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CA198(GObj* obj) {
    Pokemon_SetStateRandom(obj, D_beach_802CD8B8);
}

void func_beach_802CA1BC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, func_beach_802CA0A0, 1, 1);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CA23C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, func_beach_802CA0F4, 1, 1);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CA2BC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CD8E4);
}
