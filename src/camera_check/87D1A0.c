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

UIButton* func_camera_check_801DF9B0(void) {
    if (!checkPlayerFlag(PFID_HAS_FINISHED_TUTORIAL)) {
        return &D_camera_check_80208994;
    }
    // clang-format off
    if (!func_camera_check_801E3140()) D_camera_check_802089BC[0].text = "There's no picture to show to\nProf. Oak.";
    // clang-format on
    else {
        D_camera_check_802089BC[0].text = "I'll choose which pictures to\nshow to Prof. Oak!";
    }

    if (func_camera_check_801E2E04() != 0) {
        D_camera_check_802089BC[2].text = "I'll choose which pictures to\nsave in my PKMN Album.";
    } else {
        D_camera_check_802089BC[2].text = "The Album is full.\nNo picture can be saved.";
    }
    return D_camera_check_802089BC;
}

UIButton* func_camera_check_801DFA4C(void) {
    if (!checkPlayerFlag(PFID_HAS_FINISHED_TUTORIAL)) {
        return &D_camera_check_80208994;
    } else {
        return D_camera_check_802089BC;
    }
}

s32 func_camera_check_801DFA80(UnkStruct800BEDF8* arg0, s32* arg1, s32 arg2, UIButton* arg3) {
    s32 temp_v0;
    char* temp_v0_2;
    s32 new_var;

    if (arg0 == NULL) {
        D_camera_check_802089E4 = -1;
        if (arg1 != NULL) {
            FocusMark_SetPos(21, (*arg1 * 24) + 29);
            FocusMark_SetSize(0x3E, 0xD);
        }
        return 0;
    }

    FocusMark_SetTargetPos(21, (*arg1 * 24) + 29);

    if ((arg0->pressedButtons & 0x10000) && !(arg0->currentButtons & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 7) % 8;
        } while (D_camera_check_80249AA8[*arg1].id == 0x23);

        if (arg2 != 0) {
            auPlaySound(SOUND_ID_65);
        }
    }

    if ((arg0->pressedButtons & 0x20000) && !(arg0->currentButtons & 0xC0000)) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while (D_camera_check_80249AA8[*arg1].id == 0x23);

        if (arg2 != 0) {
            auPlaySound(SOUND_ID_65);
        }
    }

    if (arg0->pressedButtons & 0x4000) {
        return -1;
    }

    new_var = *arg1;
    temp_v0 = new_var;
    if (D_camera_check_802089E4 != (temp_v0 ^ 0)) {
        D_camera_check_802089E4 = temp_v0;
        temp_v0_2 = UILayout_GetButtonText(arg3, D_camera_check_80249AA8[temp_v0].id);
        if (temp_v0_2 != 0) {
            UIElement_Draw(func_camera_check_801DCB40());
            UIElement_SetTextPos(func_camera_check_801DCB40(), 0, 0);
            UIText_SetShadowOffset(1);
            UIText_SetSpacing(-1, 3);
            UIElement_PrintText(func_camera_check_801DCB40(), temp_v0_2);
        }
        return 1;
    }

    return 0;
}

