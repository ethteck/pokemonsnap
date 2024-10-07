#include "common.h"

#include "photo_check/photo_check.h"
#include "window/window.h"
#include "pokemon_report.h"

typedef struct UnkTriple {
    /* 0x00 */ GObj* unk_00;
    /* 0x04 */ SObj* unk_04;
    /* 0x08 */ void* unk_08;
} UnkTriple;

extern Sprite D_801E3F48_9DA8B8;
extern Sprite D_801EDD60_9E46D0;
extern Sprite D_801EDEF0_9E4860;
extern Sprite D_801E8F70_9DF8E0;
extern Sprite D_801EE150_9E4AC0;
extern Sprite D_801EF7D0_9E6140;
extern Sprite D_801F0E50_9E77C0;
extern Sprite D_801F2278_9E8BE8;
extern Sprite D_801F36A0_9EA010;
extern Sprite D_801F3860_9EA1D0;
extern Sprite D_801F3A10_9EA380;
extern Sprite D_801F3B90_9EA500;
extern Sprite D_801F4D48_9EB6B8;
extern Sprite D_801F5120_9EBA90;
extern Sprite D_801F54C8_9EBE38;
extern Sprite D_801F5680_9EBFF0;
extern Sprite D_801F57B0_9EC120;
extern Sprite D_80202CE8_9F9658;
extern s32 (*D_80202D2C_9F969C)(const void*, const void*);
extern s32 D_80202D30_9F96A0;
extern s16 D_80202D4C_9F96BC[];
extern Sprite* D_80202DD0_9F9740[];
extern u8* D_80202DE8_9F9758[];
extern char** D_80202E8C_9F97FC[6];
extern char** D_80202EA4_9F9814[6];

extern GObj* D_80230C10_A27580;
extern SObj* D_80230C14_A27584;
extern UIElement* D_80230C1C_A2758C;
extern Unk803A6C18* D_80230C20_A27590;
extern s32 D_80230C24_A27594;
extern UIFrame* D_80230C28_A27598;
extern UIElement* D_80230C30_A275A0;
extern UIElement* D_80230C34_A275A4;
extern UIElement* D_80230C38_A275A8;
extern SObj* D_80230C3C_A275AC;
extern GObj* D_80230C40_A275B0;
extern SObj* D_80230C48_A275B8[6];
extern GObj* D_80230C60_A275D0;
extern SObj* D_80230C68_A275D8[2];
extern GObj* D_80230C70_A275E0;
extern s32 D_80230C74_A275E4;
extern Unk803A6C18* D_80230C78_A275E8;
extern UIElement* D_80230C80_A275F0[10];
extern s32 D_80230CA8_A27618;
extern s32 D_80230CAC_A2761C;
extern s32 D_80230CB0_A27620[];
extern s32 D_80230DB0_A27720;
extern s32 D_80230DB4_A27724;
extern s32 D_80230DB8_A27728;
extern s32 D_80230DBC_A2772C;
extern s32 D_80202D34_9F96A4[6];
extern s32 D_80230DAC_A2771C;
extern s32 D_80230DC0_A27730;
extern UnkTriple D_80230DC8_A27738[6];

void func_801DFBD0_9D6540(s32);

s32 func_801DCCF0_9D3660(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_80202D34_9F96A4)) {
        return -1;
    }
    return D_80202D34_9F96A4[arg0];
}

void func_801DCD30_9D36A0(UIElement* arg0, s32 arg1) {
    UNUSED s32 pad;

    UIElement_SetSpriteColor(arg0, arg1, arg1, arg1, 255);
}

void func_801DCD78_9D36E8(s32 arg0) {
    s32 i;

    if (D_80230C3C_A275AC != 0) {
        D_80230C3C_A275AC->sprite.red = arg0;
        D_80230C3C_A275AC->sprite.green = arg0;
        D_80230C3C_A275AC->sprite.blue = arg0;
    }

    for (i = 0; i < ARRAY_COUNT(D_80230C48_A275B8); i++) {
        if (D_80230C48_A275B8[i] != NULL) {
            D_80230C48_A275B8[i]->sprite.red = arg0;
            D_80230C48_A275B8[i]->sprite.green = arg0;
            D_80230C48_A275B8[i]->sprite.blue = arg0;
        }
    }
}

void func_801DCE3C_9D37AC(void) {
    s32 i;

    ohRemoveSprite(D_80230C40_A275B0);
    D_80230C3C_A275AC = NULL;
    ohRemoveSprite(D_80230C60_A275D0);

    for (i = 0; i < ARRAY_COUNT(D_80230C48_A275B8) - 1; i++) {
        D_80230C48_A275B8[i] = 0;
    }
}

void func_801DCEA8_9D3818(s32 arg0) {
    s32 i;

    for (i = ARRAY_COUNT(D_80230C48_A275B8) - 1; i >= 0; i--) {
        if (D_80230C48_A275B8[i] != 0) {
            if (arg0 != 0) {
                D_80230C48_A275B8[i]->sprite.attr &= ~SP_HIDDEN;
            } else {
                D_80230C48_A275B8[i]->sprite.attr |= SP_HIDDEN;
            }
        }
    }
}

UIElement* func_801DCF40_9D38B0(void) {
    return D_80230C30_A275A0;
}

s32 func_801DCF5C_9D38CC(s32* arg0) {
    s32 i;
    s32 sp28;
    s32 sp24;

    sp28 = 0;
    sp24 = 0;

    for (i = PokemonID_BULBASAUR; i <= POKEDEX_MAX; i++) {
        if (func_800BF3D4_5C274(i)) {
            sp28 += func_800BF818_5C6B8(i);
        }
    }

    if (func_800BF3D4_5C274(PokemonID_1004)) {
        sp28 += func_800BF818_5C6B8(PokemonID_1004);
        sp24++;
    }
    if (func_800BF3D4_5C274(PokemonID_1010)) {
        sp28 += func_800BF818_5C6B8(PokemonID_1010);
        sp24++;
    }
    if (func_800BF3D4_5C274(PokemonID_KOFFING_SMOKE)) {
        sp28 += func_800BF818_5C6B8(PokemonID_KOFFING_SMOKE);
        sp24++;
    }
    if (func_800BF3D4_5C274(PokemonID_1022)) {
        sp28 += func_800BF818_5C6B8(PokemonID_1022);
        sp24++;
    }
    if (func_800BF3D4_5C274(PokemonID_1018)) {
        sp28 += func_800BF818_5C6B8(PokemonID_1018);
        sp24++;
    }
    if (func_800BF3D4_5C274(PokemonID_1035)) {
        sp28 += func_800BF818_5C6B8(PokemonID_1035);
        sp24++;
    }
    if (arg0 != NULL) {
        *arg0 = sp24;
    }
    return sp28;
}

void func_801DD12C_9D3A9C(void) {
    if (D_80230DC0_A27730 != 0) {
        D_80230DC0_A27730 = 0;
    } else {
        D_80230DC0_A27730 = 1;
    }
}

