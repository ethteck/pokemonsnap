#include "common.h"

typedef struct UnkIndigoHalibut {
    /* 0x00 */ u32 var_0;
    /* 0x04 */ char pad_4[4];
    /* 0x08 */ s16 var_8;
    /* 0x0A */ char pad_A[0x12 - 4];
    /* 0x18 */ s32 var_18_0x80000000 : 1;
    /* 0x18 */ s32 var_18_0x40000000 : 1;
    /* 0x18 */ s32 var_18_0x20000000 : 1;
    /* 0x18 */ s32 var_18_0x10000000 : 1;
    /* 0x18 */ s32 var_18_0x08000000 : 1;
} UnkIndigoHalibut; // size: 0x1C

extern UnkIndigoHalibut D_80249B30_8E7320[];
extern s32 D_8024A1C0_8E79B0;
extern s32 D_8024A1C4_8E79B4;
extern u8 D_8024A1C8_8E79B8[];
extern s32 D_8024A1D4_8E79C4;
extern s32 D_8024A1D8_8E79C8;
extern s32 (*D_802089F4_8A61E4)(const void*, const void*);

s32 func_8009BC68(void);
s32 func_8009BB4C(s32);
void func_800BFABC_5C95C(u32, s32, int, s32);

s32 func_801E2330_87FB20(s32 arg0) {
    arg0 = func_8009BB4C(arg0);
    if ((arg0 < 0) || (arg0 >= 0x45)) {
        return 0;
    }

    return (D_8024A1C8_8E79B8[arg0 / 8] & (1u << (arg0 % 8))) != 0;
}

void func_801E23A8_87FB98(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8009BB4C(arg0);
    if ((temp_v0 < 0) || (temp_v0 >= 0x45)) {
        return;
    }

    if (arg1) {
        D_8024A1C8_8E79B8[temp_v0 / 8] |= 1 << (temp_v0 % 8);
    } else {
        D_8024A1C8_8E79B8[temp_v0 / 8] &= ~(1 << (temp_v0 % 8));
    }
}

s32 func_801E246C_87FC5C(void) {
    return D_8024A1D4_8E79C4;
}

s32 func_801E2478_87FC68(void) {
    return D_8024A1D8_8E79C8;
}

s32 func_801E2484_87FC74(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= D_8024A1C4_8E79B4)) {
        return 0;
    }

    return D_80249B30_8E7320[arg0 + D_8024A1C0_8E79B0].var_0;
}

UnkIndigoHalibut* func_camera_check_801E24D8(s32) {
    if ((arg0 < 0) || (arg0 >= D_8024A1C4_8E79B4)) {
        return NULL;
    }

    return D_80249B30_8E7320 + arg0 + D_8024A1C0_8E79B0;
}

s32 func_camera_check_801E2534(void) {
    return D_8024A1C4_8E79B4;
}

s32 func_801E2540_87FD30(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 i;

    count = func_8009BC68();
    for (i = 0, item = D_80249B30_8E7320; i < count; i++, item++) {
        if ((arg0 == item->var_8) && (item->var_18_0x20000000 || (item->var_18_0x10000000))) {
            return 1;
        }
    }

    return 0;
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E25B8_87FDA8.s")
#else
#endif

s32 func_801E27FC_87FFEC(void) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = func_8009BC68();
    for (i = 0, item = D_80249B30_8E7320; i < count; i++, item++) {
        if (item->var_18_0x20000000 || item->var_18_0x10000000 || item->var_18_0x08000000) {
            return 1;
        }
    }

    return 0;
}

UnkIndigoHalibut* func_801E286C_88005C(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 i;

    count = func_8009BC68();
    for (i = 0, item = D_80249B30_8E7320; i < count; i++, item++) {
        if ((arg0 == item->var_8) && (item->var_18_0x20000000 || item->var_18_0x10000000)) {
            return item;
        }
    }
    return NULL;
}

s32 func_801E28E4_8800D4(s32 arg0) {
    s32 i;
    UnkIndigoHalibut* item;
    s32 ret;
    s32 count;

    ret = 0;
    count = func_8009BC68();
    for (i = 0, item = &D_80249B30_8E7320[0]; i < count; i++, item++) {
        if (arg0 == item->var_8) {
            ret++;
        }
    }

    return ret;
}

s32 func_801E2948_880138(s32 arg0) {
    s32 temp;

    if (arg0 == 0) {
        return -1;
    }

    // TODO: fix this
    temp = arg0 - ((uintptr_t) &D_80249B30_8E7320);
    return (temp / 28) - D_8024A1C0_8E79B0;
}

