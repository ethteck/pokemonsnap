#include "common.h"

extern GObj* D_803A6A50_87A200[4];

#pragma GLOBAL_ASM("asm/nonmatchings/window/843790/func_8036FFE0_843790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/window/843790/func_80370004_8437B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/window/843790/func_80370038_8437E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/window/843790/func_8037005C_84380C.s")

void func_80370090_843840(bool arg0) {
    D_803A6A50_87A200[0]->userData = (void*) !arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/843790/func_803700A4_843854.s")

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
