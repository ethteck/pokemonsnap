#include "../tunnel.h"

extern AnimationHeader D_802EFD58_5ECE28;
extern PokemonInitData D_802EFD90_5ECE60;

void func_802EBC04_5E8CD4(GObj*);
void func_802EBC78_5E8D48(GObj*);

POKEMON_FUNC(func_802EBBE0_5E8CB0)
    Pokemon_SetState(obj, func_802EBC04_5E8CD4);
}

POKEMON_FUNC(func_802EBC04_5E8CD4)
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetAnimation(obj, &D_802EFD58_5ECE28);
    Pokemon_StartPathProc(obj, func_802EBC78_5E8D48);    
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EBC78_5E8D48)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 0, 0.1f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS); // start = end ?

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802EBCE8_5E8DB8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802EFD90_5ECE60);
}
