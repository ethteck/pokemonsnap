#include "common.h"
#include "camera_check.h"
#include "photo_check/photo_check.h"
#include "unk_end_level/unk_end_level.h"

s32 func_camera_check_801E2330(s32 arg0) {
    arg0 = func_8009BB4C(arg0);
    if (arg0 < 0 || arg0 >= 69) {
        return 0;
    }

    return (D_camera_check_8024A1C8[arg0 / 8] & (1 << (arg0 % 8))) != 0;
}

void func_camera_check_801E23A8(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8009BB4C(arg0);
    if (temp_v0 < 0 || temp_v0 >= 69) {
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
    if (arg0 < 0 || arg0 >= D_camera_check_8024A1C4) {
        return 0;
    }

    return D_camera_check_80249B30[arg0 + D_camera_check_8024A1C0].unk_00;
}

UnkIndigoHalibut* func_camera_check_801E24D8(s32 arg0) {
    if (arg0 < 0 || arg0 >= D_camera_check_8024A1C4) {
        return NULL;
    }

    return D_camera_check_80249B30 + arg0 + D_camera_check_8024A1C0;
}

s32 func_camera_check_801E2534(void) {
    return D_camera_check_8024A1C4;
}

bool func_camera_check_801E2540(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 i;

    count = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if ((arg0 == item->unk_08) && (item->unk_18_0x20000000 || (item->unk_18_0x10000000))) {
            return true;
        }
    }

    return false;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E25B8.s")

s32 func_camera_check_801E27FC(void) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if (item->unk_18_0x20000000 || item->unk_18_0x10000000 || item->unk_18_0x08000000) {
            return true;
        }
    }

    return false;
}

UnkIndigoHalibut* func_camera_check_801E286C(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 i;

    count = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if ((arg0 == item->unk_08) && (item->unk_18_0x20000000 || item->unk_18_0x10000000)) {
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
        if (arg0 == item->unk_08) {
            ret++;
        }
    }

    return ret;
}

s32 func_camera_check_801E2948(UnkIndigoHalibut* arg0) {
    s32 temp;

    if (arg0 == NULL) {
        return -1;
    }

    temp = (uintptr_t) arg0 - (uintptr_t) &D_camera_check_80249B30;
    return (temp / 28) - D_camera_check_8024A1C0;
}

void func_camera_check_801E2984(s32 pokeID) {
    s32 count;
    UnkIndigoHalibut* item;
    s32 i;

    if (pokeID <= 0 || pokeID >= 0x40C) {
        return;
    }

    count = func_8009BC68();
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if (item->unk_08 != pokeID) {
            continue;
        }

        item->unk_18_0x10000000 = 0;
        item->unk_18_0x20000000 = 0;
    }
}

s32 func_camera_check_801E2A00(void) {
    s32 i;
    s32 ret;
    UnkIndigoHalibut* item;

    ret = 0;
    for (i = func_8009BC68(), item = D_camera_check_80249B30; i != 0; item++, i--) {
        if (item->unk_18_0x20000000) {
            ret += 1;
        }
    }

    return ret;
}

