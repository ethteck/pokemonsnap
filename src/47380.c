#include "common.h"

#include "sys/dma.h"

extern s32 D_800AC0F0;
extern s32 D_800AE27C;
extern s32 D_800AE280;
extern s32 D_800B0598;

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009B9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BB4C.s")

s32 func_8009BBF4(void) {
    return D_800AE27C;
}

s32 func_8009BC00(void) {
    return D_800AE280;
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BC0C.s")

s32 func_8009BC68(void) {
    return gPhotoCount;
}

s32* func_8009BC74(void) {
    return &D_800B0598;
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BC80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BCC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BD4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009BF48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C25C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C304.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C450.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C4F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C5C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C604.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009C9E8.s")

// & 0xFFs and temp required to match
void func_8009CDC0(u8* arg0, s32 arg1) {
    if (arg0 != NULL) {
        s32 prev = *arg0;

        *arg0 = (arg1 & 1) & 0xFF | (prev & 0xFF & ~1);
    }
}

s32 func_8009CDE4(u8* arg0) {
    if (arg0 != NULL) {
        return *arg0 & 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009CE00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009CEAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D0B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D184.s")

void func_8009D1E8(u32 arg0, s32 arg1, s32 arg2) {
    if (arg1 >= arg0) {
        dma_rom_read(arg0, arg2, arg1 - arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D21C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D37C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D65C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D8A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009D9A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009DEF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009E050.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009E110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009E1CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009E3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009FA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009FA68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009FB50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009FBC4.s")

void func_8009FC2C(s32 arg0) {
    D_800AC0F0 = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/47380/func_8009FC38.s")
