#include "common.h"
#include "app_level.h"
#include "world/world.h"

#define MAX_POKEMONS 20

extern s32 PokemonDetector_ScisTop = 0;
extern s32 PokemonDetector_ScisBottom = 0;
extern s32 PokemonDetector_ScisLeft = 0;
extern s32 PokemonDetector_ScisRight = 0;
extern Gfx PokemonDetector_GfxTileInCenter[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0x0F000000),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadTile(G_TX_LOADTILE, 156 << 2, 116 << 2, 163 << 2, 123 << 2),
    gsDPPipeSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 2, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 7 << 2, 7 << 2),
    gsSPEndDisplayList(),
};
extern Gfx PokemonDetector_GfxCopyTile[] = {
    gsDPSetCycleType(G_CYC_COPY),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 32, 32),
    gsSPTextureRectangle(0 << 2, 0 << 2, 7 << 2, 7 << 2, G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_2CYCLE),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetColorImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, 0x0F000000),
    gsSPEndDisplayList(),
};
// bss
extern s32 PokemonDetector_IsEnabled;
extern s32 PokemonDetector_NumPokemons[2];
extern u16* PokemonDetector_Regions[MAX_POKEMONS];
extern GObj* PokemonDetector_Pokemons[2][MAX_POKEMONS];
extern s32 PokemonDetector_PokemonIds[2][MAX_POKEMONS];
extern u16 PokemonDetector_PokemonFlags[2][MAX_POKEMONS];
extern s32 PokemonDetector_HasPokemonInFocus;
extern GObj* PokemonDetector_PokemonInFocus;
extern s32 PokemonDetector_PokemonIdInFocus;
extern u16 PokemonDetector_PokemonFlagsInFocus;
extern s32 gHasPokemonInFocus;
extern GObj* gPokemonInFocus;
extern s32 gPokemonIdInFocus;
extern u16 gPokemonFlagsInFocus;
extern s32 PokemonDetector_XMin;
extern s32 PokemonDetector_YMin;
extern s32 PokemonDetector_XMax;
extern s32 PokemonDetector_YMax;
extern UnkThing PokemonDetector_Photo[];
extern s32 PokemonDetector_TakenPhotoIndex;
extern u16 PokemonDetector_ContextId;
extern u16 PokemonDetector_AnalyzedPhotoId;
extern u16 gCurrentPhotoContext;
extern OSMesg PokemonDetector_Messages[2];
extern OSMesgQueue PokemonDetector_MessageQueue;

void PokemonDetector_SaveRegion(GObj* arg0);

void PokemonDetector_FindPokemonInFocus(void);
void func_8009C8E4(OMCamera* arg0, MovementState* arg1, UnkThing* arg2);

