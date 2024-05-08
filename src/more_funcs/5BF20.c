#include "common.h"

typedef struct UnkTinyGrandma {
    /* 0x000 */ PhotoData unk_0;
    /* 0x3A0 */ s16 unk_3A0;
    /* 0x3A2 */ u8 pad_3A4[0x40 - 2];
} UnkTinyGrandma; // size: 0x3E0

typedef struct UnkBigBoy {
    /* 0x000 */ s32 unk_0;
    /* 0x004 */ s32 unk_4;
    /* 0x008 */ s32 unk_8;
    /* 0x00C */ s32 unk_C;
    struct {
        /* 0x010 */ char unk_10[4];
        /* 0x014 */ u8 pad_14[0x1C];
        /* 0x030 */ u32 unk_30;
        /* 0x034 */ s32 unk_34[7];
        /* 0x050 */ s32 unk_50;
        /* 0x054 */ PlayerName playerName;
        /* 0x064 */ u32 unk_64_29 : 3;
        /* ----- */ u32 unk_64_22 : 7;
        /* ----- */ u32 unk_64_16 : 6;
        /* 0x066 */ u32 unk_64_15 : 1;
        /* ----- */ u32 unk_64_14 : 1;
        /* ----- */ u32 unk_64_13 : 1;
        /* ----- */ u32 unk_64_12 : 1;
        /* ----- */ u32 unk_64_11 : 1;
        /* ----- */ u32 unk_64_10 : 1;
        /* ----- */ u32 unk_64_09 : 1;
        /* ----- */ u32 unk_64_08 : 1;
        /* 0x067 */ u32 unk_64_07 : 1;
        /* ----- */ u32 unk_64_06 : 1;
        /* ----- */ u32 unk_64_05 : 1;
        /* ----- */ u32 unk_64_04 : 1;
        /* ----- */ u32 unk_64_03 : 1;
        /* ----- */ u32 unk_64_02 : 1;
        /* ----- */ u32 unk_64_01 : 1;
        /* ----- */ u32 unk_64_00 : 1;
        /* 0x068 */ u32 unk_68_31 : 1;
        /* ----- */ u32 unk_68_30 : 1;
        /* ----- */ u32 unk_68_29 : 1;
        /* ----- */ u32 unk_68_28 : 1;
        /* ----- */ u32 unk_68_27 : 1;
        /* ----- */ u32 unk_68_26 : 27;
        /* 0x06C */ s32 unk_6C[69];
        /* 0x180 */ PhotoData unk_180[69];
        /* 0xFBA0 */ PhotoData unk_FBA0[4];
        /* 0x10A20 */ UnkTinyGrandma var_10A20[60];
        /* 0x1f2a0 */ u8 pad_1F2A0[4];
    } data;
} UnkBigBoy; // size = 0x10 + 0x1F294

typedef struct Unk800E1510 {
    s64 unk_00;
} Unk800E1510;

UnkBigBoy* func_800C16EC_5E58C(void*, s32);
s32 func_800C09C0_5D860(UnkBigBoy* arg0, s32 arg1);
void func_800C06A8_5D548(UnkBigBoy*, s32);
void func_800C0AB4_5D954(UnkBigBoy*, s32);

extern char D_800C20E0_5EF80[16]; // HAL_SNAP_V1.0-1 in EUC-JP encoding
extern s32 D_800C20F0_5EF90;      // s32 D_800C20F0_5EF90 = 0;
extern u32 D_800C20F4_5EF94;
extern UnkBigBoy* D_800C21B0_5F050;
extern UnkBigBoy* D_800C21B8_5F058[]; // Likely wrong type, but so far it's only being used in one place and it works for now.
extern u8 D_800E14FC_7E39C[4];
extern s32 D_800E1500_7E3A0;
extern s32 D_800E1504_7E3A4;
extern s32 D_800E1508_7E3A8;
extern Unk800E1510 D_800E1510_7E3B0[];

UnkBigBoy* func_800BF080_5BF20(void) {
    return D_800C21B0_5F050;
}

