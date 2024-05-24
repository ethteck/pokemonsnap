#ifndef SYS_INTERPOLATION_H
#define SYS_INTERPOLATION_H

#include <PR/ultratypes.h>
#include "types.h"

typedef struct InterpData {
    /* 0x00 */ u8 type;
} InterpData; // size >= 1

void func_8001FCA4(Vec3f*, InterpData*, f32);

#endif
