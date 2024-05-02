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

void func_beach_802C51A0(DObj* arg0, u32 arg1, f32 arg2) {
    GObj* obj;

    if (arg1 == -2 || arg1 == -1) {
        D_beach_802CC0E0 = 1;
    } else if ((s32) arg2 - 1 >= 0) {
        obj = func_800A6C48(arg1, (s32) arg2 - 1);
        if (obj != NULL) {
            obj->data.dobj = arg0;
        }
    }
}

void func_beach_802C5214(void) {
    if (D_800968BC[D_beach_80347588] == 0x15) {
        auStopSound(D_beach_80347588);
    }
    func_80357170_4F7580();
    func_803573BC_4F77CC();
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

#ifdef NON_MATCHING
OMCamera* func_803586F8_4F8B08();
extern AnimCmd D_8013DA90;
void func_80365F38_506348(UNK_PTR, UNK_PTR, s32, s32);

extern u8 D_8013C580;
extern u8 D_8013CEA0;

void func_beach_802C52EC(GObj* obj) {
    s32 unused[3];
    Vec3f base_at;
    Vec3f start_eye;
    Vec3f start_at;
    Vec3f base_eye;
    f32 sp8C;
    GObj* temp_s0;
    OMCamera* temp_s1;
    GObjProcess* temp_s5;
    s32 i;

    temp_s1 = func_803586F8_4F8B08();
    temp_s0 = func_803586F8_4F8B08()->obj;

    start_eye.x = temp_s1->viewMtx.lookAt.eye.x;
    start_eye.y = temp_s1->viewMtx.lookAt.eye.y;
    start_eye.z = temp_s1->viewMtx.lookAt.eye.z;
    start_at.x = temp_s1->viewMtx.lookAt.at.x;
    start_at.y = temp_s1->viewMtx.lookAt.at.y;
    start_at.z = temp_s1->viewMtx.lookAt.at.z;

    temp_s1->animSpeed = 0.5f;
    animSetCameraAnimation(temp_s1, &D_8013DA90, 0.0f);
    temp_s5 = omCreateProcess(temp_s0, animUpdateCameraAnimation, 1, 1);
    func_80365F38_506348(&D_8013C580, &D_8013CEA0, 0, 0x3F000000);
    D_beach_802CC0E0 = 0;
    obj->fnAnimCallback = func_beach_802C51A0;
    omCreateProcess(obj, func_beach_802C527C, 0, 1);

    for (i = 0; i < 290 && D_beach_802CC0E0 == 0; i++) {
        if (gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
            omEndProcess(temp_s5);
            func_beach_802C5214();
        }
        ohWait(1);
    }

    omEndProcess(temp_s5);

    base_eye.x = temp_s1->viewMtx.lookAt.eye.x;
    base_eye.y = temp_s1->viewMtx.lookAt.eye.y;
    base_eye.z = temp_s1->viewMtx.lookAt.eye.z;
    base_at.x = temp_s1->viewMtx.lookAt.at.x;
    base_at.y = temp_s1->viewMtx.lookAt.at.y;
    base_at.z = temp_s1->viewMtx.lookAt.at.z;

    for (i = 0; i <= 10; i++) {
        if (gContInputPressedButtons & (A_BUTTON | START_BUTTON)) {
            func_beach_802C5214();
        }
        temp_s1->viewMtx.lookAt.eye.x = (((f32) i * (start_eye.x - base_eye.x)) / 10.0f) + base_eye.x;
        temp_s1->viewMtx.lookAt.eye.y = (((f32) i * (start_eye.y - base_eye.y)) / 10.0f) + base_eye.y;
        temp_s1->viewMtx.lookAt.eye.z = (((f32) i * (start_eye.z - base_eye.z)) / 10.0f) + base_eye.z;
        temp_s1->viewMtx.lookAt.at.x = (((f32) i * (start_at.x - base_at.x)) / 10.0f) + base_at.x;
        temp_s1->viewMtx.lookAt.at.y = (((f32) i * (start_at.y - base_at.y)) / 10.0f) + base_at.y;
        temp_s1->viewMtx.lookAt.at.z = (((f32) i * (start_at.z - base_at.z)) / 10.0f) + base_at.z;
        ohWait(1);
    }

    func_beach_802C5214();
    ohWait(1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/beach/55D1C0/func_beach_802C52EC.s")
#endif

void func_beach_802C55CC(void) {
    GObj* obj;

    obj = func_80365E80_506290();
    D_beach_802CC0E4 = obj;
    if (obj != NULL) {
        omCreateProcess(obj, func_beach_802C52EC, 0, 1);
        func_beach_802C5150(obj);
    }
}
