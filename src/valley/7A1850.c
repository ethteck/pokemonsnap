#include "valley.h"

extern AnimationHeader D_802D2AC0_7AC050;
extern AnimationHeader D_802D2AD4_7AC064;
extern AnimationHeader D_802D2AFC_7AC08C;
extern AnimationHeader D_802D2B10_7AC0A0;
extern AnimationHeader D_802D2B24_7AC0B4;
extern AnimationHeader D_802D2B38_7AC0C8;
extern AnimationHeader D_802D2B4C_7AC0DC;
extern AnimationHeader D_802D2B60_7AC0F0;
extern RandomState D_802D2B74_7AC104;
extern GObj* D_802D2B8C_7AC11C;
extern GObj* D_802D2B90_7AC120;
extern InteractionHandler2 D_802D2B94_7AC124;
extern InteractionHandler D_802D2BB4_7AC144;
extern InteractionHandler D_802D2BD4_7AC164;
extern f32 D_802D2BF4_7AC184;
extern f32 D_802D2BF8_7AC188;
extern Vec3f D_802D2BFC_7AC18C;
extern s32 D_802D2C08_7AC198;
extern f32 D_802D2C0C_7AC19C;
extern InteractionHandler3 D_802D2C10_7AC1A0;
extern InteractionHandler3 D_802D2C40_7AC1D0;
extern InteractionHandler3 D_802D2C70_7AC200;
extern PokemonInitData D_802D2CB4_7AC244;

extern f32 D_8034C8D8_825E68;
extern f32 D_8034C8DC_825E6C;

void func_802C8354_7A18E4(GObj*);
void func_802C853C_7A1ACC(GObj*);
void func_802C840C_7A199C(GObj*);
void func_802C84D0_7A1A60(GObj*);
void func_802C8704_7A1C94(GObj*);
void func_802C8764_7A1CF4(GObj*);
void func_802C8828_7A1DB8(GObj*);
void func_802C88C4_7A1E54(GObj*);
void func_802C8998_7A1F28(GObj*);
void func_802C8B38_7A20C8(GObj*);
void func_802C8C08_7A2198(GObj*);
void func_802C8C70_7A2200(GObj*);
void func_802C8D30_7A22C0(GObj*);
void func_802C8E54_7A23E4(GObj*);
void func_802C8EA8_7A2438(GObj*);
void func_802C8F50_7A24E0(GObj*);
void func_802C90E4_7A2674(GObj*);
void func_802C931C_7A28AC(GObj*);
void func_802C9408_7A2998(GObj*);
void func_802C94A4_7A2A34(GObj*);

POKEMON_FUNC(func_802C82C0_7A1850)
    switch (pokemon->behavior) {
        case 1:
            D_802D2B8C_7AC11C = obj;
            Pokemon_SetState(obj, func_802C8354_7A18E4);
            break;
        case 2:
            Pokemon_SetState(obj, func_802C8B38_7A20C8);
            break;
        default:
            Pokemon_SetState(obj, func_802C8C08_7A2198);
            break;
    }
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802C8354_7A18E4)
    InteractionHandler2 sp20 = D_802D2B94_7AC124;

    Pokemon_SetAnimation(obj, &D_802D2B10_7AC0A0);
    Pokemon_StartPathProc(obj, func_802C840C_7A199C);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802C840C_7A199C)
    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C8458_7A19E8)
    pokemon->flags |= POKEMON_FLAG_200;
    Pokemon_SetAnimation(obj, &D_802D2B24_7AC0B4);
    Pokemon_StartPathProc(obj, func_802C84D0_7A1A60);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C853C_7A1ACC);
}

POKEMON_FUNC(func_802C84D0_7A1A60)
    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.033333335f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS | MOVEMENT_FLAG_ON_GROUND);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C853C_7A1ACC)
    Pokemon_SetAnimation(obj, &D_802D2AC0_7AC050);
    pokemon->transitionGraph = &D_802D2BB4_7AC144;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802C8594_7A1B24)
    Pokemon_SetAnimation(obj, &D_802D2B38_7AC0C8);
    pokemon->transitionGraph = &D_802D2BD4_7AC164;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D2B4C_7AC0DC);
    pokemon->transitionGraph = &D_802D2BD4_7AC164;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D2B60_7AC0F0);
    pokemon->transitionGraph = &D_802D2BD4_7AC164;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C853C_7A1ACC);
}

