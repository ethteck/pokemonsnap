#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "cave.h"

typedef struct Bytes3 {
    /* 0x00 */ u8 unk_00[3];
} Bytes3; // size = 0x3

typedef struct Bytes12 {
    /* 0x00 */ u8 unk_00[12];
} Bytes12; // size = 0xC

extern GObj* D_802C6D4C_6491FC[];
extern AnimationHeader D_802C71FC_6496AC;
extern AnimationHeader D_802C7210_6496C0;
extern AnimationHeader D_802C7224_6496D4;
extern AnimationHeader D_802C7238_6496E8;
extern AnimationHeader D_802C724C_6496FC;
extern AnimationHeader D_802C7260_649710;
extern AnimationHeader D_802C7274_649724;
extern AnimationHeader D_802C7288_649738;
extern f32 D_802C729C_64974C;
extern GObj* D_802C72A0_649750[];
extern InteractionHandler7 D_802C72B0_649760;
extern InteractionHandler4 D_802C7320_6497D0;
extern InteractionHandler4 D_802C7360_649810;
extern InteractionHandler4 D_802C73A0_649850;
extern InteractionHandler D_802C73E0_649890[];
extern Vec3f D_802C7410_6498C0;
extern InteractionHandler6 D_802C741C_6498CC;
extern Bytes3 D_802C747C_64992C;
extern Bytes12 D_802C7480_649930;
extern InteractionHandler6 D_802C748C_64993C;
extern InteractionHandler3 D_802C74EC_64999C;
extern InteractionHandler3 D_802C751C_6499CC;
extern InteractionHandler D_802C754C_6499FC[];
extern PokemonInitData D_802C7590_649A40;

void func_802C157C_643A2C(GObj*);
void func_802C1660_643B10(GObj*);
void func_802C1728_643BD8(GObj*);
void func_802C1A20_643ED0(GObj*);
void func_802C1A7C_643F2C(GObj*);
void func_802C1B1C_643FCC(GObj*);
void func_802C1B54_644004(GObj*);
void func_802C1C48_6440F8(GObj*);
void func_802C1E4C_6442FC(GObj*);
void func_802C1EB0_644360(GObj*);
void func_802C1F08_6443B8(GObj*);
void func_802C1F74_644424(GObj*);
void func_802C2058_644508(GObj*);
void func_802C2308_6447B8(GObj*);
void func_802C257C_644A2C(GObj*);
void func_802C2650_644B00(GObj*);
void func_802C26AC_644B5C(GObj*);
void func_802C2710_644BC0(GObj*);
void func_802C2758_644C08(GObj*);
void func_802C27E4_644C94(GObj*);

void func_802C1440_6438F0(GObj* obj, InteractionHandler* arg1) {
    Pokemon* pokemon = GET_POKEMON(obj);

    while (true) {
        if (!Pokemon_HearsPokeFlute(obj)) {
            break;
        }
        pokemon->counter = 1;
        pokemon->transitionGraph = arg1;
        pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    }
}

void func_802C14C4_643974(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->forbiddenGround = &D_802C729C_64974C;
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;

    switch (pokemon->behavior) {
        case 4:
            Pokemon_SetState(obj, func_802C1E4C_6442FC);
            break;
        case 5:
            Pokemon_SetState(obj, func_802C2650_644B00);
            break;
        case 6:
            Pokemon_SetState(obj, func_802C26AC_644B5C);
            break;
    }
    Pokemon_SetState(obj, func_802C157C_643A2C);
}

void func_802C157C_643A2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    while (D_802C6D4C_6491FC[pokemon->behavior] == NULL) {
        ohWait(1);
    }
    pokemon->miscVars[2].field1 = (s32) pokemon->path;
    pokemon->path = GET_POKEMON(D_802C6D4C_6491FC[pokemon->behavior])->path;
    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_SetAnimation(obj, &D_802C71FC_6496AC);
    Pokemon_StartPathProc(obj, func_802C1728_643BD8);
    ohWait(60);
    D_802C72A0_649750[pokemon->behavior] = obj;
    Pokemon_SetState(obj, func_802C1660_643B10);
}

