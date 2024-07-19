#include "common.h"
#include "unk_end_level_3.h"
#include "more_funcs/more_funcs.h"

void* func_800E3230_8A8A50(void) {
    if (!checkPlayerFlag(PFID_7)) {
        return &D_801958F0_95B110;
    }
    return &D_801958C0_95B0E0;
}

// TODO struct in arg1
s32 func_800E3264_8A8A84(UnkStruct800BEDF8* arg0, s32* arg1) {
    int temp;
    if (arg0 == NULL) {
        if (arg1 != NULL) {
            func_80370004_8437B4(0x16, (*arg1 * 24) + 29);
            func_8037005C_84380C(0x3E, 0xD);
        }
        return 0;
    }

    func_8036FFE0_843790(0x16, (*arg1 * 24) + 29);

    if ((arg0->unk_18 & 0x10000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 7) % 8;
        } while ((*D_80206B44_9CC364)[*arg1].unk_0 == 35);

        auPlaySound(0x41);
    }

    if ((arg0->unk_18 & 0x20000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while ((*D_80206B44_9CC364)[*arg1].unk_0 == 35);

        auPlaySound(0x41);
    }

    if (arg0->unk_18 & 0x4000) {
        return -1;
    }

    return 0;
}

#if 0
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/func_800E3404_8A8C24.s")
#else
s32 func_800E3404_8A8C24(void) {
    UnkStruct800BEDF8* var_v0;
    s32 sp40;
    s32 temp_s0_2;
    s32 var_s2;
    UnkOrangeShark* shark;

    var_s2 = -1;
    sp40 = 0;
    if ((getLevelId() >= 0) && (getLevelId() < 7)) {
        sp40 = getLevelId();
    }
    func_80370038_8437E8(0x3E, 0xD);
    func_800E1D1C_8A753C(1);
    func_800E1C18_8A7438(1);
    func_800E61B4_8AB9D4(1, 0);
    if (func_800C0290_5D130() > func_800BFC5C_5CAFC()) {
        func_803700A4_843854(0);
        func_80370900_8440B0(0, func_800C0290_5D130() + 6);
        shark = D_80195CEC_95B50C[func_800C0290_5D130()];
        func_80370C34_8443E4(shark);
        func_803705A4_843D54();
        func_800E2A04_8A8224();
        sp40 = func_800BFC5C_5CAFC();
        func_803700A4_843854(1);
    } else {
        sp40 = D_80195894_95B0B4;
        shark = D_80195CEC_95B50C[func_800BFC5C_5CAFC()];
        func_80370C34_8443E4(shark);
    }
    func_800E3264_8A8A84(NULL, &sp40);
    func_803700A4_843854(1);

    while (true) {
        if (func_800E6404_8ABC24() != 0) {
            var_v0 = func_800AA740(0);
        } else {
            var_v0 = func_800AA38C(0);
        }
        if (func_800E3264_8A8A84(var_v0, &sp40) != 0) {
            auPlaySound(0x43);
            func_800E1D1C_8A753C(0);
            return 0;
        }
        func_800E1FEC_8A780C(sp40);

        if (var_v0->unk_18 & 0x8000) {
            auPlaySound(0x42);
            func_8037060C_843DBC(1, (*D_80206B44_9CC364)[sp40].unk_0);
            switch ((*D_80206B44_9CC364)[sp40].unk_0) {
                case 6:
                    D_80195894_95B0B4 = 0;
                    return 4;
                case 7:
                    D_80195894_95B0B4 = 1;
                    return 4;
                case 10:
                    D_80195894_95B0B4 = 4;
                    return 4;
                case 9:
                    D_80195894_95B0B4 = 3;
                    return 4;
                case 8:
                    D_80195894_95B0B4 = 2;
                    return 4;
                case 11:
                    D_80195894_95B0B4 = 5;
                    return 4;
                case 12:
                    D_80195894_95B0B4 = 6;
                    return 4;
                case 5:
                    D_80206B48_9CC368 = &func_800E307C_8A889C;
                    func_800E1D1C_8A753C(0);
                    func_8037060C_843DBC(0, (*D_80206B44_9CC364)[sp40].unk_0);
                    return 0;
            }
        }
        if (var_s2 != sp40) {
            var_s2 = sp40;
            func_8036A8E4_83E094(func_800E1B40_8A7360());
            func_8036B9EC_83F19C(func_800E1B40_8A7360(), 0, 0);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(func_800E1B40_8A7360(),
                                 func_803717A8_844F58(D_80195CEC_95B50C[func_800BFC5C_5CAFC()], (*D_80206B44_9CC364)[sp40].unk_0));
        }
        ohWait(1);
    }
}
#endif

