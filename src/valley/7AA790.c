#include "valley.h"

extern s32 D_802D2980_7ABF10;
extern GObj* D_802D2D74_7AC304;
extern u16 D_802D2D78_7AC308;
extern GObj* D_802D3FF4_7AD584;
extern s32 D_802D3FF8_7AD588;
extern AnimationHeader D_802EC818_7C5DA8;
extern AnimationHeader D_802EC82C_7C5DBC;
extern AnimationHeader D_802EC840_7C5DD0;
extern AnimationHeader D_802EC854_7C5DE4;
extern u16 D_802EC868_7C5DF8;
extern u16 D_802EC86C_7C5DFC;
extern RandomState D_802EC870_7C5E00;
extern s32 D_802EC890_7C5E20;
extern f32 D_802EC894_7C5E24;
extern InteractionHandler D_802EC898_7C5E28[];
extern InteractionHandler D_802EC8B8_7C5E48[];
extern Vec3f D_802EC8D8_7C5E68;
extern InteractionHandler D_802EC8E4_7C5E74[];
extern Vec3f D_802EC914_7C5EA4;
extern PokemonInitData D_802EC934_7C5EC4;

void func_802D1344_7AA8D4(GObj*);
void func_802D1414_7AA9A4(GObj*);
void func_802D1454_7AA9E4(GObj*);
void func_802D156C_7AAAFC(GObj*);
void func_802D1598_7AAB28(GObj*);
void func_802D15BC_7AAB4C(GObj*);
void func_802D17D8_7AAD68(GObj*);
void func_802D18D8_7AAE68(GObj*);
void func_802D19DC_7AAF6C(GObj*);
void func_802D1ACC_7AB05C(GObj*);
void func_802D1B48_7AB0D8(GObj*);
void func_802D1BC8_7AB158(GObj*);
void func_802D1C40_7AB1D0(GObj*);
void func_802D1D4C_7AB2DC(GObj*);
void func_802D1E3C_7AB3CC(GObj*);
void func_802D1EB8_7AB448(GObj*);
void func_802D1FC0_7AB550(GObj*);
void func_802D2128_7AB6B8(GObj*);

POKEMON_FUNC(func_802D1200_7AA790)
    pokemon->miscVars[0].field1 = 0;
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802D1454_7AA9E4);
    }
    if (pokemon->behavior == 2) {
        Pokemon_SetState(obj, func_802D1598_7AAB28);
    }
    if (pokemon->behavior == 3) {
        Pokemon_SetState(obj, func_802D1BC8_7AB158);
    }
    Pokemon_SetStateRandom(obj, &D_802EC870_7C5E00);
}

POKEMON_FUNC(func_802D129C_7AA82C)
    Pokemon_ForceAnimation(obj, &D_802EC82C_7C5DBC);
    Pokemon_SetState(obj, func_802D1344_7AA8D4);
}

POKEMON_FUNC(func_802D12D4_7AA864)
    Pokemon_ForceAnimation(obj, &D_802EC840_7C5DD0);
    Pokemon_SetState(obj, func_802D1344_7AA8D4);
}

POKEMON_FUNC(func_802D130C_7AA89C)
    Pokemon_ForceAnimation(obj, &D_802EC854_7C5DE4);
    Pokemon_SetState(obj, func_802D1344_7AA8D4);
}

POKEMON_FUNC(func_802D1344_7AA8D4)
    rotation->v.y = (randRange(360) * PI) / 180.0f;
    Pokemon_StartPathProc(obj, func_802D1414_7AA9A4);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->behavior == 1) {
        Pokemon_SetState(obj, func_802D1454_7AA9E4);
    }
    D_802D2980_7ABF10 = 0;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D1414_7AA9A4)
    func_8035E298_4FE6A8(obj);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D1454_7AA9E4)
    Vec3f sp34;
    GroundResult ground;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->counter = randRange(180) + 60, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    if (D_802D2D78_7AC308) {
        Pokemon_SetState(obj, func_802D156C_7AAAFC);
    }
    sp34.x = position->v.x;
    sp34.z = position->v.z;
    getGroundAt(sp34.x, sp34.z, &ground);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    sp34.y = ground.height;
    func_8035E174_4FE584(obj, &sp34);
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetStateRandom(obj, &D_802EC870_7C5E00);
}

