#include "common.h"

#include "sys/vi.h"

extern GObj* D_800E8334_A0F8C4;
extern GObj* D_800E8340_A0F8D0;
extern GObj* D_800E8344_A0F8D4;
extern GObj* D_800E8348_A0F8D8;
extern GObj* D_800E834C_A0F8DC;
extern GObj* D_800E8350_A0F8E0;
extern GObj* D_800E8354_A0F8E4;
extern GObj* D_800E8358_A0F8E8;
extern GObj* D_800E835C_A0F8EC;
extern GObj* D_800E8360_A0F8F0;
extern s8 D_800E8374_A0F904;
extern s8 D_800E8375_A0F905;
extern SObj* D_800E8378_A0F908[]; // 5-6?
extern s8 D_800E8394_A0F924;
extern s8 D_800E8395_A0F925;
extern s8 D_800E8396_A0F926;
extern GObj* D_800E838C_A0F91C;
extern GObj* D_800E8390_A0F920;

extern Sprite D_80343B28;
extern Sprite D_80343C08;
extern Sprite D_80344388;
extern Sprite D_803444D8;
extern Sprite D_80344618;

void func_800E6C00_A0E190(SObj* sobj, u8 color) {
    sobj->sprite.red = color;
    sobj->sprite.green = color;
    sobj->sprite.blue = color;
}

void func_800E6C14_A0E1A4(SObj* sobj, u8 red, u8 green, u8 blue) {
    sobj->sprite.red = red;
    sobj->sprite.green = green;
    sobj->sprite.blue = blue;
}

void func_800E6C30_A0E1C0(void) {
}

void func_800E6C38_A0E1C8(GObj* gobj, s8 delta) {
    SObj* sobj = gobj->data.sobj;

    while (sobj != NULL) {
        sobj->sprite.x += delta;
        sobj->sprite.y += delta;
        sobj = sobj->next;
    }
}

void func_800E6C7C_A0E20C(void) {
    u8 i;

    for (i = 0; i < 12; i++) {
        func_800E6C38_A0E1C8(D_800E838C_A0F91C, 2);
        func_800E6C38_A0E1C8(D_800E8390_A0F920, -2);
        ohWait(1);
    }
}

void func_800E6CF0_A0E280(void) {
    u8 i;

    for (i = 0; i < 24; i++) {
        func_800E6C38_A0E1C8(D_800E838C_A0F91C, -2);
        func_800E6C38_A0E1C8(D_800E8390_A0F920, 2);
        ohWait(1);
    }
}

void func_800E6D64_A0E2F4(void) {
    GObj* gobj;
    SObj* sobj;

    D_800E838C_A0F91C = gobj = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1U, 0x80000000, -1,
                                              &D_80344388, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 0, -3);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80343B28);
    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 0, 0);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80344618);
    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 135, -24);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80343C08);
    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, -24, 95);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;

    D_800E8390_A0F920 = gobj = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_80344388, 0, NULL, 1);
    sobj = gobj->data.sobj;
    SET_SPRITE_POS(sobj->sprite, 48, 238);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80343B28);
    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 317, 48);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_803444D8);
    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 183, 234);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
    omGObjAddSprite(gobj, &D_80343C08);
    sobj = sobj->next;
    SET_SPRITE_POS(sobj->sprite, 313, 143);
    sobj->sprite.attr = SP_TEXSHUF | SP_TRANSPARENT;
}

