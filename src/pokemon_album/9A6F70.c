#include "common.h"
#include "window/window.h"
#include "pokemon_album.h"
#include "photo_check/photo_check.h"

typedef struct UnkBordeauxBetta {
    GObj* unk_0;
    SObj* unk_4;
    u8 unk_8;
} UnkBordeauxBetta; // size: 0xC

// DATA
extern Sprite D_801E4518_9AE768;
extern Sprite D_801ED550_9B77A0;
extern Sprite D_801F2D28_9BCF78;
extern Sprite D_801F2F88_9BD1D8;
extern Sprite D_801F3108_9BD358;
extern Sprite D_801F3288_9BD4D8;
extern Sprite D_801F3408_9BD658;
extern Sprite D_801F3588_9BD7D8;
extern Sprite D_801F6B50_9C0DA0;
extern Sprite D_801FB1D0_9C5420;
extern Sprite D_801FFA10_9C9C60;
extern Sprite D_801FFC80_9C9ED0;
extern Sprite D_80200058_9CA2A8;
extern Sprite D_80200400_9CA650;
extern Sprite D_802005B8_9CA808;
extern Sprite D_802006E8_9CA938;
extern Sprite D_80201728_9CB978;
extern Sprite D_80208B10_9D2D60;
extern s32 D_80208B54_9D2DA4;
extern s32 D_80208B58_9D2DA8[6];
extern char* D_80208B70_9D2DC0[]; // this seems to be length 3, but that would have it overlap with the following symbols
extern s32 D_80208B74_9D2DC4;
extern s32 D_80208B78_9D2DC8;
extern s32 D_80208B7C_9D2DCC;
extern s32 D_80208B80_9D2DD0;
extern s32 D_80208B84_9D2DD4;
extern UNK_TYPE D_80208B88_9D2DD8;

// BSS
extern s32 D_8024EFE0_A19230;
extern s32 D_8024FFE8_A1A238;
extern UnkSnowHerring* D_8024FFF0_A1A240;
extern UnkSnowHerring* D_8024FFF4_A1A244;
extern UnkSnowHerring* D_8024FFF8_A1A248;
extern UnkSnowHerring* D_8024FFFC_A1A24C;
extern UnkSnowHerring* D_80250000_A1A250;
extern UnkSnowHerring* D_80250008_A1A258[20]; // references in the code to this being 6 long and 20 long. what?
extern UnkSnowHerring* D_8025004C_A1A29C[3];
extern UnkSnowHerring* D_80250058_A1A2A8;
extern UIFrame* D_8025005C_A1A2AC;
extern SObj* D_80250060_A1A2B0;
extern GObj* D_80250064_A1A2B4;
extern SObj* D_80250068_A1A2B8[5];
extern GObj* D_80250078_A1A2C8; // TODO this is in the middle of the previous symbol..
extern SObj* D_80250080_A1A2D0[7];
extern SObj* D_8025009C_A1A2EC;
extern SObj* D_802500A0_A1A2F0;
extern SObj* D_802500A4_A1A2F4;
extern SObj* D_802500A8_A1A2F8;
extern GObj* D_802500AC_A1A2FC;
extern SObj* D_802500B0_A1A300;
extern s32 D_802500B4_A1A304;
extern Unk803A6C18* D_802500B8_A1A308;
extern u8 D_802500BC_A1A30C;
extern s16 D_802500BE_A1A30E;
extern UnkBordeauxBetta D_802500C0_A1A310[6];
extern GObj* D_80250108_A1A358;
extern SObj* D_8025010C_A1A35C;

const char D_80208C50_9D2EA0[] = "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ０１２３４５６７８９†‡¶〜！？＠＃％＆＊（）＿＋＝ー’”；：／＄．，＜＞♂♀［］ε　";

s32 func_801DCD20_9A6F70(void) {
    return D_802500B4_A1A304;
}

s32 func_801DCD3C_9A6F8C(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_80208B58_9D2DA8)) {
        return -1;
    }
    return D_80208B58_9D2DA8[arg0];
}

s32 func_801DCD7C_9A6FCC(s16* arg0, char* arg1) {
    char sp28[0x40];
    char* sp24;
    char* sp20;
    s32 sp1C;
    s32 sp18;

    sp24 = arg0; // todo what is going on with the type of this
    sp20 = (arg1 != NULL) ? (arg1) : (sp28);
    sp1C = 0;
    sp18 = 0;

    while (sp24[sp1C] != 0) {
        if (*((u16*) (sp24 + sp1C)) == '　') {
            sp20[sp18] = ' ';
            sp20[sp18 + 1] = 0;
            sp1C += 2;
            sp18 += 1;
        } else {
            sp20[sp18] = sp24[sp1C];
            sp20[sp18 + 1] = *(sp24 + sp1C + 1);
            sp1C += 2;
            sp18 += 2;
        }
    }

    sp20[sp18] = 0;
    return func_8036D4F0_840CA0(sp20);
}

void func_801DCED4_9A7124(GObj* arg0) {
    while (D_80208B74_9D2DC4) {
        D_80208B78_9D2DC8 += D_80208B7C_9D2DCC;
        if (D_80208B78_9D2DC8 > 0xFF) {
            D_80208B78_9D2DC8 = 0xFF;
            D_80208B7C_9D2DCC = -5;
        }
        if (D_80208B78_9D2DC8 < 0x78) {
            D_80208B78_9D2DC8 = 0x78;
            D_80208B7C_9D2DCC = 5;
        }
        D_802500A4_A1A2F4->sprite.alpha = D_80208B78_9D2DC8;
        ohWait(1);
    }

    omDeleteGObj(NULL);
    ohWait(0x63);
}

void func_801DCFB8_9A7208(GObj* arg0) {
    while (D_80208B74_9D2DC4) {
        D_80208B80_9D2DD0 += D_80208B84_9D2DD4;
        if (D_80208B80_9D2DD0 > 0xFF) {
            D_80208B80_9D2DD0 = 0xFF;
            D_80208B84_9D2DD4 = -5;
        }
        if (D_80208B80_9D2DD0 < 0x78) {
            D_80208B80_9D2DD0 = 0x78;
            D_80208B84_9D2DD4 = 5;
        }

        func_8036D248_8409F8(D_8024FFF0_A1A240, 0xFF, 0xFF, 0xFF, (D_80208B80_9D2DD0 > 0xA0) ? 0xFF : 0);
        ohWait(1);
    }

    omDeleteGObj(NULL);
    ohWait(99);
}

s16 func_801DD0CC_9A731C(void) {
    return D_802500BE_A1A30E;
}

char* func_801DD0E8_9A7338(s32* arg0) {
    if (*arg0) {
        return "−−−−−";
    } else {
        *arg0 = 1;
        return "ダメじゃ！"; // No way!
    }
}

