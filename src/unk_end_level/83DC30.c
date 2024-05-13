#include "common.h"
#include "unk_end_level.h"

struct UnkSnowHerring {
    /*   0x0 */ s32 unk_0;
    /*   0x4 */ s32 unk_4;
    /*   0x8 */ s32 unk_8;
    /*   0xC */ s32 unk_C;
    /*  0x10 */ s32 unk_10;
    /*  0x14 */ s32 unk_14;
    /*  0x18 */ u32 unk_18;
    /*  0x1C */ u8 pad_1C[0x2C - 0x1C];
    /*  0x2C */ s32 unk_2C;
    /*  0x30 */ s32 unk_30;
    /*  0x34 */ s32 unk_34;
    /*  0x38 */ s32 unk_38;
    /*  0x3C */ UnkSnowHerring* unk_3C;
    /*  0x40 */ UnkSnowHerring* unk_40;
    /*  0x44 */ u8 pad_44[4];
    /*  0x4C */ u8 unk_48;
    /*  0x4D */ u8 unk_49;
    /*  0x4E */ u8 unk_4A;
    /*  0x4F */ u8 unk_4B;
    /*  0x4C */ u8 unk_4C;
    /*  0x4D */ u8 unk_4D;
    /*  0x4E */ u8 unk_4E;
    /*  0x4F */ u8 unk_4F;
    /*  0x50 */ GObj* unk_50;
    /*  0x54 */ u8 pad_54[0x64 - 0x54];
    /*  0x64 */ Sprite unk_64;
    /*  0xA8 */ Sprite unk_A8;
    /*  0xEC */ char unk_EC[0x114 - 0xEC];
    /* 0x114 */ s32 unk_114;
    /* 0x118 */ s32 unk_118;
    /* 0x11C */ u8 pad_11C[4];
    /* 0x120 */ s32 unk_120;
    /* 0x124 */ s32 unk_124;
    /* 0x128 */ u8 pad_128[8];
}; // size == 0x130

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

void func_8036CB10_8402C0(UnkSnowHerring* arg0, f32 scalex, f32 scaley) {
    if ((arg0 != NULL) && (arg0->unk_18 & 0x100)) {
        arg0->unk_50->data.sobj->sprite.scalex = scalex;
        arg0->unk_50->data.sobj->sprite.scaley = scaley;
        arg0->unk_64.scalex = scalex;
        arg0->unk_64.scaley = scaley;
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
    arg0->unk_64.x = arg1 - arg0->unk_8;
    arg0->unk_64.y = arg2 - arg0->unk_C;
    if (!(arg0->unk_18 & 0x40)) {
        arg0->unk_50->data.sobj->sprite.x = arg0->unk_64.x;
        arg0->unk_50->data.sobj->sprite.y = arg0->unk_64.y;
    }
}

void func_8036CBFC_8403AC(UnkSnowHerring* arg0, s32 x, s32 y) {
    if (!arg0) {
        return;
    }

    arg0->unk_2C = x;
    arg0->unk_30 = y;
    arg0->unk_A8.x = x;
    arg0->unk_A8.y = y;
    if (arg0->unk_18 & 0x40) {
        arg0->unk_50->data.sobj->sprite.x = arg0->unk_A8.x;
        arg0->unk_50->data.sobj->sprite.y = arg0->unk_A8.y;
    }
}

void func_8036CC48_8403F8(UnkSnowHerring* arg0, Sprite* arg1) {
    if (arg0 != NULL && arg1 != NULL) {
        arg0->unk_34 = arg1->width;
        arg0->unk_38 = arg1->height;

        arg0->unk_A8 = *arg1;

        arg0->unk_A8.x = arg0->unk_2C;
        arg0->unk_A8.y = arg0->unk_30;

        if (arg0->unk_18 & 0x40) {
            arg0->unk_50->data.sobj->sprite.x = arg0->unk_A8.x;
            arg0->unk_50->data.sobj->sprite.y = arg0->unk_A8.y;
        }
    }
}

void func_8036CCEC_84049C(UnkSnowHerring* arg0, s32 arg1) {
    if (arg0 != NULL) {
        if (arg1 != 0) {
            arg0->unk_50->data.sobj->sprite = arg0->unk_A8;
            arg0->unk_18 |= 0x40;
        } else {
            arg0->unk_50->data.sobj->sprite = arg0->unk_64;
            arg0->unk_18 &= ~0x40;
        }
    }
}

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

UnkSnowHerring* func_8036D0F8_8408A8(s32 arg0, s32 arg1, char* arg2, s32 arg3, s32 arg4) {
    UnkSnowHerring* temp_v0;
    s32 temp_s0;

    func_8036D344_840AF4(arg3);
    temp_s0 = func_8036D4F0_840CA0(arg2);
    // TODO: look into a "ceil to multiple of" macro
    temp_v0 = func_8036AC6C_83E41C(arg0, arg1, (temp_s0 + 1 + 0xF) & ~0xF, ((func_8036D758_840F08() + 1) & ~1) + 4, arg4);
    func_8036CB58_840308(temp_v0, arg3);
    func_8036B734_83EEE4(temp_v0);
    func_8036B9EC_83F19C(temp_v0, 0, 0);
    func_8036C898_840048(temp_v0, arg2);

    return temp_v0;
}

void func_8036D1A4_840954(UnkSnowHerring* arg0, s32 arg1) {
    if (!arg0) {
        return;
    }

    func_8036EFEC_84279C(arg1, arg0->unk_0, arg0->unk_4, arg0->unk_0 + arg0->unk_10, arg0->unk_4 + arg0->unk_14);

    if (arg1) {
        arg0->unk_50->data.sobj->sprite.attr |= SP_HIDDEN;
    } else {
        arg0->unk_50->data.sobj->sprite.attr &= ~SP_HIDDEN;
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
