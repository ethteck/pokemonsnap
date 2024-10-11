#include "common.h"
#include "app_render.h"
#include "photo_check/photo_check.h"

s16 score_SpecialBonuses[] = {
    0,
    1000,
    600,
    1600,
    800,
    1300,
    2000,
    500,
    500,
    500,
    2500,
    800,
    1200,
    0
};
s16 score_PoseBonuses[] = {
    0, 1250, 1300, 1250, 1000, 1200, 1200, 1300, 1300, 1200, 1300, 1300,
    1200, 1350, 1150, 1000, 1150, 1200, 1350, 1350, 1000, 1000, 1200, 1200,
    1000, 1200, 1400, 500, 1200, 800, 800, 800, 1000, 1200, 800, 1000, 150,
    1000, 1200, 1000, 800, 1200, 1200, 1200, 1250, 1250, 800, 800, 1200, 800,
    1000, 1200, 1000, 800, 1200, 800, 800, 800, 1150, 800, 800, 800, 1350, 800,
    1000, 800, 800, 800, 1400, 850, 1050, 1000, 800, 1200, 800, 800, 800, 500,
    150, 900, 1100, 1000, 1000, 1400, 1000, 1200, 1350, 1200, 1200, 1000, 1000,
    800, 1200, 1000, 1000, 800, 800, 800, 800, 1200, 1350, 900, 1250, 800, 800,
    800, 1200, 1000, 800, 800, 800, 1200, 800, 800, 800, 1200, 800, 800, 800,
    1000, 0, 0, 1200, 1300, 1300, 1300, 1000, 1050, 800, 800, 800, 1200, 800,
    1200, 1300, 1250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1400, 0, 0, 0, 800, 800, 1350,
    1250, 1500, 1200, 1200, 1000, 1200, 1000, 150, 1000, 1000, 800, 1000
};
s16 D_800AE6E4[][12] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    { 1000, 750, 800, 750, 750, 800, 1000, 350, 200, 100, 50, 10 }, 
    { 500, 700, 750, 800, 850, 1000, 1000, 700, 700, 350, 50, 10 }, 
    { 1000, 900, 800, 700, 600, 500, 500, 350, 200, 100, 50, 10},
};
s16 D_800AE744[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    3, 2, 2, 3, 1, 1, 3, 3, 2, 1,
    1, 3, 3, 1, 1, 1, 1, 1, 1, 3,
    1, 3, 1, 1, 3, 3, 1, 1, 1, 1,
    1, 3, 1, 3, 1, 1, 1, 1, 1, 1,
    1, 1, 3, 1
};
u16 D_800AE7C4 = false;
u16 D_800AE7C8 = false;
Gfx D_800AE7D0[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_COPY),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 64, 48),

    gsDPLoadTextureBlock(0x0C000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0B000000),
    gsSPTextureRectangle(0, 0, 0x00FC, 0x005C, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400),
    gsDPPipeSync(),

    gsDPLoadTextureBlock(0x0C000C00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0B000C00),
    gsSPTextureRectangle(0, 0, 0x00FC, 0x005C, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400),
    gsDPPipeSync(),
    
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0F000000),
    gsDPSetDepthImage(0x0A000000),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};
