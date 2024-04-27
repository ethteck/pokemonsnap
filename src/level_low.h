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

typedef struct UnkAmberMarlin {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ Vec3f unk4;
    /* 0x10 */ char unk10[16];
    /* 0x20 */ UnkBeigeServal* unk20;
} UnkAmberMarlin;

typedef struct UnkCeruleanComodo {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ UnkAmberMarlin* unk4;
    /* 0x08 */ struct UnkCeruleanComodo* unk8;
    /* 0x0C */ struct UnkCeruleanComodo* unkC;
} UnkCeruleanComodo;

UnkCeruleanComodo* func_800E2184_5F934(void);

#endif
