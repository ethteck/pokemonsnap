#include "common.h"
#include "oaks_lab.h"

// TODO: probably remove this when more data is integrated
s32 D_80195D10 = 0;
s32 D_80195D14 = 0;

void func_800E44A0_8A9CC0(void) {
}

s32 func_800E44A8_8A9CC8(UIElement* arg0, s32 arg1) {
    s32 button;
    UnkStruct800BEDF8* var_v0;
    s32 temp_v1;

    button = 0;
    func_8036EB80_842330(0);
    ohWait(1);
    var_v0 = func_800AA38C(0);
    while (!(var_v0->pressedButtons & (A_BUTTON | B_BUTTON))) {
        ohWait(1);
        var_v0 = func_800AA38C(0);
    }
    temp_v1 = var_v0->currentButtons;
    if (temp_v1 & A_BUTTON) {
        button = A_BUTTON;
    }
    if (temp_v1 & B_BUTTON) {
        button = B_BUTTON;
    }
    if (temp_v1 & START_BUTTON) {
        button = START_BUTTON;
    }
    if (arg1 != 0) {
        auPlaySound(0x4D);
    }
    ohWait(1);
    UIElement_Draw(arg0);
    func_8036EB80_842330(1);
    return button;
}

s32 func_800E4578_8A9D98(UIElement* arg0, char** arg1, s32 arg2, bool arg3) {
    s32 temp_t8;
    s32 button;

    for (; *arg1; arg1++) {
        UIElement_Draw(arg0);
        func_8037519C_84894C(arg0, *arg1, getPlayerName());
        if (arg2 == 2 && arg1[1] == 0) {
            return 0;
        }
        if (arg2 == 1) {
            button = func_800E44A8_8A9CC8(arg0, arg3);
        } else {
            button = func_80374F30_8486E0(arg0, arg3);
        }
        if (arg2 == 1 && button == A_BUTTON) {
            return A_BUTTON;
        }
    }

    return 0;
}

void func_800E4674_8A9E94(void) {
}

void func_800E467C_8A9E9C(void) {
    UIElement* temp_v0;

    char* sp54[] = {
        "\\w\\1\\LHello there\\t, %s!\nI'm Oak, the Pokemon professor.",
        NULL,
    };

    char* sp3C[] = {
        "\\2The reason I invited you here\nis \\Mthis PKMN Report.",
        "I'd like for you to take\npictures of Pokemon\nfor the PKMN Report.",
        "H\\3\\Mere on Pokemon Island,\nwild Pokemon can be\nfound everywhere.",
        "T\\4his is my new invention:\nthe \\MZERO-ONE Vehicle. You\ncan take this on your trip.",
        "\\6The ZERO-ONE Vehicle\nconstantly moves toward \\Mthe\nGOAL GATE!",
        NULL,
    };

    char* sp34[] = {
        "Shall I repeat this information?\n\\a Yes, please.\n\\b No, thank you.",
        NULL,
    };

    char* sp2C[] = {
        "\\5I'll teach you how to take\npictures in the first course. I'm\ncounting on you, %s!",
        NULL,
    };

    temp_v0 = func_800E1B40_8A7360();
    func_800E4578_8A9D98(temp_v0, sp54, 0, true);

    while (1) {
        func_800E4578_8A9D98(temp_v0, sp3C, 0, true);
        if (func_800E4578_8A9D98(temp_v0, sp34, 1, false) == 0) {
            break;
        }
        auPlaySound(0x53);
    }

    auPlaySound(0x4D);
    func_800E4578_8A9D98(temp_v0, sp2C, 0, true);
    func_800E1D68_8A7588(0);
    func_800E1D1C_8A753C(0);
}

void func_800E47C0_8A9FE0(void) {
    char* unused;
    char* sp1C[] = {
        "I've been expecting you,\n%s! The Pokemon\nAcademy has officially\n",
        "announced the record for the\nhighest photo score!",
        "Now you can compete to see\nhow many total points you\ncan get.",
        "I have arranged it so that you\ncan see the \\hChallenge Score\\p\nfor each course.",
        "Good luck, %s!\nDo your best to beat all of the\n\\hCHALLENGE SCORES\\p!",
        NULL,
    };
    func_800E4578_8A9D98(func_800E1B40_8A7360(), sp1C, 0, true);
}

