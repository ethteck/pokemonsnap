#ifndef APP_LEVEL_H
#define APP_LEVEL_H
#include "common.h"

enum ItemIds {
    ITEM_ID_POKEFLUTE   = 161,
    ITEM_ID_PESTER_BALL = 162,
    ITEM_ID_APPLE       = 163
};

enum PokemonCommands {
    POKEMON_CMD_8  =  8,
    POKEMON_CMD_9  =  9,
    POKEMON_CMD_10 = 10,
    POKEMON_CMD_12 = 12,
    POKEMON_CMD_13 = 13,
    POKEMON_CMD_14 = 14,
    POKEMON_CMD_21 = 21
};

#define ITEM_CMD_REMOVE 100

extern s32 D_80382CF4_523104;

extern s32 Icons_NumItemsAvailable;

void Items_Init(void);
void Items_SpawnPesterBall(Vec3f*, Vec3f*);
void Items_SpawnApple(Vec3f*, Vec3f*);
void Items_PlayPokeFlute(void);
void Items_StopPokeFlute(void);
void Items_SetCustomFunctions(GObjFunc, u8, void(*)(GObj*, GroundResult*));
void Items_RemoveFlyingItems(void);

u32 getProgressFlags(void);
void Icons_SetDashEngineEnabled(s32 enabled);
void Icons_Init(void);
void Icons_ProcessButtonPress(s32 eventID);

#endif
