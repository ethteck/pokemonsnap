#include "common.h"

void func_801DE87C_9FC53C(void);
void func_801DEE88_9FCB48();
void func_801DF8A4_9FD564(UNK_PTR, s32*);
extern s32 D_802308A4_A4E564;

u32 func_801E0328_9FDFE8();
u32 func_801E04E8_9FE1A8();
u32 func_801E06F0_9FE3B0();
u32 func_801E08FC_9FE5BC(int);
u32 func_801E0B7C_9FE83C();
s32 func_80370600();
extern s32 D_801EA294_A07F54;
extern s32 D_802308A0_A4E560;
extern s32 D_801DC904;

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801DF850_9FD510.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801DF8A4_9FD564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801DFA94_9FD754.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801DFE74_9FDB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801E006C_9FDD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801E0328_9FDFE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801E04E8_9FE1A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801E06F0_9FE3B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801E08FC_9FE5BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FD510/func_801E0B7C_9FE83C.s")

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
    D_802308A0_A4E560 = func_80370600();
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
