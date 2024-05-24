#ifndef SYS_INTERPOLATION_H
#define SYS_INTERPOLATION_H

#include <PR/ultratypes.h>
#include "types.h"

typedef struct InterpData {
    /* 0x00 */ u8 type;
    /* 0x01 */ char unk_01[11];
    /* 0x0C */ f32 unk_0C;
} InterpData; // size >= 0x10

void func_8001FCA4(Vec3f*, InterpData*, f32);
void func_8001FCE8(Vec3f*, InterpData*, f32);

#endif
