#include "types.h"

typedef struct Foo_Sub {
    s32 unk4_25 : 7;
} Foo_Sub;

typedef struct Photo {
    /* 0x00 */ Foo_Sub* unk_0; // confirmed
    /* 0x04 */ u32 unk_4;
    /* 0x08 */ u8 unk_8;
    /* 0x09 */ u8 unk_9;
    /* 0x0A */ s16 unk_0A; // confirmed
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A_15 : 1; // confirmed
    /* 0x1A */ s16 unk_1A_14 : 1; // confirmed
    /* 0x1A */ s16 unk_1A_13 : 1; // confirmed
    /* 0x1A */ s16 unk_1A_12 : 1;
    /* 0x1A */ s16 unk_1A_11 : 1;
    /* 0x1A */ s16 unk_1A_10 : 1;
    /* 0x1A */ s16 unk_1A_9 : 1;
    /* 0x1A */ s16 unk_1A_8 : 1;
    /* 0x1A */ s16 unk_1A_7 : 1;
    /* 0x1A */ s16 unk_1A_6 : 1;
    /* 0x1A */ s16 unk_1A_5 : 1;
    /* 0x1A */ s16 unk_1A_4 : 1;
    /* 0x1A */ s16 unk_1A_3 : 1;
    /* 0x1A */ s16 unk_1A_2 : 1;
    /* 0x1A */ s16 unk_1A_1 : 1;
    /* 0x1A */ s16 unk_1A_0 : 1;
} Photo; // size = 0x1C

typedef struct UnkStruct800BEDF8 {
    /* 0x00 */ char unk_00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} UnkStruct800BEDF8;

typedef struct Unk803A6C18 {
    /* 0x000 */ char unk_00[0x3A0];
    /* 0x3A0 */ s32 unk_3A0;
    /* 0x3A4 */ u16 unk_3A4;
    /* 0x3A6 */ u8 unk_3A6;
    /* 0x3A7 */ u8 unk_3A7;
    /* 0x3A8 */ u8 unk_3A8;
    /* 0x3A9 */ char unk_3A9[0x1];
    /* 0x3AA */ s16 unk_3AA;
    /* 0x3AC */ u16 unk_3AC;
    /* 0x3AE */ u16 unk_3AE;
    /* 0x3B0 */ u16 unk_3B0;
    /* 0x3B2 */ s16 unk_3B2;
    /* 0x3B4 */ u8 unk_3B4;
} Unk803A6C18;

Unk803A6C18* func_8037452C_847CDC(void*);

Photo* func_801E459C_99400C(s32 idx);

UnkStruct800BEDF8* func_800AA38C(s32);