void func_800E6F68_A0E4F8(void) {
    UNUSED s32 pad;
    UnkStruct800BEDF8 *temp_v0_2;
    s32 leftRightOrig;
    s32 topBottomOrig;
    s32 topBottom;
    s32 leftRightCur;
    s32 leftRight;
    s32 topBottomCur;

    leftRightCur = viEdgeOffsetLeft; topBottomCur = viEdgeOffsetTop;
    leftRightOrig = leftRightCur;
    topBottomOrig = topBottomCur;
    D_800E8348_A0F8D8->data.sobj->sprite.attr &= ~SP_HIDDEN;
    func_800E6D64_A0E2F4();
    func_800E6C7C_A0E20C();

    while (TRUE) {
        temp_v0_2 = func_800AA38C(0);

        if (gContInputPressedButtons & START_BUTTON) {
            leftRightCur = 0;
            topBottomCur = 0;
        } else if (gContInputPressedButtons & A_BUTTON) {
            auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1, 0);
            leftRight = leftRightCur;
            topBottom = topBottomCur;
            break;
        } else if (gContInputPressedButtons & B_BUTTON) {
            auPlaySoundWithParams(0x43, 0x7FFF, 0x40, 1.0f, 0);
            if (1) {
                // required to match
                leftRightCur = leftRightOrig;
                topBottomCur = topBottomOrig;
            }
            leftRight = leftRightCur;
            topBottom = topBottomCur;
            break;
        }

        if (temp_v0_2->unk_18 & 0x10000) {
            topBottomCur--;
        } else if (temp_v0_2->unk_18 & 0x20000) {
            topBottomCur++;
        }

        if (temp_v0_2->unk_18 & 0x80000) {
            leftRightCur--;
        } else if (temp_v0_2->unk_18 & 0x40000) {
            leftRightCur++;
        }

        if (leftRightCur < -12) {
            leftRightCur = -12;
        } else if (leftRightCur > 12) {
            leftRightCur = 12;
        }

        if (topBottomCur < -12) {
            topBottomCur = -12;
        } else if (topBottomCur > 12) {
            topBottomCur = 12;
        }
        viSetScreenOffsets(leftRightCur, leftRightCur, topBottomCur, topBottomCur);
        ohWait(1);
    }

    viSetScreenOffsets(leftRight, leftRight, topBottom, topBottomCur);
    func_800E6CF0_A0E280();
    D_800E8348_A0F8D8->data.sobj->sprite.attr |= SP_HIDDEN;
    omDeleteGObj(D_800E838C_A0F91C);
    omDeleteGObj(D_800E8390_A0F920);
    ohWait(1);
}

void func_800E71DC_A0E76C(void) {
    SObj* sobj;
    s8 i;

    D_800E8374_A0F904 = 0;
    D_800E8375_A0F905 = 0;
    sobj = D_800E8340_A0F8D0->data.sobj;
    i = 0;
    while (sobj != NULL) {
        D_800E8378_A0F908[i++] = sobj;
        func_800E6C00_A0E190(sobj, 0xFF);
        sobj = sobj->next;
    }
    D_800E8394_A0F924 = checkPlayerFlag(PFID_9);
    D_800E8395_A0F925 = checkPlayerFlag(PFID_ZOOM_SWITCH);
    D_800E8396_A0F926 = checkPlayerFlag(PFID_INVERTED_Y);
    if (D_800E8394_A0F924 == 0) {
        func_800E6C14_A0E1A4(D_800E8358_A0F8E8->data.sobj, 0xFF, 0x82, 0x41);
        func_800E6C00_A0E190(D_800E8358_A0F8E8->data.sobj->next, 0xFF);
    } else {
        func_800E6C00_A0E190(D_800E8358_A0F8E8->data.sobj, 0xFF);
        func_800E6C14_A0E1A4(D_800E8358_A0F8E8->data.sobj->next, 0xFF, 0x82, 0x41);
    }
    if (D_800E8395_A0F925 == 0) {
        func_800E6C14_A0E1A4(D_800E835C_A0F8EC->data.sobj, 0xFF, 0x82, 0x41);
        func_800E6C00_A0E190(D_800E835C_A0F8EC->data.sobj->next, 0xFF);
    } else {
        func_800E6C00_A0E190(D_800E835C_A0F8EC->data.sobj, 0xFF);
        func_800E6C14_A0E1A4(D_800E835C_A0F8EC->data.sobj->next, 0xFF, 0x82, 0x41);
    }
    if (D_800E8396_A0F926 == 0) {
        func_800E6C14_A0E1A4(D_800E8360_A0F8F0->data.sobj, 0xFF, 0x82, 0x41);
        func_800E6C00_A0E190(D_800E8360_A0F8F0->data.sobj->next, 0xFF);
        return;
    }
    func_800E6C00_A0E190(D_800E8360_A0F8F0->data.sobj, 0xFF);
    func_800E6C14_A0E1A4(D_800E8360_A0F8F0->data.sobj->next, 0xFF, 0x82, 0x41);
}

