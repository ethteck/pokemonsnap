#include "common.h"
#include "window/window.h"
#include "pokemon_album.h"
#include "photo_check/photo_check.h"

typedef struct AlbumPhoto {
    /* 0x00 */ GObj* gObj;
    /* 0x04 */ SObj* sObj;
    /* 0x08 */ u8 isShown;
} AlbumPhoto; // size: 0xC

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
s32 D_80208B58_9D2DA8[6] = { PokemonID_1004, PokemonID_1010, PokemonID_1018, PokemonID_1022, PokemonID_KOFFING_SMOKE, PokemonID_1035 };
char* album_CharGrids[] = {
    "ＡＢＣＤＥ"
    "ＦＧＨＩＪ"
    "ＫＬＭＮＯ"
    "ＰＱＲＳＴ"
    "ＵＶＷＸＹ"
    "Ｚａｂｃｄ"
    "ｅｆｇｈｉ"
    "ｊｋｌｍｎ"
    "ｏｐｑｒｓ"
    "ｔｕｖｗｘ"
    "ｙｚ０１２"
    "３４５６７"
    "８９†‡¶"
    "〜！？＠＃"
    "％＆＊（）"
    "＿＋＝ー’"
    "”；：／＄"
    "．，＜＞♂"
    "♀［］ε　",
};
bool album_IsEditingComment = true;
s32 album_CursorAlpha = 10;
s32 album_CursorAlphaRate = 5;
s32 album_LetterAlpha = 10;
s32 album_LetterAlphaRate = 5;
bool D_80208B88_9D2DD8 = false;

s32 album_D_8024EFE0_A19230;
u8 album_unused[0x1000];
bool album_D_8024FFE8_A1A238;
s32 album_D_8024FFEC_A1A23C;
UIElement* album_UiCommentActiveLetter;
UIElement* album_UiAlbumStats;
UIElement* album_UiAlbumHeader;
UIElement* album_UiPhotoComment;
UIElement* album_D_80250000_A1A250;
UIElement* album_UiRows[20];
UIElement* album_UiPageNumber;
UIFrame* album_D_8025005C_A1A2AC;
SObj* album_BackgroundSObj;
GObj* album_BackgroundGObj;
SObj* album_CoverTitleSObj[4];
GObj* album_CoverTitleGObj;
s32 album_D_8025007C_A1A2CC;
SObj* album_PhotoCorners[7];
SObj* album_D_8025009C_A1A2EC;
SObj* album_CommentBackground;
SObj* album_Cursor;
SObj* album_PhotoDescBackground;
GObj* album_DraggedPhotoGObj;
SObj* album_DraggedPhotoSObj;
s32 album_AlbumPage;
Unk803A6C18* album_D_802500B8_A1A308;
u8 album_CharGridId;
s16 album_CommentCursorPos;
AlbumPhoto album_Photos[6];
GObj* album_D_80250108_A1A358;
SObj* album_D_8025010C_A1A35C;
s32 album_D_80250110_A1A360;

s32 album_GetCurrentPage(void) {
    return album_AlbumPage;
}

u8 func_801DD2FC(void) {
    return album_CharGridId;
}

s32 func_801DCD3C_9A6F8C(s32 idx) {
    if (idx < 0 || idx >= ARRAY_COUNT(D_80208B58_9D2DA8)) {
        return -1;
    }
    return D_80208B58_9D2DA8[idx];
}

s32 album_GetCommentTextWidth(s16* wideStr, char* dst);

GLOBAL_ASM(
glabel album_GetCommentTextWidth
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
);

void album_BlinkCursor(GObj* obj) {
    while (album_IsEditingComment) {
        album_CursorAlpha += album_CursorAlphaRate;
        if (album_CursorAlpha > 255) {
            album_CursorAlpha = 255;
            album_CursorAlphaRate = -5;
        }
        if (album_CursorAlpha < 120) {
            album_CursorAlpha = 120;
            album_CursorAlphaRate = 5;
        }
        album_Cursor->sprite.alpha = album_CursorAlpha;
        ohWait(1);
    }

    omDeleteGObj(NULL);
    ohWait(99);
}

void album_BlinkLetter(GObj* obj) {
    while (album_IsEditingComment) {
        album_LetterAlpha += album_LetterAlphaRate;
        if (album_LetterAlpha > 255) {
            album_LetterAlpha = 255;
            album_LetterAlphaRate = -5;
        }
        if (album_LetterAlpha < 120) {
            album_LetterAlpha = 120;
            album_LetterAlphaRate = 5;
        }

        UIElement_SetSpriteColor(album_UiCommentActiveLetter, 255, 255, 255, (album_LetterAlpha > 160) ? 255 : 0);
        ohWait(1);
    }

    omDeleteGObj(NULL);
    ohWait(99);
}

s16 album_GetCursorPos(void) {
    return album_CommentCursorPos;
}

char* func_801DD0E8_9A7338(bool* arg0) {
    if (*arg0) {
        return "−−−−−";
    } else {
        *arg0 = true;
        return "ダメじゃ！"; // No way!
    }
}

char* album_GetPhotoParam(Unk803A6C18* arg0, u32 paramId) {
    switch (paramId) {
        case 0:
            D_80208B88_9D2DD8 = false;
            return "スペシャル"; // special
        case 1:
            return func_8037501C_8487CC("%5d", arg0->score.specialID);
        case 2:
            return "おおきさ"; // size
        case 3:
            if (arg0->score.proximityScore != 0) {
                return func_8037501C_8487CC("%5d", arg0->score.proximityScore);
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 4:
            return "まるみえ"; // "full view" (view?)
        case 5:
            if (arg0->score.completenessScore != 0) {
                return func_8037501C_8487CC("%5.2f", (s32) (f32) (arg0->score.completenessScore / 10000));
            } else {
                return func_801DD0E8_9A7338(&D_80208B88_9D2DD8);
            }
        case 6:
            return "コメント"; // comment
        case 7:
            if (arg0->score.poseID != 0) {
                return func_8037501C_8487CC("%5d", arg0->score.poseID);
            } else {
                return "　　　なし";
            }
        case 8:
            if (arg0->score.poseID != 0) {
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

void album_SetCoverColor(s32 color) {
    s32 i;

    album_BackgroundSObj->sprite.red = color;
    album_BackgroundSObj->sprite.green = color;
    album_BackgroundSObj->sprite.blue = color;

    for (i = 0; i < ARRAY_COUNT(album_CoverTitleSObj); i++) {
        if (album_CoverTitleSObj[i]) {
            album_CoverTitleSObj[i]->sprite.red = album_CoverTitleSObj[i]->sprite.green = album_CoverTitleSObj[i]->sprite.blue = color;
        }
    }
}

void album_SetCommentBackgroundColor(u32 color) {
    album_CommentBackground->sprite.red = album_CommentBackground->sprite.green = album_CommentBackground->sprite.blue = color;
}

void func_801DD500_9A7750(s32 color) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(album_Photos); i++) {
        album_Photos[i].gObj->data.sobj->sprite.red = album_Photos[i].gObj->data.sobj->sprite.green = album_Photos[i].gObj->data.sobj->sprite.blue = color;
    }
}

void func_801DD5A0_9A77F0(s32 color) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(album_PhotoCorners); i++) {
        if (album_PhotoCorners[i] != NULL) {
            album_PhotoCorners[i]->sprite.red = album_PhotoCorners[i]->sprite.green = album_PhotoCorners[i]->sprite.blue = color;
        }
    }
}

