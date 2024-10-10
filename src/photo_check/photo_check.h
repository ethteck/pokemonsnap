#include "types.h"

typedef struct Photo {
    /* 0x00 */ PhotoData* unk_0;
    /* 0x04 */ u32 totalScore;
    /* 0x08 */ u8 poseID;
    /* 0x09 */ u8 samePkmnNumber;
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

typedef struct ScoreData {
    /* 0x00 */ s32 totalScore;
    /* 0x04 */ u16 samePkmnBonus;
    /* 0x06 */ u8 samePkmnNumber;
    /* 0x07 */ u8 isWellFramed;
    /* 0x08 */ u8 poseID;
    /* 0x0A */ s16 pokemonInFocus;
    /* 0x0C */ u16 sizeParam2;
    /* 0x0E */ u16 sizeParam1;
    /* 0x10 */ u16 posePts;
    /* 0x12 */ s16 specialBonus;
    /* 0x14 */ u8 specialID;
} ScoreData; // size = 0x18

typedef struct Unk803A6C18 {
    /* 0x000 */ PhotoData photo;
    /* 0x3A0 */ ScoreData score;
} Unk803A6C18; // size = 0x3B8

Unk803A6C18* func_8037452C_847CDC(PhotoData*);

s32 func_801E41FC_993C6C(UnkStruct800BEDF8* arg0, s32* arg1);
Photo* func_801E459C_99400C(s32 idx);