void func_801DD164_9D3AD4(s32 arg0, s32 arg1) {
    f32 sp4C;
    char sp2C[0x20];

    UIElement_SetState(D_80230C38_A275A8, UI_NORMAL);
    UIElement_SetState(D_80230C30_A275A0, UI_NORMAL);

    if (arg0 == 0) {
        UIElement_Draw(D_80230C38_A275A8);
        UIElement_Draw(D_80230C30_A275A0);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_SetFont(D_80230C38_A275A8, FONT_12);
        sprintf(sp2C, "%s", getPokemonName(arg1));
        UIElement_SetTextPos(D_80230C38_A275A8, (84 - UIText_GetStringWidth(sp2C)) / 2, 0);
        UIElement_PrintText(D_80230C38_A275A8, sp2C);
        UIElement_SetFont(D_80230C30_A275A0, FONT_12);
        UIElement_SetTextPos(D_80230C30_A275A0, 22, 0);
        func_8037519C_84894C(D_80230C30_A275A0, "Course");
        UIElement_SetTextPos(D_80230C30_A275A0, 22, 16);
        func_8037519C_84894C(D_80230C30_A275A0, "Photo by");
        UIElement_SetTextPos(D_80230C30_A275A0, 22, 32);
        func_8037519C_84894C(D_80230C30_A275A0, "Score");
        sprintf(sp2C, "%s", getLevelName(func_800BF710_5C5B0(arg1)->levelID));
        UIElement_SetTextPos(D_80230C30_A275A0, 162 - UIText_GetStringWidth(sp2C), 0);
        func_8037519C_84894C(D_80230C30_A275A0, sp2C);
        sprintf(sp2C, "%s", get_player_name());
        UIElement_SetTextPos(D_80230C30_A275A0, 162 - UIText_GetStringWidth(sp2C), 16);
        func_8037519C_84894C(D_80230C30_A275A0, sp2C);
        sprintf(sp2C, "\\i%5d\\g", func_800BF818_5C6B8(arg1));
        UIElement_SetTextPos(D_80230C30_A275A0, 162 - UIText_GetStringWidth(sp2C), 32);
        func_8037519C_84894C(D_80230C30_A275A0, sp2C);
    } else {
        if (D_80202D30_9F96A0 != arg1) {
            D_80230C78_A275E8 = func_8037452C_847CDC(func_800BF710_5C5B0(arg1));
            D_80202D30_9F96A0 = arg1;
        }
        D_80230C20_A27590 = D_80230C78_A275E8;
        UIElement_Draw(D_80230C38_A275A8);
        UIElement_Draw(D_80230C30_A275A0);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_SetFont(D_80230C38_A275A8, FONT_12);
        sprintf(sp2C, "%s", getPokemonName(arg1));
        UIElement_SetTextPos(D_80230C38_A275A8, (84 - UIText_GetStringWidth(sp2C)) / 2, 0);
        UIElement_PrintText(D_80230C38_A275A8, sp2C);
        UIElement_SetFont(D_80230C30_A275A0, FONT_8);
        if (D_80230DC0_A27730 == 0) {
            UIElement_SetTextPos(D_80230C30_A275A0, 0, 0);
            UIElement_PrintText(D_80230C30_A275A0, "Special");
            sprintf(sp2C, "%s", func_8037501C_8487CC("%5d", D_80230C20_A27590->score.specialBonus));
            UIElement_SetTextPos(D_80230C30_A275A0, 40 - UIText_GetStringWidth(sp2C), 12);
            UIElement_PrintText(D_80230C30_A275A0, sp2C);
            UIElement_SetTextPos(D_80230C30_A275A0, 135, 0);
            UIElement_PrintText(D_80230C30_A275A0, "Technique");
            if (D_80230C20_A27590->score.isWellFramed != 0) {
                sprintf(sp2C, "That's nice.");
            } else {
                sprintf(sp2C, "Oh, dear...");
            }
            UIElement_SetTextPos(D_80230C30_A275A0, 188 - UIText_GetStringWidth(sp2C), 12);
            UIElement_PrintText(D_80230C30_A275A0, sp2C);
            UIElement_SetTextPos(D_80230C30_A275A0, 45, 0);
            UIElement_PrintText(D_80230C30_A275A0, "Size");
            sp4C = (D_80230C20_A27590->score.sizeParam1 / 10000.0f);
            sprintf(sp2C, "%s", func_8037501C_8487CC("%5d", (s32) (((D_80230C20_A27590->score.sizeParam2 * sp4C) + 5.0f) / 10.0f) * 10));
            UIElement_SetTextPos(D_80230C30_A275A0, 85 - UIText_GetStringWidth(sp2C), 12);
            UIElement_PrintText(D_80230C30_A275A0, sp2C);
            UIElement_SetTextPos(D_80230C30_A275A0, 90, 0);
            UIElement_PrintText(D_80230C30_A275A0, "Pose");
            sprintf(sp2C, "%s", func_8037501C_8487CC("%5d", D_80230C20_A27590->score.posePts));
            UIElement_SetTextPos(D_80230C30_A275A0, 130 - UIText_GetStringWidth(sp2C), 12);
            UIElement_PrintText(D_80230C30_A275A0, sp2C);
            if (D_80230C20_A27590->score.samePkmnNumber != 0) {
                UIElement_SetTextPos(D_80230C30_A275A0, 135, 24);
                UIElement_PrintText(D_80230C30_A275A0, "Same PKMN");
                sprintf(sp2C, "%s", func_8037501C_8487CC("%5d", D_80230C20_A27590->score.samePkmnBonus));
                UIElement_SetTextPos(D_80230C30_A275A0, 188 - UIText_GetStringWidth(sp2C), 36);
                UIElement_PrintText(D_80230C30_A275A0, sp2C);
            }
        } else {
            UIElement_SetTextPos(D_80230C30_A275A0, 0, 0);
            UIElement_PrintText(D_80230C30_A275A0, "スペシャル"); // special
            UIElement_SetTextPos(D_80230C30_A275A0, 0, 12);
            UIElement_PrintText(D_80230C30_A275A0, func_8037501C_8487CC("%5d", D_80230C20_A27590->score.specialID));
            UIElement_SetTextPos(D_80230C30_A275A0, 0, 24);
            UIElement_SetTextPos(D_80230C30_A275A0, 0, 36);
            UIElement_SetTextPos(D_80230C30_A275A0, 45, 0);
            UIElement_PrintText(D_80230C30_A275A0, "めんせき");
            UIElement_SetTextPos(D_80230C30_A275A0, 45, 12);
            UIElement_PrintText(D_80230C30_A275A0, func_8037501C_8487CC("%5d", D_80230C20_A27590->score.sizeParam2));
            UIElement_SetTextPos(D_80230C30_A275A0, 45, 24);
            UIElement_PrintText(D_80230C30_A275A0, "まるみえ"); // full view
            UIElement_SetTextPos(D_80230C30_A275A0, 45, 36);
            if (D_80230C20_A27590->score.sizeParam1 < 10000) {
                func_8037519C_84894C(D_80230C30_A275A0, "%s。", func_8037501C_8487CC("%2d", D_80230C20_A27590->score.sizeParam1 / 100));
                func_8037519C_84894C(D_80230C30_A275A0, "%s％", func_8037501C_8487CC("%d", (D_80230C20_A27590->score.sizeParam1 % 100) / 10));
            } else {
                func_8037519C_84894C(D_80230C30_A275A0, "   １００％");
            }
            UIElement_SetTextPos(D_80230C30_A275A0, 90, 0);
            UIElement_PrintText(D_80230C30_A275A0, "コメント"); // comment
            UIElement_SetTextPos(D_80230C30_A275A0, 90, 12);
            func_8037519C_84894C(D_80230C30_A275A0, "%s", func_8037501C_8487CC("%5d", D_80230C20_A27590->score.commentID));
            UIElement_SetTextPos(D_80230C30_A275A0, 90, 24);
            UIElement_PrintText(D_80230C30_A275A0, "むきタイプ"); // muki type
            UIElement_SetTextPos(D_80230C30_A275A0, 90, 36);

            switch (D_80202D4C_9F96BC[func_8009BB4C(D_80230C20_A27590->score.pokemonInFocus)]) {
                case 1:
                    UIElement_PrintText(D_80230C30_A275A0, "            Ａ");
                    break;
                case 2:
                    UIElement_PrintText(D_80230C30_A275A0, "            Ｂ");
                    break;
                case 3:
                    UIElement_PrintText(D_80230C30_A275A0, "            Ｃ");
                    break;
                default:
                    UIElement_PrintText(D_80230C30_A275A0, "               ");
                    // fallthrough
            }

            UIElement_SetTextPos(D_80230C30_A275A0, 135, 0);
            UIElement_PrintText(D_80230C30_A275A0, "センサー"); // sensor
            UIElement_SetTextPos(D_80230C30_A275A0, 135, 12);
            func_8037519C_84894C(D_80230C30_A275A0, "         %s", (D_80230C20_A27590->photo.unk_00_16 & 0xE0) ? "オン" : "オフ"); // on / off
            UIElement_SetTextPos(D_80230C30_A275A0, 135, 24);
            UIElement_PrintText(D_80230C30_A275A0, "なかま"); // friend ???
            UIElement_SetTextPos(D_80230C30_A275A0, 135, 36);
            func_8037519C_84894C(D_80230C30_A275A0, "%sひき", func_8037501C_8487CC("%3d", D_80230C20_A27590->score.samePkmnNumber));
        }
    }
}

