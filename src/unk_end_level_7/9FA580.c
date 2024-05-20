#include "ld_addrs.h"
#include "common.h"
#include "../unk_end_level/unk_end_level.h"
#include "unk_end_level_7.h"

void func_801DC8C0_9FA580(Gfx** dlist) {
    gSPDisplayList(++(*dlist), D_801E1620_9FF2E0);
}

s32 func_801DC904_9FA5C4(void) {
    return D_801EA7F0_A084B0;
}

void func_801DC920_9FA5E0(GObj** arg0, GObj** arg1) {
    *arg0 = D_801EA7F4_A084B4;
    *arg1 = D_801EA7FC_A084BC;
}

void func_801DC948_9FA608(s32 arg0, s32 arg1) {
    Gfx* gfx = gMainGfxPos[0];

    gSPDisplayList(gfx++, &D_801E1620_9FF2E0);
    gDPSetColorDither(gfx++, G_CD_MAGICSQ);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_MEM, G_BL_0),
                     AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | G_RM_NOOP2);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_PASS2);

    gMainGfxPos[0] = gfx;
}

void func_801DCA58_9FA718(GObj* arg0) {
    UnkStruct800BEDF8* sp1C;

    while (TRUE) {
        sp1C = func_800AA38C(0);
        ohWait(1);
    }
}

void func_801DCA98_9FA758(void) {
    GObj* obj;
    OMCamera* cam;
    UNUSED s32 pad[3];

    obj = ohCreateCamera(0x200, ohUpdateDefault, 5, 5, ren_func_800191D8, 0x14, 0x100000, 0x100000, 1, 0, func_801DCA58_9FA718, 0, 1);
    obj->unk_38 = 0x100000;
    cam = obj->data.cam;
    cam->flags |= (CAMERA_FLAG_4 | CAMERA_FLAG_2);
    cam->flags &= ~(CAMERA_FLAG_1 | CAMERA_FLAG_2);
    func_800A844C(cam, 0, 0, 0x140, 0xF0);
    cam->viewMtx.lookAt.up.x = 0.0f;
    cam->viewMtx.lookAt.up.y = 0.0f;
    cam->viewMtx.lookAt.up.z = 1.0f;
    cam->viewMtx.lookAt.at = D_800AF0C4;
    cam->viewMtx.lookAt.eye = D_800AF094;
    cam->perspMtx.persp.fovy = 33.0f;
    cam->perspMtx.persp.far = 8000.0f;
    cam->perspMtx.persp.near = (cam->perspMtx.persp.far / 128.0);
    cam->perspMtx.persp.scale = 1.0f;
    cam->bgColor = 0x10001;
    D_801EA7F4_A084B4 = obj;
    D_801EA7F8_A084B8 = cam;
}

void func_801DCC60_9FA920(void) {
    GObj* obj;
    OMCamera* cam;

    obj = ohCreateCamera(0x200, ohUpdateDefault, 5, 5, ren_func_800192DC, 0x13, 0x80000, -1, 0, 0, NULL, 0, 1);
    cam = obj->data.cam;
    cam->flags = CAMERA_FLAG_1 | CAMERA_FLAG_4;
    obj->flags |= 1;
    omCameraAddMtx(cam, 3, 0);
    omCameraAddMtx(cam, 0xE, 0);
    cam->perspMtx.persp.near = 10.0f;
    cam->perspMtx.persp.far = 25600.0f;
    cam->perspMtx.persp.fovy = 55.0f;
    cam->viewMtx.lookAt.at.x = 0.0f;
    cam->viewMtx.lookAt.eye.x = cam->viewMtx.lookAt.at.x;
    cam->viewMtx.lookAt.at.y = 0.0f;
    cam->viewMtx.lookAt.eye.y = cam->viewMtx.lookAt.at.y;
    cam->viewMtx.lookAt.eye.z = 100.0f;
    cam->viewMtx.lookAt.at.z = 0.0f;
    cam->viewMtx.lookAt.up.x = 0.0f;
    cam->viewMtx.lookAt.up.y = 1.0f;
    cam->viewMtx.lookAt.up.z = 0.0f;
    D_801EA7FC_A084BC = obj;
    D_801EA800_A084C0 = cam;
}

void func_801DCDDC_9FAA9C(void) {
    UNUSED s32 pad;

    D_801E1690_9FF350.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_801E1690_9FF350);
    func_8036A3F8_83DBA8(&D_801EA808_A084C8, 0x46000);
    func_800AAE28();
    func_801DCC60_9FA920();
    func_80374D40_8484F0();
    func_8036EB98_842348();
    if (D_801EA7F0_A084B0 != 0) {
        auPlaySong(0, 0x22);
        auSetBGMVolume(0, 0x7F00);
    }
    func_800A7F68(1, 0x101);
    func_801DF788_9FD448();
}

void func_801DCE90_9FAB50(void* arg0) {
    func_8036A228_83D9D8(arg0);
}

s32 func_801DCEBC_9FAB7C(s32 arg0) {
    if (arg0 == 0x16) {
        D_801EA7F0_A084B0 = 1;
    } else {
        D_801EA7F0_A084B0 = 0;
    }
    D_801E16AC_9FF36C.gtlSetup.heapSize = (uintptr_t) unk_end_level_VRAM - (uintptr_t) unk_end_level_7_VRAM_END;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801E16AC_9FF36C);
    return D_800AF3C0;
}
