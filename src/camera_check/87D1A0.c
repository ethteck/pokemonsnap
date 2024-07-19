#include "common.h"
#include "camera_check.h"

// Unreferenced strings
const char D_camera_check_80208C60[] = "I'll choose which pictures to\nshow to Prof. Oak!";
const char D_camera_check_80208C94[] = "First choose the pictures with\n\"\\hOak's Mark\\p \\m.\"\n";
const char D_camera_check_80208CCC[] = "Let's show the marked\npicture(s) to Prof. Oak.";
const char D_camera_check_80208CFC[] = "I'll choose which pictures to\nshow to Prof. Oak!";
const char D_camera_check_80208D30[] = "First choose the pictures with\n\"\\hOak's Mark\\p \\m.\"\n";
const char D_camera_check_80208D68[] = "Let's show the marked\npicture(s) to Prof. Oak.";
const char D_camera_check_80208D98[] = "I'll choose which pictures to\nshow to Prof. Oak!";
const char D_camera_check_80208DCC[] = "I'll choose which pictures to\nsave in my PKMN Album.";
const char D_camera_check_80208E04[] = "Let's show the marked\npicture(s) to Prof. Oak.";

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801DF9B0.s")

UnkCyanBass* func_camera_check_801DFA4C(void) {
    if (!checkPlayerFlag(PFID_HAS_FINISHED_TUTORIAL)) {
        return &D_camera_check_80208994;
    }
    return &D_camera_check_802089BC;
}

#if 0
extern s32 D_camera_check_802089E4;

void func_8036B9EC(s32, s32 x, s32 y);
void func_8036C898_840048(s32, const char*);

s32 func_camera_check_801DFA80(UnkStruct800BEDF8* arg0, s32* arg1, s32 arg2, void* arg3) {

    char* temp_v0_2;

    if (arg0 == NULL) {
        D_camera_check_802089E4 = -1;
        if (arg1 != NULL) {
            func_80370004(0x15, (*arg1 * 0x18) + 0x1D);
            func_8037005C(0x3E, 0xD);
        }
        // maybe elseif
        return 0;
    }

    func_8036FFE0(0x15, (*arg1 * 0x18) + 0x1D);
    if ((arg0->unk_18 & 0x10000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 7) % 8;
        } while (D_camera_check_80249AA8[*arg1].unk_0 == 0x23);
        if (arg2) {
            auPlaySound(0x41);
        }
    }
    if ((arg0->unk_18 & 0x20000) && !(arg0->unk_14 & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while (D_camera_check_80249AA8[*arg1].unk_0 == 0x23);
        if (arg2) {
            auPlaySound(0x41);
        }
    }
    if (arg0->unk_18 & 0x4000) {
        return -1;
    }
    if (D_camera_check_802089E4 != *arg1) {
        s32 i;

         i = D_camera_check_80249AA8[*arg1].unk_0;
         D_camera_check_802089E4 = *arg1;
        temp_v0_2 = func_803717A8(arg3, i);
        if (temp_v0_2) {
            func_8036A8E4_83E094(func_camera_check_801DCB40());
            func_8036B9EC(func_camera_check_801DCB40(), 0, 0);
            func_8036D448(1);
            func_8036D3E8(-1, 3);
            func_8036C898_840048(func_camera_check_801DCB40(), temp_v0_2);
        }
        return 1;
    }

    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801DFA80.s")
#endif

s32 func_camera_check_801DFCD4(UnkStruct800BEDF8*, s32*, s32*, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801DFCD4.s")

void func_camera_check_801E0034(s32 arg0) {
    s32 pad;
    UnkIndigoHalibut* temp_v0;

    temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
    if (temp_v0 == NULL) {
        return;
    }

    if (temp_v0->unk_18_0x08000000) {
        auPlaySound(0x4A);
        temp_v0->unk_18_0x08000000 = 0;
    } else {
        if (func_camera_check_801E2CC0() >= func_camera_check_801E2E04()) {
            return;
        }
        auPlaySound(0x49);
        temp_v0->unk_18_0x08000000 = 1;
    }

    if (arg0) {
        func_camera_check_801DEA20(D_camera_check_80208960, 4);
    } else {
        func_camera_check_801DD630(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0);
    }
}

void func_camera_check_801E0118(s32 arg0) {
    void* sp1C;
    s16 temp_a0;
    UnkIndigoHalibut* temp_v0;

    if (checkPlayerFlag(PFID_HAS_DASH_ENGINE) &&
        (temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960), (temp_v0 != NULL))) {
        if (temp_v0->unk_18_0x10000000) {
            auPlaySound(0x4A);
            temp_v0->unk_18_0x10000000 = 0;
            return;
        }
        temp_a0 = temp_v0->unk_08;
        if (((temp_a0 == 0x270F) | (temp_a0 < 0x98)) == 0) {
            func_camera_check_801E2984(temp_a0);
            auPlaySound(0x49);
            temp_v0->unk_18_0x10000000 = 1;
        }
    }
}

void func_camera_check_801E01C0(s32 arg0) {
    UNUSED s32 pad;
    s16 temp_a0;
    UnkIndigoHalibut* temp_v0;

    temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
    if (temp_v0 == NULL) {
        return;
    }

    if (temp_v0->unk_18_0x20000000) {
        auPlaySound(0x4A);
        temp_v0->unk_18_0x20000000 = 0;
        return;
    }

    temp_a0 = temp_v0->unk_08;
    if (temp_a0 == 9999) {
        return;
    }

    if (temp_a0 <= POKEDEX_MAX) {
        func_camera_check_801E2984(temp_a0);
        auPlaySound(0x49);
        temp_v0->unk_18_0x20000000 = 1;
    }
}

void func_camera_check_801E0258(s32 arg0) {
    func_camera_check_801DDD28(0);
    func_camera_check_801DE80C(0, D_camera_check_80208960, 0);
    func_camera_check_801DDA44(0);
    if (arg0 == 0) {
        func_camera_check_801DD6D0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 21);
    }
    func_803713EC_844B9C(3);
}

