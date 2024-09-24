#include "string.h"
#include "world.h"

CollisionModel* sCollisionModels = NULL;

struct MatrixStruct {
    f32 x00, x01, x02, x03;
    f32 x10, x11, x12, x13;
    f32 x20, x21, x22, x23;
    f32 x30, x31, x32, x33;
};

f32 dot_product(Vec3f* v1, Vec3f* v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

void transform_point(Mtx4f arg0, Vec3f* arg1) {
    s32 i;
    f32 temp[3];

    for (i = 0; i < 3; i++) {
        temp[i] = arg1->x * arg0[0][i] + arg1->y * arg0[1][i] + arg1->z * arg0[2][i] + arg0[3][i];
    }

    arg1->x = temp[0];
    arg1->y = temp[1];
    arg1->z = temp[2];
}

void transform_point_zero_w(Mtx4f arg0, Vec3f* arg1) {
    s32 i;
    f32 temp[3];

    for (i = 0; i < 3; i++) {
        temp[i] = arg1->x * arg0[0][i] + arg1->y * arg0[1][i] + arg1->z * arg0[2][i];
    }

    arg1->x = temp[0];
    arg1->y = temp[1];
    arg1->z = temp[2];
}

void copy_matrix(Mtx4f dst, Mtx4f src) {
    dst[0][0] = src[0][0];
    dst[0][1] = src[0][1];
    dst[0][2] = src[0][2];
    dst[0][3] = src[0][3];
    dst[1][0] = src[1][0];
    dst[1][1] = src[1][1];
    dst[1][2] = src[1][2];
    dst[1][3] = src[1][3];
    dst[2][0] = src[2][0];
    dst[2][1] = src[2][1];
    dst[2][2] = src[2][2];
    dst[2][3] = src[2][3];
    dst[3][0] = src[3][0];
    dst[3][1] = src[3][1];
    dst[3][2] = src[3][2];
    dst[3][3] = src[3][3];
}

// identical to guMtxCatF
void multiply_matrix(Mtx4f arg0, Mtx4f arg1, Mtx4f arg2) {
    s32 i, j, k;
    Mtx4f temp;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = 0.0f;
            for (k = 0; k < 4; k++) {
                temp[i][j] += arg1[i][k] * arg2[k][j];
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg0[i][j] = temp[i][j];
        }
    }
}

void transpose_matrix(Mtx4f dst, Mtx4f src) {
    s32 i, j;
    Mtx4f temp;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            temp[i][j] = src[j][i];
        }
    }

    memcpy(dst, temp, sizeof(Mtx4f));
}

// added to match extra "jr ra; nop"
static void nullsub() {
}

void create_identity_matrix(Mtx4f dst) {
    static struct MatrixStruct D_800E6B44_642F4 = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
    dst[0][0] = D_800E6B44_642F4.x00;
    dst[0][1] = D_800E6B44_642F4.x01;
    dst[0][2] = D_800E6B44_642F4.x02;
    dst[0][3] = D_800E6B44_642F4.x03;
    dst[1][0] = D_800E6B44_642F4.x10;
    dst[1][1] = D_800E6B44_642F4.x11;
    dst[1][2] = D_800E6B44_642F4.x12;
    dst[1][3] = D_800E6B44_642F4.x13;
    dst[2][0] = D_800E6B44_642F4.x20;
    dst[2][1] = D_800E6B44_642F4.x21;
    dst[2][2] = D_800E6B44_642F4.x22;
    dst[2][3] = D_800E6B44_642F4.x23;
    dst[3][0] = D_800E6B44_642F4.x30;
    dst[3][1] = D_800E6B44_642F4.x31;
    dst[3][2] = D_800E6B44_642F4.x32;
    dst[3][3] = D_800E6B44_642F4.x33;
}

