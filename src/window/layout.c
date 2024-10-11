#include "common.h"
#include "sp.h"
#include "window.h"

extern Sprite D_80382CE0_856490;
extern Sprite D_803A1360_874B10;
extern Sprite D_803A1B10_8752C0;
extern Sprite D_803A22C0_875A70;
extern Sprite D_803A51A0_878950;
extern Bitmap D_803A6210_8799C0;
extern Sprite D_803A6220_8799D0;
extern Bitmap D_803A6390_879B40;
extern Bitmap D_803A6510_879CC0;
extern Bitmap* D_803A6564_879D14[];

u32 D_803A6600_879DB0 = 0x803A57A0; // TODO belongs to previous array

s32 UILayout_PanelState = PANEL_STATE_STABLE;
s32 UILayout_IsAnimationHorizontal = false;
s32 UILayout_IsInstantTransition = false;
UIButton* UILayout_Buttons = NULL;
s32 UILayout_AnimationFrames = 3;
s32 UILayout_HeaderFlags = 0;
f32 UILayout_TitlePosY = -40.0f;
f32 UILayout_PrevPageIndicatorPosY = -40.0f;
s32 UILayout_PrevPageIndicatorCounter = 0;
f32 UILayout_NextPageIndicatorPosY = -40.0f;
s32 UILayout_NextPageIndicatorCounter = 0;
s32 UILayout_PanelVisibility = 0;
f32 UILayout_PanelPosX = -180.0f;

// BSS
extern GObj* UILayout_PreviousPageIndicator;
extern GObj* UILayout_NextPageIndicator;
extern GObj* UILayout_Title;
extern GObj* UILayout_ButtonObjects[];
extern GObj* UILayout_Panel;
extern f32 UILayout_ButtonPhase[];
extern UIButton D_803A6BA0_87A350[];
extern s32 D_803A6BE8_87A398[];

void UILayout_ToggleAnimationDirection(void) {
    UILayout_IsAnimationHorizontal = !UILayout_IsAnimationHorizontal;
}

void UILayout_ToggleAnimationSpeed(void) {
    if (UILayout_AnimationFrames != 0) {
        UILayout_AnimationFrames = 0;
    } else {
        UILayout_AnimationFrames = 3;
    }
}

void UILayout_WaitPanelTransitionComplete(void) {
    while (UILayout_PanelState != PANEL_STATE_STABLE) {
        ohWait(1);
    }
}

void UILayout_SetInstantTransition(s32 isInstant) {
    UILayout_IsInstantTransition = isInstant != 0;
}

UIButton* UILayout_GetButtons(void) {
    return D_803A6BA0_87A350;
}

void UILayout_DisableAllButtonsExcept(s32 disable, s32 id) {
    s32 i;

    if (id < 0) {
        id = 0;
    } else if (id > BUTTON_MAX) {
        id = BUTTON_MAX;
    }

    for (i = 0; i <= BUTTON_MAX; i++) {
        if (disable && i != id) {
            UILayout_ButtonObjects[i]->data.sobj->sprite.red = 128;
            UILayout_ButtonObjects[i]->data.sobj->sprite.green = 128;
            UILayout_ButtonObjects[i]->data.sobj->sprite.blue = 128;
        } else {
            UILayout_ButtonObjects[i]->data.sobj->sprite.red = 255;
            UILayout_ButtonObjects[i]->data.sobj->sprite.green = 255;
            UILayout_ButtonObjects[i]->data.sobj->sprite.blue = 255;
        }
    }
}

void UILayout_DisableButton(s32 disable, s32 id) {
    s32 i;

    if (id < 0) {
        id = 0;
    } else if (id > BUTTON_MAX) {
        id = BUTTON_MAX;
    }

    for (i = 0; i <= BUTTON_MAX; i++) {
        if (i == id) {
            if (disable) {
                UILayout_ButtonObjects[i]->data.sobj->sprite.red = 128;
                UILayout_ButtonObjects[i]->data.sobj->sprite.green = 128;
                UILayout_ButtonObjects[i]->data.sobj->sprite.blue = 128;
            } else {
                UILayout_ButtonObjects[i]->data.sobj->sprite.red = 255;
                UILayout_ButtonObjects[i]->data.sobj->sprite.green = 255;
                UILayout_ButtonObjects[i]->data.sobj->sprite.blue = 255;
            }
        }
    }
}

