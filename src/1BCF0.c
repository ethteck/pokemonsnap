#include "common.h"

#define COMBINE_INTEGRAL(a, b) (((a)&0xffff0000) | (((b) >> 16)))
#define COMBINE_FRACTIONAL(a, b) (((a) << 16)) | ((b)&0xffff)

void hal_mtx_f2l(Mtx4f* src, Mtx* dst) {
    u32 e1, e2;

    e1 = FTOFIX32((*src)[0][0]);
    e2 = FTOFIX32((*src)[0][1]);
    dst->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][0] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32((*src)[0][2]);
    e2 = FTOFIX32((*src)[0][3]);
    dst->m[0][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][1] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32((*src)[1][0]);
    e2 = FTOFIX32((*src)[1][1]);
    dst->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][2] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32((*src)[1][2]);
    e2 = FTOFIX32((*src)[1][3]);
    dst->m[0][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][3] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32((*src)[2][0]);
    e2 = FTOFIX32((*src)[2][1]);
    dst->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][0] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32((*src)[2][2]);
    e2 = FTOFIX32((*src)[2][3]);
    dst->m[1][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][1] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32((*src)[3][0]);
    e2 = FTOFIX32((*src)[3][1]);
    dst->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][2] = COMBINE_FRACTIONAL(e1, e2);
    e1 = FTOFIX32((*src)[3][2]);
    e2 = FTOFIX32((*src)[3][3]);
    dst->m[1][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][3] = COMBINE_FRACTIONAL(e1, e2);
}

// Same as above, but assumes column 3 is (0, 0, 0, 1)
void hal_mtx_f2l_fixed_w(Mtx4f *src, Mtx *dst) {
    u32 e1, e2;

    e1           = FTOFIX32((*src)[0][0]);
    e2           = FTOFIX32((*src)[0][1]);
    dst->m[0][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][0] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32((*src)[0][2]);
    e2           = FTOFIX32(0.0f);
    dst->m[0][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][1] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32((*src)[1][0]);
    e2           = FTOFIX32((*src)[1][1]);
    dst->m[0][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][2] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32((*src)[1][2]);
    e2           = FTOFIX32(0.0f);
    dst->m[0][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[2][3] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32((*src)[2][0]);
    e2           = FTOFIX32((*src)[2][1]);
    dst->m[1][0] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][0] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32((*src)[2][2]);
    e2           = FTOFIX32(0.0f);
    dst->m[1][1] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][1] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32((*src)[3][0]);
    e2           = FTOFIX32((*src)[3][1]);
    dst->m[1][2] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][2] = COMBINE_FRACTIONAL(e1, e2);
    e1           = FTOFIX32((*src)[3][2]);
    e2           = FTOFIX32(1.0f);
    dst->m[1][3] = COMBINE_INTEGRAL(e1, e2);
    dst->m[3][3] = COMBINE_FRACTIONAL(e1, e2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/fast_sinf.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/fast_cosf.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_f.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1BCF0/hal_look_at_roll_f.s")

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
