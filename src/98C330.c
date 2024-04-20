#include "common.h"

#include "gbi.h"
#include "string.h"

extern s32 D_800AF3C0;
extern s32 D_80229840;
extern s32 D_80369F80;

typedef struct UnkStruct98C_A {
    /* 0x00 */ GObj* unk_00;
    /* 0x04 */ char unk_04[0x4];
} UnkStruct98C_A; // size = ???

typedef struct UnkStruct98C_D {
    /* 0x00 */ char unk_00[0x0A];
    /* 0x0A */ s16 unk_0A;
} UnkStruct98C_D; // size = ???

// data
extern Gfx D_801E53A0_994E10[];
extern ScreenSettings D_801E5410_994E80;
extern SceneSetup D_801E542C_994E9C;
extern s32 D_801E543C_994EAC;
extern Sprite D_801E5DB0_995820;
extern Sprite D_801E5EE0_995950;
extern Sprite D_801F2378_9A1DE8; // Prof. Oak's check
extern Sprite D_801F26B0_9A2120; // NEW
extern Sprite D_801F2910_9A2380; // blue diamond background
extern Sprite D_801F29F0_9A2460; // evaluation background sprite
extern Sprite D_801F2AD0_9A2540; // black square
extern Sprite D_801F3B10_9A3580;
extern s32 D_801F3E28_9A3898;
extern s32 D_801F3E2C_9A389C;
extern s32 D_801F3E30_9A38A0;

// rodata
extern char D_801F51E8_9A4C58[];
extern char D_801F51EC_9A4C5C[];
extern char D_801F5F70_9A59E0[];
extern char D_801F5F78_9A59E8[]; // %s Course
extern char D_801F5F84_9A59F4[]; // Hmm...\nWhat's new this time?

// BSS
extern s32 D_801F70A0_9A6B10;
extern UnkStruct98C_A D_802290A0_9D8B10[6];
extern UnkStruct98C_A D_802290A4_9D8B14[];
extern s32 D_802290D8_9D8B48;
extern s32 D_802290DC_9D8B4C;
extern s32 D_802290E0_9D8B50;
extern s32 D_802290E4_9D8B54;
extern char D_802290E8_9D8B58[0x80];
extern SObj* D_80229168_9D8BD8;
extern SObj* D_80229170_9D8BE0[4];
extern SObj* D_80229180_9D8BF0;
extern SObj* D_80229184_9D8BF4;
extern SObj* D_80229188_9D8BF8;
// extern D_8022918C_9D8BFC
// extern D_80229190_9D8C00
// extern D_80229194_9D8C04
// extern D_802291A0_9D8C10
// extern D_80229838_9D92A8

void func_801E3FFC_993A6C(void);

void func_801DC8C0_98C330(Gfx** gfx) {
    gSPDisplayList(++*gfx, &D_801E53A0_994E10);
}

void func_801DC904_98C374(s32 arg0, s32 arg1) {
    Gfx* gfx = gMainGfxPos[0];

    gSPDisplayList(gfx++, &D_801E53A0_994E10);
    gDPSetColorDither(gfx++, G_CD_MAGICSQ);
    gDPPipeSync(gfx++);
    gDPSetRenderMode(gfx++, AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL |
                            GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_MEM, G_BL_0),
                            AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | G_RM_NOOP2);
    gDPSetCombineMode(gfx++, G_CC_MODULATEIA, G_CC_PASS2);

    gMainGfxPos[0] = gfx;
}

void func_801DCA14_98C484(s32 arg0) {
    UNUSED s32 pad;
    
    while (TRUE) {
        func_8000BCA8(1);
    }
}

void func_801DCA48_98C4B8(void);
#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DCA48_98C4B8.s")

