#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include "ultra64.h"
#include "common_structs.h"

f32 __cosf(f32);
f32 __sinf(f32);

RoomGFX* getCurrentRoom(void);
GObj* animalAddOne(RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn, AnimalDef* def);
void animalAdd(RoomGFX*, RoomGFX*, AnimalDef* def);

s32 getLevelId(void);
void setLevelId(s32 levelID);
char* getLevelName(s32 levelIdx);

s32 inRange_DEBUG(u32, s32, s32, s32);
s32 bool_DEBUG(s32, s32);

void spawnStaryuAtGeo(GObj*);
void spawnStarmieAtGeo(GObj*);
void spawnKoffingSmoke(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn);

void updateAnimalState(GObj* obj, gfxFunc state);
void weightedRandomStaightTransition(GObj* obj, randomTransition* nextStates);
void runPathProcess(GObj* obj, gfxFunc func);
void setAnimalAnimation(GObj*, animationHeader*);
void forceAnimalAnimation(GObj*, animationHeader*);
void animalUVStuff(GObj*, animationHeader*, f32 start, s32 forceUpdate);
void runInteractionsAndWaitForFlags(GObj* obj, u32 flags);
void runAnimalCleanup(GObj* obj);
GObj* addAnimalAtGeo(GObj* obj, u16 AnimalID, AnimalDef* def);
RoomGFX* setNodePosToNegRoom(GObj*);
void animalPathLoop(GObj* obj, f32 start, f32 end, f32 dt, f32 yawStep, u32 flags);
void spawnAnimalUsingDeltaHeight(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn, animalInitData* initData);

void ren_func_800192DC(GObj* obj);

OSThread* func_80000460(void);
char* getPokemonName(s32);
s32 func_8009BB4C(s32 pkmnID);
s32 func_8009BC68(void);
void func_8009FBC4(void);
void func_8009FB50(u8 arg0, u8 arg1, u8 arg2);
void func_8009FC38(void*);
void func_800A19D8(void);
void func_800A1A50(Gfx**);
GObj* func_800A6C48(s32, s32);
void* func_800A73C0(u32 romSrcStart, u32 romSrcEnd);
s32 func_800A7460(void);
void func_800A7470(s32, s32, s32);
void func_800A7860(s32, f32);
void func_800A7F68(s32, s32);
void func_800A844C(OMCamera*, s32, s32, s32, s32);
GObj* func_800A85E8(void (*arg0)(UNK_PTR), s32 arg1, s32 arg2, s32 arg3);
GObj* func_800A9F10(void*, int, Sprite*);
UnkStruct800BEDF8* func_800AA38C(s32);
UnkStruct800BEDF8* func_800AA740(int);
void func_800AA85C(s32, s32);
void func_800AA870(s32);
void func_800AADF0(s32);
void func_800AAE28(void);
void func_800AAED0(s32);
s32 func_800AAEE8(s32);
void func_800AAF10(void);
void func_800AAF20(void);
void func_800AB918(s32);
void func_800ABB4C(u8 flags);
u8 func_800ABB68(void);
void func_800ABB94(void);
void func_800BFB90_5CA30(s32, s32);
void func_800BFC18_5CAB8(s32*, s32*);
s32 func_800BF244_5C0E4(void);
s32 func_800BF3D4_5C274(s32);
char* get_player_name(void);
void func_800BF44C_5C2EC(PlayerName*);
void* func_800BF710_5C5B0(s32);
void func_800BF780_5C620(s32);
s32 func_800BF818_5C6B8(s32);
s32 func_800BF864_5C704(void);
UnkPinkBarracuda* func_800BF8BC_5C75C(int);
s32 func_800BF9EC_5C88C(void);
s32 func_800BFA44_5C8E4(s32);
void func_800BFABC_5C95C(UnkPinkBarracuda*, s32, int, s32);
s32 func_800BFC5C_5CAFC(void);
void func_800BFC70_5CB10(s32 arg0);
s32 func_800BFCA0_5CB40(s32);
void func_800BFEBC_5CD5C(s32, s32);
s32 func_800C0290_5D130(void);
void func_800C02A0_5D140(s32);
void func_800C0314_5D1B4(s32, s32);
s32 func_800C042C_5D2CC(void);
s32 func_800C05D4_5D474(void);
void func_800C0B48_5D9E8(void);
s32 func_oaks_lab_800E1AD8(s32);
void func_800E1C5C_AA0A0C(void);
f32 func_800E219C(void);
s32 menu_new_game_entry(s32);
void func_800E3064(void);
s32 func_800E4830_A0BDC0(s32);