#ifndef NON_MATCHING
s32 func_camera_check_801DFCD4(UnkStruct800BEDF8*, s32*, s32*, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801DFCD4.s")
#else
extern s32 D_camera_check_802089E8;
extern s32 D_camera_check_802089EC;
s32 func_camera_check_801DFCD4(UnkStruct800BEDF8* arg0, s32* arg1, s32* arg2, s32 arg3) {
    bool sp24;
    bool var_t0;
    s32 new_var;
    s32 temp_v0_3;

    sp24 = false;
    var_t0 = false;

    if (arg0 == NULL) {
        D_camera_check_802089EC = -1;
        D_camera_check_802089E8 = -1;
        if (arg3 != 0) {
            FocusMark_SetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
        }
        return 0;
    }

    if (arg0->pressedButtons & 0x20000) {
        if (((*arg2) <= 0) != 0) {
            (*arg2)++;
        }
    }

    if (arg0->pressedButtons & 0x10000) {
        if (*arg2 > 0) {
            (*arg2)--;
        }
    }

    if (arg0->pressedButtons & 0x40000) {
        if (*arg1 < 2) {
            (*arg1)++;
        } else {
            var_t0 = false;
            if (D_camera_check_80208960 - (D_camera_check_80208960 % 6) < func_camera_check_801E2534() - 6) {
                auPlaySound(SOUND_ID_75);
                D_camera_check_80208960 += 4;
                *arg1 = 0;
                sp24 = true;
                var_t0 = true;
            }
        }
    }

    if (arg0->pressedButtons & 0x80000) {
        if (*arg1 > 0) {
            (*arg1)--;
        } else if (D_camera_check_80208960 - (D_camera_check_80208960 % 6) > 0) {
            auPlaySound(SOUND_ID_75);
            sp24 = true;
            var_t0 = true;
            D_camera_check_80208960 -= 4;
            *arg1 = 2;
        }
    }

    if (arg3 != 0) {
        var_t0 = true;
    }

    if (D_camera_check_802089E8 != *arg1 || D_camera_check_802089EC != *arg2) {
        if (D_camera_check_802089E8 >= 0) {
            auPlaySound(SOUND_ID_69);
        }
        new_var = *arg1;
        temp_v0_3 = *arg2;
        D_camera_check_802089EC = temp_v0_3;
        D_camera_check_80208960 = ((new_var + D_camera_check_80208960) - (D_camera_check_80208960 % 6)) + (temp_v0_3 * 3);
        D_camera_check_802089E8 = *arg1;
        if (var_t0) {
            FocusMark_SetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
        } else {
            FocusMark_SetTargetPos((*arg1 * 66) + 107, (*arg2 * 55) + 56);
        }
        if (sp24) {
            D_camera_check_80249AA0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
        }
        sp24 = true;
    }
    return sp24;
}
#endif

void func_camera_check_801E0034(s32 arg0) {
    s32 pad;
    UnkIndigoHalibut* temp_v0;

    temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
    if (temp_v0 == NULL) {
        return;
    }

    if (temp_v0->unk_18_0x08000000) {
        auPlaySound(SOUND_ID_74);
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
    UNUSED s32 pad;
    s32 temp_a0;
    UnkIndigoHalibut* temp_v0;

    if (checkPlayerFlag(PFID_HAS_DASH_ENGINE) &&
        (temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960), (temp_v0 != NULL))) {
        if (temp_v0->unk_18_0x10000000) {
            auPlaySound(SOUND_ID_74);
            temp_v0->unk_18_0x10000000 = 0;
            return;
        }
        temp_a0 = temp_v0->unk_08;
        if (!(temp_a0 == 9999 | temp_a0 <= POKEDEX_MAX)) {
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
        auPlaySound(SOUND_ID_74);
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
    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT);
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
    UILayout_HideHeaderElement(HEADER_PREV | HEADER_NEXT | HEADER_TITLE);
}

void func_camera_check_801E0374(void) {
    if (D_camera_check_80208960 <= 0) {
        UILayout_HideHeaderElement(HEADER_PREV);
    } else {
        UILayout_ShowHeaderElement(HEADER_PREV);
    }
    if (D_camera_check_80208960 >= (func_camera_check_801E2534() - 1)) {
        UILayout_HideHeaderElement(HEADER_NEXT);
    } else {
        UILayout_ShowHeaderElement(HEADER_NEXT);
    }
}

void func_camera_check_801E03EC(void) {
    if (D_camera_check_80208960 - (D_camera_check_80208960 % 6) <= 0) {
        UILayout_HideHeaderElement(HEADER_PREV);
    } else {
        UILayout_ShowHeaderElement(HEADER_PREV);
    }
    if (D_camera_check_80208960 - (D_camera_check_80208960 % 6) >= func_camera_check_801E2534() - 6) {
        UILayout_HideHeaderElement(HEADER_NEXT);
    } else {
        UILayout_ShowHeaderElement(HEADER_NEXT);
    }
}

void func_camera_check_801E0480(void) {
    UILayout_HideHeaderElement(HEADER_PREV);
    UILayout_HideHeaderElement(HEADER_NEXT);
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

s32 func_camera_check_801E04F4(s32 arg0) {
    UNUSED s32 pad[3];
    UnkIndigoHalibut* temp_s1;
    s16 new_var;
    char* pokemonName;
    UnkStruct800BEDF8* temp_s4;
    char* prevPokemonName;
    s32 prevMode;
    s32 mode;
    bool var_s5;

    var_s5 = true;
    FocusMark_Show(false);
    func_camera_check_801DDD28(1);
    UIElement_Draw(func_camera_check_801DCB40());
    func_camera_check_801E24D8(D_camera_check_80208960);
    auPlaySound(SOUND_ID_71);
    prevMode = -1;
    prevPokemonName = NULL;
    ohWait(1);

    while (true) {
        temp_s4 = func_800AA38C(0);
        temp_s1 = func_camera_check_801E24D8(D_camera_check_80208960);
        if (var_s5) {
            var_s5 = false;
            func_camera_check_801E0374();
            if (temp_s1 != NULL) {
                func_camera_check_801DEA20(D_camera_check_80208960, (!func_camera_check_801E2EF4(temp_s1->unk_08) << 7) | 9);
                func_camera_check_801DDB80(temp_s1->unk_08, 0, 5);
                pokemonName = getPokemonName(temp_s1->unk_08);
                mode = func_camera_check_801E2F58(temp_s1, true);
                switch (mode) {
                    case 2:
                        if (prevMode != mode) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            UIElement_PrintText(func_camera_check_801DCB40(), "No Pokεmon are in this picture.\nPress \\a or \\b to return.");
                        }
                        break;
                    case 3:
                        if (prevMode != mode) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            UIElement_PrintText(func_camera_check_801DCB40(), "Mmm?\nThis is not clear.\nPress \\a or \\b to return.");
                        }
                        break;
                    case 4:
                    case 13:
                        if (prevMode != mode) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            UIElement_PrintText(func_camera_check_801DCB40(), "I've shown that one to\nProf. Oak, but is this better?\nPress \\z to compare.");
                        }
                        break;
                    case 5:
                    case 10:
                        if (prevMode != mode) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            UIElement_PrintText(func_camera_check_801DCB40(), "Should I show this to Prof. Oak?\n\\a Yeah, this is it!\n\\b No, I don't think so...");
                        }
                        break;
                    case 6:
                        if (prevMode != mode || prevPokemonName != pokemonName) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            func_8037519C_84894C(func_camera_check_801DCB40(), "I've decided on %s.\nWell, what should I do?\n\\a Try again.   \\b Keep it!", pokemonName);
                        }
                        break;
                    case 7:
                    case 8:
                        if (prevMode != mode || prevPokemonName != pokemonName) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            func_8037519C_84894C(func_camera_check_801DCB40(), "%s's picture\nlooks pretty cool, doesn't it?\nPress \\z to compare.", pokemonName);
                        }
                        break;
                    case 9:
                        if (prevMode != mode) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            UIElement_PrintText(func_camera_check_801DCB40(), "I chose this Sign, but should\nI choose something else?\n\\a Yes!   \\b No thanks!");
                        }
                        break;
                    case 11:
                        if (prevMode != mode) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            UIElement_PrintText(func_camera_check_801DCB40(), "This Sign picture is also\npretty good.\nPress \\z to compare.");
                        }
                        break;
                    case 12:
                        if (prevMode != mode) {
                            UIElement_Draw(func_camera_check_801DCB40());
                            UIElement_PrintText(func_camera_check_801DCB40(), "I chose this Sign, but should\nI choose something else?\n\\a Yes!   \\b No thanks!");
                        }
                        break;
                }
                prevMode = mode;
                prevPokemonName = pokemonName;
            } else {
                prevMode = -1;
                UIElement_Draw(func_camera_check_801DCB40());
                func_camera_check_801DDB08(0);
            }
        }

        if (temp_s4->pressedButtons & 0x4000) {
            auPlaySound(0x48);
            FocusMark_Show(true);
            return 0;
        }

        if ((temp_s4->pressedButtons & 0x8000) && !func_camera_check_801E2EF4(temp_s1->unk_08)) {
            auPlaySound(0x48);
            FocusMark_Show(true);
            return 0;
        }

        temp_s1 = func_camera_check_801E24D8(D_camera_check_80208960);
        if ((temp_s4->pressedButtons & 0x8000) && temp_s1 != NULL) {
            UIElement_Draw(func_camera_check_801DCB40());
            if (!(temp_s1->unk_18_0x20000000) && !(temp_s1->unk_18_0x10000000)) {
                UIElement_PrintText(func_camera_check_801DCB40(), "I choose this!");
            } else {
                UIElement_PrintText(func_camera_check_801DCB40(), "I don't want to use this one.\0\0\0(unidentified)");
            }
            if (func_camera_check_801E04B0(temp_s1)) {
                func_camera_check_801E0118(1);
            } else {
                func_camera_check_801E01C0(1);
            }
            func_camera_check_801DDB80(temp_s1->unk_08, 0, 5);
            func_camera_check_801DE80C(1, D_camera_check_80208960, 1);
            ohWait(60);
            auPlaySound(0x48);
            FocusMark_Show(true);
            return 1;
        }

        if (temp_s1 != NULL && (func_800BF3D4_5C274(temp_s1->unk_08) || (func_camera_check_801E286C(temp_s1->unk_08) != NULL)) && (temp_s4->pressedButtons & 0x2000)) {
            new_var = temp_s1->unk_08;
            var_s5 = true;
            prevMode = -1;
            pokemonName = getPokemonName(new_var);
            auPlaySound(SOUND_ID_75);
            func_camera_check_801DE934(1, temp_s1->unk_08, 9);
            func_camera_check_801DDB08(0);
            UIElement_Draw(func_camera_check_801DCB40());

            if (func_camera_check_801E2540(temp_s1->unk_08)) {
                UIElement_PrintText(func_camera_check_801DCB40(), "This is the one I chose\nbefore...");
            } else {
                UIElement_PrintText(func_camera_check_801DCB40(), "This is the picture I showed to\nProf. Oak.");
            }

            ohWait(6);

            while (func_800AA38C(0)->currentButtons & 0x2000) {
                ohWait(1);
            }

            auPlaySound(SOUND_ID_75);
            func_camera_check_801DE80C(1, D_camera_check_80208960, 9);
            func_camera_check_801DDB80(temp_s1->unk_08, 0, 5);
            ohWait(6);
        }

        if (temp_s4->pressedButtons & 0xC00000) {
            if (temp_s4->pressedButtons & 0x400000) {
                if (D_camera_check_80208960 < (func_camera_check_801E2534() - 1)) {
                    D_camera_check_80208960++;
                    func_camera_check_801DE80C(1, D_camera_check_80208960, 9);
                    var_s5 = true;
                    auPlaySound(SOUND_ID_69);
                }
            }
            if (temp_s4->pressedButtons & 0x800000) {
                if (D_camera_check_80208960 > 0) {
                    D_camera_check_80208960--;
                    func_camera_check_801DE80C(1, D_camera_check_80208960, 9);
                    var_s5 = true;
                    auPlaySound(SOUND_ID_69);
                }
            }
        }
        ohWait(1);
    }
}

