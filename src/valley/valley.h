#ifndef _VALLEY_H_
#define _VALLEY_H_

#include "common.h"
#include "ld_addrs.h"
#include "../world/world.h"
#include "app_level/app_level.h"
#include "app_render/app_render.h"
#include "app_render/effect.h"
#include "assets/3F63E0_world/declarations.h"

typedef struct SomeC {
    /* 0x00 */ char* unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ char* unk_08;
} SomeC; // size = 0xC

extern char D_8034E080_827610[20]; // player name

void func_802C6AD4_7A0064(void);
void func_802C6B30_7A00C0(s32 arg0, f32 arg1);

#endif
