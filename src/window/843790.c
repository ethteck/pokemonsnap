#include "common.h"

extern GObj* D_803A6A50_87A200[4];
extern f32 D_803A6A60_87A210[8];

void func_8036FFE0_843790(s32 arg0, s32 arg1) {
    D_803A6A60_87A210[2] = arg0;
    D_803A6A60_87A210[3] = arg1;
}

void func_80370004_8437B4(s32 arg0, s32 arg1) {
    D_803A6A60_87A210[2] = arg0;
    D_803A6A60_87A210[0] = D_803A6A60_87A210[2];
    D_803A6A60_87A210[3] = arg1;
    D_803A6A60_87A210[1] = D_803A6A60_87A210[3];
}

void func_80370038_8437E8(s32 arg0, s32 arg1) {
    D_803A6A60_87A210[6] = arg0;
    D_803A6A60_87A210[7] = arg1;
}

void func_8037005C_84380C(s32 arg0, s32 arg1) {
    D_803A6A60_87A210[6] = arg0;
    D_803A6A60_87A210[4] = D_803A6A60_87A210[6];
    D_803A6A60_87A210[7] = arg1;
    D_803A6A60_87A210[5] = D_803A6A60_87A210[7];
}

void func_80370090_843840(bool arg0) {
    D_803A6A50_87A200[0]->userData = (void*) !arg0;
}

void func_803700A4_843854(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803A6A50_87A200); i++) {
        if (arg0) {
            D_803A6A50_87A200[i]->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_803A6A50_87A200[i]->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_80370134_8438E4(void) {
    GObj* gobj;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_803A6A50_87A200); i++) {
        gobj = D_803A6A50_87A200[i];
        omMoveGObjDL(gobj, gobj->dlLink, gobj->dlPriority);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/843790/func_80370184_843934.s")

#pragma GLOBAL_ASM("asm/nonmatchings/window/843790/func_80370428_843BD8.s")
