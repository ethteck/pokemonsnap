#include "common.h"

#define F_PI ((f32) M_PI) // M_PI is a double, we want it as a single float.
#define HALF_PI (F_PI / 2.0f)

extern u16 D_80040F50[0x7FF];
f32* func_8001A8B8(f32* arg0, f32* arg1, f32 arg2);
void func_8001B870(Mtx4f arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9,
                   f32 argA);

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001B0F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001B320.s")

s32 func_8001B4D4(f32 arg0) {
    s32 temp;
    s32 ret;

    temp = arg0 * 651.8986f;
    ret = D_80040F50[temp & 0x7FF];

    if (temp & 0x800) {
        return -ret;
    }

    return ret;
}

s32 func_8001B51C(f32 arg0) {
    s32 temp;
    s32 ret;

    temp = (arg0 + HALF_PI) * 651.8986f;
    ret = D_80040F50[temp & 0x7FF];

    if (temp & 0x800) {
        return -ret;
    }

    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001B570.s")

void func_8001B0F0(Mtx4f arg0, Mtx4f arg1);
void func_8001B570(Mtx4f arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                   f32 arg9);
void func_8001B7FC(Mtx4f arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                   f32 arg9) {
    Mtx4f matrix;

    func_8001B570(matrix, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    func_8001B0F0(matrix, arg0);
}

#if NON_EQUIVALENT
#define SQ(x) ((x) * (x))
void func_8001B870(Mtx4f arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9,
                   f32 argA) {
    f32 root;
    Vec3f vec1;
    Vec3f vec2;
    Vec3f vec3;

    vec1.x = arg4 - arg1;
    vec1.y = arg5 - arg2;
    vec1.z = arg6 - arg3;
    root = -1.0f / sqrtf(SQ(vec1.x) + SQ(vec1.y) + SQ(vec1.z));
    vec1.x *= root;
    vec1.y *= root;
    vec1.z *= root;
    vec2.x = (arg9 * vec1.z) - (argA * vec1.y);
    vec2.y = (argA * vec1.x) - (arg8 * vec1.z);
    vec2.z = (arg8 * vec1.y) - (arg9 * vec1.x);
    root = 1.0f / sqrtf(SQ(vec2.x) + SQ(vec2.y) + SQ(vec2.z));
    vec2.x *= root;
    vec2.y *= root;
    vec2.z *= root;
    func_8001A8B8(&vec2, &vec1, arg7);
    vec3.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
    vec3.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
    vec3.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
    root = 1.0f / sqrtf(SQ(vec3.x) + SQ(vec3.y) + SQ(vec3.z));
    arg0[0][0] = vec2.x;
    arg0[1][0] = vec2.y;
    arg0[2][0] = vec2.z;
    arg0[3][0] = -((arg1 * vec2.x) + (arg2 * vec2.y) + (arg3 * vec2.z));
    arg0[0][1] = (vec3.x * root);
    arg0[1][1] = (vec3.y * root);
    arg0[2][1] = (vec3.z * root);
    arg0[3][1] = -((arg1 * (vec3.x * root)) + (arg2 * (vec3.y * root)) + (arg3 * (vec3.z * root)));
    arg0[0][2] = vec1.x;
    arg0[1][2] = vec1.y;
    arg0[2][2] = vec1.z;
    arg0[3][2] = -((arg1 * vec1.x) + (arg2 * vec1.y) + (arg3 * vec1.z));
    arg0[0][3] = 0.0f;
    arg0[1][3] = 0.0f;
    arg0[2][3] = 0.0f;
    arg0[3][3] = 1.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001B870.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001BB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001BBC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001BFAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001C024.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001C450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001C4D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001C664.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001C6C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001C8F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001C94C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001CB14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001CB6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001CC00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001CCA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001CDA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001CE44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001CEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D078.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D0C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D184.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D1F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D26C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D3A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D69C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001D9A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001DA08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001DDFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001DF34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001DF78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001DFCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E08C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E20C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E2B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E3BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E40C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E4F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E574.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E650.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E688.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E6D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E720.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E774.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E7DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E844.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E8C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001E99C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001EA0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001EA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001ECD0.s")
