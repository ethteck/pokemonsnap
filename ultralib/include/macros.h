#ifndef __MACROS_H__
#define __MACROS_H__

#define ALIGNED(x) __attribute__((aligned(x)))

#define ARRLEN(x) ((s32)(sizeof(x) / sizeof(x[0])))

#define STUBBED_PRINTF(x) ((void)(x))

#define UNUSED __attribute__((unused))

#if !defined(__GNUC__) && !defined(__clang__)
#define __attribute__(x)
#endif

#define offsetof(st, m) ((u32) & (((st*)0)->m))

/// Get the number of elements in a static array
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

/// Convert from a physical addresss to a ROM (0xB0) address
#define PHYSICAL_TO_ROM(x) ((uintptr_t)(x) + 0xB0000000)

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#define ABS(x) (((x) < 0) ? (-(x)) : (x))

#define SQ(x) ((x) * (x))

#define M_PI_F      ((f32)M_PI)

#define FLOAT_MAX 3.4028234e38f
#define FLOAT_NEG_MAX -FLOAT_MAX

#define TAU 6.2831855f
#define PI_2 1.5707964f

#endif
