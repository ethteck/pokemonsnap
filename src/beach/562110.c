#include "common.h"
#include "beach.h"

extern u8 D_80138C50_C50E0[];
extern u8 D_beach_802CD7E0[];
void func_beach_802C8D74();
void func_beach_802C9204();
void func_beach_802CA148(GObj*);
void func_beach_802CA198(GObj*);
void func_beach_802CA1BC(GObj*);
void func_beach_802CA23C(GObj*);
extern PokemonAnimationSetup D_beach_802CD8D0;

// .data
u32 D_beach_802CD830[] = {
    0x00000000, 0x00000000,
};

PokemonDef D_beach_802CD838 = { 16, (pokemonInit) func_beach_802C8D74, (void (*)(GObj*, f32, f32, f32, f32, f32, f32)) pokemonChangeBlock, (void (*)(GObj*)) pokemonRemoveOne };
PokemonDef D_beach_802CD848 = { 123, (pokemonInit) func_beach_802C9204, (void (*)(GObj*, f32, f32, f32, f32, f32, f32)) pokemonChangeBlock, (void (*)(GObj*)) pokemonRemoveOne };

InteractionHandler D_beach_802CD858[6] = {
    { 9, (GObjFunc) func_beach_802CA198, 0.0f, NULL },
    { 13, (GObjFunc) func_beach_802CA198, 0.0f, NULL },
    { 10, (GObjFunc) func_beach_802CA198, 0.0f, NULL },
    { 14, (GObjFunc) func_beach_802CA198, 0.0f, NULL },
    { 16, (GObjFunc) func_beach_802CA198, 1000.0f, NULL },
    { 58, NULL, 0.0f, NULL },
};

RandomState D_beach_802CD8B8[3] = {
    { 70, (GObjFunc) func_beach_802CA1BC },
    { 30, (GObjFunc) func_beach_802CA23C },
    { 0, NULL },
};

PokemonAnimationSetup D_beach_802CD8D0 = { NULL, (GObjFunc) func_beach_802CA148, 0, "", NULL, NULL };
PokemonInitData D_beach_802CD8E4 = { (UnkEC64Arg3*) &D_beach_802CD7E0, NULL, (GObjFunc) renRenderModelTypeB, (PokemonAnimationSetup*) &D_beach_802CD8D0, { 2.0f, 2.0f, 2.0f }, { 0.0f, 17.0f, -2.0f }, 17.0f, 1, 0, 0, 0, "" };

u32 D_beach_802CD918[] = {
    0x00000000, 0x00000000,
};

u32 D_beach_802CD920[] = {
    0x00000000, 0x42C80000, (u32) &D_80138C50_C50E0, 0x00000000,
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
