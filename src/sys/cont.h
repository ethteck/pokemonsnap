#ifndef SYS_CONT_H
#define SYS_CONT_H

#include <PR/ultratypes.h>

void contReadAndUpdate(void);
void contSetUpdateEveryTick(s32);
void contRumbleInit(s32);
void contRumbleStop(s32);
void contMain(void *arg);

#endif /* SYS_CONT_H */
