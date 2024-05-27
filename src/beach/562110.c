#include "common.h"
#include "beach.h"

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

    pokemon->tangible = 0;
    obj->flags |= GOBJ_FLAG_HIDDEN | GOBJ_FLAG_2;
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
    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    // clang-format on

    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CA23C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    omCreateProcess(obj, func_beach_802CA0F4, 1, 1);
    // clang-format off
    pokemon->counter = 1; pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    // clang-format on
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_beach_802CA2BC(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_beach_802CD8E4);
}
