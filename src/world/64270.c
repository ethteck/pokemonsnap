#include "world.h"

void func_800E6AC0_64270(void) {
}
/*
extern u16 D_800E6C78[];
extern Texture* D_800E8F58_66708[];
extern Texture D_800E8EE0_66690;
*/

// ROM: 0x66668 - 0x66670
// VRAM: 0x800E8EB8 - 0x800E8EC0
/*Texture** D_800E8EB8[2] = {
    NULL,
    D_800E8F58_66708
};
*/

// ROM: 0x66670 - 0x66690
// VRAM: 0x800E8EC0 - 0x800E8EE0
/*
u8* D_800E8EC0_66670[] = {
    D_800E8AB8_66268,
    D_800E86B0_65E60,
    D_800E82A8_65A58,
    D_800E7EA0_65650,
    D_800E7A98_65248,
    D_800E7690_64E40,
    D_800E7288_64A38,
    D_800E6E80_64630
};
*/
// ROM: 0x66690 - 0x66708
// VRAM: 0x800E8EE0 - 0x800E8F58
/*
Texture D_800E8EE0_66690 = {
    0,
    2,
    2,
    D_800E8EC0_66670,
    32,
    0,
    32, 32,
    FALSE,
    0.0f,
    0.0f,
    1.0f, 1.0f,
    0.0f,
    1.0f,
    NULL,
    1,
    2,
    1,
    32, 32,
    32, 32,
    0.0f,
    0.0f,
    0.0f,
    { 0, 0, 0, 0 },
    0x12205,
    255, 255, 255, 255,
    0,
    0,
    0,
    0,
    0, 0, 0, 255,
    0, 0, 0, 0,
    0xFFFFFF00,
    0x26262600,
    0,
    0,
    0,
    0
};
*/

// ROM: 0x66708 - 0x66710
// VRAM: 0x800E8F58 - 0x800E8F60
/*
Texture* D_800E8F58_66708[2] = {
    &D_800E8EE0_66690,
    NULL
};
*/

// ROM: 0x66710 - 0x66750
// VRAM: 0x800E8F60 - 0x800E8FA0
/*
Vtx D_800E8F60[4] = {
    {{{  200, -200, 0 }, 0, { 0x400,     0 }, { 255, 255, 255, 0 }}},
    {{{ -200, -200, 0 }, 0, {     0,     0 }, { 255, 255, 255, 0 }}},
    {{{ -200,  200, 0 }, 0, {     0, 0x400 }, { 255, 255, 255, 0 }}},
    {{{  200,  200, 0 }, 0, { 0x400, 0x400 }, { 255, 255, 255, 0 }}},
};
*/

// ROM: 0x66750 - 0x667D0
// VRAM: 0x800E8FA0 - 0x800E9020
/*
Vtx D_800E8FA0[8] = {
    {{{ -200, -200, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 }}},
    {{{ -200, -200, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 }}},
    {{{ -200,  200, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 }}},
    {{{ -200,  200, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 }}},
    {{{  200, -200, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 }}},
    {{{  200, -200, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 }}},
    {{{  200,  200, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 }}},
    {{{  200,  200, 0 }, 0, { 0, 0 }, { 0, 0, 0, 255 }}},
};
*/

// ROM: 0x667D0 - 0x668E8
// VRAM: 0x800E9020 - 0x800E9138
/*
Gfx D_800E9020_667D0[] =
{
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPVertex(D_800E8FA0, 8, 0),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPCullDisplayList(0, 7),
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineMode(G_CC_MODULATEIDECALA, G_CC_PASS2),
    gsDPSetBlendColor(0, 0, 0, 0),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0100, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, 5, G_TX_NOLOD),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_800E6C78),
    gsDPLoadSync(),
    gsDPLoadTLUTCmd(5, 255),
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0x007C, 0x007C),
    gsSPDisplayList(0x0E000000),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 511, 512),
    gsDPPipeSync(),
    gsSPVertex(D_800E8F60, 4, 0),
    gsSP2Triangles(3, 2, 1, 0, 0, 3, 1, 0),
    gsDPPipeSync(),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_LIGHTING),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsSPEndDisplayList(),
};
*/

// ROM: 0x668E8 - 0x6696C
// VRAM: 0x800E9138 - 0x800E91BC
/*
UnkEC64Arg3 D_800E9138[3] = {
    {
        0,
        NULL,
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 1.0f, 1.0f, 1.0f }
    },
    {
        0x8001,
        D_800E9020_667D0,
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 1.0f, 1.0f, 1.0f }
    },
    {
        0x12,
        NULL,
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f },
        { 0.0f, 0.0f, 0.0f }
    }
};
*/
