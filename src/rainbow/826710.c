#include "common.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "rainbow.h"

typedef struct Unk8 {
    /* 0x00 */ s32 unk_00[2];
} Unk8;

typedef struct Unks16 {
    /* 0x00 */ s16 unk_00[3];
} Unks16;

extern f32 D_800F5DB0;
extern AnimCmd* D_801183E0;
extern AnimCmd** D_80119050;
extern AnimCmd D_80119A8C;

extern GObj* D_8034AB94_82A304;
extern GObj* D_8034AB98_82A308;
extern s32 D_8034AB9C_82A30C;
extern AnimationHeader D_8034ACB0_82A420;
extern AnimationHeader D_8034ACC4_82A434;
extern AnimationHeader D_8034ACD8_82A448;
extern AnimationHeader D_8034ACEC_82A45C;
extern AnimationHeader D_8034AD00_82A470;
extern AnimationHeader D_8034AD14_82A484;
extern AnimationHeader D_8034AD28_82A498;
extern AnimationHeader D_8034AD3C_82A4AC;
extern InteractionHandler D_8034AD50_82A4C0[];
extern InteractionHandler D_8034AD90_82A500[];
extern InteractionHandler D_8034ADD0_82A540[];
extern InteractionHandler D_8034AE10_82A580[];
extern RandomState D_8034AE30_82A5A0[];
extern s32 D_8034AE48_82A5B8;
extern s32 D_8034AE4C_82A5BC;
extern f32 D_8034AE50_82A5C0;
extern f32 D_8034AE54_82A5C4;
extern f32 D_8034AE58_82A5C8;
extern s32 D_8034AE5C_82A5CC;
extern Unk8 D_8034AE60_82A5D0;
extern UNK_TYPE D_8034AE68_82A5D8;
extern UNK_TYPE D_8034AE78_82A5E8;
extern PokemonInitData D_8034AE90_82A600;

// file split

extern AnimationHeader D_8034AED0_82A640;
extern AnimationHeader D_8034AEE4_82A654;
extern AnimationHeader D_8034AEF8_82A668;
extern AnimationHeader D_8034AF0C_82A67C;
extern CollisionModel D_8034AF20_82A690;
extern GObj* D_8034AF2C_82A69C;
extern s32 D_8034AF30_82A6A0;
extern s32 D_8034AF34_82A6A4;
extern s32 D_8034AF38_82A6A8;
extern InteractionHandler D_8034AF3C_82A6AC[];
extern Unks16 D_8034AF5C_82A6CC;
extern PokemonInitData D_8034AF78_82A6E8;
extern PokemonDef D_8034AFAC_82A71C;

extern f32 D_80350188_82F8F8;
extern f32 D_8035018C_82F8FC;
extern bool D_80350190_82F900;
extern s32 D_80350194_82F904;
extern s32 D_80350198_82F908;

void func_803467A4_825F14(GObj*);
void func_80347188_8268F8(GObj*);
void func_803471D4_826944(GObj*);
void func_80347334_826AA4(GObj*);
void func_80347398_826B08(GObj*);
void func_80347724_826E94(GObj*);
void func_80347900_827070(GObj*);
void func_80347940_8270B0(GObj*);
void func_8034799C_82710C(GObj*);
void func_80347CC8_827438(GObj*);
void func_80347E0C_82757C(GObj*);
void func_80347E44_8275B4(GObj*);
void func_8034800C_82777C(GObj*);
void func_803480C0_827830(GObj*);
void func_803482EC_827A5C(GObj*);
void func_80348540_827CB0(GObj*);
void func_803487CC_827F3C(GObj*);
void func_80348850_827FC0(GObj*);
void func_80348994_828104(GObj*);
void func_80348B34_8282A4(GObj*);
void func_80348DD4_828544(GObj*);
void func_80349084_8287F4(GObj*);

POKEMON_FUNC(func_80346FA0_826710)
    Unk8 sp40;
    s32 i;
    s32 var_s0;

    sp40 = D_8034AE60_82A5D0;

    for (i = 0; i < (u32) ARRAY_COUNT(sp40.unk_00); i++) {
        var_s0 = sp40.unk_00[i];
        while (var_s0--) {
            ohWait(1);
        }
        D_8034AB9C_82A30C = 0x6D37F;
    }

    D_8034AB9C_82A30C = 0x65B7F;
    omCreateProcess(obj, func_80349084_8287F4, 1, 1);
    while (D_8034AE5C_82A5CC == 0) {
        if (D_8034AF38_82A6A8 != 0) {
            cmdSendCommand(obj, RAINBOW_CMD_35, obj);
        }
        ohWait(1);
    }

    Pokemon_StopAuxProc(obj);
}

