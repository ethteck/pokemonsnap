#include "types.h"

typedef struct Photo {
    /* 0x00 */ u32 unk_0; // confirmed
    /* 0x04 */ u32 unk_4;
    /* 0x08 */ u8 unk_8;
    /* 0x09 */ u8 unk_9;
    /* 0x0A */ s16 unk_0A; // confirmed
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ u16 unk_10;
    /* 0x12 */ u16 unk_12;
    /* 0x14 */ u16 unk_14;
    /* 0x16 */ u16 unk_16;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s8 unk_1A_15 : 1; // confirmed
    /* 0x1A */ s8 unk_1A_14 : 1; // confirmed
    /* 0x1A */ s8 unk_1A_13 : 1; // confirmed
    /* 0x1A */ s8 unk_1A_12 : 1;
    /* 0x1A */ s8 unk_1A_11 : 1;
    /* 0x1A */ s8 unk_1A_10 : 1;
    /* 0x1A */ s8 unk_1A_9 : 1;
    /* 0x1A */ s8 unk_1A_8 : 1;
    /* 0x1A */ s8 unk_1A_7 : 1;
    /* 0x1A */ s8 unk_1A_6 : 1;
    /* 0x1A */ s8 unk_1A_5 : 1;
    /* 0x1A */ s8 unk_1A_4 : 1;
    /* 0x1A */ s8 unk_1A_3 : 1;
    /* 0x1A */ s8 unk_1A_2 : 1;
    /* 0x1A */ s8 unk_1A_1 : 1;
    /* 0x1A */ s8 unk_1A_0 : 1;
} Photo; // size = 0x1C

Photo* func_801E459C_99400C(s32 idx);
