#include "../tunnel.h"

extern AnimationHeader D_802EFB54_5ECC24;
extern AnimationHeader D_802EFB68_5ECC38;
extern AnimationHeader D_802EFB7C_5ECC4C;
extern AnimationHeader D_802EFB90_5ECC60;
extern InteractionHandler D_802EFBA8_5ECC78[];
extern InteractionHandler D_802EFBC8_5ECC98[];
extern PokemonInitData D_802EFC0C_5ECCDC;

void func_802EB548_5E8618(GObj*);
void func_802EB6D0_5E87A0(GObj*);
void func_802EB664_5E8734(GObj*);
void func_802EB750_5E8820(GObj*);
void func_802EB7E4_5E88B4(GObj*);

POKEMON_FUNC(func_802EB3E0_5E84B0)
    HIDE_POKEMON();
    pokemon->transitionGraph = D_802EFBC8_5ECC98;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802EB430_5E8500)
    SHOW_POKEMON();
    Pokemon_SetAnimation(obj, &D_802EFB7C_5ECC4C);
    Pokemon_StartPathProc(obj, func_802EB548_5E8618);
    pokemon->transitionGraph = D_802EFBA8_5ECC78;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    pokemon->transitionGraph = D_802EFBA8_5ECC78;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_StartAuxProc(obj, func_802EB6D0_5E87A0);
    Pokemon_StartPathProc(obj, func_802EB664_5E8734);
    Pokemon_SetAnimation(obj, &D_802EFB90_5ECC60);
    pokemon->transitionGraph = D_802EFBA8_5ECC78;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetAnimation(obj, &D_802EFB54_5ECC24);
    pokemon->transitionGraph = D_802EFBA8_5ECC78;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    D_803430E8_6401B8.bits.unk_00 = true;
    Pokemon_SetState(obj, func_802EB750_5E8820);
}

POKEMON_FUNC(func_802EB548_5E8618)
    f32 angle;
    f32 f20 = 100.0f;
    PokemonTransform* playerTransform = GET_TRANSFORM(gPlayerDObj);

    pokemon->pos1.x = position->v.x;
    pokemon->pos1.z = position->v.z;

    while (f20 > 0.0f) {
        angle = atan2f(pokemon->pos1.x - playerTransform->pos.v.x, pokemon->pos1.z - playerTransform->pos.v.z);
        position->v.x = pokemon->pos1.x + sinf(angle) * f20;
        position->v.z = pokemon->pos1.z + cosf(angle) * f20;
        f20 -= 100.0f / 30.0f;
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EB664_5E8734)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.1f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802EB6D0_5E87A0)
    ohWait(6);
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    while (D_802EFF28_5ECFF8 != NULL) {
        ohWait(1);
    }
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802EB750_5E8820)
    Pokemon_ForceAnimation(obj, &D_802EFB68_5ECC38);
    pokemon->transitionGraph = D_802EFBA8_5ECC78;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_802EB750_5E8820);
}

POKEMON_FUNC(func_802EB7AC_5E887C)
    D_803430E8_6401B8.bits.unk_00 = true;
    Pokemon_SetState(obj, func_802EB7E4_5E88B4);
}

POKEMON_FUNC(func_802EB7E4_5E88B4)
    D_802EFBA4_5ECC74 = NULL;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802EB818_5E88E8(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802EFBA4_5ECC74 = Pokemon_Spawn(gObjID, id, roomA, roomB, spawn, &D_802EFC0C_5ECCDC);
    return D_802EFBA4_5ECC74;
}
