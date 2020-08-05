#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "ultra64.h"

/* 0x8009B980 */ s32 getLevelId();
/* 0x8009B98C */ void setLevelId(s32 levelID);
/* 0x8009B998 */ s8* getLevelName(s32 levelIdx);
/* 0x800AAED0 */ void func_800AAED0(s32);
/* 0x800AAEE8 */ s32 func_800AAEE8(s32);
/* 0x800AAF10 */ void func_800AAF10(void);
/* 0x800E3FF0 */ s32 inRange_DEBUG(u32, s32, s32, s32);
/* 0x800E4018 */ s32 bool_DEBUG(s32, s32);

#endif
