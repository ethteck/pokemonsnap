#include "valley.h"

extern AnimCmd* D_80120520[];
extern AnimCmd** D_801212A0[];
extern AnimCmd D_80121D30[];

extern bool D_802D2A80_7AC010;
extern GObj* D_802D2A84_7AC014;

// BSS
extern u8 D_8034C8B8_825E48; // valley_intro_SoundHandle1;
extern u8 D_8034C8B9_825E49; // valley_intro_SoundHandle2;

void func_802C65E0_79FB70(GObj* arg0) {
    func_803571C4_4F75D4();
    func_80357120_4F7530(arg0);
    func_803570B0_4F74C0();
}

void func_802C6610_79FBA0(void) {
    func_803572B0_4F76C0();
}

void func_802C6630_79FBC0(DObj* dobj, s32 arg1, f32 arg2) {
    Effect* fx;
    s32 temp_a1;

    if (arg1 == -2 || arg1 == -1) {
        D_802D2A80_7AC010 = 1;
        return;
    }
    temp_a1 = (s32) arg2 - 1;
    if (temp_a1 >= 0) {
        fx = fx_createEffect(arg1, temp_a1);
        if (fx != NULL) {
            fx->dobj = dobj;
        }
    }
}

void valley_stopIntro(void) {
    if (auPlayingSound[D_8034C8B8_825E48] == SOUND_ID_21) {
        auStopSound(D_8034C8B8_825E48);
    }
    if (auPlayingSound[D_8034C8B9_825E49] == SOUND_ID_114) {
        auStopSound(D_8034C8B9_825E49);
    }
    func_80357170_4F7580();
    resetMainCameraSettings();
    func_802C6610_79FBA0();
    omDeleteGObj(NULL);
}

void func_802C673C_79FCCC(GObj* arg0) {
    s32 i;

    for (i = 0; i < 60; i++) {
        ohWait(1);
    }
    D_8034C8B8_825E48 = auPlaySoundWithParams(SOUND_ID_21, 0x5800, 0x40, 1.0f, 30);

    for (; i < 178; i++) {
        ohWait(1);
    }
    D_8034C8B9_825E49 = auPlaySoundWithParams(SOUND_ID_114, 0x4800, 0x40, 1.0f, 30);
    omEndProcess(NULL);
}

void func_802C67F4_79FD84(GObj* obj) {
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
    animSetCameraAnimation(camera, D_80121D30, 0);
    animProc = omCreateProcess(camObj, animUpdateCameraAnimation, 1, 1);
    PlayerModel_SetAnimation(D_80120520, D_801212A0, 0, 0.5f);
    D_802D2A80_7AC010 = false;
    obj->fnAnimCallback = func_802C6630_79FBC0;
    omCreateProcess(obj, func_802C673C_79FCCC, 0, 1);

    for (i = 0; !D_802D2A80_7AC010 && i < 290; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            omEndProcess(animProc);
            valley_stopIntro();
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
            valley_stopIntro();
        }
        camera->viewMtx.lookAt.eye.x = i * (origXEye - xEye) / 10.0f + xEye;
        camera->viewMtx.lookAt.eye.y = i * (origYEye - yEye) / 10.0f + yEye;
        camera->viewMtx.lookAt.eye.z = i * (origZEye - zEye) / 10.0f + zEye;
        camera->viewMtx.lookAt.at.x = i * (origXAt - xAt) / 10.0f + xAt;
        camera->viewMtx.lookAt.at.y = i * (origYAt - yAt) / 10.0f + yAt;
        camera->viewMtx.lookAt.at.z = i * (origZAt - zAt) / 10.0f + zAt;
        ohWait(1);
    };

    valley_stopIntro();
    ohWait(1);
}

void func_802C6AD4_7A0064(void) {
    GObj* playerObj;

    playerObj = PlayerModel_Init();
    D_802D2A84_7AC014 = playerObj;
    if (playerObj != NULL) {
        omCreateProcess(playerObj, func_802C67F4_79FD84, 0, 1);
        func_802C65E0_79FB70(playerObj);
    }
}
