#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "app_render/effect.h"

#define TUNNEL_CMD_28 POKEMON_CMD_28
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
#define TUNNEL_CMD_47 POKEMON_CMD_47
#define TUNNEL_CMD_48 POKEMON_CMD_48
#define TUNNEL_CMD_49 POKEMON_CMD_49
#define TUNNEL_CMD_50 POKEMON_CMD_50
#define TUNNEL_CMD_51 POKEMON_CMD_51
#define TUNNEL_CMD_52 POKEMON_CMD_52
#define TUNNEL_CMD_53 POKEMON_CMD_53
#define TUNNEL_CMD_54 POKEMON_CMD_54
#define TUNNEL_CMD_MAGNEMITE_ZOOMED_IN POKEMON_CMD_55

extern u8 tunnel_world_tex_8014DDE0[];
extern u8 tunnel_world_tex_8014E5E8[];
extern u8 tunnel_world_tex_8014E610_png[];
extern u8 tunnel_world_tex_8014EE18[];
extern u8 tunnel_world_tex_8014EE40_png[];
extern u8 tunnel_world_tex_8014F648[];
extern u8 tunnel_world_tex_8014F670_png[];
extern u8 tunnel_world_tex_8014FE78[];
extern u8 tunnel_world_tex_8014FEA0_png[];
extern u8 tunnel_world_tex_801506A8[];
extern u8 tunnel_world_tex_801506D0_png[];
extern u8 tunnel_world_tex_80150ED8[];
extern u8 tunnel_world_tex_80150F00_png[];
extern u8 tunnel_world_tex_80151708[];
extern u8 tunnel_world_tex_80151730_png[];
extern u8 tunnel_world_tex_80151B38[];
extern u8 tunnel_world_tex_80151B60_png[];
extern u8 tunnel_world_tex_80151F68[];
extern u8 tunnel_world_tex_80151F90_png[];
extern u8 tunnel_world_tex_80152398[];
extern u8 tunnel_world_tex_801523C0_png[];
extern u8 tunnel_world_tex_801527C8[];
extern u8 tunnel_world_tex_801527F0_png[];
extern u8 tunnel_world_tex_80152BF8[];
extern u8 tunnel_world_tex_80152C20_png[];
extern u8 tunnel_world_tex_80153028[];
extern u8 tunnel_world_tex_80153050_png[];
extern u8 tunnel_world_tex_80153458[];
extern u8 tunnel_world_tex_80153480_png[];
extern u8 tunnel_world_tex_80153888[];
extern u8 tunnel_world_tex_801538A8_png[];
extern u8 tunnel_world_tex_80153CB0[];
extern u8 tunnel_world_tex_80153CD8_png[];
extern u8 tunnel_world_tex_801544E0[];
extern u8 tunnel_world_tex_801544F8_png[];
extern u8 tunnel_world_tex_80155560[];
extern u8 tunnel_world_tex_80155580_png[];
extern u8 tunnel_world_tex_80155D88[];
extern u8 tunnel_world_tex_80155DB0_png[];
extern u8 tunnel_world_tex_801565B8[];
extern u8 tunnel_world_tex_801575C0[];
extern u8 tunnel_world_tex_801585C8[];
extern u8 tunnel_world_tex_801585F0_png[];
extern u8 tunnel_world_tex_80158DF8[];

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
extern u16 D_802EE10C_5EB1DC;
extern GObj* D_802EF484_5EC554;
extern GObj* D_802EF488_5EC558;

extern union {
    struct {
        u32 unk_00 : 1;
        u32 unk_01 : 1;
        u32 unk_02 : 30;
    } bits;
    u32 intval;
} D_803430E8_6401B8;

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
GObj* electabuzz_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
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
