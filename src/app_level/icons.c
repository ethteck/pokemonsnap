#include "common.h"
#include "app_level.h"

enum IconSpriteIds {
    ICON_ID_APPLE       = 0,
    ICON_ID_PESTER_BALL = 1,
    ICON_ID_FLUTE       = 2,
    ICON_ID_ZOOM        = 3,
    ICON_ID_DASH        = 4,
    ICON_ID_DASH_ZOOMED = 5,
    ICON_ID_TAKE_PHOTO  = 6,
    ICON_ID_ZOOM_OFF    = 7
};

typedef struct SpriteDefStruct {
    /* 0x00 */ u32 x;
    /* 0x04 */ u32 y;
    /* 0x08 */ s32 shownWhenZoomedIn;
    /* 0x0C */ s32 moveOutDirection;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ Sprite* spriteDef;
} SpriteDefStruct; // size = 0x18

typedef struct SpriteStruct {
    /* 0x00 */ u32 x;
    /* 0x04 */ u32 y;
    /* 0x08 */ SObj* spriteObj;
    /* 0x0C */ char unused[12];
} SpriteStruct; // size = 0x18

// data
// TODO make sprite assets
extern Sprite D_80383B48_523F58; // Icon_Zoom
extern Sprite D_803841C8_5245D8; // Icon_ZoomOff
extern Sprite D_80384E68_525278; // Icon_Dash
extern Sprite D_80385B08_525F18; // Icon_Photo
extern Sprite D_803867A8_526BB8; // Icon_PesterBall
extern Sprite D_80387448_527858; // Icon_Apple
extern Sprite D_803880E8_5284F8; // Icon_Flute
// we have to make this small array because of alignment
u32 EndOfSpriteData[] = {
    0x803AF790,
    0x00000000,
    0x00000000
};

SpriteStruct Icons_IconObjects[] = {
    { 148, 104, NULL, 0, 0, NULL},
    { 124,  80, NULL, 0, 0, NULL},
    { 148,  80, NULL, 0, 0, NULL},
    { 172,  80, NULL, 0, 0, NULL},
    { 124, 104, NULL, 0, 0, NULL},
    { 172, 104, NULL, 0, 0, NULL},
    { 124, 128, NULL, 0, 0, NULL},
    { 148, 128, NULL, 0, 0, NULL},
    { 172, 128, NULL, 0, 0, NULL},
};
s32 D_80388204_528614[] = { ITEM_ID_APPLE, ITEM_ID_PESTER_BALL, ITEM_ID_POKEFLUTE };
SObj* Icons_ButtonIconsCopy[] = { NULL, NULL, NULL };
u32 D_8038821C_52862C = 0;
u8 Icons_ItemFlags = 0;
SObj* Icons_ButtonIcons[] = { NULL, NULL, NULL };
GObj* Icons_MainObject = NULL;
s32 Icons_IsShown = TRUE;
s32 Icons_NumItemsAvailable = 3;
u8 Icons_DashEngineEnabled = FALSE;
u8 Icons_FluteIsPlayed = FALSE;
SpriteDefStruct Icons_IconDefs[] = {
    { 210, 189, FALSE, 0, 2, &D_80387448_527858 },
    { 182, 185, FALSE, 0, 0, &D_803867A8_526BB8 },
    { 238, 185, FALSE, 0, 4, &D_803880E8_5284F8 },
    { 268, 189, FALSE, 1, 6, &D_80383B48_523F58 },
    { 268, 155, FALSE, 1, 8, &D_80384E68_525278 },
    { 316, 155, TRUE, 1, 4, &D_80384E68_525278 },
    { 238, 233, TRUE, 0, 0, &D_80385B08_525F18 },
    { 316, 189, TRUE, 1, 2, &D_803841C8_5245D8 },
};
u8 Icons_IsZoomedIn = FALSE;

// bss
extern s32 Icons_TotalMoveOutFrameCounter;
extern s32 D_803AF8BC_54FCCC;
extern s32 Icons_MoveOutCounter[8];

void Icons_FinishZoomIn(GObj*);

void Icons_UpdateDefault(GObj* arg0) {

}

void func_8035CBB8_4FCFC8(Sprite* arg0, Sprite* arg1) {
    arg0->width = arg1->width;
    arg0->height = arg1->height;
    arg0->bitmap = arg1->bitmap;
    arg0->rsp_dl = arg1->rsp_dl;
}