s32 func_800E3774_8A8F94(void) {
    s32 i;
    s32 ret = 0;

    for (i = 0; i < 60; i++) {
        if (func_800BFA44_5C8E4(i) != 0) {
            ret++;
        }
    }

    return ret;
}

const char D_801C5650_98AE70[] = "Press \\a to do it!";
const char D_801C5664_98AE84[] = "Do you want to save\ntoday's trip?";
const char D_801C5688_98AEA8[] = "Press \\a to do it!";
const char D_801C569C_98AEBC[] = "Do you want to save\ntoday's trip?";
const char D_801C56C0_98AEE0[] = "Press \\a to do it!";
const char D_801C56D4_98AEF4[] = "Do you want to save\ntoday's trip?";

s32 func_800E37CC_8A8FEC(void) {
    s32 i;
    s32 sp80;
    UnkStruct800BEDF8* temp_v0_2;
    s32 sp78;
    s32 spaceLeft;
    s32 temp_v0;
    s32 numKinds;
    s32 numPics;
    s32 numPts;
    char sp4C[0x18];

    sp78 = -1;
    sp80 = 0;
    temp_v0 = func_800E510C_8AA92C();
    if (temp_v0 != 0) {
        sp80 = temp_v0;
    }
    func_80370C34_8443E4(func_800E3230_8A8A50());
    if (func_800E3774_8A8F94() == 0) {
        func_80370780_843F30(1, 3);
    }
    func_80370038_8437E8(0x3E, 0xD);
    ohWait(1);
    while (func_800A7460() != 0) {
        ohWait(1);
    }
    func_800E3264_8A8A84(NULL, &sp80);
    func_803700A4_843854(1);

    while (true) {
        temp_v0_2 = func_800AA38C(0);
        func_800E3264_8A8A84(temp_v0_2, &sp80);
        if (temp_v0_2->unk_18 & 0x8000) {
            auPlaySound(0x42);

            switch ((*D_80206B44_9CC364)[sp80].unk_0) {
                case 1:
                    return 1;
                case 2:
                    D_80195894_95B0B4 = 0xE;
                    return 4;
                case 3:
                    if (func_800E3774_8A8F94() != 0) {
                        D_80195894_95B0B4 = 0xC;
                        return 4;
                    }
                    break;
                case 4:
                    return 3;
            }
        }

        if (sp78 != sp80) {
            sp78 = sp80;
            func_8036A8E4_83E094(func_800E1B40_8A7360());
            func_8036B9EC_83F19C(func_800E1B40_8A7360(), 0, 0);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);

            switch ((*D_80206B44_9CC364)[sp80].unk_0) {

                case 3:
                    for (numPics = 0, i = 0; i < 60; i++) {
                        if (func_800BFA44_5C8E4(i) != NULL) {
                            numPics++;
                        }
                    }

                    if (numPics != 0) {
                        if (numPics == 1) {
                            func_8036C898_840048(func_800E1B40_8A7360(), "Saved Picture");
                        } else {
                            func_8036C898_840048(func_800E1B40_8A7360(), "Saved Pictures");
                        }
                        func_8036B9EC_83F19C(func_800E1B40_8A7360(), 124, 0);
                        if (numPics == 1) {
                            sprintf(sp4C, "\\i%2d\\g picture", numPics);
                        } else {
                            sprintf(sp4C, "\\i%2d\\g pictures", numPics);
                        }
                        func_8036C898_840048(func_800E1B40_8A7360(), sp4C);
                        func_8036B9EC_83F19C(func_800E1B40_8A7360(), 0, 16);
                        func_8036C898_840048(func_800E1B40_8A7360(), "Space left for");
                        func_8036B9EC_83F19C(func_800E1B40_8A7360(), 124, 16);
                        spaceLeft = 60 - numPics;
                        if (spaceLeft == 1) {
                            sprintf(sp4C, "\\i%2d\\g picture", spaceLeft);
                        } else {
                            sprintf(sp4C, "\\i%2d\\g pictures", spaceLeft);
                        }
                        func_8036C898_840048(func_800E1B40_8A7360(), sp4C);
                    } else {
                        func_8036C898_840048(func_800E1B40_8A7360(), "Use the \"\\hAlbum Mark\\p \\u\" in\nthe Camera Check mode to\nsave pictures in your Album.");
                    }
                    break;
                case 2:
                    numKinds = 0;
                    numPts = 0;
                    for (i = 1; i <= POKEDEX_MAX; i++) {
                        if (func_800BF710_5C5B0(i) != NULL) {
                            numKinds++;
                            numPts += func_800BF818_5C6B8(i);
                        }
                    }
                    func_8036B9EC_83F19C(func_800E1B40_8A7360(), 0, 0);
                    func_8036C898_840048(func_800E1B40_8A7360(), "No. of PKMN seen");
                    func_8036B9EC_83F19C(func_800E1B40_8A7360(), 0, 16);
                    func_8036C898_840048(func_800E1B40_8A7360(), "Report Score");
                    sprintf(sp4C, "\\i%8d\\g kind%s", numKinds, numKinds != 1 ? "s" : "");
                    func_8036B9EC_83F19C(func_800E1B40_8A7360(), 86, 0);
                    func_8036C898_840048(func_800E1B40_8A7360(), sp4C);
                    sprintf(sp4C, "\\i%8d\\g pts", numPts);
                    func_8036B9EC_83F19C(func_800E1B40_8A7360(), 86, 16);
                    func_8036C898_840048(func_800E1B40_8A7360(), sp4C);
                    break;
                default:
                    func_8036C898_840048(func_800E1B40_8A7360(), func_803717A8_844F58(func_800E3230_8A8A50(), (*D_80206B44_9CC364)[sp80].unk_0));
                    break;
            }
        }
        ohWait(1);
    }
}

