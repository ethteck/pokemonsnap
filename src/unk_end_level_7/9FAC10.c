#include "common.h"

typedef struct UnkBeigeBetta {
    SObj* var_8;
    s32 var_C;
} UnkBeigeBetta;

UnkPinkBarracuda* func_801E0F88_9FEC48(s32);
s32 func_801DC904_9FA5C4(void);
void func_801DCF50_9FAC10(UNK_PTR);
void func_801DF078_9FCD38(UNK_PTR);
void func_801DD4C4_9FB184(s32);
void func_801DD28C_9FAF4C(s32);

extern struct UnkBeigeBetta D_8023084C_A4E50C[];
extern Sprite D_801E8FB0_A06C70;
extern GObj* D_80230868_A4E528;
extern s32 D_80230890_A4E550;
extern s32 D_801EA1FC_A07EBC;
extern SObj* D_8023086C_A4E52C;
extern GObj* D_80230870_A4E530;
extern SObj* D_80230874_A4E534;

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DCF50_9FAC10.s")

void func_801DD074_9FAD34(u32 arg0) {
    UNUSED s32 pad;
    D_8023086C_A4E52C->sprite.red = arg0;
    D_8023086C_A4E52C->sprite.green = arg0;
    D_8023086C_A4E52C->sprite.blue = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DD0AC_9FAD6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DD1A8_9FAE68.s")

void func_801DD270_9FAF30(void) {
    D_801EA1FC_A07EBC = 0x18;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DD28C_9FAF4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DD4C4_9FB184.s")

void func_801DD708_9FB3C8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_801DD4C4_9FB184(i);
    }

    for (i = 0; i < 6; i++) {
        func_801DD28C_9FAF4C(i);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DD768_9FB428.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DD860_9FB520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DD8F8_9FB5B8.s")

void func_801DDC50_9FB910(s32 arg0) {
    func_80374714_847EC4(func_801E0F88_9FEC48(arg0), &D_8023084C_A4E50C[arg0].var_8->sprite);
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DDCA8_9FB968.s")

void func_801DE04C_9FBD0C(s32 arg0, s32 arg1) {
    SObj* sobj;

    sobj = D_80230870_A4E530->data.sobj;
    if ((arg0 < 0) || (arg1 < 0)) {
        sobj->sprite.attr |= 4;
    } else {
        SET_SPRITE_POS(sobj->sprite, arg0, arg1);
        sobj->sprite.attr &= ~4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE0B8_9FBD78.s")

void func_801DE290_9FBF50(s32 arg0) {
    if (arg0) {
        D_80230870_A4E530->data.sobj->sprite.attr &= ~4;
    } else {
        D_80230870_A4E530->data.sobj->sprite.attr |= 4;
    }
}

void func_801DE2E0_9FBFA0(UnkPinkBarracuda* arg0) {
    func_80374714_847EC4(arg0, &D_80230874_A4E534->sprite);
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE318_9FBFD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE4A0_9FC160.s")

void func_801DD0AC_9FAD6C(s32);

void func_801DE538_9FC1F8(void) {
    s32 i;

    for (i = 0; i < 10; i++) {
        func_801DD074_9FAD34((i * 0xFF) / 10);
        func_801DD0AC_9FAD6C((i * 0xFF) / 10);
        ohWait(1);
    }

    func_801DD074_9FAD34(0xFF);
    func_801DD0AC_9FAD6C(0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE5D0_9FC290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE804_9FC4C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DE87C_9FC53C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DEE88_9FCB48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level_7/9FAC10/func_801DF078_9FCD38.s")

void func_801DF788_9FD448(void) {
    GObj* obj;
    SObj* sobj;

    D_80230890_A4E550 = func_801DC904_9FA5C4();
    func_800A85E8(func_801DF078_9FCD38, 6, 0, 0);
    func_800A85E8(func_801DCF50_9FAC10, 6, 0, 0);
    obj = func_80371D14_8454C4(NULL, 6, &D_801E8FB0_A06C70);
    sobj = obj->data.sobj;
    sobj->sprite.width = SCREEN_WIDTH;
    sobj->sprite.height = SCREEN_HEIGHT;
    sobj->sprite.istep = 0;
    D_80230868_A4E528 = obj;
    D_8023086C_A4E52C = sobj;
    func_801DD074_9FAD34(0);
}
