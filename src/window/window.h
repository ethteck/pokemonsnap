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

void* func_8036A194_83D944(u32);
void func_8036A228_83D9D8(void*);
void func_8036A3F8_83DBA8(void*, s32);
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
void func_8036EE40_8425F0(void);
void func_8036EEB0_842660(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8036EFEC_84279C(s32, s32, s32, s32, s32);
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
s32 func_8036FFE0_843790(s32, s32);
void func_80370004_8437B4(s32, s32);
void func_80370038_8437E8(s32, s32);
void func_8037005C_84380C(s32, s32);
void func_80370090_843840(bool);
void func_803700A4_843854(s32);
void func_80370134_8438E4(void);
void func_80370428_843BD8(void);
void func_803705A4_843D54(void);
void func_803705F0_843DA0(s32);
UnkCanaryScallop* func_80370600_843DB0(void);
void func_8037060C_843DBC(s32, s32);
void func_80370780_843F30(s32, s32);
void func_80370900_8440B0(s32, s32);
void func_80370990_844140(f32, s32);
void func_80370A48_8441F8(void);
void func_80370C34_8443E4(void*);
void func_803713C8_844B78(s32);
void func_803713D4_844B84(s32);
void func_803713EC_844B9C(s32);
void func_8037172C_844EDC(s32);
char* func_803717A8_844F58(UnkCyanBass*, s32);
void func_803717E8_844F98(void);
void func_803719B0_845160(SObj*, s32, s32, s32, s32, s32, s32);
GObj* func_80371C68_845418(void*, s32, Sprite*);
SObj* func_80371DC0_845570(SObj*, Sprite*);
SObj* func_80371E68_845618(SObj*, Sprite*);
void func_80371F30_8456E0(s32, s32, s32, s32);
void func_80373670_846E20(Sprite*);
PhotoData* func_803746B4_847E64(s32);
UNK_TYPE func_80374714_847EC4(PhotoData*, Sprite*);
void func_80374D20_8484D0(void);
void func_80374D40_8484F0(void);
s32 func_80374F30_8486E0(UIElement*, bool);
char* func_8037501C_8487CC(char*, s32);
s32 func_803750CC_84887C(char*, char*);
void func_8037519C_84894C(UIElement*, char*, ...);
s32 func_803751F8_8489A8(s32);
void func_80375284_848A34(s32);

#if !defined(M2CTX) && !defined(PERMUTER)
GObj* func_80371D14_8454C4(void (*gfxFunc)(GObj*), s32 arg1, Sprite* sprite);
#endif

#endif
