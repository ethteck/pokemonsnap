#include "common.h"
#include "unk_end_level/unk_end_level.h"
#include "unk_end_level_5.h"
#include "photo_check/photo_check.h"

typedef struct UnkBordeauxBetta {
    GObj* unk_0;
    SObj* unk_4;
    s8 unk_8;
} UnkBordeauxBetta; // size: 0xC

// DATA
extern Sprite D_801F6B50_9C0DA0;
extern Sprite D_801FB1D0_9C5420;
extern Sprite D_801FFA10_9C9C60;
extern Sprite D_80200058_9CA2A8;
extern Sprite D_80200400_9CA650;
extern Sprite D_802005B8_9CA808;
extern Sprite D_802006E8_9CA938;
extern Sprite D_80201728_9CB978;
extern Sprite D_80208B10_9D2D60;
extern s32 D_80208B54_9D2DA4;
extern s32 D_80208B58_9D2DA8[6];
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
extern UnkSnowHerring* D_80250008_A1A258[20]; // references in the code to this being 6 long and 20 long. what?
extern UnkSnowHerring* D_80250058_A1A2A8;
extern SObj* D_80250060_A1A2B0;
extern GObj* D_80250064_A1A2B4;
extern SObj* D_80250068_A1A2B8[4];
extern SObj* D_80250080_A1A2D0[7];
extern SObj* D_8025009C_A1A2EC;
extern SObj* D_802500A0_A1A2F0;
extern SObj* D_802500A4_A1A2F4;
extern SObj* D_802500A8_A1A2F8;
extern GObj* D_802500AC_A1A2FC;
extern SObj* D_802500B0_A1A300;
extern s32 D_802500B4_A1A304;
extern Unk803A6C18* D_802500B8_A1A308;
extern s16 D_802500BE_A1A30E;
extern UnkBordeauxBetta D_802500C0_A1A310[6];
extern GObj* D_80250108_A1A358;
extern SObj* D_8025010C_A1A35C;

void func_801DDC70_9A7EC0(UNK_TYPE);
void func_801DE1FC_9A844C(UNK_TYPE);
void func_801DE2BC_9A850C(s32);
void func_801DE350_9A85A0(UNK_TYPE, UNK_TYPE);
void func_801DE620_9A8870(UNK_TYPE, UNK_TYPE);
void func_801DF120_9A9370(UNK_TYPE);
PhotoData* func_801E38E0_9ADB30(s32 arg0);
UnkThing* func_801E4068_9AE2B8(void);
void func_801E41AC_9AE3FC(void);

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/D_80208C50_9D2EA0.s")
// char D_80208C50_9D2EA0[] = "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ０１２３４５６７８９†‡¶〜！？＠＃％＆＊（）＿＋＝ー’”；：／＄．，＜＞♂♀［］ε　";

s32 func_801DCD20_9A6F70(void) {
    return D_802500B4_A1A304;
}

