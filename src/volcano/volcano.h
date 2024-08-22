#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

#define VOLCANO_CMD_37 POKEMON_CMD_37

extern HeightMap D_8031D4D0_76E6D0;
extern WorldSetup volcano_WorldSetup;

extern u16 D_802E0EB4_7320B4;

extern Texture** growlithe_materials[];
extern UnkEC64Arg3 growlithe_model[];
extern Texture** charmander_materials[];
extern UnkEC64Arg3 charmander_model[];
extern Texture** charmeleon_materials[];
extern UnkEC64Arg3 charmeleon_model[];
extern Texture** charizard_materials[];
extern UnkEC64Arg3 charizard_model[];
extern Texture** vulpix_materials[];
extern UnkEC64Arg3 vulpix_model[];
extern Texture** arcanine_materials[];
extern UnkEC64Arg3 arcanine_model[];

s32 volcano_Start(s32);

void volcano_SpawnMagikarp(GObj* obj);
void volcano_func_802D6780_727980(s32 arg0);
void volcano_CharmeleonChangeBlock(GObj*, f32, f32, f32, f32, f32, f32);
void volcano_Init(void);
void func_802DFB80_730D80(s32, f32);
void volcano_HandleCollision(GObj*, GroundResult*);
void func_802E0C28_731E28(void);
void func_802D6E14_728014(GObj* obj);
void func_802D6F68_728168(GObj*, f32*, f32, f32, s32);
void func_802D6A5C_727C5C(GObj* obj);
void func_802D6CFC_727EFC(GObj* obj);
void func_802D6B2C_727D2C(GObj* obj);
bool func_802D6D6C_727F6C(GObj* obj);

GObj* volcano_magmar_Init(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802D8A5C_729C5C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802D9CB8_72AEB8(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DAA9C_72BC9C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DD214_72E414(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DD7AC_72E9AC(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DC018_72D218(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DB558_72C758(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DEA44_72FC44(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DE6B4_72F8B4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DE52C_72F72C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DED34_72FF34(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DDEC0_72F0C0(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DE34C_72F54C(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DF378_730578(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_8035E0D4_4FE4E4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DDA98_72EC98(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DF240_730440(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DFB44_730D44(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DFA38_730C38(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
