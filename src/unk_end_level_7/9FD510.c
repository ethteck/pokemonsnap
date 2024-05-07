#include "common.h"

typedef struct UnkCanaryScallop {
    s32 unk_0;
    s32 unk_4;
} UnkCanaryScallop;

void func_801DE87C_9FC53C(void);
void func_801DEE88_9FCB48();
s32 func_801DF8A4_9FD564(UNK_PTR, s32*);
s32 func_801E0F6C_9FEC2C(void);
s32 func_801E0FAC_9FEC6C(s32);
u32 func_801E0328_9FDFE8();
u32 func_801E04E8_9FE1A8();
s32 func_801E0B7C_9FE83C();
UNK_PTR func_80370600_843DB0();
void func_801DD860_9FB520(void);
void func_801DDC50_9FB910(s32);
void func_801DE2E0_9FBFA0(s32);
void func_801E006C_9FDD2C(UnkStruct800BEDF8*, s32*, s32*, s32);
s32 func_801E1008_9FECC8(void);
void func_801E1170_9FEE30(s32, UNK_TYPE);
void func_801E1318_9FEFD8(void);
void func_80370038(UNK_TYPE, UNK_TYPE);
void func_803700A4(UNK_TYPE);
void func_801DDCA8_9FB968(int);
void func_801DFA94_9FD754(UnkStruct800BEDF8*, s32*, s32*, int);
s32 func_801E0F50_9FEC10(void);
s32 func_801E0FE4_9FECA4(s32);
UnkStruct800BEDF8* func_801DD1A8_9FAE68();
void func_801DE5D0_9FC290(UNK_TYPE);
void func_801E1024_9FECE4(s32 arg0, s32 arg1);
void func_801DE04C_9FBD0C(int, int);
void func_80370090(int);

extern s32 D_801DC904;
extern s32 D_801EA288_A07F48;
extern s32 D_801EA28C_A07F4C;
extern s32 D_801EA294_A07F54;
extern UnkCanaryScallop* D_802308A0_A4E560;
extern s32 D_802308A4_A4E564;
extern s32 D_802308A8_A4E568;
extern s32 D_802308AC_A4E56C;
extern s32 D_802308B0_A4E570;
extern s32 D_802308B4_A4E574;
extern s32 D_802308B8_A4E578;

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801DF850_9FD510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801DF8A4_9FD564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801DFA94_9FD754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801DFE74_9FDB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801E006C_9FDD2C.s")

u32 func_801E0328_9FDFE8(void) {
    UnkStruct800BEDF8* sp24;
    UNUSED s32 pad;
    s32 sp1C;

    func_80370038(0x3E, 0xC);
    func_803700A4(1);
    func_801DF8A4_9FD564(NULL, &D_802308A4_A4E564);
    sp1C = -1;

    while (1) {
        ohWait(1);
        sp24 = func_800AA38C(0);
        if (func_801DF8A4_9FD564((void*) sp24, &D_802308A4_A4E564) != 0) {
            if (D_802308A4_A4E564 != sp1C) {
                func_801DDCA8_9FB968(7);
            }
            auPlaySound(0x43U);
            sp1C = D_802308A4_A4E564 = 7;
        }
        if (sp24->unk_18 & 0x8000) {
            switch (D_802308A0_A4E560[D_802308A4_A4E564].unk_0) {
                case 2:
                    auPlaySound(0x42U);
                    return 1U;
                case 3:
                    if (func_801E0F50_9FEC10() != 0) {
                        auPlaySound(0x42U);
                        return 3U;
                    }
                    auPlaySound(0x55U);
                    ohWait(0xA);
                    continue;
                case 26:
                    auPlaySound(0x42U);
                    return 5U;
                case 20:
                    auPlaySound(0x42U);
                    return 6U;
                case 32:
                    if (contIsPrinterAvailable() != 0) {
                        auPlaySound(0x42U);
                        return 7U;
                    }
                    auPlaySound(0x55U);
                    ohWait(0xA);
                    continue;
                case 4:
                    auPlaySound(0x42U);
                    return 8U;
            }
        }
    }
}

