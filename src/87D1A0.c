#include "common.h"

typedef struct Foo {
    /* 0x00 */ u32 var_0;
    /* 0x04 */ char pad_4[4];
    /* 0x08 */ s16 var_8;
    /* 0x0A */ char pad_A[0x12 - 4];
    /* 0x18 */ s32 var_18_0x80000000 : 1;
    /* 0x18 */ s32 var_18_0x40000000 : 1;
    /* 0x18 */ s32 var_18_0x20000000 : 1;
    /* 0x18 */ s32 var_18_0x10000000 : 1;
    /* 0x18 */ s32 var_18_0x08000000 : 1;
} Foo; // size: 0x1C

typedef struct Bar {
    s32 var_0;
} UnkDesertMackerel;

extern UnkDesertMackerel D_80208994_8A6184;
extern UnkDesertMackerel D_802089BC_8A61AC;
extern s32 D_80208960_8A6150;

int func_803713EC(int);
void func_801DDA44_87B234(int);
void func_801DDD28_87B518(int);
void func_801DE80C_87BFFC(int, s32, int);
int func_8009BB4C(int);
void func_801DDAD8_87B2C8(int);
void func_801DE288_87BA78(void*);
Foo* func_801E24D8_87FCC8(s32);
void func_801DD6D0_87AEC0(int, int);
s32 func_801E2534_87FD24(void);
void func_803713D4(int);
void func_801E2984_880174(s16);
int func_801E2CC0_8804B0(void);
int func_801E2E04_8805F4(void);
void func_801DEA20_87C210(int, int);
void func_801DD630_87AE20(int, int);

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801DF9B0_87D1A0.s")

UnkDesertMackerel* func_801DFA4C_87D23C(void) {
    if (func_800BFCA0_5CB40(8) == 0) {
        return &D_80208994_8A6184;
    }
    return &D_802089BC_8A61AC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801DFA80_87D270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801DFCD4_87D4C4.s")

void func_801E0034_87D824(s32 arg0) {
    s32 pad;
    Foo* temp_v0;

    temp_v0 = func_801E24D8_87FCC8(D_80208960_8A6150);
    if (temp_v0 == NULL) {
        return;
    }

    if (temp_v0->var_18_0x08000000) {
        func_800228E4(0x4A);
        temp_v0->var_18_0x08000000 = 0;
    } else {
        if (func_801E2CC0_8804B0() >= func_801E2E04_8805F4()) {
            return;
        }
        func_800228E4(0x49);
        temp_v0->var_18_0x08000000 = 1;
    }

    if (arg0) {
        func_801DEA20_87C210(D_80208960_8A6150, 4);
    } else {
        func_801DD630_87AE20(D_80208960_8A6150 - ((s32) D_80208960_8A6150 % 6), 0);
    }
}

void func_801E0118_87D908(s32 arg0) {
    void* sp1C;
    s16 temp_a0;
    Foo* temp_v0;

    if ((func_800BFCA0_5CB40(5) != 0) && (temp_v0 = func_801E24D8_87FCC8(D_80208960_8A6150), (temp_v0 != NULL))) {
        if (temp_v0->var_18_0x10000000) {
            func_800228E4(0x4A);
            temp_v0->var_18_0x10000000 = 0;
            return;
        }
        temp_a0 = temp_v0->var_8;
        if (((temp_a0 == 0x270F) | (temp_a0 < 0x98)) == 0) {
            func_801E2984_880174(temp_a0);
            func_800228E4(0x49);
            temp_v0->var_18_0x10000000 = 1;
        }
    }
}

void func_801E01C0_87D9B0(s32 arg0) {
    UNUSED s32 pad;
    s16 temp_a0;
    Foo* temp_v0;

    temp_v0 = func_801E24D8_87FCC8(D_80208960_8A6150);
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
        func_801E2984_880174(temp_a0);
        func_800228E4(0x49);
        temp_v0->var_18_0x20000000 = 1;
    }
}

void func_801E0258_87DA48(s32 arg0) {
    func_801DDD28_87B518(0);
    func_801DE80C_87BFFC(0, D_80208960_8A6150, 0);
    func_801DDA44_87B234(0);
    if (arg0 == 0) {
        func_801DD6D0_87AEC0(D_80208960_8A6150 - (D_80208960_8A6150 % 6), 21);
    }
    func_803713EC(3);
}

void func_801E02D0_87DAC0(void) {
    func_801DDD28_87B518(0);
    func_801DDA44_87B234(0);
    func_801DDAD8_87B2C8(1);
    func_801DE80C_87BFFC(1, D_80208960_8A6150, 0);
    func_801DE288_87BA78(func_801E24D8_87FCC8(D_80208960_8A6150));
    func_801DDD28_87B518(1);
}

void func_801E0330_87DB20(void) {
    func_801DDD28_87B518(0);
    func_801DE80C_87BFFC(0, D_80208960_8A6150, 0);
    func_801DDA44_87B234(0);
    func_803713EC(7);
}

void func_801E0374_87DB64(void) {
    if (D_80208960_8A6150 <= 0) {
        func_803713EC(1);
    } else {
        func_803713D4(1);
    }
    if (D_80208960_8A6150 >= (func_801E2534_87FD24() - 1)) {
        func_803713EC(2);
        return;
    }
    func_803713D4(2);
}

void func_801E03EC_87DBDC(void) {
    if ((D_80208960_8A6150 - (D_80208960_8A6150 % 6)) <= 0) {
        func_803713EC(1);
    } else {
        func_803713D4(1);
    }
    if ((D_80208960_8A6150 - (D_80208960_8A6150 % 6)) >= (func_801E2534_87FD24() - 6)) {
        func_803713EC(2);
        return;
    }
    func_803713D4(2);
}

void func_801E0480_87DC70(void) {
    func_803713EC(1);
    func_803713EC(2);
}

void nullsub() {
}

s32 func_801E04B0_87DCA0(Foo* arg0) {
    if (arg0 == NULL) {
        return 0;
    }

    if (func_8009BB4C(arg0->var_8) >= 0x3F) {
        return 1;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801E04F4_87DCE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801E0B5C_87E34C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801E0F10_87E700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801E15B4_87EDA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801E1918_87F108.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801E1BD4_87F3C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801E1EA4_87F694.s")

#pragma GLOBAL_ASM("asm/nonmatchings/87D1A0/func_801E21E8_87F9D8.s")
