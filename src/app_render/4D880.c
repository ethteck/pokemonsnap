#include "common.h"

typedef struct UnkCoalEel {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 unk_04;
} UnkCoalEel;

typedef struct UnkRustRat {
    /* 0x00 */ struct UnkRustRat* next;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s8 unk_08;
    /* 0x09 */ s8 unk_09;
    /* 0x0A */ s8 unk_0A;
    /* 0x0B */ s8 unk_0B;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
    /* 0x3C */ f32 unk_3C;
    /* 0x40 */ f32 unk_40;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ ucolor unk_48;
    /* 0x4C */ s32 unk_4C;
    /* 0x50 */ s8 unk_50;
    /* 0x51 */ s8 unk_51;
    /* 0x52 */ s8 unk_52;
    /* 0x53 */ s8 unk_53;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ UnkCoalEel* unk_58;
} UnkRustRat; // size = 0x5C

extern u16 D_800AEC68;
extern UnkRustRat* D_800BE1A0;
extern UnkRustRat* D_800BE1A8[16];
extern OMCamera* D_800BE1F0[4];
extern s8 D_800BE200[4];

void func_800A4798(GObj*);
void func_800A4858(GObj*);

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A1ED0.s")
/*
TODO later
extern u32 D_800BE228[8];
extern u32 D_800BE248[8];
extern u32* D_800BE268[8];
extern u32** D_800BE288[8];

void func_800A1ED0(s32 arg0, s32* arg1, s32* arg2) {
    s32 i, j;

    if (arg0 < 8) {
        D_800BE228[arg0] = *arg1;
        D_800BE248[arg0] = *arg2;
        D_800BE268[arg0] = ((u32)arg1) + 4;
        D_800BE288[arg0] = ((u32)arg2) + 4;

        for (i = 1; i < D_800BE228[arg0]; i++) {
            arg1[i] = (u32)(arg1) + arg1[i];
        }
        for (i = 1; i < D_800BE248[arg0]; i++) {
            arg2[i] = (u32)(arg2) + arg2[i];
        }

        for (i = 0; i < D_800BE248[arg0]; i++) {
            for (j = 0; j < D_800BE288[arg0][i][j]; j++) {
                D_800BE288[arg0][i][j]
            }
        }
    }
}
*/

#ifdef NON_MATCHING
// loop unroll
GObj* func_800A2094(s32 arg0, s32 arg1, OMCamera* arg2) {
    s32 i;
    s32 s0;
    UnkRustRat* temp;

    D_800BE1F0[0] = arg2;
    D_800BE200[0] = 1;
    for (i = 1; i < 4; i++) {
        D_800BE1F0[i] = 0;
    }

    D_800BE1A0 = NULL;
    for (i = 0; i < 16; i++) {
        D_800BE1A8[i] = NULL;
    }

    s0 = arg1 - 1;
    while (s0 >= 0) {
        temp = gtlMalloc(sizeof(UnkRustRat), 4);
        if (temp == NULL) {
            return NULL;
        }
        s0--;
        temp->next = D_800BE1A0;
        D_800BE1A0 = temp;
    }

    if (ohFindById(-6) != 0) {
        return NULL;
    } else {
        return ohCreateCamera(-6, func_800A4798, 0, 0x80000000, func_800A4858, arg0, 0, 0, FALSE, 1, NULL, 1, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2094.s")
GObj* func_800A2094(s32 arg0, s32 arg1, OMCamera* arg2);
#endif

void func_800A21C0(s32 arg0, OMCamera* arg1, s32 arg2) {
    D_800BE1F0[arg0] = arg1;
    D_800BE200[arg0] = arg2;
}

#ifdef NON_MATCHING
UnkRustRat* func_800A21E0(UnkRustRat** arg0, s32 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7,
                    f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE, s32 argF, UnkCoalEel* arg10) {
    UnkRustRat* ret = D_800BE1A0;

    if (ret == NULL) {
        return NULL;
    }

    if (arg10 != NULL) {
        ret->unk_04 = arg10->unk_04;
    } else {
        ret->unk_04 = ++D_800AEC68;
    }

    D_800BE1A0 = ret->next;

    if (arg0 == NULL) {
        ret->next = D_800BE1A8[arg1 >> 3];
        D_800BE1A8[arg1 >> 3] = ret;
    } else {
        ret->next = *arg0;
        *arg0 = ret;
    }

    ret->unk_08 = arg1;
    ret->unk_06 = arg2;
    ret->unk_0A = arg3;
    ret->unk_20 = arg6;
    ret->unk_24 = arg7;
    ret->unk_28 = arg8;
    ret->unk_2C = arg9;
    ret->unk_30 = argA;
    ret->unk_34 = argB;
    ret->unk_40 = argC;
    ret->unk_38 = argD;
    ret->unk_3C = argE;
    ret->unk_1E = arg5 + 1;
    ret->unk_14 = arg4;
    ret->unk_18 = 0;
    ret->unk_1A = 0;
    if (argF) {
        ret->unk_06 = arg2 | 0x10;
    }
    if (arg4 != 0) {
        ret->unk_0C = TRUE;
    } else {
        ret->unk_0C = FALSE;
    }
    ret->unk_48.r = ret->unk_48.g = ret->unk_48.b = ret->unk_48.a = 0xFF;
    ret->unk_50 = 0;
    ret->unk_51 = 0;
    ret->unk_52 = 0;
    ret->unk_0B = 0;
    ret->unk_53 = 0;
    ret->unk_12 = 0;
    ret->unk_10 = 0;
    ret->unk_0E = 0;
    ret->unk_58 = arg10;

    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A21E0.s")
UnkRustRat* func_800A21E0(UnkRustRat** arg0, s32 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7,
                    f32 arg8, f32 arg9, f32 argA, f32 argB, f32 argC, f32 argD, f32 argE, s32 argF, UnkCoalEel* arg10);
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A235C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A244C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2514.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A268C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2740.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A27B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A27E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2824.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A29AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A2B3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A4798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A4858.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A5DD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A5DF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A5E08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A5E98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A63BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6F74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6FBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A6FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A7114.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A7140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A716C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A71F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A72AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app_render/4D880/func_800A7330.s")