void Icons_ShakeIcon(s32 arg0) {
    if (Icons_IconObjects[arg0].spriteObj != NULL) {
        s32 x = Icons_IconObjects[arg0].x;
        s32 y = Icons_IconObjects[arg0].y;
        f32 scale = 1.0f;

        if (Icons_DashEngineEnabled) {
            x += randRange(5) - 2;
            y += randRange(5) - 2;
            scale = 1.2f;
        }
        spMove(&Icons_IconObjects[arg0].spriteObj->sprite, x, y);
        spScale(&Icons_IconObjects[arg0].spriteObj->sprite, scale, scale);
    }
}

void Icons_UpdateDashEngineIcon(GObj* arg0) {
    Icons_ShakeIcon(ICON_ID_DASH);
    Icons_ShakeIcon(ICON_ID_DASH_ZOOMED);
}

void Icons_UpdatePhotoIcon(GObj* arg0) {
    f32 scale;
    s32 i;
    SpriteStruct* spr = &Icons_IconObjects[ICON_ID_TAKE_PHOTO];

    if (spr->spriteObj != NULL) {
        scale = 1.0f;

        while (scale > 0.1f) {
            spScale(&spr->spriteObj->sprite, 1.0f, scale);
            spMove(&spr->spriteObj->sprite, spr->x, spr->y + (1.0f - scale) * 10.0f);
            ohWait(1);
            scale -= 0.2f;
        }

        spSetAttribute(&spr->spriteObj->sprite, SP_HIDDEN);
        for (i = 0; i < 2; i++) {
            ohWait(1);
        }
        spClearAttribute(&spr->spriteObj->sprite, SP_HIDDEN);
        spScale(&spr->spriteObj->sprite, 1.0f, 1.0f);
        spMove(&spr->spriteObj->sprite, spr->x, spr->y);
    }
    omEndProcess(NULL);
}

void func_8035CE74_4FD284(void) {
}

void Icons_ShrinkAndRestore(s32 id, f32 arg1, f32 arg2) {
    f32 scale = 1.0f;

    while (scale > 0.1f) {
        spScale(&Icons_IconObjects[id].spriteObj->sprite, scale, scale);
        spMove(&Icons_IconObjects[id].spriteObj->sprite,
               Icons_IconObjects[id].x + (1.0f - scale) * 10.0f,
               Icons_IconObjects[id].y + (1.0f - scale) * 10.0f);
        ohWait(1);
        scale -= 0.025f;
    }
    spScale(&Icons_IconObjects[id].spriteObj->sprite, 1.0f, 1.0f);
    spMove(&Icons_IconObjects[id].spriteObj->sprite,
            Icons_IconObjects[id].x,
            Icons_IconObjects[id].y);
}

void Icons_UpdateAppleIcon(GObj* arg0) {
    Icons_ShrinkAndRestore(ICON_ID_APPLE, 4.0f, 0.3f);
    omEndProcess(NULL);
}

void Icons_UpdatePesterBallIcon(GObj* arg0) {
    Icons_ShrinkAndRestore(ICON_ID_PESTER_BALL, 5.0f, 0.5f);
    omEndProcess(NULL);
}

void Icons_UpdateFluteIcon(GObj* arg0) {
    f32 scaleX = 1.0f;
    f32 scaleY = 1.0f;
    f32 scaleXIncr = 0.05f;
    f32 scaleYIncr = 0.05f;

    while (TRUE) {
        if (!Icons_FluteIsPlayed) {
            break;
        }
        scaleX += scaleXIncr;
        scaleY += scaleYIncr;

        if (scaleX > 1.5f) {
            scaleXIncr = -scaleXIncr;
        }
        if (scaleY > 1.5f) {
            scaleYIncr = -scaleYIncr;
        }
        if (scaleX < 0.8f) {
            scaleXIncr = -scaleXIncr;
        }
        if (scaleY < 0.8f) {
            scaleYIncr = -scaleYIncr;
        }
        spScale(&Icons_IconObjects[ICON_ID_FLUTE].spriteObj->sprite, scaleX, scaleY);
        ohWait(1);
    }
    spScale(&Icons_IconObjects[ICON_ID_FLUTE].spriteObj->sprite, 1.0f, 1.0f);
    omEndProcess(0);
}

