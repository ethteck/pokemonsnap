#ifndef TYPES_H
#define TYPES_H

#include <PR/ultratypes.h>

typedef u32 uintptr_t;
typedef s32 intptr_t;

typedef struct Vec3i {
    s32 x, y, z;
} Vec3i;

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef f32 Mtx4f[4][4];

#endif
