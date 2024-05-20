#include "world.h"

void (*Movement_ExitBlockCB)(WorldBlock*) = NULL;
void (*Movement_UpdateCB)(s32) = NULL;

f32 interpolateLinear(f32 val1, f32 val2, f32 startTime, f32 endTime, f32 currentTime) {
    return (val2 - val1) * (currentTime - startTime) / (endTime - startTime) + val1;
}

void getMovementPos(WorldBlock* block, f32 moveTime, f32 cpTime, f32* posX, f32* posY, f32* posZ, f32* rotX, f32* rotY, f32* rotZ, f32* speed) {
    GObj* blockUV;
    f32 nv;
    s32 a0, i;
    f32 startTime, endTime;
    s32 numSegments;
    s32 unused;
    DObj* firstCP;
    DObj* secondCP;


    *posX = *posY = *posZ = *rotX = *rotY = *rotZ = *speed = 0;

    if (block == NULL) {
        return;
    }
    if (block->blockUV == NULL) {
        return;
    }
    if (block->cpObjects == NULL) {
        return;
    }
    if (block->descriptor == NULL ||
        block->descriptor->gfx == NULL ||
        block->descriptor->gfx->movementAnim == NULL)
    {
        return;
    }

    numSegments = block->descriptor->gfx->numControlPoints - 1;
    if (numSegments <= 0) {
        return;
    }

    if (moveTime < 0.0f) {
        moveTime = 0;
    }
    if (moveTime > 1.0f) {
        moveTime = 1.0f;
    }
    if (cpTime < 0.0f) {
        cpTime = 0;
    }
    if (cpTime > 1.0f) {
        cpTime = 1.0f;
    }

    if (block->descriptor->reversed) {
        moveTime = 1.0f - moveTime;
        cpTime = 1.0f - cpTime;
    }
    blockUV = block->blockUV;
    nv = block->descriptor->gfx->movementAnimDuration * moveTime;
    animSetModelAnimationSpeed(blockUV, nv - blockUV->animationTime);
    animUpdateModelTreeAnimation(blockUV);

    if (numSegments == 1) {
        firstCP = block->cpObjects[1];
        *posX = firstCP->position.v.x;
        *posY = firstCP->position.v.y;
        *posZ = firstCP->position.v.z;
        *rotX = firstCP->rotation.f[1];
        *rotY = firstCP->rotation.f[2];
        *rotZ = firstCP->rotation.f[3];
        *speed = firstCP->scale.v.x;
        return;
    }

    a0 = 1;
    for (i = 2; i < numSegments; i++) {
        a0 = i;
        if (cpTime <= block->descriptor->gfx->cpTimeStamps[i - 2]) {
            a0 = i - 1;
            break;
        }
    }

    i = a0 + 1;
    if (i <= numSegments) {
        if (a0 < 2 || numSegments < 3) {
            startTime = 0;
        } else {
            startTime = block->descriptor->gfx->cpTimeStamps[a0 - 2];
        }

        if (i >= numSegments) {
            endTime = 1.0f;
        } else {
            endTime = block->descriptor->gfx->cpTimeStamps[i - 2];
        }
        firstCP = block->cpObjects[a0];
        secondCP = block->cpObjects[i];
        *posX = interpolateLinear(firstCP->position.v.x, secondCP->position.v.x, startTime, endTime, cpTime);
        *posY = interpolateLinear(firstCP->position.v.y, secondCP->position.v.y, startTime, endTime, cpTime);
        *posZ = interpolateLinear(firstCP->position.v.z, secondCP->position.v.z, startTime, endTime, cpTime);
        *rotX = interpolateLinear(firstCP->rotation.f[1], secondCP->rotation.f[1], startTime, endTime, cpTime);
        *rotY = interpolateLinear(firstCP->rotation.f[2], secondCP->rotation.f[2], startTime, endTime, cpTime);
        *rotZ = interpolateLinear(firstCP->rotation.f[3], secondCP->rotation.f[3], startTime, endTime, cpTime);
        *speed = interpolateLinear(firstCP->scale.v.x, secondCP->scale.v.x, startTime, endTime, cpTime);
    }
}

void getNextBlockSpeed(WorldBlock* arg0, f32 cpTime, f32* speed) {
    s32 temp_a1;
    s32 i;
    s32 a0;
    f32 cp1TimeStamp;
    f32 cp2TimeStamp;
    DObj* firstCP;
    DObj* secondCP;
    WorldBlock* block = arg0;

    if (arg0 ==NULL ||
        arg0->blockUV == NULL ||
        arg0->cpObjects == NULL ||
        arg0->descriptor == NULL ||
        arg0->descriptor->gfx == NULL ||
        arg0->descriptor->gfx->movementAnim == NULL)
    {
        return;
    }

    temp_a1 = block->descriptor->gfx->numControlPoints - 1;
    if (temp_a1 <= 0) {
        return;
    }

    if (cpTime < 0.0f) {
        cpTime = 0;
    }
    if (cpTime > 1.0f) {
        cpTime = 1.0f;
    }
    if (block->descriptor->reversed) {
        cpTime = 1.0f - cpTime;
    }
    if (temp_a1 == 1) {
        *speed = block->cpObjects[1]->scale.v.x;
        return;
    }

    a0 = 1;
    for (i = 2; i < temp_a1; i++) {
        a0 = i;
        if (cpTime <= block->descriptor->gfx->cpTimeStamps[i - 2]) {
            a0 = i - 1;
            break;
        }
    }

    i = a0 + 1;
    if (i <= temp_a1) {
        if (a0 < 2 || temp_a1 < 3) {
            cp1TimeStamp = 0;
        } else {
            cp1TimeStamp = block->descriptor->gfx->cpTimeStamps[a0 - 2];
        }

        if (i >= temp_a1) {
            cp2TimeStamp = 1.0f;
        } else {
            cp2TimeStamp = block->descriptor->gfx->cpTimeStamps[i - 2];
        }

        firstCP = block->cpObjects[a0];
        secondCP = block->cpObjects[i];
        *speed = interpolateLinear(firstCP->scale.v.x, secondCP->scale.v.x, cp1TimeStamp, cp2TimeStamp, cpTime);
    }
}

