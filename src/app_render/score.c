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
u16 score_WideFOV = false;
u16 score_ReadyToRender = false;

Gfx score_GfxCopyZBuffer[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_COPY),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 64, 48),
    // copy z buffer to current pokemon z buffer
    // upper part
    gsDPLoadTextureBlock(0x0C000000, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 24, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0B000000),
    gsSPTextureRectangle(0, 0, 0x00FC, 0x005C, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400),
    gsDPPipeSync(),
    // lower part
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
Gfx score_GfxSetupBuffers[] = {
    gsDPPipeSync(),
    // clear current z buffer and 12 pokemon z buffers
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0C000000),
    gsDPSetFillColor(0xFFFCFFFC),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 64, 48 * 13),
    gsDPFillRectangle(0, 0, 64 - 1, 48 * 13 - 1),
    gsDPPipeSync(),
    // clear image buffer
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

extern GObj* photo_PokemonObjs[];
extern s32 photo_PokemonCount;
extern GObj* score_CameraObject;
extern PhotoData* score_CurrentPhoto;
extern u16* score_ImageBuffer;
extern u16* score_CurrentZBuffer;
extern u16* score_PokemonZBuffer[];
extern u16* score_ZBufferBefore[];
extern u16 D_800BE018;
extern u16 score_PokemonCount;
extern s32 score_PixelCountWide[];
extern s32 score_PixelCountCenterPartWide[];
extern s32 score_PixelCount[];
extern s32 score_PixelCountUnobstructed[];
extern s32 score_PixelCountUnobstructedInCenter[];
extern s32 score_ApproxTotalPixelCount[];
extern s32 score_PixelCountInCenter[];
extern ScoreData D_800BE170;

s32 getNumberOfPoses(void) {
    return 164;
}

