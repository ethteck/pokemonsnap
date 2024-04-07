#include "common.h"

s32 getLevelId(void) {
    return gLevelID;
}

void setLevelId(s32 levelID) {
    gLevelID = levelID;
}

char* getLevelName(s32 levelIdx) {
    if (levelIdx < 0 || levelIdx > 6) {
        return 0;
    }
    return gLevelNames[levelIdx];
}
