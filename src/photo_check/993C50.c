#include "common.h"

#include "sys/oh.h"
#include "../window/window.h"

#include "photo_check.h"

extern char D_801F4150_9A3BC0[];
extern s32 D_801F4144_9A3BB4;
extern s32 D_801F4148_9A3BB8;
extern s32 D_801F4180_9A3BF0;
extern void* D_80229190_9D8C00;
extern UIButton* D_80229194_9D8C04;

s32 func_800BFB84_5CA24(void);
UIElement* func_801DCCE0_98C750(void);
void func_801DD9E4_98D454(s32);
void func_801DDA68_98D4D8(s32);
void func_801E3934_9933A4(void);
void func_801E43AC_993E1C();
void func_801E4BA0_994610(s32);

void* func_801E41E0_993C50(void) {
    return D_801F4150_9A3BC0;
}

s32 func_801E41FC_993C6C(UnkStruct800BEDF8* arg0, s32* arg1) {
    if (arg0 == NULL) {
        FocusMark_SetPos(0x3C, 0x27);
        FocusMark_SetSize(0x36, 0x29);
        FocusMark_Show(true);
        D_801F4180_9A3BF0 = -1;
        return 0;
    }
    if (arg0->pressedButtons & STICK_SLOW_RIGHT && *arg1 <= 0) {
        *arg1 += 1;
    }
    if (arg0->pressedButtons & STICK_SLOW_LEFT && *arg1 > 0) {
        *arg1 -= 1;
    }
    if (*arg1 != D_801F4180_9A3BF0) {
        D_801F4180_9A3BF0 = *arg1;
        auPlaySound(SOUND_ID_69);
        FocusMark_SetTargetPos((*arg1 * 0x93) + 0x3C, 0x27);
    }
    return 0;
}

void func_801E433C_993DAC(s32 arg0) {
    UIElement* sp1C;

    sp1C = func_801DCCE0_98C750();
    UIElement_Draw(sp1C);
    UIButtonImage_DeleteAll();
    UIElement_SetTextPos(sp1C, 0, 0);
    UIElement_SetFont(sp1C, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
}

void func_801E43AC_993E1C(void) {
    func_801DDA68_98D4D8(1);
    func_801DD9E4_98D454(0);
    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT | HEADER_TITLE);
}

s32 func_801E43E4_993E54(void) {
    UNUSED s32 pad[3];

    func_801E43AC_993E1C();
    func_801E3934_9933A4();
    FocusMark_SetPos(0x15, 0xC5);
    return 9;
}

s32 func_801E4428_993E98(void) {
    s32 sp24 = 2;

    D_80229190_9D8C00 = &D_801F4150_9A3BC0;
    D_80229194_9D8C04 = UILayout_GetButtons();
    D_801F4144_9A3BB4 = 0;
    D_801F4148_9A3BB8 = func_800BFB84_5CA24();
    FocusMark_MoveFront();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);
    func_801E4BA0_994610(0);

    while (true) {
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