void UILayout_ShowButton(s32 show, s32 id) {
    s32 i;

    if (id < 0) {
        id = 0;
    } else if (id > BUTTON_MAX) {
        id = BUTTON_MAX;
    }

    if (show) {
        UILayout_ButtonObjects[id]->data.sobj->sprite.alpha = 255;
        UILayout_ButtonObjects[id]->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        UILayout_ButtonObjects[id]->data.sobj->sprite.alpha = 0;
        UILayout_ButtonObjects[id]->data.sobj->sprite.attr |= SP_HIDDEN;
    }
}

void UILayout_SetButtonScale(f32 scale, s32 id) {
    s32 i;

    if (id < 0) {
        id = 0;
    } else if (id > BUTTON_MAX) {
        id = BUTTON_MAX;
    }

    UILayout_ButtonObjects[id]->data.sobj->sprite.scaley = scale;
    if (scale == 1.0) {
        UILayout_ButtonObjects[id]->data.sobj->sprite.attr &= ~SP_SCALE;
    } else {
        UILayout_ButtonObjects[id]->data.sobj->sprite.attr |= SP_SCALE;
    }
}

void UILayout_SetButtonText(UIButton* buttonList, char* text, s32 id) {
    while (buttonList->id != BUTTON_NONE) {
        if (buttonList->id == id) {
            buttonList->text = text;
        }
        buttonList++;
    }
}

void UILayout_HideButtons(void) {
    UIButton* button;
    f32 phase;

    if (UILayout_Buttons == NULL) {
        return;
    }

    while (UILayout_PanelState != PANEL_STATE_STABLE) {
        ohWait(1);
    }

    button = UILayout_Buttons;
    while (button->id != BUTTON_NONE) {
        if (button->id <= BUTTON_MAX) {
        }
        button++;
    }

    button = UILayout_Buttons;
    phase = (UILayout_AnimationFrames + 1) * PI_2;

    while (button->id != BUTTON_NONE) {
        if (button->id <= BUTTON_MAX) {
            GObj* obj = UILayout_ButtonObjects[button->id];

            obj->data.sobj->sprite.attr |= SP_SCALE;
            if (UILayout_IsAnimationHorizontal) {
                obj->data.sobj->sprite.scalex = 1.0f;
            } else {
                obj->data.sobj->sprite.scaley = 1.0f;
            }

            if (UILayout_IsAnimationHorizontal) {
                obj->data.sobj->unk_54 = obj->data.sobj->sprite.x;
            } else {
                obj->data.sobj->unk_54 = obj->data.sobj->sprite.y;
            }

            if (UILayout_IsInstantTransition) {
                UILayout_ButtonPhase[button->id] = 0.0f;
                do {
                } while (0); // required to match
            } else {
                UILayout_ButtonPhase[button->id] = phase;
                phase -= (f32) (UILayout_AnimationFrames * 90.0 / 9.0) * PI / 180.0f;
            }
        }
        button++;
    }

    UILayout_PanelState = PANEL_STATE_COLLAPSING;
    UILayout_Buttons = NULL;
}

