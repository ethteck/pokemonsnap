#ifndef WORLD_H
#define WORLD_H

#include "common.h"

#define MAX_BLOCKS 13

struct WorldBlock;

typedef struct UnkIndigoDingo {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ Mtx4f unk_04;
    /* 0x44 */ Mtx4f unk_44;
    /* 0x84 */ f32 unk_84;
    /* 0x88 */ f32 unk_88;
    /* 0x88 */ f32 unk_8C;
} UnkIndigoDingo; // size >= 0x8C

typedef struct UnkCaramelBoa {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ UnkIndigoDingo* unk_04;
    /* 0x08 */ Vec3f position;
    /* 0x14 */ Vec3f rotation;
    /* 0x20 */ Vec3f scale;
} UnkCaramelBoa; // size = 0x2C

typedef struct UnkChestnutCougar {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ UnkCaramelBoa* unk_04;
    /* 0x08 */ f32 unk_08;
} UnkChestnutCougar; // size = 0xC

typedef struct UnkBeigeServal {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ Vec3f unk_1C;
} UnkBeigeServal; // size = 0x28

typedef struct SkyBox {
    /* 0x00 */ Gfx* gfxData;
    /* 0x04 */ GObjFunc renderFunc;
    /* 0x08 */ Texture*** textures;
    /* 0x0C */ AnimCmd*** animation;
    /* 0x10 */ f32 animationSpeed;
} SkyBox; // size = 0x14

typedef struct WorldBlockGFX {
    /* 0x00 */ void* gfxData; // type depends on renderFunc value
    /* 0x04 */ Texture*** textures;
    /* 0x08 */ AnimCmd*** unk_08;
    /* 0x0C */ GObjFunc renderFunc;
    /* 0x10 */ UnkEC64Arg3* uvScrollAnim;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ AnimCmd** unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ f32 unk_20[1]; // variable size, depends on unk_14
} WorldBlockGFX; // size >= 0x20

typedef struct PayloadStruct {
    union {
        Gfx* gfx;
        UnkEC64Arg3* treeDef;
    } d;
} PayloadStruct;

typedef struct UnkVioletMarlin {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ void (*unk_04)(struct WorldBlock*, UnkBeigeServal*, PayloadStruct);
    /* 0x08 */ PayloadStruct unk_08;
} UnkVioletMarlin; // size = 0x28

typedef struct WorldBlockDescriptor {
    /* 0x00 */ WorldBlockGFX* gfx;
    /* 0x04 */ Vec3f worldPos;
    /* 0x10 */ f32 yaw;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ UnkBeigeServal* unk_18;
    /* 0x1C */ ObjectSpawn* spawn;
    /* 0x20 */ UnkBeigeServal* unk_20;
} WorldBlockDescriptor; // size >= 0x24

typedef struct WorldBlock {
    /* 0x00 */ s32 index;
    /* 0x04 */ WorldBlockDescriptor* descriptor;
    /* 0x08 */ struct WorldBlock* prev;
    /* 0x0C */ struct WorldBlock* next;
    /* 0x10 */ GObj* blockModel;
    /* 0x14 */ GObj* blockUV;
    /* 0x18 */ DObj** unk_18;
} WorldBlock; // size = 0x1C

typedef struct UnkBoneFox {
    /* 0x00 */ WorldBlockDescriptor** unk_00;
    /* 0x04 */ WorldBlockDescriptor** unk_04;
    /* 0x08 */ SkyBox* skybox;
} UnkBoneFox; // size >= 0xC

typedef struct WorldSetup {
    /* 0x00 */ UnkBoneFox* blocksSetup;
    /* 0x04 */ UnkVioletMarlin* unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ UnkChestnutCougar* unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u16 fogDistanceMin;
    /* 0x16 */ u16 fogDistanceMax;
    /* 0x18 */ u8 fogR;
    /* 0x19 */ u8 fogG;
    /* 0x1A */ u8 fogB;
    /* 0x1B */ u8 backgroundR;
    /* 0x1C */ u8 backgroundG;
    /* 0x1D */ u8 backgroundB;
} WorldSetup; // size >= 0x1E

typedef struct HeightMapPatch {
    /* 0x00 */ f32 planeA;
    /* 0x04 */ f32 planeB;
    /* 0x08 */ f32 planeC;
    /* 0x0C */ f32 planeD;
    /* 0x10 */ u32 surfaceType;
} HeightMapPatch; // size = 0x14

typedef struct HeightMapTreeNode {
    /* 0x00 */ f32 lineA;
    /* 0x04 */ f32 lineB;
    /* 0x08 */ f32 lineC;
    /* 0x0C */ struct HeightMapTreeNode* leftChild;
    /* 0x10 */ struct HeightMapTreeNode* rightChild;
    /* 0x14 */ HeightMapPatch* leftPatch;
    /* 0x18 */ HeightMapPatch* rightPatch;
} HeightMapTreeNode; // size = 0x1C