POKEMON_FUNC(func_803470CC_82683C)
    Pokemon_StartAuxProc(obj, func_80346FA0_826710);
    Pokemon_StartPathProc(obj, func_80347188_8268F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    omCreateProcess(obj, func_803467A4_825F14, 1, 1);
    D_80350188_82F8F8 = position->v.y;
    D_8035018C_82F8FC = position->v.z;
    pokemon->specialPoseID = 0;
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetState(obj, func_803471D4_826944);
}

POKEMON_FUNC(func_80347188_8268F8)
    Pokemon_TurnToTarget(obj, TAU, MOVEMENT_FLAG_TURN_TO_PLAYER);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_803471D4_826944)
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    D_8034AE50_82A5C0 = randRange(360) * TAU / 360.0f;
    D_8034AE58_82A5C8 = randRange(180) * PI / 180.0f;

    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_30, obj);
    Pokemon_StartPathProc(obj, func_80347398_826B08);
    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_8034ACD8_82A448);
    pokemon->transitionGraph = D_8034AD50_82A4C0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_80347334_826AA4);
}

POKEMON_FUNC(func_80347334_826AA4)
    D_80350190_82F900 = false;
    Pokemon_SetAnimation(obj, &D_8034ACB0_82A420);
    pokemon->transitionGraph = D_8034AD50_82A4C0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_8034AE30_82A5A0);
}

POKEMON_FUNC(func_80347398_826B08)
    f32 var_f20 = 1.0f;

    while (true) {
        var_f20 += randFloat() - 0.5;
        if (var_f20 < 1.0f) {
            var_f20 = 1.0f;
        } else if (var_f20 > 4.0f) {
            var_f20 = 4.0f;
        }

        position->v.x = sinf(D_8034AE50_82A5C0) * 200.0f;
        D_8034AE50_82A5C0 += var_f20 * PI / 180.0f;
        D_8034AE50_82A5C0 -= (s32) (D_8034AE50_82A5C0 / TAU) * TAU;

        position->v.z = sinf(D_8034AE58_82A5C8) * 150.0f + D_8035018C_82F8FC;
        D_8034AE58_82A5C8 += (PI / 225.0); // 0.8 deg
        D_8034AE58_82A5C8 -= (s32) (D_8034AE58_82A5C8 / TAU) * TAU;

        ohWait(1);
    }
}

POKEMON_FUNC(func_80347574_826CE4)
    Pokemon_SetAnimation(obj, &D_8034ACC4_82A434);
    pokemon->transitionGraph = D_8034AD50_82A4C0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetStateRandom(obj, D_8034AE30_82A5A0);
}

POKEMON_FUNC(func_803475D0_826D40)
    if (--D_8034AE48_82A5B8 != 0) {
        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_28, obj);
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);

        pokemon->tangible = false;
        obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    } else {
        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_29, obj);
        D_80350190_82F900 = true;
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);
        pokemon->tangible = false;
        obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
        Pokemon_SetState(obj, func_80347724_826E94);
    }
    Pokemon_SetState(obj, func_803471D4_826944);
}

POKEMON_FUNC(func_80347724_826E94)
    D_80350190_82F900 = false;
    pokemon->specialPoseID = 0;
    pokemon->flags |= POKEMON_FLAG_8;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    pokemon->counter = 150, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    D_8034AE50_82A5C0 = randRange(360) * TAU / 360.0f;
    D_8034AE54_82A5C4 = randRange(360) * PI / 360.0f;

    position->v.z = (randRange(50) + 80) * 10.0f + 200.0f;
    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_30, obj);
    Pokemon_StartPathProc(obj, func_8034799C_82710C);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_ForceAnimation(obj, &D_8034ACD8_82A448);
    pokemon->transitionGraph = D_8034AD90_82A500;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED | POKEMON_PROCESS_FLAG_PATH_ENDED);

    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80347900_827070);
    }
    Pokemon_SetState(obj, func_80347940_8270B0);
}

