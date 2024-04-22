#include "common.h"

#include "gbi.h"
#include "string.h"

#include "sys/cont.h"
#include "sys/om.h"
#include "sys/vi.h"
#include "sys/oh.h"

#include "photocheck.h"

extern s32 D_80229840;
extern s32 D_80369F80;

extern Addr D_803B5000;
extern Addr D_803DA800;

// data
// Gfx D_801E53A0_994E10[] = {
//     gsDPPipeSync(),
//     gsDPPipelineMode(G_PM_NPRIMITIVE),
//     gsSPSetGeometryMode(G_LIGHTING),
//     gsDPSetTextureLOD(G_TL_TILE),
//     gsDPSetTextureDetail(G_TD_CLAMP),
//     gsDPSetTexturePersp(G_TP_PERSP),
//     gsDPSetTextureLUT(G_TT_NONE),
//     gsDPSetTextureFilter(G_TF_BILERP),
//     gsDPSetTextureConvert(G_TC_FILT),
//     gsSPClipRatio(FRUSTRATIO_6),
//     gsSPEndDisplayList(),
// };

// ScreenSettings D_801E5410_994E80 = {
//     D_803B5000,
//     D_803DA800,
//     NULL,
//     NULL,
//     SCREEN_WIDTH,
//     SCREEN_HEIGHT,
//     0x16A99,
// };

// SceneSetup D_801E542C_994E9C = {
//     {
//         0,
//         func_8000AFFC,
//         func_8000ADA0,
//         &D_80229840,
//         0,
//         1,
//         1,
//         0x0000C000,
//         0x00002000,
//         0,
//         0,
//         0x00003000,
//         0x00020000,
//         0x00003000,
//         func_800A1A50,
//         contUpdate,
//     },
//     32,
//     0x00002000,
//     0x00000020,
//     0,
//     0x00000040,
//     0,
//     0x0000005C,
//     0x00000400,
//     0,
//     0,
//     0,
//     0x00000010,
//     0,
//     0x00000088,
//     0,
//     0x00000060,
//     0,
//     0x00000090,
//     func_801DCBF4_98C664
// };

extern Gfx D_801E53A0_994E10[];
extern ScreenSettings D_801E5410_994E80;
extern SceneSetup D_801E542C_994E9C;
extern s32 D_801E543C_994EAC;
extern Sprite D_801E5840_9952B0;
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
extern s32 D_801F3E60_9A38D0;
extern s32 D_801F3E64_9A38D4;


typedef struct ObjPair {
    /* 0x00 */ GObj* gobj;
    /* 0x04 */ SObj* sobj;
} ObjPair; // size = 0x8

// BSS
ObjPair D_802290A0_9D8B10[6];
u8 D_801F70A0_9A6B10[0x32000];
s32 D_802290D8_9D8B48;
s32 D_802290DC_9D8B4C;
s32 D_802290E0_9D8B50;
s32 D_802290E4_9D8B54;
char D_802290E8_9D8B58[0x80];
SObj* D_80229168_9D8BD8;
SObj* D_80229170_9D8BE0[4];
SObj* D_80229180_9D8BF0;
SObj* D_80229184_9D8BF4;
SObj* D_80229188_9D8BF8;
s32 D_8022918C_9D8BFC;
s32 D_80229190_9D8C00;

void func_801E3FFC_993A6C(void);
s32 func_801E4428_993E98(void);
void func_801E5030_994AA0(void);

s32 D_801F3B50_9A35C0[] = {
    0x00000000,
};

char* SpecialPokemonNames[] = {
    NULL,
    "Surfing PIKACHU",
    "PIKACHU on a Ball",
    "Balloon PIKACHU",
    "Speed PIKACHU",
    "PIKACHU on a Stump",
    "Flying PIKACHU",
    "Gust-using PIDGEY",
    "JIGGLYPUFF on Stage",
    "GRAVELER's Group Dance",
    "The Rare Pokεmon MEW",
    "Fighting MAGMAR",
    "JIGGLYPUFF TRIO on Stage",
};

char* PhotoComments[] = {
    "wrong number!",
    "\\BOh! It seems to be screeching.",
    "\\BOh! This is a fighting pose.",
    "\\BOh! It's happy.",
    "This is a relaxed pose.",
    "\\BOh! It's neighing.",
    "\\BOh! So many embers!",
    "\\BOh! Tons of embers!",
    "\\BOh! It's shining.",
    "\\BOh! It's shining.",
    "\\BOh! It's about to leap out!",
    "\\BOh! It's enjoying the food.",
    "\\BOh! It's DRAGONITE!",
    "\\BOh! What a Thunder Jolt!",
    "\\BOh! It's happy.",
    "It looks happy.",
    "\\BOh! It's happy.",
    "\\BOh! What a jolly dance!",
    "\\BOh! How beautiful!",
    "\\BOh! How powerful!",
    "It just showed its face.",
    "Umm... looks scary!",
    "\\BOh! It's furious!",
    "\\BOh! It looks astonished!",
    "JIGGLYPUFF's dance is great!",
    "\\BOh! That's a shame...",
    "\\BOh! It's singing cheerfully.",
    "It's rolling...",
    "\\BOh! It exploded!",
    "It's a blast!",
    "Oh dear, it fainted.",
    "You've thrown a PESTER BALL.",
    "It must be angry.",
    "\\BOh! It's surprised!",
    "It sure is happy!",
    "It's trying to go underground.",
    "I can barely see it.",
    "It's trying to go underground.",
    "\\BOh! What an amazing jump!",
    "That's a pretty good jump.",
    "It's jumping.",
    "\\BOh! It's falling.",
    "\\BOh! It's falling.",
    "\\BOh! It fell.",
    "\\BOh! It's MANKEY in the sky!",
    "\\BOh! MANKEY got blasted!",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "\\BOh! What a splash!",
    "It splashed!",
    "That's a good splash.",
    "\\BOh! It's splashing.",
    "Nice jump.",
    "It's jumping.",
    "\\BOh! What a jump!",
    "It's dizzy.",
    "Oh dear, it fainted.",
    "\\BOh! It's about to wake up.",
    "\\BOh! It's about to jump in!",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "\\BOh! It's about to pop up.",
    "It's about to go underground.",
    "Hmm... It looks jolly.",
    "It stumbled.",
    "It stumbled.",
    "It stumbled.",
    "\\BOh! It's about to pop up.",
    "It's about to go underground.",
    "\\BOh! It's happy.",
    "That's a good splash!",
    "It's splashing.",
    "\\BOh! What a splash!",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "It's about to withdraw.",
    "I only see its shell.",
    "It's about to come out.",
    "\\BOh! It's happy!",
    "Hmm... It looks happy.",
    "Hmm... It looks jolly.",
    "\\BOh! It sure is jolly!",
    "Isn't the Pokεmon dance fun?",
    "\\BOh! It's rockin'!",
    "\\BOh! It's about to wake up!",
    "\\BOh! It's been caught!",
    "\\BOh! It's snapping!",
    "It looks like it's going to fish.",
    "Nice jump.",
    "It jumped.",
    "\\BOh! What a jump!",
    "It's about to fall.",
    "Quite unique!",
    "It's submerging.",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "\\BOh! What a happy face!",
    "\\BOh! What a wonderful pose!",
    "It looks like it's shocked.",
    "\\BOh! What a flame!",
    "It's unstable...",
    "Hmm...",
    "You've thrown a PESTER BALL.",
    "\\BOh! It looks happy!",
    "Interesting! It's dizzy!",
    "It's unstable...",
    "This is pretty funny!",
    "Ha, ha, ha! This is so funny!",
    "\\BOh! It looks hot!",
    "It's about to fall.",
    "It seems to have fainted.",
    "It seems to have woken up.",
    "\\BOh! It's roaring!",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "You've thrown a PESTER BALL.",
    "Hmm... It looks happy.",
    "wrong number!",
    "wrong number!",
    "\\BOh! It looks jolly.",
    "\\BOh! You hit 'em!",
    "\\BOh! It just fainted.",
    "\\BOh! It's about to wake up.",
    "This angry shot is pretty cool.",
    "\\BOh! What an interesting pose!",
    "It's pretty funny.",
    "It seems to have fainted.",
    "You've thrown a PESTER BALL.",
    "\\BOh! A dancing MEOWTH!",
    "That's SNORLAX for sure!",
    "\\BOh! What a jolly dance!",
    "This pose zaps even me!",
    "\\BOh! This is very lively!",
    "wrong number!",
    "wrong number!",
    "wrong number!",
    "wrong number!",
    "wrong number!",
    "wrong number!",
    "wrong number!",
    "wrong number!",
    "wrong number!",
    "\\BOh! That's PIKA!",
    "wrong number!",
    "wrong number!",
    "wrong number!",
    "If only it were facing you...",
    "If only it were facing you...",
    "\\BOh! Well done!",
    "\\BOh! It's spinning.",
    "Why, it's \\Vperfect!",
    "\\BOh! It looks yummy!",
    "\\BOh! What a weird dance.",
    "Gone fishing...",
    "\\BOh! It got a bite!",
    "It's about to pop up.",
    "I can barely see it.",
    "It's about to pop up.",
    "What a funny pose.",
    "It's about to get up.",
    "It's scratching its tummy.",
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
};

s32 D_801F3E28_9A3898 = 0;
s32 D_801F3E2C_9A389C = 0;
s32 D_801F3E30_9A38A0 = 4;
s32 D_801F3E34_9A38A4 = FALSE;
s32 D_801F3E38_9A38A8 = 15;

f32 D_801F3E3C_9A38AC[] = {
    0.0f,
    0.08333333582f,
    0.1666666716f,
    0.25f,
    0.3333333433f,
    0.4166666567f,
    0.5f,
    0.5833333135f,
    0.6666666865f,
};


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

