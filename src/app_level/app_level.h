#ifndef APP_LEVEL_H
#define APP_LEVEL_H
#include "common.h"
#include "world/world.h"

#define GET_ITEM(x) ((Item*)((x)->userData))

enum ItemIds {
    ITEM_ID_POKEFLUTE   = 161,
    ITEM_ID_PESTER_BALL = 162,
    ITEM_ID_APPLE       = 163
};

enum ItemStates {
    ITEM_STATE_INVALID  = 0,
    ITEM_STATE_FLYING   = 1,
    ITEM_STATE_STILL    = 2
};

enum EndLevelReasons {
    END_LEVEL_REASON_QUIT = 1,
    END_LEVEL_REASON_FINISH = 2,
    END_LEVEL_REASON_3 = 3,
    END_LEVEL_REASON_OUT_OF_FILM = 4,
    END_LEVEL_REASON_RETRY = 6,
    END_LEVEL_REASON_IDLE_FINISHED = 7,
    END_LEVEL_REASON_IDLE_INTERRUPTED = 8
};

enum PokemonCommands {
    POKEMON_CMD_5  =  5,
    POKEMON_CMD_6  =  6,
    POKEMON_CMD_7  =  7,
    POKEMON_CMD_8  =  8,
    POKEMON_CMD_9  =  9,
    POKEMON_CMD_10 = 10,
    POKEMON_CMD_12 = 12,
    POKEMON_CMD_13 = 13,
    POKEMON_CMD_14 = 14,
    POKEMON_CMD_15 = 15,
    POKEMON_CMD_16 = 16,
    POKEMON_CMD_17 = 17,
    POKEMON_CMD_18 = 18,
    POKEMON_CMD_19 = 19,
    POKEMON_CMD_20 = 20,
    POKEMON_CMD_21 = 21,
    POKEMON_CMD_22 = 22,
    POKEMON_CMD_23 = 23,
    POKEMON_CMD_24 = 24,
    POKEMON_CMD_25 = 25,
    POKEMON_CMD_26 = 26,
    POKEMON_CMD_27 = 27,
    // command below are probably specific to level
    POKEMON_CMD_28 = 28,
    POKEMON_CMD_29 = 29,
    POKEMON_CMD_30 = 30,
    POKEMON_CMD_31 = 31,
    POKEMON_CMD_32 = 32,
    POKEMON_CMD_33 = 33,
    POKEMON_CMD_34 = 34,
    POKEMON_CMD_35 = 35,
    POKEMON_CMD_36 = 36,
    POKEMON_CMD_37 = 37,
    POKEMON_CMD_38 = 38,
    POKEMON_CMD_39 = 39,
    POKEMON_CMD_40 = 40,
    POKEMON_CMD_41 = 41,
    POKEMON_CMD_42 = 42,
    POKEMON_CMD_43 = 43,
    POKEMON_CMD_44 = 44,
    POKEMON_CMD_45 = 45,
    POKEMON_CMD_46 = 46,
    POKEMON_CMD_47 = 47,
    POKEMON_CMD_48 = 48,
    POKEMON_CMD_49 = 49,
    POKEMON_CMD_50 = 50,
    POKEMON_CMD_51 = 51,
    POKEMON_CMD_52 = 52,
    POKEMON_CMD_53 = 53,
    POKEMON_CMD_54 = 54,
    POKEMON_CMD_55 = 55,
    POKEMON_CMD_56 = 56,
    POKEMON_CMD_57 = 57,
    POKEMON_CMD_58 = 58
};

enum PlayerCommands {
    PLAYER_CMD_SHAKE_CAMERA =  3,
    PLAYER_CMD_BUMP         =  4,
    PLAYER_CMD_5            =  5,
    PLAYER_CMD_FINISH       =  6,
    PLAYER_CMD_7            =  7,
    PLAYER_CMD_8            =  8,
    PLAYER_CMD_9            =  9,
    PLAYER_CMD_10           =  10
};

enum MovementFlags {
    MOVEMENT_FLAG_ON_GROUND                         = 0x01,
    MOVEMENT_FLAG_UPDATE_TARGET_POS                 = 0x02,
    MOVEMENT_FLAG_STOP_WHEN_FLUTE_STOPPED_PLAYING   = 0x04,
    MOVEMENT_FLAG_STOP_WHEN_TURN_COMPLETED          = 0x08,
    MOVEMENT_FLAG_FIXED_HEIGHT                      = 0x10,
    MOVEMENT_FLAG_TURN_TO_PLAYER                    = 0x20,
    MOVEMENT_FLAG_TURN_AWAY                         = 0x40,
    MOVEMENT_FLAG_TURN_GRADUALLY                    = 0x80 // affects only movement along path
};

#define ITEM_CMD_REMOVE 100

#define CAMERA_CMD_BLINK 1

typedef struct Item {
    /* 0x00 */ u8 itemID;
    /* 0x01 */ u8 state;
    /* 0x02 */ u8 entryIndex;
    /* 0x03 */ u8 flags;
    /* 0x04 */ f32 restTimer;
    /* 0x08 */ Vec3f velocity;
    /* 0x14 */ Vec3f collisionVelocity;
    /* 0x20 */ Vec3f prevPos;
} Item;

extern f32 gCamTargetX;
extern f32 gCamTargetY;
extern f32 gCamTargetZ;
extern GObj* gObjPlayer;
extern s32 gDirectionIndex;
extern OMCamera* gMainCamera;
extern MovementState gMovementState;
extern u32 D_80382CF8_523108;

extern s32 LastItemId;

extern s32 Icons_NumItemsAvailable;

void Items_Init(void);
void Items_SpawnPesterBall(Vec3f*, Vec3f*);
void Items_SpawnApple(Vec3f*, Vec3f*);
void Items_PlayPokeFlute(void);
void Items_StopPokeFlute(void);
void Items_SetCustomFunctions(GObjFunc, u8, void(*)(GObj*, GroundResult*));
void Items_RemoveFlyingItems(void);
s32 Items_GetPokeFluteState(void);
void Items_Pause(void);
void Items_UnPause(void);
void Items_InitIterator(void);
GObj* Items_NextValidItem(void);
s32 Items_GetPokeFluteCmd(void);
GObj* Items_CheckObjectExists(GObj* arg0);
void Items_DeleteItem(GObj*);

u32 getProgressFlags(void);
void mainCameraSetScissor(Gfx** gfxPtr);

void Icons_SetDashEngineEnabled(s32 enabled);
void Icons_Init(void);
void Icons_ProcessButtonPress(s32 eventID);
void Icons_ProcessZoom(s32 zoomEnabled);
void Icons_Freeze(void);
void Icons_UnFreeze(void);
void Icons_Hide(void);
void Icons_Show(void);
void Icons_ProcessTakePhotoPressed(void);

s32 Pokemon_GetFlag100(GObj*);
void PokemonDetector_CleanupPokemon(GObj* pokemonObj);
void func_80357428_4F7838(GObj* arg0);

void renderPokemonModelTypeI(GObj* arg0);

#endif