void func_800E482C_8AA04C(void) {
    char* unused;
    char* sp1C[] = {
        "I have been waiting for\nyou, %s. I expect\nyou to take good pictures.",
        0x00000000,
    };
    func_800E4578_8A9D98(func_800E1B40_8A7360(), sp1C, 0, true);
}

void func_800E4878_8AA098(void) {
    UIElement* var;
    char* sp1C[] = {
        "Are you going to take\nPokemon pictures?\nGood luck, %s!",
        0x00000000,
    };

    var = func_800E1B40_8A7360();
    func_800E4578_8A9D98(var, sp1C, 0, true);
}

void func_800E48C4_8AA0E4(void) {
    s32 i;

    auPlaySound(0x52);
    UILayout_SetInstantTransition(true);
    UILayout_CreateButtons(func_800E3230_8A8A50());
    UILayout_ShowButton(1, 3);
    UILayout_SetButtonScale(0.1f, 3);

    for (i = 1; i < 30;) {
        UILayout_SetButtonScale(i / 30.0f, 3);
        i++;
        ohWait(1);
    }

    UILayout_SetButtonScale(1.0f, 3);
}

void func_800E4974_8AA194(void) {
    UIElement* sp2C;

    char* sp20[] = {
        "How have you been, %s?\nI have completed part of\nmy research.",
        "This Album is a gift for you!",
        0x00000000,
    };
    char* sp18[] = {
        "You can put any picture in\nthis Album. It's just for you!",
        0x00000000,
    };

    sp2C = func_800E1B40_8A7360();
    func_800E4578_8A9D98(sp2C, sp20, 2, true);
    func_800E48C4_8AA0E4();
    func_80374F30_8486E0(sp2C, true);
    func_800E4578_8A9D98(sp2C, sp18, 0, true);
}

void func_800E4A10_8AA230(void) {
    s32 i;

    auPlaySound(0x52);
    UILayout_SetInstantTransition(true);
    UILayout_CreateButtons(func_800E3230_8A8A50());
    UILayout_ShowButton(1, 2);
    UILayout_SetButtonScale(0.1f, 2);

    for (i = 1; i < 30;) {
        UILayout_SetButtonScale(i / 30.0f, 2);
        i++;
        ohWait(1);
    }

    UILayout_SetButtonScale(1.0f, 2);
}

void func_800E4AC0_8AA2E0(void) {
    UIElement* var;
    char* sp18[] = {
        "I saw the pictures taken\nby %s.",
        "I saved those pictures in\nthe PKMN Report.",
        "I'll help you out once you have\nmore Pokemon pictures.",
        "Good luck, %s!\nOh! I have arranged it so that\nyou can see the PKMN Report.",
        NULL,
    };

    var = func_800E1B40_8A7360();
    func_800E4578_8A9D98(var, sp18, 0, true);
    func_800E4A10_8AA230();
}

void func_800E4B2C_8AA34C(void) {
    UIElement* sp24;
    char* sp1C[] = {
        "\\w\\EWelcome back!\\t",
        0x00000000,
    };
    sp24 = func_800E1B40_8A7360();
    UIElement_Draw(sp24);
    func_8037519C_84894C(sp24, "\\w\\EWelcome back!\\t", getPlayerName());
    ohWait(0x36);
    func_80374F30_8486E0(sp24, false);
}

void func_800E4BA0_8AA3C0(void) {
    UIElement* temp_v0;

    char* sp4C[] = {
        "\\w\\1Here's something to make your\\t\nsearch for PKMN Signs easier!",
        0x00000000,
    };

    char* sp3C[] = {
        "Wouldn't it be great if the\nZERO-ONE moved faster?\n",
        "\\w\\AWell, now you can use \\Mthis\n\\hDash Engine\\p\\t if you want to\ngo faster.\n",
        "It's easy to use. Press \\r\nto make the ZERO-ONE\nmove faster.",
        0x00000000,
    };

    char* sp34[] = {
        "Shall I repeat this information?\n\\a Yes, please.\n\\b No, thank you.",
        0x00000000,
    };

    char* sp2C[] = {
        "First of all, see the\n\\hPKMN Sign\\p page!",
        0x00000000,
    };

    temp_v0 = func_800E1B40_8A7360();
    func_800E4578_8A9D98(temp_v0, sp4C, 0, true);
    while (1) {
        func_800E4578_8A9D98(temp_v0, sp3C, 0, true);
        if (func_800E4578_8A9D98(temp_v0, sp34, 1, false) == 0) {
            break;
        }
        auPlaySound(0x53);
    }

    auPlaySound(0x4D);
    func_800E4578_8A9D98(temp_v0, sp2C, 0, true);
    func_800E1D68_8A7588(0);
}