void create_matrix(Mtx4f mtx, Mtx4f invMtx, Vec3f scale, Vec3f rotation, Vec3f translation) {
    f32 sinAngleX = sinf(rotation.x);
    f32 cosAngleX = cosf(rotation.x);
    f32 sinAngleY = sinf(rotation.y);
    f32 cosAngleY = cosf(rotation.y);
    f32 sinAngleZ = sinf(rotation.z);
    f32 cosAngleZ = cosf(rotation.z);
    Mtx4f temp;
    s32 unused;

    create_identity_matrix(mtx);
    create_identity_matrix(invMtx);

    mtx[0][0] = scale.x;
    mtx[1][1] = scale.y;
    mtx[2][2] = scale.z;
    mtx[3][3] = 1.0f;

    invMtx[0][0] = 1.0f / scale.x;
    invMtx[1][1] = 1.0f / scale.y;
    invMtx[2][2] = 1.0f / scale.z;
    invMtx[3][3] = 1.0f;

    create_identity_matrix(temp);
    temp[2][1] = -sinAngleX;
    temp[1][2] = sinAngleX;
    temp[1][1] = cosAngleX;
    temp[2][2] = cosAngleX;
    multiply_matrix(mtx, mtx, temp);
    transpose_matrix(temp, temp);
    multiply_matrix(invMtx, temp, invMtx);

    create_identity_matrix(temp);
    temp[0][2] = -sinAngleY;
    temp[2][0] = sinAngleY;
    temp[0][0] = cosAngleY;
    temp[2][2] = cosAngleY;
    multiply_matrix(mtx, mtx, temp);
    transpose_matrix(temp, temp);
    multiply_matrix(invMtx, temp, invMtx);

    create_identity_matrix(temp);
    temp[1][0] = -sinAngleZ;
    temp[0][1] = sinAngleZ;
    temp[0][0] = cosAngleZ;
    temp[1][1] = cosAngleZ;
    multiply_matrix(mtx, mtx, temp);
    transpose_matrix(temp, temp);
    multiply_matrix(invMtx, temp, invMtx);

    create_identity_matrix(temp);
    temp[3][0] = translation.x;
    temp[3][1] = translation.y;
    temp[3][2] = translation.z;
    multiply_matrix(mtx, mtx, temp);

    create_identity_matrix(temp);
    temp[3][0] = -translation.x;
    temp[3][1] = -translation.y;
    temp[3][2] = -translation.z;
    multiply_matrix(invMtx, temp, invMtx);
}

void make_transform(Collider* arg0, s32* arg1) {
    f32 unused[8];
    Mtx4f mtx;
    Mtx4f invMtx;

    if (arg0 != NULL) {
        create_matrix(mtx, invMtx, arg0->scale, arg0->rotation, arg0->position);
        if (arg0->hitBox != NULL) {
            HitBox* transform = arg0->hitBox;
            copy_matrix(transform->mtxLocalToGlobal, mtx);
            copy_matrix(transform->mtxGlobalToLocal, invMtx);
        }
    }
}

void reflect_from_plane(Vec3f* pos, Vec3f* vel, f32 time, s32 dir, Vec3f* outPos, Vec3f* outVel) {
    Vec3f dirVec;

    outPos->x = vel->x * time + pos->x;
    outPos->y = vel->y * time + pos->y;
    outPos->z = vel->z * time + pos->z;

    switch (dir) {
        case 1:
            dirVec.x = -1;
            dirVec.y = 0;
            dirVec.z = 0;
            break;
        case 2:
            dirVec.x = 1;
            dirVec.y = 0;
            dirVec.z = 0;
            break;
        case 3:
            dirVec.x = 0;
            dirVec.y = -1;
            dirVec.z = 0;
            break;
        case 4:
            dirVec.x = 0;
            dirVec.y = 1;
            dirVec.z = 0;
            break;
        case 5:
            dirVec.x = 0;
            dirVec.y = 0;
            dirVec.z = -1;
            break;
        case 6:
            dirVec.x = 0;
            dirVec.y = 0;
            dirVec.z = 1;
            break;
    }

    outVel->x = vel->x;
    outVel->y = vel->y;
    outVel->z = vel->z;
    Vec3fReflect(outVel, &dirVec);
}