void func_801DD638_9A7888(s32 color) {
    album_D_80250108_A1A358->data.sobj->sprite.red = album_D_80250108_A1A358->data.sobj->sprite.green = album_D_80250108_A1A358->data.sobj->sprite.blue = color;
}

void func_801DD684_9A78D4(UIElement* el, s32 color) {
    UIElement_SetSpriteColor(el, color, color, color, 255);
}

GObj* album_CreatePhoto(s32 index) {
    GObj* gobj;
    SObj* sobj;
    s32 x;
    s32 y;
    Bitmap* bitmap;
    u8* dest;
    u8* src;

    x = ((index % 3) * 66) + 104;
    y = ((index / 3) * 55) + 53;

    gobj = func_80371C68_845418(NULL, LINK_6, &D_802005B8_9CA808);
    sobj = gobj->data.sobj;
    sobj->sprite.x = x;
    sobj->sprite.y = y;
    album_Photos[index].gObj = gobj;

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
    album_Photos[index].sObj = sobj;

    bitmap = (Bitmap*) UIMem_Allocate(sizeof(Bitmap));
    dest = (u8*) UIMem_Allocate(4056);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (x = 4056; x > 0; src++, dest++, x--) {
        *dest = *src;
    }

    return gobj;
}

void album_CreatePhotos(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(album_Photos); i++) {
        album_CreatePhoto(i);
    }
}

void album_DrawAlbumPage(s32 firstPhotoOnPage) {
    s32 i;
    char strPageNum[0x20];

    album_AlbumPage = firstPhotoOnPage / 6;

    for (i = 0; i < ARRAY_COUNT(album_Photos); firstPhotoOnPage++, i++) {
        if (func_80374714_847EC4(album_GetAlbumPhoto(firstPhotoOnPage), &album_Photos[i].sObj->sprite)) {
            album_Photos[i].gObj->data.sobj->sprite.attr |= SP_HIDDEN;
            album_Photos[i].isShown = false;
        } else {
            album_Photos[i].gObj->data.sobj->sprite.attr &= ~SP_HIDDEN;
            album_Photos[i].isShown = true;
        }
    }

    UIElement_Draw(album_UiPageNumber);
    UIText_SetPrintDelay(0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_SetTextPos(album_UiPageNumber, 0, 0);
    UIElement_PrintText(album_UiPageNumber, "  \\i−\\g      \\i−\\g  ");
    sprintf(strPageNum, "%d", album_AlbumPage + 1);
    UIElement_SetTextPos(album_UiPageNumber, 30 - (UIText_GetStringWidth(strPageNum) / 2), 0);
    UIElement_PrintText(album_UiPageNumber, strPageNum);
    UIElement_SetState(album_UiPageNumber, UI_NORMAL);
}

void func_801DDB54_9A7DA4(s32 arg0) {
    s32 idx;

    idx = arg0 % ARRAY_COUNT(album_Photos);
    if (func_80374714_847EC4(album_GetAlbumPhoto(arg0), &album_Photos[idx].sObj->sprite)) {
        album_Photos[idx].gObj->data.sobj->sprite.attr |= SP_HIDDEN;
        album_Photos[idx].isShown = 0;
    } else {
        album_Photos[idx].gObj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        album_Photos[idx].isShown = 1;
    }
}

void func_801DDC70_9A7EC0(bool arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(album_Photos); i++) {
        if (arg0 && album_Photos[i].isShown != NULL) {
            album_Photos[i].gObj->data.sobj->sprite.attr &= ~SP_HIDDEN;
        } else {
            album_Photos[i].gObj->data.sobj->sprite.attr |= SP_HIDDEN;
        }
    }
}

void func_801DDD28_9A7F78(s32 arg0, bool arg1) {
    if (arg1) {
        album_Photos[arg0 % ARRAY_COUNT(album_Photos)].gObj->data.sobj->sprite.attr =
            album_Photos[arg0 % ARRAY_COUNT(album_Photos)].gObj->data.sobj->sprite.attr & ~SP_HIDDEN;
    } else {
        album_Photos[arg0 % ARRAY_COUNT(album_Photos)].gObj->data.sobj->sprite.attr =
            album_Photos[arg0 % ARRAY_COUNT(album_Photos)].gObj->data.sobj->sprite.attr | SP_HIDDEN;
    }
}

