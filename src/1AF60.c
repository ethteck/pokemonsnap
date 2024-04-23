#include "common.h"

f32 func_8001A360(Vec3f* v) {
    f32 mag = sqrtf(SQ(v->x) + SQ(v->y) + SQ(v->z));
    if (mag == 0.0f) { return 0.0f; }

    v->x *= 1.0f / mag;
    v->y *= 1.0f / mag;
    v->z *= 1.0f / mag;

    return mag;
}

f32 func_8001A3FC(Vec3f* v) {
    return sqrtf(SQ(v->x) + SQ(v->y) + SQ(v->z));
}

Vec3f* func_8001A43C(Vec3f* dst, Vec3f* addend) {
    dst->x += addend->x;
    dst->y += addend->y;
    dst->z += addend->z;

    return dst;
}

Vec3f* func_8001A474(Vec3f* dst, Vec3f* subtrahend) {
    dst->x -= subtrahend->x;
    dst->y -= subtrahend->y;
    dst->z -= subtrahend->z;

    return dst;
}

Vec3f* func_8001A4AC(Vec3f* difference, Vec3f* minuend, Vec3f* subtrahend) {
    difference->x = minuend->x - subtrahend->x;
    difference->y = minuend->y - subtrahend->y;
    difference->z = minuend->z - subtrahend->z;

    return difference;
}

void func_8001A4E4(Vec3f* difference, Vec3f* minuend, Vec3f* subtrahend) {
    difference->x = minuend->x - subtrahend->x;
    difference->y = minuend->y - subtrahend->y;
    difference->z = minuend->z - subtrahend->z;

    func_8001A360(difference);
}

Vec3f* func_8001A530(Vec3f* v, f32 scale) {
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;

    return v;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001A564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001A5AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001A5F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001A67C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001A750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001A88C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001A8B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AA88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AD08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AD94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AEAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AF30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1AF60/func_8001AF80.s")