void func_801DDCD4_9D4644(s32 arg0) {
    if (arg0 != 0) {
        D_80230C68_A275D8[0]->sprite.attr &= ~SP_HIDDEN;
        D_80230C68_A275D8[1]->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_80230C68_A275D8[0]->sprite.attr |= SP_HIDDEN;
        D_80230C68_A275D8[1]->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DDD58_9D46C8(void) {
    s32 i;
    s32 sp48;
    char sp28[0x20];

    i = 0;
    for (i = 0; i < ARRAY_COUNT(D_80230C80_A275F0); i++) {
        sp48 = D_80230CB0_A27620[i + D_80230CA8_A27618];
        if (sp48 == 0) {

        } else {
            UIElement_SetFont(D_80230C80_A275F0[i], FONT_8);
            UIText_SetShadowOffset(0);
            UIText_SetSpacing(0, 4);
            UIElement_Draw(D_80230C80_A275F0[i]);
            func_8036D4B4_840C64(1, 0);
            UIElement_SetTextPos(D_80230C80_A275F0[i], 0, 0);
            func_8037519C_84894C(D_80230C80_A275F0[i], "%03d", sp48);
            func_8036D4B4_840C64(1, 1);
            UIElement_SetTextPos(D_80230C80_A275F0[i], 28, 0);
            func_8037519C_84894C(D_80230C80_A275F0[i], "%s", getPokemonName(sp48));
            UIElement_SetTextPos(D_80230C80_A275F0[i], 92, 0);
            func_8037519C_84894C(D_80230C80_A275F0[i], "%s", getLevelName(func_800BF710_5C5B0(sp48)->levelID));
            func_8036D4B4_840C64(1, 0);
            sprintf(sp28, "%s", func_8037501C_8487CC("%5d", func_800BF818_5C6B8(sp48)));
            UIElement_SetTextPos(D_80230C80_A275F0[i], 166 - UIText_GetStringWidth(sp28), 0);
            func_8037519C_84894C(D_80230C80_A275F0[i], "%5s", sp28);
            func_8036D4B4_840C64(1, 1);
            UIElement_SetState(D_80230C80_A275F0[i], UI_NORMAL);
        }
    }

    if (D_80230CA8_A27618 > 0) {
        UIElement_SetTextPos(D_80230C80_A275F0[0], 174, 0);
        UIElement_PrintText(D_80230C80_A275F0[0], "▲");
    }
    if (D_80230CAC_A2761C < func_800BF864_5C704() - 1) {
        UIElement_SetTextPos(D_80230C80_A275F0[ARRAY_COUNT(D_80230C80_A275F0) - 1], 174, 0);
        UIElement_PrintText(D_80230C80_A275F0[ARRAY_COUNT(D_80230C80_A275F0) - 1], "▼");
    }
}

void func_801DE078_9D49E8(s32 arg0) {
    if (arg0 != 0) {
        if (D_80230CAC_A2761C < func_800BF864_5C704() - 1) {
            UILayout_ShowHeaderElement(HEADER_NEXT);
        } else {
            UILayout_HideHeaderElement(HEADER_NEXT);
        }
        if (D_80230CA8_A27618 > 0) {
            UILayout_ShowHeaderElement(HEADER_PREV);
        } else {
            UILayout_HideHeaderElement(HEADER_PREV);
        }
    } else {
        UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
    }
}

s32 func_801DE118_9D4A88(const void* arg0, const void* arg1) {
    const s32* sp4 = arg0;
    const s32* sp0 = arg1;

    if (*sp4 > *sp0) {
        return 1;
    } else if (*sp4 < *sp0) {
        return -1;
    }
    return 0;
}

s32 func_801DE18C_9D4AFC(const void* arg0, const void* arg1) {
    const s32* sp2C;
    const s32* sp28;

    sp2C = arg0, sp28 = arg1;

    return func_803750CC_84887C(getPokemonName(*sp2C), getPokemonName(*sp28));
}

s32 func_801DE204_9D4B74(const void* arg0, const void* arg1) {
    UNUSED s32 pad;
    const s32* sp28;
    const s32* sp24;

    sp28 = arg0, sp24 = arg1;

    if (func_800BF710_5C5B0(*sp28)->levelID > func_800BF710_5C5B0(*sp24)->levelID) {
        return 1;
    }
    if (func_800BF710_5C5B0(*sp28)->levelID < func_800BF710_5C5B0(*sp24)->levelID) {
        return -1;
    }
    if (D_80202D2C_9F969C != NULL && func_801DE204_9D4B74 != D_80202D2C_9F969C) {
        return D_80202D2C_9F969C(arg0, arg1);
    }
    return func_801DE118_9D4A88(arg0, arg1);
}

s32 func_801DE318_9D4C88(const void* arg0, const void* arg1) {
    const s32* sp28;
    const s32* sp24;

    sp28 = arg0, sp24 = arg1;

    if (func_800BF818_5C6B8(*sp28) < func_800BF818_5C6B8(*sp24)) {
        return 1;
    } else if (func_800BF818_5C6B8(*sp28) > func_800BF818_5C6B8(*sp24)) {
        return -1;
    }
    if (D_80202D2C_9F969C != NULL && func_801DE318_9D4C88 != D_80202D2C_9F969C) {
        return D_80202D2C_9F969C(arg0, arg1);
    }
    return func_801DE118_9D4A88(arg0, arg1);
}

void func_801DE414_9D4D84(s32 arg0) {
    UIElement_SetTextPos(D_80230C1C_A2758C, 0, 0);
    UIElement_PrintText(D_80230C1C_A2758C, ((arg0 - 13) ^ 0) ? "No." : "\\eNo.");
    UIElement_SetTextPos(D_80230C1C_A2758C, 28, 0);
    UIElement_PrintText(D_80230C1C_A2758C, ((arg0 - 14) ^ 0) ? "NAME" : "\\eNAME");
    UIElement_SetTextPos(D_80230C1C_A2758C, 92, 0);
    if (arg0 == 15) {
        UIElement_PrintText(D_80230C1C_A2758C, "\\e");
    }
    UIElement_PrintText(D_80230C1C_A2758C, ((arg0 - 15) ^ 0) ? "COURSE" : "\\eCOURSE");
    UIElement_SetTextPos(D_80230C1C_A2758C, 137, 0);
    if (arg0 == 16) {
        UIElement_PrintText(D_80230C1C_A2758C, "\\e");
    }
    UIElement_PrintText(D_80230C1C_A2758C, ((arg0 - 16) ^ 0) ? "SCORE" : "\\eSCORE");
}

const char otherText[] = "It is said that somewhere on\nthis island is a mysterious\ngroup of huge rocks.";
const char otherText2[] = "Surprisingly, if you look at it\nfrom a certain angle, it appears\nto be a Pokεmon shape.";
const char otherText3[] = "When light shines on an\nobject, its shadow will appear\non the wall behind it.";
const char otherText4[] = "Somewhere there is a\nshadow that looks\nlike a Pokεmon!";
const char otherText5[] = "Smoke changes its shape, and\nsome shapes look like Pokεmon.";
const char otherText6[] = "Where can you find smoke...?\nYou already know!";
const char otherText7[] = "Have you heard of a tree near\nthe river in the jungle that\nlooks like CUBONE? No one";
const char otherText8[] = "knows who planted it, but I have\nheard that someone has seen\nthe tree... It's a mystery!";
const char otherText9[] = "Shining brightly somewhere...\nThat's all I know about this.";
const char otherText10[] = "Somewhere in the middle of\nsteep mountains is a mountain\nthat looks like a Pokεmon.";
const char otherText11[] = "I went to the Valley to find\nthis mountain.";
const char otherText12[] = "Isn't it amazing that a simple\nrock like this turned out to be a\nPKMN Sign?";
const char otherText13[] = "If you look at it from this\nangle, it looks like KINGLER. I\nwill call this ”KINGLER ROCK!”";
const char otherText14[] = "It was very clever of you to\nactivate the generator with\nZAPDOS's electric shock.";
const char otherText15[] = "This shadow looks like\nPINSIR... I will call this\nthe ”PINSIR SHADOW!”";
const char otherText16[] = "You hit it with a\nPESTER BALL?\nHa, ha, ha! This smoke";
const char otherText17[] = "looks like KOFFING.\nI will call this\n”KOFFING SMOKE!”";
const char otherText18[] = "The tree looked dim because of\nVILEPLUME's powder.";
const char otherText19[] = "Hmm...\nIt looks like CUBONE. I will\ncall this the ”CUBONE TREE!”";
const char otherText20[] = "I had no idea what this was all\nabout until I saw your picture.";
const char otherText21[] = "I think this looks like MEWTWO!\nCould this be the constellation\ncalled MEWTWO?";
const char otherText22[] = "This mountain looks like a\nPokεmon... This is it!\nThis is the PKMN Sign!";
const char otherText23[] = "Is this DIGLETT...?\nNo, it's DUGTRIO! I will\ncall this ”MT. DUGTRIO!”";

void func_801DE5A8_9D4F18(s32 arg0) {
    UIElement_Draw(D_80230C1C_A2758C);
    UIElement_SetColor(D_80230C1C_A2758C, UI_FOREGROUND, 0, 0, 0, 255);
    UIElement_SetColor(D_80230C1C_A2758C, UI_BACKGROUND, 133, 147, 171, 0);
    UIElement_SetTextPos(D_80230C1C_A2758C, 0, 0);
    D_80230C24_A27594 = arg0;
    func_801DE414_9D4D84(arg0);

    switch (arg0) {
        case 13:
            qsort2(D_80230CB0_A27620, func_800BF864_5C704(), 4, func_801DE118_9D4A88);
            if (func_801DE118_9D4A88 != D_80202D2C_9F969C) {
                D_80202D2C_9F969C = func_801DE118_9D4A88;
            }
            break;
        case 14:
            qsort2(D_80230CB0_A27620, func_800BF864_5C704(), 4, func_801DE18C_9D4AFC);
            if (func_801DE18C_9D4AFC != D_80202D2C_9F969C) {
                D_80202D2C_9F969C = func_801DE18C_9D4AFC;
            }
            break;
        case 15:
            qsort2(D_80230CB0_A27620, func_800BF864_5C704(), 4, func_801DE204_9D4B74);
            if (func_801DE204_9D4B74 != D_80202D2C_9F969C) {
                D_80202D2C_9F969C = func_801DE204_9D4B74;
            }
            break;
        case 16:
            qsort2(D_80230CB0_A27620, func_800BF864_5C704(), 4, func_801DE318_9D4C88);
            if (func_801DE318_9D4C88 != D_80202D2C_9F969C) {
                D_80202D2C_9F969C = func_801DE318_9D4C88;
            }
            break;
    }
    func_801DDD58_9D46C8();
}

void func_801DE7F8_9D5168(s32 arg0) {
    if (arg0 == 0) {
        func_801DCEA8_9D3818(0);
        func_801DD164_9D3AD4(arg0, D_80230CB0_A27620[D_80230DB4_A27724]);
    } else {
        func_801DCEA8_9D3818(1);
        D_80230C48_A275B8[0]->sprite.attr |= SP_HIDDEN;
        func_801DD164_9D3AD4(arg0, D_80230CB0_A27620[D_80230DB4_A27724]);
    }
}

void func_801DE898_9D5208(s32 arg0) {
    s32 i;

    if (arg0 != 0) {
        func_803700A4_843854(0);
        UILayout_CreateButtons(func_801E28A0_9D9210(0));
        UILayout_WaitPanelTransitionComplete();
        func_801DCEA8_9D3818(0);
        func_801DFBD0_9D6540(0);
        UIElement_Delete(D_80230C38_A275A8);
        UIElement_Delete(D_80230C30_A275A0);
        func_801DDCD4_9D4644(1);
        UIElement_SetState(D_80230C1C_A2758C, UI_NORMAL);
        D_80230C48_A275B8[0]->sprite.attr &= ~SP_HIDDEN;
        for (i = 0; i < ARRAY_COUNT(D_80230C80_A275F0); i++) {
            D_80230C80_A275F0[i] = UIElement_Create(112, (i * 15) + 69, 184, 8, UI_FLAG_32BIT);
            UIElement_SetColor(D_80230C80_A275F0[i], UI_FOREGROUND, 0, 0, 0, 255);
            UIElement_SetColor(D_80230C80_A275F0[i], UI_BACKGROUND, 0, 0, 0, 0);
            UIElement_SetState(D_80230C80_A275F0[i], UI_HIDDEN);
        }
        func_801DDD58_9D46C8();
    } else {
        func_80374714_847EC4(func_800BF710_5C5B0(D_80230CB0_A27620[D_80230DB4_A27724]), &D_80230C14_A27584->sprite);
        UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
        UILayout_CreateButtons(func_801E28A0_9D9210(1));
        UILayout_WaitPanelTransitionComplete();
        func_803700A4_843854(1);
        func_801DDCD4_9D4644(0);
        func_801DCEA8_9D3818(0);
        UIElement_SetState(D_80230C1C_A2758C, UI_HIDDEN);

        for (i = 0; i < ARRAY_COUNT(D_80230C80_A275F0); i++) {
            UIElement_Delete(D_80230C80_A275F0[i]);
        }

        func_801DFBD0_9D6540(1);
        D_80230C38_A275A8 = UIElement_Create(158, 157, 84, 12, UI_FLAG_32BIT);
        UIElement_SetColor(D_80230C38_A275A8, UI_FOREGROUND, 0, 0, 0, 255);
        UIElement_SetColor(D_80230C38_A275A8, UI_BACKGROUND, 0, 0, 0, 0);
        UIElement_DrawBackground(D_80230C38_A275A8);
        UIElement_SetState(D_80230C38_A275A8, UI_HIDDEN);
        D_80230C30_A275A0 = UIElement_Create(112, 173, 192, 52, UI_FLAG_32BIT);
        UIElement_SetColor(D_80230C30_A275A0, UI_FOREGROUND, 0, 0, 0, 255);
        UIElement_SetColor(D_80230C30_A275A0, UI_BACKGROUND, 0, 0, 0, 0);
        UIElement_DrawBackground(D_80230C30_A275A0);
        UIElement_SetState(D_80230C30_A275A0, UI_HIDDEN);
        if (D_80230DB4_A27724 > 0) {
            UILayout_ShowHeaderElement(HEADER_PREV);
        } else {
            UILayout_HideHeaderElement(HEADER_PREV);
        }
        if (D_80230DB4_A27724 < func_800BF864_5C704() - 1) {
            UILayout_ShowHeaderElement(HEADER_NEXT);
        } else {
            UILayout_HideHeaderElement(HEADER_NEXT);
        }
        func_801DE7F8_9D5168(0);
        ohWait(21);
    }
}

s32 func_801DEC60_9D55D0(s32 arg0, s32 arg1) {
    D_80230DBC_A2772C = 0;
    D_80230DB8_A27728 = 0;
    if (D_80230CAC_A2761C < func_800BF864_5C704() - 1) {
        D_80230DB8_A27728 = 1;
    }
    if (D_80230CAC_A2761C > 9) {
        D_80230DBC_A2772C = 1;
    }

    switch (arg1) {
        case 3:
            D_80230DB4_A27724--;
            D_80230DB0_A27720--;
            if (D_80230DB4_A27724 >= 0) {
                auPlaySound(0x45);
            }
            if ((D_80230DBC_A2772C != 0) && D_80230DB0_A27720 <= 0) {
                D_80230CA8_A27618--;
                D_80230CAC_A2761C--;
                D_80230DB0_A27720++;
            } else if (D_80230DB0_A27720 < 0) {
                D_80230DB0_A27720 = 0;
                D_80230DB4_A27724 = 0;
            }
            break;
        case 4:
            D_80230DB4_A27724++;
            D_80230DB0_A27720++;
            if (D_80230DB4_A27724 < func_800BF864_5C704()) {
                auPlaySound(0x45);
            }
            if (D_80230DB8_A27728 != 0 && D_80230DB0_A27720 >= 9) {
                D_80230CA8_A27618++;
                D_80230CAC_A2761C++;
                D_80230DB0_A27720--;
            } else if (D_80230DB0_A27720 > 9) {
                D_80230DB4_A27724--;
                D_80230DB0_A27720 = 9;
            } else if (func_800BF864_5C704() == D_80230DB0_A27720) {
                D_80230DB0_A27720 = func_800BF864_5C704() - 1;
                D_80230DB4_A27724 = D_80230DB0_A27720;
            }
            break;
    }

    if (arg1 != 0) {
        func_80374714_847EC4(func_800BF710_5C5B0(D_80230CB0_A27620[D_80230DB4_A27724]), &D_80230C14_A27584->sprite);
    }
    func_801DFBD0_9D6540(1);
    func_801DE7F8_9D5168(arg0);
    if (D_80230DB4_A27724 > 0) {
        UILayout_ShowHeaderElement(HEADER_PREV);
    } else {
        UILayout_HideHeaderElement(HEADER_PREV);
    }
    if (D_80230DB4_A27724 < func_800BF864_5C704() - 1) {
        UILayout_ShowHeaderElement(HEADER_NEXT);
    } else {
        UILayout_HideHeaderElement(HEADER_NEXT);
    }
    ohWait(12);
    return D_80230DB0_A27720;
}

void func_801DEFC8_9D5938(void) {
    s32 i;

    omDeleteGObj(D_80230C70_A275E0);

    for (i = 0; i < ARRAY_COUNT(D_80230C68_A275D8); i++)
        D_80230C68_A275D8[i] = NULL;
}

s32 func_801DF020_9D5990(s32 arg0) {
    D_80230DBC_A2772C = 0;
    D_80230DB8_A27728 = 0;
    if (D_80230CAC_A2761C < func_800BF864_5C704() - 1) {
        D_80230DB8_A27728 = 1;
    }
    if (D_80230CAC_A2761C > 9) {
        D_80230DBC_A2772C = 1;
    }

    switch (arg0) {
        case 1:
            D_80230DB4_A27724--;
            D_80230DB0_A27720--;
            if (D_80230DBC_A2772C != 0 && D_80230DB0_A27720 <= 0) {
                D_80230CA8_A27618--;
                D_80230CAC_A2761C--;
                D_80230DB0_A27720++;
                func_801DDD58_9D46C8();
            } else if (D_80230DB0_A27720 < 0) {
                D_80230DB0_A27720 = 0;
                D_80230DB4_A27724 = 0;
            }
            break;
        case 2:
            D_80230DB4_A27724++;
            D_80230DB0_A27720++;
            if (D_80230DB8_A27728 != 0 && D_80230DB0_A27720 >= 9) {
                D_80230CA8_A27618++;
                D_80230CAC_A2761C++;
                D_80230DB0_A27720--;
                func_801DDD58_9D46C8();
            } else if (D_80230DB0_A27720 >= 10) {
                D_80230DB4_A27724--;
                D_80230DB0_A27720 = 9;
            } else if (func_800BF864_5C704() == D_80230DB0_A27720) {
                D_80230DB0_A27720 = func_800BF864_5C704() - 1;
                D_80230DB4_A27724 = D_80230DB0_A27720;
            }
            break;
        case 3:
            if (D_80230DBC_A2772C != 0) {
                if (D_80230CA8_A27618 >= 10) {
                    D_80230DB4_A27724 -= 10;
                    D_80230CA8_A27618 -= 10;
                    D_80230CAC_A2761C -= 10;
                } else {
                    D_80230DB4_A27724 -= D_80230CA8_A27618;
                    D_80230CA8_A27618 = 0;
                    D_80230CAC_A2761C = 9;
                }
                func_801DDD58_9D46C8();
            }
            break;
        case 4:
            if (D_80230DB8_A27728 != 0) {
                if (D_80230CAC_A2761C < func_800BF864_5C704() - 10) {
                    D_80230DB4_A27724 += 10;
                    D_80230CA8_A27618 += 10;
                    D_80230CAC_A2761C += 10;
                } else {
                    D_80230DB4_A27724 = (func_800BF864_5C704() - (D_80230CAC_A2761C - D_80230DB4_A27724)) - 1;
                    D_80230CA8_A27618 = func_800BF864_5C704() - 10;
                    D_80230CAC_A2761C = func_800BF864_5C704() - 1;
                }
                func_801DDD58_9D46C8();
            }
            break;
    }
    D_80230C68_A275D8[0]->sprite.y = D_80230C68_A275D8[1]->sprite.y = (D_80230DB0_A27720 * 15) + 67;
    return D_80230DB4_A27724;
}

s32 func_801DF47C_9D5DEC(s32 arg0) {
    return D_80230CB0_A27620[D_80230CA8_A27618 + arg0];
}

GObj* func_801DF4AC_9D5E1C(s32 arg0) {
    GObj* gobj;
    SObj* sobj;
    s32 x;
    s32 y;
    u8* dest;
    u8* src;

    x = ((arg0 % 3) * 69) + 103;
    y = ((arg0 / 3) * 55) + 53;

    gobj = func_80371C68_845418(NULL, 6, &D_801F5680_9EBFF0);
    sobj = gobj->data.sobj;
    sobj->sprite.x = x;
    sobj->sprite.y = y;
    D_80230DC8_A27738[arg0].unk_00 = gobj;

    sobj = func_80371E68_845618(sobj, &D_801F5680_9EBFF0);
    sobj->sprite.x = 54;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801F57B0_9EC120);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801F57B0_9EC120);
    sobj->sprite.x = 2;
    sobj->sprite.y = 41;

    sobj = func_80371DC0_845570(sobj, D_80202DD0_9F9740[arg0]);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;

    D_80230DC8_A27738[arg0].unk_04 = sobj;
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = D_80202DE8_9F9758[arg0];
    sobj->sprite.bitmap->buf = D_80230DC8_A27738[arg0].unk_08 = dest; // what's going on with the types here

    for (x = 0xFD8; x > 0; src++, dest++, x--) {
        *dest = *src;
    }

    return gobj;
}

