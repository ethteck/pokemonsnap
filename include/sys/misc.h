#ifndef SYS_MISC_H
#define SYS_MISC_H

#include <PR/ultratypes.h>

f32 acosf(f32);
f32 atanf(f32);
f32 atan2f(f32 y, f32 x);
f32 asinf(f32 arg0);
f32 acosf(f32 arg0);
void setRandSeed(s32 arg0);
u16 rand16(void);
u8 randT(void);
f32 randFloat(void);
s32 randRange(s32 range);
s32 randTRange(s32 arg0);
void qsort2(void* base, u32 count, u32 itemSize, s32 (*compar)(const void*, const void*));

#endif /* SYS_MISC_H */
