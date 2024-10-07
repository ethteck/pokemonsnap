#include "common.h"
#include "../window/window.h"
#include "gallery.h"

void func_801DCF50_9FAC10(GObj* arg0) {
    s32 sp24;

    while (true) {
        if (D_801EA1F4_A07EB4 != 0) {
            sp24 = contIsPrinterAvailable();
            if (D_801EA200_A07EC0 != sp24) {
                D_801EA1F8_A07EB8 |= 2;
                UILayout_CreateButtons(func_801DF850_9FD510());

                UILayout_DisableButton(contIsPrinterAvailable() ? 0 : 1, 0x20);
            } else {
                D_801EA1F8_A07EB8 &= ~2;
            }
            D_801EA200_A07EC0 = sp24;
            if (sp24 != 0) {
                D_801EA1F8_A07EB8 |= 1;
            } else {
                D_801EA1F8_A07EB8 &= ~1;
            }
        }
        ohWait(1);
    }
}

void func_801DD074_9FAD34(u32 arg0) {
    UNUSED s32 pad;

    D_8023086C_A4E52C->sprite.red = arg0;
    D_8023086C_A4E52C->sprite.green = arg0;
    D_8023086C_A4E52C->sprite.blue = arg0;
}

void func_801DD0AC_9FAD6C(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80230848_A4E508); i++) {
        // TODO: create a macro for setting R/G/B to the same value
        D_80230848_A4E508[i].gobj->data.sobj->sprite.red = D_80230848_A4E508[i].gobj->data.sobj->sprite.green = D_80230848_A4E508[i].gobj->data.sobj->sprite.blue = arg0;
    }

    for (i = 0; i < ARRAY_COUNT(D_80230818_A4E4D8); i++) {
        D_80230818_A4E4D8[i].gobj->data.sobj->sprite.red = D_80230818_A4E4D8[i].gobj->data.sobj->sprite.green = D_80230818_A4E4D8[i].gobj->data.sobj->sprite.blue = arg0;
    }
}

UnkStruct800BEDF8* func_801DD1A8_9FAE68(void) {
    UnkStruct800BEDF8* sp24;

    FocusMark_Show(false);
    func_801DE04C_9FBD0C(-1, -1);
    UIText_SetPrintDelay(0);
    func_801DDCA8_9FB968(13);

    while (true) {
        ohWait(1);
        sp24 = func_800AA38C(0);
        if (sp24->pressedButtons & 0x4000) {
            func_801DDCA8_9FB968(8);
            break;
        }
        if (sp24->pressedButtons & 0x8000) {
            auPlaySoundWithParams(0xA0, 0x7FFF, 0x40, 0.75f, 0);
            func_801DDCA8_9FB968(10);
            break;
        }
    }

    return sp24;
}

void func_801DD270_9FAF30(void) {
    D_801EA1FC_A07EBC = 24;
}

GObj* func_801DD28C_9FAF4C(s32 arg0) {
    GObj* gobj;
    SObj* sobj;
    s32 x;
    s32 y;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    x = ((arg0 % 3) * 66) + 104;
    y = ((arg0 / 3) * 55) + 53;

    gobj = func_80371C68_845418(NULL, 6, &D_801E82A0_A05F60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = x;
    sobj->sprite.y = y;
    D_80230818_A4E4D8[arg0].gobj = gobj;

    sobj = func_80371E68_845618(sobj, &D_801E82A0_A05F60);
    sobj->sprite.x = 54;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 41;

    sobj = func_80371DC0_845570(sobj, &D_801EA1B0_A07E70);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_80230818_A4E4D8[arg0].sobj = sobj;

    bitmap = (Bitmap*) func_8036A194_83D944(0x10);
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (x = 0xFD8; x > 0; src++, dest++, x--) {
        *dest = *src;
    }

    return gobj;
}

GObj* func_801DD4C4_9FB184(s32 arg0) {
    GObj* gobj;
    SObj* sobj;
    s32 x;
    s32 y;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    x = ((arg0 % 2) * 66) + 137;
    y = ((arg0 / 2) * 55) + 53;

    gobj = func_80371C68_845418(NULL, 6, &D_801E82A0_A05F60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = x;
    sobj->sprite.y = y;
    D_80230848_A4E508[arg0].gobj = gobj;

    sobj = func_80371E68_845618(sobj, &D_801E82A0_A05F60);
    sobj->sprite.x = 0x36;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0x29;

    sobj = func_80371DC0_845570(sobj, &D_801EA1B0_A07E70);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_80230848_A4E508[arg0].sobj = sobj;

    bitmap = (Bitmap*) func_8036A194_83D944(0x10);
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (x = 0xFD8; x > 0; src++, dest++, x--) {
        *dest = *src;
    }

    return gobj;
}

void func_801DD708_9FB3C8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_801DD4C4_9FB184(i);
    }

    for (i = 0; i < 6; i++) {
        func_801DD28C_9FAF4C(i);
    }
}

