#ifndef _VARIABLES_H_
#define _VARIABLES_H_

#include "ultra64.h"
#include "common_structs.h"
#include "macros.h"

extern OSThread* __osRunningThread;
extern OSThread* __osRunQueue;
extern s32 gPhotoCount;

extern s8 sControllerIndices[MAXCONTROLLERS];

// Valley code
extern PokemonDef extraStaryuDef;
extern PokemonDef extraStarmieDef;
extern RandomState D_802ECB00_7C6090[];
extern PokemonInitData D_802EC7B8_7C5D48;
extern PokemonInitData D_802ECB2C_7C60BC;

extern GObj* cartGObj;

extern Vec3f D_800AF094;
extern Vec3f D_800AF0C4;
extern s32 D_800AF3C0;
extern s8 D_800BF051;

extern s32 D_801B0310;

extern u8 D_80369F80[];
extern GObj* D_80382D10_523120;
extern GObj* D_80382D14_523124;
extern u16 D_803B5000[SCREEN_WIDTH * SCREEN_HEIGHT];
extern u16 D_803DA800[SCREEN_WIDTH * SCREEN_HEIGHT];

extern DynamicBuffer sGeneralHeap;
extern u8 D_801ED020[];

extern Gfx D_0E000000_world[];

extern Gfx D_0E000000_beach_extra[];
extern Gfx D_0E000008_beach_extra[];
extern Gfx D_0E000010_beach_extra[];

extern Gfx D_0E000000_beach_code[];
extern Gfx D_0E000008_beach_code[];
extern Gfx D_0E000010_beach_code[];

extern Gfx D_0E000000_tunnel_assets[];

extern Gfx D_0E000000_tunnel_extra[];
extern Gfx D_0E000008_tunnel_extra[];
extern Gfx D_0E000010_tunnel_extra[];
extern Gfx D_0E000018_tunnel_extra[];
extern Gfx D_0E000020_tunnel_extra[];
extern Gfx D_0E000028_tunnel_extra[];

extern Gfx D_0E000000_tunnel_code[];
extern Gfx D_0E000008_tunnel_code[];
extern Gfx D_0E000010_tunnel_code[];
extern Gfx D_0E000018_tunnel_code[];
extern Gfx D_0E000020_tunnel_code[];
extern Gfx D_0E000028_tunnel_code[];

extern Gfx D_0E000000_cave_extra[];
extern Gfx D_0E000008_cave_extra[];
extern Gfx D_0E000010_cave_extra[];

extern Gfx D_0E000000_cave_code[];
extern Gfx D_0E000008_cave_code[];
extern Gfx D_0E000010_cave_code[];

extern Gfx D_0E000000_river_extra[];
extern Gfx D_0E000008_river_extra[];

extern Gfx D_0E000000_river_code[];
extern Gfx D_0E000008_river_code[];

extern Gfx D_0E000000_volcano_assets[];
extern Gfx D_0E000008_volcano_assets[];
extern Gfx D_0E000010_volcano_assets[];

extern Gfx D_0E000000_volcano_extra[];
extern Gfx D_0E000008_volcano_extra[];

extern Gfx D_0E000000_volcano_code[];
extern Gfx D_0E000008_volcano_code[];

extern Gfx D_0E000000_valley_extra[];
extern Gfx D_0E000008_valley_extra[];

extern Gfx D_0E000000_valley_code[];
extern Gfx D_0E000008_valley_code[];

extern Gfx D_0E000000_rainbow_extra[];

extern Gfx D_0E000000_rainbow_code[];

extern Gfx D_0E000000_pikachu_model[];
extern Gfx D_0E000008_pikachu_model[];
extern Gfx D_0E000010_pikachu_model[];

extern Gfx D_0E000000_bulbasaur_model[];
extern Gfx D_0E000000_bulbasaur_model_hd[];


#endif