void func_801DCBF4_98C664(void) {
    UNUSED s32 pad;

    func_8036A3F8(&D_801F70A0_9A6B10, 0x32000);
    func_800AAE28();
    func_801DCA48_98C4B8();
    func_80374D40_8484F0();
    func_800A7F68(1, 0x101);
    func_8036EB98();
    func_80022374(0, 0x10);
    func_80022454(0, 0x7F00);
    func_801E3FFC_993A6C();
}

s32 func_801DCC74_98C6E4(s32 arg0) {
    UNUSED s32 pad[3];

    viApplyScreenSettings(&D_801E5410_994E80);
    D_801E543C_994EAC = (s32)&D_80369F80 - (s32)&D_80229840;
    gtlDisableNearClipping(1);
    omSetupScene(&D_801E542C_994E9C);
    return D_800AF3C0;
}

s32 func_801DCCE0_98C750(void) {
    return D_802290DC_9D8B4C;
}

void func_801DCCFC_98C76C(s32, s32);
#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DCCFC_98C76C.s")

void func_801DCF4C_98C9BC(s32 arg0) {
    func_8036F0DC_84288C(arg0, 1);
    func_801DCCFC_98C76C(arg0, 1);
    func_8036F198_842948(arg0, 0xFF);
    func_8036F0A0_842850(arg0, 0);
}

void func_801DCFA0_98CA10(s32 arg0) {
    func_8036F0A0_842850(arg0, 1);
    func_801DCCFC_98C76C(arg0, 0);
    func_8036F0DC_84288C(arg0, 0);
}

void func_801DCFE8_98CA58(UnkStruct98C_D* arg0) {
    if (arg0->unk_0A == 0x97) {
        if (func_800BF3D4_5C274(arg0->unk_0A) == 0) {
            D_801F3E28_9A3898 = 0x40000;
        }
        if (func_800BFCA0_5CB40(14) != 0) {
            D_801F3E28_9A3898 = 0x80000;
        }
    }
}

s32 func_801DD05C_98CACC(s32 arg0, s32 arg1) {
    s32 ret = 0;
    UnkStruct800BEDF8* sp18;

    func_8036B9EC_83F19C(arg0, 180, 0x20);
    func_8036C898_840048(arg0, D_801F51E8_9A4C58);
    func_8036EB80_842330(0);
    func_8000BCA8(1);

    sp18 = func_800AA38C(0);
    while (!(sp18->unk_18 & (0x8000 | 0x4000))) {
        func_8000BCA8(1);
        sp18 = func_800AA38C(0);
    }
    if (sp18->unk_14 & 0x8000) {
        ret = 0x8000;
    }
    if (sp18->unk_14 & 0x4000) {
        ret = 0x4000;
    }
    if (sp18->unk_14 & 0x1000) {
        ret = 0x1000;
    }
    if (arg1 != 0) {
        func_800228E4(0x4D);
    }
    func_8036B9EC_83F19C(arg0, 180, 0x20);
    func_8036C898_840048(arg0, D_801F51EC_9A4C5C);
    func_8000BCA8(1);
    func_8036EE40_8425F0();
    func_8036EB80_842330(1);
    return ret;
}

s32 func_801DD1A8_98CC18(s32 arg0) {
    s32 i;
    s32 ret = 0;
    UnkStruct800BEDF8* sp1C;

    for (i = 0; i < arg0; i++) {
        func_8000BCA8(1);
        sp1C = func_800AA38C(0);
        if (sp1C->unk_14 & 0x8000) {
            ret = 0x8000;
            break;
        }
        if (sp1C->unk_14 & 0x4000) {
            ret = 0x4000;
            break;
        }
    }
    return ret;
}

s32 func_801DD25C_98CCCC(s32 arg0, s32 arg1) {
    s32 ret = 0;

    ret = func_801DD1A8_98CC18(arg1);

    if (ret == 0x4000) {
        if (arg0 != 0) {
            D_801F3E2C_9A389C = 4;
        } else {
            D_801F3E30_9A38A0 = 4;
        }
    }
    return ret;
}
void func_801DD2D4_98CD44(void); // TODO unsure
#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DD2D4_98CD44.s")

