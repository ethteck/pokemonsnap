#include "common.h"

#include "world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "river.h"

extern f32 D_8012ACA0;
extern AnimCmd* D_8014BFB0;
extern AnimCmd** D_8014CEC0;
extern AnimCmd D_8014EA10[];

extern GObj* D_802E4230_6CC010;
extern AnimationHeader D_802E4AE0_6CC8C0;
extern InteractionHandler D_802E4B14_6CC8F4[];
extern f32 D_802E4AF4_6CC8D4[3];
extern GObj* D_802E4B00_6CC8E0;
extern OMCamera* D_802E4B04_6CC8E4;
extern PokemonInitData D_802E4B48_6CC928;
extern s32 D_802E4B08_6CC8E8;
extern f32 D_802E4B0C_6CC8EC;
extern f32 D_802E4B10_6CC8F0;

extern GObj* D_8033F678_727458;
extern u32 D_8033F67C_72745C;
extern u8 D_8033F680_727460;
extern u8 D_8033F681_727461;

void func_802E18C4_6C96A4(GObj*);

void func_802E18A0_6C9680(GObj* obj) {
    Pokemon_SetState(obj, func_802E18C4_6C96A4);
}

void func_802E18C4_6C96A4(GObj* obj) {
    UNUSED s32 padding[3];
    Pokemon* pokemon = GET_POKEMON(obj);

    Pokemon_SetAnimation(obj, &D_802E4AE0_6CC8C0);
    pokemon->transitionGraph = D_802E4B14_6CC8F4;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, 0);
}

void func_802E191C_6C96FC(f32 animSpeed) {
    if (D_802E4B04_6CC8E4 != NULL) {
        D_802E4B04_6CC8E4->animSpeed = animSpeed;
    }
    PlayerModel_SetAnimationSpeed(animSpeed);
}

void func_802E1950_6C9730(f32 arg0) {
    if (D_802E4B04_6CC8E4 != NULL) {
        animSetCameraAnimation(D_802E4B04_6CC8E4, D_8014EA10, arg0);
    }
    PlayerModel_ChangeAnimation(&D_8014BFB0, &D_8014CEC0, arg0);
}

void func_802E19A0_6C9780(DObj* arg0, s32 arg1, f32 arg2) {
    s32 idx;

    switch (arg1) {
        case -2:
        case -1:
            D_802E4B08_6CC8E8 = 1;
            break;
        case 4:
            if (arg2 >= 0.0f) {
                D_802E4B0C_6CC8EC = arg2;
            }
            break;
        case 5:
            idx = (s32) arg2;
            if (idx >= 0 && idx < ARRAY_COUNT(D_802E4AF4_6CC8D4)) {
                D_802E4B10_6CC8F0 = D_802E4AF4_6CC8D4[idx];
            }
            break;
    }
}

