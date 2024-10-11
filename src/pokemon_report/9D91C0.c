#include "common.h"

#include "window/window.h"
#include "pokemon_report.h"

typedef struct Unk8 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[0x4];
} Unk8;

extern s32 D_80202EC0_9F9830;
extern s32 D_80202EC4_9F9834;
extern UIButton D_80202EC8_9F9838[];
extern UIButton D_80202EF8_9F9868[];
extern UIButton D_80202F20_9F9890[];
extern UIButton D_80202F48_9F98B8[];
extern UIButton D_80202F68_9F98D8[];
extern UIButton D_80202F88_9F98F8[];
extern UIButton D_80202FA8_9F9918[];
extern UIButton D_80202FC0_9F9930[];
extern s32 D_80202FF8_9F9968;
extern s32 D_80202FFC_9F996C;
extern s32 D_80203000_9F9970;
extern s32 D_80203004_9F9974;
extern s32 D_80203008_9F9978;
extern s32 D_8020300C_9F997C;
extern s32 D_80203014_9F9984;
extern UIButton* D_80230E10_A27780;
extern UIButton* D_80230E14_A27784;

UIButton* func_801E2850_9D91C0(void) {
    if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
        return D_80202EC8_9F9838;
    } else {
        return D_80202EF8_9F9868;
    }
}

UIButton* func_801E28A0_9D9210(s32 arg0) {
    if (!arg0) {
        return D_80202F20_9F9890;
    } else {
        return D_80202F48_9F98B8;
    }
}

s32 func_801E28D8_9D9248(UnkStruct800BEDF8* arg0, s32* arg1) {
    if (arg0 == NULL) {
        D_80202FF8_9F9968 = -1;
        if (arg1 != NULL) {
            FocusMark_SetPos(0x16, (*arg1 * 24) + 29);
            FocusMark_SetSize(0x3E, 0xC);
        } else {
            FocusMark_SetTargetSize(0x3E, 0xC);
        }
        return 0;
    }

    FocusMark_SetTargetPos(22, (*arg1 * 24) + 29);

    if ((arg0->pressedButtons & 0x10000) && !(arg0->currentButtons & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 7) % 8;
        } while (D_80230E14_A27784[*arg1].id == 35);
        auPlaySound(SOUND_ID_65);
    }
    if ((arg0->pressedButtons & 0x20000) && !(arg0->currentButtons & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while (D_80230E14_A27784[*arg1].id == 35);
        auPlaySound(SOUND_ID_65);
    }
    if (arg0->pressedButtons & 0x4000) {
        auPlaySound(SOUND_ID_67);
        return -1;
    }
    return 0;
}

s32 func_801E2AC0_9D9430(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2) {
    if (arg0 == NULL) {
        D_80202FFC_9F996C = -1;
        D_80203000_9F9970 = -1;
        return 0;
    }
    if ((arg0->pressedButtons & 0x20000) && *arg2 <= 0) {
        (*arg2)++;
    }
    if ((arg0->pressedButtons & 0x10000) && *arg2 > 0) {
        (*arg2)--;
    }
    if ((arg0->pressedButtons & 0x40000) && *arg1 < 2) {
        (*arg1)++;
    }
    if (arg0->pressedButtons & 0x80000) {
        if (*arg1 <= 0) {
            return 0x80000;
        }
        (*arg1)--;
    }

    if (*arg1 != D_80202FFC_9F996C || *arg2 != D_80203000_9F9970) {
        if (D_80202FFC_9F996C >= 0) {
            auPlaySound(SOUND_ID_69);
        }
        D_80202FFC_9F996C = *arg1;
        D_80203000_9F9970 = *arg2;
        D_80202EC4_9F9834 = ((D_80202EC4_9F9834 - (D_80202EC4_9F9834 % 6)) + (*arg2 * 3)) + *arg1;
        FocusMark_SetTargetPos((*arg1 * 69) + 107, (*arg2 * 55) + 56);
    }
    return 0;
}

s32 func_801E2CF8_9D9668(UnkStruct800BEDF8* arg0, s32* arg1) {
    if (arg0 == NULL) {
        D_80203004_9F9974 = -1;
        *arg1 = func_801DF020_9D5990(0);
        return 0;
    }
    if (arg0->pressedButtons & 0x20000) {
        *arg1 = func_801DF020_9D5990(2);
    }
    if (arg0->pressedButtons & 0x10000) {
        *arg1 = func_801DF020_9D5990(1);
    }
    if (!(arg0->currentButtons & 0x20000) && !(arg0->currentButtons & 0x10000) && (arg0->pressedButtons & 0x40000)) {
        *arg1 = func_801DF020_9D5990(4);
    }
    if (!(arg0->currentButtons & 0x20000) && !(arg0->currentButtons & 0x10000) && (arg0->pressedButtons & 0x80000)) {
        *arg1 = func_801DF020_9D5990(3);
    }
    if (*arg1 != D_80203004_9F9974) {
        if (D_80203004_9F9974 >= 0) {
            func_801DE078_9D49E8(1);
            if (arg0->pressedButtons & 0x30000) {
                auPlaySound(SOUND_ID_69);
            } else {
                auPlaySound(SOUND_ID_75);
            }
        }
        D_80203004_9F9974 = *arg1;
    }
    return 0;
}

