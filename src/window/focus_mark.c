#include "common.h"

typedef struct FocusMarkData {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 targetX;
    /* 0x0C */ f32 targetY;
    /* 0x10 */ f32 width;
    /* 0x14 */ f32 height;
    /* 0x18 */ f32 targetWidth;
    /* 0x1C */ f32 targetHeight;
} FocusMarkData; // size = 0x20

extern Sprite D_80381A38_8551E8;
extern Bitmap* D_80381D98_855548[];

extern GObj* D_803A6A50_87A200[4];
extern FocusMarkData D_803A6A60_87A210;

void FocusMark_SetTargetPos(s32 x, s32 y) {
    D_803A6A60_87A210.targetX = x;
    D_803A6A60_87A210.targetY = y;
}

void FocusMark_SetPos(s32 x, s32 y) {
    D_803A6A60_87A210.targetX = x;
    D_803A6A60_87A210.x = D_803A6A60_87A210.targetX;
    D_803A6A60_87A210.targetY = y;
    D_803A6A60_87A210.y = D_803A6A60_87A210.targetY;
}

void FocusMark_SetTargetSize(s32 width, s32 height) {
    D_803A6A60_87A210.targetWidth = width;
    D_803A6A60_87A210.targetHeight = height;
}

void FocusMark_SetSize(s32 width, s32 height) {
    D_803A6A60_87A210.targetWidth = width;
    D_803A6A60_87A210.width = D_803A6A60_87A210.targetWidth;
    D_803A6A60_87A210.targetHeight = height;
    D_803A6A60_87A210.height = D_803A6A60_87A210.targetHeight;
}

void FocusMark_StopAnimation(bool arg0) {
    D_803A6A50_87A200[0]->userData = (void*) !arg0;
}

void FocusMark_Show(s32 show) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803A6A50_87A200); i++) {
        if (show) {
            D_803A6A50_87A200[i]->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_803A6A50_87A200[i]->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void FocusMark_MoveFront(void) {
    GObj* gobj;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803A6A50_87A200); i++) {
        gobj = D_803A6A50_87A200[i];
        omMoveGObjDL(gobj, gobj->dlLink, gobj->dlPriority);
    }
}

void FocusMark_Update(GObj* arg0) {
    s32 offset = 0;
    s32 counter = 4;
    s32 offsetInc = 1;

    while (true) {
        counter--;
        if ((bool)(arg0->userData)) {
            counter = 4;
            offset = 0;
            offsetInc = 1;
        } else if (counter == 0) {
            offset += offsetInc;
            counter = 4;
            if (offset <= 0) {
                offsetInc = 1;
            } else if (offset >= 2) {
                offsetInc = -1;
            }
        }

        D_803A6A60_87A210.x += (D_803A6A60_87A210.targetX - D_803A6A60_87A210.x) * 0.3;
        D_803A6A60_87A210.y += (D_803A6A60_87A210.targetY - D_803A6A60_87A210.y) * 0.3;
        D_803A6A60_87A210.width += (D_803A6A60_87A210.targetWidth - D_803A6A60_87A210.width) * 0.3;
        D_803A6A60_87A210.height += (D_803A6A60_87A210.targetHeight - D_803A6A60_87A210.height) * 0.3;

        D_803A6A50_87A200[0]->data.sobj->sprite.x = (s32)D_803A6A60_87A210.x - offset - 5;
        D_803A6A50_87A200[0]->data.sobj->sprite.y = (s32)D_803A6A60_87A210.y - offset - 5;
        D_803A6A50_87A200[1]->data.sobj->sprite.x = (s32)(D_803A6A60_87A210.x + D_803A6A60_87A210.width) + offset - 5;
        D_803A6A50_87A200[1]->data.sobj->sprite.y = (s32)D_803A6A60_87A210.y - offset - 5;
        D_803A6A50_87A200[2]->data.sobj->sprite.x = (s32)D_803A6A60_87A210.x - offset - 5;
        D_803A6A50_87A200[2]->data.sobj->sprite.y = (s32)(D_803A6A60_87A210.y + D_803A6A60_87A210.height) + offset - 5;
        D_803A6A50_87A200[3]->data.sobj->sprite.x = (s32)(D_803A6A60_87A210.x + D_803A6A60_87A210.width) + offset - 5;
        D_803A6A50_87A200[3]->data.sobj->sprite.y = (s32)(D_803A6A60_87A210.y + D_803A6A60_87A210.height) + offset - 5;
        ohWait(1);
    }
}

void FocusMark_Create(void) {
    GObj* tabObj;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_803A6A50_87A200[i] = func_800A9F10(i != 0 ? NULL : FocusMark_Update, 6, &D_80381A38_8551E8);
        D_803A6A50_87A200[i]->data.sobj->sprite.bitmap = D_80381D98_855548[i];
        D_803A6A50_87A200[i]->data.sobj->sprite.x = 80;
        D_803A6A50_87A200[i]->data.sobj->sprite.y = 80;
        D_803A6A50_87A200[i]->userData = (void*)false;
    }

    D_803A6A60_87A210.x = 22.0f;
    D_803A6A60_87A210.targetX = D_803A6A60_87A210.x;
    D_803A6A60_87A210.y = 29.0f;    
    D_803A6A60_87A210.targetY = D_803A6A60_87A210.y;
    D_803A6A60_87A210.width = 62.0f;
    D_803A6A60_87A210.targetWidth = D_803A6A60_87A210.width;
    D_803A6A60_87A210.height = 13.0f;    
    D_803A6A60_87A210.targetHeight = D_803A6A60_87A210.height;
}