s32 func_800BF08C_5BF2C(void) {
    UnkBigBoy* temp_v0 = func_800C16EC_5E58C(&D_800C21B0_5F050->data, sizeof(D_800C21B0_5F050->data));

    if (temp_v0->unk_0 != D_800C21B0_5F050->unk_0 || temp_v0->unk_4 != D_800C21B0_5F050->unk_4 ||
        temp_v0->unk_8 != D_800C21B0_5F050->unk_8 || temp_v0->unk_C != D_800C21B0_5F050->unk_C) {
        return 1;
    } else {
        return 0;
    }
}

void func_800BF10C_5BFAC(void) {
    UnkBigBoy* temp_v0 = func_800C16EC_5E58C(&D_800C21B0_5F050->data, sizeof(D_800C21B0_5F050->data));

    D_800C21B0_5F050->unk_0 = temp_v0->unk_0;
    D_800C21B0_5F050->unk_4 = temp_v0->unk_4;
    D_800C21B0_5F050->unk_8 = temp_v0->unk_8;
    D_800C21B0_5F050->unk_C = temp_v0->unk_C;
}

s32 func_800BF178_5C018(void) {
    s32 i;
    u8* versionStringBytes;
    u8* comparisonStringBytes;

    versionStringBytes = D_800C20E0_5EF80;
    comparisonStringBytes = D_800C21B0_5F050->data.unk_10;
    i = 0;
    while (TRUE) {
        if (*versionStringBytes != *comparisonStringBytes) {
            return TRUE;
        }
        versionStringBytes++;
        comparisonStringBytes++;
        i++;
        if (i == sizeof(D_800C20E0_5EF80)) {
            if (func_800BF08C_5BF2C() != 0) {
                return TRUE;
            }
            return FALSE;
        }
    }
}

void func_800BF1F0_5C090(void) {
    s32 i;
    u8* versionStringBytes;
    u8* copyToBytes;

    versionStringBytes = D_800C20E0_5EF80;
    copyToBytes = D_800C21B0_5F050->data.unk_10;
    for (i = 0; i < sizeof(D_800C20E0_5EF80); i++) {
        *copyToBytes = *versionStringBytes;
        versionStringBytes++;
        copyToBytes++;
    }
}

s32 func_800BF244_5C0E4(void) {
    UnkBigBoy* sp24;

    if (contIsPrinterAvailable()) {
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
        contPrinterSendCommand(0xCC);
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
    }
    sp24 = D_800C21B0_5F050;
    D_800C21B0_5F050->data.unk_30 = osGetTime();
    func_800BF10C_5BFAC();
    if (func_800C09C0_5D860(sp24, 0x1F2A4) != 0) {
        return 1;
    }
    if (contIsPrinterAvailable()) {
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
        contPrinterSendCommand(0x33);
        while (contPrinterGetStatus() == 8) {
            ohWait(1);
        }
    }
    return 0;
}

void func_800BF37C_5C21C(void) {
    UnkBigBoy* arg0 = D_800C21B0_5F050;
    func_800C06A8_5D548(arg0, sizeof(UnkBigBoy));
}

void func_800BF3A8_5C248(void) {
    UnkBigBoy* arg0 = D_800C21B0_5F050;
    func_800C0AB4_5D954(arg0, sizeof(UnkBigBoy));
}

s32 func_800BF3D4_5C274(s32 arg0) {
    s32 temp_v0;
    PhotoData* var_v1;

    temp_v0 = func_8009BB4C(arg0);
    if ((temp_v0 < 0) || (temp_v0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_180))) {
        return 0;
    }
    var_v1 = (D_800C21B0_5F050->data.unk_180[temp_v0].unk_04.s32 == -1) ? 0 : &D_800C21B0_5F050->data.unk_180[temp_v0];
    return var_v1 != 0;
}

void func_800BF444_5C2E4(s32 arg0) {
}

void func_800BF44C_5C2EC(PlayerName* arg0) {
    D_800C21B0_5F050->data.playerName = *arg0;
}

char* get_player_name(void) {
    return D_800C21B0_5F050->data.playerName.data;
}

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800BF4A8_5C348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800BF534_5C3D4.s")

PhotoData* func_800BF574_5C414(s32 arg0) {
    PhotoData* ret;

    if ((arg0 < 0) || (arg0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_FBA0))) {
        return NULL;
    }

    if (D_800C21B0_5F050->data.unk_FBA0[arg0].unk_04.s32 == -1) {
        ret = NULL;
    } else {
        ret = &D_800C21B0_5F050->data.unk_FBA0[arg0];
    }

    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800BF5D8_5C478.s")

