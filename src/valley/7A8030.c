#include "valley.h"

extern AnimationHeader D_802D3F8C_7AD51C;
extern AnimationHeader D_802D3FA0_7AD530;
extern AnimationHeader D_802D3FB4_7AD544;
extern AnimationHeader D_802D3FC8_7AD558;
extern AnimationHeader D_802D3FDC_7AD56C;
extern GObj* D_802D3FF0_7AD580;
extern GObj* D_802D3FF4_7AD584;
extern s32 D_802D3FF8_7AD588;
extern InteractionHandler D_802D3FFC_7AD58C[];
extern InteractionHandler D_802D401C_7AD5AC[];
extern InteractionHandler2 D_802D404C_7AD5DC;
extern f32 D_802D406C_7AD5FC;
extern InteractionHandler D_802D4070_7AD600[];
extern RandomState D_802D40A0_7AD630[];
extern InteractionHandler D_802D40B0_7AD640[];
extern InteractionHandler D_802D40D0_7AD660[];
extern PokemonInitData D_802D4124_7AD6B4;
extern GObj* D_802D41A4_7AD734;
extern GObj* D_802EC644_7C5BD4;

void func_802CF388_7A8918(GObj*);
void func_802CF500_7A8A90(GObj*);
void func_802CF524_7A8AB4(GObj*);
void func_802CF638_7A8BC8(GObj*);
void func_802CF65C_7A8BEC(GObj*);
void func_802CEB4C_7A80DC(GObj*);
void func_802CED44_7A82D4(GObj*);
void func_802CF114_7A86A4(GObj*);

POKEMON_FUNC(func_802CEAA0_7A8030)
    switch (pokemon->behavior) {
        case 1:
            Pokemon_SetState(obj, func_802CF388_7A8918);
            break;
        case 2:
            D_802D3FF0_7AD580 = obj;
            Pokemon_SetState(obj, func_802CF500_7A8A90);
            break;
        case 3:
            D_802D3FF4_7AD584 = obj;
            Pokemon_SetState(obj, func_802CF638_7A8BC8);
            break;
    }
    Pokemon_SetState(obj, func_802CEB4C_7A80DC);
}

POKEMON_FUNC(func_802CEB4C_7A80DC)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = D_802D3FFC_7AD58C;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CEB9C_7A812C)
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802D3F8C_7AD51C);
    Pokemon_StartPathProc(obj, func_802CED44_7A82D4);
    pokemon->transitionGraph = D_802D401C_7AD5AC;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

f32 func_802CEC18_7A81A8(Vec3f* arg0, Vec3f* arg1) {
    f32 deltaX = arg0->x - arg1->x;
    f32 deltaY = arg0->y - arg1->y;
    f32 deltaZ = arg0->z - arg1->z;
    f32 f2;
    f32 angle;

    if (ABS(deltaZ) < 0.00001) {
        deltaX = 1.0f;
        deltaZ = 0.0f;
    }

    f2 = 1.0f / sqrtf(SQ(deltaX) + SQ(deltaY) + SQ(deltaZ));
    deltaX *= f2;
    deltaZ *= f2;

    angle = atan2f(deltaX, deltaZ);
    if (angle < 0.0f) {
        angle += TAU;
    } else if (angle > TAU) {
        angle -= (s32) (angle / TAU) * TAU;
    }
    return angle;
}

POKEMON_FUNC(func_802CED44_7A82D4)
    Vec3f* playerPos = &GET_TRANSFORM(gPlayerDObj)->pos.v;
    Vec3f* pokemonPos = &GET_TRANSFORM(model)->pos.v;
    f32 targetYaw;
    f32 yaw;
    f32 delta;
    f32 sign;
    f32 turnSpeed = 0.03f;
    f32 x, z;

    while (true) {
        targetYaw = func_802CEC18_7A81A8(playerPos, pokemonPos);

        yaw = GET_TRANSFORM(model)->rot.v.y;
        yaw -= (s32) (yaw / TAU) * TAU;
        if (yaw < 0.0f) {
            yaw += TAU;
        }

        delta = targetYaw - yaw;
        if (ABS(delta) > turnSpeed) {
            if (ABS(delta) < PI) {
                sign = SIGN(delta);
            } else {
                sign = -SIGN(delta);
            }
            targetYaw = yaw + sign * turnSpeed;
        }
        GET_TRANSFORM(model)->rot.v.y = targetYaw;

        if (targetYaw < pokemon->euler.y) {
            pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
        } else {
            pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;
        }

        if (targetYaw < pokemon->euler.y) {
            targetYaw = pokemon->euler.y;
        }

        x = pokemon->pos1.x + sinf(targetYaw) * 500.0f;
        z = pokemon->pos1.z + cosf(targetYaw) * 500.0f;
        GET_TRANSFORM(model)->pos.v.x = x;
        GET_TRANSFORM(model)->pos.v.z = z;
        ohWait(1);
    }
}

POKEMON_FUNC(func_802CEFB8_7A8548)
    InteractionHandler2 sp20 = D_802D404C_7AD5DC;

    Pokemon_StartPathProc(obj, NULL);
    Pokemon_KickItem(obj, 30.0f);
    Pokemon_SetAnimation(obj, &D_802D3FA0_7AD530);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CEB9C_7A812C);
}