PhotoData* func_camera_check_801E2AD8(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 i;

    for (i = 0, item = D_camera_check_80249B30; i < func_8009BC68(); i++, item++) {
        if (!item->unk_18_0x20000000) {
            continue;
        }

        if (arg0-- == 0) {
            return item->unk_00;
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
        if (item->unk_18_0x10000000) {
            ret += 1;
        }
    }

    return ret;
}

PhotoData* func_camera_check_801E2C38(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 i;

    for (i = 0, item = D_camera_check_80249B30; i < func_8009BC68(); i++, item++) {
        if (!item->unk_18_0x10000000) {
            continue;
        }

        if (arg0-- == 0) {
            return item->unk_00;
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
        if (item->unk_18_0x08000000) {
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
        if (item->unk_18_0x20000000) {

            if ((arg0--) == 0) {
                return item->unk_00;
            }
        }

        // required to match
        if (false) {
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

bool func_camera_check_801E2E5C(s32 id) {
    if (id == PokemonID_1004 || id == PokemonID_1010 || id == PokemonID_1018 || id == PokemonID_1022 ||
        id == PokemonID_1028 || id == PokemonID_1035) {
        return true;
    }
    return false;
}

s32 func_camera_check_801E2EA0(s32 id) {
    return func_camera_check_801E2E5C(id);
}

bool func_camera_check_801E2EC0(s32 id) {
    switch (id) {
        case PokemonID_500:
        case PokemonID_600:
        case PokemonID_601:
        case PokemonID_602:
            return true;
        default:
            return false;
    }
}

bool func_camera_check_801E2EF4(s32 id) {
    if (id > 0 && id <= POKEDEX_MAX) {
        return true;
    }

    if (!func_camera_check_801E2E5C(id)) {
        return false;
    }

    if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
        return true;
    }

    return false;
}

s32 func_camera_check_801E2F58(UnkIndigoHalibut* arg0, bool arg1) {
    s32 sp24;
    UNUSED s32 unused[1];
    s32 sp1C;
    s32 var_v0;

    if (arg0 == NULL) {
        return 0;
    }
    sp24 = arg0->unk_08;

    sp1C = arg0->unk_18_0x20000000 != 0;
    if (sp1C == 0) {
        sp1C = arg0->unk_18_0x10000000 != 0;
    }

    if (!arg1 && func_camera_check_801E3420()) {
        return 1;
    }
    if (sp24 == 9999) {
        return 2;
    }
    if (!func_camera_check_801E2E5C(sp24) || !checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
        if (func_camera_check_801E2EC0(sp24) != 0) {
            return 3;
        }
        if (func_camera_check_801E2540(sp24)) {
            if (sp1C != 0) {
                return 6;
            }
            return 7;
        }
        if (func_800BF3D4_5C274(sp24)) {
            return 4;
        }
        return 5;
    }
    if (func_800BF3D4_5C274(sp24)) {
        if (!func_camera_check_801E2540(sp24)) {
            return 13;
        }
        if (sp1C != 0) {
            return 12;
        }
        return 11;
    }
    if (!func_camera_check_801E2540(sp24)) {
        return 10;
    }

    if (sp1C) {
        return 9;
    }

    return 8;
}

s32 func_camera_check_801E30CC(s32 arg0) {
    if (func_800BF3D4_5C274(arg0)) {
        return false;
    }

    if (arg0 > 0 && arg0 <= POKEDEX_MAX) {
        return true;
    }

    if (func_camera_check_801E2E5C(arg0) && checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
        return true;
    }

    return false;
}

bool func_camera_check_801E3140(void) {
    UnkIndigoHalibut* item;
    s32 count;
    s32 hashDashEngine;
    s32 i;

    count = func_8009BC68();
    hashDashEngine = checkPlayerFlag(PFID_HAS_DASH_ENGINE);
    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        if (item->unk_08 > 0 && item->unk_08 <= POKEDEX_MAX) {
            return true;
        }
        if (hashDashEngine && func_camera_check_801E2E5C(item->unk_08)) {
            return true;
        }
    }

    return false;
}

void func_camera_check_801E31E4(s32 arg0, UNK_TYPE arg1) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = func_8009BC68();

    for (i = 0, item = D_camera_check_80249B30; i < count; i++, item++) {
        item->unk_18_0x01000000 = 0;
        if (arg0 == 1) {
            if (item->unk_08 >= 0x40C) {
                item->unk_18_0x01000000 = 1;
            } else if (func_camera_check_801E2540(item->unk_08)) {
                item->unk_18_0x01000000 = 1;
            } else {
                if ((item->unk_08 > 151) && (!func_camera_check_801E2E5C(item->unk_08) || !checkPlayerFlag(PFID_HAS_DASH_ENGINE))) {

                    item->unk_18_0x01000000 = 1;
                }
            }
        }

        // Required to match
        if (true) {
        }
    }
}

s32 func_camera_check_801E32E0(PhotoData* arg0) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = D_camera_check_8024A1C4;
    for (i = 0, item = &D_camera_check_80249B30[D_camera_check_8024A1C0]; i < count; item++, i++) {
        if (item->unk_00 == arg0) {
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
        if ((item->unk_08 >= 1004) && (item->unk_08 < 1036)) {
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
        if (!item->unk_18_0x01000000) {
            return false;
        }
    }

    return true;
}

s32 func_camera_check_801E350C(void) {
    s32 count;
    s32 i;
    UnkIndigoHalibut* item;

    count = D_camera_check_8024A1C4;
    for (i = 0, item = &D_camera_check_80249B30[D_camera_check_8024A1C0]; i < count; item++, i++) {
        if (!item->unk_18_0x01000000 && item->unk_18_0x80000000) {
            return true;
        }
    }

    return false;
}

s32 func_camera_check_801E3620(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;
    if (rhs->unk_00 < lhs->unk_00) {
        return 1;
    }
    if (rhs->unk_00 > lhs->unk_00) {
        return -1;
    }
    return 0;
}

s32 func_camera_check_801E3658(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;
    if (lhs->unk_18_0x80000000 < rhs->unk_18_0x80000000) {
        return 1;
    }
    if (rhs->unk_18_0x80000000 < lhs->unk_18_0x80000000) {
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
    if (lhs->unk_08 < rhs->unk_08) {
        return 1;
    }
    if (rhs->unk_08 < lhs->unk_08) {
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
    if (lhs->unk_18_0x20000000 > rhs->unk_18_0x20000000) {
        return 1;
    }
    if (lhs->unk_18_0x20000000 < rhs->unk_18_0x20000000) {
        return -1;
    }
    if (D_camera_check_802089F4 != NULL && D_camera_check_802089F4 != func_camera_check_801E3758) {
        return D_camera_check_802089F4(arg0, arg1);
    }
    return func_camera_check_801E3620(arg0, arg1);
}

s32 func_camera_check_801E37E4(const void* arg0, const void* arg1) {
    UnkIndigoHalibut* lhs;
    UnkIndigoHalibut* rhs;

    lhs = (UnkIndigoHalibut*) arg0;
    rhs = (UnkIndigoHalibut*) arg1;
    if (lhs->unk_18_0x10000000 > rhs->unk_18_0x10000000) {
        return 1;
    }
    if (lhs->unk_18_0x10000000 < rhs->unk_18_0x10000000) {
        return -1;
    }
    if (D_camera_check_802089F4 != NULL && D_camera_check_802089F4 != func_camera_check_801E37E4) {
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
    lhsVal = (lhs->unk_18_0x20000000 << 2 & (1 << 2)) | (lhs->unk_18_0x10000000 << 1 & (1 << 1)) | (lhs->unk_18_0x08000000 << 0 & (1 << 0));
    rhsVal = (rhs->unk_18_0x20000000 << 2 & (1 << 2)) | (rhs->unk_18_0x10000000 << 1 & (1 << 1)) | (rhs->unk_18_0x08000000 << 0 & (1 << 0));

    if (lhsVal != rhsVal) {
        return rhsVal - lhsVal;
    }
    return func_camera_check_801E3620(arg0, arg1);
}

void func_camera_check_801E3910(s32 arg0) {
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

void func_camera_check_801E3AF4(UnkIndigoHalibut* arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87FB20/func_camera_check_801E3AF4.s")

void func_camera_check_801E3C24(s32 arg0) {
    UnkIndigoHalibut* item;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v1;

    if (arg0 == 0) {
        func_camera_check_801E3910(0);
        D_camera_check_802089F0 = false;
        D_camera_check_8024A1C0 = 0;
        D_camera_check_8024A1C4 = func_8009BC68();
    } else {
        func_camera_check_801E3910(6);
        temp_v0 = func_8009BC68();
        D_camera_check_8024A1C0 = 0;

        for (D_camera_check_8024A1C4 = 0, item = D_camera_check_80249B30; D_camera_check_8024A1C4 < temp_v0; item++, D_camera_check_8024A1C4++) {
            if (!item->unk_18_0x20000000 && !item->unk_18_0x10000000 && !item->unk_18_0x08000000) {
                break;
            }
        }

        D_camera_check_802089F0 = true;
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
        if (item->unk_18_0x20000000 || item->unk_18_0x10000000 || item->unk_18_0x08000000) {
            var_a1 = item->unk_18_0x20000000 != 0;
            if (var_a1 == 0) {
                var_a1 = item->unk_18_0x10000000 != 0;
            }
            func_800BFABC_5C95C(item->unk_00, var_a1, 0, item->unk_18_0x08000000);
        }
    }
}

void func_camera_check_801E3D8C(PhotoData* arg0, UnkIndigoHalibut* arg1) {
    Unk803A6C18* temp_v0;
    UNK_TYPE sp28;

    temp_v0 = func_8037452C_847CDC(arg0);
    arg1->unk_00 = arg0;
    if (temp_v0->unk_3AA == 0) {
        arg1->unk_04 = NULL;
        arg1->unk_08 = 9999;
        arg1->unk_18_0x80000000 = false;
        arg1->unk_0A = 0;
        arg1->unk_0C = 0;
        arg1->unk_18_0x04000000 = true;
        arg1->unk_0E = 0;
        arg1->unk_10 = 0;
        arg1->unk_12 = 0;
        arg1->unk_14 = 0;
        arg1->unk_16 = 0;
    } else {
        arg1->unk_04 = temp_v0->unk_3A0;
        arg1->unk_08 = temp_v0->unk_3AA;
        arg1->unk_18_0x80000000 = func_camera_check_801E30CC(arg1->unk_08);
        arg1->unk_18_0x04000000 = false;
        arg1->unk_0A = temp_v0->unk_3B4;
        arg1->unk_0C = temp_v0->unk_3A7;
        arg1->unk_0E = temp_v0->unk_3B0;
        arg1->unk_10 = temp_v0->unk_3AE;
        arg1->unk_12 = temp_v0->unk_3AC;
        arg1->unk_14 = temp_v0->unk_3B2;
        arg1->unk_16 = temp_v0->unk_3A4;
        D_camera_check_8024A1D4 += (s32) arg1->unk_04;
        func_camera_check_801E23A8(arg1->unk_08, 1);
    }
    arg1->unk_18_0x40000000 = false;
    arg1->unk_18_0x20000000 = false;
    arg1->unk_18_0x10000000 = false;
    arg1->unk_18_0x08000000 = false;
    arg1->unk_18_0x01000000 = false;
}

void func_camera_check_801E3EEC(void (*arg0)(s32)) {
    UnkIndigoHalibut* it;
    s32 temp_v0;
    s32 i;

    D_camera_check_802089F0 = false;
    D_camera_check_8024A1C0 = 0;
    temp_v0 = D_camera_check_8024A1C4 = func_8009BC68();
    D_camera_check_8024A1D4 = 0;
    D_camera_check_8024A1D8 = 0;

    for (i = 0; i < 9U;) {
        D_camera_check_8024A1C8[i++] = 0;
    }

    for (it = D_camera_check_80249B30, i = 0; i < temp_v0; i++, it++) {
        func_camera_check_801E3D8C(func_803746B4_847E64(i), it);
        if (arg0 != NULL) {
            arg0(i);
        }
    }

    for (i = 1; i < 0x40C; i++) {
        if (func_camera_check_801E2330(i) != 0) {
            D_camera_check_8024A1D8++;
        }
    }
}
