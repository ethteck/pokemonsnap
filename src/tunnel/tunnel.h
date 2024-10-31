#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

extern HeightMap D_80326EE0_623FB0;
extern HeightMap D_80326EE8_623FB8;
extern WorldSetup D_8011E6CC;

void func_802E2C70_5DFD40(s32, f32);
void func_802ED5C8_5EA698(void);
void func_802E2BB0_5DFC80(s32 arg0);
void tunnel_Init(void);
void tunnel_SpawnMagikarp(GObj*);

GObj* func_802E4AFC_5E1BCC(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802E505C_5E212C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802E5C74_5E2D44(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802E6420_5E34F0(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802E6C28_5E3CF8(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802E7620_5E46F0(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802E9390_5E6460(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EA424_5E74F4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EB818_5E88E8(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EC3BC_5E948C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EBBA8_5E8C78(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EBCE8_5E8DB8(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EBF04_5E8FD4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EAF18_5E7FE8(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_8035E0D4_4FE4E4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EA6F8_5E77C8(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EB3A8_5E8478(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EC720_5E97F0(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802ECA80_5E9B50(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802EDEC0_5EAF90(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802ECFC8_5EA098(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
void func_802E6458_5E3528(GObj*);
void func_802E6C74_5E3D44(GObj*);
void func_802EA45C_5E752C(GObj*);
void func_802EC398_5E9468(GObj*);