void func_801DDDF8_9A8048(s32 x, s32 y) {
    SObj* sobj = album_DraggedPhotoGObj->data.sobj;

    if (x < 0 || y < 0) {
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

    gobj = func_80371C68_845418(NULL, LINK_6, &D_802005B8_9CA808);
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
    album_DraggedPhotoGObj = gobj;
    album_DraggedPhotoSObj = sobj;

    bitmap = (Bitmap*) UIMem_Allocate(sizeof(Bitmap));
    dest = (u8*) UIMem_Allocate(4056);
    src = sobj->sprite.bitmap->buf;
    *bitmap = *sobj->sprite.bitmap;
    bitmap->buf = dest;
    sobj->sprite.bitmap = bitmap;
    for (i = 4056; i > 0; src++, dest++, i--) {
        *dest = *src;
    }

    return gobj;
}

void func_801DE03C_9A828C(bool arg0) {
    // BUG: this pointer is never assigned
    SObj* sp4;

    if (arg0) {
        sp4->sprite.attr &= ~SP_HIDDEN;
    } else {
        sp4->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DE080_9A82D0(void) {
    func_80374714_847EC4(func_801E4068_9AE2B8(), &album_DraggedPhotoSObj->sprite);
}

void* func_801DE0C8_9A8318(void) {
    GObj* gobj;
    SObj* sobj;
    UNUSED s32 pad[2];

    gobj = func_80371C68_845418(NULL, LINK_6, &D_80200058_9CA2A8);
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

void album_PrintPhotoComment(s32 photoIndex) {
    char comment[0x40];

    UIElement_Draw(album_UiPhotoComment);
    if (album_GetPhotoComment(photoIndex) == NULL) {
        return;
    }
    UIElement_SetFont(album_UiPhotoComment, FONT_12);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_SetTextPos(album_UiPhotoComment, 0, 0);
    album_GetCommentTextWidth(album_GetPhotoComment(photoIndex), comment);
    UIElement_PrintText(album_UiPhotoComment, comment);
    UIElement_SetState(album_UiPhotoComment, UI_NORMAL);
}

void func_801DE2BC_9A850C(s32 photoId) {
    if (D_80208B54_9D2DA4 != photoId) {
        D_80208B54_9D2DA4 = photoId;
    }
    func_80374714_847EC4(album_GetAlbumPhoto(photoId), &album_D_8025010C_A1A35C->sprite);
    UIElement_SetState(album_UiPhotoComment, UI_HIDDEN);
    album_PrintPhotoComment(photoId);
    UIElement_SetState(album_UiPhotoComment, UI_NORMAL);
}

void func_801DE350_9A85A0(bool arg0, s32 arg1) {
    if (arg0) {
        UIElement_SetState(album_UiPageNumber, UI_HIDDEN);
        func_801DE2BC_9A850C(arg1);
        auPlaySound(SOUND_ID_71);
        album_D_80250108_A1A358->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        album_D_80250108_A1A358->data.sobj->sprite.attr |= SP_HIDDEN;
    }
}

GObj* album_CreatePhotoCorners(void) {
    GObj* gobj;
    SObj* sobj;
    s32 j;
    s32 i;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            gobj = func_80371C68_845418(NULL, LINK_6, &D_801F3108_9BD358);
            sobj = gobj->data.sobj;
            album_PhotoCorners[(i * 3) + j] = sobj;
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

    gobj = func_80371C68_845418(NULL, LINK_6, &D_801F3108_9BD358);
    sobj = gobj->data.sobj;
    album_PhotoCorners[6] = sobj;
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
            for (i = 0; i < ARRAY_COUNT(album_PhotoCorners) - 1; i++) {
                album_PhotoCorners[i]->sprite.attr |= SP_HIDDEN;
            }
            album_PhotoCorners[ARRAY_COUNT(album_PhotoCorners) - 1]->sprite.attr &= ~SP_HIDDEN;
        } else {
            for (i = 0; i < ARRAY_COUNT(album_PhotoCorners) - 1; i++) {
                album_PhotoCorners[i]->sprite.attr &= ~SP_HIDDEN;
            }
            album_PhotoCorners[ARRAY_COUNT(album_PhotoCorners) - 1]->sprite.attr |= SP_HIDDEN;
        }
    } else {
        if (arg0 & 1) {
            album_PhotoCorners[ARRAY_COUNT(album_PhotoCorners) - 1]->sprite.attr |= SP_HIDDEN;
        }
        if (arg0 & 2) {
            for (i = 0; i < ARRAY_COUNT(album_PhotoCorners) - 1; i++) {
                album_PhotoCorners[i]->sprite.attr |= SP_HIDDEN;
            }
        }
    }
}

void* album_CreateCommentBackground(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, LINK_6, &D_801F6B50_9C0DA0);
    sobj = gobj->data.sobj;

    sobj->sprite.x = 101;
    sobj->sprite.y = 186;
    sobj->sprite.attr |= SP_HIDDEN;
    album_CommentBackground = sobj;

    return gobj;
}

void album_ShowCommentBackground(bool show) {
    if (show) {
        album_CommentBackground->sprite.attr &= ~SP_HIDDEN;
    } else {
        album_CommentBackground->sprite.attr |= SP_HIDDEN;
    }
}

GObj* album_CreateCommentTextBox(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, LINK_6, &D_801FFC80_9C9ED0);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 115;
    sobj->sprite.y = 196;
    sobj->sprite.attr |= SP_HIDDEN | SP_TRANSPARENT;
    album_Cursor = sobj;
    album_IsEditingComment = true;
    func_800A85E8(album_BlinkCursor, LINK_6, DL_LINK_0, NULL);

    album_UiCommentActiveLetter = UIElement_Create(116, 197, 12, 12, UI_FLAG_32BIT);
    UIElement_SetColor(album_UiCommentActiveLetter, UI_FOREGROUND, 255, 15, 25, 255);
    UIElement_SetColor(album_UiCommentActiveLetter, UI_BACKGROUND, 0, 0, 0, 0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_DrawBackground(album_UiCommentActiveLetter);
    UIElement_SetFont(album_UiCommentActiveLetter, FONT_12);
    UIElement_SetState(album_UiCommentActiveLetter, UI_HIDDEN);
    func_800A85E8(album_BlinkLetter, LINK_6, DL_LINK_0, NULL);

    return gobj;
}

void func_801DE998_9A8BE8(bool arg0) {
    album_D_8024FFE8_A1A238 = arg0;
}

void func_801DE9B0_9A8C00(bool arg0) {
    if (arg0) {
        if (album_D_8024FFE8_A1A238) {
            UIElement_SetState(album_UiCommentActiveLetter, UI_NORMAL);
        } else {
            album_Cursor->sprite.attr &= ~SP_HIDDEN;
        }
    } else {
        UIElement_SetState(album_UiCommentActiveLetter, UI_HIDDEN);
        album_Cursor->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DEA4C_9A8C9C(bool arg0, s32 column, s32 row) {
    s16* sp64;
    char sp60[0x4];
    char sp20[0x40];
    s32 x;

    sp64 = album_GetPhotoComment(D_80208B54_9D2DA4);
    if (sp64 == NULL) {
        return;
    }
    sp64[31] = 0;

    if (arg0) {
        for (album_CommentCursorPos = 0; album_CommentCursorPos < 31; album_CommentCursorPos++) {
            if (sp64[album_CommentCursorPos] == 0) {
                break;
            }
        }
    }

    if (album_D_8024FFE8_A1A238) {
        sp60[0] = album_CharGrids[album_CharGridId][row * 5 + column];
        sp60[1] = 0;
        sp60[2] = 0;
        UIElement_Draw(album_UiCommentActiveLetter);
        UIElement_PrintText(album_UiCommentActiveLetter, sp60);
        if (sp60[0] == ' ') {
            UIElement_SetState(album_UiCommentActiveLetter, UI_HIDDEN);
            album_Cursor->sprite.attr &= ~SP_HIDDEN;
        } else {
            UIElement_SetState(album_UiCommentActiveLetter, UI_NORMAL);
            album_Cursor->sprite.attr |= SP_HIDDEN;
        }
    } else {
        sp60[0] = sp60[1] = sp60[2] = 0;
        UIElement_SetState(album_UiCommentActiveLetter, UI_HIDDEN);
        album_Cursor->sprite.attr &= ~SP_HIDDEN;
    }

    UIText_SetFont(0xC);
    x = album_GetCommentTextWidth(sp64, sp20);
    if ((album_CommentCursorPos < 31) || 168 - UIText_GetStringWidth(sp60) < x) {
        x += 116;
    } else {
        x = -16;
    }
    UIElement_SetPos(album_UiCommentActiveLetter, x, 197);
    album_Cursor->sprite.x = x;
}

void* album_CreatePhotoDescBackground(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, LINK_6, &D_801FB1D0_9C5420);
    sobj = gobj->data.sobj;

    sobj->sprite.x = 308;
    sobj->sprite.y = 50;
    sobj->sprite.attr |= SP_HIDDEN;
    album_PhotoDescBackground = sobj;

    return gobj;
}

void album_ShowPhotoDescBackground(bool show) {
    if (show) {
        album_PhotoDescBackground->sprite.attr &= ~SP_HIDDEN;
    } else {
        album_PhotoDescBackground->sprite.attr |= SP_HIDDEN;
    }
}

void func_801DEDB0_9A9000(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        album_UiRows[i] = UIElement_Create(234, ((i / 2) * 36) + ((i % 2) * 12) + 67, 60, 8, UI_FLAG_32BIT);
        UIElement_SetColor(album_UiRows[i], UI_FOREGROUND, 0, 0, 0, 255);
        UIElement_SetColor(album_UiRows[i], UI_BACKGROUND, 0, 0, 0, 0);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_DrawBackground(album_UiRows[i]);
        UIElement_SetFont(album_UiRows[i], FONT_8);
        UIElement_SetState(album_UiRows[i], UI_HIDDEN);
    }
}

void func_801DEF1C_9A916C(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        UIElement_Delete(album_UiRows[i]);
    }
}

