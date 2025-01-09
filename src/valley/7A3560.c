#include "valley.h"

extern AnimationHeader D_802D2F8C_7AC51C;
extern AnimationHeader D_802D2FA0_7AC530;
extern AnimationHeader D_802D2FB4_7AC544;
extern AnimationHeader D_802D2FC8_7AC558;
extern AnimationHeader D_802D2FDC_7AC56C;
extern GObj* D_802D2FF0_7AC580;
extern s16 D_802D2FF4_7AC584;
extern InteractionHandler D_802D2FF8_7AC588[];
extern PokemonInitData D_802D302C_7AC5BC;

void func_802CA1B0_7A3740(GObj*);

POKEMON_FUNC(func_802C9FD0_7A3560)
    HIDE_POKEMON();
    pokemon->transitionGraph = D_802D2FF8_7AC588;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CA020_7A35B0)
    Mtx3Float* scale;

    D_802D2FF4_7AC584 = 1;

    scale = &GET_TRANSFORM(func_8035E1D4_4FE5E4(obj)->data.dobj)->scale;

    scale->v.x *= 15.0f;
    scale->v.y *= 15.0f;
    scale->v.z *= 10.0f;

    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_ForceAnimation(obj, &D_802D2F8C_7AC51C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D2FA0_7AC530);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D2FC8_7AC558);
    Pokemon_StartPathProc(obj, func_802CA1B0_7A3740);

    while (true) {
        if (pokemon->pathParam > 0.2) {
            break;
        }
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802D2FB4_7AC544);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802D2FDC_7AC56C);
    pokemon->transitionGraph = 0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CA1B0_7A3740)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 1.0f, 0.1f, 0.1f, MOVEMENT_FLAG_TURN_GRADUALLY);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

static void nullsub(void) {
    // todo remove?
}

GObj* func_802CA224_7A37B4(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802D2FF0_7AC580 = Pokemon_SpawnOnGround(gObjID, id, roomA, roomB, spawn, &D_802D302C_7AC5BC);

    return D_802D2FF0_7AC580;
}