u32 func_801E04E8_9FE1A8(void) {
    UnkStruct800BEDF8* sp1C;

    D_802308A4_A4E564 = 0;
    D_801EA294_A07F54 = D_801EA288_A07F48;
    func_803700A4(0);
    func_801DE5D0_9FC290(2);
    D_802308AC_A4E56C = 0;
    D_802308A8_A4E568 = 0;
    func_80370038(0x32, 0x25);
    func_803700A4(1);
    func_801DFA94_9FD754(NULL, &D_802308A8_A4E568, &D_802308AC_A4E56C, 2);
    func_801DDCA8_9FB968(0xB);

    while (1) {
        sp1C = func_800AA38C(0);
        func_801DFA94_9FD754(sp1C, &D_802308A8_A4E568, &D_802308AC_A4E56C, 2);
        if ((D_801EA294_A07F54 - ((s32) D_801EA294_A07F54 % 6)) < (func_801E0F6C_9FEC2C() - 6)) {
            func_803713D4_844B84(2);
        } else {
            func_803713EC_844B9C(2);
        }
        if ((D_801EA294_A07F54 - ((s32) D_801EA294_A07F54 % 6)) > 0) {
            func_803713D4_844B84(1);
        } else {
            func_803713EC_844B9C(1);
        }
        D_801EA288_A07F48 = D_801EA294_A07F54;
        if (sp1C->unk_18 & 0x4000) {
            auPlaySound(0x43U);
            func_803700A4(0);
            func_801DE5D0_9FC290(0);
            func_801E1024_9FECE4(2, -1);
            func_803713EC_844B9C(3);
            func_801DDCA8_9FB968(0);
            return 0U;
        }
        if ((func_801E0FAC_9FEC6C(D_801EA294_A07F54) != 0) && (sp1C->unk_18 & 0x8000)) {
            auPlaySound(0x42U);
            func_803700A4(0);
            func_801E1024_9FECE4(2, D_801EA294_A07F54);
            func_803713EC_844B9C(3);
            func_801DDCA8_9FB968(0xC);
            return 2U;
        }
        ohWait(1);
    }
}

s32 func_801E06F0_9FE3B0(void) {
    UnkStruct800BEDF8* sp1C;

    D_802308A4_A4E564 = 1;
    D_801EA294_A07F54 = D_801EA28C_A07F4C;
    func_803700A4(0);
    func_801DE5D0_9FC290(1);
    D_802308AC_A4E56C = 0;
    D_802308A8_A4E568 = 0;
    func_80370038(0x32, 0x25);
    func_803700A4(1);
    func_801DFA94_9FD754(NULL, &D_802308A8_A4E568, &D_802308AC_A4E56C, 1);
    func_801DDCA8_9FB968(0xB);

    while (1) {

        sp1C = func_800AA38C(0);
        func_801DFA94_9FD754(sp1C, &D_802308A8_A4E568, &D_802308AC_A4E56C, 1);
        if ((D_801EA294_A07F54 - ((s32) D_801EA294_A07F54 % 6)) < (func_801E0F50_9FEC10() - 6)) {
            func_803713D4_844B84(2);
        } else {
            func_803713EC_844B9C(2);
        }
        if ((D_801EA294_A07F54 - ((s32) D_801EA294_A07F54 % 6)) > 0) {
            func_803713D4_844B84(1);
        } else {
            func_803713EC_844B9C(1);
        }
        D_801EA28C_A07F4C = D_801EA294_A07F54;
        if (sp1C->unk_18 & 0x4000) {
            auPlaySound(0x43U);
            func_803700A4(0);
            func_801DE5D0_9FC290(0);
            func_801E1024_9FECE4(1, -1);
            func_803713EC_844B9C(3);
            func_801DDCA8_9FB968(1);
            return 0;
        }
        if ((func_801E0FE4_9FECA4(D_801EA294_A07F54) != 0) && (sp1C->unk_18 & 0x8000)) {
            auPlaySound(0x42U);
            func_803700A4(0);
            func_801E1024_9FECE4(1, D_801EA294_A07F54);
            func_803713EC_844B9C(3);
            func_801DDCA8_9FB968(0xC);
            return 4;
        }
        ohWait(1);
    }
}

s32 func_801E08FC_9FE5BC(s32 arg0) {
    UnkStruct800BEDF8* sp1C;

    if (arg0 == 2) {
        D_802308A4_A4E564 = 0;
    } else {
        D_802308A4_A4E564 = 1;
    }
    func_803700A4(0);
    func_801DE5D0_9FC290(0);
    D_802308B4_A4E574 = 0;
    D_802308B0_A4E570 = 0;
    func_80370038(0x32, 0x25);
    D_802308B8_A4E578 = 1;
    func_801E006C_9FDD2C(NULL, &D_802308B0_A4E570, &D_802308B4_A4E574, D_802308B8_A4E578);
    func_803700A4(1);

    while (1) {
        sp1C = func_800AA38C(0);
        func_801E006C_9FDD2C(sp1C, &D_802308B0_A4E570, &D_802308B4_A4E574, D_802308B8_A4E578);
        if (sp1C->unk_18 & 0x4000) {
            auPlaySound(0x43U);
            func_80370090(1);
            func_803700A4(0);
            func_801DE04C_9FBD0C(-1, -1);
            if (arg0 == 2) {
                return 1;
            } else {
                return 3;
            }
        }

        if (sp1C->unk_18 & 0x8000) {
            func_801E1170_9FEE30((D_802308B4_A4E574 * 2) + D_802308B0_A4E570, 1);
            func_801DDC50_9FB910((D_802308B4_A4E574 * 2) + D_802308B0_A4E570);
            func_801DD860_9FB520();
            sp1C = func_801DD1A8_9FAE68();
            if (sp1C->unk_18 & 0x8000) {
                func_801E1024_9FECE4(0, -1);
                func_80370090(1);
                func_801DF8A4_9FD564(0, &D_802308A4_A4E564);
                return 0;
            } else {
                auPlaySound(0x43U);
                func_801E1170_9FEE30((D_802308B4_A4E574 * 2) + D_802308B0_A4E570, 0);
                func_801DDC50_9FB910((D_802308B4_A4E574 * 2) + D_802308B0_A4E570);
                func_803700A4(1);
                func_801DE04C_9FBD0C((D_802308B0_A4E570 * 0x43) + 0x82, (D_802308B4_A4E574 * 0x38) + 0x2E);
            }
        }

        ohWait(1);
    }
}

