#include "common.h"
#include "window.h"

extern u8* D_8037EA68_852218[];

s32 UIText_Charset = 0;
s32 UIText_HorizontalSpacing = -2;
s32 UIText_VerticalSpacing = 4;
s32 UIText_GlyphSize[2] = { 8, 12 };
s32 UIText_ShadowOffset = 2;
s32 UIText_HorizontalInterval = 12;
s32 UIText_VerticalInterval = 12;
ucolor UIText_ShadowColor = { 0, 0, 0, 255 };
s32 UIText_PrintDelay = 3;
s32 UIText_DelayDisabled = false;
s32 D_8037EACC_85227C = 1;
ucolor UIText_BlackColor = { 0, 0, 0, 255 };
ucolor UIText_WhiteColor = { 255, 255, 255, 255 };
ucolor UIText_RedColor = { 255, 0, 0, 255 };
ucolor UIText_YellowColor = { 255, 255, 0, 255 };
s32 D_8037EAE0_852290 = false;
// clang-format off
u8 UIText_CharTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                         "abcdefghijklmnopqrstuvwxyz"
                         "1234567890"
                         "\xA0\x9F~!@#$%&*()_+=-'\";:/.,?<>\x9E\x9D\x9C\x9B\x9A[]"
                         "\xE9\x99\x98\xC9\xC4\xD6\xDC\xE4\xF6\xFC\xE2\xE0\xEE\xEF\xFB\xF9\xE8\xEA\xEB\xF4\xF3\xC1\xCD\xD3\xDA\xD1\xF1\xE1\xED\xEC\xFA\xF2\xC0\xC8\xD2\xD9\xA1\xBF\xBA\xAA\xE7\xDF\xC2\xD4\xC7\xCC";
u8 UIText_WidthTable[2][142] = {
    {
        5, 5, 5, 5, 5, 5, 5, 5, 3, 5,
        5, 4, 5, 5, 5, 5, 5, 5, 4, 5,
        5, 5, 5, 5, 5, 5, 5, 4, 3, 4,
        4, 4, 4, 4, 2, 3, 4, 1, 5, 4,
        4, 3, 4, 3, 3, 4, 4, 4, 5, 4,
        4, 4, 3, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 2, 5, 5, 4, 5,
        5, 5, 2, 2, 4, 5, 3, 3, 1, 3,
        2, 1, 3, 1, 2, 4, 3, 3, 5, 5,
        5, 5, 5, 2, 2, 4, 5, 5, 5, 5,
        5, 5, 5, 4, 4, 5, 5, 3, 3, 4,
        4, 4, 4, 4, 4, 4, 5, 3, 5, 5,
        5, 4, 5, 4, 4, 4, 4, 5, 5, 5,
        5, 2, 4, 4, 5, 3, 5, 5, 5, 5,
        3, 0,
    },
    {
        8, 7, 8, 8, 7, 7, 7, 7, 5, 8,
        7, 6, 8, 8, 8, 7, 8, 7, 6, 8,
        8, 8, 8, 8, 8, 7, 7, 6, 5, 6,
        6, 6, 5, 6, 2, 4, 5, 2, 8, 6,
        6, 5, 6, 5, 4, 6, 6, 6, 7, 5,
        6, 6, 3, 7, 8, 8, 7, 6, 7, 6,
        6, 8, 8, 8, 8, 3, 8, 8, 6, 8,
        7, 8, 4, 4, 6, 8, 5, 5, 2, 5,
        2, 2, 5, 2, 2, 6, 5, 5, 8, 7,
        8, 8, 8, 4, 4, 6, 8, 7, 7, 8,
        8, 8, 7, 6, 6, 7, 7, 5, 3, 6,
        6, 6, 6, 6, 6, 6, 8, 5, 8, 8,
        8, 6, 7, 3, 3, 6, 6, 8, 7, 8,
        8, 3, 6, 6, 7, 5, 7, 8, 8, 7,
        5, 0,
    }
};
// clang-format on
static u8 padding[0x10];
static u32 UIText_TextPalette[16];
static u32 UIText_ShadowPalette[16];
static u32 UIText_ShadowedTextPalette[16];
static s32 padding2;
static ucolor D_803A6A04_87A1B4;
static ucolor D_803A6A08_87A1B8;
static void (*D_803A6A0C_87A1BC)(s32);

