#include "common.h"

extern ScreenSettings D_800E6740_8ABF60;
extern SceneSetup D_800E675C_8ABF7C;
extern u8 D_80206B90[];
extern u8 D_801C6B10_98C330;

void func_80375284(int);
void func_800E3190_8A89B0(void);

void func_800E18C0_8A70E0(void) {
}

void func_800E18C8_8A70E8(void) {
}

void func_800E18D0_8A70F0(GObj* arg0) {
    while (1) {
        ohWait(1);
    }
}

void func_800E1910_8A7130(void) {
    GObj* camObj;
    OMCamera* camera;

    camObj = ohCreateCamera(0x200, ohUpdateDefault, 5, 5, ren_func_800191D8, 0x14, 0x100000, 0x100000, 1, 0U,
                            func_800E18D0_8A70F0, 0, 1);
    camera = camObj->data.cam;
    camObj->unk38 = 0x100000;
    camera->flags |= 6;
    camera->flags &= ~3;
    func_800A844C(camera, 0, 0, 0x280, 0x1E0);
    camera->viewMtx.lookAt.up.x = 0.0f;
    camera->viewMtx.lookAt.up.y = 0.0f;
    camera->viewMtx.lookAt.up.z = 1.0f;
    camera->viewMtx.lookAt.at = D_800AF0C4;
    camera->viewMtx.lookAt.eye = D_800AF094;
    camera->bgColor = 0x7101;
    camera->perspMtx.persp.scale = 1.0f;
    camera->perspMtx.persp.far = 8000.0f;
    camera->perspMtx.persp.fovy = 33.0f;
    camera->perspMtx.persp.near = camera->perspMtx.persp.far / 128.0;
}

void func_800E1A60_8A7280(void) {
    func_8036A3F8(&D_801C6B10_98C330, 0x40000);
    func_800AAE28();
    func_800E1910_8A7130();
    func_8036EB98();
    func_800A7F68(1, 0x101);
    func_80375284(3);
    func_80375284(0);
    auSetBGMVolume(0, 0x7F00U);
    func_800E3190_8A89B0();
}

void func_800E1AD0_8A72F0(void) {
}

s32 func_800E1AD8_8A72F8(s32 arg0) {
    gtlDisableNearClipping(1);
    gtlSetIntervals(1U, 2U);
    viApplyScreenSettings(&D_800E6740_8ABF60);
    D_800E675C_8ABF7C.gtlSetup.heapSize = D_80369F80 - D_80206B90;
    omSetupScene(&D_800E675C_8ABF7C);
    return D_800AF3C0;
}
