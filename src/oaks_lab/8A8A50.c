#include "common.h"
#include "oaks_lab.h"
#include "more_funcs/more_funcs.h"

// .bss
void* D_80206B40_9CC360;
UIButton* D_80206B44_9CC364;
void (*D_80206B48_9CC368)(void);

extern const char D_801C5650_98AE70[];
extern const char D_801C5664_98AE84[];
extern const char D_801C5688_98AEA8[];
extern const char D_801C569C_98AEBC[];
extern const char D_801C56C0_98AEE0[];
extern const char D_801C56D4_98AEF4[];
extern u32 D_80195918_95B138[];
extern u32 D_80195964_95B184[];
extern u32 D_801959BC_95B1DC[];
extern u32 D_80195A1C_95B23C[];
extern u32 D_80195A60_95B280[];
extern u32 D_80195AA8_95B2C8[];
extern u32 D_80195AFC_95B31C[];
extern u32 D_80195B48_95B368[];
extern struct UIButton D_80195B6C_95B38C;
extern struct UIButton D_80195B8C_95B3AC;
extern struct UIButton D_80195BB4_95B3D4;
extern struct UIButton D_80195BE4_95B404;
extern struct UIButton D_80195C1C_95B43C;
extern struct UIButton D_80195C5C_95B47C;
extern struct UIButton D_80195CA4_95B4C4;

// .data
u32 D_80195890_95B0B0 = 0x00000000;
s32 D_80195894_95B0B4 = 0;

u32 D_80195898_95B0B8[] = {
    0x00000001, (u32) &D_801C5650_98AE70, 0x00000002, 0x00000000,
    0x00000022, 0x00000000, 0x00000004, (u32) &D_801C5664_98AE84,
    0x00000023, 0x00000000,
};

s32 D_801958C0_95B0E0 = 1;

u32 D_801958C4_95B0E4[] = {
    (u32) &D_801C5688_98AEA8, 0x00000002, 0x00000000, 0x00000022,
    0x00000000, 0x00000003, 0x00000000, 0x00000004,
    (u32) &D_801C569C_98AEBC, 0x00000023, 0x00000000,
};

s32 D_801958F0_95B110 = 1;

u32 D_801958F4_95B114[] = {
    (u32) &D_801C56C0_98AEE0, 0x00000022, 0x00000000, 0x00000003,
    0x00000000, 0x00000004, (u32) &D_801C56D4_98AEF4, 0x00000023,
    0x00000000,
};

u32 D_80195918_95B138[] = {
    0x57686174, 0x20612073, 0x756E6E79, 0x20626561,
    0x63682E20, 0x4974206C, 0x6F6F6B73, 0x0A677265,
    0x61742120, 0x49207368, 0x6F756C64, 0x20676574,
    0x20736F6D, 0x650A6177, 0x65736F6D, 0x65207368,
    0x6F747320, 0x74686572, 0x65210000,
};

u32 D_80195964_95B184[] = {
    0x54686572, 0x65207573, 0x65642074, 0x6F206265,
    0x20612050, 0x6F776572, 0x20506C61, 0x6E740A69,
    0x6E207468, 0x6973206C, 0x6F6E672C, 0x20646172,
    0x6B207475, 0x6E6E656C, 0x2E0A4920, 0x63616E27,
    0x74207761, 0x69742074, 0x6F206368, 0x65636B20,
    0x6974206F, 0x75742100,
};

u32 D_801959BC_95B1DC[] = {
    0x54686973, 0x20697320, 0x61207363, 0x6172792D,
    0x6C6F6F6B, 0x696E6720, 0x63617665, 0x2E0A4920,
    0x62657420, 0x69662049, 0x206C6973, 0x74656E20,
    0x63617265, 0x66756C6C, 0x792C0A49, 0x276C6C20,
    0x68656172, 0x206C6F74, 0x73206F66, 0x20737472,
    0x616E6765, 0x206E6F69, 0x7365732E, 0x00000000,
};

