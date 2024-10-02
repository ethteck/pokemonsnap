#include "common.h"
#include "window.h"

extern s32 D_8037EA68_852218[];
extern s32 D_8037EAA0_852250;
extern s32 D_8037EAA4_852254;
extern s32 D_8037EAA8_852258;
extern s32 D_8037EAAC_85225C[2];
extern s32 D_8037EAB4_852264;
extern s32 D_8037EAB8_852268;
extern s32 D_8037EABC_85226C;
extern ucolor D_8037EAC0_852270;
extern s32 D_8037EAC4_852274;
extern s32 D_8037EAC8_852278;
extern s32 D_8037EACC_85227C;
extern ucolor D_8037EAD4_852284;
extern ucolor D_8037EAD8_852288;
extern ucolor D_8037EADC_85228C;
extern s32 D_8037EAE0_852290;
extern u16 D_8037EAE4_852294[370];
extern u8 D_8037EDCC_85257C[];
extern u8 D_8037EE8C_85263C[2][370];

extern u32 D_803A6940_87A0F0[16];
extern u32 D_803A6980_87A130[16];
extern u32 D_803A69C0_87A170[16];
extern ucolor D_803A6A04_87A1B4;
extern ucolor D_803A6A08_87A1B8;
extern void (*D_803A6A0C_87A1BC)(s32);

s32 func_8036E44C_841BFC(s32 arg0);
void* func_8036ECFC_8424AC(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 func_8036D2A0_840A50(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8037EAE4_852294); i++) {
        if (arg0 == D_8037EAE4_852294[i]) {
            return i;
        }
    }
    return 0;
}

s32 func_8036D344_840AF4(s32 font) {
    switch (font) {
        case FONT_8:
            D_8037EAA0_852250 = 0;
            break;
        case FONT_12:
            D_8037EAA0_852250 = 1;
            break;
        default:
            D_8037EAA0_852250 = 0;
            break;
    }

    D_8037EAB8_852268 = D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAA4_852254 + D_8037EAB4_852264;
    D_8037EABC_85226C = D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAA8_852258 + D_8037EAB4_852264;
    return 0;
}

s32 func_8036D3D8_840B88(s32 arg0, s32 arg1) {
    return 0;
}

void func_8036D3E8_840B98(s32 arg0, s32 arg1) {
    D_8037EAA4_852254 = arg0;
    D_8037EAA8_852258 = arg1;
    D_8037EAB8_852268 = D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAA4_852254 + D_8037EAB4_852264;
    D_8037EABC_85226C = D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAA8_852258 + D_8037EAB4_852264;
}

void func_8036D448_840BF8(s32 arg0) {
    D_8037EAB4_852264 = arg0;
    D_8037EAB8_852268 = D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAA4_852254 + D_8037EAB4_852264;
    D_8037EABC_85226C = D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAA8_852258 + D_8037EAB4_852264;
}

void func_8036D4A0_840C50(s32 arg0) {
    D_8037EAC4_852274 = arg0;
    D_8037EAC8_852278 = false;
}

void func_8036D4B4_840C64(s32 flags, s32 set) {
    if (set) {
        D_8037EACC_85227C |= flags;
    } else {
        D_8037EACC_85227C &= ~flags;
    }
}

s32 func_8036D4F0_840CA0(char* ptr) {
    s32 width = 0;
    s32 printedChar;
    s32 s5 = D_8037EAA0_852250;
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
                printedChar = func_8036E44C_841BFC(c);
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
                    width += s5 ? 4 : 2;
                } else {
                    width += s5 ? 9 : 6;
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
                width += D_8037EE8C_85263C[D_8037EAA0_852250][func_8036D2A0_840A50(printedChar)] + 1;
            } else {
                width += s5 ? 9 : 6;
            }
        }

        text += 2;
    }

    return width;
}

s32 func_8036D758_840F08(void) {
    return D_8037EAAC_85225C[D_8037EAA0_852250];
}

s32 func_8036D774_840F24(void) {
    return 0;
}

