#include "common.h"

#define F_PI ((f32) M_PI) // M_PI is a double, we want it as a single float.
#define HALF_PI (F_PI / 2.0f)

f32 func_80019994(f32);

extern s32 D_80040F40; //s32 D_80040F40 = 1;

f32 func_80019960(f32 arg0) {
    return __sinf(arg0) / __cosf(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_80019994.s")

f32 func_80019ABC(f32 arg0, f32 arg1) {
    f32 temp_f0;
    s32 var_v0;
    f32 var_f12;

    if (arg1 > 0.0f) {
        return func_80019994(arg0 / arg1);
    }
    if (arg1 < 0.0f) {
        var_v0 = (arg0 < 0.0f) ? -1 : 1;
        temp_f0 = arg0 / arg1;
        if (temp_f0 < 0.0f) {
            var_f12 = -temp_f0;
        } else {
            var_f12 = temp_f0;
        }
        return (F_PI - func_80019994(var_f12)) * var_v0;
    }
    if (arg0 != 0.0f) {
        var_v0 = (arg0 < 0.0f) ? -1 : 1;
        return var_v0 * HALF_PI;
    }
    return 0.0f;
}

f32 func_80019BBC(f32 arg0) {
    if (arg0 > 0.99999f) {
        return HALF_PI;
    }
    if (arg0 < -0.99999f) {
        return -HALF_PI;
    }
    return func_80019994(arg0 / sqrtf(1.0f - (arg0 * arg0)));
}

f32 func_80019C40(f32 arg0) {
    if (arg0 > 0.99999f) {
        return 0.0f;
    }
    if (arg0 < -0.99999f) {
        return F_PI;
    }
    return HALF_PI - func_80019994(arg0 / sqrtf(1.0f - (arg0 * arg0)));
}

f32 func_80019CD0(f32 arg0) {
    return 1.0f / __sinf(arg0);
}

f32 func_80019CF8(f32 arg0) {
    return 1.0f / __cosf(arg0);
}

f32 func_80019D20(f32 arg0) {
    return 1.0f / func_80019960(arg0);
}

void func_80019D48(s32 arg0) {
    D_80040F40 = arg0;
}

s32 func_80019D54(void) {
    return D_80040F40;
}

u16 func_80019D60(void) {
    // This seems a little ridiculous...
    return (D_80040F40 = (D_80040F40 * 0x343FD) + 0x269EC3) >> 16;
}

f32 func_80019DB0(void) {
    D_80040F40 = (D_80040F40 * 0x343FD) + 0x269EC3;
    return ((D_80040F40 >> 16) & 0xFFFF) / 65536.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_80019E14.s")

s32 func_80019E54(void) {
    return (osGetTime() & 0xFF);
}

f32 func_80019E78(void) {
    return (osGetTime() & 0xFF) * (1.0f / 256.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_80019EB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_80019F00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_80019F38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_8001A094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_8001A16C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_8001A29C.s")