char* func_801DD12C_9A737C(Unk803A6C18* arg0, u32 arg1) {
    switch (arg1) {
        case 0:
            D_80208B88_9D2DD8 = 0;
            return "スペシャル"; // special
        case 1:
            return func_8037501C_8487CC("%5d", arg0->unk_3A0.unk_14);
        case 2:
            return "おおきさ"; // size
        case 3:
            if (arg0->unk_3A0.unk_0C != 0) {
                return func_8037501C_8487CC("%5d", arg0->unk_3A0.unk_0C);
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 4:
            return "まるみえ"; // "full view" (view?)
        case 5:
            if (arg0->unk_3A0.unk_0E != 0) {
                return func_8037501C_8487CC("%5.2f", (s32) (f32) (arg0->unk_3A0.unk_0E / 10000));
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 6:
            return "コメント"; // comment
        case 7:
            if (arg0->unk_3A0.unk_08 != 0) {
                return func_8037501C_8487CC("%5d", arg0->unk_3A0.unk_08);
            } else {
                return "　　　なし";
            }
        case 8:
            if (arg0->unk_3A0.unk_08 != 0) {
                return "ポーズ";
            } else {
                return "むき";
            }
        case 9:
            if (arg0->unk_3A0.unk_10 != 0) {
                return func_8037501C_8487CC("%5d", arg0->unk_3A0.unk_10);
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 10:
            return "センサー"; // sensor
        case 11:
            if (arg0->unk_3A0.unk_07 != 0) {
                return "　　　あり";
            } else {

                return "　　　なし";
            }
        case 12:
            return "なかま";
        case 13:
            if (D_80208B88_9D2DD8 != 0) {
                return "−−−−−";
            } else {
                return func_8037501C_8487CC("%3d", arg0->unk_3A0.unk_06);
            }
        case 14:
            if (D_80208B88_9D2DD8 != 0) {
                return "−−−−−";
            } else {
                return func_8037501C_8487CC("%5d", arg0->unk_3A0.unk_04);
            }
    }
}

void func_801DD404_9A7654(s32 arg0) {
    s32 i;

    D_80250060_A1A2B0->sprite.red = arg0;
    D_80250060_A1A2B0->sprite.green = arg0;
    D_80250060_A1A2B0->sprite.blue = arg0;

    for (i = 0; i < ARRAY_COUNT(D_80250068_A1A2B8) - 1; i++) {
        if (D_80250068_A1A2B8[i]) {
            D_80250068_A1A2B8[i]->sprite.red = D_80250068_A1A2B8[i]->sprite.green = D_80250068_A1A2B8[i]->sprite.blue = arg0;
        }
    }
}

void func_801DD4C0_9A7710(u32 arg0) {
    D_802500A0_A1A2F0->sprite.red = D_802500A0_A1A2F0->sprite.green = D_802500A0_A1A2F0->sprite.blue = arg0;
}

void func_801DD500_9A7750(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_802500C0_A1A310); i++) {
        D_802500C0_A1A310[i].unk_0->data.sobj->sprite.red = D_802500C0_A1A310[i].unk_0->data.sobj->sprite.green = D_802500C0_A1A310[i].unk_0->data.sobj->sprite.blue = arg0;
    }
}

void func_801DD5A0_9A77F0(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80250080_A1A2D0); i++) {
        if (D_80250080_A1A2D0[i] != NULL) {
            D_80250080_A1A2D0[i]->sprite.red = D_80250080_A1A2D0[i]->sprite.green = D_80250080_A1A2D0[i]->sprite.blue = arg0;
        }
    }
}

void func_801DD638_9A7888(s32 arg0) {
    D_80250108_A1A358->data.sobj->sprite.red = D_80250108_A1A358->data.sobj->sprite.green = D_80250108_A1A358->data.sobj->sprite.blue = arg0;
}

void func_801DD684_9A78D4(UnkSnowHerring* arg0, s32 arg1) {
    func_8036D248_8409F8(arg0, arg1, arg1, arg1, 255);
}

GObj* func_801DD6CC_9A791C(s32 arg0) {
    GObj* gobj;
    SObj* sobj;
    s32 x;
    s32 y;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    x = ((arg0 % 3) * 66) + 104;
    y = ((arg0 / 3) * 55) + 53;

    gobj = func_80371C68_845418(NULL, 6, &D_802005B8_9CA808);
    sobj = gobj->data.sobj;
    sobj->sprite.x = x;
    sobj->sprite.y = y;
    D_802500C0_A1A310[arg0].unk_0 = gobj;

    sobj = func_80371E68_845618(sobj, &D_802005B8_9CA808);
    sobj->sprite.x = 54;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_802006E8_9CA938);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_802006E8_9CA938);
    sobj->sprite.x = 2;
    sobj->sprite.y = 41;

    sobj = func_80371DC0_845570(sobj, &D_80201728_9CB978);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_802500C0_A1A310[arg0].unk_4 = sobj;

    bitmap = (Bitmap*) func_8036A194_83D944(0x10);
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (x = 0xFD8; x > 0; src++, dest++, x--) {
        *dest = *src;
    }

    return gobj;
}

void func_801DD914_9A7B64(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_802500C0_A1A310); i++) {
        func_801DD6CC_9A791C(i);
    }
}

void func_801DD954_9A7BA4(s32 arg0) {
    s32 i;
    char sp24[0x20];

    D_802500B4_A1A304 = arg0 / 6;

    for (i = 0; i < ARRAY_COUNT(D_802500C0_A1A310); arg0++, i++) {
        if (func_80374714_847EC4(func_801E38E0_9ADB30(arg0), &D_802500C0_A1A310[i].unk_4->sprite) != NULL) {
            D_802500C0_A1A310[i].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
            D_802500C0_A1A310[i].unk_8 = 0;
        } else {
            D_802500C0_A1A310[i].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
            D_802500C0_A1A310[i].unk_8 = 1;
        }
    }

    func_8036A8E4_83E094(D_80250058_A1A2A8);
    func_8036D4A0_840C50(0);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036B9EC_83F19C(D_80250058_A1A2A8, 0, 0);
    func_8036C898_840048(D_80250058_A1A2A8, "  \\i−\\g      \\i−\\g  ");
    sprintf(sp24, "%d", D_802500B4_A1A304 + 1);
    func_8036B9EC_83F19C(D_80250058_A1A2A8, 30 - (func_8036D4F0_840CA0(sp24) / 2), 0);
    func_8036C898_840048(D_80250058_A1A2A8, sp24);
    func_8036D1A4_840954(D_80250058_A1A2A8, 0);
}

void func_801DDB54_9A7DA4(s32 arg0) {
    s32 idx;

    idx = arg0 % ARRAY_COUNT(D_802500C0_A1A310);
    if (func_80374714_847EC4(func_801E38E0_9ADB30(arg0), &D_802500C0_A1A310[idx].unk_4->sprite)) {
        D_802500C0_A1A310[idx].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
        D_802500C0_A1A310[idx].unk_8 = 0;
    } else {
        D_802500C0_A1A310[idx].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
        D_802500C0_A1A310[idx].unk_8 = 1;
    }
}

