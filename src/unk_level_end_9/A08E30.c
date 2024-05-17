#include "common.h"

#include "unk_level_end_9.h"

typedef struct PanData {
    /* 0x00 */ s32 data[4];
} PanData;

typedef struct YValues {
    /* 0x00 */ s16 data[3][4];
} YValues;

extern s8 D_800E80D0_A0F660;
extern PanData D_800E80D4_A0F664;
extern YValues D_800E80E4_A0F674;
extern ScreenSettings D_800E80FC_A0F68C;
extern Gfx D_800E8130_A0F6C0[];
extern SceneSetup D_800E8188_A0F718;
extern s32 D_800E8198_A0F728;
extern GObj* D_800E82A4_A0F834;
extern GObj* D_800E82A8_A0F838;
extern GObj* D_800E82AC_A0F83C;
extern GObj* D_800E82B8_A0F848;
extern GObj* D_800E82B0_A0F840;
extern GObj* D_800E82B4_A0F844;
extern GObj* D_800E82BC_A0F84C;
extern GObj* D_800E82C0_A0F850;
extern GObj* D_800E82C4_A0F854;
extern GObj* D_800E82C8_A0F858;
extern GObj* D_800E82CC_A0F85C;
extern GObj* D_800E82D0_A0F860;
extern GObj* D_800E82D4_A0F864;
extern GObj* D_800E82D8_A0F868;
extern GObj* D_800E82DC_A0F86C;
extern GObj* D_800E82E0_A0F870;
extern u8 D_800E82E4_A0F874;
extern u32 D_800E82E8_A0F878;
extern u8 D_800E82EC_A0F87C;
extern s8 D_800E82ED_A0F87D;
extern s32 D_800E83A0;

extern Sprite D_802DABC0;
extern Sprite D_802DB328;
extern Sprite D_802DB588;
extern Sprite D_802DBCE8;
extern Sprite D_802DC1A8;
extern Sprite D_802DC718;
extern Sprite D_802DC978;
extern Sprite D_802DCE88;
extern Sprite D_802DFAB0;
extern Sprite D_802E8DD0;
extern Sprite D_802F20F0;
extern Sprite D_802F4828;
extern Sprite D_802F6490;
extern Sprite D_802F82C8;
extern Sprite D_80309770;
extern Sprite D_8030A4E0;
extern Sprite D_8030B250;
extern Sprite D_8030BFC0;
extern Sprite D_8030E020;
extern Sprite D_80310080;
extern Sprite D_803120E0;
extern Sprite D_8034B020;
extern Sprite D_8034B920;
extern Sprite D_8034BBB8;
extern Sprite D_8034C4B0;
extern Sprite D_8034C710;
extern Sprite D_8034D3A0;
extern Sprite D_8034FAD8;

// same file (needs to be declared early)
s32 func_800E3E28_A0B3B8(void);

void func_800E18A0_A08E30(SObj* sobj, u16 attr) {
    sobj->sprite.attr = attr;
}

void func_800E18AC_A08E3C(SObj* sobj, u8 hide) {
    if (!hide) {
        sobj->sprite.attr |= SP_HIDDEN;
    } else {
        sobj->sprite.attr &= ~SP_HIDDEN;
    }
}

void func_800E18E0_A08E70(SObj* sobj, u8 red, u8 green, u8 blue) {
    sobj->sprite.red = red;
    sobj->sprite.green = green;
    sobj->sprite.blue = blue;
}

void func_800E18FC_A08E8C(SObj* sobj, s16 x, s16 y) {
    sobj->sprite.x = x;
    sobj->sprite.y = y;
}

void func_800E1920_A08EB0(void) {

}

void func_800E1928_A08EB0(void) {

}

void func_800E1930_A08EC0(u8 arg0, u8 arg1, u8 arg2, u8 arg3, f32 arg4) {
    u16 i;

    func_800A7470(arg1, arg2, arg3);
    if (arg0 == 0) {
        func_800A7860(1, arg4);
    } else if (arg0 == 1) {
        func_800A7860(0, arg4);
    }

    for (i = 0; i < (u16) (arg4 * 60.0f); i++) {
        ohWait(1);
    }
}

void func_800E1A68_A08FF8(void) {
    SObj* sobj = D_800E82B0_A0F840->data.sobj;
    u8 newColor;

    while (TRUE) {
        newColor = (u64) (sobj->sprite.blue + 5); // TODO: u64 cast required to match
        sobj->sprite.blue = newColor;
        sobj->sprite.green = newColor;
        sobj->sprite.red = newColor;
        if ((newColor & 0xFF) > 250) {
            break;
        }
        ohWait(1);
    }

    sobj->sprite.red = sobj->sprite.green = sobj->sprite.blue = 0xFF;
}

void func_800E1AD4_A09064(void) {
    D_800E82EC_A0F87C = 1;
}

void func_800E1AE4_A09074(void) {
}