s32 func_801E2EB0_9D9820(void) {
    UnkStruct800BEDF8* sp2C;
    UNUSED s32 pad;

    func_801E1378_9D7CE8();
    func_800AA85C(0x18, 0xC);
    UILayout_CreateButtons(func_801E2850_9D91C0());
    FocusMark_SetTargetSize(0x3E, 0xC);

    while (true) {
        sp2C = func_800AA38C(0);
        if (func_801E28D8_9D9248(sp2C, &D_80202EC0_9F9830) != 0) {
            func_801E1568_9D7ED8(0x1E);
            return 5;
        }
        if (sp2C->pressedButtons & 0x8000) {
            auPlaySound(SOUND_ID_66);
            switch (D_80230E14_A27784[D_80202EC0_9F9830].id) {
                case 2:
                    func_801E1568_9D7ED8(0);
                    return 1;
                case 18:
                    func_801E1568_9D7ED8(0x1E);
                    return 2;
                case 25:
                    func_801E1568_9D7ED8(0x1E);
                    return 3;
                case 17:
                    func_801E1568_9D7ED8(0x1E);
                    return 5;
            }
        }
        ohWait(1);
    }
}

s32 func_801E3000_9D9970(void) {
    UnkStruct800BEDF8* sp2C;
    s32 sp28;

    func_801E16DC_9D804C();
    FocusMark_SetTargetSize(0x3E, 0xC);
    sp28 = 0;
    UILayout_CreateButtons(D_80202F20_9F9890);
    UILayout_WaitPanelTransitionComplete();

    while (true) {
        sp2C = func_800AA38C(0);
        switch (D_80203008_9F9978) {
            case 0:
                if (func_801E28D8_9D9248(sp2C, &sp28) != 0) {
                    func_801E1AC4_9D8434();
                    D_80202EC0_9F9830 = 0;
                    func_801E28D8_9D9248(NULL, &D_80202EC0_9F9830);
                    return 0;
                }

                if (sp2C->pressedButtons & 0x8000) {
                    auPlaySound(SOUND_ID_66);
                    switch (D_80230E14_A27784[sp28].id) {
                        case 29:
                            if (func_800BF864_5C704() != 0) {
                                func_801DDCD4_9D4644(1);
                                func_801DE078_9D49E8(1);
                                FocusMark_Show(false);
                                func_801E2CF8_9D9668(NULL, &D_8020300C_9F997C);
                                func_800AA85C(0x18, 6);
                                D_80203008_9F9978 = 1;
                            }
                            break;
                        case 0:
                            sp28 = 0;
                            UILayout_CreateButtons(D_80202FC0_9F9930);
                            UILayout_WaitPanelTransitionComplete();
                            D_80203008_9F9978 = 4;
                            break;
                        case 31:
                            func_801E1AC4_9D8434();
                            D_80202EC0_9F9830 = 0;
                            func_801E28D8_9D9248(NULL, &D_80202EC0_9F9830);
                            return 0;
                    }
                }
                break;
            case 1:
                func_801E2CF8_9D9668(sp2C, &D_8020300C_9F997C);
                if (sp2C->pressedButtons & 0x4000) {
                    auPlaySound(SOUND_ID_67);
                    func_801DDCD4_9D4644(0);
                    func_801DE078_9D49E8(0);
                    func_801E28D8_9D9248(NULL, NULL);
                    FocusMark_Show(true);
                    func_800AA85C(0x18, 0xC);
                    D_80203008_9F9978 = 0;
                }
                if (sp2C->pressedButtons & 0x8000) {
                    auPlaySound(SOUND_ID_66);
                    func_801DE898_9D5208(0);
                    func_801DEC60_9D55D0(0, 0);
                    D_80203008_9F9978 = 2;
                }
                break;
            case 2:
                if (func_801E28D8_9D9248(sp2C, &sp28) != 0) {
                    func_801DE898_9D5208(1);
                    FocusMark_Show(false);
                    func_801DDCD4_9D4644(1);
                    func_801DE078_9D49E8(1);
                    func_801E2CF8_9D9668(NULL, &D_8020300C_9F997C);
                    func_800AA85C(0x18, 6);
                    D_80203008_9F9978 = 1;
                } else if (sp2C->pressedButtons & 0x8000) {
                    auPlaySound(SOUND_ID_66);

                    switch (D_80230E14_A27784[sp28].id) {
                        case 28:
                            UILayout_CreateButtons(D_80202FA8_9F9918);
                            FocusMark_SetTargetPos(0x16, 0xC5);
                            func_801DE7F8_9D5168(1);
                            UILayout_WaitPanelTransitionComplete();
                            D_80203008_9F9978 = 3;
                            break;
                        case 5:
                            func_801DE898_9D5208(1);
                            FocusMark_Show(false);
                            func_801E2CF8_9D9668(NULL, &D_8020300C_9F997C);
                            func_800AA85C(0x18, 6);
                            func_801DDCD4_9D4644(1);
                            func_801DE078_9D49E8(1);
                            D_80203008_9F9978 = 1;
                    }
                } else {
                    if (sp2C->pressedButtons & 0x40000) {
                        D_8020300C_9F997C = func_801DEC60_9D55D0(0, 4);
                    }
                    if (sp2C->pressedButtons & 0x80000) {
                        D_8020300C_9F997C = func_801DEC60_9D55D0(0, 3);
                    }
                }
                break;
            case 3:
                if (sp2C->pressedButtons & 0x8000) {
                    auPlaySound(SOUND_ID_66);
                }
                if (sp2C->pressedButtons & 0x4000) {
                    auPlaySound(SOUND_ID_67);
                }

                if (sp2C->pressedButtons & 0xC000) {
                    UILayout_CreateButtons(D_80202F48_9F98B8);
                    FocusMark_SetTargetPos(0x16, 0x1D);
                    func_801DE7F8_9D5168(0);
                    UILayout_WaitPanelTransitionComplete();
                    D_80203008_9F9978 = 2;
                    break;
                }

                if (sp2C->pressedButtons & 0x40000) {
                    D_8020300C_9F997C = func_801DEC60_9D55D0(1, 4);
                }
                if (sp2C->pressedButtons & 0x80000) {
                    D_8020300C_9F997C = func_801DEC60_9D55D0(1, 3);
                }
                break;
            case 4:
                if (func_801E28D8_9D9248(sp2C, &sp28) != 0) {
                    sp28 = 1;
                    func_801E28D8_9D9248(NULL, NULL);
                    UILayout_CreateButtons(D_80202F20_9F9890);
                    UILayout_WaitPanelTransitionComplete();
                    D_80203008_9F9978 = 0;
                } else if (sp2C->pressedButtons & 0x8000) {
                    if (D_80230E14_A27784[sp28].id == 5) {
                        auPlaySound(SOUND_ID_66);
                        func_801DDCD4_9D4644(0);
                        func_801DE078_9D49E8(0);
                        FocusMark_Show(true);
                        sp28 = 1;
                        UILayout_CreateButtons(D_80202F20_9F9890);
                        UILayout_WaitPanelTransitionComplete();
                        D_80203008_9F9978 = 0;
                    } else {
                        auPlaySound(0x44);
                        func_801DE5A8_9D4F18(D_80230E14_A27784[sp28].id);
                    }
                }
        }
        ohWait(1);
    }
}

