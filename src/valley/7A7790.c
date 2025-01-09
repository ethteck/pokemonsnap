#include "valley.h"

extern AnimationHeader D_802D3C5C_7AD1EC;
extern AnimationHeader D_802D3C70_7AD200;
extern AnimationHeader D_802D3C84_7AD214;
extern AnimationHeader D_802D3C98_7AD228;
extern AnimationHeader D_802D3CAC_7AD23C;
extern AnimationHeader D_802D3CC0_7AD250;
extern AnimationHeader D_802D3CD4_7AD264;
extern AnimationHeader D_802D3CE8_7AD278;
extern AnimationHeader D_802D3CFC_7AD28C;
extern AnimationHeader D_802D3D10_7AD2A0;
extern InteractionHandler D_802D3D24_7AD2B4[];
extern RandomState D_802D3D84_7AD314;
extern InteractionHandler2 D_802D3DA4_7AD334;
extern InteractionHandler D_802D3DC4_7AD354[];
extern InteractionHandler D_802D3DE4_7AD374[];
extern InteractionHandler D_802D3E14_7AD3A4[];
extern InteractionHandler D_802D3E44_7AD3D4[];
extern InteractionHandler D_802D3E94_7AD424[];
extern InteractionHandler4 D_802D3EE4_7AD474;
extern PokemonInitData D_802D3F38_7AD4C8;

void func_802CE224_7A77B4(GObj*);
void func_802CE2DC_7A786C(GObj*);
void func_802CE37C_7A790C(GObj* obj);
void func_802CE440_7A79D0(GObj* obj);
void func_802CE554_7A7AE4(GObj*);
void func_802CE654_7A7BE4(GObj*);
void func_802CE7D8_7A7D68(GObj*);
void func_802CE870_7A7E00(GObj*);
void func_802CE8F4_7A7E84(GObj* obj);

POKEMON_FUNC(func_802CE200_7A7790)
    Pokemon_SetState(obj, func_802CE224_7A77B4);
}

POKEMON_FUNC(func_802CE224_7A77B4)
    InteractionHandler2 sp20 = D_802D3DA4_7AD334;

    Pokemon_SetAnimation(obj, &D_802D3C5C_7AD1EC);
    Pokemon_StartPathProc(obj, func_802CE2DC_7A786C);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CE2DC_7A786C)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CE328_7A78B8)
    Pokemon_SetAnimation(obj, &D_802D3D10_7AD2A0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CE37C_7A790C);
}

POKEMON_FUNC(func_802CE37C_7A790C)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = D_802D3DC4_7AD354;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CE3CC_7A795C)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802D3CFC_7AD28C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CE440_7A79D0);
}

POKEMON_FUNC(func_802CE440_7A79D0)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802D3C5C_7AD1EC);
    pokemon->transitionGraph = D_802D3D24_7AD2B4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_802D3D84_7AD314);
}

POKEMON_FUNC(func_802CE4B0_7A7A40)
    Pokemon_SetAnimation(obj, &D_802D3C70_7AD200);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802CE554_7A7AE4);
    pokemon->transitionGraph = D_802D3D24_7AD2B4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802CE440_7A79D0);
    }
    Pokemon_SetStateRandom(obj, &D_802D3D84_7AD314);
}

POKEMON_FUNC(func_802CE554_7A7AE4)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CE5B0_7A7B40)
    Pokemon_SetAnimation(obj, &D_802D3C84_7AD214);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802CE654_7A7BE4);
    pokemon->transitionGraph = D_802D3D24_7AD2B4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802CE440_7A79D0);
    }
    Pokemon_SetStateRandom(obj, &D_802D3D84_7AD314);
}

POKEMON_FUNC(func_802CE654_7A7BE4)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CE6B0_7A7C40)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802D3CAC_7AD23C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3CC0_7AD250);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3CD4_7AD264);
    pokemon->transitionGraph = D_802D3DE4_7AD374;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CE440_7A79D0);
}

POKEMON_FUNC(func_802CE768_7A7CF8)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802D3C98_7AD228);
    pokemon->transitionGraph = D_802D3E14_7AD3A4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CE440_7A79D0);
}

POKEMON_FUNC(func_802CE7D8_7A7D68)
    Pokemon_SetAnimation(obj, &D_802D3C70_7AD200);
    Pokemon_StartPathProc(obj, func_802CE870_7A7E00);
    pokemon->transitionGraph = D_802D3E44_7AD3D4;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802CE440_7A79D0);
    }
    Pokemon_SetState(obj, func_802CE8F4_7A7E84);
}

POKEMON_FUNC(func_802CE870_7A7E00)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    Pokemon_SetAnimation(obj, &D_802D3C84_7AD214);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, 3);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CE8F4_7A7E84)
    Pokemon_SetAnimation(obj, &D_802D3CE8_7AD278);
    pokemon->transitionGraph = D_802D3E94_7AD424;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget != NULL) {
        Pokemon_SetState(obj, func_802CE8F4_7A7E84);
    }
    Pokemon_SetStateRandom(obj, &D_802D3D84_7AD314);
}

POKEMON_FUNC(func_802CE978_7A7F08)
    InteractionHandler4 sp20 = D_802D3EE4_7AD474;

    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->interactionTarget == NULL) {
        Pokemon_SetState(obj, func_802CE440_7A79D0);
    }
    Pokemon_SetState(obj, func_802CE7D8_7A7D68);
}

POKEMON_FUNC(func_802CEA34_7A7FC4)
    Pokemon_SetState(obj, func_802CE7D8_7A7D68);
}

GObj* func_802CEA58_7A7FE8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D3F38_7AD4C8);
}
