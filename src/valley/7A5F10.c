#include "valley.h"

extern f32 D_802D2828_7ABDB8;
extern AnimationHeader D_802D3808_7ACD98;
extern AnimationHeader D_802D381C_7ACDAC;
extern f32 D_802D3844_7ACDD4;
extern s32 D_802D3848_7ACDD8;
extern f32 D_802D384C_7ACDDC;
extern InteractionHandler D_802D3850_7ACDE0[];
extern InteractionHandler2 D_802D3880_7ACE10;
extern InteractionHandler D_802D38A0_7ACE30[];
extern InteractionHandler D_802D38E0_7ACE70[];
extern PokemonInitData D_802D3914_7ACEA4;
extern GObj* D_802D3B34_7AD0C4;

void func_802CCB34_7A60C4(GObj*);
void func_802CCC90_7A6220(GObj*);
void func_802CCCFC_7A628C(GObj*);
void func_802CCE70_7A6400(GObj*);
void func_802CD118_7A66A8(GObj*);
void func_802CD1AC_7A673C(GObj*);
void func_802CD2A8_7A6838(GObj*);
void func_802CD2FC_7A688C(GObj*);
void func_802CD4F4_7A6A84(GObj*);
void func_802CD5D8_7A6B68(GObj*);

void func_802CC980_7A5F10(s32 arg0, Vec3f* arg1, f32* arg2) {
    switch (arg0) {
        case 1:
            *arg2 = D_802D2828_7ABDB8;
            break;
        case 2:
            *arg2 = (PI / 9 * D_802D3844_7ACDD4) + D_802D2828_7ABDB8;
            break;
        default:
            *arg2 = (2 * PI / 9 * D_802D3844_7ACDD4) + D_802D2828_7ABDB8;
            break;
    }

    arg1->x = (__sinf(*arg2) * 500.0f) + GET_TRANSFORM(gPlayerDObj)->pos.v.x;
    arg1->z = (__cosf(*arg2) * 500.0f) + GET_TRANSFORM(gPlayerDObj)->pos.v.z;
}

POKEMON_FUNC(func_802CCA70_7A6000)
    if (pokemon->behavior != 0) {
        Pokemon_SetState(obj, func_802CCB34_7A60C4);
    }
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CCAB4_7A6044)
    f32 temp_f20 = (2.0f * randFloat()) + 2.0f;

    while (true) {
        rotation->v.y += temp_f20 * PI / 180.0f;
        ohWait(1);
    }
}

POKEMON_FUNC(func_802CCB34_7A60C4)
    InteractionHandler2 sp20 = D_802D3880_7ACE10;

    pokemon->forbiddenGround = &D_802D384C_7ACDDC;
    Pokemon_SetAnimation(obj, &D_802D3808_7ACD98);
    Pokemon_StartAuxProc(obj, func_802CCAB4_7A6044);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CCBF8_7A6188)
    Pokemon_StartPathProc(obj, func_802CCC90_7A6220);
    pokemon->transitionGraph = D_802D38A0_7ACE30;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    pokemon->counter = 300, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802D38A0_7ACE30;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetState(obj, func_802CCCFC_7A628C);
}

POKEMON_FUNC(func_802CCC90_7A6220)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 1.0f, 0.08f, 0.1f, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CCCFC_7A628C)
    Pokemon_StartAuxProc(obj, func_802CD5D8_7A6B68);
    pokemon->miscVars[0].field0 = 3000.0f;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    pokemon->transitionGraph = D_802D38E0_7ACE70;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_1000);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CCD80_7A6310)
    pokemon->miscVars[0].field0 = 3000.0f;
    pokemon->transitionGraph = NULL;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_1000);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CCDDC_7A636C)
    Pokemon_StartAuxProc(obj, func_802CD5D8_7A6B68);
    pokemon->miscVars[0].field0 = 100.0f;
    Pokemon_SetAnimation(obj, &D_802D381C_7ACDAC);
    Pokemon_StartPathProc(obj, func_802CCE70_7A6400);
    pokemon->transitionGraph = D_802D3850_7ACDE0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802CD118_7A66A8);
}