s32 func_800E3CE8_8A9508(void) {
    UNUSED s32 pad;
    s32 sp38;
    s32 temp_v1;
    s32 temp_v1_2;
    UnkSnowHerring* sp2C;
    UNUSED s32 pad2;

    sp38 = 7;
    sp2C = func_800E1B40_8A7360();
    func_8036A8E4_83E094(sp2C);
    ohWait(1);
    func_8036C898_840048(sp2C, "Shall I save your progress?\n\\a Yes!   \\b No!");
    func_800E3264_8A8A84(func_800AA740(0), &sp38);
    func_803700A4_843854(0);

    while (1) {
        temp_v1 = func_800AA38C(0)->unk_18;
        if (temp_v1 & 0x8000) {
            auPlaySoundWithParams(0xA0, 0x7FFF, 0x40, 0.75f, 0);
            auPlaySound(0x53);
            func_8036A8E4_83E094(sp2C);
            func_8036B9EC_83F19C(sp2C, 0, 32);
            func_8036C898_840048(sp2C, "\\eSaving...\\p");
            ohWait(48);
            auSetBGMVolumeSmooth(0, 0, 30);
            ohWait(33);
            if (checkPlayerFlag(PFID_21)) {
                D_80206B48_9CC368();
            }
            if (func_800BF244_5C0E4() != 0) {
                func_800E30B8_8A88D8();
            }
            auSetBGMVolumeSmooth(0, 0x7F00, 0x12);
            ohWait(21);
            func_8036A8E4_83E094(sp2C);
            func_8036C898_840048(sp2C, "Would you like to keep going?\n\\a Yes!  \\b No!");
            while (1) {
                temp_v1_2 = func_800AA38C(0)->unk_18;
                if (temp_v1_2 & 0x4000) {
                    auPlaySound(0x53);
                    func_8036A8E4_83E094(sp2C);
                    func_8036C898_840048(sp2C, "I'm looking forward to seeing\nyour new shots!");
                    ohWait(120);
                    D_80195894_95B0B4 = 8;
                    return 4;
                }
                if (temp_v1_2 & 0x8000) {
                    auPlaySound(0x4D);
                    return 0;
                }
                ohWait(1);
            }
        }
        if (temp_v1 & 0x4000) {
            auPlaySound(0x4D);
            return 0;
        }
        ohWait(1);
    }
}

// #pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_3/8A8A50/func_800E3ED4_8A96F4.s")

extern void* D_80206B40_9CC360;
extern void (*D_80206B48_9CC368)(void);

