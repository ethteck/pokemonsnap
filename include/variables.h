#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"

extern OSThread* __osRunningThread;
extern OSThread* __osRunQueue;
extern s32 D_80042D10;
extern s32 D_80042D18;
extern s32 gLevelID;
extern s32 gLevelNames[6];
extern s32 gPhotoCount;

// Valley code
extern animalDef extraStaryuDef;
extern animalDef extraStarmieDef;
extern randomTransition D_802ECB00;
extern animalInitData D_802EC7B8;
extern animalInitData D_802ECB2C;

extern GObj* cartGObj;

#endif