POKEMON_FUNC(func_802CCE70_7A6400)
    f32 var_f2;
    Vec3f sp80;
    f32 temp_f0_2;
    Mtx3Float* playerPos = &GET_TRANSFORM(gPlayerDObj)->pos;

    pokemon->hSpeed = 600.0f;

    while (true) {
        Pokemon_SetTargetPos(obj, playerPos->v.x, playerPos->v.z);
        Pokemon_StepToTargetPos(obj, 0.1f, 0);
        if (SQ(playerPos->v.x - position->v.x) + SQ(playerPos->v.z - position->v.z) < 250000.0f) {
            break;
        }
        ohWait(1);
    }

    temp_f0_2 = atan2f(position->v.x - playerPos->v.x, position->v.z - playerPos->v.z);
    if (temp_f0_2 < 0.0f) {
        temp_f0_2 += TAU;
    }

    while (true) {
        ohWait(1);
        position->v.x = (__sinf(temp_f0_2) * 500.0f) + playerPos->v.x;
        position->v.z = (__cosf(temp_f0_2) * 500.0f) + playerPos->v.z;
        var_f2 = D_802D2828_7ABDB8 - temp_f0_2;
        if (var_f2 > PI) {
            var_f2 -= TAU;
        }
        if (var_f2 < 0.0f && var_f2 > -(PI / 36)) {
            break;
        }
    }

    while (true) {
        ohWait(1);
        pokemon->hSpeed = 1200.0f;
        func_802CC980_7A5F10(pokemon->behavior, &sp80, &pokemon->miscVars[1].field0);
        // required to match
        if (&sp80) {
        }
        Pokemon_SetTargetPos(obj, sp80.x, sp80.z);

        if (Pokemon_StepToTargetPos(obj, 0.1f, 0) != 0) {
            break;
        }
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CD0B8_7A6648)
    if (randRange(2) != 0) {
        Pokemon_SetAnimation(obj, &D_802D3808_7ACD98);
    } else {
        Pokemon_SetAnimation(obj, &D_802D381C_7ACDAC);
    }
    Pokemon_SetState(obj, func_802CD118_7A66A8);
}

POKEMON_FUNC(func_802CD118_7A66A8)
    pokemon->miscVars[0].field0 = -50.0f;
    Pokemon_StartPathProc(obj, func_802CD1AC_7A673C);
    pokemon->transitionGraph = D_802D3850_7ACDE0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802CD0B8_7A6648);
    }
    Pokemon_SetState(obj, func_802CD2A8_7A6838);
}

POKEMON_FUNC(func_802CD1AC_7A673C)
    s32 blockCount;
    f32 blockPart;

    while (true) {
        func_802CC980_7A5F10(pokemon->behavior, &position->v, &pokemon->miscVars[1].field0);
        getLevelProgress(&blockCount, &blockPart);
        blockPart += blockCount;
        if (blockPart >= 5.5 && D_802D3B34_7AD0C4 != NULL) {
            break;
        }
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CD2A8_7A6838)
    Pokemon_StartPathProc(obj, func_802CD2FC_7A688C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802CD4F4_7A6A84);
}

POKEMON_FUNC(func_802CD2FC_7A688C)
    f32 temp_f0;
    f32 var_f2;
    Mtx3Float* temp_s0;
    Mtx3Float* temp_s2;

    temp_s2 = &GET_TRANSFORM(gPlayerDObj)->pos;
    temp_s0 = &GET_TRANSFORM(D_802D3B34_7AD0C4->data.dobj)->pos;

    while (true) {
        func_802CC980_7A5F10(pokemon->behavior, &position->v, &pokemon->miscVars[1].field0);
        temp_f0 = atan2f(temp_s0->v.x - temp_s2->v.x, temp_s0->v.z - temp_s2->v.z);
        var_f2 = pokemon->miscVars[1].field0;
        if (var_f2 > PI) {
            var_f2 -= TAU;
        }
        var_f2 -= temp_f0;

        if (ABS(var_f2) < PI / 60) {
            break;
        }

        if (D_802D3844_7ACDD4 < 4.0f) {
            D_802D3844_7ACDD4 += 0.03f;
        }
        ohWait(1);
    }

    pokemon->miscVars[0].field0 = 1000.0f;
    do {
        ohWait(1);
        pokemon->hSpeed = 1200.0f;
        Pokemon_SetTargetPos(obj, temp_s0->v.x, temp_s0->v.z);
    } while (Pokemon_StepToTargetPos(obj, 0.1f, 0) == 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CD4F4_7A6A84)
    pokemon->miscVars[0].field0 = -400.0f;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_1000);
    switch (D_802D3848_7ACDD8) {
        case 0:
            cmdSendCommandToLink(3, 0x22, obj);
            break;
        case 1:
            cmdSendCommandToLink(3, 0x23, obj);
            break;
        default:
            cmdSendCommandToLink(3, 0x24, obj);
            break;
    }
    D_802D3848_7ACDD8++;
    cmdSendCommand(D_802D3B34_7AD0C4, 0x25, obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CD5D8_7A6B68)
    GroundResult ground;
    f32 diff;
    f32 delta;

    getGroundAt(position->v.x, position->v.z, &ground);
    delta = position->v.y - ground.height;

    while (true) {
        diff = delta - pokemon->miscVars[0].field0;

        if (ABS(diff) < 20.0f) {
            delta = pokemon->miscVars[0].field0;
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;
        } else if (diff < 0) {
            delta += 20.0f;
        } else {
            delta -= 20.0f;
        }
        getGroundAt(position->v.x, position->v.z, &ground);
        position->v.y = ground.height + delta;
        ohWait(1);
    }
}

GObj* func_802CD704_7A6C94(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802D3914_7ACEA4);
}

GObj* func_802CD73C_7A6CCC(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802D3914_7ACEA4);
}

POKEMON_FUNC(func_802CD774_7A6D04)
    if (pokemon->behavior == 0) {
        pokemonRemoveOne(obj);
    }
}
