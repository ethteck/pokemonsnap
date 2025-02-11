#include "common.h"

#include "more_funcs/more_funcs.h"
#include "pokemon_album.h"

s32 album_D_80208C40_9D2E90 = false;

AlbumComment album_EmptyComment;
AlbumPhotoData album_D_80250170_A1A3C0;
s32 album_D_80250550_A1A7A0;
s32 album_D_80250554_A1A7A4;
AlbumPhotoData album_D_80250558_A1A7A8;
s32 album_D_80250938_A1AB88;
s32 album_PhotoCount;
s32 album_LastPhotoIndex;
s32 album_FirstPhotoIndex;

AlbumComment* getAlbumComment(s32);
void setAlbumComment(AlbumComment* arg0, s32 arg1);
void removeAlbumPhoto(s32);

void func_801E3880_9ADAD0(void) {
    album_D_80208C40_9D2E90 = true;
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

void album_DeleteAlbumPhoto(s32 index) {
    setAlbumComment(&album_EmptyComment, index);
    removeAlbumPhoto(index);
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

    return getAlbumComment(idx)->text;
}

s32 album_GetLastPhotoIndex(void) {
    return album_LastPhotoIndex;
}

s32 album_GetFirstPhotoIndex(void) {
    return album_FirstPhotoIndex;
}

s32 album_GetPhotoCount(void) {
    return album_PhotoCount;
}

s32 album_IsOnCurrentPage(s32 photoId) {
    s32 page;

    page = photoId / 6;
    if (album_GetCurrentPage() == page) {
        return true;
    }
    return false;
}

s32 func_801E3B34_9ADD84(s32 index) {
    PhotoData* photoData;

    if (album_D_80250170_A1A3C0.photoData.unk_04.f32 >= 0.0f) {
        auPlaySound(0x5D);
        if (getAlbumPhoto(index) != NULL) {
            album_D_80250558_A1A7A8.photoData = album_D_80250170_A1A3C0.photoData;
            album_CopyComment(&album_D_80250170_A1A3C0.comment, &album_D_80250558_A1A7A8.comment);
            album_D_80250170_A1A3C0.photoData = *getAlbumPhoto(index);
            album_CopyComment(getAlbumComment(index), &album_D_80250170_A1A3C0.comment);
            func_800BF954_5C7F4(index, &album_D_80250558_A1A7A8.photoData, &album_D_80250558_A1A7A8.comment);
            func_801DE080_9A82D0();
            func_801DDB54_9A7DA4(index);
            return 1;
        } else {
            func_800BF954_5C7F4(index, &album_D_80250170_A1A3C0.photoData, &album_D_80250170_A1A3C0.comment);
            if (album_IsOnCurrentPage(index)) {
                func_801DDB54_9A7DA4(index);
            }
            album_D_80250170_A1A3C0.photoData.unk_04.f32 = -1.0f;
            album_D_80250550_A1A7A0 = -1;
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
        auPlaySound(SOUND_ID_94);
        album_D_80250170_A1A3C0.photoData = *getAlbumPhoto(index);
        album_CopyComment(getAlbumComment(index), &album_D_80250170_A1A3C0.comment);
        func_801DE080_9A82D0();
        setAlbumComment(&album_EmptyComment, index);
        removeAlbumPhoto(index);
        func_801DDD28_9A7F78(index, false);
        album_D_80250550_A1A7A0 = index;
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

    sp1C = album_D_80250550_A1A7A0;
    if (album_D_80250170_A1A3C0.photoData.unk_04.f32 < 0.0f) {
        auPlaySound(SOUND_ID_65);
        return;
    }
    auPlaySound(SOUND_ID_74);
    album_D_80250558_A1A7A8.photoData = album_D_80250170_A1A3C0.photoData;
    album_CopyComment(&album_D_80250170_A1A3C0.comment, &album_D_80250558_A1A7A8.comment);
    func_800BF954_5C7F4(sp1C, &album_D_80250558_A1A7A8.photoData, &album_D_80250558_A1A7A8.comment);
    if (album_IsOnCurrentPage(sp1C)) {
        func_801DDB54_9A7DA4(sp1C);
    }

    album_D_80250170_A1A3C0.photoData.unk_04.f32 = -1.0f;
    album_D_80250550_A1A7A0 = -1;
    album_PhotoCount++;

    if (album_LastPhotoIndex < sp1C) {
        album_LastPhotoIndex = sp1C;
    }
    if (album_FirstPhotoIndex > sp1C) {
        album_FirstPhotoIndex = sp1C;
    }
}

PhotoData* func_801E4068_9AE2B8(void) {
    return &album_D_80250170_A1A3C0.photoData;
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
    album_D_80250170_A1A3C0.photoData.unk_04.f32 = -1.0f;
    album_D_80250170_A1A3C0.comment.text[0] = 0;
    album_D_80250550_A1A7A0 = -1;
    album_D_80250558_A1A7A8.photoData.unk_04.f32 = -1.0f;
    album_D_80250558_A1A7A8.comment.text[0] = 0;
    album_D_80250938_A1AB88 = -1;

    for (i = 0; i < (s32) sizeof(AlbumComment); i++) {
        ((u8*) &album_EmptyComment)[i] = 0;
    }

    album_D_80208C40_9D2E90 = false;
}

void func_801E41AC_9AE3FC(void) {
    UNUSED s32 pad;

    if (album_D_80208C40_9D2E90) {
        album_D_80208C40_9D2E90 = false;
    }
}
