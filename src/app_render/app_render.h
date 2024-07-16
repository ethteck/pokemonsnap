#ifndef _APP_RENDER_H_
#define _APP_RENDER_H_

#include "common_structs.h"

typedef struct UnkCoalEel {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ char unk_09[0x50 - 0x9];
    /* 0x50 */ u16 unk_50;
} UnkCoalEel;

typedef struct UnkRustRat {
    /* 0x00 */ struct UnkRustRat* next;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ ucolor unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ ucolor unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ UnkCoalEel* unk_58;
} UnkRustRat; // size = 0x5C

extern UnkRustRat* D_800BE1A8[16];

#endif
