#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E2F0C_6CACEC;
extern AnimationHeader D_802E2F20_6CAD00;
extern InteractionHandler D_802E2F34_6CAD14[];
extern PokemonInitData D_802E2F70_6CAD50;

void func_802DA910_6C26F0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E2F0C_6CACEC);
    pokemon->transitionGraph = D_802E2F34_6CAD14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E2F20_6CAD00);
    pokemon->transitionGraph = D_802E2F34_6CAD14;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802DA9A4_6C2784(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E2F70_6CAD50);
}