s32 func_camera_check_801E0B5C(bool arg0) {
    PhotoData* var_s2;
    s32 sp60;
    s32 sp5C;
    bool temp_v0_4;
    s32 var_a2;
    UnkIndigoHalibut* temp_v0;
    UnkIndigoHalibut* temp_v0_5;
    UnkIndigoHalibut* var_s0;
    UnkIndigoHalibut* var_v1;
    UnkStruct800BEDF8* temp_v0_2;
    bool var_s1;

    temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);

    if (temp_v0 != NULL) {
        var_s2 = temp_v0->unk_00;
    } else {
        if (D_camera_check_80208960 >= 0) {
            var_v1 = func_camera_check_801E24D8(0);
        } else {
            var_v1 = NULL;
        }

        if (var_v1 != NULL) {
            var_s2 = var_v1->unk_00;
        } else {
            var_s2 = NULL;
        }
    }

    if (D_camera_check_80208960 < 0) {
        D_camera_check_80208960 = 0;
    }
    var_a2 = D_camera_check_80208960;

    if (temp_v0 != NULL) {
        func_camera_check_801E3AF4(temp_v0);
    } else {
        func_camera_check_801E3AF4((UnkIndigoHalibut*) 1);
    }

    if (var_s2 != NULL) {
        D_camera_check_80208960 = func_camera_check_801E32E0(var_s2);
    } else {
        D_camera_check_80208960 = 0;
    }

    sp60 = (D_camera_check_80208960 % 6) % 3, sp5C = (D_camera_check_80208960 % 6) / 3;
    var_s0 = func_camera_check_801E24D8(D_camera_check_80208960);
    var_s1 = true;
    FocusMark_SetTargetSize(0x33, 0x26);
    func_camera_check_801DFCD4(NULL, &sp60, &sp5C, 0);
    ohWait(1);

    for (;; ohWait(1)) {
        temp_v0_2 = func_800AA740(0);
        if (func_camera_check_801DFCD4(temp_v0_2, &sp60, &sp5C, 0) != 0) {
            func_camera_check_801E03EC();
        }

        if (((temp_v0_2->pressedButtons & 0x8000) && (var_s0 = func_camera_check_801E24D8(D_camera_check_80208960), (var_s0 != NULL))) || var_s1) {
            func_camera_check_801E02D0();
            func_800AA85C(0x18, 6);
            func_800AA870(0xCF0003);
            if (var_s0 != NULL) {
                func_camera_check_801DDB80(var_s0->unk_08, 0, 0x47);
            }
            temp_v0_4 = func_camera_check_801E04F4(arg0);
            if (arg0 == true) {
                func_camera_check_801E0258(0);
            } else if (!var_s1 && !temp_v0_4) {
                func_camera_check_801E0258(0);
            }
            func_800AA85C(0x18, 0xC);
            func_800AA870(0xF0000);
            var_s0 = func_camera_check_801E24D8(D_camera_check_80208960);
            if (var_s0 != NULL) {
                func_camera_check_801DDB80(var_s0->unk_08, 0, 7);
            }
            sp60 = (D_camera_check_80208960 % 6) % 3, sp5C = (D_camera_check_80208960 % 6) / 3;
            func_camera_check_801E03EC();
            if (temp_v0_4 && arg0 != true) {
                var_s1 |= true;
            }
            if (!var_s1) {
                continue;
            }
        }

        var_s0 = func_camera_check_801E24D8(D_camera_check_80208960);
        if ((temp_v0_2->pressedButtons & 0x4000) || var_s1) {
            if (var_s0 != NULL) {
                var_s2 = var_s0->unk_00;
            } else {
                temp_v0_5 = func_camera_check_801E24D8(0);
                if (temp_v0_5 != NULL) {
                    var_s2 = temp_v0_5->unk_00;
                } else {
                    var_s2 = NULL;
                }
            }

            func_camera_check_801E3AF4(NULL);
            if (!var_s0->unk_00) {
            } // todo required to match
            if (var_s2 != NULL) {
                D_camera_check_80208960 = func_camera_check_801E32E0(var_s2);
            } else {
                D_camera_check_80208960 = var_a2;
            }

            if (var_s1 && arg0 != true) {
                func_camera_check_801E0258(1);
            } else {
                func_camera_check_801DD6D0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x17);
            }
            return 0;
        }
    }
}