void func_801DD46C_98CEDC(s32 rgb) {
    s32 i;

    D_80229168_9D8BD8->sprite.red = rgb;
    D_80229168_9D8BD8->sprite.green = rgb;
    D_80229168_9D8BD8->sprite.blue = rgb;

    for (i = 0; i < ARRAY_COUNT(D_80229170_9D8BE0); i++) {
        if (D_80229170_9D8BE0[i] == NULL) {
            continue;
        }
        D_80229170_9D8BE0[i]->sprite.red = rgb;
        D_80229170_9D8BE0[i]->sprite.green = rgb;
        D_80229170_9D8BE0[i]->sprite.blue = rgb;
    }
}

void func_801DD528_98CF98(s32 rgb) {
    D_80229180_9D8BF0->sprite.red = D_80229180_9D8BF0->sprite.green = D_80229180_9D8BF0->sprite.blue = rgb;
}

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DD568_98CFD8.s")
/*
void func_801DD568_98CFD8(void) {
    GObj* gobj = func_80371D14_8454C4(NULL, 6, &D_801F29F0_9A2460);
    SObj* sobj = gobj->userData.sobj;

    sobj->sprite.x = 0;
    sobj->sprite.y = 86;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = 74;
    sobj->sprite.istep = 0;
    D_80229170_9D8BE0[0] = sobj;
}
*/

void func_801DD5F0_98D060(s32 arg0) {
   if (arg0 != 0) {
        D_80229180_9D8BF0->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_80229180_9D8BF0->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DD638_98D0A8(s32 arg0) {
    if (arg0 != 0) {
        D_80229184_9D8BF4->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_80229184_9D8BF4->sprite.attr |= SP_HIDDEN;
    }
}

/*
void func_801DD680_98D0F0(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_802290A0_9D8B10[i].unk_00->userData.sobj->sprite.x = ((i % 3) * 66) + 104;
        D_802290A0_9D8B10[i].unk_00->userData.sobj->sprite.y = ((i / 3) * 55) + 53;
    }
}
*/

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DD680_98D0F0.s")

void func_801DD720_98D190(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DD720_98D190.s")

// GObj* func_801DD720_98D190(s32 idx) {
//     GObj* gobj;
//     SObj* sobj;
//     UNUSED s32 pad[2];
//     Bitmap* sp24;
//     s32 i;
//     u8* sp20;
//     u8* sp1C;

//     gobj = func_80371C68(0, 6, &D_801E5DB0_995820);
//     sobj = gobj->userData.sobj;
//     D_802290A0_9D8B10[idx].unk_00 = gobj;
//     sobj = func_80371E68(sobj, &D_801E5DB0_995820);
//     sobj->sprite.x = 54;
//     sobj->sprite.y = 0;
//     sobj = func_80371DC0(sobj, &D_801E5EE0_995950);
//     sobj->sprite.x = 2;
//     sobj->sprite.y = 0;
//     sobj = func_80371DC0(sobj, &D_801E5EE0_995950);
//     sobj->sprite.x = 2;
//     sobj->sprite.y = 41;
//     sobj = func_80371DC0(sobj, &D_801F3B10_9A3580);
//     sobj->sprite.x = 2;
//     sobj->sprite.y = 2;
//     D_802290A4_9D8B14[idx].unk_00 = sobj;
//     sp24 = func_8036A194(0x30);
//     sp20 = func_8036A194(0xFD8);
//     sp1C = sobj->sprite.bitmap->buf;
//     *sp24 = *sobj->sprite.bitmap;
//     sp24->buf = sp20;
//     sobj->sprite.bitmap = sp24;

//     for (i = 0xFD8; i > 0; i--) {
//         *sp20++ = *sp1C++;
//     }

//     return gobj;
// }


void func_801DD8F4_98D364(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        func_801DD720_98D190(i);
    }
    D_802290A0_9D8B10[0].unk_00->data.sobj->sprite.x = -60;
    D_802290A0_9D8B10[1].unk_00->data.sobj->sprite.x = 320;
}

void func_801DD964_98D3D4(s32 rgb) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_802290A0_9D8B10[i].unk_00->data.sobj->sprite.red = rgb;
        D_802290A0_9D8B10[i].unk_00->data.sobj->sprite.green = rgb;
        D_802290A0_9D8B10[i].unk_00->data.sobj->sprite.blue = rgb;
    }
}

