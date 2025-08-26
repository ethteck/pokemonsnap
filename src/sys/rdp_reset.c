#include "sys/vi.h"
#include "sys/gtl.h"
#include "PR/mbi.h"
#include "macros.h"

Vp sViewport;

void (*sPreRenderFunc)(Gfx**) = NULL;

Mtx gIdentityMatrix = { {
    /* Integer Portion */
    { 0x00010000, 0x00000000, 0x00000001, 0x00000000 },
    { 0x00000000, 0x00010000, 0x00000000, 0x00000001 },
    /* Fractional Portion */
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
    { 0x00000000, 0x00000000, 0x00000000, 0x00000000 },
} };

Gfx srdpReset[] = {
    gsDPPipeSync(),
    gsSPViewport(&sViewport),
    gsSPClearGeometryMode(
        G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPClipRatio(FRUSTRATIO_1),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPMatrix(&gIdentityMatrix, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION),
    gsSPMatrix(&gIdentityMatrix, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

void syRdpSetViewport(Vp* vp, f32 ulx, f32 uly, f32 lrx, f32 lry) {
    f32 h = (ulx + lrx) / 2.0F;
    f32 v = (uly + lry) / 2.0F;

    vp->vp.vscale[0] = (s32) ((lrx - h) * 4.0F) & 0xFFFF;
    vp->vp.vscale[1] = (s32) ((lry - v) * 4.0F) & 0xFFFF;
    vp->vp.vtrans[0] = (s32) (h * 4.0F) & 0xFFFF;
    vp->vp.vtrans[1] = (s32) (v * 4.0F) & 0xFFFF;

    vp->vp.vscale[2] = vp->vp.vtrans[2] = G_MAXZ / 2;
}

void func_80007CBC(Vp* vp) {
    vp->vp.vscale[0] = vp->vp.vtrans[0] = viScreenWidth * 2;
    vp->vp.vscale[1] = vp->vp.vtrans[1] = viScreenHeight * 2;
    vp->vp.vscale[2] = vp->vp.vtrans[2] = G_MAXZ / 2;
}

void rdpSetPreRenderFunc(void (*func)(Gfx**)) {
    sPreRenderFunc = func;
}

void rdpReset(Gfx** pGfxPos) {
    Gfx* gfxPos = *pGfxPos;

    gSPSegment(gfxPos++, 0x00, 0x00000000);
    gtlSetSegmentF(&gfxPos);
    gDPSetDepthImage(gfxPos++, viZBuffer);
    func_80007CBC(&sViewport);
    gSPDisplayList(gfxPos++, srdpReset);
    gDPSetScissor(gfxPos++, G_SC_NON_INTERLACE,
                  0 * (viScreenWidth / SCREEN_WIDTH), 0 * (viScreenHeight / SCREEN_HEIGHT),
                  viScreenWidth - 0 * (viScreenWidth / SCREEN_WIDTH),
                  viScreenHeight - 0 * (viScreenHeight / SCREEN_HEIGHT));
    if (sPreRenderFunc != NULL) {
        sPreRenderFunc(&gfxPos);
    }
    *pGfxPos = gfxPos;
}
