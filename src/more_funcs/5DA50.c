#include "common.h"

extern UNK_TYPE D_800E17C0_7E660;

void func_800C0BB0_5DA50(void*);
#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5DA50/func_800C0BB0_5DA50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5DA50/func_800C0C10_5DAB0.s")

void func_800C14C8_5E368(void*, uintptr_t, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5DA50/func_800C14C8_5E368.s")

uintptr_t func_800C16EC_5E58C(uintptr_t arg0, s32 arg1) {
    s32 var_s1;
    u32 var_v0;
    uintptr_t var_s0;

    func_800C0BB0_5DA50(&D_800E17C0_7E660);
    var_v0 = 0;
    if (arg1 >= 0x40) {
        var_s0 = arg0;
        var_s1 = 0x40;
        do {
            func_800C14C8_5E368(&D_800E17C0_7E660, var_s0, 0x200);
            var_v0 = var_s1;
            var_s1 += 0x40;
            var_s0 += 0x40;
        } while (arg1 >= var_s1);
        // required to match
        if (!var_s1 && !var_s1 && !var_s1) {
        }
    }
    func_800C14C8_5E368(&D_800E17C0_7E660, (arg0 + var_v0), (arg1 - var_v0) * 8);
    return (uintptr_t) &D_800E17C0_7E660;
}
