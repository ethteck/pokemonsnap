#include "common.h"

extern s8 D_800BF051;
extern s8 sControllerIndices[MAXCONTROLLERS];

#pragma GLOBAL_ASM("asm/nonmatchings/574F0/func_800ABB40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/574F0/func_800ABB4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/574F0/func_800ABB68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/574F0/func_800ABB74.s")

void func_800ABB94(void) {
    if (sControllerIndices[0] == 0) {
        D_800BF051 = 0;
    } else {
        D_800BF051 = -1;
    }
}
