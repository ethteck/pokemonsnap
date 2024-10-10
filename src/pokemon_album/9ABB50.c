#include "common.h"

#include "pokemon_album.h"

s32 D_80208B90_9D2DE0 = false;
s32 album_SelectedPhoto = 0;

UIButton album_CoverButtonsDef[] = {
    { BUTTON_OPEN, "ひらく" },
    { BUTTON_SPLITTER, NULL },
    { BUTTON_GO_TO_LAB, "けんきゅうじょへ" },
    { BUTTON_NONE, NULL },
};
UIButton album_AlbumButtonsDef[] = {
    { BUTTON_ENLARGE, "みる" },
    { BUTTON_ARRANGE, "いれかえ" },
    { BUTTON_DELETE, "けす" },
    { BUTTON_SPLITTER, NULL },
    { BUTTON_RETURN_TO_COVER, "ひょうしへ" },
    { BUTTON_NONE, NULL },
};
UIButton album_PhotoButtonsDef[] = {
    { BUTTON_CHECK, "くわしく" },
    { BUTTON_COMMENT, "コメント" },
    { BUTTON_DELETE, "けす" },
    { BUTTON_SPLITTER, NULL },
    { BUTTON_RETURN, "もどる" },
    { BUTTON_NONE, NULL },
};

s32 D_80208C18_9D2E68 = -1;
s32 album_CurrentColumn = -1;
s32 album_CurrentRow = -1;
s32 album_DraggedPhotoColumn = -1;
s32 album_DraggedPhotoRow = -1;
s32 D_80208C2C_9D2E7C = -1;
s32 D_80208C30_9D2E80 = -1;

UIButton* album_CoverButtons;
UIButton* album_PanelButtons;

UIButton* album_GetCoverButtons(void) {
    return album_CoverButtonsDef;
}