u32 D_80195A1C_95B23C[] = {
    0x54686520, 0x72697665, 0x72206865, 0x72652069,
    0x7320666C, 0x6F77696E, 0x67206765, 0x6E746C79,
    0x2E0A536F, 0x6D656F6E, 0x65206D69, 0x67687420,
    0x62652068, 0x6964696E, 0x670A6E65, 0x61726279,
    0x2E2E2E00,
};

u32 D_80195A60_95B280[] = {
    0x54686520, 0x626F696C, 0x696E6720, 0x6D61676D,
    0x61206865, 0x7265206D, 0x616B6573, 0x0A746869,
    0x7320706C, 0x61636520, 0x76657279, 0x20686F74,
    0x2E0A4927, 0x6D207377, 0x65617469, 0x6E672061,
    0x6C726561, 0x64792100,
};

u32 D_80195AA8_95B2C8[] = {
    0x54686973, 0x20726976, 0x65722069, 0x73207261,
    0x70696421, 0x20204927, 0x6C6C2068, 0x61766520,
    0x746F0A63, 0x6F6E6365, 0x6E747261, 0x74652068,
    0x6172642C, 0x206F7220, 0x4920636F, 0x756C640A,
    0x6D697373, 0x20612067, 0x6F6F6420, 0x73686F74,
    0x21000000,
};

u32 D_80195AFC_95B31C[] = {
    0x54686973, 0x20697320, 0x61207365, 0x63726574,
    0x20636F75, 0x7273652E, 0x2E2E0A49, 0x6E207468,
    0x61742063, 0x6173652C, 0x20492073, 0x686F756C,
    0x64206669, 0x6E642074, 0x68650A72, 0x61726573,
    0x7420506F, 0x6BA6C56D, 0x6F6E2100,
};

u32 D_80195B48_95B368[] = {
    0x4D617962, 0x65204920, 0x73686F75, 0x6C642073,
    0x746F7020, 0x74616B69, 0x6E670A70, 0x686F746F,
    0x732E0000,
};

struct UIButton D_80195B6C_95B38C = { 6, (char*) &D_80195918_95B138 };

u32 D_80195B74_95B394[] = {
    0x00000022, 0x00000000, 0x00000005, (u32) &D_80195B48_95B368,
    0x00000023, 0x00000000,
};

struct UIButton D_80195B8C_95B3AC = { 6, (char*) &D_80195918_95B138 };

u32 D_80195B94_95B3B4[] = {
    0x00000007, (u32) &D_80195964_95B184, 0x00000022, 0x00000000,
    0x00000005, (u32) &D_80195B48_95B368, 0x00000023, 0x00000000,
};

struct UIButton D_80195BB4_95B3D4 = { 6, (char*) &D_80195918_95B138 };

u32 D_80195BBC_95B3DC[] = {
    0x00000007, (u32) &D_80195964_95B184, 0x00000008, (u32) &D_80195A60_95B280,
    0x00000022, 0x00000000, 0x00000005, (u32) &D_80195B48_95B368,
    0x00000023, 0x00000000,
};

struct UIButton D_80195BE4_95B404 = { 6, (char*) &D_80195918_95B138 };

u32 D_80195BEC_95B40C[] = {
    0x00000007, (u32) &D_80195964_95B184, 0x00000008, (u32) &D_80195A60_95B280,
    0x00000009, (u32) &D_80195A1C_95B23C, 0x00000022, 0x00000000,
    0x00000005, (u32) &D_80195B48_95B368, 0x00000023, 0x00000000,
};

struct UIButton D_80195C1C_95B43C = { 6, (char*) &D_80195918_95B138 };

u32 D_80195C24_95B444[] = {
    0x00000007, (u32) &D_80195964_95B184, 0x00000008, (u32) &D_80195A60_95B280,
    0x00000009, (u32) &D_80195A1C_95B23C, 0x0000000A, (u32) &D_801959BC_95B1DC,
    0x00000022, 0x00000000, 0x00000005, (u32) &D_80195B48_95B368,
    0x00000023, 0x00000000,
};

struct UIButton D_80195C5C_95B47C = { 6, (char*) &D_80195918_95B138 };

