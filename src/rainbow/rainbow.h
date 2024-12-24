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
GObj* func_80349EB8_829628(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
GObj* func_80348FB8_828728(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
GObj* func_8034A064_8297D4(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);
GObj* func_8034A4E8_829C58(s32 objID, u16 id, WorldBlock* block, WorldBlock* blockB, ObjectSpawn* spawn);

void func_8034AABC_82A22C(void);

#endif