POKEMON_FUNC(func_802D156C_7AAAFC)
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D1598_7AAB28)
    Pokemon_SetState(obj, func_802D15BC_7AAB4C);
}

POKEMON_FUNC(func_802D15BC_7AAB4C)
    s32 roll;

    pokemon->tangible = true;
    obj->flags = 0;

    roll = randRange(100);
    if (roll < 20) {
        Pokemon_ForceAnimation(obj, &D_802EC82C_7C5DBC);
    } else if (roll < 70) {
        Pokemon_ForceAnimation(obj, &D_802EC840_7C5DD0);
    } else {
        Pokemon_ForceAnimation(obj, &D_802EC854_7C5DE4);
    }

    Pokemon_StartPathProc(obj, func_802D1414_7AA9A4);
    pokemon->transitionGraph = D_802EC898_7C5E28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->counter = randRange(30) + 30, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_802EC898_7C5E28;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_SetState(obj, func_802D15BC_7AAB4C);
}

POKEMON_FUNC(func_802D16CC_7AAC5C)
    pokemon = obj->userData;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->transitionGraph = D_802EC8B8_7C5E48;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D1734_7AACC4)
    s32 blockCount;
    f32 blockPart;

    getLevelProgress(&blockCount, &blockPart);
    blockPart += blockCount;
    if (pokemon->interactionDist > 400.0f || blockPart > 1.3) {
        Pokemon_SetState(obj, func_802D16CC_7AAC5C);
    }
    Pokemon_SetState(obj, func_802D17D8_7AAD68);
}

POKEMON_FUNC(func_802D17D8_7AAD68)
    pokemon->tangible = true;
    obj->flags = 0;
    pokemon->forbiddenGround = &D_802EC894_7C5E24;
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_1000;
    Pokemon_SetAnimation(obj, &D_802EC818_7C5DA8);
    Pokemon_StartPathProc(obj, func_802D18D8_7AAE68);
    Pokemon_StartAuxProc(obj, func_802D19DC_7AAF6C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_1000);
    if (D_802D3FF8_7AD588 == 0) {
        Pokemon_SetState(obj, func_802D1ACC_7AB05C);
    }

    pokemon->counter = 0x40, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    D_802EC890_7C5E20 = 1;
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, 2);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D18D8_7AAE68)
    Mtx3Float* temp_v1 = &GET_TRANSFORM(D_802D3FF4_7AD584->data.dobj)->pos;
    f32 dx = temp_v1->v.x - position->v.x;
    f32 dz = temp_v1->v.z - position->v.z;
    f32 temp_f20 = atan2f(dx, dz);

    while (D_802EC890_7C5E20 == 0) {
        pokemon->hSpeed = 300.0f;
        pokemon->jumpVel = 500.0f;
        pokemon->facingYaw = temp_f20;
        Pokemon_FallDownOnGround(obj, -24.5f, 1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D19DC_7AAF6C)
    f32 var_f0 = Pokemon_GetDistance(obj, D_802D3FF4_7AD584);

    while (var_f0 > 200.0f) {
        if (!D_802EC868_7C5DF8 && var_f0 < 300.0f) {
            D_802EC868_7C5DF8 = true;
            cmdSendCommand(D_802D3FF4_7AD584, 0x21, obj);
        }
        ohWait(1);
        var_f0 = Pokemon_GetDistance(obj, D_802D3FF4_7AD584);
    }
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_1000;
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802D1ACC_7AB05C)
    EnvSound_PlaySound(obj, 1, 0x183);
    Pokemon_StartPathProc(obj, func_802D1B48_7AB0D8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    D_802EC86C_7C5DFC = true;
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D1B48_7AB0D8)
    rotation->v.y = 1.7453293f;
    pokemon->facingYaw = 1.7453293f;
    pokemon->hSpeed = 800.0f;
    pokemon->jumpVel = 1100.0f;
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D1BC8_7AB158)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    while (!D_802EC86C_7C5DFC) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802D1C40_7AB1D0);
}

