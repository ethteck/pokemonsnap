#include "common.h"

void func_8009FBC4(void);
extern s32 D_801E54C8_AAA508;

void func_801DC8A0_AA18E0(s32 arg0) {
    if (arg0 == 4) {
        PANIC();
    }
    if (arg0 == 2) {
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
        contPrinterSendCommand(0x10);
    }
    D_801E54C8_AAA508 = arg0;
    if (arg0 == 0) {
        func_8009FBC4();
    }
    func_800067DC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DC930_AA1970.s")

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DC9BC_AA19FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DC9D0_AA1A10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DCCD4_AA1D14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DCCDC_AA1D1C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DD010_AA2050.s")