void func_800E7408_A0E998(void) {
    SObj* sobj = D_800E8334_A0F8C4->data.sobj;
    u8 color;

    for (color = 0xFF; color > 0x66; color -= 5) {
        func_800E6C00_A0E190(sobj, color);
        ohWait(1);
    }

    func_800E6C00_A0E190(sobj, 0x66);
    ohWait(1);
}

void func_800E7478_A0EA08(GObj* arg0) {
    SObj* sobj;
    u8 state;
    u8 counter;
    s8 var_s0;

    counter = 0;
    state = 0;
    var_s0 = D_800E8374_A0F904;

    while (TRUE) {
        if (var_s0 != D_800E8374_A0F904) {
            func_800E6C00_A0E190(D_800E8378_A0F908[var_s0], 0xFF);
            counter = 0;
            state = 0;
        }
        sobj = D_800E8378_A0F908[D_800E8374_A0F904];

        switch (state) {
            case 0:
                if (sobj->sprite.red >= 0x84) {
                    sobj->sprite.red -= 4;
                    func_800E6C00_A0E190(sobj, sobj->sprite.red);
                } else {
                    func_800E6C00_A0E190(sobj, 0x80);
                    state++;
                }
                break;
            case 1:
                if (sobj->sprite.red < 0xE2) {
                    sobj->sprite.red += 0x1E;
                    func_800E6C00_A0E190(sobj, sobj->sprite.red);
                } else {
                    counter = 0;
                    func_800E6C00_A0E190(sobj, 0xFF);
                    state++;
                }
                break;
            case 2:
                if (counter++ > 30) {
                    state = 0;
                }
                break;
        }

        var_s0 = D_800E8374_A0F904;
        ohWait(1);
    }
}

void func_800E7604_A0EB94(GObj* arg0) {
    UNUSED s32 pad;
    SObj* sobj;
    s8 var_s1;
    s8 i;
    SObj* sp34[4];

    sobj = D_800E8344_A0F8D4->data.sobj;
    i = 0;
    while (sobj != NULL) {
        sp34[i] = sobj;
        sobj->sprite.attr |= SP_HIDDEN;
        sobj = sobj->next;
        i++;
    }

    var_s1 = D_800E8374_A0F904;
    while (TRUE) {
        if (var_s1 != D_800E8374_A0F904) {
            sp34[var_s1]->sprite.attr |= SP_HIDDEN;
        }
        sp34[D_800E8374_A0F904]->sprite.attr &= ~SP_HIDDEN;
        var_s1 = D_800E8374_A0F904;
        ohWait(1);
    }
}

s8 func_800E7700_A0EC90(void) {
    UNUSED s32 pad;
    GObj* gobj;
    UnkStruct800BEDF8* temp_v0_2;
    s32 pressedB;
    SObj* sobj;

    gobj = omAddGObj(0xE, NULL, 0, 0x80000000);
    omCreateProcess(gobj, func_800E7478_A0EA08, 0, 1);
    omCreateProcess(gobj, func_800E7604_A0EB94, 0, 1);
    ohWait(1);

    while (TRUE) {
        temp_v0_2 = func_800AA38C(0);
        if (gContInputPressedButtons & A_BUTTON) {
            auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
            pressedB = FALSE;
            break;
        } else if (gContInputPressedButtons & B_BUTTON) {
            auPlaySoundWithParams(0x43, 0x7FFF, 0x40, 1.0f, 0);
            pressedB = TRUE;
            break;
        } else {
            if (temp_v0_2->unk_18 & 0x10000) {
                auPlaySoundWithParams(0x41, 0x7FFF, 0x40, 1.0f, 0);
                D_800E8374_A0F904--;
                if (D_800E8374_A0F904 < 0) {
                    D_800E8374_A0F904 = 4;
                }
            } else if (temp_v0_2->unk_18 & 0x20000) {
                auPlaySoundWithParams(0x41, 0x7FFF, 0x40, 1.0f, 0);
                D_800E8374_A0F904++;
                D_800E8374_A0F904 %= 5;
            }
            ohWait(1);
        }
    }

    sobj = D_800E8344_A0F8D4->data.sobj;
    while (sobj != NULL) {
        sobj->sprite.attr |= SP_HIDDEN;
        sobj = sobj->next;
    }
    omDeleteGObj(gobj);
    ohWait(1);
    func_800E6C14_A0E1A4(D_800E8378_A0F908[D_800E8374_A0F904], 0xFF, 0x82, 0x41);
    ohWait(1);
    if (!pressedB) {
        return D_800E8374_A0F904;
    }
    return 4;
}