u32 D_80195C64_95B484[] = {
    0x00000007, (u32) &D_80195964_95B184, 0x00000008, (u32) &D_80195A60_95B280,
    0x00000009, (u32) &D_80195A1C_95B23C, 0x0000000A, (u32) &D_801959BC_95B1DC,
    0x0000000B, (u32) &D_80195AA8_95B2C8, 0x00000022, 0x00000000,
    0x00000005, (u32) &D_80195B48_95B368, 0x00000023, 0x00000000,
};

struct UIButton D_80195CA4_95B4C4 = { 6, (char*) &D_80195918_95B138 };

u32 D_80195CAC_95B4CC[] = {
    0x00000007, (u32) &D_80195964_95B184, 0x00000008, (u32) &D_80195A60_95B280,
    0x00000009, (u32) &D_80195A1C_95B23C, 0x0000000A, (u32) &D_801959BC_95B1DC,
    0x0000000B, (u32) &D_80195AA8_95B2C8, 0x0000000C, (u32) &D_80195AFC_95B31C,
    0x00000005, (u32) &D_80195B48_95B368, 0x00000023, 0x00000000,
};

UIButton* D_80195CEC_95B50C[9] = {
    (struct UIButton*) &D_80195B6C_95B38C,
    (struct UIButton*) &D_80195B8C_95B3AC,
    (struct UIButton*) &D_80195BB4_95B3D4,
    (struct UIButton*) &D_80195BE4_95B404,
    (struct UIButton*) &D_80195C1C_95B43C,
    (struct UIButton*) &D_80195C5C_95B47C,
    (struct UIButton*) &D_80195CA4_95B4C4,
    NULL,
    NULL,
};

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
            FocusMark_SetPos(0x16, (*arg1 * 24) + 29);
            FocusMark_SetSize(0x3E, 0xD);
        }
        return 0;
    }

    FocusMark_SetTargetPos(0x16, (*arg1 * 24) + 29);

    if ((arg0->pressedButtons & STICK_SLOW_UP) && !(arg0->currentButtons & (STICK_SLOW_RIGHT | STICK_SLOW_LEFT))) {
        do {
            *arg1 = (*arg1 + 7) % 8;
        } while (D_80206B44_9CC364[*arg1].id == 35);

        auPlaySound(SOUND_ID_65);
    }

    if ((arg0->pressedButtons & STICK_SLOW_DOWN) && !(arg0->currentButtons & (STICK_SLOW_RIGHT | STICK_SLOW_LEFT))) {
        do {
            *arg1 = (*arg1 + 1) % 8;
        } while (D_80206B44_9CC364[*arg1].id == 35);

        auPlaySound(SOUND_ID_65);
    }

    if (arg0->pressedButtons & B_BUTTON) {
        return -1;
    }

    return 0;
}

