#include "common.h"
#include "sys/gtl.h"
#include "app_render/app_render.h"

extern s32 D_803A6660_879E10;
extern s32 D_803A6664_879E14;
extern f32 D_803A6668_879E18;
extern GObj* D_803A666C_879E1C;
extern bool D_803A6670_879E20;
extern s32 D_803A6674_879E24;
extern s32 D_803A6678_879E28;
extern PhotoData* D_803A667C_879E2C;
extern u16* D_803A6684_879E34;
extern u16* D_803A6C10_87A3C0;
extern u16* D_803A6C14_87A3C4;

void func_803743B0_847B60(f32 arg0) {
    D_803A6668_879E18 = arg0;
}

void func_803743BC_847B6C(GObj* camGobj) {
    GObj* gobj;
    OMCamera* cam;

    if (D_803A6670_879E20) {
        D_803A6670_879E20 = false;
        gtlWaitAllGfxTasksDone();
        func_8009FA68(D_803A666C_879E1C->data.cam, D_803A667C_879E2C);

        gobj = omGObjListHead[LINK_18];
        while (gobj != NULL) {
            ohPauseObjectProcesses(gobj);
            gobj = gobj->next;
        }

        gobj = omGObjListHead[LINK_17];
        while (gobj != NULL) {
            ohPauseObjectProcesses(gobj);
            gobj = gobj->next;
        }

        omCurrentCamera = camGobj;
        cam = camGobj->data.cam;
        cam->flags |= CAMERA_FLAG_10;
        cam->perspMtx.ortho.r /= D_803A6668_879E18;
        func_800A844C(cam, 0, 0, D_803A6674_879E24, D_803A6678_879E28);
        renInitCameraEx(gMainGfxPos, cam, 0, D_803A6C10_87A3C0, D_803A6660_879E10, D_803A6664_879E14, D_803A6C14_87A3C4);
        renPrepareCameraMatrix(gMainGfxPos, cam);
        renCameraPreRender(cam, 0);
        renCameraRenderObjects(camGobj, 0);
        renCameraPostRender(cam);
        cam->flags &= ~CAMERA_FLAG_10;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/847B60/func_8037452C_847CDC.s")

u16** func_80374608_847DB8(s32 arg0, s32 arg1, PhotoData* arg2) {
    D_803A6684_879E34 = D_803A6C10_87A3C0;

    if (arg0 < 16) {
        arg0 = 16;
    }
    if (arg0 > 320) {
        arg0 = 320;
    }
    if (arg1 < 16) {
        arg1 = 16;
    }
    if (arg1 > 210) {
        arg1 = 210;
    }
    if (arg2 == 0) {
        return NULL;
    }
    D_803A6674_879E24 = arg0;
    D_803A6678_879E28 = arg1;
    D_803A667C_879E2C = arg2;
    D_803A6670_879E20 = true;
    func_80006F8C(D_803A666C_879E1C);
    return &D_803A6684_879E34;
}

static void nullsub() {
}

PhotoData* func_803746B4_847E64(s32 arg0) {
    if (arg0 < 0 || arg0 >= func_8009BC68()) {
        return NULL;
    }
    return &func_8009BC74()[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/847B60/func_80374714_847EC4.s")

void func_80374D20_8484D0(void) {
    func_8009FBC4();
}

void func_80374D40_8484F0(void) {
    GObj* camera;
    UNUSED s32 pad;
    u8 r, g, b;
    UNUSED s32 pad2;
    OMCamera* cam;

    D_803A6C10_87A3C0 = gtlMalloc(0x20D00, 0x80);
    D_803A6C14_87A3C4 = gtlMalloc(0x20D00, 0x80);
    camera = ohCreateCamera(0x200, ohUpdateDefault, 5, 5, func_803743BC_847B6C, 0x13, 0x80000, -1, 0, 0, NULL, 0, 1);
    cam = camera->data.cam;
    omCameraAddMtx(cam, MTX_TYPE_PERSP_FAST, 0);
    omCameraAddMtx(cam, MTX_TYPE_LOOKAT_REFLECT, 0);
    cam->flags |= CAMERA_FLAG_10 | CAMERA_FLAG_4 | CAMERA_FLAG_2 | CAMERA_FLAG_1;
    func_800A844C(cam, 0, 0, 0x140, 0xD2);
    cam->viewMtx.lookAt.up.x = 0.0f;
    cam->viewMtx.lookAt.up.y = 0.0f;
    cam->viewMtx.lookAt.up.z = 1.0f;
    cam->viewMtx.lookAt.at = D_800AF0C4;
    cam->viewMtx.lookAt.eye = D_800AF094;
    func_8009FB50(0x13, 0x12, 0x11);
    D_803A666C_879E1C = camera;
    D_803A6670_879E20 = false;
    cam->perspMtx.persp.far = 8000.0f;
    cam->perspMtx.persp.fovy = 33.0f;
    cam->perspMtx.persp.near = 8000.0f;
    cam->perspMtx.persp.near *= 0.0078125;
    cam->perspMtx.persp.scale = 1.0f;
    getBackgroundColor(&r, &g, &b);
    cam->bgColor = (r << 0x18) | (g << 0x10) | (b << 8) | 1;
    D_803A666C_879E1C = camera;
}
