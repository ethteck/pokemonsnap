#include "common.h"

extern s32 D_8037EA80_852230;
extern s32 D_8037EA84_852234;
extern s32 D_8037EA88_852238;
extern UnkSnowHerring* D_8037EA8C_85223C;
extern UnkSnowHerring* D_8037EA90_852240;

void func_8036EEB0_842660(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8036EFEC_84279C(s32, s32, s32, s32, s32);

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

void func_8036A8E4_83E094(UnkSnowHerring* arg0) {
    func_8036A5B8_83DD68(arg0, 0, 0, arg0->unk_10, arg0->unk_14, arg0->unk_4C, arg0->unk_4D, arg0->unk_4E, arg0->unk_4F);
    arg0->unk_120 = 0;
    arg0->unk_124 = 0;
    arg0->unk_118 = 0;
    func_8036EEB0_842660(arg0->unk_0, arg0->unk_4, arg0->unk_0 + arg0->unk_10, arg0->unk_4 + arg0->unk_14);
}

void func_8036A968_83E118(UnkSnowHerring* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_8036A5B8_83DD68(arg0, arg1, arg2, arg3, arg4, arg0->unk_4C, arg0->unk_4D, arg0->unk_4E, arg0->unk_4F);
}

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

u32 func_8036B988_83F138(UnkSnowHerring* arg0, s32 arg1) {
    u32 out;

    if (arg1) {
        out = (arg0->unk_48 << 24) | (arg0->unk_49 << 16) | (arg0->unk_4A << 8) | arg0->unk_4B;
    } else {
        out = (arg0->unk_4C << 24) | (arg0->unk_4D << 16) | (arg0->unk_4E << 8) | arg0->unk_4F;
    }

    return out;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036B9EC_83F19C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036BA50_83F200.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036C2FC_83FAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036C898_840048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036C9C0_840170.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CAE8_840298.s")

void func_8036CB10_8402C0(UnkSnowHerring* arg0, f32 arg1, f32 arg2) {
    if ((arg0 != NULL) && (arg0->unk_18 & 0x100)) {
        arg0->unk_50->data.sobj->sprite.scalex = arg1;
        arg0->unk_50->data.sobj->sprite.scaley = arg2;
        arg0->unk_6C = arg1;
        arg0->unk_70 = arg2;
    }
}

void func_8036CB58_840308(UnkSnowHerring* arg0, s32 arg1) {
    if (func_8036D344_840AF4(arg1)) {
        return;
    }

    if (arg0) {
        arg0->unk_114 = arg1;
    } else {
        D_8037EA84_852234 = arg1;
    }
}

void func_8036CBA0_840350(UnkSnowHerring* arg0, s32 arg1, s32 arg2) {
    if (!arg0) {
        return;
    }

    arg0->unk_0 = arg1;
    arg0->unk_4 = arg2;
    arg0->unk_64 = arg1 - arg0->unk_8;
    arg0->unk_66 = arg2 - arg0->unk_C;
    if (!(arg0->unk_18 & 0x40)) {
        arg0->unk_50->data.sobj->sprite.x = arg0->unk_64;
        arg0->unk_50->data.sobj->sprite.y = arg0->unk_66;
    }
}

void func_8036CBFC_8403AC(UnkSnowHerring* arg0, s32 arg1, s32 arg2) {
    if (!arg0) {
        return;
    }

    arg0->unk_2C = arg1;
    arg0->unk_30 = arg2;
    arg0->unk_A8 = arg1;
    arg0->unk_AA = arg2;
    if (arg0->unk_18 & 0x40) {
        arg0->unk_50->data.sobj->sprite.x = arg0->unk_A8;
        arg0->unk_50->data.sobj->sprite.y = arg0->unk_AA;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CC48_8403F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CCEC_84049C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036CDAC_84055C.s")

UnkSnowHerring* func_8036D018_8407C8(void) {
    return D_8037EA8C_85223C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D024_8407D4.s")

void func_8036D040_8407F0(UnkSnowHerring* arg0) {
    GObj* gobj;

    if ((D_8037EA8C_85223C != NULL) && (arg0 != D_8037EA8C_85223C) && (arg0 != NULL)) {
        gobj = arg0->unk_50;
        omMoveGObjDL(gobj, gobj->dlLink, gobj->dlPriority);
        func_8036A53C_83DCEC(arg0);
        func_8036A4AC_83DC5C(arg0);
    }
}

void func_8036D09C_84084C(UnkSnowHerring* arg0) {
    GObj* temp_a0;

    if ((D_8037EA8C_85223C != NULL) && (arg0 != D_8037EA8C_85223C) && (arg0 != NULL)) {
        temp_a0 = arg0->unk_50;
        omMoveGObjDLHead(temp_a0, temp_a0->dlLink, temp_a0->dlPriority);
        func_8036A53C_83DCEC(arg0);
        func_8036A4F4_83DCA4(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D0F8_8408A8.s")

void func_8036D1A4_840954(UnkSnowHerring* arg0, s32 arg1) {
    if (!arg0) {
        return;
    }

    func_8036EFEC_84279C(arg1, arg0->unk_0, arg0->unk_4, arg0->unk_0 + arg0->unk_10, arg0->unk_4 + arg0->unk_14);

    if (arg1) {
        arg0->unk_50->data.sobj->sprite.attr |= 4;
    } else {
        arg0->unk_50->data.sobj->sprite.attr &= 0xFFFB;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D22C_8409DC.s")

void func_8036D248_8409F8(UnkSnowHerring* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 != NULL) {
        arg0->unk_50->data.sobj->sprite.red = arg1;
        arg0->unk_50->data.sobj->sprite.green = arg2;
        arg0->unk_50->data.sobj->sprite.blue = arg3;
        arg0->unk_50->data.sobj->sprite.alpha = arg4;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/unk_end_level/83DC30/func_8036D28C_840A3C.s")