void func_800E1AEC_A0907C(void) {
    D_800E82EC_A0F87C = 2;
    D_800E82E8_A0F878 = 0;
}

void func_800E1B04_A09094(GObj* gobj) {
    while (TRUE) {
        if (D_800E82EC_A0F87C == 1 && D_800E82E8_A0F878 < 1800) {
            D_800E82E8_A0F878++;
        }
        ohWait(1);
    }
}

void func_800E1B78_A09108(u8 arg0) {
    if (!arg0) {
        auSetBGMVolumeSmooth(0, 0, 60);
        func_800E1930_A08EC0(1, 0, 0, 0, 1.0f);
    } else {
        auSetBGMVolumeSmooth(0, 0, 30);
        ohWait(30);
    }
    omDeleteGObj(D_800E82B0_A0F840);
    omDeleteGObj(D_800E82BC_A0F84C);
    omDeleteGObj(D_800E82C0_A0F850);
    omDeleteGObj(D_800E82C4_A0F854);
    if (D_800BF051 == 0) {
        omDeleteGObj(D_800E82C8_A0F858);
        omDeleteGObj(D_800E82CC_A0F85C);
        if (D_800E82ED_A0F87D != 0) {
            omDeleteGObj(D_800E82D0_A0F860);
            omDeleteGObj(D_800E82DC_A0F86C);
        }
        if (D_800E80D0_A0F660 == 1) {
            omDeleteGObj(D_800E82D4_A0F864);
        }
        omDeleteGObj(D_800E82D8_A0F868);
    } else {
        omDeleteGObj(D_800E82E0_A0F870);
    }
}

void func_800E1CAC_A0923C(void) {
    func_800C042C_5D2CC();
}

// Returns whether you've caught(?) more than 3 pokemon
s32 func_800E1CCC_A0925C(void) {
    u16 sum = 0;
    s32 ret;
    u16 i;

    for (i = 0; i < PokemonID_MEW; i++) {
        if (func_800BF710_5C5B0(i) != NULL) {
            sum++;
        }
    }

    if (sum > 3) {
        ret = TRUE;
    } else {
        ret = FALSE;
    }
    return ret;
}

void func_800E1D3C_A092CC(void) {
}

void func_800E1D44_A092D4(u8 arg0) {
    SObj* sobj;
    GObj* gobj;

    D_800E82B0_A0F840 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                       &D_802DABC0, 0, NULL, 1);
    sobj = D_800E82B0_A0F840->data.sobj;
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_TRANSPARENT);
    if (arg0 == 0xD) {
        func_800E18E0_A08E70(sobj, 0xFF, 0xFF, 0xFF);
    } else if (arg0 == 0xC) {
        func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
    }
}

void func_800E1E10_A093A0(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E82B4_A0F844 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_802DB328, 0, NULL, 1);

    sobj = gobj->data.sobj;
    func_800E18FC_A08E8C(sobj, 42, 51);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT);
    sobj->sprite.scalex = 1.2f;
    sobj->sprite.scaley = 1.2f;
    omGObjAddSprite(gobj, &D_802DB588);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 67, 60);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT);
    sobj->sprite.scalex = 1.2f;
    sobj->sprite.scaley = 1.2f;
    omGObjAddSprite(gobj, &D_802DBCE8);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 78, 48);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT);
    sobj->sprite.scalex = 1.2f;
    sobj->sprite.scaley = 1.2f;
    omGObjAddSprite(gobj, &D_802DC1A8);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 98, 39);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT);
    sobj->sprite.scalex = 1.2f;
    sobj->sprite.scaley = 1.2f;
    omGObjAddSprite(gobj, &D_802DC718);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 117, 46);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT);
    sobj->sprite.scalex = 1.2f;
    sobj->sprite.scaley = 1.2f;
    omGObjAddSprite(gobj, &D_802DC978);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 134, 55);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT);
    sobj->sprite.scalex = 1.2f;
    sobj->sprite.scaley = 1.2f;
    omGObjAddSprite(gobj, &D_802DCE88);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 146, 48);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT);
    sobj->sprite.scalex = 1.2f;
    sobj->sprite.scaley = 1.2f;
    omGObjAddSprite(gobj, &D_802DFAB0);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 166, 53);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_SCALE | SP_HIDDEN | SP_TRANSPARENT);
    sobj->sprite.scalex = 1.2f;
    sobj->sprite.scaley = 1.2f;
}

void func_800E2058_A095E8(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E82BC_A0F84C = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_802F20F0, 0, NULL, 1);
    sobj = gobj->data.sobj;

    func_800E18FC_A08E8C(sobj, 35, 35);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_TRANSPARENT);
    omGObjAddSprite(gobj, &D_802F82C8);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 74, 198);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_TRANSPARENT);
}