void func_801DF704_9D6074(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80230DC8_A27738); i++) {
        func_801DF4AC_9D5E1C(i);
    }
}

void func_801DF744_9D60B4(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80202D34_9F96A4); i++) {
        if (!func_800BF3D4_5C274(D_80202D34_9F96A4[i])) {

        } else {
            func_80374714_847EC4(func_800BF710_5C5B0(D_80202D34_9F96A4[i]), &D_80230DC8_A27738[i].unk_04->sprite);
        }
    }
}

void func_801DF7F0_9D6160(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80230DC8_A27738); i++) {
        if (arg0 != 0) {
            D_80230DC8_A27738[i].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_80230DC8_A27738[i].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void* func_801DF884_9D61F4(s32 arg0) {
    GObj* gobj = D_80230C10_A27580;
    SObj* sobj = gobj->data.sobj;

    sobj->sprite = D_801F5120_9EBA90;
    sobj->sprite.x = 127;
    sobj->sprite.y = 43;

    sobj = sobj->unk_58;
    sobj->sprite = D_801F5120_9EBA90;
    sobj->sprite.x = 143;
    sobj->sprite.y = 0;

    sobj = sobj->next;
    sobj->sprite = D_801F54C8_9EBE38;
    sobj->sprite.x = 3;
    sobj->sprite.y = 0;

    sobj = sobj->next;
    sobj->sprite = D_801F54C8_9EBE38;
    sobj->sprite.x = 3;
    sobj->sprite.y = 108;
    sobj = sobj->next;
    sobj->sprite = *D_80202DD0_9F9740[arg0];
    sobj->sprite.x = 3;
    sobj->sprite.y = 3;

    sobj->sprite.bitmap->buf = D_80202DE8_9F9758[arg0];
    sobj->sprite.scalex = 2.692f;
    sobj->sprite.scaley = 2.692f;
    sobj->sprite.attr |= SP_SCALE;
    D_80230C14_A27584 = sobj;
    return D_80230C10_A27580;
}

void func_801DFB10_9D6480(s32 arg0) {
    UNUSED s32 pad;

    if (arg0 < 0) {
        func_801DFBD0_9D6540(0);
        func_801DF7F0_9D6160(1);
    } else {
        func_801DF7F0_9D6160(0);
        func_801DF884_9D61F4(arg0);
    }
}

void func_801DFB68_9D64D8(s32 arg0) {
    s32 i;
    SObj* sobj;

    for (i = 0; i < 6; i++) {
        sobj = D_80230DC8_A27738[i].unk_00->data.sobj;
        sobj->sprite.red = arg0;
        sobj->sprite.green = arg0;
        sobj->sprite.blue = arg0;
    }
}

void func_801DFBD0_9D6540(s32 arg0) {
    if (arg0 != 0) {
        D_80230C10_A27580->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_80230C10_A27580->data.sobj->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DFC20_9D6590(s32 arg0) {
    if (func_800BF3D4_5C274(D_80202D34_9F96A4[arg0]) == 0) {
        return;
    }
    D_80230C14_A27584->sprite = D_80202CE8_9F9658;
    D_80230C14_A27584->sprite.x = 3;
    D_80230C14_A27584->sprite.y = 3;
    D_80230C14_A27584->sprite.attr &= ~SP_SCALE;
    func_80374714_847EC4(func_800BF710_5C5B0(D_80202D34_9F96A4[arg0]), &D_80230C14_A27584->sprite);
}

void func_801DFD24_9D6694(s32 arg0) {
    UNUSED s32 pad;

    D_80230C10_A27580->data.sobj->sprite.red = arg0;
    D_80230C10_A27580->data.sobj->sprite.green = arg0;
    D_80230C10_A27580->data.sobj->sprite.blue = arg0;
}

GObj* func_801DFD68_9D66D8(void) {
    GObj* gobj;
    SObj* sobj;

    D_80230C10_A27580 = gobj = func_80371C68_845418(NULL, 6, &D_801F5120_9EBA90);

    sobj = gobj->data.sobj;
    sobj->sprite.x = 130;
    sobj->sprite.y = 46;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = func_80371E68_845618(sobj, &D_801F5120_9EBA90);
    sobj->sprite.x = 143;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801F54C8_9EBE38);
    sobj->sprite.x = 3;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801F54C8_9EBE38);
    sobj->sprite.x = 3;
    sobj->sprite.y = 108;

    sobj = func_80371DC0_845570(sobj, &D_80202CE8_9F9658);
    sobj->sprite.x = 3;
    sobj->sprite.y = 3;

    D_80230C14_A27584 = sobj;
    return gobj;
}

GObj* func_801DFE9C_9D680C(void) {
    GObj* gobj = D_80230C10_A27580;
    SObj* sobj = gobj->data.sobj;

    sobj->sprite = D_801F5120_9EBA90;
    sobj->sprite.x = 130;
    sobj->sprite.y = 46;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = sobj->unk_58;
    sobj->sprite = D_801F5120_9EBA90;
    sobj->sprite.x = 143;
    sobj->sprite.y = 0;

    sobj = sobj->next;
    sobj->sprite = D_801F54C8_9EBE38;
    sobj->sprite.x = 3;
    sobj->sprite.y = 0;

    sobj = sobj->next;
    sobj->sprite = D_801F54C8_9EBE38;
    sobj->sprite.x = 3;
    sobj->sprite.y = 108;

    sobj = sobj->next;
    sobj->sprite = D_80202CE8_9F9658;
    sobj->sprite.x = 3;
    sobj->sprite.y = 3;

    D_80230C14_A27584 = sobj;
    return gobj;
}

s32 func_801E00E0_9D6A50(s32 arg0) {
    s32 i;
    s32 sp20;
    s32 lowest;
    s32 sp18;

    sp18 = func_800BF864_5C704();

    for (i = 0, lowest = -1; i < sp18; i++) {
        if (lowest < func_800BF818_5C6B8(D_80230CB0_A27620[i])) {
            lowest = func_800BF818_5C6B8(D_80230CB0_A27620[i]);
            sp20 = i;
        }
    }

    func_801DCEA8_9D3818(arg0);
    func_801DD164_9D3AD4(arg0, D_80230CB0_A27620[sp20]);
    return D_80230CB0_A27620[sp20];
}

void func_801E01C4_9D6B34(void) {
    GObj* sp1C = func_80371D14_8454C4(0, 6, &D_801E8F70_9DF8E0);
    SObj* sp18 = sp1C->data.sobj;

    sp18->sprite.x = 106;
    sp18->sprite.y = 52;
    D_80230C48_A275B8[0] = sp18;

    sp18 = func_80371DC0_845570(sp18, &D_801EDD60_9E46D0);
    sp18->sprite.x = 149;
    sp18->sprite.y = 116;
    sp18->sprite.alpha = 0x80;
    sp18->sprite.attr |= SP_TRANSPARENT;
    D_80230C48_A275B8[1] = sp18;

    sp18 = func_80371DC0_845570(sp18, &D_801EDEF0_9E4860);
    sp18->sprite.x = 124;
    sp18->sprite.y = 168;

    D_80230C48_A275B8[2] = sp18;
    D_80230C48_A275B8[3] = NULL;
    D_80230C48_A275B8[4] = NULL;
    D_80230C48_A275B8[5] = NULL;
    D_80230C60_A275D0 = sp1C;
}

void func_801E02F4_9D6C64(void) {
    GObj* gobj = D_80230C40_A275B0;
    SObj* sobj = omGObjAddSprite(gobj, &D_801E3F48_9DA8B8);

    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80230C3C_A275AC = sobj;
    gobj = D_80230C60_A275D0;

    sobj = omGObjAddSprite(gobj, &D_801E8F70_9DF8E0);
    sobj->sprite.x = 106;
    sobj->sprite.y = 52;
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;
    D_80230C48_A275B8[0] = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801EDD60_9E46D0);
    sobj->sprite.x = 149;
    sobj->sprite.y = 116;
    sobj->sprite.alpha = 0x80;
    sobj->sprite.attr |= SP_TRANSPARENT;
    D_80230C48_A275B8[1] = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801EDEF0_9E4860);
    sobj->sprite.x = 124;
    sobj->sprite.y = 168;

    D_80230C48_A275B8[2] = sobj;
    D_80230C48_A275B8[3] = NULL;
    D_80230C48_A275B8[4] = NULL;
    D_80230C48_A275B8[5] = NULL;
}

