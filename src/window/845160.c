#include "common.h"
#include "window.h"

void func_803719B0_845160(SObj* arg0, s32 x, s32 y, s32 r, s32 g, s32 b, s32 a) {
    s32 origX;
    s32 origY;
    u32 origR;
    u32 origG;
    u32 origB;
    u32 origA;

    while (arg0 != NULL) {
        if (!(arg0->sprite.attr & SP_HIDDEN)) {
            origX = arg0->sprite.x;
            origY = arg0->sprite.y;
            origR = arg0->sprite.red;
            origG = arg0->sprite.green;
            origB = arg0->sprite.blue;
            origA = arg0->sprite.alpha;
            arg0->sprite.rsp_dl_next = gMainGfxPos[0];
            arg0->sprite.x += x;
            arg0->sprite.y += y;
            if (!(arg0->sprite.attr & 0x4000)) {
                arg0->sprite.red = (arg0->sprite.red * r) / 255;
                arg0->sprite.green = (arg0->sprite.green * g) / 255;
                arg0->sprite.blue = (arg0->sprite.blue * b) / 255;
                arg0->sprite.alpha = (arg0->sprite.alpha * a) / 255;
            }
            func_80373670_846E20(&arg0->sprite);
            *gMainGfxPos = arg0->sprite.rsp_dl_next - 1;
            if (arg0->unk_58 != NULL) {
                func_803719B0_845160(
                    arg0->unk_58,
                    arg0->sprite.x, arg0->sprite.y,
                    arg0->sprite.red, arg0->sprite.green, arg0->sprite.blue, arg0->sprite.alpha);
            }
            arg0->sprite.x = origX;
            arg0->sprite.y = origY;
            arg0->sprite.red = origR;
            arg0->sprite.green = origG;
            arg0->sprite.blue = origB;
            arg0->sprite.alpha = origA;
        }
        arg0 = arg0->next;
    }
}

void func_80371C0C_8453BC(GObj* gobj) {
    func_803719B0_845160(gobj->data.sobj, 0, 0, 255, 255, 255, 255);
    func_80371F30_8456E0(0, SCREEN_WIDTH * 2 - 1, 0, SCREEN_HEIGHT * 2 - 1);
}

GObj* func_80371C68_845418(void (*func)(GObj*), s32 link, Sprite* sprite) {
    GObj* obj;

    obj = omAddGObj(1 << link, 0, link, link);
    if (obj == NULL) {
        return NULL;
    }
    omLinkGObjDL(obj, func_80371C0C_8453BC, 30, link, 0x40000000);
    omGObjAddSprite(obj, sprite);
    obj->data.sobj->unk_58 = NULL;
    obj->data.sobj->unk_5C = NULL;
    if (func != NULL) {
        omCreateProcess(obj, func, 1, 0);
    }
    return obj;
}

GObj* func_80371D14_8454C4(void (*func)(GObj*), s32 link, Sprite* sprite) {
    GObj* obj;

    obj = omAddGObj(1 << link, 0, link, link);
    if (obj == NULL) {
        return NULL;
    }
    omLinkGObjDL(obj, func_80371C0C_8453BC, 30, link, 0x40000000);
    omGObjAddSprite(obj, sprite);
    obj->data.sobj->unk_58 = NULL;
    obj->data.sobj->unk_5C = NULL;
    if (func != NULL) {
        omCreateProcess(obj, func, 0, 0);
    }
    return obj;
}

SObj* func_80371DC0_845570(SObj* arg0, Sprite* arg1) {
    SObj* temp_v0;

    temp_v0 = omGetSObj();
    if (arg0->next != NULL) {
        arg0->next->prev = temp_v0;
    }
    temp_v0->prev = arg0;
    temp_v0->next = arg0->next;
    arg0->next = temp_v0;
    temp_v0->obj = arg0->obj;
    temp_v0->unk_5C = arg0->unk_5C;
    temp_v0->unk_58 = NULL;
    temp_v0->sprite = *arg1;
    temp_v0->unk_54 = 0;
    return temp_v0;
}

SObj* func_80371E68_845618(SObj* arg0, Sprite* arg1) {
    SObj* temp_v0;
    SObj* var_a0;
    SObj* var_v1;

    temp_v0 = omGetSObj();
    if (arg0->unk_58 != NULL) {
        var_a0 = arg0->unk_58;
        var_v1 = arg0->unk_58->next;
        while (var_v1 != NULL) {
            var_a0 = var_v1;
            var_v1 = var_v1->next;
        }
        var_a0->next = temp_v0;
        temp_v0->prev = var_a0;
    } else {
        arg0->unk_58 = temp_v0;
        temp_v0->prev = NULL;
    }
    temp_v0->obj = arg0->obj;
    temp_v0->unk_5C = arg0;
    temp_v0->unk_58 = NULL;
    temp_v0->next = NULL;
    temp_v0->sprite = *arg1;
    temp_v0->unk_54 = 0;
    return temp_v0;
}
