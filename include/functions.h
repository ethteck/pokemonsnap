#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "ultra64.h"
#include "common_structs.h"
#include "sys/vi.h"

f32 __cosf(f32);
f32 __sinf(f32);

void dmaReadVPK(u32 rom, u32 ram);

void sendSignalToLink(s32 llIndex, s32, GObj*);

roomGFX* getCurrentRoom(void);
GObj* animalAddOne(roomGFX* roomA, roomGFX* roomB, objectSpawn* spawn, animalDef* def);
void animalAdd(roomGFX*, roomGFX*, animalDef* def);

s32 getLevelId(void);
void setLevelId(s32 levelID);
char* getLevelName(s32 levelIdx);

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
void func_80007BC4(s32*);
void func_8000BCA8(s32);
void func_800A1A50(Gfx**);
void func_80022334(void);
void func_80022374(s32, s32);
void func_80022454(s32, s32);
void func_800224DC(s32, s32, s32);
void func_800228E4(s32);
void func_80022A58(s32, s32, s32, f32, s32);
void func_80022B14(void);
void func_800A19D8(void);
void func_800A7F68(s32, s32);
UnkStruct800BEDF8* func_800AA38C(s32);
void* func_800A85E8(void (*arg0)(s32), s32 arg1, s32 arg2, s32 arg3);
void func_800AADF0(s32);
void func_800AAE28(void);
void func_800AAED0(s32);
s32 func_800AAEE8(s32);
void func_800AAF10(void);
s32 func_800BF3D4_5C274(s16);
s32 func_800BF818_5C6B8(s32);
s32 func_800BF9EC_5C88C(void);
s32 func_800BFA44_5C8E4(s32);
s32 func_800BFCA0_5CB40(s32);
void func_800E3064(void);
s32 func_801DD010(s32);

char* func_8009B9D0(s16);

void func_80356FBC_4F73CC(void);
void func_803586C0_4F8AD0(void);
void func_80359074_4F9484(void);

void func_8036406C_50447C(s32*, objectSpawn*, animalDef*);
void func_803641B8_5045C8(s32, animalDef*);
void func_8036650C_50691C(void);
void func_8036A3F8(s32*, s32);
void func_8036A5B8_83DD68(s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_8036AC6C_83E41C(s32, s32, s32, s32, s32);
void func_8036B5F0_83EDA0(s32);
void func_8036B734_83EEE4(s32);
void func_8036B870_83F020(s32, s32, s32, s32, s32, s32);
void func_8036B9EC_83F19C(s32, s32 x, s32 y);
void func_8036C898_840048(s32, char*);
void func_8036C9C0_840170(s32, char*);
void func_8036CB58_840308(s32, s32);
void func_8036D1A4_840954(s32, s32);
void func_8036D3E8_840B98(s32, s32);
void func_8036D448_840BF8(s32);
void func_8036D4A0_840C50(s32);
s32 func_8036D4F0_840CA0(char*);
void func_8036EE40_8425F0(void);
void func_8036EB80_842330(s32);
void func_8036EB8C_84233C(void (*)(s32));
void func_8036EB98(void);
void func_8036F0A0_842850(s32, s32);
void func_8036F0DC_84288C(s32, s32);
void func_8036F198_842948(s32, s32);
void func_8036F1F4_8429A4(s32, s32, s32);
void func_8036F378_842B28(s32, s32, s32);
void func_8036F684_842E34(s32, s32);
void func_8036F738_842EE8(s32, ucolor*);
s32 func_8036F78C_842F3C(void);

void func_803700A4_843854(s32);
void func_80370428_843BD8(void);
void func_803705A4_843D54(void);
void func_80370A48_8441F8(void);
void func_803713C8_844B78(s32);
void func_8037172C_844EDC(s32);
void func_803717E8_844F98(void);
GObj* func_80371D14_8454C4(void (*gfxFunc)(GObj*), s32 arg1, Sprite* sprite);
void func_80374D20_8484D0(void);
void func_80374D40_8484F0(void);
void func_80374F30_8486E0(s32, s32);

#endif
