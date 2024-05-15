#include "common.h"

u8 sBackroundR = 90;
u8 sBackgroundG = 140;
u8 sBackgroundB = 200;
u8 sFogR = 60;
u8 sFogG = 110;
u8 sFogB = 180;
u16 sFogMin = 968;
u16 sFogMax = 990;
u8 sUnkColorR = 0;
u8 sUnkColorG = 0;
u8 sUnkColorB = 0;

Gfx DListRMFogOpaSet[] = {
    gsDPPipeSync(),
    gsSPFogPosition(968, 990),
    gsDPSetFogColor(60, 110, 180, 0),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPSetGeometryMode(G_FOG),
    gsSPEndDisplayList(),
};

Gfx DListRMFogOpaClear[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPClearGeometryMode(G_FOG),
    gsSPEndDisplayList(),
};

Gfx DListRMFogXluSet[] = {
    gsDPPipeSync(),
    gsSPFogPosition(968, 990),
    gsDPSetFogColor(60, 110, 180, 0),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsSPSetGeometryMode(G_FOG),
    gsSPEndDisplayList(),
};

Gfx DListRMFogXluClear[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsSPClearGeometryMode(G_FOG),
    gsSPEndDisplayList(),
};

Gfx DListRMNoFogOpaSet[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_OPA_SURF2),
    gsSPEndDisplayList(),
};

Gfx DListRMNoFogXluSet[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPEndDisplayList(),
};

Gfx DListRMNoFogOpaClear[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_NOOP2),
    gsSPEndDisplayList(),
};

Gfx DListRMNoFogXluClear[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_NOOP2),
    gsSPEndDisplayList(),
};

s32 D_800AEBC0 = 0;

void enableFog(GObj* arg0) {
    gSPDisplayList(gMainGfxPos[0]++, DListRMFogOpaSet);
}

void disableFog(GObj* arg0) {
    gSPDisplayList(gMainGfxPos[0]++, DListRMFogOpaClear);
}

void func_800A1460(GObj* arg0) {
    gSPDisplayList(gMainGfxPos[0]++, DListRMNoFogOpaSet);
}

void func_800A1490(GObj* arg0) {
    gSPDisplayList(gMainGfxPos[0]++, DListRMNoFogOpaClear);
}

void enableFogTrasparent(GObj* arg0) {
    gSPDisplayList(gMainGfxPos[1]++, DListRMFogXluSet);
}

void disableFogTransparent(GObj* arg0) {
    gSPDisplayList(gMainGfxPos[1]++, DListRMFogXluClear);
}

void func_800A1520(void) {

}

void func_800A1528(void) {

}

void renderModelTypeAFogged(GObj* arg0) {
    enableFog(arg0);
    renRenderModelTypeA(arg0);
    disableFog(arg0);
}

void renderModelTypeAFoggedTransparent(GObj* arg0) {
    enableFogTrasparent(arg0);
    renRenderModelTypeA(arg0);
    disableFogTransparent(arg0);
}

void renderModelTypeCFogged(GObj* arg0) {
    enableFog(arg0);
    enableFogTrasparent(arg0);
    renRenderModelTypeC(arg0);
    disableFog(arg0);
    disableFogTransparent(arg0);
}

void renderModelTypeBFogged(GObj* arg0) {
    enableFog(arg0);
    renRenderModelTypeB(arg0);
    disableFog(arg0);
}

void renderModelTypeDFogged(GObj* arg0) {
    enableFog(arg0);
    enableFogTrasparent(arg0);
    renRenderModelTypeD(arg0);
    disableFog(arg0);
    disableFogTransparent(arg0);
}

void renderModelTypeIFogged(GObj* arg0) {
    enableFog(arg0);
    renRenderModelTypeI(arg0);
    disableFog(arg0);
}

void func_800A1680(GObj* arg0) {
    func_800A1460(arg0);
    renRenderModelTypeI(arg0);
    func_800A1490(arg0);
}

void renderModelTypeJFogged(GObj* arg0) {
    enableFog(arg0);
    enableFogTrasparent(arg0);
    renRenderModelTypeJ(arg0);
    disableFog(arg0);
    disableFogTransparent(arg0);
}

void func_800A16F8(GObj* arg0) {
    gDPSetTextureLUT(gMainGfxPos[1]++, G_TT_NONE);
    gDPSetCycleType(gMainGfxPos[1]++, G_CYC_2CYCLE);
    renderModelTypeDFogged(arg0);
}

void getBackgroundColor(u8* arg0, u8* arg1, u8* arg2) {
    *arg0 = sBackroundR;
    *arg1 = sBackgroundG;
    *arg2 = sBackgroundB;
}

void setBackgroundColor(u8 arg0, u8 arg1, u8 arg2) {
    sBackroundR = arg0;
    sBackgroundG = arg1;
    sBackgroundB = arg2;
}

void setCameraBackgroundColor(OMCamera* camera) {
    u32 packed = ((sBackroundR << 8) & 0xF800) | ((sBackgroundG << 3) & 0x07C0) | ((sBackgroundB >> 2) & 0x003E) | 1;
    camera->bgColor = (packed << 16) | packed;
}

void getFogColor(u8* arg0, u8* arg1, u8* arg2) {
    *arg0 = sFogR;
    *arg1 = sFogG;
    *arg2 = sFogB;
}

void setFogColor(u8 arg0, u8 arg1, u8 arg2) {
    sFogR = arg0;
    sFogG = arg1;
    sFogB = arg2;

    gDPSetFogColor(&DListRMFogOpaSet[2], sFogR, sFogG, sFogB, 0);
    gDPSetFogColor(&DListRMFogXluSet[2], sFogR, sFogG, sFogB, 0);
}

void getFogDistance(u16* arg0, u16* arg1) {
    *arg0 = sFogMin;
    *arg1 = sFogMax;
}

void setFogDistance(u16 arg0, u16 arg1) {
    sFogMin = arg0;
    sFogMax = arg1;

    gSPFogPosition(&DListRMFogOpaSet[1], sFogMin, sFogMax);
    gSPFogPosition(&DListRMFogXluSet[1], sFogMin, sFogMax);
}

void func_800A1988(u8* arg0, u8* arg1, u8* arg2) {
    *arg0 = sUnkColorR;
    *arg1 = sUnkColorG;
    *arg2 = sUnkColorB;
}

void func_800A19B0(u8 arg0, u8 arg1, u8 arg2) {
    sUnkColorR = arg0;
    sUnkColorG = arg1;
    sUnkColorB = arg2;
}


void func_800A19D8(s32 arg0) {
    D_800AEBC0 = arg0;
    if (arg0 == 2) {
        sUnkColorR = sUnkColorG = sUnkColorB = 255;
    } else {
        sUnkColorR = sUnkColorG = sUnkColorB = 0;
    }
}

s32 func_800A1A38(void) {
    return D_800AEBC0;
}