s32 collide_with_box(Vec3f* inPos, Vec3f* inVel, f32 x1, f32 x2, f32 y1, f32 y2, f32 z1, f32 z2, Vec3f* outPos, Vec3f* outVel) {
    Vec3f velDir;
    f32 speed;
    f32 time = 0.0f;
    f32 minTime = FLOAT_MAX;
    f32 timeToEdge;
    s32 dir = 0;

    outVel->x = inVel->x;
    outVel->y = inVel->y;
    outVel->z = inVel->z;

    velDir.x = outVel->x;
    velDir.y = outVel->y;
    velDir.z = outVel->z;

    speed = Vec3fNormalize(&velDir);

    if (velDir.x < -0.0001f) {
        timeToEdge = (x1 - inPos->x) / velDir.x;
        if (timeToEdge < time) {
            return false;
        }

        if (timeToEdge <= minTime) {
            minTime = timeToEdge;
        }

        timeToEdge = (x2 - inPos->x) / velDir.x;
        if (timeToEdge >= time) {
            dir = 2;
            if (timeToEdge > minTime) {
                return false;
            }
            time = timeToEdge;
        }
    } else if (velDir.x > 0.0001f) {
        timeToEdge = (x2 - inPos->x) / velDir.x;
        if (timeToEdge < time) {
            return false;
        }

        if (timeToEdge <= minTime) {
            minTime = timeToEdge;
        }

        timeToEdge = (x1 - inPos->x) / velDir.x;
        if (timeToEdge >= time) {
            dir = 1;
            if (timeToEdge > minTime) {
                return false;
            }
            time = timeToEdge;
        }
    } else if (inPos->x < x1 || inPos->x > x2) {
        return false;
    }

    if (velDir.y < -0.0001f) {
        timeToEdge = (y1 - inPos->y) / velDir.y;
        if (timeToEdge < time) {
            return false;
        }

        if (timeToEdge <= minTime) {
            minTime = timeToEdge;
        }

        timeToEdge = (y2 - inPos->y) / velDir.y;
        if (timeToEdge >= time) {
            dir = 4;
            if (timeToEdge > minTime) {
                return false;
            }
            time = timeToEdge;
        }
    } else if (velDir.y > 0.0001f) {
        timeToEdge = (y2 - inPos->y) / velDir.y;
        if (timeToEdge < time) {
            return false;
        }

        if (timeToEdge <= minTime) {
            minTime = timeToEdge;
        }

        timeToEdge = (y1 - inPos->y) / velDir.y;
        if (timeToEdge >= time) {
            dir = 3;
            if (timeToEdge > minTime) {
                return false;
            }
            time = timeToEdge;
        }
    } else if (inPos->y < y1 || inPos->y > y2) {
        return false;
    }

    if (velDir.z < -0.0001f) {
        timeToEdge = (z1 - inPos->z) / velDir.z;
        if (timeToEdge < time) {
            return false;
        }

        if (timeToEdge <= minTime) {
            minTime = timeToEdge;
        }

        timeToEdge = (z2 - inPos->z) / velDir.z;
        if (timeToEdge >= time) {
            dir = 6;
            if (timeToEdge > minTime) {
                return false;
            }
            time = timeToEdge;
        }
    } else if (velDir.z > 0.0001f) {
        timeToEdge = (z2 - inPos->z) / velDir.z;
        if (timeToEdge < time) {
            return false;
        }

        if (timeToEdge <= minTime) {
            minTime = timeToEdge;
        }

        timeToEdge = (z1 - inPos->z) / velDir.z;
        if (timeToEdge >= time) {
            dir = 5;
            if (timeToEdge > minTime) {
                return false;
            }
            time = timeToEdge;
        }
    } else if (inPos->z < z1 || inPos->z > z2) {
        return false;
    }

    if (time < 0.0001f) {
        return false;
    }

    if (dir > 0 && time < speed) {
        reflect_from_plane(inPos, &velDir, time, dir, outPos, outVel);
        speed *= 0.7f;
        Vec3fScale(outVel, speed);
        return true;
    } else {
        return false;
    }
}

s32 collide_with_sphere(Vec3f* inPos, Vec3f* inVel, Vec3f* center, f32 radius, Vec3f* outPos, Vec3f* outVel) {
    f32 unused;
    f32 distToCenterSquared;
    f32 speed;
    f32 distToClosestPoint;
    f32 outPathLenSquared;
    f32 dist;
    f32 unused2;
    Vec3f vecToCenter;
    Vec3f normal;

    outVel->x = inVel->x;
    outVel->y = inVel->y;
    outVel->z = inVel->z;
    speed = Vec3fNormalize(outVel);
    Vec3fDiff(&vecToCenter, center, inPos);
    distToCenterSquared = dot_product(&vecToCenter, &vecToCenter);
    distToClosestPoint = dot_product(&vecToCenter, outVel);

    if (distToCenterSquared >= SQ(radius) || distToClosestPoint < 0.0001f) {
        return false;
    }

    outPathLenSquared = sqrtf(distToClosestPoint) + (SQ(radius) - distToCenterSquared); // BUG: SQ(distToClosestPoint) makes more sense
    if (outPathLenSquared > 0.0001f) {
        dist = distToClosestPoint - sqrtf(outPathLenSquared);
        if (dist < speed) {
            dist -= 12.0f;
            if (dist < 0.0f) {
                dist = 0.0f;
            }
            // move in the original direction
            outPos->x = inPos->x + dist * outVel->x;
            outPos->y = inPos->y + dist * outVel->y;
            outPos->z = inPos->z + dist * outVel->z;
            dist = speed - dist;
            // bounce
            Vec3fDirection(&normal, outPos, center);
            speed *= 0.7f;
            Vec3fReflect(outVel, &normal);
            // move in the new direction
            outPos->x += dist * outVel->x;
            outPos->y += dist * outVel->y;
            outPos->z += dist * outVel->z;
            Vec3fScale(outVel, speed);
            return true;
        }
    }
    return false;
}

