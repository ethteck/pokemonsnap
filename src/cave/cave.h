#ifndef _CAVE_H_
#define _CAVE_H_

typedef struct SomeBits {
    /* 0x00 */ u8 unk_00_0 : 1;
    /* 0x00 */ u8 unk_00_1 : 1;
    /* 0x00 */ u8 unk_00_2 : 1;
    /* 0x00 */ u8 unk_00_3 : 1;
    /* 0x00 */ u8 unk_00_4 : 1;
    /* 0x00 */ u8 unk_00_5 : 1;
    /* 0x00 */ u8 unk_00_6 : 1;
    /* 0x00 */ u8 unk_00_7 : 1;
    /* 0x01 */ u8 unk_01_0 : 1;
    /* 0x01 */ u8 unk_01_1 : 1;
    /* 0x01 */ u8 unk_01_2 : 1;
} SomeBits;

void func_802BE450_640900(s32, f32);
void func_802C38E0_645D90(GObj*);
void func_802C39B8_645E68(GObj*);
void func_802C60F4_6485A4(void);

extern SomeBits D_8033E138_6C05E8;

#endif