// #else
// #pragma GLOBAL_ASM("asm/nonmatchings/camera_check/87D1A0/func_camera_check_801E0B5C.s")
// #endif

s32 func_camera_check_801E0F10(void) {
    UnkIndigoHalibut* temp_v0_2;
    UnkStruct800BEDF8* temp_v0;
    s32 sp6C;
    s32 sp68;
    s32 numPics;
    s32 mode;
    s32 prevMode;
    s32 prevNumPics;
    bool var_s6;
    char* pokemonName;
    char* prevPokemonName;
    s32 a2;

    var_s6 = true;
    a2 = D_camera_check_80208960 % 6;
    sp6C = a2 % 3, sp68 = a2 / 3;
    D_camera_check_80208960 -= (D_camera_check_80208960 % 6);
    FocusMark_SetTargetSize(0x33, 0x26);
    func_camera_check_801DFCD4(NULL, &sp6C, &sp68, 0);
    prevMode = -1;
    prevNumPics = -1;
    prevPokemonName = NULL;
    ohWait(1);

    while (true) {
        temp_v0 = func_800AA38C(0);
        var_s6 |= func_camera_check_801DFCD4(temp_v0, &sp6C, &sp68, 0);
        if ((temp_v0->pressedButtons & 0x8000) && (func_camera_check_801E24D8(D_camera_check_80208960) != NULL)) {
            prevMode = -1;
            func_camera_check_801E24D8(D_camera_check_80208960);
            func_camera_check_801E31E4(0, 0);
            func_camera_check_801E0B5C(false);
            func_camera_check_801E31E4(1, 0);
            a2 = D_camera_check_80208960 % 6;
            sp6C = a2 % 3, sp68 = a2 / 3;
            func_camera_check_801DFCD4(NULL, &sp6C, &sp68, 1);
            func_camera_check_801DD6D0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
            temp_v0_2 = func_camera_check_801E24D8(D_camera_check_80208960);
            if (temp_v0_2 != NULL) {
                func_camera_check_801DDB80(temp_v0_2->unk_08, 0, 5);
            }
            var_s6 |= true;
            prevMode = -1;
        } else {
            if (temp_v0->pressedButtons & 0x4000) {
                return 0;
            } else {
                if (var_s6) {
                    var_s6 = false;
                    func_camera_check_801E03EC();
                    temp_v0_2 = func_camera_check_801E24D8(D_camera_check_80208960);
                    if (temp_v0_2 != NULL) {
                        func_camera_check_801DDB80(temp_v0_2->unk_08, 0, 5);
                        pokemonName = getPokemonName(temp_v0_2->unk_08);
                        numPics = func_camera_check_801E28E4(temp_v0_2->unk_08);
                        mode = func_camera_check_801E2F58(temp_v0_2, false);

                        switch (mode) {
                            case 1:
                                if (prevMode != mode) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    UIElement_PrintText(func_camera_check_801DCB40(), "I've chosen pictures to show to\nProf. Oak! Press \\b to return\nand choose \"\\hTo Prof. Oak\\p!\"");
                                }
                                break;
                            case 2:
                                if (prevMode != mode) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    UIElement_PrintText(func_camera_check_801DCB40(), "Umm... It looks like there are\nno Pokεmon.");
                                }
                                break;
                            case 3:
                                if (prevMode != mode) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    UIElement_PrintText(func_camera_check_801DCB40(), "What's this?\nIt's kind of odd...");
                                }
                                break;
                            case 4:
                                if (numPics < 2) {
                                    if (prevMode != mode || prevPokemonName != pokemonName || prevNumPics != numPics) {
                                        UIElement_Draw(func_camera_check_801DCB40());
                                        func_8037519C_84894C(func_camera_check_801DCB40(), "\\h%d\\p picture of %s\nhas been taken! Prof. Oak has\nseen it already. Check with \\a", numPics, pokemonName);
                                    }
                                } else if (prevMode != mode || prevPokemonName != pokemonName || prevNumPics != numPics) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    func_8037519C_84894C(func_camera_check_801DCB40(), "\\h%d\\p pictures of %s\nhave been taken! Prof. Oak has\nseen this one. Check with \\a", numPics, pokemonName);
                                }
                                break;
                            case 5:
                                if (numPics < 2) {
                                    if (prevMode != mode || prevPokemonName != pokemonName || prevNumPics != numPics) {
                                        UIElement_Draw(func_camera_check_801DCB40());
                                        func_8037519C_84894C(func_camera_check_801DCB40(), "\\h%d\\p picture of %s\nhas been taken! Press \\a.", numPics, pokemonName);
                                    }
                                } else if (prevMode != mode || prevPokemonName != pokemonName || prevNumPics != numPics) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    func_8037519C_84894C(func_camera_check_801DCB40(), "\\h%d\\p pictures of %s\nhave been taken! Press \\a.", numPics, pokemonName);
                                }
                                break;
                            case 6:
                            case 7:
                                if (prevMode != mode || prevPokemonName != pokemonName) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    func_8037519C_84894C(func_camera_check_801DCB40(), "I have decided to show\n%s's picture.", pokemonName);
                                }
                                break;
                            case 8:
                            case 9:
                                if (prevMode != mode) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    UIElement_PrintText(func_camera_check_801DCB40(), "I have decided which picture to\nshow for this Sign.");
                                }
                                break;
                            case 10:
                                if (prevMode != mode) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    UIElement_PrintText(func_camera_check_801DCB40(), "Is this the PKMN Sign Prof. Oak\nwas talking about?\nPress \\a.");
                                }
                                break;
                            case 11:
                            case 12:
                                if (prevMode != mode) {
                                    UIElement_Draw(func_camera_check_801DCB40());
                                    UIElement_PrintText(func_camera_check_801DCB40(), "I have decided on the Sign\npicture.");
                                }
                                break;
                            case 13:
                                if (numPics <= 1) {
                                    if (prevMode != mode || prevNumPics != numPics) {
                                        UIElement_Draw(func_camera_check_801DCB40());
                                        func_8037519C_84894C(func_camera_check_801DCB40(), "There is \\h%d\\p Sign picture. I\nshowed it to Prof. Oak already.\nCheck with \\a.", numPics);
                                    }
                                } else {
                                    if (prevMode != mode || prevNumPics != numPics) {
                                        UIElement_Draw(func_camera_check_801DCB40());
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
                        UIElement_Draw(func_camera_check_801DCB40());
                        func_camera_check_801DDB08(0);
                    }
                }
            }
        }
        ohWait(1);
    }
    return 0;
}

