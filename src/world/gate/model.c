#include <common.h>

extern u8 gate_tex0_pal[];
extern u8 gate_tex1_pal[];
extern u8 gate_tex2_pal[];
extern u8 gate_tex0_png[];
extern u8 gate_tex1_png[];
extern u8 gate_tex2_png[];

extern Gfx gate_part0[];

#include "assets/world/gate/model.vtx.inc.c"
#include "assets/world/gate/first.gfx.inc.c"
#include "assets/world/gate/part0.gfx.inc.c"
Gfx gate_part_a[] = {
    gsSPVertex(0x800F1A30, 8, 0),
    gsSPCullDisplayList(0, 7),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPClearGeometryMode(G_FOG),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetCombineMode(G_CC_PRIMITIVE, G_CC_PRIMITIVE),
    gsSPDisplayList(0x0E000000),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPVertex(0x800F1680, 15, 0),
    gsSP2Triangles(14, 13, 12, 0, 12, 13, 11, 0),
    gsSP2Triangles(10, 14, 12, 0, 9, 12, 11, 0),
    gsSP2Triangles(10, 12, 8, 0, 8, 12, 9, 0),
    gsSP2Triangles(9, 7, 8, 0, 9, 11, 6, 0),
    gsSP2Triangles(5, 10, 7, 0, 9, 4, 7, 0),
    gsSP2Triangles(4, 9, 6, 0, 5, 7, 3, 0),
    gsSP2Triangles(3, 7, 4, 0, 3, 2, 5, 0),
    gsSP2Triangles(1, 5, 2, 0, 0, 1, 2, 0),
    gsSP2Triangles(4, 2, 3, 0, 0, 2, 6, 0),
    gsSP2Triangles(8, 7, 10, 0, 2, 4, 6, 0),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_FOG),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, 0x800F0C88),
    gsDPLoadSync(),
    gsDPLoadTLUTCmd(5, 7),
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 1, G_TX_RENDERTILE, G_ON),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, 0x800F0A80),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 255, 1024),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD),
    gsSPVertex(0x800F1770, 16, 0),
    gsSP2Triangles(15, 14, 13, 0, 12, 15, 13, 0),
    gsSP2Triangles(11, 14, 10, 0, 9, 11, 10, 0),
    gsSP2Triangles(8, 10, 7, 0, 6, 8, 7, 0),
    gsSP2Triangles(5, 4, 7, 0, 4, 3, 7, 0),
    gsSP2Triangles(5, 2, 1, 0, 2, 0, 1, 0),
    gsDPPipeSync(),
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPEndDisplayList(),
};

Gfx gate_part_b[] = {
    gsDPPipeSync(),
    gsSPDisplayList(0x800F1E78),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPEndDisplayList(),
};

Gfx gate_part_c[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2),
    gsSPLightColor(LIGHT_2, 0x26262600),
    gsSPClearGeometryMode(G_FOG | G_LIGHTING),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0),
    gsDPSetPrimColor(0, 0, 0xFF, 0xFF, 0xFF, 0xFF),
    gsSPDisplayList(0x800F20F8),
    gsSPEndDisplayList(),
};

Gfx gate_part_d[] = {
    gsSPVertex(0x800F1AB0, 8, 0),
    gsSPCullDisplayList(0, 7),
    gsDPPipeSync(),
    gsSPLightColor(LIGHT_1, 0xB3B3B300),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 7, G_TX_NOLOD),
    gsSPDisplayList(0x0E000000),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 1023, 128),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 16, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 4, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 7, G_TX_NOLOD),
    gsSPVertex(0x800F1870, 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 0, 3, 1, 0),
    gsSPEndDisplayList(),
};

Gfx gate_part_e[] = {
    gsSPVertex(0x800F1B30, 8, 0),
    gsSPCullDisplayList(0, 7),
    gsDPPipeSync(),
    gsSPLightColor(LIGHT_1, 0xFFFFFF00),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 6, G_TX_NOLOD),
    gsSPDisplayList(0x0E000000),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 2047, 256),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 6, G_TX_NOLOD, G_TX_MIRROR | G_TX_CLAMP, 6, G_TX_NOLOD),
    gsSPVertex(0x800F18B0, 16, 0),
    gsSP2Triangles(15, 14, 13, 0, 14, 12, 13, 0),
    gsSP2Triangles(11, 14, 15, 0, 10, 11, 15, 0),
    gsSP2Triangles(11, 10, 9, 0, 8, 11, 9, 0),
    gsSP2Triangles(7, 6, 5, 0, 4, 7, 5, 0),
    gsSP2Triangles(3, 2, 1, 0, 0, 3, 1, 0),
    gsSPEndDisplayList(),
};

Gfx gate_part_f[] = {
    gsDPPipeSync(),
    gsSPDisplayList(0x800F2168),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_FOG | G_LIGHTING),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsDPPipeSync(),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsSPEndDisplayList(),
};

// #include "assets/world/gate/part1.gfx.inc.c"
// #include "assets/world/gate/part3.gfx.inc.c"
// #include "assets/world/gate/last.gfx.inc.c"
// #include "assets/world/gate/part2.gfx.inc.c"

extern Gfx gate_part1[];
extern Gfx gate_part2[];
extern Gfx gate_last[];
extern Gfx gate_part3[];

DObjPayloadTypeC gate_gfxdata[] = {
    { 0, gate_first },
    { 4, NULL },
    { 0, gate_part1 },
    { 4, NULL },
    { 1, gate_part2 },
    { 4, NULL },
    { 0, gate_last },
    { 4, NULL },
};

UnkEC64Arg3 gate_model[] = {
    { 0,
      &gate_gfxdata[0],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &gate_gfxdata[2],
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 1,
      &gate_gfxdata[4],
      { 0.0, 449.2, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 0.02239 } },
    { 1,
      &gate_gfxdata[6],
      { 0.0, 528.6123, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 1.0, 1.0, 1.0 } },
    { 18,
      NULL,
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 },
      { 0.0, 0.0, 0.0 } },
};
