#include "common.h"
#include "sys/mtx.h"

#define COMBINE_INTEGRAL(a, b) (((a)&0xffff0000) | (((b) >> 16)))
#define COMBINE_FRACTIONAL(a, b) (((a) << 16)) | ((b)&0xffff)

#define F_PI ((f32) M_PI) // M_PI is a double, we want it as a single float.
#define HALF_PI (F_PI / 2.0f)

extern u16 D_80040F50[0x7FF];
f32* func_8001A8B8(f32* arg0, f32* arg1, f32 arg2);

void hal_mtx_f2l(Mtx4f src, Mtx* dst) {
    u32 e1, e2;

    e1 = FTOFIX32(src[0][0]);
    e2 = FTOFIX32(src[0][1]);
    dst->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][0] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[0][2]);
    e2 = FTOFIX32(src[0][3]);
    dst->m[0][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][1] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[1][0]);
    e2 = FTOFIX32(src[1][1]);
    dst->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][2] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[1][2]);
    e2 = FTOFIX32(src[1][3]);
    dst->m[0][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][3] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[2][0]);
    e2 = FTOFIX32(src[2][1]);
    dst->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][0] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[2][2]);
    e2 = FTOFIX32(src[2][3]);
    dst->m[1][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][1] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[3][0]);
    e2 = FTOFIX32(src[3][1]);
    dst->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][2] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32(src[3][2]);
    e2 = FTOFIX32(src[3][3]);
    dst->m[1][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][3] = COMBINE_FRACTIONAL(e1, e2);
}

// Same as above, but assumes column 3 is (0, 0, 0, 1)
void hal_mtx_f2l_fixed_w(Mtx4f src, Mtx *dst) {
    u32 e1, e2;

    e1           = FTOFIX32(src[0][0]);
    e2           = FTOFIX32(src[0][1]);
    dst->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][0] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32(src[0][2]);
    e2           = FTOFIX32(0.0f);
    dst->m[0][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][1] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32(src[1][0]);
    e2           = FTOFIX32(src[1][1]);
    dst->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][2] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32(src[1][2]);
    e2           = FTOFIX32(0.0f);
    dst->m[0][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][3] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32(src[2][0]);
    e2           = FTOFIX32(src[2][1]);
    dst->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][0] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32(src[2][2]);
    e2           = FTOFIX32(0.0f);
    dst->m[1][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][1] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32(src[3][0]);
    e2           = FTOFIX32(src[3][1]);
    dst->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][2] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32(src[3][2]);
    e2           = FTOFIX32(1.0f);
    dst->m[1][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][3] = COMBINE_FRACTIONAL(e1, e2);
}

s32 fast_sinf(f32 arg0) {
    s32 temp;
    s32 ret;

    temp = arg0 * 651.8986f;
    ret = D_80040F50[temp & 0x7FF];

    if (temp & 0x800) {
        return -ret;
    }

    return ret;
}

s32 fast_cosf(f32 arg0) {
    s32 temp;
    s32 ret;

    temp = (arg0 + HALF_PI) * 651.8986f;
    ret = D_80040F50[temp & 0x7FF];

    if (temp & 0x800) {
        return -ret;
    }

    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_f.s")

void hal_look_at(Mtx* arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8,
                   f32 arg9) {
    Mtx4f matrix;

    hal_look_at_f(matrix, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
    hal_mtx_f2l(matrix, arg0);
}

#if NON_EQUIVALENT
#define SQ(x) ((x) * (x))
void hal_look_at_roll_f(Mtx4f arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9,
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
#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_roll_f.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_roll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_reflect_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_reflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_reflect_roll_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_reflect_roll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_ortho_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_ortho.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_perspective_fast_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_perspective_fast.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_perspective_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_perspective.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_scale_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_scale.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_scale_mul_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_translate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_translate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_translate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_translate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_translate_scale_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_translate_scale.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_translate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_translate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_translate_scale_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_translate_scale.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pyr_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pyr.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pyr_translate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pyr_translate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pyr_translate_scale_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pyr_translate_scale.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_py_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_py.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_py_translate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_py_translate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rp_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rp_translate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rp_translate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_yaw_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_yaw.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_yaw_translate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_yaw_translate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pitch_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pitch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pitch_translate_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_pitch_translate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_f_deg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_deg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_translate_f_deg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_translate_deg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_f_deg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_deg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_translate_f_deg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_rotate_rpy_translate_deg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001EA90.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/func_8001ECD0.s")
