#include "common.h"
#include "../window/window.h"
#include "credits.h"

// .bss
OSThread D_credits_801E9A90;
u8 D_credits_801E9C40[0x3000];
OSMesg D_credits_801ECC40[10];
OSMesgQueue D_credits_801ECC68;

void func_credits_801DC8C4(void);
void func_credits_801DC9FC(void*);

// .data
ScreenSettings D_credits_801DEBA0 = {
    D_803B5000,    /* fb1 */
    D_803DA800,    /* fb2 */
    NULL,          /* fb3 */
    NULL,          /* zbuffer */
    SCREEN_WIDTH,  /* width*/
    SCREEN_HEIGHT, /* height */
    0x00016A99     /* flags*/
};
u32 D_credits_801DEBBC = 0x00000000;
Lights1 D_credits_801DEBC0 = gdSPDefLights1(100, 100, 100, 180, 180, 180, 30, 30, 30);

Gfx D_credits_801DEBD8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPFogFactor(256, -512),
    gsDPSetFogColor(0x00, 0x00, 0x00, 0xFF),
    gsSPSetGeometryMode(G_FOG),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPSetLights1(D_credits_801DEBC0),
    gsSPEndDisplayList(),
};

SceneSetup D_credits_801DEC30 = {
    {
        0,              /* unk_00*/
        omUpdateAll,    /* fnUpdate */
        omDrawAll,      /* fnDraw */
        D_801ED020,     /* heapBase */
        0,              /* heapSize */
        1,              /* unk_14 */
        1,              /* numContexts */
        0x8000,         /* dlBufferSize0 */
        0x2000,         /* dlBufferSize1 */
        0x0000,         /* dlBufferSize2 */
        0x0000,         /* dlBufferSize3 */
        0x1800,         /* gfxHeapSize */
        0,              /* unk30 */
        0,              /* rdpOutputBufferSize */
        func_800A1A50,  /* fnPreRender */
        contUpdate      /* fnUpdateInput */
    },
    8,                     /* numOMThreads */
    0x2800,                /* omThreadStackSize */
    32,                    /* numOMStacks */
    0,                     /* unk4C */
    8,                     /* numOMProcesses */
    16,                    /* numOMGobjs */
    sizeof(GObj),          /* objectSize */
    512,                   /* numOMMtx */
    NULL,                  /* unk60 */
    func_credits_801DC9FC, /* unk64 */
    0,                     /* numOMAobjs */
    0,                     /* numOMMobjs */
    0,                     /* numOMDobjs */
    sizeof(DObj),          /* omDobjSize */
    96,                    /* numOMSobjs */
    0x58,                  /* omSobjSize */
    2,                     /* numOMCameras */
    sizeof(OMCamera),      /* omCameraSize */
    func_credits_801DC8C4  /* postInitFunc */
};

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
    UIMem_CreateHeap(mlHeapAlloc(&sGeneralHeap, var_a1, 8), (s32) var_a1);
    func_800AAE28();
    func_80374D40_8484F0();
    ohCreateCameraWrapper(0, 0x80000000, 0x64, 6, 0xFF);
    ohCreateCamera(3, &ohUpdateDefault, 0, 0x80000000, &renSpriteCameraRender, 3, 2, -1, 1, 1, 0, 1, 1)
        ->data.cam->flags = CAMERA_FLAG_8;
    func_800A7F68(0, 0x101);
    omCreateProcess(omAddGObj(0xE, NULL, 0, 0x80000000), func_credits_801DE844, 0, 1);
}

void func_credits_801DC9FC(void* arg1) {
    UIMem_Deallocate(arg1);
}

void func_credits_801DCA1C(void* arg0) {
    void* sp34;
    s32 temp_v0;
    PhotoData* temp_v0_2;

    while (true) {
        osRecvMesg(&D_credits_801ECC68, &sp34, 1);
        osSetThreadPri(NULL, 0x34);
        temp_v0 = func_credits_801DE8D8();
        temp_v0_2 = func_800BF710_5C5B0(temp_v0); // TODO TYPE
        if (temp_v0_2 != NULL) {
            func_8009FC38(temp_v0_2);
        }
        osSetThreadPri(NULL, 0x31);
        osStopThread(get_main_thread());
        osSetThreadPri(NULL, 0x34);
        func_credits_801DE8A0(sp34, temp_v0);
        osSetThreadPri(NULL, 0x31);
        osStartThread(get_main_thread());
    }
}

void func_credits_801DCAF8(SObj* arg0) {
    osSendMesg(&D_credits_801ECC68, arg0, 1);
}

s32 func_credits_801DCB24(s32 sceneId) {
    D_credits_801ECDA0 = sceneId;
    D_credits_801DEC30.gtlSetup.heapSize = (uintptr_t) D_80369F80 - (uintptr_t) D_801ED020;
    gtlDisableNearClipping(1);
    gtlSetIntervals(1, 2);
    osCreateMesgQueue(&D_credits_801ECC68, D_credits_801ECC40, ARRAY_COUNT(D_credits_801ECC40));
    osCreateThread(&D_credits_801E9A90, 0x64, func_credits_801DCA1C, NULL, &D_credits_801ECC40, 0x31);
    osStartThread(&D_credits_801E9A90);
    omSetupScene(&D_credits_801DEC30);
    osStopThread(&D_credits_801E9A90);
    osDestroyThread(&D_credits_801E9A90);

    return SCENE_MAIN_MENU;
}
