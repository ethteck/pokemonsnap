#include "valley.h"

extern AnimationHeader D_802D3450_7AC9E0;
extern AnimationHeader D_802D3464_7AC9F4;
extern AnimationHeader D_802D3478_7ACA08;
extern AnimationHeader D_802D348C_7ACA1C;
extern AnimationHeader D_802D34A0_7ACA30;
extern AnimationHeader D_802D34B4_7ACA44;
extern AnimationHeader D_802D34C8_7ACA58;
extern AnimationHeader D_802D34DC_7ACA6C;
extern AnimationHeader D_802D34F0_7ACA80;
extern AnimationHeader D_802D3504_7ACA94;
extern AnimationHeader D_802D3518_7ACAA8;
extern AnimationHeader D_802D352C_7ACABC;
extern AnimationHeader D_802D3540_7ACAD0;
extern AnimationHeader D_802D3554_7ACAE4;
extern InteractionHandler D_802D3568_7ACAF8[];
extern RandomState D_802D3608_7ACB98[];
extern f32 D_802D3638_7ACBC8;
extern InteractionHandler D_802D363C_7ACBCC[];
extern InteractionHandler D_802D366C_7ACBFC[];
extern InteractionHandler D_802D369C_7ACC2C[];
extern InteractionHandler D_802D36CC_7ACC5C[];
extern InteractionHandler D_802D370C_7ACC9C[];
extern InteractionHandler D_802D372C_7ACCBC[];
extern InteractionHandler D_802D374C_7ACCDC[];
extern InteractionHandler D_802D376C_7ACCFC[];
extern InteractionHandler D_802D378C_7ACD1C[];
extern PokemonInitData D_802D37C0_7ACD50;
extern GObj* D_802D3FF0_7AD580;

void func_802CB110_7A46A0(GObj*);
void func_802CB238_7A47C8(GObj*);
void func_802CB338_7A48C8(GObj*);
void func_802CB550_7A4AE0(GObj*);
void func_802CB6F8_7A4C88(GObj*);
void func_802CB79C_7A4D2C(GObj*);
void func_802CB88C_7A4E1C(GObj*);
void func_802CB8D8_7A4E68(GObj*);
void func_802CB9BC_7A4F4C(GObj*);
void func_802CBA24_7A4FB4(GObj*);
void func_802CBA90_7A5020(GObj*);
void func_802CBBDC_7A516C(GObj*);
void func_802CBCDC_7A526C(GObj*);
void func_802CBE14_7A53A4(GObj*);
void func_802CBE9C_7A542C(GObj*);
void func_802CBF18_7A54A8(GObj*);
void func_802CBF64_7A54F4(GObj*);
void func_802CBFDC_7A556C(GObj*);
void func_802CC068_7A55F8(GObj*);
void func_802CC08C_7A561C(GObj*);
void func_802CC1E0_7A5770(GObj*);
void func_802CC250_7A57E0(GObj*);
void func_802CC2B4_7A5844(GObj*);
void func_802CC3B4_7A5944(GObj*);
void func_802CC424_7A59B4(GObj*);
void func_802CC514_7A5AA4(GObj*);
void func_802CC5C0_7A5B50(GObj*);

POKEMON_FUNC(func_802CB080_7A4610)
    switch (pokemon->behavior) {
        case 1:
            Pokemon_SetState(obj, func_802CB8D8_7A4E68);
            break;
        case 2:
            Pokemon_SetState(obj, func_802CC068_7A55F8);
            break;
        default:
            Pokemon_SetState(obj, func_802CC2B4_7A5844);
            break;
    }
    Pokemon_SetState(obj, func_802CB110_7A46A0);
}

POKEMON_FUNC(func_802CB110_7A46A0)
    pokemon->flags |= POKEMON_FLAG_200;
    pokemon->flags |= POKEMON_FLAG_800;

    Pokemon_SetAnimation(obj, &D_802D3450_7AC9E0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D3568_7ACAF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802D3608_7ACB98);
}

POKEMON_FUNC(func_802CB194_7A4724)
    Pokemon_SetAnimation(obj, &D_802D348C_7ACA1C);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802CB238_7A47C8);
    pokemon->transitionGraph = D_802D3568_7ACAF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802CB110_7A46A0);
    }
    Pokemon_SetStateRandom(obj, D_802D3608_7ACB98);
}

POKEMON_FUNC(func_802CB238_7A47C8)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CB294_7A4824)
    Pokemon_SetAnimation(obj, &D_802D34A0_7ACA30);
    pokemon->pokemonLoopTarget = 5;
    Pokemon_StartPathProc(obj, func_802CB338_7A48C8);
    pokemon->transitionGraph = D_802D3568_7ACAF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_802CB110_7A46A0);
    }
    Pokemon_SetStateRandom(obj, D_802D3608_7ACB98);
}

POKEMON_FUNC(func_802CB338_7A48C8)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CB394_7A4924)
    Pokemon_ForceAnimation(obj, &D_802D3464_7AC9F4);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D3568_7ACAF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802D3608_7ACB98);
}

