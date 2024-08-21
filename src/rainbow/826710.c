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
extern RandomState D_8034AE30_82A5A0;
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
extern AnimationHeader D_8034AED0_82A640;
extern AnimationHeader D_8034AEE4_82A654;
extern AnimationHeader D_8034AEF8_82A668;
extern AnimationHeader D_8034AF0C_82A67C;
extern UnkChestnutCougar D_8034AF20_82A690;
extern GObj* D_8034AF2C_82A69C;
extern s32 D_8034AF30_82A6A0;
extern s32 D_8034AF34_82A6A4;
extern s32 D_8034AF38_82A6A8;
extern InteractionHandler D_8034AF3C_82A6AC[];
extern Unks16 D_8034AF5C_82A6CC;
extern PokemonInitData D_8034AF78_82A6E8;
extern PokemonDef D_8034AFAC_82A71C;
extern f32 D_8034B680_82ADF0;
extern f32 D_8034B684_82ADF4;
extern f64 D_8034B688_82ADF8;
extern f32 D_8034B690_82AE00;
extern f32 D_8034B694_82AE04;
extern f32 D_8034B698_82AE08;
extern f32 D_8034B69C_82AE0C;
extern f32 D_8034B6A0_82AE10;
extern f64 D_8034B6A8_82AE18;
extern f32 D_8034B6B0_82AE20;
extern f32 D_8034B6B4_82AE24;
extern f32 D_8034B6B8_82AE28;
extern f64 D_8034B6C0_82AE30;
extern f32 D_8034B6C8_82AE38;
extern f64 D_8034B6D0_82AE40;
extern f32 D_8034B6D8_82AE48;
extern f64 D_8034B6E0_82AE50;
extern f32 D_8034B6E8_82AE58;
extern f32 D_8034B6EC_82AE5C;
extern f32 D_8034B6F0_82AE60;
extern f32 D_8034B6F4_82AE64;
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

void func_80346FA0_826710(GObj* obj) {
    s32 pad[3];
    s32 var_s0;
    Unk8 sp40;
    s32 i;
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
            cmdSendCommand(obj, 0x23, obj);
        }
        ohWait(1);
    }

    Pokemon_StopAuxProc(obj);
}

void func_803470CC_82683C(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(dobj); // TODO could be an Item
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_StartAuxProc(obj, func_80346FA0_826710);
    Pokemon_StartPathProc(obj, func_80347188_8268F8);
    pokemon->transitionGraph = NULL;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    omCreateProcess(obj, func_803467A4_825F14, 1, 1);
    D_80350188_82F8F8 = transform->pos.v.y;
    D_8035018C_82F8FC = transform->pos.v.z;
    pokemon->unk_10E = 0;
    pokemon->flags |= POKEMON_FLAG_8;
    Pokemon_SetState(obj, func_803471D4_826944);
}

void func_80347188_8268F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_TurnToTarget(obj, TAU, 0x20);
    pokemon->pathProc = NULL;
    pokemon->processFlags |= POKEMON_PROCESS_FLAG_PATH_ENDED;
    omEndProcess(NULL);
}

void func_803471D4_826944(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    D_8034AE50_82A5C0 = (randRange(360) * D_8034B680_82ADF0) / 360.0f;
    D_8034AE58_82A5C8 = (randRange(180) * D_8034B684_82ADF4) / 180.0f;
    cmdSendCommand(D_8034AB98_82A308, 0x1E, obj);
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

void func_80347334_826AA4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    D_80350190_82F900 = false;
    Pokemon_SetAnimation(obj, &D_8034ACB0_82A420);
    pokemon->transitionGraph = D_8034AD50_82A4C0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_8034AE30_82A5A0);
}

#ifndef NON_EQUIVALENT
#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347398_826B08.s")
#else
void func_80347398_826B08(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    PokemonTransform* transform;
    f32 var_f20;
    f32 new_var2;
    f64 new_var;
    f32 new_var3;

    new_var2 = D_8034B690_82AE00;
    new_var = D_8034B688_82ADF8;
    new_var3 = D_8035018C_82F8FC;

    var_f20 = 1.0f;
    transform = (PokemonTransform*) dobj->unk_4C->data;

    while (true) {
        var_f20 += randFloat() - 0.5;
        if (var_f20 < 1.0f) {
            var_f20 = 1.0f;
        } else if (var_f20 > 4.0f) {
            var_f20 = 4.0f;
        }

        transform->pos.v.x = __sinf(D_8034AE50_82A5C0) * 200.0f;
        D_8034AE50_82A5C0 += (var_f20 * D_8034B694_82AE04) / 180.0f;
        D_8034AE50_82A5C0 -= ((s32) (D_8034AE50_82A5C0 / new_var2)) * new_var2;
        transform->pos.v.z = (__sinf(D_8034AE58_82A5C8) * 150.0f) + new_var3;
        D_8034AE58_82A5C8 += new_var;
        D_8034AE58_82A5C8 -= ((s32) (D_8034AE58_82A5C8 / new_var2)) * new_var2;
        ohWait(1);
    }
}
#endif

void func_80347574_826CE4(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_8034ACC4_82A434);
    pokemon->transitionGraph = D_8034AD50_82A4C0;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    Pokemon_SetStateRandom(obj, &D_8034AE30_82A5A0);
}

