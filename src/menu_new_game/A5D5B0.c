#include "common.h"
#include "../window/window.h"

extern Sprite D_80118068_A93418; // cursor

// BSS
extern UIElement* D_80118110;
extern UIElement* D_80118114;
static s32 menu_new_game_CursorX;
static s32 menu_new_game_CursorY;
static s32 D_80168128;
static s8 D_8016812C;
static char D_80168130[16];
static u8 D_80168140[3];
static u8 D_80168143;
static u8 D_80168144;
static GObj* D_80168148;
static u8 D_8016814C;

void func_800E2800_A5DBB0(void);
void func_800E2758_A5DB08(void);
void func_800E28C0_A5DC70(void);
u8** func_800E18B4_A5CC64(s32 arg0);

void func_800E2200_A5D5B0(void) {
    if (menu_new_game_CursorY < 19) {
        FocusMark_SetTargetSize(4, 5);
        FocusMark_SetTargetPos(menu_new_game_CursorX * 13 + 25, menu_new_game_CursorY * 10 + 22);
        return;
    }
    if (menu_new_game_CursorX < 2) {
        FocusMark_SetTargetSize(4, 5);
        FocusMark_SetTargetPos(menu_new_game_CursorX * 13 + 25, menu_new_game_CursorY * 10 + 22);
        return;
    }
    FocusMark_SetTargetSize(15, 5);
    FocusMark_SetTargetPos(63, menu_new_game_CursorY * 10 + 22);
}

void func_800E2314_A5D6C4(void) {
    menu_new_game_CursorX = 2;
    menu_new_game_CursorY = 19;
    func_800E2200_A5D5B0();
    auPlaySound(SOUND_ID_65);
}

void func_800E2350_A5D700(void) {
    s8 i;

    for (i = 0; i < 8; i++) {
        D_80168130[i] = 0;
    }
    D_80168143 = 0;
}

void func_800E2384_A5D734(void) {
    menu_new_game_CursorX = menu_new_game_CursorY = D_80168128 = 0;
    D_8016812C = 0;
}

void func_800E23B0_A5D760(void) {
    D_80168144 = 1;
    func_800E2384_A5D734();
    func_800E2350_A5D700();
}

void func_800E23E0_A5D790(s32 buttons) {
    if (menu_new_game_CursorY < 19) {
        if (buttons & 0x10000) {
            menu_new_game_CursorY--;
            if (menu_new_game_CursorY < 0) {
                menu_new_game_CursorY = 19;
            }
        }
        if (buttons & 0x20000) {
            menu_new_game_CursorY++;
        }
        if (buttons & 0x80000) {
            menu_new_game_CursorX--;
            if (menu_new_game_CursorX < 0) {
                menu_new_game_CursorX = 4;
            }
        }
        if (buttons & 0x40000) {
            menu_new_game_CursorX++;
            menu_new_game_CursorX %= 5;
        }
        if (menu_new_game_CursorY >= 19) {
            D_80168128 = menu_new_game_CursorX;
            menu_new_game_CursorX = menu_new_game_CursorX / 3;
            auPlaySound(SOUND_ID_65);
        } else {
            auPlaySound(69);
        }
    } else {
        if (buttons & 0x10000) {
            menu_new_game_CursorY--;
        }
        if (buttons & 0x20000) {
            menu_new_game_CursorY++;
            menu_new_game_CursorY = menu_new_game_CursorY % 20;
        }
        if (buttons & 0x80000) {
            menu_new_game_CursorX--;
            if (menu_new_game_CursorX < 0) {
                menu_new_game_CursorX = 0;
            }
        }
        if (buttons & 0x40000) {
            menu_new_game_CursorX++;
            if (menu_new_game_CursorX >= 3) {
                menu_new_game_CursorX = 2;
            }
        }
        if (menu_new_game_CursorY < 19) {
            menu_new_game_CursorX = D_80168128;
            auPlaySound(69);
        } else {
            auPlaySound(SOUND_ID_65);
        }
    }
}

