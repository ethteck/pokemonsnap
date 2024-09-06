#include "common.h"
#include "sp.h"
#include "unk_end_level.h"

extern s32 D_803A6604_879DB4;
extern s32 D_803A660C_879DBC;
extern s32 D_803A6614_879DC4;
extern s32 D_803A6648_879DF8; // xmin
extern s32 D_803A664C_879DFC; // ymin
extern s32 D_803A6650_879E00; // xmax
extern s32 D_803A6654_879E04; // ymax

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370560_843D10.s")

void func_80370578_843D28(void) {
    if (D_803A6614_879DC4 != 0) {
        D_803A6614_879DC4 = 0;
    } else {
        D_803A6614_879DC4 = 3;
    }
}

void func_803705A4_843D54(void) {
    while (D_803A6604_879DB4 != 2) {
        ohWait(1);
    }
}

void func_803705F0_843DA0(s32 arg0) {
    D_803A660C_879DBC = arg0 != 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370600_843DB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_8037060C_843DBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370780_843F30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370900_8440B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370990_844140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370A14_8441C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370A48_8441F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370C34_8443E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80370F34_8446E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_803713C8_844B78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_803713D4_844B84.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_803713EC_844B9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80371408_844BB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_8037147C_844C2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_8037154C_844CFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_8037161C_844DCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_8037172C_844EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80371738_844EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_803717A8_844F58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_803717E8_844F98.s")

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
    func_803719B0_845160(gobj->data.sobj, 0, 0, 0xFF, 0xFF, 0xFF, 0xFF);
    func_80371F30_8456E0(0, SCREEN_WIDTH * 2 - 1, 0, SCREEN_HEIGHT * 2 - 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80371C68_845418.s")

/*
GObj* func_80371D14_8454C4(void (*gfxFunc)(GObj*), s32 arg1, Sprite* sprite) {
    GObj* gobj = omAddGObj(1 << arg1, 0, arg1 & 0xFF, arg1);

    if (gobj == NULL) {
        return NULL;
    }
    omLinkGObjDL(gobj, func_80371C0C_8453BC, 0x1E, arg1, 0x40000000);
    omGObjAddSprite(gobj, sprite);
    gobj->userData.rootNode->payloads[0] = NULL;
    gobj->userData.rootNode->payloads[1] = NULL;
    if (gfxFunc != NULL) {
        omCreateProcess(gobj, gfxFunc, 0, 0);
    }
    return gobj;
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80371D14_8454C4.s")

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
        var_v1 = arg0->unk_58->next;
        var_a0 = arg0->unk_58;
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

void func_80371F30_8456E0(s32 xMin, s32 xMax, s32 yMin, s32 yMax) {
    D_803A6648_879DF8 = xMin;
    D_803A664C_879DFC = yMin;
    D_803A6650_879E00 = xMax;
    D_803A6654_879E04 = yMax;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/843D10/func_80371F54_845704.s")