void func_801DCA14_98C484(GObj* arg0) {
    UNUSED s32 pad;

    while (TRUE) {
        ohWait(1);
    }
}

void func_801DCA48_98C4B8(void) {
    GObj* camObj;
    OMCamera* camera;
    char pad[0x10];

    camObj = ohCreateCamera(0x200, ohUpdateDefault, 5, 5, ren_func_800191D8, 0x14, 0x100000, 0x100000, 1, 0,
                         func_801DCA14_98C484, 0, 1);
    camObj->unk38 = 0x100000;
    camera = camObj->data.cam;
    camera->flags |= 0x4 | 0x2;
    camera->flags &= ~(0x2 | 0x1);
    func_800A844C(camera, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    camera->viewMtx.lookAt.up.x = 0.0f;
    camera->viewMtx.lookAt.up.y = 0.0f;
    camera->viewMtx.lookAt.up.z = 1.0f;
    camera->viewMtx.lookAt.at = D_800AF0C4;
    camera->viewMtx.lookAt.eye = D_800AF094;
    camera->perspMtx.persp.fovy = 33.0f;
    camera->perspMtx.persp.far = 8000.0f;
    camera->perspMtx.persp.near = camera->perspMtx.persp.far / 128.0;
    camera->perspMtx.persp.scale = 1.0f;
    camera->bgColor = 1;
}

void func_801DCBF4_98C664(void) {
    UNUSED s32 pad;

    func_8036A3F8(D_801F70A0_9A6B10, sizeof(D_801F70A0_9A6B10));
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

void func_801DCCFC_98C76C(s32 arg0, s32 arg1) {
    s32 sp2C;
    s32 i;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    func_8036F684_842E34(arg0, 1);
    func_8036F0A0_842850(arg0, 1);
    for (i = 0; i <= D_801F3E38_9A38A8; i++) {
        if (arg1 != 0) {
            sp2C = i;
        } else {
            sp2C = D_801F3E38_9A38A8 - i;
        }
        sp24 = (sp2C * -92) / D_801F3E38_9A38A8 + 148;
        sp20 = (sp2C * 92) / D_801F3E38_9A38A8 + 172;
        sp1C = (sp2C * -36) / D_801F3E38_9A38A8 + 201;
        sp18 = (sp2C * 0xFF) / D_801F3E38_9A38A8;
        func_8036F1F4_8429A4(arg0, sp24, sp1C);
        func_8036F378_842B28(arg0, sp20 - sp24, 225 - sp1C);
        func_8036F198_842948(arg0, sp18);
        ohWait(1);
    }

    if (arg1 != 0) {
        func_8036F1F4_8429A4(arg0, 0x38, 0xA5);
        func_8036F378_842B28(arg0, 0xD0, 0x3C);
    }
}

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

void func_801DCFE8_98CA58(Photo* arg0) {
    if (arg0->pkmnID == 0x97) {
        if (func_800BF3D4_5C274(arg0->pkmnID) == 0) {
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

    func_8036B9EC_83F19C(arg0, 180, 32);
    func_8036C898_840048(arg0, "\\l");
    func_8036EB80_842330(0);
    ohWait(1);

    sp18 = func_800AA38C(0);
    while (!(sp18->unk_18 & (0x8000 | 0x4000))) {
        ohWait(1);
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
    func_8036B9EC_83F19C(arg0, 180, 32);
    func_8036C898_840048(arg0, "　");
    ohWait(1);
    func_8036EE40_8425F0();
    func_8036EB80_842330(1);
    return ret;
}

s32 func_801DD1A8_98CC18(s32 arg0) {
    s32 i;
    s32 ret = 0;
    UnkStruct800BEDF8* sp1C;

    for (i = 0; i < arg0; i++) {
        ohWait(1);
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

void func_801DD2D4_98CD44(s32 arg0) {
    switch (arg0) {
        case 0x5C42:
            func_80022A58(0xA2, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C43:
            func_80022A58(0xA3, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C46:
            func_80022A58(0xA6, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C47:
            func_80022A58(0xA7, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C48:
            func_80022A58(0xA8, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C49:
            func_80022A58(0xA9, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C4A:
            func_80022A58(0xAA, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C51:
            func_80022A58(0xAE, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C53:
            func_80022A58(0xAF, 0x7FFF, 0x40, 0.75f, 0);
            break;
        case 0x5C56:
            func_80022A58(0xB2, 0x7FFF, 0x40, 0.75f, 0);
            break;
        default:
            break;
    }
}

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

void func_801DD568_98CFD8(void) {
    GObj* gobj = func_80371D14_8454C4(NULL, 6, &D_801F29F0_9A2460);
    SObj* sobj = gobj->data.sobj;

    sobj->sprite.x = 0;
    sobj->sprite.y = 86;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = 74;
    sobj->sprite.istep = 0;
    D_80229170_9D8BE0[0] = sobj;
}

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

void func_801DD680_98D0F0(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_802290A0_9D8B10[i].gobj->data.sobj->sprite.x = ((i % 3) * 66) + 104;
        D_802290A0_9D8B10[i].gobj->data.sobj->sprite.y = ((i / 3) * 55) + 53;
    }
}

GObj* func_801DD720_98D190(s32 idx) {
    GObj* gobj;
    SObj* sobj;
    s32 i;
    UNUSED s32 pad[1];
    Bitmap* sp24;
    u8* sp20;
    u8* sp1C;

    gobj = func_80371C68_845418(NULL, 6, &D_801E5DB0_995820);
    sobj = gobj->data.sobj;
    D_802290A0_9D8B10[idx].gobj = gobj;
    sobj = func_80371E68_845618(sobj, &D_801E5DB0_995820);
    sobj->sprite.x = 54;
    sobj->sprite.y = 0;
    sobj = func_80371DC0_845570(sobj, &D_801E5EE0_995950);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;
    sobj = func_80371DC0_845570(sobj, &D_801E5EE0_995950);
    sobj->sprite.x = 2;
    sobj->sprite.y = 41;
    sobj = func_80371DC0_845570(sobj, &D_801F3B10_9A3580);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_802290A0_9D8B10[idx].sobj = sobj; // ?
    sp24 = func_8036A194_83D944(0x30);
    sp20 = func_8036A194_83D944(0xFD8);
    sp1C = sobj->sprite.bitmap->buf;
    *sp24 = *sobj->sprite.bitmap;
    sp24->buf = sp20;
    sobj->sprite.bitmap = sp24;

    for (i = 0xFD8; i > 0; sp1C++, sp20++, i--) {
        *sp20 = *sp1C;
    }

    return gobj;
}

void func_801DD8F4_98D364(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        func_801DD720_98D190(i);
    }
    D_802290A0_9D8B10[0].gobj->data.sobj->sprite.x = -60;
    D_802290A0_9D8B10[1].gobj->data.sobj->sprite.x = 320;
}

void func_801DD964_98D3D4(s32 rgb) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_802290A0_9D8B10[i].gobj->data.sobj->sprite.red = rgb;
        D_802290A0_9D8B10[i].gobj->data.sobj->sprite.green = rgb;
        D_802290A0_9D8B10[i].gobj->data.sobj->sprite.blue = rgb;
    }
}

void func_801DD9E4_98D454(s32 arg0) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (arg0 != 0) {
            D_802290A0_9D8B10[i].gobj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_802290A0_9D8B10[i].gobj->data.sobj->sprite.attr |= SP_HIDDEN;
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

void func_801DDAD8_98D548(s32 arg0, s32 arg1) {
    char str[0x10];

    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036D4A0_840C50(0);
    func_8036A5B8_83DD68(D_802290E0_9D8B50, 0, 0x3C, 0xC8, 0x48, 0, 0, 0, 0);
    func_8036B870_83F020(D_802290E0_9D8B50, 1, 0xFF, 0xFF, 0, 0xFF);
    func_8036CB58_840308(D_802290E0_9D8B50, 8);
    func_8036D4A0_840C50(0);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Total")) / 2) - 71, 60);
    func_8036C898_840048(D_802290E0_9D8B50, "Total");
    func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
    func_8036D4A0_840C50(0);
    if (D_801F3E60_9A38D0) {
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 60);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        sprintf(str, "%5d", arg0);
        func_8036C9C0_840170(D_802290E0_9D8B50, str);
    }
    func_8036B9EC_83F19C(D_802290E0_9D8B50, 146, 60);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    sprintf(str, "%5d", arg1);
    func_8036C9C0_840170(D_802290E0_9D8B50, str);
    func_8036D4A0_840C50(2);
    func_8036B870_83F020(D_802290E0_9D8B50, 1, 0xFF, 0xFF, 0xFF, 0xFF);
}

void func_801DDCF8_98D768(UNK_PTR arg0) { // TODO STRUCT
    SObj* sp3C;
    f32 sp38;
    f32 sp34;
    s32 i;
    s32 sp2C;

    func_80022A58(0x4F, 0x7FFF, 0x2C, 1.65f, 0xA);
    D_8022918C_9D8BFC = FALSE;
    sp2C = arg0[0x58 / 4]; // TODO STRUCT
    sp3C = D_802290A0_9D8B10[1].gobj->data.sobj;
    sp3C->sprite.x = -140;
    sp3C->sprite.y = 37;
    sp3C->sprite.attr &= ~SP_HIDDEN;
    i = 30;

    for (sp34 = 0.0f, sp38 = -199.0f; sp38 > -200.0f; ohWait(1)) {
        if (D_801F3E2C_9A389C == 2) {
            sp3C->sprite.x = -140;
            break;
        }

        if (D_801F3E34_9A38A4) {
            sp3C->sprite.x = 59;
            sp38 = 0.0f;
            sp34 = 0.0f;
        } else if (D_801F3E2C_9A389C != 0) {
            if (i > 0) {
                i--;
                continue;
            } else {
                if (!D_8022918C_9D8BFC) {
                    func_80022A58(0x50, 0x7FFF, 0x22, 1.0f, 0xA);
                    D_8022918C_9D8BFC = TRUE;
                }
                sp34 = -210.0f;
            }
        }

        sp38 += (sp34 - sp38) * 0.1f;
        if (D_801F3E2C_9A389C == 3) {
            i = 10;

            for (i--; i > 0; i--) {
                if (i % 2) {
                    sp3C->sprite.attr |= SP_HIDDEN;
                } else {
                    sp3C->sprite.attr &= ~SP_HIDDEN;
                }
                ohWait(2);
            }
            break;
        } else {
            if (ABS(sp38) < 0.5) {
                sp3C->sprite.x = 59;
            } else {
                sp3C->sprite.x = 59.0f + sp38;
            }
        }
    }

    sp3C->sprite.attr |= SP_HIDDEN;
    D_801F3E2C_9A389C = 2;
    omDeleteGObj(NULL);
    ohWait(0x63);
}

void func_801DE02C_98DA9C(UNK_PTR arg0) {
    f32 sp24;

    D_80229188_9D8BF8->sprite.y = 0;
    D_80229188_9D8BF8->sprite.x = -211;
    D_80229188_9D8BF8->sprite.attr &= ~SP_HIDDEN;
    sp24 = 7.0f;

    while (D_80229188_9D8BF8->sprite.x >= -211) {
        if (D_801F3E30_9A38A0 == 2) {
            break;
        }

        switch (D_801F3E30_9A38A0) {
            case 0:
                sp24 -= 0.1f;
                break;
            case 4:
                D_80229188_9D8BF8->sprite.x = -12;
                sp24 = 0.0f;
                break;
            case 1:
                sp24 = -16.0f;
        }

        D_80229188_9D8BF8->sprite.x += sp24;
        if (D_80229188_9D8BF8->sprite.x > -12) {
            D_80229188_9D8BF8->sprite.x = -12;
            D_801F3E30_9A38A0 = 4;
        }
        ohWait(1);
    }
    D_80229188_9D8BF8->sprite.attr |= SP_HIDDEN;
    D_801F3E30_9A38A0 = 2;
    omDeleteGObj(NULL);
    ohWait(0x63);
}

s32 func_801DE204_98DC74(Photo* photo) {
    Unk803A6C18* sp25C;
    s32 sp258;
    s32 sp254;
    char sp214[0x40];
    s32 sp210;
    s32 sp20C;
    s32 sp208;
    s32 sp204;
    s32 sp200;
    s32 sp1FC;
    u16 sp1FA;
    f32 sp1F4;
    s32 sp1F0;
    s32 sp1EC;
    s32 sp1E8;
    GObj* sp1E4;
    char sp1D4[16];
    char sp1C4[16];
    GObj* sp1C0;
    GObj* sp1BC;
    GObj* sp1B8;
    GObj* sp1B4;
    char sp1A4[16];
    s32 sp1A0;
    f32 sp19C;
    char sp18C[16];
    char sp17C[16];
    char sp16C[16];
    char sp15C[16];
    u32 sp158;
    char sp148[16];
    char sp138[16];
    char sp128[16];
    char sp118[16];
    char sp108[16];
    s32 sp104;
    char spF4[16];
    char spE4[16];
    s32 spE0;
    char spD0[16];
    u16 spCE;
    u16 spCC;
    u16 spCA;
    f32 spC4;
    char spB4[16];
    char spA4[16];
    char sp94[16];
    char sp84[16];
    char sp74[16];
    char sp64[16];
    char sp54[16];
    char sp44[16];
    UnkStruct800BEDF8* sp40;
    s32 sp3C;

    sp1F0 = 2;
    sp210 = 0;
    sp204 = 0;
    sp200 = 0;
    sp1FC = FALSE;
    sp1E8 = FALSE;
    sp258 = D_802290E0_9D8B50;
    sp254 = D_802290DC_9D8B4C;
    func_8036A5B8_83DD68(sp258, 0xE, 0x4E, 0x8E, 0x72, 0, 0, 0, 0);
    if (func_800BF3D4_5C274(photo->pkmnID) != 0) {
        sp20C = TRUE;
        D_801F3E60_9A38D0 = TRUE;
        D_801F3E64_9A38D4 = 0;
        sp25C = func_8037452C_847CDC(func_800BF710_5C5B0(photo->pkmnID));
        if (D_801F3E34_9A38A4) {
            D_801F3E2C_9A389C = 0;
            sp1E4 = func_800A85E8(func_801DDCF8_98D768, 6, 0, 0);
            sp1E4->userData = func_800BF710_5C5B0(photo->pkmnID);
            sp1E8 = TRUE;
            ohWait(1);
        }
    } else {
        func_801DD638_98D0A8(1);
        sp20C = FALSE;
        D_801F3E60_9A38D0 = FALSE;
    }
    sp208 = !(photo->pkmnID < 0x3EC);// == 0;
    func_8036A8E4_83E094(D_802290E0_9D8B50);

    // Special pokemon (and forms)
    if (photo->specialID != 0) {
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036C898_840048(D_802290DC_9D8B4C, "\\CWow! Isn't this \n");
        func_8036B870_83F020(D_802290DC_9D8B4C, 1, 0xFF, 0xFF, 0, 0xFF);
        func_80022A58(0x60, 0x7FFF, 0x40, 0.7f, 0xA);
        func_8036C898_840048(D_802290DC_9D8B4C, SpecialPokemonNames[photo->specialID]);
        func_8036B870_83F020(D_802290DC_9D8B4C, 1, 0xFF, 0xFF, 0xFF, 0xFF);
        func_8036C898_840048(D_802290DC_9D8B4C, "!?!");
        if (!D_801F3E34_9A38A4 && func_801DD05C_98CACC(D_802290DC_9D8B4C, 1) == 0x4000) {
            D_801F3E34_9A38A4 = TRUE;
        }
        func_8036CB58_840308(D_802290E0_9D8B50, 8);
        func_8036D4A0_840C50(0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Special")) / 2) - 71, 48);
        func_8036C898_840048(D_802290E0_9D8B50, "Special");
        func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
        if (D_801F3E60_9A38D0 && sp25C->unk_3B4 != 0) {
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp1D4, "%5d", sp25C->unk_3B2);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, sp1D4);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
        }
        func_8036A8E4_83E094(D_802290DC_9D8B4C);
        func_8036B870_83F020(D_802290DC_9D8B4C, 1, 0xFF, 0xFF, 0, 0xFF);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8037519C_84894C(D_802290DC_9D8B4C, SpecialPokemonNames[photo->specialID]);
        func_8036B870_83F020(D_802290DC_9D8B4C, 1, 0xFF, 0xFF, 0xFF, 0xFF);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036C898_840048(D_802290DC_9D8B4C, "\nhas a value of ");
        func_800228E4(0x5D);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        sprintf(sp1C4, "%5d", photo->specialBonus);
        func_8036D4A0_840C50(0);
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
        func_8036C9C0_840170(D_802290E0_9D8B50, sp1C4);
        func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8037519C_84894C(D_802290DC_9D8B4C, "%d", photo->specialBonus);
        func_8036C898_840048(D_802290DC_9D8B4C, "pts!");
        sp210 += photo->specialBonus;
        if (sp20C) {
            D_801F3E64_9A38D4 = sp25C->unk_3B4 ? sp25C->unk_3B2 : 0;
        }
    } else if (!D_801F3E34_9A38A4) {
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        if (sp208) {
            func_8036C898_840048(D_802290DC_9D8B4C, "\\BOh! This is exactly the PKMN\nSign I've been looking for!");
        } else {
            func_8037519C_84894C(D_802290DC_9D8B4C, "Let me see...\nThis is %s!!", func_8009B9D0(photo->pkmnID));
        }
    }
    if (!D_801F3E34_9A38A4 && (func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000)) {
        D_801F3E34_9A38A4 = TRUE;
    }
    if (sp208) {
        if (!sp20C) {
            if (D_801F3E34_9A38A4) {
                D_801F3E30_9A38A0 = 4;
            } else {
                D_801F3E30_9A38A0 = 0;
            }
            sp1C0 = func_800A85E8(func_801DE02C_98DA9C, 6, 0, 0);
            if (1) {}
        } else if (D_801F3E60_9A38D0) {
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            func_8036CB58_840308(D_802290E4_9D8B54, 8);
            func_8036B9EC_83F19C(D_802290E4_9D8B54, 0, 0);
            func_8036C898_840048(D_802290E4_9D8B54, "Last time");
            func_8036B9EC_83F19C(D_802290E4_9D8B54, 0x90, 0);
            func_8036C898_840048(D_802290E4_9D8B54, "This time");
            if (!sp1E8) {
                D_801F3E2C_9A389C = 0;
                sp1BC = func_800A85E8(func_801DDCF8_98D768, 6, 0, 0);
                sp1BC->userData = func_800BF710_5C5B0(photo->pkmnID);
            }
        }
    } else {
        if (!sp20C) {
            if (D_801F3E34_9A38A4) {
                D_801F3E30_9A38A0 = 4;
            } else {
                D_801F3E30_9A38A0 = 0;
            }
            sp1B8 = func_800A85E8(func_801DE02C_98DA9C, 6, 0, 0);
            if (photo->specialID != 0) {
                func_800228E4(0x4E);
            }
            func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
            func_801DD1A8_98CC18(0x1E);
        } else if (!sp1E8) {
            D_801F3E2C_9A389C = 0;
            sp1B4 = func_800A85E8(func_801DDCF8_98D768, 6, 0, 0);
            sp1B4->userData = func_800BF710_5C5B0(photo->pkmnID);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_800228E4(0x4D);
            func_8037519C_84894C(D_802290DC_9D8B4C, "%s's picture\nis in the PKMN Report already.", func_8009B9D0(photo->pkmnID));
            func_8036D4A0_840C50(0);
            if (photo->specialID != 0) {
                func_800228E4(0x4E);
            }
            if (D_801F3E60_9A38D0 && sp25C->unk_3B4 != 0) {
                func_8036CB58_840308(D_802290E0_9D8B50, 8);
                func_8036D4A0_840C50(0);
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Special")) / 2) - 71, 48);
                func_8036C898_840048(D_802290E0_9D8B50, "Special");
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(sp1A4, "%5d", sp25C->unk_3B2);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, sp1A4);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                D_801F3E64_9A38D4 = sp25C->unk_3B2;
            }
            if (D_801F3E60_9A38D0) {
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                func_8036CB58_840308(D_802290E4_9D8B54, 8);
                func_8036B9EC_83F19C(D_802290E4_9D8B54, 0, 0);
                func_8036C898_840048(D_802290E4_9D8B54, "Last time");
                func_8036B9EC_83F19C(D_802290E4_9D8B54, 0x90, 0);
                func_8036C898_840048(D_802290E4_9D8B54, "This time");
            }
            func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
            func_8036D4A0_840C50(2);
            if (!D_801F3E34_9A38A4 && func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000) {
                D_801F3E34_9A38A4 = TRUE;
            }
        }
        sp1F4 = photo->sizeParam1 / 10000.0f;
        sp1FA = ((u32) (((photo->sizeParam2 * sp1F4) + 5.0f) / 10.0f) & 0xFFFF) * 0xA;
    }

    if (!sp208 && !D_801F3E34_9A38A4) {
        func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
        func_800228E4(0x4D);
        func_8036CB58_840308(D_802290E0_9D8B50, 8);
        func_8036D4A0_840C50(0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Size")) / 2) - 71, 48);
        func_8036C898_840048(D_802290E0_9D8B50, "Size");
        func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
        func_8036A8E4_83E094(D_802290DC_9D8B4C);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036C898_840048(D_802290DC_9D8B4C, "How's the Size?");
        if (D_801F3E60_9A38D0) {
            sp19C = sp25C->unk_3AE / 10000.0f;
            sp1A0 = ((u32) (((sp25C->unk_3AC * sp19C) + 5.0f) / 10.0f) & 0xFFFF) * 0xA;
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp18C, "%5d", sp1A0);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, sp18C);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            if (sp25C->unk_3AC < 245.0f || sp25C->unk_3AE < 6000.0f) {
                sp1FC = TRUE;
            }
            D_801F3E64_9A38D4 += sp1A0;
        }
        if ((!D_801F3E34_9A38A4) && (func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000)) {
            D_801F3E34_9A38A4 = TRUE;
        }
    }
    sp210 += sp1FA;
    if (!sp208 && !D_801F3E34_9A38A4) {
        func_80022A58(0x56, 0x7FFF, 0x40, D_801F3E3C_9A38AC[sp1F0++] + 1.0, 0x1E);
        func_801DD1A8_98CC18(0x2D);
        if (photo->sizeParam2 < 245.0f || photo->sizeParam1 < 6000.0f) {
            sp204 = 1;
            func_800228E4(0x5F);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp17C, "%5d", sp1FA);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, sp17C);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
            func_8037519C_84894C(D_802290DC_9D8B4C, "%d", sp1FA);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "pts. Hmm...");
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
            func_8036C898_840048(D_802290DC_9D8B4C, "It's not very good.");
            if (!D_801F3E34_9A38A4 && func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000) {
                D_801F3E34_9A38A4 = TRUE;
            }
            sp200 = 1;
            func_800228E4(0x4D);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "\\HYou were close.");
            if (photo->sizeParam2 < 245.0f) {
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
                func_8036C898_840048(D_802290DC_9D8B4C, "But it would have been better\nif it were a larger shot.");
            } else {
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
                func_8036C898_840048(D_802290DC_9D8B4C, "It would be better if more of\nthe Pokεmon were in the shot.");
            }
        } else if (sp1FA < 795.0f) {
            func_800228E4(0x5E);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp16C, "%5d", sp1FA);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, sp16C);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
            func_8037519C_84894C(D_802290DC_9D8B4C, "%d", sp1FA);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "pts! Hmm...");
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
            func_8036C898_840048(D_802290DC_9D8B4C, "It's so-so.");
        } else {
            func_800228E4(0x5D);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp15C, "%5d", sp1FA);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, sp15C);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
            func_8037519C_84894C(D_802290DC_9D8B4C, "%d", sp1FA);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "pts! All right!");
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
            func_8036C898_840048(D_802290DC_9D8B4C, "It's very nice!");
        }
        func_800228E4(0x4E);
        func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
        if ((!D_801F3E34_9A38A4) && (func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000)) {
            D_801F3E34_9A38A4 = TRUE;
        }
    }
    if (!sp208 && !D_801F3E34_9A38A4 && sp204 == 0) {
        func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
        func_800228E4(0x4D);
        func_8036CB58_840308(D_802290E0_9D8B50, 8);
        func_8036D4A0_840C50(0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Pose")) / 2) - 71, 48);
        func_8036C898_840048(D_802290E0_9D8B50, "Pose");
        func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
        func_8036A8E4_83E094(D_802290DC_9D8B4C);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036C898_840048(D_802290DC_9D8B4C, "How's the Pose?");
        if (D_801F3E60_9A38D0 && !sp1FC) {
            sp158 = sp25C->unk_3B0;
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp148, "%5d", sp158);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, sp148);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            if (sp158 < 200) {
                sp1FC = TRUE;
            }
            D_801F3E64_9A38D4 += sp158;
        }
        if ((!D_801F3E34_9A38A4) && (func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000)) {
            D_801F3E34_9A38A4 = TRUE;
        }
    }
    if (sp204 == 0) {
        sp210 += photo->posePts;
    }
    if (!sp208 && !D_801F3E34_9A38A4 && sp204 == 0) {
        func_80022A58(0x56, 0x7FFF, 0x40, D_801F3E3C_9A38AC[sp1F0++] + 1.0, 0x1E);
        func_801DD1A8_98CC18(0x2D);
        if (photo->commentID != 0) {
            if (photo->posePts > 1000) {
                func_80022A58(0x60, 0x7FFF, 0x40, 0.7f, 0xA);
                func_8036B870_83F020(D_802290DC_9D8B4C, 1, 0xFF, 0xFF, 0, 0xFF);
            }
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
            func_8036C898_840048(D_802290DC_9D8B4C, PhotoComments[photo->commentID]);
            func_8036B870_83F020(D_802290DC_9D8B4C, 1, 0xFF, 0xFF, 0xFF, 0xFF);
            if (photo->posePts < 200) {
                func_800228E4(0x5F);
            } else {
                func_800228E4(0x5D);
            }
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp138, "%5d", photo->posePts);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, sp138);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
            func_8037519C_84894C(D_802290DC_9D8B4C, "%d", photo->posePts);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "pts!");
            func_800228E4(0x4E);
            func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
            if (photo->posePts < 200) {
                sp204 = 2;
                if (!D_801F3E34_9A38A4 && func_801DD05C_98CACC(D_802290DC_9D8B4C, 1) == 0x4000) {
                    D_801F3E34_9A38A4 = TRUE;
                }
                func_8036A8E4_83E094(D_802290DC_9D8B4C);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036C898_840048(D_802290DC_9D8B4C, "Hmm...\nNot so good.");
            }
        } else {
            if (photo->posePts < 200) {
                sp204 = 2;
                func_800228E4(0x5F);
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(sp128, "%5d", photo->posePts);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, sp128);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
                func_8037519C_84894C(D_802290DC_9D8B4C, "%d", photo->posePts);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036C898_840048(D_802290DC_9D8B4C, "pts! Hmm...");
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
                func_8036C898_840048(D_802290DC_9D8B4C, "It's not very good.");
                if ((!D_801F3E34_9A38A4) && (func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000)) {
                    D_801F3E34_9A38A4 = TRUE;
                }
                sp200 = 1;
                func_800228E4(0x4D);
                func_8036A8E4_83E094(D_802290DC_9D8B4C);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036C898_840048(D_802290DC_9D8B4C, "\\HYou were close, but you see...\nIt disappoints Pokεmon to\nbe photographed from behind!");
            } else if (photo->posePts < 800) {
                func_800228E4(0x5E);
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(sp118, "%5d", photo->posePts);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, sp118);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
                func_8037519C_84894C(D_802290DC_9D8B4C, "%d", photo->posePts);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036C898_840048(D_802290DC_9D8B4C, "pts! Hmm...");
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
                func_8036C898_840048(D_802290DC_9D8B4C, "It's so-so.");
            } else {
                func_800228E4(0x5D);
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(sp108, "%5d", photo->posePts);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, sp108);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
                func_8037519C_84894C(D_802290DC_9D8B4C, "%d", photo->posePts);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036C898_840048(D_802290DC_9D8B4C, "pts! All right!");
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
                func_8036C898_840048(D_802290DC_9D8B4C, "It's very nice!");
            }
            func_800228E4(0x4E);
            func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
        }
        if ((!D_801F3E34_9A38A4) && (func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000)) {
            D_801F3E34_9A38A4 = TRUE;
        }
    }
    if (!sp208 && !D_801F3E34_9A38A4 && sp204 == 0) {
        func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
        func_800228E4(0x4D);
        func_8036CB58_840308(D_802290E0_9D8B50, 8);
        func_8036D4A0_840C50(0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Technique")) / 2) - 71, 48);
        func_8036C898_840048(D_802290E0_9D8B50, "Technique");
        func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
        func_8036A8E4_83E094(D_802290DC_9D8B4C);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036C898_840048(D_802290DC_9D8B4C, "How's the Technique?");
        if (D_801F3E60_9A38D0 && !sp1FC) {
            if (sp25C->unk_3A7 != 0) {
                func_8036CB58_840308(D_802290E0_9D8B50, 8);
                func_8036D4A0_840C50(0);
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(sp214, "ｘ２");
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 38 - func_8036D4F0_840CA0(sp214), 48);
                func_8036C898_840048(D_802290E0_9D8B50, sp214);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                D_801F3E64_9A38D4 += D_801F3E64_9A38D4; // TODO points?
            } else {
                sp1FC = TRUE;
            }
        }
        if (!D_801F3E34_9A38A4 && func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000) {
            D_801F3E34_9A38A4 = TRUE;
        }
    }
    if (!sp208 && !D_801F3E34_9A38A4 && sp204 == 0) {
        func_80022A58(0x56, 0x7FFF, 0x40, D_801F3E3C_9A38AC[sp1F0++] + 1.0, 0x1E);
        func_801DD1A8_98CC18(0x2D);
        if (photo->isWellFramed) {
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
            func_8036C898_840048(D_802290DC_9D8B4C, "OK! The Pokεmon is right in");
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
            func_8036C898_840048(D_802290DC_9D8B4C, "the middle of the frame.");
            if (!D_801F3E34_9A38A4 && func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000) {
                D_801F3E34_9A38A4 = TRUE;
            }
            func_800228E4(0x4D);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "I can ");
            func_8036CB58_840308(D_802290E0_9D8B50, 8);
            func_8036D4A0_840C50(0);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp214, "ｘ２");
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0xB8 - func_8036D4F0_840CA0(sp214), 48);
            func_8036C898_840048(D_802290E0_9D8B50, sp214);
            func_8036B870_83F020(D_802290DC_9D8B4C, 1, 0xFF, 0xFF, 0, 0xFF);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "double ");
            func_8036B870_83F020(D_802290DC_9D8B4C, 1, 0xFF, 0xFF, 0xFF, 0xFF);
            func_80022A58(0x60, 0x7FFF, 0x40, 0.7f, 0xA);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "the score for you!");
            sp210 *= 2;
            func_800228E4(0x4E);
            func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
        } else {
            sp204 = 3;
            func_800228E4(0x5F);
            func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "\\QWait...\nYour Pokεmon isn't\nin the middle of the frame.");
            if ((!D_801F3E34_9A38A4) && (func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000)) {
                D_801F3E34_9A38A4 = TRUE;
            }
            sp200 = 1;
            func_800228E4(0x4D);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C,  "It would have been\nperfect if the Pokεmon were\nin the middle of the frame.");
        }
        if ((!D_801F3E34_9A38A4) && (func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000)) {
            D_801F3E34_9A38A4 = TRUE;
        }
    }
    if (!sp208 && !D_801F3E34_9A38A4 && sp204 == 0) {
        if (photo->unk_9 != 0 && photo->samePkmnBonus != 0) {
            func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
            if (D_801F3E60_9A38D0 && sp25C->unk_3A4 != 0) {
                sp104 = sp25C->unk_3A4;
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(spF4, "%5d", sp104);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, spF4);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                D_801F3E64_9A38D4 += sp104;
            }
            sp210 += photo->samePkmnBonus;
            func_8036CB58_840308(D_802290E0_9D8B50, 8);
            func_8036D4A0_840C50(0);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Same †‡")) / 2) - 71, 48);
            func_8036C898_840048(D_802290E0_9D8B50, "Same †‡");
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "\\CWow!");
            func_80022A58(0x56, 0x7FFF, 0x40, D_801F3E3C_9A38AC[sp1F0++] + 1.0, 0x1E);
            func_801DD1A8_98CC18(0x2D);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x10);
            func_8036C898_840048(D_802290DC_9D8B4C, "There are other ");
            func_80022A58(0x60, 0x7FFF, 0x40, 0.7f, 0xA);
            func_8037519C_84894C(D_802290DC_9D8B4C, "%s", func_8009B9D0(photo->pkmnID));
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
            func_8036C898_840048(D_802290DC_9D8B4C, "in the picture.");
            if (!D_801F3E34_9A38A4 && func_801DD05C_98CACC(D_802290DC_9D8B4C, 1) == 0x4000) {
                D_801F3E34_9A38A4 = TRUE;
            }
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "I'll give you an extra\n");
            func_800228E4(0x5D);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(spE4, "%5d", photo->samePkmnBonus);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, spE4);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8037519C_84894C(D_802290DC_9D8B4C, "%spts.", func_8037501C("%d", photo->samePkmnBonus));
            func_800228E4(0x4E);
            func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
            func_801DD1A8_98CC18(0x2D);
            if (!D_801F3E34_9A38A4 && func_801DD05C_98CACC(D_802290DC_9D8B4C, 0) == 0x4000) {
                D_801F3E34_9A38A4 = TRUE;
            }
        } else if (D_801F3E60_9A38D0 && sp25C->unk_3A4 != 0) {
            func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
            func_8036CB58_840308(D_802290E0_9D8B50, 8);
            func_8036D4A0_840C50(0);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Same †‡")) / 2) - 71, 48);
            func_8036C898_840048(D_802290E0_9D8B50, "Same †‡");
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            spE0 = sp25C->unk_3A4;
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(spD0, "%5d", spE0);
            func_8036D4A0_840C50(0);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
            func_8036C9C0_840170(D_802290E0_9D8B50, spD0);
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            D_801F3E64_9A38D4 += spE0;
            func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
        }
    }
    sp210 = photo->unk_4;
    if (sp20C) {
        D_801F3E64_9A38D4 = sp25C->unk_3A0;
    }
    if (!sp208 && (D_801F3E34_9A38A4 != 0 || sp204 != 0)) {
        if (sp20C) {
            spC4 = sp25C->unk_3AE / 10000.0f;
            spCC = ((u32) (((sp25C->unk_3AC * spC4) + 5.0f) / 10.0f) & 0xFFFF) * 0xA;
        }
        spC4 = photo->sizeParam1 / 10000.0f;
        spCA = ((u32) (((photo->sizeParam2 * spC4) + 5.0f) / 10.0f) & 0xFFFF) * 0xA;
        func_800228E4(0x4D);
        func_8036A8E4_83E094(D_802290E0_9D8B50);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036D4A0_840C50(0);
        if ((sp20C && sp25C->unk_3B4 != 0) || photo->specialID != 0) {
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x4B, 0x30);
            func_8036C898_840048(D_802290E0_9D8B50, "Special");
            if (sp20C) {
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                if (sp25C->unk_3B4 != 0) {
                    func_8036D448_840BF8(0);
                    func_8036D3E8_840B98(0, 4);
                    sprintf(spB4, "%5d", sp25C->unk_3B2);
                    func_8036D4A0_840C50(0);
                    func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                    func_8036C9C0_840170(D_802290E0_9D8B50, spB4);
                    func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                }
            }
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
            if (photo->specialID != 0) {
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(spA4, "%5d", photo->specialBonus);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, spA4);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            }
            ohWait(2);
        }
        func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
        func_8036CB58_840308(D_802290E0_9D8B50, 8);
        func_8036D4A0_840C50(0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Size")) / 2) - 71, 48);
        func_8036C898_840048(D_802290E0_9D8B50, "Size");
        func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
        if (sp20C) {
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
            spCE = spCC;
            if (spCE != 0) {
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(sp94, "%5d", spCE);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, sp94);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            }
        }
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        sprintf(sp84, "%5d", spCA);
        func_8036D4A0_840C50(0);
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
        func_8036C9C0_840170(D_802290E0_9D8B50, sp84);
        func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
        ohWait(2);
        func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
        if ((sp20C && sp25C->unk_3B0 != 0) || photo->posePts != 0) {
            func_8036CB58_840308(D_802290E0_9D8B50, 8);
            func_8036D4A0_840C50(0);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Pose")) / 2) - 71, 48);
            func_8036C898_840048(D_802290E0_9D8B50, "Pose");
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            if (sp20C) {
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                spCE = sp25C->unk_3B0;
                if (spCE != 0) {
                    func_8036D448_840BF8(0);
                    func_8036D3E8_840B98(0, 4);
                    sprintf(sp74, "%5d", spCE);
                    func_8036D4A0_840C50(0);
                    func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                    func_8036C9C0_840170(D_802290E0_9D8B50, sp74);
                    func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                }
            }
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
            if (photo->posePts != 0) {
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(sp64, "%5d", photo->posePts);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, sp64);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            }
            ohWait(2);
        }
        func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
        if ((sp20C && sp25C->unk_3A7 != 0) || photo->isWellFramed) {
            func_8036CB58_840308(D_802290E0_9D8B50, 8);
            func_8036D4A0_840C50(0);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Technique")) / 2) - 71, 48);
            func_8036C898_840048(D_802290E0_9D8B50, "Technique");
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            func_8036CB58_840308(D_802290E0_9D8B50, 8);
            func_8036D4A0_840C50(0);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            sprintf(sp214, "ｘ２");
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x26 - func_8036D4F0_840CA0(sp214), 0x30);
            if (sp20C && sp25C->unk_3A7 != 0) {
                func_8036C898_840048(D_802290E0_9D8B50, sp214);
            }
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0xB8 - func_8036D4F0_840CA0(sp214), 0x30);
            if (photo->isWellFramed) {
                func_8036C898_840048(D_802290E0_9D8B50, sp214);
            }
        }
        ohWait(2);
        if ((sp20C && sp25C->unk_3A4 > 0) || photo->samePkmnBonus > 0) {
            func_8036C2FC_83FAAC(D_802290E0_9D8B50, 0xC, 0, 0, 0, 0x104, 0x3B);
            func_8036CB58_840308(D_802290E0_9D8B50, 8);
            func_8036D4A0_840C50(0);
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            func_8036B9EC_83F19C(D_802290E0_9D8B50, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Same †‡")) / 2) - 71, 48);
            func_8036C898_840048(D_802290E0_9D8B50, "Same †‡");
            func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            if (sp20C) {
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                spCE = sp25C->unk_3A4;
                if (spCE != 0) {
                    func_8036D448_840BF8(0);
                    func_8036D3E8_840B98(0, 4);
                    sprintf(sp54, "%5d", spCE);
                    func_8036D4A0_840C50(0);
                    func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 0x30);
                    func_8036C9C0_840170(D_802290E0_9D8B50, sp54);
                    func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
                }
            }
            func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
            if (photo->samePkmnBonus != 0) {
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                sprintf(sp44, "%5d", photo->samePkmnBonus);
                func_8036D4A0_840C50(0);
                func_8036B9EC_83F19C(D_802290E0_9D8B50, 0x92, 0x30);
                func_8036C9C0_840170(D_802290E0_9D8B50, sp44);
                func_8036D4A0_840C50(D_801F3E34_9A38A4 ? 0 : 2);
            }
            ohWait(2);
        }
        sp210 = photo->unk_4;
        if (sp20C) {
            D_801F3E64_9A38D4 = sp25C->unk_3A0;
        }
        func_801DDAD8_98D548(D_801F3E64_9A38D4, sp210);
        if (sp204 == 0 && (photo->sizeParam2 < 245 || photo->sizeParam1 < 6000 || photo->posePts < 200 || !photo->isWellFramed)) {
            sp204 = 1;
        }
    }
    if (!sp20C) {
        if (D_801F3E34_9A38A4 != 0 && sp204 != 0) {
            func_800228E4(0x55);
            if (sp200 == 0) {
                func_8036A8E4_83E094(D_802290DC_9D8B4C);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036C898_840048(D_802290DC_9D8B4C, "\\HYou were close.\nI expect a better shot\nnext time.");
                func_801DD05C_98CACC(D_802290DC_9D8B4C, 1);
            }
            sp1EC = 0;
            func_8036A8E4_83E094(D_802290E4_9D8B54);
            func_8036A8E4_83E094(D_802290E0_9D8B50);
        }
        if (sp204 == 0) {
            if (!sp208) {
                func_80022374(1, 0x1F);
            } else {
                func_800228E4(0x61);
            }
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "\\GWonderful!\nYour work is impeccable.\nKeep up the good work!");
            sp1EC = 0xA;
            func_801DD05C_98CACC(D_802290DC_9D8B4C, 1);
            func_8036A8E4_83E094(D_802290E4_9D8B54);
            func_8036A8E4_83E094(D_802290E0_9D8B50);
        }
        func_801DCFE8_98CA58(photo);
    } else if (sp210 > D_801F3E64_9A38D4) {
        if (!sp208) {
            func_80022374(1, 0x1F);
        } else {
            func_800228E4(0x61);
        }
        func_8036A8E4_83E094(D_802290DC_9D8B4C);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036C898_840048(D_802290DC_9D8B4C, "\\FWell done.\nThis picture is much better\nthan the last one.");
        func_801DD05C_98CACC(D_802290DC_9D8B4C, 1);
        D_801F3E2C_9A389C = 3;
        sp1EC = 0x3C;
        func_8036A8E4_83E094(D_802290E4_9D8B54);
        func_8036A8E4_83E094(D_802290E0_9D8B50);
        func_801DCFE8_98CA58(photo);
    } else {
        sp3C = 0;
        if (sp210 == D_801F3E64_9A38D4) {
            func_800228E4(0x4D);
            if (sp208) {
                func_8036A8E4_83E094(D_802290DC_9D8B4C);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036C898_840048(D_802290DC_9D8B4C, "Hmm...\nBoth pictures are\npretty good.");
            } else {
                func_8036A8E4_83E094(D_802290DC_9D8B4C);
                func_8036D448_840BF8(1);
                func_8036D3E8_840B98(-1, 3);
                func_8036C898_840048(D_802290DC_9D8B4C, "Hmm... It's the same score\nas last time.");
            }
        } else {
            func_800228E4(0x55);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036C898_840048(D_802290DC_9D8B4C, "Oh, dear... Your last shot\nwas better than this.");
        }
        func_801DD05C_98CACC(D_802290DC_9D8B4C, 1);
        func_8036A8E4_83E094(D_802290DC_9D8B4C);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036C898_840048(D_802290DC_9D8B4C, "Which picture are you going\nto save to your Report?\nPress \\a to Save.");
        func_801E41FC_993C6C(NULL, &sp3C);
        ohWait(8);

// TODO LABEL
loop_1:
        sp40 = func_800AA38C(0);
        func_801E41FC_993C6C(sp40, &sp3C);
        if (sp40->unk_18 & 0x8000) {
            func_803700A4_843854(0);
            if (sp3C != NULL) {
                func_800228E4(0x5F);
                func_801DCFE8_98CA58(photo);
                D_801F3E2C_9A389C = 3;
                sp1EC = 0x3C;
            } else {
                func_800228E4(0x53);
                photo->unk_1A_14 = 0;
                D_801F3E2C_9A389C = 1;
                sp1EC = 0;
            }
        } else {
            ohWait(1);
            goto loop_1;
        }
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0x20);
        func_8036C898_840048(D_802290DC_9D8B4C, "                             ");

    }
    ohWait(1);
    func_8036A8E4_83E094(D_802290E4_9D8B54);
    func_8036A8E4_83E094(D_802290E0_9D8B50);
    func_8036A8E4_83E094(D_802290DC_9D8B4C);
    func_8036EE40_8425F0();
    ohWait(2);
    func_801DD638_98D0A8(0);
    D_801F3E34_9A38A4 = FALSE;
    return sp1EC;
}

