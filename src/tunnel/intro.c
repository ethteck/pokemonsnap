#include "tunnel.h"

extern AnimCmd D_8013EE60[];
extern AnimCmd* D_8013D920[];
extern AnimCmd** D_8013E3D0[];

extern bool D_802F01E0_5ED2B0;
extern GObj* D_802F01E4_5ED2B4;

extern u8 D_80344738_641808;
extern u8 D_80344739_641809;
extern u8 D_8034473A_64180A;
extern u8 D_8034473B_64180B;

void func_802ED000_5EA0D0(GObj* obj) {
    func_803571C4_4F75D4();
    func_80357120_4F7530(obj);
    func_803570B0_4F74C0();
}

void func_802ED030_5EA100(void) {
    func_803572B0_4F76C0();
}

void func_802ED050_5EA120(struct DObj* dobj, s32 param, f32 value) {
    if (param == -2 || param == -1) {
        D_802F01E0_5ED2B0 = true;
    } else if ((s32) value - 1 >= 0) {
        UnkPinkRat* effect = func_800A6C48(param, (s32) value - 1);
        if (effect != NULL) {
            effect->dobj = dobj;
        }
    }
}

void func_802ED0C4_5EA194(void) {
    if (auPlayingSound[D_80344738_641808] == SOUND_ID_21) {
        auStopSound(D_80344738_641808);
    }
    if (auPlayingSound[D_80344739_641809] == SOUND_ID_101) {
        auStopSound(D_80344739_641809);
    }
    if (auPlayingSound[D_8034473A_64180A] == SOUND_ID_30) {
        auStopSound(D_8034473A_64180A);
    }
    if (auPlayingSound[D_8034473B_64180B] == SOUND_ID_50) {
        auStopSound(D_8034473B_64180B);
    }
    func_80357170_4F7580();
    resetMainCameraSettings();
    func_802ED030_5EA100();
    omDeleteGObj(NULL);
}

void func_802ED1BC_5EA28C(GObj* obj) {
    s32 i;

    for (i = 0; i < 60; i++) {
        ohWait(1);
    }
    D_80344738_641808 = auPlaySoundWithParams(SOUND_ID_21, 32512, 64, 1.0f, 30);
    for (; i < 178; i++) {
        ohWait(1);
    }
    D_80344739_641809 = auPlaySoundWithParams(SOUND_ID_101, 12288, 64, 1.5f, 30);
    D_8034473A_64180A = auPlaySoundWithParams(SOUND_ID_30, 8192, 64, 0.6f, 30);
    for (; i < 196; i++) {
        ohWait(1);
    }
    D_8034473B_64180B = auPlaySoundWithParams(SOUND_ID_50, 12288, 64, 0.74f, 30);
    omEndProcess(NULL);
}

void func_802ED2E8_5EA3B8(GObj* obj) {
    s32 unused[4];
    s32 i;
    OMCamera* camera = getMainCamera();
    GObj* camObj = getMainCamera()->obj;
    f32 origXEye, origYEye, origZEye;
    f32 origXAt, origYAt, origZAt;
    f32 xEye, yEye, zEye;
    f32 xAt, yAt, zAt;
    GObjProcess* animProc;

    origXEye = camera->viewMtx.lookAt.eye.x;
    origYEye = camera->viewMtx.lookAt.eye.y;
    origZEye = camera->viewMtx.lookAt.eye.z;
    origXAt = camera->viewMtx.lookAt.at.x;
    origYAt = camera->viewMtx.lookAt.at.y;
    origZAt = camera->viewMtx.lookAt.at.z;
    camera->animSpeed = 0.5f;
    animSetCameraAnimation(camera, D_8013EE60, 0);
    animProc = omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    PlayerModel_SetAnimation(D_8013D920, D_8013E3D0, 0, 0.5f);
    D_802F01E0_5ED2B0 = false;
    obj->fnAnimCallback = func_802ED050_5EA120;
    omCreateProcess(obj, func_802ED1BC_5EA28C, 0, 1);

    for (i = 0; !D_802F01E0_5ED2B0 && i < 290; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            omEndProcess(animProc);
            func_802ED0C4_5EA194();
        }
        ohWait(1);
    }

    omEndProcess(animProc);

    xEye = camera->viewMtx.lookAt.eye.x;
    yEye = camera->viewMtx.lookAt.eye.y;
    zEye = camera->viewMtx.lookAt.eye.z;
    xAt = camera->viewMtx.lookAt.at.x;
    yAt = camera->viewMtx.lookAt.at.y;
    zAt = camera->viewMtx.lookAt.at.z;

    for (i = 0; i < 11; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            func_802ED0C4_5EA194();
        }
        camera->viewMtx.lookAt.eye.x = i * (origXEye - xEye) / 10.0f + xEye;
        camera->viewMtx.lookAt.eye.y = i * (origYEye - yEye) / 10.0f + yEye;
        camera->viewMtx.lookAt.eye.z = i * (origZEye - zEye) / 10.0f + zEye;
        camera->viewMtx.lookAt.at.x = i * (origXAt - xAt) / 10.0f + xAt;
        camera->viewMtx.lookAt.at.y = i * (origYAt - yAt) / 10.0f + yAt;
        camera->viewMtx.lookAt.at.z = i * (origZAt - zAt) / 10.0f + zAt;
        ohWait(1);
    };

    func_802ED0C4_5EA194();
    ohWait(1);
}

void func_802ED5C8_5EA698(void) {
    GObj* obj;

    obj = PlayerModel_Init();
    D_802F01E4_5ED2B4 = obj;
    if (obj != NULL) {
        omCreateProcess(obj, func_802ED2E8_5EA3B8, 0, 1);
        func_802ED000_5EA0D0(obj);
    }
}
