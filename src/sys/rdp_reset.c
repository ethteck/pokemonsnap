#include "sys/vi.h"
#include "sys/gtl.h"
#include "PR/mbi.h"


Vp sViewport;

void (*sPreRenderFunc)(Gfx**) = NULL;

Mtx sIdentityMatrix = {{
    /* Integer Portion */
    {0x00010000, 0x00000000, 0x00000001, 0x00000000},
    {0x00000000, 0x00010000, 0x00000000, 0x00000001},
    /* Fractional Portion */
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
    {0x00000000, 0x00000000, 0x00000000, 0x00000000},
}};

Gfx srdpReset[] = {
    gsDPPipeSync(),
    gsSPViewport(&sViewport),
    gsSPClearGeometryMode(
        G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN
        | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPClipRatio(FRUSTRATIO_1),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPMatrix(&sIdentityMatrix, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION),
    gsSPMatrix(&sIdentityMatrix, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
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

#ifdef NON_MATCHING
void func_80007C20(Vp *vp, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp1 = (arg1 + arg3) / 2.0f;
    f32 temp2 = (arg2 + arg4) / 2.0f;
    vp->vp.vscale[0] = (arg3 - temp1) * 4.0f;
    vp->vp.vscale[1] = (arg4 - temp2) * 4.0f;
    vp->vp.vtrans[0] = temp1 * 4.0f;
    vp->vp.vtrans[1] = temp2 * 4.0f;
    vp->vp.vscale[2] = vp->vp.vtrans[2] = G_MAXZ / 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/rdp_reset/func_80007C20.s")
#endif

void func_80007CBC(Vp *vp) {
    vp->vp.vscale[0] = vp->vp.vtrans[0] = viScreenWidth * 2;
    vp->vp.vscale[1] = vp->vp.vtrans[1] = viScreenHeight * 2;
    vp->vp.vscale[2] = vp->vp.vtrans[2] = G_MAXZ / 2;
}

void rdpSetPreRenderFunc(void (*func)(Gfx**)) {
    sPreRenderFunc = func;
}

#ifdef NON_MATCHING
void rdpReset(Gfx** pGfxPos) {
    Gfx* gfxPos = *pGfxPos;
    s32 x = 0;
    s32 y = 0;
    gSPSegment(gfxPos++, 0x00, 0x00000000);
    gtl_set_segment_F(&gfxPos);
    gDPSetDepthImage(gfxPos++, viZBuffer);
    func_80007CBC(&sViewport);
    gSPDisplayList(gfxPos++, srdpReset);
    gDPSetScissor(gfxPos++, G_SC_NON_INTERLACE, x, y, viScreenWidth, viScreenHeight);
    if (sPreRenderFunc != NULL) {
        sPreRenderFunc(&gfxPos);
    }
    *pGfxPos = gfxPos;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/rdp_reset/rdpReset.s")
void rdpReset(Gfx**);
#endif