s32 func_801E1FA8_991A18(Photo* arg0, s32 arg1, s32 arg2) {
    SObj* sp5C;
    f32 sp58;
    f32 sp54;
    s32 sp50;
    ObjPair* sp4C;
    s32 sp48;
    s32 i;
    s32 sp40;
    s32 sp3C;

    D_801F3E34_9A38A4 = FALSE;
    if (func_800BF3D4_5C274(arg0->pkmnID) != 0) {
        sp5C = D_802290A0_9D8B10[1].gobj->data.sobj;
        sp5C->sprite.x = -140;
        sp5C->sprite.y = 37;
        sp5C->sprite.attr &= ~SP_HIDDEN;
        func_80374714_847EC4(func_800BF710_5C5B0(arg0->pkmnID), &D_802290A0_9D8B10[1].sobj->sprite);
        ohWait(2);
        func_80374714_847EC4(func_800BF710_5C5B0(arg0->pkmnID), &D_802290A0_9D8B10[1].sobj->sprite);
        ohWait(2);
    }
    func_80022A58(0x4F, 0x7FFF, 0x4A, 1.0f, 0xA);
    sp4C = D_802290A0_9D8B10;
    sp5C = D_802290A0_9D8B10->gobj->data.sobj;
    sp5C->sprite.x = 431;
    sp5C->sprite.y = 37;
    sp5C->sprite.attr &= ~SP_HIDDEN;
    func_80374714_847EC4(arg0->unk_0, &D_802290A0_9D8B10->sobj->sprite);
    ohWait(2);
    func_80374714_847EC4(arg0->unk_0, &D_802290A0_9D8B10->sobj->sprite);
    if (arg1 != 0) {
        sp58 = -239.0f;
    } else {
        sp58 = 240.0f;
    }
    sp5C->sprite.x = 471;
    sp5C->sprite.attr &= ~SP_HIDDEN;
    if (func_800BF3D4_5C274(arg0->pkmnID) != 0) {
        sp48 = 0xE7;
        sp3C = 1;
    } else {
        sp48 = 0xE7;
        sp3C = 0;
    }

    sp40 = FALSE;
    for (sp54 = 0.0f; sp58 > -240.0f; ) {
            sp50 = func_801DD1A8_98CC18(1);
            if (!sp40 && sp50 != 0) {
                if (sp50 == 0x4000) {
                    D_801F3E34_9A38A4 = TRUE;
                }
                sp58 = 0.0f;
                sp54 = 0.0f;
            }
            sp58 += (sp54 - sp58) * 0.12;
            sp5C->sprite.x = sp48 + sp58 + arg2;

            if (ABS(sp54 - sp58) < 0.1) {
                func_8036D4A0_840C50(2);
                func_8036EB80_842330(1);
                sp40 = TRUE;
                i = func_801DE204_98DC74(arg0);
                if (D_801F3E2C_9A389C == 1) {
                    i = 10;

                    for(i--; i > 0; i--) {
                        if (i % 2) {
                            sp5C->sprite.attr |= SP_HIDDEN;
                        } else {
                            sp5C->sprite.attr &= ~SP_HIDDEN;
                        }
                        ohWait(2);
                    }
                }
                D_801F3E30_9A38A0 = 1;

                for (i--; i > 0; i--) {
                    ohWait(1);
                }
                func_8036D4A0_840C50(0);
                func_8036EB80_842330(0);
                sp54 = -250.0f;
            }
    }
    sp5C->sprite.attr |= SP_HIDDEN;
    return 0;
}