s32 UIText_Ascii2WideChar(s32 arg0);
void* UIButtonImage_Create(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 UIText_GetCharIndex(s32 ch) {
    u8* p = UIText_CharTable;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(UIText_CharTable); i++) {
        if (ch == p[i]) {
            return i;
        }
    }
    return 0;
}

s32 UIText_SetFont(s32 font) {
    switch (font) {
        case FONT_12:
            UIText_Charset = 1;
            break;
        default:
            UIText_Charset = 0;
            break;
    }

    UIText_HorizontalInterval = UIText_GlyphSize[UIText_Charset] + UIText_HorizontalSpacing + UIText_ShadowOffset;
    UIText_VerticalInterval = UIText_GlyphSize[UIText_Charset] + UIText_VerticalSpacing + UIText_ShadowOffset;
    return 0;
}

s32 func_8036D3D8_840B88(s32 arg0, s32 arg1) {
    return 0;
}

void UIText_SetSpacing(s32 arg0, s32 arg1) {
    UIText_HorizontalSpacing = arg0;
    UIText_VerticalSpacing = arg1;
    UIText_HorizontalInterval = UIText_GlyphSize[UIText_Charset] + UIText_HorizontalSpacing + UIText_ShadowOffset;
    UIText_VerticalInterval = UIText_GlyphSize[UIText_Charset] + UIText_VerticalSpacing + UIText_ShadowOffset;
}

void UIText_SetShadowOffset(s32 arg0) {
    UIText_ShadowOffset = arg0;
    UIText_HorizontalInterval = UIText_GlyphSize[UIText_Charset] + UIText_HorizontalSpacing + UIText_ShadowOffset;
    UIText_VerticalInterval = UIText_GlyphSize[UIText_Charset] + UIText_VerticalSpacing + UIText_ShadowOffset;
}

void UIText_SetPrintDelay(s32 arg0) {
    UIText_PrintDelay = arg0;
    UIText_DelayDisabled = false;
}

void func_8036D4B4_840C64(s32 flags, s32 set) {
    if (set) {
        D_8037EACC_85227C |= flags;
    } else {
        D_8037EACC_85227C &= ~flags;
    }
}

s32 UIText_GetStringWidth(char* ptr) {
    u8* text;
    s32 printedChar;
    s32 charset;
    s32 width = 0;
    s32 s4 = D_8037EACC_85227C & 1;
    s32 v1;

    charset = UIText_Charset;
    text = ptr;

    while (*text) {
        s32 isSpecial = false;
        s32 c = *text;

        switch (*text) {
            case '\n':
                printedChar = '\n';
                break;
            case '\\':
                printedChar = ((text[0] << 8) & 0xFF00) | (text[1] & 0xFF);
                if (text[1]) {
                    text++;
                }
                break;
            default:
                if (*text < ' ') {
                    printedChar = ' ';
                } else {
                    printedChar = *text;
                }
                break;
        }

        switch (printedChar) {
            case '\\a':
            case '\\b':
            case '\\c':
            case '\\d':
            case '\\f':
            case '\\l':
            case '\\m':
            case '\\r':
            case '\\s':
            case '\\u':
            case '\\z':
                width += 12;
                isSpecial = true;
                break;
            case '\\i':
                s4 = 0;
                isSpecial = true;
                break;
            case '\\g':
                s4 = 1;
                isSpecial = true;
                break;
            case '\\j':
                charset = 0;
                isSpecial = true;
                break;
            case '\\k':
                charset = 1;
                isSpecial = true;
                break;
            case '\\e':
            case '\\h':
            case '\\n':
            case '\\p':
            case '\\t':
            case '\\w':
                isSpecial = true;
                break;
            case ' ':
                if (s4 != 0) {
                    width += charset ? 4 : 2;
                } else {
                    width += charset ? 9 : 6;
                }
                isSpecial = true;
                break;
            default:
                if (c == '\\') {
                    isSpecial = true;
                }
                break;
        }

        if (!isSpecial) {
            if (s4 != 0) {
                width += UIText_WidthTable[charset][UIText_GetCharIndex(printedChar)] + 1;
            } else {
                width += charset ? 9 : 6;
            }
        }

        text++;
    }

    return width;
}

