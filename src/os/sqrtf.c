#include "ultra64.h"

#pragma intrinsic(sqrtf)
#define __builtin_sqrtf sqrtf

f32 sqrtf(f32 f) {
    return __builtin_sqrtf(f);
}