void func_801E242C_991E9C(UnkPinkBarracuda* arg0, s32 arg1, s32 arg2) {
    UNUSED s32 pad[3];

    PANIC();
}

void func_801E2454_991EC4(void) {
    s32 i;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    UNUSED s32 pad;
    char* sp48;
    Photo* photo;
    UNUSED s32 pad2;
    s32 sp3C;

    sp54 = -26;
    sp50 = 0;

    for (i = 0, sp58 = 0; i < 60; i++) {
        photo = func_801E459C_99400C(i);
        if (photo == NULL) {
            break;
        }
        if (photo->unk_1A_14 != 0) {
            sp58++;
            }
        if (photo->unk_1A_14 != 0 && func_800BF3D4_5C274(photo->pkmnID) == 0) {
            sp50++;
        }
    }
    if (sp58 == 0) {
        return;
    }
    sp3C = D_802290E0_9D8B50;
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036CB58_840308(sp3C, 8);

    for (i = 0, sp58 = 0; i < 60; i++) {
        photo = func_801E459C_99400C(i);
        if (photo == NULL) {
            break;
        }
        if (photo->unk_1A_14 == 0) {

        } else if (photo->pkmnID >= 0x3EC) {

        } else {
            func_8036A5B8_83DD68(sp3C, sp54 + 0x4C, 0x5A, sp54 + 0x84, 0x64, 0, 0, 0, 0);
            func_8036A5B8_83DD68(sp3C, sp54 + 71, 0xF, sp54 + 0x7F, 0x19, 0, 0, 0, 0);
            if (sp54 == 0) {
                sprintf(D_802290E8_9D8B58, "%7d", photo->unk_4);
                func_8036B9EC_83F19C(sp3C, sp54 + 0x4C, 0x5A);
                func_8036C9C0_840170(sp3C, D_802290E8_9D8B58);
            }
            func_8036A8E4_83E094(D_802290E4_9D8B54);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            sp48 = func_8009B9D0(photo->pkmnID);
            if (sp48 != NULL) {
                func_8036D448_840BF8(0);
                func_8036D3E8_840B98(0, 4);
                func_8036CB58_840308(D_802290E4_9D8B54, 0xC);
                func_8036B9EC_83F19C(D_802290E4_9D8B54, ((SCREEN_WIDTH - func_8036D4F0_840CA0(sp48)) / 2) - 71, 28);
                func_8036C898_840048(D_802290E4_9D8B54, sp48);
                func_8036D1A4_840954(D_802290E4_9D8B54, 0);
            }
            if (sp54 != 0) {
                func_801E1FA8_991A18(photo, 0, sp54);
            } else {
                func_801E242C_991E9C(photo->unk_0, 0, 0);
            }
            D_801F3E2C_9A389C = 2;
            D_801F3E30_9A38A0 = 2;
        }
    }

    for (i = 0, sp58 = 0; i < 60; i++) {
        photo = func_801E459C_99400C(i);
        if (photo == NULL) {
            break;
        }
        if (photo->unk_1A_14 == 0) {
            continue;
        }
        if (photo->pkmnID < 0x3EC) {

        } else {
            func_8036A8E4_83E094(D_802290E0_9D8B50);
            func_8036A8E4_83E094(D_802290E4_9D8B54);
            func_8036A8E4_83E094(D_802290DC_9D8B4C);
            photo->unk_1A_13 = 1;
            func_8036D448_840BF8(0);
            func_8036D3E8_840B98(0, 4);
            func_8036CB58_840308(D_802290E4_9D8B54, 0xC);
            func_8036B9EC_83F19C(D_802290E4_9D8B54, 0x3C, 0x1C);
            func_8036C898_840048(D_802290E4_9D8B54, "PKMN Sign");
            func_8036D1A4_840954(D_802290E4_9D8B54, 0);
            func_801E1FA8_991A18(photo, 0, sp54);
            break;
        }
    }
    func_8036A8E4_83E094(D_802290E4_9D8B54);
    func_8036A8E4_83E094(sp3C);
    func_8036A8E4_83E094(D_802290DC_9D8B4C);
    func_8036EE40_8425F0();
}

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
            ret++;
        }
    }

    return ret;
}