void func_801E0480_9D6DF0(void) {
    GObj* gobj;
    SObj* sobj;
    UNUSED s32 pad;

    gobj = D_80230C40_A275B0;
    sobj = omGObjAddSprite(gobj, &D_801EE150_9E4AC0);
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80230C3C_A275AC = sobj;

    gobj = D_80230C60_A275D0;
    sobj = omGObjAddSprite(gobj, &D_801F3A10_9EA380);
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;
    sobj->sprite.x = 112;
    sobj->sprite.y = 63;
    sobj->sprite.attr &= ~SP_SCALE;
    D_80230C48_A275B8[0] = sobj;
    sobj = func_80371DC0_845570(sobj, &D_801F3860_9EA1D0);
    sobj->sprite.x = 154;
    sobj->sprite.y = 173;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80230C48_A275B8[1] = sobj;
    sobj = func_80371DC0_845570(sobj, &D_801F3860_9EA1D0);
    sobj->sprite.x = 199;
    sobj->sprite.y = 173;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80230C48_A275B8[2] = sobj;
    sobj = func_80371DC0_845570(sobj, &D_801F3860_9EA1D0);
    sobj->sprite.x = 244;
    sobj->sprite.y = 173;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80230C48_A275B8[3] = sobj;
    D_80230C48_A275B8[4] = NULL;
    D_80230C48_A275B8[5] = NULL;

    gobj = func_80371D14_8454C4(0, 6, &D_801F4D48_9EB6B8);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 102;
    sobj->sprite.y = 67;
    sobj->sprite.alpha = 0x80;
    sobj->sprite.attr |= SP_HIDDEN | SP_TRANSPARENT;
    D_80230C70_A275E0 = gobj;
    D_80230C68_A275D8[0] = sobj;
    sobj = func_80371DC0_845570(sobj, &D_801F3B90_9EA500);
    sobj->sprite.x = 96;
    sobj->sprite.y = 67;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80230C68_A275D8[1] = sobj;
    func_801DFE9C_9D680C();
}

