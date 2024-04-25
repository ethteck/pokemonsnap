#include "common.h"

f32 func_800E4860_62010(Vec3f* v1, Vec3f* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4890_62040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4904_620B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4970_62120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E49F4_621A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4B60_62310.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4BCC_6237C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4C64_62414.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4E98_62648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E4F40_626F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E5094_62844.s")

//#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E55C0_62D70.s")
s32 func_800E55C0_62D70(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, f32 arg3, void* arg4, Vec3f* arg5) {
    f32 f20;
    f32 sp60;
    f32 sp58;
    Vec3f sp40;

    arg5 = arg1;
    f20 = Vec3fNormalize(arg5);
    Vec3fDiff(&sp40, arg2, arg0);
    sp60 = func_800E4860_62010(&sp40, &sp40);
    sp58 = func_800E4860_62010(&sp40, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E57CC_62F7C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E5854_63004.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E5A4C_631FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E5AD4_63284.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E5D30_634E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E6168_63918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E61CC_6397C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E6238_639E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E66BC_63E6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E6778_63F28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/62010/func_800E67E4_63F94.s")
