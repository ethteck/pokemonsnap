#include "common.h"

void func_800A86A4(void(*), s32, s32, s32);

extern s32 D_8037EAA0_852250;
extern s32 D_8037EAAC_85225C[];
extern s32 D_8037EAC4_852274;
extern s32 D_8037EAC8_852278;
extern s32 D_8037EAE0_852290;
extern u16 D_8037EAE4_852294[370];
extern void (*D_803A6A0C_87A1BC)(s32);

s32 func_8036D2A0_840A50(s32 arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8037EAE4_852294); i++) {
        if (arg0 == D_8037EAE4_852294[i]) {
            return i;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036D344_840AF4.s")

s32 func_8036D3D8_840B88(s32 arg0, s32 arg1) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036D3E8_840B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036D448_840BF8.s")

void func_8036D4A0_840C50(s32 arg0) {
    D_8037EAC4_852274 = arg0;
    D_8037EAC8_852278 = 0;
}

extern s32 D_8037EACC_85227C;

void func_8036D4B4_840C64(s32 flags, s32 set) {
    if (set) {
        D_8037EACC_85227C |= flags;
    } else {
        D_8037EACC_85227C &= ~flags;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036D4F0_840CA0.s")

s32 func_8036D758_840F08(void) {
    return D_8037EAAC_85225C[D_8037EAA0_852250];
}

s32 func_8036D774_840F24(void) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036D77C_840F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036DC4C_8413FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036DC68_841418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036DE98_841648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036E0E0_841890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036E22C_8419DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036E44C_841BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036E490_841C40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/840A50/func_8036E9BC_84216C.s")

void func_8036EB34_8422E4(s32 arg0) {
    if ((D_8037EAE0_852290 != 0) && (func_800AA38C(0)->unk_18 & (0x8000 | 0x4000))) {
        D_8037EAC8_852278 = 1;
    }
}

void func_8036EB80_842330(s32 arg0) {
    D_8037EAE0_852290 = arg0;
}

void func_8036EB8C_84233C(void (*arg0)(s32)) {
    D_803A6A0C_87A1BC = arg0;
}

void func_8036EB98_842348(void) {
    func_800A86A4(func_8036EB34_8422E4, 6, 0, 0);
    D_8037EAC4_852274 = 0;
    D_803A6A0C_87A1BC = 0;
    D_8037EAC8_852278 = 0;
}
