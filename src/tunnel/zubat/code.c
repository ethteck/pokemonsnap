#include "../tunnel.h"

void func_802EB9F8_5E8AC8(GObj*);
void func_802EBA48_5E8B18(GObj*);
void func_802EB908_5E89D8(GObj*);
void func_802EB98C_5E8A5C(GObj*);
void func_802EBABC_5E8B8C(GObj*);

extern AnimationHeader D_802EFC48_5ECD18;
extern InteractionHandler D_802EFC5C_5ECD2C[];
extern InteractionHandler D_802EFC7C_5ECD4C[];
extern InteractionHandler D_802EFCAC_5ECD7C[];
extern InteractionHandler D_802EFCCC_5ECD9C[];
extern PokemonInitData D_802EFD10_5ECDE0;

POKEMON_FUNC(func_802EB860_5E8930)
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802EB9F8_5E8AC8);
    }
    if (pokemon->behavior == 7) {
        Pokemon_SetState(obj, func_802EBA48_5E8B18);
    }

    HIDE_POKEMON();
    pokemon->transitionGraph = D_802EFC5C_5ECD2C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, func_802EB908_5E89D8);
}

POKEMON_FUNC(func_802EB908_5E89D8)
    SHOW_POKEMON();
    Pokemon_StartPathProc(obj, func_802EB98C_5E8A5C);
    Pokemon_SetAnimation(obj, &D_802EFC48_5ECD18);
    pokemon->transitionGraph = D_802EFC7C_5ECD4C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EB98C_5E8A5C)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EB9F8_5E8AC8)
    HIDE_POKEMON();
    pokemon->transitionGraph = D_802EFCAC_5ECD7C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EBA48_5E8B18)
    Pokemon_StartPathProc(obj, func_802EBABC_5E8B8C);
    Pokemon_SetAnimation(obj, &D_802EFC48_5ECD18);
    pokemon->transitionGraph = D_802EFCCC_5ECD9C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_802EBA48_5E8B18);
}

POKEMON_FUNC(func_802EBABC_5E8B8C)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.13333334f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EBB28_5E8BF8)
    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 300.0f;
    Pokemon_Fall(obj, 120.0f, 0.0f, 0.0f, 0.0f);
    pokemon->jumpVel = 300.0f;
    Pokemon_Jump(obj, 120.0f, 0.0f, 0.0f, 0.0f);
    Pokemon_StopAuxProc(obj);
}

GObj* func_802EBBA8_5E8C78(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802EFD10_5ECDE0);
}
