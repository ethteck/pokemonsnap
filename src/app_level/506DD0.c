#include "common.h"

extern u16 D_80393BF0_534000[];

s32 func_803669C0_506DD0(f32 arg0, f32 arg1) {
    f32 f0, f2;
    s32 v1;

    f0 = ABS(arg1);
    f2 = ABS(arg0);

    if ((s32)f0 == 0 && (s32)f2 == 0) {
        return 0;
    }

    if (f0 >= f2) {
        if (f0 == 0.0f) {
            return 0;
        }

        v1 = D_80393BF0_534000[(s32)(f2 * 4096 / f0)];
        if (arg1 >= 0 && arg0 < 0) {
            v1 = -v1;
        } else if (arg1 < 0 && arg0 >= 0) {
            v1 = 0x4000 - v1;
        } else if (arg1 < 0 && arg0 < 0) {
            v1 = 0x4000 + v1;
        }
    } else {
        v1 = D_80393BF0_534000[(s32)(f0 * 4096 / f2)];
        if (arg0 >= 0 && arg1 >= 0) {
            v1 = 0x2000 - v1;
        } else if (arg0 >= 0 && arg1 < 0) {
            v1 = 0x2000 + v1;
        } else if (arg0 < 0 && arg1 >= 0) {
            v1 = 0x6000 + v1;
        } else {
            v1 = 0x6000 - v1;
        }
    }

    return v1 & 0x7FFF;
}
