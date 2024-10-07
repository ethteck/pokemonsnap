#include "common.h"

#include "pokemon_album.h"

s32 D_80208B90_9D2DE0 = false;
s32 D_80208B94_9D2DE4 = 0;

UIButton album_CoverButtonsDef[] = {
    { BUTTON_OPEN, "ひらく" },
    { BUTTON_SPLITTER, NULL },
    { BUTTON_GO_TO_LAB, "けんきゅうじょへ" },
    { BUTTON_END, NULL },
};
UIButton album_AlbumButtonsDef[] = {
    { BUTTON_ENLARGE, "みる" },
    { BUTTON_ARRANGE, "いれかえ" },
    { BUTTON_DELETE, "けす" },
    { BUTTON_SPLITTER, NULL },
    { BUTTON_RETURN_TO_COVER, "ひょうしへ" },
    { BUTTON_END, NULL },
};
UIButton album_PhotoButtonsDef[] = {
    { BUTTON_CHECK, "くわしく" },
    { BUTTON_COMMENT, "コメント" },
    { BUTTON_DELETE, "けす" },
    { BUTTON_SPLITTER, NULL },
    { BUTTON_RETURN, "もどる" },
    { BUTTON_END, NULL },
};

s32 D_80208C18_9D2E68 = -1;
s32 D_80208C1C_9D2E6C = -1;
s32 D_80208C20_9D2E70 = -1;
s32 D_80208C24_9D2E74 = -1;
s32 D_80208C28_9D2E78 = -1;
s32 D_80208C2C_9D2E7C = -1;
s32 D_80208C30_9D2E80 = -1;

UIButton* album_CoverButtons;
UIButton* album_PanelButtons;

UIButton* func_801E1900_9ABB50(void) {
    return album_CoverButtonsDef;
}

s32 func_801E191C_9ABB6C(void) {
    return D_80208B94_9D2DE4;
}

s32 album_GetNextPhotoIndex(s32 index) {
    s32 next = index;

    for (next++; next <= album_GetLastPhotoIndex(); next++) {
        if (album_GetAlbumPhoto(next) != NULL) {
            return next;
        }
    }

    return index;
}

s32 album_GetPreviousPhotoIndex(s32 arg0) {
    s32 i = arg0;

    for (i--; i >= album_GetFirstPhotoIndex(); i--) {
        if (album_GetAlbumPhoto(i) != NULL) {
            return i;
        }
    }

    return arg0;
}

s32 func_801E1A50_9ABCA0(UnkStruct800BEDF8* input, s32* arg1) {
    if (input == NULL) {
        D_80208C18_9D2E68 = -1;
        if (arg1 != NULL) {
            FocusMark_SetPos(22, (*arg1 * 24) + 29);
            FocusMark_SetSize(62, 12);
        } else {
            FocusMark_SetTargetSize(62, 12);
        }
        return 0;
    }

    FocusMark_SetTargetPos(22, (*arg1 * 24) + 29);

    if ((input->pressedButtons & STICK_SLOW_UP) && !(input->currentButtons & (STICK_SLOW_RIGHT | STICK_SLOW_LEFT))) {
        do {
            *arg1 = (*arg1 + 7) % 8;
        } while (album_PanelButtons[*arg1].id == BUTTON_END);
        auPlaySound(0x41);
    }
    if ((input->pressedButtons & STICK_SLOW_DOWN) && !(input->currentButtons & (STICK_SLOW_RIGHT | STICK_SLOW_LEFT))) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while (album_PanelButtons[*arg1].id == BUTTON_END);
        auPlaySound(0x41);
    }
    if (input->pressedButtons & B_BUTTON) {
        return -1;
    }
    return 0;
}

