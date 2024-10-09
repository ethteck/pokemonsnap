#ifndef _POKEMON_ALBUM_H
#define _POKEMON_ALBUM_H

#include "../window/window.h"

enum AlbumPages {
    ALBUM_MAIN_PAGE = 0,
    ALBUM_PAGE_SELECT_PHOTO_TO_VIEW = 1,
    ALBUM_PAGE_VIEW_PHOTO = 2,
    ALBUM_PAGE_ARRANGE_PHOTO = 3,
    ALBUM_PAGE_PHOTO_DETAILS = 4,
    ALBUM_PAGE_EDIT_COMMENT = 5,
    ALBUM_PAGE_DELETE_PHOTO = 6,
    ALBUM_PAGE_SELECT_PHOTO_TO_DELETE = 7,
    ALBUM_PAGE_DELETE_PHOTO_FROM_ALBUM = 8
};

s32 album_GetCurrentPage(void);
s16 func_801DD0CC_9A731C(void);
void func_801DD954_9A7BA4(s32);
void func_801DDB54_9A7DA4(s32);
void func_801DDD28_9A7F78(s32, s32);
void func_801DDDF8_9A8048(s32 x, s32 y);
void func_801DE080_9A82D0(void);
void album_PrintPhotoComment(s32);
void func_801DE2BC_9A850C(s32);
void func_801DE998_9A8BE8(s32);
void func_801DEA4C_9A8C9C(s32, s32, s32);
void func_801DF744_9A9994(s32, s32);
void album_SwitchCharacterGridPage(u32);
void album_DeleteCharInComment(void);
void album_PressedCharacterInGrid(s32, s32);
void func_801E0774_9AA9C4(void);
void func_801E09A0_9AABF0(s32);
void func_801E0AF0_9AAD40(void);
void func_801E0FFC_9AB24C(s32);
void func_801E0E58_9AB0A8(void);
void album_DrawDeletePhotoPrompt(s32);
void album_DeletePhoto(s32);
UIButton* album_GetCoverButtons(void);
s32 album_GetSelectedPhoto(void);
s32 album_GetNextPhotoIndex(s32);
s32 album_GetPreviousPhotoIndex(s32);
s32 album_UpdateButtonSelection(UnkStruct800BEDF8*, s32*);
s32 album_UpdatePhotoSelection(UnkStruct800BEDF8*, s32*, s32*);
s32 album_DragPhoto(UnkStruct800BEDF8*, s32*, s32*, s32);
s32 album_EditComment(UnkStruct800BEDF8*, s32*, s32*);
s32 album_UpdateAlbumPage(void);
void album_Update(void);
void func_801E3880_9ADAD0(void);
PhotoData* album_GetAlbumPhoto(s32);
void album_DeleteAlbumPhoto(s32);
s16* album_GetPhotoComment(s32);
s32 album_GetLastPhotoIndex(void);
s32 album_GetFirstPhotoIndex(void);
s32 album_GetPhotoCount(void);
s32 func_801E3B34_9ADD84(s32);
void func_801E3F00_9AE150(void);
PhotoData* func_801E4068_9AE2B8(void);
void func_801E4084_9AE2D4(void);
void func_801E41AC_9AE3FC(void);

#endif