POKEMON_FUNC(func_802CB404_7A4994)
    Pokemon_ForceAnimation(obj, &D_802D3478_7ACA08);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D3568_7ACAF8;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802D3608_7ACB98);
}

POKEMON_FUNC(func_802CB474_7A4A04)
    Pokemon_SetAnimation(obj, &D_802D34C8_7ACA58);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D34DC_7ACA6C);
    pokemon->pokemonLoopTarget = 3;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D34F0_7ACA80);
    pokemon->transitionGraph = D_802D363C_7ACBCC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_802CB550_7A4AE0);
    pokemon->transitionGraph = D_802D363C_7ACBCC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802CB110_7A46A0);
}

POKEMON_FUNC(func_802CB550_7A4AE0)
    pokemon->hSpeed = 80.0f;
    Pokemon_RunAwayFromTarget(obj, 300.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CB5AC_7A4B3C)
    Pokemon_SetAnimation(obj, &D_802D34B4_7ACA44);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CB110_7A46A0);
}

POKEMON_FUNC(func_802CB614_7A4BA4)
    Pokemon_SetAnimation(obj, &D_802D348C_7ACA1C);
    Pokemon_StartPathProc(obj, func_802CB6F8_7A4C88);
    pokemon->transitionGraph = D_802D366C_7ACBFC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_TARGET_REACHED)) {
        Pokemon_SetState(obj, func_802CB110_7A46A0);
    }
    Pokemon_SetAnimation(obj, &D_802D3518_7ACAA8);
    Pokemon_StartPathProc(obj, func_802CB79C_7A4D2C);
    pokemon->transitionGraph = D_802D366C_7ACBFC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_EatApple(obj);
    Pokemon_SetState(obj, func_802CB110_7A46A0);
}

POKEMON_FUNC(func_802CB6F8_7A4C88)
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    Pokemon_SetAnimation(obj, &D_802D3504_7ACA94);
    Pokemon_WaitForFlagNoInteraction(obj, 1);
    Pokemon_SetAnimation(obj, &D_802D34A0_7ACA30);
    pokemon->hSpeed = 80.0f;
    Pokemon_RunToTarget(obj, 50.0f, 0.1f, 3);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CB79C_7A4D2C)
    while (true) {
        Pokemon_TurnToTarget(obj, 0.1f, 0);
        ohWait(1);
    }
}

POKEMON_FUNC(func_802CB7F4_7A4D84)
    Pokemon_SetState(obj, func_802CB614_7A4BA4);
}

POKEMON_FUNC(func_802CB818_7A4DA8)
    Pokemon_SetAnimation(obj, &D_802D348C_7ACA1C);
    Pokemon_StartPathProc(obj, func_802CB88C_7A4E1C);
    pokemon->transitionGraph = D_802D369C_7ACC2C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802CB110_7A46A0);
}

POKEMON_FUNC(func_802CB88C_7A4E1C)
    Pokemon_TurnToTarget(obj, 0.1f, 0x2E);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CB8D8_7A4E68)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->miscVars[0].field1 = 0;
    pokemon->transitionGraph = D_802D370C_7ACC9C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CB92C_7A4EBC)
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802D3540_7ACAD0);
    Pokemon_StartPathProc(obj, func_802CBA24_7A4FB4);
    Pokemon_StartAuxProc(obj, func_802CBA90_7A5020);
    pokemon->transitionGraph = D_802D36CC_7ACC5C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802CB9BC_7A4F4C);
}

POKEMON_FUNC(func_802CB9BC_7A4F4C)
    pokemon->miscVars[0].field1 = 1;
    Pokemon_StartPathProc(obj, func_802CBBDC_7A516C);
    pokemon->transitionGraph = 0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CBA24_7A4FB4)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_FIXED_HEIGHT);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CBA90_7A5020)
    f32 var_f20;
    f32 var_f22;
    f32 temp;
    GroundResult ground;

    var_f22 = -50.0f;
    var_f20 = 0.0f;

    while (pokemon->miscVars[0].field1 == 0) {
        getGroundAt(position->v.x, position->v.z, &ground);
        temp = (__sinf(var_f20) * 10.0f) + var_f22;
        position->v.y = (ground.height + temp) - 45.0f;
        var_f20 = var_f20 + (2 * PI) / 45;
        var_f20 = var_f20 - ((f32) (s32) (var_f20 / TAU) * TAU);
        if (var_f22 >= 0.0f) {
            var_f22 = 0;
        } else {
            var_f22 += 2.0;
        }
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802CBBDC_7A516C)
    s32 i;

    for (i = 19; i != 0; i--) {
        position->v.y -= 2.0;
        ohWait(1);
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CBC74_7A5204)
    pokemon->miscVars[0].field1 = 1;
    Pokemon_StartPathProc(obj, func_802CBCDC_7A526C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CBCDC_7A526C)
    s32 i = 20;

    while (i--) {
        position->v.y -= 0.5;
        ohWait(1);
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CBD74_7A5304)
    pokemon->miscVars[0].field1 = 1;
    pokemon->forbiddenGround = &D_802D3638_7ACBC8;
    Pokemon_StartPathProc(obj, func_802CBE14_7A53A4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->currGround.surfaceType == SURFACE_TYPE_337FB2 || pokemon->currGround.surfaceType == SURFACE_TYPE_007F66) {
        Pokemon_SetState(obj, func_802CBF64_7A54F4);
    }
    Pokemon_SetState(obj, func_802CBE9C_7A542C);
}