s32 func_801E3604_9D9F74(void) {
    UnkStruct800BEDF8* sp3C;
    s32 sp38;
    UNUSED s32 pad;
    bool sp30;
    s32 sp2C;
    s32 sp28;
    UNUSED s32 pad2;

    sp30 = 0;
    sp2C = 0;
    sp28 = 0;
    func_801E1BEC_9D855C();
    sp38 = 0;
    UILayout_CreateButtons(D_80202F68_9F98D8);
    func_801E28D8_9D9248(NULL, &sp38);
    FocusMark_Show(true);

    while (true) {
        sp3C = func_800AA38C(0);
        if (!sp30) {

            if (func_801E28D8_9D9248(sp3C, &sp38) != 0) {
                func_801E1F20_9D8890();
                D_80202EC0_9F9830 = 2;
                func_801E28D8_9D9248(NULL, &D_80202EC0_9F9830);
                return 0;
            }
            if (sp3C->pressedButtons & 0x8000) {
                auPlaySound(SOUND_ID_66);
                switch (D_80230E14_A27784[sp38].id) {
                    case 29:
                        sp2C = 0;
                        sp28 = 0;
                        FocusMark_SetTargetSize(0x32, 0x25);
                        func_801E2AC0_9D9430(NULL, &sp2C, &sp28);
                        sp30 = true;
                        break;
                    case 31:
                        func_801E1F20_9D8890();
                        D_80202EC0_9F9830 = 2;
                        func_801E28D8_9D9248(NULL, &D_80202EC0_9F9830);
                        return 0;
                }
            }
        } else {
            func_801E2AC0_9D9430(sp3C, &sp2C, &sp28);
            if (sp3C->pressedButtons & 0x4000) {
                auPlaySound(SOUND_ID_67);
                FocusMark_SetTargetSize(0x3E, 0xC);
                func_801E28D8_9D9248(NULL, NULL);
                sp30 = false;
                UIElement_Draw(func_801DCF40_9D38B0());
            } else if (sp3C->pressedButtons & 0x8000) {
                if (func_800BF3D4_5C274(func_801DCCF0_9D3660((sp28 * 3) + sp2C))) {
                    auPlaySound(SOUND_ID_71);
                    func_801E0D84_9D76F4();
                    func_801DFC20_9D6590((sp28 * 3) + sp2C);
                    FocusMark_Show(false);
                    func_801E0C3C_9D75AC((sp28 * 3) + sp2C);
                    FocusMark_Show(true);
                    func_801E0D54_9D76C4();
                } else {
                    auPlaySound(0x47U);
                    FocusMark_Show(false);
                    func_801DFB10_9D6480((sp28 * 3) + sp2C);
                    func_801E0C3C_9D75AC((sp28 * 3) + sp2C);
                    FocusMark_Show(true);
                    func_801DFB10_9D6480(-1);
                }
            }
        }
        ohWait(1);
    }
}