void func_801DDC70_9A7EC0(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_802500C0_A1A310); i++) {
        if (arg0 && D_802500C0_A1A310[i].unk_8 != NULL) {
            D_802500C0_A1A310[i].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            D_802500C0_A1A310[i].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_801DDD28_9A7F78(s32 arg0, s32 arg1) {
    if (arg1) {
        D_802500C0_A1A310[arg0 % ARRAY_COUNT(D_802500C0_A1A310)].unk_0->data.sobj->sprite.attr =
            D_802500C0_A1A310[arg0 % ARRAY_COUNT(D_802500C0_A1A310)].unk_0->data.sobj->sprite.attr & ~SP_HIDDEN;
    } else {
        D_802500C0_A1A310[arg0 % ARRAY_COUNT(D_802500C0_A1A310)].unk_0->data.sobj->sprite.attr =
            D_802500C0_A1A310[arg0 % ARRAY_COUNT(D_802500C0_A1A310)].unk_0->data.sobj->sprite.attr | SP_HIDDEN;
    }
}

void func_801DDDF8_9A8048(s32 x, s32 y) {
    SObj* sobj;

    sobj = D_802500AC_A1A2FC->data.sobj;
    if ((x < 0) || (y < 0)) {
        sobj->sprite.attr |= SP_HIDDEN;
    } else {
        sobj->sprite.x = x;
        sobj->sprite.y = y;
        sobj->sprite.attr &= ~SP_HIDDEN;
    }
}

GObj* func_801DDE64_9A80B4(void) {
    GObj* gobj;
    SObj* sobj;
    s32 i;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    gobj = func_80371C68_845418(NULL, 6, &D_802005B8_9CA808);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 0;
    sobj->sprite.y = 0;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = func_80371E68_845618(sobj, &D_802005B8_9CA808);
    sobj->sprite.x = 54;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_802006E8_9CA938);
    sobj->sprite.x = 2;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_802006E8_9CA938);
    sobj->sprite.x = 2;
    sobj->sprite.y = 41;

    sobj = func_80371DC0_845570(sobj, &D_80201728_9CB978);
    sobj->sprite.x = 2;
    sobj->sprite.y = 2;
    D_802500AC_A1A2FC = gobj;
    D_802500B0_A1A300 = sobj;

    bitmap = (Bitmap*) func_8036A194_83D944(0x10);
    dest = (u8*) func_8036A194_83D944(0xFD8);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (i = 0xFD8; i > 0; src++, dest++, i--) {
        *dest = *src;
    }

    return gobj;
}
void func_801DE03C_9A828C(s32 arg0) {
    // BUG: this pointer is never assigned
    SObj* sp4;

    if (arg0 != 0) {
        sp4->sprite.attr &= ~SP_HIDDEN;
    } else {
        sp4->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DE080_9A82D0(void) {
    func_80374714_847EC4(func_801E4068_9AE2B8(), &D_802500B0_A1A300->sprite);
}

void* func_801DE0C8_9A8318(void) {
    GObj* gobj;
    SObj* sobj;
    UNUSED s32 pad[2];

    gobj = func_80371C68_845418(NULL, 6, &D_80200058_9CA2A8);
    D_80250108_A1A358 = gobj;
    sobj = gobj->data.sobj;
    sobj->sprite.x = 127;
    sobj->sprite.y = 53;
    sobj->sprite.attr |= SP_HIDDEN;

    sobj = func_80371E68_845618(sobj, &D_80200058_9CA2A8);
    sobj->sprite.x = 143;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_80200400_9CA650);
    sobj->sprite.x = 3;
    sobj->sprite.y = 0;

    sobj = func_80371DC0_845570(sobj, &D_80200400_9CA650);
    sobj->sprite.x = 3;
    sobj->sprite.y = 108;

    sobj = func_80371DC0_845570(sobj, &D_80208B10_9D2D60);
    sobj->sprite.x = 3;
    sobj->sprite.y = 3;

    D_8025010C_A1A35C = sobj;

    return gobj;
}

void func_801DE1FC_9A844C(s32 arg0) {
    char sp28[0x40];

    func_8036A8E4_83E094(D_8024FFFC_A1A24C);
    if (func_801E3A34_9ADC84(arg0) == NULL) {
        return;
    }
    func_8036CB58_840308(D_8024FFFC_A1A24C, 0xC);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036B9EC_83F19C(D_8024FFFC_A1A24C, 0, 0);
    func_801DCD7C_9A6FCC(func_801E3A34_9ADC84(arg0), sp28);
    func_8036C898_840048(D_8024FFFC_A1A24C, sp28);
    func_8036D1A4_840954(D_8024FFFC_A1A24C, 0);
}

void func_801DE2BC_9A850C(s32 arg0) {
    if (D_80208B54_9D2DA4 != arg0) {
        D_80208B54_9D2DA4 = arg0;
    }
    func_80374714_847EC4(func_801E38E0_9ADB30(arg0), &D_8025010C_A1A35C->sprite);
    func_8036D1A4_840954(D_8024FFFC_A1A24C, 1);
    func_801DE1FC_9A844C(arg0);
    func_8036D1A4_840954(D_8024FFFC_A1A24C, 0);
}

void func_801DE350_9A85A0(s32 arg0, s32 arg1) {
    if (arg0) {
        func_8036D1A4_840954(D_80250058_A1A2A8, 1);
        func_801DE2BC_9A850C(arg1);
        auPlaySound(0x47);
        D_80250108_A1A358->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_80250108_A1A358->data.sobj->sprite.attr |= SP_HIDDEN;
    }
}

GObj* func_801DE3DC_9A862C(void) {
    GObj* gobj;
    SObj* sobj;
    s32 j;
    s32 i;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            gobj = func_80371C68_845418(NULL, 6, &D_801F3108_9BD358);
            sobj = gobj->data.sobj;
            D_80250080_A1A2D0[(i * 3) + j] = sobj;
            sobj->sprite.x = (j * 66) + 102;
            sobj->sprite.y = (i * 55) + 51;
            sobj->sprite.attr |= SP_HIDDEN;
            sobj = func_80371E68_845618(sobj, &D_801F3288_9BD4D8);
            sobj->sprite.x = 48;
            sobj->sprite.y = 0;
            sobj = func_80371DC0_845570(sobj, &D_801F3408_9BD658);
            sobj->sprite.x = 0;
            sobj->sprite.y = 36;
            sobj = func_80371DC0_845570(sobj, &D_801F3588_9BD7D8);
            sobj->sprite.x = 48;
            sobj->sprite.y = 36;
        }
    }

    gobj = func_80371C68_845418(NULL, 6, &D_801F3108_9BD358);
    sobj = gobj->data.sobj;
    D_80250080_A1A2D0[6] = sobj;
    sobj->sprite.x = 125;
    sobj->sprite.y = 51;
    sobj->sprite.attr |= SP_HIDDEN;
    sobj = func_80371E68_845618(sobj, &D_801F3288_9BD4D8);
    sobj->sprite.x = 138;
    sobj->sprite.y = 0;
    sobj = func_80371DC0_845570(sobj, &D_801F3408_9BD658);
    sobj->sprite.x = 0;
    sobj->sprite.y = 103;
    sobj = func_80371DC0_845570(sobj, &D_801F3588_9BD7D8);
    sobj->sprite.x = 138;
    sobj->sprite.y = 103;

    return gobj;
}

void func_801DE620_9A8870(s32 arg0, s32 arg1) {
    s32 i;

    if (arg1 == 1) {
        if (arg0 & 1) {
            for (i = 0; i < ARRAY_COUNT(D_80250080_A1A2D0) - 1; i++) {
                D_80250080_A1A2D0[i]->sprite.attr |= SP_HIDDEN;
            }
            D_80250080_A1A2D0[ARRAY_COUNT(D_80250080_A1A2D0) - 1]->sprite.attr &= ~SP_HIDDEN;
        } else {
            for (i = 0; i < ARRAY_COUNT(D_80250080_A1A2D0) - 1; i++) {
                D_80250080_A1A2D0[i]->sprite.attr &= ~SP_HIDDEN;
            }
            D_80250080_A1A2D0[ARRAY_COUNT(D_80250080_A1A2D0) - 1]->sprite.attr |= SP_HIDDEN;
        }
    } else {
        if (arg0 & 1) {
            D_80250080_A1A2D0[ARRAY_COUNT(D_80250080_A1A2D0) - 1]->sprite.attr |= SP_HIDDEN;
        }
        if (arg0 & 2) {
            for (i = 0; i < ARRAY_COUNT(D_80250080_A1A2D0) - 1; i++) {
                D_80250080_A1A2D0[i]->sprite.attr |= SP_HIDDEN;
            }
        }
    }
}

void* func_801DE768_9A89B8(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, 6, &D_801F6B50_9C0DA0);
    sobj = gobj->data.sobj;

    sobj->sprite.x = 101;
    sobj->sprite.y = 186;
    sobj->sprite.attr |= SP_HIDDEN;
    D_802500A0_A1A2F0 = sobj;

    return gobj;
}

void func_801DE7E8_9A8A38(s32 arg0) {
    if (arg0) {
        D_802500A0_A1A2F0->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_802500A0_A1A2F0->sprite.attr |= SP_HIDDEN;
    }
}