void func_800E212C_A096BC(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E82C0_A0F850 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_80309770, 0, NULL, 1);
    sobj = gobj->data.sobj;

    func_800E18FC_A08E8C(sobj, 0, 172);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    omGObjAddSprite(gobj, &D_8030A4E0);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 0, 172);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    omGObjAddSprite(gobj, &D_8030B250);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 0, 172);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    omGObjAddSprite(gobj, &D_8030BFC0);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 0, 172);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);

    gobj = D_800E82C4_A0F854 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                               &D_8030E020, 0, NULL, 1);
    sobj = gobj->data.sobj;

    func_800E18FC_A08E8C(sobj, 0, 150);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    omGObjAddSprite(gobj, &D_80310080);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 0, 150);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    omGObjAddSprite(gobj, &D_803120E0);

    sobj = sobj->next;
    func_800E18FC_A08E8C(sobj, 0, 150);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
}

void func_800E2348_A098D8(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E82C8_A0F858 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                          &D_802F4828, 0, NULL, 1);
    sobj = gobj->data.sobj;

    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
}

void func_800E23E4_A09974(void) {
    SObj* sobj;
    GObj* gobj;

    gobj = D_800E82CC_A0F85C = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                          &D_8034B920, 0, NULL, 1);
    if (1) { } if (1) { } if (1) { } // TODO 3 if 1s required to match
    sobj = gobj->data.sobj;

    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
}

void func_800E2480_A09A10(void) {
    SObj* sobj;
    GObj* gobj;

    gobj = D_800E82D0_A0F860 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                          &D_8034C4B0, 0, NULL, 1);
    if (1) { } if (1) { } if (1) { } // TODO 3 if 1s required to match
    sobj = gobj->data.sobj;

    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
}

void func_800E251C_A09AAC(void) {
    SObj* sobj;
    GObj* gobj;

    gobj = D_800E82D4_A0F864 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                          &D_8034D3A0, 0, NULL, 1);
    if (1) { } if (1) { } if (1) { } // TODO 3 if 1s required to match
    sobj = gobj->data.sobj;

    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
}

void func_800E25B8_A09B48(void) {
    SObj* sobj;
    GObj* gobj;

    gobj = D_800E82D8_A0F868 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                          &D_802F6490, 0, NULL, 1);
    if (1) { } if (1) { } if (1) { } // TODO 3 if 1s required to match
    sobj = gobj->data.sobj;

    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
}

void func_800E2654_A09BE4(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E82DC_A0F86C = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                                              &D_8034B020, 0, NULL, 1);
    sobj = gobj->data.sobj;

    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18FC_A08E8C(sobj, 0x28, 0x83);
    omGObjAddSprite(gobj, &D_8034BBB8);

    sobj = sobj->next;
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
    func_800E18FC_A08E8C(sobj, 170, 172);
    omGObjAddSprite(gobj, &D_8034C710);

    sobj = sobj->next;
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
    func_800E18FC_A08E8C(sobj, 124, 172);
}

void func_800E2780_A09D10(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = D_800E82E0_A0F870 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1,
                          &D_8034FAD8, 0, NULL, 1);
    sobj = gobj->data.sobj;

    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_HIDDEN | SP_TRANSPARENT);
    func_800E18E0_A08E70(sobj, 0x80, 0x80, 0x80);
}

void func_800E281C_A09DAC(void) {
    switch (D_800BF051) {
        case 0:
            D_800E82ED_A0F87D = func_800BFCA0_5CB40(0x10);
            func_800E2348_A098D8();
            func_800E23E4_A09974();
            D_800E80D0_A0F660 = func_800E1CCC_A0925C();
            if (D_800E80D0_A0F660 == TRUE) {
                func_800E251C_A09AAC();
            }
            func_800E25B8_A09B48();
            if (D_800E82ED_A0F87D != 0) {
                func_800E2480_A09A10();
                func_800E2654_A09BE4();
            }
            break;
        case -1:
            func_800E2780_A09D10();
            break;
    }
}

void func_800E28CC_A09E5C(void) {
    UnkStruct800BEDF8* temp_v0;
    PanData pan;
    s32 reverb;
    f32 temp_f0;
    SObj* sobj;
    GObj* gobj;
    u8 j;
    u8 i;
    f32 x;
    f32 y;

    reverb = 0;
    pan = D_800E80D4_A0F664;
    gobj = D_800E82B4_A0F844;
    sobj = gobj->data.sobj;

    for (i = 0; i < 8; i++) {
        x = sobj->sprite.x + (sobj->sprite.width / 2);
        y = sobj->sprite.y + (sobj->sprite.height / 2);

        func_800E18AC_A08E3C(sobj, TRUE);

        for (j = 0; j < 6; j++) {
            temp_v0 = func_800AA38C(0);
            if (temp_v0->unk_18 & (0x8000 | 0x1000)) {
                break;
            }
            temp_f0 = 1.2 - ((j * 0.2) / 5.0);
            sobj->sprite.scaley = temp_f0;
            sobj->sprite.scalex = temp_f0;
            func_800E18FC_A08E8C(
                sobj,
                x - (sobj->sprite.width * temp_f0 * 0.5),
                y - (sobj->sprite.height * temp_f0 * 0.5)
            );
            ohWait(1);
        }

        if (i == 6) {
            reverb = 10;
        }
        if (temp_v0->unk_18 & (0x8000 | 0x1000)) {
            break;
        }
        if (!(i & 1)) {
            auPlaySoundWithParams(0, 0x7FFF, pan.data[i / 2], 1.0f, reverb);
        }
        sobj = sobj->next;
    }
    ohRemoveSprite(gobj);
    omGObjAddSprite(gobj, &D_802E8DD0);

    sobj = gobj->data.sobj;
    func_800E18FC_A08E8C(sobj, 35, 35);
    func_800E18A0_A08E30(sobj, SP_TEXSHUF | SP_TRANSPARENT);
    func_800E1930_A08EC0(1, 0xFF, 0xFF, 0xFF, 17.0f / 120.0f);
    omDeleteGObj(gobj);
    omDeleteGObj(D_800E82B0_A0F840);
}

