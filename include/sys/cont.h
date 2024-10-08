#ifndef SYS_CONT_H
#define SYS_CONT_H

#include <PR/ultratypes.h>

typedef struct {
    /* 0x00 */ u16 buttons;
    /* 0x02 */ u16 pressedButtons;
    /* 0x04 */ u16 heldButtons;
    /* 0x06 */ u16 releasedButtons;
    /* 0x08 */ s8 stickX;
    /* 0x09 */ s8 stickY;
} ControllerInput; // size = 0x0A

void contUpdate(void);
void contReadAndUpdate(void);
void contSetUpdateEveryTick(s32);
void contRumbleInit(s32);
void contRumbleStop(s32);
void contMain(void *arg);
void contPrinterSendCommand(u8 value);
s32 contIsPrinterAvailable(void);
u8 contPrinterGetStatus(void);
extern u16 gContInputCurrentButtons;
extern u16 gContInputPressedButtons;
extern u16 gContInputHeldButtons;
extern u16 gContInputReleasedButtons;
extern s8 gContInputStickX;
extern s8 gContInputStickY;
extern s32 gNumControllers;
extern ControllerInput gContInput[MAXCONTROLLERS];

#endif /* SYS_CONT_H */