void func_802C1660_643B10(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler7 sp20 = D_802C72B0_649760;

    Pokemon_SetAnimation(obj, &D_802C71FC_6496AC);
    pokemon->transitionGraph = sp20.data;
    Pokemon_WaitForFlag(obj, 2 | 1);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802C1660_643B10);
    }
    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C1728_643BD8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0, 1, 0.05f, 0.0f, MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C1794_643C44(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler4 sp18 = D_802C7320_6497D0;

    Pokemon_SetAnimation(obj, &D_802C7210_6496C0);
    func_802C1440_6438F0(obj, sp18.data);
    Pokemon_SetState(obj, func_802C1660_643B10);
}

void func_802C1818_643CC8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler4 sp18 = D_802C7360_649810;

    Pokemon_SetAnimation(obj, &D_802C7224_6496D4);
    func_802C1440_6438F0(obj, sp18.data);
    Pokemon_SetState(obj, func_802C1660_643B10);
}

void func_802C189C_643D4C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler4 sp18 = D_802C73A0_649850;

    Pokemon_SetAnimation(obj, &D_802C7238_6496E8);
    func_802C1440_6438F0(obj, sp18.data);
    Pokemon_SetState(obj, func_802C1660_643B10);
}

void func_802C1920_643DD0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802C724C_6496FC);
    pokemon->hSpeed = 0.0f;
    pokemon->jumpVel = 150.0f;
    Pokemon_Fall(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    pokemon->jumpVel = 150.0f;
    Pokemon_Jump(obj, 30.0f, 0.0f, 0.0f, 0.0f);
    Pokemon_StopAuxProc(obj);
}

void func_802C19BC_643E6C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->counter = 60;
    pokemon->transitionGraph = NULL;
    pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    Pokemon_StartPathProc(obj, func_802C1A7C_643F2C);
    Pokemon_SetState(obj, func_802C1A20_643ED0);
}

void func_802C1A20_643ED0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ForceAnimation(obj, &D_802C7288_649738);
    pokemon->transitionGraph = D_802C73E0_649890;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C1B1C_643FCC);
}

void func_802C1A7C_643F2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, 0.1f, MOVEMENT_FLAG_TURN_TO_PLAYER | MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED | MOVEMENT_FLAG_UPDATE_TARGET_POS);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C1AC8_643F78(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802C7274_649724);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C1A20_643ED0);
}

void func_802C1B1C_643FCC(GObj* obj) {
    Pokemon_StartPathProc(obj, func_802C1C48_6440F8);
    Pokemon_SetState(obj, func_802C1B54_644004);
}

void func_802C1B54_644004(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon = obj->userData;
    Pokemon_ForceAnimation(obj, &D_802C7288_649738);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (!(pokemon->processFlags & POKEMON_PROCESS_FLAG_PATH_ENDED)) {
        Pokemon_SetState(obj, func_802C1B54_644004);
    }

    switch (pokemon->behavior) {
        case 1:
            D_8033E138_6C05E8.unk_00_7 = true;
            break;
        case 2:
            D_8033E138_6C05E8.unk_01_0 = true;
            break;
        case 3:
            D_8033E138_6C05E8.unk_01_1 = true;
            break;
    }

    Pokemon_RunCleanup(obj);
    Pokemon_SetState(obj, NULL);
}

