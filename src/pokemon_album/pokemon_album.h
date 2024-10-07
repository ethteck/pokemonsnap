#ifndef _POKEMON_ALBUM_H
#define _POKEMON_ALBUM_H

#include "../window/window.h"

s32 func_801DCD20_9A6F70(void);
s16 func_801DD0CC_9A731C(void);
void func_801DD954_9A7BA4(s32);
void func_801DDB54_9A7DA4(s32);
void func_801DDD28_9A7F78(s32, s32);
void func_801DDDF8_9A8048(s32 x, s32 y);
void func_801DE080_9A82D0(void);
void func_801DE1FC_9A844C(s32);
void func_801DE2BC_9A850C(s32);
void func_801DE998_9A8BE8(s32);
void func_801DEA4C_9A8C9C(s32, s32, s32);
void func_801DF744_9A9994(s32, s32);
void album_SwitchCharacterGridPage(u32);
void func_801E0300_9AA550(void);
void album_PressedCharacterInGrid(s32, s32);
void func_801E0774_9AA9C4(void);
void func_801E09A0_9AABF0(s32);
void func_801E0AF0_9AAD40(void);
void func_801E0FFC_9AB24C(s32);
void func_801E0E58_9AB0A8(void);
void func_801E1168_9AB3B8(s32);
void func_801E1320_9AB570(s32);
UIButton* func_801E1900_9ABB50(void);
s32 func_801E191C_9ABB6C(void);
s32 func_801E1938_9ABB88(s32);
s32 func_801E19C4_9ABC14(s32);
s32 func_801E1A50_9ABCA0(UnkStruct800BEDF8*, s32*);
s32 func_801E1C30_9ABE80(UnkStruct800BEDF8*, s32*, s32*);
s32 func_801E1FE4_9AC234(UnkStruct800BEDF8*, s32*, s32*, s32);
s32 func_801E2438_9AC688(UnkStruct800BEDF8*, s32*, s32*);
s32 func_801E29A8_9ACBF8(void);
void func_801E37A0_9AD9F0(void);
void func_801E3880_9ADAD0(void);
PhotoData* album_GetAlbumPhoto(s32);
void func_801E3914_9ADB64(s32);
s16* album_GetPhotoComment(s32);
s32 func_801E3A80_9ADCD0(void);
s32 func_801E3A9C_9ADCEC(void);
s32 album_GetPhotoCount(void);
s32 func_801E3B34_9ADD84(s32);
void func_801E3F00_9AE150(void);
PhotoData* func_801E4068_9AE2B8(void);
void func_801E4084_9AE2D4(void);
void func_801E41AC_9AE3FC(void);

#endif
