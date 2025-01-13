#ifndef _WINDOW_H
#define _WINDOW_H

enum FrameStyle {
    FRAME_STYLE_0,
    FRAME_STYLE_1,
    FRAME_STYLE_2,
    FRAME_STYLE_3
};

enum UiFlags {
    UI_FLAG_BORDER = 0x001,
    UI_FLAG_THICK_BORDER = 0x002,
    UI_FLAG_10 = 0x010,
    UI_FLAG_SHOW_ALT = 0x040,
    UI_FLAG_USE_ALT_IMAGE = 0x080,
    UI_FLAG_SCALABLE = 0x100,
    UI_FLAG_8BIT = 0x200,
    UI_FLAG_32BIT = 0x400,
    UI_FLAG_GRAYSCALE = 0x800
};

enum {
    UI_BACKGROUND = 0,
    UI_FOREGROUND = 1
};

enum UiStates {
    UI_NORMAL,
    UI_HIDDEN
};

enum UiFonts {
    FONT_8 = 8,
    FONT_12 = 12
};

enum Buttons {
    BUTTON_RETURN = 5,
    BUTTON_GO_TO_LAB = 17,
    BUTTON_DELETE = 19,
    BUTTON_ENLARGE = 20,
    BUTTON_ARRANGE = 26,
    BUTTON_COMMENT = 27,
    BUTTON_CHECK = 28,
    BUTTON_OPEN = 30,
    BUTTON_RETURN_TO_COVER = 31,
    BUTTON_MAX = 32,
    BUTTON_SPLITTER = 34,
    BUTTON_NONE = 35
};

enum HeaderFlags {
    HEADER_PREV = 1,
    HEADER_NEXT = 2,
    HEADER_TITLE = 4
};

enum HeaderStates {
    PANEL_STATE_COLLAPSING = 0,
    PANEL_STATE_EXPANDING = 1,
    PANEL_STATE_STABLE = 2
};

typedef struct UnkSnow2 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} UnkSnow2;

typedef struct UIText {
    /* 0x00 */ u8* image;
    /* 0x04 */ s32 width;
    /* 0x08 */ s32 height;
    /* 0x0C */ s32 bpp;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 screenX;
    /* 0x18 */ s32 screenY;
    /* 0x1C */ s32 font;
    /* 0x20 */ s32 unk_118;
    /* 0x24 */ s32 unk_11C;
    /* 0x28 */ s32 curX;
    /* 0x2C */ s32 curY;
} UIText; // size = 0x30

typedef struct UIElement {
    /*  0x00 */ s32 x;
    /*  0x04 */ s32 y;
    /*  0x08 */ s32 borderWidth;
    /*  0x0C */ s32 borderHeight;
    /*  0x10 */ s32 width;
    /*  0x14 */ s32 height;
    /*  0x18 */ u32 flags;
    /*  0x1C */ u32 unk_1C;
    /*  0x20 */ u32 unk_20;
    /*  0x24 */ u32 unk_24;
    /*  0x28 */ u32 unk_28;
    /*  0x2C */ s32 altX;
    /*  0x30 */ s32 altY;
    /*  0x34 */ s32 altWidth;
    /*  0x38 */ s32 altHeight;
    /*  0x3C */ struct UIElement* next;
    /*  0x40 */ struct UIElement* prev;
    /*  0x44 */ s32 imageWidth;
    /*  0x48 */ ucolor fgColor;
    /*  0x4C */ ucolor bgColor;
    /*  0x50 */ GObj* spriteObj;
    /*  0x54 */ u8* image;
    /*  0x58 */ u8* altImage;
    /*  0x5C */ s32 unk_5C;
    /*  0x60 */ s32 bpp;
    /*  0x64 */ Sprite sprite;
    /*  0xA8 */ Sprite altSprite;
    /*  0xEC */ Gfx* rsp_dl;
    /*  0xF0 */ Bitmap* bitmaps;
    /*  0xF4 */ Bitmap* altBitmaps;
    /*  0xF8 */ UIText text;
    /* 0x128 */ s32 id;
    /* 0x12C */ u8 pad_12C[4];
} UIElement; // size == 0x130