GObj* func_801DE830_9A8A80(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, 6, &D_801FFC80_9C9ED0);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 115;
    sobj->sprite.y = 196;
    sobj->sprite.attr |= SP_HIDDEN | SP_TRANSPARENT;
    D_802500A4_A1A2F4 = sobj;
    D_80208B74_9D2DC4 = true;
    func_800A85E8(func_801DCED4_9A7124, LINK_6, DL_LINK_0, NULL);
    D_8024FFF0_A1A240 = UIElement_Create(0x74, 0xC5, 0xC, 0xC, 0x400);
    func_8036B870_83F020(D_8024FFF0_A1A240, 1, 0xFF, 0xF, 0x19, 0xFF);
    func_8036B870_83F020(D_8024FFF0_A1A240, 0, 0, 0, 0, 0);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036B734_83EEE4(D_8024FFF0_A1A240);
    func_8036CB58_840308(D_8024FFF0_A1A240, 0xC);
    func_8036D1A4_840954(D_8024FFF0_A1A240, 1);
    func_800A85E8(func_801DCFB8_9A7208, LINK_6, DL_LINK_0, NULL);

    return gobj;
}

void func_801DE998_9A8BE8(s32 arg0) {
    D_8024FFE8_A1A238 = arg0;
}

void func_801DE9B0_9A8C00(s32 arg0) {
    if (arg0 != 0) {
        if (D_8024FFE8_A1A238 != 0) {
            func_8036D1A4_840954(D_8024FFF0_A1A240, 0);
        } else {
            D_802500A4_A1A2F4->sprite.attr &= ~SP_HIDDEN;
        }
    } else {
        func_8036D1A4_840954(D_8024FFF0_A1A240, 1);
        D_802500A4_A1A2F4->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DEA4C_9A8C9C(s32 arg0, s32 arg1, s32 arg2) {
    s16* sp64;
    char sp60[0x4];
    char sp20[0x40];
    s32 x;

    sp64 = func_801E3A34_9ADC84(D_80208B54_9D2DA4);
    if (sp64 == NULL) {
        return;
    }
    sp64[31] = 0;

    if (arg0 != 0) {
        for (D_802500BE_A1A30E = 0; D_802500BE_A1A30E < 31; D_802500BE_A1A30E++) {
            if (sp64[D_802500BE_A1A30E] == 0) {
                break;
            }
        }
    }

    if (D_8024FFE8_A1A238 != 0) {
        sp60[0] = D_80208B70_9D2DC0[D_802500BC_A1A30C][arg2 * 10 + 2 * arg1];
        sp60[1] = D_80208B70_9D2DC0[D_802500BC_A1A30C][arg2 * 10 + 2 * arg1 + 1];
        sp60[2] = 0;
        func_8036A8E4_83E094(D_8024FFF0_A1A240);
        func_8036C898_840048(D_8024FFF0_A1A240, sp60);
        if ((((sp60[0] << 8) | sp60[1]) & 0xFFFF) == '　') {
            func_8036D1A4_840954(D_8024FFF0_A1A240, 1);
            D_802500A4_A1A2F4->sprite.attr &= ~SP_HIDDEN;
        } else {
            func_8036D1A4_840954(D_8024FFF0_A1A240, 0);
            D_802500A4_A1A2F4->sprite.attr |= SP_HIDDEN;
        }
    } else {
        func_8036D1A4_840954(D_8024FFF0_A1A240, 1);
        D_802500A4_A1A2F4->sprite.attr &= ~SP_HIDDEN;
    }

    x = func_801DCD7C_9A6FCC(sp64, sp20);
    if ((D_802500BE_A1A30E < 31) || 168 - func_8036D4F0_840CA0(sp60) < x) {
        x += 116;
    } else {
        x = -16;
    }
    func_8036CBA0_840350(D_8024FFF0_A1A240, x, 197);
    D_802500A4_A1A2F4->sprite.x = x;
}

void* func_801DECE8_9A8F38(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, 6, &D_801FB1D0_9C5420);
    sobj = gobj->data.sobj;

    sobj->sprite.x = 308;
    sobj->sprite.y = 50;
    sobj->sprite.attr |= SP_HIDDEN;
    D_802500A8_A1A2F8 = sobj;

    return gobj;
}

void func_801DED68_9A8FB8(s32 arg0) {
    if (arg0) {
        D_802500A8_A1A2F8->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_802500A8_A1A2F8->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DEDB0_9A9000(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        D_80250008_A1A258[i] = UIElement_Create(234, ((i / 2) * 36) + ((i % 2) * 12) + 67, 0x3C, 8, 0x400);
        func_8036B870_83F020(D_80250008_A1A258[i], 1, 0, 0, 0, 0xFF);
        func_8036B870_83F020(D_80250008_A1A258[i], 0, 0, 0, 0, 0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B734_83EEE4(D_80250008_A1A258[i]);
        func_8036CB58_840308(D_80250008_A1A258[i], 8);
        func_8036D1A4_840954(D_80250008_A1A258[i], 1);
    }
}

void func_801DEF1C_9A916C(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        func_8036B5F0_83EDA0(D_80250008_A1A258[i]);
    }
}

void func_801DEF6C_9A91BC(s32 arg0) {
    s32 i;

    if (arg0 != 0) {
        for (i = 0; i < 6; i++) {
            func_8036D1A4_840954(D_80250008_A1A258[i], 0);
        }
    } else {
        for (i = 0; i < 6; i++) {
            func_8036D1A4_840954(D_80250008_A1A258[i], 1);
        }
    }
}

void func_801DF00C_9A925C(s32 arg0) {
    s32 i;

    for (i = 0; i < 6; i += 2) {
        func_8036CBA0_840350(D_80250008_A1A258[i], arg0 + 234, ((i / 2) * 36) + 67);
        func_8036CBA0_840350(D_80250008_A1A258[i + 1], arg0 + 234, ((i / 2) * 36) + 79);
    }
}

void func_801DF0D0_9A9320(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        func_8036A8E4_83E094(D_80250008_A1A258[i]);
    }
}

void func_801DF120_9A9370(s32 arg0) {
    s32 i;

    if (arg0) {
        D_80250064_A1A2B4->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        D_80250064_A1A2B4->data.sobj->sprite.attr |= SP_HIDDEN;
    }

    for (i = ARRAY_COUNT(D_80250068_A1A2B8); i >= 0; i--) {
        if (D_80250068_A1A2B8[i] != NULL) {
            if (arg0) {
                D_80250068_A1A2B8[i]->sprite.attr &= ~SP_HIDDEN;
            } else {
                D_80250068_A1A2B8[i]->sprite.attr |= SP_HIDDEN;
            }
        }
    }
}

void func_801DF1F8_9A9448(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371D14_8454C4(0, 6, &D_801F2D28_9BCF78);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 106;
    sobj->sprite.y = 52;
    D_80250068_A1A2B8[0] = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801ED550_9B77A0);
    sobj->sprite.x = 110;
    sobj->sprite.y = 108;
    sobj->sprite.alpha = 0x80;
    sobj->sprite.attr |= SP_TRANSPARENT;
    D_80250068_A1A2B8[1] = sobj;
    D_80250068_A1A2B8[2] = NULL;
    D_80250068_A1A2B8[3] = NULL;
    D_80250078_A1A2C8 = gobj;
}

void func_801DF2E0_9A9530(void) {
    UNUSED s32 pad;
    SObj* sobj;

    sobj = D_80250068_A1A2B8[0];
    sobj->sprite = D_801F2D28_9BCF78;
    sobj->sprite.x = 106;
    sobj->sprite.y = 52;
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;

    sobj = D_80250068_A1A2B8[1];
    sobj->sprite = D_801ED550_9B77A0;
    sobj->sprite.x = 110;
    sobj->sprite.y = 108;
    sobj->sprite.alpha = 0x80;
    sobj->sprite.attr |= SP_TRANSPARENT;

    D_80250068_A1A2B8[2] = NULL;
    D_80250068_A1A2B8[3] = NULL;
    D_80250068_A1A2B8[4] = NULL;
    D_80250068_A1A2B8[5] = NULL;
}