void score_Render(GObj* camObj) {
    OMCamera* camera;
    GObj* it;
    s32 dllink;
    u32 bitMask;
    u32 unk_38;
    f32 aspect;

    if (!score_ReadyToRender) {
        return;
    }

    initObjectsOnPhoto(score_CameraObject->data.cam, score_CurrentPhoto);
    score_ReadyToRender = false;
    omCurrentCamera = camObj;
    camera = camObj->data.cam;
    camera->flags |= CAMERA_FLAG_10;
    if (score_WideFOV) {
        camera->perspMtx.persp.fovy *= 2.0f;
    }

    camera->vp.vp.vscale[0] = 128;
    camera->vp.vp.vscale[1] = 96;
    camera->vp.vp.vtrans[0] = 128;
    camera->vp.vp.vtrans[1] = 96;

    gSPViewport(gMainGfxPos[0]++, &camera->vp);
    gSPSegment(gMainGfxPos[0]++, 0x0F, score_ImageBuffer);
    gSPSegment(gMainGfxPos[0]++, 0x0C, score_CurrentZBuffer);
    gSPDisplayList(gMainGfxPos[0]++, score_GfxSetupBuffers);

    aspect = camera->perspMtx.persp.aspect;
    camera->perspMtx.persp.aspect = 4.0f / 3.0f;
    renPrepareCameraMatrix(&gMainGfxPos[0], camera);
    camera->perspMtx.persp.aspect = aspect;

    score_PokemonCount = 0;
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
                if (it == photo_PokemonObjs[score_PokemonCount] && score_PokemonCount < photo_PokemonCount) {
                    gSPSegment(gMainGfxPos[0]++, 0x0A, score_PokemonZBuffer[score_PokemonCount]);
                    gSPSegment(gMainGfxPos[0]++, 0x0B, score_ZBufferBefore[score_PokemonCount]);
                    score_PokemonCount++;
                    gSPDisplayList(gMainGfxPos[0]++, score_GfxCopyZBuffer);
                    it->fnRender(it);
                    gDPPipeSync(gMainGfxPos[0]++);
                    // restore z buffer to score_CurrentZBuffer
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
    if (score_WideFOV) {
        camera->perspMtx.persp.fovy /= 2.0f;
    }
}

void func_800A007C(GObj* camObj, PhotoData* photo, u16 arg2, u16* buffer) {
    s32 unused[4];
    GObjFunc originalRenderFunc;
    s32 pixelIdx;
    s32 i;
    s32 x, y;

    score_CameraObject = camObj;
    originalRenderFunc = camObj->fnRender;
    camObj->fnRender = score_Render;
    score_CurrentPhoto = photo;
    D_800BE018 = arg2;

    score_ImageBuffer = buffer;
    buffer += 64 * 48;
    score_CurrentZBuffer = buffer;
    buffer += 64 * 48;

    for (i = 0; i < 12; i++) {
        score_PokemonZBuffer[i] = buffer;
        buffer += 64 * 48;
    }

    for (i = 0; i < 12; i++) {
        score_ZBufferBefore[i] = buffer;
        buffer += 64 * 48;
    }

    score_ReadyToRender = true;
    score_WideFOV = true;

    bzero(score_ImageBuffer, 0x27000);
    osWritebackDCacheAll();
    osInvalDCache(score_ImageBuffer, 0x27000);
    gtlDrawOne(score_CameraObject);

    for (i = 0; i < 12; i++) {
        score_PixelCountWide[i] = score_PixelCountCenterPartWide[i] = 0;

        for (y = 0; y < 48; y++) {
            for (x = 0; x < 64; x++) {
                pixelIdx = y * 64 + x;
                if (score_PokemonZBuffer[i][pixelIdx] != 0xFFFC) {
                    score_PixelCountWide[i]++;
                    if (x >= 17 && x <= 46 && y >= 13 && y <= 34) {
                        score_PixelCountCenterPartWide[i]++;
                    }
                }
            }
        }
    }

    score_ReadyToRender = true;
    score_WideFOV = false;

    bzero(score_ImageBuffer, 0x27000);
    osWritebackDCacheAll();
    osInvalDCache(score_ImageBuffer, 0x27000);
    gtlDrawOne(score_CameraObject);

    camObj->fnRender = originalRenderFunc;

    for (i = 0; i < 12; i++) {
        score_PixelCount[i] = score_PixelCountUnobstructed[i] = score_PixelCountUnobstructedInCenter[i] = score_PixelCountInCenter[i] = 0;

        for (y = 0; y < 48; y++) {
            for (x = 0; x < 64; x++) {
                pixelIdx = y * 64 + x;
                if (score_PokemonZBuffer[i][pixelIdx] != 0xFFFC) {
                    score_PixelCount[i]++;
                    if (x >= 30 && x <= 33 && y >= 22 && y <= 25) {
                        score_PixelCountInCenter[i]++;
                    }
                    if (score_PokemonZBuffer[i][pixelIdx] == score_CurrentZBuffer[pixelIdx] && score_ZBufferBefore[i][pixelIdx] != score_CurrentZBuffer[pixelIdx]) {
                        score_PixelCountUnobstructed[i]++;
                        if (x >= 31 && x <= 32 && y >= 23 && y <= 24) {
                            score_PixelCountUnobstructedInCenter[i]++;
                        }
                    }
                }
            }
        }

        if (score_PixelCountCenterPartWide[i] != 0) {
            score_ApproxTotalPixelCount[i] = score_PixelCountWide[i] * score_PixelCount[i] / score_PixelCountCenterPartWide[i];
        } else {
            score_ApproxTotalPixelCount[i] = score_PixelCountWide[i] * 4;
        }
    }

    for (i = 0; i < score_PokemonCount; i++) {
        if (photo->pokemons[i].animationTime < 0.0f) {
            auPlaySound(SOUND_ID_85);
            ohWait(60);
        }
    }
    ohWait(1);
}

f32 score_Interpolate(f32 value, f32 xmin, f32 xmax, f32 ymin, f32 ymax) {
    return (ymax - ymin) * (value - xmin) / (xmax - xmin) + ymin;
}

void score_AddSamePkmnBonus(ScoreData* score, PhotoData* photo, s32 idx, s32 thisPokemon) {
    f32 visiblePart;
    u16 new_var;
    s32 visiblePixelScore; // from 200 to 1000
    s32 visiblePixels;
    s32* temp_a0;

    if (thisPokemon == PokemonID_SHELLDER || thisPokemon == PokemonID_603) {
        if (photo->pokemons[photo_PokemonIndexes[idx]].pokemonID != PokemonID_SHELLDER &&
            photo->pokemons[photo_PokemonIndexes[idx]].pokemonID != PokemonID_603) {
            return;
        }
    } else if (thisPokemon != photo->pokemons[photo_PokemonIndexes[idx]].pokemonID) {
        return;
    }

    visiblePixels = score_PixelCountUnobstructed[idx];
    if (visiblePixels > 768) {
        visiblePixels = 768;
    }
    if (visiblePixels >= 4 && score_ApproxTotalPixelCount[idx] > 0) {
        // TODO remove dumb
        if (1) {
        }
        visiblePixelScore = 10;
        new_var = ((score_Interpolate(visiblePixels, 4.0f, 768.0f, 0.2f, 1.0f) * 1000.0f) + 5.0f) / 10.0f;
        visiblePixelScore = new_var * visiblePixelScore;

        visiblePart = ((f32) score_PixelCountUnobstructed[idx]) / ((f32) score_ApproxTotalPixelCount[idx]);
        if (visiblePart > 1.0) {
            visiblePart = 1.0f;
        }

        score->samePkmnBonus += ((u16) (((visiblePart * visiblePixelScore) + 5.0f) / 10.0f)) * 10;
        score->totalScore += ((u16) (((visiblePart * visiblePixelScore) + 5.0f) / 10.0f)) * 10;
        score->samePkmnNumber++;
    }
}

void score_CalculateScore(ScoreData* score, PhotoData* photo, s32 id) {
    s32 pkmnID;
    s32 visiblePixels;
    f32 visiblePixelScore;
    f32 visiblePart;
    s32 i;
    s32 specialID;
    f32 f22;
    s32 tmp2;
    s32 idx;
    s32 tmp4;
    s32 roundedSizeScore;
    s32 poseID;
    f32 sizeScore;
    f32 tmp7;
    f32 tmp8;

    score->totalScore = 0;

    idx = photo_PokemonIndexes[id];
    pkmnID = photo->pokemons[idx].pokemonID;
    if (pkmnID == PokemonID_603) {
        score->pokemonInFocus = PokemonID_SHELLDER;
    } else {
        score->pokemonInFocus = pkmnID;
    }

    if (func_8009BDDC(photo->pokemons[idx].pokemonID, photo->pokemons[idx].unk_00_13) < 0.0f) {
        score->pokemonInFocus = PokemonID_500;
        return;
    }

    specialID = photo->pokemons[idx].specialID;
    if (specialID > 0) {
        score->specialID = specialID;
        score->specialBonus = score_SpecialBonuses[specialID];
        score->totalScore += score->specialBonus;
    }

    visiblePixels = score_PixelCountUnobstructed[id];
    if (visiblePixels > 768) {
        visiblePixels = 768;
    }
    if (visiblePixels < 4) {
        return;
    }

    visiblePixelScore = score_Interpolate(visiblePixels, 4.0f, 768.0f, 0.2f, 1.0f);
    score->proximityScore = ((u16) ((visiblePixelScore * 1000.0f + 5.0f) / 10.0f)) * 10;

    if (visiblePixels < 4 || score_ApproxTotalPixelCount[id] <= 0) {
        return;
    }

    visiblePart = (f32) score_PixelCountUnobstructed[id] / (f32) score_ApproxTotalPixelCount[id];
    if (visiblePart > 1.0) {
        visiblePart = 1.0f;
    }

    score->completenessScore = visiblePart * 10000.0f + 0.5f;
    tmp8 = score->proximityScore;
    visiblePart = score->completenessScore / 10000.f;
    sizeScore = visiblePart * tmp8;
    roundedSizeScore = ((u16) ((sizeScore + 5.0f) / 10.0f)) * 10;
    score->totalScore += roundedSizeScore;

    if (visiblePixelScore < 0.245f || visiblePart < 0.6f) {
        return;
    }

    poseID = photo->pokemons[idx].poseID;
    score->poseID = poseID;
    if (poseID > 0) {
        score->posePts = score_PoseBonuses[poseID];
        score->totalScore += score->posePts;
        if (score->posePts < 200) {
            return;
        }
    } else {
        f22 = photo->pokemons[idx].yaw - atan2f(photo->unk_08.x - photo->unk_14.x, photo->unk_08.z - photo->unk_14.z);
        while (f22 > PI) {
            f22 -= TAU;
        }
        while (f22 < -PI) {
            f22 += TAU;
        }
        if (f22 < 0.0f) {
            f22 = -f22;
        }

        tmp4 = D_800AE744[func_8009BB4C(pkmnID)];
        tmp2 = f22 * 180.0f / PI / 15.0f;
        score->posePts = D_800AE6E4[tmp4][tmp2];
        score->totalScore += score->posePts;
        if (score->posePts < 200) {
            return;
        }
    }

    if (score_PixelCountInCenter[id] != 0) {
        score->isWellFramed = true;
        score->totalScore *= 2;

        for (i = 0; i < id; i++) {
            score_AddSamePkmnBonus(score, photo, i, pkmnID);
        }
        for (i = id + 1; i < score_PokemonCount; i++) {
            score_AddSamePkmnBonus(score, photo, i, pkmnID);
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
    D_800BE170.proximityScore = 0;
    D_800BE170.completenessScore = 0;
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
            case PokemonID_ZAPDOS_EGG:
                D_800BE170.pokemonInFocus = tmp;
                break;
            default:
                if (func_8009BDDC(photo->pokemons[0].pokemonID, photo->pokemons[0].unk_00_13) < 0.0f) {
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
        id = photo->pokemons[i].pokemonID;
        if (id == -1) {
            break;
        }

        if ((id > 0 && id <= POKEDEX_MAX) ||
            id == PokemonID_603 || id == PokemonID_MOLTRES_EGG ||
            id == PokemonID_601 || id == PokemonID_ZAPDOS_EGG) {
            var_t0++;
        }
    }

    func_800A007C(camera, photo, var_t0, buffer);
    if (tmp > 0 && score_PixelCountUnobstructed[0] >= 12 && score_ApproxTotalPixelCount[0] > 0 && (f32) score_PixelCountUnobstructed[0] / (f32) score_ApproxTotalPixelCount[0] >= 0.05f) {
        score_CalculateScore(&D_800BE170, photo, 0);
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

    for (j = 0; j < score_PokemonCount; j++) {
        temp_v1 = score_PixelCountUnobstructed[j];
        if (temp_v1 < 12 || score_ApproxTotalPixelCount[j] == 0) {
            continue;
        }

        temp_f0 = (f32) temp_v1 / (f32) score_ApproxTotalPixelCount[j];
        if (temp_f0 < 0.2f) {
            continue;
        }

        id = photo->pokemons[j].pokemonID;
        if (id > POKEDEX_MAX && id != PokemonID_603 || temp_f0 < 0.65f) {
            if (score_PixelCountInCenter[j] == 0) {
                if (scoreType4 < temp_v1) {
                    scoreType4 = temp_v1;
                    photoIdType4 = j;
                }
            } else if (scoreType2 < temp_v1) {
                scoreType2 = temp_v1;
                photoIdType2 = j;
            }
        } else if (score_PixelCountInCenter[j] == 0) {
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
        score_CalculateScore(&D_800BE170, photo, sp24);
        func_800A0E9C(&D_800BE170);
        return &D_800BE170;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/score/func_800A0EA4.s")
#endif