POKEMON_FUNC(func_80347900_827070)
    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);
    Pokemon_SetState(obj, func_80347724_826E94);
}

POKEMON_FUNC(func_80347940_8270B0)
    Pokemon_SetAnimation(obj, &D_8034ACB0_82A420);
    pokemon->transitionGraph = D_8034AD90_82A500;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    Pokemon_SetState(obj, func_80347900_827070);
}

POKEMON_FUNC(func_8034799C_82710C)
    s32 counter = 120;

    while (position->v.z > 200.0f && counter--) {
        position->v.x = sinf(D_8034AE50_82A5C0) * 300.0f;
        D_8034AE50_82A5C0 += PI / 180.0f;
        D_8034AE50_82A5C0 -= (s32) (D_8034AE50_82A5C0 / TAU) * TAU;

        position->v.z -= 10.0f;

        position->v.y = sinf(D_8034AE54_82A5C4) * 20.0f + D_80350188_82F8F8;
        D_8034AE54_82A5C4 += PI / 45.0; // 4 deg
        D_8034AE54_82A5C4 -= (s32) (D_8034AE54_82A5C4 / TAU) * TAU;

        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_80347B88_8272F8)
    if (--D_8034AE4C_82A5BC != 0) {
        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_28, obj);
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);
    } else {
        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_29, obj);
        D_80350190_82F900 = true;
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

        cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);
        Pokemon_SetState(obj, func_80347E0C_82757C);
    }
    Pokemon_SetState(obj, func_80347724_826E94);
}

POKEMON_FUNC(func_80347CC8_827438)
    while (true) {
        if (!(position->v.z < 2200.0f)) {
            break;
        }
        position->v.z += 10.0f;
        position->v.y = sinf(D_8034AE54_82A5C4) * 50.0f + D_80350188_82F8F8;
        D_8034AE54_82A5C4 += PI / 30.0; // 6 deg
        D_8034AE54_82A5C4 -= (s32) (D_8034AE54_82A5C4 / TAU) * TAU;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_80347E0C_82757C)
    Pokemon_StartAuxProc(obj, func_80348540_827CB0);
    Pokemon_SetState(obj, func_80347E44_8275B4);
}

POKEMON_FUNC(func_80347E44_8275B4)
    D_80350194_82F904 = 4;
    pokemon->flags &= ~POKEMON_FLAG_8;
    pokemon->specialPoseID = 10;

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    position->v.y = 100.0f;
    position->v.z = 200.0f;
    position->v.x = randRange(2) != 0 ? ((D_80350194_82F904 * 60.0f) + 100.0f) : -((D_80350194_82F904 * 60.0f) + 100.0f);

    D_8034AE54_82A5C4 = 0.0f;
    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_30, obj);
    Pokemon_StartPathProc(obj, func_803480C0_827830);

    pokemon->counter = 1, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->tangible = true;
    obj->flags = 0;

    Pokemon_SetAnimation(obj, &D_8034AD28_82A498);
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    Pokemon_SetState(obj, func_8034800C_82777C);
}

POKEMON_FUNC(func_8034800C_82777C)
    if (randRange(2) != 0) {
        Pokemon_SetAnimation(obj, &D_8034AD00_82A470);
    } else {
        Pokemon_SetAnimation(obj, &D_8034AD14_82A484);
    }
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);

    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_34, obj);
    D_8034AE4C_82A5BC = 1;
    D_80350198_82F908 = 0;
    Pokemon_SetState(obj, func_80347724_826E94);
}

POKEMON_FUNC(func_803480C0_827830)
    while (position->v.z < 2000.0f) {
        position->v.z += 5.0f;
        position->v.y = sinf(D_8034AE54_82A5C4) * 50.0f + D_80350188_82F8F8;
        D_8034AE54_82A5C4 += PI / 60.0; // 3 deg
        D_8034AE54_82A5C4 -= (s32) (D_8034AE54_82A5C4 / TAU) * TAU;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

POKEMON_FUNC(func_80348208_827978)
    D_80350198_82F908 = 2;
    pokemon->poseID = 152;
    Pokemon_StartPathProc(obj, func_803482EC_827A5C);
    Pokemon_ForceAnimation(obj, &D_8034AD3C_82A4AC);
    pokemon->counter = 192, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);

    pokemon->poseID = 153;
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);

    if (D_80350194_82F904 != 0) {
        D_80350194_82F904--;
    }
    pokemon->poseID = 0;
    D_80350198_82F908 = 1;
    Pokemon_SetState(obj, func_80347E44_8275B4);
}

