#include "common.h"
#include "sys/mtx.h"

#define COMBINE_INTEGRAL(a, b) (((a)&0xffff0000) | (((b) >> 16)))
#define COMBINE_FRACTIONAL(a, b) (((a) << 16)) | ((b)&0xffff)

#define F_PI ((f32) M_PI) // M_PI is a double, we want it as a single float.
#define HALF_PI (F_PI / 2.0f)

extern u16 D_80040F50[0x7FF];
f32* Vec3f_func_8001A8B8(f32* arg0, f32* arg1, f32 arg2);

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

void hal_look_at(Mtx* m, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp) {
    Mtx4f matrix;

    hal_look_at_f(matrix, xEye, yEye, zEye, xAt, yAt, zAt, xUp, yUp, zUp);
    hal_mtx_f2l(matrix, m);
}

#ifdef NON_EQUIVALENT
#define SQ(x) ((x) * (x))
void hal_look_at_roll_f(Mtx4f mf, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 roll, f32 xUp, f32 yUp,
                       f32 zUp) {
    f32 root;
    Vec3f vec1;
    Vec3f vec2;
    Vec3f vec3;

    vec1.x = xAt - xEye;
    vec1.y = yAt - yEye;
    vec1.z = zAt - zEye;
    root = -1.0f / sqrtf(SQ(vec1.x) + SQ(vec1.y) + SQ(vec1.z));
    vec1.x *= root;
    vec1.y *= root;
    vec1.z *= root;
    vec2.x = (yUp * vec1.z) - (zUp * vec1.y);
    vec2.y = (zUp * vec1.x) - (xUp * vec1.z);
    vec2.z = (xUp * vec1.y) - (yUp * vec1.x);
    root = 1.0f / sqrtf(SQ(vec2.x) + SQ(vec2.y) + SQ(vec2.z));
    vec2.x *= root;
    vec2.y *= root;
    vec2.z *= root;
    Vec3f_func_8001A8B8(&vec2, &vec1, roll);
    vec3.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
    vec3.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
    vec3.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
    root = 1.0f / sqrtf(SQ(vec3.x) + SQ(vec3.y) + SQ(vec3.z));
    mf[0][0] = vec2.x;
    mf[1][0] = vec2.y;
    mf[2][0] = vec2.z;
    mf[3][0] = -((xEye * vec2.x) + (yEye * vec2.y) + (zEye * vec2.z));
    mf[0][1] = (vec3.x * root);
    mf[1][1] = (vec3.y * root);
    mf[2][1] = (vec3.z * root);
    mf[3][1] = -((xEye * (vec3.x * root)) + (yEye * (vec3.y * root)) + (zEye * (vec3.z * root)));
    mf[0][2] = vec1.x;
    mf[1][2] = vec1.y;
    mf[2][2] = vec1.z;
    mf[3][2] = -((xEye * vec1.x) + (yEye * vec1.y) + (zEye * vec1.z));
    mf[0][3] = 0.0f;
    mf[1][3] = 0.0f;
    mf[2][3] = 0.0f;
    mf[3][3] = 1.0f;
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