s32 func_801DCD3C_9A6F8C(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_80208B58_9D2DA8)) {
        return -1;
    }
    return D_80208B58_9D2DA8[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DCD7C_9A6FCC.s")

void func_801DCED4_9A7124(s32 arg0) {
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

void func_801DCFB8_9A7208(s32 arg0) {
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
            return func_8037501C_8487CC("%5d", arg0->unk_3B4);
        case 2:
            return "おおきさ"; // size
        case 3:
            if (arg0->unk_3AC != 0) {
                return func_8037501C_8487CC("%5d", arg0->unk_3AC);
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 4:
            return "まるみえ"; // "full view" (view?)
        case 5:
            if (arg0->unk_3AE != 0) {
                return func_8037501C_8487CC("%5.2f", (s32) (f32) (arg0->unk_3AE / 10000));
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 6:
            return "コメント"; // comment
        case 7:
            if (arg0->unk_3A8 != 0) {
                return func_8037501C_8487CC("%5d", arg0->unk_3A8);
            } else {
                return "　　　なし";
            }
        case 8:
            if (arg0->unk_3A8 != 0) {
                return "ポーズ";
            } else {
                return "むき";
            }
        case 9:
            if (arg0->unk_3B0 != 0) {
                return func_8037501C_8487CC("%5d", arg0->unk_3B0);
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 10:
            return "センサー"; // sensor
        case 11:
            if (arg0->unk_3A7 != 0) {
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
                return func_8037501C_8487CC("%3d", arg0->unk_3A6);
            }
        case 14:
            if (D_80208B88_9D2DD8 != 0) {
                return "−−−−−";
            } else {
                return func_8037501C_8487CC("%5d", arg0->unk_3A4);
            }
    }
}

void func_801DD404_9A7654(s32 arg0) {
    s32 i;

    D_80250060_A1A2B0->sprite.red = arg0;
    D_80250060_A1A2B0->sprite.green = arg0;
    D_80250060_A1A2B0->sprite.blue = arg0;

    for (i = 0; i < ARRAY_COUNT(D_80250068_A1A2B8); i++) {
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

    for (i = 0; i < 6; i++) {
        func_801DD6CC_9A791C(i);
    }
}

void func_801DD954_9A7BA4(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DD954_9A7BA4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DDC70_9A7EC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DDD28_9A7F78.s")

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

GObj* func_801DDE64_9A80B4() {
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
    func_80374714_847EC4(&func_801E4068_9AE2B8()->main, &D_802500B0_A1A300->sprite);
}

void* func_801DE0C8_9A8318(void) {
    GObj* temp_v0;
    SObj* sp20;
    UNUSED s32 pad[2];

    temp_v0 = func_80371C68_845418(0, 6, &D_80200058_9CA2A8);
    D_80250108_A1A358 = temp_v0;
    sp20 = temp_v0->data.sobj;
    sp20->sprite.x = 127;
    sp20->sprite.y = 53;
    sp20->sprite.attr |= SP_HIDDEN;

    sp20 = func_80371E68_845618(sp20, &D_80200058_9CA2A8);
    sp20->sprite.x = 143;
    sp20->sprite.y = 0;

    sp20 = func_80371DC0_845570(sp20, &D_80200400_9CA650);
    sp20->sprite.x = 3;
    sp20->sprite.y = 0;

    sp20 = func_80371DC0_845570(sp20, &D_80200400_9CA650);
    sp20->sprite.x = 3;
    sp20->sprite.y = 108;

    sp20 = func_80371DC0_845570(sp20, &D_80208B10_9D2D60);
    sp20->sprite.x = 3;
    sp20->sprite.y = 3;

    D_8025010C_A1A35C = sp20;

    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DE1FC_9A844C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DE3DC_9A862C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DE620_9A8870.s")

void* func_801DE768_9A89B8(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(0, 6, &D_801F6B50_9C0DA0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DE830_9A8A80.s")

void func_801DE998_9A8BE8(s32 arg0) {
    D_8024FFE8_A1A238 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DE9B0_9A8C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DEA4C_9A8C9C.s")

void* func_801DECE8_9A8F38(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(0, 6, &D_801FB1D0_9C5420);
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

void func_801DEDB0_9A9000(void);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DEDB0_9A9000.s")

void func_801DEF1C_9A916C(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        func_8036B5F0_83EDA0(D_80250008_A1A258[i]);
    }
}

void func_801DEF6C_9A91BC(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DEF6C_9A91BC.s")

void func_801DF00C_9A925C(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DF00C_9A925C.s")

void func_801DF0D0_9A9320(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        func_8036A8E4_83E094(D_80250008_A1A258[i]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DF120_9A9370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DF1F8_9A9448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DF2E0_9A9530.s")

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
        sprintf(sp28, "%s", (sp4C->unk_3AA > 0 && sp4C->unk_3AA <= POKEDEX_MAX) ? getPokemonName(sp4C->unk_3AA) : "−−−−−");
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
            if (D_802500B8_A1A308->unk_3AA > 0) {
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

            D_8024FFF8_A1A248 = func_8036AC6C_83E41C(0x92, 0x16, 0x6C, 0x10, 0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DFB48_9A9D98.s")

void func_801DFDA0_9A9FF0(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        func_8036B5F0_83EDA0(D_80250008_A1A258[i]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DFDF0_9AA040.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801DFFEC_9AA23C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E008C_9AA2DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E0194_9AA3E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E0300_9AA550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E0398_9AA5E8.s")

void func_801E0678_9AA8C8(s32);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E0678_9AA8C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E0774_9AA9C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E09A0_9AABF0.s")

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
    sp34 = func_8036AC6C_83E41C(0xA8, 0xA5, 0x3C, 0x12, 0x400);
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
    sp34 = func_8036AC6C_83E41C(0x92, 0x16, 0x6C, 0x10, 0);
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
    sp34 = func_8036AC6C_83E41C(0x74, 0xC5, 0xA8, 0xC, 0x400);
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

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E0FFC_9AB24C.s")

void* func_801E10D0_9AB320(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(0, 6, &D_801FFA10_9C9C60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 127;
    sobj->sprite.y = 53;
    sobj->sprite.scalex = 0.0f;
    sobj->sprite.scaley = 0.0f;
    sobj->sprite.attr |= SP_HIDDEN;
    D_8025009C_A1A2EC = sobj;

    return gobj;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E1168_9AB3B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E1320_9AB570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E1598_9AB7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9A6F70/func_801E1858_9ABAA8.s")