void func_800E2BD8_A0A168(u8 arg0) {
    auSetBGMVolume(0, 0x7F00);
    auSetBGMVolume(1, 0x7F00);
    auPlaySong(0, 0x17);

    if (arg0 == 0xD) {
        func_800E1930_A08EC0(0, 0xFF, 0xFF, 0xFF, 1.0f);
    } else if (arg0 == 0xC) {
        func_800E1A68_A08FF8();
    }
}

void func_800E2C60_A0A1F0(GObj* gobj) {
    SObj* sobj;
    f32 x;
    u8 var_s1;
    u8 var_s2;

    x = 287.0f;
    sobj = gobj->data.sobj;
    var_s2 = 0;
    var_s1 = 0;
    sobj->sprite.x = x;

    while (TRUE) {
        var_s2++;
        if ((var_s2 % 4) == 0) {
            func_800E18AC_A08E3C(sobj, FALSE);
            if (var_s1 != 3) {
                sobj->next->sprite.x = sobj->sprite.x;
                sobj = sobj->next;
            } else {
                gobj->data.sobj->sprite.x = sobj->sprite.x;
                sobj = gobj->data.sobj;
            }
            func_800E18AC_A08E3C(sobj, TRUE);
            var_s1++;
            var_s1 %= 4;
        }

        if (sobj->sprite.x > -32) {
            x -= 0.5f;
            sobj->sprite.x = x;
            ohWait(1);
        } else {
            break;
        }
    }

    sobj = gobj->data.sobj;
    while (sobj != NULL) {
        func_800E18AC_A08E3C(sobj, FALSE);
        sobj = sobj->next;
    }

    while (TRUE) {
        ohWait(1);
    }
}

void func_800E2DC8_A0A358(GObj* gobj) {
    SObj* sobj;
    u8 var_s1;
    u8 var_s2;

    sobj = gobj->data.sobj;
    var_s2 = 0;
    var_s1 = 0;
    sobj->sprite.x = 671;

    while (TRUE) {
        var_s2++;
        if ((var_s2 % 4) == 0) {
            func_800E18AC_A08E3C(sobj, FALSE);
            if (var_s1 != 2) {
                sobj->next->sprite.x = sobj->sprite.x;
                sobj = sobj->next;
            } else {
                gobj->data.sobj->sprite.x = sobj->sprite.x;
                sobj = gobj->data.sobj;
            }
            func_800E18AC_A08E3C(sobj, TRUE);
            var_s1++;
            var_s1 %= 3;
        }

        if (sobj->sprite.x > -32) {
            sobj->sprite.x--;
            ohWait(1);
        } else {
            break;
        }
    }

    sobj = gobj->data.sobj;
    while (sobj != NULL) {
        func_800E18AC_A08E3C(sobj, FALSE);
        sobj = sobj->next;
    }

    while (TRUE) {
        ohWait(1);
    }
}


void func_800E2F24_A0A4B4(void) {
    omCreateProcess(D_800E82C0_A0F850, func_800E2C60_A0A1F0, 0, 1);
    omCreateProcess(D_800E82C4_A0F854, func_800E2DC8_A0A358, 0, 1);
}

void func_800E2F74_A0A504(GObj* gobj) {
    u8 counter;
    u8 color;
    u8 state;
    SObj* sobj;

    sobj = gobj->data.sobj;
    state = 0;
    func_800E18E0_A08E70(sobj, 0, 0, 0);

    while (TRUE) {
        switch (state) {
            case 0:
                color += 5;
                func_800E18E0_A08E70(sobj, color, color, color);
                if (sobj->sprite.red > 250) {
                    color = 0xFF;
                    func_800E18E0_A08E70(sobj, color, color, color);
                    counter = 0;
                    state++;
                }
                break;
            case 1:
                counter++;
                if (counter == 120) {
                    state++;
                }
                break;
            case 2:
                color -= 5;
                func_800E18E0_A08E70(sobj, color, color, color);
                if (sobj->sprite.red < 0x80) {
                    color = 0x80;
                    func_800E18E0_A08E70(sobj, color, color, color);
                    state = 0;
                }
                break;
        }
        ohWait(1);
    }
}