s32 func_800E3404_8A8C24(void) {
    UnkStruct800BEDF8* var_v0;
    s32 sp40;
    s32 var_s2;
    UIButton* bass;

    var_s2 = -1;
    sp40 = 0;
    if (getLevelId() >= 0 && getLevelId() < 7) {
        sp40 = getLevelId();
    }
    FocusMark_SetTargetSize(0x3E, 0xD);
    func_800E1D1C_8A753C(1);
    func_800E1C18_8A7438(1);
    func_800E61B4_8AB9D4(1, 0);
    if (func_800C0290_5D130() > func_800BFC5C_5CAFC()) {
        FocusMark_Show(false);
        UILayout_ShowButton(false, func_800C0290_5D130() + 6);
        bass = D_80195CEC_95B50C[func_800C0290_5D130()];
        UILayout_CreateButtons(bass);
        UILayout_WaitPanelTransitionComplete();
        func_800E2A04_8A8224();
        sp40 = func_800BFC5C_5CAFC();
        FocusMark_Show(true);
    } else {
        sp40 = D_80195894_95B0B4;
        bass = D_80195CEC_95B50C[func_800BFC5C_5CAFC()];
        UILayout_CreateButtons(bass);
    }
    func_800E3264_8A8A84(NULL, &sp40);
    FocusMark_Show(true);

    while (true) {
        if (func_800E6404_8ABC24() != 0) {
            var_v0 = func_800AA740(0);
        } else {
            var_v0 = func_800AA38C(0);
        }
        if (func_800E3264_8A8A84(var_v0, &sp40) != 0) {
            auPlaySound(SOUND_ID_67);
            func_800E1D1C_8A753C(0);
            return 0;
        }
        func_800E1FEC_8A780C(sp40);

        if (var_v0->pressedButtons & A_BUTTON) {
            auPlaySound(SOUND_ID_66);
            UILayout_DisableAllButtonsExcept(1, D_80206B44_9CC364[sp40].id);
            switch (D_80206B44_9CC364[sp40].id) {
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
                    UILayout_DisableAllButtonsExcept(0, D_80206B44_9CC364[sp40].id);
                    return 0;
            }
        }
        if (var_s2 != sp40) {
            var_s2 = sp40;
            UIElement_Draw(func_800E1B40_8A7360());
            UIElement_SetTextPos(func_800E1B40_8A7360(), 0, 0);
            UIText_SetShadowOffset(1);
            UIText_SetSpacing(-1, 3);
            UIElement_PrintText(func_800E1B40_8A7360(),
                                UILayout_GetButtonText(D_80195CEC_95B50C[func_800BFC5C_5CAFC()], D_80206B44_9CC364[sp40].id));
        }
        ohWait(1);
    }
}

