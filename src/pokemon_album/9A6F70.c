#include "common.h"
#include "window/window.h"
#include "pokemon_album.h"
#include "photo_check/photo_check.h"

typedef struct UnkBordeauxBetta {
    GObj* unk_0;
    SObj* unk_4;
    u8 unk_8;
} UnkBordeauxBetta; // size: 0xC

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

s32 D_80208B50_9D2DA0 = 0; // TODO belongs to sprites

s32 D_80208B54_9D2DA4 = -1;
s32 D_80208B58_9D2DA8[6] = { 0x3ec, 0x3f2, 0x3fa, 0x3fe, 0x404, 0x40b };
char* D_80208B70_9D2DC0[] = {
    "ＡＢＣＤＥＦＧＨＩＪＫＬＭＮＯＰＱＲＳＴＵＶＷＸＹＺａｂｃｄｅｆｇｈｉｊｋｌｍｎｏｐｑｒｓｔｕｖｗｘｙｚ０１２３４５６７８９†‡¶〜！？＠＃％＆＊（）＿＋＝ー’”；：／＄．，＜＞♂♀［］ε　",
};
s32 D_80208B74_9D2DC4 = 1;
s32 D_80208B78_9D2DC8 = 10;
s32 D_80208B7C_9D2DCC = 5;
s32 D_80208B80_9D2DD0 = 10;
s32 D_80208B84_9D2DD4 = 5;
UNK_TYPE D_80208B88_9D2DD8 = 0;

UIElement* album_D_8024FFF8_A1A248;
UIElement* album_D_8024FFFC_A1A24C;
UIElement* album_D_80250000_A1A250;
UIElement* album_D_80250008_A1A258[20]; // references in the code to this being 6 long and 20 long. what?
UIElement* album_D_80250058_A1A2A8;
UIFrame* album_D_8025005C_A1A2AC;
SObj* album_D_80250060_A1A2B0;
GObj* album_D_80250064_A1A2B4;
SObj* album_D_80250068_A1A2B8[4];
GObj* album_D_80250078_A1A2C8;
s32 album_D_8025007C_A1A2CC;
SObj* album_D_80250080_A1A2D0[7];
SObj* album_D_8025009C_A1A2EC;
SObj* album_D_802500A0_A1A2F0;
SObj* album_D_802500A4_A1A2F4;
SObj* album_D_802500A8_A1A2F8;
GObj* album_D_802500AC_A1A2FC;
SObj* album_D_802500B0_A1A300;
s32 album_AlbumPage;
Unk803A6C18* album_D_802500B8_A1A308;
u8 album_D_802500BC_A1A30C;
s16 album_D_802500BE_A1A30E;
UnkBordeauxBetta album_D_802500C0_A1A310[6];
GObj* album_D_80250108_A1A358;
SObj* album_D_8025010C_A1A35C;
s32 album_D_80250110_A1A360;
s32 album_D_8024EFE0_A19230;
u8 album_D_8024EFE8[0x1000];
s32 album_D_8024FFE8_A1A238;
s32 album_D_8024FFEC_A1A23C;
UIElement* album_D_8024FFF0_A1A240;
UIElement* album_D_8024FFF4_A1A244;

s32 func_801DCD20_9A6F70(void) {
    return album_AlbumPage;
}

s32 func_801DCD3C_9A6F8C(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_80208B58_9D2DA8)) {
        return -1;
    }
    return D_80208B58_9D2DA8[arg0];
}

s32 func_801DCD7C_9A6FCC(s16* wideStr, char* dst) {
    char temp[0x40];
    char* srcPtr;
    char* dstPtr;
    s32 srcIndex;
    s32 dstIndex;

    srcPtr = (char*) wideStr; // todo what is going on with the type of this
    dstPtr = dst != NULL ? dst : temp;
    srcIndex = 0;
    dstIndex = 0;

    while (srcPtr[srcIndex] != 0) {
        if (*((u16*) (srcPtr + srcIndex)) == '　') {
            // convert wide space to normal space
            dstPtr[dstIndex] = ' ';
            dstPtr[dstIndex + 1] = 0;
            srcIndex += 2;
            dstIndex += 1;
        } else {
            dstPtr[dstIndex] = srcPtr[srcIndex];
            dstPtr[dstIndex + 1] = *(srcPtr + srcIndex + 1);
            srcIndex += 2;
            dstIndex += 2;
        }
    }

    dstPtr[dstIndex] = 0;
    return UIText_GetStringWidth(dstPtr);
}

void func_801DCED4_9A7124(GObj* arg0) {
    while (D_80208B74_9D2DC4) {
        D_80208B78_9D2DC8 += D_80208B7C_9D2DCC;
        if (D_80208B78_9D2DC8 > 255) {
            D_80208B78_9D2DC8 = 255;
            D_80208B7C_9D2DCC = -5;
        }
        if (D_80208B78_9D2DC8 < 120) {
            D_80208B78_9D2DC8 = 120;
            D_80208B7C_9D2DCC = 5;
        }
        album_D_802500A4_A1A2F4->sprite.alpha = D_80208B78_9D2DC8;
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

        UIElement_SetSpriteColor(album_D_8024FFF0_A1A240, 255, 255, 255, (D_80208B80_9D2DD0 > 0xA0) ? 255 : 0);
        ohWait(1);
    }

    omDeleteGObj(NULL);
    ohWait(99);
}