void reflect_from_cylinder(Vec3f* pos, Vec3f* vel, f32 time, Vec3f* outPos, Vec3f* outVel) {
    Vec3f normal;

    outPos->x = pos->x + time * vel->x;
    outPos->y = pos->y + time * vel->y;
    outPos->z = pos->z + time * vel->z;

    normal.x = outPos->x;
    normal.y = 0.0f;
    normal.z = outPos->z;
    Vec3fNormalize(&normal);
    Vec3fReflect(outVel, &normal);
}

s32 collide_with_cylinder(Vec3f* inPos, Vec3f* inVel, Vec3f* center, f32 radius, f32 halfHeight, Vec3f* outPos, Vec3f* outVel) {
    Vec3f velDir;
    Vec3f vecFromCenter;
    f32 speed;
    f32 distToClosestPointSq;
    f32 unused1;
    f32 hSpeedSquared;
    f32 distToClosestPoint;
    f32 f12;
    f32 sp4C;
    f32 timeToClosestPoint;
    f32 sp44;
    f32 unused2;

    Vec3fDiff(&vecFromCenter, inPos, center);
    outVel->x = inVel->x;
    outVel->y = inVel->y;
    outVel->z = inVel->z;

    speed = Vec3fNormalize(outVel);
    velDir.x = outVel->x;
    velDir.y = outVel->y;
    velDir.z = outVel->z;

    hSpeedSquared = SQ(velDir.x) + SQ(velDir.z);
    if (hSpeedSquared > 0.0001f) {
        distToClosestPoint = vecFromCenter.x * velDir.x + vecFromCenter.z * velDir.z;
        distToClosestPointSq = SQ(distToClosestPoint);
        unused1 = SQ(vecFromCenter.x) + SQ(vecFromCenter.z) - SQ(radius);
        f12 = hSpeedSquared * unused1;
        sp4C = distToClosestPointSq - f12;
        if (f12 <= distToClosestPointSq) {
            timeToClosestPoint = (-distToClosestPoint - sqrtf(sp4C)) / hSpeedSquared;
            if (timeToClosestPoint > 0.0001f && sp44 < FLOAT_MAX) { // UB: sp44 uninitialized
                if (ABS(timeToClosestPoint * velDir.y + vecFromCenter.y) <= halfHeight && timeToClosestPoint < speed) {
                    reflect_from_cylinder(&vecFromCenter, &velDir, timeToClosestPoint, outPos, outVel);
                    speed *= 0.7f;
                    Vec3fScale(outVel, speed);
                    Vec3fAdd(outPos, center);
                    return true;
                }
            }
        }
    }
    return false;
}

void reflect_from_cylinder_copy(Vec3f* pos, Vec3f* vel, f32 time, Vec3f* outPos, Vec3f* outVel) {
    Vec3f normal;

    outPos->x = pos->x + time * vel->x;
    outPos->y = pos->y + time * vel->y;
    outPos->z = pos->z + time * vel->z;

    normal.x = outPos->x;
    normal.y = 0.0f;
    normal.z = outPos->z;
    Vec3fNormalize(&normal);
    Vec3fReflect(outVel, &normal);
}

