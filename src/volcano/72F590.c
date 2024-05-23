#include "common.h"
#include "world/world.h"

void func_802DE3FC_72F5FC(GObj* obj);
void func_802DE450_72F650(GObj* obj);
void func_802DE4C0_72F6C0(GObj* obj);

extern AnimationHeader D_802E31F4_7343F4;
extern AnimationHeader D_802E3208_734408;
extern AnimationHeader D_802E321C_73441C;
extern PokemonInitData koffingSmokeData;



void func_802DE390_72F590(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E31F4_7343F4);
    runPathProcess(obj, func_802DE4C0_72F6C0);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DE3FC_72F5FC);
}

void func_802DE3FC_72F5FC(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    forcePokemonAnimation(obj, &D_802E3208_734408);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    updatePokemonState(obj, func_802DE450_72F650);
}

void func_802DE450_72F650(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setPokemonAnimation(obj, &D_802E321C_73441C);
    pokemon->transitionGraph = NULL;
    runInteractionsAndWaitForFlags(obj, 1);
    cmdSendCommandToLink(3, 0x21, obj);
    runPokemonCleanup(obj);
    updatePokemonState(obj, NULL);
}

void func_802DE4C0_72F6C0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    setNodePosToNegRoom(obj);
    pokemonPathLoop(obj, 0, 1, 0.05f, 0.0f, 2);
    pokemon->pathProcess = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_2;
    omEndProcess(NULL);
}

void spawnKoffingSmoke(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    spawnPokemon(gObjID, id, roomA, roomB, spawn, &koffingSmokeData);
}