s16 func_801DD0CC_9A731C(void) {
    return album_D_802500BE_A1A30E;
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
            return func_8037501C_8487CC("%5d", arg0->score.specialID);
        case 2:
            return "おおきさ"; // size
        case 3:
            if (arg0->score.sizeParam2 != 0) {
                return func_8037501C_8487CC("%5d", arg0->score.sizeParam2);
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 4:
            return "まるみえ"; // "full view" (view?)
        case 5:
            if (arg0->score.sizeParam1 != 0) {
                return func_8037501C_8487CC("%5.2f", (s32) (f32) (arg0->score.sizeParam1 / 10000));
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 6:
            return "コメント"; // comment
        case 7:
            if (arg0->score.commentID != 0) {
                return func_8037501C_8487CC("%5d", arg0->score.commentID);
            } else {
                return "　　　なし";
            }
        case 8:
            if (arg0->score.commentID != 0) {
                return "ポーズ";
            } else {
                return "むき";
            }
        case 9:
            if (arg0->score.posePts != 0) {
                return func_8037501C_8487CC("%5d", arg0->score.posePts);
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 10:
            return "センサー"; // sensor
        case 11:
            if (arg0->score.isWellFramed) {
                return "　　　あり";
            } else {

                return "　　　なし";
            }
        case 12:
            return "なかま";
        case 13:
            if (D_80208B88_9D2DD8) {
                return "−−−−−";
            } else {
                return func_8037501C_8487CC("%3d", arg0->score.samePkmnNumber);
            }
        case 14:
            if (D_80208B88_9D2DD8) {
                return "−−−−−";
            } else {
                return func_8037501C_8487CC("%5d", arg0->score.samePkmnBonus);
            }
    }
}

void func_801DD404_9A7654(s32 color) {
    s32 i;

    album_D_80250060_A1A2B0->sprite.red = color;
    album_D_80250060_A1A2B0->sprite.green = color;
    album_D_80250060_A1A2B0->sprite.blue = color;

    for (i = 0; i < ARRAY_COUNT(album_D_80250068_A1A2B8); i++) {
        if (album_D_80250068_A1A2B8[i]) {
            album_D_80250068_A1A2B8[i]->sprite.red = album_D_80250068_A1A2B8[i]->sprite.green = album_D_80250068_A1A2B8[i]->sprite.blue = color;
        }
    }
}

void func_801DD4C0_9A7710(u32 arg0) {
    album_D_802500A0_A1A2F0->sprite.red = album_D_802500A0_A1A2F0->sprite.green = album_D_802500A0_A1A2F0->sprite.blue = arg0;
}

void func_801DD500_9A7750(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(album_D_802500C0_A1A310); i++) {
        album_D_802500C0_A1A310[i].unk_0->data.sobj->sprite.red = album_D_802500C0_A1A310[i].unk_0->data.sobj->sprite.green = album_D_802500C0_A1A310[i].unk_0->data.sobj->sprite.blue = arg0;
    }
}

void func_801DD5A0_9A77F0(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(album_D_80250080_A1A2D0); i++) {
        if (album_D_80250080_A1A2D0[i] != NULL) {
            album_D_80250080_A1A2D0[i]->sprite.red = album_D_80250080_A1A2D0[i]->sprite.green = album_D_80250080_A1A2D0[i]->sprite.blue = arg0;
        }
    }
}

void func_801DD638_9A7888(s32 arg0) {
    album_D_80250108_A1A358->data.sobj->sprite.red = album_D_80250108_A1A358->data.sobj->sprite.green = album_D_80250108_A1A358->data.sobj->sprite.blue = arg0;
}

void func_801DD684_9A78D4(UIElement* el, s32 color) {
    UIElement_SetSpriteColor(el, color, color, color, 255);
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
    album_D_802500C0_A1A310[arg0].unk_0 = gobj;

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
    album_D_802500C0_A1A310[arg0].unk_4 = sobj;

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

    for (i = 0; i < ARRAY_COUNT(album_D_802500C0_A1A310); i++) {
        func_801DD6CC_9A791C(i);
    }
}

