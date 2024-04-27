#ifndef LEVEL_LOW_H
#define LEVEL_LOW_H

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

typedef struct UnkEbonyBarracuda {
    /* 0x00 */ Gfx* unk_00;
    /* 0x04 */ GObjFunc unk_04;
    /* 0x08 */ Texture*** unk_08;
    /* 0x0C */ union AnimCmd*** unk_0C;
    /* 0x10 */ f32 unk_10;
} UnkEbonyBarracuda;

typedef struct UnkIvoryMamba {
    /* 0x00 */ char unk_00[0xC];
} UnkIvoryMamba; // size == 0xC

typedef struct UnkPlumPython {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Texture*** unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ GObjFunc unk_0C;
    /* 0x10 */ void* unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ union AnimCmd** unk_18;
    /* 0x1C */ s32 unk_1C;
} UnkPlumPython; // size >= 0x20

typedef struct UnkMintLynx {
    /* 0x00 */ UnkPlumPython* unk_00;
    /* 0x04 */ Vec3f unk_04;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32* unk_18;
    /* 0x1C */ char unk_1C[4];
    /* 0x20 */ UnkBeigeServal* unk20;
} UnkMintLynx; // size >= 0x1C

typedef struct UnkBordeauxWolf {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ UnkMintLynx* unk_04;
    /* 0x08 */ struct UnkBordeauxWolf* unk_08;
    /* 0x0C */ struct UnkBordeauxWolf* unk_0C;
    /* 0x10 */ GObj* unk_10;
    /* 0x14 */ GObj* unk_14;
    /* 0x18 */ UnkIvoryMamba* unk_18;
} UnkBordeauxWolf; // size = 0x1C

typedef struct UnkBoneFox {
    /* 0x00 */ UnkMintLynx** unk_00;
    /* 0x04 */ UnkMintLynx** unk_04;
    /* 0x08 */ UnkEbonyBarracuda* unk_08;
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

UnkBordeauxWolf* func_800E2184_5F934(void);
void func_800E66BC_63E6C(UnkChestnutCougar* arg0);

#endif