void func_800E4CCC_8AA4EC(void) {
    UIElement* var;
    char* sp1C[] = {
        "You are doing a fine\njob, %s.\nChoose \xA1\xC9\\hGo to Course\\p.\xA1\xC9",
        0x00000000,
    };

    var = func_800E1B40_8A7360();
    func_800E4578_8A9D98(var, sp1C, 0, true);
}

void func_800E4D18_8AA538(void) {
    UIElement* i;
    char* sp18[] = {
        "%s, you found a split\nin the path! According\nto my research, that split\n",
        "should link to a new course.\nI've also made a link from my\nlab. You should go right away!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp18, 0, true);
}

void func_800E4D6C_8AA58C(void) {
    UIElement* i;
    char* sp18[] = {
        "You finally got all of\nthe \\hPKMN Sign\\p pictures!",
        "\\JHmm... After looking at these\nsix pictures, I've noticed that\nthe Signs are just like the",
        "constellations that can be\nseen from Pokemon Island!",
        "That's the key to this mystery!\nNow it all makes sense!\n\\PIt's the sky!",
        "Rainbow Cloud, floating in the\nsky, is the secret course!",
        "Someone in the clouds must\nhave created the PKMN Signs.",
        "I have made a new path\nto the Rainbow Cloud.",
        "This could prove very important\nfor Pokemon research.\nGood luck, %s!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp18, 0, true);
}

void func_800E4DD4_8AA5F4(void) {
    UIElement* i;
    char* sp18[] = {
        "I've seen your \\hPKMN Sign\\p in\npictures!",
        "\\OWe have solved a Pokemon\nIsland mystery.\nKeep going!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp18, 0, true);
}

void func_800E4E28_8AA648(s32 arg0) {
    UIElement* temp_v0;
    char* sp88[] = {
        "You take pictures at a good\npace. To make your work easier,\n\\Dhere is a present for you.\n",
        "It will come in handy for taking\nPokemon pictures.",
        0x00000000,
    };
    char* sp68[] = {
        "Would you like to be\ncloser with Pokemon?",
        "\\w\\1Then use \\Mthis \\7apple-shaped\\t\n\\hPOKeMON FOOD\\p.",
        "It's easy to use! When you are\nnot focusing your camera,\npress \\a to throw it.",
        "Pokemon in the distance will\nhappily come closer when you\nuse this item.",
        "If you want to throw farther,\nlook up slightly, then throw!\nHere's a hint for you:",
        "Throw some Pokemon Food\nto an \\hELECTRODE that's not\\p\n\\hmoving\\p and see what happens!",
        "Good luck, %s!",
        0x00000000,
    };
    char* sp58[] = {
        "\\w\\1If you see a place where you\nthink Pokemon might be hiding,\nuse \\Mthis \\8\\hPESTER BALL\\p\\t.",
        "It's easy! Press \\b when you\nare not focusing your camera.",
        "This will make hidden Pokemon\ncome out into the open.",
        0x00000000,
    };
    char* sp44[] = {
        "Would you like to see rare\nPokemon poses?",
        "\\w\\1Play \\Mthis \\9\\hPOKe FLUTE\\p\\t to\nmake it happen!\nIt's easy to use!",
        "The \\d C Button allows\nyou to play the\n\\hPoke Flute\\p.",
        "You can listen to different\nmusic by using \\d.\nTry playing it often!",
        0x00000000,
    };
    char* sp3C[] = {
        "Shall I repeat this information?\n\\a Yes, please.\n\\b No, thank you.",
        0x00000000,
    };

    temp_v0 = func_800E1B40_8A7360();
    func_800E4578_8A9D98(temp_v0, sp88, 0, true);

    while (1) {
        switch (arg0) {
            case 0:
                func_800E4578_8A9D98(temp_v0, sp68, 0, true);
                break;
            case 1:
                func_800E4578_8A9D98(temp_v0, sp58, 0, true);
                break;
            case 2:
                func_800E4578_8A9D98(temp_v0, sp44, 0, true);
                break;
        }

        if (func_800E4578_8A9D98(temp_v0, sp3C, 1, false) == 0) {
            break;
        }
        auPlaySound(0x53);
    }

    auPlaySound(0x4D);
    func_800E1D68_8A7588(0);
}

void func_800E502C_8AA84C(void) {
    UIElement* i;
    char* sp18[] = {
        "You have completed the\nPKMN Report!",
        "%s is a genuine Pokemon\nphotographer.\n\\KCongratulations!",
        "I have nothing left to\nteach you.",
        "Listen to your instincts\nand click the shutter when you\nsee something that looks cool.",
        "Pokemon research on this island\nseemed long at first,\nbut it really went by fast.",
        "I appreciate all of your help.\nWell then, see you later!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp18, 0, true);
}

void func_800E50A0_8AA8C0(void) {
    UIElement* i;
    char* sp1C[] = {
        "\\UYou made it, %s!\nI never believed that MEW lived\non this island!",
        "Our PKMN Report now has a\nvery memorable picture.",
        "Thank you, %s.\nThis is all because of your\nhard work.",
        "It was so nice to find a\nphotographer as good as you.",
        "Bye for now, but I'll see you\nlater, %s!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp1C, 0, true);
}

s32 func_800E510C_8AA92C(void) {
    s32 prev = D_80206B50_9CC370;
    D_80206B50_9CC370 = 0;
    return prev;
}

void func_800E5120_8AA940(void) {
    UIElement* sp1C;

    sp1C = func_800E1B40_8A7360();
    func_8036EB80_842330(0);
    UIText_SetPrintDelay(2);
    UIElement_PrintText(sp1C, "Well then, \\Tsee you!");
    UIText_SetPrintDelay(0);
    UIElement_SetTextPos(sp1C, 0, 32);
    UIElement_PrintText(sp1C, "Press \\a or \\b to save.");
    ohWait(1);

    while (!(func_800AA38C(0)->pressedButtons & (A_BUTTON | B_BUTTON))) {
        ohWait(1);
    }

    auPlaySound(0x53);
    UIElement_Draw(sp1C);
    UIElement_SetTextPos(sp1C, 0, 0);
    UIElement_PrintText(sp1C, "Well then, see you later!");
    UIElement_SetTextPos(sp1C, 0, 32);
    UIElement_PrintText(sp1C, "\\eSaving...\\p\n\\hCaution: Do not \"Power Off\"\\p\n\\hor press the \"Reset Button\"!!!\\p");
    auSetBGMVolumeSmooth(0, 0, 30);
    ohWait(0x21);
    if (func_800BF244_5C0E4() != 0) {
        func_800E30B8_8A88D8();
    }
    ohWait(6);
    UIElement_Draw(sp1C);
    func_800A7860(0, 1.0f);
    ohWait(1);

    while (func_800A7460()) {
        ohWait(1);
    }
}

void func_800E5298_8AAAB8(void) {
    char* unused;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 temp_v0;

    sp28 = 0;
    D_80206B50_9CC370 = 0;
    UIText_SetPrintDelay(2);
    if (func_800AAEE8(0x100000) != 0) {
        D_80206B50_9CC370 = 6;
        return;
    }
    if (func_800AAEE8(0x200000) != 0) {
        D_80206B50_9CC370 = 1;
        return;
    }
    if (func_800AAEE8(1) != 0) {
        func_800E467C_8A9E9C();
    }
    if (func_800AAEE8(2) != 0) {
        if (checkPlayerFlag(PFID_14) != 0) {
            func_800E4878_8AA098();
        } else if (checkPlayerFlag(PFID_17) == 0 && checkPlayerFlag(PFID_11) != 0) {
            func_800E47C0_8A9FE0();
            setPlayerFlag(PFID_17, 1);
            if (checkPlayerFlag(PFID_20) != 0) {
                setPlayerFlag(PFID_20, 0);
                setPlayerFlag(PFID_14, 1);
            }
        } else {
            func_800E482C_8AA04C();
        }
    }
    if (func_800AAEE8(8) != 0) {
        setPlayerFlag(PFID_6, 1);
        func_800E4974_8AA194();
        D_80206B50_9CC370 = 6;
    }
    if (func_800AAEE8(0x10) != 0) {
        func_800E4B2C_8AA34C();
    }
    if (func_800AAEE8(0x20) != 0) {
        if (checkPlayerFlag(PFID_7) == 0 && func_800BF864_5C704() != 0) {
            setPlayerFlag(PFID_7, 1);
            func_800E4AC0_8AA2E0();
            D_80206B50_9CC370 = 1;
        } else {
            func_800E4B2C_8AA34C();
        }
    }
    if (func_800AAEE8(0x800) != 0) {
        setPlayerFlag(PFID_HAS_DASH_ENGINE, 1);
        func_800E4BA0_8AA3C0();
        D_80206B50_9CC370 = 1;
    }
    if (D_80206B50_9CC370 != 1 && func_800AAEE8(0x400) != 0) {
        if (func_800C0290_5D130() == 6) {
            func_800E4D6C_8AA58C();
            sp28 = 1;
        } else if (func_800C0290_5D130() == 2 || func_800C0290_5D130() == 4) {
            func_800E4D18_8AA538();
        } else {
            func_800E4CCC_8AA4EC();
        }
    }
    if (sp28 == 0) {
        if (func_800AAEE8(0x1000) != 0) {
            func_800E4DD4_8AA5F4();
        }
        if (func_800AAEE8(0x2000) != 0) {
            func_800E4DD4_8AA5F4();
        }
        if (func_800AAEE8(0x4000) != 0) {
            func_800E4DD4_8AA5F4();
        }
        if (func_800AAEE8(0x8000) != 0) {
            func_800E4DD4_8AA5F4();
        }
        if (func_800AAEE8(0x10000) != 0) {
            func_800E4DD4_8AA5F4();
        }
        if (func_800AAEE8(0x20000) != 0) {
            func_800E4DD4_8AA5F4();
        }
    }
    if (func_800AAEE8(0x80) != 0) {
        setPlayerFlag(PFID_HAS_APPLE, 1);
        func_800E4E28_8AA648(0);
    }
    if (func_800AAEE8(0x100) != 0) {
        setPlayerFlag(PFID_HAS_PESTER_BALL, 1);
        func_800E4E28_8AA648(1);
    }
    if (func_800AAEE8(0x200) != 0) {
        setPlayerFlag(PFID_HAS_FLUTE, 1);
        func_800E4E28_8AA648(2);
    }
    sp24 = func_800AAEE8(0x40);
    sp20 = func_800AAEE8(0x40000);
    sp1C = func_800AAEE8(0x80000);
    temp_v0 = checkPlayerFlag(PFID_14);

    if (sp20 != 0 && sp24 != 0) {
        setPlayerFlag(PFID_11, 1);
        setPlayerFlag(PFID_20, 1);
        func_800E502C_8AA84C();
        func_800E5120_8AA940();
        func_800AAF10();
        func_800AADF0(SCENE_CREDITS_19);
    } else if (sp20 != 0) {
        setPlayerFlag(PFID_11, 1);
        func_800E50A0_8AA8C0();
        func_800E5120_8AA940();
        func_800AAF10();
        func_800AADF0(SCENE_CREDITS_18);
    } else if (sp24 != 0) {
        setPlayerFlag(PFID_14, 1);
        func_800E502C_8AA84C();
        func_800E5120_8AA940();
        func_800AAF10();
        func_800AADF0(SCENE_CREDITS_19);
    } else if (sp1C != 0 && temp_v0 != 0) {
        func_800E50A0_8AA8C0();
        func_800E5120_8AA940();
        func_800AAF10();
        func_800AADF0(SCENE_CREDITS_17);
    }
    UIText_SetPrintDelay(0);
}