void func_camera_check_801E02D0(void) {
    func_camera_check_801DDD28(0);
    func_camera_check_801DDA44(0);
    func_camera_check_801DDAD8(1);
    func_camera_check_801DE80C(1, D_camera_check_80208960, 0);
    func_camera_check_801DE288(func_camera_check_801E24D8(D_camera_check_80208960));
    func_camera_check_801DDD28(1);
}

void func_camera_check_801E0330(void) {
    func_camera_check_801DDD28(0);
    func_camera_check_801DE80C(0, D_camera_check_80208960, 0);
    func_camera_check_801DDA44(0);
    func_803713EC_844B9C(7);
}

void func_camera_check_801E0374(void) {
    if (D_camera_check_80208960 <= 0) {
        func_803713EC_844B9C(1);
    } else {
        func_803713D4_844B84(1);
    }
    if (D_camera_check_80208960 >= (func_camera_check_801E2534() - 1)) {
        func_803713EC_844B9C(2);
    } else {
        func_803713D4_844B84(2);
    }
}

void func_camera_check_801E03EC(void) {
    if (D_camera_check_80208960 - (D_camera_check_80208960 % 6) <= 0) {
        func_803713EC_844B9C(1);
    } else {
        func_803713D4_844B84(1);
    }
    if (D_camera_check_80208960 - (D_camera_check_80208960 % 6) >= func_camera_check_801E2534() - 6) {
        func_803713EC_844B9C(2);
    } else {
        func_803713D4_844B84(2);
    }
}

void func_camera_check_801E0480(void) {
    func_803713EC_844B9C(1);
    func_803713EC_844B9C(2);
}

void nullsub() {
}

