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

s32 func_8036D344_840AF4(s32 arg0) {
    switch (arg0) {
        case 8:
            D_8037EAA0_852250 = 0;
            break;
        case 12:
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
    D_8037EAC8_852278 = 0;
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

void func_8036D77C_840F2C(UIText* unused, ucolor* arg1, ucolor* arg2) {
    s32 i;
    s32 r, g, b, a;

    D_803A6A04_87A1B4 = *arg1;
    D_803A6A08_87A1B8 = *arg2;

    for (i = 0; i < 16; i++) {
        r = (arg1->r - arg2->r) * i / 15 + arg2->r;
        g = (arg1->g - arg2->g) * i / 15 + arg2->g;
        b = (arg1->b - arg2->b) * i / 15 + arg2->b;
        a = (arg1->a - arg2->a) * i / 15 + arg2->a;
        D_803A6940_87A0F0[i] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | ((a != 0) & 0x1);

        r = (D_8037EAC0_852270.r - arg2->r) * i / 15 + arg2->r;
        g = (D_8037EAC0_852270.g - arg2->g) * i / 15 + arg2->g;
        b = (D_8037EAC0_852270.b - arg2->b) * i / 15 + arg2->b;
        a = (D_8037EAC0_852270.a - arg2->a) * i / 15 + arg2->a;
        D_803A6980_87A130[i] = ((r << 8) & 0xF800) | ((g << 3) & 0x7C0) | ((b >> 2) & 0x3E) | ((a != 0) & 0x1);

        r = (arg1->r - D_8037EAC0_852270.r) * i / 15 + D_8037EAC0_852270.r;
        g = (arg1->g - D_8037EAC0_852270.g) * i / 15 + D_8037EAC0_852270.g;
        b = (arg1->b - D_8037EAC0_852270.b) * i / 15 + D_8037EAC0_852270.b;
        a = (arg1->a - D_8037EAC0_852270.a) * i / 15 + D_8037EAC0_852270.a;
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

#pragma GLOBAL_ASM("asm/nonmatchings/window/840A50/func_8036DE98_841648.s")
void func_8036DE98_841648(UIText*, s32, s32, s32);

void func_8036E0E0_841890(ucolor* arg0, ucolor* arg1, s32 arg2) {
    arg0->r += (arg1->r - arg0->r) * arg2 / 15;
    arg0->g += (arg1->g - arg0->g) * arg2 / 15;
    arg0->b += (arg1->b - arg0->b) * arg2 / 15;
    arg0->a += (arg1->a - arg0->a) * arg2 / 15;
}

#pragma GLOBAL_ASM("asm/nonmatchings/window/840A50/func_8036E22C_8419DC.s")
void func_8036E22C_8419DC(UIText*, s32, s32, s32);

s32 func_8036E44C_841BFC(s32 c) {
    if (c > 0x20 && (u32) c < 0x7F) {
        c = ((D_8037EDCC_85257C[(c - 0x21) * 2] << 8) & 0xFF00) | (D_8037EDCC_85257C[(c - 0x21) * 2 + 1] & 0xFF);
    } else {
        c = '　';
    }
    return c;
}

void func_8036E490_841C40(UIText* arg0, s32* arg1, s32* arg2, char* ptr) {
    s32 printedChar;
    u8* text = ptr;
    s32 i;
    s32 var_a1;

    while (*text) {
        s32 isSpecial = false;
        u32 c = text[0] & 0xFF;

        if (c == '\n') {
            text--;
            // goto block_65
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
                func_8036ECFC_8424AC(*arg1 + arg0->x, *arg2 + arg0->y, printedChar, D_8037EAAC_85225C[D_8037EAA0_852250]);
                goto LABEL2;
            case '\\e':
                func_8036D77C_840F2C(arg0, &D_8037EAD8_852288, &D_803A6A08_87A1B8);
                goto END;
            case '\\h':
                func_8036D77C_840F2C(arg0, &D_8037EADC_85228C, &D_803A6A08_87A1B8);
                goto END;
            case '\\p':
                func_8036D77C_840F2C(arg0, &D_8037EAD4_852284, &D_803A6A08_87A1B8);
                goto END;
            case '\\w':
                D_8037EAC8_852278 = 0;
                D_8037EAE0_852290 = 0;
                goto END;
            case '\\t':
                D_8037EAE0_852290 = 1;
                goto END;
            case '\\g':
                func_8036D4B4_840C64(1, 1);
                goto END;
            case '\\i':
                func_8036D4B4_840C64(1, 0);
                goto END;
            case '\\j':
                func_8036D344_840AF4(0);
                goto END;
            case '\\k':
                func_8036D344_840AF4(1);
                goto END;
            case '　':
                goto LABEL2;
            case '◆':
                goto LABEL2;
            case 0xA1DD:
                printedChar = 'ー';
                break;
            default:
                if (c == '\\') {
                    if (D_8037EAC4_852274 != 0 && D_803A6A0C_87A1BC != NULL && D_8037EAC8_852278 == 0) {
                        D_803A6A0C_87A1BC(printedChar);
                    }
                    goto END;
                }
                break;
        }

        if (D_8037EACC_85227C & 1) {
            var_a1 = *arg1;
        } else {
            s32 tmp = D_8037EAA0_852250 != 0 ? 9 : 6;
            var_a1 = *arg1 + (s32) ((tmp - D_8037EE8C_85263C[D_8037EAA0_852250][func_8036D2A0_840A50(printedChar)]) * 0.5 + 0.5);
        }
        if (arg0->bpp == 4) {
            func_8036E22C_8419DC(arg0, var_a1, *arg2, printedChar);
        } else {
            func_8036DE98_841648(arg0, var_a1, *arg2, printedChar);
        }
        if (D_803A6A0C_87A1BC != NULL && D_8037EAC8_852278 == 0) {
            D_803A6A0C_87A1BC(printedChar);
        }
LABEL2:
        i = D_8037EAC4_852274;
        while (i >= 0) {
            
            if (D_8037EAC8_852278 != 0) {
                break;
            }
            i--;
            ohWait(1);
        }

        if (D_8037EACC_85227C & 1) {
            if (printedChar == '　') {
                *arg1 += D_8037EAA0_852250 != 0 ? 4 : 2;
            } else {
                *arg1 = *arg1 + D_8037EE8C_85263C[D_8037EAA0_852250][func_8036D2A0_840A50(printedChar)] + 1;
            }
        } else {
            *arg1 += D_8037EAA0_852250 != 0 ? 9 : 6;
        }

        if (*arg1 > arg0->imageWidth - D_8037EAB8_852268) {
            *arg1 = 0;
        }

LABEL1:
        *arg2 += D_8037EABC_85226C;
        if (*arg2 > arg0->height - D_8037EAAC_85225C[D_8037EAA0_852250] - D_8037EAB4_852264) {
            *arg2 = 0;
        }

    END:
        text += 2;
    }

    D_8037EAC8_852278 = 0;
}

void func_8036E9BC_84216C(UIText* arg0, s32* arg1, s32* arg2, u8* arg3) {
    s32 temp_a3;
    u8* ptr = arg3;

    while (*ptr) {
        s32 c = ptr[0];

        if (c > 0x20 && c < 0x7F) {
            temp_a3 = ((D_8037EDCC_85257C[(c - 0x21) * 2] << 8) & 0xFF00) | (D_8037EDCC_85257C[(c - 0x21) * 2 + 1] & 0xFF);
            if (arg0->bpp == 4) {
                func_8036E22C_8419DC(arg0, *arg1, *arg2, temp_a3);
            } else {
                func_8036DE98_841648(arg0, *arg1, *arg2, temp_a3);
            }
        }
        *arg1 += D_8037EAB8_852268;
        if (*arg1 > arg0->imageWidth - D_8037EAB8_852268) {
            *arg1 = 0;
            *arg2 += D_8037EABC_85226C;
            if (*arg2 > arg0->height - D_8037EAAC_85225C[D_8037EAA0_852250] - D_8037EAB4_852264) {
                *arg2 = 0;
            }
        }
        ptr++;
    }
}

void func_8036EB34_8422E4(GObj* arg0) {
    if (D_8037EAE0_852290 != 0 && (func_800AA38C(0)->unk_18 & (0x8000 | 0x4000))) {
        D_8037EAC8_852278 = 1;
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
    D_8037EAC8_852278 = 0;
}
