#include "ultra64.h"

extern s32 gLevelID;
extern s32 gLevelNames[6];

s32 func_8009B980(void) {
    return gLevelID;
}

void func_8009B98C(s32 levelID) {
    gLevelID = levelID;
}

s8* func_8009B998(s32 levelIdx) {
    if (levelIdx < 0 || levelIdx >= 7) {
        return 0;
    }
    return gLevelNames[levelIdx];
}