void func_800E7950_A0EEE0(GObj* arg0) {
    u8 color;
    u8 state;
    u8 var_s0;
    SObj* sobj;
    SObj* sp40[2];

    var_s0 = D_800E8375_A0F905;
    state = 0;
    color = 0x80;
    switch (D_800E8374_A0F904) {
        case 1:
            sobj = D_800E8358_A0F8E8->data.sobj;
            break;
        case 2:
            sobj = D_800E835C_A0F8EC->data.sobj;
            break;
        case 3:
            sobj = D_800E8360_A0F8F0->data.sobj;
            break;
    }
    sp40[0] = sobj;
    sp40[1] = sobj->next;

    while (TRUE) {
        if (var_s0 != D_800E8375_A0F905) {
            func_800E6C00_A0E190(sp40[var_s0], 0xFF);
            color = 0xFF;
            state = 0;
        }
        sobj = sp40[D_800E8375_A0F905];

        switch (state) {
            case 0:
                if (color >= 0x84) {
                    func_800E6C00_A0E190(sobj, color);
                    color -= 4;
                } else {
                    func_800E6C00_A0E190(sobj, 0x80);
                    color = 0x80;
                    state++;
                }
                break;
            case 1:
                if (color < 0xE2) {
                    func_800E6C00_A0E190(sobj, color);
                    color += 0x1E;
                } else {
                    func_800E6C00_A0E190(sobj, 0xFF);
                    color = 0;
                    state++;
                }
                break;
            case 2:
                if (color++ > 30) {
                    color = 0xFF;
                    state = 0;
                }
                break;
        }

        var_s0 = D_800E8375_A0F905;
        ohWait(1);
    }
}

void func_800E7B24_A0F0B4(GObj* arg0) {
    s8 var_s2;
    SObj* var_v0;
    SObj* sp38[2];

    var_s2 = D_800E8375_A0F905;
    switch (D_800E8374_A0F904) {
        case 1:
            var_v0 = D_800E834C_A0F8DC->data.sobj;
            break;
        case 2:
            var_v0 = D_800E8350_A0F8E0->data.sobj;
            break;
        case 3:
            var_v0 = D_800E8354_A0F8E4->data.sobj;
            break;
    }
    sp38[0] = var_v0;
    sp38[1] = var_v0->next;

    while (TRUE) {
        if (var_s2 != D_800E8375_A0F905) {
            sp38[var_s2]->sprite.attr |= SP_HIDDEN;
        }
        sp38[D_800E8375_A0F905]->sprite.attr &= ~SP_HIDDEN;
        var_s2 = D_800E8375_A0F905;
        ohWait(1);
    }
}