void func_802C1C48_6440F8(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);
    UNUSED s32 pad[2];
    WorldBlockDescriptor* blockDesc;
    Vec3f sp64;
    f32 z;
    f32 y;
    f32 x;
    DObj* dobj;
    PokemonTransform* transform;

    dobj = obj->data.dobj;
    transform = GET_TRANSFORM(dobj);
    sp64 = D_802C7410_6498C0;

    pokemon->path = (InterpData*) pokemon->miscVars[2].field1;
    GetInterpolatedPosition(&sp64, pokemon->path, pokemon->path->paramPoints[1]);
    blockDesc = getCurrentWorldBlock()->descriptor;
    x = (sp64.x - blockDesc->worldPos.x) * 100.0f;
    y = (sp64.y - blockDesc->worldPos.y) * 100.0f;
    z = (sp64.z - blockDesc->worldPos.z) * 100.0f;
    pokemon->hSpeed = 450.0f;

    Pokemon_SetTargetPos(obj, x, z);

    while (Pokemon_StepToTargetPos(obj, 0.1f, 0) == 0) {
        if (ABS(y - transform->pos.v.y) < 10.0f) {
            transform->pos.v.y = y;
        } else if (transform->pos.v.y < y) {
            transform->pos.v.y += 10.0f;
        } else {
            transform->pos.v.y -= 10.0f;
        }
        ohWait(1);
    }

    transform->pos.v.x = x;
    transform->pos.v.y = y;
    transform->pos.v.z = z;

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, pokemon->path->paramPoints[1], 1.0f, 0.25f, 0.0f, 2);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C1E4C_6442FC(GObj* obj) {
    while (!(D_8033E138_6C05E8.unk_00_7)) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C1EB0_644360);
}

void func_802C1EB0_644360(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_StartAuxProc(obj, func_802C2058_644508);
    Pokemon_StartPathProc(obj, func_802C1F08_6443B8);
    Pokemon_SetState(obj, func_802C1F74_644424);
}

void func_802C1F08_6443B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 0.0f, 0.016666668f, 0, 0);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

// clang-format off
void func_802C1F74_644424(GObj* obj) { \
    UNUSED s32 pad[3]; \
    Pokemon* pokemon = GET_POKEMON(obj);
    // clang-format on
    InteractionHandler6 sp18 = D_802C741C_6498CC;

    pokemon->miscVars[1].field1 = 0;
    if (D_8033E138_6C05E8.unk_00_7 == true && D_8033E138_6C05E8.unk_01_0 == true && D_8033E138_6C05E8.unk_01_1 == true) {
        pokemon->unk_10E = 12;
    } else {
        pokemon->unk_10E = 8;
    }
    Pokemon_ForceAnimation(obj, &D_802C7260_649710);
    pokemon->transitionGraph = sp18.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C1F74_644424);
}
void func_802C2058_644508(GObj* obj) {
    UNUSED s32 pad[2];
    Pokemon* pokemon = GET_POKEMON(obj);
    u8 vol;
    s32 i;
    bool var_s5;
    Bytes3 sp54;
    u8 var_s0;
    s32 sp4C;
    f32 sp48;

    var_s5 = true;
    vol = 0;
    sp54 = D_802C747C_64992C;

    while (true) {
        getLevelProgress(&sp4C, &sp48);
        if (sp4C >= 4 || (sp4C == 3 && sp48 >= 0.75f)) {
            break;
        }
        ohWait(1);
    }

    Pokemon_StartAuxProc(obj, func_802C2308_6447B8);
    while (Items_GetPokeFluteCmd() != 0) {
        ohWait(1);
    }

    while (1) {
        var_s0 = 0;
        if (!pokemon->miscVars[1].field1) {
            if (var_s5) {
                auPlaySong(1, 0x18);
            }
            if (pokemon->playerDist < 5000.0f) {
                if (pokemon->playerDist < 1000.0f) {
                    var_s0 = 127;
                } else {
                    var_s0 = ((u32) (((5000.0f - pokemon->playerDist) * 127.0f) / 4000.0f));
                }
            }
        }

        var_s5 = pokemon->miscVars[1].field1;

        if (ABS(vol - var_s0) < 127) {
            vol = var_s0;
        } else if (vol < var_s0) {
            vol = (vol + 127);
        } else {
            vol = (vol - (127));
        }

        for (i = 0; i < ARRAY_COUNT(sp54.unk_00); i++) {
            auSetBGMChannelVolume(1, sp54.unk_00[i], vol);
        }

        ohWait(1);
    }
}