void PokemonDetector_PostProcessImage(u16* fb) {
    s32 i, j;
    s32 unused;
    OSMesg ctxId;

    if (osRecvMesg(&PokemonDetector_MessageQueue, &ctxId, OS_MESG_NOBLOCK) == -1) {
        return;
    }

    PokemonDetector_AnalyzedPhotoId = (u16) ctxId;
    PokemonDetector_FindPokemonInFocus();

    if (PokemonDetector_HasPokemonInFocus && PokemonDetector_PokemonInFocus != NULL) {
        if (PokemonDetector_PokemonIdInFocus == PokemonID_1004 ||
            PokemonDetector_PokemonIdInFocus == PokemonID_1018 ||
            PokemonDetector_PokemonIdInFocus == PokemonID_1022 ||
            PokemonDetector_PokemonIdInFocus == PokemonID_1035) {
            PokemonDetector_Photo[PokemonDetector_AnalyzedPhotoId].pokemonInFocus = PokemonDetector_PokemonInFocus;
        } else {
            for (i = 0; i < ARRAY_COUNT(PokemonDetector_Photo[PokemonDetector_AnalyzedPhotoId].pokemonObjects); i++) {
                if (PokemonDetector_Photo[PokemonDetector_AnalyzedPhotoId].pokemonObjects[i] == PokemonDetector_PokemonInFocus) {
                    PokemonDetector_Photo[PokemonDetector_AnalyzedPhotoId].pokemonInFocus = PokemonDetector_PokemonInFocus;
                    break;
                }
            }
            if (i >= ARRAY_COUNT(PokemonDetector_Photo[PokemonDetector_AnalyzedPhotoId].pokemonObjects)) {
                PokemonDetector_HasPokemonInFocus = false;
                PokemonDetector_PokemonInFocus = NULL;
            }
        }
    } else {
        PokemonDetector_Photo[PokemonDetector_AnalyzedPhotoId].pokemonInFocus = NULL;
        PokemonDetector_PokemonInFocus = NULL;
        PokemonDetector_HasPokemonInFocus = false;
    }

    if (PokemonDetector_HasPokemonInFocus && gDirectionIndex == -1 && (PokemonDetector_PokemonFlagsInFocus & POKEMON_FLAG_4)) {
        osInvalDCache(fb, SCREEN_WIDTH * SCREEN_HEIGHT * 2);
        // draw red dot in the center of the screen
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (i != 0 && i != 4 || j != 0 && j != 4) {
                    fb[(117 + i) * SCREEN_WIDTH + (157 + j)] = GPACK_RGBA5551(255, 0, 0, 255);
                }
            }
        }
        osWritebackDCacheAll();
    }
}

// this is called before drawing any pokemon
void PokemonDetector_InitDetector(GObj* detectorObj) {
    OMCamera* cam = omCurrentCamera->data.cam;
    Vp* vp = &cam->vp;

    PokemonDetector_ContextId = 1 - PokemonDetector_ContextId;
    func_8009C8E4(gMainCamera, &gMovementState, &PokemonDetector_Photo[PokemonDetector_ContextId]);
    PokemonDetector_NumPokemons[PokemonDetector_ContextId] = 0;

    PokemonDetector_XMin = vp->vp.vtrans[0] / 4 - vp->vp.vscale[0] / 4;
    PokemonDetector_YMin = vp->vp.vtrans[1] / 4 - vp->vp.vscale[1] / 4;
    PokemonDetector_XMax = vp->vp.vtrans[0] / 4 + vp->vp.vscale[0] / 4;
    PokemonDetector_YMax = vp->vp.vtrans[1] / 4 + vp->vp.vscale[1] / 4;

    if (PokemonDetector_XMin < viScreenWidth / SCREEN_WIDTH * PokemonDetector_ScisLeft) {
        PokemonDetector_XMin = viScreenWidth / SCREEN_WIDTH * PokemonDetector_ScisLeft;
    }
    if (PokemonDetector_YMin < viScreenHeight / SCREEN_HEIGHT * PokemonDetector_ScisTop) {
        PokemonDetector_YMin = viScreenHeight / SCREEN_HEIGHT * PokemonDetector_ScisTop;
    }
    if (PokemonDetector_XMax > viScreenWidth - viScreenWidth / SCREEN_WIDTH * PokemonDetector_ScisRight) {
        PokemonDetector_XMax = viScreenWidth - viScreenWidth / SCREEN_WIDTH * PokemonDetector_ScisRight;
    }
    if (PokemonDetector_YMax > viScreenHeight - viScreenHeight / SCREEN_HEIGHT * PokemonDetector_ScisBottom) {
        PokemonDetector_YMax = viScreenHeight - viScreenHeight / SCREEN_HEIGHT * PokemonDetector_ScisBottom;
    }

    PokemonDetector_SaveRegion(NULL);
}

void PokemonDetector_CopyInfo(GObj* arg0) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);
    gHasPokemonInFocus = PokemonDetector_HasPokemonInFocus;
    gPokemonInFocus = PokemonDetector_PokemonInFocus;
    gPokemonIdInFocus = PokemonDetector_PokemonIdInFocus;
    gPokemonFlagsInFocus = PokemonDetector_PokemonFlagsInFocus;
    gCurrentPhotoContext = PokemonDetector_AnalyzedPhotoId;
    osSetIntMask(mask);
}