s32 UIText_GetCharsWidth(void) {
    return UIText_GlyphSize[UIText_Charset];
}

s32 func_8036D774_840F24(void) {
    return 0;
}

void UIText_MakePalettes(UIText* text, ucolor* fgColor, ucolor* bgColor) {
    s32 i;
    s32 r, g, b, a;

    D_803A6A04_87A1B4 = *fgColor;
    D_803A6A08_87A1B8 = *bgColor;

    for (i = 0; i < 16; i++) {
        r = (fgColor->r - bgColor->r) * i / 15 + bgColor->r;
        g = (fgColor->g - bgColor->g) * i / 15 + bgColor->g;
        b = (fgColor->b - bgColor->b) * i / 15 + bgColor->b;
        a = (fgColor->a - bgColor->a) * i / 15 + bgColor->a;
        UIText_TextPalette[i] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | ((a != 0) & 0x1);

        r = (UIText_ShadowColor.r - bgColor->r) * i / 15 + bgColor->r;
        g = (UIText_ShadowColor.g - bgColor->g) * i / 15 + bgColor->g;
        b = (UIText_ShadowColor.b - bgColor->b) * i / 15 + bgColor->b;
        a = (UIText_ShadowColor.a - bgColor->a) * i / 15 + bgColor->a;
        UIText_ShadowPalette[i] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | ((a != 0) & 0x1);

        r = (fgColor->r - UIText_ShadowColor.r) * i / 15 + UIText_ShadowColor.r;
        g = (fgColor->g - UIText_ShadowColor.g) * i / 15 + UIText_ShadowColor.g;
        b = (fgColor->b - UIText_ShadowColor.b) * i / 15 + UIText_ShadowColor.b;
        a = (fgColor->a - UIText_ShadowColor.a) * i / 15 + UIText_ShadowColor.a;
        UIText_ShadowedTextPalette[i] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | ((a != 0) & 0x1);
    }
}

void func_8036DC4C_8413FC(s32 r, s32 g, s32 b, s32 a) {
    UIText_ShadowColor.r = r;
    UIText_ShadowColor.g = g;
    UIText_ShadowColor.b = b;
    UIText_ShadowColor.a = a;
}

u8* UIText_GetGlyph(s32 ch) {
    u8* p = UIText_CharTable;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(UIText_CharTable); i++) {
        u8* tmp = D_8037EA68_852218[UIText_Charset];
        if (p[i] == ch) {
            return i * UIText_GlyphSize[UIText_Charset] * UIText_GlyphSize[UIText_Charset] / 2 + tmp;
        }
    }

    return 0;
}

s32 UIText_PrintChar16(UIText* arg0, s32 x, s32 y, s32 ch) {
    u16* img;
    u16* shadowImg;
    u8* glyph;
    s32 i, j, k;
    s32 ci;

    img = (u16*) arg0->image + y * arg0->width + x;
    glyph = UIText_GetGlyph(ch);
    // clang-format off
    if (glyph == NULL) { return UIText_GlyphSize[UIText_Charset] + UIText_ShadowOffset; }
    // clang-format on

    for (i = 0; i < UIText_GlyphSize[UIText_Charset]; i++) {
        if (y + i < arg0->height) {
            for (j = 0; j < UIText_GlyphSize[UIText_Charset]; img++, j++) {
                if (x + j >= arg0->width) {
                    continue;
                }
                if (j & 1) {
                    ci = (*glyph & 0xF0) >> 4;
                    glyph++;
                } else {
                    ci = *glyph & 0xF;
                }

                if (ci == 0) {
                    continue;
                }

                if (img[arg0->width + 1] == UIText_ShadowPalette[15] || img[0] == UIText_ShadowPalette[15]) {
                    *img = UIText_ShadowedTextPalette[ci];
                } else {
                    *img = UIText_TextPalette[ci];
                }

                for (shadowImg = img, k = UIText_ShadowOffset; k > 0; k--) {
                    if (y + i + k < arg0->height && x + j + k < arg0->width) {
                        shadowImg += arg0->width + 1;
                        *shadowImg = k == 1 ? UIText_ShadowPalette[ci] : UIText_ShadowPalette[15];
                    }
                }
            }
            img += arg0->width - UIText_GlyphSize[UIText_Charset];
        }
    }

    return UIText_GlyphSize[UIText_Charset] + UIText_ShadowOffset;
}

