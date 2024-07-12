#ifndef _COMMON_STRUCTS_H
#define _COMMON_STRUCTS_H

#include "ultra64.h"
#include "types.h"
#include "sys/om.h"
#include "sys/anim.h"

typedef struct {
    /* 0x00 */ s32 cmd;
    /* 0x04 */ GObjFunc state;
    /* 0x08 */ f32 value; // meaning depends on command
    /* 0x0C */ GObjFunc aux;
} InteractionHandler; // size = 0x10

typedef struct {
    /* 0x00 */ AnimationHeader* animations;
    /* 0x04 */ GObjFunc initialState;
    /* 0x08 */ s8 kind;
    /* 0x09 */ char unk_09[0x3];
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ InteractionHandler* transitionGraph;
} PokemonAnimationSetup;

typedef struct {
    /* 0x0 */ s8 r;
    /* 0x1 */ s8 g;
    /* 0x2 */ s8 b;
    /* 0x3 */ s8 a;
} color;

typedef struct {
    /* 0x0 */ u8 r;
    /* 0x1 */ u8 g;
    /* 0x2 */ u8 b;
    /* 0x3 */ u8 a;
} ucolor;

typedef struct {
    /* 0x00 */ u32 id;
    /* 0x04 */ s32 behavior;
    /* 0x08 */ Vec3f translation;
    /* 0x14 */ Vec3f euler;
    /* 0x20 */ Vec3f scale;
    /* 0x2C */ InterpData* path;
} ObjectSpawn; // size = 0x30

typedef union {
    f32 field0;
    s32 field1;
} misc;

typedef struct PokemonInitData {
    /* 0x00 */ UnkEC64Arg3* tree;
    /* 0x04 */ Texture*** textures;
    /* 0x08 */ GObjFunc fnRender;
    /* 0x0C */ PokemonAnimationSetup* animSetup;
    /* 0x10 */ Vec3f scale;
    /* 0x1C */ Vec3f scaleNumerator;
    /* 0x28 */ f32 radius;
    /* 0x2C */ u16 flags;
    /* 0x2E */ u8 matrix1;
    /* 0x2F */ u8 matrix2;
    /* 0x30 */ u8 matrix3;
    /* 0x31 */ char unk_31[0x3];
    /* 0x34 */ //f32 unk_34; // size = 0x34 in 4FE330.c
} PokemonInitData;

typedef struct PokemonTransform {
    /* 0x00 */ struct Mtx3Float pos;
    /* 0x10 */ struct Mtx4Float rot;
    /* 0x24 */ struct Mtx3Float scale;
} PokemonTransform; // size = 0x34

typedef struct PokemonTransformBase {
    /* 0x00 */ u8 kinds[3];
    /* 0x03 */ u8 pad;
    /* 0x04 */ PokemonTransform xform;
} PokemonTransformBase; // size = 0x38

typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
    /* 0x06 */ s16 flag;
    /* 0x08 */ s16 s;
    /* 0x0A */ s16 t;
    /* 0x0C */ s8 r;
    /* 0x0D */ s8 g;
    /* 0x0E */ s8 b;
    /* 0x0F */ s8 a;
} vertex;

typedef struct {
    /* 0x00 */ vertex* data;
    /* 0x04 */ vertex** tempBuffer;
    /* 0x08 */ s32 vertexCount;
    /* 0x0C */ s32 end;
    /* 0x10 */ f32 timer;
} EggStruct;

typedef struct GroundResult {
    /* 0x00 */ f32 height;
    /* 0x04 */ Vec3f normal;
    /* 0x10 */ u32 surfaceType;
} GroundResult; // size = 0x14

struct WorldBlock;
typedef struct {
    /* 0x000 */ s32 id;
    /* 0x001 */ //char unk_01[0x1];
    /* 0x002 */ //s8 appleID;
    /* 0x003 */ //char unk_03[0x5];
    /* 0x004 */ char unk_04[0x4];
    /* 0x008 */ u16 flags;
    /* 0x00A */ char unk_0A[0x6];
    /* 0x010 */ s32 tangible;
    /* 0x014 */ s32 loopCount;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ Vec3f pos1;
    /* 0x028 */ Vec3f targetPos;
    /* 0x034 */ Vec3f dirToNeighbors;
    /* 0x040 */ Vec3f euler;
    /* 0x04C */ Vec3f collisionOffset;
    /* 0x058 */ f32 collisionRadius;
    /* 0x05C */ PokemonAnimationSetup* animSetup;
    /* 0x060 */ GObjProcess* stateProc;
    /* 0x064 */ GObj* apple;
    /* 0x068 */ f32 interactionDist;
    /* 0x06C */ f32 playerDist;
    /* 0x070 */ GObj* interactionTarget;
    /* 0x074 */ struct WorldBlock* baseBlock;
    /* 0x078 */ char unk_78[0x8];
    /* 0x080 */ union AnimCmd** modelAnims;
    /* 0x084 */ union AnimCmd*** matAnims;
    /* 0x088 */ s32 behavior;
    /* 0x08C */ u32 processFlags;
    /* 0x090 */ s32 counter;
    /* 0x094 */ GObjProcess* pathProc;
    /* 0x098 */ f32 hSpeed;
    /* 0x09C */ f32 jumpVel;
    /* 0x0A0 */ f32 facingYaw;
    /* 0x0A4 */ s32 pokemonLoopTarget;
    /* 0x0A8 */ f32 lastAnimationFrame;
    /* 0x0AC */ InteractionHandler* transitionGraph;
    /* 0x0B0 */ misc miscVars[7];
    /* 0x0CC */ f32* forbiddenGround;
    /* 0x0D0 */ GroundResult currGround;
    /* 0x0E4 */ u8 unk_E4;
    /* 0x0E5 */ char unk_E5[0x3];
    /* 0x0E8 */ InterpData* path;
    /* 0x0EC */ f32 pathParam;
    /* 0x0F0 */ PokemonInitData* initData;
    /* 0x0F4 */ AnimationHeader* animHeader;
    /* 0x0F8 */ EggStruct* eggGeo;
    /* 0x0FC */ char unk_FC[0x4];
    /* 0x100 */ Vec3f collPosition;
    /* 0x10C */ s16 unk_10C;
    /* 0x10E */ s16 field_0x10e;
} Pokemon; // size = 0x110

