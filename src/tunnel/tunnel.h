#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

#define TUNNEL_CMD_44 POKEMON_CMD_44
#define TUNNEL_CMD_45 POKEMON_CMD_45
#define TUNNEL_CMD_46 POKEMON_CMD_46
#define TUNNEL_CMD_55 POKEMON_CMD_55

extern u8 D_8014DDE0_193F40[];
extern u8 D_8014E5E8_194748[];
extern u8 D_8014E610_194770[];
extern u8 D_8014EE18_194F78[];
extern u8 D_8014EE40_194FA0[];
extern u8 D_8014F648_1957A8[];
extern u8 D_8014F670_1957D0[];
extern u8 D_8014FE78_195FD8[];
extern u8 D_8014FEA0_196000[];
extern u8 D_801506A8_196808[];
extern u8 D_801506D0_196830[];
extern u8 D_80150ED8_197038[];
extern u8 D_80150F00_197060[];
extern u8 D_80151708_197868[];
extern u8 D_80151730_197890[];
extern u8 D_80151B38_197C98[];
extern u8 D_80151B60_197CC0[];
extern u8 D_80151F68_1980C8[];
extern u8 D_80151F90_1980F0[];
extern u8 D_80152398_1984F8[];
extern u8 D_801523C0_198520[];
extern u8 D_801527C8_198928[];
extern u8 D_801527F0_198950[];
extern u8 D_80152BF8_198D58[];
extern u8 D_80152C20_198D80[];
extern u8 D_80153028_199188[];
extern u8 D_80153050_1991B0[];
extern u8 D_80153458_1995B8[];
extern u8 D_80153480_1995E0[];
extern u8 D_80153888_1999E8[];
extern u8 D_801538A8_199A08[];
extern u8 D_80153CB0_199E10[];
extern u8 D_80153CD8_199E38[];
extern u8 D_801544E0_19A640[];
extern u8 D_801544F8_19A658[];
extern u8 D_80155560_19B6C0[];
extern u8 D_80155580_19B6E0[];
extern u8 D_80155D88_19BEE8[];
extern u8 D_80155DB0_19BF10[];
extern u8 D_801565B8_19C718[];
extern u8 D_801575C0_19D720[];
extern u8 D_801585C8_19E728[];
extern u8 D_801585F0_19E750[];
extern u8 D_80158DF8_19EF58[];

extern HeightMap D_80326EE0_623FB0;
extern HeightMap D_80326EE8_623FB8;
extern WorldSetup tunnel_WorldSetup;

void tunnel_UpdateSounds(s32, f32);
void func_802ED5C8_5EA698(void);
void func_802E2BB0_5DFC80(s32 arg0);
void tunnel_Init(void);
void tunnel_SpawnMagikarp(GObj*);
void func_802E5094_5E2164(void);

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