// arg2 is num photos left / num photos taken / something like that
void func_801E2AE8_992558(s32 numPokemon, s32 numPoints, s32 arg2) {
    UNUSED s32 pad[0x7];

    func_8036A8E4_83E094(D_802290E0_9D8B50);
    func_8036D4A0_840C50(0);
    func_8036CB58_840308(D_802290E0_9D8B50, 0xC);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);

    if (arg2 < 0) {
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 10);
        func_8037519C_84894C(D_802290E0_9D8B50, "Pokεmon in Report");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 109, 10);
        func_8037519C_84894C(D_802290E0_9D8B50, "\\i%7d\\g kind%s", numPokemon, numPokemon != 1 ? "s" : "");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 42);
        func_8036C898_840048(D_802290E0_9D8B50, "Report Score");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 109, 42);
        func_8037519C_84894C(D_802290E0_9D8B50, "\\i%7d\\g point%s", numPoints, numPoints != 1 ? "s" : "");
    } else {
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 2);
        func_8037519C_84894C(D_802290E0_9D8B50, "Pokεmon in Report", numPokemon != 1 ? "s" : "");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 109, 2);
        func_8037519C_84894C(D_802290E0_9D8B50, "\\i%7d\\g kind%s", numPokemon, numPokemon != 1 ? "s" : "");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 18);
        func_8036C898_840048(D_802290E0_9D8B50, "Report Score");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 109, 18);
        func_8037519C_84894C(D_802290E0_9D8B50, "\\i%7d\\g point%s", numPoints, numPoints != 1 ? "s" : "");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 34);
        func_8036C898_840048(D_802290E0_9D8B50, "Pictures in Album");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 109, 34);
        func_8037519C_84894C(D_802290E0_9D8B50, "\\i%7d\\g shot%s",
                             func_801E2A68_9924D8() - arg2,
                             (func_801E2A68_9924D8() - arg2) != 1 ? "s" : "");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 0, 50);
        func_8036C898_840048(D_802290E0_9D8B50, "Left in Album");
        func_8036B9EC_83F19C(D_802290E0_9D8B50, 109, 50);
        func_8037519C_84894C(D_802290E0_9D8B50, "\\i%7d\\g shot%s",
                             (func_800BF9EC_5C88C() - func_801E2A68_9924D8()) + arg2,
                             ((func_800BF9EC_5C88C() - func_801E2A68_9924D8()) + arg2) != 1 ? "s" : "");
    }
}

