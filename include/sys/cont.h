#ifndef SYS_CONT_H
#define SYS_CONT_H

#include <PR/ultratypes.h>

void contUpdate(void);
void contReadAndUpdate(void);
void contSetUpdateEveryTick(s32);
void contRumbleInit(s32);
void contRumbleStop(s32);
void contMain(void* arg);
void contPrinterSendCommand(u8 value);
s32 contIsPrinterAvailable(void);
u8 contPrinterGetStatus(void);
extern u16 gContInputCurrentButtons;
extern u16 gContInputPressedButtons;
extern u16 gContInputHeldButtons;
extern u16 gContInputReleasedButtons;
extern s8 gContInputStickX;
extern s8 gContInputStickY;

#endif /* SYS_CONT_H */