s32 func_801E38DC_9DA24C(void) {
    UnkStruct800BEDF8* sp2C;
    s32 sp28;

    func_801E20B4_9D8A24();
    sp28 = 0;
    func_801E28D8_9D9248(NULL, NULL);
    UILayout_CreateButtons(D_80202F88_9F98F8);
    FocusMark_SetTargetPos(0x16, 0x1D);
    FocusMark_SetTargetSize(0x3E, 0xC);
    UILayout_WaitPanelTransitionComplete();
    FocusMark_Show(true);

    while (true) {
        sp2C = func_800AA38C(0);

        switch (D_80203014_9F9984) {
            case 0:
                if (func_801E28D8_9D9248(sp2C, &sp28) != 0) {
                    func_801E2340_9D8CB0();
                    D_80202EC0_9F9830 = 1;
                    func_801E28D8_9D9248(NULL, &D_80202EC0_9F9830);
                    return 0;
                }
                if (sp2C->pressedButtons & 0x8000) {
                    auPlaySound(SOUND_ID_66);

                    switch (D_80230E14_A27784[sp28].id) {
                        case 28:
                            UILayout_CreateButtons(D_80202FA8_9F9918);
                            FocusMark_SetTargetPos(0x16, 0xC5);
                            func_801E00E0_9D6A50(1);
                            UILayout_WaitPanelTransitionComplete();
                            D_80203014_9F9984 = 3;
                            break;
                        case 31:
                            func_801E2340_9D8CB0();
                            D_80202EC0_9F9830 = 1;
                            func_801E28D8_9D9248(NULL, &D_80202EC0_9F9830);
                            return 0;
                    }
                }
                break;
            case 3:
                if (sp2C->pressedButtons & 0x8000) {
                    auPlaySound(SOUND_ID_66);
                }
                if (sp2C->pressedButtons & 0x4000) {
                    auPlaySound(SOUND_ID_67);
                }
                if (sp2C->pressedButtons & 0xC000) {
                    UILayout_CreateButtons(D_80202F88_9F98F8);
                    FocusMark_SetTargetPos(0x16, 0x1D);
                    func_801E00E0_9D6A50(0);
                    UILayout_WaitPanelTransitionComplete();
                    D_80203014_9F9984 = 0;
                }
                break;
        }
        ohWait(1);
    }
}

void func_801E3B18_9DA488(void) {
    UNUSED s32 pad;
    u32 sp18;

    sp18 = 0;
    D_80230E10_A27780 = func_801E2850_9D91C0();
    D_80230E14_A27784 = UILayout_GetButtons();
    FocusMark_MoveFront();
    D_80202EC0_9F9830 = 0;
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);

    while (true) {
        switch (sp18) {
            case 0:
                sp18 = func_801E2EB0_9D9820();
                break;
            case 1:
                sp18 = func_801E3000_9D9970();
                break;
            case 2:
                sp18 = func_801E3604_9D9F74();
                break;
            case 3:
                sp18 = func_801E38DC_9DA24C();
                break;
            case 5:
                return;
        }
    }
}
