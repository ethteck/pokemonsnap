#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "app_render/particle.h"

#define VOLCANO_CMD_CHARMELEON_FELL_IN_LAVA POKEMON_CMD_28
#define VOLCANO_CMD_CHARMELEON_EVOLVE POKEMON_CMD_29
#define VOLCANO_CMD_SPAWN_MOLTRES POKEMON_CMD_30
#define VOLCANO_CMD_UNUSED_CHARIZARD POKEMON_CMD_31
#define VOLCANO_CMD_CHARIZARD_APPEARED POKEMON_CMD_32
#define VOLCANO_CMD_SMOKE_FADED POKEMON_CMD_33
#define VOLCANO_CMD_LAVA_SPLASH_START POKEMON_CMD_34
#define VOLCANO_CMD_LAVA_SPLASH_END POKEMON_CMD_35
#define VOLCANO_CMD_ANOTHER_CHARMANDER_HIT POKEMON_CMD_36
#define VOLCANO_CMD_MAGMAR_SPEW_FIRE POKEMON_CMD_37
#define VOLCANO_CMD_PESTER_BALL_IN_LAVA POKEMON_CMD_38
#define VOLCANO_CMD_GROUP3_SUMMONED POKEMON_CMD_39
#define VOLCANO_CMD_GROUP4_SUMMONED POKEMON_CMD_40
#define VOLCANO_CMD_CHARMANDER_EVOLVE POKEMON_CMD_41
#define VOLCANO_CMD_HOWLING_ENDED POKEMON_CMD_42
#define VOLCANO_CMD_HOWL_IN_RESPONSE POKEMON_CMD_43
#define VOLCANO_CMD_VULPIX_RUN POKEMON_CMD_44

extern u8 volcano_world_tex_road_pal[];
extern u8 volcano_world_tex_road_png[];
extern u8 volcano_world_tex_rocks0_pal[];
extern u8 volcano_world_tex_rocks0_png[];
extern u8 volcano_world_tex_rocks1_pal[];
extern u8 volcano_world_tex_rocks1_png[];
extern u8 volcano_world_tex_rocks2_pal[];
extern u8 volcano_world_tex_rocks2_png[];
extern u8 volcano_world_tex_rocks3_pal[];
extern u8 volcano_world_tex_rocks3_png[];
extern u8 volcano_world_tex_rocks4_pal[];
extern u8 volcano_world_tex_rocks4_png[];
extern u8 volcano_world_tex_rocks5_pal[];
extern u8 volcano_world_tex_rocks5_png[];
extern u8 volcano_world_tex_rocks6_pal[];
extern u8 volcano_world_tex_rocks6_png[];
extern u8 volcano_world_tex_lava_frame0_pal[];
extern u8 volcano_world_tex_lava_frame0_png[];
extern u8 volcano_world_tex_lava_frame1_pal[];
extern u8 volcano_world_tex_lava_frame1_png[];
extern u8 volcano_world_tex_lava_frame2_png[];
extern u8 volcano_world_tex_lava_frame3_png[];
extern u8 volcano_world_tex_water_frame0_png[];
extern u8 volcano_world_tex_water_frame1_pal[];
extern u8 volcano_world_tex_water_frame1_png[];
extern u8 volcano_world_tex_water_frame2_png[];
extern u8 volcano_world_tex_water_frame3_png[];

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
void volcano_UpdateSounds(s32, f32);
void volcano_HandleCollision(GObj*, GroundResult*);
void volcano_StartIntro(void);
void volcano_PokemonMove(GObj* obj);
void volcano_FollowPath(GObj*, f32*, f32, f32, s32);
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
GObj* smoke_spawner_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
GObj* smoke_puff_Spawn(s32, u16, WorldBlock*, WorldBlock*, ObjectSpawn*);
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