void UILayout_CreateButtons(UIButton* buttons) {
    UIButton* button;
    s32 i;
    s32 numButtons, splitterPos;
    f32 phase;

    if (UILayout_Buttons != NULL) {
        if (buttons == UILayout_Buttons) {
            return;
        }
        UILayout_HideButtons();
        while (UILayout_PanelState != PANEL_STATE_STABLE) {
            ohWait(1);
        }
    }

    for (i = 0; i < 8; i++) {
        D_803A6BA0_87A350[i].id = BUTTON_NONE;
        D_803A6BE8_87A398[i] = 0;
    }

    numButtons = 0;
    splitterPos = 0;
    button = buttons;
    while (button->id != BUTTON_NONE) {
        if (button->id <= BUTTON_MAX) {
            numButtons++;
        }
        if (button->id == BUTTON_SPLITTER) {
            splitterPos = button - buttons;
        }
        button++;
    }

    button = buttons;
    phase = 0.0f;
    i = 0;

    while (button->id != BUTTON_NONE) {
        if (button->id <= BUTTON_MAX) {
            GObj* obj = UILayout_ButtonObjects[button->id];

            obj->data.sobj->sprite.attr |= SP_SCALE;
            obj->data.sobj->sprite.attr |= SP_HIDDEN;
            if (UILayout_IsAnimationHorizontal) {
                obj->data.sobj->sprite.scalex = 1.0f;
            } else {
                obj->data.sobj->sprite.scaley = 1.0f;
            }

            obj->data.sobj->sprite.x = 0;
            obj->data.sobj->sprite.y = 25 + i * 24;

            if (UILayout_IsAnimationHorizontal) {
                obj->data.sobj->unk_54 = obj->data.sobj->sprite.x;
            } else {
                obj->data.sobj->unk_54 = obj->data.sobj->sprite.y;
            }

            if (UILayout_IsInstantTransition) {
                UILayout_ButtonPhase[button->id] = PI_2;
                obj->data.sobj->sprite.attr &= ~SP_HIDDEN;
            } else {
                UILayout_ButtonPhase[button->id] = phase;
                phase -= (f32) (UILayout_AnimationFrames * 90.0 / 9.0) * PI / 180.0f;
            }
            D_803A6BA0_87A350[i++].id = button->id;
        } else if (button->id == BUTTON_SPLITTER) {
            i = splitterPos - numButtons + 8;
        }
        button++;
    }

    UILayout_PanelState = PANEL_STATE_EXPANDING;
    UILayout_Buttons = buttons;
}

void UILayout_UpdateButtons(GObj* unused) {
    s32 i;
    GObj* button;
    s32 numSlidingButtons;
    f32 scale;

    while (true) {
        numSlidingButtons = 0;
        for (i = 0; i <= BUTTON_MAX; i++) {
            button = UILayout_ButtonObjects[i];
            if (UILayout_PanelState == PANEL_STATE_EXPANDING) {
                if ((button->data.sobj->sprite.attr ^ SP_HIDDEN) & (SP_HIDDEN | SP_SCALE)) {
                    UILayout_ButtonPhase[i] += (f32) ((UILayout_AnimationFrames + 1) * 90.0 / 30.0) * PI / 180.0f;
                    if (UILayout_IsInstantTransition) {
                        UILayout_ButtonPhase[i] = PI_2;
                    }
                    if (UILayout_ButtonPhase[i] >= PI_2) {
                        UILayout_ButtonPhase[i] = PI_2;
                    } else {
                        scale = sinf(UILayout_ButtonPhase[i]);

                        if (scale < 0.001) {
                            scale = 0.001f;
                        }
                        if (UILayout_ButtonPhase[i] >= 0.0f) {
                            button->data.sobj->sprite.attr &= ~SP_HIDDEN;
                            if (UILayout_IsAnimationHorizontal) {
                                button->data.sobj->sprite.scalex = scale;
                                button->data.sobj->sprite.x = button->data.sobj->unk_54 + (1.0 - scale) * 86.0;
                            } else {
                                button->data.sobj->sprite.scaley = scale;
                                button->data.sobj->sprite.y = button->data.sobj->unk_54 + (1.0 - scale) * 15.0;
                            }
                        }
                        numSlidingButtons++;
                    }
                }
            } else if (UILayout_PanelState == PANEL_STATE_COLLAPSING) {
                if ((button->data.sobj->sprite.attr ^ SP_HIDDEN) & (SP_HIDDEN | SP_SCALE)) {
                    UILayout_ButtonPhase[i] -= (f32) ((UILayout_AnimationFrames + 1) * 90.0 / 30.0) * PI / 180.0f;
                    if (UILayout_IsInstantTransition) {
                        UILayout_ButtonPhase[i] = -PI / 1800.0f;
                    }
                    if (UILayout_ButtonPhase[i] <= 0.0f) {
                        button->data.sobj->sprite.attr |= SP_HIDDEN;
                        button->data.sobj->sprite.attr &= ~SP_SCALE;
                        if (UILayout_IsAnimationHorizontal) {
                            button->data.sobj->sprite.scalex = 1.0f;
                        } else {
                            button->data.sobj->sprite.scaley = 1.0f;
                        }
                        UILayout_ButtonPhase[i] = PI / 180.0f;
                    } else {
                        scale = sinf(UILayout_ButtonPhase[i]);
                        if (scale < 0.001) {
                            scale = 0.001f;
                        }
                        if (UILayout_ButtonPhase[i] < PI_2) {
                            if (UILayout_IsAnimationHorizontal) {
                                button->data.sobj->sprite.scalex = scale;
                                button->data.sobj->sprite.x = button->data.sobj->unk_54 + (1.0 - scale) * 86.0;
                            } else {
                                button->data.sobj->sprite.scaley = scale;
                                button->data.sobj->sprite.y = button->data.sobj->unk_54 + (1.0 - scale) * 15.0;
                            }
                            button->data.sobj->sprite.attr |= SP_SCALE;
                        }
                        numSlidingButtons++;
                    }
                }
            }
        }
        if (numSlidingButtons == 0) {
            UILayout_PanelState = PANEL_STATE_STABLE;
        }
        ohWait(1);
    }
}

