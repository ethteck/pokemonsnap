#ifndef _COMMON_STRUCTS_H
#define _COMMON_STRUCTS_H

#include "ultra64.h"
#include "types.h"
#include "sys/om.h"

typedef f32 quartic[5];

typedef enum geoPayloadType {
    translate=18,
    axisDEG=19,
    axisDEG_translate=20,
    eulerDEG_XYZ=21,
    eulerDEG_translate=22,
    axis=23,
    axis_translate=24,
    axis_translate_scale=25,
    eulerTAB=26,
    eulerTAB_translate=27,
    eulerTAB_translate_scale=28,
    euler_translate=30,
    euler=29,
    euler_scale_translate=31,
    scale=32,
    set_viewproj=42,
    scale_proj=44,
    zrot_viewproj=46,
    scaled_viewproj=50,
    bone=51,
    tempScale=53,
    euler_translate_conjScale=54,
    xform_eulerTAB_trans_scale=63
} geoPayloadType;

typedef struct { /* OMMtx */
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ geoPayloadType type;
} nodePayload; // size = 0x44;

typedef struct xformData {
    /* 0x00 */ char unk_00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ Vec3f translation;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 angle;
    /* 0x1C */ Vec3f euler;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ Vec3f scale;
} xformData; // size = 0x38

typedef struct {
    /* 0x00 */ s8 type; /* 0=linear;1=bezier;2=hermite/6 */
    /* 0x01 */ char unk_01[0x1];
    /* 0x02 */ s16 length;
    /* 0x04 */ f32 invSegTime;
    /* 0x08 */ Vec3f* pts;
    /* 0x0C */ f32 duration;
    /* 0x10 */ f32* times;
    /* 0x14 */ quartic* quartics;
} pathSpline;

typedef struct {
    /* 0x00 */ struct uvOP* next;
    /* 0x04 */ s8 value;
    /* 0x05 */ s8 op;
    /* 0x06 */ char unk_06[0x2];
    /* 0x08 */ f32 ref;
    /* 0x0C */ f32 t;
    /* 0x10 */ f32 p0;
    /* 0x14 */ f32 p1;
    /* 0x18 */ f32 v0;
    /* 0x1C */ f32 v1;
    /* 0x20 */ struct pathSpline* path;
} uvOP;

typedef struct {
    /* 0x00 */ u32 type;
    /* 0x04 */ u32 flags;
    /* 0x08 */ s32 inc;
} uvState;

typedef struct { /* MObj internally */
    /* 0x00 */ struct uvScroll* next;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ u16 h_8;
    /* 0x0A */ s8 fmt1;
    /* 0x0B */ s8 siz1;
    /* 0x0C */ u32* textures;
    /* 0x10 */ u16 stretch;
    /* 0x12 */ u16 sharedOffset;
    /* 0x14 */ u16 t0w;
    /* 0x16 */ u16 t0h;
    /* 0x18 */ s32 halve;
    /* 0x1C */ f32 xFrac0;
    /* 0x20 */ f32 yFrac0;
    /* 0x24 */ f32 xScale;
    /* 0x28 */ f32 yScale;
    /* 0x2C */ f32 field_0x2c;
    /* 0x30 */ f32 field_0x30;
    /* 0x34 */ u32* palettes;
    /* 0x38 */ u16 flags;
    /* 0x3A */ s8 fmt2;
    /* 0x3B */ s8 siz2;
    /* 0x3C */ u16 w2;
    /* 0x3E */ u16 h2;
    /* 0x40 */ u16 t1w;
    /* 0x42 */ u16 t1h;
    /* 0x44 */ f32 xFrac1;
    /* 0x48 */ f32 yFrac1;
    /* 0x4C */ f32 unk_4C;
    /* 0x50 */ s32 unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s8 primR;
    /* 0x59 */ s8 primG;
    /* 0x5A */ s8 primB;
    /* 0x5B */ s8 primA;
    /* 0x5C */ char unk_5C[0x1];
    /* 0x5D */ s8 minLOD;
    /* 0x5E */ char unk_5E[0x2];
    /* 0x60 */ s8 envR;
    /* 0x61 */ s8 envG;
    /* 0x62 */ s8 envB;
    /* 0x63 */ s8 envA;
    /* 0x64 */ s8 blendR;
    /* 0x65 */ s8 blendG;
    /* 0x66 */ s8 blendB;
    /* 0x67 */ s8 blendA;
    /* 0x68 */ u32 lightColor1;
    /* 0x6C */ u32 lightColor2;
    /* 0x70 */ char unk_70[0x10];
    /* 0x80 */ u16 texIndex1;
    /* 0x82 */ u16 texIndex2;
    /* 0x84 */ f32 primLOD;
    /* 0x88 */ f32 palIndex;
    /* 0x8C */ char unk_8C[0x4];
    /* 0x90 */ uvOP* ops;
    /* 0x94 */ uvState* states;
    /* 0x98 */ f32 offset;
    /* 0x9C */ f32 increment;
    /* 0xA0 */ f32 unk_A0;
    /* 0xA4 */ char unk_A4[0x4];
} uvScroll; // size = 0xA8

