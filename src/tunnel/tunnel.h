#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

#define TUNNEL_CMD_29 POKEMON_CMD_29
#define TUNNEL_CMD_FIRST_DIGLETT_SHOW_UP POKEMON_CMD_31
#define TUNNEL_CMD_SECOND_DIGLETT_SHOW_UP POKEMON_CMD_32
#define TUNNEL_CMD_THIRD_DIGLETT_SHOW_UP POKEMON_CMD_33
#define TUNNEL_CMD_FIRST_DUGTRIO_SHOW_UP POKEMON_CMD_34
#define TUNNEL_CMD_SECOND_DUGTRIO_SHOW_UP POKEMON_CMD_35
#define TUNNEL_CMD_THIRD_DUGTRIO_SHOW_UP POKEMON_CMD_36
#define TUNNEL_CMD_37 POKEMON_CMD_37
#define TUNNEL_CMD_38 POKEMON_CMD_38
#define TUNNEL_CMD_39 POKEMON_CMD_39
#define TUNNEL_CMD_40 POKEMON_CMD_40
#define TUNNEL_CMD_41 POKEMON_CMD_41
#define TUNNEL_CMD_42 POKEMON_CMD_42
#define TUNNEL_CMD_43 POKEMON_CMD_43
#define TUNNEL_CMD_MAGNEMITE_ATTRACT POKEMON_CMD_44
#define TUNNEL_CMD_3_MAGNEMITES_COMBINED POKEMON_CMD_45
#define TUNNEL_CMD_DELETE_MAGNEMITE POKEMON_CMD_46
#define TUNNEL_CMD_50 POKEMON_CMD_50
#define TUNNEL_CMD_51 POKEMON_CMD_51
#define TUNNEL_CMD_54 POKEMON_CMD_54
#define TUNNEL_CMD_MAGNEMITE_ZOOMED_IN POKEMON_CMD_55

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

extern Texture** magnemite_materials[];
extern UnkEC64Arg3 magnemite_model[];
extern UnkEC64Arg3 magneton_model[];
extern Texture** electrode_materials[];
extern UnkEC64Arg3 electrode_model[];
extern Texture** diglett_materials[];
extern UnkEC64Arg3 diglett_model[];
extern UnkEC64Arg3 dugtrio_model[];

extern HeightMap D_80326EE0_623FB0;
extern HeightMap D_80326EE8_623FB8;
extern WorldSetup tunnel_WorldSetup;

extern GObj* D_802EEEC4_5EBF94;
extern GObj* D_802EEEC8_5EBF98;
extern GObj* D_802EEECC_5EBF9C;
extern s32 D_802EEED0_5EBFA0;
extern GObj* D_802EE8AC_5EB97C;
extern GObj* D_802EFBA4_5ECC74;
extern GObj* D_802EFF28_5ECFF8;

void tunnel_UpdateSounds(s32, f32);
void func_802ED5C8_5EA698(void);
void func_802E2BB0_5DFC80(s32 arg0);
void tunnel_Init(void);
void tunnel_SpawnMagikarp(GObj*);
void tunnel_SpawnMagneton(GObj*);

GObj* magnemite_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* magneton_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* electrode_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* diglett_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* dugtrio_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* kakuna_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
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
void diglett_Remove(GObj*);
void dugtrio_Remove(GObj*);
void func_802EA45C_5E752C(GObj*);
void func_802EC398_5E9468(GObj*);