void func_801E2ED4_992944(s32 arg0) {
    s32 i;
    UNUSED s32 pad;
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    Photo* photo;
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    UNUSED s32 pad2;

    sp54 = 0;
    sp50 = 0;
    sp4C = 0;
    sp48 = 0;
    sp44 = 0;
    sp3C = 2;
    sp38 = 0;
    sp34 = 0;
    sp30 = 0;

    func_8036A8E4_83E094(D_802290E4_9D8B54);
    func_8036A8E4_83E094(D_802290DC_9D8B4C);
    func_8036B5F0_83EDA0(D_802290E0_9D8B50);
    D_802290E0_9D8B50 = func_8036AC6C_83E41C(0x36, 0x58, 0xD8, 0x48, 0);
    func_8036B734_83EEE4(D_802290E0_9D8B50);
    func_8036CB58_840308(D_802290E0_9D8B50, 0xC);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036A8E4_83E094(D_802290E0_9D8B50);
    func_8036D1A4_840954(D_802290E0_9D8B50, 0);
    func_8036CB58_840308(D_802290E4_9D8B54, 0xC);
    func_8036B9EC_83F19C(D_802290E4_9D8B54, ((SCREEN_WIDTH - func_8036D4F0_840CA0("Evaluation")) / 2) - 71, 34);
    func_8036C898_840048(D_802290E4_9D8B54, "Evaluation");

    for (i = 0; i < 60; i++) {
        photo = func_801E459C_99400C(i);
        if (photo == NULL) {
            break;
        }
        if (photo->unk_1A_14 & photo->unk_1A_15) {
            sp50++;
        }
        if (photo->unk_1A_12 != 0) {
            sp30++;
        }
    }

    sp4C = func_801E28CC_99233C(&sp54);
    func_801E4E04_994874();
    sp48 = func_801E28CC_99233C(&sp44);
    func_801E2AE8_992558(sp54, sp4C, sp30 ? sp30 : -1);
    func_8036D4A0_840C50(2);
    func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);

    if (sp48 != sp4C && sp30 > 0) {
        func_8036C898_840048(D_802290DC_9D8B4C, "I'll save the results of today's\ntrip in the PKMN Report\nand the PKMN Album!");
    } else if (sp30 == 0) {
        func_8036C898_840048(D_802290DC_9D8B4C, "I'll save the results of\ntoday's trip in the\nPKMN Report!");
    } else {
        func_8036C898_840048(D_802290DC_9D8B4C, "I'll save the results of today's\ntrip in the PKMN Album!");
    }

    func_80374F30_8486E0(D_802290DC_9D8B4C, 1);
    func_800228E4(0x4E);
    func_801E2AE8_992558(sp44, sp48, sp30 ? 0 : -1);

    if (func_800BFCA0_5CB40(0xE) == 0 && sp44 >= 0x3F) {
        D_801F3E28_9A3898 |= 0x40;
    }
    if (func_800BF3D4_5C274(0x3EC) != 0 &&
        func_800BF3D4_5C274(0x3F2) != 0 &&
        func_800BF3D4_5C274(0x3FA) != 0 &&
        func_800BF3D4_5C274(0x3FE) != 0 &&
        func_800BF3D4_5C274(0x404) != 0 &&
        func_800BF3D4_5C274(0x40B) != 0 &&
        (func_800BFC5C_5CAFC() < 6))
    {
        D_801F3E28_9A3898 = 0x400;
        func_800C02A0_5D140(6);
    } else if (sp44 >= 0x28) {
        if (func_800BFC5C_5CAFC() < 5) {
            D_801F3E28_9A3898 = 0x400;
            func_800C02A0_5D140(5);
        }
    } else if (sp44 >= 0x16) {
        if (func_800BFC5C_5CAFC() < 3) {
            D_801F3E28_9A3898 = 0x400;
            func_800C02A0_5D140(3);
        }
    } else if (sp44 >= 6 && func_800BFC5C_5CAFC() <= 0) {
        D_801F3E28_9A3898 = 0x400;
        func_800C02A0_5D140(1);
    }
    if (func_800C0290_5D130() > func_800BFC5C_5CAFC()) {
        sp38 = 1;
    }
    if (func_800AAEE8(0x800) != 0) {
        func_800AAED0(0x800);
        sp38 = 1;
    }
    if (sp38 == 0) {
        sp38 = 0;
        sp34 = 0;
        if (sp48 >= 130000 && func_800BFCA0_5CB40(5) != 0) {
            if (func_800BFCA0_5CB40(2) == 0) {
                sp34 = 1;
                D_801F3E28_9A3898 = 0x200;
                func_800C0314_5D1B4(2, 1);
            }
        } else if (sp48 >= 72500 && func_800BFC5C_5CAFC() >= 3) {
            if (func_800BFCA0_5CB40(1) == 0) {
                sp34 = 1;
                D_801F3E28_9A3898 = 0x100;
                func_800C0314_5D1B4(1, 1);
            }
        } else if (sp48 >= 24000 && func_800BFC5C_5CAFC() > 0 && func_800BFCA0_5CB40(0) == 0) {
            sp34 = 1;
            D_801F3E28_9A3898 = 0x80;
            func_800C0314_5D1B4(0, 1);
        }
    }
    func_8036B9EC_83F19C(D_802290DC_9D8B4C, 0, 0);
    func_8036D4A0_840C50(2);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);

    if (sp38 != 0 || D_801F3E28_9A3898 != 0) {
        func_8037519C_84894C(D_802290DC_9D8B4C, "\\SWait, %s...\nLet's return to the Lab!", func_800BF498_5C338());
    } else if (func_800BFCA0_5CB40(0xE) != 0) {
        func_8037519C_84894C(D_802290DC_9D8B4C, "The Report is complete,\nisn't it, %s?", func_800BF498_5C338());
    } else if (func_800BF3D4_5C274(0x97) != 0) {
        func_8037519C_84894C(D_802290DC_9D8B4C, "You need \\h%s\\p\nmore Pokεmon to\ncomplete the PKMN Report!", func_8037501C("%2d", 0x3F - sp44));
    } else if (func_800BFC5C_5CAFC() == 6) {
        func_8037519C_84894C(D_802290DC_9D8B4C, "Take pictures of Pokεmon\nthat live on the Rainbow Cloud!");
    } else if (func_800BFC5C_5CAFC() == 5) {
        if (func_800BFCA0_5CB40(2) != 0) {
            func_8037519C_84894C(D_802290DC_9D8B4C, "If you collect all the\nPKMN Signs, you will be able\nto enter the Secret Course.");
        } else if (func_800BFCA0_5CB40(5) != 0) {
            func_8037519C_84894C(D_802290DC_9D8B4C, "If you get \\h%s\\p more pts.\non your PKMN Report, you'll\nget something cool.", func_8037501C("%d", 130000 - sp48));
        } else if (func_801E4510_993F80() == 5) {
            func_8037519C_84894C(D_802290DC_9D8B4C, "\\hA suspicious Switch...\\p\nGood luck, %s!", func_800BF498_5C338());
        } else {
            func_8037519C_84894C(D_802290DC_9D8B4C, "Hmm... Pokεmon seem to\nbe \\hbowling\\p in the Valley.\nIt sure looks difficult.", func_800BF498_5C338());
        }
    } else if (func_800BFC5C_5CAFC() == 4) {
        func_8037519C_84894C(D_802290DC_9D8B4C, "You'll find out what the next\ncourse is if you take \\h%s\\p\nmore Pokεmon picture(s).", func_8037501C("%d", 40 - sp44));
    } else if (func_800BFC5C_5CAFC() == 3) {
        if (func_800BFCA0_5CB40(1) != 0) {
            if (func_801E4510_993F80() == 3) {
                func_8037519C_84894C(D_802290DC_9D8B4C, "\\hA suspicious Switch...\\p\nGood luck, %s!", func_800BF498_5C338());
            } else {
                func_8037519C_84894C(D_802290DC_9D8B4C, "There are Pokεmon \\hhiding\\p by\nthe River. Find them with\na PESTER BALL!", func_800BF498_5C338());
            }
        } else {
            func_8037519C_84894C(D_802290DC_9D8B4C, "If you get \\h%s\\p more pts.\non your PKMN Report, you'll\nget something cool.", func_8037501C("%d", 72500 - sp48));
        }
    } else if (func_800BFC5C_5CAFC() == 2) {
        func_8037519C_84894C(D_802290DC_9D8B4C, "You'll find out what the next\ncourse is if you take \\h%s\\p\nmore Pokεmon picture(s).", func_8037501C("%d", 22 - sp44));
    } else if (func_800BFC5C_5CAFC() == 1) {
        if (func_800BFCA0_5CB40(0) != 0) {
            func_8037519C_84894C(D_802290DC_9D8B4C, "There is a \\hhidden path\\p in the\nTunnel!\n");
            func_8037519C_84894C(D_802290DC_9D8B4C, "Good luck, %s!", func_800BF498_5C338());
        } else {
            func_8037519C_84894C(D_802290DC_9D8B4C, "If you get \\h%s\\p more pts.\non your PKMN Report, you'll\nget something cool.", func_8037501C("%d", 24000 - sp48));
        }
    } else {
        func_8037519C_84894C(D_802290DC_9D8B4C, "You'll find out what the next\ncourse is if you take \\h%s\\p\nmore Pokεmon picture(s).", func_8037501C("%d", 6 - sp44));
    }
    func_80374F30_8486E0(D_802290DC_9D8B4C, 1);
}

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