void func_800BF650_5C4F0(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_FBA0)) {
        return;
    }

    D_800C21B0_5F050->data.unk_FBA0[arg0].unk_04.s32 = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800BF690_5C530.s")

PhotoData* func_800BF710_5C5B0(s32 arg0) {
    s32 index;
    PhotoData* ret;

    index = func_8009BB4C(arg0);
    if ((index < 0) || (index >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_180))) {
        return NULL;
    }

    if (D_800C21B0_5F050->data.unk_180[index].unk_04.s32 == -1) {
        ret = NULL;
    } else {
        ret = &D_800C21B0_5F050->data.unk_180[index];
    }
    return ret;
}

void func_800BF780_5C620(s32 arg0) {
    s32 temp_v0 = func_8009BB4C(arg0);

    if (temp_v0 < 0 || temp_v0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_180)) {
        return;
    }

    D_800C21B0_5F050->data.unk_180[temp_v0].unk_04.s32 = -1;
}

void func_800BF7D4_5C674(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8009BB4C(arg0);
    if (temp_v0 >= 0 && temp_v0 < ARRAY_COUNT(D_800C21B0_5F050->data.unk_6C)) {
        D_800C21B0_5F050->data.unk_6C[temp_v0] = arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800BF818_5C6B8.s")
// s32 func_800BF818_5C6B8(s32 arg0) {
//     s32 temp_v0 = func_8009BB4C(arg0);

//     if (temp_v0 < 0 || temp_v0 >= 69) {
//         return 0;
//     }
//     return D_800C21B0_5F050->unk_6C[temp_v0];
// }

s32 func_800BF864_5C704(void) {
    s32 i;
    s32 ret = 0;

    for (i = 1; i < 152; i++) {
        if (func_800BF3D4_5C274(i)) {
            ret++;
        }
    }

    return ret;
}

#ifdef NON_EQUIVALENT
s32** func_800BF8BC_5C75C(s32 arg0) {
    s32 temp;
    s32** sp28;
    s32 i;

    sp28 = NULL;
    for (i = 1; i < 152; i++) {
        if (func_800BF3D4_5C274(i)) {
            temp = arg0;
            arg0--;
            if (temp == 0) {
                sp28 = &D_800C21B0_5F050[func_8009BB4C()].unk_180;
                break;
            }
        }
    }
    return sp28;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800BF8BC_5C75C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800BF954_5C7F4.s")

s32 func_800BF9EC_5C88C(void) {
    return 60;
}

void func_800BF9F4_5C894(s32 arg0) {

    if (arg0 < 0 || arg0 >= 60) {
        return;
    }

    D_800C21B0_5F050->data.var_10A20[arg0].unk_0.unk_04.s32 = -1;
    D_800C21B0_5F050->data.var_10A20[arg0].unk_3A0 = 0;
}

PhotoData* func_800BFA44_5C8E4(s32 arg0) {
    UnkTinyGrandma* ret;
    if ((arg0 < 0) || (arg0 >= 0x3C)) {
        return NULL;
    }

    if (D_800C21B0_5F050->data.var_10A20[arg0].unk_0.unk_04.s32 == -1) {
        ret = NULL;
    } else {
        ret = &D_800C21B0_5F050->data.var_10A20[arg0];
    }

    if (ret) {
        // TODO: Determine if we only need to return the substruct
        return &D_800C21B0_5F050->data.var_10A20[arg0].unk_0;
    }

    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800BFABC_5C95C.s")

void* func_800BFB50_5C9F0(s32 arg0) {
    if (arg0 < 0 || arg0 >= D_800C20F0_5EF90) {
        return NULL;
    }
    return &D_800E1510_7E3B0[arg0];
}

s32 func_800BFB84_5CA24(void) {
    return D_800C20F0_5EF90;
}

void func_800BFB90_5CA30(s32 arg0, s32 arg1) {
    if (arg0 < -0x4C) {
        arg0 = -0x4C;
    } else if (arg0 > 0x18) {
        arg0 = 0x18;
    }
    if (arg1 < -0x24) {
        arg1 = -0x24;
    } else if (arg1 > 0xE) {
        arg1 = 0xE;
    }

    D_800C21B0_5F050->data.unk_64_22 = arg0 + 0x4C;
    D_800C21B0_5F050->data.unk_64_16 = arg1 + 0x24;
}

void func_800BFC18_5CAB8(s32* arg0, s32* arg1) {
    if (arg0 != NULL) {
        *arg0 = D_800C21B0_5F050->data.unk_64_22 - 76;
    }
    if (arg1 != NULL) {
        *arg1 = D_800C21B0_5F050->data.unk_64_16 - 36;
    }
}

s32 func_800BFC5C_5CAFC(void) {
    return D_800C21B0_5F050->data.unk_64_29;
}

void func_800BFC70_5CB10(s32 arg0) {
    if (arg0 >= 0 && arg0 < 7) {
        D_800C21B0_5F050->data.unk_64_29 = arg0;
    }
}

s32 func_800BFCA0_5CB40(s32 arg0) {
    switch (arg0) {
        case 0:
            return D_800C21B0_5F050->data.unk_64_15;
        case 1:
            return D_800C21B0_5F050->data.unk_64_14;
        case 2:
            return D_800C21B0_5F050->data.unk_64_13;
        case 3:
            return D_800C21B0_5F050->data.unk_64_12;
        case 4:
            return D_800C21B0_5F050->data.unk_64_11;
        case 5:
            return D_800C21B0_5F050->data.unk_64_10;
        case 6:
            return D_800C21B0_5F050->data.unk_64_09;
        case 7:
            return D_800C21B0_5F050->data.unk_64_08;
        case 8:
            return D_800C21B0_5F050->data.unk_64_07;
        case 9:
            return D_800C21B0_5F050->data.unk_64_06;
        case 10:
            return D_800C21B0_5F050->data.unk_64_05;
        case 11:
            return D_800C21B0_5F050->data.unk_64_03;
        case 12:
            return D_800C21B0_5F050->data.unk_64_02;
        case 13:
            return D_800C21B0_5F050->data.unk_64_01;
        case 14:
            return D_800C21B0_5F050->data.unk_64_00;
        case 16:
            return D_800C21B0_5F050->data.unk_68_31;
        case 17:
            return D_800C21B0_5F050->data.unk_68_30;
        case 18:
            return D_800C21B0_5F050->data.unk_68_29;
        case 19:
            return D_800C21B0_5F050->data.unk_68_28;
        case 20:
            return D_800C21B0_5F050->data.unk_68_27;
        case 21:
            return D_800C21B0_5F050->data.unk_64_04;
        case 15:
            return D_800C20F4_5EF94;
    }

    return 0;
}

void func_800BFEBC_5CD5C(s32 arg0, s32 arg1) {
    switch (arg0) {
        case 0:
            D_800C21B0_5F050->data.unk_64_15 = arg1 != 0;
            break;
        case 1:
            D_800C21B0_5F050->data.unk_64_14 = arg1 != 0;
            break;
        case 2:
            D_800C21B0_5F050->data.unk_64_13 = arg1 != 0;
            break;
        case 3:
            D_800C21B0_5F050->data.unk_64_12 = arg1 != 0;
            break;
        case 4:
            D_800C21B0_5F050->data.unk_64_11 = arg1 != 0;
            break;
        case 5:
            D_800C21B0_5F050->data.unk_64_10 = arg1 != 0;
            break;
        case 6:
            D_800C21B0_5F050->data.unk_64_09 = arg1 != 0;
            break;
        case 7:
            D_800C21B0_5F050->data.unk_64_08 = arg1 != 0;
            break;
        case 8:
            D_800C21B0_5F050->data.unk_64_07 = arg1 != 0;
            break;
        case 9:
            D_800C21B0_5F050->data.unk_64_06 = arg1 != 0;
            break;
        case 10:
            D_800C21B0_5F050->data.unk_64_05 = arg1 != 0;
            break;
        case 11:
            D_800C21B0_5F050->data.unk_64_03 = arg1 != 0;
            break;
        case 12:
            D_800C21B0_5F050->data.unk_64_02 = arg1 != 0;
            break;
        case 13:
            D_800C21B0_5F050->data.unk_64_01 = arg1 != 0;
            break;
        case 14:
            D_800C21B0_5F050->data.unk_64_00 = arg1 != 0;
            break;
        case 16:
            D_800C21B0_5F050->data.unk_68_31 = arg1 != 0;
            break;
        case 17:
            D_800C21B0_5F050->data.unk_68_30 = arg1 != 0;
            break;
        case 18:
            D_800C21B0_5F050->data.unk_68_29 = arg1 != 0;
            break;
        case 19:
            D_800C21B0_5F050->data.unk_68_28 = arg1 != 0;
            break;
        case 20:
            D_800C21B0_5F050->data.unk_68_27 = arg1 != 0;
            break;
        case 21:
            D_800C21B0_5F050->data.unk_64_04 = arg1 != 0;
            break;
        case 15:
            D_800C20F4_5EF94 = arg1 != 0;
            break;
    }
}

s32 func_800C0224_5D0C4(s32 arg0) {
    if (arg0 < 0 || arg0 >= ARRAY_COUNT(D_800C21B0_5F050->data.unk_34)) {
        return 0;
    }
    return D_800C21B0_5F050->data.unk_34[arg0];
}

void func_800C0254_5D0F4(s32 arg0, s32 arg1) {
    if (arg0 >= 0 && arg0 < ARRAY_COUNT(D_800C21B0_5F050->data.unk_34)) {
        D_800C21B0_5F050->data.unk_34[arg0] = arg1;
    }
}

s32 func_800C027C_5D11C(void) {
    s32 prev = D_800E1500_7E3A0;

    D_800E1500_7E3A0 = 0;
    return prev;
}

s32 func_800C0290_5D130(void) {
    return D_800C21B0_5F050->data.unk_50;
}

void func_800C02A0_5D140(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 6) {
        arg0 = 6;
    }
    D_800C21B0_5F050->data.unk_50 = arg0;
    if (D_800C21B0_5F050->data.unk_64_29 < arg0) {
        D_800E1500_7E3A0 = 1;
    }
}

u8 func_800C02EC_5D18C(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 2U) {
        arg0 = 2;
    }
    return D_800E14FC_7E39C[arg0];
}

void func_800C0314_5D1B4(s32 arg0, s32 arg1) {
    s32 temp_v0;

    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 2U) {
        arg0 = 2;
    }

    temp_v0 = !!arg1;
    D_800E14FC_7E39C[arg0] = temp_v0;

    switch (arg0) {
        case 0:
            if (temp_v0 && !D_800C21B0_5F050->data.unk_64_15) {
                D_800E1500_7E3A0 = 1;
            }
            break;
        case 1:
            if (temp_v0 && !D_800C21B0_5F050->data.unk_64_14) {
                D_800E1500_7E3A0 = 1;
            }
            break;
        case 2:
            if (temp_v0 && !D_800C21B0_5F050->data.unk_64_13) {
                D_800E1500_7E3A0 = 1;
            }
            break;
    }
}

s32 func_800C03D4_5D274(void) {
    if (D_800E1504_7E3A4 == 0) {
        return 0;
    }
    D_800E1504_7E3A4 = 0;
    return 1;
}

s32 func_800C0400_5D2A0(void) {
    if (D_800E1508_7E3A8 == 0) {
        return 0;
    }
    D_800E1508_7E3A8 = 0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/more_funcs/5BF20/func_800C042C_5D2CC.s")

s32 func_800C05D4_5D474(void) {
    s32 temp_v0;

    // Align to a multiple of 16
    D_800C21B0_5F050 = (UnkBigBoy*) ((s32) (&D_800C21B8_5F058) + 0xF & ~0xF);

    func_800C0B48_5D9E8();
    func_800BF37C_5C21C();
    temp_v0 = func_800BF178_5C018();
    if (temp_v0 != 0) {
        if (func_800C042C_5D2CC() != 0) {
            return 1;
        } else {
            D_800E1504_7E3A4 = 1;
            D_800E1508_7E3A8 = 1;
        }
        return 1;
    } else {
        D_800E1504_7E3A4 = 0;
        D_800E1508_7E3A8 = 0;
    }

//! @bug This doesn't guarantee a return. In practice, the return value isn't actually checked though.
#ifdef AVOID_UB
    return 0;
#endif
}