void func_802E1A3C_6C981C(DObj*, s32, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/river/6C9680/func_802E1A3C_6C981C.s")

void func_802E1A4C_6C982C(GObj* obj) {
    func_800AB9A4();

    for (D_8033F67C_72745C = 0;; D_8033F67C_72745C++) {
        switch (D_8033F67C_72745C) {
            case 0x1:
                D_8033F680_727460 = auPlaySoundWithParams(0x24, 0x7F00, 0x40, 1.0f, 30);
                break;
            case 0x2:
                func_800AB700(D_8033F680_727460, 0x7F00, 0x5800, 0x78);
                break;
            case 0x7A:
                auStopBGM();
                break;
            case 0xC8:
                auPlaySoundWithParams(0x25, 0x6000, 0x40, 0.5f, 0xA);
                auStopSound(D_8033F680_727460);
                auSetBGMVolume(1, 0x7F00);
                auPlaySong(1, 0x14);
                break;
            case 0x140:
                D_8033F681_727461 = auPlaySoundWithParams(0x21, 0x1000, 0x40, 1.0f, 60);
                break;
            case 0x168:
                func_800AB700(D_8033F681_727461, 0x1000, 0x5800, 30);
                break;
            case 0x21C:
                func_800AB700(D_8033F681_727461, 0x5800, 0x3800, 20);
                break;
            case 0x294:
                func_800AB700(D_8033F681_727461, 0x3800, 0x5800, 20);
                auSetBGMVolumeSmooth(1, 0, 60);
                break;
            case 0x2BC:
                auPlaySoundWithParams(0x32, 0x5000, 0x40, 0.8f, 30);
                break;
            case 0x2D0:
                auPlaySoundWithParams(0xF, 0x7C00, 0x40, 1.0f, 30);
                break;
            case 0x33E:
                func_800AB700(D_8033F681_727461, 0x5800, 0x2000, 60);
                break;
        }
        ohWait(1);
    }
}

void func_802E1CBC_6C9A9C(void) {
    D_8033F678_727458 = omAddGObj(14, ohUpdateDefault, 0, 0x80000000);
    omCreateProcess(D_8033F678_727458, func_802E1A4C_6C982C, 0, 1);
}

void func_802E1D10_6C9AF0(GObj* obj) {
    UNUSED s32 padding[7];
    f32 sp34;
    GObj* temp_s0;
    f32 var_f20;
    s32 var_s1;
    GObj* playerGobj;

    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    cmdSendCommand(gObjPlayer, 0xA, NULL);
    if (func_800BFC5C_5CAFC() < 4) {
        func_800C02A0_5D140(4);
        func_800AAED0(0x400);
    }
    ohResumeObjectProcesses(D_802E4B00_6CC8E0);
    if (D_802E4230_6CC010 != NULL) {
        ohResumeObjectProcesses(D_802E4230_6CC010);
    }
    auSetBGMVolumeSmooth(0, 0, 240);
    func_800E1A78_5F228(D_8012ACA0);
    D_802E4B04_6CC8E4 = getMainCamera();
    temp_s0 = D_802E4B04_6CC8E4->obj;
    ohPauseObjectProcesses(temp_s0);
    omCreateProcess(temp_s0, animUpdateCameraAnimation, 1, 1);
    playerGobj = PlayerModel_Init();
    obj->fnAnimCallback = func_802E1A3C_6C981C;
    animSetModelAnimationSpeed(obj, 0.5f);
    func_802E1950_6C9730(0.0f);
    func_802E191C_6C96FC(0.5f);
    func_802E1CBC_6C9A9C();
    D_802E4B08_6CC8E8 = 0;
    playerGobj->fnAnimCallback = func_802E19A0_6C9780;
    var_s1 = 0;
    for (var_s1 = 0; D_802E4B08_6CC8E8 == 0 && var_s1 < 10800; var_s1++) {
        if ((D_802E4B0C_6CC8EC >= 0.0f) && (D_802E4B10_6CC8F0 >= 0.0f)) {
            func_802E191C_6C96FC(3.0f);
            ohWait(1);
            func_802E191C_6C96FC(D_802E4B10_6CC8F0);
            ohWait(1);
            D_802E4B10_6CC8F0 = -1.0f;
            D_802E4B0C_6CC8EC = D_802E4B10_6CC8F0;
        }
        ohWait(1);
    }
    var_f20 = 1.0f;
    sp34 = -(var_f20 / 30.0f);
    func_800A7F68(10, 1);
    func_800A7470(0, 0, 0);
    func_800A7918(0, 0.5f);
    auSetBGMVolumeSmooth(1, 0, 30);
    ohWait(1);
    while (func_800A7460() == 1) {
        var_f20 += sp34;
        auSetSoundGlobalVolume(127.0f * var_f20);
        ohWait(1);
    }
    auSetSoundGlobalVolume(0);
    cmdSendCommand(gObjPlayer, 7, NULL);
    omEndProcess(NULL);
    omDeleteGObj(D_8033F678_727458);
    Pokemon_SetState(obj, 0);
}

GObj* func_802E2084_6C9E64(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802E4B00_6CC8E0 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802E4B48_6CC928);

    return D_802E4B00_6CC8E0;
}