s32 func_800E3ED4_8A96F4(void) {
    s32 temp_s0;
    UnkSnowHerring* temp_s1;
    ucolor sp64;
    s32 levelID;
    s32 temp_v1;
    char sp44[0x18];
    s32 var_s0;

    var_s0 = 0;
    D_80206B40_9CC360 = func_800E3230_8A8A50();
    D_80206B44_9CC364 = func_80370600_843DB0();
    func_80370134_8438E4();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);
    func_803705F0_843DA0(1);
    levelID = getLevelId();
    D_80195894_95B0B4 = levelID;
    if (levelID < 0 || levelID >= 7) {
        D_80195894_95B0B4 = 0;
    }
    func_8036D4A0_840C50(0);
    D_80206B48_9CC368 = func_800E5EBC_8AB6DC;

    while (true) {
        switch (var_s0) {
            case 0:
                var_s0 = func_800E37CC_8A8FEC();
                if (var_s0 == 1) {
                    func_800A7860(0, 0.2f);
                    ohWait(1);
                    if (func_800A7460() != 0) {
                        do {
                            ohWait(1);
                        } while (func_800A7460() != 0);
                    }
                    func_803700A4_843854(0);
                    func_800A7860(1, 0.2f);
                    func_8036F684_842E34(func_800E1B4C_8A736C(), 0);
                    func_8036F738_842EE8(func_800E1B4C_8A736C(), &sp64);
                    func_8036B870_83F020(func_800E1B40_8A7360(), 0, sp64.r, sp64.g, sp64.b, 0xFF);
                    func_8036A8E4_83E094(func_800E1B40_8A7360());
                    func_800E60D8_8AB8F8(1);
                }
                break;
            case 1:
                func_80375284_848A34(1);
                func_800A7470(0, 0, 0);
                func_800E1BF4_8A7414(0xB2);
                var_s0 = func_800E3404_8A8C24();
                if (var_s0 != 4) {
                    if (var_s0 == 0) {
                        func_800A7860(0, 0.2f);
                        ohWait(1);
                        while (func_800A7460() != 0) {
                            ohWait(1);
                        }
                        func_803700A4_843854(0);
                        func_800A7860(1, 0.2f);
                        func_8036F684_842E34(func_800E1B4C_8A736C(), 1);
                        func_8036F738_842EE8(func_800E1B4C_8A736C(), &sp64);
                        func_8036B870_83F020(func_800E1B40_8A7360(), 0, sp64.r, sp64.g, sp64.b, 0xFF);
                        func_8036A8E4_83E094(func_800E1B40_8A7360());
                        func_800E1C18_8A7438(0);
                        func_800E60D8_8AB8F8(0);
                        func_800E61B4_8AB9D4(0, 0);
                        func_80375284_848A34(0);
                    }
                    break;
                }
                func_8036A8E4_83E094(func_800E1B40_8A7360());
                func_8036B9EC_83F19C(func_800E1B40_8A7360(), 0, 0);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                if (!checkPlayerFlag(PFID_11)) {
                    func_8036C898_840048(func_800E1B40_8A7360(), "Should I take this course?\n\\a Let's go!   \\b Maybe later.");
                } else {
                    temp_s1 = func_800E1B40_8A7360();
                    temp_s0 = func_803751F8_8489A8(D_80195894_95B0B4);
                    if (temp_s0 < func_800C0224_5D0C4(D_80195894_95B0B4)) {
                        func_8036B870_83F020(temp_s1, 1, 0xFF, 0xFF, 0, 0xFF);
                    } else {
                        func_8036B870_83F020(temp_s1, 1, 0xFF, 0xFF, 0xFF, 0xFF);
                    }
                    func_8036B9EC_83F19C(temp_s1, 0, 0);
                    func_8036C898_840048(temp_s1, "HI-SCORE");
                    sprintf(sp44, "\\i%8d\\g pts", func_800C0224_5D0C4(D_80195894_95B0B4));
                    func_8036B9EC_83F19C(temp_s1, 0x60, 0);
                    func_8036C898_840048(temp_s1, sp44);
                    temp_s0 = func_803751F8_8489A8(D_80195894_95B0B4);
                    if (temp_s0 < func_800C0224_5D0C4(D_80195894_95B0B4)) {
                        func_8036B870_83F020(temp_s1, 1, 0xFF, 0xFF, 0xFF, 0xFF);
                    } else {
                        func_8036B870_83F020(temp_s1, 1, 0xFF, 0xFF, 0, 0xFF);
                    }
                    func_8036B9EC_83F19C(temp_s1, 0, 0x10);
                    func_8036C898_840048(temp_s1, "CHALLENGE SCORE");
                    sprintf(sp44, "\\i%8d\\g pts", func_803751F8_8489A8(D_80195894_95B0B4));
                    func_8036B9EC_83F19C(temp_s1, 0x60, 0x20);
                    func_8036C898_840048(temp_s1, sp44);
                    func_8036B870_83F020(temp_s1, 1, 0xFF, 0xFF, 0xFF, 0xFF);
                }
                func_800E1D1C_8A753C(0);
                func_800E1BF4_8A7414(0xFF);
                ohWait(1);

                while (true) {
                loop_28:
                    func_800E3264_8A8A84(func_800AA740(0), &D_80195894_95B0B4);
                    temp_v1 = func_800AA38C(0)->unk_18;
                    if (temp_v1 & 0x8000) {
                        auPlaySoundWithParams(0xA0, 0x7FFF, 0x40, 0.75f, 0);
                        func_800E61B4_8AB9D4(2, D_80195894_95B0B4);
                        return D_80195894_95B0B4;
                    }
                    if (temp_v1 & 0x4000) {
                        auPlaySound(0x43);
                        func_8037060C_843DBC(0, 0);
                        ohWait(1);
                        var_s0 = 1;
                        func_800E1D1C_8A753C(1);
                        break;
                    }
                    ohWait(1);
                }
                break;
            case 3:
                var_s0 = func_800E3CE8_8A9508();
                break;
            case 4:
                return D_80195894_95B0B4;
        }
    }
    return D_80195894_95B0B4;
}
