#include "common.h"

#include "sys/interpolation.h"

void func_8001ED60(Vec3f*, Vec3f*, f32, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001ED60.s")

void func_8001EEA4(Vec3f* arg0, Vec3f* arg1, f32 arg2, f32 arg3) {
    f32 temp_f0;
    f32 temp_f16;
    f32 temp_f18;
    f32 temp_f2;
    f32 temp_f8;
    f32 other;

    temp_f0 = SQ(arg3);
    temp_f2 = (-3.0f * temp_f0 + 4.0f * arg3 - 1.0f) * arg2;
    temp_f8 = arg2 - 3.0f;
    other = arg2;
    temp_f16 = (2.0f - other) * 3.0f * temp_f0 + 2.0f * temp_f8 * arg3;
    temp_f8 = 3.0f - 2.0f * other;
    temp_f18 = (other - 2.0f) * 3.0f * temp_f0 + 2.0f * temp_f8 * arg3 + other;
    other = (3.0f * temp_f0 - 2.0f * arg3) * other;

    arg0->x = (arg1->x * temp_f2) + (arg1[1].x * temp_f16) + (arg1[2].x * temp_f18) + (arg1[3].x * other);
    arg0->y = (arg1->y * temp_f2) + (arg1[1].y * temp_f16) + (arg1[2].y * temp_f18) + (arg1[3].y * other);
    arg0->z = (arg1->z * temp_f2) + (arg1[1].z * temp_f16) + (arg1[2].z * temp_f18) + (arg1[3].z * other);
}

void func_8001F030(Vec3f*, Vec3f*, f32);
#pragma GLOBAL_ASM("asm/nonmatchings/1F960/func_8001F030.s")

void func_8001F190(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    UNUSED s32 pad[2];
    f32 temp_f0;
    f32 w1;
    f32 w2;
    f32 w3;
    f32 w0;
    f32 temp_f8;
    
    temp_f8 = 1.0f - arg2;
    temp_f0 = SQ(arg2);
    
    w0 = -0.5f * temp_f8 * temp_f8;
    w1 = 0.5f * (3.0f * temp_f0 - 4.0f * arg2);
    w2 = 0.5f * (-3.0f * temp_f0 + 2.0f * arg2 + 1.0f);
    w3 = 0.5f * temp_f0;

    arg0->x = arg1[0].x * w0 + arg1[1].x * w1 + arg1[2].x * w2 + arg1[3].x * w3;
    arg0->y = arg1[0].y * w0 + arg1[1].y * w1 + arg1[2].y * w2 + arg1[3].y * w3;
    arg0->z = arg1[0].z * w0 + arg1[1].z * w1 + arg1[2].z * w2 + arg1[3].z * w3;
}

void func_8001F2C4(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    f32 temp_f0;
    f32 w1;
    f32 w2;
    f32 w3;
    f32 w0;
    f32 temp_f8;
    f32 temp2;
    
    temp_f8 = 1.0f - arg2;
    temp_f0 = SQ(arg2);
    temp2 = SQ(temp_f8);
    
    w0 = temp2 * temp_f8;
    w1 = 3.0f * arg2 * temp2;
    w2 = 3.0f * temp_f0 * temp_f8;
    w3 = temp_f0 * arg2;

    arg0->x = arg1[0].x * w0 + arg1[1].x * w1 + arg1[2].x * w2 + arg1[3].x * w3;
    arg0->y = arg1[0].y * w0 + arg1[1].y * w1 + arg1[2].y * w2 + arg1[3].y * w3;
    arg0->z = arg1[0].z * w0 + arg1[1].z * w1 + arg1[2].z * w2 + arg1[3].z * w3;
}

void func_8001F3D8(Vec3f* arg0, Vec3f* arg1, f32 arg2) {
    f32 temp_f0;
    f32 w3;
    f32 w1;
    f32 w2;
    f32 w0;

    temp_f0 = arg2 - 1.0f;
    
    w0 = -3.0f * temp_f0 * temp_f0;
    w1 = 3.0f * (1.0f - 4.0f * arg2 + 3.0f * SQ(arg2));
    w2 = 3.0f * (2.0f * arg2 - 3.0f * SQ(arg2));
    w3 = 3.0f * SQ(arg2);

    arg0->x = arg1[0].x * w0 + arg1[1].x * w1 + arg1[2].x * w2 + arg1[3].x * w3;
    arg0->y = arg1[0].y * w0 + arg1[1].y * w1 + arg1[2].y * w2 + arg1[3].y * w3;
    arg0->z = arg1[0].z * w0 + arg1[1].z * w1 + arg1[2].z * w2 + arg1[3].z * w3;
}

// arg1->unk02 is total frames? elapsed frames?
// delta time cubic interpolation?
void func_8001F4E4(Vec3f* out, InterpData* path, f32 t) {
    s16 targetSegment;
    Vec3f* cur;

    if (t < 0.0f || t > 1.0f) {
        return;
    }

    if (t < 1.0f) {
        // convert interval from [0,1] to [0,totalFrames]
        t *= (f32) (path->numPoints - 1);
        targetSegment = t;
        // get only the rounding difference for interpolation?
        t = t - (f32) targetSegment;

        switch (path->type) {
            case HAL_INTERP_LINEAR:
                cur = &path->points[targetSegment];
                out->x = (cur[1].x - cur[0].x) * t + cur[0].x;
                out->y = (cur[1].y - cur[0].y) * t + cur[0].y;
                out->z = (cur[1].z - cur[0].z) * t + cur[0].z;

                break;
            case HAL_INTERP_BEZIER_S3:
                func_8001F2C4(out, &path->points[targetSegment * 3], t);
                break;
            case HAL_INTERP_BEZIER:
                func_8001F030(out, &path->points[targetSegment], t);
                break;
            case HAL_INTERP_CATROM:
                func_8001ED60(out, &path->points[targetSegment], path->unk_04, t);
                break;
        }
    } else {
        targetSegment = path->numPoints - 1;

        switch (path->type) {
            case HAL_INTERP_LINEAR:
                cur = &path->points[targetSegment];
                *out = *cur;
                break;
            case HAL_INTERP_BEZIER_S3:
                cur = &path->points[targetSegment * 3];
                *out = *cur;
                break;
            case HAL_INTERP_BEZIER:
                func_8001F030(out, &path->points[targetSegment - 1], 1.0f);
                break;
            case HAL_INTERP_CATROM:
                cur = &path->points[targetSegment + 1];
                *out = *cur;
                break;
        }
    }
}

void func_8001F770(Vec3f* out, InterpData* path, f32 t) {
    s16 targetSegment;
    f32 tOrig;
    Vec3f* cur;

    if (t < 0.0f || t > 1.0f) {
        return;
    }

    tOrig = t;
    t *= (f32) (path->numPoints - 1);
    targetSegment = t;
    t = t - (f32) targetSegment;

    switch (path->type) {
        case HAL_INTERP_LINEAR:
            if (tOrig == 1.0f) {
                targetSegment--;
            }
            cur = &path->points[targetSegment];
            out->x = cur[1].x - cur[0].x;
            out->y = cur[1].y - cur[0].y;
            out->z = cur[1].z - cur[0].z;

            break;
        case HAL_INTERP_BEZIER_S3:
            func_8001F3D8(out, &path->points[targetSegment * 3], t);
            break;
        case HAL_INTERP_BEZIER:
            func_8001F190(out, &path->points[targetSegment], t);
            break;
        case HAL_INTERP_CATROM:
            func_8001EEA4(out, &path->points[targetSegment], path->unk_04, t);
            break;
    }
}

f32 get_speed_approx(f32 x, FittingParams* coefs) {
    f32 value;

    value = coefs->c[0] * (x * x * x * x) +
            coefs->c[1] * (x * x * x) +
            coefs->c[2] * (x * x) +
            coefs->c[3] * (x) +
            coefs->c[4];

    if (value < 0.0f && value > -0.001f) {
        value = 0.0f;
    }
    return sqrtf(value);
}

// numerically integrate get_speed_approx using Simpson's rule (https://en.wikipedia.org/wiki/Simpson%27s_rule)

f32 interp_integrate(f32 start, f32 end, FittingParams* coefs) {
    f32 step;
    f32 x;
    f32 sum;
    s32 i;

    step = (end - start) / 8;
    sum = 0.0f;

    for (x = start + step, i = 2; i < 9; i++, x += step) {
        if (i % 2 == 0) {
            sum += 4.0f * get_speed_approx(x, coefs);
        } else {
            sum += 2.0f * get_speed_approx(x, coefs);
        }
    }

    return (get_speed_approx(start, coefs) + sum + get_speed_approx(end, coefs)) * step / 3;
}

f32 get_uniform_param(InterpData* arg0, f32 param) {
    f32 curTime;
    f32 targetTime;
    f32 mid;
    f32 low;
    f32 high;
    f32 curTime2;
    s32 targetSegment;

    targetSegment = 0;
    low = 0.0f;
    high = 1.0f;

    if (param == 1.0f) {
        return 1.0f;
    }

    while (arg0->paramPoints[targetSegment + 1] < param) {
        targetSegment++;
    }

    switch (arg0->type) {
        case HAL_INTERP_LINEAR:
            mid = (param - arg0->paramPoints[targetSegment]) / (arg0->paramPoints[targetSegment + 1] - arg0->paramPoints[targetSegment]);
            break;
        case HAL_INTERP_BEZIER_S3:
        case HAL_INTERP_BEZIER:
        case HAL_INTERP_CATROM:
            targetTime = (param - arg0->paramPoints[targetSegment]) * arg0->duration;

            while (true) {
                mid = (low + high) * 0.5f;
                curTime2 = curTime = interp_integrate(low, mid, &arg0->speedFunc[targetSegment]);
                if (targetTime < curTime + 0.00001f) {
                    high = mid;
                } else {
                    low = mid;
                    curTime2 = curTime;
                    targetTime = targetTime - curTime;
                }

                if (ABS(low - high) < 0.00001f) {
                    break;
                }

                if (!(targetTime > curTime2 + 0.00001f || targetTime < curTime2 - 0.00001f)) {
                    break;
                }
            }
            break;
    }
    return (targetSegment + mid) / (arg0->numPoints - 1.0f);
}

void GetInterpolatedPosition(Vec3f* pos, InterpData* path, f32 param) {
    func_8001F4E4(pos, path, get_uniform_param(path, param));
}

void GetInterpolatedVelocity(Vec3f* vel, InterpData* path, f32 param) {
    func_8001F770(vel, path, get_uniform_param(path, param));
}
