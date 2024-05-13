#include "common.h"
#include "unk_end_level_3.h"

// TODO: probably remove this when more data is integrated
s32 D_80195D10 = 0;
s32 D_80195D14 = 0;

void func_800E44A0_8A9CC0(void) {
}

s32 func_800E44A8_8A9CC8(UnkSnowHerring* arg0, s32 arg1) {
    s32 sp1C;
    UnkStruct800BEDF8* var_v0;
    s32 temp_v1;

    sp1C = 0;
    func_8036EB80_842330(0);
    ohWait(1);
    var_v0 = func_800AA38C(0);
    while (!(var_v0->unk_18 & 0xC000)) {
        ohWait(1);
        var_v0 = func_800AA38C(0);
    }
    temp_v1 = var_v0->unk_14;
    if (temp_v1 & 0x8000) {
        sp1C = 0x8000;
    }
    if (temp_v1 & 0x4000) {
        sp1C = 0x4000;
    }
    if (temp_v1 & 0x1000) {
        sp1C = 0x1000;
    }
    if (arg1 != 0) {
        auPlaySound(0x4DU);
    }
    ohWait(1);
    func_8036A8E4_83E094(arg0);
    func_8036EB80_842330(1);
    return sp1C;
}

s32 func_800E4578_8A9D98(UnkSnowHerring* arg0, char** arg1, s32 arg2, s32 arg3) {
    s32 temp_t8;
    s32 var_v0;

    for (; *arg1; arg1++) {
        func_8036A8E4_83E094(arg0);
        func_8037519C_84894C(arg0, *arg1, get_player_name());
        if (arg2 == 2 && arg1[1] == 0) {
            return 0;
        }
        if (arg2 == 1) {
            var_v0 = func_800E44A8_8A9CC8(arg0, arg3);
        } else {
            var_v0 = func_80374F30_8486E0(arg0, arg3);
        }
        if (arg2 == 1 && var_v0 == 0x8000) {
            return 0x8000;
        }
    }

    return 0;
}

void func_800E4674_8A9E94(void) {
}

