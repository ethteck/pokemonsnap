#ifndef WORLD_H
#define WORLD_H

#include "common.h"

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
} SkyBox;

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

typedef struct WorldBlockDescriptor {
    /* 0x00 */ WorldBlockGFX* gfx;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ f32 yaw;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32* unk_18;
    /* 0x1C */ void* unk_1C;
    /* 0x20 */ UnkBeigeServal* unk20;
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

typedef struct UnkTomatoEagle {
    /* 0x00 */ UnkBoneFox* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ UnkChestnutCougar* unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ u8 unk_18;
    /* 0x19 */ u8 unk_19;
    /* 0x1A */ u8 unk_1A;
    /* 0x1B */ u8 unk_1B;
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ u8 unk_1D;
} UnkTomatoEagle; // size >= 0x1E

typedef struct UnkFuchsiaKomodo {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ u32 unk_10;
} UnkFuchsiaKomodo; // size = 0x14

typedef struct UnkCoralFossa {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ struct UnkCoralFossa* unk_0C;
    /* 0x10 */ struct UnkCoralFossa* unk_10;
    /* 0x14 */ UnkFuchsiaKomodo* unk_14;
    /* 0x18 */ UnkFuchsiaKomodo* unk_18;
} UnkCoralFossa; // size = 0x1C

typedef void (*BlockFunc)(WorldBlock*);
typedef void (*BlockFunc2)(WorldBlock*, WorldBlock*);

WorldBlock* getCurrentWorldBlock(void);
void func_800E66BC_63E6C(UnkChestnutCougar* arg0);
WorldBlock* func_800E26CC_5FE7C(s32 arg0);
WorldBlock* func_800E2400_5FBB0(void);
void func_800E4634_61DE4(UnkCoralFossa* arg0, UnkFuchsiaKomodo* arg1);
UnkFuchsiaKomodo* func_800E4670_61E20(UnkCoralFossa*, f32, f32);
f32 func_800E4734_61EE4(UnkFuchsiaKomodo*, f32, f32);
Vec3f* func_800E47C4_61F74(UnkFuchsiaKomodo* arg0);
s32 func_800E4820_61FD0(UnkFuchsiaKomodo*);

#endif