POKEMON_FUNC(func_802C8650_7A1BE0)
    Pokemon_StartPathProc(obj, func_802C8704_7A1C94);
    Pokemon_StartAuxProc(obj, func_802C8764_7A1CF4);
    Pokemon_SetAnimation(obj, &D_802D2AD4_7AC064);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetAnimation(obj, &D_802D2AFC_7AC08C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, 8);
    Pokemon_SetState(obj, func_802C8828_7A1DB8);
}

POKEMON_FUNC(func_802C8704_7A1C94)
    Pokemon_JumpAndBounceFromGround(obj, 200.0f, 1.0f, 0);
    cmdSendCommandToLink(3, 0x27, obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C8764_7A1CF4)
    f32 turnAngle;

    turnAngle = rotation->v.y + PI;
    turnAngle -= (s32) (turnAngle / TAU) * TAU;
    while (!Pokemon_Turn(model, turnAngle, PI / 45)) {
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802C8828_7A1DB8)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_SetAnimation(obj, &D_802D2B10_7AC0A0);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D2B24_7AC0B4);
    Pokemon_StartPathProc(obj, func_802C88C4_7A1E54);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802C8458_7A19E8);
}

POKEMON_FUNC(func_802C88C4_7A1E54)
    pokemon->hSpeed = 20.0f;
    Pokemon_SetTargetPos(obj, pokemon->pos1.x, pokemon->pos1.z);
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C892C_7A1EBC)
    Pokemon_StartPathProc(obj, func_802C8998_7A1F28);
    Pokemon_SetAnimation(obj, &D_802D2B24_7AC0B4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetStateRandom(obj, &D_802D2B74_7AC104);
}

POKEMON_FUNC(func_802C8998_7A1F28)
    pokemon->hSpeed = 20.0f;
    Pokemon_RunInCircles(obj, 500.0f, 0.1f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

f32 func_802C89F4_7A1F84(s32 behavior) {
    f32 ret;

    switch (behavior) {
        default:
            ret = D_802D2BF4_7AC184 + (4 * PI) / 3;
            break;
        case 2:
            ret = D_802D2BF4_7AC184;
            break;
        case 3:
            ret = D_802D2BF4_7AC184 + (2 * PI) / 3;
            break;
    }

    return ret;
}

void func_802C8A4C_7A1FDC(DObj* model, Pokemon* pokemon, Vec3f* arg2) {
    GroundResult ground;
    f32 temp_f0;
    f32 targetYaw;

    temp_f0 = func_802C89F4_7A1F84(pokemon->behavior);
    arg2->x = (__sinf(temp_f0) * 300.0f) + pokemon->pos1.x;
    arg2->z = ((__cosf(temp_f0) * 300.0f) + pokemon->pos1.z);
    getGroundAt(arg2->x, arg2->z, &ground);
    arg2->y = ground.height;
    targetYaw = temp_f0 + D_802D2BF8_7AC188;
    targetYaw -= (s32) (targetYaw / TAU) * TAU;
    Pokemon_Turn(model, targetYaw, PI / 45);
}

POKEMON_FUNC(func_802C8B38_7A20C8)
    s32 blockCount;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount < 3 && (blockCount != 2 || !(blockPart >= 0.6))) {
            ohWait(1);
        } else {
            break;
        }
    }

    while (Items_GetPokeFluteCmd() == 0) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C8C70_7A2200);
}

POKEMON_FUNC(func_802C8C08_7A2198)
    Pokemon_SetAnimation(obj, &D_802D2AC0_7AC050);
    while (D_802D2B90_7AC120 == NULL) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C8D30_7A22C0);
}

POKEMON_FUNC(func_802C8C70_7A2200)
    Vec3f sp1C = D_802D2BFC_7AC18C;
    WorldBlock* block;

    GetInterpolatedPosition(&sp1C, pokemon->path, 0.99999f);
    block = getCurrentWorldBlock();
    D_8034C8D8_825E68 = (sp1C.x * 100.0f) - (block->descriptor->worldPos.x * 100.0f);
    D_8034C8DC_825E6C = (sp1C.z * 100.0f) - (block->descriptor->worldPos.z * 100.0f);
    D_802D2B90_7AC120 = obj;
    Pokemon_SetState(obj, func_802C8D30_7A22C0);
}

