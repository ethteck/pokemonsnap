#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"

#define POKEMON_FUNC(name) void name(GObj* obj) { \
    DObj* model = obj->data.dobj; \
    Mtx3Float* position = &GET_TRANSFORM(model)->pos; \
    Mtx4Float* rotation = &GET_TRANSFORM(model)->rot; \
    Pokemon* pokemon = GET_POKEMON(obj);

#define VOLCANO_CMD_28 POKEMON_CMD_28
#define VOLCANO_CMD_CHARMELEON_EVOLVE POKEMON_CMD_29
#define VOLCANO_CMD_SPAWN_MOLTRES POKEMON_CMD_30
#define VOLCANO_CMD_31 POKEMON_CMD_31
#define VOLCANO_CMD_32 POKEMON_CMD_32
#define VOLCANO_CMD_33 POKEMON_CMD_33
#define VOLCANO_CMD_34 POKEMON_CMD_34
#define VOLCANO_CMD_35 POKEMON_CMD_35
#define VOLCANO_CMD_ANOTHER_CHARMANDER_HIT POKEMON_CMD_36
#define VOLCANO_CMD_MAGMAR_SPEW_FIRE POKEMON_CMD_37
#define VOLCANO_CMD_38 POKEMON_CMD_38
#define VOLCANO_CMD_GROUP3_SUMMONED POKEMON_CMD_39
#define VOLCANO_CMD_GROUP4_SUMMONED POKEMON_CMD_40
#define VOLCANO_CMD_CHARMANDER_EVOLVE POKEMON_CMD_41
#define VOLCANO_CMD_HOWLING_ENDED POKEMON_CMD_42
#define VOLCANO_CMD_HOWL_IN_RESPONSE POKEMON_CMD_43
#define VOLCANO_CMD_VULPIX_RUN POKEMON_CMD_44

extern HeightMap volcano_heightMap;
extern WorldSetup volcano_WorldSetup;

extern u16 volcano_MagikarpHasSpawned;

extern Texture** magmar_materials[];
extern UnkEC64Arg3 magmar_model[];
extern Texture** moltres_materials[];
extern UnkEC64Arg3 moltres_model[];
extern Texture** rapidash_materials[];
extern UnkEC64Arg3 rapidash_model[];
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
void volcano_SpawnCharizard(GObj* obj);
void volcano_CreateSplashFromCharizard(GObj* obj);
void volcano_CreateSplashFromGrowlitheSpawner(GObj* obj);
bool volcano_SpawnGrowlitheOrArcanine(GObj* obj);

GObj* magmar_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* rapidash_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* charmander_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* vulpix_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* charmeleon_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* charizard_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* arcanine_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* growlithe_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DEA44_72FC44(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_802DE6B4_72F8B4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* koffing_smoke_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* evolution_controller_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* moltres_egg_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* moltres_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* volcano_magikarp_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* func_8035E0D4_4FE4E4(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* growlithe_spawner_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* lava_splash_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* volcano_smoke_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* volcano_gate_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