void* UIMem_Allocate(u32);
void UIMem_Deallocate(void*);
void UIMem_CreateHeap(u8*, s32);
void UIElement_FillRect(UIElement*, s32, s32, s32, s32, s32, s32, s32, s32);
void UIElement_Draw(UIElement*);
void UIElement_FillRectDefault(UIElement*, s32, s32, s32, s32);
void UIElement_FillRectWithBorder(UIElement*, UNK_TYPE, UNK_TYPE, s32, s32, s32, s32, s32, s32);
UIElement* UIElement_Create(s32, s32, s32, s32, s32);
void UIElement_Delete(UIElement*);
void UIElement_SwapImages(UIElement*);
void UIElement_DrawBackground(UIElement*);
void UIElement_SetColor(UIElement*, s32, s32, s32, s32, s32);
void UIElement_SetTextPos(UIElement*, s32 x, s32 y);
void UIElement_VertScroll(UIElement*, s32, s32, s32, s32, s32, s32);
void UIElement_PrintText(UIElement*, char*);
void UIElement_PrintAsciiString(UIElement*, char*);
void UIElement_SetFont(UIElement*, s32);
void UIElement_SetPos(UIElement*, s32 x, s32 y);
void UIElement_SetState(UIElement*, s32);
void UIElement_SetSpriteColor(UIElement*, s32, s32, s32, s32);
s32 UIText_SetFont(s32);
void UIText_SetSpacing(s32, s32);
void UIText_SetShadowOffset(s32);
void UIText_SetPrintDelay(s32);
void func_8036D4B4_840C64(s32, s32);
s32 UIText_GetStringWidth(char*);
s32 UIText_GetCharsWidth(void);
s32 func_8036D774_840F24(void);
void UIText_MakePalettes(UIText*, ucolor*, ucolor*);
void UIText_PrintString(UIText* arg0, s32* arg1, s32* arg2, u8* arg3);
void UIText_PrintAsciiString(UIText* arg0, s32* arg1, s32* arg2, u8* arg3);
void UIText_PrintAsciiString(UIText*, s32*, s32*, u8*);
void func_8036EB80_842330(s32);
void func_8036EB8C_84233C(void (*)(s32));
void UIText_Initialize(void);
void UIButton_DeleteAll(void);
void UIButton_DeleteInRect(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void UIButton_SetStateInsideRect(s32, s32, s32, s32, s32);
void UIFrame_ShowBackground(UIFrame*, bool show);
void UIFrame_Show(UIFrame*, bool show);
void UIFrame_SetOpacity(UIFrame*, s32 alpha);
void UIFrame_SetPos(UIFrame*, s32, s32);
void UIFrame_SetSize(UIFrame*, s32, s32);
void UIFrame_SetStyle(UIFrame*, s32);
void UIFrame_GetBackgroundColor(UIFrame*, ucolor*);
UIFrame* UIFrame_Create(void);
void UIFrame_FadeIn(UIFrame*, s32);
void UIFrame_FadeOut(UIFrame*);
s32 FocusMark_SetTargetPos(s32, s32);
void FocusMark_SetPos(s32, s32);
void FocusMark_SetTargetSize(s32, s32);
void FocusMark_SetSize(s32, s32);
void FocusMark_StopAnimation(bool);
void FocusMark_Show(s32);
void FocusMark_MoveFront(void);
void FocusMark_Create(void);
void UILayout_WaitPanelTransitionComplete(void);
void UILayout_SetInstantTransition(s32);
UIButton* func_80370600_843DB0(void);
void UILayout_DisableAllButtonsExcept(s32, s32);
void UILayout_DisableButton(s32, s32);
void UILayout_ShowButton(s32, s32);
void UILayout_SetButtonScale(f32, s32);
void UILayout_HideButtons(void);
void UILayout_CreateButtons(UIButton*);
void UILayout_SetHeaderFlags(s32);
void UILayout_ShowHeaderElement(s32);
void UILayout_HideHeaderElement(s32);
void UILayout_ShowPanel(s32);
char* UILayout_GetButtonText(UIButton*, s32);
void UILayout_Init(void);
void func_803719B0_845160(SObj*, s32, s32, s32, s32, s32, s32);
GObj* func_80371C68_845418(void (*func)(GObj*), s32 link, Sprite* sprite);
SObj* func_80371DC0_845570(SObj*, Sprite*);
SObj* func_80371E68_845618(SObj*, Sprite*);
void func_80371F30_8456E0(s32, s32, s32, s32);
void func_80373670_846E20(Sprite*);
PhotoData* func_803746B4_847E64(s32);
bool func_80374714_847EC4(PhotoData*, Sprite*);
void func_80374D20_8484D0(void);
void func_80374D40_8484F0(void);
s32 func_80374F30_8486E0(UIElement*, bool);
char* func_8037501C_8487CC(char*, s32);
s32 func_803750CC_84887C(char*, char*);
s32 func_8037519C_84894C(UIElement*, const char*, ...);
s32 func_803751F8_8489A8(s32);
void func_80375284_848A34(s32);
UIButton* UILayout_GetButtons(void);

#if !defined(M2CTX) && !defined(PERMUTER)
GObj* func_80371D14_8454C4(void (*gfxFunc)(GObj*), s32 arg1, Sprite* sprite);
#endif

#endif
