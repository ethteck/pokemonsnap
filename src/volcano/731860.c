#include "volcano/volcano.h"

extern AnimCmd D_80118D90[];
extern AnimCmd* D_801174E0[];
extern AnimCmd** D_801182F0[];
extern s32 D_802E3800_734A00;
extern GObj* D_802E3804_734A04;

extern u8 D_8034E108_79F308;
extern u8 D_8034E109_79F309;
extern u8 D_8034E10A_79F30A;
extern u8 D_8034E10B_79F30B;

void func_802E0660_731860(GObj* obj) {
    func_803571C4_4F75D4();
    func_80357120_4F7530(obj);
    func_803570B0_4F74C0();
}

void func_802E0690_731890(void) {
    func_803572B0_4F76C0();
}

void func_802E06B0_7318B0(struct DObj* dobj, s32 param, f32 value) {
    if (param == -2 || param == -1) {
        D_802E3800_734A00 = 1;
    } else if ((s32)value - 1 >= 0) {
        UnkPinkRat* unk = func_800A6C48(param, (s32)value - 1);
        if (unk != NULL) {
            unk->dobj = dobj;
        }
    }
}

void func_802E0724_731924(void) {
    if (auPlayingSound[D_8034E108_79F308] == SOUND_ID_21) {
        auStopSound(D_8034E108_79F308);
    }
    if (auPlayingSound[D_8034E109_79F309] == SOUND_ID_101) {
        auStopSound(D_8034E109_79F309);
    }
    if (auPlayingSound[D_8034E10A_79F30A] == SOUND_ID_30) {
        auStopSound(D_8034E10A_79F30A);
    }
    if (auPlayingSound[D_8034E10B_79F30B] == SOUND_ID_50) {
        auStopSound(D_8034E10B_79F30B);
    }
    func_80357170_4F7580();
    resetMainCameraSettings();
    func_802E0690_731890();
    omDeleteGObj(NULL);
}

void func_802E081C_731A1C(GObj* obj) {
    s32 i;

    for (i = 0; i < 60; i++) {
        ohWait(1);
    }
    D_8034E108_79F308 = auPlaySoundWithParams(SOUND_ID_21, 32256, 64, 1.0f, 30);
    for (; i < 178; i++) {
        ohWait(1);
    }
    D_8034E109_79F309 = auPlaySoundWithParams(SOUND_ID_101, 12288, 64, 1.5f, 30);
    D_8034E10A_79F30A = auPlaySoundWithParams(SOUND_ID_30, 8192, 64, 0.6f, 30);
    for (; i < 196; i++) {
        ohWait(1);
    }
    D_8034E10B_79F30B = auPlaySoundWithParams(SOUND_ID_50, 12288, 64, 0.74f, 30);
    omEndProcess(NULL);
}

void func_802E0948_731B48(GObj* obj) {
    s32 unused[4];
    s32 i;
    OMCamera* temp_s1 = getMainCamera();
    GObj* temp_s0 = getMainCamera()->obj;
    f32 spB0, spAC, spA8;
    f32 spA4, spA0, sp9C;
    f32 temp_f22, temp_f24, temp_f26;
    f32 temp_f28, temp_f30, sp84;
    GObjProcess* temp_s5;

    spB0 = temp_s1->viewMtx.lookAt.eye.x;
    spAC = temp_s1->viewMtx.lookAt.eye.y;
    spA8 = temp_s1->viewMtx.lookAt.eye.z;
    spA4 = temp_s1->viewMtx.lookAt.at.x;
    spA0 = temp_s1->viewMtx.lookAt.at.y;
    sp9C = temp_s1->viewMtx.lookAt.at.z;
    temp_s1->animSpeed = 0.5f;
    animSetCameraAnimation(temp_s1, D_80118D90, 0);
    temp_s5 = omCreateProcess(temp_s0, animUpdateCameraAnimation, 1, 1);
    PlayerModel_SetAnimation(D_801174E0, D_801182F0, 0, 0.5f);
    D_802E3800_734A00 = 0;
    obj->fnAnimCallback = func_802E06B0_7318B0;
    omCreateProcess(obj, func_802E081C_731A1C, 0, 1);

    for (i = 0; !D_802E3800_734A00 && i < 290; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            omEndProcess(temp_s5);
            func_802E0724_731924();
        }
        ohWait(1);
    }

    omEndProcess(temp_s5);

    temp_f22 = temp_s1->viewMtx.lookAt.eye.x;
    temp_f24 = temp_s1->viewMtx.lookAt.eye.y;
    temp_f26 = temp_s1->viewMtx.lookAt.eye.z;
    temp_f28 = temp_s1->viewMtx.lookAt.at.x;
    temp_f30 = temp_s1->viewMtx.lookAt.at.y;
    sp84 = temp_s1->viewMtx.lookAt.at.z;

    for (i = 0; i < 11; i++) {
        if (gContInputPressedButtons & (START_BUTTON | A_BUTTON)) {
            func_802E0724_731924();
        }
        temp_s1->viewMtx.lookAt.eye.x = i * (spB0 - temp_f22) / 10.0f + temp_f22;
        temp_s1->viewMtx.lookAt.eye.y = i * (spAC - temp_f24) / 10.0f + temp_f24;
        temp_s1->viewMtx.lookAt.eye.z = i * (spA8 - temp_f26) / 10.0f + temp_f26;
        temp_s1->viewMtx.lookAt.at.x = i * (spA4 - temp_f28) / 10.0f + temp_f28;
        temp_s1->viewMtx.lookAt.at.y = i * (spA0 - temp_f30) / 10.0f + temp_f30;
        temp_s1->viewMtx.lookAt.at.z = i * (sp9C - sp84) / 10.0f + sp84;
        ohWait(1);
    };

    func_802E0724_731924();
    ohWait(1);
}

void func_802E0C28_731E28(void) {
    GObj* obj;

    obj = PlayerModel_Init();
    D_802E3804_734A04 = obj;
    if (obj != NULL) {
        omCreateProcess(obj, func_802E0948_731B48, 0, 1);
        func_802E0660_731860(obj);
    }
}
