#include "common.h"
#include "window.h"
#include "string.h"

typedef struct UIButtonListEntry {
    /* 0x00 */ struct UIButtonListEntry* next;
    /* 0x04 */ struct UIButtonListEntry* prev;
    /* 0x08 */ GObj* obj;
} UIButtonListEntry; // size = 0xC

extern Sprite D_8037F2A8_852A58;
extern Bitmap* D_80380B50_854300[];
extern s32 D_80380BA8_854358[];
extern char D_80380BD4_854384[];
extern UIButtonListEntry D_80380BE0_854390;
extern UIButtonListEntry* D_80380BEC_85439C;

void UIButton_SetAnimationInterval(s32 btnName, f32 speed) {
    char* pos;

    pos = strchr(D_80380BD4_854384, (char) btnName);
    if (pos != NULL) {
        D_80380BA8_854358[pos - D_80380BD4_854384] = speed * 60.0;
        if (D_80380BA8_854358[pos - D_80380BD4_854384] < 1) {
            D_80380BA8_854358[pos - D_80380BD4_854384] = 1;
        }
    }
}

void UIButton_Update(GObj* obj) {
    s32 btnId = (s32) obj->userData;
    s32 i = 0;

    while (true) {
        i = !i;
        obj->data.sobj->sprite.bitmap = D_80380B50_854300[2 * btnId + i];
        ohWait(D_80380BA8_854358[btnId]);
    }
}

void* UIButton_Create(s32 posX, s32 posY, s32 btnName, s32 scale) {
    char* pos;
    UIButtonListEntry* entry;
    GObj* obj;

    pos = strchr(D_80380BD4_854384, (char) btnName);
    if (pos == NULL) {
        return NULL;
    }

    obj = func_800A9F10(UIButton_Update, LINK_6, &D_8037F2A8_852A58);
    obj->data.sobj->sprite.x = posX;
    obj->data.sobj->sprite.y = posY;
    obj->data.sobj->sprite.bitmap = D_80380B50_854300[2 * (pos - D_80380BD4_854384)];

    if (scale != 24) {
        obj->data.sobj->sprite.scalex = (f32) scale / 12.0;
        obj->data.sobj->sprite.scaley = (f32) scale / 12.0;
        obj->data.sobj->sprite.attr |= SP_SCALE;
    }

    obj->userData = (void*) (pos - D_80380BD4_854384);

    entry = (UIButtonListEntry*) func_8036A194_83D944(sizeof(UIButtonListEntry));
    entry->obj = obj;
    entry->prev = D_80380BEC_85439C->next->prev;
    D_80380BEC_85439C->next->prev = entry;
    entry->next = D_80380BEC_85439C->next;
    D_80380BEC_85439C->next = entry;

    return obj;
}

void UIButton_DeleteAll(void) {
    UIButtonListEntry* csr;

    for (csr = D_80380BEC_85439C->next; csr->obj != NULL; csr = csr->next) {
        omDeleteGObj(csr->obj);
        func_8036A228_83D9D8(csr);
    }

    D_80380BEC_85439C = &D_80380BE0_854390;
    D_80380BE0_854390.next = &D_80380BE0_854390;
    D_80380BE0_854390.prev = &D_80380BE0_854390;
    D_80380BE0_854390.obj = NULL;
}

void UIButton_DeleteInRect(s32 minX, s32 minY, s32 maxX, s32 maxY) {
    UIButtonListEntry* csr;
    UIButtonListEntry* next;
    s32 x, y;

    for (csr = D_80380BEC_85439C->next; csr->obj != NULL; csr = next) {
        next = csr->next;
        x = csr->obj->data.sobj->sprite.x;
        y = csr->obj->data.sobj->sprite.y;

        if (x < minX || x > maxX | y < minY || y > maxY) { // BUG: | instead of ||
            continue;
        }

        omDeleteGObj(csr->obj);
        csr->prev->next = csr->next;
        csr->next->prev = csr->prev;
        func_8036A228_83D9D8(csr);
    }
}

void UIButton_SetState(s32 state) {
    UIButtonListEntry* csr;

    for (csr = D_80380BEC_85439C->next; csr->obj != NULL; csr = csr->next) {
        if (state) {
            csr->obj->data.sobj->sprite.attr |= SP_HIDDEN;
        } else {
            csr->obj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        }
    }
}

void UIButton_SetStateInsideRect(s32 state, s32 minX, s32 minY, s32 maxX, s32 maxY) {
    UIButtonListEntry* csr;
    s32 x, y;

    for (csr = D_80380BEC_85439C->next; csr->obj != NULL; csr = csr->next) {
        x = csr->obj->data.sobj->sprite.x;
        y = csr->obj->data.sobj->sprite.y;
        if (x < minX || x > maxX | y < minY || y > maxY) { // BUG: | instead of ||
            continue;
        }

        if (state) {
            csr->obj->data.sobj->sprite.attr |= SP_HIDDEN;
        } else {
            csr->obj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        }
    }
}
