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
extern u8 UIText_CharTable[] = { 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0xa0, 0x9f, 0x7e, 0x21, 0x40, 0x23, 0x24, 0x25, 0x26, 0x2a, 0x28, 0x29, 0x5f, 0x2b, 0x3d, 0x2d, 0x27, 0x22, 0x3b, 0x3a, 0x2f, 0x2e, 0x2c, 0x3f, 0x3c, 0x3e, 0x9e, 0x9d, 0x9c, 0x9b, 0x9a, 0x5b, 0x5d, 0xe9, 0x99, 0x98, 0xc9, 0xc4, 0xd6, 0xdc, 0xe4, 0xf6, 0xfc, 0xe2, 0xe0, 0xee, 0xef, 0xfb, 0xf9, 0xe8, 0xea, 0xeb, 0xf4, 0xf3, 0xc1, 0xcd, 0xd3, 0xda, 0xd1, 0xf1, 0xe1, 0xed, 0xec, 0xfa, 0xf2, 0xc0, 0xc8, 0xd2, 0xd9, 0xa1, 0xbf, 0xba, 0xaa, 0xe7, 0xdf, 0xc2, 0xd4, 0xc7, 0xcc, 0x00 };

s32 unused_2 = 0;
u16 UIText_AsciiTable[] = {
    '！', '”', '＃', '＄', '％', '＆', '’', '（', '）', '＊',
    '＋', '，', 'ー', '．', '／', '０', '１', '２', '３', '４',
    '５', '６', '７', '８', '９', '：', '；', '＜', '＝', '＞',
    '？', '＠', 'Ａ', 'Ｂ', 'Ｃ', 'Ｄ', 'Ｅ', 'Ｆ', 'Ｇ', 'Ｈ',
    'Ｉ', 'Ｊ', 'Ｋ', 'Ｌ', 'Ｍ', 'Ｎ', 'Ｏ', 'Ｐ', 'Ｑ', 'Ｒ',
    'Ｓ', 'Ｔ', 'Ｕ', 'Ｖ', 'Ｗ', 'Ｘ', 'Ｙ', 'Ｚ', '［', '￥',
    '］', '＾', '＿', '‘', 'ａ', 'ｂ', 'ｃ', 'ｄ', 'ｅ', 'ｆ',
    'ｇ', 'ｈ', 'ｉ', 'ｊ', 'ｋ', 'ｌ', 'ｍ', 'ｎ', 'ｏ', 'ｐ',
    'ｑ', 'ｒ', 'ｓ', 'ｔ', 'ｕ', 'ｖ', 'ｗ', 'ｘ', 'ｙ', 'ｚ',
    '｛', '｜', '｝', '￣',
};
s32 unused_3 = 0;