void UILayout_SetHeaderFlags(s32 arg0) {
    UILayout_HeaderFlags = arg0;
}

void UILayout_ShowHeaderElement(s32 arg0) {
    UILayout_HeaderFlags |= arg0;
}

void UILayout_HideHeaderElement(s32 arg0) {
    UILayout_HeaderFlags &= ~arg0;
}

void UILayout_UpdateTitle(GObj* arg0) {
    f32 var_f0;
    f32 tmp;

    if (UILayout_HeaderFlags & HEADER_TITLE) {
        var_f0 = 0.0f;
    } else {
        var_f0 = -40.0f;
    }
    tmp = UILayout_TitlePosY;
    tmp += (var_f0 - tmp) * 0.2;
    arg0->data.sobj->sprite.y = tmp;
    var_f0 = tmp;
    if (1) {
    }
    UILayout_TitlePosY = var_f0;
}

void UILayout_UpdatePrevPageIndicator(GObj* arg0) {
    f32 var_f0;
    f32 tmp;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 tmp5;

    if (UILayout_HeaderFlags & HEADER_PREV) {
        var_f0 = 0.0f;
    } else {
        var_f0 = -40.0f;
    }
    tmp3 = UILayout_PrevPageIndicatorCounter + 1;
    tmp = UILayout_PrevPageIndicatorPosY;
    tmp2 = tmp3;
    tmp = tmp + (var_f0 - tmp) * 0.2;

    arg0->data.sobj->sprite.y = tmp;
    var_f0 = tmp;
    if (1) {
    }
    UILayout_PrevPageIndicatorPosY = var_f0;

    if (tmp2 < 0) {
        arg0->data.sobj->unk_58->sprite.bitmap = &D_803A6390_879B40;
    } else {
        arg0->data.sobj->unk_58->sprite.bitmap = &D_803A6210_8799C0;
    }
    UILayout_PrevPageIndicatorCounter = (unsigned long long) tmp2;
    tmp4 = 48;
    if (tmp2 > tmp4) {
        tmp4 = -tmp4;
        tmp5 = tmp4;
        if (1) {
            UILayout_PrevPageIndicatorCounter = tmp5;
        }
    }
}

void UILayout_UpdateNextPageIndicator(GObj* arg0) {
    f32 var_f0;
    f32 tmp;
    s32 tmp2;
    s32 tmp3;
    s32 tmp4;
    s32 tmp5;

    if (UILayout_HeaderFlags & HEADER_NEXT) {
        var_f0 = 0.0f;
    } else {
        var_f0 = -40.0f;
    }
    tmp3 = UILayout_NextPageIndicatorCounter + 1;
    tmp = UILayout_NextPageIndicatorPosY;
    tmp2 = tmp3;
    tmp = tmp + (var_f0 - tmp) * 0.2;

    arg0->data.sobj->sprite.y = tmp;
    var_f0 = tmp;
    if (1) {
    }
    UILayout_NextPageIndicatorPosY = var_f0;

    if (tmp2 < 0) {
        arg0->data.sobj->unk_58->sprite.bitmap = &D_803A6510_879CC0;
    } else {
        arg0->data.sobj->unk_58->sprite.bitmap = &D_803A6210_8799C0;
    }
    UILayout_NextPageIndicatorCounter = (unsigned long long) tmp2;
    tmp4 = 48;
    if (tmp2 > tmp4) {
        tmp4 = -tmp4;
        tmp5 = tmp4;
        if (1) {
            UILayout_NextPageIndicatorCounter = tmp5;
        }
    }
}