bool func_camera_check_801E04B0(UnkIndigoHalibut* arg0) {
    if (arg0 == NULL) {
        return false;
    }

    if (func_8009BB4C(arg0->unk_08) >= 63) {
        return true;
    }

    return false;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E04F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E0B5C.s")

s32 func_camera_check_801E0F10(void) {
    UnkIndigoHalibut* temp_v0_2;
    UnkStruct800BEDF8* temp_v0;
    s32 sp6C;
    s32 sp68;
    s32 numPics;
    s32 mode;
    s32 prevMode;
    s32 prevNumPics;
    s32 var_s6;
    char* pokemonName;
    char* prevPokemonName;
    s32 a2;

    var_s6 = 1;
    a2 = D_camera_check_80208960 % 6;
    sp6C = a2 % 3, sp68 = a2 / 3;
    D_camera_check_80208960 -= (D_camera_check_80208960 % 6);
    func_80370038_8437E8(0x33, 0x26);
    func_camera_check_801DFCD4(NULL, &sp6C, &sp68, 0);
    prevMode = -1;
    prevNumPics = -1;
    prevPokemonName = NULL;
    ohWait(1);

    while (true) {
        temp_v0 = func_800AA38C(0);
        var_s6 |= func_camera_check_801DFCD4(temp_v0, &sp6C, &sp68, 0);
        if ((temp_v0->unk_18 & 0x8000) && (func_camera_check_801E24D8(D_camera_check_80208960) != NULL)) {
            prevMode = -1;
            func_camera_check_801E24D8(D_camera_check_80208960);
            func_camera_check_801E31E4(0, 0);
            func_camera_check_801E0B5C(0);
            func_camera_check_801E31E4(1, 0);
            a2 = D_camera_check_80208960 % 6;
            sp6C = a2 % 3, sp68 = a2 / 3;
            func_camera_check_801DFCD4(NULL, &sp6C, &sp68, 1);
            func_camera_check_801DD6D0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
            temp_v0_2 = func_camera_check_801E24D8(D_camera_check_80208960);
            if (temp_v0_2 != NULL) {
                func_camera_check_801DDB80(temp_v0_2->unk_08, 0, 5);
            }
            var_s6 |= 1;
            prevMode = -1;
        } else {
            if (temp_v0->unk_18 & 0x4000) {
                return 0;
            } else {
                if (var_s6 != 0) {
                    var_s6 = 0;
                    func_camera_check_801E03EC();
                    temp_v0_2 = func_camera_check_801E24D8(D_camera_check_80208960);
                    if (temp_v0_2 != NULL) {
                        func_camera_check_801DDB80(temp_v0_2->unk_08, 0, 5);
                        pokemonName = getPokemonName(temp_v0_2->unk_08);
                        numPics = func_camera_check_801E28E4(temp_v0_2->unk_08);
                        mode = func_camera_check_801E2F58(temp_v0_2, 0);

                        switch (mode) {
                            case 1:
                                if (prevMode != mode) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8036C898_840048(func_camera_check_801DCB40(), "I've chosen pictures to show to\nProf. Oak! Press \\b to return\nand choose \"\\hTo Prof. Oak\\p!\"");
                                }
                                break;
                            case 2:
                                if (prevMode != mode) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8036C898_840048(func_camera_check_801DCB40(), "Umm... It looks like there are\nno Pokεmon.");
                                }
                                break;
                            case 3:
                                if (prevMode != mode) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8036C898_840048(func_camera_check_801DCB40(), "What's this?\nIt's kind of odd...");
                                }
                                break;
                            case 4:
                                if (numPics < 2) {
                                    if (prevMode != mode || prevPokemonName != pokemonName || prevNumPics != numPics) {
                                        func_8036A8E4_83E094(func_camera_check_801DCB40());
                                        func_8037519C_84894C(func_camera_check_801DCB40(), "\\h%d\\p picture of %s\nhas been taken! Prof. Oak has\nseen it already. Check with \\a", numPics, pokemonName);
                                    }
                                } else if (prevMode != mode || prevPokemonName != pokemonName || prevNumPics != numPics) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8037519C_84894C(func_camera_check_801DCB40(), "\\h%d\\p pictures of %s\nhave been taken! Prof. Oak has\nseen this one. Check with \\a", numPics, pokemonName);
                                }
                                break;
                            case 5:
                                if (numPics < 2) {
                                    if (prevMode != mode || prevPokemonName != pokemonName || prevNumPics != numPics) {
                                        func_8036A8E4_83E094(func_camera_check_801DCB40());
                                        func_8037519C_84894C(func_camera_check_801DCB40(), "\\h%d\\p picture of %s\nhas been taken! Press \\a.", numPics, pokemonName);
                                    }
                                } else if (prevMode != mode || prevPokemonName != pokemonName || prevNumPics != numPics) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8037519C_84894C(func_camera_check_801DCB40(), "\\h%d\\p pictures of %s\nhave been taken! Press \\a.", numPics, pokemonName);
                                }
                                break;
                            case 6:
                            case 7:
                                if (prevMode != mode || prevPokemonName != pokemonName) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8037519C_84894C(func_camera_check_801DCB40(), "I have decided to show\n%s's picture.", pokemonName);
                                }
                                break;
                            case 8:
                            case 9:
                                if (prevMode != mode) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8036C898_840048(func_camera_check_801DCB40(), "I have decided which picture to\nshow for this Sign.");
                                }
                                break;
                            case 10:
                                if (prevMode != mode) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8036C898_840048(func_camera_check_801DCB40(), "Is this the PKMN Sign Prof. Oak\nwas talking about?\nPress \\a.");
                                }
                                break;
                            case 11:
                            case 12:
                                if (prevMode != mode) {
                                    func_8036A8E4_83E094(func_camera_check_801DCB40());
                                    func_8036C898_840048(func_camera_check_801DCB40(), "I have decided on the Sign\npicture.");
                                }
                                break;
                            case 13:
                                if (numPics <= 1) {
                                    if (prevMode != mode || prevNumPics != numPics) {
                                        func_8036A8E4_83E094(func_camera_check_801DCB40());
                                        func_8037519C_84894C(func_camera_check_801DCB40(), "There is \\h%d\\p Sign picture. I\nshowed it to Prof. Oak already.\nCheck with \\a.", numPics);
                                    }
                                } else {
                                    if (prevMode != mode || prevNumPics != numPics) {
                                        func_8036A8E4_83E094(func_camera_check_801DCB40());
                                        func_8037519C_84894C(func_camera_check_801DCB40(), "There are \\h%d\\p Sign pictures.\nProf. Oak has seen this one.\nCheck with \\a.", numPics);
                                    }
                                }
                                break;
                        }
                        prevMode = mode;
                        prevNumPics = numPics;
                        prevPokemonName = pokemonName;
                    } else {
                        prevMode = -1;
                        func_8036A8E4_83E094(func_camera_check_801DCB40());
                        func_camera_check_801DDB08(0);
                    }
                }
            }
        }
        ohWait(1);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E15B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E1918.s")

