#include "../tunnel.h"

extern AnimCmd* D_8013EEE0[];
extern AnimCmd** D_8013FDD0[];
extern AnimCmd D_801419E4[];

void func_802ED644_5EA714(GObj*);

extern AnimationHeader D_802F01F0_5ED2C0;
extern f32 D_802F0204_5ED2D4[3];
extern GObj* D_802F0210_5ED2E0;
extern OMCamera* D_802F0214_5ED2E4;
extern s32 D_802F0218_5ED2E8;
extern f32 D_802F0220_5ED2F0;
extern f32 D_802F0224_5ED2F4;
extern InteractionHandler D_802F0228_5ED2F8[];
extern PokemonInitData D_802F025C_5ED32C;

extern GObj* D_80344748_641818;
extern u32 D_8034474C_64181C;
extern u8 D_80344750_641820;
extern u8 D_80344751_641821;

POKEMON_FUNC(func_802ED620_5EA6F0)
    Pokemon_SetState(obj, func_802ED644_5EA714);
}

POKEMON_FUNC(func_802ED644_5EA714)
    Pokemon_SetAnimation(obj, &D_802F01F0_5ED2C0);
    pokemon->transitionGraph = D_802F0228_5ED2F8;
    Pokemon_WaitForFlag(obj, 0);
    Pokemon_SetState(obj, NULL);
}

void func_802ED69C_5EA76C(f32 arg0) {
    if (D_802F0214_5ED2E4 != NULL) {
        D_802F0214_5ED2E4->animSpeed = arg0;
    }
    PlayerModel_SetAnimationSpeed(arg0);
}

void func_802ED6D0_5EA7A0(f32 arg0) {
    if (D_802F0214_5ED2E4 != NULL) {
        animSetCameraAnimation(D_802F0214_5ED2E4, D_801419E4, arg0);
    }
    PlayerModel_ChangeAnimation(D_8013EEE0, D_8013FDD0, arg0);
}

void func_802ED720_5EA7F0(DObj* arg0, s32 arg1, f32 arg2) {
    s32 idx;

    switch (arg1) {
        case -2:
        case -1:
            D_802F0218_5ED2E8 = 1;
            break;
        case 4:
            if (arg2 >= 0.0f) {
                D_802F0220_5ED2F0 = arg2;
            }
            break;
        case 5:
            idx = (s32) arg2;
            if (idx >= 0 && idx < ARRAY_COUNT(D_802F0204_5ED2D4)) {
                D_802F0224_5ED2F4 = D_802F0204_5ED2D4[idx];
            }
            break;
    }
}

void func_802ED7BC_5EA88C(DObj* arg0, s32 arg1, f32 arg2) {
    if (arg1 == -2 || arg1 == -1) {
    }
}

void func_802ED7CC_5EA89C(GObj* obj) {
    func_800AB9A4();

    for (D_8034474C_64181C = 0;; D_8034474C_64181C++) {
        switch (D_8034474C_64181C) {
            case 1:
                D_80344750_641820 = auPlaySoundWithParams(SOUND_ID_56, 0x6800, 64, 1.0f, 0);
                break;
            case 100:
                auPlaySoundWithParams(SOUND_ID_53, 0x5000, 64, 0.7f, 0);
                auPlaySoundWithParams(SOUND_ID_20, 0x5800, 54, 1.2f, 10);
                break;
            case 140:
                auPlaySoundWithParams(SOUND_ID_53, 0x7800, 54, 0.68f, 0);
                break;
            case 180:
                auPlaySoundWithParams(SOUND_ID_53, 0x6800, 94, 0.69f, 0);
                break;
            case 240:
                auPlaySoundWithParams(SOUND_ID_53, 0x5800, 74, 0.7f, 0);
                break;
            case 300:
                auPlaySoundWithParams(SOUND_ID_53, 0x5000, 54, 0.68f, 0);
                break;
            case 480:
                auPlaySoundWithParams(SOUND_ID_53, 0x5000, 54, 0.7f, 10);
                func_800AB700(D_80344750_641820, 0x6800, 0x1000, 90);
                break;
            case 540:
                D_80344751_641821 = auPlaySoundWithParams(SOUND_ID_14, 0x7400, 64, 1.0f, 20),
                auPlaySoundWithParams(SOUND_ID_50, 0x6800, 54, 0.8f, 10);
                break;
            case 580:
                auPlaySoundWithParams(SOUND_ID_53, 0x4000, 54, 0.62f, 10);
                auStopSound(D_80344750_641820);
                break;
            case 680:
                auPlaySoundWithParams(SOUND_ID_41, 0x7000, 54, 1.2f, 0x14);
                break;
            case 690:
                func_800AB700(D_80344751_641821, 0x7000, 0x1000, 0xC8);
                func_800AB41C(D_80344751_641821, 0x2C, 0x4A, 0xC8);
                break;
        }

        if (D_802F0218_5ED2E8 == 1) {
            auSetBGMVolumeSmooth(BGM_PLAYER_MAIN, 0, 120);
        }
        ohWait(1);
    }
}

