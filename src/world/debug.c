#include "world.h"

s32 inRange_DEBUG(u32 arg0, s32 arg1, s32 arg2, const char* arg3) {
    if ((arg0 < arg1) || (arg2 < arg0)) {
        return FALSE;
    }
    return TRUE;
}

s32 notNull_DEBUG(void* arg0, const char* arg1) {
    if (arg0 == NULL) {
        return FALSE;
    }
    return TRUE;
}
