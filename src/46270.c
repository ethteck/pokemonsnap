#include "common.h"
#include "os_cache.h"

extern s32 D_800ABBD0;
extern s32 D_800ABDEC;
extern s32 D_800AC00C;
extern s32 D_800B0578;

void func_8009A8C0(s32 arg0) {
    D_800B0578 = arg0;
}

s32 func_8009A8CC(void) {
    return D_800B0578;
}

void func_8009A8D8(s32 arg0) {
    D_800AC00C = arg0;
}

s32 func_8009A8E4(void) {
    return D_800AC00C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009A8F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009AE0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009B2BC.s")

// ordering of the 0
#ifdef NON_MATCHING
void func_8009B40C(void) {
    s32 var_s0 = 0;

    while (1) {
        func_80002B64(&D_800ABDEC);
        func_80002B64(&D_800ABBD0);
        if (func_801DD010(var_s0) != 0) {
            while (1);
        }
        var_s0++;
        if (var_s0 == 0x11) {
            while (1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009B40C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/46270/func_8009B49C.s")
