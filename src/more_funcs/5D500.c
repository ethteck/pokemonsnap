#include "common.h"
#include "more_funcs.h"

s32 func_800C0790_5D630(s32, s32);

extern s32 D_800E16F0_7E590;
extern s32 D_800E1700_7E5A0;
extern s64 D_800E1708_7E5A8[];
extern s32 D_800E1798_7E638;
extern s32 D_800E179C_7E63C;
extern void* D_800E17A0_7E640;
extern OSMesgQueue D_800E17A8_7E648;

void func_800C0660_5D500(s32* arg0, s32* arg1) {
    if (arg0 != NULL) {
        *arg0 = D_800E1798_7E638;
    }
    if (arg1 != NULL) {
        *arg1 = D_800E179C_7E63C;
    }
}

void func_800C0688_5D528(void) {
    func_800C1BBC_5EA5C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5D500/func_800C06A8_5D548.s")

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5D500/func_800C0790_5D630.s")

s32 func_800C0848_5D6E8(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 0; i != 0x80; i++) {
        if (arg2 < 0) {
            return 0;
        }
        if (arg1 >= PokemonID_1022) {
            break;
        }
        if (func_800C0790_5D630(arg0, arg1)) {
            return 1;
        }

        arg0 += 0x80;
        arg2 -= 0x80;
        arg1++;
    }

    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5D500/func_800C08DC_5D77C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5D500/func_800C09C0_5D860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5D500/func_800C0AB4_5D954.s")

void func_800C0B48_5D9E8(void) {
    D_800E1700_7E5A0 = (s32) ((uintptr_t) D_800E1708_7E5A8 + 0xF) & ~0xF;
    D_800E16F0_7E590 = func_800C1818_5E6B8();
    osCreateMesgQueue(&D_800E17A8_7E648, &D_800E17A0_7E640, 1);
    D_800E1798_7E638 = 0;
    D_800E179C_7E63C = 0;
}