void UIText_GetBlendedColor(ucolor* arg0, ucolor* arg1, s32 arg2) {
    arg0->r += (arg1->r - arg0->r) * arg2 / 15;
    arg0->g += (arg1->g - arg0->g) * arg2 / 15;
    arg0->b += (arg1->b - arg0->b) * arg2 / 15;
    arg0->a += (arg1->a - arg0->a) * arg2 / 15;
}

s32 UIText_PrintChar32(UIText* arg0, s32 x, s32 y, s32 ch) {
    u32* img;
    u32* v1;
    u8* glyph;
    s32 ci;
    s32 i, j, k;

    img = (u32*) arg0->image + y * arg0->width + x;
    glyph = UIText_GetGlyph(ch);
    if (glyph == NULL) {
        return UIText_GlyphSize[UIText_Charset] + UIText_ShadowOffset;
    }

    for (i = 0; i < UIText_GlyphSize[UIText_Charset]; i++) {
        if (y + i < arg0->height) {
            for (j = 0; j < UIText_GlyphSize[UIText_Charset]; img++, j++) {
                if (x + j >= arg0->width) {
                    if (0) {
                    } // TODO required to match
                    continue;
                }
                if (j & 1) {
                    ci = (*glyph++ & 0xF0) >> 4;
                } else {
                    ci = *glyph & 0xF;
                }

                if (ci == 0) {
                    continue;
                }

                UIText_GetBlendedColor((ucolor*) img, &D_803A6A04_87A1B4, ci);

                for (v1 = img, k = UIText_ShadowOffset; k > 0; k--) {
                    v1 += arg0->width + 1;
                    if (k == 1) {
                        UIText_GetBlendedColor((ucolor*) v1, &UIText_ShadowColor, ci);
                    } else {
                        UIText_GetBlendedColor((ucolor*) v1, &UIText_ShadowColor, 15);
                    }
                }
            }
            img += arg0->width - UIText_GlyphSize[UIText_Charset];
        }
    }

    return UIText_GlyphSize[UIText_Charset] + UIText_ShadowOffset;
}