s32 func_credits_801DCB24(s32);
void func_801DCBF4_98C664(void);
s32 func_801DCC74_98C6E4(s32);
s32 func_801DCC74_9D35E4(s32);
s32 func_801DCCA0_9A6EF0(s32);
s32 func_801DCEBC_9FAB7C(s32);
s32 func_801DD09C_A08C8C(s32);
s32 func_801DD010(s32);
void func_801DD2D4_98CD44(s32 arg0);
GObj* func_801DD720_98D190(s32 idx);
s32 func_801E4510_993F80(void);
void func_801E4E04_994874(void);

s32 func_802BE3B0_640860(s32);

s32 func_beach_802C4740(s32);
s32 func_802C6544_79FAD4(s32);

s32 func_802D67C4_7279C4(s32);
s32 func_802D9210_6C0FF0(s32);

s32 func_802E2BB8_5DFC88(s32);

s32 func_80346EF0_826660(s32);

void func_803507E0_4F0BF0(s32);
void func_80356FBC_4F73CC(void);
void func_803586C0_4F8AD0(void);
void func_80359074_4F9484(void);
void func_8035FEEC_5002FC(GObj*, s32);

void func_8036406C_50447C(s32*, ObjectSpawn*, AnimalDef*);
void func_803641B8_5045C8(s32, AnimalDef*);
s32 func_80364718(GObj *);
s32 func_80364718_504B28(GObj *obj);
s32 func_803647BC(GObj*);
void func_8036650C_50691C(void);
void* func_8036A194_83D944(u32);
void func_8036A228_83D9D8(void*);
void func_8036A3F8_83DBA8(void*, s32);
void func_8036A3F8(u8*, s32);
void func_8036A5B8_83DD68(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_8036A8E4_83E094(s32);
s32 func_8036AC6C_83E41C(s32, s32, s32, s32, s32);
void func_8036B5F0_83EDA0(s32);
void func_8036B734_83EEE4(s32);
void func_8036B870_83F020(s32, s32, s32, s32, s32, s32);
void func_8036B9EC_83F19C(s32, s32 x, s32 y);
void func_8036C2FC_83FAAC(s32, s32, s32, s32, s32, s32, s32);
void func_8036C898_840048(s32, const char*);
void func_8036C9C0_840170(s32, char*);
void func_8036CB58_840308(s32, s32);
void func_8036CBA0_840350(s32, s32, s32);
void func_8036D1A4_840954(s32, s32);
void func_8036D248_8409F8(s32, s32, s32, s32, s32);
void func_8036D344_840AF4(s32);
void func_8036D3E8_840B98(s32, s32);
void func_8036D448_840BF8(s32);
void func_8036D4A0_840C50(s32);
void func_8036D4B4_840C64(s32, s32);
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
void func_8036FE54_843604(s32, s32);
s32 func_8036FFE0_843790(s32, s32);
void func_80370004_8437B4(s32, s32);
void func_80370038_8437E8(s32, s32);
void func_803700A4_843854(s32);
void func_80370134_8438E4(void);
void func_80370428_843BD8(void);
void func_803705A4_843D54(void);
void func_803705F0_843DA0(int);
void func_8037060C_843DBC(int, s32);
void func_80370900_8440B0(int, s32);
void func_80370990_844140(f32, int);
void func_80370A48_8441F8(void);
void func_80370C34_8443E4(void*);
void func_803713C8_844B78(s32);
void func_803713D4_844B84(int);
void func_803713EC_844B9C(int);
void func_8037172C_844EDC(s32);
char* func_803717A8_844F58(void*, s32);
void func_803717E8_844F98(void);
GObj* func_80371C68_845418(void*, s32, Sprite*);
#if !defined(M2CTX) && !defined(PERMUTER)
GObj* func_80371D14_8454C4(void (*gfxFunc)(GObj*), s32 arg1, Sprite* sprite);
#endif

SObj* func_80371DC0_845570(SObj*, Sprite*);
SObj* func_80371E68_845618(SObj*, Sprite*);
void func_80374714_847EC4(UnkPinkBarracuda*, Sprite*);
void func_80374D40_8484F0(void);
void func_80374D20_8484D0(void);
void func_80374D40_8484F0(void);
s32 func_80374F30_8486E0(s32, s32);
char* func_8037501C(char*, s32);
void func_8037519C_84894C(s32, char*, ...);
void func_80375284_848A34(int);

void func_8037005C_84380C(s32, s32);

void func_80362EE0_5032F0(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn, animalInitData* initData);
void func_80362DC4_5031D4(s32 gObjID, u16 id, RoomGFX* roomA, RoomGFX* roomB, ObjectSpawn* spawn, animalInitData* initData);

// void qsort(void* base, s32 nitems, u32 size, s32 (*compar)(const void*, const void*));

#endif
