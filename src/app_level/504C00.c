#include "common.h"
#include "string.h"

extern GObj* D_8039366C_533A7C;
extern s32 D_80393670_533A80;
extern s32 D_80393674_533A84;
extern s32 D_80393678_533A88;
extern s32 D_8039367C_533A8C;
extern s32 D_80393690_533AA0;
extern s32 D_80393694_533AA4;
extern s32 D_80393698_533AA8;
extern s32 D_803B4FA0_5553B0;
extern u8 D_80393680_533A90;
extern u8 D_80393684_533A94;
extern u8 D_80393688_533A98;
extern u8 D_8039368C_533A9C;
extern void (*D_803936B4_533AC4)(u8);
extern u8 D_80393738_533B48[];
extern u8 D_803B4DA0_5551B0[];
extern u8 D_803B4EA0_5552B0[];
extern f32 D_803B4FA8_5553B8;
extern f32 D_803B4FAC_5553BC;
extern u32 D_803937E8_533BF8;
extern s32 D_803B4FB4_5553C4;
extern s32 D_803936A8_533AB8;
extern f32 D_803936A4_533AB4;
extern s32 D_803B4FA4_5553B4;
extern f32 D_803936AC_533ABC;
extern f32 D_803936B0_533AC0;
extern s32 D_803B4FB0_5553C0;
extern s32 D_8039369C_533AAC;
extern s32 D_803936A0_533AB0;

void func_803647F0_504C00(GObj* obj) {
    s32 i = 0;
    s32 j;

    D_803B4DA0_5551B0[0] = 0;
    if (D_80393678_533A88 > 0) {
        while (TRUE) {
            i += 2;
            memcpy(D_803B4DA0_5551B0, D_803B4EA0_5552B0, i);
            D_803B4DA0_5551B0[i] = 0;

            if (i >= D_8039367C_533A8C) {
                break;
            }

            if (D_80393694_533AA4 != 0) {
                j = D_80393678_533A88;
                while (j > 0) {
                    ohWait(1);
                    j--;
                    if (gContInputPressedButtons & 0xD000) {
                        goto END;
                    }
                }
            } else {
                ohWait(D_80393678_533A88);
            }
        }
    }
END:
    memcpy(D_803B4DA0_5551B0, D_803B4EA0_5552B0, D_8039367C_533A8C);
    D_803B4DA0_5551B0[D_8039367C_533A8C] = 0;
    ohWait(1);
    D_80393698_533AA8 = 1;
    omEndProcess(0);
}

u8 func_8036496C_504D7C(s32 arg0) {
    if (arg0 == 0x40) {
        return 4;
    }
    if (arg0 > 0x40) {
        arg0--;
    }
    return D_80393738_533B48[arg0];
}

typedef struct UnkMagentaCivet {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} UnkMagentaCivet; // size 0x10

extern UnkMagentaCivet D_8038BF18_52C328[2];
extern UnkMagentaCivet D_8038BF38_52C348[2];
extern UnkMagentaCivet D_8038BF58_52C368[2];
extern UnkMagentaCivet D_8038BF78_52C388[2];
extern UnkMagentaCivet D_8038BF98_52C3A8[2];
extern UnkMagentaCivet D_8038BFB8_52C3C8[2];
extern UnkMagentaCivet D_8038BFD8_52C3E8[2];
extern UnkMagentaCivet D_80392E10_533220[2];
extern UnkMagentaCivet D_803931F0_533600[];

extern u8 D_803936B8_533AC8[];
extern s16 D_8039379C_533BAC[];