void UIText_MakePalettes(UIText* unused, ucolor* fgColor, ucolor* bgColor) {
    s32 i;
    s32 r, g, b, a;

    D_803A6A04_87A1B4 = *fgColor;
    D_803A6A08_87A1B8 = *bgColor;

    for (i = 0; i < 16; i++) {
        r = (fgColor->r - bgColor->r) * i / 15 + bgColor->r;
        g = (fgColor->g - bgColor->g) * i / 15 + bgColor->g;
        b = (fgColor->b - bgColor->b) * i / 15 + bgColor->b;
        a = (fgColor->a - bgColor->a) * i / 15 + bgColor->a;
        D_803A6940_87A0F0[i] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | ((a != 0) & 0x1);

        r = (D_8037EAC0_852270.r - bgColor->r) * i / 15 + bgColor->r;
        g = (D_8037EAC0_852270.g - bgColor->g) * i / 15 + bgColor->g;
        b = (D_8037EAC0_852270.b - bgColor->b) * i / 15 + bgColor->b;
        a = (D_8037EAC0_852270.a - bgColor->a) * i / 15 + bgColor->a;
        D_803A6980_87A130[i] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | ((a != 0) & 0x1);

        r = (fgColor->r - D_8037EAC0_852270.r) * i / 15 + D_8037EAC0_852270.r;
        g = (fgColor->g - D_8037EAC0_852270.g) * i / 15 + D_8037EAC0_852270.g;
        b = (fgColor->b - D_8037EAC0_852270.b) * i / 15 + D_8037EAC0_852270.b;
        a = (fgColor->a - D_8037EAC0_852270.a) * i / 15 + D_8037EAC0_852270.a;
        D_803A69C0_87A170[i] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | ((a != 0) & 0x1);
    }
}

void func_8036DC4C_8413FC(s32 r, s32 g, s32 b, s32 a) {
    D_8037EAC0_852270.r = r;
    D_8037EAC0_852270.g = g;
    D_8037EAC0_852270.b = b;
    D_8037EAC0_852270.a = a;
}

s32 func_8036DC68_841418(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8037EAE4_852294); i++) {
        s32 tmp = D_8037EA68_852218[D_8037EAA0_852250];
        if (D_8037EAE4_852294[i] == arg0) {
            return i * D_8037EAAC_85225C[D_8037EAA0_852250] * D_8037EAAC_85225C[D_8037EAA0_852250] / 2 + tmp;
        }
    }

    return 0;
}

s32 UIText_PrintChar16(UIText* arg0, s32 arg1, s32 arg2, s32 arg3) {
    u16* sp34;
    u16* v1;
    u8* var_t4;
    s32 i, j, k;
    s32 v0;

    sp34 = (u16*) arg0->image + arg2 * arg0->width + arg1;
    var_t4 = func_8036DC68_841418(arg3);
    // clang-format off
    if (var_t4 == NULL) { return D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAB4_852264; }
    // clang-format on

    for (i = 0; i < D_8037EAAC_85225C[D_8037EAA0_852250]; i++) {
        if (arg2 + i < arg0->height) {
            for (j = 0; j < D_8037EAAC_85225C[D_8037EAA0_852250]; sp34++, j++) {
                if (arg1 + j >= arg0->width) {
                    continue;
                }
                if (j & 1) {
                    v0 = (*var_t4 & 0xF0) >> 4;
                    var_t4++;
                } else {
                    v0 = *var_t4 & 0xF;
                }

                if (v0 == 0) {
                    continue;
                }

                if (sp34[arg0->width + 1] == D_803A6980_87A130[15] || sp34[0] == D_803A6980_87A130[15]) {
                    *sp34 = D_803A69C0_87A170[v0];
                } else {
                    *sp34 = D_803A6940_87A0F0[v0];
                }

                for (v1 = sp34, k = D_8037EAB4_852264; k > 0; k--) {
                    if (arg2 + i + k < arg0->height && arg1 + j + k < arg0->width) {
                        v1 += arg0->width + 1;
                        *v1 = k == 1 ? D_803A6980_87A130[v0] : D_803A6980_87A130[15];
                    }
                }
            }
            sp34 += arg0->width - D_8037EAAC_85225C[D_8037EAA0_852250];
        }
    }

    return D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAB4_852264;
}