s32 func_camera_check_801E15B4(s32 arg0) {
    UnkIndigoHalibut* temp_v0;
    UnkStruct800BEDF8* temp_s6;
    bool temp_s0;
    s32 temp_s2;
    s32 temp_s4;
    s32 temp_v1;
    s32 var_s5;

    var_s5 = true;
    FocusMark_Show(false);
    func_camera_check_801DDD28(1);
    UIElement_Draw(func_camera_check_801DCB40());
    temp_s4 = func_camera_check_801E2E04();
    auPlaySound(SOUND_ID_71);
    ohWait(1);

    while (true) {
        temp_s6 = func_800AA38C(0);
        temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
        temp_s2 = func_camera_check_801E2CC0();
        if (var_s5) {
            var_s5 = false;
            UIElement_Draw(func_camera_check_801DCB40());
            temp_s0 = temp_s4 == temp_s2;
            func_camera_check_801DEA20(D_camera_check_80208960, (temp_s0 << 8) | 0xC);
            func_camera_check_801E0374();
            if (temp_s4 == 0) {
                UIElement_PrintText(func_camera_check_801DCB40(), "The Album is full.\nI can't save any more pictures.\nPress \\b to return.");
            } else if (temp_v0->unk_18_0x08000000) {
                func_8037519C_84894C(func_camera_check_801DCB40(), "Should I drop this picture?\n\\a Pick again.   \\b Keep it.\n");
                if (temp_s0) {
                    UIElement_PrintText(func_camera_check_801DCB40(), "\\hThe Album is full\\p.");
                } else {
                    func_8037519C_84894C(func_camera_check_801DCB40(), "I can save %d more.", temp_s4 - temp_s2);
                }
            } else if (temp_s0) {
                UIElement_PrintText(func_camera_check_801DCB40(), "To save this picture, I have to\ndelete the \"\\hAlbum Mark\\p \\u.\"\nPress \\a or \\b to return.");
            } else {
                func_8037519C_84894C(func_camera_check_801DCB40(), "Shall I save this in the Album?\n\\a Yes!   \\b No thanks!\nI can save %d more.", temp_s4 - temp_s2);
            }
        }

        temp_v0 = func_camera_check_801E24D8(D_camera_check_80208960);
        temp_v1 = temp_s6->pressedButtons;
        if ((temp_v1 & 0x4000) || ((temp_v1 & 0x8000) && (temp_s4 == temp_s2) && !(temp_v0->unk_18_0x08000000))) {
            func_camera_check_801E0258(0);
            FocusMark_Show(true);
            auPlaySound(0x48);
            return 2;
        }

        if ((temp_v1 & 0x8000) && temp_v0 != NULL) {
            UIElement_Draw(func_camera_check_801DCB40());
            if (!(temp_v0->unk_18_0x08000000)) {
                UIElement_PrintText(func_camera_check_801DCB40(), "I choose this!");
            } else {
                UIElement_PrintText(func_camera_check_801DCB40(), "I don't want to use this one.");
            }
            func_camera_check_801E0034(1);
            func_camera_check_801DE80C(1, D_camera_check_80208960, 4);
            ohWait(60);
            func_camera_check_801E0258(0);
            auPlaySound(0x48);
            FocusMark_Show(true);
            return 1;
        }

        if (temp_v1 & 0xC00000) {
            if (temp_v1 & 0x400000) {
                if (D_camera_check_80208960 < (func_camera_check_801E2534() - 1)) {
                    D_camera_check_80208960++;
                    func_camera_check_801DE80C(1, D_camera_check_80208960, 0xC);
                    var_s5 = true;
                    auPlaySound(SOUND_ID_69);
                }
            }
            if (temp_s6->pressedButtons & 0x800000) {
                if (D_camera_check_80208960 > 0) {
                    D_camera_check_80208960--;
                    func_camera_check_801DE80C(1, D_camera_check_80208960, 0xC);
                    var_s5 = true;
                    auPlaySound(SOUND_ID_69);
                }
            }
        }
        ohWait(1);
    }
}

