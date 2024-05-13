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

PhotoData* func_camera_check_801E2484(s32 arg0) {
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

u32 func_camera_check_801E2A00(void) {
    s32 i;
    s32 ret;
    UnkIndigoHalibut* item;

    ret = 0;
    for (i = func_8009BC68(), item = D_camera_check_80249B30; i != 0; item++, i--) {
        if (item->var_18_0x20000000) {
            ret += 1;
        }
    }

    return ret;
}

PhotoData* func_camera_check_801E2AD8(s32 arg0) {
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

s32 func_camera_check_801E2B60(void) {
    s32 i;
    s32 ret;
    UnkIndigoHalibut* item;

    ret = 0;
    for (i = func_8009BC68(), item = D_camera_check_80249B30; i != 0; item++, i--) {
        if (item->var_18_0x10000000) {
            ret += 1;
        }
    }

    return ret;
}

PhotoData* func_camera_check_801E2C38(s32 arg0) {
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

s32 func_camera_check_801E2CC0(void) {
    s32 i;
    s32 ret;
    UnkIndigoHalibut* item;

    ret = 0;
    for (i = func_8009BC68(), item = D_camera_check_80249B30; i != 0; item++, i--) {
        if (item->var_18_0x08000000) {
            ret += 1;
        }
    }

    return ret;
}

PhotoData* func_camera_check_801E2D98(s32 arg0) {
    s32 max;
    s32 i;
    UnkIndigoHalibut* item;

    max = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < max; i++, item++) {
        if (item->var_18_0x20000000) {

            if ((arg0--) == 0) {
                return item->var_0;
            }
        }

        // required to match
        if (FALSE) {
        }
    }

    return NULL;
}

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

s32 func_camera_check_801E2F58(UnkIndigoHalibut* arg0, s32 arg1) {
    s32 sp24;
    UNUSED s32 unused[1];
    s32 sp1C;
    s32 var_v0;

    if (arg0 == NULL) {
        return 0;
    }
    sp24 = arg0->var_8;

    sp1C = arg0->var_18_0x20000000 != 0;
    if (sp1C == 0) {
        sp1C = arg0->var_18_0x10000000 != 0;
    }

    if ((arg1 == 0) && (func_camera_check_801E3420() != 0)) {
        return 1;
    }
    if (sp24 == 9999) {
        return 2;
    }
    if ((func_camera_check_801E2E5C(sp24) == 0) || (func_800BFCA0_5CB40(5) == 0)) {
        if (func_camera_check_801E2EC0(sp24) != 0) {
            return 3;
        }
        if (func_camera_check_801E2540(sp24) != 0) {
            if (sp1C != 0) {
                return 6;
            }
            return 7;
        }
        if (func_800BF3D4_5C274(sp24) != 0) {
            return 4;
        }
        return 5;
    }
    if (func_800BF3D4_5C274(sp24) != 0) {
        if (func_camera_check_801E2540(sp24) == 0) {
            return 13;
        }
        if (sp1C != 0) {
            return 12;
        }
        return 11;
    }
    if (func_camera_check_801E2540(sp24) == 0) {
        return 10;
    }

    if (sp1C) {
        return 9;
    }

    return 8;
}

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

void func_camera_check_801E31E4(s32 arg0, UNK_TYPE arg1) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = func_8009BC68();

    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        item->var_18_0x01000000 = 0;
        if (arg0 == 1) {
            if (item->var_8 >= 0x40C) {
                item->var_18_0x01000000 = 1;
            } else if (func_camera_check_801E2540(item->var_8) != 0) {
                item->var_18_0x01000000 = 1;
            } else {
                if ((item->var_8 > 151) && ((func_camera_check_801E2E5C(item->var_8) == 0) || (func_800BFCA0_5CB40(5) == 0))) {

                    item->var_18_0x01000000 = 1;
                }
            }
        }

        // Required to match
        if (TRUE) {
        }
    }
}

s32 func_camera_check_801E32E0(PhotoData* arg0) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = D_camera_check_8024A1C4;
    for (i = 0, item = &D_camera_check_80249B30[D_camera_check_8024A1C0]; i < count; item++, i++) {
        if (item->var_0 == arg0) {
            return i;
        }
    }

    return -1;
}

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

