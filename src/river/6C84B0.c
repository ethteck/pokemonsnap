#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimationHeader D_802E4580_6CC360;
extern AnimationHeader D_802E4594_6CC374;
extern InteractionHandler D_802E45A8_6CC388[];
extern PokemonInitData D_802E45DC_6CC3BC;

void func_802E06D0_6C84B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4580_6CC360);
    pokemon->transitionGraph = D_802E45A8_6CC388;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802E0728_6C8508(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4580_6CC360);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802E4594_6CC374);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802E07A4_6C8584(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_802E45DC_6CC3BC);
}