s32 func_camera_check_801E1918(void) {
    UIElement* temp_a0;
    UnkStruct800BEDF8* temp_v0;
    s32 sp5C;
    s32 sp58;
    UNUSED s32 pad;
    s32 spaceLeft;
    s32 temp_hi;
    s32 temp_s0;
    s32 temp_s3;
    bool var_s1;

    temp_hi = D_camera_check_80208960 % 6;
    var_s1 = true;

    sp5C = temp_hi % 3, sp58 = temp_hi / 3;
    D_camera_check_80208960 -= D_camera_check_80208960 % 6;
    FocusMark_SetTargetSize(0x33, 0x26);
    func_camera_check_801DFCD4(NULL, &sp5C, &sp58, 0);
    UIElement_Draw(func_camera_check_801DCB40());
    UIElement_PrintText(func_camera_check_801DCB40(), D_camera_check_80249AB0);
    temp_s3 = func_camera_check_801E2E04();
    ohWait(1);

    while (true) {
        temp_v0 = func_800AA38C(0);
        var_s1 |= func_camera_check_801DFCD4(temp_v0, &sp5C, &sp58, 0);
        if (var_s1) {
            var_s1 = false;
            func_camera_check_801E03EC();
            temp_s0 = func_camera_check_801E2CC0();
            UIElement_Draw(func_camera_check_801DCB40());
            if (temp_s3 == 0) {
                UIElement_PrintText(func_camera_check_801DCB40(), "I can't save any more pictures.\nThe Album is full.");
            } else if (temp_s3 == temp_s0) {
                UIElement_PrintText(func_camera_check_801DCB40(), "Delete \"\\hAlbum Marks\\p \\u\" to\nsave other pictures.");
            } else {
                spaceLeft = temp_s3 - temp_s0;
                temp_a0 = func_camera_check_801DCB40();
                func_8037519C_84894C(temp_a0, "Which picture should I save in\nthe Album? Check with \\a.\nYou can save %d more picture%s.", spaceLeft, spaceLeft != 1 ? "s" : "");
            }
        }

        if ((temp_v0->pressedButtons & 0x8000) && func_camera_check_801E24D8(D_camera_check_80208960) != NULL) {
            func_camera_check_801E02D0();
            func_800AA85C(0x18, 6);
            func_800AA870(0xCF0003);
            func_camera_check_801E15B4(0);
            func_800AA85C(0x18, 0xC);
            func_800AA870(0xF0000);
            temp_hi = D_camera_check_80208960 % 6;
            sp5C = temp_hi % 3, sp58 = temp_hi / 3;
            func_camera_check_801E03EC();
            var_s1 = true;
        } else if (temp_v0->pressedButtons & 0x4000) {
            return 0;
        }
        ohWait(1);
        continue;
    }
}