void func_801E39DC_99344C(UNK_PTR arg0) {
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
        levelName = "−−−";
    } else {
        sprintf(D_802290E8_9D8B58, "%s Course", levelName);
        levelName = D_802290E8_9D8B58;
    }
    sp3C = func_8036AC6C_83E41C(0x47, 0x32, 0xCC, 0x78, 0);
    D_802290E0_9D8B50 = sp3C;
    func_8036B870_83F020(sp3C, 1, 255, 255, 0xFF, 0xFF);
    func_8036B870_83F020(sp3C, 0, 0, 0, 0, 0);
    func_8036B734_83EEE4(sp3C);
    func_8036CB58_840308(sp3C, 0xC);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036D1A4_840954(sp3C, 1);
    func_8036B9EC_83F19C(sp3C, 90 - (strlen(levelName) * 3), 62);
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
    ohWait(1);

    for (i = 0; i < 60; i++) {
        func_801DD46C_98CEDC((i * 0xFF) / 60);
        func_801DD528_98CF98((i * 0xFF) / 60);
        ohWait(1);
    }

    func_801DD46C_98CEDC(0xFF);
    func_801DD528_98CF98(0xFF);
    func_8037172C_844EDC(0);
    func_803713C8_844B78(0);
    ohWait(1);
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
    func_8036C898_840048(sp3C, "Hmm...\nWhat's new this time?");
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
    ohWait(1);
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
            func_801DD46C_98CEDC((i * 0xFF) / 30);
            func_801DD964_98D3D4((i * 0xFF) / 30);
            ohWait(1);
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
        ohWait(1);
    }

    func_800AAED0(0x20);
    omDeleteGObj(NULL);
    ohWait(99);
}