s32 func_800E5AD4_63284(Vec3f* inPos, Vec3f* inVel, Vec3f* center, f32 arg3, f32 height, Vec3f* outPos, Vec3f* outVel) {
    Vec3f velDir;
    Vec3f vecFromCenter;
    Vec3f unused;
    f32 velSquaredMod;
    f32 dotProductMod;
    f32 distSquaredMod;
    f32 colPointY;
    f32 speed;
    f32 sp4C;
    f32 time;
    f32 unused2;

    Vec3fDiff(&vecFromCenter, inPos, center);
    outVel->x = inVel->x;
    outVel->y = inVel->y;
    outVel->z = inVel->z;
    speed = Vec3fNormalize(outVel);
    velDir.x = outVel->x;
    velDir.y = outVel->y;
    velDir.z = outVel->z;

    velSquaredMod = SQ(velDir.x) + SQ(velDir.z) - SQ(velDir.y);
    dotProductMod = velDir.x * vecFromCenter.x + velDir.z * vecFromCenter.z - velDir.y * vecFromCenter.y;
    distSquaredMod = SQ(vecFromCenter.x) + SQ(vecFromCenter.z) - SQ(vecFromCenter.y);

    if (!(ABS(velSquaredMod) < 0.0001f) && velSquaredMod * distSquaredMod <= SQ(dotProductMod)) {
        time = (-dotProductMod - sqrtf(SQ(dotProductMod) - velSquaredMod * distSquaredMod)) / velSquaredMod;
        if (time > 0.0001f && sp4C < FLOAT_MAX) { // UB: sp4C uninitialized
            colPointY = time * velDir.y + vecFromCenter.y;
            if (colPointY >= 0.0f && colPointY <= height && time < speed) {
                reflect_from_cylinder_copy(&vecFromCenter, &velDir, time, outPos, outVel);
                speed *= 0.7f;
                Vec3fScale(outVel, speed);
                Vec3fAdd(outPos, center);
                return true;
            }
        }
    }
    return false;
}

s32 collide_with_hitbox(Vec3f* pos, Vec3f* vel, Vec3f* arg2, Collider* collider, Vec3f* outPos, Vec3f* outVel) {
    f32 unused[4];
    Vec3f inPos;
    Vec3f hitBoxCenter;
    Vec3f inVel;
    Vec3f sp58;
    f32 globalSpeed;
    f32 outSpeed;
    f32 scaleCoef;

    hitBoxCenter.x = 0.0f;
    hitBoxCenter.y = 0.0f;
    hitBoxCenter.z = 0.0f;

    inPos.x = pos->x;
    inPos.y = pos->y;
    inPos.z = pos->z;

    inVel.x = vel->x;
    inVel.y = vel->y;
    inVel.z = vel->z;

    transform_point(collider->hitBox->mtxGlobalToLocal, &inPos);
    transform_point_zero_w(collider->hitBox->mtxGlobalToLocal, &inVel);

    globalSpeed = sqrtf(SQ(vel->x) + SQ(vel->y) + SQ(vel->z));
    scaleCoef = globalSpeed / sqrtf(SQ(inVel.x) + SQ(inVel.y) + SQ(inVel.z));

    switch (collider->hitBox->type) {
        case 1:
            if (collide_with_sphere(&inPos, &inVel, &hitBoxCenter, collider->hitBox->unk_84, outPos, outVel)) {
                outSpeed = sqrtf(SQ(outVel->x) + SQ(outVel->y) + SQ(outVel->z));
                transform_point(collider->hitBox->mtxLocalToGlobal, outPos);
                transform_point_zero_w(collider->hitBox->mtxLocalToGlobal, outVel);
                Vec3fNormalize(outVel);
                Vec3fScale(outVel, outSpeed * scaleCoef);
                return true;
            }
            break;
        case 3:
            if (collide_with_cylinder(&inPos, &inVel, &hitBoxCenter, collider->hitBox->unk_84, collider->hitBox->unk_88 * 0.5f, outPos, outVel)) {
                outSpeed = sqrtf(SQ(outVel->x) + SQ(outVel->y) + SQ(outVel->z));
                transform_point(collider->hitBox->mtxLocalToGlobal, outPos);
                transform_point_zero_w(collider->hitBox->mtxLocalToGlobal, outVel);
                Vec3fNormalize(outVel);
                Vec3fScale(outVel, outSpeed * scaleCoef);
                return true;
            }
            break;
        case 2:
            if (func_800E5AD4_63284(&inPos, &inVel, &hitBoxCenter, collider->hitBox->unk_84, collider->hitBox->unk_88 * 0.5f, outPos, outVel)) {
                outSpeed = sqrtf(SQ(outVel->x) + SQ(outVel->y) + SQ(outVel->z));
                transform_point(collider->hitBox->mtxLocalToGlobal, outPos);
                transform_point_zero_w(collider->hitBox->mtxLocalToGlobal, outVel);
                Vec3fNormalize(outVel);
                Vec3fScale(outVel, outSpeed * scaleCoef);
                return true;
            }
            break;
        case 4:
            if (1) {
            }
            if (1) {
            }
            if (1) {
            } // TODO fake match
            sp58.x = collider->hitBox->unk_84;
            sp58.y = collider->hitBox->unk_88;
            sp58.z = collider->hitBox->unk_8C;
            if (collide_with_box(&inPos, &inVel, -sp58.x, sp58.x, -sp58.y, sp58.y, -sp58.z, sp58.z, outPos, outVel)) {
                outSpeed = sqrtf(SQ(outVel->x) + SQ(outVel->y) + SQ(outVel->z));
                transform_point(collider->hitBox->mtxLocalToGlobal, outPos);
                transform_point_zero_w(collider->hitBox->mtxLocalToGlobal, outVel);
                Vec3fNormalize(outVel);
                Vec3fScale(outVel, outSpeed * scaleCoef);
                return true;
            }
            break;
        default:
            return false;
    }
    return false;
}