void Icons_Init(void) {
    GObj* gobj;
    s32 temp_v0_8;
    s32 i;
    u32 progressFlags;
    SpriteStruct* spr;
    SpriteDefStruct* sprDef;
    s32 zero = 0;

    progressFlags = getProgressFlags();
    Icons_ItemFlags = 0;
    D_8038821C_52862C = 0;
    Icons_NumItemsAvailable = 0;

    if (progressFlags & PF_HAS_APPLE) {
        Icons_ItemFlags |= PF_HAS_APPLE;
    }
    if (progressFlags & PF_HAS_PESTER_BALL) {
        Icons_ItemFlags |= PF_HAS_PESTER_BALL;
    }
    if (progressFlags & PF_HAS_FLUTE) {
        Icons_ItemFlags |= PF_HAS_FLUTE;
    }

    if (Icons_ItemFlags & PF_HAS_APPLE) {
        Icons_NumItemsAvailable = 1;
    }
    if (Icons_ItemFlags & PF_HAS_PESTER_BALL) {
        Icons_NumItemsAvailable = 2;
    }
    if (Icons_ItemFlags & PF_HAS_FLUTE) {
        Icons_NumItemsAvailable = 3;
    }

    if (Icons_NumItemsAvailable > 0) {
        LastItemId = D_80388204_528614[D_8038821C_52862C];
    } else {
        LastItemId = -1;
    }
    gobj = omAddGObj(26, Icons_UpdateDefault, 0, 0x80000000);
    omLinkGObjDL(gobj, &renDrawSprite, 1, 0x80000000, -1);
    Icons_MainObject = gobj;

    spr = &Icons_IconObjects[ICON_ID_ZOOM];
    sprDef = &Icons_IconDefs[ICON_ID_ZOOM];
    spr->spriteObj = omGObjAddSprite(gobj, sprDef->spriteDef);
    spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
    spr->x = sprDef->x; spr->y = sprDef->y;

    if (progressFlags & PF_HAS_DASH_ENGINE) {
        spr = &Icons_IconObjects[ICON_ID_DASH];
        sprDef = &Icons_IconDefs[ICON_ID_DASH];
        spr->spriteObj = omGObjAddSprite(gobj, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;

        spr = &Icons_IconObjects[ICON_ID_DASH_ZOOMED];
        sprDef = &Icons_IconDefs[ICON_ID_DASH_ZOOMED];
        spr->spriteObj = omGObjAddSprite(gobj, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
        spSetAttribute(&spr->spriteObj->sprite, SP_HIDDEN);
    }

    spr = &Icons_IconObjects[ICON_ID_TAKE_PHOTO];
    sprDef = &Icons_IconDefs[ICON_ID_TAKE_PHOTO];
    spr->spriteObj = omGObjAddSprite(gobj, sprDef->spriteDef);
    spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
    spr->x = sprDef->x; spr->y = sprDef->y;
    spSetAttribute(&spr->spriteObj->sprite, SP_HIDDEN);

    if (progressFlags & PF_ZOOM_SWITCH) {
        spr = &Icons_IconObjects[ICON_ID_ZOOM_OFF];
        sprDef = &Icons_IconDefs[ICON_ID_ZOOM_OFF];
        spr->spriteObj = omGObjAddSprite(gobj, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
        spSetAttribute(&spr->spriteObj->sprite, SP_HIDDEN);
    }

    if (Icons_NumItemsAvailable >= 3) {
        spr = &Icons_IconObjects[ICON_ID_FLUTE];
        sprDef = &Icons_IconDefs[ICON_ID_FLUTE];
        spr->spriteObj = Icons_ButtonIcons[ICON_ID_FLUTE] = omGObjAddSprite(gobj, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
    }
    if (Icons_NumItemsAvailable >= 1) {
        spr = &Icons_IconObjects[ICON_ID_APPLE];
        sprDef = &Icons_IconDefs[ICON_ID_APPLE];
        spr->spriteObj = Icons_ButtonIcons[ICON_ID_APPLE] = omGObjAddSprite(gobj, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
    }
    if (Icons_NumItemsAvailable >= 2) {
        spr = &Icons_IconObjects[ICON_ID_PESTER_BALL];
        sprDef = &Icons_IconDefs[ICON_ID_PESTER_BALL];
        spr->spriteObj = Icons_ButtonIcons[ICON_ID_PESTER_BALL] = omGObjAddSprite(gobj, sprDef->spriteDef);
        spMove(&spr->spriteObj->sprite, sprDef->x, sprDef->y);
        spr->x = sprDef->x; spr->y = sprDef->y;
    }

    Icons_ButtonIconsCopy[0] = Icons_ButtonIcons[0];
    Icons_ButtonIconsCopy[1] = Icons_ButtonIcons[1];
    Icons_ButtonIconsCopy[2] = Icons_ButtonIcons[2];

    omCreateProcess(gobj, Icons_UpdateDashEngineIcon, 1, 1);

    for (i = 0; i < ARRAY_COUNT(Icons_MoveOutCounter); i++) { Icons_MoveOutCounter[i] = 0; }
}

void Icons_SetDashEngineEnabled(s32 enabled) {
    Icons_DashEngineEnabled = enabled;
}

void Icons_MoveIcon(s32 id, s32 offset) {
    Icons_IconObjects[id].x += Icons_IconDefs[id].moveOutDirection ? offset : 0;
    Icons_IconObjects[id].y += Icons_IconDefs[id].moveOutDirection ? 0 : offset;
    spMove(&Icons_IconObjects[id].spriteObj->sprite, Icons_IconObjects[id].x, Icons_IconObjects[id].y);
}

void Icons_ProcessZoomIn(GObj* arg0) {
    s32 i;
    s32 isMoving;

    while (TRUE) {
        isMoving = FALSE;
        if (!Icons_IsZoomedIn) {
            break;
        }

        for (i = 0; i < ARRAY_COUNT(Icons_IconDefs); i++) {
            if (!Icons_IconDefs[i].shownWhenZoomedIn && Icons_IconObjects[i].spriteObj != NULL && Icons_MoveOutCounter[i] < 8) {
                isMoving = TRUE;
                Icons_MoveOutCounter[i]++;
                Icons_MoveIcon(i, 6);
            }
        }

        if (isMoving) {
            if (Icons_TotalMoveOutFrameCounter < 8) {
                Icons_TotalMoveOutFrameCounter++;
            }
            ohWait(1);
            continue;
        }

        for (i = 0; i < ARRAY_COUNT(Icons_IconDefs); i++) {
            if (!Icons_IconDefs[i].shownWhenZoomedIn && Icons_IconObjects[i].spriteObj != NULL) {
                spSetAttribute(&Icons_IconObjects[i].spriteObj->sprite, SP_HIDDEN);
            }
        }
        omCreateProcess(Icons_MainObject, Icons_FinishZoomIn, 0, 1);
        break;
    }
    omEndProcess(NULL);
}

void Icons_FinishZoomOut(GObj* arg0) {
    s32 i;
    s32 isMoving;

    for (i = 0; i < ARRAY_COUNT(Icons_IconDefs); i++) {
        if (!Icons_IconDefs[i].shownWhenZoomedIn && Icons_IconObjects[i].spriteObj != NULL) {
            spClearAttribute(&Icons_IconObjects[i].spriteObj->sprite, SP_HIDDEN);
        }
    }

    while (TRUE) {
        isMoving = FALSE;
        if (Icons_IsZoomedIn == TRUE) {
            break;
        }

        for (i = 0; i < ARRAY_COUNT(Icons_IconDefs); i++) {
            if (!Icons_IconDefs[i].shownWhenZoomedIn && Icons_IconObjects[i].spriteObj != NULL) {
                if (Icons_IconDefs[i].unk_10 <= 8 - Icons_TotalMoveOutFrameCounter) {
                    if (Icons_MoveOutCounter[i] > 0) {
                        isMoving = TRUE;
                        Icons_MoveOutCounter[i]--;
                        Icons_MoveIcon(i, -6);
                    }
                } else {
                    isMoving = TRUE;
                }
            }
        }

        if (isMoving) {
            if (Icons_TotalMoveOutFrameCounter > 0) {
                Icons_TotalMoveOutFrameCounter--;
            }
            ohWait(1);
            continue;
        }
        break;
    }
    omEndProcess(NULL);
}

void Icons_ProcessZoomOut(GObj* arg0) {
    s32 i;
    s32 isMoving;

    while (TRUE) {
        isMoving = FALSE;
        if (Icons_IsZoomedIn == TRUE) {
            break;
        }

        for (i = 0; i < ARRAY_COUNT(Icons_IconDefs); i++) {
            if (Icons_IconDefs[i].shownWhenZoomedIn && Icons_IconObjects[i].spriteObj != NULL && Icons_MoveOutCounter[i] >= 0) {
                isMoving = TRUE;
                Icons_MoveOutCounter[i]--;
                Icons_MoveIcon(i, 6);
            }
        }

        if (isMoving) {
            if (D_803AF8BC_54FCCC > 0) {
                D_803AF8BC_54FCCC--;
            }
            ohWait(1);
            continue;
        }

        for (i = 0; i < ARRAY_COUNT(Icons_IconDefs); i++) {
            if (Icons_IconDefs[i].shownWhenZoomedIn && Icons_IconObjects[i].spriteObj != NULL) {
                spSetAttribute(&Icons_IconObjects[i].spriteObj->sprite, SP_HIDDEN);
            }
        }
        omCreateProcess(Icons_MainObject, Icons_FinishZoomOut, 0, 1);
        break;
    }
    omEndProcess(NULL);
}

void Icons_FinishZoomIn(GObj* arg0) {
    s32 i;
    s32 isMoving;

    for (i = 0; i < ARRAY_COUNT(Icons_IconDefs); i++) {
        if (Icons_IconDefs[i].shownWhenZoomedIn && Icons_IconObjects[i].spriteObj != NULL) {
            spClearAttribute(&Icons_IconObjects[i].spriteObj->sprite, SP_HIDDEN);
        }
    }

    while (TRUE) {
        isMoving = FALSE;
        if (!Icons_IsZoomedIn) {
            break;
        }

        for (i = 0; i < ARRAY_COUNT(Icons_IconDefs); i++) {
            if (Icons_IconDefs[i].shownWhenZoomedIn && Icons_IconObjects[i].spriteObj != NULL) {
                if (Icons_IconDefs[i].unk_10 <= D_803AF8BC_54FCCC) {
                    if (Icons_MoveOutCounter[i] < 8) {
                        isMoving = TRUE;
                        Icons_MoveOutCounter[i]++;
                        Icons_MoveIcon(i, -6);
                    }
                } else {
                    isMoving = TRUE;
                }
            }
        }

        if (isMoving) {
            if (D_803AF8BC_54FCCC < 8) {
                D_803AF8BC_54FCCC++;
            }
            ohWait(1);
            continue;
        }
        break;
    }
    omEndProcess(NULL);
}

void Icons_ProcessZoom(s32 zoomEnabled) {
    if (zoomEnabled == 0 && Icons_IsZoomedIn != FALSE) {
        omCreateProcess(Icons_MainObject, Icons_ProcessZoomOut, 0, 1);
        Icons_IsZoomedIn = FALSE;
        return;
    }
    if (zoomEnabled == 1 && Icons_IsZoomedIn != TRUE) {
        omCreateProcess(Icons_MainObject, Icons_ProcessZoomIn, 0, 1);
        Icons_IsZoomedIn = TRUE;
    }
}

void Icons_Show(void) {
    Icons_MainObject->flags &= ~GOBJ_FLAG_HIDDEN;
    Icons_IsShown = TRUE;
}

void Icons_Hide(void) {
    Icons_MainObject->flags |= GOBJ_FLAG_HIDDEN;
    Icons_IsShown = FALSE;
}

void Icons_ProcessButtonPress(s32 eventID) {
    if (eventID == ITEM_ID_PESTER_BALL) {
        omCreateProcess(Icons_MainObject, Icons_UpdatePesterBallIcon, 0, 1);
    } else if (eventID == ITEM_ID_APPLE) {
        omCreateProcess(Icons_MainObject, Icons_UpdateAppleIcon, 0, 1);
    } else if (eventID == ITEM_ID_POKEFLUTE) {
        if (Icons_FluteIsPlayed == FALSE) {
            omCreateProcess(Icons_MainObject, Icons_UpdateFluteIcon, 0, 1);
            Icons_FluteIsPlayed = TRUE;
        }
    } else {
        Icons_FluteIsPlayed = FALSE;
    }
}

void Icons_ProcessTakePhotoPressed(void) {
    omCreateProcess(Icons_MainObject, Icons_UpdatePhotoIcon, 0, 1);
}

void Icons_Freeze(void) {
    ohPauseObjectProcesses(Icons_MainObject);
}

void Icons_UnFreeze(void) {
    ohResumeObjectProcesses(Icons_MainObject);
}
