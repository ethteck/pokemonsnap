#include "common.h"

typedef struct UnkMaroonHaddock {
    /* 0x00 */ u32 var_0;
    /* 0x04 */ char pad_4[4];
    /* 0x08 */ s16 var_8;
    /* 0x0A */ char pad_A[0x12 - 4];
    /* 0x18 */ s32 var_18_0x80000000 : 1;
    /* 0x18 */ s32 var_18_0x40000000 : 1;
    /* 0x18 */ s32 var_18_0x20000000 : 1;
    /* 0x18 */ s32 var_18_0x10000000 : 1;
    /* 0x18 */ s32 var_18_0x08000000 : 1;
} UnkMaroonHaddock; // size: 0x1C

typedef struct CyanBass {
    s32 var_0;
} UnkCyanBass;

extern UnkCyanBass D_camera_check_80208994;
extern UnkCyanBass D_camera_check_802089BC;
extern s32 D_camera_check_80208960;

int func_803713EC(int);
void func_camera_check_801DDA44(int);
void func_camera_check_801DDD28(int);
void func_camera_check_801DE80C(int, s32, int);
int func_8009BB4C(int);
void func_camera_check_801DDAD8(int);
void func_camera_check_801DE288(void*);
UnkMaroonHaddock* func_camera_check_801E24D8(s32);
void func_camera_check_801DD6D0(int, int);
s32 func_camera_check_801E2534(void);
void func_803713D4(int);
void func_camera_check_801E2984(s16);
int func_camera_check_801E2CC0(void);
int func_camera_check_801E2E04(void);
void func_camera_check_801DEA20(int, int);
void func_camera_check_801DD630(int, int);

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
    UnkMaroonHaddock* temp_v0;

    temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
    if (temp_v0 == NULL) {
        return;
    }

    if (temp_v0->var_18_0x08000000) {
        func_800228E4(0x4A);
        temp_v0->var_18_0x08000000 = 0;
    } else {
        if (func_camera_check_801E2CC0() >= func_camera_check_801E2E04()) {
            return;
        }
        func_800228E4(0x49);
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
    UnkMaroonHaddock* temp_v0;

    if ((func_800BFCA0_5CB40(5) != 0) && (temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960), (temp_v0 != NULL))) {
        if (temp_v0->var_18_0x10000000) {
            func_800228E4(0x4A);
            temp_v0->var_18_0x10000000 = 0;
            return;
        }
        temp_a0 = temp_v0->var_8;
        if (((temp_a0 == 0x270F) | (temp_a0 < 0x98)) == 0) {
            func_camera_check_801E2984(temp_a0);
            func_800228E4(0x49);
            temp_v0->var_18_0x10000000 = 1;
        }
    }
}

void func_camera_check_801E01C0(s32 arg0) {
    UNUSED s32 pad;
    s16 temp_a0;
    UnkMaroonHaddock* temp_v0;

    temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
    if (temp_v0 == NULL) {
        return;
    }

    if (temp_v0->var_18_0x20000000) {
        func_800228E4(0x4A);
        temp_v0->var_18_0x20000000 = 0;
        return;
    }

    temp_a0 = temp_v0->var_8;
    if (temp_a0 == 0x270F) {
        return;
    }

    if (temp_a0 < 0x98) {
        func_camera_check_801E2984(temp_a0);
        func_800228E4(0x49);
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
    func_803713EC(3);
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
    func_803713EC(7);
}

void func_camera_check_801E0374(void) {
    if (D_camera_check_80208960 <= 0) {
        func_803713EC(1);
    } else {
        func_803713D4(1);
    }
    if (D_camera_check_80208960 >= (func_camera_check_801E2534() - 1)) {
        func_803713EC(2);
        return;
    }
    func_803713D4(2);
}

void func_camera_check_801E03EC(void) {
    if ((D_camera_check_80208960 - (D_camera_check_80208960 % 6)) <= 0) {
        func_803713EC(1);
    } else {
        func_803713D4(1);
    }
    if ((D_camera_check_80208960 - (D_camera_check_80208960 % 6)) >= (func_camera_check_801E2534() - 6)) {
        func_803713EC(2);
        return;
    }
    func_803713D4(2);
}

void func_camera_check_801E0480(void) {
    func_803713EC(1);
    func_803713EC(2);
}

void nullsub() {
}

s32 func_camera_check_801E04B0(UnkMaroonHaddock* arg0) {
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