Collider* get_root_collider(Collider* colliders) {
    s32 minDepth = 100;
    Collider* cur = colliders;
    Collider* ret = NULL;

    while (cur->depth != 18) {
        if (cur->hitBox != NULL && cur->depth < minDepth && cur->hitBox->type == 1) {
            ret = cur;
            minDepth = cur->depth;
        }
        cur++;
    }

    return ret;
}

s32 has_collision(Collider* root, Vec3f* pos1, Vec3f* pos2, f32 scaleX) {
    f32 radius = root->hitBox->unk_84 * root->scale.x * scaleX;

    if (SQ(pos1->x - pos2->x) + SQ(pos1->z - pos2->z) < SQ(radius)) {
        return true;
    } else {
        return false;
    }
}

s32 StaticObject_Collide(Vec3f* inPos, Vec3f* inVel, Vec3f* outPos, Vec3f* outVel) {
    WorldBlock* block;
    WorldBlock* curBlock;
    WorldBlock* blockArray[3];
    f32 unused[4];
    Collider* collider;
    Collider* rootHitBox;
    Vec3f objPos;
    Vec3f scale;
    s32 i;
    s32 j;
    Vec3f worldPos;
    Vec3f worldVel;
    Mtx4f mtx;
    Mtx4f invMtx;
    StaticObject* object;
    f32 scaleX;
    f32 speed;

    if (sCollisionModels == NULL) {
        return -1;
    }

    block = getCurrentWorldBlock();
    if (block == NULL || block->descriptor == NULL) {
        return -1;
    }

    blockArray[0] = block->prev;
    blockArray[1] = block;
    blockArray[2] = block->next;

    for (j = 0; j < ARRAY_COUNT(blockArray); j++) {
        curBlock = blockArray[j];
        if (curBlock == NULL || curBlock->descriptor == NULL || curBlock->descriptor->staticObjects == NULL) {
            continue;
        }

        object = curBlock->descriptor->staticObjects;
        while (object->id != -1) {
            for (i = 0; i < 100; i++) {
                if (sCollisionModels[i].id == -1) {
                    break;
                }
                if (sCollisionModels[i].colliders != NULL && sCollisionModels[i].id == object->id) {
                    objPos.x = object->position.x + (curBlock->descriptor->worldPos.x - block->descriptor->worldPos.x);
                    objPos.y = object->position.y + (curBlock->descriptor->worldPos.y - block->descriptor->worldPos.y);
                    objPos.z = object->position.z + (curBlock->descriptor->worldPos.z - block->descriptor->worldPos.z);

                    worldPos.x = inPos->x / 100.0f;
                    worldPos.y = inPos->y / 100.0f;
                    worldPos.z = inPos->z / 100.0f;

                    worldVel.x = inVel->x / 100.0f;
                    worldVel.y = inVel->y / 100.0f;
                    worldVel.z = inVel->z / 100.0f;

                    speed = Vec3fNormalize(&worldVel);
                    if (ABS(speed) < 0.1f) {
                        speed = 0.1f;
                    }
                    Vec3fScale(&worldVel, speed);

                    if (sCollisionModels[i].scale > 0.0f) {
                        scale.x = scale.y = scaleX = scale.z = sCollisionModels[i].scale;
                    } else {
                        scale.x = scaleX = object->scale.x;
                        scale.y = object->scale.y;
                        scale.z = object->scale.z;
                    }

                    rootHitBox = get_root_collider(sCollisionModels[i].colliders);
                    if (rootHitBox != NULL && has_collision(rootHitBox, &worldPos, &objPos, scaleX)) {
                        create_matrix(mtx, invMtx, scale, object->rotation, objPos);
                        transform_point(invMtx, &worldPos);
                        transform_point_zero_w(invMtx, &worldVel);

                        collider = sCollisionModels[i].colliders;
                        while (collider->depth != 18) {
                            if (collider != rootHitBox && collider->hitBox != NULL && collide_with_hitbox(&worldPos, &worldVel, &objPos, collider, outPos, outVel)) {
                                transform_point(mtx, outPos);
                                transform_point_zero_w(mtx, outVel);

                                outPos->x *= 100.0f;
                                outPos->y *= 100.0f;
                                outPos->z *= 100.0f;

                                outVel->x *= 100.0f;
                                outVel->y *= 100.0f;
                                outVel->z *= 100.0f;

                                return object->id;
                            }
                            collider++;
                        }
                    }
                }
            }
            object++;
        }
    }

    return -1;
}