POKEMON_FUNC(func_802C8D30_7A22C0)
    Vec3f sp2C;

    pokemon->forbiddenGround = &D_802D2C0C_7AC19C;
    pokemon->pos1.x = D_8034C8D8_825E68;
    pokemon->pos1.z = D_8034C8DC_825E6C;
    func_802C8A4C_7A1FDC(model, pokemon, &sp2C);
    Pokemon_SetTargetPos(obj, sp2C.x, sp2C.z);
    Pokemon_SetAnimation(obj, &D_802D2B24_7AC0B4);
    Pokemon_StartPathProc(obj, func_802C8E54_7A23E4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    if (pokemon->behavior == 2) {
        D_802D2BF8_7AC188 = PI / 2;
        Pokemon_StartAuxProc(obj, func_802C94A4_7A2A34);
    }
    D_802D2C08_7AC198++;
    while (D_802D2C08_7AC198 != 3) {
        ohWait(1);
    }
    pokemon->specialPoseID = 9;
    Pokemon_SetState(obj, func_802C8EA8_7A2438);
}

POKEMON_FUNC(func_802C8E54_7A23E4)
    pokemon->hSpeed = 200.0f;
    Pokemon_RunToTargetPos(obj, 0.1f);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C8EA8_7A2438)
    InteractionHandler3 sp20 = D_802D2C10_7AC1A0;

    Pokemon_SetAnimation(obj, &D_802D2B24_7AC0B4);
    Pokemon_StartPathProc(obj, func_802C8F50_7A24E0);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C8EA8_7A2438);
}

POKEMON_FUNC(func_802C8F50_7A24E0)
    s32 i = 40;

    while (i--) {
        if (pokemon->behavior == 2) {
            D_802D2BF8_7AC188 = PI / 2;
            D_802D2BF4_7AC184 += PI / 360;
        }
        func_802C8A4C_7A1FDC(model, pokemon, &position->v);
        ohWait(1);
    }

    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C903C_7A25CC)
    InteractionHandler3 sp20 = D_802D2C40_7AC1D0;

    Pokemon_SetAnimation(obj, &D_802D2B24_7AC0B4);
    Pokemon_StartPathProc(obj, func_802C90E4_7A2674);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C903C_7A25CC);
}

POKEMON_FUNC(func_802C90E4_7A2674)
    s32 i = 40;

    while (i--) {
        rotation->v.y += PI / 20;
        rotation->v.y -= (s32) (rotation->v.y / TAU) * TAU;
        ohWait(1);
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = NULL;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C91AC_7A273C)
    s32 i;
    InteractionHandler3 sp44 = D_802D2C70_7AC200;

    Pokemon_StartPathProc(obj, func_802C9408_7A2998);

    for (i = 0; i < 2; i++) {
        Pokemon_SetAnimation(obj, &D_802D2B24_7AC0B4);
        pokemon->counter = 24;
        pokemon->transitionGraph = sp44.data;
        pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
        Pokemon_SetAnimation(obj, &D_802D2B38_7AC0C8);
        pokemon->counter = 6;
        pokemon->transitionGraph = sp44.data;
        pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    }

    Pokemon_SetAnimation(obj, &D_802D2B24_7AC0B4);
    Pokemon_StartPathProc(obj, func_802C931C_7A28AC);
    pokemon->transitionGraph = sp44.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C91AC_7A273C);
}

POKEMON_FUNC(func_802C931C_7A28AC)
    s32 i = 40;

    while (i--) {
        if (pokemon->behavior == 2) {
            D_802D2BF8_7AC188 = PI / 2;
            D_802D2BF4_7AC184 += PI / 180;
        }
        func_802C8A4C_7A1FDC(model, pokemon, &position->v);
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802C9408_7A2998)
    while (true) {
        if (pokemon->behavior == 2) {
            D_802D2BF8_7AC188 = PI;
        }
        func_802C8A4C_7A1FDC(model, pokemon, &position->v);
        ohWait(1);
    }
}

POKEMON_FUNC(func_802C94A4_7A2A34)
    s32 cmd;
    s32 oldCmd;

    oldCmd = 5;

    while (true) {
        cmd = Items_GetPokeFluteCmd();
        if (cmd != 0 && oldCmd != cmd) {
            oldCmd = cmd;
            switch (cmd) {
                case 5:
                    cmdSendCommandToLink(3, 0x28, obj);
                    break;
                case 6:
                    cmdSendCommandToLink(3, 0x29, obj);
                    break;
                default:
                    cmdSendCommandToLink(3, 0x2A, obj);
                    break;
            }
        }
        ohWait(1);
    }
}

GObj* func_802C957C_7A2B0C(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D2CB4_7AC244);
}
