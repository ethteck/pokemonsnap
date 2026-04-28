#include "common.h"
#include "string.h"

enum CharTypes {
    CHAR_TYPE_REGULAR,
    CHAR_TYPE_IMAGE
};

extern Bitmap font_rgb_bitmaps[];
extern Bitmap font_mono_bitmaps[];
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
extern bool Msg_IsPrinted;
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

u8* Msg_GetCharParams(u8* ptr, s32* nbytes, s32* width);
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/msg/Msg_GetCharParams.s")

void Msg_DrawChar(u8* timg, s32 offsetX, s32 offsetY, s32 width, s32 height);
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/msg/Msg_DrawChar.s")

void Msg_DrawMessage(GObj* obj);
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/msg/Msg_DrawMessage.s")

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

void Msg_ShowMessage(u8* message, s32 posX, s32 posY, u8 colorR, u8 colorG, u8 colorB, u8 colorA, s32 delayBetweenChars, u8 alignment);
#pragma GLOBAL_ASM("asm/nonmatchings/app_level/msg/Msg_ShowMessage.s")


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

bool Msg_IsMessagePrinted(void) {
    return Msg_IsPrinted;
}