s32 func_803649A0_504DB0(u8* ptr, s32* arg1, s32* arg2) {
    s32 ret;
    s32 a0;
    s32 c0 = ptr[0];
    s32 c1 = ptr[1];
    s32 i;

    D_803B4FB0_5553C0 = 0;
    ret = 0;
    *arg1 = 2;
    *arg2 = 12;

    if (c0 == '\n') {
        *arg1 = 1;
        *arg2 = 0;
        D_803B4FA8_5553B8 = 0.0f;
        D_803B4FAC_5553BC += D_803B4FA0_5553B0 * D_803936B0_533AC0;
    } else if (c0 == '\\') {
        switch (c1) {
            case 'z':
                ret = D_8038BF18_52C328[D_803B4FB4_5553C4].unk_00;
                D_803B4FB0_5553C0 = 1;
                break;
            case 'r':
                ret = D_8038BF38_52C348[D_803B4FB4_5553C4].unk_00;
                D_803B4FB0_5553C0 = 1;
                break;
            case 'F':
                ret = D_8038BF58_52C368[D_803B4FB4_5553C4].unk_00;
                D_803B4FB0_5553C0 = 1;
                break;
            case 'a':
                ret = D_8038BF78_52C388[D_803B4FB4_5553C4].unk_00;
                D_803B4FB0_5553C0 = 1;
                break;
            case 'b':
                ret = D_8038BF98_52C3A8[D_803B4FB4_5553C4].unk_00;
                D_803B4FB0_5553C0 = 1;
                break;
            case '[':
                ret = D_8038BFB8_52C3C8[D_803B4FB4_5553C4].unk_00;
                D_803B4FB0_5553C0 = 1;
                *arg2 = 11;
                break;
            case ']':
                ret = D_8038BFD8_52C3E8[D_803B4FB4_5553C4].unk_00;
                D_803B4FB0_5553C0 = 1;
                *arg2 = 11;
                break;
            case '#':
                switch (ptr[2]) {
                    case 'S':
                        D_8039369C_533AAC = ptr[3] - '0';
                        *arg1 = 4;
                        break;
                    case 'X':
                        D_803936AC_533ABC = (ptr[3] - '0') + (ptr[4] - '0') * 0.1f;
                        *arg1 = 5;
                        break;
                    case 'Y':
                        D_803936B0_533AC0 = (ptr[3] - '0') + (ptr[4] - '0') * 0.1f;
                        *arg1 = 5;
                        break;
                    case 'F':
                        D_803936A0_533AB0 = ptr[3] - '0';
                        *arg1 = 4;
                        break;
                }
                *arg2 = 0;
                break;
            case 'B':
            case 'Q':
                break;
            default:
                *arg1 = 1;
                *arg2 = 0;
                break;
        }
    } else if (c0 >= ' ' && c0 < 0x80) {
        *arg1 = 1;
        a0 = D_803936B8_533AC8[c0];
        ret = D_80392E10_533220[a0].unk_00;
        *arg2 = func_8036496C_504D7C(a0);
    } else if (c0 == 0xA3) {
        s32 v02 = c1 - 0x80;
        if (c1 - 0x80 >= 0x20 && c1 - 0x80 < 0x80) {
            a0 = D_803936B8_533AC8[v02];
            ret = D_80392E10_533220[a0].unk_00;
            *arg2 = func_8036496C_504D7C(a0);
        }
    } else {
        s16 q = ((c0 & 0xFF) << 8) + (c1 & 0xFF);
        s16 *test = D_8039379C_533BAC;
        i = 0;
        for (i = 0;;i++) {
            if (*test == q) {
                ret = D_803931F0_533600[i].unk_00;
                *arg2 = func_8036496C_504D7C(i + 0x3E);
                break;
            }

            if (((*test >> 8) & 0xFF) == 0) {
                *arg1 = 1;
                *arg2 = 0;
                break;
            }
            test++;
        }
    }
    return ret;
}

void func_80364DDC_5051EC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_t4 = arg1 + D_80393670_533A80;
    s32 temp_t5 = arg2 + D_80393674_533A84;
    s32 sp4 = temp_t4 + arg3 * D_803936AC_533ABC - 1;
    s32 sp0 = temp_t5 + arg4 * D_803936B0_533AC0 - 1;

    if (D_803B4FB0_5553C0 == 0) {
        gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPLoadTextureBlockS(gMainGfxPos[0]++, arg0, G_IM_FMT_I, G_IM_SIZ_8b, 14, 14, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
        gDPLoadTextureBlockS(gMainGfxPos[0]++, arg0, G_IM_FMT_RGBA, G_IM_SIZ_16b, 14, 14, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    }
    if (D_8039369C_533AAC != 0) {
        gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, 0, 0, 0, 255);
        gSPTextureRectangle(gMainGfxPos[0]++, (temp_t4 + 1) << 2, (temp_t5 + 1) << 2, (sp4 + 1) << 2, (sp0 + 1) << 2, G_TX_RENDERTILE, 0, 0, 1024 / D_803936AC_533ABC, 1024 / D_803936B0_533AC0);
        gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, D_80393680_533A90, D_80393684_533A94, D_80393688_533A98, D_8039368C_533A9C);
    }
    if (D_803936A0_533AB0 != 0) {
        gDPSetPrimColor(gMainGfxPos[0]++, 0, 0,
        D_80393680_533A90 * D_803936A4_533AB4,
        D_80393684_533A94 * D_803936A4_533AB4,
        D_80393688_533A98 * D_803936A4_533AB4,
        D_8039368C_533A9C);
    }
    gSPTextureRectangle(gMainGfxPos[0]++, temp_t4 << 2, temp_t5 << 2, sp4 << 2, sp0 << 2, G_TX_RENDERTILE, 0, 0, 1024 / D_803936AC_533ABC, 1024 / D_803936B0_533AC0);
}