typedef struct geoNodeSub {
    /* 0x00 */ nodePayload* newPayload;
    /* 0x04 */ Vec3f translation;
} geoNodeSub; // size = 0x10

typedef struct geoNode { /* top level rendering object */
    /* 0x00 */ struct geoNode* unk_00;
    /* 0x04 */ struct GObj* gobj;
    /* 0x08 */ struct geoNode* next;
    /* 0x0C */ struct geoNode* prev;
    /* 0x10 */ struct geoNode* child;
    /* 0x14 */ struct geoNode* parent;
    /* 0x18 */ geoNodeSub unk_18;
    /* 0x28 */ char unk_28[0x4];
    /* 0x2C */ f32 degrees;
    /* 0x30 */ Vec3f euler;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ Vec3f scale;
    /* 0x4C */ xformData* xform;
    /* 0x50 */ s32 nodeGraphics;
    /* 0x54 */ s8 stateFlags;
    /* 0x55 */ s8 firstState;
    /* 0x56 */ s8 nextIndex;
    /* 0x57 */ char unk_57[0x1];
    /* 0x58 */ nodePayload* payloads[5];
    /* 0x6C */ uvOP* ops;
    /* 0x70 */ uvState* uvState;
    /* 0x74 */ f32 untilUpdate; /* see uvScroll offset */
    /* 0x78 */ f32 inc;
    /* 0x7C */ f32 currFrame;
    /* 0x80 */ uvScroll* uvScrolls;
    /* 0x84 */ char unk_84[0x4];
} geoNode; // size = 0x88

typedef struct {
    /* 0x00 */ struct signalLL* next;
    /* 0x04 */ struct GObj* gobj;
    /* 0x08 */ s32 data;
} signalLL;

typedef struct {
    /* 0x00 */ f32 nodeInc;
    /* 0x04 */ f32 field_0x4;
    /* 0x08 */ uvState** animList;
    /* 0x0C */ uvState*** matAnims;
    /* 0x10 */ s32* ids;
} animationHeader;

typedef struct {
    /* 0x00 */ s32 id;
    /* 0x04 */ void* state;
    /* 0x08 */ f32 radius;
    /* 0x0C */ void* aux;
} idFuncStruct;

typedef struct {
    /* 0x00 */ animationHeader* animations;
    /* 0x04 */ GObjFunc func;
    /* 0x08 */ s8 kind;
    /* 0x09 */ char unk_09[0x3];
    /* 0x0C */ void* unk_0C;
    /* 0x10 */ idFuncStruct* idfuncs;
} animalAnimationSetup;

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
    /* 0x2C */ pathSpline* path;
} ObjectSpawn; // size = 0x30

typedef union {
    f32 field0;
    s32 field1;
} misc;

typedef struct PokemonInitData {
    /* 0x00 */ UnkEC64Arg3* tree;
    /* 0x04 */ Texture*** textures;
    /* 0x08 */ GObjFunc fnRender;
    /* 0x0C */ animalAnimationSetup* animSetup;
    /* 0x10 */ Vec3f scale;
    /* 0x1C */ Vec3f scaleNumerator;
    /* 0x28 */ f32 radius;
    /* 0x2C */ u16 flags;
    /* 0x2E */ u8 matrix1;
    /* 0x2F */ u8 matrix2;
    /* 0x30 */ u8 matrix3;
    /* 0x31 */ char unk_31[0x3];
    /* 0x34 */ f32 unk_34;
} PokemonInitData;

