#include "common.h"
#include "window.h"
#include "string.h"

typedef struct UIButtonImageListEntry {
    /* 0x00 */ struct UIButtonImageListEntry* next;
    /* 0x04 */ struct UIButtonImageListEntry* prev;
    /* 0x08 */ GObj* obj;
} UIButtonImageListEntry; // size = 0xC

extern Sprite D_8037F2A8_852A58;
extern Bitmap* D_80380B50_854300[];
extern s32 D_80380BA8_854358[];
extern char D_80380BD4_854384[];
extern UIButtonImageListEntry D_80380BE0_854390;
extern UIButtonImageListEntry* D_80380BEC_85439C;

void UIButtonImage_SetAnimationInterval(s32 btnName, f32 speed) {
    char* pos;

    pos = strchr(D_80380BD4_854384, (char) btnName);
    if (pos != NULL) {
        D_80380BA8_854358[pos - D_80380BD4_854384] = speed * 60.0;
        if (D_80380BA8_854358[pos - D_80380BD4_854384] < 1) {
            D_80380BA8_854358[pos - D_80380BD4_854384] = 1;
        }
    }
}

void UIButtonImage_Update(GObj* obj) {
    s32 btnId = (s32) obj->userData;
    s32 i = 0;

    while (true) {
        i = !i;
        obj->data.sobj->sprite.bitmap = D_80380B50_854300[2 * btnId + i];
        ohWait(D_80380BA8_854358[btnId]);
    }
}

void* UIButtonImage_Create(s32 posX, s32 posY, s32 btnName, s32 scale) {
    char* pos;
    UIButtonImageListEntry* entry;
    GObj* obj;

    pos = strchr(D_80380BD4_854384, (char) btnName);
    if (pos == NULL) {
        return NULL;
    }

    obj = func_800A9F10(UIButtonImage_Update, LINK_6, &D_8037F2A8_852A58);
    obj->data.sobj->sprite.x = posX;
    obj->data.sobj->sprite.y = posY;
    obj->data.sobj->sprite.bitmap = D_80380B50_854300[2 * (pos - D_80380BD4_854384)];

    if (scale != 24) {
        obj->data.sobj->sprite.scalex = (f32) scale / 12.0;
        obj->data.sobj->sprite.scaley = (f32) scale / 12.0;
        obj->data.sobj->sprite.attr |= SP_SCALE;
    }

    obj->userData = (void*) (pos - D_80380BD4_854384);

    entry = (UIButtonImageListEntry*) UIMem_Allocate(sizeof(UIButtonImageListEntry));
    entry->obj = obj;
    entry->prev = D_80380BEC_85439C->next->prev;
    D_80380BEC_85439C->next->prev = entry;
    entry->next = D_80380BEC_85439C->next;
    D_80380BEC_85439C->next = entry;

    return obj;
}

void UIButtonImage_DeleteAll(void) {
    UIButtonImageListEntry* csr;

    for (csr = D_80380BEC_85439C->next; csr->obj != NULL; csr = csr->next) {
        omDeleteGObj(csr->obj);
        UIMem_Deallocate(csr);
    }

    D_80380BEC_85439C = &D_80380BE0_854390;
    D_80380BE0_854390.next = &D_80380BE0_854390;
    D_80380BE0_854390.prev = &D_80380BE0_854390;
    D_80380BE0_854390.obj = NULL;
}

void UIButtonImage_DeleteInRect(s32 minX, s32 minY, s32 maxX, s32 maxY) {
    UIButtonImageListEntry* csr;
    UIButtonImageListEntry* next;
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
        UIMem_Deallocate(csr);
    }
}

void UIButtonImage_SetState(s32 state) {
    UIButtonImageListEntry* csr;

    for (csr = D_80380BEC_85439C->next; csr->obj != NULL; csr = csr->next) {
        if (state) {
            csr->obj->data.sobj->sprite.attr |= SP_HIDDEN;
        } else {
            csr->obj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        }
    }
}

void UIButtonImage_SetStateInsideRect(s32 state, s32 minX, s32 minY, s32 maxX, s32 maxY) {
    UIButtonImageListEntry* csr;
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
