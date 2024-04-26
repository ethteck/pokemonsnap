#include "common.h"
#include "camera_check.h"

// Unreferenced strings
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/D_camera_check_80208C60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801DF9B0.s")

UnkCyanBass* func_camera_check_801DFA4C(void) {
    if (func_800BFCA0_5CB40(8) == 0) {
        return &D_camera_check_80208994;
    }
    return &D_camera_check_802089BC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801DFA80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801DFCD4.s")

void func_camera_check_801E0034(s32 arg0) {
    s32 pad;
    UnkIndigoHalibut* temp_v0;

    temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
    if (temp_v0 == NULL) {
        return;
    }

    if (temp_v0->var_18_0x08000000) {
        auPlaySound(0x4A);
        temp_v0->var_18_0x08000000 = 0;
    } else {
        if (func_camera_check_801E2CC0() >= func_camera_check_801E2E04()) {
            return;
        }
        auPlaySound(0x49);
        temp_v0->var_18_0x08000000 = 1;
    }

    if (arg0) {
        func_camera_check_801DEA20(D_camera_check_80208960, 4);
    } else {
        func_camera_check_801DD630(D_camera_check_80208960 - ((s32) D_camera_check_80208960 % 6), 0);
    }
}

void func_camera_check_801E0118(s32 arg0) {
    void* sp1C;
    s16 temp_a0;
    UnkIndigoHalibut* temp_v0;

    if ((func_800BFCA0_5CB40(5) != 0) &&
        (temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960), (temp_v0 != NULL))) {
        if (temp_v0->var_18_0x10000000) {
            auPlaySound(0x4A);
            temp_v0->var_18_0x10000000 = 0;
            return;
        }
        temp_a0 = temp_v0->var_8;
        if (((temp_a0 == 0x270F) | (temp_a0 < 0x98)) == 0) {
            func_camera_check_801E2984(temp_a0);
            auPlaySound(0x49);
            temp_v0->var_18_0x10000000 = 1;
        }
    }
}

void func_camera_check_801E01C0(s32 arg0) {
    UNUSED s32 pad;
    s16 temp_a0;
    UnkIndigoHalibut* temp_v0;

    temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
    if (temp_v0 == NULL) {
        return;
    }

    if (temp_v0->var_18_0x20000000) {
        auPlaySound(0x4A);
        temp_v0->var_18_0x20000000 = 0;
        return;
    }

    temp_a0 = temp_v0->var_8;
    if (temp_a0 == 0x270F) {
        return;
    }

    if (temp_a0 < 0x98) {
        func_camera_check_801E2984(temp_a0);
        auPlaySound(0x49);
        temp_v0->var_18_0x20000000 = 1;
    }
}

void func_camera_check_801E0258(s32 arg0) {
    func_camera_check_801DDD28(0);
    func_camera_check_801DE80C(0, D_camera_check_80208960, 0);
    func_camera_check_801DDA44(0);
    if (arg0 == 0) {
        func_camera_check_801DD6D0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 21);
    }
    func_803713EC_844B9C(3);
}

void func_camera_check_801E02D0(void) {
    func_camera_check_801DDD28(0);
    func_camera_check_801DDA44(0);
    func_camera_check_801DDAD8(1);
    func_camera_check_801DE80C(1, D_camera_check_80208960, 0);
    func_camera_check_801DE288(func_camera_check_801E24D8(D_camera_check_80208960));
    func_camera_check_801DDD28(1);
}

void func_camera_check_801E0330(void) {
    func_camera_check_801DDD28(0);
    func_camera_check_801DE80C(0, D_camera_check_80208960, 0);
    func_camera_check_801DDA44(0);
    func_803713EC_844B9C(7);
}

void func_camera_check_801E0374(void) {
    if (D_camera_check_80208960 <= 0) {
        func_803713EC_844B9C(1);
    } else {
        func_803713D4_844B84(1);
    }
    if (D_camera_check_80208960 >= (func_camera_check_801E2534() - 1)) {
        func_803713EC_844B9C(2);
        return;
    }
    func_803713D4_844B84(2);
}

void func_camera_check_801E03EC(void) {
    if ((D_camera_check_80208960 - (D_camera_check_80208960 % 6)) <= 0) {
        func_803713EC_844B9C(1);
    } else {
        func_803713D4_844B84(1);
    }
    if ((D_camera_check_80208960 - (D_camera_check_80208960 % 6)) >= (func_camera_check_801E2534() - 6)) {
        func_803713EC_844B9C(2);
        return;
    }
    func_803713D4_844B84(2);
}

void func_camera_check_801E0480(void) {
    func_803713EC_844B9C(1);
    func_803713EC_844B9C(2);
}

void nullsub() {
}

s32 func_camera_check_801E04B0(UnkIndigoHalibut* arg0) {
    if (arg0 == NULL) {
        return 0;
    }

    if (func_8009BB4C(arg0->var_8) >= 0x3F) {
        return 1;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E04F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E0B5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E0F10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E15B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E1918.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E1BD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E1EA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E21E8.s")
