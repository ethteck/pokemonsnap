#ifndef SYS_VECTOR_H
#define SYS_VECTOR_H

enum VectorAxisFlags {
    AXIS_X = 1 << 0,
    AXIS_Y = 1 << 1,
    AXIS_Z = 1 << 2
};

f32 Vec3fNormalize(Vec3f* v);
Vec3f* Vec3fAdd(Vec3f* dst, Vec3f* addend);
Vec3f* Vec3fSub(Vec3f* dst, Vec3f* subtrahend);
Vec3f* Vec3fDiff(Vec3f* difference, Vec3f* minuend, Vec3f* subtrahend);
f32 Vec3fDirection(Vec3f* dir, Vec3f* to, Vec3f* from);
Vec3f* Vec3fScale(Vec3f* v, f32 scale);
Vec3f* Vec3fAddScaled(Vec3f* dst, Vec3f* addend, f32 scale);
f32 Vec3fAngleDiff(Vec3f* v1, Vec3f* v2);
Vec3f* Vec3fGetEulerRotation(Vec3f* v, enum VectorAxisFlags axis, f32 angle);
Vec3f* Vec3f_func_8001A8B8(Vec3f* arg0, Vec3f* arg1, f32 arg2);
Vec3f* Vec3fReflect(Vec3f* v1, Vec3f* v2);
Vec3f* Vec3fNormalizedCross(Vec3f* v0, Vec3f* v1, Vec3f* result);
f32 Vec3fDistance(Vec3f* v0, Vec3f* v1);

#endif