void func_803656E8_505AF8(GObj* obj) {
    u8* ptr;

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gSPTexture(gMainGfxPos[0]++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_NONE);
    gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimDepth(gMainGfxPos[0]++, 0x1234, 0);
    gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, D_80393680_533A90, D_80393684_533A94, D_80393688_533A98, D_8039368C_533A9C);

    if (D_803B4DA0_5551B0[0] != 0) {
        s32 v0;
        s32 sp4C;
        s32 sp48;

        ptr = D_803B4DA0_5551B0;
        D_803B4FA8_5553B8 = 0.0f;
        D_803B4FAC_5553BC = 0.0f;
        if (D_803937E8_533BF8 & 8) {
            D_803B4FB4_5553C4 = 1;
        } else {
            D_803B4FB4_5553C4 = 0;
        }

        switch (D_803936A8_533AB8) {
            case 0:
                D_803936A4_533AB4 += 0.02f;
                if (D_803936A4_533AB4 >= 1.0f) {
                    D_803936A4_533AB4 = 1.0f;
                    D_803B4FA4_5553B4 = 0;
                    D_803936A8_533AB8++;
                }
                break;
            case 1:
                D_803B4FA4_5553B4++;
                if (D_803B4FA4_5553B4 >= 60) {
                    D_803936A8_533AB8++;
                }
                break;
            case 2:
                D_803936A4_533AB4 -= 0.02f;
                if (D_803936A4_533AB4 <= 0.5f) {
                    D_803936A4_533AB4 = 0.5f;
                    D_803936A8_533AB8 = 0;
                }
                break;
        }

        while (*ptr != 0) {
            v0 = func_803649A0_504DB0(ptr, &sp4C, &sp48);
            if (v0 == 0) {
                ptr += sp4C;
            } else {
                if (sp4C == 1) {
                    func_80364DDC_5051EC(v0, D_803B4FA8_5553B8, D_803B4FAC_5553BC, 9, 13);
                } else {
                    func_80364DDC_5051EC(v0, D_803B4FA8_5553B8, D_803B4FAC_5553BC, 13, 13);
                }
                ptr += sp4C;
                D_803B4FA8_5553B8 += (sp48 + 1) * D_803936AC_533ABC;
            }
        }

        if (D_80393694_533AA4 != 0 && D_80393698_533AA8 != 0) {
            func_80364DDC_5051EC(func_803649A0_504DB0("\\F", &sp4C, &sp48), 187, 32, 13, 13);
        }
    } else {
        D_803936A8_533AB8 = 0;
        D_803936A4_533AB4 = 1.0f;
    }

    gDPPipeSync(gMainGfxPos[0]++);
    D_803937E8_533BF8++;
}

GObj* func_80365B24_505F34(void) {
    GObj* temp_v0;

    if (ohFindById(29) != 0) {
        return 0;
    }
    D_8039366C_533A7C = temp_v0 = ohCreateCamera(29, ohUpdateDefault, 0, 0x80000000, func_803656E8_505AF8, 3, 0, 0, 0, 0, 0, 0, 0);
    D_803B4DA0_5551B0[0] = 0;
    D_8039367C_533A8C = 0;
    return temp_v0;
}

void showMessage(u8* arg0, s32 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, s32 arg7, u8 arg8) {
    u8* ptr;
    s32 sp50;
    s32 sp4C;
    s32 s1;
    s32 unused;

    s1 = 0;
    for (ptr = arg0; *ptr != 0; ptr += sp50) {
        func_803649A0_504DB0(ptr, &sp50, &sp4C);
        s1 += sp4C + 1;
        if (*ptr == '\\' && (ptr[1] == (0,'B') || ptr[1] == (0,'Q')) && D_803936B4_533AC4 != NULL) { // TODO find better way to match
            D_803936B4_533AC4(ptr[1]);
        }
    }

    D_8039367C_533A8C = 0;
    for (ptr = arg0; *ptr != 0; ptr++) {
        D_8039367C_533A8C++;
    }
    memcpy(D_803B4EA0_5552B0, arg0, D_8039367C_533A8C);
    D_803B4EA0_5552B0[D_8039367C_533A8C] = 0;

    if (arg8 == 0) {
        D_80393670_533A80 = arg1;
        D_80393674_533A84 = arg2;
    } else if (arg8 == 1) {
        D_80393670_533A80 = arg1 - s1;
        D_80393674_533A84 = arg2;
    } else {
        D_80393670_533A80 = arg1 - s1 / 2;
        D_80393674_533A84 = arg2;
    }
    D_803B4FA0_5553B0 = D_80393690_533AA0 + 12;
    D_80393680_533A90 = arg3;
    D_80393684_533A94 = arg4;
    D_80393688_533A98 = arg5;
    D_8039368C_533A9C = arg6;
    D_80393678_533A88 = arg7;
    D_80393698_533AA8 = 0;
    if (D_80393678_533A88 > 0) {
        omCreateProcess(D_8039366C_533A7C, func_803647F0_504C00, 0, 1);
    } else {
        memcpy(D_803B4DA0_5551B0, D_803B4EA0_5552B0, D_8039367C_533A8C);
        D_803B4DA0_5551B0[D_8039367C_533A8C] = 0;
    }
}

void func_80365E34_506244(void) {
    D_803B4DA0_5551B0[0] = 0;
    D_8039367C_533A8C = 0;
}

void func_80365E48_506258(s32 arg0) {
    D_803936B4_533AC4 = arg0;
}

void func_80365E54_506264(void) {
    D_80393694_533AA4 = 0;
}

void func_80365E60_506270(void) {
    D_80393694_533AA4 = 1;
}

s32 func_80365E70_506280(void) {
    return D_80393698_533AA8;
}
