#include "world.h"

void (*D_800E6B20_642D0)(WorldBlock*) = NULL;
void (*D_800E6B24_642D4)(s32) = NULL;

f32 func_800E3560_60D10(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    return (arg1 - arg0) * (arg4 - arg2) / (arg3 - arg2) + arg0;
}

void func_800E3590_60D40(WorldBlock* arg0, f32 arg1, f32 arg2, f32* arg3, f32* arg4, f32* arg5, f32* arg6, f32* arg7, f32* arg8, f32* arg9) {
    GObj* blockUV;
    f32 nv;
    s32 a0, i;
    f32 f2, f0;
    s32 temp_a2;
    s32 unused;
    DObj* dobj1;
    DObj* dobj2;
    

    *arg3 = *arg4 = *arg5 = *arg6 = *arg7 = *arg8 = *arg9 = 0;

    if (arg0 == NULL) {
        return;
    } 
    if (arg0->blockUV == NULL) {
        return;
    }
    if (arg0->unk_18 == NULL) {
        return;
    }
    if (arg0->descriptor == NULL ||
        arg0->descriptor->gfx == NULL ||
        arg0->descriptor->gfx->unk_18 == NULL)
    {
        return;
    }

    temp_a2 = arg0->descriptor->gfx->unk_14 - 1;
    if (temp_a2 <= 0) {
        return;
    }

    if (arg1 < 0.0f) {
        arg1 = 0;
    }
    if (arg1 > 1.0f) {
        arg1 = 1.0f;
    }
    if (arg2 < 0.0f) {
        arg2 = 0;
    }
    if (arg2 > 1.0f) {
        arg2 = 1.0f;
    }

    if (arg0->descriptor->unk_14 != 0) {
        arg1 = 1.0f - arg1;
        arg2 = 1.0f - arg2;
    }
    blockUV = arg0->blockUV;
    nv = arg0->descriptor->gfx->unk_1C * arg1;
    animSetModelAnimationSpeed(blockUV, nv - blockUV->animationTime);
    animUpdateModelTreeAnimation(blockUV);

    if (temp_a2 == 1) {
        dobj1 = arg0->unk_18[1];
        *arg3 = dobj1->position.v.x;
        *arg4 = dobj1->position.v.y;
        *arg5 = dobj1->position.v.z;
        *arg6 = dobj1->rotation.f[1];
        *arg7 = dobj1->rotation.f[2];
        *arg8 = dobj1->rotation.f[3];
        *arg9 = dobj1->scale.v.x;
        return;
    }

    a0 = 1;
    for (i = 2; i < temp_a2; i++) {
        a0 = i;
        if (arg2 <= arg0->descriptor->gfx->unk_20[i - 2]) {
            a0 = i - 1;
            break;
        }
    }

    i = a0 + 1;
    if (i <= temp_a2) {
        if (a0 < 2 || temp_a2 < 3) {
            f2 = 0;
        } else {
            f2 = arg0->descriptor->gfx->unk_20[a0 - 2];
        }

        if (i >= temp_a2) {
            f0 = 1.0f;
        } else {
            f0 = arg0->descriptor->gfx->unk_20[i - 2];
        }
        dobj1 = arg0->unk_18[a0];
        dobj2 = arg0->unk_18[i];
        *arg3 = func_800E3560_60D10(dobj1->position.v.x, dobj2->position.v.x, f2, f0, arg2);
        *arg4 = func_800E3560_60D10(dobj1->position.v.y, dobj2->position.v.y, f2, f0, arg2);
        *arg5 = func_800E3560_60D10(dobj1->position.v.z, dobj2->position.v.z, f2, f0, arg2);
        *arg6 = func_800E3560_60D10(dobj1->rotation.f[1], dobj2->rotation.f[1], f2, f0, arg2);
        *arg7 = func_800E3560_60D10(dobj1->rotation.f[2], dobj2->rotation.f[2], f2, f0, arg2);
        *arg8 = func_800E3560_60D10(dobj1->rotation.f[3], dobj2->rotation.f[3], f2, f0, arg2);
        *arg9 = func_800E3560_60D10(dobj1->scale.v.x, dobj2->scale.v.x, f2, f0, arg2);
    }
}

void func_800E3968_61118(WorldBlock* arg0, f32 arg1, f32* arg2) {
    s32 temp_a1;
    s32 i;
    s32 a0;
    f32 f2;
    f32 f0;
    DObj* dobj1;
    DObj* dobj2;
    WorldBlock* block = arg0;

    if (arg0 ==NULL ||
        arg0->blockUV == NULL ||
        arg0->unk_18 == NULL ||
        arg0->descriptor == NULL ||
        arg0->descriptor->gfx == NULL ||
        arg0->descriptor->gfx->unk_18 == NULL)
    {
        return;
    }

    temp_a1 = block->descriptor->gfx->unk_14 - 1;
    if (temp_a1 <= 0) {
        return;
    }

    if (arg1 < 0.0f) {
        arg1 = 0;
    }
    if (arg1 > 1.0f) {
        arg1 = 1.0f;
    }
    if (block->descriptor->unk_14 != 0) {
        arg1 = 1.0f - arg1;
    }
    if (temp_a1 == 1) {
        *arg2 = block->unk_18[1]->scale.v.x;
        return;
    }

    a0 = 1;
    for (i = 2; i < temp_a1; i++) {
        a0 = i;
        if (arg1 <= block->descriptor->gfx->unk_20[i - 2]) {
            a0 = i - 1;
            break;
        }
    }

    i = a0 + 1;
    if (i <= temp_a1) {
        if (a0 < 2 || temp_a1 < 3) {
            f2 = 0;
        } else {
            f2 = block->descriptor->gfx->unk_20[a0 - 2];
        }

        if (i >= temp_a1) {
            f0 = 1.0f;
        } else {
            f0 = block->descriptor->gfx->unk_20[i - 2];
        }
        
        dobj1 = block->unk_18[a0];
        dobj2 = block->unk_18[i];
        *arg2 = func_800E3560_60D10(dobj1->scale.v.x, dobj2->scale.v.x, f2, f0, arg1);
    }
}

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

