#include "common.h"
#include "string.h"

enum CharTypes {
    CHAR_TYPE_REGULAR,
    CHAR_TYPE_IMAGE
};

typedef struct UnkMagentaCivet {
    /* 0x00 */ u8* img;
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

extern GObj* Msg_CameraObject;
extern s32 Msg_PosX;
extern s32 Msg_PosY;
extern s32 Msg_PrintDelay;
extern s32 Msg_MessageLength;
extern u8 Msg_TextColorR;
extern u8 Msg_TextColorG;
extern u8 Msg_TextColorB;
extern u8 Msg_TextColorA;
extern s32 Msg_LineSpacing;
extern s32 Msg_IsInteractive;
extern s32 Msg_IsPrinted;
extern s32 Msg_ShadowEnabled;
extern s32 Msg_BlinkEnabled;
extern f32 Msg_BlinkAlpha;
extern s32 Msg_BlinkState;
extern f32 Message_ScaleX;
extern f32 Message_ScaleY;
extern void (*Msg_SpecialHandler)(u8);

extern u8 D_803936B8_533AC8[];
extern u8 D_80393738_533B48[];
extern s16 D_8039379C_533BAC[];
extern u32 Msg_FrameCounter;
// BSS
extern u8 Msg_PrintedText[];
extern u8 Msg_MessageText[];
extern s32 Msg_LineHeight;
extern s32 Msg_BlinkFrameCounter;
extern f32 Msg_CharOffsetX;
extern f32 Msg_CharOffsetY;
extern s32 Msg_CharType;
extern s32 Msg_ImageIndex;

void Msg_UpdatePrinter(GObj* obj) {
    s32 i = 0;
    s32 j;

    Msg_PrintedText[0] = 0;
    if (Msg_PrintDelay > 0) {
        while (true) {
            i += 2;
            memcpy(Msg_PrintedText, Msg_MessageText, i);
            Msg_PrintedText[i] = 0;

            if (i >= Msg_MessageLength) {
                break;
            }

            if (Msg_IsInteractive) {
                j = Msg_PrintDelay;
                while (j > 0) {
                    ohWait(1);
                    j--;
                    if (gContInputPressedButtons & (A_BUTTON | B_BUTTON | START_BUTTON)) {
                        goto END;
                    }
                }
            } else {
                ohWait(Msg_PrintDelay);
            }
        }
    }
END:
    memcpy(Msg_PrintedText, Msg_MessageText, Msg_MessageLength);
    Msg_PrintedText[Msg_MessageLength] = 0;
    ohWait(1);
    Msg_IsPrinted = true;
    omEndProcess(NULL);
}

u8 Msg_GetGlyphWidth(s32 glyphIndex) {
    if (glyphIndex == 64) {
        return 4;
    }
    if (glyphIndex > 64) {
        glyphIndex--;
    }
    return D_80393738_533B48[glyphIndex];
}

u8* Msg_GetCharParams(u8* ptr, s32* nbytes, s32* width) {
    u8* img;
    s32 glyphIndex;
    s32 c0 = ptr[0];
    s32 c1 = ptr[1];
    s32 i;

    Msg_CharType = CHAR_TYPE_REGULAR;
    img = NULL;
    *nbytes = 2;
    *width = 12;

    if (c0 == '\n') {
        *nbytes = 1;
        *width = 0;
        Msg_CharOffsetX = 0.0f;
        Msg_CharOffsetY += Msg_LineHeight * Message_ScaleY;
    } else if (c0 == '\\') {
        // special chars
        switch (c1) {
            case 'z': // Z trigger
                img = D_8038BF18_52C328[Msg_ImageIndex].img;
                Msg_CharType = CHAR_TYPE_IMAGE;
                break;
            case 'r': // R button
                img = D_8038BF38_52C348[Msg_ImageIndex].img;
                Msg_CharType = CHAR_TYPE_IMAGE;
                break;
            case 'F': // 'NEXT' mark
                img = D_8038BF58_52C368[Msg_ImageIndex].img;
                Msg_CharType = CHAR_TYPE_IMAGE;
                break;
            case 'a': // A button
                img = D_8038BF78_52C388[Msg_ImageIndex].img;
                Msg_CharType = CHAR_TYPE_IMAGE;
                break;
            case 'b': // B button
                img = D_8038BF98_52C3A8[Msg_ImageIndex].img;
                Msg_CharType = CHAR_TYPE_IMAGE;
                break;
            case '[': // left part of 'NEW'
                img = D_8038BFB8_52C3C8[Msg_ImageIndex].img;
                Msg_CharType = CHAR_TYPE_IMAGE;
                *width = 11;
                break;
            case ']': // right part of 'NEW'
                img = D_8038BFD8_52C3E8[Msg_ImageIndex].img;
                Msg_CharType = CHAR_TYPE_IMAGE;
                *width = 11;
                break;
            case '#':
                switch (ptr[2]) {
                    case 'S':
                        Msg_ShadowEnabled = ptr[3] - '0';
                        *nbytes = 4;
                        break;
                    case 'X':
                        Message_ScaleX = (ptr[3] - '0') + (ptr[4] - '0') * 0.1f;
                        *nbytes = 5;
                        break;
                    case 'Y':
                        Message_ScaleY = (ptr[3] - '0') + (ptr[4] - '0') * 0.1f;
                        *nbytes = 5;
                        break;
                    case 'F':
                        Msg_BlinkEnabled = ptr[3] - '0';
                        *nbytes = 4;
                        break;
                }
                *width = 0;
                break;
            case 'B':
            case 'Q':
                break;
            default:
                *nbytes = 1;
                *width = 0;
                break;
        }
    } else if (c0 >= ' ' && c0 < 0x80) {
        // ascii character
        *nbytes = 1;
        glyphIndex = D_803936B8_533AC8[c0];
        img = D_80392E10_533220[glyphIndex].img;
        *width = Msg_GetGlyphWidth(glyphIndex);
    } else if (c0 == 0xA3) {
        // wide latin letters
        s32 v02 = c1 - 0x80;
        if (c1 - 0x80 >= 0x20 && c1 - 0x80 < 0x80) {
            glyphIndex = D_803936B8_533AC8[v02];
            img = D_80392E10_533220[glyphIndex].img;
            *width = Msg_GetGlyphWidth(glyphIndex);
        }
    } else {
        // wide non-alphanumeric chars
        s16 code2byte = ((c0 & 0xFF) << 8) + (c1 & 0xFF);
        s16* test = D_8039379C_533BAC;
        i = 0;
        for (i = 0;; i++) {
            if (*test == code2byte) {
                img = D_803931F0_533600[i].img;
                *width = Msg_GetGlyphWidth(i + 62);
                break;
            }

            if (((*test >> 8) & 0xFF) == 0) {
                *nbytes = 1;
                *width = 0;
                break;
            }
            test++;
        }
    }
    return img;
}

void Msg_DrawChar(u8* timg, s32 offsetX, s32 offsetY, s32 width, s32 height) {
    s32 ulx = offsetX + Msg_PosX;
    s32 uly = offsetY + Msg_PosY;
    s32 lrx = ulx + width * Message_ScaleX - 1;
    s32 lry = uly + height * Message_ScaleY - 1;

    if (Msg_CharType == CHAR_TYPE_REGULAR) {
        gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPLoadTextureBlockS(gMainGfxPos[0]++, timg, G_IM_FMT_I, G_IM_SIZ_8b, 14, 14, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    } else {
        gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
        gDPLoadTextureBlockS(gMainGfxPos[0]++, timg, G_IM_FMT_RGBA, G_IM_SIZ_16b, 14, 14, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    }
    if (Msg_ShadowEnabled) {
        gDPSetCombineMode(gMainGfxPos[0]++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, 0, 0, 0, 255);
        gSPTextureRectangle(gMainGfxPos[0]++, (ulx + 1) << 2, (uly + 1) << 2, (lrx + 1) << 2, (lry + 1) << 2, G_TX_RENDERTILE, 0, 0, 1024 / Message_ScaleX, 1024 / Message_ScaleY);
        gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, Msg_TextColorR, Msg_TextColorG, Msg_TextColorB, Msg_TextColorA);
    }
    if (Msg_BlinkEnabled) {
        gDPSetPrimColor(gMainGfxPos[0]++, 0, 0,
                        Msg_TextColorR * Msg_BlinkAlpha,
                        Msg_TextColorG * Msg_BlinkAlpha,
                        Msg_TextColorB * Msg_BlinkAlpha,
                        Msg_TextColorA);
    }
    gSPTextureRectangle(gMainGfxPos[0]++, ulx << 2, uly << 2, lrx << 2, lry << 2, G_TX_RENDERTILE, 0, 0, 1024 / Message_ScaleX, 1024 / Message_ScaleY);
}

void Msg_DrawMessage(GObj* obj) {
    u8* ptr;

    gDPPipeSync(gMainGfxPos[0]++);
    gDPSetCycleType(gMainGfxPos[0]++, G_CYC_1CYCLE);
    gSPTexture(gMainGfxPos[0]++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gMainGfxPos[0]++, G_TP_NONE);
    gDPSetTextureLUT(gMainGfxPos[0]++, G_TT_NONE);
    gDPSetRenderMode(gMainGfxPos[0]++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimDepth(gMainGfxPos[0]++, 0x1234, 0);
    gDPSetPrimColor(gMainGfxPos[0]++, 0, 0, Msg_TextColorR, Msg_TextColorG, Msg_TextColorB, Msg_TextColorA);

    if (Msg_PrintedText[0] != '\0') {
        u8* img;
        s32 nbytes;
        s32 charWidth;

        ptr = Msg_PrintedText;
        Msg_CharOffsetX = 0.0f;
        Msg_CharOffsetY = 0.0f;
        if (Msg_FrameCounter & 8) {
            Msg_ImageIndex = 1;
        } else {
            Msg_ImageIndex = 0;
        }

        switch (Msg_BlinkState) {
            case 0:
                Msg_BlinkAlpha += 0.02f;
                if (Msg_BlinkAlpha >= 1.0f) {
                    Msg_BlinkAlpha = 1.0f;
                    Msg_BlinkFrameCounter = 0;
                    Msg_BlinkState++;
                }
                break;
            case 1:
                Msg_BlinkFrameCounter++;
                if (Msg_BlinkFrameCounter >= 60) {
                    Msg_BlinkState++;
                }
                break;
            case 2:
                Msg_BlinkAlpha -= 0.02f;
                if (Msg_BlinkAlpha <= 0.5f) {
                    Msg_BlinkAlpha = 0.5f;
                    Msg_BlinkState = 0;
                }
                break;
        }

        while (*ptr != '\0') {
            img = Msg_GetCharParams(ptr, &nbytes, &charWidth);
            if (img == NULL) {
                ptr += nbytes;
            } else {
                if (nbytes == 1) {
                    Msg_DrawChar(img, Msg_CharOffsetX, Msg_CharOffsetY, 9, 13);
                } else {
                    Msg_DrawChar(img, Msg_CharOffsetX, Msg_CharOffsetY, 13, 13);
                }
                ptr += nbytes;
                Msg_CharOffsetX += (charWidth + 1) * Message_ScaleX;
            }
        }

        if (Msg_IsInteractive && Msg_IsPrinted) {
            Msg_DrawChar(Msg_GetCharParams("\\F", &nbytes, &charWidth), 187, 32, 13, 13);
        }
    } else {
        Msg_BlinkState = 0;
        Msg_BlinkAlpha = 1.0f;
    }

    gDPPipeSync(gMainGfxPos[0]++);
    Msg_FrameCounter++;
}

GObj* Msg_InitCamera(void) {
    GObj* cam;

    if (ohFindById(OBJID_MSG_CAMERA) != NULL) {
        return NULL;
    }
    Msg_CameraObject = cam = ohCreateCamera(OBJID_MSG_CAMERA, ohUpdateDefault, LINK_0, 0x80000000, Msg_DrawMessage, 3, 0, 0, false, 0, NULL, 0, 0);
    Msg_PrintedText[0] = 0;
    Msg_MessageLength = 0;
    return cam;
}

void Msg_ShowMessage(u8* message, s32 posX, s32 posY, u8 colorR, u8 colorG, u8 colorB, u8 colorA, s32 delayBetweenChars, u8 alignment) {
    u8* ptr;
    s32 nbytes;
    s32 charWidth;
    s32 messageWidth;
    s32 unused;

    messageWidth = 0;
    for (ptr = message; *ptr != 0; ptr += nbytes) {
        Msg_GetCharParams(ptr, &nbytes, &charWidth);
        messageWidth += charWidth + 1;
        if (*ptr == '\\' && (ptr[1] == (0, 'B') || ptr[1] == (0, 'Q')) && Msg_SpecialHandler != NULL) { // TODO find better way to match
            Msg_SpecialHandler(ptr[1]);
        }
    }

    Msg_MessageLength = 0;
    for (ptr = message; *ptr != 0; ptr++) {
        Msg_MessageLength++;
    }
    memcpy(Msg_MessageText, message, Msg_MessageLength);
    Msg_MessageText[Msg_MessageLength] = 0;

    if (alignment == MSG_ALIGN_LEFT) {
        Msg_PosX = posX;
        Msg_PosY = posY;
    } else if (alignment == MSG_ALIGN_RIGHT) {
        Msg_PosX = posX - messageWidth;
        Msg_PosY = posY;
    } else {
        Msg_PosX = posX - messageWidth / 2;
        Msg_PosY = posY;
    }
    Msg_LineHeight = Msg_LineSpacing + 12;
    Msg_TextColorR = colorR;
    Msg_TextColorG = colorG;
    Msg_TextColorB = colorB;
    Msg_TextColorA = colorA;
    Msg_PrintDelay = delayBetweenChars;
    Msg_IsPrinted = 0;
    if (Msg_PrintDelay > 0) {
        omCreateProcess(Msg_CameraObject, Msg_UpdatePrinter, 0, 1);
    } else {
        memcpy(Msg_PrintedText, Msg_MessageText, Msg_MessageLength);
        Msg_PrintedText[Msg_MessageLength] = 0;
    }
}

void Msg_Reset(void) {
    Msg_PrintedText[0] = 0;
    Msg_MessageLength = 0;
}

void Msg_SetSpecialHandler(void (*handler)(u8)) {
    Msg_SpecialHandler = handler;
}

void Msg_SetNonInteractive(void) {
    Msg_IsInteractive = false;
}

void Msg_SetInteractive(void) {
    Msg_IsInteractive = true;
}

s32 Msg_IsMessagePrinted(void) {
    return Msg_IsPrinted;
}