s32 func_camera_check_801E3420(void) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = D_camera_check_8024A1C4;
    for (i = 0, item = &D_camera_check_80249B30[D_camera_check_8024A1C0]; i < count; item++, i++) {
        if (!item->var_18_0x01000000) {
            return 0;
        }
    }

    return 1;
}

s32 func_camera_check_801E350C(void) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = D_camera_check_8024A1C4;
    for (i = 0, item = &D_camera_check_80249B30[D_camera_check_8024A1C0]; i < count; item++, i++) {
        if (!item->var_18_0x01000000 && item->var_18_0x80000000) {
            return 1;
        }
    }

    return 0;
}

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

s32 func_camera_check_801E3870(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;
    s32 lhsVal, rhsVal;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;

    // TODO: see if this can be matched in a better way
    lhsVal = (lhs->var_18_0x20000000 << 2 & (1 << 2)) | (lhs->var_18_0x10000000 << 1 & (1 << 1)) | (lhs->var_18_0x08000000 << 0 & (1 << 0));
    rhsVal = (rhs->var_18_0x20000000 << 2 & (1 << 2)) | (rhs->var_18_0x10000000 << 1 & (1 << 1)) | (rhs->var_18_0x08000000 << 0 & (1 << 0));

    if (lhsVal != rhsVal) {
        return rhsVal - lhsVal;
    }
    return func_camera_check_801E3620(arg0, arg1);
}

void func_camera_check_801E3910(u32 arg0) {
    switch (arg0) {
        case 0:
            qsort(D_camera_check_80249B30, func_8009BC68(), sizeof(UnkIndigoHalibut), func_camera_check_801E3620);
            if (D_camera_check_802089F4 != func_camera_check_801E3620) {
                D_camera_check_802089F4 = func_camera_check_801E3620;
            }
            break;
        case 1:
            qsort(D_camera_check_80249B30, func_8009BC68(), sizeof(UnkIndigoHalibut), func_camera_check_801E3658);
            if (D_camera_check_802089F4 != func_camera_check_801E3658) {
                D_camera_check_802089F4 = func_camera_check_801E3658;
            }
            break;
        case 2:
            qsort(D_camera_check_80249B30, func_8009BC68(), sizeof(UnkIndigoHalibut), func_camera_check_801E36DC);
            if (D_camera_check_802089F4 != func_camera_check_801E36DC) {
                D_camera_check_802089F4 = func_camera_check_801E36DC;
            }
            break;
        case 4:
            qsort(D_camera_check_80249B30, func_8009BC68(), sizeof(UnkIndigoHalibut), func_camera_check_801E3758);
            if (D_camera_check_802089F4 != func_camera_check_801E3758) {
                D_camera_check_802089F4 = func_camera_check_801E3758;
            }
            break;
        case 5:
            qsort(D_camera_check_80249B30, func_8009BC68(), sizeof(UnkIndigoHalibut), func_camera_check_801E37E4);
            if (D_camera_check_802089F4 != func_camera_check_801E37E4) {
                D_camera_check_802089F4 = func_camera_check_801E37E4;
            }
            break;
        case 6:
            qsort(D_camera_check_80249B30, func_8009BC68(), sizeof(UnkIndigoHalibut), func_camera_check_801E3870);
            if (D_camera_check_802089F4 != func_camera_check_801E37E4) {
                D_camera_check_802089F4 = func_camera_check_801E37E4;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3AF4.s")

void func_camera_check_801E3C24(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 temp_t2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v1;

    if (arg0 == 0) {
        func_camera_check_801E3910(0);
        D_camera_check_802089F0 = 0;
        D_camera_check_8024A1C0 = 0;
        D_camera_check_8024A1C4 = func_8009BC68();
    } else {
        func_camera_check_801E3910(6);
        temp_v0 = func_8009BC68();
        D_camera_check_8024A1C0 = 0;

        for (D_camera_check_8024A1C4 = 0, item = D_camera_check_80249B30; D_camera_check_8024A1C4 < temp_v0; item++, D_camera_check_8024A1C4++) {
            if (!item->var_18_0x20000000 && !item->var_18_0x10000000 && !item->var_18_0x08000000) {
                break;
            }
        }

        D_camera_check_802089F0 = 1;
    }
}

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