s32 func_camera_check_801E1BD4(void) {
    UNUSED s32 pad2;
    s32 sp38;
    UNUSED s32 pad;
    s32 sp30;
    UnkStruct800BEDF8* temp_s0;

    sp38 = 0;
    sp30 = func_camera_check_801E2E04();
    func_80370C34_8443E4(func_camera_check_801DF9B0());
    if (checkPlayerFlag(PFID_HAS_FINISHED_TUTORIAL) == 0) {
        func_80370780_843F30(1, 0x18);
    }
    if (func_camera_check_801E3140() == 0) {
        func_80370780_843F30(1, 0x17);
    }
    if (sp30 == 0) {
        func_80370780_843F30(1, 0x18);
    }
    func_camera_check_801E0258(0);
    func_camera_check_801E0480();
    func_camera_check_801E3910(0);
    func_803700A4_843854(1);
    ohWait(1);

    while (1) {
        temp_s0 = func_800AA38C(0);
        func_camera_check_801DFA80((UNK_PTR) temp_s0, &sp38, 1, func_camera_check_801DF9B0());
        if (temp_s0->unk_18 & 0x8000) {
            auPlaySound(0x42);

            switch (D_camera_check_80249AA8[sp38].unk_0) {

                case 23:
                    if (func_camera_check_801E3140() != 0) {
                        func_camera_check_801E31E4(1, 0);
                        func_camera_check_801DD630(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
                        func_camera_check_801DDB08(1);
                        func_camera_check_801E0F10();
                        auPlaySound(0x43);
                        func_camera_check_801E0480();
                        func_camera_check_801DDB08(0);
                        func_camera_check_801E31E4(0, 0);
                        func_camera_check_801DD630(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
                        func_80370038_8437E8(0x3E, 0xD);
                        func_camera_check_801DFA80(NULL, NULL, 0, 0);
                    }
                    break;

                case 24:
                    if ((checkPlayerFlag(PFID_HAS_FINISHED_TUTORIAL) != 0) && (sp30 != 0)) {
                        func_camera_check_801E1918();
                        auPlaySound(0x43);
                        func_camera_check_801E0480();
                        func_camera_check_801DD630(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
                        func_80370038_8437E8(0x3E, 0xD);
                        func_camera_check_801DFA80(NULL, NULL, 0, 0);
                    }
                    break;

                case 22:
                    return 4;
            }
        }

        ohWait(1);
    }
}

u32 func_camera_check_801E1EA4(void) {
    UnkStruct800BEDF8* temp_v0;

    func_803700A4_843854(0);
    D_camera_check_80208960 = 0;
    func_camera_check_801E3C24(1);
    func_camera_check_801DD6D0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
    func_8037060C_843DBC(1, 0x16);
    func_8036A8E4_83E094(func_camera_check_801DCB40());
    if (!func_camera_check_801E27FC()) {
        func_8036C898_840048(func_camera_check_801DCB40(), "No pictures to show to\nProf. Oak?\n\\a No.   \\b I have some.");
    } else {
        if ((func_camera_check_801E2A00() + func_camera_check_801E2B60()) != 0) {
            func_8036C898_840048(func_camera_check_801DCB40(), "Show this picture to Prof. Oak?\n\\a Yeah!\n\\b Maybe not...");
        } else {
            func_8036C898_840048(func_camera_check_801DCB40(), "Save this picture in the Album?\n\\a Yeah!\n\\b Maybe not...");
        }
    }
    func_camera_check_801E03EC();

    while (1) {
        temp_v0 = func_800AA38C(0);
        if (temp_v0->unk_18 & 0x8000) {
            D_camera_check_80208960 = 0;
            if (func_camera_check_801E27FC()) {
                auPlaySoundWithParams(0xA0U, 0x7FFF, 0x40, 0.75f, 0);
            }
            auPlaySound(0x53);
            return 0x10;
        }
        if (temp_v0->unk_18 & 0x4000) {
            func_camera_check_801E3C24(0);
            func_8037060C_843DBC(0, 0);
            func_803700A4_843854(1);
            D_camera_check_80208960 = 0;
            auPlaySound(0x43);
            return 0;
        }
        if ((temp_v0->unk_18 & 0x40000) && ((D_camera_check_80208960 - (D_camera_check_80208960 % 6)) < (func_camera_check_801E2534() - 6))) {
            auPlaySound(0x4B);
            D_camera_check_80208960 += 6;
            D_camera_check_80249AA0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
            func_camera_check_801E03EC();
        }
        if ((temp_v0->unk_18 & 0x80000) && ((D_camera_check_80208960 - (D_camera_check_80208960 % 6)) > 0)) {
            auPlaySound(0x4B);
            D_camera_check_80208960 -= 6;
            D_camera_check_80249AA0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
            func_camera_check_801E03EC();
        }
        ohWait(1);
    }
}

s32 func_camera_check_801E21E8(void) {
    u32 var_s1 = 0;
    s32 sp30 = 0;
    u32 var_v0;

    D_camera_check_80249AA4 = &D_camera_check_8020896C;
    D_camera_check_80249AA8 = func_80370600_843DB0();
    D_camera_check_80208960 = 0;
    D_camera_check_80208964 = func_8009BC68();
    D_camera_check_80249AA0 = func_camera_check_801DD6D0;
    func_80370134_8438E4();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);
    func_camera_check_801DCB40();
    func_camera_check_801DFA80(NULL, &sp30, 0, NULL);

    while (1) {
        switch (var_s1) {
            case 0:
                var_s1 = func_camera_check_801E1BD4();
                break;
            case 1:
                var_s1 = func_camera_check_801E0F10();
                break;
            case 2:
                var_s1 = func_camera_check_801E0B5C(0);
                break;
            case 3:
                var_s1 = func_camera_check_801E04F4(0);
                break;
            case 4:
                var_s1 = func_camera_check_801E1EA4();
                break;
            case 16:
                func_8036A8E4_83E094(func_camera_check_801DCB40());
                func_camera_check_801E0330();
                func_camera_check_801E3CE8();
                return -1;
        }

        ohWait(1);
    }
}
