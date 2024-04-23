#include "common.h"
#include "sys/oh.h"

void func_8009FA68(void* arg0, s32* arg1);
void func_801DC9D0_AA1A10(GObj*);

extern Sprite D_801E5478_AAA4B8;
extern u8 D_801E54BC_AAA4FC;
extern u8 D_801E54C0_AAA500;
extern u8 D_801E54C4_AAA504;
extern s32 D_801E54C8_AAA508;
extern s32 D_801E550C_AAA54C;
extern ScreenSettings D_801E5510_AAA550;
extern SceneSetup D_801E552C_AAA56C;
extern s32 D_801E553C_AAA57C;
extern f32 D_801E55C0_AAA600;
extern s32 D_801E55D8_AAA618;
extern GObj* D_801E55DC_AAA61C;

void func_801DC8A0_AA18E0(s32 arg0) {
    if (arg0 == 4) {
        PANIC();
    }
    if (arg0 == 2) {
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
        contPrinterSendCommand(0x10);
    }
    D_801E54C8_AAA508 = arg0;
    if (arg0 == 0) {
        func_8009FBC4();
    }
    func_800067DC();
}

void func_801DC930_AA1970(void* arg0, s32* arg1) {
    GObj* obj;

    func_8009FA68(arg0, arg1);
    obj = omGObjListHead[D_801E54C0_AAA500];
    while (obj != NULL) {
        ohPauseObjectProcesses(obj);
        obj = obj->next;
    }
    obj = omGObjListHead[D_801E54C4_AAA504];
    while (obj != NULL) {
        ohPauseObjectProcesses(obj);
        obj = obj->next;
    }
}

void func_801DC9BC_AA19FC(s32 unused) {
    D_801E550C_AAA54C = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DC9D0_AA1A10.s")

void func_801DCCD4_AA1D14(s32 unused) {
}

#if 0
u64 D_801E55E0_AAA620;
//s32 D_801E55E4_AAA624;
u64 D_801E55E8_AAA628;
//s32 D_801E55EC_AAA62C;
void func_801DCCDC_AA1D1C(void) {
    GObj* cam;
    OMCamera* omCamera;
    s32 stackpad;

    D_801E5510_AAA550.zBuffer = gtlMalloc(0x96000, 0x40);
    viApplyScreenSettings(&D_801E5510_AAA550);
    ohCreateCameraWrapper(0, 0x80000000, 0x64, 2, -1);
    cam = ohCreateCamera(1, (void*) func_801DCCD4_AA1D14, 0, 0x80000000, ren_func_800192DC, 5, 1 << D_801E54BC_AAA4FC, -1, 0, 1, NULL, 0, 0);
    if (cam == NULL) {
        func_801DC8A0_AA18E0(4);
    }
    omCamera = cam->data.cam;
    omCreateProcess(cam, func_801DC9D0_AA1A10, 0, 1);
    omCamera->flags |= 5;
    omCamera->vp.vp.vscale[0] = (omCamera->vp.vp.vscale[0] * 97) / 100;
    omCamera->vp.vp.vscale[1] = (omCamera->vp.vp.vscale[1] * 93) / 100;
    omCamera->vp.vp.vtrans[1] = (omCamera->vp.vp.vtrans[1] * 93) / 100;
    omCameraAddMtx(omCamera, 3, 0);
    omCameraAddMtx(omCamera, 0xE, 0);
    omCamera->perspMtx.persp.near = 10.0f;
    omCamera->perspMtx.persp.far = 25600.0f;
    omCamera->perspMtx.persp.fovy = 60.0f;
    omCamera->perspMtx.persp.aspect = D_801E55C0_AAA600;

    omCamera->viewMtx.lookAt.at.x = 0.0f;

    omCamera->viewMtx.lookAt.eye.x = 0.0f;
    omCamera->viewMtx.lookAt.eye.y = 100.0f;
    
    omCamera->viewMtx.lookAt.at.y = 0.0f;
    omCamera->viewMtx.lookAt.eye.z = 0.0f;
    omCamera->viewMtx.lookAt.up.z = 1.0f;
    
    omCamera->viewMtx.lookAt.at.z = 0.0f;
    omCamera->viewMtx.lookAt.up.x = 0.0f;
    omCamera->viewMtx.lookAt.up.y = 0.0f;

    cam = ohCreateCamera(3, ohUpdateDefault, 0, 0x80000000, renSpriteCameraRender, 3, 2, -1, 1, 1, NULL, 1, 1);
    cam->data.cam->flags = 8;
    cam->flags = 1;
    D_801E55DC_AAA61C = cam;
    ohCreateSprite(0x1F, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, &D_801E5478_AAA4B8, 0, NULL, 1);

    //D_801E55E4_AAA624 = 0;
    D_801E55E0_AAA620 = 0;
    D_801E55E8_AAA628 = 0;
    //D_801E55EC_AAA62C = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DCCDC_AA1D1C.s")
#endif

s32 func_801DD010_AA2050(s32 arg0) {
    D_801E55D8_AAA618 = arg0;
    D_801E553C_AAA57C = 0x2D4000;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801E552C_AAA56C);
    return D_801E54C8_AAA508;
}