s32 func_800E30EC_A0A67C(s8 arg0) {
    UnkStruct800BEDF8* temp_v0;
    SObj* sobj;
    s32 ret;

    sobj = D_800E82C8_A0F858->data.sobj;
    func_800E18FC_A08E8C(sobj, 59, 147);
    omCreateProcess(D_800E82C8_A0F858, func_800E2F74_A0A504, 0, 1);
    func_800E18AC_A08E3C(sobj, TRUE);

    while (TRUE) {
        temp_v0 = func_800AA38C(0);
        if (temp_v0->unk_18 != 0) {
            func_800E1AEC_A0907C();
            func_800E1AD4_A09064();
        }

        if (D_800E82E8_A0F878 >= 1800 && D_800BF051 == 0) {
            func_800E1B78_A09108(FALSE);
            if (arg0 == 0xF) {
                ret = 0xB;
            } else {
                ret = 0xA;
            }
            break;
        } else if (temp_v0->unk_18 & 0x9000) {
            ret = 3;
            break;
        } else {
            ohWait(1);
        }
    }

    func_800E18AC_A08E3C(sobj, FALSE);
    ohEndAllObjectProcesses(D_800E82C8_A0F858);
    if (ret == 3) {
        auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
    }
    return ret;
}

void func_800E3240_A0A7D0(GObj* gobj) {
    u8 color;
    u8 counter;
    u8 state;
    SObj* sobj;

    sobj = gobj->data.sobj;
    state = 0;
    color = 0xFF;
    func_800E18E0_A08E70(sobj, color, color, color);

    while (TRUE) {
        switch (state) {
            case 0:
                if (sobj->sprite.red < 226) {
                    color += 30;
                    func_800E18E0_A08E70(sobj, color, color, color);
                } else {
                    color = 0xFF;
                    func_800E18E0_A08E70(sobj, color, color, color);
                    counter = 0;
                    state++;
                }
                break;
            case 1:
                if (counter++ > 30) {
                    state++;
                }
                break;
            case 2:
                if (sobj->sprite.red >= 132) {
                    color -= 4;
                    func_800E18E0_A08E70(sobj, color, color, color);
                } else {
                    color = 0x80;
                    func_800E18E0_A08E70(sobj, color, color, color);
                    state = 0;
                }
                break;
        }
        ohWait(1);
    }
}


u8 func_800E33C8_A0A958(GObj** gobjs) {
    u8 ret;
    u8 sp4E;
    YValues yVals = D_800E80E4_A0F674;

    ret = 0;

    if (D_800E82ED_A0F87D == 0) {
        sp4E = 0;
    } else if (D_800E80D0_A0F660 == FALSE) {
        sp4E = 1;
    } else if (D_800E80D0_A0F660 == TRUE) {
        sp4E = 2;
    }

    switch (sp4E) {
        case 0:
            gobjs[ret] = D_800E82CC_A0F85C;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 127, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;

            gobjs[ret] = D_800E82D8_A0F868;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 128, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;
            break;
        case 1:
            gobjs[ret] = D_800E82CC_A0F85C;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 127, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;

            gobjs[ret] = D_800E82D0_A0F860;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 128, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;

            gobjs[ret] = D_800E82D8_A0F868;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 128, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;
            break;
        case 2:
            gobjs[ret] = D_800E82CC_A0F85C;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 127, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;

            gobjs[ret] = D_800E82D0_A0F860;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 128, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;

            gobjs[ret] = D_800E82D4_A0F864;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 116, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;

            gobjs[ret] = D_800E82D8_A0F868;
            func_800E18FC_A08E8C(gobjs[ret]->data.sobj, 128, yVals.data[sp4E][ret]);
            func_800E18AC_A08E3C(gobjs[ret]->data.sobj, TRUE);
            func_800E18E0_A08E70(gobjs[ret]->data.sobj, 0xC0, 0xC0, 0);
            ret++;
            break;
    }
    return ret;
}

s32 func_800E37E8_A0AD78(s32 arg0, s8 arg1) {
    if (D_800E82ED_A0F87D == 0) {
        switch (arg1) {
            case 0:
                auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
                func_800E1B78_A09108(1);
                return 6;
            case 1:
                auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
                func_800E1B78_A09108(1);
                return 8;
        }
    } else {
        switch (arg1) {
            case 0:
                if (func_800E3E28_A0B3B8() == 6) {
                    func_800E1B78_A09108(1);
                    return 6;
                } else {
                    return 4;
                }
            case 1:
                auPlaySoundWithParams(0x40, 0x7FFF, 0x40, 1.0f, 0);
                func_800E1B78_A09108(0);
                return 7;
            default:
                if (D_800E80D0_A0F660 == TRUE) {
                    if (arg1 == 2) {
                        auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
                        func_800E1B78_A09108(0);
                        return 9;
                    } else if (arg1 == 3) {
                        auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
                        func_800E1B78_A09108(1);
                        return 8;
                    }
                } else {
                    auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
                    func_800E1B78_A09108(1);
                    return 8;
                }
        }
    }
    #ifdef AVOID_UB
    return 0;
    #endif
}