void func_801DF428_9A9678(s32 arg0, s32 arg1) {
    Unk803A6C18* sp4C;
    s32 i;
    char sp28[0x20];

    sp4C = func_8037452C_847CDC(func_801E38E0_9ADB30(arg1));
    if (arg0 == 0) {
        func_801DF0D0_9A9320();
        func_8036D344_840AF4(8);
        func_8036B9EC_83F19C(D_80250008_A1A258[0], 0, 0);
        func_8036C898_840048(D_80250008_A1A258[0], "Course");
        sprintf(sp28, "%s", getLevelName(func_800BFA44_5C8E4(arg1)->levelID));
        func_8036B9EC_83F19C(D_80250008_A1A258[1], 60 - func_8036D4F0_840CA0(sp28), 0);
        func_8037519C_84894C(D_80250008_A1A258[1], "%s", sp28);
        func_8036B9EC_83F19C(D_80250008_A1A258[2], 0, 0);
        func_8036C898_840048(D_80250008_A1A258[2], "Photo by");
        sprintf(sp28, "%s", get_player_name());
        func_8036B9EC_83F19C(D_80250008_A1A258[3], 60 - func_8036D4F0_840CA0(sp28), 0);
        func_8037519C_84894C(D_80250008_A1A258[3], "%s", sp28);
        func_8036B9EC_83F19C(D_80250008_A1A258[4], 0, 0);
        func_8036C898_840048(D_80250008_A1A258[4], "Focus");
        sprintf(sp28, "%s", (sp4C->unk_3A0.unk_0A > 0 && sp4C->unk_3A0.unk_0A <= POKEDEX_MAX) ? getPokemonName(sp4C->unk_3A0.unk_0A) : "−−−−−");
        func_8036B9EC_83F19C(D_80250008_A1A258[5], 60 - func_8036D4F0_840CA0(sp28), 0);
        func_8037519C_84894C(D_80250008_A1A258[5], "%s", sp28);
    } else {
        func_801DF0D0_9A9320();

        for (i = 0; i < 6; i++) {
            func_8036B9EC_83F19C(D_80250008_A1A258[i], 0, 0);
            if (i == 13) {
                func_8037519C_84894C(D_80250008_A1A258[i], "%sひき", func_801DD12C_9A737C(sp4C, i));
            } else {
                func_8036C898_840048(D_80250008_A1A258[i], func_801DD12C_9A737C(sp4C, i));
            }
        }
    }
}

void func_801DF744_9A9994(s32 arg0, s32 arg1) {
    s32 i;

    switch (arg0) {
        case 0:
            D_8024EFE0_A19230 = 0;
            D_80250064_A1A2B4->data.sobj->sprite.width = 400;
            func_803700A4_843854(0);
            func_80370A48_8441F8();
            func_803705A4_843D54();
            func_8037172C_844EDC(0);
            func_8036B5F0_83EDA0(D_8024FFF8_A1A248);
            func_801DEDB0_9A9000();
            func_801DF428_9A9678(D_8024EFE0_A19230, arg1);
            func_803713C8_844B78(0);
            ohWait(30);
            func_801DEF6C_9A91BC(1);
            func_801DED68_9A8FB8(1);

            for (i = 80; i > 0; i -= 8, ohWait(1)) {
                D_80250064_A1A2B4->data.sobj->sprite.x -= 8;
                D_80250108_A1A358->data.sobj->sprite.x -= 8;
                D_80250080_A1A2D0[6]->sprite.x -= 8;
                D_802500A0_A1A2F0->sprite.x -= 8;
                D_802500A8_A1A2F8->sprite.x -= 8;
                func_8036CBA0_840350(D_8024FFFC_A1A24C, i + 0x1C, 0xC5);
                func_801DF00C_9A925C(i);
            }

            func_801DF00C_9A925C(0);
            func_8036CBA0_840350(D_8024FFFC_A1A24C, 0x24, 0xC5);
            ohWait(1);
            break;
        case 1:
            if (D_802500B8_A1A308->unk_3A0.unk_0A > 0) {
                D_8024EFE0_A19230 ^= 1;
                func_801DF428_9A9678(D_8024EFE0_A19230, arg1);
            }
            break;
        case 2:
            for (i = 0; i < 80; i += 8, ohWait(1)) {
                D_80250064_A1A2B4->data.sobj->sprite.x += 8;
                D_80250108_A1A358->data.sobj->sprite.x += 8;
                D_80250080_A1A2D0[6]->sprite.x += 8;
                D_802500A0_A1A2F0->sprite.x += 8;
                D_802500A8_A1A2F8->sprite.x += 8;
                func_801DF00C_9A925C(i);
                func_8036CBA0_840350(D_8024FFFC_A1A24C, i + 0x2C, 0xC5);
            }

            D_80250064_A1A2B4->data.sobj->sprite.width = SCREEN_WIDTH;
            func_801DED68_9A8FB8(0);
            func_8036CBA0_840350(D_8024FFFC_A1A24C, 0x74, 0xC5);
            func_801DEF1C_9A916C();
            func_803713D4_844B84(4);
            func_8037172C_844EDC(1);

            ohWait(30);

            D_8024FFF8_A1A248 = UIElement_Create(0x92, 0x16, 0x6C, 0x10, 0);
            func_8036B870_83F020(D_8024FFF8_A1A248, 1, 0xFF, 0xFF, 0xFF, 0xFF);
            func_8036B870_83F020(D_8024FFF8_A1A248, 0, 0xDA, 0x6C, 0, 0);
            func_8036B734_83EEE4(D_8024FFF8_A1A248);
            func_8036CB58_840308(D_8024FFF8_A1A248, 0xC);
            func_8036D448_840BF8(1);
            func_8036D3E8_840B98(-1, 3);
            func_8036B9EC_83F19C(D_8024FFF8_A1A248, (108 - func_8036D4F0_840CA0("PKMN Album")) / 2, 0);
            func_8036C898_840048(D_8024FFF8_A1A248, "PKMN Album");
            func_8036D1A4_840954(D_8024FFF8_A1A248, 0);
            break;
    }
}

void func_801DFB48_9A9D98(void) {
    s32 i;

    for (i = 0; i < 17; i++) {
        D_80250008_A1A258[i] = UIElement_Create(23, (i * 10) + 20, 0x3C, 8, 0);
        func_8036B870_83F020(D_80250008_A1A258[i], 1, 0xFF, 0xFF, 0xFF, 0xFF);
        func_8036B870_83F020(D_80250008_A1A258[i], 0, 0, 0, 0, 0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B734_83EEE4(D_80250008_A1A258[i]);
        func_8036CB58_840308(D_80250008_A1A258[i], 8);
        func_8036D1A4_840954(D_80250008_A1A258[i], 1);
    }

    for (i = 0; i < ARRAY_COUNT(D_8025004C_A1A29C); i++) {
        D_8025004C_A1A29C[i] = UIElement_Create(23, (i * 10) + 190, 0x3C, 8, 0);
        func_8036B870_83F020(D_8025004C_A1A29C[i], 1, 0xFF, 0xFF, 0xFF, 0xFF);
        func_8036B870_83F020(D_8025004C_A1A29C[i], 0, 0, 0, 0, 0);
        func_8036D448_840BF8(0);
        func_8036D3E8_840B98(0, 4);
        func_8036B734_83EEE4(D_8025004C_A1A29C[i]);
        func_8036CB58_840308(D_8025004C_A1A29C[i], 8);
        func_8036D1A4_840954(D_8025004C_A1A29C[i], 1);
    }
}

void func_801DFDA0_9A9FF0(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        func_8036B5F0_83EDA0(D_80250008_A1A258[i]);
    }
}

