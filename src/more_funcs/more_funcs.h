#ifndef _MORE_FUNCS_H_
#define _MORE_FUNCS_H_

#include "types.h"
#include "common_structs.h"

typedef struct UnkBigBoy {
    /* 0x000 */ s32 unk_0;
    /* 0x004 */ s32 unk_4;
    /* 0x008 */ s32 unk_8;
    /* 0x00C */ s32 unk_C;
    struct {
        /* 0x010 */ char unk_10[4];
        /* 0x014 */ u8 pad_14[0xC];
        /* 0x020 */ s32 unk_20;
        /* 0x024 */ s32 unk_24;
        /* 0x028 */ s32 unk_28;
        /* 0x02C */ s32 unk_2C;
        /* 0x030 */ u32 unk_30;
        /* 0x034 */ s32 unk_34[7];
        /* 0x050 */ s32 unk_50;
        /* 0x054 */ PlayerName playerName;
        /* 0x064 */ u32 unk_64_29 : 3;
        /* ----- */ u32 unk_64_22 : 7;
        /* ----- */ u32 unk_64_16 : 6;
        /* 0x066 */ u32 hasApple : 1;
        /* ----- */ u32 hasPesterBall : 1;
        /* ----- */ u32 hasFlute : 1;
        /* ----- */ u32 unk_64_12 : 1;
        /* ----- */ u32 unk_64_11 : 1;
        /* ----- */ u32 hasDashEngine : 1;
        /* ----- */ u32 unk_64_09 : 1;
        /* ----- */ u32 unk_64_08 : 1;
        /* 0x067 */ u32 hasFinishedTutorial : 1;
        /* ----- */ u32 unk_64_06 : 1;
        /* ----- */ u32 unk_64_05 : 1;
        /* ----- */ u32 unk_64_04 : 1;
        /* ----- */ u32 unk_64_03 : 1;
        /* ----- */ u32 zoomSwitch : 1;
        /* ----- */ u32 invertedY : 1;
        /* ----- */ u32 unk_64_00 : 1;
        /* 0x068 */ u32 unk_68_31 : 1;
        /* ----- */ u32 unk_68_30 : 1;
        /* ----- */ u32 unk_68_29 : 1;
        /* ----- */ u32 unk_68_28 : 1;
        /* ----- */ u32 unk_68_27 : 1;
        /* ----- */ u32 unk_68_26 : 27;
        /* 0x06C */ s32 unk_6C[69];
        /* 0x180 */ PhotoData unk_180[69];
        /* 0xFBA0 */ PhotoData unk_FBA0[4];
        /* 0x10A20 */ PhotoDataExt var_10A20[60];
        /* 0x1f2a0 */ u8 pad_1F2A0[4];
    } data;
} UnkBigBoy; // size = 0x1F2A4

void func_800BF954_5C7F4(s32, PhotoData*, UnkFuzzyCaterpillar*);
s32 func_800C0224_5D0C4(s32);
void func_800C0254_5D0F4(s32, s32);
s32 func_800C06A8_5D548(uintptr_t, s32 size);
s32 func_800C09C0_5D860(uintptr_t, s32 size);
s32 func_800C0AB4_5D954(uintptr_t, s32);
UnkBigBoy* func_800C16EC_5E58C(void*, s32);
#endif
