#include "common.h"
#include "level_low.h"

typedef struct UnkGoldViper {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ WorldBlock* unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
} UnkGoldViper; // size >= 0x28

extern void (*D_800E6B20_642D0)(WorldBlock*);
extern void (*D_800E6B24_642D4)(s32);
extern f32 D_800E6BD0_64380;

f32 func_800E3560_60D10(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return (arg1 - arg0) * (arg4 - arg2) / (arg3 - arg2) + arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/60D10/func_800E3590_60D40.s")
void func_800E3590_60D40(WorldBlock* arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6, f32* arg7, f32* arg8, f32* arg9);

#ifdef NON_MATCHING
void func_800E3968_61118(WorldBlock* arg0, f32 arg1, f32* arg2) {
    s32 temp_a1;
    s32 i;
    s32 a0;
    f32 f2;
    f32 f0;

    if (arg0 ==NULL ||
        arg0->blockUV == NULL ||
        arg0->unk_18 == NULL ||
        arg0->descriptor == NULL ||
        arg0->descriptor->gfx == NULL ||
        arg0->descriptor->gfx->unk_18 == NULL)
    {
        return;
    }

    temp_a1 = arg0->descriptor->gfx->unk_14 - 1;
    if (temp_a1 <= 0) {
        return;
    }

    if (arg1 < 0.0f) {
        arg1 = 0;
    }
    if (arg1 > 1.0f) {
        arg1 = 1.0f;
    }
    if (arg0->descriptor->unk_14 != 0) {
        arg1 = 1.0f - arg1;
    }
    if (temp_a1 == 1) {
        *arg2 = arg0->unk_18->unk_00[1]->scale.v.x;
        return;
    }

    a0 = 1;
    for (i = 2; i < temp_a1; i++) {
        a0 = i;
        if (arg1 <= arg0->descriptor->gfx->unk_20[i - 2]) {
            a0 = i - 1;
            break;
        }
    }

    i = a0 + 1;
    if (i <= temp_a1) {
        if (a0 < 2 || temp_a1 < 3) {
            f2 = 0;
        } else {
            f2 = arg0->descriptor->gfx->unk_20[a0 - 2];
        }

        if (i >= temp_a1) {
            f0 = 1.0f;
        } else {
            f0 = arg0->descriptor->gfx->unk_20[i - 2];
        }

        *arg2 = func_800E3560_60D10(arg0->unk_18->unk_00[a0]->scale.v.x, arg0->unk_18->unk_00[i]->scale.v.x, f2, f0, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/60D10/func_800E3968_61118.s")
void func_800E3968_61118(WorldBlock* arg0, f32 arg1, f32* arg2);
#endif

void func_800E3B0C_612BC(WorldBlock* arg0, f32 arg1, f32 arg2, UnkGoldViper* arg3) {
    f32 sp6C, sp68, sp64, sp60, sp5C, sp58, sp54;
    f32 sp50;
    f32 f14;
    f32 cosAngle, sinAngle;

    if (D_800E6B24_642D4 != NULL) {
        D_800E6B24_642D4(arg0->index);
    }

    func_800E3590_60D40(arg0, arg1, arg2, &sp6C, &sp68, &sp64, &sp60, &sp5C, &sp58, &sp54);

    if (arg0->next ==NULL ||
        arg0->next->blockUV == NULL ||
        arg0->next->unk_18 == NULL ||
        arg0->next->descriptor == NULL ||
        arg0->next->descriptor->gfx == NULL ||
        arg0->next->descriptor->gfx->uvScrollAnim == NULL ||
        arg0->next->descriptor->gfx->unk_18 == NULL ||
        arg0->next->descriptor->gfx->unk_14 < 2)
    {
        f14 = sp54;
    } else {
        func_800E3968_61118(arg0->next, arg2, &sp50);
        f14 = sp54 + (sp50 - sp54) * arg1;
    }

    sp5C = sp5C + arg0->descriptor->yaw;
    if (arg0->descriptor->unk_14 != 0) {
        sp5C += 3.1415927f;
    }
    arg3->unk_1C = sp5C;

    cosAngle = cosf(arg0->descriptor->yaw);
    sinAngle = sinf(arg0->descriptor->yaw);

    arg3->unk_0C = cosAngle * sp6C + sinAngle * sp64;
    arg3->unk_14 = -sinAngle * sp6C + cosAngle * sp64;
    arg3->unk_10 = sp68;    

    arg3->unk_18 = sp60;
    arg3->unk_20 = sp58;

    arg3->unk_24 = arg3->unk_28 * f14;
    
    arg3->unk_0C = arg3->unk_0C;
    arg3->unk_10 = arg3->unk_10;
    arg3->unk_14 = arg3->unk_14;
}

void func_800E3D04_614B4(UnkGoldViper* arg0) {
    WorldBlock* block;
    f32 f0, f14;

    block = arg0->unk_08;
    if (block == NULL) {
        return;
    }

    f14 = arg0->unk_04;
    if (f14 < 0.0f) {
        f14 = 0;
    }
    if (f14 > 1.0f) {
        f14 = 1.0f;
    }
    f0 = arg0->unk_00;
    if (f0 < 0.0f) {
        f0 = 0;
    }
    if (f0 > 1.0f) {
        f0 = 1.0f;
    }

    if (arg0->unk_24 + f0 > 1.0f) {
        if (D_800E6B20_642D0 != 0) {
            D_800E6B20_642D0(block);
        }
        
        if (block->next == NULL || block->next->unk_18 == NULL) {
            func_800E3B0C_612BC(block, f0, f14, arg0);
            arg0->unk_24 = 0;
            return;
        }

        f0 = arg0->unk_24 + f0 - 1.0f;
        block = func_800E2400_5FBB0();
        if (block == NULL) {
            return;
        }
        arg0->unk_08 = block;
        
        if (block->blockUV != NULL && block->descriptor != NULL && block->descriptor->gfx != NULL && block->descriptor->gfx->unk_18 != NULL) {
            animSetModelTreeAnimation(block->blockUV, block->descriptor->gfx->unk_18, 0);
        }
    } else {
        f0 = arg0->unk_24 + f0;
    }

    func_800E3B0C_612BC(block, f0, f14, arg0);
    arg0->unk_00 = f0;
}

void func_800E3EE8_61698(UnkGoldViper* arg0, s32 arg1, void (*arg2)(WorldBlock*), void (*arg3)(s32)) {
    f32 unused;
    f32 f0, f2;
    WorldBlock* block;
    

    D_800E6B20_642D0 = arg2;
    D_800E6B24_642D4 = arg3;

    if (arg0->unk_28 < 0.0f || arg1 < 0 || arg1 >= 13) {
        return;
    }
    
    f0 = arg0->unk_00;
    f2 = arg0->unk_04;
    if (f0 < 0.0f) {
        f0 = 0;
    }
    if (f0 > 1.0f) {
        f0 = 1.0f;
    }
    if (f2 < 0.0f) {
        f2 = 0;
    }
    if (f2 > 1.0f) {
        f2 = 1.0f;
    }

    block = func_800E26CC_5FE7C(arg1);
    if (block != NULL) {
        arg0->unk_08 = block;
        arg0->unk_24 = 0;
        func_800E3B0C_612BC(block, f0, f2, arg0);
    }
}