void func_802C2308_6447B8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    u8 vol;
    Bytes12 sp70;
    s32 i;
    f32 temp_f20;
    s32 sp64;
    f32 sp60;

    sp70 = D_802C7480_649930;
    temp_f20 = FLOAT_MAX;

    while (temp_f20 > 0.0f) {
        getLevelProgress(&sp64, &sp60);
        sp60 += sp64;
        temp_f20 = (3.95f - sp60) / 0.20000005f;
        vol = (u32) (127.0f * temp_f20);
        if (Items_GetPokeFluteCmd() == 0) {
            for (i = 0; i < ARRAY_COUNT(sp70.unk_00); i++) {
                auSetBGMChannelVolume(0, sp70.unk_00[i], vol);
            }
        }
        ohWait(1);
    }

    if (Items_GetPokeFluteCmd() == 0) {
        auStopSong(0);
    }

    setBackgroundMusic(0x16);
    Pokemon_StopAuxProc(obj);
}

void func_802C2504_6449B4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[1].field1 = 1;
    pokemon->unk_10E = 0;
    Pokemon_SetAnimation(obj, &D_802C724C_6496FC);
    Pokemon_StartPathProc(obj, func_802C1A7C_643F2C);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C257C_644A2C);
}

void func_802C257C_644A2C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[1].field1 = 1;
    Pokemon_ForceAnimation(obj, &D_802C7274_649724);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C1F74_644424);
}

void func_802C25D8_644A88(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->miscVars[1].field1 = 1;
    pokemon->unk_10E = 0;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetAnimation(obj, &D_802C7274_649724);
    func_802C1440_6438F0(obj, NULL);
    pokemon->processFlags &= ~POKEMON_PROCESS_FLAG_MOVEMENT_PAUSED;
    Pokemon_SetState(obj, func_802C1F74_644424);
}

void func_802C2650_644B00(GObj* arg0) {
    while (!(D_8033E138_6C05E8.unk_01_0)) {
        ohWait(1);
    }
    Pokemon_SetState(arg0, func_802C2710_644BC0);
}

void func_802C26AC_644B5C(GObj* obj) {
    while (!(D_8033E138_6C05E8.unk_01_1)) {
        ohWait(1);
    }
    Pokemon_SetState(obj, func_802C2710_644BC0);
}

void func_802C2710_644BC0(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = true;
    obj->flags = 0;
    Pokemon_StartPathProc(obj, func_802C27E4_644C94);
    Pokemon_SetState(obj, func_802C2758_644C08);
}

void func_802C2758_644C08(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);
    InteractionHandler6 sp18 = D_802C748C_64993C;

    Pokemon_SetAnimation(obj, &D_802C7238_6496E8);
    pokemon->transitionGraph = sp18.data;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetState(obj, func_802C2758_644C08);
}

void func_802C27E4_644C94(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_ResetPathPos(obj);
    Pokemon_FollowPath(obj, 0.0f, 0.0f, 0.05f, 0, 2);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_802C2854_644D04(GObj* obj) {
    UNUSED s32 pad[4];
    InteractionHandler3 sp18 = D_802C74EC_64999C;

    Pokemon_SetAnimation(obj, &D_802C7210_6496C0);
    func_802C1440_6438F0(obj, sp18.data);
    Pokemon_SetState(obj, func_802C2758_644C08);
}

void func_802C28D0_644D80(GObj* obj) {
    UNUSED s32 pad[4];
    InteractionHandler3 sp18 = D_802C751C_6499CC;

    Pokemon_SetAnimation(obj, &D_802C7224_6496D4);
    func_802C1440_6438F0(obj, sp18.data);
    Pokemon_SetState(obj, func_802C2758_644C08);
}

void func_802C294C_644DFC(GObj* obj) {
    Pokemon_SetAnimation(obj, &D_802C7238_6496E8);
    func_802C1440_6438F0(obj, D_802C754C_6499FC);
    Pokemon_SetState(obj, func_802C2758_644C08);
}

GObj* func_802C2994_644E44(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
    return Pokemon_Spawn(objID, id, block, blockB, spawn, &D_802C7590_649A40);
}