void func_801DD9E4_98D454(s32 arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (arg0 != 0) {
            D_802290A0_9D8B10[i].unk_00->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_802290A0_9D8B10[i].unk_00->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}


void func_801DDA68_98D4D8(s32 arg0) {
    if (D_802290E0_9D8B50 == 0) {
        return;
    }

    if (arg0 != 0) {
        func_8036D1A4_840954(D_802290E0_9D8B50, 0);
    } else {
        func_8036D1A4_840954(D_802290E0_9D8B50, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DDAD8_98D548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DDCF8_98D768.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DE02C_98DA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801DE204_98DC74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801E1FA8_991A18.s")

void func_801E242C_991E9C(s32 arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad[3];

    PANIC();
}

void func_801E2454_991EC4(void);
#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801E2454_991EC4.s")

s32 func_801E28CC_99233C(s32* arg0) {
    s32 i;
    s32 sp28;
    s32 sp24;

    sp28 = 0;
    sp24 = 0;

    for (i = 1; i < 0x98; i++) {
        if (func_800BF3D4_5C274(i) == 0) {

        } else {
            sp28 += func_800BF818_5C6B8(i);
            sp24++;
        }
    }
    if (func_800BF3D4_5C274(1004) != 0) {
        sp28 += func_800BF818_5C6B8(1004);
    }
    if (func_800BF3D4_5C274(1010) != 0) {
        sp28 += func_800BF818_5C6B8(1010);
    }
    if (func_800BF3D4_5C274(1018) != 0) {
        sp28 += func_800BF818_5C6B8(1018);
    }
    if (func_800BF3D4_5C274(1022) != 0) {
        sp28 += func_800BF818_5C6B8(1022);
    }
    if (func_800BF3D4_5C274(1028) != 0) {
        sp28 += func_800BF818_5C6B8(1028);
    }
    if (func_800BF3D4_5C274(1035) != 0) {
        sp28 += func_800BF818_5C6B8(1035);
    }
    if (arg0 != NULL) {
        *arg0 = sp24;
    }
    return sp28;
}

s32 func_801E2A68_9924D8(void) {
    s32 i, ret;

    for (i = 0, ret = 0; i < func_800BF9EC_5C88C(); i++) {
        if (func_800BFA44_5C8E4(i) != 0) {
            ret += 1;
        }
    }

    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801E2AE8_992558.s")

void func_801E2ED4_992944(s32); // TODO probably a struct
#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801E2ED4_992944.s")

// TODO probably needs a struct on the stack - this is broken
void func_801E3934_9933A4(void) {
    UNUSED s32 pad[1];
    s32 sp28 = D_802290DC_9D8B4C;
    UNUSED s32 pad2[2];
    s32 sp1C;

    func_801DD9E4_98D454(0);
    func_803700A4_843854(0);
    func_801E2454_991EC4();
    sp1C = 0;
    func_801E2ED4_992944(sp1C);
    if (D_801F3E28_9A3898 == 0) {
        D_801F3E28_9A3898 = 0x20;
    }
    func_800AAED0(D_801F3E28_9A3898);
    func_8036D1A4_840954(D_802290E4_9D8B54, 1);
    func_8036D1A4_840954(D_802290E0_9D8B50, 1);
    func_8036D1A4_840954(D_802290DC_9D8B4C, 1);
}

s32 func_801E4428_993E98(void);
void func_801E5030_994AA0(void);

void func_801E39DC_99344C(s32 arg0) {
    UNUSED s32 pad;
    s32 sp48;
    s32 i;
    UNUSED s32 pad2;
    s32 sp3C;
    s32 sp38;
    ucolor sp34; // ?
    s32 sp30;
    char* levelName;

    sp30 = 1;
    func_801E5030_994AA0();
    D_801F3E28_9A3898 = 0;
    func_803717E8_844F98();
    func_80370428_843BD8();
    func_803700A4_843854(0);
    sp3C = func_8036AC6C_83E41C(0x47, 0x19, 0xCC, 0x30, 0);
    D_802290E4_9D8B54 = sp3C;
    func_8036B870_83F020(sp3C, 1, 255, 255, 0xFF, 0xFF);
    func_8036B870_83F020(sp3C, 0, 0x11, 0x4E, 0x7D, 0);
    func_8036B734_83EEE4(sp3C);
    func_8036CB58_840308(sp3C, 8);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036D1A4_840954(sp3C, 1);

    levelName = getLevelName(getLevelId());
    if (levelName == NULL) {
        levelName = D_801F5F70_9A59E0;
    } else {
        sprintf(D_802290E8_9D8B58, D_801F5F78_9A59E8, levelName);
        levelName = D_802290E8_9D8B58;
    }
    sp3C = func_8036AC6C_83E41C(0x47, 0x32, 0xCC, 0x78, 0);
    D_802290E0_9D8B50 = sp3C;
    func_8036B870_83F020(sp3C, 1, 255, 255, 0xFF, 0xFF);
    func_8036B870_83F020(sp3C, 0, 0U, 0U, 0, 0);
    func_8036B734_83EEE4(sp3C);
    func_8036CB58_840308(sp3C, 0xC);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036D1A4_840954(sp3C, 1);
    func_8036B9EC_83F19C(sp3C, 90 - (strlen(levelName) * 3), 0x3E);
    func_8036C898_840048(sp3C, levelName);
    sp38 = func_8036F78C_842F3C();
    D_802290D8_9D8B48 = sp38;
    func_8036F684_842E34(sp38, 1);
    func_8036F738_842EE8(sp38, &sp34);
    func_8036F1F4_8429A4(sp38, 0xB8, SCREEN_WIDTH);
    func_8036F0DC_84288C(sp38, 0);
    sp3C = func_8036AC6C_83E41C(0x40, 0xAD, 0xC0, 0x2F, 0);
    func_8036B870_83F020(sp3C, 1, 255, 255, 0xFF, 0xFF);
    func_8036B870_83F020(sp3C, 0, sp34.r, sp34.g, sp34.b, 0xFF);
    func_8036B734_83EEE4(sp3C);
    func_8036D1A4_840954(sp3C, 1);
    func_8000BCA8(1);

    for (i = 0; i < 60; i++) {
        func_801DD46C_98CEDC((i * 0xFF) / 60);
        func_801DD528_98CF98((i * 0xFF) / 60);
        func_8000BCA8(1);
    }

    func_801DD46C_98CEDC(0xFF);
    func_801DD528_98CF98(0xFF);
    func_8037172C_844EDC(0);
    func_803713C8_844B78(0);
    func_8000BCA8(1);
    func_8036CB58_840308(sp3C, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036CB58_840308(sp3C, 0xC);
    func_8036D4A0_840C50(0);
    D_802290DC_9D8B4C = sp3C;
    func_801DCF4C_98C9BC(sp38);
    func_8036D4A0_840C50((0, 0)); // fake match or typo?
    func_8036D1A4_840954(sp3C, 0);
    func_8036B9EC_83F19C(sp3C, 0, 0);
    func_8036C898_840048(sp3C, D_801F5F84_9A59F4);
    func_8036D1A4_840954(D_802290E0_9D8B50, 0);
    func_80374F30_8486E0(sp3C, 1);
    func_8036D4A0_840C50(0);
    func_801DD5F0_98D060(0);
    func_8036B5F0_83EDA0(D_802290E0_9D8B50);
    sp3C = func_8036AC6C_83E41C(0x47, 0x58, 0xC0, 0x48, 0);
    func_8036B870_83F020(sp3C, 1, 255, 255, 0xFF, 0xFF);
    func_8036B870_83F020(sp3C, 0, 0, 0, 0, 0);
    func_8036B734_83EEE4(sp3C);
    func_8036D1A4_840954(sp3C, 1);
    func_8036CB58_840308(sp3C, 0xC);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_801DD8F4_98D364();
    func_801DD9E4_98D454(0);
    func_8000BCA8(1);
    D_802290E0_9D8B50 = sp3C;

    while (TRUE) {
        sp48 = func_801E4428_993E98();
        func_800AAED0(0x20);
        func_803700A4_843854(0);
        func_8036D1A4_840954(sp3C, 1);
        func_8036D1A4_840954(D_802290DC_9D8B4C, 1);
        func_803713C8_844B78(0);
        func_80370A48_8441F8();
        func_801DCFA0_98CA10(sp38);
        func_800224DC(0, 0, 30);

        for (i = 30; i >= 0; i--) {
            func_801DD46C_98CEDC((s32) (i * 0xFF) / 30);
            func_801DD964_98D3D4((s32) (i * 0xFF) / 30);
            func_8000BCA8(1);
        }

        func_801DD46C_98CEDC(0);
        func_801DD964_98D3D4(0);
        func_803705A4_843D54();
        func_80374D20_8484D0();
        if (sp48 < 0) {
            func_800AADF0(0xD);
        } else {
            func_800AADF0(sp48);
        }
        func_8000BCA8(1);
    }

    func_800AAED0(0x20);
    omDeleteGObj(0);
    func_8000BCA8(0x63);
}

#pragma GLOBAL_ASM("asm/nonmatchings/98C330/func_801E3FFC_993A6C.s")
/*
void func_801E3FFC_993A6C(void) {
    GObj* gobj;
    SObj* sobj;

    func_800A85E8(func_801E39DC_99344C, 6, 0, 0);

    gobj = func_80371D14_8454C4(0, 6, &D_801F2910_9A2380);
    sobj = gobj->userData.sobj;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80229168_9D8BD8 = sobj;
    func_801DD568_98CFD8();
    func_801DD46C_98CEDC(0);

    gobj = func_80371D14_8454C4(0, 6, &D_801F2378_9A1DE8);
    D_80229180_9D8BF0 = gobj->userData.sobj;
    D_80229180_9D8BF0->sprite.x = 56;
    D_80229180_9D8BF0->sprite.y = 38;
    func_801DD5F0_98D060(1);
    func_801DD528_98CF98(0);

    gobj = func_80371D14_8454C4(0, 6, &D_801F26B0_9A2120);
    D_80229184_9D8BF4 = gobj->userData.sobj;
    D_80229184_9D8BF4->sprite.x = 217;
    D_80229184_9D8BF4->sprite.y = 23;
    func_801DD638_98D0A8(0);

    gobj = func_80371D14_8454C4(0, 6, &D_801F2AD0_9A2540);
    D_80229188_9D8BF8 = gobj->userData.sobj;
    D_80229188_9D8BF8->sprite.x = 0;
    D_80229188_9D8BF8->sprite.y = 0;
    D_80229188_9D8BF8->sprite.width = 132;
    D_80229188_9D8BF8->sprite.height = SCREEN_HEIGHT;
    D_80229188_9D8BF8->sprite.alpha = 128;
    D_80229188_9D8BF8->sprite.istep = 0;
    D_80229188_9D8BF8->sprite.attr |= SP_HIDDEN | SP_TRANSPARENT;
    func_8036EB8C_84233C(&func_801DD2D4_98CD44);
}
*/