void func_8036E0E0_841890(ucolor* arg0, ucolor* arg1, s32 arg2) {
    arg0->r += (arg1->r - arg0->r) * arg2 / 15;
    arg0->g += (arg1->g - arg0->g) * arg2 / 15;
    arg0->b += (arg1->b - arg0->b) * arg2 / 15;
    arg0->a += (arg1->a - arg0->a) * arg2 / 15;
}

s32 UIText_PrintChar32(UIText* arg0, s32 x, s32 y, s32 ch) {
    u32* sp34;
    u32* v1;
    u8* var_t4;
    s32 v0;
    s32 i, j, k;    

    sp34 = (u32*) arg0->image + y * arg0->width + x;
    var_t4 = func_8036DC68_841418(ch);
    if (var_t4 == NULL) {
        return D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAB4_852264;
    }

    for (i = 0; i < D_8037EAAC_85225C[D_8037EAA0_852250]; i++) {
        if (y + i < arg0->height) {
            for (j = 0; j < D_8037EAAC_85225C[D_8037EAA0_852250]; sp34++, j++) {
                if (x + j >= arg0->width) {
                    if (0) { } // TODO required to match
                    continue;
                }
                if (j & 1) {
                    v0 = (*var_t4++ & 0xF0) >> 4;
                } else {
                    v0 = *var_t4 & 0xF;
                }

                if (v0 == 0) {
                    continue;
                }

                func_8036E0E0_841890(sp34, &D_803A6A04_87A1B4, v0);

                for (v1 = sp34, k = D_8037EAB4_852264; k > 0; k--) {
                    v1 += arg0->width + 1;
                    if (k == 1) {
                        func_8036E0E0_841890(v1, &D_8037EAC0_852270, v0);
                    } else {
                        func_8036E0E0_841890(v1, &D_8037EAC0_852270, 15);
                    }
                }
            }
            sp34 += arg0->width - D_8037EAAC_85225C[D_8037EAA0_852250];
        }
    }

    return D_8037EAAC_85225C[D_8037EAA0_852250] + D_8037EAB4_852264;
}

s32 func_8036E44C_841BFC(s32 c) {
    if (c > 0x20 && (u32) c < 0x7F) {
        c = ((D_8037EDCC_85257C[(c - 0x21) * 2] << 8) & 0xFF00) | (D_8037EDCC_85257C[(c - 0x21) * 2 + 1] & 0xFF);
    } else {
        c = '　';
    }
    return c;
}

