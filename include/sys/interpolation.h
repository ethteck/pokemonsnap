#ifndef SYS_INTERPOLATION_H
#define SYS_INTERPOLATION_H

#include <PR/ultratypes.h>
#include "types.h"

typedef struct InterpData {
    /* 0x00 */ u8 type;
    /* 0x01 */ char unk_01[0x1];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec3f* unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32* unk_10;
} InterpData; // size >= 0x10

enum HalInterpolationKind {
    HAL_INTERP_LINEAR,
    HAL_INTERP_BEZIER_S3,
    HAL_INTERP_BEZIER,
    HAL_INTERP_CATROM
};

void func_8001FCA4(Vec3f*, InterpData*, f32);
void func_8001FCE8(Vec3f*, InterpData*, f32);

#endif
