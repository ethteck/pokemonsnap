#ifndef _CAVE_H_
#define _CAVE_H_

typedef struct InteractionHandler2 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[2];
} InteractionHandler2; // size = 0x20

typedef struct InteractionHandler3 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[3];
} InteractionHandler3; // size = 0x30

typedef struct InteractionHandler4 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[4];
} InteractionHandler4; // size = 0x40

typedef struct InteractionHandler5 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[5];
} InteractionHandler5; // size = 0x50

typedef struct InteractionHandler6 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[6];
} InteractionHandler6; // size = 0x60

typedef struct InteractionHandler7 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[7];
} InteractionHandler7; // size = 0x70

typedef struct InteractionHandler8 { // needed for struct copy
    /* 0x00 */ InteractionHandler data[8];
} InteractionHandler8; // size = 0x80

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
