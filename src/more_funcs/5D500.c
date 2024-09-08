#include "common.h"
#include "more_funcs.h"

extern OSPiHandle* D_800E16F0_7E590;
extern uintptr_t D_800E1700_7E5A0;
extern s64 D_800E1708_7E5A8[];
extern s32 D_800E1798_7E638;
extern s32 D_800E179C_7E63C;
extern void* D_800E17A0_7E640;
extern OSMesgQueue D_800E17A8_7E648;

void func_800C0660_5D500(s32* arg0, s32* arg1) {
    if (arg0 != NULL) {
        *arg0 = D_800E1798_7E638;
    }
    if (arg1 != NULL) {
        *arg1 = D_800E179C_7E63C;
    }
}

void func_800C0688_5D528(void) {
    func_800C1BBC_5EA5C();
}

s32 func_800C06A8_5D548(uintptr_t arg0, s32 size) {
    char sp44[0x1C];
    UNUSED s32 pad;
    s32 i;

    if (size >= 0x20000) {
        size = 0x20000;
    }
    if (size <= 0 || size > 0x20000) {
        return -1;
    }
    i = 0;
    osGetTime();
    while (size > 0) {
        osInvalDCache((void*) arg0, 0x80);
        func_800C1FD4_5EE74(&sp44, 0, i, arg0, 1, &D_800E17A8_7E648);
        osRecvMesg(&D_800E17A8_7E648, NULL, 1);
        i += 1;
        if (i >= PokemonID_1022) {
            break;
        }
        arg0 += 0x80;
        size -= 0x80;
    }
    osGetTime();
}

// crazy usage of temps required to match
s32 func_800C0790_5D630(uintptr_t arg0, s32 arg1) {
    u32 var_v0;
    u32 temp_v1;
    u8 temp_t8;
    char sp30[0x0C];
    s32 new_var;

    new_var = D_800E1700_7E5A0;
    osInvalDCache((void*) new_var, 0x80);
    func_800C1FD4_5EE74(&sp30, 0, arg1, D_800E1700_7E5A0, 1, &D_800E17A8_7E648);
    osRecvMesg(&D_800E17A8_7E648, NULL, 1);
    new_var = D_800E1700_7E5A0;
    var_v0 = new_var;
    temp_v1 = var_v0 + 0x80;
    while (var_v0 < temp_v1) {
        new_var = *((u8*) (var_v0++));
        temp_t8 = new_var;
        if (temp_t8 != (*((u8*) arg0))) {
            return 1;
        }
        arg0++;
    }

    return 0;
}

bool func_800C0848_5D6E8(uintptr_t arg0, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 0; i != 0x80; i++) {
        if (arg2 < 0) {
            return false;
        }
        if (arg1 >= PokemonID_1022) {
            break;
        }
        if (func_800C0790_5D630(arg0, arg1)) {
            return true;
        }

        arg0 += 0x80;
        arg2 -= 0x80;
        arg1++;
    }

    return false;
}

s32 func_800C08DC_5D77C(s32 arg0, s32 arg1, s32 arg2) {
    char sp40[0x18];
    s32 var_s0;

    if (func_800C1CD8_5EB78(arg1) != 0) {
        return 1;
    }
    var_s0 = 0;
    while (true) {
        if (arg2 < 0) {
            return 0;
        }
        if (arg1 >= 0x3FE) {
            break;
        }
        func_800C1E04_5ECA4(&sp40, 0, arg0, &D_800E17A8_7E648);
        osRecvMesg(&D_800E17A8_7E648, NULL, 1);
        if (func_800C1ED0_5ED70(arg1) != 0) {
            return 1;
        }
        arg0 += 0x80;
        arg2 -= 0x80;
        var_s0++;
        arg1++;
        if (var_s0 == 0x80) {
            break;
        }
    }
    return 0;
}

s32 func_800C09C0_5D860(uintptr_t arg0, s32 size) {
    s32 var_s1;
    s32 i;

    func_800C1A38_5E8D8(&D_800E1798_7E638, &D_800E179C_7E63C);
    if (size <= 0 || size > 0x20000) {
        return -1;
    }
    var_s1 = 0;
    osWritebackDCache((void*) arg0, size);

    while (size > 0) {
        if (func_800C0848_5D6E8(arg0, var_s1, size)) {

            for (i = 3;; i--) {
                func_800C08DC_5D77C(arg0, var_s1, size);
                if (!func_800C0848_5D6E8(arg0, var_s1, size)) {
                    // required to match
                    if (1) {
                    }
                    break;
                }

                if (i <= 0) {
                    return 1;
                }
            }

            if (var_s1 > 0x380) {

                break;
            }
        }
        size -= 0x4000;
        arg0 += 0x4000;
        var_s1 += 0x80;
    }

    return 0;
}

s32 func_800C0AB4_5D954(uintptr_t arg0, s32 size) {
    s32 var_s1;

    if (size <= 0 || size > 0x20000) {
        return -1;
    }
    var_s1 = 0;
    osWritebackDCache((void*) arg0, size);

    while (size > 0) {
        if (func_800C0848_5D6E8((s32) arg0, var_s1, size) != 0) {
            return 1;
        }
        size -= 0x4000;
        arg0 += 0x4000;
        var_s1 += 0x80;
    }
    return 0;
}

void func_800C0B48_5D9E8(void) {
    D_800E1700_7E5A0 = ((uintptr_t) D_800E1708_7E5A8 + 0xF) & ~0xF;
    D_800E16F0_7E590 = func_800C1818_5E6B8();
    osCreateMesgQueue(&D_800E17A8_7E648, &D_800E17A0_7E640, 1);
    D_800E1798_7E638 = 0;
    D_800E179C_7E63C = 0;
}
