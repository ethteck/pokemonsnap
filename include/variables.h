#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"

/* 0x80042CC0 */ extern OSThread* __osRunningThread;
/* 0x80042CB8 */ extern OSThread* __osRunQueue;
/* 0x80042D10 */ extern s32 D_80042D10;
/* 0x80042D18 */ extern s32 D_80042D18;
/* 0x800AC0C0 */ extern s32 gLevelID;
/* 0x800AC0C4 */ extern s32 gLevelNames[6];
/* 0x800AC0E0 */ extern s32 gPhotoCount;

// Valley code
/* 0x802ECAE0 */ extern animalDef extraStaryuDef;
/* 0x802ECAF0 */ extern animalDef extraStarmieDef;
/* 0x802ECB00 */ extern randomTransition D_802ECB00;
/* 0x802EC7B8 */ extern animalInitData D_802EC7B8;
/* 0x802ECB2C */ extern animalInitData D_802ECB2C;

/* 0x803937F0 */ extern GObj* cartGObj;

#endif