void UIText_PrintString(UIText* text, s32* x, s32* y, char* str) {
    s32 printedChar;
    u8* ptr = str;
    s32 i;
    s32 posX;
    s32 tmp;

    while (*ptr) {
        u32 c = ptr[0] & 0xFF;

        switch (*ptr) {
            case '\n':
                goto NEXT_LINE;
            case '\\':
                printedChar = ((ptr[0] << 8) & 0xFF00) | (ptr[1] & 0xFF);
                ptr++;
                break;
            default:
                printedChar = *ptr < ' ' ? ' ' : *ptr;
                break;
        }
        switch (printedChar) {
            case ' ':
                goto SKIP_PRINTING;
            case '\\a':
            case '\\b':
            case '\\c':
            case '\\d':
            case '\\f':
            case '\\l':
            case '\\m':
            case '\\r':
            case '\\s':
            case '\\u':
            case '\\z':
                UIButtonImage_Create(*x + text->screenX, *y + text->screenY, printedChar, UIText_GlyphSize[UIText_Charset]);
                goto SKIP_PRINTING;
            case '\\e':
                UIText_MakePalettes(text, &UIText_RedColor, &D_803A6A08_87A1B8);
                goto END;
            case '\\h':
                UIText_MakePalettes(text, &UIText_YellowColor, &D_803A6A08_87A1B8);
                goto END;
            case '\\p':
                UIText_MakePalettes(text, &UIText_WhiteColor, &D_803A6A08_87A1B8);
                goto END;
            case '\\w':
                UIText_DelayDisabled = false;
                D_8037EAE0_852290 = false;
                goto END;
            case '\\t':
                D_8037EAE0_852290 = true;
                goto END;
            case '\\g':
                func_8036D4B4_840C64(1, true);
                goto END;
            case '\\i':
                func_8036D4B4_840C64(1, false);
                goto END;
            case '\\j':
                UIText_SetFont(0); // BUG: 0 is not valid font
                goto END;
            case '\\k':
                UIText_SetFont(1); // BUG: 1 is not valid font
                goto END;
            default:
                if (c == '\\') {
                    if (UIText_PrintDelay != 0 && D_803A6A0C_87A1BC != NULL && !UIText_DelayDisabled) {
                        D_803A6A0C_87A1BC(printedChar);
                    }
                    goto END;
                }
                break;
        }

        if (D_8037EACC_85227C & 1) {
            posX = *x;
        } else {
            tmp = UIText_Charset != 0 ? 9 : 6;
            posX = *x + (s32) ((tmp - UIText_WidthTable[UIText_Charset][UIText_GetCharIndex(printedChar)]) * .5 + 0.5);
        }
        if (text->bpp == 4) {
            UIText_PrintChar32(text, posX, *y, printedChar);
        } else {
            UIText_PrintChar16(text, posX, *y, printedChar);
        }
        if (D_803A6A0C_87A1BC != NULL && !UIText_DelayDisabled) {
            D_803A6A0C_87A1BC(printedChar);
        }
    SKIP_PRINTING:
        i = UIText_PrintDelay;
        while (i > 0 && !UIText_DelayDisabled) {
            i--;
            ohWait(1);
        }

        if (D_8037EACC_85227C & 1) {
            switch (printedChar) {
                case ' ':
                    tmp = UIText_Charset != 0 ? 4 : 2;
                    *x += tmp;
                    break;
                case '\\a':
                case '\\b':
                case '\\c':
                case '\\d':
                case '\\f':
                case '\\l':
                case '\\m':
                case '\\r':
                case '\\s':
                case '\\u':
                case '\\z':
                    *x += UIText_Charset != 0 ? 13 : 9;
                    break;
                default:
                    *x += UIText_WidthTable[UIText_Charset][UIText_GetCharIndex(printedChar)] + 1;
                    break;
            }
        } else {
            *x += UIText_Charset != 0 ? 9 : 6;
        }

        if (*x > text->width - UIText_HorizontalInterval) {
        NEXT_LINE:
            *x = 0;
        } else {
            goto END;
        }

        *y += UIText_VerticalInterval;
        if (*y > text->height - UIText_GlyphSize[UIText_Charset] - UIText_ShadowOffset) {
            *y = 0;
        }

    END:
        ptr++;
    }

    UIText_DelayDisabled = false;
}

void UIText_PrintAsciiString(UIText* text, s32* x, s32* y, u8* str) {
    s32 printedChar;
    u8* ptr = str;

    while (*ptr) {
        s32 c = ptr[0];

        if (ptr[0] > 0x20 && ptr[0] < 0xFD) {
            printedChar = ptr[0];
            if (text->bpp == 4) {
                UIText_PrintChar32(text, *x, *y, printedChar);
            } else {
                UIText_PrintChar16(text, *x, *y, printedChar);
            }
        }
        *x += UIText_HorizontalInterval;
        if (*x > text->width - UIText_HorizontalInterval) {
            *x = 0;
            *y += UIText_VerticalInterval;
            if (*y > text->height - UIText_GlyphSize[UIText_Charset] - UIText_ShadowOffset) {
                *y = 0;
            }
        }
        ptr++;
    }
}

void func_8036EB34_8422E4(GObj* arg0) {
    if (D_8037EAE0_852290 && (func_800AA38C(0)->pressedButtons & (0x8000 | 0x4000))) {
        UIText_DelayDisabled = true;
    }
}

void func_8036EB80_842330(s32 arg0) {
    D_8037EAE0_852290 = arg0;
}

void func_8036EB8C_84233C(void (*arg0)(s32)) {
    D_803A6A0C_87A1BC = arg0;
}

void UIText_Initialize(void) {
    func_800A86A4(func_8036EB34_8422E4, LINK_6, DL_LINK_0, NULL);
    UIText_PrintDelay = 0;
    D_803A6A0C_87A1BC = NULL;
    UIText_DelayDisabled = false;
}