POKEMON_FUNC(func_802D1C40_7AB1D0)
    s32 blockCount;
    f32 blockPart;

    while (true) {
        getLevelProgress(&blockCount, &blockPart);
        if (blockCount < 4 && (blockCount != 3 || !(blockPart >= 0.18))) {
            ohWait(1);
        } else {
            break;
        }
    }
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_802D1D4C_7AB2DC);
    Pokemon_StartAuxProc(obj, func_802D1E3C_7AB3CC);
    Pokemon_SetAnimation(obj, &D_802EC818_7C5DA8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_802D1EB8_7AB448);
}

POKEMON_FUNC(func_802D1D4C_7AB2DC)
    Vec3f sp24 = D_802EC8D8_7C5E68;
    WorldBlock* block;
    block = getCurrentWorldBlock();
    GetInterpolatedPosition(&sp24, pokemon->path, *pokemon->path->paramPoints);
    position->v.x = (sp24.x - block->descriptor->worldPos.x) * 100.0f;
    position->v.z = (sp24.z - block->descriptor->worldPos.z) * 100.0f;
    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 0.0f;
    Pokemon_FallDownOnGround(obj, -9.8f, 1);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_802D1E3C_7AB3CC)
    while (pokemon->playerDist > 1950.0f) {
        ohWait(1);
    }
    EnvSound_PlaySound(obj, 1, 0x187);
    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_802D1EB8_7AB448)
    Pokemon_SetAnimation(obj, &D_802EC818_7C5DA8);
    pokemon->transitionGraph = D_802EC8E4_7C5E74;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

static void nullsub() {
}

POKEMON_FUNC(func_802D1F18_7AB4A8)
    pokemon->forbiddenGround = &D_802EC894_7C5E24;
    Pokemon_SetAnimation(obj, &D_802EC818_7C5DA8);
    Pokemon_StartPathProc(obj, func_802D1FC0_7AB550);
    Pokemon_StartAuxProc(obj, func_802D2128_7AB6B8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_AUX_ENDED);
    ohWait(20);
    cmdSendCommand(D_802D2D74_7AC304, 0x1E, obj);
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

POKEMON_FUNC(func_802D1FC0_7AB550)
    Vec3f sp5C = D_802EC914_7C5EA4;
    WorldBlockDescriptor* temp_v1 = getCurrentWorldBlock()->descriptor;
    f32 x;
    f32 z;
    f32 facingYaw;

    x = -(temp_v1->worldPos.x * 100.0f);
    z = -(temp_v1->worldPos.z * 100.0f);
    GetInterpolatedPosition(&sp5C, pokemon->path, 0.99999f);
    x += sp5C.x * 100.0f;
    z += sp5C.z * 100.0f;
    facingYaw = atan2f(x - position->v.x, z - position->v.z);

    while (true) {
        pokemon->hSpeed = 300.0f;
        pokemon->jumpVel = 500.0f;
        pokemon->facingYaw = facingYaw;
        Pokemon_FallDownOnGround(obj, -24.5f, 1);
        EnvSound_PlaySound(obj, 1, 0x181);
        func_8035E174_4FE584(obj, &position->v);
    }
}

POKEMON_FUNC(func_802D2128_7AB6B8)
    Mtx3Float* tmp = &GET_TRANSFORM(D_802D2D74_7AC304->data.dobj)->pos;

    while (position->v.y < tmp->v.y + 100.0f) {
        ohWait(1);
    }
    Pokemon_StopAuxProc(obj);
}

void func_802D21C8_7AB758(s32 arg0, u16 arg1, WorldBlock* arg2, WorldBlock* arg3, ObjectSpawn* arg4) {
    if (arg4->behavior != 3) {
        Pokemon_SpawnOnGround(arg0, arg1, arg2, arg3, arg4, &D_802EC934_7C5EC4);
    } else {
        Pokemon_Spawn(arg0, arg1, arg2, arg3, arg4, &D_802EC934_7C5EC4);
    }
}