void func_801DEF6C_9A91BC(bool arg0) {
    s32 i;

    if (arg0) {
        for (i = 0; i < 6; i++) {
            UIElement_SetState(album_UiRows[i], UI_NORMAL);
        }
    } else {
        for (i = 0; i < 6; i++) {
            UIElement_SetState(album_UiRows[i], UI_HIDDEN);
        }
    }
}

void func_801DF00C_9A925C(s32 arg0) {
    s32 i;

    for (i = 0; i < 6; i += 2) {
        UIElement_SetPos(album_UiRows[i], arg0 + 234, ((i / 2) * 36) + 67);
        UIElement_SetPos(album_UiRows[i + 1], arg0 + 234, ((i / 2) * 36) + 79);
    }
}

void func_801DF0D0_9A9320(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        UIElement_Draw(album_UiRows[i]);
    }
}

void func_801DF120_9A9370(bool arg0) {
    s32 i;

    if (arg0) {
        album_BackgroundGObj->data.sobj->sprite.attr &= ~SP_HIDDEN;
    } else {
        album_BackgroundGObj->data.sobj->sprite.attr |= SP_HIDDEN;
    }

    for (i = ARRAY_COUNT(album_CoverTitleSObj) + 1; i >= 0; i--) {
        if (album_CoverTitleSObj[i] != NULL) {
            if (arg0) {
                album_CoverTitleSObj[i]->sprite.attr &= ~SP_HIDDEN;
            } else {
                album_CoverTitleSObj[i]->sprite.attr |= SP_HIDDEN;
            }
        }
    }
}

void album_CreateCoverUI(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371D14_8454C4(NULL, LINK_6, &D_801F2D28_9BCF78);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 106;
    sobj->sprite.y = 52;
    album_CoverTitleSObj[0] = sobj;

    sobj = func_80371DC0_845570(sobj, &D_801ED550_9B77A0);
    sobj->sprite.x = 110;
    sobj->sprite.y = 108;
    sobj->sprite.alpha = 128;
    sobj->sprite.attr |= SP_TRANSPARENT;
    album_CoverTitleSObj[1] = sobj;
    album_CoverTitleSObj[2] = NULL;
    album_CoverTitleSObj[3] = NULL;
    album_CoverTitleGObj = gobj;
}

void func_801DF2E0_9A9530(void) {
    UNUSED s32 pad;
    SObj* sobj;

    sobj = album_CoverTitleSObj[0];
    sobj->sprite = D_801F2D28_9BCF78;
    sobj->sprite.x = 106;
    sobj->sprite.y = 52;
    sobj->unk_58 = NULL;
    sobj->unk_5C = NULL;

    sobj = album_CoverTitleSObj[1];
    sobj->sprite = D_801ED550_9B77A0;
    sobj->sprite.x = 110;
    sobj->sprite.y = 108;
    sobj->sprite.alpha = 128;
    sobj->sprite.attr |= SP_TRANSPARENT;

    album_CoverTitleSObj[2] = NULL;
    album_CoverTitleSObj[3] = NULL;

    // what is going on here?
    album_CoverTitleSObj[4] = NULL;
    album_CoverTitleSObj[5] = NULL;
}

