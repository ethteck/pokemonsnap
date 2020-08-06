#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "ultra64.h"

/* 0x80008C28 */ GObj* runGObjProcess(GObj*, gfxFunc* func, s8 kind, u32 priority);
/* 0x80008F2C */ void endGObjProcess(GObj*);

/* 0x8000B830 */ void sendSignalToLink(s32 llIndex, s32, GObj*);

/* 0x8009B980 */ s32 getLevelId();
/* 0x8009B98C */ void setLevelId(s32 levelID);
/* 0x8009B998 */ s8* getLevelName(s32 levelIdx);

/* 0x800AAED0 */ void func_800AAED0(s32);
/* 0x800AAEE8 */ s32 func_800AAEE8(s32);
/* 0x800AAF10 */ void func_800AAF10(void);

/* 0x800E3FF0 */ s32 inRange_DEBUG(u32, s32, s32, s32);
/* 0x800E4018 */ s32 bool_DEBUG(s32, s32);

/* 0x802D2580 */ void spawnStaryuAtGeo(GObj*);
/* 0x802D25B0 */ void spawnStarmieAtGeo(GObj*);

/* 0x8035EC58 */ void updateAnimalState(GObj* obj, gfxFunc* state);
/* 0x8035ECAC */ void weightedRandomStaightTransition(GObj* obj, randomTransition* nextStates);
/* 0x8035EDF8 */ void runPathProcess(GObj* obj, gfxFunc* func);
/* 0x8035F138 */ void setAnimalAnimation(s32, animationHeader*);
/* 0x8035F15C */ void forceAnimalAnimation(s32, animationHeader*);
/* 0x8035FBF0 */ void runInteractionsAndWaitForFlags(GObj* obj, u32 flags);
/* 0x8035FD70 */ void runAnimalCleanup(GObj* obj);
/* 0x8035FE24 */ GObj* addAnimalAtGeo(GObj* obj, u32 id, animalDef* def);
/* 0x80362050 */ roomGFX* setNodePosToNegRoom(GObj*);
/* 0x803620C8 */ void animalPathLoop(GObj* obj, f32 start, f32 end, f32 dt, f32 yawStep, u32 flags);
/* 0x80362E5C */ void spawnAnimalUsingDeltaHeight(s32 gObjID, u16 id, roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn, animalInitData* initData);

#endif