void func_801E072C_9D709C(void) {
    GObj* gobj;
    SObj* sobj;
    UNUSED s32 pad;

    gobj = D_80230C40_A275B0;
    sobj = omGObjAddSprite(gobj, &D_801EE150_9E4AC0);
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80230C3C_A275AC = sobj;
    func_801DF744_9D60B4();
    func_801DFE9C_9D680C();
    func_801DF7F0_9D6160(0);
}

void func_801E07C0_9D7130(void) {
    GObj* gobj;
    SObj* sobj;
    UNUSED s32 pad;

    gobj = D_80230C40_A275B0;
    sobj = omGObjAddSprite(gobj, &D_801EE150_9E4AC0);
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80230C3C_A275AC = sobj;

    gobj = D_80230C60_A275D0;
    sobj = omGObjAddSprite(gobj, &D_801F3860_9EA1D0);
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;
    sobj->sprite.x = 154;
    sobj->sprite.y = 173;
    sobj->sprite.attr &= ~SP_SCALE;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80230C48_A275B8[0] = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801F3860_9EA1D0);
    sobj->sprite.x = 199;
    sobj->sprite.y = 173;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80230C48_A275B8[1] = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801F3860_9EA1D0);
    sobj->sprite.x = 244;
    sobj->sprite.y = 173;
    sobj->sprite.attr |= SP_HIDDEN;
    D_80230C48_A275B8[2] = sobj;
    D_80230C48_A275B8[3] = NULL;
    D_80230C48_A275B8[4] = NULL;
    D_80230C48_A275B8[5] = NULL;

    gobj = D_80230C10_A27580;
    sobj = gobj->data.sobj;
    sobj->sprite = D_801EF7D0_9E6140;
    sobj->sprite.x = 112;
    sobj->sprite.y = 21;

    sobj = sobj->unk_58;
    sobj->sprite = D_801F0E50_9E77C0;
    sobj->sprite.x = 158;
    sobj->sprite.y = 0;

    sobj = sobj->next;
    sobj->sprite = D_801F2278_9E8BE8;
    sobj->sprite.x = 18;
    sobj->sprite.y = 0;

    sobj = sobj->next;
    sobj->sprite = D_801F36A0_9EA010;
    sobj->sprite.x = 18;
    sobj->sprite.y = 123;

    sobj = sobj->next;
    sobj->sprite = D_80202CE8_9F9658;
    sobj->sprite.x = 18;
    sobj->sprite.y = 18;
    D_80230C14_A27584 = sobj;
}

s32 func_801E0B8C_9D74FC(UIElement* arg0, char** arg1, s32 arg2) {
    s32 sp1C;

    UIText_SetPrintDelay(2);

    for (; *arg1 != 0; arg1++) {
        UIElement_Draw(arg0);
        UIElement_PrintText(arg0, *arg1);
        sp1C = func_80374F30_8486E0(arg0, true);
        if (arg2 != 0 && sp1C == 0x4000) {
            return 0x4000;
        }
    }

    return 0;
}

void func_801E0C3C_9D75AC(s32 arg0) {
    s32 sp1C;

    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_80202E8C_9F97FC)) {
        return;
    }
    if (func_800BF3D4_5C274(D_80202D34_9F96A4[arg0]) == 0) {
        func_801E0B8C_9D74FC(D_80230C30_A275A0, D_80202E8C_9F97FC[arg0], 0);
    } else {
        func_801E0B8C_9D74FC(D_80230C30_A275A0, D_80202EA4_9F9814[arg0], 0);
    }
    UIText_SetPrintDelay(0);
    func_801DCF5C_9D38CC(&sp1C);
    UIElement_SetTextPos(D_80230C30_A275A0, 0, 0);
    UIElement_PrintText(D_80230C30_A275A0, "You have collected");
    UIElement_SetTextPos(D_80230C30_A275A0, 0, 18);
    func_8037519C_84894C(D_80230C30_A275A0, "%d PKMN Signs.", sp1C);
}

void func_801E0D54_9D76C4(void) {
    func_801DFBD0_9D6540(0);
    func_801DF7F0_9D6160(1);
}

void func_801E0D84_9D76F4(void) {
    func_801DFBD0_9D6540(1);
    func_801DF7F0_9D6160(0);
}

void func_801E0DB4_9D7724(UIElement* arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp28[0x80];

    UIElement_Draw(arg0);
    sp28[0] = sp28[1] = 0;

    if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
        UIElement_SetTextPos(arg0, 8, 0);
        UIElement_PrintText(arg0, "No. of PKMN seen");
        UIElement_SetTextPos(arg0, 88, 0);
        func_8037519C_84894C(arg0, "\\i%7d\\g kind%s", arg1, (arg1 >= 2) ? "s" : "");
        UIElement_SetTextPos(arg0, 8, 16);
        func_8037519C_84894C(arg0, "No. of PKMN Signs seen", (arg2 != 1) ? "s" : "");
        UIElement_SetTextPos(arg0, 88, 16);
        func_8037519C_84894C(arg0, "\\i%7d\\g Sign%s", arg2, (arg2 != 1) ? "s" : "");
    } else {
        UIElement_SetTextPos(arg0, 8, 16);
        UIElement_PrintText(arg0, "No. of PKMN seen");
        UIElement_SetTextPos(arg0, 88, 16);
        func_8037519C_84894C(arg0, "\\i%7d\\g kind%s", arg1, (arg1 >= 2) ? "s" : "");
    }
    UIElement_SetTextPos(arg0, 8, 32);
    UIElement_PrintText(arg0, "Report Score");
    UIElement_SetTextPos(arg0, 88, 32);
    func_8037519C_84894C(arg0, "\\i%7d\\g points", arg3);
    if (checkPlayerFlag(PFID_14)) {
        sprintf(sp28, "%s", "Boost your PKMN Report Score!");
    } else if (func_800BF3D4_5C274(PokemonID_MEW)) {
        sprintf(sp28, "%s", "Complete your PKMN Report!");
    } else if (func_800BFC5C_5CAFC() == 6) {
        sprintf(sp28, "%s", "Find rare Pokεmon!");
    } else if (func_800BFC5C_5CAFC() == 5) {
        if (checkPlayerFlag(PFID_HAS_FLUTE)) {
            if (func_800BF3D4_5C274(PokemonID_1004) && func_800BF3D4_5C274(PokemonID_1010) && func_800BF3D4_5C274(PokemonID_KOFFING_SMOKE) &&
                func_800BF3D4_5C274(PokemonID_1022) && func_800BF3D4_5C274(PokemonID_1018) && func_800BF3D4_5C274(PokemonID_1035)) {
                UIElement_SetTextPos(arg0, 82 - (UIText_GetStringWidth("Well, this is the final course!") / 2), 51);
                sprintf(sp28, "%s", "Well, this is the final course!");
            } else {
                sprintf(sp28, "%s", "Collect all the PKMN Signs!");
            }
        } else if (checkPlayerFlag(PFID_HAS_DASH_ENGINE)) {
            if (arg3 < 130000) {
                sprintf(sp28, "%s", "Boost your PKMN Report Score!");
            }
        } else {
            sprintf(sp28, "%s", "Solve the secret of the Switch!");
        }
    } else if (func_800BFC5C_5CAFC() == 4) {
        sprintf(sp28, "%s", "Collect more Pokεmon for the Report!");
    } else if (func_800BFC5C_5CAFC() == 3) {
        if (checkPlayerFlag(PFID_HAS_PESTER_BALL)) {
            sprintf(sp28, "%s", "Solve the secret of the Switch!");
        } else if (arg3 < 72500) {
            sprintf(sp28, "%s", "Boost your PKMN Report Score!");
        }
    } else if (func_800BFC5C_5CAFC() == 2) {
        sprintf(sp28, "%s", "Collect more Pokεmon for the Report!");
    } else if (func_800BFC5C_5CAFC() == 1) {
        if (checkPlayerFlag(PFID_HAS_APPLE)) {
            sprintf(sp28, "%s", "Solve the mystery of the Tunnel!");
        } else if (arg3 < 24000) {
            sprintf(sp28, "%s", "Boost your PKMN Report Score!");
        }
    } else {
        sprintf(sp28, "%s", "Collect more Pokεmon for the Report!");
    }
    UIElement_SetTextPos(arg0, 82 - (UIText_GetStringWidth(sp28) / 2), 51);
    func_8037519C_84894C(arg0, "%s", sp28);
}

