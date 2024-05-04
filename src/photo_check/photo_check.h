#include "types.h"

typedef struct Photo {
    /* 0x00 */ UnkPinkBarracuda* unk_0;
    /* 0x04 */ u32 unk_4;
    /* 0x08 */ u8 commentID;
    /* 0x09 */ u8 unk_9;
    /* 0x0A */ s16 pkmnID;
    /* 0x0C */ s16 specialID;
    /* 0x0E */ s16 isWellFramed;
    /* 0x10 */ s16 posePts;
    /* 0x12 */ s16 sizeParam1;
    /* 0x14 */ s16 sizeParam2;
    /* 0x16 */ s16 specialBonus;
    /* 0x18 */ s16 samePkmnBonus;
    /* 0x1A */ s16 unk_1A_15 : 1;
    /* 0x1A */ s16 unk_1A_14 : 1;
    /* 0x1A */ s16 unk_1A_13 : 1;
    /* 0x1A */ s16 unk_1A_12 : 1;
    /* 0x1A */ s16 unk_1A_11 : 1;
    // /* 0x1A */ s16 unk_1A_10 : 1;
    // /* 0x1A */ s16 unk_1A_9 : 1;
    // /* 0x1A */ s16 unk_1A_8 : 1;
    // /* 0x1A */ s16 unk_1A_7 : 1;
    // /* 0x1A */ s16 unk_1A_6 : 1;
    // /* 0x1A */ s16 unk_1A_5 : 1;
    // /* 0x1A */ s16 unk_1A_4 : 1;
    // /* 0x1A */ s16 unk_1A_3 : 1;
    // /* 0x1A */ s16 unk_1A_2 : 1;
    // /* 0x1A */ s16 unk_1A_1 : 1;
    // /* 0x1A */ s16 unk_1A_0 : 1;
} Photo; // size = 0x1C

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

s32 func_801E41FC_993C6C(UnkStruct800BEDF8* arg0, s32* arg1);
Photo* func_801E459C_99400C(s32 idx);

