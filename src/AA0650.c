#include "common.h"

typedef struct Unk800E1DD0_data {
    u8 pad_00[0x10];
    s16 unk_10;
    s16 unk_12;
    s16 unk_14;
    s16 unk_16;
    u8 pad_18[0xC];
    s16 unk_24;
    u8 pad_26[0x2];
    u8 unk_28;
    u8 unk_29;
    u8 unk_2A;
} Unk800E1DD0_data;

extern GObj* D_800E1DD0_AA0B80;
extern s32 D_800E1DD4_AA0B84;

GObj* func_800E18A0_AA0650(void);
void func_800E1958_AA0708(Unk800E1DD0_data* arg0, u16 arg1);
extern Sprite D_802BC0C0;

GObj* func_800E18A0_AA0650(void) {
    Unk800E1DD0_data* temp_v1;
    GObj* temp_v0;

    temp_v0 = ohCreateSprite(0xE, ohUpdateDefault, 0, 0x80000000, renDrawSprite, 1, 0x80000000, -1, &D_802BC0C0, 0, NULL, 1);
    temp_v1 = temp_v0->data.any;
    temp_v1->unk_24 = 0x201;
    temp_v1->unk_10 = 160 - (temp_v1->unk_14 / 2);
    temp_v1->unk_12 = 120 - (temp_v1->unk_16 / 2);
    return temp_v0;
}

void func_800E1958_AA0708(Unk800E1DD0_data* arg0, u16 arg1) {
    u8 temp_lo;
    u16 temp_arg1;
    u8 temp;

    if (arg1) {
        temp_arg1 = arg1;
        for (arg1 = arg1 - 1; arg1 > 0; arg1--) {
            temp_lo = (arg1 * (temp = 0xFF)) / temp_arg1;
            arg0->unk_2A = temp_lo;
            arg0->unk_29 = temp_lo;
            arg0->unk_28 = temp_lo;
            ohWait(1);
        }
        arg0->unk_2A = 0;
        arg0->unk_29 = 0;
        arg0->unk_28 = 0;
        ohWait(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/AA0650/func_800E1A34_AA07E4.s")

void func_800E1A94_AA0844(s32 arg0) {
    func_800ABB94();
    D_800E1DD0_AA0B80 = func_800E18A0_AA0650();
    ohWait(1);
    func_800C05D4_5D474();
    ohWait(1);
    if (D_800E1DD4_AA0B84 < 60) {
        ohWait(60 - D_800E1DD4_AA0B84);
    }
    func_800E1958_AA0708(D_800E1DD0_AA0B80->data.any, 20);
    func_800067DC();
    // Infinite wait loop
    while(1) {
        ohWait(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/AA0650/func_800E1B30_AA08E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/AA0650/func_800E1B54_AA0904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/AA0650/func_800E1C5C_AA0A0C.s")