void func_800E467C_8A9E9C(void) {
    UnkSnowHerring* temp_v0;

    char* sp54[] = {
        "\\w\\1\\LHello there\\t, %s!\nI'm Oak, the Pokεmon professor.",
        NULL,
    };

    char* sp3C[] = {
        "\\2The reason I invited you here\nis \\Mthis PKMN Report.",
        "I'd like for you to take\npictures of Pokεmon\nfor the PKMN Report.",
        "H\\3\\Mere on Pokεmon Island,\nwild Pokεmon can be\nfound everywhere.",
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
    func_800E4578_8A9D98(temp_v0, sp54, 0, 1);

    while (1) {
        func_800E4578_8A9D98(temp_v0, sp3C, 0, 1);
        if (!func_800E4578_8A9D98(temp_v0, sp34, 1, 0)) {
            break;
        }
        auPlaySound(0x53);
    }

    auPlaySound(0x4D);
    func_800E4578_8A9D98(temp_v0, sp2C, 0, 1);
    func_800E1D68_8A7588(0);
    func_800E1D1C_8A753C(0);
}

void func_800E47C0_8A9FE0(void) {
    char* unused;
    char* sp1C[] = {
        "I've been expecting you,\n%s! The Pokεmon\nAcademy has officially\n",
        "announced the record for the\nhighest photo score!",
        "Now you can compete to see\nhow many total points you\ncan get.",
        "I have arranged it so that you\ncan see the \\hChallenge Score\\p\nfor each course.",
        "Good luck, %s!\nDo your best to beat all of the\n\\hCHALLENGE SCORES\\p!",
        NULL,
    };
    func_800E4578_8A9D98(func_800E1B40_8A7360(), sp1C, 0, 1);
}

void func_800E482C_8AA04C(void) {
    char* unused;
    char* sp1C[] = {
        "I have been waiting for\nyou, %s. I expect\nyou to take good pictures.",
        0x00000000,
    };
    func_800E4578_8A9D98(func_800E1B40_8A7360(), sp1C, 0, 1);
}

void func_800E4878_8AA098(void) {
    UnkSnowHerring* var;
    char* sp1C[] = {
        "Are you going to take\nPokεmon pictures?\nGood luck, %s!",
        0x00000000,
    };

    var = func_800E1B40_8A7360();
    func_800E4578_8A9D98(var, sp1C, 0, 1);
}

void func_800E48C4_8AA0E4(void) {
    s32 i;

    auPlaySound(0x52U);
    func_803705F0_843DA0(1);
    func_80370C34_8443E4(func_800E3230_8A8A50());
    func_80370900_8440B0(1, 3);
    func_80370990_844140(0.1f, 3);

    for (i = 1; i < 30;) {
        func_80370990_844140(i / 30.0f, 3);
        i++;
        ohWait(1);
    }

    func_80370990_844140(1.0f, 3);
}

void func_800E4974_8AA194(void) {
    UnkSnowHerring* sp2C;

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
    func_800E4578_8A9D98(sp2C, sp20, 2, 1);
    func_800E48C4_8AA0E4();
    func_80374F30_8486E0(sp2C, 1);
    func_800E4578_8A9D98(sp2C, sp18, 0, 1);
}

void func_800E4A10_8AA230(void) {
    s32 i;

    auPlaySound(0x52);
    func_803705F0_843DA0(1);
    func_80370C34_8443E4(func_800E3230_8A8A50());
    func_80370900_8440B0(1, 2);
    func_80370990_844140(0.1f, 2);

    for (i = 1; i < 30;) {
        func_80370990_844140(i / 30.0f, 2);
        i++;
        ohWait(1);
    }

    func_80370990_844140(1.0f, 2);
}

void func_800E4AC0_8AA2E0(void) {
    UnkSnowHerring* var;
    char* sp18[] = {
        "I saw the pictures taken\nby %s.",
        "I saved those pictures in\nthe PKMN Report.",
        "I'll help you out once you have\nmore Pokεmon pictures.",
        "Good luck, %s!\nOh! I have arranged it so that\nyou can see the PKMN Report.",
        NULL,
    };

    var = func_800E1B40_8A7360();
    func_800E4578_8A9D98(var, sp18, 0, 1);
    func_800E4A10_8AA230();
}

void func_800E4B2C_8AA34C(void) {
    UnkSnowHerring* sp24;
    char* sp1C[] = {
        "\\w\\EWelcome back!\\t",
        0x00000000,
    };
    sp24 = func_800E1B40_8A7360();
    func_8036A8E4_83E094(sp24);
    func_8037519C_84894C(sp24, "\\w\\EWelcome back!\\t", get_player_name());
    ohWait(0x36);
    func_80374F30_8486E0(sp24, 0);
}

void func_800E4BA0_8AA3C0(void) {
    UnkSnowHerring* temp_v0;

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
    func_800E4578_8A9D98(temp_v0, sp4C, 0, 1);
    while (1) {
        func_800E4578_8A9D98(temp_v0, sp3C, 0, 1);
        if (!func_800E4578_8A9D98(temp_v0, sp34, 1, 0)) {
            break;
        }
        auPlaySound(0x53);
    }

    auPlaySound(0x4DU);
    func_800E4578_8A9D98(temp_v0, sp2C, 0, 1);
    func_800E1D68_8A7588(0);
}

void func_800E4CCC_8AA4EC(void) {
    UnkSnowHerring* var;
    char* sp1C[] = {
        "You are doing a fine\njob, %s.\nChoose \xA1\xC9\\hGo to Course\\p.\xA1\xC9",
        0x00000000,
    };

    var = func_800E1B40_8A7360();
    func_800E4578_8A9D98(var, sp1C, 0, 1);
}

void func_800E4D18_8AA538(void) {
    UnkSnowHerring* i;
    char* sp18[] = {
        "%s, you found a split\nin the path! According\nto my research, that split\n",
        "should link to a new course.\nI've also made a link from my\nlab. You should go right away!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp18, 0, 1);
}

void func_800E4D6C_8AA58C(void) {
    UnkSnowHerring* i;
    char* sp18[] = {
        "You finally got all of\nthe \\hPKMN Sign\\p pictures!",
        "\\JHmm... After looking at these\nsix pictures, I've noticed that\nthe Signs are just like the",
        "constellations that can be\nseen from Pokεmon Island!",
        "That's the key to this mystery!\nNow it all makes sense!\n\\PIt's the sky!",
        "Rainbow Cloud, floating in the\nsky, is the secret course!",
        "Someone in the clouds must\nhave created the PKMN Signs.",
        "I have made a new path\nto the Rainbow Cloud.",
        "This could prove very important\nfor Pokεmon research.\nGood luck, %s!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp18, 0, 1);
}

void func_800E4DD4_8AA5F4(void) {
    UnkSnowHerring* i;
    char* sp18[] = {
        "I've seen your \\hPKMN Sign\\p in\npictures!",
        "\\OWe have solved a Pokεmon\nIsland mystery.\nKeep going!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp18, 0, 1);
}

void func_800E4E28_8AA648(s32 arg0) {
    UnkSnowHerring* temp_v0;
    char* sp88[] = {
        "You take pictures at a good\npace. To make your work easier,\n\\Dhere is a present for you.\n",
        "It will come in handy for taking\nPokεmon pictures.",
        0x00000000,
    };
    char* sp68[] = {
        "Would you like to be\ncloser with Pokεmon?",
        "\\w\\1Then use \\Mthis \\7apple-shaped\\t\n\\hPOKεMON FOOD\\p.",
        "It's easy to use! When you are\nnot focusing your camera,\npress \\a to throw it.",
        "Pokεmon in the distance will\nhappily come closer when you\nuse this item.",
        "If you want to throw farther,\nlook up slightly, then throw!\nHere's a hint for you:",
        "Throw some Pokεmon Food\nto an \\hELECTRODE that's not\\p\n\\hmoving\\p and see what happens!",
        "Good luck, %s!",
        0x00000000,
    };
    char* sp58[] = {
        "\\w\\1If you see a place where you\nthink Pokεmon might be hiding,\nuse \\Mthis \\8\\hPESTER BALL\\p\\t.",
        "It's easy! Press \\b when you\nare not focusing your camera.",
        "This will make hidden Pokεmon\ncome out into the open.",
        0x00000000,
    };
    char* sp44[] = {
        "Would you like to see rare\nPokεmon poses?",
        "\\w\\1Play \\Mthis \\9\\hPOKε FLUTE\\p\\t to\nmake it happen!\nIt's easy to use!",
        "The \\d C Button allows\nyou to play the\n\\hPokε Flute\\p.",
        "You can listen to different\nmusic by using \\d.\nTry playing it often!",
        0x00000000,
    };
    char* sp3C[] = {
        "Shall I repeat this information?\n\\a Yes, please.\n\\b No, thank you.",
        0x00000000,
    };

    temp_v0 = func_800E1B40_8A7360();
    func_800E4578_8A9D98(temp_v0, sp88, 0, 1);

    while (1) {
        switch (arg0) {
            case 0:
                func_800E4578_8A9D98(temp_v0, sp68, 0, 1);
                break;
            case 1:
                func_800E4578_8A9D98(temp_v0, sp58, 0, 1);
                break;
            case 2:
                func_800E4578_8A9D98(temp_v0, sp44, 0, 1);
                break;
        }

        if (!func_800E4578_8A9D98(temp_v0, sp3C, 1, 0)) {
            break;
        }
        auPlaySound(0x53);
    }

    auPlaySound(0x4D);
    func_800E1D68_8A7588(0);
}

void func_800E502C_8AA84C(void) {
    UnkSnowHerring* i;
    char* sp18[] = {
        "You have completed the\nPKMN Report!",
        "%s is a genuine Pokεmon\nphotographer.\n\\KCongratulations!",
        "I have nothing left to\nteach you.",
        "Listen to your instincts\nand click the shutter when you\nsee something that looks cool.",
        "Pokεmon research on this island\nseemed long at first,\nbut it really went by fast.",
        "I appreciate all of your help.\nWell then, see you later!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp18, 0, 1);
}

void func_800E50A0_8AA8C0(void) {
    UnkSnowHerring* i;
    char* sp1C[] = {
        "\\UYou made it, %s!\nI never believed that MEW lived\non this island!",
        "Our PKMN Report now has a\nvery memorable picture.",
        "Thank you, %s.\nThis is all because of your\nhard work.",
        "It was so nice to find a\nphotographer as good as you.",
        "Bye for now, but I'll see you\nlater, %s!",
        0x00000000,
    };

    i = func_800E1B40_8A7360();
    func_800E4578_8A9D98(i, sp1C, 0, 1);
}

s32 func_800E510C_8AA92C(void) {
    s32 prev = D_80206B50_9CC370;
    D_80206B50_9CC370 = 0;
    return prev;
}

void func_800E5120_8AA940(void) {
    UnkSnowHerring* sp1C;

    sp1C = func_800E1B40_8A7360();
    func_8036EB80_842330(0);
    func_8036D4A0_840C50(2);
    func_8036C898_840048(sp1C, "Well then, \\Tsee you!");
    func_8036D4A0_840C50(0);
    func_8036B9EC_83F19C(sp1C, 0, 0x20);
    func_8036C898_840048(sp1C, "Press \\a or \\b to save.");
    ohWait(1);

    while (!(func_800AA38C(0)->unk_18 & 0xC000)) {
        ohWait(1);
    }

    auPlaySound(0x53);
    func_8036A8E4_83E094(sp1C);
    func_8036B9EC_83F19C(sp1C, 0, 0);
    func_8036C898_840048(sp1C, "Well then, see you later!");
    func_8036B9EC_83F19C(sp1C, 0, 0x20);
    func_8036C898_840048(sp1C, "\\eSaving...\\p");
    auSetBGMVolumeSmooth(0, 0, 30);
    ohWait(0x21);
    if (func_800BF244_5C0E4() != 0) {
        func_800E30B8_8A88D8();
    }
    ohWait(6);
    func_8036A8E4_83E094(sp1C);
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
    func_8036D4A0_840C50(2);
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
        if (func_800BFCA0_5CB40(0xE) != 0) {
            func_800E4878_8AA098();
        } else if (func_800BFCA0_5CB40(0x11) == 0 && func_800BFCA0_5CB40(0xB) != 0) {
            func_800E47C0_8A9FE0();
            func_800BFEBC_5CD5C(0x11, 1);
            if (func_800BFCA0_5CB40(0x14) != 0) {
                func_800BFEBC_5CD5C(0x14, 0);
                func_800BFEBC_5CD5C(0xE, 1);
            }
        } else {
            func_800E482C_8AA04C();
        }
    }
    if (func_800AAEE8(8) != 0) {
        func_800BFEBC_5CD5C(6, 1);
        func_800E4974_8AA194();
        D_80206B50_9CC370 = 6;
    }
    if (func_800AAEE8(0x10) != 0) {
        func_800E4B2C_8AA34C();
    }
    if (func_800AAEE8(0x20) != 0) {
        if (func_800BFCA0_5CB40(7) == 0 && func_800BF864_5C704() != 0) {
            func_800BFEBC_5CD5C(7, 1);
            func_800E4AC0_8AA2E0();
            D_80206B50_9CC370 = 1;
        } else {
            func_800E4B2C_8AA34C();
        }
    }
    if (func_800AAEE8(0x800) != 0) {
        func_800BFEBC_5CD5C(5, 1);
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
        func_800BFEBC_5CD5C(0, 1);
        func_800E4E28_8AA648(0);
    }
    if (func_800AAEE8(0x100) != 0) {
        func_800BFEBC_5CD5C(1, 1);
        func_800E4E28_8AA648(1);
    }
    if (func_800AAEE8(0x200) != 0) {
        func_800BFEBC_5CD5C(2, 1);
        func_800E4E28_8AA648(2);
    }
    sp24 = func_800AAEE8(0x40);
    sp20 = func_800AAEE8(0x40000);
    sp1C = func_800AAEE8(0x80000);
    temp_v0 = func_800BFCA0_5CB40(0xE);

    if (sp20 != 0 && sp24 != 0) {
        func_800BFEBC_5CD5C(0xB, 1);
        func_800BFEBC_5CD5C(0x14, 1);
        func_800E502C_8AA84C();
        func_800E5120_8AA940();
        func_800AAF10();
        func_800AADF0(0x13);
    } else if (sp20 != 0) {
        func_800BFEBC_5CD5C(0xB, 1);
        func_800E50A0_8AA8C0();
        func_800E5120_8AA940();
        func_800AAF10();
        func_800AADF0(0x12);
    } else if (sp24 != 0) {
        func_800BFEBC_5CD5C(0xE, 1);
        func_800E502C_8AA84C();
        func_800E5120_8AA940();
        func_800AAF10();
        func_800AADF0(0x13);
    } else if (sp1C != 0 && temp_v0 != 0) {
        func_800E50A0_8AA8C0();
        func_800E5120_8AA940();
        func_800AAF10();
        func_800AADF0(0x11);
    }
    func_8036D4A0_840C50(0);
}
