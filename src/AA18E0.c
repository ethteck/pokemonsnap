#include "common.h"
#include "sys/oh.h"

void func_8009FA68(UNK_PTR arg0, UNK_PTR arg1);
void func_801DC9D0_AA1A10(GObj*);
UNK_PTR func_800BF574_5C414(s32 arg0);

// data
extern Sprite D_801E5478_AAA4B8;
extern u8 D_801E54BC_AAA4FC;
extern u8 D_801E54C0_AAA500;
extern u8 D_801E54C4_AAA504;
extern s32 D_801E54C8_AAA508[211]; // All 0xBDEFBDEF
extern s32 D_801E550C_AAA54C;
extern ScreenSettings D_801E5510_AAA550;
extern SceneSetup D_801E552C_AAA56C;
extern s32 D_801E553C_AAA57C;
extern f32 D_801E55C0_AAA600;
extern UNK_PTR D_801E54CC_AAA50C;

// bss
s32 D_801E55D0_AAA610[2];
s32 D_801E55D8_AAA618;
GObj* D_801E55DC_AAA61C;
UNK_PTR D_801E55E0_AAA620[4];

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
    D_801E54C8_AAA508[0] = arg0;
    if (arg0 == 0) {
        func_8009FBC4();
    }
    func_800067DC();
}

void func_801DC930_AA1970(UNK_PTR arg0, UNK_PTR arg1) {
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

void func_801DC9BC_AA19FC(void *unused) {
    D_801E550C_AAA54C = 1;
}

void func_801DC9D0_AA1A10(GObj* arg0) {
    void* sp2C;
    s32 var_s0;
    s32 var_a0;
    s32 i;
    s32 *temp_v0;

    sp2C = arg0->data.any;
    if (D_801E54C8_AAA508[0] >= 0) {
        func_800067DC();
    }
    var_s0 = 0;
    for (var_a0 = 0; var_a0 < 4; var_a0++) {
        temp_v0 = func_800BF574_5C414(var_a0);
        if (temp_v0 != NULL) {
            var_s0++;
            D_801E55E0_AAA620[var_a0] = temp_v0;
        }

    }
    if (var_s0 < 4) {
        func_801DC8A0_AA18E0(2);
        ohWait(1);
    }
    if (D_801E55D8_AAA618 == 3) {
        D_801E55DC_AAA61C->flags &= ~1;
    } else {
        D_801E55DC_AAA61C->flags |= 1;
    }
    if (D_801E55D8_AAA618 >= 0 && D_801E55D8_AAA618 < 16) {
        func_8009FB50(D_801E54BC_AAA4FC, D_801E54C0_AAA500, D_801E54C4_AAA504);
        var_s0 = D_801E55E0_AAA620[D_801E54C8_AAA508[1 + D_801E55D8_AAA618]];
        D_801E550C_AAA54C = 0;
        scSetPostProcessFunc(func_801DC9BC_AA19FC);
        func_801DC930_AA1970(sp2C, var_s0);
        if (D_801E55D8_AAA618 == 0) {
            while (contPrinterGetStatus() == 8) {
                ohWait(1);
            }
            contPrinterSendCommand(1);
            while (contPrinterGetStatus() == 8) {
                ohWait(1);
            }
        }
        for (i = 0; i < 180; i++) {
            if (D_801E550C_AAA54C == 0) {
                ohWait(1);
            } else {
                break;
            }
        }
        scRemovePostProcessFunc();
        ohWait(1);
        contPrinterSendCommand(2);
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
        ohWait(1);
    }
    if (D_801E55D8_AAA618 < 16) {
        func_801DC8A0_AA18E0(0);
        ohWait(1);
    }
    contPrinterSendCommand(4);
    while (contPrinterGetStatus() == 8) {
        ohWait(1);
    }
    ohWait(1);
    while (TRUE) {
        if (gContInputPressedButtons & START_BUTTON) {
            contPrinterSendCommand(4);
            while (contPrinterGetStatus() == 8) {
                ohWait(1);
            }
        }
        ohWait(1);
    }
}

void func_801DCCD4_AA1D14(s32 unused) {
}

void func_801DCCDC_AA1D1C(void) {
    GObj* cam;
    OMCamera* omCamera;
    s32 i;

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
    omCamera->viewMtx.lookAt.at.y = 0.0f;
    omCamera->viewMtx.lookAt.eye.y = 0.0f;
    omCamera->viewMtx.lookAt.at.z = 0.0f;
    omCamera->viewMtx.lookAt.up.x = 0.0f;
    omCamera->viewMtx.lookAt.up.z = 0.0f;
    omCamera->viewMtx.lookAt.eye.z = 100.0f;
    omCamera->viewMtx.lookAt.up.y = 1.0f;

    cam = ohCreateCamera(3, ohUpdateDefault, 0, 0x80000000, renSpriteCameraRender, 3, 2, -1, 1, 1, NULL, 1, 1);
    cam->data.cam->flags = 8;
    cam->flags = 1;
    D_801E55DC_AAA61C = cam;
    ohCreateSprite(0x1F, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, &D_801E5478_AAA4B8, 0, NULL, 1);

    for (i = 0; i < ARRAY_COUNT(D_801E55E0_AAA620); i++) {
        D_801E55E0_AAA620[i] = 0;
    }
}

s32 func_801DD010_AA2050(s32 arg0) {
    D_801E55D8_AAA618 = arg0;
    D_801E553C_AAA57C = 0x2D4000;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801E552C_AAA56C);
    return D_801E54C8_AAA508[0];
}
