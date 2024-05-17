#include "world.h"

void (*WorldCamera_ExitBlockCB)(WorldBlock*) = NULL;
void (*D_800E6B24_642D4)(s32) = NULL;

f32 interpolateLinear(f32 val1, f32 val2, f32 startTime, f32 endTime, f32 currentTime) {
    return (val2 - val1) * (currentTime - startTime) / (endTime - startTime) + val1;
}

void func_800E3590_60D40(WorldBlock* block, f32 arg1, f32 arg2, f32* posX, f32* posY, f32* posZ, f32* rotX, f32* rotY, f32* rotZ, f32* speed) {
    GObj* blockUV;
    f32 nv;
    s32 a0, i;
    f32 startTime, endTime;
    s32 temp_a2;
    s32 unused;
    DObj* dobj1;
    DObj* dobj2;


    *posX = *posY = *posZ = *rotX = *rotY = *rotZ = *speed = 0;

    if (block == NULL) {
        return;
    }
    if (block->blockUV == NULL) {
        return;
    }
    if (block->unk_18 == NULL) {
        return;
    }
    if (block->descriptor == NULL ||
        block->descriptor->gfx == NULL ||
        block->descriptor->gfx->unk_18 == NULL)
    {
        return;
    }

    temp_a2 = block->descriptor->gfx->unk_14 - 1;
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

    if (block->descriptor->unk_14 != 0) {
        arg1 = 1.0f - arg1;
        arg2 = 1.0f - arg2;
    }
    blockUV = block->blockUV;
    nv = block->descriptor->gfx->unk_1C * arg1;
    animSetModelAnimationSpeed(blockUV, nv - blockUV->animationTime);
    animUpdateModelTreeAnimation(blockUV);

    if (temp_a2 == 1) {
        dobj1 = block->unk_18[1];
        *posX = dobj1->position.v.x;
        *posY = dobj1->position.v.y;
        *posZ = dobj1->position.v.z;
        *rotX = dobj1->rotation.f[1];
        *rotY = dobj1->rotation.f[2];
        *rotZ = dobj1->rotation.f[3];
        *speed = dobj1->scale.v.x;
        return;
    }

    a0 = 1;
    for (i = 2; i < temp_a2; i++) {
        a0 = i;
        if (arg2 <= block->descriptor->gfx->unk_20[i - 2]) {
            a0 = i - 1;
            break;
        }
    }

    i = a0 + 1;
    if (i <= temp_a2) {
        if (a0 < 2 || temp_a2 < 3) {
            startTime = 0;
        } else {
            startTime = block->descriptor->gfx->unk_20[a0 - 2];
        }

        if (i >= temp_a2) {
            endTime = 1.0f;
        } else {
            endTime = block->descriptor->gfx->unk_20[i - 2];
        }
        dobj1 = block->unk_18[a0];
        dobj2 = block->unk_18[i];
        *posX = interpolateLinear(dobj1->position.v.x, dobj2->position.v.x, startTime, endTime, arg2);
        *posY = interpolateLinear(dobj1->position.v.y, dobj2->position.v.y, startTime, endTime, arg2);
        *posZ = interpolateLinear(dobj1->position.v.z, dobj2->position.v.z, startTime, endTime, arg2);
        *rotX = interpolateLinear(dobj1->rotation.f[1], dobj2->rotation.f[1], startTime, endTime, arg2);
        *rotY = interpolateLinear(dobj1->rotation.f[2], dobj2->rotation.f[2], startTime, endTime, arg2);
        *rotZ = interpolateLinear(dobj1->rotation.f[3], dobj2->rotation.f[3], startTime, endTime, arg2);
        *speed = interpolateLinear(dobj1->scale.v.x, dobj2->scale.v.x, startTime, endTime, arg2);
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
        *arg2 = interpolateLinear(dobj1->scale.v.x, dobj2->scale.v.x, f2, f0, arg1);
    }
}