s32 func_800E3974_A0AF04(s8 arg0) {
    UnkStruct800BEDF8* temp_v0;
    GObj* sp54[4];
    s32 ret;
    s8 temp_s3;
    s8 var_s0;
    u8 i;

    if (D_800E82E4_A0F874 == 4) {
        var_s0 = 0;
    } else if (D_800E82ED_A0F87D != 0) {
        var_s0 = 1;
    } else {
        var_s0 = 0;
    }

    temp_s3 = func_800E33C8_A0A958(sp54);
    omCreateProcess(sp54[var_s0], func_800E3240_A0A7D0, 0, 1);
    ohWait(1);

    while (TRUE) {
        temp_v0 = func_800AA38C(0);
        if (temp_v0->unk_18 != 0) {
            func_800E1AEC_A0907C();
            func_800E1AD4_A09064();
        }

        if (D_800E82E8_A0F878 >= 1800 && D_800BF051 == 0) {
            func_800E1B78_A09108(0);
            if (arg0 == 0xF) {
                ret = 11;
            } else {
                ret = 10;
            }
            break;
        }

        if (temp_v0->unk_18 & 0x10000) {
            auPlaySoundWithParams(0x41, 0x7FFF, 0x40, 1.0f, 0);
            ohEndAllObjectProcesses(sp54[var_s0]);
            func_800E18E0_A08E70((sp54[var_s0])->data.sobj, 0xC0, 0xC0, 0);
            var_s0--;
            if (var_s0 < 0) {
                var_s0 = temp_s3 - 1;
            }
            omCreateProcess(sp54[var_s0], func_800E3240_A0A7D0, 0, 1);
        } else if (temp_v0->unk_18 & 0x20000) {
            auPlaySoundWithParams(0x41, 0x7FFF, 0x40, 1.0f, 0);
            ohEndAllObjectProcesses(sp54[var_s0]);
            func_800E18E0_A08E70(sp54[var_s0]->data.sobj, 0xC0, 0xC0, 0);
            var_s0++;
            var_s0 %= temp_s3;
            omCreateProcess(sp54[var_s0], func_800E3240_A0A7D0, 0, 1);
        } else if (temp_v0->unk_18 & 0x4000) {
            auPlaySoundWithParams(0x43, 0x7FFF, 0x40, 1.0f, 0);
            ohEndAllObjectProcesses(sp54[var_s0]);
            for (i = 0; i < temp_s3; i++) {
                func_800E18AC_A08E3C(sp54[i]->data.sobj, FALSE);
            }
            ret = 2;
            break;
        } else if (temp_v0->unk_18 & (0x8000 | 0x1000)) {
            ret = func_800E37E8_A0AD78(D_800E82ED_A0F87D, var_s0) & 0xFF;
            break;
        }

        ohWait(1);
    }
    return ret;
}

void func_800E3C7C_A0B20C(GObj* gobj) {
    u8 color;
    u8 counter;
    u8 state;
    SObj* sobj;

    state = 0;
    sobj = gobj->data.sobj;
    color = 0xFF;

    if (gobj->userData == NULL) {
        sobj = gobj->data.sobj->next;
    } else {
        sobj = gobj->data.sobj->next->next;
    }
    func_800E18E0_A08E70(sobj, color, color, color);

    while (TRUE) {
        switch (state) {
            case 0:
                if (sobj->sprite.red < 226) {
                    color += 30;
                    func_800E18E0_A08E70(sobj, color, color, color);
                } else {
                    color = 0xFF;
                    func_800E18E0_A08E70(sobj, color, color, color);
                    counter = 0;
                    state++;
                }
                break;
            case 1:
                if (counter++ > 30) {
                    state++;
                }
                break;
            case 2:
                if (sobj->sprite.red >= 132) {
                    color -= 4;
                    func_800E18E0_A08E70(sobj, color, color, color);
                } else {
                    color = 0x80;
                    func_800E18E0_A08E70(sobj, color, color, color);
                    state = 0;
                }
                break;
        }
        ohWait(1);
    }
}

