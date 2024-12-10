#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "river.h"

void func_802DCFBC_6C4D9C(GObj*);

extern AnimationHeader D_802E36FC_6CB4DC;
extern AnimationHeader D_802E3710_6CB4F0;
extern AnimationHeader D_802E3724_6CB504;
extern RandomState D_802E3748_6CB528[];
extern PokemonInitData D_802E377C_6CB55C;

void func_802DD068_6C4E48(GObj*);

void func_802DCEF0_6C4CD0(GObj* obj) {
    Pokemon_SetStateRandom(obj, D_802E3748_6CB528);
}

void func_802DCF14_6C4CF4(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E36FC_6CB4DC);
    Pokemon_SetState(obj, func_802DCFBC_6C4D9C);
}

void func_802DCF4C_6C4D2C(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E3710_6CB4F0);
    Pokemon_SetState(obj, func_802DCFBC_6C4D9C);
}

void func_802DCF84_6C4D64(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802E3724_6CB504);
    Pokemon_SetState(obj, func_802DCFBC_6C4D9C);
}

POKEMON_FUNC(func_802DCFBC_6C4D9C)
    rotation->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802DD068_6C4E48);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    D_802E28AC_6CA68C = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802DD068_6C4E48(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    func_8035E298_4FE6A8(obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802DD0A8_6C4E88(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802E377C_6CB55C);
}