s32 func_camera_check_801E1BD4(void) {
    UNUSED s32 pad2;
    s32 sp38;
    UNUSED s32 pad;
    s32 sp30;
    UnkStruct800BEDF8* temp_s0;

    sp38 = 0;
    sp30 = func_camera_check_801E2E04();
    UILayout_CreateButtons(func_camera_check_801DF9B0());
    if (checkPlayerFlag(PFID_HAS_FINISHED_TUTORIAL) == 0) {
        UILayout_DisableButton(1, 0x18);
    }
    if (!func_camera_check_801E3140()) {
        UILayout_DisableButton(1, 0x17);
    }
    if (sp30 == 0) {
        UILayout_DisableButton(1, 0x18);
    }
    func_camera_check_801E0258(0);
    func_camera_check_801E0480();
    func_camera_check_801E3910(0);
    FocusMark_Show(true);
    ohWait(1);

    while (1) {
        temp_s0 = func_800AA38C(0);
        func_camera_check_801DFA80(temp_s0, &sp38, 1, func_camera_check_801DF9B0());
        if (temp_s0->pressedButtons & 0x8000) {
            auPlaySound(SOUND_ID_66);

            switch (D_camera_check_80249AA8[sp38].id) {

                case 23:
                    if (func_camera_check_801E3140()) {
                        func_camera_check_801E31E4(1, 0);
                        func_camera_check_801DD630(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
                        func_camera_check_801DDB08(1);
                        func_camera_check_801E0F10();
                        auPlaySound(SOUND_ID_67);
                        func_camera_check_801E0480();
                        func_camera_check_801DDB08(0);
                        func_camera_check_801E31E4(0, 0);
                        func_camera_check_801DD630(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
                        FocusMark_SetTargetSize(0x3E, 0xD);
                        func_camera_check_801DFA80(NULL, NULL, 0, 0);
                    }
                    break;

                case 24:
                    if ((checkPlayerFlag(PFID_HAS_FINISHED_TUTORIAL) != 0) && (sp30 != 0)) {
                        func_camera_check_801E1918();
                        auPlaySound(SOUND_ID_67);
                        func_camera_check_801E0480();
                        func_camera_check_801DD630(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
                        FocusMark_SetTargetSize(0x3E, 0xD);
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

    FocusMark_Show(false);
    D_camera_check_80208960 = 0;
    func_camera_check_801E3C24(1);
    func_camera_check_801DD6D0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
    UILayout_DisableAllButtonsExcept(1, 0x16);
    UIElement_Draw(func_camera_check_801DCB40());
    if (!func_camera_check_801E27FC()) {
        UIElement_PrintText(func_camera_check_801DCB40(), "No pictures to show to\nProf. Oak?\n\\a No.   \\b I have some.");
    } else {
        if ((func_camera_check_801E2A00() + func_camera_check_801E2B60()) != 0) {
            UIElement_PrintText(func_camera_check_801DCB40(), "Show this picture to Prof. Oak?\n\\a Yeah!\n\\b Maybe not...");
        } else {
            UIElement_PrintText(func_camera_check_801DCB40(), "Save this picture in the Album?\n\\a Yeah!\n\\b Maybe not...");
        }
    }
    func_camera_check_801E03EC();

    while (1) {
        temp_v0 = func_800AA38C(0);
        if (temp_v0->pressedButtons & 0x8000) {
            D_camera_check_80208960 = 0;
            if (func_camera_check_801E27FC()) {
                auPlaySoundWithParams(0xA0, 0x7FFF, 0x40, 0.75f, 0);
            }
            auPlaySound(0x53);
            return 0x10;
        }
        if (temp_v0->pressedButtons & 0x4000) {
            func_camera_check_801E3C24(0);
            UILayout_DisableAllButtonsExcept(0, 0);
            FocusMark_Show(true);
            D_camera_check_80208960 = 0;
            auPlaySound(SOUND_ID_67);
            return 0;
        }
        if ((temp_v0->pressedButtons & 0x40000) && ((D_camera_check_80208960 - (D_camera_check_80208960 % 6)) < (func_camera_check_801E2534() - 6))) {
            auPlaySound(SOUND_ID_75);
            D_camera_check_80208960 += 6;
            D_camera_check_80249AA0(D_camera_check_80208960 - (D_camera_check_80208960 % 6), 0x15);
            func_camera_check_801E03EC();
        }
        if ((temp_v0->pressedButtons & 0x80000) && ((D_camera_check_80208960 - (D_camera_check_80208960 % 6)) > 0)) {
            auPlaySound(SOUND_ID_75);
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
    UNUSED s32 pad;

    D_camera_check_80249AA4 = &D_camera_check_8020896C;
    D_camera_check_80249AA8 = UILayout_GetButtons();
    D_camera_check_80208960 = 0;
    D_camera_check_80208964 = func_8009BC68();
    D_camera_check_80249AA0 = func_camera_check_801DD6D0;
    FocusMark_MoveFront();
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
                var_s1 = func_camera_check_801E0B5C(false);
                break;
            case 3:
                var_s1 = func_camera_check_801E04F4(0);
                break;
            case 4:
                var_s1 = func_camera_check_801E1EA4();
                break;
            case 16:
                UIElement_Draw(func_camera_check_801DCB40());
                func_camera_check_801E0330();
                func_camera_check_801E3CE8();
                return -1;
        }

        ohWait(1);
    }
}