void UILayout_InitHeader(void) {
    GObj* obj;
    SObj* sobj;

    obj = func_80371C68_845418(UILayout_UpdatePrevPageIndicator, 6, &D_803A1B10_8752C0);
    obj->data.sobj->sprite.x = 96;
    obj->data.sobj->sprite.y = -40;
    sobj = func_80371E68_845618(obj->data.sobj, &D_803A6220_8799D0);
    sobj->sprite.x = 9;
    sobj->sprite.y = 22;
    UILayout_PreviousPageIndicator = obj;

    obj = func_80371C68_845418(UILayout_UpdateNextPageIndicator, 6, &D_803A22C0_875A70);
    obj->data.sobj->sprite.x = 280;
    obj->data.sobj->sprite.y = -40;
    sobj = func_80371E68_845618(obj->data.sobj, &D_803A6220_8799D0);
    sobj->sprite.x = 3;
    sobj->sprite.y = 22;
    UILayout_NextPageIndicator = obj;

    obj = func_80371C68_845418(UILayout_UpdateTitle, 6, &D_803A51A0_878950);
    obj->data.sobj->sprite.x = 124;
    obj->data.sobj->sprite.y = -40;
    UILayout_Title = obj;
}

void UILayout_ShowPanel(s32 show) {
    UILayout_PanelVisibility = show;
}

void UILayout_UpdatePanel(GObj* panel) {
    f32 targetX;
    f32 tmp;

    if (UILayout_PanelVisibility) {
        targetX = 0.0f;
    } else {
        targetX = -180.0f;
    }
    tmp = UILayout_PanelPosX;
    tmp += (targetX - tmp) * 0.15;
    panel->data.sobj->sprite.x = tmp;
    targetX = tmp;
    if (1) {
    }
    UILayout_PanelPosX = targetX;
}

char* UILayout_GetButtonText(UIButton* tabs, s32 id) {
    while (tabs->id != BUTTON_NONE) {
        if (id == tabs->id) {
            return tabs->text;
        }
        tabs++;
    }
    return "";
}

void UILayout_Init(void) {
    GObj* panelObj;
    GObj* tabObj;
    s32 i;

    panelObj = func_80371C68_845418(UILayout_UpdatePanel, LINK_6, &D_803A1360_874B10);
    panelObj->data.sobj->sprite.x = -180;
    panelObj->data.sobj->sprite.y = 0;
    panelObj->data.sobj->sprite.attr |= SP_SCALE | SP_TRANSPARENT;
    panelObj->data.sobj->sprite.scalex = 23.0f;
    panelObj->data.sobj->sprite.scaley = 60.0f;
    panelObj->data.sobj->sprite.alpha = 178;
    UILayout_Panel = panelObj;

    for (i = 0; i <= BUTTON_MAX; i++) {
        tabObj = func_80371D14_8454C4(i != 0 ? NULL : UILayout_UpdateButtons, LINK_6, &D_80382CE0_856490);
        tabObj->data.sobj->sprite.bitmap = D_803A6564_879D14[i];
        tabObj->data.sobj->sprite.x = 0;
        tabObj->data.sobj->sprite.y = 20 + i * 30;
        tabObj->data.sobj->sprite.attr &= ~SP_SCALE;
        tabObj->data.sobj->sprite.attr |= SP_HIDDEN;
        tabObj->data.sobj->sprite.scalex = 1.0f;
        tabObj->data.sobj->sprite.scaley = 1.0f;
        UILayout_ButtonObjects[i] = tabObj;
        UILayout_ButtonPhase[i] = 0.0001f;
    }

    UILayout_PanelState = PANEL_STATE_STABLE;
    UILayout_Buttons = 0;
    UILayout_InitHeader();
}
