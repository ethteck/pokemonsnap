#ifndef SYS_CONT_H
#define SYS_CONT_H

#include <PR/ultratypes.h>

void contUpdate(void);
void contReadAndUpdate(void);
void contSetUpdateEveryTick(s32);
void contRumbleInit(s32);
void contRumbleStop(s32);
void contMain(void *arg);
void contPrinterSendCommand(u8 value);
s32 contIsPrinterAvailable(void);
u8 contPrinterGetStatus(void);
extern u16 gContInputPressedButtons;

#endif /* SYS_CONT_H */