void func_800E7C40_A0F1D0(void) {
    u8 setting;
    u8 settingInv;
    GObj* gobj;
    SObj* sobj;
    SObj* sp44[2];
    UnkStruct800BEDF8* temp_v0_2;

    switch (D_800E8374_A0F904) {
        case 1:
            sobj = D_800E8358_A0F8E8->data.sobj;
            D_800E8375_A0F905 = D_800E8394_A0F924;
            break;
        case 2:
            sobj = D_800E835C_A0F8EC->data.sobj;
            D_800E8375_A0F905 = D_800E8395_A0F925;
            break;
        case 3:
            sobj = D_800E8360_A0F8F0->data.sobj;
            D_800E8375_A0F905 = D_800E8396_A0F926;
            break;
    }

    sp44[0] = sobj;
    sp44[1] = sobj->next;
    gobj = omAddGObj(0xE, NULL, 0, 0x80000000);
    omCreateProcess(gobj, func_800E7950_A0EEE0, 0, 1);
    omCreateProcess(gobj, func_800E7B24_A0F0B4, 0, 1);
    setting = D_800E8375_A0F905;
    ohWait(1);

    while (TRUE) {
        temp_v0_2 = func_800AA38C(0);
        if (gContInputPressedButtons & A_BUTTON) {
            auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
            break;
        } else if (gContInputPressedButtons & B_BUTTON) {
            auPlaySoundWithParams(0x43, 0x7FFF, 0x40, 1.0f, 0);
            D_800E8375_A0F905 = setting;
            if (D_800E8374_A0F904 == 1) {
                auSetSoundQuality(!D_800E8375_A0F905);
            }
            break;
        } else {
            if (temp_v0_2->unk_18 & 0x80000) {
                auPlaySoundWithParams(0x41, 0x7FFF, 0x40, 1.0f, 0);
                D_800E8375_A0F905 = 0;
            } else if (temp_v0_2->unk_18 & 0x40000) {
                auPlaySoundWithParams(0x41, 0x7FFF, 0x40, 1.0f, 0);
                D_800E8375_A0F905 = 1;
            }
            if (D_800E8374_A0F904 == 1 && temp_v0_2->unk_18 & (0x80000 | 0x40000)) {
                auSetSoundQuality(!D_800E8375_A0F905);
            }
            ohWait(1);
        }
    }

    switch (D_800E8374_A0F904) {
        case 1:
            D_800E8394_A0F924 = D_800E8375_A0F905;
            sobj = D_800E834C_A0F8DC->data.sobj;
            break;
        case 2:
            D_800E8395_A0F925 = D_800E8375_A0F905;
            sobj = D_800E8350_A0F8E0->data.sobj;
            break;
        case 3:
            D_800E8396_A0F926 = D_800E8375_A0F905;
            sobj = D_800E8354_A0F8E4->data.sobj;
            break;
    }
    sobj->sprite.attr |= SP_HIDDEN;
    sobj->next->sprite.attr |= SP_HIDDEN;
    omDeleteGObj(gobj);
    ohWait(1);
    setting = D_800E8375_A0F905;
    func_800E6C14_A0E1A4(sp44[setting], 0xFF, 0x82, 0x41);
    setting ^= 1;
    settingInv = setting;
    func_800E6C00_A0E190(sp44[settingInv], 0xFF);
    ohWait(1);
}

void func_800E7F98_A0F528(void) {
    s32 cond;
    u32 temp_v0;

    func_800E71DC_A0E76C();
    func_800E7408_A0E998();
    auSetBGMVolume(0, 0x7F00);
    auPlaySong(0, 0x1B);

    do {
        cond = FALSE;
        temp_v0 = func_800E7700_A0EC90();
        switch (temp_v0) {
        case 0:
            func_800E6F68_A0E4F8();
            break;
        case 1:
        case 2:
        case 3:
            func_800E7C40_A0F1D0();
            break;
        case 4:
            func_800BFB90_5CA30(viEdgeOffsetLeft, viEdgeOffsetTop);
            setPlayerFlag(PFID_9, D_800E8394_A0F924);
            setPlayerFlag(PFID_ZOOM_SWITCH, D_800E8395_A0F925);
            setPlayerFlag(PFID_INVERTED_Y, D_800E8396_A0F926);
            cond = TRUE;
            break;
        }
    } while (!cond);

    auSetBGMVolumeSmooth(0, 0, 30);
    ohWait(30);
    auStopBGM();
}
