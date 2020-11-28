#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "ultra64.h"
#include "common_structs.h"

void loadCompressedData(u32 rom, u32 ram);

GObj* runGObjProcess(GObj*, gfxFunc* func, s8 kind, u32 priority);
void endGObjProcess(GObj*);

void sendSignalToLink(s32 llIndex, s32, GObj*);

void osStopThread(OSThread* thread);
s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, s32 flag);
void __osEnqueueAndYield(OSThread**);
void __osEnqueueThread(OSThread** queue, OSThread* thread);
void __osDispatchThread();
OSThread* __osPopThread(OSThread**);
void __osDequeueThread(OSThread** queue, OSThread* thread);
void __osSetSR(u32);
u32 __osGetSR();
f32 sqrtf(f32 f);
void osSetThreadPri(OSThread* thread, OSPri pri);
OSPri osGetThreadPri(OSThread* thread);
void __osSetCompare(u32);
s32 __osDisableInt(void);
void __osRestoreInt(s32);
void osYieldThread(void);
void osStartThread(OSThread*);

roomGFX* getCurrentRoom(void);
GObj* animalAddOne(roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn, animalDef* def);

s32 getLevelId();
void setLevelId(s32 levelID);
s8* getLevelName(s32 levelIdx);

void func_800AAED0(s32);
s32 func_800AAEE8(s32);
void func_800AAF10(void);

s32 inRange_DEBUG(u32, s32, s32, s32);
s32 bool_DEBUG(s32, s32);

void spawnStaryuAtGeo(GObj*);
void spawnStarmieAtGeo(GObj*);
void spawnKoffingSmoke(s32 gObjID, u16 id, roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn);

void updateAnimalState(GObj* obj, gfxFunc* state);
void weightedRandomStaightTransition(GObj* obj, randomTransition* nextStates);
void runPathProcess(GObj* obj, gfxFunc* func);
void setAnimalAnimation(GObj*, animationHeader*);
void forceAnimalAnimation(GObj*, animationHeader*);
void animalUVStuff(GObj*, animationHeader*, f32 start, s32 forceUpdate);
void runInteractionsAndWaitForFlags(GObj* obj, u32 flags);
void runAnimalCleanup(GObj* obj);
GObj* addAnimalAtGeo(GObj* obj, u16 AnimalID, animalDef* def);
roomGFX* setNodePosToNegRoom(GObj*);
void animalPathLoop(GObj* obj, f32 start, f32 end, f32 dt, f32 yawStep, u32 flags);
void spawnAnimalUsingDeltaHeight(s32 gObjID, u16 id, roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn, animalInitData* initData);

#endif