s32 func_800E3E28_A0B3B8(void) {
    SObj* sobj2;
    SObj* sobj1;
    SObj* sobj0;
    GObj* gobj;
    s32 flags;
    s32 ret;
    s32 cond;
    s32 one;

    gobj = D_800E82DC_A0F86C;
    sobj0 = gobj->data.sobj;
    sobj1 = sobj0->next;
    sobj2 = sobj1->next;

    ohEndAllObjectProcesses(D_800E82CC_A0F85C);
    func_800E18E0_A08E70(D_800E82CC_A0F85C->data.sobj, 0xFF, 0xFF, 0xFF);
    func_800E18AC_A08E3C(sobj0, TRUE);
    func_800E18AC_A08E3C(sobj2, TRUE);
    func_800E18AC_A08E3C(sobj1, TRUE);
    func_800E18E0_A08E70(sobj2, 0x80, 0x80, 0x80);
    func_800E18E0_A08E70(sobj1, 0x80, 0x80, 0x80);
    cond = FALSE;
    gobj->userData = NULL;
    omCreateProcess(gobj, func_800E3C7C_A0B20C, 0, 1);
    auSetBGMVolume(1, 0x7F00);
    auPlaySong(1, 0x23);
    auSetBGMVolumeSmooth(0, 0x4000, 30);
    ohWait(30);

    one = 1;

    while (TRUE) {
        flags = func_800AA38C(0)->unk_18;
        if (flags & 0x4000) {
            cond = FALSE;
            break;
        } else {
            if (flags & 0x80000) {
                if (gobj->userData == NULL) {
                    auPlaySoundWithParams(0x41, 0x7FFF, 0x40, 1.0f, 0);
                    cond = TRUE;
                    ohEndAllObjectProcesses(gobj);
                    gobj->userData = (void* ) one;
                    func_800E18E0_A08E70(sobj1, 0x80, 0x80, 0x80);
                    omCreateProcess(gobj, func_800E3C7C_A0B20C, 0, 1);
                }
            } else if (flags & 0x40000) {
                if (gobj->userData == (void* )one) {
                    auPlaySoundWithParams(0x41, 0x7FFF, 0x40, 1.0f, 0);
                    cond = FALSE;
                    ohEndAllObjectProcesses(gobj);
                    gobj->userData = NULL;
                    func_800E18E0_A08E70(sobj2, 0x80, 0x80, 0x80);
                    omCreateProcess(gobj, func_800E3C7C_A0B20C, 0, 1);
                }
            } else if (flags & (0x8000 | 0x1000)) {
                break;
            }

            ohWait(one);
        }
    }

    if (cond) {
        auPlaySoundWithParams(0x42, 0x7FFF, 0x40, 1.0f, 0);
        func_800E1CAC_A0923C();
        ret = 6;
    } else {
        ohEndAllObjectProcesses(gobj);
        func_800E18AC_A08E3C(sobj0, FALSE);
        func_800E18AC_A08E3C(sobj2, FALSE);
        func_800E18AC_A08E3C(sobj1, FALSE);
        auPlaySoundWithParams(0x43, 0x7FFF, 0x40, 1.0f, 0);
        auSetBGMVolumeSmooth(0, 0x7FFF, 30);
        ohWait(30);
        ret = 3;
    }
    ohWait(1);
    return ret;
}

void func_800E4100_A0B690(GObj* gobj) {
    u8 counter;
    u8 color;
    u8 state;
    SObj* sobj;

    sobj = gobj->data.sobj;
    state = 0;
    func_800E18E0_A08E70(sobj, 0, 0, 0);

    while (TRUE) {
        switch (state) {
            case 0:
                color += 5;
                func_800E18E0_A08E70(sobj, color, color, color);
                if (sobj->sprite.red > 250) {
                    color = 0xFF;
                    func_800E18E0_A08E70(sobj, color, color, color);
                    counter = 0;
                    state++;
                }
                break;
            case 1:
                counter++;
                if (counter == 120) {
                    state++;
                }
                break;
            case 2:
                color -= 5;
                func_800E18E0_A08E70(sobj, color, color, color);
                if (sobj->sprite.red < 0x80) {
                    color = 0x80;
                    func_800E18E0_A08E70(sobj, color, color, color);
                    state = 0;
                }
                break;
        }
        ohWait(1);
    }
}

s32 func_800E426C_A0B7FC(s8 arg0) {
    UNUSED s32 padding;
    GObj* gobj;
    SObj* sobj;
    s32 ret;

    sobj = D_800E82E0_A0F870->data.sobj;
    gobj = D_800E82E0_A0F870;
    func_800E18FC_A08E8C(sobj, 59, 147);
    omCreateProcess(gobj, func_800E4100_A0B690, 0, 1);
    func_800E18AC_A08E3C(sobj, TRUE);

    while (TRUE) {
        if (D_800E82E8_A0F878 >= 1800 && D_800BF051 == 0) {
            func_800E1B78_A09108(0);
            if (arg0 == 0xF) {
                ret = 0xB;
            } else {
                ret = 0xA;
            }
            break;
        }
        ohWait(1);
    }

    func_800E18AC_A08E3C(sobj, FALSE);
    ohEndAllObjectProcesses(gobj);
    return ret;
}

void func_800E4354_A0B8E4(void) {
    func_800E5D2C_A0D2BC();
}