void func_801E3FFC_993A6C(void) {
    GObj* gobj;
    SObj* sobj;

    func_800A85E8(func_801E39DC_99344C, 6, 0, 0);

    gobj = func_80371D14_8454C4(0, 6, &D_801F2910_9A2380);
    sobj = gobj->data.sobj;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80229168_9D8BD8 = sobj;
    func_801DD568_98CFD8();
    func_801DD46C_98CEDC(0);

    gobj = func_80371D14_8454C4(0, 6, &D_801F2378_9A1DE8);
    D_80229180_9D8BF0 = gobj->data.sobj;
    D_80229180_9D8BF0->sprite.x = 56;
    D_80229180_9D8BF0->sprite.y = 38;
    func_801DD5F0_98D060(1);
    func_801DD528_98CF98(0);

    gobj = func_80371D14_8454C4(0, 6, &D_801F26B0_9A2120);
    D_80229184_9D8BF4 = gobj->data.sobj;
    D_80229184_9D8BF4->sprite.x = 217;
    D_80229184_9D8BF4->sprite.y = 23;
    func_801DD638_98D0A8(0);

    gobj = func_80371D14_8454C4(0, 6, &D_801F2AD0_9A2540);
    D_80229188_9D8BF8 = gobj->data.sobj;
    D_80229188_9D8BF8->sprite.x = 0;
    D_80229188_9D8BF8->sprite.y = 0;
    D_80229188_9D8BF8->sprite.width = 132;
    D_80229188_9D8BF8->sprite.height = SCREEN_HEIGHT;
    D_80229188_9D8BF8->sprite.alpha = 128;
    D_80229188_9D8BF8->sprite.istep = 0;
    D_80229188_9D8BF8->sprite.attr |= SP_HIDDEN | SP_TRANSPARENT;
    func_8036EB8C_84233C(func_801DD2D4_98CD44);
}
