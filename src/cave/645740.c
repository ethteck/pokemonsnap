#include "common.h"
#include "app_level/app_level.h"

extern s16 D_802C6354_648804;
extern AnimationHeader D_802C779C_649C4C;
extern PokemonInitData D_802C77FC_649CAC;

void func_802C3348_6457F8(GObj*);

POKEMON_FUNC(func_802C3290_645740)
    Pokemon_SetAnimation(obj, &D_802C779C_649C4C);
    rotation->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802C3348_6457F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    D_802C6354_648804 = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802C3348_6457F8)
    func_8035E298_4FE6A8(obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802C3388_645838(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802C77FC_649CAC);
}
