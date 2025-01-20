#ifndef _APP_RENDER_H_
#define _APP_RENDER_H_

#include "common.h"

extern s32 photo_PokemonIndexes[12];

extern struct WorldSetup D_800F5DA0;

extern struct WorldSetup D_8012A0E8;
extern struct WorldSetup D_8012AC90;

PhotoData* func_8009BC74(void);
// s32 func_8009BCC4(PhotoData*);
f32 func_8009BDDC(s16, s8);
struct ScoreData* func_800A0EA4(GObj*, PhotoData*, u16*, s32, s32, u16*);
void getBackgroundColor(u8* r, u8* g, u8* b);
void func_800A7F40(f32 arg0, f32 arg1, s32 arg2, f32 arg3);
void func_800A7918(s32, f32);

#endif
