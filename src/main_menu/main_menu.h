#ifndef _MAIN_MENU_H
#define _MAIN_MENU_H

typedef struct PanData {
    /* 0x00 */ s32 data[4];
} PanData;

typedef struct YValues {
    /* 0x00 */ s16 data[3][4];
} YValues;

extern PanData D_800E80D4_A0F664;
extern YValues D_800E80E4_A0F674;

void func_800E1930_A08EC0(u8 arg0, u8 arg1, u8 arg2, u8 arg3, f32 arg4);

void func_800E5C8C_A0D21C(void);
void func_800E5D2C_A0D2BC(void);
s32 func_800E6B2C_A0E0BC(void);
void func_800E7F98_A0F528(void);

#endif