void PokemonDetector_Create(void) {
    s32 i;

    PokemonDetector_TakenPhotoIndex = 0;
    PokemonDetector_Photo[0].pokemonInFocus = PokemonDetector_Photo[1].pokemonInFocus = NULL;

    for (i = 0; i < 12; i++) {
        PokemonDetector_Photo[0].pokemonObjects[i] = PokemonDetector_Photo[1].pokemonObjects[i] = NULL;
    }

    for (i = 0; i < MAX_POKEMONS; i++) {
        PokemonDetector_Regions[i] = gtlMalloc(8 * 8 * 2, 0x40);
    }
    omLinkGObjDL(omAddGObj(OBJID_0, NULL, LINK_PLAYER, 0x80000000), PokemonDetector_InitDetector, DL_LINK_5, 0x80000001, -1);
    osCreateMesgQueue(&PokemonDetector_MessageQueue, PokemonDetector_Messages, ARRAY_COUNT(PokemonDetector_Messages));
    scSetPostProcessFunc((void (*)(void*)) PokemonDetector_PostProcessImage);
    PokemonDetector_ContextId = 1;
    gHasPokemonInFocus = PokemonDetector_HasPokemonInFocus = 0;
    omAddGObj(OBJID_0, PokemonDetector_CopyInfo, LINK_0, 0x80000001);
}

void PokemonDetector_ProcessImage(void) {
    osSendMesg(&PokemonDetector_MessageQueue, (OSMesg) PokemonDetector_ContextId, OS_MESG_NOBLOCK);
}

void PokemonDetector_Enable(void) {
    PokemonDetector_IsEnabled = true;
}

void PokemonDetector_Disable(void) {
    PokemonDetector_IsEnabled = false;
}

void PokemonDetector_SaveRegion(GObj* pokemonObj) {
    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
    gSPDisplayList(gMainGfxPos[0]++, PokemonDetector_GfxTileInCenter);
    gDPSetColorImage(gMainGfxPos[0]++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, PokemonDetector_Regions[PokemonDetector_NumPokemons[PokemonDetector_ContextId]]);
    gSPDisplayList(gMainGfxPos[0]++, PokemonDetector_GfxCopyTile);
    mainCameraSetScissor(&gMainGfxPos[0]);
    PokemonDetector_Pokemons[PokemonDetector_ContextId][PokemonDetector_NumPokemons[PokemonDetector_ContextId]] = pokemonObj;
    if (pokemonObj != NULL && GET_POKEMON(pokemonObj) != NULL) {
        PokemonDetector_PokemonIds[PokemonDetector_ContextId][PokemonDetector_NumPokemons[PokemonDetector_ContextId]] = GET_POKEMON(pokemonObj)->id;
        PokemonDetector_PokemonFlags[PokemonDetector_ContextId][PokemonDetector_NumPokemons[PokemonDetector_ContextId]] = GET_POKEMON(pokemonObj)->flags;
    } else {
        PokemonDetector_PokemonIds[PokemonDetector_ContextId][PokemonDetector_NumPokemons[PokemonDetector_ContextId]] = -1;
        PokemonDetector_PokemonFlags[PokemonDetector_ContextId][PokemonDetector_NumPokemons[PokemonDetector_ContextId]] = 0;
    }
    if (PokemonDetector_NumPokemons[PokemonDetector_ContextId] < MAX_POKEMONS) {
        PokemonDetector_NumPokemons[PokemonDetector_ContextId]++;
    }
}

