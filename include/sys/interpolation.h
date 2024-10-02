#ifndef SYS_INTERPOLATION_H
#define SYS_INTERPOLATION_H

#include <PR/ultratypes.h>
#include "types.h"

typedef struct FittingParams {
    /* 0x00 */ f32 c[5];
} FittingParams; // size = 0x14

typedef struct InterpData {
    /* 0x00 */ u8 type;
    /* 0x02 */ s16 numPoints;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec3f* points;
    /* 0x0C */ f32 duration;
    /* 0x10 */ f32* paramPoints;
    /* 0x14 */ FittingParams* speedFunc;
} InterpData; // size >= 0x10

enum HalInterpolationKind {
    HAL_INTERP_LINEAR,
    HAL_INTERP_BEZIER_S3,
    HAL_INTERP_BEZIER,
    HAL_INTERP_CATROM
};

void GetInterpolatedPosition(Vec3f*, InterpData*, f32);
void GetInterpolatedVelocity(Vec3f*, InterpData*, f32);

#endif
