#include "ultra64.h"

s32 inRange_DEBUG(u32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if ((arg0 < arg1) || (arg2 < arg0)) {
        return 0;
    }
    return 1;
}

s32 bool_DEBUG(s32 arg0, s32 arg1) {
    if (arg0 == 0) {
        return 0;
    }
    return 1;
}
