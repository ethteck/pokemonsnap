#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "common_structs.h"
#include "macros.h"

extern OSThread* __osRunningThread;
extern OSThread* __osRunQueue;
extern s32 gPhotoCount;

// Valley code
extern AnimalDef extraStaryuDef;
extern AnimalDef extraStarmieDef;
extern randomTransition D_802ECB00_7C6090;
extern animalInitData D_802EC7B8_7C5D48;
extern animalInitData D_802ECB2C_7C60BC;

extern GObj* cartGObj;

extern Vec3f D_800AF094;
extern Vec3f D_800AF0C4;
extern s32 D_800AF3C0;
extern s8 D_800BF051;

extern s32 D_801B0310;

extern u8 D_80369F80[];
extern s32 D_80382D10_523120;
extern s32 D_80382D14_523124;
extern u16 D_803B5000[SCREEN_WIDTH * SCREEN_HEIGHT];
extern u16 D_803DA800[SCREEN_WIDTH * SCREEN_HEIGHT];

extern DynamicBuffer sGeneralHeap;
extern u8 D_801ED020[];

extern UnkStruct80366BA4 D_80366BA4_506FB4;

#endif
