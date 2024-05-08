#ifndef APP_LEVEL_H
#define APP_LEVEL_H
#include "common.h"

extern s32 D_80382CF4_523104;

u32 getProgressFlags(void);
void Icons_SetDashEngineEnabled(s32 enabled);
void Icons_Init(void);
void Icons_ProcessButtonPress(s32 eventID);

#endif
