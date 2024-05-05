#include "common.h"

s32 gLevelID = -1;
char* gLevelNames[] = {
    "Beach", "Tunnel", "Volcano", "River", "Cave", "Valley", "Rainbow",
};

s32 getLevelId(void) {
    return gLevelID;
}

void setLevelId(s32 levelID) {
    gLevelID = levelID;
}

char* getLevelName(s32 levelIdx) {
    if (levelIdx < 0 || levelIdx >= ARRAY_COUNT(gLevelNames)) {
        return NULL;
    }
    return gLevelNames[levelIdx];
}
