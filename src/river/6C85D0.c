#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E4610_6CC3F0;
extern AnimationHeader D_802E4624_6CC404;
extern InteractionHandler D_802E4638_6CC418[];
extern PokemonInitData D_802E466C_6CC44C;

void func_802E07F0_6C85D0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4610_6CC3F0);
    pokemon->transitionGraph = D_802E4638_6CC418;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802E0848_6C8628(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4610_6CC3F0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E4624_6CC404);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802E08C4_6C86A4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E466C_6CC44C);
}
