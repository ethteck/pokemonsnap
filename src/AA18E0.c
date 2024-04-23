#include "common.h"
#include "sys/oh.h"

void func_8009FA68(void* arg0, s32* arg1);
extern s32 D_801E550C_AAA54C;
extern u8 D_801E54C0_AAA500;
extern u8 D_801E54C4_AAA504;
extern s32 D_801E54C8_AAA508;
extern SceneSetup D_801E552C_AAA56C;
extern s32 D_801E553C_AAA57C;
extern s32 D_801E55D8_AAA618;

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

void func_801DC930_AA1970(void* arg0, s32* arg1) {
    GObj* obj;

    func_8009FA68(arg0, arg1);
    obj = omGObjListHead[D_801E54C0_AAA500];
    while (obj != NULL) {
        ohPauseObjectProcesses(obj);
        obj = obj->next;
    }
    obj = omGObjListHead[D_801E54C4_AAA504];
    while (obj != NULL) {
        ohPauseObjectProcesses(obj);
        obj = obj->next;
    }
}

void func_801DC9BC_AA19FC(s32 unused) {
    D_801E550C_AAA54C = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DC9D0_AA1A10.s")

void func_801DCCD4_AA1D14(s32 unused) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/AA18E0/func_801DCCDC_AA1D1C.s")

s32 func_801DD010_AA2050(s32 arg0) {
    D_801E55D8_AAA618 = arg0;
    D_801E553C_AAA57C = 0x2D4000;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801E552C_AAA56C);
    return D_801E54C8_AAA508;
}