void func_801E1378_9D7CE8(void) {
    s32 i;
    UNUSED s32 pad2;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    UIElement* sp38;
    UNUSED s32 pad[3];

    if (D_80230C74_A275E4 <= 0) {
        func_801E02F4_9D6C64();
        func_801DCD78_9D36E8(0);
        sp38 = UIElement_Create(118, 123, 182, 97, UI_FLAG_32BIT);
        UIElement_SetColor(sp38, UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(sp38, UI_BACKGROUND, 133, 147, 171, 0);
        UIElement_DrawBackground(sp38);
        UIElement_SetState(sp38, UI_HIDDEN);
        D_80230C1C_A2758C = sp38;
        UIElement_SetFont(sp38, FONT_8);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIText_SetPrintDelay(0);
        sp44 = func_801DCF5C_9D38CC(&sp3C);
        sp40 = func_800BF864_5C704();
        UIElement_Draw(sp38);
        func_801E0DB4_9D7724(sp38, sp40, sp3C, sp44);
        ohWait(1);
        UIElement_SetState(sp38, UI_NORMAL);

        for (i = 0; i < 10; i++) {
            func_801DCD30_9D36A0(sp38, (i * 0xFF) / 10);
            func_801DCD78_9D36E8((i * 0xFF) / 10);
            ohWait(1);
        }

        func_801DCD78_9D36E8(0xFF);
        func_801DCD30_9D36A0(sp38, 0xFF);
    }

    UILayout_ShowPanel(true);
    ohWait(21);
    UILayout_CreateButtons(func_801E2850_9D91C0());
    UILayout_WaitPanelTransitionComplete();
    func_803700A4_843854(1);
}

void func_801E1568_9D7ED8(s32 arg0) {
    UNUSED s32 pad;
    s32 i;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    func_803700A4_843854(0);
    UILayout_SetHeaderFlags(0);
    UILayout_HideButtons();
    ohWait(21);

    sp24 = func_801DCF5C_9D38CC(&sp1C);
    sp20 = func_800BF864_5C704();
    if (arg0 != 0) {
        sp18 = arg0;
        auSetBGMVolumeSmooth(0, 0, sp18 + 5);
    } else {
        sp18 = 10;
    }

    for (i = sp18; i >= 0; i--) {
        func_801DCD30_9D36A0(D_80230C1C_A2758C, (i * 0xFF) / sp18);
        func_801DCD78_9D36E8((i * 0xFF) / sp18);
        ohWait(1);
    }

    func_801DCD78_9D36E8(0);
    UIElement_Delete(D_80230C1C_A2758C);
    func_801DCE3C_9D37AC();
    D_80230C74_A275E4 = 0;
    UILayout_ShowPanel(false);
}

void func_801E16DC_9D804C(void) {
    s32 i;
    UNUSED s32 pad;
    UIElement* sp2C;

    if (D_80230C74_A275E4 <= 0) {
        func_801E0480_9D6DF0();
        func_801DCD78_9D36E8(0);
        sp2C = UIElement_Create(146, 22, 108, 16, 0);
        UIElement_SetColor(sp2C, UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(sp2C, UI_BACKGROUND, 218, 108, 0, 0);
        UIElement_DrawBackground(sp2C);
        UIElement_SetFont(sp2C, FONT_12);
        UIText_SetShadowOffset(1);
        UIText_SetSpacing(-1, 3);
        UIElement_SetTextPos(sp2C, (108 - UIText_GetStringWidth("PKMN Report")) / 2, 0);
        UIElement_PrintText(sp2C, "PKMN Report");
        UIElement_SetState(sp2C, UI_HIDDEN);
        D_80230C34_A275A4 = sp2C;
        sp2C = UIElement_Create(112, 50, 176, 15, 0);
        UIElement_SetColor(sp2C, UI_FOREGROUND, 0, 0, 0, 255);
        UIElement_SetColor(sp2C, UI_BACKGROUND, 133, 147, 171, 0);
        UIElement_DrawBackground(sp2C);
        UIElement_SetState(sp2C, UI_HIDDEN);
        D_80230C1C_A2758C = sp2C;

        for (i = 0; i < 10; i++) {
            D_80230C80_A275F0[i] = UIElement_Create(112, (i * 15) + 69, 184, 8, UI_FLAG_32BIT);
            UIElement_SetColor(D_80230C80_A275F0[i], UI_FOREGROUND, 0, 0, 0, 255);
            UIElement_SetColor(D_80230C80_A275F0[i], UI_BACKGROUND, 0, 0, 0, 0);
            UIElement_SetState(D_80230C80_A275F0[i], UI_HIDDEN);
        }

        D_80230CA8_A27618 = 0;
        D_80230CAC_A2761C = 9;
        D_80230DAC_A2771C = 0;
        D_80230DB0_A27720 = 0;
        D_80230DB4_A27724 = 0;
        func_801DDD58_9D46C8();
        func_801DFBD0_9D6540(0);
        UIElement_SetFont(sp2C, FONT_8);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIText_SetPrintDelay(0);
        UIElement_Draw(sp2C);
        if (D_80230C24_A27594 == -1) {
            func_801DE414_9D4D84(13);
        } else {
            func_801DE414_9D4D84(D_80230C24_A27594);
        }
        UIElement_SetSpriteColor(sp2C, 0, 0, 0, 0);
        UIElement_SetState(sp2C, UI_NORMAL);
        ohWait(1);

        for (i = 0; i < 10; i++) {
            func_801DCD78_9D36E8((i * 0xFF) / 10);
            func_801DCD30_9D36A0(sp2C, (i * 0xFF) / 10);
            ohWait(1);
        }

        func_801DCD78_9D36E8(0xFF);
        UILayout_ShowPanel(true);
        UILayout_ShowHeaderElement(HEADER_TITLE);
        func_801DE078_9D49E8(0);
        ohWait(30);
        UIElement_SetState(D_80230C34_A275A4, UI_NORMAL);
        func_803700A4_843854(1);
    }
}

void func_801E1AC4_9D8434(void) {
    s32 i;

    func_803700A4_843854(0);
    UIElement_Delete(D_80230C34_A275A4);
    UILayout_SetHeaderFlags(0);
    UILayout_HideButtons();
    ohWait(21);

    for (i = 10; i >= 0; i--) {
        func_801DCD30_9D36A0(D_80230C1C_A2758C, (i * 0xFF) / 10);
        func_801DCD78_9D36E8((i * 0xFF) / 10);
        ohWait(1);
    }

    func_801DCD78_9D36E8(0);
    UIElement_Delete(D_80230C1C_A2758C);

    for (i = 0; i < 10; i++) {
        UIElement_Delete(D_80230C80_A275F0[i]);
    }

    func_801DCE3C_9D37AC();
    func_801DEFC8_9D5938();
    func_801DFBD0_9D6540(0);
    D_80230C74_A275E4 = 0;
    UILayout_ShowPanel(false);
}

void func_801E1BEC_9D855C(void) {
    s32 i;
    s32 sp38;
    ucolor sp34;
    UIFrame* sp30;
    UIElement* sp2C;

    auPlaySong(0, 0x1E);
    auSetBGMVolumeSmooth(0, 0x7F00, 0xF);
    if (D_80230C74_A275E4 <= 0) {
        func_801E072C_9D709C();
        func_801DCD78_9D36E8(0);
        sp30 = D_80230C28_A27598;
        UIFrame_GetBackgroundColor(sp30, &sp34);
        sp2C = UIElement_Create(146, 22, 108, 16, 0);
        UIElement_SetColor(sp2C, UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(sp2C, UI_BACKGROUND, 218, 108, 0, 0);
        UIElement_DrawBackground(sp2C);
        UIElement_SetFont(sp2C, FONT_12);
        UIText_SetShadowOffset(1);
        UIText_SetSpacing(-1, 3);
        UIElement_SetTextPos(sp2C, (108 - UIText_GetStringWidth("PKMN Signs")) / 2, 0);
        UIElement_PrintText(sp2C, "PKMN Signs");
        UIElement_SetState(sp2C, UI_HIDDEN);
        D_80230C34_A275A4 = sp2C;
        sp2C = UIElement_Create(104, 173, 192, 47, 0);
        UIElement_SetColor(sp2C, UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(sp2C, UI_BACKGROUND, sp34.r, sp34.g, sp34.b, 255);
        UIElement_DrawBackground(sp2C);
        UIElement_SetState(sp2C, UI_HIDDEN);
        D_80230C30_A275A0 = sp2C;
        ohWait(1);
        func_801DF7F0_9D6160(1);

        for (i = 0; i < 10; i++) {
            func_801DCD78_9D36E8((i * 0xFF) / 10);
            func_801DFB68_9D64D8((i * 0xFF) / 10);
            ohWait(1);
        }

        func_801DCD78_9D36E8(0xFF);
        func_801DFB68_9D64D8(0xFF);
        UILayout_ShowPanel(true);
        UILayout_ShowHeaderElement(HEADER_TITLE);
        ohWait(21);
        UIElement_SetState(D_80230C34_A275A4, UI_NORMAL);
        UIFrame_FadeIn(sp30, FRAME_STYLE_1);
        UIElement_SetState(sp2C, UI_NORMAL);
        UIText_SetPrintDelay((0, 0));
        UIElement_SetFont(sp2C, FONT_12);
        UIText_SetShadowOffset(1);
        UIText_SetSpacing(-1, 3);
        UIElement_SetFont(sp2C, FONT_12);
        UIText_SetPrintDelay(0);
        func_801DCF5C_9D38CC(&sp38);
        UIElement_SetTextPos(sp2C, 0, 0);
        UIElement_PrintText(sp2C, "You have collected");
        UIElement_SetTextPos(sp2C, 0, 18);
        func_8037519C_84894C(sp2C, "%d PKMN Signs.", sp38);
    }
}

void func_801E1F20_9D8890(void) {
    s32 i;
    s32 sp18;

    sp18 = 30;
    func_803700A4_843854(0);
    UIElement_SetState(D_80230C30_A275A0, UI_HIDDEN);
    UIElement_SetState(D_80230C34_A275A4, UI_HIDDEN);
    UILayout_SetHeaderFlags(0);
    UIElement_Delete(D_80230C34_A275A4);
    UIElement_Delete(D_80230C30_A275A0);
    UIFrame_FadeOut(D_80230C28_A27598);
    UILayout_HideButtons();
    ohWait(21);
    auSetBGMVolumeSmooth(0, 0, sp18);

    for (i = sp18; i >= 0; i--) {
        func_801DCD78_9D36E8((i * 0xFF) / sp18);
        func_801DFB68_9D64D8((i * 0xFF) / sp18);
        ohWait(1);
    }

    func_801DCD78_9D36E8(0);
    func_801DFB68_9D64D8(0);
    func_801DCE3C_9D37AC();
    func_801DF7F0_9D6160(0);
    D_80230C74_A275E4 = 0;
    UILayout_WaitPanelTransitionComplete();
    auPlaySong(0, 0x1D);
    auSetBGMVolumeSmooth(0, 0x7F00, 0xF);
}

void func_801E20B4_9D8A24(void) {
    s32 i;
    s32 sp30;

    auPlaySong(0, 0x12);
    auSetBGMVolumeSmooth(0, 0x7F00, 0xF);
    if (D_80230C74_A275E4 <= 0) {
        func_801E07C0_9D7130();
        func_801DCD78_9D36E8(0);
        func_801DFD24_9D6694(0);
        D_80230C38_A275A8 = UIElement_Create(158, 147, 84, 12, UI_FLAG_32BIT);
        UIElement_SetColor(D_80230C38_A275A8, UI_FOREGROUND, 0, 0, 0, 255);
        UIElement_SetColor(D_80230C38_A275A8, UI_BACKGROUND, 0, 0, 0, 0);
        UIElement_DrawBackground(D_80230C38_A275A8);
        UIElement_SetState(D_80230C38_A275A8, UI_NORMAL);
        D_80230C30_A275A0 = UIElement_Create(112, 173, 192, 52, UI_FLAG_32BIT);
        UIElement_SetColor(D_80230C30_A275A0, UI_FOREGROUND, 0, 0, 0, 255);
        UIElement_SetColor(D_80230C30_A275A0, UI_BACKGROUND, 0, 0, 0, 0);
        UIElement_DrawBackground(D_80230C30_A275A0);
        UIElement_SetState(D_80230C30_A275A0, UI_NORMAL);
        ohWait(1);
        func_801DFBD0_9D6540(1);
        sp30 = func_801E00E0_9D6A50(0);
        func_80374714_847EC4(func_800BF710_5C5B0(sp30), &D_80230C14_A27584->sprite);

        for (i = 0; i < 10; i++) {
            func_801DCD78_9D36E8((i * 0xFF) / 10);
            func_801DFD24_9D6694((i * 0xFF) / 10);
            ohWait(1);
        }

        func_801DCD78_9D36E8(0xFF);
        func_801DFD24_9D6694(0xFF);
        if (D_80202D30_9F96A0 != sp30) {
            D_80230C78_A275E8 = func_8037452C_847CDC(func_800BF710_5C5B0(sp30));
            D_80202D30_9F96A0 = sp30;
        }

        UIElement_SetState(D_80230C30_A275A0, UI_NORMAL);
        UIText_SetPrintDelay(0);
        UILayout_ShowPanel(true);
        ohWait(21);
    }
}

void func_801E2340_9D8CB0(void) {
    s32 i;
    s32 sp18;

    sp18 = 30;
    func_803700A4_843854(0);
    UILayout_SetHeaderFlags(0);
    UILayout_HideButtons();
    ohWait(21);
    auSetBGMVolumeSmooth(0, 0U, sp18);

    for (i = sp18 - 5; i >= 0; i--) {
        func_801DCD78_9D36E8((i * 0xFF) / (sp18 - 5));
        func_801DFD24_9D6694((i * 0xFF) / (sp18 - 5));
        ohWait(1);
    }

    func_801DCD78_9D36E8(0);
    func_801DFD24_9D6694(0);
    UIElement_Delete(D_80230C38_A275A8);
    UIElement_Delete(D_80230C30_A275A0);
    func_801DCE3C_9D37AC();
    func_801DFBD0_9D6540(0);
    D_80230C74_A275E4 = 0;
    UILayout_WaitPanelTransitionComplete();
    auPlaySong(0, 0x1D);
    auSetBGMVolumeSmooth(0, 0x7F00, 0xF);
}

void func_801E24B4_9D8E24(GObj* arg0) {
    UNUSED s32 pad2;
    s32 i2;
    s32 i;
    s32 sp44;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    UIElement* sp30;
    s32 sp2C;

    sp2C = 1;
    D_80230DC0_A27730 = 0;
    UILayout_Init();
    func_80370428_843BD8();
    func_803700A4_843854(0);
    sp3C = func_801DCF5C_9D38CC(&sp34);
    sp38 = func_800BF864_5C704();
    D_80230C28_A27598 = UIFrame_Create();
    UIFrame_SetStyle(D_80230C28_A27598, FRAME_STYLE_1);
    UIFrame_SetPos(D_80230C28_A27598, 184, 320);
    UIFrame_Show(D_80230C28_A27598, false);
    sp30 = UIElement_Create(118, 123, 182, 97, UI_FLAG_32BIT);
    UIElement_SetColor(sp30, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp30, UI_BACKGROUND, 133, 147, 171, 0);
    UIElement_DrawBackground(sp30);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_SetFont(sp30, FONT_8);
    UIElement_Draw(sp30);
    UIElement_SetState(sp30, UI_HIDDEN);
    func_801E0DB4_9D7724(sp30, sp38, sp34, sp3C);
    D_80230C1C_A2758C = sp30;
    func_801DF704_9D6074();
    func_801DF7F0_9D6160(0);
    func_801DFD68_9D66D8();
    ohWait(1);
    UIElement_SetState(sp30, UI_NORMAL);

    for (i = 0; i < 60; i++) {
        func_801DCD30_9D36A0(sp30, (i * 0xFF) / 60);
        func_801DCD78_9D36E8((i * 0xFF) / 60);
        ohWait(1);
    }

    func_801DCD78_9D36E8(0xFF);
    func_801DCD30_9D36A0(sp30, 0xFF);

    for (i = 0, i2 = 0; i2 <= POKEDEX_MAX; i2++) {
        if (func_800BF3D4_5C274(i2)) {
            D_80230CB0_A27620[i++] = i2;
        }
    }

    UILayout_ShowPanel(true);
    UILayout_SetHeaderFlags(0);
    ohWait(30);
    UILayout_CreateButtons(func_801E2850_9D91C0());
    UILayout_WaitPanelTransitionComplete();
    func_803700A4_843854(1);

    while (true) {
        sp30 = D_80230C30_A275A0;
        func_801E3B18_9DA488();
        UILayout_ShowPanel(false);
        func_800AADF0(SCENE_OAKS_LAB_2);
        ohWait(1);
    }
}

void func_801E2790_9D9100(void) {
    GObj* gobj;
    SObj* sobj;

    func_800A85E8(func_801E24B4_9D8E24, LINK_6, DL_LINK_0, NULL);
    gobj = func_80371D14_8454C4(0, 6, &D_801E3F48_9DA8B8);
    sobj = gobj->data.sobj;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80230C40_A275B0 = gobj;
    D_80230C3C_A275AC = sobj;
    func_801E01C4_9D6B34();
    D_80230C74_A275E4 = 1;
    D_80230C24_A27594 = -1;
    func_801DCD78_9D36E8(0);
}
