#include "common.h"
#include "camera_check.h"

s32 func_camera_check_801E2330(s32 arg0) {
    arg0 = func_8009BB4C(arg0);
    if ((arg0 < 0) || (arg0 >= 0x45)) {
        return 0;
    }

    return (D_camera_check_8024A1C8[arg0 / 8] & (1u << (arg0 % 8))) != 0;
}

void func_camera_check_801E23A8(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8009BB4C(arg0);
    if ((temp_v0 < 0) || (temp_v0 >= 0x45)) {
        return;
    }

    if (arg1) {
        D_camera_check_8024A1C8[temp_v0 / 8] |= 1 << (temp_v0 % 8);
    } else {
        D_camera_check_8024A1C8[temp_v0 / 8] &= ~(1 << (temp_v0 % 8));
    }
}

s32 func_camera_check_801E246C(void) {
    return D_camera_check_8024A1D4;
}

s32 func_camera_check_801E2478(void) {
    return D_camera_check_8024A1D8;
}

UnkPinkBarracuda* func_camera_check_801E2484(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= D_camera_check_8024A1C4)) {
        return 0;
    }

    return D_camera_check_80249B30[arg0 + D_camera_check_8024A1C0].var_0;
}

UnkIndigoHalibut* func_camera_check_801E24D8(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= D_camera_check_8024A1C4)) {
        return NULL;
    }

    return D_camera_check_80249B30 + arg0 + D_camera_check_8024A1C0;
}

s32 func_camera_check_801E2534(void) {
    return D_camera_check_8024A1C4;
}

s32 func_camera_check_801E2540(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 i;

    count = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if ((arg0 == item->var_8) && (item->var_18_0x20000000 || (item->var_18_0x10000000))) {
            return 1;
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E25B8.s")

s32 func_camera_check_801E27FC(void) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if (item->var_18_0x20000000 || item->var_18_0x10000000 || item->var_18_0x08000000) {
            return 1;
        }
    }

    return 0;
}

UnkIndigoHalibut* func_camera_check_801E286C(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 i;

    count = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if ((arg0 == item->var_8) && (item->var_18_0x20000000 || item->var_18_0x10000000)) {
            return item;
        }
    }
    return NULL;
}

s32 func_camera_check_801E28E4(s32 arg0) {
    s32 i;
    UnkIndigoHalibut* item;
    s32 ret;
    s32 count;

    ret = 0;
    count = func_8009BC68();
    for (i = 0, item = &D_camera_check_80249B30[0]; i < count; i++, item++) {
        if (arg0 == item->var_8) {
            ret++;
        }
    }

    return ret;
}

s32 func_camera_check_801E2948(s32 arg0) {
    s32 temp;

    if (arg0 == 0) {
        return -1;
    }

    // TODO: fix this
    temp = arg0 - ((uintptr_t) &D_camera_check_80249B30);
    return (temp / 28) - D_camera_check_8024A1C0;
}

