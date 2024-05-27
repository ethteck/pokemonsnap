#include "common.h"
#include "ld_addrs.h"
#include "unk_end_level/unk_end_level.h"

extern u8 D_80208FE0_9D3230[];

void func_801E1858_9ABAA8(void);
void func_801DCC74_9A6EC4(void* arg0);
void func_801DCBF4_9A6E44(void);

Gfx D_801E41E0_9AE430[] = {
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsSPClipRatio(FRUSTRATIO_6),
    gsSPEndDisplayList(),
};

ScreenSettings D_801E4250_9AE4A0 = {
    D_803B5000,
    D_803DA800,
    NULL,
    NULL,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0x16A99,
};

SceneSetup D_801E426C_9AE4BC = {
    {
        0,
        omUpdateAll,
        omDrawAll,
        unk_end_level_5_VRAM_END,
        0,
        0x2,
        0x1,
        0xC000,
        0x2000,
        0,
        0,
        0x3000,
        0x2,
        0x2000,
        func_800A1A50,
        contUpdate,
    },
    0x20,
    0x2000,
    0x20,
    0,
    0x40,
    0,
    sizeof(GObj),
    0x400,
    0,
    func_801DCC74_9A6EC4,
    0,
    0x10,
    0,
    sizeof(DObj),
    0,
    0x60,
    0,
    sizeof(OMCamera),
    func_801DCBF4_9A6E44,
};

void func_801DC8C0_9A6B10(Gfx** arg0) {
    gSPDisplayList(++(*arg0), &D_801E41E0_9AE430);
}

void func_801DC904_9A6B54(s32 arg0, s32 arg1) {
    Gfx* gfx = gMainGfxPos[0];

    gSPDisplayList(gfx++, D_801E41E0_9AE430);
    gDPSetColorDither(gfx++, G_CD_MAGICSQ);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(
        gfx++,
        AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_MEM, G_BL_0),
        AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | G_RM_NOOP2);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_PASS2);

    gMainGfxPos[0] = gfx;
}

void func_801DCA14_9A6C64(GObj* obj) {
    UNUSED s32 pad[2];

    while (TRUE) {
        ohWait(1);
    }
}

void func_801DCA48_9A6C98(void) {
    GObj* sp54;
    struct OMCamera* cam;
    UNUSED s32 pad[4];

    sp54 = ohCreateCamera(0x200, ohUpdateDefault, 5, 5, ren_func_800191D8, 0x14, 0x100000, 0x100000, 1, 0, func_801DCA14_9A6C64, 0, 1);
    sp54->unk_38 = 0x100000;

    cam = sp54->data.cam;
    cam->flags |= 6;
    cam->flags &= ~3;
    func_800A844C(cam, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    cam->viewMtx.lookAt.up.x = 0.0f;
    cam->viewMtx.lookAt.up.y = 0.0f;
    cam->viewMtx.lookAt.up.z = 1.0f;
    cam->viewMtx.lookAt.at = D_800AF0C4;
    cam->viewMtx.lookAt.eye = D_800AF094;
    cam->perspMtx.persp.fovy = 33.0f;
    cam->perspMtx.persp.far = 8000.0f;
    cam->perspMtx.persp.near = (cam->perspMtx.persp.far / 128.0);
    cam->perspMtx.persp.scale = 1.0f;
    cam->bgColor = 1;
}

void func_801DCBF4_9A6E44(void) {
    UNUSED s32 pad[2];

    func_8036A3F8_83DBA8(D_80208FE0_9D3230, 0x46000);
    func_800AAE28();
    func_801DCA48_9A6C98();
    func_80374D40_8484F0();
    func_800A7F68(1, 0x101);
    func_8036EB98_842348();
    auPlaySong(0, 0xA);
    auSetBGMVolume(0, 0x7F00);
    func_801E1858_9ABAA8();
}

void func_801DCC74_9A6EC4(void* arg0) {
    func_8036A228_83D9D8(arg0);
}

s32 func_801DCCA0_9A6EF0(s32 sceneId) {
    UNUSED s32 pad[3];

    viApplyScreenSettings(&D_801E4250_9AE4A0);
    D_801E426C_9AE4BC.gtlSetup.heapSize = (uintptr_t) unk_end_level_VRAM - (uintptr_t) unk_end_level_5_VRAM_END;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801E426C_9AE4BC);
    func_800AAED0(0x100000);

    return D_800AF3C0;
}