void func_801E2984_880174(s32 arg0) {
    s32 count;
    UnkIndigoHalibut* item;
    s32 i;

    if (arg0 <= 0 || arg0 >= 0x40C) {
        return;
    }

    count = func_8009BC68();
    for (i = 0, item = D_80249B30_8E7320; i < count; i++, item++) {
        if (item->var_8 != arg0) {
            continue;
        }

        item->var_18_0x10000000 = 0;
        item->var_18_0x20000000 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E2A00_8801F0.s")

u32 func_801E2AD8_8802C8(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 i;

    for (i = 0, item = D_80249B30_8E7320; i < func_8009BC68(); i++, item++) {
        if (!item->var_18_0x20000000) {
            continue;
        }

        if (arg0-- == 0) {
            return item->var_0;
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E2B60_880350.s")

u32 func_801E2C38_880428(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 i;

    for (i = 0, item = D_80249B30_8E7320; i < func_8009BC68(); i++, item++) {
        if (!item->var_18_0x10000000) {
            continue;
        }

        if (arg0-- == 0) {
            return item->var_0;
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_camera_check_801E2CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E2D98_880588.s")

// Get the number of photos that have been taken?
s32 func_camera_check_801E2E04(void) {
    s32 i;
    s32 ret;

    ret = 0;
    for (i = 0; i < 60; i++) { // TODO: PHOTOS_COUNT ?
        if (func_800BFA44_5C8E4(i) == 0) {
            ret++;
        }
    }

    return ret;
}

s32 func_801E2E5C_88064C(s32 arg0) {
    if ((arg0 == 0x3EC) || (arg0 == 0x3F2) || (arg0 == 0x3FA) || (arg0 == 0x3FE) || (arg0 == 0x404) ||
        (arg0 == 0x40B)) {
        return 1;
    }
    return 0;
}

void func_801E2EA0_880690(s32 arg0) {
    func_801E2E5C_88064C(arg0);
}

s32 func_801E2EC0_8806B0(s32 arg0) {
    switch (arg0) {
        case 0x1F4:
        case 0x258:
        case 0x259:
        case 0x25A:
            return 1;

        default:
            return 0;
    }
}

s32 func_801E2EF4_8806E4(s32 arg0) {
    if ((arg0 > 0) && (arg0 < 0x98)) {
        return 1;
    }

    if (func_801E2E5C_88064C(arg0) == 0) {
        return 0;
    }

    if (func_800BFCA0_5CB40(5) != 0) {
        return 1;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E2F58_880748.s")

s32 func_801E30CC_8808BC(s32 arg0) {
    if (func_800BF3D4_5C274(arg0) != 0) {
        return FALSE;
    }

    if ((arg0 > 0) && (arg0 < 0x98)) {
        return TRUE;
    }

    if ((func_801E2E5C_88064C(arg0) != 0) && (func_800BFCA0_5CB40(5) != 0)) {
        return TRUE;
    }

    return FALSE;
}

s32 func_801E3140_880930(void) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 temp_s3;
    s32 i;

    count = func_8009BC68();
    temp_s3 = func_800BFCA0_5CB40(5);
    for (i = 0, item = D_80249B30_8E7320; i < count; i++, item++) {
        if ((item->var_8 > 0) && (item->var_8 < 0x98)) {
            return 1;
        }
        if ((temp_s3 != 0) && (func_801E2E5C_88064C(item->var_8) != 0)) {
            return 1;
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E31E4_8809D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E32E0_880AD0.s")

s32 func_801E33B8_880BA8(void) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 i;

    count = func_8009BC68();
    item = D_80249B30_8E7320;
    for (i = 0; i < count; i++, item++) {
        if ((item->var_8 >= 1004) && (item->var_8 < 1036)) {
            return i;
        }
    }

    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E3420_880C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E350C_880CFC.s")

s32 func_801E3620_880E10(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;
    if (rhs->var_0 < lhs->var_0) {
        return 1;
    }
    if (rhs->var_0 > lhs->var_0) {
        return -1;
    }
    return 0;
}

s32 func_801E3658_880E48(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;
    if (lhs->var_18_0x80000000 < rhs->var_18_0x80000000) {
        return 1;
    }
    if (rhs->var_18_0x80000000 < lhs->var_18_0x80000000) {
        return -1;
    }
    if ((D_802089F4_8A61E4 != NULL) && (D_802089F4_8A61E4 != func_801E3658_880E48)) {
        return D_802089F4_8A61E4(arg0, arg1);
    }
    return func_801E3620_880E10(arg0, arg1);
}

s32 func_801E36DC_880ECC(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;
    if (lhs->var_8 < rhs->var_8) {
        return 1;
    }
    if (rhs->var_8 < lhs->var_8) {
        return -1;
    }
    if ((D_802089F4_8A61E4 != NULL) && (D_802089F4_8A61E4 != func_801E36DC_880ECC)) {
        return D_802089F4_8A61E4(arg0, arg1);
    }
    return func_801E3620_880E10(arg0, arg1);
}

s32 func_801E3758_880F48(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;
    if (lhs->var_18_0x20000000 > rhs->var_18_0x20000000) {
        return 1;
    }
    if (lhs->var_18_0x20000000 < rhs->var_18_0x20000000) {
        return -1;
    }
    if ((D_802089F4_8A61E4 != NULL) && (D_802089F4_8A61E4 != func_801E3758_880F48)) {
        return D_802089F4_8A61E4(arg0, arg1);
    }
    return func_801E3620_880E10(arg0, arg1);
}

s32 func_801E37E4_880FD4(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;
    if (lhs->var_18_0x10000000 > rhs->var_18_0x10000000) {
        return 1;
    }
    if (lhs->var_18_0x10000000 < rhs->var_18_0x10000000) {
        return -1;
    }
    if ((D_802089F4_8A61E4 != NULL) && (D_802089F4_8A61E4 != func_801E37E4_880FD4)) {
        return D_802089F4_8A61E4(arg0, arg1);
    }
    return func_801E3620_880E10(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E3870_881060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E3910_881100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E3AF4_8812E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E3C24_881414.s")

void func_801E3CE8_8814D8(void) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 var_a1;
    s32 i;

    func_800BFABC_5C95C(0, 0, 0, 0);
    count = func_8009BC68();
    item = D_80249B30_8E7320;
    for (i = count; i != 0; i--, item++) {
        if (item->var_18_0x20000000 || item->var_18_0x10000000 || item->var_18_0x08000000) {
            var_a1 = item->var_18_0x20000000 != 0;
            if (var_a1 == 0) {
                var_a1 = item->var_18_0x10000000 != 0;
            }
            func_800BFABC_5C95C(item->var_0, var_a1, 0, item->var_18_0x08000000);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E3D8C_88157C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87FB20/func_801E3EEC_8816DC.s")