typedef struct WorldCameraState {
    /* 0x00 */ f32 progress;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ WorldBlock* block;
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ Vec3f rotation;
    /* 0x24 */ f32 moveSpeed; // blocks per frame
    /* 0x28 */ f32 baseMoveSpeed;
} WorldCameraState; // size >= 0x2C

typedef struct HeightMap {
    /* 0x00 */ HeightMapPatch* patches;
    /* 0x04 */ HeightMapTreeNode* tree;
} HeightMap; // size >= 0x08

enum SurfaceTypes {
    SURFACE_TYPE_4C1900 = 0x4C1900,
    SURFACE_TYPE_4C4C33 = 0x4C4C33,
    SURFACE_TYPE_7F4C00 = 0x7F4C00,
    SURFACE_TYPE_7F7F7F = 0x7F7F7F,
    SURFACE_TYPE_B2997F = 0xB2997F,
    SURFACE_TYPE_193333 = 0x193333,
    SURFACE_TYPE_4C7F00 = 0x4C7F00,
    SURFACE_TYPE_996666 = 0x996666,
    SURFACE_TYPE_FF9919 = 0xFF9919,
    SURFACE_TYPE_331919 = 0x331919,
    SURFACE_TYPE_7F667F = 0x7F667F,
    SURFACE_TYPE_FF7FB2 = 0xFF7FB2,
    SURFACE_TYPE_7F6633 = 0x7F6633,
    SURFACE_TYPE_00FF00 = 0x00FF00,
    SURFACE_TYPE_FF4C19 = 0xFF4C19,
    SURFACE_TYPE_0019FF = 0x0019FF,
    SURFACE_TYPE_007F66 = 0x007F66,
    SURFACE_TYPE_337FB2 = 0x337FB2,
    SURFACE_TYPE_4CCCCC = 0x4CCCCC,
    SURFACE_TYPE_FF0000 = 0xFF0000
};

typedef void (*BlockFunc)(WorldBlock*);
typedef void (*BlockFunc2)(WorldBlock*, WorldBlock*);

extern WorldSetup D_80100720;

void func_800E66BC_63E6C(UnkChestnutCougar* arg0);
WorldBlock* func_800E26CC_5FE7C(s32 arg0);
WorldBlock* enterNextBlock(void);
void createHeightMapTree(HeightMapTreeNode* arg0, HeightMapPatch* arg1);
HeightMapPatch* findHeightMapPatch(HeightMapTreeNode*, f32, f32);
f32 getPatchHeightAt(HeightMapPatch*, f32, f32);
Vec3f* getPatchNormal(HeightMapPatch* arg0);
s32 getPatchSurfaceType(HeightMapPatch*);

// Public functions
void func_800E1A78_5F228(f32 arg0);
void drawSkyBox1Cycle(GObj* obj);
void drawSkyBox2Cycle(GObj* obj);
void setSkyBoxFollowPlayer(void);
void setSkyBoxPos(f32 posX, f32 posY, f32 posZ, f32 yaw, f32 arg4);
WorldBlock* getCurrentWorldBlock(void);
WorldBlock** getWorldBlocks(void);
f32 world_func_800E219C(void);
f32 world_func_800E21A8(f32 arg0);
s32 createWorld(WorldSetup* arg0, s32 skyBoxObjId, s32 blockMinObjId, s32 blockMaxObjId, s32 link, s32 dllink, BlockFunc2 arg6, BlockFunc arg7, BlockFunc2 arg8);
void destroyWorld(void);
void func_800E30B0_60860(WorldBlock* block, UnkBeigeServal* arg1, PayloadStruct arg2);
void func_800E3258_60A08(WorldBlock* block, UnkBeigeServal* arg1, PayloadStruct arg2);
void func_800E3D04_614B4(WorldCameraState* arg0);
void func_800E3EE8_61698(WorldCameraState* arg0, s32 arg1, void (*arg2)(WorldBlock*), void (*arg3)(s32));
s32 inRange_DEBUG(u32, s32, s32, const char*);
s32 notNull_DEBUG(void*, const char*);
s32 setHeightMap(HeightMap* arg0);
s32 setCeilingMap(HeightMap* arg0);
s32 getGroundAt(f32 arg0, f32 arg1, GroundResult* arg2);
s32 getCeilingAt(f32 arg0, f32 arg1, GroundResult* arg2);
s32 func_800E6238_639E8(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3);
void world_func_800E6778(UnkChestnutCougar* arg0);
s32 world_func_800E67E4(Vec3f* arg0, Vec3f* arg1, Vec3f* arg2, Vec3f* arg3, UnkChestnutCougar* arg4, Vec3f arg5, Vec3f arg8);

#endif