s32 func_800E3774_8A8F94(void) {
    s32 i;
    s32 ret = 0;

    for (i = 0; i < 60; i++) {
        if (getAlbumPhoto(i) != 0) {
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
    UILayout_CreateButtons(func_800E3230_8A8A50());
    if (func_800E3774_8A8F94() == 0) {
        UILayout_DisableButton(1, 3);
    }
    FocusMark_SetTargetSize(0x3E, 0xD);
    ohWait(1);
    while (func_800A7460() != 0) {
        ohWait(1);
    }
    func_800E3264_8A8A84(NULL, &sp80);
    FocusMark_Show(true);

    while (true) {
        temp_v0_2 = func_800AA38C(0);
        func_800E3264_8A8A84(temp_v0_2, &sp80);
        if (temp_v0_2->pressedButtons & A_BUTTON) {
            auPlaySound(SOUND_ID_66);

            switch (D_80206B44_9CC364[sp80].id) {
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
            UIElement_Draw(func_800E1B40_8A7360());
            UIElement_SetTextPos(func_800E1B40_8A7360(), 0, 0);
            UIText_SetShadowOffset(1);
            UIText_SetSpacing(-1, 3);

            switch (D_80206B44_9CC364[sp80].id) {

                case 3:
                    for (numPics = 0, i = 0; i < 60; i++) {
                        if (getAlbumPhoto(i) != NULL) {
                            numPics++;
                        }
                    }

                    if (numPics != 0) {
                        if (numPics == 1) {
                            UIElement_PrintText(func_800E1B40_8A7360(), "Saved Picture");
                        } else {
                            UIElement_PrintText(func_800E1B40_8A7360(), "Saved Pictures");
                        }
                        UIElement_SetTextPos(func_800E1B40_8A7360(), 124, 0);
                        if (numPics == 1) {
                            sprintf(sp4C, "\\i%2d\\g picture", numPics);
                        } else {
                            sprintf(sp4C, "\\i%2d\\g pictures", numPics);
                        }
                        UIElement_PrintText(func_800E1B40_8A7360(), sp4C);
                        UIElement_SetTextPos(func_800E1B40_8A7360(), 0, 16);
                        UIElement_PrintText(func_800E1B40_8A7360(), "Space left for");
                        UIElement_SetTextPos(func_800E1B40_8A7360(), 124, 16);
                        spaceLeft = 60 - numPics;
                        if (spaceLeft == 1) {
                            sprintf(sp4C, "\\i%2d\\g picture", spaceLeft);
                        } else {
                            sprintf(sp4C, "\\i%2d\\g pictures", spaceLeft);
                        }
                        UIElement_PrintText(func_800E1B40_8A7360(), sp4C);
                    } else {
                        UIElement_PrintText(func_800E1B40_8A7360(), "Use the \"\\hAlbum Mark\\p \\u\" in\nthe Camera Check mode to\nsave pictures in your Album.");
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
                    UIElement_SetTextPos(func_800E1B40_8A7360(), 0, 0);
                    UIElement_PrintText(func_800E1B40_8A7360(), "No. of PKMN seen");
                    UIElement_SetTextPos(func_800E1B40_8A7360(), 0, 16);
                    UIElement_PrintText(func_800E1B40_8A7360(), "Report Score");
                    sprintf(sp4C, "\\i%8d\\g kind%s", numKinds, numKinds != 1 ? "s" : "");
                    UIElement_SetTextPos(func_800E1B40_8A7360(), 86, 0);
                    UIElement_PrintText(func_800E1B40_8A7360(), sp4C);
                    sprintf(sp4C, "\\i%8d\\g pts", numPts);
                    UIElement_SetTextPos(func_800E1B40_8A7360(), 86, 16);
                    UIElement_PrintText(func_800E1B40_8A7360(), sp4C);
                    break;
                default:
                    UIElement_PrintText(func_800E1B40_8A7360(), UILayout_GetButtonText(func_800E3230_8A8A50(), D_80206B44_9CC364[sp80].id));
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
    UIElement* sp2C;
    UNUSED s32 pad2;

    sp38 = 7;
    sp2C = func_800E1B40_8A7360();
    UIElement_Draw(sp2C);
    ohWait(1);
    UIElement_PrintText(sp2C, "Shall I save your progress?\n\\a Yes!   \\b No!");
    func_800E3264_8A8A84(func_800AA740(0), &sp38);
    FocusMark_Show(false);

    while (1) {
        temp_v1 = func_800AA38C(0)->pressedButtons;
        if (temp_v1 & 0x8000) {
            auPlaySoundWithParams(0xA0, 0x7FFF, 0x40, 0.75f, 0);
            auPlaySound(0x53);
            UIElement_Draw(sp2C);
            UIElement_SetTextPos(sp2C, 0, 32);
            UIElement_PrintText(sp2C, "\\eSaving...\\p");
            ohWait(48);
            auSetBGMVolumeSmooth(0, 0, 30);
            ohWait(33);
            if (checkPlayerFlag(PFID_ILLEGAL_COPY)) {
                D_80206B48_9CC368();
            }
            if (func_800BF244_5C0E4() != 0) {
                func_800E30B8_8A88D8();
            }
            auSetBGMVolumeSmooth(0, 0x7F00, 0x12);
            ohWait(21);
            UIElement_Draw(sp2C);
            UIElement_PrintText(sp2C, "Would you like to keep going?\n\\a Yes!  \\b No!");
            while (1) {
                temp_v1_2 = func_800AA38C(0)->pressedButtons;
                if (temp_v1_2 & 0x4000) {
                    auPlaySound(0x53);
                    UIElement_Draw(sp2C);
                    UIElement_PrintText(sp2C, "I'm looking forward to seeing\nyour new shots!");
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

s32 func_800E3ED4_8A96F4(void) {
    s32 temp_s0;
    UIElement* temp_s1;
    ucolor sp64;
    s32 levelID;
    s32 temp_v1;
    char sp44[0x18];
    s32 var_s0;

    var_s0 = 0;
    D_80206B40_9CC360 = func_800E3230_8A8A50();
    D_80206B44_9CC364 = UILayout_GetButtons();
    FocusMark_MoveFront();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);
    UILayout_SetInstantTransition(true);
    levelID = getLevelId();
    D_80195894_95B0B4 = levelID;
    if (levelID < 0 || levelID >= 7) {
        D_80195894_95B0B4 = 0;
    }
    UIText_SetPrintDelay(0);
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
                    FocusMark_Show(false);
                    func_800A7860(1, 0.2f);
                    UIFrame_SetStyle(func_800E1B4C_8A736C(), FRAME_STYLE_0);
                    UIFrame_GetBackgroundColor(func_800E1B4C_8A736C(), &sp64);
                    UIElement_SetColor(func_800E1B40_8A7360(), UI_BACKGROUND, sp64.r, sp64.g, sp64.b, 255);
                    UIElement_Draw(func_800E1B40_8A7360());
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
                        FocusMark_Show(false);
                        func_800A7860(1, 0.2f);
                        UIFrame_SetStyle(func_800E1B4C_8A736C(), FRAME_STYLE_1);
                        UIFrame_GetBackgroundColor(func_800E1B4C_8A736C(), &sp64);
                        UIElement_SetColor(func_800E1B40_8A7360(), UI_BACKGROUND, sp64.r, sp64.g, sp64.b, 255);
                        UIElement_Draw(func_800E1B40_8A7360());
                        func_800E1C18_8A7438(0);
                        func_800E60D8_8AB8F8(0);
                        func_800E61B4_8AB9D4(0, 0);
                        func_80375284_848A34(0);
                    }
                    break;
                }
                UIElement_Draw(func_800E1B40_8A7360());
                UIElement_SetTextPos(func_800E1B40_8A7360(), 0, 0);
                UIText_SetShadowOffset(1);
                UIText_SetSpacing(-1, 3);
                if (!checkPlayerFlag(PFID_11)) {
                    UIElement_PrintText(func_800E1B40_8A7360(), "Should I take this course?\n\\a Let's go!   \\b Maybe later.");
                } else {
                    temp_s1 = func_800E1B40_8A7360();
                    temp_s0 = func_803751F8_8489A8(D_80195894_95B0B4);
                    if (temp_s0 < func_800C0224_5D0C4(D_80195894_95B0B4)) {
                        UIElement_SetColor(temp_s1, UI_FOREGROUND, 255, 255, 0, 255);
                    } else {
                        UIElement_SetColor(temp_s1, UI_FOREGROUND, 255, 255, 255, 255);
                    }
                    UIElement_SetTextPos(temp_s1, 0, 0);
                    UIElement_PrintText(temp_s1, "HI-SCORE");
                    sprintf(sp44, "\\i%8d\\g pts", func_800C0224_5D0C4(D_80195894_95B0B4));
                    UIElement_SetTextPos(temp_s1, 96, 0);
                    UIElement_PrintText(temp_s1, sp44);
                    temp_s0 = func_803751F8_8489A8(D_80195894_95B0B4);
                    if (temp_s0 < func_800C0224_5D0C4(D_80195894_95B0B4)) {
                        UIElement_SetColor(temp_s1, UI_FOREGROUND, 255, 255, 255, 255);
                    } else {
                        UIElement_SetColor(temp_s1, UI_FOREGROUND, 255, 255, 0, 255);
                    }
                    UIElement_SetTextPos(temp_s1, 0, 16);
                    UIElement_PrintText(temp_s1, "CHALLENGE SCORE");
                    sprintf(sp44, "\\i%8d\\g pts", func_803751F8_8489A8(D_80195894_95B0B4));
                    UIElement_SetTextPos(temp_s1, 96, 32);
                    UIElement_PrintText(temp_s1, sp44);
                    UIElement_SetColor(temp_s1, UI_FOREGROUND, 255, 255, 255, 255);
                }
                func_800E1D1C_8A753C(0);
                func_800E1BF4_8A7414(0xFF);
                ohWait(1);

                while (true) {
                loop_28:
                    func_800E3264_8A8A84(func_800AA740(0), &D_80195894_95B0B4);
                    temp_v1 = func_800AA38C(0)->pressedButtons;
                    if (temp_v1 & 0x8000) {
                        auPlaySoundWithParams(0xA0, 0x7FFF, 0x40, 0.75f, 0);
                        func_800E61B4_8AB9D4(2, D_80195894_95B0B4);
                        return D_80195894_95B0B4;
                    }
                    if (temp_v1 & 0x4000) {
                        auPlaySound(SOUND_ID_67);
                        UILayout_DisableAllButtonsExcept(0, 0);
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