#ifdef NON_MATCHING
POKEMON_FUNC(func_802CBE14_7A53A4)
    void* temp_v1;

    pokemon->hSpeed = 600.0f;
    pokemon->jumpVel = 150.0f;
    temp_v1 = pokemon->interactionTarget->userData;
    pokemon->facingYaw = atan2f(temp_v1->unk_14, temp_v1->unk_1C);
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CBE14_7A53A4.s")
#endif

POKEMON_FUNC(func_802CBE9C_7A542C)
    Pokemon_SetAnimation(obj, &D_802D3554_7ACAE4);
    Pokemon_StartPathProc(obj, func_802CBF18_7A54A8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->behavior = 0;
    pokemon->forbiddenGround = NULL;
    Pokemon_SetState(obj, func_802CB110_7A46A0);
}

POKEMON_FUNC(func_802CBF18_7A54A8)
    Pokemon_TurnToTarget(obj, 0.1f, 0x20);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CBF64_7A54F4)
    EnvSound_PlaySound(obj, 1, 0x17C);
    func_8035E1D4_4FE5E4(obj);
    Pokemon_StartPathProc(obj, func_802CBFDC_7A556C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CBFDC_7A556C)
    s32 i = 20;

    while (i--) {
        position->v.y -= 5.0f;
        ohWait(1);
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CC068_7A55F8)
    Pokemon_SetState(obj, func_802CC08C_7A561C);
}

POKEMON_FUNC(func_802CC08C_7A561C)
    pokemon->forbiddenGround = &D_802D3638_7ACBC8;
    Pokemon_SetAnimation(obj, &D_802D3450_7AC9E0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D372C_7ACCBC;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CC104_7A5694)
    Pokemon_TurnToTarget(obj, 0.1f, 0x20);
    Pokemon_SetAnimation(obj, &D_802D3504_7ACA94);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_StartPathProc(obj, func_802CC1E0_7A5770);
    Pokemon_StartAuxProc(obj, func_802CC250_7A57E0);
    Pokemon_SetAnimation(obj, &D_802D352C_7ACABC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    EnvSound_PlaySound(obj, 1, 0x185);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CC1E0_7A5770)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 1.0f, 0.1, 0.1f, 0x12);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802CC250_7A57E0)
    GroundResult ground;

    while (true) {
        getGroundAt(position->v.x, position->v.z, &ground);
        position->v.y = ground.height;
        ohWait(1);
    }
}

POKEMON_FUNC(func_802CC2B4_7A5844)
    Pokemon_SetAnimation(obj, &D_802D3450_7AC9E0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D376C_7ACCFC;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CC320_7A58B0)
    Pokemon_TurnToTarget(obj, 0.1f, 0x20);
    Pokemon_SetAnimation(obj, &D_802D3504_7ACA94);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->interactionTarget = D_802D3FF0_7AD580;
    Pokemon_TurnToTarget(obj, 0.1f, 0);
    Pokemon_SetState(obj, func_802CC424_7A59B4);
}

POKEMON_FUNC(func_802CC3B4_7A5944)
    Pokemon_SetAnimation(obj, &D_802D3450_7AC9E0);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D374C_7ACCDC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CC424_7A59B4);
}

POKEMON_FUNC(func_802CC424_7A59B4)
    Pokemon_SetAnimation(obj, &D_802D352C_7ACABC);
    pokemon->transitionGraph = D_802D378C_7ACD1C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->counter = 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802D378C_7ACD1C;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3554_7ACAE4);
    pokemon->transitionGraph = D_802D374C_7ACCDC;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CC3B4_7A5944);
}

POKEMON_FUNC(func_802CC4DC_7A5A6C)
    Pokemon_SetAnimation(obj, &D_802D352C_7ACABC);
    Pokemon_SetState(obj, func_802CC514_7A5AA4);
}

POKEMON_FUNC(func_802CC514_7A5AA4)
    s32 temp_v0_2;

    pokemon->forbiddenGround = &D_802D3638_7ACBC8;
    EnvSound_PlaySound(obj, 1, 0x185);
    Pokemon_StartPathProc(obj, func_802CC5C0_7A5B50);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->currGround.surfaceType == SURFACE_TYPE_337FB2 || pokemon->currGround.surfaceType == SURFACE_TYPE_007F66) {
        Pokemon_SetState(obj, func_802CBF64_7A54F4);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/valley/7A4610/func_802CC5C0_7A5B50.s")

GObj* func_802CC8A8_7A5E38(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D37C0_7ACD50);
}

void func_802CC8E0_7A5E70(GObj* obj, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    if (GET_POKEMON(obj)->behavior == 1) {
        pokemonChangeBlock(obj, arg1, arg2, arg3, arg4, arg5, arg6);
    } else {
        pokemonChangeBlockOnGround(obj, arg1, arg2, arg3, arg4, arg5, arg6);
    }
}