void func_camera_check_801E2984(s32 arg0) {
    s32 count;
    UnkIndigoHalibut* item;
    s32 i;

    if (arg0 <= 0 || arg0 >= 0x40C) {
        return;
    }

    count = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if (item->var_8 != arg0) {
            continue;
        }

        item->var_18_0x10000000 = 0;
        item->var_18_0x20000000 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E2A00.s")

UnkPinkBarracuda* func_camera_check_801E2AD8(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 i;

    for (i = 0, item = D_camera_check_80249B30; i < func_8009BC68(); i++, item++) {
        if (!item->var_18_0x20000000) {
            continue;
        }

        if (arg0-- == 0) {
            return item->var_0;
        }
    }

    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E2B60.s")

UnkPinkBarracuda* func_camera_check_801E2C38(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 i;

    for (i = 0, item = D_camera_check_80249B30; i < func_8009BC68(); i++, item++) {
        if (!item->var_18_0x10000000) {
            continue;
        }

        if (arg0-- == 0) {
            return item->var_0;
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E2CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E2D98.s")

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

s32 func_camera_check_801E2E5C(s32 arg0) {
    if ((arg0 == 0x3EC) || (arg0 == 0x3F2) || (arg0 == 0x3FA) || (arg0 == 0x3FE) || (arg0 == 0x404) ||
        (arg0 == 0x40B)) {
        return 1;
    }
    return 0;
}

void func_camera_check_801E2EA0(s32 arg0) {
    func_camera_check_801E2E5C(arg0);
}

s32 func_camera_check_801E2EC0(s32 arg0) {
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

s32 func_camera_check_801E2EF4(s32 arg0) {
    if ((arg0 > 0) && (arg0 < 0x98)) {
        return 1;
    }

    if (func_camera_check_801E2E5C(arg0) == 0) {
        return 0;
    }

    if (func_800BFCA0_5CB40(5) != 0) {
        return 1;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E2F58.s")

s32 func_camera_check_801E30CC(s32 arg0) {
    if (func_800BF3D4_5C274(arg0) != 0) {
        return FALSE;
    }

    if ((arg0 > 0) && (arg0 < 0x98)) {
        return TRUE;
    }

    if ((func_camera_check_801E2E5C(arg0) != 0) && (func_800BFCA0_5CB40(5) != 0)) {
        return TRUE;
    }

    return FALSE;
}

s32 func_camera_check_801E3140(void) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 temp_s3;
    s32 i;

    count = func_8009BC68();
    temp_s3 = func_800BFCA0_5CB40(5);
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if ((item->var_8 > 0) && (item->var_8 < 0x98)) {
            return 1;
        }
        if ((temp_s3 != 0) && (func_camera_check_801E2E5C(item->var_8) != 0)) {
            return 1;
        }
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E31E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E32E0.s")

s32 func_camera_check_801E33B8(void) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 i;

    count = func_8009BC68();
    item = D_camera_check_80249B30;
    for (i = 0; i < count; i++, item++) {
        if ((item->var_8 >= 1004) && (item->var_8 < 1036)) {
            return i;
        }
    }

    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E350C.s")

s32 func_camera_check_801E3620(const void* arg0, const void* arg1) {
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

s32 func_camera_check_801E3658(const void* arg0, const void* arg1) {
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
    if ((D_camera_check_802089F4 != NULL) && (D_camera_check_802089F4 != func_camera_check_801E3658)) {
        return D_camera_check_802089F4(arg0, arg1);
    }
    return func_camera_check_801E3620(arg0, arg1);
}

s32 func_camera_check_801E36DC(const void* arg0, const void* arg1) {
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
    if ((D_camera_check_802089F4 != NULL) && (D_camera_check_802089F4 != func_camera_check_801E36DC)) {
        return D_camera_check_802089F4(arg0, arg1);
    }
    return func_camera_check_801E3620(arg0, arg1);
}

s32 func_camera_check_801E3758(const void* arg0, const void* arg1) {
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
    if ((D_camera_check_802089F4 != NULL) && (D_camera_check_802089F4 != func_camera_check_801E3758)) {
        return D_camera_check_802089F4(arg0, arg1);
    }
    return func_camera_check_801E3620(arg0, arg1);
}

s32 func_camera_check_801E37E4(const void* arg0, const void* arg1) {
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
    if ((D_camera_check_802089F4 != NULL) && (D_camera_check_802089F4 != func_camera_check_801E37E4)) {
        return D_camera_check_802089F4(arg0, arg1);
    }
    return func_camera_check_801E3620(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3870.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3910.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3AF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3C24.s")

void func_camera_check_801E3CE8(void) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 var_a1;
    s32 i;

    func_800BFABC_5C95C(NULL, 0, 0, 0);
    count = func_8009BC68();
    item = D_camera_check_80249B30;
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

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3D8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3EEC.s")
