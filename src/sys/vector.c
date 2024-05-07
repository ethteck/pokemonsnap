#include "common.h"

#define VEC_DOT(v, w) ((v->x * w->x) + (v->y * w->y) + (v->z * w->z))

f32 Vec3fNormalize(Vec3f* v) {
    f32 mag = sqrtf(SQ(v->x) + SQ(v->y) + SQ(v->z));
    if (mag == 0.0f) { return 0.0f; }

    v->x *= 1.0f / mag;
    v->y *= 1.0f / mag;
    v->z *= 1.0f / mag;

    return mag;
}

f32 Vec3fMagnitude(Vec3f* v) {
    return sqrtf(SQ(v->x) + SQ(v->y) + SQ(v->z));
}

Vec3f* Vec3fAdd(Vec3f* dst, Vec3f* addend) {
    dst->x += addend->x;
    dst->y += addend->y;
    dst->z += addend->z;

    return dst;
}

Vec3f* Vec3fSub(Vec3f* dst, Vec3f* subtrahend) {
    dst->x -= subtrahend->x;
    dst->y -= subtrahend->y;
    dst->z -= subtrahend->z;

    return dst;
}

Vec3f* Vec3fDiff(Vec3f* difference, Vec3f* minuend, Vec3f* subtrahend) {
    difference->x = minuend->x - subtrahend->x;
    difference->y = minuend->y - subtrahend->y;
    difference->z = minuend->z - subtrahend->z;

    return difference;
}

f32 Vec3fDirection(Vec3f* dir, Vec3f* to, Vec3f* from) {
    dir->x = to->x - from->x;
    dir->y = to->y - from->y;
    dir->z = to->z - from->z;

    return Vec3fNormalize(dir);
}

Vec3f* Vec3fScale(Vec3f* v, f32 scale) {
    v->x *= scale;
    v->y *= scale;
    v->z *= scale;

    return v;
}

Vec3f* Vec3fDivideScale(Vec3f* v, f32 invScale) {
    if (invScale != 0.0f) {
        v->x /= invScale;
        v->y /= invScale;
        v->z /= invScale;
    }

    return v;
}

Vec3f* Vec3fAddScaled(Vec3f* dst, Vec3f* addend, f32 scale) {
    dst->x += (addend->x * scale);
    dst->y += (addend->y * scale);
    dst->z += (addend->z * scale);

    return dst;
}

void Vec3fScaledAddScaledNormalize(Vec3f* dst, f32 dstScale, Vec3f* addend, f32 addendScale) {
    dst->x *= dstScale;
    dst->y *= dstScale;
    dst->z *= dstScale;
    dst->x += (addend->x * addendScale);
    dst->y += (addend->y * addendScale);
    dst->z += (addend->z * addendScale);

    Vec3fNormalize(dst);
}

f32 Vec3fAngleDiff(Vec3f* v1, Vec3f* v2) {
    f32 magProd = Vec3fMagnitude(v1) * Vec3fMagnitude(v2);

    if (magProd != 0.0f) {
        f32 cosDiff = VEC_DOT(v1, v2) / magProd;
        // limit result to -1 < x < 1
        if (1.0f < cosDiff) { cosDiff = 1.0f; }
        if (cosDiff < -1.0f) { cosDiff = -1.0f; }
        return acosf(cosDiff);
    }

    // at least one of the vectors is a zero vector
    return 0.0f;
}

Vec3f* Vec3fGetEulerRotation(Vec3f* v, enum VectorAxisFlags axis, f32 angle) {
    f32 xResult, yResult, zResult;
    f32 sinAngle = sinf(angle);
    f32 cosAngle = cosf(angle);

    switch (axis) {
        case AXIS_X:
            xResult = v->x;
            yResult = (v->y * cosAngle) - (v->z * sinAngle);
            zResult = (v->y * sinAngle) + (v->z * cosAngle);
            break;
        case AXIS_Y:
            xResult = (v->x * cosAngle) + (v->z * sinAngle);
            yResult = v->y;
            zResult = (v->z * cosAngle) - (v->x * sinAngle);
            break;
        case AXIS_Z:
            xResult = (v->x * cosAngle) - (v->y * sinAngle);
            yResult = (v->x * sinAngle) + (v->y * cosAngle);
            zResult = v->z;
            break;
    }
    v->x = xResult;
    v->y = yResult;
    v->z = zResult;
    return v;
}