POKEMON_FUNC(func_803482EC_827A5C)
    f32 f20 = position->v.x;
    s32 counter1 = 0x65; 
    s32 counter2 = 0x60;
    bool cond;

    D_8034AE50_82A5C0 = 0.0f;
    cmdSendCommand(D_8034AB98_82A308, RAINBOW_CMD_31, obj);

    while (true) {
        if (counter2 == 0) {
            if (position->v.z > 200.0f) {
                position->v.z -= 2.0f;
            } else {
                break;
            }
        } else {
            counter2--;
        }

        position->v.y = sinf(D_8034AE54_82A5C4) * 10.0f + D_80350188_82F8F8;
        D_8034AE54_82A5C4 += PI / 90.0; // 2 deg
        D_8034AE54_82A5C4 -= (s32) (D_8034AE54_82A5C4 / TAU) * TAU;

        if (counter1-- > 0) {
            if (ABS(f20) > 1.0f) {
                if (f20 > 0) {
                    f20 -= 1.0f;
                } else {
                    f20 += 1.0f;
                }
            } else {
                f20 = 0.0f;
            }
        }
        position->v.x = f20;
        ohWait(1);
    }

    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    pokemon->pathProc = FALSE;
    omEndProcess(NULL);
}

void func_803484F0_827C60(s32 arg0, s32* arg1) {
    if (ABS(arg0 - *arg1) < 6) {
        *arg1 = arg0;
    } else if (*arg1 < arg0) {
        *arg1 += 6;
    } else {
        *arg1 -= 6;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348540_827CB0.s")

void func_8034877C_827EEC(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    D_8034AE5C_82A5CC = 1;
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_80348850_827FC0);
    Pokemon_SetState(obj, func_803487CC_827F3C);
}

void func_803487CC_827F3C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_8034AD3C_82A4AC);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_803487CC_827F3C);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348850_827FC0.s")

GObj* func_80348938_8280A8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnOnGround(objID, id, block, blockB, spawn, &D_8034AE90_82A600);
}

void func_80348970_8280E0(GObj* obj) {
    Pokemon_SetState(obj, func_80348994_828104);
}

void func_80348994_828104(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_8034AED0_82A640);
    Pokemon_StartPathProc(obj, func_80348B34_8282A4);
    pokemon->transitionGraph = D_8034AF3C_82A6AC;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

// clang-format off
void func_80348A04_828174(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on

    cmdSendCommand(gObjPlayer, 9, NULL);
    auPlaySound(0x26);
    Pokemon_SetAnimation(obj, &D_8034AEE4_82A654);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80348DD4_828544);
    }
    auPlaySound(0x28);
    D_8034AF30_82A6A0 = auPlaySound(0x27);
    Pokemon_SetAnimation(obj, &D_8034AEF8_82A668);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80348DD4_828544);
    }
    Pokemon_SetAnimation(obj, &D_8034AF0C_82A67C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED) {
        Pokemon_SetState(obj, func_80348DD4_828544);
    }
    Pokemon_SetState(obj, func_80348DD4_828544);
}

void func_80348B34_8282A4(GObj* obj) {
    UNUSED s32 pad[2];
    DObj* dobj = obj->data.dobj;
    Pokemon* pokemon = GET_POKEMON(obj);
    PokemonTransform* transform = GET_TRANSFORM(dobj);

    while (transform->pos.v.z > 0.0f) {
        transform->pos.v.z -= 5.0f;
        ohWait(1);
    }
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_80348BDC_82834C(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
        D_8034AF34_82A6A4 = 1;
    }
}

void func_80348C08_828378(GObj* obj) {
    f32 fader;
    s32 i;
    u32 vol;

    f32 steps = 240;
    fader = 1.0f;

    for (i = 239; i > 0; i--) {
        fader += -1.0f / steps;
        vol = 32512.0f * fader;
        auSetBGMVolume(0, vol);
        auSetBGMVolume(1, vol);
        ohWait(1);
    }

    auSetBGMVolume(0, 0);
    auSetBGMVolume(1, 0);
    Pokemon_StopAuxProc(obj);
}

