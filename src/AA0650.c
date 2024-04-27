#include "common.h"
#include "sys.h"

// bss
GObj* D_800E1DD0_AA0B80;
s32 D_800E1DD4_AA0B84;

// external data
extern Sprite D_802BC0C0;
extern Addr D_800E1DE0;

// internal data
ScreenSettings D_800E1CB0_AA0A60 = {
    /* .fb1 = */ D_803B5000,
    /* .fb2 = */ D_803DA800,
    /* .fb3 = */ NULL,
    /* .zBuffer = */ NULL,
    /* .screenWidth = */ SCREEN_WIDTH,
    /* .screenHeight = */ SCREEN_HEIGHT,
    /* .flags = */ 0x00016A99,
};

Lights1 D_800E1CD0_AA0A80 = gdSPDefLights1(0x61, 0x61, 0x61, 0xCF, 0xCF, 0xCF, 0x1A, 0x4D, 0x7F);

Gfx D_800E1CE8_AA0A98[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPFogFactor(256, -512),
    gsDPSetFogColor(0x00, 0x00, 0x00, 0xFF),
    gsSPSetGeometryMode(G_FOG),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPSetLights1(D_800E1CD0_AA0A80),
    gsSPEndDisplayList(),
};

void func_800E1B30_AA08E0(Gfx**);
void func_800E1B54_AA0904(void);

SceneSetup D_800E1D40_AA0AF0 = {
     {
         0,
         omUpdateAll,
         omDrawAll,
         D_800E1DE0,
         0,
         1,
         2,
         0x5000,
         0x2000,
         0,
         0,
         0xC800,
         0,
         0,
         func_800E1B30_AA08E0,
         contUpdate,
    },
    0x20,
    0x400,
    0x80,
    0,
    0x40,
    0x40,
    0x5C,
    0x400,
    0,
    0,
    0x10,
    0x8,
    0x10,
    0x88,
    0x80,
    0x58,
    0x8,
    0x90,
    func_800E1B54_AA0904,
};

GObj* func_800E18A0_AA0650(void) {
    SObj* temp_v1;
    GObj* temp_v0;

    temp_v0 =
        ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, &D_802BC0C0, 0, NULL, 1);
    temp_v1 = temp_v0->data.sobj;
    temp_v1->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    temp_v1->sprite.x = SCREEN_WIDTH / 2 - (temp_v1->sprite.width / 2);
    temp_v1->sprite.y = SCREEN_HEIGHT / 2 - (temp_v1->sprite.height / 2);
    return temp_v0;
}

void func_800E1958_AA0708(SObj* sobj, u16 arg1) {
    u8 temp_lo;
    u16 temp_arg1;
    u8 temp;

    if (arg1) {
        temp_arg1 = arg1;
        for (arg1 = arg1 - 1; arg1 > 0; arg1--) {
            temp_lo = (arg1 * (temp = 0xFF)) / temp_arg1;
            sobj->sprite.blue = temp_lo;
            sobj->sprite.green = temp_lo;
            sobj->sprite.red = temp_lo;
            ohWait(1);
        }
        sobj->sprite.blue = 0;
        sobj->sprite.green = 0;
        sobj->sprite.red = 0;
        ohWait(1);
    }
}

void func_800E1A34_AA07E4(s32 unused) {
    while (TRUE) {
        D_800E1DD4_AA0B84++;
        ohWait(1);
    }
}

void func_800E1A94_AA0844(s32 unused) {
    func_800ABB94();
    D_800E1DD0_AA0B80 = func_800E18A0_AA0650();
    ohWait(1);
    func_800C05D4_5D474();
    ohWait(1);
    if (D_800E1DD4_AA0B84 < 60) {
        ohWait(60 - D_800E1DD4_AA0B84);
    }
    func_800E1958_AA0708(D_800E1DD0_AA0B80->data.sobj, 20);
    func_800067DC();
    while (TRUE) {
        ohWait(1);
    }
}

void func_800E1B30_AA08E0(Gfx** dlist) {
    gSPDisplayList((*dlist)++, &D_800E1CE8_AA0A98);
}

void func_800E1B54_AA0904(void) {
    GObj* objE_Clone;
    GObj* objE;
    GObj* camera;

    D_800E1CB0_AA0A60.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_800E1CB0_AA0A60);
    ohCreateCameraWrapper(0, 0x80000000, 0x64, 3, 0);
    camera = ohCreateCamera(3, ohUpdateDefault, 0, 0x80000000, renSpriteCameraRender, 3, 2, -1, 1, 1, NULL, 1, 1);
    camera->data.cam->flags = 8;
    objE = omAddGObj(0xE, NULL, 0, 0x80000000);
    objE_Clone = objE;
    omCreateProcess(objE, (void*) func_800E1A94_AA0844, 0, 1);
    omCreateProcess(objE_Clone, (void*) func_800E1A34_AA07E4, 0, 1);
    D_800E1DD4_AA0B84 = 0;
}

void func_800E1C5C_AA0A0C(void) {
    D_800E1D40_AA0AF0.gtlSetup.heapSize = VPK_VRAM - (uintptr_t) D_800E1DE0;
    gtlDisableNearClipping(1);
    omSetupScene(&D_800E1D40_AA0AF0);
}