void func_800E3B0C_612BC(WorldBlock* block, f32 arg1, f32 arg2, WorldCameraState* camState) {
    f32 sp6C, sp68, sp64, sp60, sp5C, sp58, sp54;
    f32 sp50;
    f32 speedFactor;
    f32 cosAngle, sinAngle;

    if (D_800E6B24_642D4 != NULL) {
        D_800E6B24_642D4(block->index);
    }

    func_800E3590_60D40(block, arg1, arg2, &sp6C, &sp68, &sp64, &sp60, &sp5C, &sp58, &sp54);

    if (block->next == NULL ||
        block->next->blockUV == NULL ||
        block->next->unk_18 == NULL ||
        block->next->descriptor == NULL ||
        block->next->descriptor->gfx == NULL ||
        block->next->descriptor->gfx->uvScrollAnim == NULL ||
        block->next->descriptor->gfx->unk_18 == NULL ||
        block->next->descriptor->gfx->unk_14 < 2)
    {
        speedFactor = sp54;
    } else {
        func_800E3968_61118(block->next, arg2, &sp50);
        speedFactor = sp54 + (sp50 - sp54) * arg1;
    }

    sp5C = sp5C + block->descriptor->yaw;
    if (block->descriptor->unk_14 != 0) {
        sp5C += 3.1415927f;
    }
    camState->rotation.y = sp5C;

    cosAngle = cosf(block->descriptor->yaw);
    sinAngle = sinf(block->descriptor->yaw);

    camState->pos.x = cosAngle * sp6C + sinAngle * sp64;
    camState->pos.z = -sinAngle * sp6C + cosAngle * sp64;
    camState->pos.y = sp68;

    camState->rotation.x = sp60;
    camState->rotation.z = sp58;

    camState->moveSpeed = camState->baseMoveSpeed * speedFactor;

    camState->pos.x = camState->pos.x;
    camState->pos.y = camState->pos.y;
    camState->pos.z = camState->pos.z;
}

void func_800E3D04_614B4(WorldCameraState* camState) {
    WorldBlock* block;
    f32 progress, f14;

    block = camState->block;
    if (block == NULL) {
        return;
    }

    f14 = camState->unk_04;
    if (f14 < 0.0f) {
        f14 = 0;
    }
    if (f14 > 1.0f) {
        f14 = 1.0f;
    }
    progress = camState->progress;
    if (progress < 0.0f) {
        progress = 0;
    }
    if (progress > 1.0f) {
        progress = 1.0f;
    }

    if (camState->moveSpeed + progress > 1.0f) {
        // enter next block
        if (WorldCamera_ExitBlockCB != NULL) {
            WorldCamera_ExitBlockCB(block);
        }

        if (block->next == NULL || block->next->unk_18 == NULL) {
            // stop movement
            func_800E3B0C_612BC(block, progress, f14, camState);
            camState->moveSpeed = 0;
            return;
        }

        progress = camState->moveSpeed + progress - 1.0f;
        block = enterNextBlock();
        if (block == NULL) {
            return;
        }
        camState->block = block;

        if (block->blockUV != NULL && block->descriptor != NULL && block->descriptor->gfx != NULL && block->descriptor->gfx->unk_18 != NULL) {
            animSetModelTreeAnimation(block->blockUV, block->descriptor->gfx->unk_18, 0);
        }
    } else {
        progress = camState->moveSpeed + progress;
    }

    func_800E3B0C_612BC(block, progress, f14, camState);
    camState->progress = progress;
}

void func_800E3EE8_61698(WorldCameraState* arg0, s32 blockID, void (*arg2)(WorldBlock*), void (*arg3)(s32)) {
    f32 unused;
    f32 f0, f2;
    WorldBlock* block;


    WorldCamera_ExitBlockCB = arg2;
    D_800E6B24_642D4 = arg3;

    if (arg0->baseMoveSpeed < 0.0f || blockID < 0 || blockID >= MAX_BLOCKS) {
        return;
    }

    f0 = arg0->progress;
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

    block = func_800E26CC_5FE7C(blockID);
    if (block != NULL) {
        arg0->block = block;
        arg0->moveSpeed = 0;
        func_800E3B0C_612BC(block, f0, f2, arg0);
    }
}