void func_800E2590_A5D940(UnkStruct800BEDF8* arg0) {
    func_800E23E0_A5D790(arg0->pressedButtons);
    func_800E2200_A5D5B0();
}

void func_800E25B8_A5D968(void) {
}

void func_800E25C0_A5D970(void) {
    u8* src;
    u8* dst;

    if (D_80168143 >= 14) {
        func_800E2314_A5D6C4();
        return;
    }

    dst = &D_80168130[D_80168143];
    src = D_80168140;
    while (*src != 0) {
        *dst++ = *src++;
    }

    UIElement_Draw(D_80118110);
    UIElement_SetTextPos(D_80118110, 0, 0);
    UIElement_PrintText(D_80118110, D_80168130);
    if (D_80168143 < 14) {
        D_80168143 += 2;
    }
    if (D_80168143 == 14) {
        func_800E2314_A5D6C4();
    }
}

void func_800E26A0_A5DA50(void) {
    switch (menu_new_game_CursorX) {
        case 0:
            func_800E2800_A5DBB0();
            break;
        case 1:
            func_800E2758_A5DB08();
            break;
        default:
            func_800E28C0_A5DC70();
            D_80168144 = 2;
            break;
    }
}

void func_800E270C_A5DABC(void) {
    if (menu_new_game_CursorY < 19) {
        func_800E25C0_A5D970();
        auPlaySound(66);
    } else {
        func_800E26A0_A5DA50();
    }
}

void func_800E2758_A5DB08(void) {
    u8 sp24[] = "　";

    if (D_80168143 < 14) {
        u8* src = sp24;
        u8* dst = &D_80168130[D_80168143];

        auPlaySound(66);

        while (*src != 0) {
            *dst++ = *src++;
        }
        D_80168143 += 2;
    } else {
        func_800E2314_A5D6C4();
    }
}

void func_800E2800_A5DBB0(void) {
    if (D_80168143 == 0) {
        D_80168130[D_80168143] = 0;
        D_80168130[D_80168143 + 1] = 0;
        func_800E2314_A5D6C4();
    } else {
        D_80168130[--D_80168143] = 0;
        D_80168130[--D_80168143] = 0;
        auPlaySound(74);
    }
    UIElement_Draw(D_80118110);
    UIElement_SetTextPos(D_80118110, 0, 0);
    UIElement_PrintText(D_80118110, D_80168130);
}

void func_800E28C0_A5DC70(void) {
    u8 sp44[] = "Ｔｏｄｄ";
    u8 sp34[] = "　　　　　　　";
    u8* sp30;
    u8* sp2C;
    u8* sp28;

    sp30 = sp44;
    sp28 = sp34;
    sp2C = D_80168130;
    D_8016814C = 0;
    ohWait(1);

    while (*sp2C != 0) {
        if (*sp2C != *sp28++) {
            break;
        }
        sp2C++;
    }

    if (*sp2C == 0) {
        sp2C = D_80168130;
        while (true) {
            *sp2C++ = *sp30;
            if (*sp30 == 0) {
                break;
            }
            sp30++;
        }
        UIElement_Draw(D_80118110);
        UIElement_SetTextPos(D_80118110, 0, 0);
        UIElement_PrintText(D_80118110, D_80168130);
        auPlaySoundWithParams(96, 0x7FFF, 84, 1.0f, 10);
    }

    setPlayerName((PlayerName*) D_80168130); // todo cast ??
    auPlaySound(66);
}

s32 func_800E2A24_A5DDD4(char* arg0) {
    u8 i = 0;
    char sp4[] = "　";

    while (i < 3) {
        if (sp4[i++] != *arg0++) {
            return 0;
        }
    }
    return 1;
}

