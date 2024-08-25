#ifndef SYS_INTERPOLATION_H
#define SYS_INTERPOLATION_H

#include <PR/ultratypes.h>
#include "types.h"

typedef struct TripleVec {
    Vec3f data[3];
} TripleVec; // size = 0x18

typedef struct InterpData {
    /* 0x00 */ u8 type;
    /* 0x01 */ char unk_01[0x1];
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ Vec3f* unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32* unk_10;
} InterpData; // size >= 0x10

void func_8001FCA4(Vec3f*, InterpData*, f32);
void func_8001FCE8(Vec3f*, InterpData*, f32);

#endif