s32 album_GetSelectedPhoto(void) {
    return album_SelectedPhoto;
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

s32 album_UpdateButtonSelection(UnkStruct800BEDF8* input, s32* row) {
    if (input == NULL) {
        D_80208C18_9D2E68 = -1;
        if (row != NULL) {
            FocusMark_SetPos(22, (*row * 24) + 29);
            FocusMark_SetSize(62, 12);
        } else {
            FocusMark_SetTargetSize(62, 12);
        }
        return 0;
    }

    FocusMark_SetTargetPos(22, (*row * 24) + 29);

    if ((input->pressedButtons & STICK_SLOW_UP) && !(input->currentButtons & (STICK_SLOW_RIGHT | STICK_SLOW_LEFT))) {
        do {
            *row = (*row + 7) % 8;
        } while (album_PanelButtons[*row].id == BUTTON_NONE);
        auPlaySound(SOUND_ID_65);
    }
    if ((input->pressedButtons & STICK_SLOW_DOWN) && !(input->currentButtons & (STICK_SLOW_RIGHT | STICK_SLOW_LEFT))) {
        do {
            *row = (*row + 1) % 8;
        } while (album_PanelButtons[*row].id == BUTTON_NONE);
        auPlaySound(SOUND_ID_65);
    }
    if (input->pressedButtons & B_BUTTON) {
        return -1;
    }
    return 0;
}

s32 album_UpdatePhotoSelection(UnkStruct800BEDF8* input, s32* column, s32* row) {
    if (input == NULL) {
        album_CurrentColumn = -1;
        album_CurrentRow = -1;
        album_PrintPhotoComment(album_SelectedPhoto);
        return 0;
    }
    if ((input->pressedButtons & STICK_SLOW_DOWN) && *row <= 0) {
        (*row)++;
    }
    if ((input->pressedButtons & STICK_SLOW_UP) && *row > 0) {
        (*row)--;
    }
    if (input->pressedButtons & STICK_SLOW_RIGHT) {
        if (*column < 2) {
            (*column)++;
        } else if ((album_SelectedPhoto - (album_SelectedPhoto % 6)) < getAlbumCapacity() - 6) {
            auPlaySound(SOUND_ID_75);
            album_SelectedPhoto += 6;
            *column = 0;
            FocusMark_SetPos((*column * 66) + 107, (*row * 55) + 56);
            album_DrawAlbumPage(album_SelectedPhoto - (album_SelectedPhoto % 6));
        }
    }
    if (input->pressedButtons & STICK_SLOW_LEFT) {
        if (*column > 0) {
            (*column)--;
        } else if (album_SelectedPhoto - (album_SelectedPhoto % 6) > 0) {
            auPlaySound(SOUND_ID_75);
            album_SelectedPhoto -= 6;
            *column = 2;
            FocusMark_SetPos((*column * 66) + 107, (*row * 55) + 56);
            album_DrawAlbumPage(album_SelectedPhoto - (album_SelectedPhoto % 6));
        }
    }
    if ((*column != album_CurrentColumn) || (*row != album_CurrentRow)) {
        // bug? using the same variable twice. silly mask needed to match
        if (!((album_CurrentColumn < 0) & 0xFFFFFFFF) || !(album_CurrentColumn < 0)) {
            auPlaySound(SOUND_ID_69);
        }
        album_CurrentColumn = *column;
        album_CurrentRow = *row;
        album_SelectedPhoto = ((album_SelectedPhoto - (album_SelectedPhoto % 6)) + (*row * 3)) + *column;
        FocusMark_SetTargetPos((*column * 66) + 107, (*row * 55) + 56);
        album_PrintPhotoComment(album_SelectedPhoto);
    }
    return 0;
}

s32 album_DragPhoto(UnkStruct800BEDF8* input, s32* column, s32* row, s32 isDragged) {
    if (input == NULL) {
        album_DraggedPhotoColumn = -1;
        album_DraggedPhotoRow = -1;
        return 0;
    }
    func_801E3880_9ADAD0();
    if ((input->pressedButtons & STICK_SLOW_DOWN) && *row <= 0) {
        (*row)++;
    }
    if ((input->pressedButtons & STICK_SLOW_UP) && *row > 0) {
        (*row)--;
    }
    if (input->pressedButtons & STICK_SLOW_RIGHT) {
        if (*column < 2) {
            (*column)++;
        } else if (album_SelectedPhoto - (album_SelectedPhoto % 6) < getAlbumCapacity() - 6) {
            auPlaySound(SOUND_ID_75);
            album_SelectedPhoto += 6;
            *column = 0;
            FocusMark_SetPos((*column * 66) + 107, (*row * 55) + 56);
            album_DrawAlbumPage(album_SelectedPhoto - (album_SelectedPhoto % 6));
        }
    }
    if (input->pressedButtons & STICK_SLOW_LEFT) {
        if (*column > 0) {
            (*column)--;
        } else if (album_SelectedPhoto - (album_SelectedPhoto % 6) > 0) {
            auPlaySound(SOUND_ID_75);
            album_SelectedPhoto -= 6;
            *column = 2;
            FocusMark_SetPos((*column * 66) + 107, (*row * 55) + 56);
            album_DrawAlbumPage(album_SelectedPhoto - (album_SelectedPhoto % 6));
        }
    }
    if ((*column != album_DraggedPhotoColumn) || (*row != album_DraggedPhotoRow)) {
        // bug? using the same variable twice. silly mask needed to match
        if (!((album_DraggedPhotoColumn < 0) & 0xFFFFFFFF) || !(album_DraggedPhotoColumn < 0)) {
            auPlaySound(SOUND_ID_69);
        }
        album_DraggedPhotoColumn = *column;
        album_DraggedPhotoRow = *row;
        album_SelectedPhoto = ((album_SelectedPhoto - (album_SelectedPhoto % 6)) + (*row * 3)) + *column;
        if (isDragged != 0) {
            FocusMark_SetTargetPos((*column * 66) + 99, (*row * 55) + 48);
            func_801DDDF8_9A8048((*column * 66) + 96, (*row * 55) + 45);
        } else {
            FocusMark_SetTargetPos((*column * 66) + 107, (*row * 55) + 56);
            func_801DDDF8_9A8048(-1, -1);
        }
        album_PrintPhotoComment(album_SelectedPhoto);
    }
    return 0;
}

s32 album_EditComment(UnkStruct800BEDF8* input, s32* column, s32* row) {
    if (input == NULL) {
        D_80208C2C_9D2E7C = -1;
        D_80208C30_9D2E80 = -1;
        func_801DEA4C_9A8C9C(1, 0, 0);
        return 0;
    }
    func_801E3880_9ADAD0();
    if (input->pressedButtons & STICK_SLOW_DOWN) {
        if (*row < 19) {
            (*row)++;
        } else {
            *row = 0;
        }
    }
    if (input->pressedButtons & STICK_SLOW_UP) {
        if (*row > 0) {
            (*row)--;
        } else {
            *row = 19;
        }
    }
    if (input->pressedButtons & STICK_SLOW_RIGHT) {
        if (*row < 19) {
            if (*column < 4) {
                (*column)++;
            } else {
                *column = 0;
            }
        } else if (*column < 2) {
            (*column)++;
        } else {
            *column = 0;
        }
    }
    if (input->pressedButtons & STICK_SLOW_LEFT) {
        if (*row < 19) {
            if (*column > 0) {
                *column -= 1;
            } else {
                *column = 4;
            }
        } else if (*column > 0) {
            *column -= 1;
        } else {
            *column = 2;
        }
    }

    if (*row < 19) {
        if ((*column != D_80208C2C_9D2E7C) || (*row != D_80208C30_9D2E80)) {
            // bug? using the same variable twice. silly mask needed to match
            if (!((D_80208C2C_9D2E7C < 0) & 0xFFFFFFFF) || !(D_80208C2C_9D2E7C < 0)) {
                auPlaySound(SOUND_ID_69);
            }
            D_80208C2C_9D2E7C = *column;
            D_80208C30_9D2E80 = *row;
            func_801DE998_9A8BE8(true);
            FocusMark_SetTargetSize(4, 5);
            FocusMark_SetTargetPos((*column * 13) + 25, (*row * 10) + 22);
            func_801DEA4C_9A8C9C(0, *column, *row);
        }
    } else if (*column != D_80208C2C_9D2E7C || *row != D_80208C30_9D2E80) {
        D_80208C2C_9D2E7C = *column;
        D_80208C30_9D2E80 = *row;
        auPlaySound(SOUND_ID_65);
        func_801DE998_9A8BE8(false);
        if (*column < 2) {
            FocusMark_SetTargetSize(4, 5);
            FocusMark_SetTargetPos((*column * 13) + 25, (*row * 10) + 22);
        } else {
            FocusMark_SetTargetSize(13, 5);
            FocusMark_SetTargetPos(68, (*row * 10) + 22);
        }
        func_801DEA4C_9A8C9C(0, *column, *row);
    }
    return 0;
}

s32 album_UpdateCoverPage(void) {
    UnkStruct800BEDF8* input;
    s32 row;

    if (D_80208B90_9D2DE0) {
        album_CreateCoverPage();
    }
    D_80208B90_9D2DE0 = true;
    row = 0;
    UILayout_CreateButtons(album_CoverButtonsDef);
    FocusMark_SetTargetSize(62, 12);
    FocusMark_Show(true);

    while (true) {
        input = func_800AA38C(0);
        if (album_UpdateButtonSelection(input, &row) != 0) {
            auPlaySound(SOUND_ID_67);
            func_801E09A0_9AABF0(60);
            return 6;
        }
        if (input->pressedButtons & A_BUTTON) {
            auPlaySound(SOUND_ID_66);
            switch (album_PanelButtons[row].id) {
                case BUTTON_OPEN:
                    UILayout_HideButtons();
                    func_801E09A0_9AABF0(0);
                    return 0;
                case BUTTON_GO_TO_LAB:
                    func_801E09A0_9AABF0(60);
                    return 6;
            }
        }
        ohWait(1);
    }
}

s32 album_UpdateAlbumPage(void) {
    UnkStruct800BEDF8* input;
    s32 buttonIndex;
    s32 pad;
    u32 pageId;
    s32 isDragged;
    s32 column;
    s32 row;
    s32 sp30;
    s32 gridColumn;
    s32 gridRow;
    s32 sp24;

    pageId = 0;
    isDragged = false;
    sp30 = album_SelectedPhoto % 6;
    column = sp30 % 3;
    row = sp30 / 3;
    func_801E0AF0_9AAD40();
    FocusMark_SetTargetSize(62, 12);
    buttonIndex = 0;
    UILayout_CreateButtons(album_AlbumButtonsDef);
    UILayout_WaitPanelTransitionComplete();
    FocusMark_Show(true);
    while (true) {
        input = func_800AA38C(0);
        switch (pageId) {
            case ALBUM_MAIN_PAGE:
                if (album_UpdateButtonSelection(input, &buttonIndex) != 0) {
                    buttonIndex = 0;
                    auPlaySound(SOUND_ID_67);
                    func_801E0E58_9AB0A8();
                    album_UpdateButtonSelection(NULL, &buttonIndex);
                    return 1;
                }
                if (input->pressedButtons & A_BUTTON) {
                    auPlaySound(SOUND_ID_66);
                    switch (album_PanelButtons[buttonIndex].id) {
                        case BUTTON_ENLARGE:
                            album_UpdatePhotoSelection(NULL, &column, &row);
                            FocusMark_SetTargetSize(50, 37);
                            pageId = ALBUM_PAGE_SELECT_PHOTO_TO_VIEW;
                            break;
                        case BUTTON_ARRANGE:
                            FocusMark_SetTargetSize(50, 37);
                            pageId = ALBUM_PAGE_ARRANGE_PHOTO;
                            isDragged = false;
                            album_DragPhoto(NULL, &column, &row, isDragged);
                            break;
                        case BUTTON_DELETE:
                            album_UpdatePhotoSelection(NULL, &column, &row);
                            FocusMark_SetTargetSize(50, 37);
                            pageId = ALBUM_PAGE_SELECT_PHOTO_TO_DELETE;
                            break;
                        case BUTTON_RETURN_TO_COVER:
                            buttonIndex = 0;
                            album_UpdateButtonSelection(NULL, &buttonIndex);
                            func_801E0E58_9AB0A8();
                            return 1;
                    }
                }
                break;
            case ALBUM_PAGE_SELECT_PHOTO_TO_VIEW:
                album_UpdatePhotoSelection(input, &column, &row);
                if (album_SelectedPhoto - (album_SelectedPhoto % 6) < getAlbumCapacity() - 6) {
                    UILayout_ShowHeaderElement(HEADER_NEXT);
                } else {
                    UILayout_HideHeaderElement(HEADER_NEXT);
                }

                if (album_SelectedPhoto - (album_SelectedPhoto % 6) > 0) {
                    UILayout_ShowHeaderElement(HEADER_PREV);
                } else {
                    UILayout_HideHeaderElement(HEADER_PREV);
                }

                if (input->pressedButtons & B_BUTTON) {
                    auPlaySound(SOUND_ID_65);
                    album_SelectedPhoto -= album_SelectedPhoto % 6;
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    buttonIndex = 0;
                    album_UpdateButtonSelection(NULL, NULL);
                    pageId = ALBUM_MAIN_PAGE;
                } else if (input->pressedButtons & A_BUTTON) {
                    if (album_GetAlbumPhoto(album_SelectedPhoto) == NULL) {
                        break;
                    }
                    auPlaySound(SOUND_ID_66);
                    buttonIndex = 0;
                    UILayout_CreateButtons(album_PhotoButtonsDef);
                    func_801E0FFC_9AB24C(2);
                    album_UpdateButtonSelection(NULL, NULL);
                    pageId = ALBUM_PAGE_VIEW_PHOTO;
                }
                break;
            case ALBUM_PAGE_VIEW_PHOTO:
                album_UpdateButtonSelection(input, &buttonIndex);
                if (album_SelectedPhoto < album_GetLastPhotoIndex()) {
                    UILayout_ShowHeaderElement(HEADER_NEXT);
                } else {
                    UILayout_HideHeaderElement(HEADER_NEXT);
                }
                if (album_GetFirstPhotoIndex() < album_SelectedPhoto) {
                    UILayout_ShowHeaderElement(HEADER_PREV);
                } else {
                    UILayout_HideHeaderElement(HEADER_PREV);
                }
                if (input->pressedButtons & B_BUTTON) {
                    auPlaySound(SOUND_ID_67);
                    func_801E0FFC_9AB24C(1);
                    FocusMark_SetTargetSize(50, 37);
                    FocusMark_SetTargetPos((column * 66) + 107, (row * 55) + 56);
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    album_UpdatePhotoSelection(NULL, &column, &row);
                    buttonIndex = 0;
                    UILayout_CreateButtons(album_AlbumButtonsDef);
                    pageId = ALBUM_PAGE_SELECT_PHOTO_TO_VIEW;
                } else if (input->pressedButtons & A_BUTTON) {
                    switch (album_PanelButtons[buttonIndex].id) {
                        case BUTTON_CHECK:
                            auPlaySound(SOUND_ID_66);
                            func_801DF744_9A9994(0, album_SelectedPhoto);
                            sp24 = 0;
                            pageId = ALBUM_PAGE_PHOTO_DETAILS;
                            break;
                        case BUTTON_COMMENT:
                            auPlaySound(SOUND_ID_66);
                            FocusMark_Show(false);
                            UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                            UILayout_HideButtons();
                            ohWait(30);
                            album_SwitchCharacterGridPage(0);
                            gridRow = 0;
                            gridColumn = 0;
                            FocusMark_SetTargetSize(4, 5);
                            FocusMark_SetTargetPos(25, 22);
                            album_EditComment(NULL, &gridColumn, &gridRow);
                            func_801DE998_9A8BE8(true);
                            FocusMark_Show(true);
                            pageId = ALBUM_PAGE_EDIT_COMMENT;
                            func_800AA85C(24, 6);
                            break;
                        case BUTTON_DELETE:
                            auPlaySound(SOUND_ID_66);
                            FocusMark_Show(false);
                            UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                            album_DrawDeletePhotoPrompt(true);
                            pageId = ALBUM_PAGE_DELETE_PHOTO;
                            break;
                        case BUTTON_RETURN:
                            auPlaySound(SOUND_ID_67);
                            func_801E0FFC_9AB24C(1);
                            FocusMark_SetTargetSize(50, 37);
                            FocusMark_SetTargetPos((column * 66) + 107, (row * 55) + 56);
                            album_UpdatePhotoSelection(NULL, &column, &row);
                            buttonIndex = 0;
                            UILayout_CreateButtons(album_AlbumButtonsDef);
                            pageId = ALBUM_PAGE_SELECT_PHOTO_TO_VIEW;
                            break;
                    }
                } else if ((input->pressedButtons & STICK_SLOW_RIGHT) && (album_SelectedPhoto < album_GetLastPhotoIndex())) {
                    auPlaySound(SOUND_ID_69);
                    album_SelectedPhoto = album_GetNextPhotoIndex(album_SelectedPhoto);
                    func_801DE2BC_9A850C(album_SelectedPhoto);
                } else if ((input->pressedButtons & STICK_SLOW_LEFT) && (album_GetFirstPhotoIndex() < album_SelectedPhoto)) {
                    auPlaySound(SOUND_ID_69);
                    album_SelectedPhoto = album_GetPreviousPhotoIndex(album_SelectedPhoto);
                    func_801DE2BC_9A850C(album_SelectedPhoto);
                }
                break;
            case ALBUM_PAGE_ARRANGE_PHOTO:
                album_DragPhoto(input, &column, &row, isDragged);
                if ((album_SelectedPhoto - (album_SelectedPhoto % 6)) < (getAlbumCapacity() - 6)) {
                    UILayout_ShowHeaderElement(HEADER_NEXT);
                } else {
                    UILayout_HideHeaderElement(HEADER_NEXT);
                }
                if ((album_SelectedPhoto - (album_SelectedPhoto % 6)) > 0) {
                    UILayout_ShowHeaderElement(HEADER_PREV);
                } else {
                    UILayout_HideHeaderElement(HEADER_PREV);
                }
                if (input->pressedButtons & B_BUTTON) {
                    album_SelectedPhoto -= album_SelectedPhoto % 6;
                    buttonIndex = 1;
                    FocusMark_StopAnimation(true);
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    album_UpdateButtonSelection(NULL, NULL);
                    func_801DDDF8_9A8048(-1, -1);
                    func_801E3F00_9AE150();
                    pageId = ALBUM_MAIN_PAGE;
                } else if (input->pressedButtons & A_BUTTON) {
                    album_DragPhoto(NULL, &column, &row, isDragged);
                    isDragged = func_801E3B34_9ADD84(album_SelectedPhoto);
                    if (isDragged) {
                        FocusMark_StopAnimation(false);
                    } else {
                        FocusMark_StopAnimation(true);
                    }
                }
                break;
            case ALBUM_PAGE_PHOTO_DETAILS:
                if (input->pressedButtons & 0xC000) {
                    auPlaySound(SOUND_ID_67);
                    func_801DF744_9A9994(2, album_SelectedPhoto);
                    buttonIndex = 0;
                    UILayout_CreateButtons(album_PhotoButtonsDef);
                    ohWait(21);
                    album_UpdateButtonSelection(NULL, &buttonIndex);
                    FocusMark_Show(true);
                    pageId = ALBUM_PAGE_VIEW_PHOTO;
                    break;
                }
                break;
            case ALBUM_PAGE_EDIT_COMMENT:
                album_EditComment(input, &gridColumn, &gridRow);
                if (input->pressedButtons & B_BUTTON) {
                    if (album_GetCursorPos() != 0) {
                        auPlaySound(SOUND_ID_74);
                        album_DeleteCharInComment();
                    } else {
                        gridColumn = 3;
                        gridRow = 19;
                    }
                    break;
                }

                if (input->pressedButtons & START_BUTTON) {
                    gridColumn = 3;
                    gridRow = 19;
                    break;
                }

                if (input->pressedButtons & A_BUTTON) {
                    if (gridColumn >= 2 && gridRow == 19) {
                        auPlaySound(SOUND_ID_66);
                        FocusMark_Show(false);
                        album_SwitchCharacterGridPage(6);
                        UILayout_CreateButtons(album_PhotoButtonsDef);
                        ohWait(21);
                        buttonIndex = 1;
                        album_UpdateButtonSelection(NULL, &buttonIndex);
                        FocusMark_Show(true);
                        pageId = ALBUM_PAGE_VIEW_PHOTO;
                        func_800AA85C(24, 12);
                    } else {
                        album_PressedCharacterInGrid(gridColumn, gridRow);
                        func_801DEA4C_9A8C9C(0, gridColumn, gridRow);
                    }
                    if (album_GetCursorPos() >= 31) {
                        gridColumn = 2;
                        gridRow = 19;
                    }
                    break;
                }
                break;
            case ALBUM_PAGE_DELETE_PHOTO:
                if (input->pressedButtons & B_BUTTON) {
                    auPlaySound(SOUND_ID_67);
                    album_DrawDeletePhotoPrompt(false);
                    album_UpdateButtonSelection(NULL, &buttonIndex);
                    FocusMark_Show(true);
                    pageId = ALBUM_PAGE_VIEW_PHOTO;
                    break;
                }

                if (input->pressedButtons & A_BUTTON) {
                    auPlaySound(SOUND_ID_66);
                    func_801E3880_9ADAD0();
                    album_DrawDeletePhotoPrompt(false);
                    album_DeletePhoto(album_SelectedPhoto);
                    func_801E0FFC_9AB24C(1);
                    FocusMark_SetTargetSize(50, 37);
                    FocusMark_SetTargetPos((column * 66) + 107, (row * 55) + 56);
                    album_UpdatePhotoSelection(NULL, &column, &row);
                    buttonIndex = 0;
                    UILayout_CreateButtons(album_AlbumButtonsDef);
                    FocusMark_Show(true);
                    pageId = ALBUM_PAGE_SELECT_PHOTO_TO_VIEW;
                    break;
                }
                break;
            case ALBUM_PAGE_SELECT_PHOTO_TO_DELETE:
                album_UpdatePhotoSelection(input, &column, &row);
                if ((album_SelectedPhoto - (album_SelectedPhoto % 6)) < (getAlbumCapacity() - 6)) {
                    UILayout_ShowHeaderElement(HEADER_NEXT);
                } else {
                    UILayout_HideHeaderElement(HEADER_NEXT);
                }
                if ((album_SelectedPhoto - (album_SelectedPhoto % 6)) > 0) {
                    UILayout_ShowHeaderElement(HEADER_PREV);
                } else {
                    UILayout_HideHeaderElement(HEADER_PREV);
                }
                if (input->pressedButtons & 0x4000) {
                    auPlaySound(SOUND_ID_65);
                    album_SelectedPhoto -= album_SelectedPhoto % 6;
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    buttonIndex = 2;
                    album_UpdateButtonSelection(NULL, NULL);
                    pageId = ALBUM_MAIN_PAGE;
                } else if (input->pressedButtons & A_BUTTON) {
                    if (album_GetAlbumPhoto(album_SelectedPhoto) == NULL) {
                        break;
                    }

                    auPlaySound(SOUND_ID_66);
                    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
                    func_801E0FFC_9AB24C(2);
                    FocusMark_Show(false);
                    ohWait(30);
                    album_DrawDeletePhotoPrompt(true);
                    pageId = ALBUM_PAGE_DELETE_PHOTO_FROM_ALBUM;
                }
                break;
            case ALBUM_PAGE_DELETE_PHOTO_FROM_ALBUM:
                if (input->pressedButtons & (A_BUTTON | B_BUTTON)) {
                    if (input->pressedButtons & A_BUTTON) {
                        auPlaySound(SOUND_ID_66);
                        func_801E3880_9ADAD0();
                        album_DrawDeletePhotoPrompt(false);
                        album_DeletePhoto(album_SelectedPhoto);
                    } else {
                        auPlaySound(SOUND_ID_67);
                        album_DrawDeletePhotoPrompt(false);
                        func_801E0FFC_9AB24C(1);
                    }
                    FocusMark_SetTargetSize(50, 37);
                    FocusMark_SetTargetPos((column * 66) + 107, (row * 55) + 56);
                    album_UpdatePhotoSelection(NULL, &column, &row);
                    FocusMark_Show(true);
                    pageId = ALBUM_PAGE_SELECT_PHOTO_TO_DELETE;
                    break;
                }
                break;
        }
        ohWait(1);
    }
}

void album_Update(void) {
    UNUSED s32 pad;
    s32 sp28;

    sp28 = 1;
    album_CoverButtons = album_CoverButtonsDef;
    album_PanelButtons = UILayout_GetButtons();
    album_SelectedPhoto = 0;
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
