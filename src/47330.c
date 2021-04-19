#include "common.h"

s32 getLevelId(void) {
    return gLevelID;
}

void setLevelId(s32 levelID) {
    gLevelID = levelID;
}

s8* getLevelName(s32 levelIdx) {
    if (levelIdx < 0 || levelIdx >= 7) {
        return 0;
    }
    return gLevelNames[levelIdx];
}