void InitCollisionModels(CollisionModel* objects) {
    s32 i;
    Collider* part;
    s32 sp44;
    s32 unused[2];

    sCollisionModels = objects;
    if (sCollisionModels == NULL) {
        return;
    }

    for (i = 0; i < 100; i++) {
        if (sCollisionModels[i].id == -1) {
            break;
        }

        part = sCollisionModels[i].colliders;
        if (part != NULL) {
            sp44 = -1;
            while (part->depth != 18) {
                make_transform(part, &sp44);
                part++;
            }
        }
    }
}

void InitOneCollisionModel(CollisionModel* arg0) {
    Collider* part;
    s32 unused;
    s32 sp44;
    s32 unused2[3];

    part = arg0->colliders;
    if (part != NULL) {
        sp44 = -1;
        while (part->depth != 18) {
            make_transform(part, &sp44);
            part++;
        }
    }
}

bool StaticObject_CollideOne(Vec3f* inPos, Vec3f* inVel, Vec3f* outPos, Vec3f* outVel, CollisionModel* colModel, Vec3f objPos, Vec3f rotation) {
    Collider* root;
    Collider* collider;
    Vec3f objWorldPos;
    Vec3f scale;
    f32 speed;
    Vec3f worldPos;
    Vec3f worldVel;
    Mtx4f mtx;
    Mtx4f invMtx;
    f32 scaleX;

    objWorldPos.x = objPos.x / 100.0f;
    objWorldPos.y = objPos.y / 100.0f;
    objWorldPos.z = objPos.z / 100.0f;

    worldPos.x = inPos->x / 100.0f;
    worldPos.y = inPos->y / 100.0f;
    worldPos.z = inPos->z / 100.0f;

    worldVel.x = inVel->x / 100.0f;
    worldVel.y = inVel->y / 100.0f;
    worldVel.z = inVel->z / 100.0f;

    speed = Vec3fNormalize(&worldVel);
    if (ABS(speed) < 0.1f) {
        speed = 0.1f;
    }
    Vec3fScale(&worldVel, speed);
    scaleX = scale.x = scale.y = scale.z = colModel->scale;

    root = get_root_collider(colModel->colliders);
    if (root == NULL) {
        return false;
    }
    if (!has_collision(root, &worldPos, &objWorldPos, scaleX)) {
        return false;
    }

    create_matrix(mtx, invMtx, scale, rotation, objWorldPos);
    transform_point(invMtx, &worldPos);
    transform_point_zero_w(invMtx, &worldVel);

    collider = colModel->colliders;
    while (collider->depth != 18) {
        if (collider != root && collider->hitBox != NULL && collide_with_hitbox(&worldPos, &worldVel, &objWorldPos, collider, outPos, outVel)) {
            transform_point(mtx, outPos);
            transform_point_zero_w(mtx, outVel);

            outPos->x *= 100.0f;
            outPos->y *= 100.0f;
            outPos->z *= 100.0f;

            outVel->x *= 100.0f;
            outVel->y *= 100.0f;
            outVel->z *= 100.0f;

            return true;
        }
        collider++;
    }
    return false;
}