typedef struct {
    /* 0x00 */ char unk_00[0x1];
    /* 0x01 */ s8 oob;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 flags;
    /* 0x04 */ f32 timer;
    /* 0x08 */ Vec3f vel;
    /* 0x14 */ Vec3f oldVel;
    /* 0x20 */ Vec3f prevPos;
    /* 0x2C */ char unk_2C[0x4];
} projectileData; // size = 0x30

typedef union {
    Pokemon* pokemon;
    projectileData* projectileData;
} gobjData;

typedef GObj* (*pokemonInit)(s32 arg0, u16 id, struct WorldBlock* blockA, struct WorldBlock* blockB, ObjectSpawn* spawn);

typedef struct RandomState {
    /* 0x00 */ s32 weight;
    /* 0x04 */ GObjFunc func;
} RandomState; // size = 0x8

typedef struct {
    /* 0x00 */ u32 id;
    /* 0x04 */ pokemonInit init;
    /* 0x08 */ void (*update)(GObj*, f32, f32, f32, f32, f32, f32);
    /* 0x0C */ void (*kill)(GObj*);
} PokemonDef; // size = 0x10

typedef struct UnkStruct800BEDF8 {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} UnkStruct800BEDF8; // size = 0x1C

typedef struct PlayerName {
    /* 0x00 */ char data[0x10];
} PlayerName; // size = 0x10

typedef struct PhotoDataSub {
    /* 0x00 */ s32 pokemonID : 13;
    /* 0x00 */ s32 unk_20_7 : 3; // padding?
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ Vec3f unk_08;
    /* 0x14 */ f32 unk_14;
} PhotoDataSub; // size = 0x18

typedef struct PhotoDataSub2 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ u8 unk_01; // TODO skipFrames bitfield?
    /* 0x04 */ Vec3f pos;
} PhotoDataSub2; // size == 0x10

typedef struct PhotoDataSub3 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ char unk_01[0x3];
    /* 0x04 */ char unk_04[0x8];
    /* 0x0C */ f32 unk_0C;
} PhotoDataSub3;

typedef struct PhotoData {
    /* 0x000 */ s8 levelID : 7;
                u8 unk_00_24 : 1;
                u32 unk_00_16 : 8;
    /* 0x002 */ char unk_02[0x2];
    /* 0x004 */ union {
                    s32 s32;
                    f32 f32;
                } unk_04;
    /* 0x008 */ Vec3f unk_08;
    /* 0x014 */ Vec3f unk_14;
    /* 0x020 */ PhotoDataSub unk_20[12];
    /* 0x140 */ PhotoDataSub2 unk_140[6];
    /* 0x1A0 */ PhotoDataSub3 unk_1A0[32];
} PhotoData; // size = 0x3A0

typedef struct UnkThing {
    /* 0x000 */ PhotoData main;
    /* 0x3A0 */ GObj* pokemonInFocus;
    /* 0x3A4 */ GObj* pokemonObjects[12];
} UnkThing;

typedef struct UnkCanaryScallop {
    s32 unk_0;
    s32 unk_4;
} UnkCanaryScallop; // size == 0x8

typedef struct UnkBrassLynx {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ Vec3f unk_14;
    /* 0x20 */ char unk_20[0x28];
    /* 0x48 */ DObj* unk_48;
} UnkBrassLynx;

typedef struct IdleScriptEntry {
    /* 0x00 */ u16 currentButtons;
    /* 0x02 */ u16 pressedButtons;
    /* 0x04 */ u16 heldButtons;
    /* 0x06 */ u16 releasedButtons;
    /* 0x08 */ s8 stickX;
    /* 0x09 */ s8 stickY;
} IdleScriptEntry; // size = 0xA

typedef struct IdleScript {
    /* 0x00 */ u32 dataSize;
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s32 randSeed;
    /* 0x0C */ u32 playerFlags;
    /* 0x10 */ IdleScriptEntry inputs[1];
} IdleScript; // VLA

#endif