void func_800E2A84_A5DE34(char* arg0) {
    u8** temp_v0;
    s16 sp1A;
    SObj* unk_48;

    UIText_SetFont(FONT_12);
    sp1A = UIText_GetStringWidth(D_80168130) + 203;
    unk_48 = D_80168148->data.sobj;
    SET_SPRITE_POS(unk_48->sprite, sp1A, 64);
    if (D_80168143 >= 14 || menu_new_game_CursorY >= 19) {
        if (D_80168143 < 14) {
            D_8016814C = 1;
        } else {
            D_8016814C = 0;
        }
        UIElement_SetState(D_80118114, UI_HIDDEN);
        return;
    }
    temp_v0 = func_800E18B4_A5CC64(D_8016812C);
    arg0[0] = temp_v0[menu_new_game_CursorY * 5 + menu_new_game_CursorX][0];
    arg0[1] = temp_v0[menu_new_game_CursorY * 5 + menu_new_game_CursorX][1];
    arg0[2] = 0;
    if (func_800E2A24_A5DDD4(arg0) != 0) {
        D_8016814C = 1;
        UIElement_SetState(D_80118114, UI_HIDDEN);
    } else {
        D_8016814C = 0;
        UIElement_SetState(D_80118114, UI_NORMAL);
    }
    UIElement_Draw(D_80118114);
    UIElement_SetTextPos(D_80118114, 0, 0);
    UIElement_SetPos(D_80118114, sp1A, 64);
    UIElement_PrintText(D_80118114, arg0);
}

void func_800E2C38_A5DFE8(GObj* arg0) {
    s16 var_s0 = 10;
    s32 var_s1 = 5;

    while (true) {
        var_s0 += var_s1;
        if (var_s0 > 255) {
            var_s0 = 255;
            var_s1 = -5;
        } else if (var_s0 < 120) {
            var_s0 = 120;
            var_s1 = 5;
        }
        if (var_s0 > 160) {
            UIElement_SetSpriteColor(D_80118114, 255, 255, 255, 255);
        } else {
            UIElement_SetSpriteColor(D_80118114, 255, 255, 255, 0);
        }
        ohWait(1);
    }
}

void func_800E2D18_A5E0C8(GObj* arg0) {
    s16 var_s0 = 10;
    s16 var_s2 = 5;
    SObj* unk_48 = arg0->data.sobj;

    while (true) {
        if (D_8016814C == 0) {
            var_s0 = 10;
            var_s2 = 5;
            unk_48->sprite.attr |= SP_HIDDEN;
        } else {
            unk_48->sprite.attr &= ~SP_HIDDEN;
        }

        var_s0 += var_s2;
        if (var_s0 > 255) {
            var_s0 = 255;
            var_s2 = -5;
        } else if (var_s0 < 120) {
            var_s0 = 120;
            var_s2 = 5;
        }
        unk_48->sprite.alpha = var_s0;
        ohWait(1);
    }
}

void func_800E2E00_A5E1B0(void) {
    SObj* unk_48;

    omCreateProcess(omAddGObj(14, NULL, 0, 0x80000000), func_800E2C38_A5DFE8, 0, 1);
    D_8016814C = 0;
    D_80168148 = ohCreateSprite(14, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, &D_80118068_A93418, 0, func_800E2D18_A5E0C8, 1);
    unk_48 = D_80168148->data.sobj;
    unk_48->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    SET_SPRITE_POS(unk_48->sprite, 203, 64);
}

void func_800E2ED0_A5E280(void) {

    func_800E23B0_A5D760();
    func_800E2E00_A5E1B0();
    func_800E2A84_A5DE34(D_80168140);
    while (true) {
        UnkStruct800BEDF8* temp_v0 = func_800AA38C(0);
        s32 temp_v1 = temp_v0->pressedButtons;
        if (temp_v1 & 0xF0000) {
            func_800E2590_A5D940(temp_v0);
            func_800E2A84_A5DE34(D_80168140);
        } else if (temp_v1 & 0x4000) {
            func_800E2800_A5DBB0();
            func_800E2A84_A5DE34(D_80168140);
        } else if (temp_v1 & 0x8000) {
            func_800E270C_A5DABC();
            if (D_80168144 != 2) {
                func_800E2A84_A5DE34(D_80168140);
            }
        } else if (temp_v1 & 0x1000) {
            func_800E2314_A5D6C4();
            func_800E2A84_A5DE34(D_80168140);
        }
        if (D_80168144 == 2) {
            break;
        }
        ohWait(1);
    }
}
