#include "common.h"

#include "more_funcs/more_funcs.h"
#include "pokemon_album.h"

s32 D_80208C40_9D2E90 = false;

AlbumComment D_80250130_A1A380;
AlbumPhotoData D_80250170_A1A3C0;
s32 D_80250550_A1A7A0;
s32 D_80250554_A1A7A4;
AlbumPhotoData D_80250558_A1A7A8;
s32 D_80250938_A1AB88;
s32 album_PhotoCount;
s32 album_LastPhotoIndex;
s32 album_FirstPhotoIndex;

AlbumComment* get_album_comment(s32);
void set_album_comment(AlbumComment* arg0, s32 arg1);
void func_800BF9F4_5C894(s32);

void func_801E3880_9ADAD0(void) {
    D_80208C40_9D2E90 = true;
}

void album_CopyComment(const AlbumComment* src, AlbumComment* dst) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(src->text) - 1; i++) {
        dst->text[i] = src->text[i];
    }
}

PhotoData* album_GetAlbumPhoto(s32 arg0) {
    return getAlbumPhoto(arg0);
}

void func_801E3914_9ADB64(s32 index) {
    set_album_comment(&D_80250130_A1A380, index);
    func_800BF9F4_5C894(index);
    album_PhotoCount--;

    if (index == album_LastPhotoIndex) {
        while (index >= 0 && getAlbumPhoto(index) == NULL) {
            index--;
        }
        album_LastPhotoIndex = index;
    }

    if (index == album_FirstPhotoIndex) {
        while (index < 60 && getAlbumPhoto(index) == NULL) {
            index++;
        }
        album_FirstPhotoIndex = index;
    }
}

s16* album_GetPhotoComment(s32 idx) {
    if (!getAlbumPhoto(idx)) {
        return NULL;
    }

    return get_album_comment(idx)->text;
}

s32 func_801E3A80_9ADCD0(void) {
    return album_LastPhotoIndex;
}

s32 func_801E3A9C_9ADCEC(void) {
    return album_FirstPhotoIndex;
}

s32 album_GetPhotoCount(void) {
    return album_PhotoCount;
}

s32 func_801E3AD4_9ADD24(s32 arg0) {
    s32 sp1C;

    sp1C = arg0 / 6;
    if (func_801DCD20_9A6F70() == sp1C) {
        return 1;
    }
    return 0;
}

s32 func_801E3B34_9ADD84(s32 index) {
    PhotoData* photoData;

    if (D_80250170_A1A3C0.photoData.unk_04.f32 >= 0.0f) {
        auPlaySound(0x5D);
        if (getAlbumPhoto(index) != NULL) {
            D_80250558_A1A7A8.photoData = D_80250170_A1A3C0.photoData;
            album_CopyComment(&D_80250170_A1A3C0.comment, &D_80250558_A1A7A8.comment);
            D_80250170_A1A3C0.photoData = *getAlbumPhoto(index);
            album_CopyComment(get_album_comment(index), &D_80250170_A1A3C0.comment);
            func_800BF954_5C7F4(index, &D_80250558_A1A7A8.photoData, &D_80250558_A1A7A8.comment);
            func_801DE080_9A82D0();
            func_801DDB54_9A7DA4(index);
            return 1;
        } else {
            func_800BF954_5C7F4(index, &D_80250170_A1A3C0.photoData, &D_80250170_A1A3C0.comment);
            if (func_801E3AD4_9ADD24(index) != 0) {
                func_801DDB54_9A7DA4(index);
            }
            D_80250170_A1A3C0.photoData.unk_04.f32 = -1.0f;
            D_80250550_A1A7A0 = -1;
            album_PhotoCount++;
            if (album_LastPhotoIndex < index) {
                album_LastPhotoIndex = index;
            }
            if (album_FirstPhotoIndex > index) {
                album_FirstPhotoIndex = index;
            }
            return 0;
        }
    } else if (getAlbumPhoto(index) != NULL) {
        auPlaySound(0x5E);
        D_80250170_A1A3C0.photoData = *getAlbumPhoto(index);
        album_CopyComment(get_album_comment(index), &D_80250170_A1A3C0.comment);
        func_801DE080_9A82D0();
        set_album_comment(&D_80250130_A1A380, index);
        func_800BF9F4_5C894(index);
        func_801DDD28_9A7F78(index, 0);
        D_80250550_A1A7A0 = index;
        album_PhotoCount--;
        if (index == album_LastPhotoIndex) {
            while (index >= 0 && getAlbumPhoto(index) == NULL) {
                index--;
            }
            album_LastPhotoIndex = index;
        }
        if (index == album_FirstPhotoIndex) {
            while (index < 60 && getAlbumPhoto(index) == NULL) {
                index++;
            }
            album_FirstPhotoIndex = index;
        }
        return 1;
    } else {

        return 0;
    }
    return -1;
}

void func_801E3F00_9AE150(void) {
    s32 sp1C;

    sp1C = D_80250550_A1A7A0;
    if (D_80250170_A1A3C0.photoData.unk_04.f32 < 0.0f) {
        auPlaySound(0x41);
        return;
    }
    auPlaySound(0x4A);
    D_80250558_A1A7A8.photoData = D_80250170_A1A3C0.photoData;
    album_CopyComment(&D_80250170_A1A3C0.comment, &D_80250558_A1A7A8.comment);
    func_800BF954_5C7F4(sp1C, &D_80250558_A1A7A8.photoData, &D_80250558_A1A7A8.comment);
    if (func_801E3AD4_9ADD24(sp1C) != 0) {
        func_801DDB54_9A7DA4(sp1C);
    }

    D_80250170_A1A3C0.photoData.unk_04.f32 = -1.0f;
    D_80250550_A1A7A0 = -1;
    album_PhotoCount++;

    if (album_LastPhotoIndex < sp1C) {
        album_LastPhotoIndex = sp1C;
    }
    if (album_FirstPhotoIndex > sp1C) {
        album_FirstPhotoIndex = sp1C;
    }
}

PhotoData* func_801E4068_9AE2B8(void) {
    return &D_80250170_A1A3C0.photoData;
}

void func_801E4084_9AE2D4(void) {
    s32 i;
    s32 photoCount;
    s32 lastPhotoIndex;
    s32 firstPhotoIndex;
    UNUSED s32 pad;

    firstPhotoIndex = -1;

    for (i = 0, photoCount = 0; i < 60; i++) {
        if (getAlbumPhoto(i) == NULL) {

        } else {
            if (firstPhotoIndex < 0) {
                firstPhotoIndex = i;
            }
            photoCount++;
            lastPhotoIndex = i;
        }
    }
    album_FirstPhotoIndex = firstPhotoIndex;
    album_LastPhotoIndex = lastPhotoIndex;
    album_PhotoCount = photoCount;
    D_80250170_A1A3C0.photoData.unk_04.f32 = -1.0f;
    D_80250170_A1A3C0.comment.text[0] = 0;
    D_80250550_A1A7A0 = -1;
    D_80250558_A1A7A8.photoData.unk_04.f32 = -1.0f;
    D_80250558_A1A7A8.comment.text[0] = 0;
    D_80250938_A1AB88 = -1;

    for (i = 0; i < (s32) sizeof(AlbumComment); i++) {
        ((u8*) &D_80250130_A1A380)[i] = 0;
    }

    D_80208C40_9D2E90 = false;
}

void func_801E41AC_9AE3FC(void) {
    UNUSED s32 pad;

    if (D_80208C40_9D2E90) {
        D_80208C40_9D2E90 = false;
    }
}