POKEMON_FUNC(func_802CF07C_7A860C)
    Pokemon_StartPathProc(obj, NULL);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_1000) {
        Pokemon_SetState(obj, func_802CF114_7A86A4);
    }
    Pokemon_SetAnimation(obj, &D_802D3FC8_7AD558);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3FDC_7AD56C);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CF114_7A86A4)
    if (D_802D41A4_7AD734 != NULL) {
        cmdSendCommand(D_802D41A4_7AD734, 0x1D, obj);
    }
    Pokemon_ForceAnimationAtTime(obj, &D_802D3FB4_7AD544, 0.0f);
    pokemon->pokemonLoopTarget = 1;
    pokemon->transitionGraph = NULL;
    pokemon->lastAnimationFrame = 30.0f;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Camera_StartCutScene(obj, &D_8011C550, D_802D406C_7AD5FC);
    setSkyBoxAnimationSpeed(D_80100730);
    gMainCamera->viewMtx.lookAt.eye.x = -328.82117f;
    gMainCamera->viewMtx.lookAt.eye.y = 200.0f;
    gMainCamera->viewMtx.lookAt.eye.z = 747.35345f;
    gMainCamera->viewMtx.lookAt.at.x = -268.6555f;
    gMainCamera->viewMtx.lookAt.at.y = -174.30309f;
    gMainCamera->viewMtx.lookAt.at.z = 98.58791f;
    if (D_802D41A4_7AD734 != NULL) {
        func_80357150_4F7560(D_802D41A4_7AD734);
        cmdSendCommand(D_802D41A4_7AD734, 0x1D, obj);
    }
    Pokemon_ForceAnimationAtTime(obj, &D_802D3FB4_7AD544, 10.0f);
    pokemon->pokemonLoopTarget = 1;
    pokemon->transitionGraph = NULL;
    pokemon->lastAnimationFrame = 30.0f;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    gMainCamera->viewMtx.lookAt.eye.x = 225.21014f;
    gMainCamera->viewMtx.lookAt.eye.y = 625.0675f;
    gMainCamera->viewMtx.lookAt.eye.z = -10.07608f;
    gMainCamera->viewMtx.lookAt.at.x = -305.68546f;
    gMainCamera->viewMtx.lookAt.at.y = -171.95915f;
    gMainCamera->viewMtx.lookAt.at.z = 81.30422f;
    if (D_802D41A4_7AD734 != NULL) {
        func_80357150_4F7560(D_802D41A4_7AD734);
        cmdSendCommand(D_802D41A4_7AD734, 0x1D, obj);
    }
    Pokemon_ForceAnimationAtTime(obj, &D_802D3FB4_7AD544, 10.0f);
    pokemon->pokemonLoopTarget = 1;
    pokemon->transitionGraph = NULL;
    pokemon->lastAnimationFrame = 59.0f;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (D_802EC644_7C5BD4 != NULL) {
        ohResumeObjectProcesses(D_802EC644_7C5BD4);
        cmdSendCommand(D_802EC644_7C5BD4, 0x20, NULL);
    }
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CF388_7A8918)
    Pokemon_SetAnimation(obj, &D_802D3F8C_7AD51C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D4070_7AD600;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802D40A0_7AD630);
}

POKEMON_FUNC(func_802CF3F8_7A8988)
    Pokemon_SetAnimation(obj, &D_802D3FC8_7AD558);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3FDC_7AD56C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CF48C_7A8A1C)
    Pokemon_KickItem(obj, 30.0f);
    Pokemon_SetAnimation(obj, &D_802D3FA0_7AD530);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, D_802D40A0_7AD630);
}

POKEMON_FUNC(func_802CF500_7A8A90)
    Pokemon_SetState(obj, func_802CF524_7A8AB4);
}

POKEMON_FUNC(func_802CF524_7A8AB4)
    Pokemon_SetAnimation(obj, &D_802D3F8C_7AD51C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D40B0_7AD640;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CF524_7A8AB4);
}

POKEMON_FUNC(func_802CF594_7A8B24)
    Pokemon_SetAnimation(obj, &D_802D3FC8_7AD558);
    pokemon->hSpeed = 400.0f;
    pokemon->jumpVel = 300.0f;
    pokemon->facingYaw = rotation->v.y + PI;
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802CF638_7A8BC8)
    Pokemon_SetState(obj, func_802CF65C_7A8BEC);
}

POKEMON_FUNC(func_802CF65C_7A8BEC)
    Pokemon_SetAnimation(obj, &D_802D3F8C_7AD51C);
    Pokemon_StartPathProc(obj, NULL);
    pokemon->transitionGraph = D_802D40D0_7AD660;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CF65C_7A8BEC);
}

POKEMON_FUNC(func_802CF6CC_7A8C5C)
    Pokemon_SetAnimation(obj, &D_802D3FA0_7AD530);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CF65C_7A8BEC);
}

POKEMON_FUNC(func_802CF720_7A8CB0)
    Pokemon_StartPathProc(obj, NULL);
    Pokemon_KickItem(obj, 30.0f);
    Pokemon_SetAnimation(obj, &D_802D3FA0_7AD530);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802CF65C_7A8BEC);
}

POKEMON_FUNC(func_802CF794_7A8D24)
    D_802D3FF8_7AD588 = 1;
    Pokemon_SetAnimation(obj, &D_802D3FC8_7AD558);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetAnimation(obj, &D_802D3FDC_7AD56C);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802CF808_7A8D98(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_802D4124_7AD6B4);
}
