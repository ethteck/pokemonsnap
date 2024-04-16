#include "common.h"

void *memcpy(void *,const void *,size_t);

#define F_PI ((f32) M_PI) // M_PI is a double, we want it as a single float.
#define HALF_PI (F_PI / 2.0f)

f32 func_80019994(f32);

extern s32 D_80040F40; //s32 D_80040F40 = 1;

f32 func_80019960(f32 arg0) {
    return __sinf(arg0) / __cosf(arg0);
}

#if 0
#define pow(arg) (arg * arg)
f32 func_80019994(f32 arg0) {
    f32 temp_f0;
    f32 temp_f2;
    s32 var_v0;

    if (arg0 == 0.0f) {
        return 0.0f;
    }
    var_v0 = 1;
    if (arg0 > 1.0f) {
        arg0 = 1.0f / arg0;
    } else if (arg0 < -1.0f) {
        arg0 = 1.0f / arg0;
        var_v0 = 2;
    } else {        
        var_v0 = 0;
    }
    temp_f2 = arg0  * ((pow(arg0) / ((pow(arg0) / ((pow(arg0) / ((pow(arg0) / ((pow(arg0) / ((pow(arg0) / -0.108107f) + -44.5719f)) + -0.161908f)) + -(HALF_PI * 10.0f))) + -0.55557f)) + -3.0f)) + 1.0f);
    switch (var_v0) {
    default:
        return pow(arg0);
    case 0:
        return temp_f2;
    case 1:
        return HALF_PI - temp_f2;
    case 2:
        return -HALF_PI - temp_f2;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_80019994.s")
#endif

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
    // Required to be one line to match.
    D_80040F40 = (D_80040F40 * 0x343FD) + 0x269EC3; \
    return (D_80040F40 >> 16);
}

f32 func_80019DB0(void) {
    D_80040F40 = (D_80040F40 * 0x343FD) + 0x269EC3;
    return ((D_80040F40 >> 16) & 0xFFFF) / 65536.0f;
}

#if 0
s32 func_80019E14(s32 arg0) {
    u16 temp_lo;
    s32 var_at;

    temp_lo = func_80019D60() * arg0;
    if ((temp_lo) < 0) {
        var_at = temp_lo + 0xFFFF;
    } else {
        var_at = temp_lo;
    }
    return var_at >> 16;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_80019E14.s")
#endif

s32 func_80019E54(void) {
    return (osGetTime() & 0xFF);
}

f32 func_80019E78(void) {
    return (osGetTime() & 0xFF) * (1.0f / 256.0f);
}

s32 func_80019EB0(s32 arg0) {
    s32 time = osGetTime() & 0xFF;
    return (time * arg0 * (1.0f / 256.0f));
}

void func_80019F00(u8* arg0, u8* arg1, s32 arg2) {
    while (arg2--) {
        s32 temp = *arg0;
        *arg0++ = *arg1;
        *arg1++ = temp;
    }
}

#if 0
extern s32 D_80040F44;
extern s32 (*D_80040F48)(u32, u32);

void func_80019F38(u32 arg0, s32 arg1) {
    s32 temp_a2;
    s32 var_s1;

    var_s1 = arg1 + D_80040F44;
    while (arg0 < arg1) {
loop_2:
        do {
            arg0 += D_80040F44;
        } while (arg0 < arg1 && D_80040F48(arg0, arg0) <= 0);

        do {
            var_s1 -= D_80040F44;
        } while (arg0 < var_s1 && D_80040F48(var_s1, arg0) >= 0);

        if (arg0 < var_s1) {
            func_80019F00((u8* ) arg0, (u8* ) var_s1, D_80040F44);
            goto loop_2;
        }
        func_80019F00((u8* ) arg0, (u8* ) var_s1, D_80040F44);
        if ((var_s1 - (s32) arg0) >= (arg1 - var_s1)) {
            func_80019F38(var_s1 + D_80040F44, arg1);
            arg1 = var_s1 - D_80040F44;
        } else {
            func_80019F38(arg0, var_s1 - D_80040F44);
            arg0 = var_s1 + D_80040F44;
            var_s1 = arg1 + D_80040F44;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_80019F38.s")
#endif

extern s32 D_80040F44;
extern s32 (*D_80040F48)(u32, u32);
void func_80019F38(u32 arg0, s32 arg1);

void func_8001A094(u32 arg0, s32 arg1, s32 arg2, s32 (*arg3)(u32, u32)) {
    s32 temp;
    s32 temp_v1;
    s32 var_s1;
    s32 found;
    
    temp_v1 = arg1 - 1U;
    temp = arg0;
    var_s1 = temp + arg2;
    found = FALSE;
    if (arg1 != 0) {
        while (temp_v1--) {
            if (arg3(temp, var_s1) > 0) {
                found = TRUE;
                break;
            }
            temp = var_s1;
            var_s1 += arg2;
        }
    }
    if (found) {
        D_80040F44 = arg2;
        D_80040F48 = arg3;
        func_80019F38(arg0, ((arg1 - 1) * D_80040F44) + arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/1A560/func_8001A16C.s")

s32 func_8001A29C(u32 arg0, u32 arg1, u32* arg2, u32 arg3, s32 (*arg4)(u32, u32)) {
    s32 var_s0;

    for (var_s0 = 0; *arg2 > var_s0; var_s0++) {
        if (arg4(arg0, arg1) == 0) {
            return arg1;
        }
        arg1 += arg3;        
    }
    memcpy((u8 *) arg0, (u8 *) arg1, arg3);
    *arg2 += 1;
    return arg1;
}
