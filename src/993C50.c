#include "common.h"

#include "sys/oh.h"

#include "photocheck.h"

extern char D_801F4150_9A3BC0[];
extern s32 D_801F4144_9A3BB4;
extern s32 D_801F4148_9A3BB8;
extern s32 D_801F4180_9A3BF0;
extern void* D_80229190_9D8C00;
extern s32 D_80229194_9D8C04;

void func_800AA85C(s32, s32);
void func_800AA870(s32);
s32 func_800BFB84_5CA24(void);
s32 func_801DCCE0_98C750(void);
void func_801DD9E4_98D454(s32);
void func_801DDA68_98D4D8(s32);
void func_801E3934_9933A4(void);
void func_801E43AC_993E1C();
void func_801E4BA0_994610(s32);
s32 func_8036FFE0_843790(s32, s32);
void func_80370004_8437B4(s32, s32);
void func_8037005C_84380C(s32, s32);
void func_80370134_8438E4(void);
s32 func_80370600_843DB0(void);

void* func_801E41E0_993C50(void) {
    return D_801F4150_9A3BC0;
}

s32 func_801E41FC_993C6C(UnkStruct800BEDF8* arg0, s32* arg1) {
    if (arg0 == NULL) {
        func_80370004_8437B4(0x3C, 0x27);
        func_8037005C_84380C(0x36, 0x29);
        func_803700A4_843854(1);
        D_801F4180_9A3BF0 = -1;
        return 0;
    }
    if (arg0->unk_18 & 0x40000 && *arg1 <= 0) {
        *arg1 += 1;
    }
    if (arg0->unk_18 & 0x80000 && *arg1 > 0) {
        *arg1 -= 1;
    }
    if (*arg1 != D_801F4180_9A3BF0) {
        D_801F4180_9A3BF0 = *arg1;
        func_800228E4(0x45);
        func_8036FFE0_843790((*arg1 * 0x93) + 0x3C, 0x27);
    }
    return 0;
}

void func_801E433C_993DAC(s32 arg0) {
    s32 sp1C;

    sp1C = func_801DCCE0_98C750();
    func_8036A8E4_83E094(sp1C);
    func_8036EE40_8425F0();
    func_8036B9EC_83F19C(sp1C, 0, 0);
    func_8036CB58_840308(sp1C, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
}

void func_801E43AC_993E1C(void) {
    func_801DDA68_98D4D8(1);
    func_801DD9E4_98D454(0);
    func_803713EC_844B9C(7);
}

s32 func_801E43E4_993E54(void) {
    UNUSED s32 pad[3];

    func_801E43AC_993E1C();
    func_801E3934_9933A4();
    func_80370004_8437B4(0x15, 0xC5);
    return 9;
}

s32 func_801E4428_993E98(void) {
    s32 sp24 = 2;

    D_80229190_9D8C00 = &D_801F4150_9A3BC0;
    D_80229194_9D8C04 = func_80370600_843DB0();
    D_801F4144_9A3BB4 = 0;
    D_801F4148_9A3BB8 = func_800BFB84_5CA24();
    func_80370134_8438E4();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);
    func_801E4BA0_994610(0);

    while (TRUE) {
        func_801E433C_993DAC(sp24);
        switch (sp24) {
            case 2:
                sp24 = func_801E43E4_993E54();
                break;
            case 9:
                return -1;
        }

        ohWait(1);
    }
}