void func_801DFDF0_9AA040(s32 arg0) {
    s32 i;
    s32 j;
    char sp18[0x8];

    func_8036D4B4_840C64(1, 0);

    for (i = 0; i < ARRAY_COUNT(D_80250008_A1A258) - 1; i++) {
        func_8036A8E4_83E094(D_80250008_A1A258[i]);

        for (j = 0; j < 5; j++) {
            func_8036B9EC_83F19C(D_80250008_A1A258[i], j * 13, 0);
            sp18[0] = D_80208B70_9D2DC0[arg0][i * 10 + 2 * j];
            sp18[1] = D_80208B70_9D2DC0[arg0][i * 10 + 2 * j + 1];
            sp18[2] = 0;
            func_8036C898_840048(D_80250008_A1A258[i], sp18);
        }
    }
    func_8036D4B4_840C64(1, 1);
    func_8036A8E4_83E094(D_80250008_A1A258[ARRAY_COUNT(D_80250008_A1A258) - 1]);
    func_8036B9EC_83F19C(D_80250008_A1A258[ARRAY_COUNT(D_80250008_A1A258) - 1], 0, 0);
    func_8036C898_840048(D_80250008_A1A258[ARRAY_COUNT(D_80250008_A1A258) - 1], "←");
    func_8036B9EC_83F19C(D_80250008_A1A258[ARRAY_COUNT(D_80250008_A1A258) - 1], 13, 0);
    func_8036C898_840048(D_80250008_A1A258[ARRAY_COUNT(D_80250008_A1A258) - 1], "→");
    func_8036B9EC_83F19C(D_80250008_A1A258[ARRAY_COUNT(D_80250008_A1A258) - 1], 42, 0);
    func_8036C898_840048(D_80250008_A1A258[ARRAY_COUNT(D_80250008_A1A258) - 1], "End");
}

void func_801DFFEC_9AA23C(s32 arg0) {
    s32 i;

    if (arg0 != 0) {
        for (i = 0; i < 20; i++) {
            func_8036D1A4_840954(D_80250008_A1A258[i], 0);
        }
    } else {
        for (i = 0; i < 20; i++) {
            func_8036D1A4_840954(D_80250008_A1A258[i], 1);
        }
    }
}

void func_801E008C_9AA2DC(s16* arg0, s32 arg1) {
    char sp20[0x40];
    s32 sp1C;

    if (arg0 == NULL) {
        return;
    }
    func_8036A8E4_83E094(D_8024FFFC_A1A24C);
    func_8036CB58_840308(D_8024FFFC_A1A24C, 0xC);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036B9EC_83F19C(D_8024FFFC_A1A24C, 0, 0);
    sp1C = func_801DCD7C_9A6FCC(arg0, sp20);
    if (*arg0 != 0) {
        func_8036C898_840048(D_8024FFFC_A1A24C, sp20);
    }
    if (D_802500BE_A1A30E < 31) {
        sp1C += 116;
    } else {
        sp1C = -16;
    }
    func_8036CBA0_840350(D_8024FFF0_A1A240, sp1C, 0xC5);
    D_802500A4_A1A2F4->sprite.x = sp1C;
    func_801DE9B0_9A8C00(1);
}

void func_801E0194_9AA3E4(u32 arg0) {
    UNUSED s32 pad;

    switch (arg0) {
        case 0:
            D_802500BC_A1A30C = 0;
            func_801DFB48_9A9D98();
            func_801DFDF0_9AA040(D_802500BC_A1A30C);
            func_801DFFEC_9AA23C(1);
            break;
        case 1:
            D_802500BC_A1A30C++, D_802500BC_A1A30C %= 3;
            func_801DFDF0_9AA040(D_802500BC_A1A30C);
            break;
        case 2:
            D_802500BC_A1A30C--, D_802500BC_A1A30C %= 3;
            func_801DFDF0_9AA040(D_802500BC_A1A30C);
            break;
        case 3:
            D_802500BC_A1A30C = 0;
            func_801DFDF0_9AA040(D_802500BC_A1A30C);
            break;
        case 4:
            D_802500BC_A1A30C = 1;
            func_801DFDF0_9AA040(D_802500BC_A1A30C);
            break;
        case 5:
            D_802500BC_A1A30C = 2;
            func_801DFDF0_9AA040(D_802500BC_A1A30C);
            break;
        case 6:
            func_801DFDA0_9A9FF0();
            func_801DE9B0_9A8C00(0);
            break;
    }
}

void func_801E0300_9AA550(void) {
    s16* sp1C;

    sp1C = func_801E3A34_9ADC84(D_80208B54_9D2DA4);
    if (sp1C == 0) {
        return;
    }
    if (D_802500BE_A1A30E > 0) {
        sp1C[--D_802500BE_A1A30E] = 0;
    }
    func_801E008C_9AA2DC(sp1C, D_802500BE_A1A30E);
    return;
}

void func_801E0398_9AA5E8(s32 arg0, s32 arg1) {
    s16* sp2C;
    char* temp_t7;

    sp2C = func_801E3A34_9ADC84(D_80208B54_9D2DA4);
    if (sp2C == NULL) {
        return;
    }
    sp2C[31] = 0;

    for (D_802500BE_A1A30E = 0; D_802500BE_A1A30E < 31; D_802500BE_A1A30E++) {
        if (sp2C[D_802500BE_A1A30E] == 0) {
            break;
        }
    }

    if (arg1 == 19) {
        switch (arg0) {
            case 0:
                auPlaySound(0x4A);
                func_801E0300_9AA550();
                return;
            case 1:
                if (D_802500BE_A1A30E < 31) {
                    sp2C[D_802500BE_A1A30E] = '　';
                    D_802500BE_A1A30E++;
                    sp2C[D_802500BE_A1A30E] = 0;
                    if (func_801DCD7C_9A6FCC(sp2C, 0) >= 169) {
                        auPlaySound(0x55);
                        ohWait(0xA);
                        sp2C[--D_802500BE_A1A30E] = 0;
                    } else {
                        auPlaySound(0x42);
                    }
                }
                /* fallthrough */
            default:
                func_801E008C_9AA2DC(sp2C, D_802500BE_A1A30E);
        }
        return;
    }

    if (D_802500BE_A1A30E < 31) {
        sp2C[D_802500BE_A1A30E] = (D_80208B70_9D2DC0[D_802500BC_A1A30C][arg1 * 10 + arg0 * 2] << 8) |
                                  D_80208B70_9D2DC0[D_802500BC_A1A30C][arg1 * 10 + arg0 * 2 + 1];
        D_802500BE_A1A30E++;
        sp2C[D_802500BE_A1A30E] = 0;
        if (func_801DCD7C_9A6FCC(sp2C, 0) >= 169) {
            auPlaySound(0x55);
            ohWait(10);
            sp2C[--D_802500BE_A1A30E] = 0;
        } else {
            auPlaySound(0x42);
        }
        func_801E008C_9AA2DC(sp2C, D_802500BE_A1A30E);
    }
}

void func_801E0678_9AA8C8(s32 arg0) {
    GObj* gobj = D_80250064_A1A2B4;
    SObj* sobj = gobj->data.sobj;

    if (arg0) {
        sobj->sprite = D_801F2F88_9BD1D8;
    } else {
        sobj->sprite = D_801E4518_9AE768;
    }

    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80250060_A1A2B0 = sobj;
}

