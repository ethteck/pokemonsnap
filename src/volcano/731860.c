#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/731860/func_802E0660_731860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/731860/func_802E0690_731890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/731860/func_802E06B0_7318B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/731860/func_802E0724_731924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/731860/func_802E081C_731A1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/volcano/731860/func_802E0948_731B48.s")

void func_802E0660_731860(GObj*);
void func_802E0948_731B48(GObj*);
extern GObj* D_802E3804_734A04;

void func_802E0C28_731E28(void) {
    GObj* obj;

    obj = func_80365E80_506290();
    D_802E3804_734A04 = obj;
    if (obj != NULL) {
        omCreateProcess(obj, func_802E0948_731B48, 0, 1);
        func_802E0660_731860(obj);
    }
}
