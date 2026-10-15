#ifndef _RAINBOW_H_
#define _RAINBOW_H_

#include "common.h"
#include "world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

#define RAINBOW_CMD_28 POKEMON_CMD_28
#define RAINBOW_CMD_29 POKEMON_CMD_29
#define RAINBOW_CMD_30 POKEMON_CMD_30
#define RAINBOW_CMD_31 POKEMON_CMD_31
#define RAINBOW_CMD_32 POKEMON_CMD_32
#define RAINBOW_CMD_33 POKEMON_CMD_33
#define RAINBOW_CMD_34 POKEMON_CMD_34
#define RAINBOW_CMD_35 POKEMON_CMD_35

extern GObj* D_8034AB94_82A304;
extern GObj* D_8034AB98_82A308;
extern s32 D_8034AB9C_82A30C;
extern s32 D_8034AF38_82A6A8;

GObj* func_80348938_8280A8(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
void func_80348970_8280E0(GObj*);
void func_80348A04_828174(GObj*);
void func_80349180_8288F0(GObj*);
void func_8034935C_828ACC(GObj*);
void func_80349480_828BF0(GObj*);
void func_80349514_828C84(GObj*);
void func_8034956C_828CDC(GObj*);
void func_803495FC_828D6C(GObj*);
void func_80349654_828DC4(GObj*);
void func_803496BC_828E2C(GObj*);
void func_8034977C_828EEC(GObj*);
void func_803498A0_829010(GObj*);
void func_80349934_8290A4(GObj*);
void func_8034998C_8290FC(GObj*);
void func_80349A1C_82918C(GObj*);
void func_80349A74_8291E4(GObj*);
void func_80349ADC_82924C(GObj*);
void func_80349B98_829308(GObj*);
void func_80349DB0_829520(GObj*);
void func_80349DE8_829558(GObj*);
GObj* func_80349EB8_829628(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
GObj* func_80348FB8_828728(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
void func_80349F00_829670(GObj*);
GObj* func_8034A064_8297D4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
void func_8034A190_829900(GObj*);
GObj* func_8034A4E8_829C58(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);

void func_8034AABC_82A22C(void);

#endif