void func_802EDAE8_5EABB8(void) {
    D_80344748_641818 = omAddGObj(OBJID_14, ohUpdateDefault, LINK_0, 0x80000000);
    omCreateProcess(D_80344748_641818, func_802ED7CC_5EA89C, 0, 1);
}

void func_802EDB3C_5EAC0C(GObj* obj) {
    UNUSED s32 padding[7];
    f32 sp34;
    GObj* temp_s0;
    f32 var_f20;
    s32 var_s1;
    GObj* playerGobj;

    Items_RemoveFlyingItems();
    resetMainCameraSettings();
    Msg_Reset();
    cmdSendCommand(gObjPlayer, PLAYER_CMD_10, NULL);
    if (func_800BFC5C_5CAFC() < 2) {
        func_800C02A0_5D140(2);
        func_800AAED0(0x400);
    }
    ohResumeObjectProcesses(D_802F0210_5ED2E0);
    auSetBGMVolumeSmooth(BGM_PLAYER_MAIN, 0, 240);
    setSkyBoxAnimationSpeed(tunnel_WorldSetup.unk_10);

    D_802F0214_5ED2E4 = getMainCamera();
    temp_s0 = D_802F0214_5ED2E4->obj;
    ohPauseObjectProcesses(temp_s0);
    omCreateProcess(temp_s0, animUpdateCameraAnimation, 1, 1);

    playerGobj = PlayerModel_Init();
    obj->fnAnimCallback = func_802ED7BC_5EA88C;
    animSetModelAnimationSpeed(obj, 0.5f);
    func_802ED6D0_5EA7A0(0.0f);
    func_802ED69C_5EA76C(0.5f);
    func_802EDAE8_5EABB8();
    D_802F0218_5ED2E8 = 0;
    playerGobj->fnAnimCallback = func_802ED720_5EA7F0;

    for (var_s1 = 0; D_802F0218_5ED2E8 == 0 && var_s1 < 10800; var_s1++) {
        if (D_802F0220_5ED2F0 >= 0.0f && D_802F0224_5ED2F4 >= 0.0f) {
            func_802ED69C_5EA76C(3.0f);
            ohWait(1);
            func_802ED69C_5EA76C(D_802F0224_5ED2F4);
            ohWait(1);
            D_802F0224_5ED2F4 = -1.0f;
            D_802F0220_5ED2F0 = D_802F0224_5ED2F4;
        }
        ohWait(1);
    }
    var_f20 = 1.0f;
    sp34 = -(var_f20 / 30.0f);
    func_800A7F68(10, 1);
    func_800A7470(0, 0, 0);
    func_800A7918(0, 0.5f);

    auSetBGMVolumeSmooth(BGM_PLAYER_AUX, 0, 30);
    ohWait(1);

    while (func_800A7460() == 1) {
        var_f20 += sp34;
        auSetSoundGlobalVolume(127.0f * var_f20);
        ohWait(1);
    }

    auSetSoundGlobalVolume(0);

    while (func_800A7460() == 1) {
        ohWait(1);
    }

    cmdSendCommand(gObjPlayer, PLAYER_CMD_7, NULL);
    omEndProcess(NULL);
    omDeleteGObj(D_80344748_641818);
    Pokemon_SetState(obj, NULL);
}

GObj* func_802EDEC0_5EAF90(s32 gObjID, u16 id, WorldBlock* roomA, WorldBlock* roomB, ObjectSpawn* spawn) {
    D_802F0210_5ED2E0 = Pokemon_SpawnDlLink4(gObjID, id, roomA, roomB, spawn, &D_802F025C_5ED32C);

    return D_802F0210_5ED2E0;
}
