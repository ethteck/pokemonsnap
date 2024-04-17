#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "ultra64.h"
#include "common_structs.h"

f32 __cosf(f32);
f32 __sinf(f32);

void loadCompressedData(u32 rom, u32 ram);

GObj* runGObjProcess(GObj*, gfxFunc func, s8 kind, u32 priority);
void endGObjProcess(GObj*);

void sendSignalToLink(s32 llIndex, s32, GObj*);

roomGFX* getCurrentRoom(void);
GObj* animalAddOne(roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn, animalDef* def);
void animalAdd(roomGFX*, roomGFX*, animalDef* def);

s32 getLevelId();
void setLevelId(s32 levelID);
char* getLevelName(s32 levelIdx);

void func_800AAED0(s32);
s32 func_800AAEE8(s32);
void func_800AAF10(void);

s32 inRange_DEBUG(u32, s32, s32, s32);
s32 bool_DEBUG(s32, s32);

void spawnStaryuAtGeo(GObj*);
void spawnStarmieAtGeo(GObj*);
void spawnKoffingSmoke(s32 gObjID, u16 id, roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn);

void updateAnimalState(GObj* obj, gfxFunc state);
void weightedRandomStaightTransition(GObj* obj, randomTransition* nextStates);
void runPathProcess(GObj* obj, gfxFunc func);
void setAnimalAnimation(GObj*, animationHeader*);
void forceAnimalAnimation(GObj*, animationHeader*);
void animalUVStuff(GObj*, animationHeader*, f32 start, s32 forceUpdate);
void runInteractionsAndWaitForFlags(GObj* obj, u32 flags);
void runAnimalCleanup(GObj* obj);
GObj* addAnimalAtGeo(GObj* obj, u16 AnimalID, animalDef* def);
roomGFX* setNodePosToNegRoom(GObj*);
void animalPathLoop(GObj* obj, f32 start, f32 end, f32 dt, f32 yawStep, u32 flags);
void spawnAnimalUsingDeltaHeight(s32 gObjID, u16 id, roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn, animalInitData* initData);

void func_800067DC(void);
void func_80022334(void);
void func_80022B14(void);
void func_800A19D8(void);
void func_800E3064(void);
s32 func_801DD010(s32);
void func_80356FBC_4F73CC(void);
void func_803586C0_4F8AD0(void);
void func_80359074_4F9484(void);
void func_8036406C_50447C(s32*, objectSpawn*, animalDef*);
void func_803641B8_5045C8(s32, animalDef*);
void func_8036650C_50691C(void);

#endif