void func_803475D0_826D40(GObj* obj) {
    Pokemon* pokemon = GET_POKEMON(obj);

    D_8034AE48_82A5B8--;

    if (D_8034AE48_82A5B8 != 0) {
        cmdSendCommand(D_8034AB98_82A308, 0x1C, obj);
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        cmdSendCommand(D_8034AB98_82A308, 0x1F, obj);
        pokemon->tangible = false;
        obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    } else {
        cmdSendCommand(D_8034AB98_82A308, 0x1D, obj);
        D_80350190_82F900 = true;
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        cmdSendCommand(D_8034AB98_82A308, 0x1F, obj);
        pokemon->tangible = false;
        obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
        Pokemon_SetState(obj, func_80347724_826E94);
    }
    Pokemon_SetState(obj, func_803471D4_826944);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347724_826E94.s")

void func_80347900_827070(GObj* obj) {
    cmdSendCommand(D_8034AB98_82A308, 0x1F, obj);
    Pokemon_SetState(obj, func_80347724_826E94);
}

void func_80347940_8270B0(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_8034ACB0_82A420);
    pokemon->transitionGraph = D_8034AD90_82A500;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    Pokemon_SetState(obj, func_80347900_827070);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_8034799C_82710C.s")

void func_80347B88_8272F8(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    D_8034AE4C_82A5BC--;
    if (D_8034AE4C_82A5BC != 0) {
        cmdSendCommand(D_8034AB98_82A308, 0x1C, obj);
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        cmdSendCommand(D_8034AB98_82A308, 0x1F, obj);
    } else {
        cmdSendCommand(D_8034AB98_82A308, 0x1D, obj);
        D_80350190_82F900 = true;
        Pokemon_StartPathProc(obj, func_80347CC8_827438);
        Pokemon_SetAnimation(obj, &D_8034ACEC_82A45C);
        pokemon->transitionGraph = D_8034AE10_82A580;
        Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
        cmdSendCommand(D_8034AB98_82A308, 0x1F, obj);
        Pokemon_SetState(obj, func_80347E0C_82757C);
    }
    Pokemon_SetState(obj, func_80347724_826E94);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_80347CC8_827438.s")

void func_80347E0C_82757C(GObj* arg0) {
    Pokemon_StartAuxProc(arg0, func_80348540_827CB0);
    Pokemon_SetState(arg0, func_80347E44_8275B4);
}

void func_80347E44_8275B4(GObj* obj) {
    DObj* dobj = obj->data.dobj;
    PokemonTransform* transform = GET_TRANSFORM(dobj);
    Pokemon* pokemon = GET_POKEMON(obj);

    pokemon = obj->userData;
    D_80350194_82F904 = 4;
    pokemon->flags &= ~POKEMON_FLAG_8;
    pokemon->unk_10E = 0xA;
    pokemon->tangible = false;
    obj->flags |= GOBJ_FLAG_2 | GOBJ_FLAG_HIDDEN;
    pokemon->counter = 180, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034AE10_82A580;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    transform->pos.v.y = 100.0f;
    transform->pos.v.z = 200.0f;
    transform->pos.v.x = randRange(2) != 0 ? ((D_80350194_82F904 * 60.0f) + 100.0f) : -((D_80350194_82F904 * 60.0f) + 100.0f);
    D_8034AE54_82A5C4 = 0.0f;
    cmdSendCommand(D_8034AB98_82A308, 0x1E, obj);
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

void func_8034800C_82777C(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    if (randRange(2) != 0) {
        Pokemon_SetAnimation(obj, &D_8034AD00_82A470);
    } else {
        Pokemon_SetAnimation(obj, &D_8034AD14_82A484);
    }
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED);
    cmdSendCommand(D_8034AB98_82A308, 0x22, obj);
    D_8034AE4C_82A5BC = 1;
    D_80350198_82F908 = 0;
    Pokemon_SetState(obj, func_80347724_826E94);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803480C0_827830.s")

void func_80348208_827978(GObj* obj) {
    UNUSED s32 pad[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    D_80350198_82F908 = 2;
    pokemon->unk_10C = 0x98;
    Pokemon_StartPathProc(obj, func_803482EC_827A5C);
    Pokemon_ForceAnimation(obj, &D_8034AD3C_82A4AC);
    pokemon->counter = 192, pokemon->processFlags &= ~POKEMON_PROCESS_WAIT_ENDED;
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_WAIT_ENDED);
    pokemon->unk_10C = 0x99;
    pokemon->transitionGraph = D_8034ADD0_82A540;
    Pokemon_WaitForFlag(obj, POKEMON_PROCESS_FLAG_PATH_ENDED | POKEMON_PROCESS_FLAG_ANIMATION_ENDED);
    if (D_80350194_82F904 != 0) {
        D_80350194_82F904--;
    }
    pokemon->unk_10C = 0;
    D_80350198_82F908 = 1;
    Pokemon_SetState(obj, func_80347E44_8275B4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/rainbow/826710/func_803482EC_827A5C.s")

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

GObj* func_80348938_8280A8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
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
    func_800E1A78_5F228(D_800F5DB0);
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

GObj* func_80348FB8_828728(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn, PokemonInitData* initData) {
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
    if (world_func_800E67E4(arg0, arg1, arg2, arg3, &D_8034AF20_82A690, temp_v0->pos.v, temp_t1->v)) {
        return PokemonID_1001;
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
    spawn.id = PokemonID_1001;
    spawn.translation.x = 0.0;
    spawn.translation.y = 0.0;
    spawn.translation.z = 0.0;
    spawn.euler.x = 0.0;
    spawn.euler.y = D_8034B6F0_82AE60;
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
    GET_TRANSFORM(model)->pos.v.z = D_8034B6F4_82AE64;
    world_func_800E6778(&D_8034AF20_82A690);
    Items_func_8035CA1C(&func_80348FF0_828760);
    omEndProcess(NULL);
}