void func_801DD954_9A7BA4(s32 idx) {
    s32 i;
    char sp24[0x20];

    album_AlbumPage = idx / 6;

    for (i = 0; i < ARRAY_COUNT(album_D_802500C0_A1A310); idx++, i++) {
        if (func_80374714_847EC4(album_GetAlbumPhoto(idx), &album_D_802500C0_A1A310[i].unk_4->sprite) != NULL) {
            album_D_802500C0_A1A310[i].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
            album_D_802500C0_A1A310[i].unk_8 = 0;
        } else {
            album_D_802500C0_A1A310[i].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
            album_D_802500C0_A1A310[i].unk_8 = 1;
        }
    }

    UIElement_Draw(album_D_80250058_A1A2A8);
    UIText_SetPrintDelay(0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_SetTextPos(album_D_80250058_A1A2A8, 0, 0);
    UIElement_PrintText(album_D_80250058_A1A2A8, "  \\i−\\g      \\i−\\g  ");
    sprintf(sp24, "%d", album_AlbumPage + 1);
    UIElement_SetTextPos(album_D_80250058_A1A2A8, 30 - (UIText_GetStringWidth(sp24) / 2), 0);
    UIElement_PrintText(album_D_80250058_A1A2A8, sp24);
    UIElement_SetState(album_D_80250058_A1A2A8, UI_NORMAL);
}

void func_801DDB54_9A7DA4(s32 arg0) {
    s32 idx;

    idx = arg0 % ARRAY_COUNT(album_D_802500C0_A1A310);
    if (func_80374714_847EC4(album_GetAlbumPhoto(arg0), &album_D_802500C0_A1A310[idx].unk_4->sprite)) {
        album_D_802500C0_A1A310[idx].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
        album_D_802500C0_A1A310[idx].unk_8 = 0;
    } else {
        album_D_802500C0_A1A310[idx].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
        album_D_802500C0_A1A310[idx].unk_8 = 1;
    }
}

void func_801DDC70_9A7EC0(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(album_D_802500C0_A1A310); i++) {
        if (arg0 && album_D_802500C0_A1A310[i].unk_8 != NULL) {
            album_D_802500C0_A1A310[i].unk_0->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            album_D_802500C0_A1A310[i].unk_0->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_801DDD28_9A7F78(s32 arg0, s32 arg1) {
    if (arg1) {
        album_D_802500C0_A1A310[arg0 % ARRAY_COUNT(album_D_802500C0_A1A310)].unk_0->data.sobj->sprite.attr =
            album_D_802500C0_A1A310[arg0 % ARRAY_COUNT(album_D_802500C0_A1A310)].unk_0->data.sobj->sprite.attr & ~SP_HIDDEN;
    } else {
        album_D_802500C0_A1A310[arg0 % ARRAY_COUNT(album_D_802500C0_A1A310)].unk_0->data.sobj->sprite.attr =
            album_D_802500C0_A1A310[arg0 % ARRAY_COUNT(album_D_802500C0_A1A310)].unk_0->data.sobj->sprite.attr | SP_HIDDEN;
    }
}

void func_801DDDF8_9A8048(s32 x, s32 y) {
    SObj* sobj;

    sobj = album_D_802500AC_A1A2FC->data.sobj;
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
    album_D_802500AC_A1A2FC = gobj;
    album_D_802500B0_A1A300 = sobj;

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
    func_80374714_847EC4(func_801E4068_9AE2B8(), &album_D_802500B0_A1A300->sprite);
}

void* func_801DE0C8_9A8318(void) {
    GObj* gobj;
    SObj* sobj;
    UNUSED s32 pad[2];

    gobj = func_80371C68_845418(NULL, 6, &D_80200058_9CA2A8);
    album_D_80250108_A1A358 = gobj;
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

    album_D_8025010C_A1A35C = sobj;

    return gobj;
}

void func_801DE1FC_9A844C(s32 arg0) {
    char comment[0x40];

    UIElement_Draw(album_D_8024FFFC_A1A24C);
    if (album_GetPhotoComment(arg0) == NULL) {
        return;
    }
    UIElement_SetFont(album_D_8024FFFC_A1A24C, FONT_12);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_SetTextPos(album_D_8024FFFC_A1A24C, 0, 0);
    func_801DCD7C_9A6FCC(album_GetPhotoComment(arg0), comment);
    UIElement_PrintText(album_D_8024FFFC_A1A24C, comment);
    UIElement_SetState(album_D_8024FFFC_A1A24C, UI_NORMAL);
}

void func_801DE2BC_9A850C(s32 arg0) {
    if (D_80208B54_9D2DA4 != arg0) {
        D_80208B54_9D2DA4 = arg0;
    }
    func_80374714_847EC4(album_GetAlbumPhoto(arg0), &album_D_8025010C_A1A35C->sprite);
    UIElement_SetState(album_D_8024FFFC_A1A24C, UI_HIDDEN);
    func_801DE1FC_9A844C(arg0);
    UIElement_SetState(album_D_8024FFFC_A1A24C, UI_NORMAL);
}

void func_801DE350_9A85A0(s32 arg0, s32 arg1) {
    if (arg0) {
        UIElement_SetState(album_D_80250058_A1A2A8, UI_HIDDEN);
        func_801DE2BC_9A850C(arg1);
        auPlaySound(0x47);
        album_D_80250108_A1A358->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        album_D_80250108_A1A358->data.sobj->sprite.attr |= SP_HIDDEN;
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
            album_D_80250080_A1A2D0[(i * 3) + j] = sobj;
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
    album_D_80250080_A1A2D0[6] = sobj;
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
            for (i = 0; i < ARRAY_COUNT(album_D_80250080_A1A2D0) - 1; i++) {
                album_D_80250080_A1A2D0[i]->sprite.attr |= SP_HIDDEN;
            }
            album_D_80250080_A1A2D0[ARRAY_COUNT(album_D_80250080_A1A2D0) - 1]->sprite.attr &= ~SP_HIDDEN;
        } else {
            for (i = 0; i < ARRAY_COUNT(album_D_80250080_A1A2D0) - 1; i++) {
                album_D_80250080_A1A2D0[i]->sprite.attr &= ~SP_HIDDEN;
            }
            album_D_80250080_A1A2D0[ARRAY_COUNT(album_D_80250080_A1A2D0) - 1]->sprite.attr |= SP_HIDDEN;
        }
    } else {
        if (arg0 & 1) {
            album_D_80250080_A1A2D0[ARRAY_COUNT(album_D_80250080_A1A2D0) - 1]->sprite.attr |= SP_HIDDEN;
        }
        if (arg0 & 2) {
            for (i = 0; i < ARRAY_COUNT(album_D_80250080_A1A2D0) - 1; i++) {
                album_D_80250080_A1A2D0[i]->sprite.attr |= SP_HIDDEN;
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
    album_D_802500A0_A1A2F0 = sobj;

    return gobj;
}

void func_801DE7E8_9A8A38(s32 arg0) {
    if (arg0) {
        album_D_802500A0_A1A2F0->sprite.attr &= ~SP_HIDDEN;
    } else {
        album_D_802500A0_A1A2F0->sprite.attr |= SP_HIDDEN;
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
    album_D_802500A4_A1A2F4 = sobj;
    D_80208B74_9D2DC4 = true;
    func_800A85E8(func_801DCED4_9A7124, LINK_6, DL_LINK_0, NULL);
    album_D_8024FFF0_A1A240 = UIElement_Create(116, 197, 12, 12, UI_FLAG_32BIT);
    UIElement_SetColor(album_D_8024FFF0_A1A240, UI_FOREGROUND, 255, 15, 25, 255);
    UIElement_SetColor(album_D_8024FFF0_A1A240, UI_BACKGROUND, 0, 0, 0, 0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_DrawBackground(album_D_8024FFF0_A1A240);
    UIElement_SetFont(album_D_8024FFF0_A1A240, FONT_12);
    UIElement_SetState(album_D_8024FFF0_A1A240, UI_HIDDEN);
    func_800A85E8(func_801DCFB8_9A7208, LINK_6, DL_LINK_0, NULL);

    return gobj;
}

void func_801DE998_9A8BE8(s32 arg0) {
    album_D_8024FFE8_A1A238 = arg0;
}

void func_801DE9B0_9A8C00(s32 arg0) {
    if (arg0) {
        if (album_D_8024FFE8_A1A238 != 0) {
            UIElement_SetState(album_D_8024FFF0_A1A240, UI_NORMAL);
        } else {
            album_D_802500A4_A1A2F4->sprite.attr &= ~SP_HIDDEN;
        }
    } else {
        UIElement_SetState(album_D_8024FFF0_A1A240, UI_HIDDEN);
        album_D_802500A4_A1A2F4->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DEA4C_9A8C9C(s32 arg0, s32 arg1, s32 arg2) {
    s16* sp64;
    char sp60[0x4];
    char sp20[0x40];
    s32 x;

    sp64 = album_GetPhotoComment(D_80208B54_9D2DA4);
    if (sp64 == NULL) {
        return;
    }
    sp64[31] = 0;

    if (arg0 != 0) {
        for (album_D_802500BE_A1A30E = 0; album_D_802500BE_A1A30E < 31; album_D_802500BE_A1A30E++) {
            if (sp64[album_D_802500BE_A1A30E] == 0) {
                break;
            }
        }
    }

    if (album_D_8024FFE8_A1A238 != 0) {
        sp60[0] = D_80208B70_9D2DC0[album_D_802500BC_A1A30C][arg2 * 10 + 2 * arg1];
        sp60[1] = D_80208B70_9D2DC0[album_D_802500BC_A1A30C][arg2 * 10 + 2 * arg1 + 1];
        sp60[2] = 0;
        UIElement_Draw(album_D_8024FFF0_A1A240);
        UIElement_PrintText(album_D_8024FFF0_A1A240, sp60);
        if ((((sp60[0] << 8) | sp60[1]) & 0xFFFF) == '　') {
            UIElement_SetState(album_D_8024FFF0_A1A240, UI_HIDDEN);
            album_D_802500A4_A1A2F4->sprite.attr &= ~SP_HIDDEN;
        } else {
            UIElement_SetState(album_D_8024FFF0_A1A240, UI_NORMAL);
            album_D_802500A4_A1A2F4->sprite.attr |= SP_HIDDEN;
        }
    } else {
        UIElement_SetState(album_D_8024FFF0_A1A240, UI_HIDDEN);
        album_D_802500A4_A1A2F4->sprite.attr &= ~SP_HIDDEN;
    }

    x = func_801DCD7C_9A6FCC(sp64, sp20);
    if ((album_D_802500BE_A1A30E < 31) || 168 - UIText_GetStringWidth(sp60) < x) {
        x += 116;
    } else {
        x = -16;
    }
    UIElement_SetPos(album_D_8024FFF0_A1A240, x, 197);
    album_D_802500A4_A1A2F4->sprite.x = x;
}

void* func_801DECE8_9A8F38(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, 6, &D_801FB1D0_9C5420);
    sobj = gobj->data.sobj;

    sobj->sprite.x = 308;
    sobj->sprite.y = 50;
    sobj->sprite.attr |= SP_HIDDEN;
    album_D_802500A8_A1A2F8 = sobj;

    return gobj;
}

void func_801DED68_9A8FB8(s32 arg0) {
    if (arg0) {
        album_D_802500A8_A1A2F8->sprite.attr &= ~SP_HIDDEN;
    } else {
        album_D_802500A8_A1A2F8->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DEDB0_9A9000(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        album_D_80250008_A1A258[i] = UIElement_Create(234, ((i / 2) * 36) + ((i % 2) * 12) + 67, 60, 8, UI_FLAG_32BIT);
        UIElement_SetColor(album_D_80250008_A1A258[i], UI_FOREGROUND, 0, 0, 0, 255);
        UIElement_SetColor(album_D_80250008_A1A258[i], UI_BACKGROUND, 0, 0, 0, 0);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_DrawBackground(album_D_80250008_A1A258[i]);
        UIElement_SetFont(album_D_80250008_A1A258[i], FONT_8);
        UIElement_SetState(album_D_80250008_A1A258[i], UI_HIDDEN);
    }
}

void func_801DEF1C_9A916C(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        UIElement_Delete(album_D_80250008_A1A258[i]);
    }
}

void func_801DEF6C_9A91BC(s32 arg0) {
    s32 i;

    if (arg0 != 0) {
        for (i = 0; i < 6; i++) {
            UIElement_SetState(album_D_80250008_A1A258[i], UI_NORMAL);
        }
    } else {
        for (i = 0; i < 6; i++) {
            UIElement_SetState(album_D_80250008_A1A258[i], UI_HIDDEN);
        }
    }
}

void func_801DF00C_9A925C(s32 arg0) {
    s32 i;

    for (i = 0; i < 6; i += 2) {
        UIElement_SetPos(album_D_80250008_A1A258[i], arg0 + 234, ((i / 2) * 36) + 67);
        UIElement_SetPos(album_D_80250008_A1A258[i + 1], arg0 + 234, ((i / 2) * 36) + 79);
    }
}

void func_801DF0D0_9A9320(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        UIElement_Draw(album_D_80250008_A1A258[i]);
    }
}

void func_801DF120_9A9370(s32 arg0) {
    s32 i;

    if (arg0) {
        album_D_80250064_A1A2B4->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        album_D_80250064_A1A2B4->data.sobj->sprite.attr |= SP_HIDDEN;
    }

    for (i = ARRAY_COUNT(album_D_80250068_A1A2B8) + 1; i >= 0; i--) {
        if (album_D_80250068_A1A2B8[i] != NULL) {
            if (arg0) {
                album_D_80250068_A1A2B8[i]->sprite.attr &= ~SP_HIDDEN;
            } else {
                album_D_80250068_A1A2B8[i]->sprite.attr |= SP_HIDDEN;
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
    album_D_80250068_A1A2B8[0] = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801ED550_9B77A0);
    sobj->sprite.x = 110;
    sobj->sprite.y = 108;
    sobj->sprite.alpha = 0x80;
    sobj->sprite.attr |= SP_TRANSPARENT;
    album_D_80250068_A1A2B8[1] = sobj;
    album_D_80250068_A1A2B8[2] = NULL;
    album_D_80250068_A1A2B8[3] = NULL;
    album_D_80250078_A1A2C8 = gobj;
}

void func_801DF2E0_9A9530(void) {
    UNUSED s32 pad;
    SObj* sobj;

    sobj = album_D_80250068_A1A2B8[0];
    sobj->sprite = D_801F2D28_9BCF78;
    sobj->sprite.x = 106;
    sobj->sprite.y = 52;
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;

    sobj = album_D_80250068_A1A2B8[1];
    sobj->sprite = D_801ED550_9B77A0;
    sobj->sprite.x = 110;
    sobj->sprite.y = 108;
    sobj->sprite.alpha = 0x80;
    sobj->sprite.attr |= SP_TRANSPARENT;

    album_D_80250068_A1A2B8[2] = NULL;
    album_D_80250068_A1A2B8[3] = NULL;

    album_D_80250068_A1A2B8[4] = NULL;
    album_D_80250068_A1A2B8[5] = NULL;
}

void album_PrintPhotoDescription(s32 descType, s32 entryIndex) {
    Unk803A6C18* sp4C;
    s32 i;
    char str[32];

    sp4C = func_8037452C_847CDC(album_GetAlbumPhoto(entryIndex));
    if (descType == 0) {
        func_801DF0D0_9A9320();

        UIText_SetFont(FONT_8);
        UIElement_SetTextPos(album_D_80250008_A1A258[0], 0, 0);
        UIElement_PrintText(album_D_80250008_A1A258[0], "Course");

        sprintf(str, "%s", getLevelName(getAlbumPhoto(entryIndex)->levelID));
        UIElement_SetTextPos(album_D_80250008_A1A258[1], 60 - UIText_GetStringWidth(str), 0);
        func_8037519C_84894C(album_D_80250008_A1A258[1], "%s", str);

        UIElement_SetTextPos(album_D_80250008_A1A258[2], 0, 0);
        UIElement_PrintText(album_D_80250008_A1A258[2], "Photo by");

        sprintf(str, "%s", get_player_name());
        UIElement_SetTextPos(album_D_80250008_A1A258[3], 60 - UIText_GetStringWidth(str), 0);
        func_8037519C_84894C(album_D_80250008_A1A258[3], "%s", str);

        UIElement_SetTextPos(album_D_80250008_A1A258[4], 0, 0);
        UIElement_PrintText(album_D_80250008_A1A258[4], "Focus");

        sprintf(str, "%s", (sp4C->score.pokemonInFocus > 0 && sp4C->score.pokemonInFocus <= POKEDEX_MAX) ? getPokemonName(sp4C->score.pokemonInFocus) : "−−−−−");
        UIElement_SetTextPos(album_D_80250008_A1A258[5], 60 - UIText_GetStringWidth(str), 0);
        func_8037519C_84894C(album_D_80250008_A1A258[5], "%s", str);
    } else {
        func_801DF0D0_9A9320();

        for (i = 0; i < 6; i++) {
            UIElement_SetTextPos(album_D_80250008_A1A258[i], 0, 0);
            if (i == 13) {
                func_8037519C_84894C(album_D_80250008_A1A258[i], "%sひき", func_801DD12C_9A737C(sp4C, i));
            } else {
                UIElement_PrintText(album_D_80250008_A1A258[i], func_801DD12C_9A737C(sp4C, i));
            }
        }
    }
}

void func_801DF744_9A9994(s32 arg0, s32 arg1) {
    s32 i;

    switch (arg0) {
        case 0:
            album_D_8024EFE0_A19230 = 0;
            album_D_80250064_A1A2B4->data.sobj->sprite.width = 400;
            FocusMark_Show(false);
            UILayout_HideButtons();
            UILayout_WaitPanelTransitionComplete();
            UILayout_ShowPanel(false);
            UIElement_Delete(album_D_8024FFF8_A1A248);
            func_801DEDB0_9A9000();
            album_PrintPhotoDescription(album_D_8024EFE0_A19230, arg1);
            UILayout_SetHeaderFlags(0);
            ohWait(30);
            func_801DEF6C_9A91BC(1);
            func_801DED68_9A8FB8(1);

            for (i = 80; i > 0; i -= 8, ohWait(1)) {
                album_D_80250064_A1A2B4->data.sobj->sprite.x -= 8;
                album_D_80250108_A1A358->data.sobj->sprite.x -= 8;
                album_D_80250080_A1A2D0[6]->sprite.x -= 8;
                album_D_802500A0_A1A2F0->sprite.x -= 8;
                album_D_802500A8_A1A2F8->sprite.x -= 8;
                UIElement_SetPos(album_D_8024FFFC_A1A24C, i + 28, 197);
                func_801DF00C_9A925C(i);
            }

            func_801DF00C_9A925C(0);
            UIElement_SetPos(album_D_8024FFFC_A1A24C, 36, 197);
            ohWait(1);
            break;
        case 1:
            if (album_D_802500B8_A1A308->score.pokemonInFocus > 0) {
                album_D_8024EFE0_A19230 ^= 1;
                album_PrintPhotoDescription(album_D_8024EFE0_A19230, arg1);
            }
            break;
        case 2:
            for (i = 0; i < 80; i += 8, ohWait(1)) {
                album_D_80250064_A1A2B4->data.sobj->sprite.x += 8;
                album_D_80250108_A1A358->data.sobj->sprite.x += 8;
                album_D_80250080_A1A2D0[6]->sprite.x += 8;
                album_D_802500A0_A1A2F0->sprite.x += 8;
                album_D_802500A8_A1A2F8->sprite.x += 8;
                func_801DF00C_9A925C(i);
                UIElement_SetPos(album_D_8024FFFC_A1A24C, i + 44, 197);
            }

            album_D_80250064_A1A2B4->data.sobj->sprite.width = SCREEN_WIDTH;
            func_801DED68_9A8FB8(0);
            UIElement_SetPos(album_D_8024FFFC_A1A24C, 116, 197);
            func_801DEF1C_9A916C();
            UILayout_ShowHeaderElement(HEADER_TITLE);
            UILayout_ShowPanel(true);

            ohWait(30);

            album_D_8024FFF8_A1A248 = UIElement_Create(146, 22, 108, 16, 0);
            UIElement_SetColor(album_D_8024FFF8_A1A248, UI_FOREGROUND, 255, 255, 255, 255);
            UIElement_SetColor(album_D_8024FFF8_A1A248, UI_BACKGROUND, 218, 108, 0, 0);
            UIElement_DrawBackground(album_D_8024FFF8_A1A248);
            UIElement_SetFont(album_D_8024FFF8_A1A248, FONT_12);
            UIText_SetShadowOffset(1);
            UIText_SetSpacing(-1, 3);
            UIElement_SetTextPos(album_D_8024FFF8_A1A248, (108 - UIText_GetStringWidth("PKMN Album")) / 2, 0);
            UIElement_PrintText(album_D_8024FFF8_A1A248, "PKMN Album");
            UIElement_SetState(album_D_8024FFF8_A1A248, UI_NORMAL);
            break;
    }
}

void func_801DFB48_9A9D98(void) {
    s32 i;

    for (i = 0; i < 17; i++) {
        album_D_80250008_A1A258[i] = UIElement_Create(23, (i * 10) + 20, 60, 8, 0);
        UIElement_SetColor(album_D_80250008_A1A258[i], UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(album_D_80250008_A1A258[i], UI_BACKGROUND, 0, 0, 0, 0);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_DrawBackground(album_D_80250008_A1A258[i]);
        UIElement_SetFont(album_D_80250008_A1A258[i], FONT_8);
        UIElement_SetState(album_D_80250008_A1A258[i], UI_HIDDEN);
    }

    for (i = 0; i < 3; i++) {
        album_D_80250008_A1A258[17 + i] = UIElement_Create(23, (i * 10) + 190, 60, 8, 0);
        UIElement_SetColor(album_D_80250008_A1A258[17 + i], UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(album_D_80250008_A1A258[17 + i], UI_BACKGROUND, 0, 0, 0, 0);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_DrawBackground(album_D_80250008_A1A258[17 + i]);
        UIElement_SetFont(album_D_80250008_A1A258[17 + i], FONT_8);
        UIElement_SetState(album_D_80250008_A1A258[17 + i], UI_HIDDEN);
    }
}

void func_801DFDA0_9A9FF0(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        UIElement_Delete(album_D_80250008_A1A258[i]);
    }
}

void album_DrawCharacterGrid(s32 page) {
    s32 i;
    s32 j;
    char sp18[0x8];

    func_8036D4B4_840C64(1, 0);

    for (i = 0; i < ARRAY_COUNT(album_D_80250008_A1A258) - 1; i++) {
        UIElement_Draw(album_D_80250008_A1A258[i]);

        for (j = 0; j < 5; j++) {
            UIElement_SetTextPos(album_D_80250008_A1A258[i], j * 13, 0);
            sp18[0] = D_80208B70_9D2DC0[page][i * 10 + 2 * j];
            sp18[1] = D_80208B70_9D2DC0[page][i * 10 + 2 * j + 1];
            sp18[2] = 0;
            UIElement_PrintText(album_D_80250008_A1A258[i], sp18);
        }
    }
    func_8036D4B4_840C64(1, 1);
    UIElement_Draw(album_D_80250008_A1A258[ARRAY_COUNT(album_D_80250008_A1A258) - 1]);
    UIElement_SetTextPos(album_D_80250008_A1A258[ARRAY_COUNT(album_D_80250008_A1A258) - 1], 0, 0);
    UIElement_PrintText(album_D_80250008_A1A258[ARRAY_COUNT(album_D_80250008_A1A258) - 1], "←");
    UIElement_SetTextPos(album_D_80250008_A1A258[ARRAY_COUNT(album_D_80250008_A1A258) - 1], 13, 0);
    UIElement_PrintText(album_D_80250008_A1A258[ARRAY_COUNT(album_D_80250008_A1A258) - 1], "→");
    UIElement_SetTextPos(album_D_80250008_A1A258[ARRAY_COUNT(album_D_80250008_A1A258) - 1], 42, 0);
    UIElement_PrintText(album_D_80250008_A1A258[ARRAY_COUNT(album_D_80250008_A1A258) - 1], "End");
}

void func_801DFFEC_9AA23C(s32 show) {
    s32 i;

    if (show) {
        for (i = 0; i < 20; i++) {
            UIElement_SetState(album_D_80250008_A1A258[i], UI_NORMAL);
        }
    } else {
        for (i = 0; i < 20; i++) {
            UIElement_SetState(album_D_80250008_A1A258[i], UI_HIDDEN);
        }
    }
}

void func_801E008C_9AA2DC(s16* arg0, s32 arg1) {
    char sp20[0x40];
    s32 sp1C;

    if (arg0 == NULL) {
        return;
    }
    UIElement_Draw(album_D_8024FFFC_A1A24C);
    UIElement_SetFont(album_D_8024FFFC_A1A24C, FONT_12);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_SetTextPos(album_D_8024FFFC_A1A24C, 0, 0);
    sp1C = func_801DCD7C_9A6FCC(arg0, sp20);
    if (*arg0 != 0) {
        UIElement_PrintText(album_D_8024FFFC_A1A24C, sp20);
    }
    if (album_D_802500BE_A1A30E < 31) {
        sp1C += 116;
    } else {
        sp1C = -16;
    }
    UIElement_SetPos(album_D_8024FFF0_A1A240, sp1C, 197);
    album_D_802500A4_A1A2F4->sprite.x = sp1C;
    func_801DE9B0_9A8C00(1);
}

void album_SwitchCharacterGridPage(u32 opId) {
    UNUSED s32 pad;

    switch (opId) {
        case 0:
            album_D_802500BC_A1A30C = 0;
            func_801DFB48_9A9D98();
            album_DrawCharacterGrid(album_D_802500BC_A1A30C);
            func_801DFFEC_9AA23C(1);
            break;
        case 1:
            album_D_802500BC_A1A30C++, album_D_802500BC_A1A30C %= 3;
            album_DrawCharacterGrid(album_D_802500BC_A1A30C);
            break;
        case 2:
            album_D_802500BC_A1A30C--, album_D_802500BC_A1A30C %= 3;
            album_DrawCharacterGrid(album_D_802500BC_A1A30C);
            break;
        case 3:
            album_D_802500BC_A1A30C = 0;
            album_DrawCharacterGrid(album_D_802500BC_A1A30C);
            break;
        case 4:
            album_D_802500BC_A1A30C = 1;
            album_DrawCharacterGrid(album_D_802500BC_A1A30C);
            break;
        case 5:
            album_D_802500BC_A1A30C = 2;
            album_DrawCharacterGrid(album_D_802500BC_A1A30C);
            break;
        case 6:
            func_801DFDA0_9A9FF0();
            func_801DE9B0_9A8C00(0);
            break;
    }
}

void func_801E0300_9AA550(void) {
    s16* sp1C;

    sp1C = album_GetPhotoComment(D_80208B54_9D2DA4);
    if (sp1C == 0) {
        return;
    }
    if (album_D_802500BE_A1A30E > 0) {
        sp1C[--album_D_802500BE_A1A30E] = 0;
    }
    func_801E008C_9AA2DC(sp1C, album_D_802500BE_A1A30E);
    return;
}

void album_PressedCharacterInGrid(s32 x, s32 y) {
    s16* comment;
    char* temp_t7;

    comment = album_GetPhotoComment(D_80208B54_9D2DA4);
    if (comment == NULL) {
        return;
    }
    comment[31] = 0;

    // clear comment
    for (album_D_802500BE_A1A30E = 0; album_D_802500BE_A1A30E < 31; album_D_802500BE_A1A30E++) {
        if (comment[album_D_802500BE_A1A30E] == 0) {
            break;
        }
    }

    if (y == 19) {
        // last line
        switch (x) {
            case 0:
                auPlaySound(0x4A);
                func_801E0300_9AA550();
                return;
            case 1:
                if (album_D_802500BE_A1A30E < 31) {
                    comment[album_D_802500BE_A1A30E] = '　';
                    album_D_802500BE_A1A30E++;
                    comment[album_D_802500BE_A1A30E] = 0;
                    if (func_801DCD7C_9A6FCC(comment, 0) >= 169) {
                        auPlaySound(0x55);
                        ohWait(0xA);
                        comment[--album_D_802500BE_A1A30E] = 0;
                    } else {
                        auPlaySound(0x42);
                    }
                }
                /* fallthrough */
            default:
                func_801E008C_9AA2DC(comment, album_D_802500BE_A1A30E);
        }
        return;
    }

    if (album_D_802500BE_A1A30E < 31) {
        comment[album_D_802500BE_A1A30E] = (D_80208B70_9D2DC0[album_D_802500BC_A1A30C][y * 10 + x * 2] << 8) |
                                           D_80208B70_9D2DC0[album_D_802500BC_A1A30C][y * 10 + x * 2 + 1];
        album_D_802500BE_A1A30E++;
        comment[album_D_802500BE_A1A30E] = 0;
        if (func_801DCD7C_9A6FCC(comment, 0) >= 169) {
            auPlaySound(0x55);
            ohWait(10);
            comment[--album_D_802500BE_A1A30E] = 0;
        } else {
            auPlaySound(0x42);
        }
        func_801E008C_9AA2DC(comment, album_D_802500BE_A1A30E);
    }
}

void func_801E0678_9AA8C8(s32 arg0) {
    GObj* gobj = album_D_80250064_A1A2B4;
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
    album_D_80250060_A1A2B0 = sobj;
}

void func_801E0774_9AA9C4(void) {
    s32 sp54;
    s32 i;
    UIElement* sp4C;
    UNUSED s32 pad[7];

    func_801DF2E0_9A9530();
    func_801E0678_9AA8C8(0);
    func_801DD404_9A7654(0);
    func_801DD500_9A7750(0);
    func_801DD5A0_9A77F0(0);
    func_801DD4C0_9A7710(0);
    func_801DF120_9A9370(1);
    sp4C = UIElement_Create(124, 131, 184, 149, UI_FLAG_32BIT);
    UIElement_SetColor(sp4C, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp4C, UI_BACKGROUND, 0, 0, 0, 0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_DrawBackground(sp4C);
    UIElement_SetFont(sp4C, FONT_8);
    UIElement_SetTextPos(sp4C, 10, 0);
    func_8037519C_84894C(sp4C, "\\i%2d \\gTaken", album_GetPhotoCount());
    UIElement_SetTextPos(sp4C, 10, 9);
    func_8037519C_84894C(sp4C, "\\i%2d \\gLeft", 60 - album_GetPhotoCount());
    UIElement_SetState(sp4C, UI_HIDDEN);
    album_D_8024FFF4_A1A244 = sp4C;
    ohWait(1);
    UIElement_SetState(album_D_8024FFF4_A1A244, UI_NORMAL);

    for (i = 0; i < 10; i++) {
        sp54 = (i * 0xFF) / 10;
        func_801DD684_9A78D4(album_D_8024FFF4_A1A244, sp54);
        func_801DD404_9A7654(sp54);
        ohWait(1);
    }

    func_801DD404_9A7654(0xFF);

    ohWait(21);

    UILayout_ShowPanel(true);
    UILayout_SetHeaderFlags(0);

    ohWait(30);

    UILayout_CreateButtons(func_801E1900_9ABB50());
    UILayout_WaitPanelTransitionComplete();
    FocusMark_Show(true);
    UIText_SetPrintDelay((0, 0));
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

    FocusMark_Show(false);
    UILayout_SetHeaderFlags(0);
    UILayout_HideButtons();
    UILayout_WaitPanelTransitionComplete();

    for (i = sp1C; i >= 0; i--) {
        func_801DD684_9A78D4(album_D_8024FFF4_A1A244, (i * 0xFF) / sp1C);
        func_801DD404_9A7654((i * 0xFF) / sp1C);
        ohWait(1);
    }

    UIElement_Delete(album_D_8024FFF4_A1A244);
    func_801DD404_9A7654(0);
    func_801DF120_9A9370(0);
    UILayout_ShowPanel(false);
}

void func_801E0AF0_9AAD40(void) {
    s32 sp3C;
    s32 i;
    UIElement* sp34;

    func_801E0678_9AA8C8(1);
    func_801DE620_9A8870(2, 1);
    func_801DE7E8_9A8A38(1);
    func_801DED68_9A8FB8(0);
    func_801DD404_9A7654(0);
    func_801DD500_9A7750(0);
    func_801DD5A0_9A77F0(0);
    func_801DD4C0_9A7710(0);
    sp34 = UIElement_Create(168, 165, 60, 18, UI_FLAG_32BIT);
    UIElement_SetColor(sp34, UI_FOREGROUND, 0, 0, 0, 255);
    UIElement_SetColor(sp34, UI_BACKGROUND, 0, 0, 0, 0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_DrawBackground(sp34);
    UIElement_SetFont(sp34, FONT_12);
    UIElement_Draw(sp34);
    UIElement_PrintText(sp34, "\\i−\\g   \\i−\\g");
    UIElement_SetState(sp34, UI_HIDDEN);
    album_D_80250058_A1A2A8 = sp34;
    sp34 = UIElement_Create(146, 22, 108, 16, 0);
    UIElement_SetColor(sp34, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp34, UI_BACKGROUND, 218, 108, 0, 0);
    UIElement_DrawBackground(sp34);
    UIElement_SetFont(sp34, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    UIElement_SetTextPos(sp34, (108 - UIText_GetStringWidth("PKMN Album")) / 2, 0);
    UIElement_PrintText(sp34, "PKMN Album");
    UIElement_SetState(sp34, UI_HIDDEN);
    album_D_8024FFF8_A1A248 = sp34;
    sp34 = UIElement_Create(116, 197, 168, 12, UI_FLAG_32BIT);
    UIElement_SetColor(sp34, UI_FOREGROUND, 0, 0, 0, 255);
    UIElement_SetColor(sp34, UI_BACKGROUND, 0, 0, 0, 0);
    UIElement_DrawBackground(sp34);
    UIElement_SetFont(sp34, FONT_12);
    UIElement_SetState(sp34, UI_HIDDEN);
    album_D_8024FFFC_A1A24C = sp34;
    ohWait(1);

    for (i = 0; i < 10; i++) {
        sp3C = (i * 0xFF) / 10;
        func_801DD404_9A7654(sp3C);
        func_801DD500_9A7750(sp3C);
        func_801DD4C0_9A7710(sp3C);
        func_801DD5A0_9A77F0(sp3C);
        ohWait(1);
    }

    UILayout_ShowHeaderElement(HEADER_TITLE);
    func_801DD404_9A7654(0xFF);
    func_801DD500_9A7750(0xFF);
    func_801DD5A0_9A77F0(0xFF);
    func_801DD954_9A7BA4(func_801E191C_9ABB6C() - (func_801E191C_9ABB6C() % 6));
    ohWait(21);
    UIElement_SetState(album_D_8024FFF8_A1A248, UI_NORMAL);
    UILayout_ShowPanel(true);
    ohWait(30);
}

void func_801E0E58_9AB0A8(void) {
    s32 sp1C;
    s32 i;

    FocusMark_Show(false);
    UIElement_SetState(album_D_8024FFF8_A1A248, UI_HIDDEN);
    UILayout_SetHeaderFlags(0);
    UILayout_HideButtons();
    UILayout_WaitPanelTransitionComplete();

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
    UIElement_Delete(album_D_8024FFF8_A1A248);
    UIElement_Delete(album_D_8024FFFC_A1A24C);
    UIElement_Delete(album_D_80250058_A1A2A8);
    func_801DF120_9A9370(0);
    func_801DDC70_9A7EC0(0);
    func_801DE620_9A8870(2, 0);
    func_801DE7E8_9A8A38(0);
    func_801DED68_9A8FB8(0);
    UILayout_ShowPanel(false);
    func_801E41AC_9AE3FC();
}

void func_801E0F90_9AB1E0(void) {
    UNUSED s32 pad[1];
    int sp20;
    UNUSED s32 pad2[1];

    sp20 = 0;
    func_801DE620_9A8870(1, 1);
    func_801DE350_9A85A0(1, sp20);
    UIElement_SetState(album_D_8024FFF4_A1A244, UI_NORMAL);
    UIText_SetPrintDelay(0);
    UILayout_ShowPanel(true);
    FocusMark_Show(true);
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
    album_D_8025009C_A1A2EC = sobj;

    return gobj;
}

void func_801E1168_9AB3B8(s32 arg0) {
    UNUSED s32 pad[2];
    UIFrame* sp34;
    UIElement* sp30;

    if (arg0 != 0) {
        sp34 = UIFrame_Create();
        album_D_8025005C_A1A2AC = sp34;
        UIFrame_SetPos(sp34, 184, 320);
        UIFrame_Show(sp34, false);
        sp30 = UIElement_Create(104, 173, 192, 47, 0);
        album_D_80250000_A1A250 = sp30;
        UIElement_SetColor(sp30, UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(sp30, UI_BACKGROUND, 163, 70, 70, 255);
        UIElement_DrawBackground(sp30);
        UIElement_SetState(sp30, UI_HIDDEN);
        ohWait(1);
        UIElement_SetFont(sp30, FONT_12);
        UIText_SetShadowOffset(1);
        UIText_SetSpacing(-1, 3);
        UIElement_SetTextPos(sp30, 0, 0);
        UIElement_PrintText(sp30, "Delete this picture?\n\n");
        ohWait(1);
        UIFrame_FadeIn(sp34, FRAME_STYLE_0);
        UIElement_SetState(sp30, UI_NORMAL);
        UIText_SetPrintDelay((0, 0));
        UIElement_SetTextPos(sp30, 0, 32);
        UIElement_PrintText(sp30, "\\a Yes   \\b No");
    } else {
        UIElement_Draw(album_D_80250000_A1A250);
        UIElement_Delete(album_D_80250000_A1A250);
        UIFrame_FadeOut(album_D_8025005C_A1A2AC);
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
    sobj->sprite = album_D_8025010C_A1A35C->sprite;
    func_801DE350_9A85A0(0, 0);
    UIElement_SetState(album_D_8024FFFC_A1A24C, UI_HIDDEN);
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
    UIElement* sp64;
    UNUSED s32 pad3;
    s32 sp5C;
    UNUSED s32 pad4[12];

    sp5C = 1;
    UILayout_Init();
    FocusMark_Create();
    func_801E4084_9AE2D4();
    FocusMark_Show(false);
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

    sp64 = UIElement_Create(124, 131, 60, 18, UI_FLAG_32BIT);
    UIElement_SetColor(sp64, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp64, UI_BACKGROUND, 0, 0, 0, 0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_DrawBackground(sp64);
    UIElement_SetFont(sp64, FONT_8);
    UIElement_SetTextPos(sp64, 10, 0);
    func_8037519C_84894C(sp64, "\\i%2d \\gTaken", album_GetPhotoCount());
    UIElement_SetTextPos(sp64, 10, 9);
    func_8037519C_84894C(sp64, "\\i%2d \\gLeft", 60 - album_GetPhotoCount());
    UIElement_SetState(sp64, UI_HIDDEN);
    ohWait(1);
    album_D_8024FFF4_A1A244 = sp64;

    UIElement_SetState(album_D_8024FFF4_A1A244, UI_NORMAL);

    for (i = 0; i < 60; i++) {
        func_801DD684_9A78D4(album_D_8024FFF4_A1A244, i * 255 / 60);
        func_801DD404_9A7654(i * 255 / 60);
        ohWait(1);
    }

    func_801DD404_9A7654(255);
    UILayout_ShowPanel(true);
    UILayout_SetHeaderFlags(0);

    ohWait(30);

    UILayout_CreateButtons(func_801E1900_9ABB50());
    UILayout_WaitPanelTransitionComplete();
    FocusMark_Show(true);
    UIText_SetPrintDelay((0, 0));

    while (true) {
        func_801E37A0_9AD9F0();
        UILayout_ShowPanel(false);
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
    album_D_80250064_A1A2B4 = gobj;
    album_D_80250060_A1A2B0 = sobj;
    func_801DF1F8_9A9448();
    func_801DD404_9A7654(0);
}
