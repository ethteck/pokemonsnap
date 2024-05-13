#include "common.h"

extern s32 D_8037EA80_852230;
extern s32 D_8037EA84_852234;
extern s32 D_8037EA88_852238;
extern UnkSnowHerring* D_8037EA8C_85223C;
extern UnkSnowHerring* D_8037EA90_852240;

void func_8036A480_83DC30(void) {
    D_8037EA80_852230 = 0;
    D_8037EA84_852234 = 0;
    D_8037EA88_852238 = 0;
    D_8037EA8C_85223C = NULL;
    D_8037EA90_852240 = NULL;
}

void func_8036A4AC_83DC5C(UnkSnowHerring* arg0) {
    if (D_8037EA8C_85223C == NULL) {
        D_8037EA8C_85223C = arg0;
        D_8037EA90_852240 = arg0;
        arg0->unk_3C = NULL;
        arg0->unk_40 = 0;
    } else {
        D_8037EA8C_85223C->unk_40 = arg0;
        arg0->unk_3C = (void*) D_8037EA8C_85223C;
        arg0->unk_40 = 0;
        D_8037EA8C_85223C = arg0;
    }
}

void func_8036A4F4_83DCA4(UnkSnowHerring* arg0) {
    if (D_8037EA90_852240 == NULL) {
        D_8037EA8C_85223C = arg0;
        D_8037EA90_852240 = arg0;
        arg0->unk_3C = NULL;
        arg0->unk_40 = NULL;
    } else {
        D_8037EA90_852240->unk_3C = arg0;
        arg0->unk_3C = NULL;
        arg0->unk_40 = D_8037EA90_852240;
        D_8037EA90_852240 = arg0;
    }
}

void func_8036A53C_83DCEC(UnkSnowHerring* arg0) {

    if (!arg0->unk_3C && !arg0->unk_40) {
        D_8037EA8C_85223C = NULL;
        D_8037EA90_852240 = NULL;
    } else if (!arg0->unk_3C) {
        D_8037EA90_852240 = arg0->unk_40;
        arg0->unk_40->unk_3C = NULL;
    } else if (!arg0->unk_40) {
        arg0->unk_3C->unk_40 = NULL;
        D_8037EA8C_85223C = arg0->unk_3C;
    } else {
        arg0->unk_3C->unk_40 = arg0->unk_40;
        arg0->unk_40->unk_3C = arg0->unk_3C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036A5B8_83DD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036A8E4_83E094.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036A968_83E118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036A9AC_83E15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036AC6C_83E41C.s")

void func_8036B5F0_83EDA0(UnkSnowHerring* arg0) {
    if (arg0 != 0) {
        func_8036A53C_83DCEC(arg0);
        omDeleteGObj(arg0->unk_50);
        func_8036A228_83D9D8(arg0);
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036B628_83EDD8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036B734_83EEE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036B870_83F020.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036B988_83F138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036B9EC_83F19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036BA50_83F200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036C2FC_83FAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036C898_840048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036C9C0_840170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CAE8_840298.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CB10_8402C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CB58_840308.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CBA0_840350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CBFC_8403AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CC48_8403F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CCEC_84049C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CDAC_84055C.s")

UnkSnowHerring* func_8036D018_8407C8(void) {
    return D_8037EA8C_85223C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D024_8407D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D040_8407F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D09C_84084C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D0F8_8408A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D1A4_840954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D22C_8409DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D248_8409F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D28C_840A3C.s")
