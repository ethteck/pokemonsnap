#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "common_structs.h"

extern OSThread* __osRunningThread;
extern OSThread* __osRunQueue;
extern s32 gLevelID;
extern char* gLevelNames[6];
extern s32 gPhotoCount;

// Valley code
extern AnimalDef extraStaryuDef;
extern AnimalDef extraStarmieDef;
extern randomTransition D_802ECB00;
extern animalInitData D_802EC7B8;
extern animalInitData D_802ECB2C;

extern GObj* cartGObj;

extern Vec3f D_800AF094;
extern Vec3f D_800AF0C4;
extern s32 D_800AF3C0;

#endif
