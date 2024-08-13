#ifndef _CAVE_H_
#define _CAVE_H_

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

void func_802BE450_640900(s32, f32);
void func_802C60F4_6485A4(void);

#endif