s32 func_801E0B7C_9FE83C(void) {
    UnkStruct800BEDF8* sp2C;
    s32 sp28;

    D_802308A4_A4E564 = 2;
    D_802308B4_A4E574 = 0;
    D_802308B0_A4E570 = 0;
    func_803700A4(0);
    func_80370038(0x32, 0x25);
    D_802308B8_A4E578 = 0;
    func_801E006C_9FDD2C(NULL, &D_802308B0_A4E570, &D_802308B4_A4E574, D_802308B8_A4E578);
    func_803700A4(1);

    while (1) {
        ohWait(1);
        sp2C = func_800AA38C(0);
        func_801E006C_9FDD2C(sp2C, &D_802308B0_A4E570, &D_802308B4_A4E574, D_802308B8_A4E578);

        if (sp2C->unk_18 & 0x4000) {

            if (func_801E1008_9FECC8() == 0) {
                auPlaySound(0x43U);
                func_803700A4(0);
                ohWait(1);
                return 0;
            } else {
                func_801E1318_9FEFD8();
                func_801DD860_9FB520();
                D_802308B8_A4E578 = 0;
            }
        }

        if (sp2C->unk_18 & 0x8000) {
            sp28 = (D_802308B4_A4E574 * 2) + D_802308B0_A4E570;
            func_801E1170_9FEE30(sp28, 1);
            if (func_801E1008_9FECC8() != 0) {
                if (D_802308B8_A4E578 == 1) {
                    func_801DDC50_9FB910(sp28);
                }
                func_801DE2E0_9FBFA0(func_801E1008_9FECC8());
                func_801DD860_9FB520();
                D_802308B8_A4E578 = 1;
            } else {
                func_801DDC50_9FB910(sp28);
                D_802308B8_A4E578 = 0;
            }
            func_801DD860_9FB520();
        }
    }
}

s32 func_801E0D50_9FEA10(void) {
    UNUSED s32 pad[2];

    func_801DE87C_9FC53C();
    return 0;
}

s32 func_801E0D80_9FEA40(void) {
    UNK_TYPE sp18[10];

    func_801DEE88_9FCB48();
    if (contIsPrinterAvailable() == 0) {
        func_801DF8A4_9FD564(NULL, &D_802308A4_A4E564);
        D_802308A4_A4E564 = 7;
        func_801DF8A4_9FD564(&sp18, &D_802308A4_A4E564);
    }
    return 0;
}

void func_801E0DEC_9FEAAC(void) {
    UNUSED s32 pad[1];
    u32 sp18;

    sp18 = 0;
    D_802308A0_A4E560 = func_80370600_843DB0();
    if (&D_801DC904 != NULL) {
        D_802308A4_A4E564 = 0;
    } else {
        D_802308A4_A4E564 = 3;
    }
    D_801EA294_A07F54 = 0;
    func_80370134_8438E4();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);

    while (1) {
        switch (sp18) {
            case 0:
                sp18 = func_801E0328_9FDFE8();
                break;
            case 1:
                sp18 = func_801E04E8_9FE1A8();
                break;
            case 2:
                sp18 = func_801E08FC_9FE5BC(2);
                break;
            case 3:
                sp18 = func_801E06F0_9FE3B0();
                break;
            case 4:
                sp18 = func_801E08FC_9FE5BC(1);
                break;
            case 5:
                sp18 = func_801E0B7C_9FE83C();
                break;
            case 6:
                sp18 = func_801E0D50_9FEA10();
                break;
            case 7:
                sp18 = func_801E0D80_9FEA40();
                break;

            case 8:
                return;
        }
    }
}