void UIText_PrintString(UIText* text, s32* x, s32* y, char* str) {
    s32 printedChar;
    u8* ptr = str;
    s32 i;
    s32 var_a1;

    while (*ptr) {
        u32 c = ptr[0] & 0xFF;

        if (c == '\n') {
            ptr--;
            goto LABEL3;
        } else {
            printedChar = '　';
            if (c == ' ') {
                ptr--;
            } else if ((s32) c > ' ' && c < 0x7F && c != '\\') {
                ptr--;
                printedChar = func_8036E44C_841BFC(c);
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
                func_8036ECFC_8424AC(*x + text->screenX, *y + text->screenY, printedChar, D_8037EAAC_85225C[D_8037EAA0_852250]);
                goto LABEL2;
            case '\\e':
                UIText_MakePalettes(text, &D_8037EAD8_852288, &D_803A6A08_87A1B8);
                goto END;
            case '\\h':
                UIText_MakePalettes(text, &D_8037EADC_85228C, &D_803A6A08_87A1B8);
                goto END;
            case '\\p':
                UIText_MakePalettes(text, &D_8037EAD4_852284, &D_803A6A08_87A1B8);
                goto END;
            case '\\w':
                D_8037EAC8_852278 = false;
                D_8037EAE0_852290 = false;
                goto END;
            case '\\t':
                D_8037EAE0_852290 = true;
                goto END;
            case '\\g':
                func_8036D4B4_840C64(1, 1);
                goto END;
            case '\\i':
                func_8036D4B4_840C64(1, 0);
                goto END;
            case '\\j':
                func_8036D344_840AF4(0); // BUG: 0 is not valid font
                goto END;
            case '\\k':
                func_8036D344_840AF4(1); // BUG: 1 is not valid font
                goto END;
            case '\\n':
                goto LABEL3;
            case '　':
                goto LABEL2;
            case '◆':
                goto LABEL3;
            case 0xA1DD:
                printedChar = 'ー';
                break;
            default:
                if (c == '\\') {
                    if (D_8037EAC4_852274 != 0 && D_803A6A0C_87A1BC != NULL && !D_8037EAC8_852278) {
                        D_803A6A0C_87A1BC(printedChar);
                    }
                    goto END;
                }
                break;
        }

        if (D_8037EACC_85227C & 1) {
            var_a1 = *x;
        } else {
            s32 tmp = D_8037EAA0_852250 != 0 ? 9 : 6;
            var_a1 = *x + (s32) ((tmp - D_8037EE8C_85263C[D_8037EAA0_852250][func_8036D2A0_840A50(printedChar)]) * .5 + 0.5);
        }
        if (text->bpp == 4) {
            UIText_PrintChar32(text, var_a1, *y, printedChar);
        } else {
            UIText_PrintChar16(text, var_a1, *y, printedChar);
        }
        if (D_803A6A0C_87A1BC != NULL && !D_8037EAC8_852278) {
            D_803A6A0C_87A1BC(printedChar);
        }
    LABEL2:
        i = D_8037EAC4_852274;
        while (i > 0 && !D_8037EAC8_852278) {
            i--;
            ohWait(1);
        }

        if (D_8037EACC_85227C & 1) {
            if (printedChar == '　') {
                *x += D_8037EAA0_852250 != 0 ? 4 : 2;
            } else {
                *x += D_8037EE8C_85263C[D_8037EAA0_852250][func_8036D2A0_840A50(printedChar)] + 1;
            }
        } else {
            *x += D_8037EAA0_852250 != 0 ? 9 : 6;
        }

        if (*x > text->width - D_8037EAB8_852268) {
        LABEL3:
            *x = 0;
        } else {
            goto END;
        }

    LABEL1:
        *y += D_8037EABC_85226C;
        if (*y > text->height - D_8037EAAC_85225C[D_8037EAA0_852250] - D_8037EAB4_852264) {
            *y = 0;
        }

    END:
        ptr += 2;
    }

    D_8037EAC8_852278 = false;
}

void UIText_PrintAsciiString(UIText* text, s32* x, s32* y, u8* str) {
    s32 temp_a3;
    u8* ptr = str;

    while (*ptr) {
        s32 c = ptr[0];

        if (c > 0x20 && c < 0x7F) {
            temp_a3 = ((D_8037EDCC_85257C[(c - 0x21) * 2] << 8) & 0xFF00) | (D_8037EDCC_85257C[(c - 0x21) * 2 + 1] & 0xFF);
            if (text->bpp == 4) {
                UIText_PrintChar32(text, *x, *y, temp_a3);
            } else {
                UIText_PrintChar16(text, *x, *y, temp_a3);
            }
        }
        *x += D_8037EAB8_852268;
        if (*x > text->width - D_8037EAB8_852268) {
            *x = 0;
            *y += D_8037EABC_85226C;
            if (*y > text->height - D_8037EAAC_85225C[D_8037EAA0_852250] - D_8037EAB4_852264) {
                *y = 0;
            }
        }
        ptr++;
    }
}

void func_8036EB34_8422E4(GObj* arg0) {
    if (D_8037EAE0_852290 && (func_800AA38C(0)->unk_18 & (0x8000 | 0x4000))) {
        D_8037EAC8_852278 = true;
    }
}

void func_8036EB80_842330(s32 arg0) {
    D_8037EAE0_852290 = arg0;
}

void func_8036EB8C_84233C(void (*arg0)(s32)) {
    D_803A6A0C_87A1BC = arg0;
}

void func_8036EB98_842348(void) {
    func_800A86A4(func_8036EB34_8422E4, LINK_6, DL_LINK_0, NULL);
    D_8037EAC4_852274 = 0;
    D_803A6A0C_87A1BC = NULL;
    D_8037EAC8_852278 = false;
}
