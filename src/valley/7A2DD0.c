#include "valley.h"

extern GObj* D_802D2B8C_7AC11C;
extern AnimationHeader D_802D2E48_7AC3D8;
extern AnimationHeader D_802D2E5C_7AC3EC;
extern AnimationHeader D_802D2E84_7AC414;
extern AnimationHeader D_802D2E98_7AC428;
extern AnimationHeader D_802D2EAC_7AC43C;
extern RandomState D_802D2EC0_7AC450;
extern InteractionHandler2 D_802D2ED8_7AC468;
extern InteractionHandler D_802D2EF8_7AC488;
extern PokemonInitData D_802D2F2C_7AC4BC;

void func_802C9840_7A2DD0(GObj*);
void func_802C9990_7A2F20(GObj*);
void func_802C9A48_7A2FD8(GObj*);
void func_802C9B0C_7A309C(GObj*);
void func_802C9F34_7A34C4(GObj*);
void func_802C9B78_7A3108(GObj*);
void func_802C9C84_7A3214(GObj*);
void func_802C9D00_7A3290(GObj*);
void func_802C9DC4_7A3354(GObj*);
void func_802C9E60_7A33F0(GObj*);

POKEMON_FUNC(func_802C9840_7A2DD0)
    if (pokemon->behavior == 1) {
        s32 blockCount;
        f32 blockPart;

        while (true) {
            getLevelProgress(&blockCount, &blockPart);
            if (blockCount < 2 && (blockCount != 1 || !(blockPart >= 0.85))) {
                ohWait(1);
            } else {
                break;
            }
        }
    } else {
        s32 blockCount;
        f32 blockPart;

        while (true) {
            getLevelProgress(&blockCount, &blockPart);
            if (blockCount < 3 && (blockCount != 2 || !(blockPart >= 0.4))) {
                ohWait(1);
            } else {
                break;
            }
        }
    }
    Pokemon_RunCleanup(obj);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802C9958_7A2EE8)
    Pokemon_StartAuxProc(obj, func_802C9840_7A2DD0);
    Pokemon_SetState(obj, func_802C9990_7A2F20);
}

POKEMON_FUNC(func_802C9990_7A2F20)
    InteractionHandler2 sp20 = D_802D2ED8_7AC468;

    Pokemon_SetAnimation(obj, &D_802D2E98_7AC428);
    Pokemon_StartPathProc(obj, func_802C9A48_7A2FD8);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802C9A48_7A2FD8)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C9A94_7A3024)
    pokemon->flags |= POKEMON_FLAG_200;
    Pokemon_SetAnimation(obj, &D_802D2EAC_7AC43C);
    Pokemon_StartPathProc(obj, func_802C9B0C_7A309C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C9B78_7A3108);
}

POKEMON_FUNC(func_802C9B0C_7A309C)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C9B78_7A3108)
    Pokemon_SetAnimation(obj, &D_802D2E48_7AC3D8);
    pokemon->transitionGraph = &D_802D2EF8_7AC488;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802C9BD0_7A3160)
    Pokemon_StartPathProc(obj, func_802C9C84_7A3214);
    Pokemon_StartAuxProc(obj, func_802C9D00_7A3290);
    Pokemon_SetAnimation(obj, &D_802D2E5C_7AC3EC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_802D2E84_7AC414);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED);
    Pokemon_SetState(obj, func_802C9DC4_7A3354);
}

POKEMON_FUNC(func_802C9C84_7A3214)
    Pokemon_JumpAndBounceFromGround(obj, 200.0f, 1.0f, 0.0f);
    if (pokemon->behavior == 2) {
        pokemon = pokemon;
        cmdSendCommand(D_802D2B8C_7AC11C, 0x26, obj);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C9D00_7A3290)
    f32 temp_f20;

    temp_f20 = rotation->v.y + PI;
    temp_f20 -= (s32) (temp_f20 / TAU) * TAU;
    while (!Pokemon_Turn(model, temp_f20, PI / 45)) {
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802C9DC4_7A3354)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802D2E98_7AC428);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D2EAC_7AC43C);
    Pokemon_StartPathProc(obj, func_802C9E60_7A33F0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C9A94_7A3024);
}

POKEMON_FUNC(func_802C9E60_7A33F0)
    pokemon->hSpeed = 20.0f;
    Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C9EC8_7A3458)
    Pokemon_StartPathProc(obj, func_802C9F34_7A34C4);
    Pokemon_SetAnimation(obj, &D_802D2EAC_7AC43C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetStateRandom(obj, &D_802D2EC0_7AC450);
}

POKEMON_FUNC(func_802C9F34_7A34C4)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

GObj* func_802C9F90_7A3520(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D2F2C_7AC4BC);
}