void Movement_UpdatePos(WorldBlock* block, f32 moveTime, f32 cpTime, MovementState* state) {
    f32 posX, posY, posZ, rotX, rotY, rotZ, speed;
    f32 nextBlockSpeed;
    f32 animSpeed;
    f32 cosAngle, sinAngle;

    if (Movement_UpdateCB != NULL) {
        Movement_UpdateCB(block->index);
    }

    getMovementPos(block, moveTime, cpTime, &posX, &posY, &posZ, &rotX, &rotY, &rotZ, &speed);

    if (block->next == NULL ||
        block->next->blockUV == NULL ||
        block->next->cpObjects == NULL ||
        block->next->descriptor == NULL ||
        block->next->descriptor->gfx == NULL ||
        block->next->descriptor->gfx->uvScrollAnim == NULL ||
        block->next->descriptor->gfx->movementAnim == NULL ||
        block->next->descriptor->gfx->numControlPoints < 2)
    {
        animSpeed = speed;
    } else {
        getNextBlockSpeed(block->next, cpTime, &nextBlockSpeed);
        animSpeed = speed + (nextBlockSpeed - speed) * moveTime;
    }

    rotY = rotY + block->descriptor->yaw;
    if (block->descriptor->reversed) {
        rotY += 3.1415927f;
    }
    state->rotation.y = rotY;

    cosAngle = cosf(block->descriptor->yaw);
    sinAngle = sinf(block->descriptor->yaw);

    state->pos.x = cosAngle * posX + sinAngle * posZ;
    state->pos.z = -sinAngle * posX + cosAngle * posZ;
    state->pos.y = posY;

    state->rotation.x = rotX;
    state->rotation.z = rotZ;

    state->moveSpeed = state->speedMult * animSpeed;

    state->pos.x = state->pos.x;
    state->pos.y = state->pos.y;
    state->pos.z = state->pos.z;
}

void Movement_Update(MovementState* state) {
    WorldBlock* block;
    f32 moveTime, cpTime;

    block = state->block;
    if (block == NULL) {
        return;
    }

    cpTime = state->cpTime;
    if (cpTime < 0.0f) {
        cpTime = 0;
    }
    if (cpTime > 1.0f) {
        cpTime = 1.0f;
    }
    moveTime = state->moveTime;
    if (moveTime < 0.0f) {
        moveTime = 0;
    }
    if (moveTime > 1.0f) {
        moveTime = 1.0f;
    }

    if (state->moveSpeed + moveTime > 1.0f) {
        // enter next block
        if (Movement_ExitBlockCB != NULL) {
            Movement_ExitBlockCB(block);
        }

        if (block->next == NULL || block->next->cpObjects == NULL) {
            // stop movement
            Movement_UpdatePos(block, moveTime, cpTime, state);
            state->moveSpeed = 0;
            return;
        }

        moveTime = state->moveSpeed + moveTime - 1.0f;
        block = enterNextBlock();
        if (block == NULL) {
            return;
        }
        state->block = block;

        if (block->blockUV != NULL && block->descriptor != NULL && block->descriptor->gfx != NULL && block->descriptor->gfx->movementAnim != NULL) {
            animSetModelTreeAnimation(block->blockUV, block->descriptor->gfx->movementAnim, 0);
        }
    } else {
        moveTime = state->moveSpeed + moveTime;
    }

    Movement_UpdatePos(block, moveTime, cpTime, state);
    state->moveTime = moveTime;
}

void Movement_Init(MovementState* state, s32 blockID, void (*exitBlockCB)(WorldBlock*), void (*updateMovementCB)(s32)) {
    f32 unused;
    f32 f0, f2;
    WorldBlock* block;


    Movement_ExitBlockCB = exitBlockCB;
    Movement_UpdateCB = updateMovementCB;

    if (state->speedMult < 0.0f || blockID < 0 || blockID >= MAX_BLOCKS) {
        return;
    }

    f0 = state->moveTime;
    f2 = state->cpTime;
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

    block = enterFirstBlock(blockID);
    if (block != NULL) {
        state->block = block;
        state->moveSpeed = 0;
        Movement_UpdatePos(block, f0, f2, state);
    }
}

