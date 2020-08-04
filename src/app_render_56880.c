#include "ultra64.h"

extern s32 D_800AF3D0;

void func_800AAED0(s32 arg0) {
    D_800AF3D0 |= arg0;
}

s32 func_800AAEE8(s32 arg0) {
    s32 temp_v0= (D_800AF3D0 & arg0) != 0;
    
    D_800AF3D0 &= arg0 ^ -1;
    return temp_v0;
}

void func_800AAF10(void) {
    D_800AF3D0 = 0;
}