s32 func_801E1C30_9ABE80(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2) {
    if (arg0 == NULL) {
        D_80208C1C_9D2E6C = -1;
        D_80208C20_9D2E70 = -1;
        func_801DE1FC_9A844C(D_80208B94_9D2DE4);
        return 0;
    }
    if ((arg0->pressedButtons & 0x20000) && *arg2 <= 0) {
        (*arg2)++;
    }
    if ((arg0->pressedButtons & 0x10000) && *arg2 > 0) {
        (*arg2)--;
    }
    if (arg0->pressedButtons & 0x40000) {
        if (*arg1 < 2) {
            (*arg1)++;
        } else if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) < func_800BF9EC_5C88C() - 6) {
            auPlaySound(0x4B);
            D_80208B94_9D2DE4 += 6;
            *arg1 = 0;
            FocusMark_SetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DD954_9A7BA4(D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6));
        }
    }
    if (arg0->pressedButtons & 0x80000) {
        if (*arg1 > 0) {
            (*arg1)--;
        } else if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) > 0) {
            auPlaySound(0x4B);
            D_80208B94_9D2DE4 -= 6;
            *arg1 = 2;
            FocusMark_SetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DD954_9A7BA4(D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6));
        }
    }
    if ((*arg1 != D_80208C1C_9D2E6C) || (*arg2 != D_80208C20_9D2E70)) {
        // bug? using the same variable twice. silly mask needed to match
        if (!((D_80208C1C_9D2E6C < 0) & 0xFFFFFFFF) || !(D_80208C1C_9D2E6C < 0)) {
            auPlaySound(0x45);
        }
        D_80208C1C_9D2E6C = *arg1;
        D_80208C20_9D2E70 = *arg2;
        D_80208B94_9D2DE4 = ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) + (*arg2 * 3)) + *arg1;
        FocusMark_SetTargetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
        func_801DE1FC_9A844C(D_80208B94_9D2DE4);
    }
    return 0;
}

s32 func_801E1FE4_9AC234(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2, s32 arg3) {
    if (arg0 == NULL) {
        D_80208C24_9D2E74 = -1;
        D_80208C28_9D2E78 = -1;
        return 0;
    }
    func_801E3880_9ADAD0();
    if ((arg0->pressedButtons & 0x20000) && *arg2 <= 0) {
        (*arg2)++;
    }
    if ((arg0->pressedButtons & 0x10000) && *arg2 > 0) {
        (*arg2)--;
    }
    if (arg0->pressedButtons & 0x40000) {
        if (*arg1 < 2) {
            (*arg1)++;
        } else if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) < func_800BF9EC_5C88C() - 6) {
            auPlaySound(0x4B);
            D_80208B94_9D2DE4 += 6;
            *arg1 = 0;
            FocusMark_SetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DD954_9A7BA4(D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6));
        }
    }
    if (arg0->pressedButtons & 0x80000) {
        if (*arg1 > 0) {
            (*arg1)--;
        } else if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) > 0) {
            auPlaySound(0x4B);
            D_80208B94_9D2DE4 -= 6;
            *arg1 = 2;
            FocusMark_SetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DD954_9A7BA4(D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6));
        }
    }
    if ((*arg1 != D_80208C24_9D2E74) || (*arg2 != D_80208C28_9D2E78)) {
        // bug? using the same variable twice. silly mask needed to match
        if (!((D_80208C24_9D2E74 < 0) & 0xFFFFFFFF) || !(D_80208C24_9D2E74 < 0)) {
            auPlaySound(0x45);
        }
        D_80208C24_9D2E74 = *arg1;
        D_80208C28_9D2E78 = *arg2;
        D_80208B94_9D2DE4 = ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) + (*arg2 * 3)) + *arg1;
        if (arg3 != 0) {
            FocusMark_SetTargetPos((*arg1 * 66) + 99, (*arg2 * 55) + 48);
            func_801DDDF8_9A8048((*arg1 * 66) + 96, (*arg2 * 55) + 45);
        } else {
            FocusMark_SetTargetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
            func_801DDDF8_9A8048(-1, -1);
        }
        func_801DE1FC_9A844C(D_80208B94_9D2DE4);
    }
    return 0;
}