void album_PrintPhotoDescription(s32 descType, s32 entryIndex) {
    Unk803A6C18* sp4C;
    s32 i;
    char str[32];

    sp4C = func_8037452C_847CDC(album_GetAlbumPhoto(entryIndex));
    if (descType == 0) {
        func_801DF0D0_9A9320();

        UIText_SetFont(FONT_8);
        UIElement_SetTextPos(album_UiRows[0], 0, 0);
        UIElement_PrintText(album_UiRows[0], "Course");

        sprintf(str, "%s", getLevelName(getAlbumPhoto(entryIndex)->levelID));
        UIElement_SetTextPos(album_UiRows[1], 60 - UIText_GetStringWidth(str), 0);
        func_8037519C_84894C(album_UiRows[1], "%s", str);

        UIElement_SetTextPos(album_UiRows[2], 0, 0);
        UIElement_PrintText(album_UiRows[2], "Photo by");

        sprintf(str, "%s", getPlayerName());
        UIElement_SetTextPos(album_UiRows[3], 60 - UIText_GetStringWidth(str), 0);
        func_8037519C_84894C(album_UiRows[3], "%s", str);

        UIElement_SetTextPos(album_UiRows[4], 0, 0);
        UIElement_PrintText(album_UiRows[4], "Focus");

        sprintf(str, "%s", (sp4C->score.pokemonInFocus > 0 && sp4C->score.pokemonInFocus <= POKEDEX_MAX) ? getPokemonName(sp4C->score.pokemonInFocus) : "−−−−−");
        UIElement_SetTextPos(album_UiRows[5], 60 - UIText_GetStringWidth(str), 0);
        func_8037519C_84894C(album_UiRows[5], "%s", str);
    } else {
        func_801DF0D0_9A9320();

        for (i = 0; i < 6; i++) {
            UIElement_SetTextPos(album_UiRows[i], 0, 0);
            if (i == 13) {
                func_8037519C_84894C(album_UiRows[i], "%sひき", album_GetPhotoParam(sp4C, i));
            } else {
                UIElement_PrintText(album_UiRows[i], album_GetPhotoParam(sp4C, i));
            }
        }
    }
}

void func_801DF744_9A9994(s32 arg0, s32 arg1) {
    s32 i;

    switch (arg0) {
        case 0:
            album_D_8024EFE0_A19230 = 0;
            album_BackgroundGObj->data.sobj->sprite.width = 400;
            FocusMark_Show(false);
            UILayout_HideButtons();
            UILayout_WaitPanelTransitionComplete();
            UILayout_ShowPanel(false);
            UIElement_Delete(album_UiAlbumHeader);
            func_801DEDB0_9A9000();
            album_PrintPhotoDescription(album_D_8024EFE0_A19230, arg1);
            UILayout_SetHeaderFlags(0);
            ohWait(30);
            func_801DEF6C_9A91BC(true);
            album_ShowPhotoDescBackground(true);

            for (i = 80; i > 0; i -= 8, ohWait(1)) {
                album_BackgroundGObj->data.sobj->sprite.x -= 8;
                album_D_80250108_A1A358->data.sobj->sprite.x -= 8;
                album_PhotoCorners[6]->sprite.x -= 8;
                album_CommentBackground->sprite.x -= 8;
                album_PhotoDescBackground->sprite.x -= 8;
                UIElement_SetPos(album_UiPhotoComment, i + 28, 197);
                func_801DF00C_9A925C(i);
            }

            func_801DF00C_9A925C(0);
            UIElement_SetPos(album_UiPhotoComment, 36, 197);
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
                album_BackgroundGObj->data.sobj->sprite.x += 8;
                album_D_80250108_A1A358->data.sobj->sprite.x += 8;
                album_PhotoCorners[6]->sprite.x += 8;
                album_CommentBackground->sprite.x += 8;
                album_PhotoDescBackground->sprite.x += 8;
                func_801DF00C_9A925C(i);
                UIElement_SetPos(album_UiPhotoComment, i + 44, 197);
            }

            album_BackgroundGObj->data.sobj->sprite.width = SCREEN_WIDTH;
            album_ShowPhotoDescBackground(false);
            UIElement_SetPos(album_UiPhotoComment, 116, 197);
            func_801DEF1C_9A916C();
            UILayout_ShowHeaderElement(HEADER_TITLE);
            UILayout_ShowPanel(true);

            ohWait(30);

            album_UiAlbumHeader = UIElement_Create(146, 22, 108, 16, 0);
            UIElement_SetColor(album_UiAlbumHeader, UI_FOREGROUND, 255, 255, 255, 255);
            UIElement_SetColor(album_UiAlbumHeader, UI_BACKGROUND, 218, 108, 0, 0);
            UIElement_DrawBackground(album_UiAlbumHeader);
            UIElement_SetFont(album_UiAlbumHeader, FONT_12);
            UIText_SetShadowOffset(1);
            UIText_SetSpacing(-1, 3);
            UIElement_SetTextPos(album_UiAlbumHeader, (108 - UIText_GetStringWidth("PKMN Album")) / 2, 0);
            UIElement_PrintText(album_UiAlbumHeader, "PKMN Album");
            UIElement_SetState(album_UiAlbumHeader, UI_NORMAL);
            break;
    }
}