void PokemonDetector_FindPokemonInFocus(void) {
    s32 i, j;
    s32 cnt;

    for (i = 0; i < MAX_POKEMONS; i++) {
        osInvalDCache(PokemonDetector_Regions[i], 8 * 8 * 2);
    }
    PokemonDetector_HasPokemonInFocus = false;

    for (i = 1; i < PokemonDetector_NumPokemons[PokemonDetector_AnalyzedPhotoId]; i++) {
        do {
        } while (0); // required to match
        if (PokemonDetector_Pokemons[PokemonDetector_AnalyzedPhotoId][i] != NULL) {
            cnt = 0;
            for (j = 0; j < 8 * 8; j++) {
                if (PokemonDetector_Regions[i - 1][j] != PokemonDetector_Regions[i][j]) {
                    cnt++;
                }
            }
            if (cnt >= 32) {
                // at least 32 pixels of 64 are different
                PokemonDetector_HasPokemonInFocus = true;
                PokemonDetector_PokemonInFocus = PokemonDetector_Pokemons[PokemonDetector_AnalyzedPhotoId][i];
                PokemonDetector_PokemonIdInFocus = PokemonDetector_PokemonIds[PokemonDetector_AnalyzedPhotoId][i];
                PokemonDetector_PokemonFlagsInFocus = PokemonDetector_PokemonFlags[PokemonDetector_AnalyzedPhotoId][i];
            }
        }
    }
}

bool PokemonDetector_ReturnFalse(GObj* arg0) {
    return false;
}

void renderPokemonModelTypeIFogged(GObj* arg0) {
    if (!Pokemon_GetFlag100(arg0) && !PokemonDetector_ReturnFalse(arg0)) {
        renderModelTypeIFogged(arg0);
        if (PokemonDetector_IsEnabled) {
            PokemonDetector_SaveRegion(arg0);
        }
    }
}

void renderPokemonModelTypeJFogged(GObj* arg0) {
    if (!Pokemon_GetFlag100(arg0) && !PokemonDetector_ReturnFalse(arg0)) {
        renderModelTypeJFogged(arg0);
        if (PokemonDetector_IsEnabled) {
            PokemonDetector_SaveRegion(arg0);
        }
    }
}

void renderPokemonModelTypeBFogged(GObj* arg0) {
    if (!Pokemon_GetFlag100(arg0) && !PokemonDetector_ReturnFalse(arg0)) {
        renderModelTypeBFogged(arg0);
        if (PokemonDetector_IsEnabled) {
            PokemonDetector_SaveRegion(arg0);
        }
    }
}

void renderPokemonModelTypeDFogged(GObj* arg0) {
    if (!Pokemon_GetFlag100(arg0) && !PokemonDetector_ReturnFalse(arg0)) {
        renderModelTypeDFogged(arg0);
        if (PokemonDetector_IsEnabled) {
            PokemonDetector_SaveRegion(arg0);
        }
    }
}

void renderPokemonModelTypeI(GObj* arg0) {
    if (!Pokemon_GetFlag100(arg0) && !PokemonDetector_ReturnFalse(arg0)) {
        renRenderModelTypeI(arg0);
        if (PokemonDetector_IsEnabled) {
            PokemonDetector_SaveRegion(arg0);
        }
    }
}

void renderPokemonModelTypeB(GObj* arg0) {
    if (!Pokemon_GetFlag100(arg0) && !PokemonDetector_ReturnFalse(arg0)) {
        renRenderModelTypeB(arg0);
        if (PokemonDetector_IsEnabled) {
            PokemonDetector_SaveRegion(arg0);
        }
    }
}

void renderPokemonModelTypeD(GObj* arg0) {
    if (!Pokemon_GetFlag100(arg0) && !PokemonDetector_ReturnFalse(arg0)) {
        renRenderModelTypeD(arg0);
        if (PokemonDetector_IsEnabled) {
            PokemonDetector_SaveRegion(arg0);
        }
    }
}

void PokemonDetector_CleanupPokemon(GObj* pokemonObj) {
    s32 i, j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < MAX_POKEMONS; j++) {
            if (PokemonDetector_Pokemons[i][j] == pokemonObj) {
                PokemonDetector_Pokemons[i][j] = NULL;
            }
        }
    }

    if (PokemonDetector_HasPokemonInFocus == true && pokemonObj == PokemonDetector_PokemonInFocus) {
        PokemonDetector_HasPokemonInFocus = false;
    }
}