s32 func_801E2438_9AC688(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2) {
    if (arg0 == NULL) {
        D_80208C2C_9D2E7C = -1;
        D_80208C30_9D2E80 = -1;
        func_801DEA4C_9A8C9C(1, 0, 0);
        return 0;
    }
    func_801E3880_9ADAD0();
    if (arg0->pressedButtons & 0x20000) {
        if (*arg2 < 0x13) {
            (*arg2)++;
        } else {
            *arg2 = 0;
        }
    }
    if (arg0->pressedButtons & 0x10000) {
        if (*arg2 > 0) {
            (*arg2)--;
        } else {
            *arg2 = 19;
        }
    }
    if (arg0->pressedButtons & 0x40000) {
        if (*arg2 < 0x13) {
            if (*arg1 < 4) {
                (*arg1)++;
            } else {
                *arg1 = 0;
            }
        } else if (*arg1 < 2) {
            (*arg1)++;
        } else {
            *arg1 = 0;
        }
    }
    if (arg0->pressedButtons & 0x80000) {
        if (*arg2 < 19) {
            if (*arg1 > 0) {
                *arg1 -= 1;
            } else {
                *arg1 = 4;
            }
        } else if (*arg1 > 0) {
            *arg1 -= 1;
        } else {
            *arg1 = 2;
        }
    }

    if (*arg2 < 19) {
        if ((*arg1 != D_80208C2C_9D2E7C) || (*arg2 != D_80208C30_9D2E80)) {
            // bug? using the same variable twice. silly mask needed to match
            if (!((D_80208C2C_9D2E7C < 0) & 0xFFFFFFFF) || !(D_80208C2C_9D2E7C < 0)) {
                auPlaySound(0x45);
            }
            D_80208C2C_9D2E7C = *arg1;
            D_80208C30_9D2E80 = *arg2;
            func_801DE998_9A8BE8(1);
            FocusMark_SetTargetSize(4, 5);
            FocusMark_SetTargetPos((*arg1 * 13) + 25, (*arg2 * 10) + 22);
            func_801DEA4C_9A8C9C(0, *arg1, *arg2);
        }
    } else if (*arg1 != D_80208C2C_9D2E7C || *arg2 != D_80208C30_9D2E80) {
        D_80208C2C_9D2E7C = *arg1;
        D_80208C30_9D2E80 = *arg2;
        auPlaySound(0x41);
        func_801DE998_9A8BE8(0);
        if (*arg1 < 2) {
            FocusMark_SetTargetSize(4, 5);
            FocusMark_SetTargetPos((*arg1 * 13) + 25, (*arg2 * 10) + 22);
        } else {
            FocusMark_SetTargetSize(0xD, 5);
            FocusMark_SetTargetPos(68, (*arg2 * 10) + 22);
        }
        func_801DEA4C_9A8C9C(0, *arg1, *arg2);
    }
    return 0;
}

s32 album_UpdateCoverPage(void) {
    UnkStruct800BEDF8* input;
    s32 sp28;

    if (D_80208B90_9D2DE0) {
        func_801E0774_9AA9C4();
    }
    D_80208B90_9D2DE0 = true;
    sp28 = 0;
    UILayout_CreateButtons(album_CoverButtonsDef);
    FocusMark_SetTargetSize(62, 12);
    FocusMark_Show(true);

    while (true) {
        input = func_800AA38C(0);
        if (func_801E1A50_9ABCA0(input, &sp28) != 0) {
            auPlaySound(0x43);
            func_801E09A0_9AABF0(0x3C);
            return 6;
        }
        if (input->pressedButtons & A_BUTTON) {
            auPlaySound(0x42);
            switch (album_PanelButtons[sp28].id) {
                case 30:
                    UILayout_HideButtons();
                    func_801E09A0_9AABF0(0);
                    return 0;
                case 17:
                    func_801E09A0_9AABF0(0x3C);
                    return 6;
            }
        }
        ohWait(1);
    }
}