typedef struct PokemonTransform {
    /* 0x00 */ struct Mtx3Float pos;
    /* 0x10 */ struct Mtx4Float rot;
    /* 0x24 */ struct Mtx3Float scale;
} PokemonTransform; // size = 0x34

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
} eggStruct;

typedef struct GroundResult {
    /* 0x00 */ f32 height;
    /* 0x04 */ Vec3f normal;
    /* 0x10 */ s32 type;
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
    /* 0x05C */ animalAnimationSetup* animSetup; /* Created by retype action */
    /* 0x060 */ GObjProcess* interactionProc; /* Created by retype action */
    /* 0x064 */ struct GObj* apple;
    /* 0x068 */ f32 interactionDist;
    /* 0x06C */ f32 playerDist;
    /* 0x070 */ struct GObj* interactionTarget;
    /* 0x074 */ struct WorldBlock* someRoom;
    /* 0x078 */ char unk_78[0x8];
    /* 0x080 */ uvState** animators; /* Created by retype action */
    /* 0x084 */ uvState*** matAnims; /* Created by retype action */
    /* 0x088 */ s32 behavior;
    /* 0x08C */ u32 processFlags; /* Created by retype action */
    /* 0x090 */ s32 counter;
    /* 0x094 */ struct GObj* pathProcess; /* Created by retype action */
    /* 0x098 */ f32 hSpeed;
    /* 0x09C */ f32 jumpVel;
    /* 0x0A0 */ f32 facingYaw; /* Created by retype action */
    /* 0x0A4 */ s32 animalLoopTarget;
    /* 0x0A8 */ f32 lastAnimationFrame;
    /* 0x0AC */ idFuncStruct* transitionGraph; /* Created by retype action */
    /* 0x0B0 */ misc miscVars[7];
    /* 0x0CC */ f32* forbiddenGround;
    /* 0x0D0 */ GroundResult currGround; /* Created by retype action */
    /* 0x0E4 */ u8 unk_E4;
    /* 0x0E5 */ char unk_E5[0x3];
    /* 0x0E8 */ pathSpline* path;
    /* 0x0EC */ f32 pathParam; /* Created by retype action */
    /* 0x0F0 */ PokemonInitData* initData;
    /* 0x0F4 */ animationHeader* animHeader;
    /* 0x0F8 */ eggStruct* eggGeo;
    /* 0x0FC */ char unk_FC[0x4];
    /* 0x100 */ Vec3f collPosition;
    /* 0x10C */ s16 unk_10C;
    /* 0x10E */ s16 field_0x10e;
} Animal; // size = 0x110

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
    Animal* animal;
    projectileData* projectileData;
} gobjData;

typedef GObj* (*animalInit)(s32 arg0, u16 id, struct WorldBlock* blockA, struct WorldBlock* blockB, ObjectSpawn* spawn);
typedef void (*gfxFunc)(GObj*);

typedef struct {
    s32 value;
    void (*func)(GObj*);
} randomTransition;

typedef struct {
    /* 0x00 */ u32 id;
    /* 0x04 */ animalInit init;
    /* 0x08 */ void* update;
    /* 0x0C */ void* kill;
} AnimalDef; // size = 0x10

typedef struct UnkPinkBarracuda {
    s32 unk4_25 : 7;
} UnkPinkBarracuda;

typedef struct UnkStruct800BEDF8 {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} UnkStruct800BEDF8;

typedef struct PlayerName {
    /* 0x00 */ char data[0x10];
} PlayerName; // size = 0x10

typedef struct UnkStruct80366BA4 {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ s32 *unk_08;
    /* 0x0C */ Vec3f unk_0C;
    /* 0x18 */ u8 pad18[0x4];
    /* 0x1C */ f32 unk_1C; 
} UnkStruct80366BA4; // size >= 0x20

#endif