void func_80348D48_8284B8(GObj* obj) {
    s32 i;

    for (i = 0; i < 280; i++) {
        ohWait(1);
    }

    auPlaySound(0x29);

    if (D_8034AF30_82A6A0 != -1 && auPlayingSound[D_8034AF30_82A6A0] != -1) {
        auStopSound(D_8034AF30_82A6A0);
    }
    Pokemon_StopAuxProc(obj);
}

void func_80348DD4_828544(GObj* obj) {
    UNUSED s32 pad[4];
    GObj* camObj;
    GObj* playerObj;
    OMCamera* cam;
    s32 i;
    Unks16 sp30;

    sp30 = D_8034AF5C_82A6CC;
    Pokemon_StartAuxProc(obj, func_80348C08_828378);
    Pokemon_StartAuxProc(obj, func_80348D48_8284B8);
    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    Pokemon_RemovePokemons(&sp30);
    ohWait(1);
    Camera_StartCutScene(obj, NULL, 0.0f);
    if (D_8034AB94_82A304 != NULL) {
        ohResumeObjectProcesses(D_8034AB94_82A304);
    }
    D_8034AF38_82A6A8 = 1;
    cam = getMainCamera();
    camObj = cam->obj;
    ohPauseObjectProcesses(camObj);
    cam->animSpeed = 0.5f;
    animSetCameraAnimation(cam, &D_80119A8C, 0.0f);
    omCreateProcess(camObj, animUpdateCameraAnimation, 1U, 1U);
    setSkyBoxAnimationSpeed(D_800F5DB0);
    playerObj = PlayerModel_Init();
    if (playerObj == NULL) {
        cmdSendCommand(gObjPlayer, 7, NULL);
        omEndProcess(NULL);
    }
    PlayerModel_SetAnimation(&D_801183E0, &D_80119050, 0.0f, 0.5f);
    D_8034AF34_82A6A4 = 0;
    playerObj->fnAnimCallback = func_80348BDC_82834C;

    for (i = 0; D_8034AF34_82A6A4 == 0 && i < 1200; i++) {
        ohWait(1);
    }

    auStopAllSounds();
    cmdSendCommand(gObjPlayer, 6, NULL);
    omEndProcess(NULL);
    Pokemon_SetState(obj, NULL);
}

GObj* func_80348FB8_828728(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn) {
    return Pokemon_SpawnDlLink4(objID, id, block, blockB, spawn, &D_8034AF78_82A6E8);
}

// TODO needs Mtx4Float to have a vec3f
#ifdef NON_MATCHING
s32 func_80348FF0_828760(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    PokemonTransform* temp_v0;
    Mtx3Float* temp_t0;
    Mtx3Float* temp_t1;

    if (D_8034AF2C_82A69C == NULL) {
        return -1;
    }
    temp_v0 = GET_TRANSFORM(D_8034AF2C_82A69C->data.dobj);
    temp_t1 = &GET_TRANSFORM(D_8034AF2C_82A69C->data.dobj)->rot;
    if (StaticObject_CollideOne(arg0, arg1, arg2, arg3, &D_8034AF20_82A690, temp_v0->pos.v, temp_t1->v)) {
        return PokemonID_GATE;
    }
    return -1;
}
#else
s32 func_80348FF0_828760(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3);
#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80348FF0_828760.s")
#endif

void func_80349084_8287F4(GObj* obj) {
    Pokemon* pokemon;
    DObj* model;
    GObj* pokemonObj;
    ObjectSpawn spawn;
    WorldBlock* block;
    PokemonDef def = D_8034AFAC_82A71C;

    block = getCurrentWorldBlock();
    spawn.id = PokemonID_GATE;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = PI;
    spawn.euler.z = 0.0;
    spawn.scale.x = 1.0;
    spawn.scale.y = 1.0;
    spawn.scale.z = 1.0;

    pokemonObj = pokemonAddOne(block, block, &spawn, &def);
    D_8034AF2C_82A69C = pokemonObj;
    pokemon = GET_POKEMON(D_8034AB94_82A304);

    model = pokemonObj->data.dobj;
    GET_TRANSFORM(model)->pos.v.x = 0.0f;
    GET_TRANSFORM(model)->pos.v.y = 0.0f;
    GET_TRANSFORM(model)->pos.v.z = 10000.0f;
    InitOneCollisionModel(&D_8034AF20_82A690);
    Items_func_8035CA1C(&func_80348FF0_828760);
    omEndProcess(NULL);
}