s32 album_UpdateAlbumPage(void) {
    UnkStruct800BEDF8* input;
    s32 sp48;
    s32 pad;
    u32 pageId;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    pageId = 0;
    sp3C = 0;
    sp30 = D_80208B94_9D2DE4 % 6;
    sp38 = sp30 % 3;
    sp34 = sp30 / 3;
    func_801E0AF0_9AAD40();
    FocusMark_SetTargetSize(62, 12);
    sp48 = 0;
    UILayout_CreateButtons(album_AlbumButtonsDef);
    UILayout_WaitPanelTransitionComplete();
    FocusMark_Show(true);
    while (true) {
        input = func_800AA38C(0);
        switch (pageId) {
            case 0:
                if (func_801E1A50_9ABCA0(input, &sp48) != 0) {
                    sp48 = 0;
                    auPlaySound(0x43);
                    func_801E0E58_9AB0A8();
                    func_801E1A50_9ABCA0(NULL, &sp48);
                    return 1;
                }
                if (input->pressedButtons & 0x8000) {
                    auPlaySound(0x42);
                    switch (album_PanelButtons[sp48].id) {
                        case 20:
                            func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                            FocusMark_SetTargetSize(0x32, 0x25);
                            pageId = 1;
                            break;
                        case 26:
                            FocusMark_SetTargetSize(0x32, 0x25);
                            pageId = 3;
                            sp3C = 0;
                            func_801E1FE4_9AC234(NULL, &sp38, &sp34, sp3C);
                            break;
                        case 19:
                            func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                            FocusMark_SetTargetSize(0x32, 0x25);
                            pageId = 7;
                            break;
                        case 31:
                            sp48 = 0;
                            func_801E1A50_9ABCA0(NULL, &sp48);
                            func_801E0E58_9AB0A8();
                            return 1;
                    }
                }
                break;
            case 1:
                func_801E1C30_9ABE80(input, &sp38, &sp34);
                if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) < func_800BF9EC_5C88C() - 6) {
                    UILayout_ShowHeaderElement(HEADER_NEXT);
                } else {
                    UILayout_HideHeaderElement(HEADER_NEXT);
                }

                if (D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6) > 0) {
                    UILayout_ShowHeaderElement(HEADER_PREV);
                } else {
                    UILayout_HideHeaderElement(HEADER_PREV);
                }

                if (input->pressedButtons & 0x4000) {
                    auPlaySound(0x41);
                    D_80208B94_9D2DE4 -= D_80208B94_9D2DE4 % 6;
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    sp48 = 0;
                    func_801E1A50_9ABCA0(NULL, NULL);
                    pageId = 0;
                } else if (input->pressedButtons & 0x8000) {
                    if (album_GetAlbumPhoto(D_80208B94_9D2DE4) == NULL) {
                        break;
                    }

                    auPlaySound(0x42);
                    sp48 = 0;
                    UILayout_CreateButtons(album_PhotoButtonsDef);
                    func_801E0FFC_9AB24C(2);
                    func_801E1A50_9ABCA0(NULL, NULL);
                    pageId = 2;
                }
                break;
            case 2:
                func_801E1A50_9ABCA0(input, &sp48);
                if (D_80208B94_9D2DE4 < album_GetLastPhotoIndex()) {
                    UILayout_ShowHeaderElement(HEADER_NEXT);
                } else {
                    UILayout_HideHeaderElement(HEADER_NEXT);
                }
                if (album_GetFirstPhotoIndex() < D_80208B94_9D2DE4) {
                    UILayout_ShowHeaderElement(HEADER_PREV);
                } else {
                    UILayout_HideHeaderElement(HEADER_PREV);
                }
                if (input->pressedButtons & 0x4000) {
                    auPlaySound(0x43);
                    func_801E0FFC_9AB24C(1);
                    FocusMark_SetTargetSize(0x32, 0x25);
                    FocusMark_SetTargetPos((sp38 * 66) + 107, (sp34 * 55) + 56);
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                    sp48 = 0;
                    UILayout_CreateButtons(album_AlbumButtonsDef);
                    pageId = 1;
                } else if (input->pressedButtons & 0x8000) {
                    switch (album_PanelButtons[sp48].id) {
                        case 28:
                            auPlaySound(0x42);
                            func_801DF744_9A9994(0, D_80208B94_9D2DE4);
                            sp24 = 0;
                            pageId = 4;
                            break;
                        case 27:
                            auPlaySound(0x42);
                            FocusMark_Show(false);
                            UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                            UILayout_HideButtons();
                            ohWait(30);
                            album_SwitchCharacterGridPage(0);
                            sp28 = 0;
                            sp2C = 0;
                            FocusMark_SetTargetSize(4, 5);
                            FocusMark_SetTargetPos(0x19, 0x16);
                            func_801E2438_9AC688(NULL, &sp2C, &sp28);
                            func_801DE998_9A8BE8(1);
                            FocusMark_Show(true);
                            pageId = 5;
                            func_800AA85C(0x18, 6);
                            break;
                        case 19:
                            auPlaySound(0x42);
                            FocusMark_Show(false);
                            UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                            func_801E1168_9AB3B8(1);
                            pageId = 6;
                            break;
                        case 5:
                            auPlaySound(0x43);
                            func_801E0FFC_9AB24C(1);
                            FocusMark_SetTargetSize(0x32, 0x25);
                            FocusMark_SetTargetPos((sp38 * 66) + 107, (sp34 * 55) + 56);
                            func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                            sp48 = 0;
                            UILayout_CreateButtons(album_AlbumButtonsDef);
                            pageId = 1;
                            break;
                    }
                } else if ((input->pressedButtons & 0x40000) && (D_80208B94_9D2DE4 < album_GetLastPhotoIndex())) {
                    auPlaySound(0x45);
                    D_80208B94_9D2DE4 = album_GetNextPhotoIndex(D_80208B94_9D2DE4);
                    func_801DE2BC_9A850C(D_80208B94_9D2DE4);
                } else if ((input->pressedButtons & 0x80000) && (album_GetFirstPhotoIndex() < D_80208B94_9D2DE4)) {
                    auPlaySound(0x45);
                    D_80208B94_9D2DE4 = album_GetPreviousPhotoIndex(D_80208B94_9D2DE4);
                    func_801DE2BC_9A850C(D_80208B94_9D2DE4);
                }
                break;
            case 3:
                func_801E1FE4_9AC234(input, &sp38, &sp34, sp3C);
                if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) < (func_800BF9EC_5C88C() - 6)) {
                    UILayout_ShowHeaderElement(HEADER_NEXT);
                } else {
                    UILayout_HideHeaderElement(HEADER_NEXT);
                }
                if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) > 0) {
                    UILayout_ShowHeaderElement(HEADER_PREV);
                } else {
                    UILayout_HideHeaderElement(HEADER_PREV);
                }
                if (input->pressedButtons & 0x4000) {
                    D_80208B94_9D2DE4 -= D_80208B94_9D2DE4 % 6;
                    sp48 = 1;
                    FocusMark_StopAnimation(true);
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    func_801E1A50_9ABCA0(NULL, NULL);
                    func_801DDDF8_9A8048(-1, -1);
                    func_801E3F00_9AE150();
                    pageId = 0;
                } else if (input->pressedButtons & 0x8000) {
                    func_801E1FE4_9AC234(NULL, &sp38, &sp34, sp3C);
                    sp3C = func_801E3B34_9ADD84(D_80208B94_9D2DE4);
                    if (sp3C != 0) {
                        FocusMark_StopAnimation(false);
                    } else {
                        FocusMark_StopAnimation(true);
                    }
                }
                break;
            case 4:
                if (input->pressedButtons & 0xC000) {
                    auPlaySound(0x43);
                    func_801DF744_9A9994(2, D_80208B94_9D2DE4);
                    sp48 = 0;
                    UILayout_CreateButtons(album_PhotoButtonsDef);
                    ohWait(21);
                    func_801E1A50_9ABCA0(NULL, &sp48);
                    FocusMark_Show(true);
                    pageId = 2;
                    break;
                }
                break;
            case 5:
                func_801E2438_9AC688(input, &sp2C, &sp28);
                if (input->pressedButtons & 0x4000) {
                    if (func_801DD0CC_9A731C() != 0) {
                        auPlaySound(0x4A);
                        func_801E0300_9AA550();
                    } else {
                        sp2C = 3;
                        sp28 = 0x13;
                    }
                    break;
                }

                if (input->pressedButtons & 0x1000) {
                    sp2C = 3;
                    sp28 = 0x13;
                    break;
                }

                if (input->pressedButtons & 0x8000) {
                    if ((sp2C >= 2) && (sp28 == 0x13)) {
                        auPlaySound(0x42);
                        FocusMark_Show(false);
                        album_SwitchCharacterGridPage(6);
                        UILayout_CreateButtons(album_PhotoButtonsDef);
                        ohWait(21);
                        sp48 = 1;
                        func_801E1A50_9ABCA0(NULL, &sp48);
                        FocusMark_Show(true);
                        pageId = 2;
                        func_800AA85C(0x18, 0xC);
                    } else {
                        album_PressedCharacterInGrid(sp2C, sp28);
                        func_801DEA4C_9A8C9C(0, sp2C, sp28);
                    }
                    if (func_801DD0CC_9A731C() >= 0x1F) {
                        sp2C = 2;
                        sp28 = 0x13;
                    }
                    break;
                }
                break;
            case 6:
                if (input->pressedButtons & 0x4000) {
                    auPlaySound(0x43);
                    func_801E1168_9AB3B8(0);
                    func_801E1A50_9ABCA0(NULL, &sp48);
                    FocusMark_Show(true);
                    pageId = 2;
                    break;
                }

                if (input->pressedButtons & 0x8000) {
                    auPlaySound(0x42);
                    func_801E3880_9ADAD0();
                    func_801E1168_9AB3B8(0);
                    func_801E1320_9AB570(D_80208B94_9D2DE4);
                    func_801E0FFC_9AB24C(1);
                    FocusMark_SetTargetSize(0x32, 0x25);
                    FocusMark_SetTargetPos((sp38 * 66) + 107, (sp34 * 55) + 56);
                    func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                    sp48 = 0;
                    UILayout_CreateButtons(album_AlbumButtonsDef);
                    FocusMark_Show(true);
                    pageId = 1;
                    break;
                }
                break;
            case 7:
                func_801E1C30_9ABE80(input, &sp38, &sp34);
                if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) < (func_800BF9EC_5C88C() - 6)) {
                    UILayout_ShowHeaderElement(HEADER_NEXT);
                } else {
                    UILayout_HideHeaderElement(HEADER_NEXT);
                }
                if ((D_80208B94_9D2DE4 - (D_80208B94_9D2DE4 % 6)) > 0) {
                    UILayout_ShowHeaderElement(HEADER_PREV);
                } else {
                    UILayout_HideHeaderElement(HEADER_PREV);
                }
                if (input->pressedButtons & 0x4000) {
                    auPlaySound(0x41);
                    D_80208B94_9D2DE4 -= D_80208B94_9D2DE4 % 6;
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    sp48 = 2;
                    func_801E1A50_9ABCA0(NULL, NULL);
                    pageId = 0;
                } else if (input->pressedButtons & 0x8000) {
                    if (album_GetAlbumPhoto(D_80208B94_9D2DE4) == NULL) {
                        break;
                    }

                    auPlaySound(0x42);
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    func_801E0FFC_9AB24C(2);
                    FocusMark_Show(false);
                    ohWait(30);
                    func_801E1168_9AB3B8(1);
                    pageId = 8;
                }
                break;
            case 8:
                if (input->pressedButtons & 0xC000) {
                    if (input->pressedButtons & 0x8000) {
                        auPlaySound(0x42);
                        func_801E3880_9ADAD0();
                        func_801E1168_9AB3B8(0);
                        func_801E1320_9AB570(D_80208B94_9D2DE4);
                    } else {
                        auPlaySound(0x43);
                        func_801E1168_9AB3B8(0);
                        func_801E0FFC_9AB24C(1);
                    }
                    FocusMark_SetTargetSize(0x32, 0x25);
                    FocusMark_SetTargetPos((sp38 * 66) + 107, (sp34 * 55) + 56);
                    func_801E1C30_9ABE80(NULL, &sp38, &sp34);
                    FocusMark_Show(true);
                    pageId = 7;
                    break;
                }
                break;
        }
        ohWait(1);
    }
}

void func_801E37A0_9AD9F0(void) {
    UNUSED s32 pad;
    s32 sp28;

    sp28 = 1;
    album_CoverButtons = album_CoverButtonsDef;
    album_PanelButtons = UILayout_GetButtons();
    D_80208B94_9D2DE4 = 0;
    FocusMark_MoveFront();
    func_800AA85C(24, 12);
    func_800AA870(0xF0000);

    while (true) {
        switch (sp28) {
            case 1:
                sp28 = album_UpdateCoverPage();
                break;
            case 0:
                sp28 = album_UpdateAlbumPage();
                break;
            case 6:
                return;
        }
    }
}