void func_801DD768_9FB428(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80230848_A4E508); i++) {
        if (arg0 == 0) {
            D_80230848_A4E508[i].gobj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_80230848_A4E508[i].gobj->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }

    for (i = 0; i < ARRAY_COUNT(D_80230818_A4E4D8); i++) {
        if (arg0 == 1) {
            D_80230818_A4E4D8[i].gobj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_80230818_A4E4D8[i].gobj->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_801DD860_9FB520(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80230848_A4E508); i++) {
        if (func_801E0F88_9FEC48(i)) {
            D_80230848_A4E508[i].gobj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_80230848_A4E508[i].gobj->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_801DD8F8_9FB5B8(s32 arg0, s32 arg1) {
    s32 i;
    s32 sp48;
    char sp28[0x20];

    switch (arg0) {
        case 0:
            for (i = 0; i < ARRAY_COUNT(D_80230848_A4E508); i++) {
                func_80374714_847EC4(func_801E0F88_9FEC48(i), &D_80230848_A4E508[i].sobj->sprite);
            }
            func_801DD768_9FB428(0);
            break;
        case 1:
            D_8023088C_A4E54C = arg1;
            sp48 = arg1 * 6;
            func_801DD768_9FB428(1);
            for (i = 0; i < ARRAY_COUNT(D_80230818_A4E4D8); sp48++, i++) {
                if (func_80374714_847EC4(func_801E0FE4_9FECA4(sp48), &D_80230818_A4E4D8[i].sobj->sprite) != 0) {
                    D_80230818_A4E4D8[i].gobj->data.sobj->sprite.attr |= SP_HIDDEN;
                } else {
                    D_80230818_A4E4D8[i].gobj->data.sobj->sprite.attr &= ~SP_HIDDEN;
                }
            }
            break;
        case 2:
            D_80230888_A4E548 = arg1;
            func_801DD768_9FB428(1);
            for (i = 0, sp48 = arg1 * 6; i < ARRAY_COUNT(D_80230818_A4E4D8); sp48++, i++) {
                if (sp48 > 68 || (func_80374714_847EC4(func_801E0FAC_9FEC6C(sp48), &D_80230818_A4E4D8[i].sobj->sprite) != 0)) {
                    D_80230818_A4E4D8[i].gobj->data.sobj->sprite.attr |= SP_HIDDEN;
                } else {
                    D_80230818_A4E4D8[i].gobj->data.sobj->sprite.attr &= ~SP_HIDDEN;
                }
            }
            break;
    }

    if (arg0 == 0) {
        UIElement_SetState(D_80230884_A4E544, UI_HIDDEN);
    } else {
        UIElement_Draw(D_80230884_A4E544);
        UIText_SetPrintDelay(0);
        UIText_SetFont(FONT_12);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_SetTextPos(D_80230884_A4E544, 0, 0);
        UIElement_PrintText(D_80230884_A4E544, "  \\i−\\g      \\i−\\g  ");
        sprintf(sp28, "%d", arg1 + 1);
        UIElement_SetTextPos(D_80230884_A4E544, 30 - (UIText_GetStringWidth(sp28) / 2), 0);
        UIElement_PrintText(D_80230884_A4E544, sp28);
        UIElement_SetState(D_80230884_A4E544, UI_NORMAL);
    }
}

void func_801DDC50_9FB910(s32 arg0) {
    func_80374714_847EC4(func_801E0F88_9FEC48(arg0), &D_80230848_A4E508[arg0].sobj->sprite);
}

void func_801DDCA8_9FB968(s32 arg0) {
    s32 i;
    s32 sp30;
    s32 bestShotID;
    s32 sp28;

    UIElement_Draw(D_80230880_A4E540);
    UIElement_SetTextPos(D_80230880_A4E540, 0, 0);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);

    switch (arg0) {
        case 0:
            sp28 = -1;
            sp30 = func_800BF864_5C704();
            if (func_800BF3D4_5C274(PokemonID_1004)) {
                sp30++;
            }
            if (func_800BF3D4_5C274(PokemonID_1010)) {
                sp30++;
            }
            if (func_800BF3D4_5C274(PokemonID_KOFFING_SMOKE)) {
                sp30++;
            }
            if (func_800BF3D4_5C274(PokemonID_1022)) {
                sp30++;
            }
            if (func_800BF3D4_5C274(PokemonID_1018)) {
                sp30++;
            }
            if (func_800BF3D4_5C274(PokemonID_1035)) {
                sp30++;
            }
            for (i = PokemonID_BULBASAUR; i <= POKEDEX_MAX; i++) {
                if (func_800BF3D4_5C274(i) && sp28 < func_800BF818_5C6B8(i)) {
                    sp28 = func_800BF818_5C6B8(i);
                    bestShotID = i;
                }
            }
            func_8037519C_84894C(D_80230880_A4E540, "Choosing from the PKMN\nReport? You took %s pictures.\n%s's your best shot.",
                                 func_8037501C_8487CC("%2d", sp30), getPokemonName(bestShotID));
            break;
        case 1:
            switch (func_801E0F50_9FEC10()) {
                case 0:
                    UIElement_PrintText(D_80230880_A4E540, "Go to the course and take a lot\nof pictures!\nFile them in your Album.");
                    break;
                case 1:
                    func_8037519C_84894C(D_80230880_A4E540, "Are you choosing from the\nAlbum? There is a total of\n%d saved picture.", 1, "");
                    break;
                default:
                    func_8037519C_84894C(D_80230880_A4E540, "Are you choosing from the\nAlbum? There are a total of\n%d saved picture%s.", func_801E0F50_9FEC10(), "s");
                    break;
            }
            break;
        case 2:
            UIElement_PrintText(D_80230880_A4E540, "Arrange the photos\nany way you want!\n");
            break;
        case 3:
            UIElement_PrintText(D_80230880_A4E540, "Enlarge your favorite picture.");
            break;
        case 11:
            UIElement_PrintText(D_80230880_A4E540, "Choose the picture you'd like\nto enlarge with the Control\nStick. Press \\a to decide.");
            break;
        case 12:
            UIElement_PrintText(D_80230880_A4E540, "Where shall I put this?\nPress \\a to decide.");
            break;
        case 13:
            UIElement_PrintText(D_80230880_A4E540, "How's this?\n\\a Cool! 　\\b Not so good...");
            break;
        case 8:
            UIElement_PrintText(D_80230880_A4E540, "Where shall I put this?\nPress \\a to decide.");
            break;
        case 9:
            UIElement_PrintText(D_80230880_A4E540, "What an amazing picture!\n\\a Continue.   \\b I'm done.\n\\z Shows the full picture.");
            break;
        case 10:
            UIElement_PrintText(D_80230880_A4E540, "Choose ”\\hSave\\p” to return to\nthe Title Screen.");
            break;
        case 6:
            UIElement_PrintText(D_80230880_A4E540, "If you like these pictures, please\nmake sure a print credit exists\nthen press \\a to print.");
            break;
        default:
            UIElement_PrintText(D_80230880_A4E540, "Return to the Title Screen\nby saving.");
            break;
    }
}

void func_801DE04C_9FBD0C(s32 arg0, s32 arg1) {
    SObj* sobj;

    sobj = D_80230870_A4E530->data.sobj;
    if (arg0 < 0 || arg1 < 0) {
        sobj->sprite.attr |= SP_HIDDEN;
    } else {
        SET_SPRITE_POS(sobj->sprite, arg0, arg1);
        sobj->sprite.attr &= ~SP_HIDDEN;
    }
}

GObj* func_801DE0B8_9FBD78(void) {
    GObj* gobj;
    SObj* sobj;
    s32 i;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    gobj = func_80371C68_845418(NULL, 6, &D_801E82A0_A05F60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 0;
    sobj->sprite.y = 0;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = func_80371E68_845618(sobj, &D_801E82A0_A05F60);
    sobj->sprite.x = 54;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_801E83D0_A06090);
    sobj->sprite.x = 2;
    sobj->sprite.y = 41;

    sobj = func_80371DC0_845570(sobj, &D_801EA1B0_A07E70);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_80230870_A4E530 = gobj;
    D_80230874_A4E534 = sobj;

    bitmap = (Bitmap*) func_8036A194_83D944(0x10);
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (i = 0xFD8; i > 0; src++, dest++, i--) {
        *dest = *src;
    }

    return gobj;
}

void func_801DE290_9FBF50(s32 arg0) {
    if (arg0) {
        D_80230870_A4E530->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_80230870_A4E530->data.sobj->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DE2E0_9FBFA0(PhotoData* arg0) {
    func_80374714_847EC4(arg0, &D_80230874_A4E534->sprite);
}

void func_801DE318_9FBFD8(s32 arg0) {
    switch (arg0) {
        case 0:
            D_8023086C_A4E52C->sprite = D_801E8FB0_A06C70;
            break;
        case 1:
            D_8023086C_A4E52C->sprite = D_801E8890_A06550;
            break;
        case 2:
            D_8023086C_A4E52C->sprite = D_801E8D50_A06A10;
            break;
    }

    D_80230868_A4E528->data.sobj->unk_58 = NULL;
    D_80230868_A4E528->data.sobj->unk_5C = NULL;

    D_80230868_A4E528->data.sobj->sprite.width = SCREEN_WIDTH;
    D_80230868_A4E528->data.sobj->sprite.height = SCREEN_HEIGHT;
    D_80230868_A4E528->data.sobj->sprite.istep = 0;
}
void func_801DE4A0_9FC160(void) {
    s32 i;

    for (i = 10; i >= 0; i--) {
        func_801DD0AC_9FAD6C((i * 0xFF) / 10);
        func_801DD074_9FAD34((i * 0xFF) / 10);
        ohWait(1);
    }
    func_801DD074_9FAD34(0);
    func_801DD0AC_9FAD6C(0);
}

void func_801DE538_9FC1F8(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        func_801DD074_9FAD34((i * 0xFF) / 10);
        func_801DD0AC_9FAD6C((i * 0xFF) / 10);
        ohWait(1);
    }

    func_801DD074_9FAD34(0xFF);
    func_801DD0AC_9FAD6C(0xFF);
}

void func_801DE5D0_9FC290(s32 arg0) {
    func_801DE4A0_9FC160();
    UIElement_Draw(D_8023087C_A4E53C);
    UIElement_SetTextPos(D_8023087C_A4E53C, 0, 0);

    switch (arg0) {
        case 0:
            func_801DE318_9FBFD8(0);
            func_801DD8F8_9FB5B8(0, 0);
            UIText_SetShadowOffset(1);
            UIText_SetSpacing(-1, 3);
            UIElement_SetTextPos(D_8023087C_A4E53C, (108 - UIText_GetStringWidth("Gallery")) / 2, 0);
            UIElement_PrintText(D_8023087C_A4E53C, "Gallery");
            break;
        case 1:
            func_801DE318_9FBFD8(1);
            func_801DD8F8_9FB5B8(1, D_8023088C_A4E54C);
            UIText_SetShadowOffset(1);
            UIText_SetSpacing(-1, 3);
            UIText_SetFont(FONT_12);
            UIElement_SetTextPos(D_8023087C_A4E53C, (108 - UIText_GetStringWidth("PKMN Album")) / 2, 0);
            UIElement_PrintText(D_8023087C_A4E53C, "PKMN Album");
            break;
        case 2:
            func_801DE318_9FBFD8(2);
            func_801DD8F8_9FB5B8(2, D_80230888_A4E548);
            UIText_SetShadowOffset(1);
            UIText_SetSpacing(-1, 3);
            UIText_SetFont(FONT_12);
            UIElement_SetTextPos(D_8023087C_A4E53C, (108 - UIText_GetStringWidth("PKMN Report")) / 2, 0);
            UIElement_PrintText(D_8023087C_A4E53C, "PKMN Report");
            break;
    }

    func_801DE538_9FC1F8();
    UILayout_ShowHeaderElement(HEADER_TITLE);
    ohWait(30);
    UIElement_SetState(D_8023087C_A4E53C, UI_NORMAL);
}

void func_801DE804_9FC4C4(void) {
    GObj* sp1C;

    for (sp1C = omGObjListHead[LINK_18]; sp1C != NULL; sp1C = sp1C->next) {
        ohPauseObjectProcesses(sp1C);
    }
    for (sp1C = omGObjListHead[LINK_17]; sp1C != NULL; sp1C = sp1C->next) {
        ohPauseObjectProcesses(sp1C);
    }
}

void func_801DE87C_9FC53C(void) {
    UnkStruct800BEDF8* sp54;
    GObj* sp50;
    GObj* sp4C;
    OMCamera* cam;
    UNUSED s32 pad;
    s32 sp40;
    s32 sp3C;
    u8 sp3B;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    GObj* sp28;

    sp3C = 1;
    sp34 = 30;
    sp30 = 40;
    sp2C = 5;

    func_801DC920_9FA5E0(&sp50, &sp4C);
    sp28 = omGObjListHead[10];
    while (sp28 != NULL) {
        if (sp28->id == 0x200) {
            sp50 = sp28;
            break;
        }
        sp28 = sp28->next;
    }
    cam = sp4C->data.cam;
    sp40 = 0;
    sp3B = 0;
    UIElement_SetState(D_8023087C_A4E53C, UI_HIDDEN);
    UILayout_SetHeaderFlags(0);
    FocusMark_Show(false);
    UILayout_HideButtons();
    UILayout_WaitPanelTransitionComplete();
    func_800A7860(0, 1.0f);
    ohWait(30);
    func_8009FA68(cam, func_801E0F88_9FEC48(sp3B));
    func_801DE804_9FC4C4();

    while (func_800A7460() != 0) {
        ohWait(1);
    }

    sp50->flags |= GOBJ_FLAG_HIDDEN;
    sp4C->flags &= ~GOBJ_FLAG_HIDDEN;
    func_801DD074_9FAD34(0);
    func_801DD0AC_9FAD6C(0);
    func_801DDCA8_9FB968(9);
    func_800A7860(1, 1.0f);

    while (func_800A7460()) {
        ohWait(1);
    }

    if (!sp40) {
        do {
        loop_9:
            ohWait(1);
            sp54 = func_800AA38C(0);
            if (D_801EA204_A07EC4 != 0 && --D_80230810_A4E4D0 == 0) {

            } else if (sp54->pressedButtons & 0x8000) {
                auPlaySound(0x4B);
                D_801EA204_A07EC4 = 0;
                ;
            } else if (sp54->pressedButtons & 0x4000) {
                auPlaySound(0x4D);
                D_801EA204_A07EC4 = 0;
                sp40 = true;
                ;
            } else {
                if (sp54->pressedButtons & 0x2000) {
                    sp3C ^= 1;
                    if (sp3C != 0) {
                        auPlaySound(0x60);
                        UIFrame_Show(D_80230878_A4E538, true);
                        UIFrame_ShowBackground(D_80230878_A4E538, true);
                        UIElement_SetState(D_80230880_A4E540, UI_NORMAL);
                    } else {
                        auPlaySound(0x4A);
                        UIFrame_Show(D_80230878_A4E538, false);
                        UIFrame_ShowBackground(D_80230878_A4E538, false);
                        UIElement_SetState(D_80230880_A4E540, UI_HIDDEN);
                    }
                }

                if (sp54->pressedButtons & 4 && D_801EA204_A07EC4 > 0) {
                    sp3B = (sp3B - 1) % 4;
                    auPlaySound(0x43);
                    D_801EA204_A07EC4--;
                    ;
                } else if ((sp54->pressedButtons & 8) && D_801EA204_A07EC4 < 5) {
                    auPlaySound(0x42);
                    D_801EA204_A07EC4++;
                    ;

                } else {
                    goto loop_9; // TODO remove
                }
            }

            if (!sp40) {
                sp3B = (sp3B + 1) % 4;
                sp4C->flags |= GOBJ_FLAG_HIDDEN;
                gtlWaitAllGfxTasksDone();
                func_8009FA68(cam, func_801E0F88_9FEC48(sp3B));
                func_801DE804_9FC4C4();
                sp4C->flags &= ~GOBJ_FLAG_HIDDEN;
                D_80230810_A4E4D0 = D_801EA204_A07EC4 != 0 ? (sp30 * sp2C) / D_801EA204_A07EC4 : 0;
            }
        } while (!sp40);
    }

    func_800A7860(0, 1.0f);

    while (func_800A7460()) {
        ohWait(1);
    }

    UIFrame_Show(D_80230878_A4E538, true);
    UIFrame_ShowBackground(D_80230878_A4E538, true);
    UIElement_SetState(D_80230880_A4E540, UI_NORMAL);
    sp4C->flags |= GOBJ_FLAG_HIDDEN;
    sp50->flags &= ~GOBJ_FLAG_HIDDEN;
    func_801DDCA8_9FB968(10);
    func_801DD074_9FAD34(0xFF);
    func_801DD0AC_9FAD6C(0xFF);
    func_800A7860(1, 1.0f);

    while (func_800A7460()) {
        ohWait(1);
    }

    ohWait(1);
    UILayout_ShowHeaderElement(HEADER_TITLE);
    UILayout_CreateButtons(func_801DF850_9FD510());
    UILayout_DisableButton(contIsPrinterAvailable() ? 0 : 1, 0x20);
    ohWait(18);
    UIElement_SetState(D_8023087C_A4E53C, UI_NORMAL);
    UILayout_WaitPanelTransitionComplete();
    FocusMark_Show(true);
    func_801DDCA8_9FB968(10);
}

void func_801DEE88_9FCB48(void) {
    s32 sp2C;
    GObj* sp28;

    if (D_801EA1F4_A07EB4 != 0 && contIsPrinterAvailable()) {
        FocusMark_Show(false);
        UILayout_DisableButton(1, 0x20);
        UIElement_Draw(D_80230880_A4E540);
        UIElement_SetTextPos(D_80230880_A4E540, 0, 32);
        UIElement_PrintText(D_80230880_A4E540, "\\eNow Saving...");
        if (func_801E1504_9FF1C4(1) != 0) {
            sp28 = func_80371D14_8454C4(NULL, 6, &D_801E80E8_A05DA8);
            sp28->data.sobj->sprite.x = 40;
            sp28->data.sobj->sprite.y = 92;
            auSetBGMVolumeSmooth(0, 0x3F80, 0x3C);

            while (true) {
                ohWait(1);
            }
        }

        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }

        contPrinterSendCommand(0x5A);
        ohWait(1);

        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }

        auSetBGMVolumeSmooth(0, 0x7F00, 30);
        ohWait(32);
        UILayout_DisableButton(contIsPrinterAvailable() ? 0 : 1, 0x20);
        if (contIsPrinterAvailable()) {
            sp2C = 6;
            func_801DDCA8_9FB968(sp2C);
        } else {
            sp2C = 7;
            func_801DDCA8_9FB968(sp2C);
            auPlaySound(0x41);
        }
        FocusMark_Show(true);
    }
}

void func_801DF078_9FCD38(GObj* arg0) {
    s32 pad[2];
    s32 i;
    UIFrame* sp38;
    UIElement* sp34;
    ucolor sp30;
    GObj* gobj;

    UILayout_Init();
    FocusMark_Create();
    func_801E1384_9FF044();
    FocusMark_Show(false);
    D_801EA1F4_A07EB4 = 0;
    func_801DD708_9FB3C8();
    func_801DD8F8_9FB5B8(0, 0);
    func_801DD0AC_9FAD6C(0);
    func_801DE0B8_9FBD78();
    func_801DE290_9FBF50(0);
    sp34 = UIElement_Create(170, 153, 60, 18, UI_FLAG_32BIT);
    UIElement_SetColor(sp34, UI_FOREGROUND, 0, 0, 0, 255);
    UIElement_SetColor(sp34, UI_BACKGROUND, 0, 0, 0, 0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_DrawBackground(sp34);
    UIElement_SetFont(sp34, FONT_12);
    UIElement_Draw(sp34);
    UIElement_PrintText(sp34, "\\i−\\g   \\i−\\g");
    UIElement_SetState(sp34, UI_HIDDEN);
    D_80230884_A4E544 = sp34;
    sp38 = UIFrame_Create();
    UIFrame_SetStyle(sp38, FRAME_STYLE_1);
    D_80230878_A4E538 = sp38;
    UIFrame_GetBackgroundColor(sp38, &sp30);
    UIFrame_SetPos(sp38, 184, 320);
    UIFrame_Show(sp38, false);
    sp34 = UIElement_Create(146, 22, 108, 16, 0);
    UIElement_SetColor(sp34, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp34, UI_BACKGROUND, 218, 108, 0, 0);
    UIElement_DrawBackground(sp34);
    UIElement_SetFont(sp34, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    UIElement_SetTextPos(sp34, (108 - UIText_GetStringWidth("Gallery")) / 2, 0);
    UIElement_PrintText(sp34, "Gallery");
    UIElement_SetState(sp34, UI_HIDDEN);
    D_8023087C_A4E53C = sp34;
    sp34 = UIElement_Create(104, 173, 192, 47, 0);
    UIElement_SetColor(sp34, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp34, UI_BACKGROUND, sp30.r, sp30.g, sp30.b, 255);
    UIElement_DrawBackground(sp34);
    UIElement_SetState(sp34, UI_HIDDEN);
    D_80230880_A4E540 = sp34;
    UILayout_SetHeaderFlags(0);
    ohWait(1);

    for (i = 0; i < 20; i++) {
        func_801DD074_9FAD34((i * 0xFF) / 20);
        func_801DD0AC_9FAD6C((i * 0xFF) / 20);
        ohWait(1);
    }

    func_801DD0AC_9FAD6C(0xFF);
    func_801DD074_9FAD34(0xFF);
    UIFrame_FadeIn(sp38, FRAME_STYLE_1);
    UIElement_SetState(sp34, UI_NORMAL);
    UIText_SetPrintDelay((0, 0));
    UIElement_SetFont(sp34, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    UIElement_SetFont(sp34, FONT_12);
    UIText_SetPrintDelay(0);
    UILayout_ShowHeaderElement(HEADER_TITLE);
    UILayout_ShowPanel(true);
    ohWait(30);
    UIElement_SetState(D_8023087C_A4E53C, UI_NORMAL);
    UILayout_CreateButtons(func_801DF850_9FD510());

    if (func_801E0F50_9FEC10() == 0) {
        UILayout_DisableButton(1, 3);
    }

    UILayout_DisableButton(contIsPrinterAvailable() ? 0 : 1, 0x20);
    UILayout_WaitPanelTransitionComplete();
    D_801EA1F4_A07EB4 = 1;

    if (D_80230890_A4E550 != 0) {
        UIElement_SetTextPos(D_80230880_A4E540, 0, 0);
        func_8037519C_84894C(D_80230880_A4E540, "Pick your four best shots!");
        func_80374F30_8486E0(D_80230880_A4E540, true);
        UIElement_SetTextPos(D_80230880_A4E540, 0, 0);
        func_8037519C_84894C(D_80230880_A4E540, "Choose your favorite shots\nfrom the Report and Album.");
        func_80374F30_8486E0(D_80230880_A4E540, true);
        func_801DDCA8_9FB968(0);
        FocusMark_SetTargetPos(0x16, 0x1D);
    } else {
        func_801DDCA8_9FB968(0xA);
        FocusMark_SetTargetSize(0x3E, 0xC);
        FocusMark_SetTargetPos(0x16, 0x65);
    }

    FocusMark_Show(true);
    UIText_SetPrintDelay((0, 0));

    while (true) {
        func_801E0DEC_9FEAAC();
        if (D_801EA1FC_A07EBC != 0) {
            func_801E1504_9FF1C4(0);
        } else {
            UIElement_Draw(D_80230880_A4E540);
            UIElement_SetTextPos(D_80230880_A4E540, 0, 32);
            UIElement_PrintText(D_80230880_A4E540, "\\eNow Saving...");
            if (func_801E1504_9FF1C4(1) != 0) {
                gobj = func_80371D14_8454C4(NULL, 6, &D_801E80E8_A05DA8);
                gobj->data.sobj->sprite.x = 40;
                gobj->data.sobj->sprite.y = 92;
                auSetBGMVolumeSmooth(0, 0x3F80, 60);

                while (true) {
                    ohWait(1);
                }
            }
        }

        FocusMark_Show(false);
        UIElement_Delete(D_80230880_A4E540);
        UIFrame_FadeOut(D_80230878_A4E538);
        UILayout_SetHeaderFlags(0);
        UIElement_Delete(D_8023087C_A4E53C);
        UIElement_Delete(D_80230884_A4E544);
        UILayout_HideButtons();
        UILayout_WaitPanelTransitionComplete();

        if (D_801EA1FC_A07EBC != 24) {
            for (i = 30; i >= 0; i--) {
                func_801DD0AC_9FAD6C((s32) (i * 0xFF) / 30);
                func_801DD074_9FAD34((s32) (i * 0xFF) / 30);
                ohWait(1);
            }
        }

        func_801DD074_9FAD34(0);
        func_801DD0AC_9FAD6C(0);
        UILayout_ShowPanel(false);
        func_80374D20_8484D0();
        if (D_801EA1FC_A07EBC != 0) {
            func_800AADF0(SCENE_24);
        } else {
            func_800AADF0(SCENE_MAIN_MENU);
        }
        ohWait(1);
    }
}

void func_801DF788_9FD448(void) {
    GObj* obj;
    SObj* sobj;

    D_80230890_A4E550 = func_801DC904_9FA5C4();
    func_800A85E8(func_801DF078_9FCD38, LINK_6, DL_LINK_0, NULL);
    func_800A85E8(func_801DCF50_9FAC10, LINK_6, DL_LINK_0, NULL);
    obj = func_80371D14_8454C4(NULL, 6, &D_801E8FB0_A06C70);
    sobj = obj->data.sobj;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80230868_A4E528 = obj;
    D_8023086C_A4E52C = sobj;
    func_801DD074_9FAD34(0);
}
