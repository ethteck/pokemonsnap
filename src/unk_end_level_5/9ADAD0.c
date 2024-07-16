#include "common.h"

#include "more_funcs/more_funcs.h"
#include "unk_end_level_5.h"

extern s32 D_8025093C_A1AB8C;
extern s32 D_80250940_A1AB90;
extern s32 D_80250944_A1AB94;
extern PhotoData D_80250170_A1A3C0;
extern s32 D_80208C40_9D2E90;

extern UnkFuzzyCaterpillar D_80250130_A1A380;
extern f32 D_80250174_A1A3C4;
extern s32 D_80250550_A1A7A0;
extern PhotoData D_80250558_A1A7A8;

UnkFuzzyCaterpillar* func_800BF534_5C3D4(s32);
void func_800BF4A8_5C348(UnkFuzzyCaterpillar* arg0, s32 arg1);
void func_800BF9F4_5C894(s32);

void func_801E3880_9ADAD0(void) {
    D_80208C40_9D2E90 = TRUE;
}

void func_801E389C_9ADAEC(const s16* src, s16* dst) {
    s32 i;

    for (i = 0; i < 31; i++) {
        dst[i] = src[i];
    }
}

PhotoData* func_801E38E0_9ADB30(s32 arg0) {
    return func_800BFA44_5C8E4(arg0);
}

void func_801E3914_9ADB64(s32 arg0) {
    func_800BF4A8_5C348(&D_80250130_A1A380, arg0);
    func_800BF9F4_5C894(arg0);
    D_8025093C_A1AB8C--;

    if (arg0 == D_80250940_A1AB90) {
        while (arg0 >= 0 && func_800BFA44_5C8E4(arg0) == NULL) {
            arg0--;
        }
        D_80250940_A1AB90 = arg0;
    }

    if (arg0 == D_80250944_A1AB94) {
        while (arg0 < 60 && func_800BFA44_5C8E4(arg0) == NULL) {
            arg0++;
        }
        D_80250944_A1AB94 = arg0;
    }
}

s16* func_801E3A34_9ADC84(s32 arg0) {
    if (!func_800BFA44_5C8E4(arg0)) {
        return NULL;
    }

    return func_800BF534_5C3D4(arg0);
}

s32 func_801E3A80_9ADCD0(void) {
    return D_80250940_A1AB90;
}

s32 func_801E3A9C_9ADCEC(void) {
    return D_80250944_A1AB94;
}

s32 func_801E3AB8_9ADD08(void) {
    return D_8025093C_A1AB8C;
}

s32 func_801E3AD4_9ADD24(s32 arg0) {
    s32 sp1C;

    sp1C = arg0 / 6;
    if (func_801DCD20_9A6F70() == sp1C) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9ADAD0/func_801E3B34_9ADD84.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9ADAD0/func_801E3F00_9AE150.s")
void func_801E3F00_9AE150(void) {
    s32 sp1C;

    sp1C = D_80250550_A1A7A0;
    if (D_80250174_A1A3C4 < 0.0f) {
        auPlaySound(0x41);
        return;
    }
    auPlaySound(0x4A);
    D_80250558_A1A7A8 = D_80250170_A1A3C0;
    func_801E389C_9ADAEC(&D_80250170_A1A3C0 + 1, &D_80250558_A1A7A8 + 1);
    func_800BF954_5C7F4(sp1C, &D_80250558_A1A7A8, &D_80250558_A1A7A8 + 1);
    if (func_801E3AD4_9ADD24(sp1C) != 0) {
        func_801DDB54_9A7DA4(sp1C);
    }

    D_80250174_A1A3C4 = -1.0f;
    D_80250550_A1A7A0 = -1;
    D_8025093C_A1AB8C++;

    if (D_80250940_A1AB90 < sp1C) {
        D_80250940_A1AB90 = sp1C;
    }
    if (D_80250944_A1AB94 > sp1C) {
        D_80250944_A1AB94 = sp1C;
    }
}

PhotoData* func_801E4068_9AE2B8(void) {
    return &D_80250170_A1A3C0;
}

void func_801E4084_9AE2D4(void);
#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_5/9ADAD0/func_801E4084_9AE2D4.s")

void func_801E41AC_9AE3FC(void) {
    UNUSED s32 pad;

    if (D_80208C40_9D2E90) {
        D_80208C40_9D2E90 = FALSE;
    }
}