void func_800E4374_A0B904(s8 arg0) {
    if (D_800BF051 == 0) {
        func_800E1D44_A092D4(13);
        func_800E1930_A08EC0(0, 0, 0, 0, 1.0f);
        func_800E1E10_A093A0();
        func_800E28CC_A09E5C();
        D_800E82E4_A0F874 = 13;
    } else {
        D_800E82E4_A0F874 = 12;
    }


    while (TRUE) {
        func_800E1AEC_A0907C();
        func_800E1D44_A092D4(D_800E82E4_A0F874);
        func_800E212C_A096BC();
        func_800E2058_A095E8();
        func_800E281C_A09DAC();
        func_800E2BD8_A0A168(D_800E82E4_A0F874);
        func_800E2F24_A0A4B4();
        func_800E1AD4_A09064();
        if (D_800BF051 == -1) {
            D_800E82E4_A0F874 = 5;
        } else {
            D_800E82E4_A0F874 = 13;
            if (D_800E82E4_A0F874 != 0) {
                D_800E82E4_A0F874 = 2;
            } else {
                D_800E82E4_A0F874 = 3;
            }
        }

        do {
            switch (D_800E82E4_A0F874) {
                case 2:
                    D_800E82E4_A0F874 = func_800E30EC_A0A67C(arg0);
                    break;
                case 3:
                case 4:
                    D_800E82E4_A0F874 = func_800E3974_A0AF04(arg0);
                    break;
                case 5:
                    D_800E82E4_A0F874 = func_800E426C_A0B7FC(arg0);
                    break;
                case 8:
                    auStopBGM();
                    D_800E82E4_A0F874 = func_800E6B2C_A0E0BC();
                    break;
                case 11:
                    auStopBGM();
                    return;
                case 6:
                case 7:
                case 9:
                case 10:
                    auStopBGM();
                    func_800067DC();

                    while (TRUE) {
                        ohWait(1);
                    }
            }
        } while (D_800E82E4_A0F874 != 0xC);
    }
}

void func_800E455C_A0BAEC(GObj* gobj) {
    auStopAllSounds();
    if (D_800BF051 == -1) {
        func_800ABB4C(1);
    }
    if ((func_800ABB68() % 2) == 0) {
        func_800ABB4C(1);
        func_800E4354_A0B8E4();
        func_800E4374_A0B904(0xE);
    } else {
        func_800E4374_A0B904(0xF);
        func_800E4354_A0B8E4();
        func_800E4374_A0B904(0x10);
    }

    while (TRUE) {
        ohWait(1);
    }
}

void func_800E4610_A0BBA0(Gfx** gfx) {
    gSPDisplayList((*gfx)++, D_800E8130_A0F6C0);
}

void func_800E4634_A0BBC4(void) {
    GObj* gobj;

    func_800AAE28();
    func_800AA85C(0x18, 0xC);
    func_800AA870(0xF0000);
    D_800E80FC_A0F68C.zBuffer = gtlMalloc(0x25800, 0x40);
    viApplyScreenSettings(&D_800E80FC_A0F68C);
    D_800E82A4_A0F834 = ohCreateCameraWrapper(0, 0x80000000, 0x64, 3, 0x6464B4FF);
    D_800E82A8_A0F838 = ohCreateCamera(1, ohUpdateDefault, 0, 0x80000000, ren_func_800192DC, 5, 0x10, -1, 0, 1, NULL, 1, 1);
    omCameraAddMtx(D_800E82A8_A0F838->data.cam, 3, 0);
    omCameraAddMtx(D_800E82A8_A0F838->data.cam, 8, 0);

    D_800E82AC_A0F83C = ohCreateCamera(3, ohUpdateDefault, 0, 0x80000000, renSpriteCameraRender, 3, 2, -1, 1, 1, NULL, 1, 1);
    D_800E82AC_A0F83C->data.cam->flags = CAMERA_FLAG_8;
    func_800A7F68(0, 0x101);
    func_800E5C8C_A0D21C();

    D_800E82B8_A0F848 = omAddGObj(0xE, NULL, 0, 0x80000000);
    omCreateProcess(D_800E82B8_A0F848, func_800E1B04_A09094, 0, 1);

    gobj = omAddGObj(0xE, NULL, 0, 0x80000000);
    omCreateProcess(gobj, func_800E455C_A0BAEC, 0, 1);
}

s32 func_800E4830_A0BDC0(s32 sceneId) {
    D_800E8198_A0F728 = VPK_VRAM - (s32)&D_800E83A0;
    gtlDisableNearClipping(1);
    omSetupScene(&D_800E8188_A0F718);

    switch (D_800E82E4_A0F874) {
        case 6:
            func_800AAED0(1);
            return 0;
        case 7:
            func_800AAED0(2);
            return 11;
        case 9:
            return 22;
        case 10:
            return 21;
        default:
            break;
    }

    #ifdef AVOID_UB
    return 0;
    #endif
}
