#include "common.h"

extern Gfx D_credits_801DEBD8[];
extern ScreenSettings D_credits_801DEBA0;
extern DynamicBuffer sGeneralHeap;
extern s32 D_credits_801ECDA0; // scene id
extern u8 D_801ED020[];
extern s32 D_credits_801DEC40;
extern OSMesg D_credits_801ECC40[10];
extern OSThread D_credits_801E9A90;
extern SceneSetup D_credits_801DEC30;
extern OSMesgQueue D_credits_801ECC68;

void func_80374D40(void);
void func_credits_801DE844(GObj*);
void func_8036A228_83D9D8(void*);
OSThread* func_80000460(void);
void func_8009FC38(void*);
void func_credits_801DE8A0(void*, s32);
s32 func_credits_801DE8D8(void);

void func_credits_801DC8A0(Gfx** gfx) {
    gSPDisplayList((*gfx)++, &D_credits_801DEBD8);
}

void func_credits_801DC8C4(void) {
    u32 sp40;
    u32 var_a1;

    viApplyScreenSettings(&D_credits_801DEBA0);
    if (D_credits_801ECDA0 == 19) {
        var_a1 = 0x64000;
    } else {
        var_a1 = 0x78000;
    }
    func_8036A3F8(mlHeapAlloc(&sGeneralHeap, var_a1, 8U), (s32) var_a1);
    func_800AAE28();
    func_80374D40();
    ohCreateCameraWrapper(0, 0x80000000, 0x64, 6, 0xFF);
    ohCreateCamera(3, &ohUpdateDefault, 0, 0x80000000, &renSpriteCameraRender, 3, 2, -1, 1, 1, 0, 1, 1)
        ->data.cam->flags = 8;
    func_800A7F68(0, 0x101);
    omCreateProcess(omAddGObj(0xEU, NULL, 0U, 0x80000000U), func_credits_801DE844, 0U, 1U);
}

void func_credits_801DC9FC(void* arg1) {
    func_8036A228_83D9D8(arg1);
}

void func_credits_801DCA1C(void* arg0) {
    void* sp34;
    s32 temp_v0;
    void* temp_v0_2;

    while (TRUE) {
        osRecvMesg(&D_credits_801ECC68, &sp34, 1);
        osSetThreadPri(NULL, 0x34);
        temp_v0 = func_credits_801DE8D8();
        temp_v0_2 = func_800BF710_5C5B0(temp_v0);
        if (temp_v0_2 != NULL) {
            func_8009FC38(temp_v0_2);
        }
        osSetThreadPri(NULL, 0x31);
        osStopThread(func_80000460());
        osSetThreadPri(NULL, 0x34);
        func_credits_801DE8A0(sp34, temp_v0);
        osSetThreadPri(NULL, 0x31);
        osStartThread(func_80000460());
    }
}

void func_credits_801DCAF8(void* arg0) {
    osSendMesg(&D_credits_801ECC68, arg0, 1);
}

s32 func_credits_801DCB24(s32 sceneId) {
    D_credits_801ECDA0 = sceneId;
    D_credits_801DEC40 = (uintptr_t) &D_80369F80 - (uintptr_t) &D_801ED020;
    gtlDisableNearClipping(1);
    gtlSetIntervals(1U, 2U);
    osCreateMesgQueue(&D_credits_801ECC68, D_credits_801ECC40, ARRAY_COUNT(D_credits_801ECC40));
    osCreateThread(&D_credits_801E9A90, 0x64, func_credits_801DCA1C, NULL, &D_credits_801ECC40, 0x31);
    osStartThread(&D_credits_801E9A90);
    omSetupScene(&D_credits_801DEC30);
    osStopThread(&D_credits_801E9A90);
    osDestroyThread(&D_credits_801E9A90);

    return SCENE_8;
}
