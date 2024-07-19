#include "common.h"
#include "beach.h"

void func_beach_802C5150(GObj* obj) {
    func_803571C4_4F75D4();
    func_80357120_4F7530(obj);
    func_803570B0_4F74C0();
}

void func_beach_802C5180(void) {
    func_803572B0_4F76C0();
}

void func_beach_802C51A0(DObj* arg0, s32 arg1, f32 arg2) {
    UnkPinkRat* unk;

    if (arg1 == -2 || arg1 == -1) {
        D_beach_802CC0E0 = 1;
    } else if ((s32) arg2 - 1 >= 0) {
        unk = func_800A6C48(arg1, (s32) arg2 - 1);
        if (unk != NULL) {
            unk->dobj = arg0;
        }
    }
}

void func_beach_802C5214(void) {
    if (auPlayingSound[D_beach_80347588] == 0x15) {
        auStopSound(D_beach_80347588);
    }
    func_80357170_4F7580();
    resetMainCameraSettings();
    func_beach_802C5180();
    omDeleteGObj(NULL);
}

void func_beach_802C527C(GObj* obj) {
    s32 i;

    for (i = 0; i < 120; i++) {
        ohWait(1);
    }

    D_beach_80347588 = auPlaySoundWithParams(0x15, 0x6000, 0x40, 1.0f, 30);
    omEndProcess(NULL);
}

void func_beach_802C52EC(GObj* obj) {
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
    animSetCameraAnimation(cam, &D_8013DA90, 0.0f);
    proc = omCreateProcess(gobj, animUpdateCameraAnimation, 1, 1);
    PlayerModel_SetAnimation(&D_8013C580, &D_8013CEA0, 0.0f, 0.5f);
    D_beach_802CC0E0 = 0;
    obj->fnAnimCallback = func_beach_802C51A0;
    omCreateProcess(obj, func_beach_802C527C, 0, 1);

    i = 0;
    while (D_beach_802CC0E0 == 0 && i < 290) {
        if (gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
            omEndProcess(proc);
            func_beach_802C5214();
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
            func_beach_802C5214();
        }
        cam->viewMtx.lookAt.eye.x = (((f32) i * (startEyeX - baseEyeX)) / 10.0f) + baseEyeX;
        cam->viewMtx.lookAt.eye.y = (((f32) i * (startEyeY - baseEyeY)) / 10.0f) + baseEyeY;
        cam->viewMtx.lookAt.eye.z = (((f32) i * (startEyeZ - baseEyeZ)) / 10.0f) + baseEyeZ;
        cam->viewMtx.lookAt.at.x = (((f32) i * (startAtX - baseAtX)) / 10.0f) + baseAtX;
        cam->viewMtx.lookAt.at.y = (((f32) i * (startAtY - baseAtY)) / 10.0f) + baseAtY;
        cam->viewMtx.lookAt.at.z = (((f32) i * (startAtZ - baseAtZ)) / 10.0f) + baseAtZ;
        ohWait(1);
    }

    func_beach_802C5214();
    ohWait(1);
}

void func_beach_802C55CC(void) {
    GObj* obj;

    obj = PlayerModel_Init();
    D_beach_802CC0E4 = obj;
    if (obj != NULL) {
        omCreateProcess(obj, func_beach_802C52EC, 0, 1);
        func_beach_802C5150(obj);
    }
}