Gfx D_800AE8F8[] = {
    gsDPPipeSync(),
    // clear depth buffer and 12 images
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0C000000),
    gsDPSetFillColor(0xFFFCFFFC),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 64, 48 * 13),
    gsDPFillRectangle(0, 0, 64 - 1, 48 * 13 - 1),
    gsDPPipeSync(),

    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0F000000),
    gsDPSetDepthImage(0x0C000000),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 64, 48),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetFillColor(0x00010001),
    gsDPFillRectangle(0, 0, 63, 47),
    gsDPPipeSync(),

    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING),
    gsSPClipRatio(FRUSTRATIO_1),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPMatrix(&gIdentityMatrix, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION),
    gsSPMatrix(&gIdentityMatrix, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetAlphaDither(G_AD_PATTERN),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

extern GObj* D_800BDF30[];
extern s32 D_800BDF60;
extern GObj* D_800BDFA8;
extern PhotoData* D_800BDFAC;
extern u16* D_800BDFB0;
extern u16* D_800BDFB4;
extern u16* D_800BDFB8[];
extern u16* D_800BDFE8[];
extern u16 D_800BE018;
extern u16 D_800BE01A;
extern s32 D_800BE020[];
extern s32 D_800BE050[];
extern s32 D_800BE080[];
extern s32 D_800BE0B0[];
extern s32 D_800BE0E0[];
extern s32 D_800BE110[];
extern s32 D_800BE140[];
extern ScoreData D_800BE170;

s32 getNumberOfPoses(void) {
    return 164;
}

void func_8009FCC8(GObj* camObj) {
    OMCamera* camera;
    GObj* it;
    s32 dllink;
    u32 bitMask;
    u32 unk_38;
    f32 aspect;

    if (!D_800AE7C8) {
        return;
    }

    initObjectsOnPhoto(D_800BDFA8->data.cam, D_800BDFAC);
    D_800AE7C8 = false;
    omCurrentCamera = camObj;
    camera = camObj->data.cam;
    camera->flags |= CAMERA_FLAG_10;
    if (D_800AE7C4) {
        camera->perspMtx.persp.fovy *= 2.0f;
    }

    camera->vp.vp.vscale[0] = 128;
    camera->vp.vp.vscale[1] = 96;
    camera->vp.vp.vtrans[0] = 128;
    camera->vp.vp.vtrans[1] = 96;

    gSPViewport(gMainGfxPos[0]++, &camera->vp);
    gSPSegment(gMainGfxPos[0]++, 0x0F, D_800BDFB0);
    gSPSegment(gMainGfxPos[0]++, 0x0C, D_800BDFB4);
    gSPDisplayList(gMainGfxPos[0]++, D_800AE8F8);

    aspect = camera->perspMtx.persp.aspect;
    camera->perspMtx.persp.aspect = 4.0f / 3.0f;
    renPrepareCameraMatrix(&gMainGfxPos[0], camera);
    camera->perspMtx.persp.aspect = aspect;

    D_800BE01A = 0;
    dllink = 0;
    bitMask = camObj->dlLinkBitMask;
    unk_38 = camObj->unk_38;
    while (bitMask != 0) {
        if (bitMask & 1) {
            for (it = omGObjListDlHead[dllink]; it != NULL; it = it->nextDl) {
                if ((it->flags & GOBJ_FLAG_HIDDEN) || !(camObj->cameraTag & it->cameraTag)) {
                    continue;
                }
                omRenderedObject = it;
                if (it == D_800BDF30[D_800BE01A] && D_800BE01A < D_800BDF60) {
                    gSPSegment(gMainGfxPos[0]++, 0x0A, D_800BDFB8[D_800BE01A]);
                    gSPSegment(gMainGfxPos[0]++, 0x0B, D_800BDFE8[D_800BE01A]);
                    D_800BE01A++;
                    gSPDisplayList(gMainGfxPos[0]++, D_800AE7D0);
                    it->fnRender(it);
                    gDPPipeSync(gMainGfxPos[0]++);
                    gDPSetDepthImage(gMainGfxPos[0]++, 0x0C000000);
                }

                it->fnRender(it);
                it->lastDrawFrame = gtlDrawnFrameCounter;
                if (1) {
                } // required to match
            }
        }
        bitMask >>= 1;
        unk_38 >>= 1;
        dllink++;
    }

    renCameraPostRender(camera);
    camera->flags &= ~CAMERA_FLAG_10;
    if (D_800AE7C4) {
        camera->perspMtx.persp.fovy /= 2.0f;
    }
}

void func_800A007C(GObj* arg0, PhotoData* arg1, u16 arg2, u16* arg3) {
    s32 unused[4];
    GObjFunc sp3C;
    s32 idx;
    s32 i;
    s32 x, y;

    D_800BDFA8 = arg0;
    sp3C = arg0->fnRender;
    arg0->fnRender = func_8009FCC8;
    D_800BDFAC = arg1;
    D_800BE018 = arg2;

    D_800BDFB0 = arg3;
    arg3 += 64 * 48;
    D_800BDFB4 = arg3;
    arg3 += 64 * 48;

    for (i = 0; i < 12; i++) {
        D_800BDFB8[i] = arg3;
        arg3 += 64 * 48;
    }

    for (i = 0; i < 12; i++) {
        D_800BDFE8[i] = arg3;
        arg3 += 64 * 48;
    }

    D_800AE7C8 = true;
    D_800AE7C4 = true;

    bzero(D_800BDFB0, 0x27000);
    osWritebackDCacheAll();
    osInvalDCache(D_800BDFB0, 0x27000);
    func_80006F8C(D_800BDFA8);

    for (i = 0; i < 12; i++) {
        D_800BE020[i] = D_800BE050[i] = 0;

        for (y = 0; y < 48; y++) {
            for (x = 0; x < 64; x++) {
                idx = y * 64 + x;
                if (D_800BDFB8[i][idx] != 0xFFFC) {
                    D_800BE020[i]++;
                    if (x >= 17 && x <= 46 && y >= 13 && y <= 34) {
                        D_800BE050[i]++;
                    }
                }
            }
        }
    }

    D_800AE7C8 = true;
    D_800AE7C4 = false;

    bzero(D_800BDFB0, 0x27000);
    osWritebackDCacheAll();
    osInvalDCache(D_800BDFB0, 0x27000);
    func_80006F8C(D_800BDFA8);

    arg0->fnRender = sp3C;

    for (i = 0; i < 12; i++) {
        D_800BE080[i] = D_800BE0B0[i] = D_800BE0E0[i] = D_800BE140[i] = 0;

        for (y = 0; y < 48; y++) {
            for (x = 0; x < 64; x++) {
                idx = y * 64 + x;
                if (D_800BDFB8[i][idx] != 0xFFFC) {
                    D_800BE080[i]++;
                    if (x >= 30 && x <= 33 && y >= 22 && y <= 25) {
                        D_800BE140[i]++;
                    }
                    if (D_800BDFB8[i][idx] == D_800BDFB4[idx] && D_800BDFE8[i][idx] != D_800BDFB4[idx]) {
                        D_800BE0B0[i]++;
                        if (x >= 31 && x <= 32 && y >= 23 && y <= 24) {
                            D_800BE0E0[i]++;
                        }
                    }
                }
            }
        }

        if (D_800BE050[i] != 0) {
            D_800BE110[i] = D_800BE020[i] * D_800BE080[i] / D_800BE050[i];
        } else {
            D_800BE110[i] = D_800BE020[i] * 4;
        }
    }

    for (i = 0; i < D_800BE01A; i++) {
        if (arg1->unk_20[i].animationTime < 0.0f) {
            auPlaySound(SOUND_ID_85);
            ohWait(60);
        }
    }
    ohWait(1);
}

f32 func_800A0504(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return (arg4 - arg3) * (arg0 - arg1) / (arg2 - arg1) + arg3;
}

void func_800A0534(ScoreData* arg0, PhotoData* arg1, s32 arg2, s32 arg3) {
    f32 var_f2;
    u16 new_var;
    s32 new_var2;
    s32 var_v1;
    s32* temp_a0;

    if (arg3 == PokemonID_SHELLDER || arg3 == PokemonID_603) {
        if (arg1->unk_20[D_800BDF68[arg2]].pokemonID != PokemonID_SHELLDER &&
            arg1->unk_20[D_800BDF68[arg2]].pokemonID != PokemonID_603) {
            return;
        }
    } else if (arg3 != arg1->unk_20[D_800BDF68[arg2]].pokemonID) {
        return;
    }

    var_v1 = D_800BE0B0[arg2];
    if (var_v1 > 0x300) {
        var_v1 = 0x300;
    }
    if (var_v1 >= 4 && D_800BE110[arg2] > 0) {
        // TODO remove dumb
        if (1) {
        }
        new_var2 = 10;
        new_var = ((func_800A0504(var_v1, 4.0f, 768.0f, 0.2f, 1.0f) * 1000.0f) + 5.0f) / 10.0f;
        new_var2 = new_var * new_var2;

        var_f2 = ((f32) D_800BE0B0[arg2]) / ((f32) D_800BE110[arg2]);
        if (var_f2 > 1.0) {
            var_f2 = 1.0f;
        }

        arg0->samePkmnBonus += ((u16) (((var_f2 * new_var2) + 5.0f) / 10.0f)) * 10;
        arg0->totalScore += ((u16) (((var_f2 * new_var2) + 5.0f) / 10.0f)) * 10;
        arg0->samePkmnNumber++;
    }
}

void func_800A081C(ScoreData* arg0, PhotoData* arg1, s32 arg2) {
    s32 s3;
    s32 s0;
    f32 f0;
    f32 f2;
    s32 i;
    s32 specialID;
    f32 f22;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 tmp5;
    s32 poseID;
    f32 tmp6;
    f32 tmp7;
    f32 tmp8;

    arg0->totalScore = 0;
    tmp3 = D_800BDF68[arg2];
    s3 = arg1->unk_20[tmp3].pokemonID;
    if (s3 == PokemonID_603) {
        arg0->pokemonInFocus = PokemonID_SHELLDER;
    } else {
        arg0->pokemonInFocus = s3;
    }

    if (func_8009BDDC(arg1->unk_20[tmp3].pokemonID, arg1->unk_20[tmp3].unk_00_13) < 0.0f) {
        arg0->pokemonInFocus = PokemonID_500;
        return;
    }

    specialID = arg1->unk_20[tmp3].specialID;
    if (specialID > 0) {
        arg0->specialID = specialID;
        arg0->specialBonus = score_SpecialBonuses[specialID];
        arg0->totalScore += arg0->specialBonus;
    }

    s0 = D_800BE0B0[arg2];
    if (s0 > 0x300) {
        s0 = 0x300;
    }
    if (s0 < 4) {
        return;
    }

    f0 = func_800A0504(s0, 4.0f, 768.0f, 0.2f, 1.0f);
    arg0->sizeParam2 = ((u16) ((f0 * 1000.0f + 5.0f) / 10.0f)) * 10;

    if (s0 < 4 || D_800BE110[arg2] <= 0) {
        return;
    }

    f2 = (f32) D_800BE0B0[arg2] / (f32) D_800BE110[arg2];
    if (f2 > 1.0) {
        f2 = 1.0f;
    }

    arg0->sizeParam1 = f2 * 10000.0f + 0.5f;
    tmp8 = arg0->sizeParam2;
    f2 = arg0->sizeParam1 / 10000.f;
    tmp6 = f2 * tmp8;
    tmp5 = ((u16) ((tmp6 + 5.0f) / 10.0f)) * 10;
    arg0->totalScore += tmp5;

    if (f0 < 0.245f || f2 < 0.6f) {
        return;
    }

    poseID = arg1->unk_20[tmp3].poseID;
    arg0->poseID = poseID;
    if (poseID > 0) {
        arg0->posePts = score_PoseBonuses[poseID];
        arg0->totalScore += arg0->posePts;
        if (arg0->posePts < 200) {
            return;
        }
    } else {
        f22 = arg1->unk_20[tmp3].yaw - atan2f(arg1->unk_08.x - arg1->unk_14.x, arg1->unk_08.z - arg1->unk_14.z);
        while (f22 > PI) {
            f22 -= TAU;
        }
        while (f22 < -PI) {
            f22 += TAU;
        }
        if (f22 < 0.0f) {
            f22 = -f22;
        }

        tmp4 = D_800AE744[func_8009BB4C(s3)];
        tmp2 = f22 * 180.0f / PI / 15.0f;
        arg0->posePts = D_800AE6E4[tmp4][tmp2];
        arg0->totalScore += arg0->posePts;
        if (arg0->posePts < 200) {
            return;
        }
    }

    if (D_800BE140[arg2] != 0) {
        arg0->isWellFramed = true;
        arg0->totalScore *= 2;

        for (i = 0; i < arg2; i++) {
            func_800A0534(arg0, arg1, i, s3);
        }
        for (i = arg2 + 1; i < D_800BE01A; i++) {
            func_800A0534(arg0, arg1, i, s3);
        }
    }
}

void func_800A0E9C(ScoreData* arg0) {
}

#ifdef NON_MATCHING
s32 func_8009BCC4(UnkThing* arg0);
struct ScoreData* func_800A0EA4(GObj* camera, PhotoData* photo, u16* buffer, s32 width, s32 height, u16* zbuffer) {
    s32 tmp;
    s32 photoIdType1;
    s32 photoIdType2;
    s32 photoIdType3;
    s32 photoIdType4;
    s32 scoreType2;
    s32 scoreType1;
    s32 scoreType4;
    s32 sp24;
    s32 scoreType3;

    f32 temp_f0;
    s32 id;
    s32 temp_v1;
    s32 j;
    s32 var_t0;

    s32 i;

    D_800BE170.totalScore = 0;
    D_800BE170.pokemonInFocus = 0;
    D_800BE170.specialID = 0;
    D_800BE170.sizeParam2 = 0;
    D_800BE170.sizeParam1 = 0;
    D_800BE170.specialBonus = 0;
    D_800BE170.poseID = 0;
    D_800BE170.posePts = 0;
    D_800BE170.isWellFramed = 0;
    D_800BE170.samePkmnBonus = 0;
    D_800BE170.samePkmnNumber = 0;

    tmp = func_8009BCC4(photo);
    if (tmp > 0) {
        switch (tmp) {
            case PokemonID_1004:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.pokemonInFocus = tmp;
                    D_800BE170.totalScore = 0;
                } else {
                    D_800BE170.pokemonInFocus = 500;
                }
                break;
            case PokemonID_1010:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.pokemonInFocus = tmp;
                    D_800BE170.totalScore = 0;
                } else {
                    D_800BE170.pokemonInFocus = 500;
                }
                break;
            case PokemonID_1018:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.pokemonInFocus = tmp;
                    D_800BE170.totalScore = 0;
                } else {
                    D_800BE170.pokemonInFocus = 500;
                }
                break;
            case PokemonID_1022:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.pokemonInFocus = tmp;
                    D_800BE170.totalScore = 0;
                } else {
                    D_800BE170.pokemonInFocus = 500;
                }
                break;
            case PokemonID_KOFFING_SMOKE:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.pokemonInFocus = tmp;
                    D_800BE170.totalScore = 0;
                } else {
                    D_800BE170.pokemonInFocus = 500;
                }
                break;
            case PokemonID_1035:
                if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
                    D_800BE170.pokemonInFocus = tmp;
                    D_800BE170.totalScore = 0;
                } else {
                    D_800BE170.pokemonInFocus = 500;
                }
                break;
            case PokemonID_MOLTRES_EGG:
            case PokemonID_601:
            case PokemonID_602:
                D_800BE170.pokemonInFocus = tmp;
                break;
            default:
                if (func_8009BDDC(photo->unk_20[0].pokemonID, photo->unk_20[0].unk_00_13) < 0.0f) {
                    D_800BE170.pokemonInFocus = 500;
                }
                break;
        }

        if (D_800BE170.pokemonInFocus > 0) {
            func_800A0E9C(&D_800BE170);
            return &D_800BE170;
        }
    }

    for (var_t0 = 0, i = 0; i < 12; i++) {
        id = photo->unk_20[i].pokemonID;
        if (id == -1) {
            break;
        }

        if ((id > 0 && id <= POKEDEX_MAX) ||
            id == PokemonID_603 || id == PokemonID_MOLTRES_EGG ||
            id == PokemonID_601 || id == PokemonID_602) {
            var_t0++;
        }
    }

    func_800A007C(camera, photo, var_t0, buffer);
    if (tmp > 0 && D_800BE0B0[0] >= 12 && D_800BE110[0] > 0 && (f32) D_800BE0B0[0] / (f32) D_800BE110[0] >= 0.05f) {
        func_800A081C(&D_800BE170, photo, 0);
        func_800A0E9C(&D_800BE170);
        return &D_800BE170;
    }

    tmp = -1;
    photoIdType4 = -1;
    photoIdType1 = -1;
    photoIdType2 = -1;
    sp24 = -1;
    scoreType2 = -1;
    scoreType1 = -1;
    scoreType4 = -1;
    scoreType3 = -1;

    for (j = 0; j < D_800BE01A; j++) {
        temp_v1 = D_800BE0B0[j];
        if (temp_v1 < 12 || D_800BE110[j] == 0) {
            continue;
        }

        temp_f0 = (f32) temp_v1 / (f32) D_800BE110[j];
        if (temp_f0 < 0.2f) {
            continue;
        }

        id = photo->unk_20[j].pokemonID;
        if (id > POKEDEX_MAX && id != PokemonID_603 || temp_f0 < 0.65f) {
            if (D_800BE140[j] == 0) {
                if (scoreType4 < temp_v1) {
                    scoreType4 = temp_v1;
                    photoIdType4 = j;
                }
            } else if (scoreType2 < temp_v1) {
                scoreType2 = temp_v1;
                photoIdType2 = j;
            }
        } else if (D_800BE140[j] == 0) {
            if (scoreType3 < temp_v1) {
                scoreType3 = temp_v1;
                tmp = j;
            }
        } else if (scoreType1 < temp_v1) {
            scoreType1 = temp_v1;
            photoIdType1 = j;
        }
    }

    photo->unk_00_16 &= ~0x20;

    if (photoIdType1 >= 0) {
        sp24 = photoIdType1;
    } else if (photoIdType2 >= 0) {
        sp24 = photoIdType2;
    } else if (tmp >= 0) {
        sp24 = tmp;
    } else if (photoIdType4 >= 0) {
        sp24 = photoIdType4;
    }

    if (sp24 == -1) {
        func_800A0E9C(&D_800BE170);
        return &D_800BE170;
    } else {
        func_800A081C(&D_800BE170, photo, sp24);
        func_800A0E9C(&D_800BE170);
        return &D_800BE170;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4B670/func_800A0EA4.s")
#endif