u8 UIText_WidthTable[2][370] = {
    {
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 5, 5, 5, 5, 5, 5, 5, 5,
        3, 5, 5, 4, 5, 5, 5, 5, 5, 5,
        4, 5, 5, 5, 5, 5, 5, 5, 5, 4,
        3, 4, 4, 4, 4, 4, 2, 3, 4, 1,
        5, 4, 4, 3, 4, 3, 3, 4, 4, 4,
        5, 4, 4, 4, 3, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 2, 5, 5,
        4, 5, 5, 5, 2, 2, 4, 5, 3, 3,
        1, 3, 2, 1, 3, 1, 2, 4, 3, 3,
        5, 5, 5, 5, 5, 2, 2, 4, 5, 5,
    },
    {
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 8, 7, 8, 8, 7, 7, 7, 7,
        5, 8, 7, 6, 8, 8, 8, 7, 8, 7,
        6, 8, 8, 8, 8, 8, 8, 7, 7, 6,
        5, 6, 6, 6, 5, 6, 2, 4, 5, 2,
        8, 6, 6, 5, 6, 5, 4, 6, 6, 6,
        7, 5, 6, 6, 3, 7, 8, 8, 7, 6,
        7, 6, 6, 8, 8, 8, 8, 3, 8, 8,
        6, 8, 7, 8, 4, 4, 6, 8, 5, 5,
        2, 5, 2, 2, 5, 2, 2, 6, 5, 5,
        8, 7, 8, 8, 8, 4, 4, 6, 8, 7,
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
        case FONT_8:
            UIText_Charset = 0;
            break;
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
    s32 width = 0;
    s32 printedChar;
    s32 charset = UIText_Charset;
    s32 s4 = D_8037EACC_85227C & 1;
    u8* text = ptr;
    s32 v1;

    while (*text) {
        s32 isSpecial = false;
        u32 c = text[0] & 0xFF;

        if (c == '\n') {
            text--;
        } else {
            printedChar = '　';
            if (c == ' ') {
                text--;
            } else if ((s32) c > ' ' && c < 0x7F && c != '\\') {
                text--;
                printedChar = UIText_Ascii2WideChar(c);
            } else {
                printedChar = ((text[0] << 8) & 0xFF00) | (text[1] & 0xFF);
            }
        }
        // BUG: printedChar may be uninitialized
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
            case '\\e':
            case '\\h':
            case '\\n':
            case '\\p':
            case '\\t':
            case '\\w':
            case '◆':
                isSpecial = true;
                break;
            case '　':
                if (s4 != 0) {
                    width += charset ? 4 : 2;
                } else {
                    width += charset ? 9 : 6;
                }
                isSpecial = true;
                break;
            case 0xA1DD:
                printedChar = 'ー';
                break;
            default:
                if (c == '\\') {
                    isSpecial = true;
                }
                break;
        }

        if (!isSpecial) {
            if (s4 != 0) {
                width += UIText_WidthTable[UIText_Charset][UIText_GetCharIndex(printedChar)] + 1;
            } else {
                width += charset ? 9 : 6;
            }
        }

        text += 2;
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
    s32 i;

    for (i = 0; i < ARRAY_COUNT(UIText_CharTable); i++) {
        u8* tmp = D_8037EA68_852218[UIText_Charset];
        if (UIText_CharTable[i] == ch) {
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

s32 UIText_Ascii2WideChar(s32 c) {
    if (c > 0x20 && (u32) c < 0x7F) {
        c = ((((u8*) UIText_AsciiTable)[(c - 0x21) * 2] << 8) & 0xFF00) | (((u8*) UIText_AsciiTable)[(c - 0x21) * 2 + 1] & 0xFF);
    } else {
        c = '　';
    }
    return c;
}

void UIText_PrintString(UIText* text, s32* x, s32* y, char* str) {
    s32 printedChar;
    u8* ptr = str;
    s32 i;
    s32 posX;

    while (*ptr) {
        u32 c = ptr[0] & 0xFF;

        if (c == '\n') {
            ptr--;
            goto NEXT_LINE;
        } else {
            printedChar = '　';
            if (c == ' ') {
                ptr--;
            } else if ((s32) c > ' ' && c < 0x7F && c != '\\') {
                ptr--;
                printedChar = UIText_Ascii2WideChar(c);
            } else {
                printedChar = ((ptr[0] << 8) & 0xFF00) | (ptr[1] & 0xFF);
            }
        }
        // BUG: specialChar may be uninitialized
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
            case '\\n':
                goto NEXT_LINE;
            case '　':
                goto SKIP_PRINTING;
            case '◆':
                goto NEXT_LINE;
            case 0xA1DD:
                printedChar = 'ー';
                break;
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
            s32 tmp = UIText_Charset != 0 ? 9 : 6;
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
            if (printedChar == '　') {
                *x += UIText_Charset != 0 ? 4 : 2;
            } else {
                *x += UIText_WidthTable[UIText_Charset][UIText_GetCharIndex(printedChar)] + 1;
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
        ptr += 2;
    }

    UIText_DelayDisabled = false;
}

void UIText_PrintAsciiString(UIText* text, s32* x, s32* y, u8* str) {
    s32 printedChar;
    u8* ptr = str;

    while (*ptr) {
        s32 c = ptr[0];

        if (c > 0x20 && c < 0x7F) {
            printedChar = ((((u8*) UIText_AsciiTable)[(c - 0x21) * 2] << 8) & 0xFF00) | (((u8*) UIText_AsciiTable)[(c - 0x21) * 2 + 1] & 0xFF);
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