Vec3f* Vec3fNegate(Vec3f* v) {
    v->x = -v->x;
    v->y = -v->y;
    v->z = -v->z;

    return v;
}

#ifdef NON_MATCHING
Vec3f* Vec3f_func_8001A8B8(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    f32 sp3C;
    f32 sp38; // only set when sp3C != 0
    f32 sp34; // only set when sp3C != 0
    f32 sp30; // cosX
    f32 sp2C; // sinX
    f32 phiF18;
    f32 phiF20;
    f32 resX, resY, resZ;

    sp3C = sqrtf(SQUARE(arg1->y) + SQUARE(arg1->z));
    sp2C = sinf(arg2);
    sp30 = cosf(arg2);

    if (sp3C != 0.0f) {
        sp34 = arg1->y / sp3C;
        sp38 = arg1->z / sp3C;

        phiF20 = (arg0->y * sp38) - (arg0->z * sp34);
        phiF18 = (arg0->y * sp34) + (arg0->z * sp38);
    } else {
        phiF20 = arg0->y;
        phiF18 = arg0->z;
    }
    // L800194F8
    resX = (((((arg0->x * sp3C) - (phiF18 * arg1->x)) * sp30) - (phiF20 * sp2C)) * sp3C)
         + (((arg1->x * arg0->x) + (phiF18 * sp3C)) * arg1->x);
    resY = (((arg0->x * sp3C) - (phiF18 * arg1->x)) * sp2C) + (phiF20 * sp30);
    resZ = (-((((arg0->x * sp3C) - (phiF18 * arg1->x)) * sp30) - (phiF20 * sp2C)) * arg1->x)
         + (((arg1->x * arg0->x) + (phiF18 * sp3C)) * sp3C);

    if (sp3C != 0.0f) {
        arg0->x = resX;
        arg0->y = phiF20 * sp38 + resY * sp34;
        arg0->z = -phiF20 * sp34 + resZ * sp38;
    } else {
        arg0->x = resX;
        arg0->y = resY;
        arg0->z = resZ;
    }

    return arg0;
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/sys/vector/Vec3f_func_8001A8B8.s")
#endif

Vec3f* Vec3fNegateByAxis(Vec3f* v, enum VectorAxisFlags flag) {
    if (flag & AXIS_X) { v->x = -v->x; }
    if (flag & AXIS_Y) { v->y = -v->y; }
    if (flag & AXIS_Z) { v->z = -v->z; }
    return v;
}

Vec3f* Vec3f_func_8001AA88(Vec3f* v, u32 flags) {
    do {
        if (flags & 0x40) {
            if ((flags & 1) && (v->x < 0.0f)) {
                v->x = -v->x;
            } else if ((flags & 8) && (v->x > 0.0f)) {
                v->x = -v->x;
            }
            if ((flags & 2) && (v->y < 0.0f)) {
                v->y = -v->y;
            } else if ((flags & 0x10) && (0.0f < v->y)) {
                v->y = -v->y;
            }
            if ((flags & 4) && (v->z < 0.0f)) {
                v->z = -v->z;
                break;
            }
            if (flags & 0x20) {
                if (0.0f < v->z) {
                    v->z = -v->z;
                    break;
                }
            }
        } else {
            if ((flags & 1) && (0.0f < v->x)) {
                v->x = -v->x;
            } else if (flags & 8) {
                if (v->x < 0.0f) { v->x = -v->x; }
            }
            if ((flags & 2) && (0.0f < v->y)) {
                v->y = -v->y;
            } else if (flags & 0x10) {
                if (v->y < 0.0f) { v->y = -v->y; }
            }
            if (flags & 4) {
                if (0.0f < v->z) {
                    v->z = -v->z;
                    break;
                }
            }
            if ((flags & 0x20) && (v->z < 0.0f)) { v->z = -v->z; }
        }
    } while (FALSE);

    // do while (0)... macro?

    return v;
}

Vec3f* Vec3f_func_8001AC98(Vec3f* v1, Vec3f* v2) {
    f32 dot;

    dot = VEC_DOT(v2, v1) * -2.0f;
    v1->x += (v2->x * dot);
    v1->y += (v2->y * dot);
    v1->z += (v2->z * dot);
    return v1;
}

Vec3f* Vec3f_func_8001AD08(Vec3f* v1, Vec3f* v2) {
    f32 dot;

    dot = VEC_DOT(v2, v1);
    if (dot < 0.0f) {
        dot *= -2.0f;
        v1->x += (v2->x * dot);
        v1->y += (v2->y * dot);
        v1->z += (v2->z * dot);
    }
    return v1;
}

s32 Vec3fCompareDirection(Vec3f* v1, Vec3f* v2) {
    f32 dot;

    dot = VEC_DOT(v2, v1);
    if (dot != 0.0f) {
        return (dot < 0.0f ? -1 : 1);
    } else {
        return 0;
    }
}


Vec3f* Vec3fNormalizedCross(Vec3f *v0, Vec3f *v1, Vec3f *result) {
    result->x = (v0->y * v1->z) - (v0->z * v1->y);
    result->y = (v0->z * v1->x) - (v0->x * v1->z);
    result->z = (v0->x * v1->y) - (v0->y * v1->x);

    return (Vec3fNormalize(result) != 0.0f) ? result : NULL;
}

// Subtracts v0 from v2, and runs the same check as Vec3fCompareDirection on the result and v1
s32 Vec3fSubtractCompareDirection(Vec3f* v0, Vec3f* v1, Vec3f* v2) {
    f32 dot;

    dot = (v1->x * (v2->x - v0->x)) + (v1->y * (v2->y - v0->y)) + (v1->z * (v2->z - v0->z));
    if (dot != 0.0f) {
        return (dot < 0.0f ? -1 : 1);
    } else {
        return 0;
    }
}

f32 Vec3fDistance(Vec3f* v0, Vec3f* v1) {
    struct Vec3f result;

    result.x = v1->x - v0->x;
    result.y = v1->y - v0->y;
    result.z = v1->z - v0->z;

    return Vec3fMagnitude(&result);
}

// Takes the cross product of (arg1 - arg0) and (arg2 - arg0), then
// does the difference of cross dot arg3 and cross dot arg0, then
// takes the absolute value of that difference and divides by the magnitude of the cross product
f32 Vec3f_func_8001AF80(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3) {
    f32 dz1;
    f32 dy1;
    f32 dx1;
    f32 dz2;
    f32 dy2;
    f32 dx2;
    f32 crossx;
    f32 crossy;
    f32 crossz;
    f32 crossdotarg0_neg;
    f32 numerator;

    dx1 = (arg1->x - arg0->x);
    dy1 = (arg1->y - arg0->y);
    dz1 = (arg1->z - arg0->z);

    dx2 = (arg2->x - arg0->x);
    dy2 = (arg2->y - arg0->y);
    dz2 = (arg2->z - arg0->z);

    crossx = (dy1 * dz2) - (dz1 * dy2);
    crossy = (dz1 * dx2) - (dx1 * dz2);
    crossz = (dx1 * dy2) - (dy1 * dx2);

    crossdotarg0_neg = -((arg0->x * crossx) + (crossy * arg0->y) + (crossz * arg0->z));
    numerator =
        ABS(((arg3->x * crossx) + (crossy * arg3->y) + (crossz * arg3->z)) + crossdotarg0_neg);

    return numerator / sqrtf((crossx * crossx) + (crossy * crossy) + (crossz * crossz));
}
