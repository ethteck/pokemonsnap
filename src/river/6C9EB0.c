#include "common.h"
#include "app_level/app_level.h"
#include "river.h"

extern AnimCmd* D_8014A660;
extern AnimCmd** D_8014B450;
extern AnimCmd D_8014BF30;
extern s32 D_802E4B80_6CC960;
extern GObj* D_802E4B84_6CC964;

extern u8 D_8033F698_727478;
extern u8 D_8033F699_727479;

void func_802E20D0_6C9EB0(GObj* arg0) {
    func_803571C4_4F75D4();
    func_80357120_4F7530(arg0);
    func_803570B0_4F74C0();
}

void func_802E2100_6C9EE0(void) {
    func_803572B0_4F76C0();
}

void func_802E2120_6C9F00(DObj* arg0, s32 arg1, f32 arg2) {
    UnkPinkRat* temp_v0;
    s32 temp_a1;

    if (arg1 == -2 || arg1 == -1) {
        D_802E4B80_6CC960 = 1;
        return;
    }

    temp_a1 = (s32) arg2 - 1;
    if (temp_a1 >= 0) {
        temp_v0 = func_800A6C48(arg1, temp_a1);
        if (temp_v0 != NULL) {
            temp_v0->dobj = arg0;
        }
    }
}

void func_802E2194_6C9F74(void) {
    if (auPlayingSound[D_8033F698_727478] == 21) {
        auStopSound(D_8033F698_727478);
    }
    if (auPlayingSound[D_8033F699_727479] == 114) {
        auStopSound(D_8033F699_727479);
    }
    func_80357170_4F7580();
    resetMainCameraSettings();
    func_802E2100_6C9EE0();
    omDeleteGObj(NULL);
}

void func_802E222C_6CA00C(GObj* arg0) {
    s32 i;

    for (i = 0; i < 60; i++) {
        ohWait(1);
    }
    D_8033F698_727478 = auPlaySoundWithParams(SOUND_ID_21, 0x7800, 0x40, 1.0f, 30);

    for (; i < 178; i++) {
        ohWait(1);
    }
    D_8033F699_727479 = auPlaySoundWithParams(SOUND_ID_114, 0x5000, 0x40, 1.0f, 30);
    omEndProcess(NULL);
}

void func_802E22E4_6CA0C4(GObj* obj) {
    s32 unused[4];
    GObj* gobj;
    f32 baseAtX, baseAtY;
    f32 startEyeX, startEyeY, startEyeZ;
    f32 startAtX, startAtY, startAtZ;
    f32 baseEyeX, baseEyeY, baseEyeZ;
    OMCamera* cam;
    GObjProcess* proc;
    f32 baseAtZ;
    s32 i;

    cam = getMainCamera();
    gobj = getMainCamera()->obj;

    startEyeX = cam->viewMtx.lookAt.eye.x;
    startEyeY = cam->viewMtx.lookAt.eye.y;
    startEyeZ = cam->viewMtx.lookAt.eye.z;
    startAtX = cam->viewMtx.lookAt.at.x;
    startAtY = cam->viewMtx.lookAt.at.y;
    startAtZ = cam->viewMtx.lookAt.at.z;

    cam->animSpeed = 0.5f;
    animSetCameraAnimation(cam, &D_8014BF30, 0.0f);
    proc = omCreateProcess(gobj, animUpdateCameraAnimation, 1, 1);
    PlayerModel_SetAnimation(&D_8014A660, &D_8014B450, 0.0f, 0.5f);
    D_802E4B80_6CC960 = 0;
    obj->fnAnimCallback = func_802E2120_6C9F00;
    omCreateProcess(obj, func_802E222C_6CA00C, 0, 1);

    i = 0;
    while (D_802E4B80_6CC960 == 0 && i < 290) {
        if (gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
            omEndProcess(proc);
            func_802E2194_6C9F74();
        }
        ohWait(1);
        i++;
    }

    omEndProcess(proc);

    baseEyeX = cam->viewMtx.lookAt.eye.x;
    baseEyeY = cam->viewMtx.lookAt.eye.y;
    baseEyeZ = cam->viewMtx.lookAt.eye.z;
    baseAtX = cam->viewMtx.lookAt.at.x;
    baseAtY = cam->viewMtx.lookAt.at.y;
    baseAtZ = cam->viewMtx.lookAt.at.z;

    for (i = 0; i <= 10; i++) {
        if (gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
            func_802E2194_6C9F74();
        }
        cam->viewMtx.lookAt.eye.x = (((f32) i * (startEyeX - baseEyeX)) / 10.0f) + baseEyeX;
        cam->viewMtx.lookAt.eye.y = (((f32) i * (startEyeY - baseEyeY)) / 10.0f) + baseEyeY;
        cam->viewMtx.lookAt.eye.z = (((f32) i * (startEyeZ - baseEyeZ)) / 10.0f) + baseEyeZ;
        cam->viewMtx.lookAt.at.x = (((f32) i * (startAtX - baseAtX)) / 10.0f) + baseAtX;
        cam->viewMtx.lookAt.at.y = (((f32) i * (startAtY - baseAtY)) / 10.0f) + baseAtY;
        cam->viewMtx.lookAt.at.z = (((f32) i * (startAtZ - baseAtZ)) / 10.0f) + baseAtZ;
        ohWait(1);
    }

    func_802E2194_6C9F74();
    ohWait(1);
}

void func_802E25C4_6CA3A4(void) {
    GObj* temp_v0;

    temp_v0 = PlayerModel_Init();
    D_802E4B84_6CC964 = temp_v0;
    if (temp_v0 != NULL) {
        omCreateProcess(temp_v0, func_802E22E4_6CA0C4, 0, 1);
        func_802E20D0_6C9EB0(temp_v0);
    }
}
