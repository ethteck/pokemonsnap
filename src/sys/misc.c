#include "common.h"
#include "string.h"

#define F_PI ((f32) M_PI) // M_PI is a double, we want it as a single float.
#define HALF_PI (F_PI / 2.0f)

s32 sRandSeed = 1;
s32 qsortItemSize = 0;
s32 (*qsortCompareFunc)(u8*, u8*) = NULL;


f32 tanf(f32 arg0) {
    return sinf(arg0) / cosf(arg0);
}

f32 atanf(f32 arg) {
    f32 arg2;
    f32 result;
    s32 phi_v0;

    if (arg == 0.0f) {
        return 0.0f;
    }

    phi_v0 = 1;

    if (arg > 1.0f) {
        arg = 1.0f / arg;
    } else if (arg < -1.0f) {
        arg = 1.0f / arg;
        phi_v0 = 2;
    } else {
        phi_v0 = 0;
    }

    arg2 = arg * arg;
    result =
        (arg2 / (arg2 / (arg2 / (arg2 / (arg2 / ((arg2 / -0.10810675f) + -44.57192f) + -0.1619081f) + -15.774018f) +
                         -0.55556977f) +
                 -3.000003f) +
         1) *
        arg;

    switch (phi_v0) {
        case 0:
            return result;
        case 1:
            return PI_2 - result;
        case 2:
            return -PI_2 - result;
    }
}

f32 atan2f(f32 y, f32 x) {
    f32 temp_f0;
    s32 var_v0;
    f32 var_f12;

    if (x > 0.0f) {
        return atanf(y / x);
    }
    if (x < 0.0f) {
        var_v0 = (y < 0.0f) ? -1 : 1;
        temp_f0 = y / x;
        if (temp_f0 < 0.0f) {
            var_f12 = -temp_f0;
        } else {
            var_f12 = temp_f0;
        }
        return (F_PI - atanf(var_f12)) * var_v0;
    }
    if (y != 0.0f) {
        var_v0 = (y < 0.0f) ? -1 : 1;
        return var_v0 * HALF_PI;
    }
    return 0.0f;
}

f32 asinf(f32 arg0) {
    if (arg0 > 0.99999f) {
        return HALF_PI;
    }
    if (arg0 < -0.99999f) {
        return -HALF_PI;
    }
    return atanf(arg0 / sqrtf(1.0f - (arg0 * arg0)));
}

f32 acosf(f32 arg0) {
    if (arg0 > 0.99999f) {
        return 0.0f;
    }
    if (arg0 < -0.99999f) {
        return F_PI;
    }
    return HALF_PI - atanf(arg0 / sqrtf(1.0f - (arg0 * arg0)));
}

f32 cosecf(f32 arg0) {
    return 1.0f / sinf(arg0);
}

f32 secf(f32 arg0) {
    return 1.0f / cosf(arg0);
}

f32 cotanf(f32 arg0) {
    return 1.0f / tanf(arg0);
}

void setRandSeed(s32 arg0) {
    sRandSeed = arg0;
}

s32 getRandSeed(void) {
    return sRandSeed;
}

u16 rand(void) {
    // Required to be one line to match.
    sRandSeed = (sRandSeed * 0x343FD) + 0x269EC3; \
    return (sRandSeed >> 16);
}

f32 randFloat(void) {
    sRandSeed = (sRandSeed * 0x343FD) + 0x269EC3;
    return ((sRandSeed >> 16) & 0xFFFF) / 65536.0f;
}

u32 randRange(s32 range) {
    return rand() * range / 0x10000;
}

u8 randT(void) {
    return osGetTime();
}

f32 randTFloat(void) {
    return (osGetTime() & 0xFF) * (1.0f / 256.0f);
}

s32 randTRange(s32 arg0) {
    s32 time = osGetTime() & 0xFF;
    return time * arg0 * (1.0f / 256.0f);
}

void swap(u8* ptr1, u8* ptr2, s32 size) {
    while (size--) {
        s32 temp = *ptr1;
        *ptr1++ = *ptr2;
        *ptr2++ = temp;
    }
}

void qsortInternal(u8* first, u8* last) {
    u8* s0;
    u8* s1;

    s0 = first;
    s1 = last + qsortItemSize;

    while (first < last) {
    restart:
        do {
            s0 += qsortItemSize;
            if (s0 >= last) {
                break;
            }
        } while (qsortCompareFunc(s0, first) <= 0);

        do {
            s1 -= qsortItemSize;
            if (first >= s1) {
                break;
            }
        } while (qsortCompareFunc(s1, first) >= 0);

        if (s0 < s1) {
            swap(s0, s1, qsortItemSize);
            goto restart;
        }

        swap(first, s1, qsortItemSize);
        if (s1 - first >= last - s1) {
            qsortInternal(s1 + qsortItemSize, last);
            last = s1 - qsortItemSize;
            s0 = first;
        } else {
            qsortInternal(first, s1 - qsortItemSize);
            first = s1 + qsortItemSize;
            s0 = first;
            s1 = last + qsortItemSize;
        }
    }
}

void qsort(u8* base, s32 count, s32 itemSize, s32 (*compare)(u8*, u8*)) {
    u8 *curr, *next;
    s32 s0;
    s32 foundInversion;
    s32 nv = 1; // required to match

    curr = base;
    next = base + itemSize;
    foundInversion = FALSE;

    if (count) {
        s0 = count - nv;
        do { // required to match
            while (s0--) {
                if (compare(curr, next) > 0) {
                    foundInversion = TRUE;
                    break;
                }
                curr = next;
                next += itemSize;
            }
        } while (FALSE);
    }

    if (foundInversion) {
        qsortItemSize = itemSize;
        qsortCompareFunc = compare;
        qsortInternal(base, base + ((count - 1) * qsortItemSize));
    }
}

u8* find(u8* value, u8* array, u32 count, s32 itemSize, s32 (*compare)(u8*, u8*)) {
    s32 newvar = (count - 1) * itemSize;
    u8* low = array;
    u8* high = array + newvar;

    while (low <= high) {
        u32 midIndex = count >> 1;
        u32 parity = count & 1;

        if (midIndex != 0) {
            u8* mid = low + (parity ? midIndex : midIndex - 1) * itemSize;
            s32 ret = compare(value, mid);

            if (ret == 0) {
                return mid;
            } else if (ret < 0) {
                high = mid - itemSize;
                count = parity ? midIndex : midIndex - 1;
            } else {
                low = mid + itemSize;
                count = midIndex;
            }
        } else {
            if (count == 0) {
                break;
            }
            return compare(value, low) ? NULL : low;
        }
    }
    return NULL;
}

u8* func_8001A29C(u8* dst, u8* src, u32* count, u32 itemSize, s32 (*compare)(u8*, u8*)) {
    s32 i;

    for (i = 0; i < *count; i++) {
        if (compare(dst, src) == 0) {
            return src;
        }
        src += itemSize;        
    }
    memcpy(dst, src, itemSize);
    *count += 1;
    return src;
}