void func_801DFB48_9A9D98(void) {
    s32 i;

    for (i = 0; i < 17; i++) {
        album_UiRows[i] = UIElement_Create(23, (i * 10) + 20, 60, 8, 0);
        UIElement_SetColor(album_UiRows[i], UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(album_UiRows[i], UI_BACKGROUND, 0, 0, 0, 0);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_DrawBackground(album_UiRows[i]);
        UIElement_SetFont(album_UiRows[i], FONT_8);
        UIElement_SetState(album_UiRows[i], UI_HIDDEN);
    }

    for (i = 0; i < 3; i++) {
        album_UiRows[17 + i] = UIElement_Create(23, (17 + i) * 10 + 20, 60, 8, 0);
        UIElement_SetColor(album_UiRows[17 + i], UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(album_UiRows[17 + i], UI_BACKGROUND, 0, 0, 0, 0);
        UIText_SetShadowOffset(0);
        UIText_SetSpacing(0, 4);
        UIElement_DrawBackground(album_UiRows[17 + i]);
        UIElement_SetFont(album_UiRows[17 + i], FONT_8);
        UIElement_SetState(album_UiRows[17 + i], UI_HIDDEN);
    }
}

void func_801DFDA0_9A9FF0(void) {
    s32 i;

    for (i = 0; i < 20; i++) {
        UIElement_Delete(album_UiRows[i]);
    }
}

void album_DrawCharacterGrid(s32 page) {
    s32 i;
    s32 j;
    char sp18[0x8];

    func_8036D4B4_840C64(1, 0);

    for (i = 0; i < 0x13; i++) {
        UIElement_Draw(album_UiRows[i]);

        for (j = 0; j < 5; j++) {
            if (!album_CharGrids[page][i * 5 + j]) {
                break;
            }
            sp18[0] = album_CharGrids[page][i * 5 + j];
            sp18[1] = 0;
            sp18[2] = 0;
            UIElement_SetTextPos(album_UiRows[i], j * 13, 0);
            UIElement_PrintText(album_UiRows[i], sp18);
        }

        if (!album_CharGrids[page][i * 5 + j]) {
            break;
        }
    }
    func_8036D4B4_840C64(1, 1);
    UIElement_Draw(album_UiRows[ARRAY_COUNT(album_UiRows) - 1]);
    UIElement_SetTextPos(album_UiRows[ARRAY_COUNT(album_UiRows) - 1], 0, 0);
    UIElement_PrintText(album_UiRows[ARRAY_COUNT(album_UiRows) - 1], "←");
    UIElement_SetTextPos(album_UiRows[ARRAY_COUNT(album_UiRows) - 1], 13, 0);
    UIElement_PrintText(album_UiRows[ARRAY_COUNT(album_UiRows) - 1], "←");
    UIElement_SetTextPos(album_UiRows[ARRAY_COUNT(album_UiRows) - 1], 26, 0);
    UIElement_PrintText(album_UiRows[ARRAY_COUNT(album_UiRows) - 1], "→");
    UIElement_SetTextPos(album_UiRows[ARRAY_COUNT(album_UiRows) - 1], 43, 0);
    UIElement_PrintText(album_UiRows[ARRAY_COUNT(album_UiRows) - 1], "End");
}

void func_801DFFEC_9AA23C(s32 show) {
    s32 i;

    if (show) {
        for (i = 0; i < 20; i++) {
            UIElement_SetState(album_UiRows[i], UI_NORMAL);
        }
    } else {
        for (i = 0; i < 20; i++) {
            UIElement_SetState(album_UiRows[i], UI_HIDDEN);
        }
    }
}

void func_801E008C_9AA2DC(s16* comment, s32 arg1) {
    char sp20[0x40];
    s32 width;

    if (comment == NULL) {
        return;
    }
    UIElement_Draw(album_UiPhotoComment);
    UIElement_SetFont(album_UiPhotoComment, FONT_12);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_SetTextPos(album_UiPhotoComment, 0, 0);
    width = album_GetCommentTextWidth(comment, sp20);
    if (*comment != 0) {
        UIElement_PrintText(album_UiPhotoComment, sp20);
    }
    if (album_CommentCursorPos < 31) {
        width += 116;
    } else {
        width = -16;
    }
    UIElement_SetPos(album_UiCommentActiveLetter, width, 197);
    album_Cursor->sprite.x = width;
    func_801DE9B0_9A8C00(true);
}

void album_SwitchCharacterGridPage(u32 opId) {
    s32 pad;

    switch (opId) {
        case 0:
            album_CharGridId = 0;
            func_801DFB48_9A9D98();
            album_DrawCharacterGrid(album_CharGridId);
            func_801DFFEC_9AA23C(1);
            break;
        case 1:
            album_CharGridId++, album_CharGridId %= 2;
            album_DrawCharacterGrid(album_CharGridId);
            break;
        case 6:
            func_801DFDA0_9A9FF0();
            func_801DE9B0_9A8C00(false);
            break;
    }
}

void album_DeleteCharInComment(void) {
    s16* comment;

    comment = album_GetPhotoComment(D_80208B54_9D2DA4);
    if (comment == 0) {
        return;
    }
    if (album_CommentCursorPos > 0) {
        comment[--album_CommentCursorPos] = 0;
    }
    func_801E008C_9AA2DC(comment, album_CommentCursorPos);
    return;
}

void album_PressedCharacterInGrid(s32 column, s32 row) {
    s16* comment;
    char* temp_t7;

    comment = album_GetPhotoComment(D_80208B54_9D2DA4);
    if (comment == NULL) {
        return;
    }
    comment[31] = 0;

    for (album_CommentCursorPos = 0; album_CommentCursorPos < 31; album_CommentCursorPos++) {
        if (comment[album_CommentCursorPos] == 0) {
            break;
        }
    }

    if (row == 19) {
        // last row
        switch (column) {
            case 0:
                // left
                auPlaySound(SOUND_ID_74);
                album_DeleteCharInComment();
                return;
            case 1:
                // right
                if (album_CommentCursorPos < 31) {
                    comment[album_CommentCursorPos] = ' ';
                    album_CommentCursorPos++;
                    comment[album_CommentCursorPos] = 0;
                    if (album_GetCommentTextWidth(comment, 0) >= 169) {
                        auPlaySound(SOUND_ID_85);
                        ohWait(10);
                        comment[--album_CommentCursorPos] = 0;
                    } else {
                        auPlaySound(SOUND_ID_66);
                    }
                }
                func_801E008C_9AA2DC(comment, album_CommentCursorPos);
                return;
            case 2:
                album_SwitchCharacterGridPage(1);
                auPlaySound(0x42);
                return;
            default:
                func_801E008C_9AA2DC(comment, album_CommentCursorPos);
                return;
        }
    }

    if (album_CommentCursorPos < 31) {
        // add character to comment
        comment[album_CommentCursorPos++] = album_CharGrids[album_CharGridId][row * 5 + column];

        comment[album_CommentCursorPos] = 0;
        if (album_GetCommentTextWidth(comment, 0) >= 169) {
            auPlaySound(SOUND_ID_85);
            ohWait(10);
            comment[--album_CommentCursorPos] = 0;
        } else {
            auPlaySound(SOUND_ID_66);
        }
        func_801E008C_9AA2DC(comment, album_CommentCursorPos);
    }
}

void album_SetBackgroundTexture(bool arg0) {
    GObj* gobj = album_BackgroundGObj;
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
    album_BackgroundSObj = sobj;
}

void album_CreateCoverPage(void) {
    s32 sp54;
    s32 i;
    UIElement* sp4C;
    s32 pad[7];
    int sp30;

    func_801DF2E0_9A9530();
    album_SetBackgroundTexture(false);
    album_SetCoverColor(0);
    func_801DD500_9A7750(0);
    func_801DD5A0_9A77F0(0);
    album_SetCommentBackgroundColor(0);
    func_801DF120_9A9370(true);

    sp4C = UIElement_Create(124, 131, 184, 149, UI_FLAG_32BIT);
    UIElement_SetColor(sp4C, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(sp4C, UI_BACKGROUND, 0, 0, 0, 0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_DrawBackground(sp4C);
    sp30 = 10;
    UIElement_SetFont(sp4C, FONT_8);
    UIElement_SetTextPos(sp4C, sp30, 0);
    func_8037519C_84894C(sp4C, "\\i%2d \\gTaken", album_GetPhotoCount());
    UIElement_SetTextPos(sp4C, sp30, 9);
    func_8037519C_84894C(sp4C, "\\i%2d \\gLeft", 60 - album_GetPhotoCount());
    UIElement_SetState(sp4C, UI_HIDDEN);
    album_UiAlbumStats = sp4C;

    ohWait(1);
    UIElement_SetState(album_UiAlbumStats, UI_NORMAL);

    for (i = 0; i < 10; i++) {
        sp54 = i * 255 / 10;
        func_801DD684_9A78D4(album_UiAlbumStats, sp54);
        album_SetCoverColor(sp54);
        ohWait(1);
    }

    album_SetCoverColor(255);

    ohWait(21);

    UILayout_ShowPanel(true);
    UILayout_SetHeaderFlags(0);

    ohWait(30);

    UILayout_CreateButtons(album_GetCoverButtons());
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
        func_801DD684_9A78D4(album_UiAlbumStats, (i * 255) / sp1C);
        album_SetCoverColor((i * 255) / sp1C);
        ohWait(1);
    }

    UIElement_Delete(album_UiAlbumStats);
    album_SetCoverColor(0);
    func_801DF120_9A9370(false);
    UILayout_ShowPanel(false);
}

void func_801E0AF0_9AAD40(void) {
    s32 color;
    s32 i;
    UIElement* el;

    album_SetBackgroundTexture(true);
    func_801DE620_9A8870(2, 1);
    album_ShowCommentBackground(true);
    album_ShowPhotoDescBackground(false);
    album_SetCoverColor(0);
    func_801DD500_9A7750(0);
    func_801DD5A0_9A77F0(0);
    album_SetCommentBackgroundColor(0);

    el = UIElement_Create(168, 165, 60, 18, UI_FLAG_32BIT);
    UIElement_SetColor(el, UI_FOREGROUND, 0, 0, 0, 255);
    UIElement_SetColor(el, UI_BACKGROUND, 0, 0, 0, 0);
    UIText_SetShadowOffset(0);
    UIText_SetSpacing(0, 4);
    UIElement_DrawBackground(el);
    UIElement_SetFont(el, FONT_12);
    UIElement_Draw(el);
    UIElement_PrintText(el, "\\i−\\g   \\i−\\g");
    UIElement_SetState(el, UI_HIDDEN);
    album_UiPageNumber = el;

    el = UIElement_Create(146, 22, 108, 16, 0);
    UIElement_SetColor(el, UI_FOREGROUND, 255, 255, 255, 255);
    UIElement_SetColor(el, UI_BACKGROUND, 218, 108, 0, 0);
    UIElement_DrawBackground(el);
    UIElement_SetFont(el, FONT_12);
    UIText_SetShadowOffset(1);
    UIText_SetSpacing(-1, 3);
    UIElement_SetTextPos(el, (108 - UIText_GetStringWidth("PKMN Album")) / 2, 0);
    UIElement_PrintText(el, "PKMN Album");
    UIElement_SetState(el, UI_HIDDEN);
    album_UiAlbumHeader = el;

    el = UIElement_Create(116, 197, 168, 12, UI_FLAG_32BIT);
    UIElement_SetColor(el, UI_FOREGROUND, 0, 0, 0, 255);
    UIElement_SetColor(el, UI_BACKGROUND, 0, 0, 0, 0);
    UIElement_DrawBackground(el);
    UIElement_SetFont(el, FONT_12);
    UIElement_SetState(el, UI_HIDDEN);
    album_UiPhotoComment = el;

    ohWait(1);

    for (i = 0; i < 10; i++) {
        color = (i * 255) / 10;
        album_SetCoverColor(color);
        func_801DD500_9A7750(color);
        album_SetCommentBackgroundColor(color);
        func_801DD5A0_9A77F0(color);
        ohWait(1);
    }

    UILayout_ShowHeaderElement(HEADER_TITLE);
    album_SetCoverColor(255);
    func_801DD500_9A7750(255);
    func_801DD5A0_9A77F0(255);
    album_DrawAlbumPage(album_GetSelectedPhoto() - (album_GetSelectedPhoto() % 6));
    ohWait(21);
    UIElement_SetState(album_UiAlbumHeader, UI_NORMAL);
    UILayout_ShowPanel(true);
    ohWait(30);
}

void func_801E0E58_9AB0A8(void) {
    s32 sp1C;
    s32 i;

    FocusMark_Show(false);
    UIElement_SetState(album_UiAlbumHeader, UI_HIDDEN);
    UILayout_SetHeaderFlags(0);
    UILayout_HideButtons();
    UILayout_WaitPanelTransitionComplete();

    for (i = 10; i >= 0; i--) {
        sp1C = (i * 255) / 10;
        album_SetCoverColor(sp1C);
        func_801DD500_9A7750(sp1C);
        func_801DD5A0_9A77F0(sp1C);
        album_SetCommentBackgroundColor(sp1C);
        ohWait(1);
    }

    album_SetCoverColor(0);
    func_801DD500_9A7750(0);
    func_801DD5A0_9A77F0(0);
    album_SetCommentBackgroundColor(0);
    ohWait(1);
    UIElement_Delete(album_UiAlbumHeader);
    UIElement_Delete(album_UiPhotoComment);
    UIElement_Delete(album_UiPageNumber);
    func_801DF120_9A9370(false);
    func_801DDC70_9A7EC0(false);
    func_801DE620_9A8870(2, 0);
    album_ShowCommentBackground(false);
    album_ShowPhotoDescBackground(false);
    UILayout_ShowPanel(false);
    func_801E41AC_9AE3FC();
}

void func_801E0F90_9AB1E0(void) {
    UNUSED s32 pad[1];
    int sp20;
    UNUSED s32 pad2[1];

    sp20 = 0;
    func_801DE620_9A8870(1, 1);
    func_801DE350_9A85A0(true, sp20);
    UIElement_SetState(album_UiAlbumStats, UI_NORMAL);
    UIText_SetPrintDelay(0);
    UILayout_ShowPanel(true);
    FocusMark_Show(true);
    ohWait(21);
}

void func_801E0FFC_9AB24C(s32 arg0) {
    switch (arg0) {
        case 1:
            func_801DE350_9A85A0(false, 0);
            func_801DE620_9A8870(2, 1);
            album_DrawAlbumPage(album_GetSelectedPhoto() - (album_GetSelectedPhoto() % 6));
            break;
        case 2:
            func_801DE620_9A8870(1, 1);
            func_801DDC70_9A7EC0(false);
            func_801DE350_9A85A0(true, album_GetSelectedPhoto());
            break;
    }
}

GObj* func_801E10D0_9AB320(void) {
    GObj* gobj;
    SObj* sobj;

    gobj = func_80371C68_845418(NULL, LINK_6, &D_801FFA10_9C9C60);
    sobj = gobj->data.sobj;
    sobj->sprite.x = 127;
    sobj->sprite.y = 53;
    sobj->sprite.scalex = 0.0f;
    sobj->sprite.scaley = 0.0f;
    sobj->sprite.attr |= SP_HIDDEN;
    album_D_8025009C_A1A2EC = sobj;

    return gobj;
}

void album_DrawDeletePhotoPrompt(bool show) {
    UNUSED s32 pad[2];
    UIFrame* frame;
    UIElement* message;

    if (show) {
        frame = UIFrame_Create();
        album_D_8025005C_A1A2AC = frame;
        UIFrame_SetPos(frame, 184, 320);
        UIFrame_Show(frame, false);

        message = UIElement_Create(104, 173, 192, 47, 0);
        album_D_80250000_A1A250 = message;
        UIElement_SetColor(message, UI_FOREGROUND, 255, 255, 255, 255);
        UIElement_SetColor(message, UI_BACKGROUND, 163, 70, 70, 255);
        UIElement_DrawBackground(message);
        UIElement_SetState(message, UI_HIDDEN);
        ohWait(1);
        UIElement_SetFont(message, FONT_12);
        UIText_SetShadowOffset(1);
        UIText_SetSpacing(-1, 3);
        UIElement_SetTextPos(message, 0, 0);
        UIElement_PrintText(message, "Delete this picture?\n\n");
        ohWait(1);
        UIFrame_FadeIn(frame, FRAME_STYLE_0);
        UIElement_SetState(message, UI_NORMAL);
        UIText_SetPrintDelay((0, 0));
        UIElement_SetTextPos(message, 0, 32);
        UIElement_PrintText(message, "\\a Yes   \\b No");
    } else {
        UIElement_Draw(album_D_80250000_A1A250);
        UIElement_Delete(album_D_80250000_A1A250);
        UIFrame_FadeOut(album_D_8025005C_A1A2AC);
        ohWait(21);
    }
}

void album_DeletePhoto(s32 photoId) {
    GObj* gobj;
    SObj* sobj;
    s32 i;

    gobj = func_80371C68_845418(NULL, LINK_6, &D_80200058_9CA2A8);
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

    func_801DE350_9A85A0(false, 0);
    UIElement_SetState(album_UiPhotoComment, UI_HIDDEN);
    auPlaySound(SOUND_ID_94);

    for (i = 0; i < 13; i++, ohWait(1)) {
        gobj->data.sobj->sprite.y--;
        gobj->data.sobj->sprite.x++;
    }

    ohWait(45);

    auPlaySound(SOUND_ID_74);

    for (i = 0; gobj->data.sobj->sprite.y < 270; i++, ohWait(1)) {
        gobj->data.sobj->sprite.y += (i * 2) + 10;
    }

    omDeleteGObj(gobj);
    if (D_80208B54_9D2DA4 == photoId) {
        D_80208B54_9D2DA4 = -1;
    }
    album_DeleteAlbumPhoto(photoId);
    func_801E0FFC_9AB24C(1);
    return;
}

void album_CreateAlbumUI(GObj* arg0) {
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
    album_CreateCommentBackground();
    album_CreateCommentTextBox();
    album_CreatePhotoDescBackground();
    func_801E10D0_9AB320();
    album_CreatePhotos();
    func_801DDC70_9A7EC0(false);
    func_801DD500_9A7750(0);
    func_801DE0C8_9A8318();
    album_CreatePhotoCorners();
    func_801DDE64_9A80B4();
    func_801DE03C_9A828C(false);

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
    album_UiAlbumStats = sp64;

    UIElement_SetState(album_UiAlbumStats, UI_NORMAL);

    for (i = 0; i < 60; i++) {
        func_801DD684_9A78D4(album_UiAlbumStats, i * 255 / 60);
        album_SetCoverColor(i * 255 / 60);
        ohWait(1);
    }

    album_SetCoverColor(255);
    UILayout_ShowPanel(true);
    UILayout_SetHeaderFlags(0);

    ohWait(30);

    UILayout_CreateButtons(album_GetCoverButtons());
    UILayout_WaitPanelTransitionComplete();
    FocusMark_Show(true);
    UIText_SetPrintDelay((0, 0));

    while (true) {
        album_Update();
        UILayout_ShowPanel(false);
        func_80374D20_8484D0();
        album_IsEditingComment = false;
        func_800AADF0(SCENE_OAKS_LAB_2);
        ohWait(1);
    }
}

void album_CreateUI(void) {
    GObj* bgObj;
    SObj* bgSObj;

    func_800A85E8(album_CreateAlbumUI, LINK_6, DL_LINK_0, NULL);
    bgObj = func_80371D14_8454C4(NULL, LINK_6, &D_801E4518_9AE768);
    bgSObj = bgObj->data.sobj;
    bgSObj->sprite.width = SCREEN_WIDTH;
    bgSObj->sprite.height = SCREEN_HEIGHT;
    bgSObj->sprite.istep = 0;
    album_BackgroundGObj = bgObj;
    album_BackgroundSObj = bgSObj;
    album_CreateCoverUI();
    album_SetCoverColor(0);
}