void func_801E0774_9AA9C4(void) {
    s32 sp54;
    s32 i;
    UnkSnowHerring* sp4C;
    UNUSED s32 pad[7];

    func_801DF2E0_9A9530();
    func_801E0678_9AA8C8(0);
    func_801DD404_9A7654(0);
    func_801DD500_9A7750(0);
    func_801DD5A0_9A77F0(0);
    func_801DD4C0_9A7710(0);
    func_801DF120_9A9370(1);
    sp4C = UIElement_Create(0x7C, 0x83, 0xB8, 0x95, 0x400);
    func_8036B870_83F020(sp4C, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(sp4C, 0, 0, 0, 0, 0);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036B734_83EEE4(sp4C);
    func_8036CB58_840308(sp4C, 8);
    func_8036B9EC_83F19C(sp4C, 0xA, 0);
    func_8037519C_84894C(sp4C, "\\i%2d \\gTaken", func_801E3AB8_9ADD08());
    func_8036B9EC_83F19C(sp4C, 0xA, 9);
    func_8037519C_84894C(sp4C, "\\i%2d \\gLeft", 60 - func_801E3AB8_9ADD08());
    func_8036D1A4_840954(sp4C, 1);
    D_8024FFF4_A1A244 = sp4C;
    ohWait(1);
    func_8036D1A4_840954(D_8024FFF4_A1A244, 0);

    for (i = 0; i < 10; i++) {
        sp54 = (i * 0xFF) / 10;
        func_801DD684_9A78D4(D_8024FFF4_A1A244, sp54);
        func_801DD404_9A7654(sp54);
        ohWait(1);
    }

    func_801DD404_9A7654(0xFF);

    ohWait(21);

    func_8037172C_844EDC(1);
    func_803713C8_844B78(0);

    ohWait(30);

    func_80370C34_8443E4(func_801E1900_9ABB50());
    func_803705A4_843D54();
    func_803700A4_843854(1);
    func_8036D4A0_840C50((0, 0));
}

void func_801E09A0_9AABF0(s32 arg0) {
    UNUSED s32 pad;
    s32 i;
    s32 sp1C;

    if (arg0 != 0) {
        sp1C = arg0;
        auSetBGMVolumeSmooth(0, 0, sp1C);
    } else {
        sp1C = 10;
    }

    func_803700A4_843854(0);
    func_803713C8_844B78(0);
    func_80370A48_8441F8();
    func_803705A4_843D54();

    for (i = sp1C; i >= 0; i--) {
        func_801DD684_9A78D4(D_8024FFF4_A1A244, (i * 0xFF) / sp1C);
        func_801DD404_9A7654((i * 0xFF) / sp1C);
        ohWait(1);
    }

    func_8036B5F0_83EDA0(D_8024FFF4_A1A244);
    func_801DD404_9A7654(0);
    func_801DF120_9A9370(0);
    func_8037172C_844EDC(0);
}

void func_801E0AF0_9AAD40(void) {
    s32 sp3C;
    s32 i;
    UnkSnowHerring* sp34;

    func_801E0678_9AA8C8(1);
    func_801DE620_9A8870(2, 1);
    func_801DE7E8_9A8A38(1);
    func_801DED68_9A8FB8(0);
    func_801DD404_9A7654(0);
    func_801DD500_9A7750(0);
    func_801DD5A0_9A77F0(0);
    func_801DD4C0_9A7710(0);
    sp34 = UIElement_Create(0xA8, 0xA5, 0x3C, 0x12, 0x400);
    func_8036B870_83F020(sp34, 1, 0, 0, 0, 0xFF);
    func_8036B870_83F020(sp34, 0, 0, 0, 0, 0);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036B734_83EEE4(sp34);
    func_8036CB58_840308(sp34, 0xC);
    func_8036A8E4_83E094(sp34);
    func_8036C898_840048(sp34, "\\i−\\g   \\i−\\g");
    func_8036D1A4_840954(sp34, 1);
    D_80250058_A1A2A8 = sp34;
    sp34 = UIElement_Create(0x92, 0x16, 0x6C, 0x10, 0);
    func_8036B870_83F020(sp34, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(sp34, 0, 0xDA, 0x6C, 0, 0);
    func_8036B734_83EEE4(sp34);
    func_8036CB58_840308(sp34, 0xC);
    func_8036D448_840BF8(1);
    func_8036D3E8_840B98(-1, 3);
    func_8036B9EC_83F19C(sp34, (108 - func_8036D4F0_840CA0("PKMN Album")) / 2, 0);
    func_8036C898_840048(sp34, "PKMN Album");
    func_8036D1A4_840954(sp34, 1);
    D_8024FFF8_A1A248 = sp34;
    sp34 = UIElement_Create(0x74, 0xC5, 0xA8, 0xC, 0x400);
    func_8036B870_83F020(sp34, 1, 0, 0, 0, 0xFF);
    func_8036B870_83F020(sp34, 0, 0, 0, 0, 0);
    func_8036B734_83EEE4(sp34);
    func_8036CB58_840308(sp34, 0xC);
    func_8036D1A4_840954(sp34, 1);
    D_8024FFFC_A1A24C = sp34;
    ohWait(1);

    for (i = 0; i < 10; i++) {
        sp3C = (i * 0xFF) / 10;
        func_801DD404_9A7654(sp3C);
        func_801DD500_9A7750(sp3C);
        func_801DD4C0_9A7710(sp3C);
        func_801DD5A0_9A77F0(sp3C);
        ohWait(1);
    }

    func_803713D4_844B84(4);
    func_801DD404_9A7654(0xFF);
    func_801DD500_9A7750(0xFF);
    func_801DD5A0_9A77F0(0xFF);
    func_801DD954_9A7BA4(func_801E191C_9ABB6C() - (func_801E191C_9ABB6C() % 6));
    ohWait(21);
    func_8036D1A4_840954(D_8024FFF8_A1A248, 0);
    func_8037172C_844EDC(1);
    ohWait(30);
}

void func_801E0E58_9AB0A8(void) {
    s32 sp1C;
    s32 i;

    func_803700A4_843854(0);
    func_8036D1A4_840954(D_8024FFF8_A1A248, 1);
    func_803713C8_844B78(0);
    func_80370A48_8441F8();
    func_803705A4_843D54();

    for (i = 10; i >= 0; i--) {
        sp1C = (i * 0xFF) / 10;
        func_801DD404_9A7654(sp1C);
        func_801DD500_9A7750(sp1C);
        func_801DD5A0_9A77F0(sp1C);
        func_801DD4C0_9A7710(sp1C);
        ohWait(1);
    }

    func_801DD404_9A7654(0);
    func_801DD500_9A7750(0);
    func_801DD5A0_9A77F0(0);
    func_801DD4C0_9A7710(0);
    ohWait(1);
    func_8036B5F0_83EDA0(D_8024FFF8_A1A248);
    func_8036B5F0_83EDA0(D_8024FFFC_A1A24C);
    func_8036B5F0_83EDA0(D_80250058_A1A2A8);
    func_801DF120_9A9370(0);
    func_801DDC70_9A7EC0(0);
    func_801DE620_9A8870(2, 0);
    func_801DE7E8_9A8A38(0);
    func_801DED68_9A8FB8(0);
    func_8037172C_844EDC(0);
    func_801E41AC_9AE3FC();
}

void func_801E0F90_9AB1E0(void) {
    UNUSED s32 pad[1];
    int sp20;
    UNUSED s32 pad2[1];

    sp20 = 0;
    func_801DE620_9A8870(1, 1);
    func_801DE350_9A85A0(1, sp20);
    func_8036D1A4_840954(D_8024FFF4_A1A244, 0);
    func_8036D4A0_840C50(0);
    func_8037172C_844EDC(1);
    func_803700A4_843854(1);
    ohWait(21);
}

void func_801E0FFC_9AB24C(s32 arg0) {
    switch (arg0) {
        case 1:
            func_801DE350_9A85A0(0, 0);
            func_801DE620_9A8870(2, 1);
            func_801DD954_9A7BA4(func_801E191C_9ABB6C() - (func_801E191C_9ABB6C() % 6));
            break;
        case 2:
            func_801DE620_9A8870(1, 1);
            func_801DDC70_9A7EC0(0);
            func_801DE350_9A85A0(1, func_801E191C_9ABB6C());
            break;
    }
}

void* func_801E10D0_9AB320(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, 6, &D_801FFA10_9C9C60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 127;
    sobj->sprite.y = 53;
    sobj->sprite.scalex = 0.0f;
    sobj->sprite.scaley = 0.0f;
    sobj->sprite.attr |= SP_HIDDEN;
    D_8025009C_A1A2EC = sobj;

    return gobj;
}

void func_801E1168_9AB3B8(s32 arg0) {
    UNUSED s32 pad[2];
    UIFrame* sp34;
    UnkSnowHerring* sp30;

    if (arg0 != 0) {
        sp34 = UIFrame_Create();
        D_8025005C_A1A2AC = sp34;
        UIFrame_SetPos(sp34, 184, 320);
        UIFrame_Show(sp34, false);
        sp30 = UIElement_Create(0x68, 0xAD, 0xC0, 0x2F, 0);
        D_80250000_A1A250 = sp30;
        func_8036B870_83F020(sp30, 1, 0xFF, 0xFF, 0xFF, 0xFF);
        func_8036B870_83F020(sp30, 0, 0xA3, 0x46, 0x46, 0xFF);
        func_8036B734_83EEE4(sp30);
        func_8036D1A4_840954(sp30, 1);
        ohWait(1);
        func_8036CB58_840308(sp30, 0xC);
        func_8036D448_840BF8(1);
        func_8036D3E8_840B98(-1, 3);
        func_8036B9EC_83F19C(sp30, 0, 0);
        func_8036C898_840048(sp30, "Delete this picture?\n\n");
        ohWait(1);
        UIFrame_FadeIn(sp34, FRAME_STYLE_0);
        func_8036D1A4_840954(sp30, 0);
        func_8036D4A0_840C50((0, 0));
        func_8036B9EC_83F19C(sp30, 0, 32);
        func_8036C898_840048(sp30, "\\a Yes   \\b No");
    } else {
        func_8036A8E4_83E094(D_80250000_A1A250);
        func_8036B5F0_83EDA0(D_80250000_A1A250);
        UIFrame_FadeOut(D_8025005C_A1A2AC);
        ohWait(21);
    }
}

void func_801E1320_9AB570(s32 arg0) {
    GObj* gobj;
    SObj* sobj;
    s32 i;

    gobj = func_80371C68_845418(NULL, 6, &D_80200058_9CA2A8);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 127;
    sobj->sprite.y = 53;
    sobj = func_80371E68_845618(sobj, &D_80200058_9CA2A8);
    sobj->sprite.x = 143;
    sobj->sprite.y = 0;
    sobj = func_80371DC0_845570(sobj, &D_80200400_9CA650);
    sobj->sprite.x = 3;
    sobj->sprite.y = 0;
    sobj = func_80371DC0_845570(sobj, &D_80200400_9CA650);
    sobj->sprite.x = 3;
    sobj->sprite.y = 108;
    sobj = func_80371DC0_845570(sobj, &D_80208B10_9D2D60);
    sobj->sprite.x = 3;
    sobj->sprite.y = 3;
    sobj->sprite = D_8025010C_A1A35C->sprite;
    func_801DE350_9A85A0(0, 0);
    func_8036D1A4_840954(D_8024FFFC_A1A24C, 1);
    auPlaySound(0x5E);

    for (i = 0; i < 13; i++, ohWait(1)) {
        gobj->data.sobj->sprite.y--;
        gobj->data.sobj->sprite.x++;
    }

    ohWait(45);

    auPlaySound(0x4A);

    for (i = 0; gobj->data.sobj->sprite.y < 270; i++, ohWait(1)) {
        gobj->data.sobj->sprite.y += (i * 2) + 10;
    }

    omDeleteGObj(gobj);
    if (D_80208B54_9D2DA4 == arg0) {
        D_80208B54_9D2DA4 = -1;
    }
    func_801E3914_9ADB64(arg0);
    func_801E0FFC_9AB24C(1);
    return;
}

void func_801E1598_9AB7E8(GObj* arg0) {
    UNUSED s32 pad[2];
    s32 i;
    UNUSED s32 pad2;
    UnkSnowHerring* sp64;
    UNUSED s32 pad3;
    s32 sp5C;
    UNUSED s32 pad4[12];

    sp5C = 1;
    func_803717E8_844F98();
    func_80370428_843BD8();
    func_801E4084_9AE2D4();
    func_803700A4_843854(0);
    func_801DE768_9A89B8();
    func_801DE830_9A8A80();
    func_801DECE8_9A8F38();
    func_801E10D0_9AB320();
    func_801DD914_9A7B64();
    func_801DDC70_9A7EC0(0);
    func_801DD500_9A7750(0);
    func_801DE0C8_9A8318();
    func_801DE3DC_9A862C();
    func_801DDE64_9A80B4();
    func_801DE03C_9A828C(0);
    sp64 = UIElement_Create(0x7C, 0x83, 0x3C, 0x12, 0x400);
    func_8036B870_83F020(sp64, 1, 0xFF, 0xFF, 0xFF, 0xFF);
    func_8036B870_83F020(sp64, 0, 0, 0, 0, 0);
    func_8036D448_840BF8(0);
    func_8036D3E8_840B98(0, 4);
    func_8036B734_83EEE4(sp64);
    func_8036CB58_840308(sp64, 8);
    func_8036B9EC_83F19C(sp64, 0xA, 0);
    func_8037519C_84894C(sp64, "\\i%2d \\gTaken", func_801E3AB8_9ADD08());
    func_8036B9EC_83F19C(sp64, 0xA, 9);
    func_8037519C_84894C(sp64, "\\i%2d \\gLeft", 60 - func_801E3AB8_9ADD08());
    func_8036D1A4_840954(sp64, 1);
    ohWait(1);
    D_8024FFF4_A1A244 = sp64;
    func_8036D1A4_840954(D_8024FFF4_A1A244, 0);

    for (i = 0; i < 60; i++) {
        func_801DD684_9A78D4(D_8024FFF4_A1A244, (i * 0xFF) / 60);
        func_801DD404_9A7654((i * 0xFF) / 60);
        ohWait(1);
    }

    func_801DD404_9A7654(0xFF);
    func_8037172C_844EDC(1);
    func_803713C8_844B78(0);

    ohWait(30);

    func_80370C34_8443E4(func_801E1900_9ABB50());
    func_803705A4_843D54();
    func_803700A4_843854(1);
    func_8036D4A0_840C50((0, 0));

    while (true) {
        func_801E37A0_9AD9F0();
        func_8037172C_844EDC(0);
        func_80374D20_8484D0();
        D_80208B74_9D2DC4 = false;
        func_800AADF0(SCENE_OAKS_LAB_2);
        ohWait(1);
    }
}

void func_801E1858_9ABAA8(void) {
    GObj* gobj;
    SObj* sobj;

    func_800A85E8(func_801E1598_9AB7E8, LINK_6, DL_LINK_0, NULL);
    gobj = func_80371D14_8454C4(0, 6, &D_801E4518_9AE768);
    sobj = gobj->data.sobj;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80250064_A1A2B4 = gobj;
    D_80250060_A1A2B0 = sobj;
    func_801DF1F8_9A9448();
    func_801DD404_9A7654(0);
}
