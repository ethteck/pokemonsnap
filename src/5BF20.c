#include "common.h"

// sizeof: 0x3A0?
typedef struct Unk_D_800C21B0_5F050 {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
    char unk_10[4];
    u8 pad_14[0x1C];
    u32 unk_30;
    s32 unk_34;
    u8 pad_38[0x18];
    s32 unk_50;
    char playerName[0x10];
    u32 unk_64_29 : 3;
    u32 unk_64_22 : 7;
    u32 unk_64_16 : 6;
    u32 unk_64_15 : 1;
    u32 unk_64_14 : 1;
    u32 unk_64_13 : 1;
    u32 unk_64_06 : 7;
    u32 unk_64_00 : 6;
    u8 pad_68[0x4];
    s32 unk_6C ;
    u8 pad_70[0x110];
    s32* unk_180;
    s32 unk_184;
    u8 pad_188[0x216];
} Unk_D_800C21B0_5F050;

Unk_D_800C21B0_5F050* func_800C16EC_5E58C(char*, s32);
s32 func_800C09C0_5D860(Unk_D_800C21B0_5F050* arg0, s32 arg1);
void func_800C06A8_5D548(Unk_D_800C21B0_5F050*, s32);
void func_800C0AB4_5D954(Unk_D_800C21B0_5F050*, s32);

extern Unk_D_800C21B0_5F050* D_800C21B0_5F050;
extern char D_800C20E0_5EF80[16]; // HAL_SNAP_V1.0-1 in EUC-JP encoding
extern s32 D_800C20F0_5EF90;    // s32 D_800C20F0_5EF90 = 0;
extern Unk_D_800C21B0_5F050* D_800C21B8_5F058[];  // Likely wrong type, but so far it's only being used in one place and it works for now.
extern u8 D_800E14FC_7E39C[4];
extern s32 D_800E1500_7E3A0;
extern s32 D_800E1504_7E3A4;
extern s32 D_800E1508_7E3A8;

Unk_D_800C21B0_5F050* func_800BF080_5BF20(void) {
    return D_800C21B0_5F050;
}

s32 func_800BF08C_5BF2C(void) {
    Unk_D_800C21B0_5F050* temp_v0;

    temp_v0 = func_800C16EC_5E58C(D_800C21B0_5F050->unk_10, 0x1F294);
    if (temp_v0->unk_0 != D_800C21B0_5F050->unk_0 || temp_v0->unk_4 != D_800C21B0_5F050->unk_4 ||
        temp_v0->unk_8 != D_800C21B0_5F050->unk_8 || temp_v0->unk_C != D_800C21B0_5F050->unk_C) {
        return 1;
    } else {
        return 0;
    }
}

void func_800BF10C_5BFAC(void) {
    Unk_D_800C21B0_5F050* temp_v0;

    temp_v0 = func_800C16EC_5E58C(D_800C21B0_5F050->unk_10, 0x1F294);
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
    comparisonStringBytes = D_800C21B0_5F050->unk_10;
    i = 0;
    while (1) {
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
    copyToBytes = D_800C21B0_5F050->unk_10;
    for (i = 0; i < sizeof(D_800C20E0_5EF80); i++) {
        *copyToBytes = *versionStringBytes;
        versionStringBytes++;
        copyToBytes++;
    }
}

s32 func_800BF244_5C0E4(void) {
    Unk_D_800C21B0_5F050* sp24;

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
    D_800C21B0_5F050->unk_30 = osGetTime();
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
    Unk_D_800C21B0_5F050* arg0 = D_800C21B0_5F050;
    func_800C06A8_5D548(arg0, 0x1F2A4);
}

void func_800BF3A8_5C248(void) {
    Unk_D_800C21B0_5F050* arg0 = D_800C21B0_5F050;
    func_800C0AB4_5D954(arg0, 0x1F2A4);
}

#ifdef NON_EQUIVALENT
s32 func_800BF3D4_5C274(s32 arg0) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_8009BB4C(arg0);
    if ((temp_v0 < 0) || (temp_v0 >= 69)) {
        return 0;
    }
    var_v1 = (D_800C21B0_5F050[temp_v0].unk184 == -1) ? 0 : D_800C21B0_5F050[temp_v0].unk180;
    return var_v1 != 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF3D4_5C274.s")
#endif

void func_800BF444_5C2E4(s32 arg0) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF44C_5C2EC.s")

char* get_player_name(void) {
    return D_800C21B0_5F050->playerName;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF4A8_5C348.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF534_5C3D4.s")

#ifdef NON_EQUIVALENT
void* func_800BF574_5C414(s32 arg0) {
    Unk_D_800C21B0_5F050* temp_v0;
    void* var_v1;

    if ((arg0 < 0) || (arg0 >= 4)) {
        return NULL;
    }
    temp_v0 = &D_800C21B0_5F050[arg0];
    if ((s32) (temp_v0 + 68) == -1) {
        var_v1 = NULL;
    } else {
        var_v1 = temp_v0 + 69;
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF574_5C414.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF5D8_5C478.s")

#ifdef NON_EQUIVALENT
void func_800BF650_5C4F0(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 4)) {
        D_800C21B0_5F050[arg0].unk184 = -1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF650_5C4F0.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF690_5C530.s")

#ifdef NON_EQUIVALENT
s32* func_800BF710_5C5B0(s32 arg0) {
    Unk_D_800C21B0_5F050* temp_a0;
    s32 temp_v0;
    s32* var_v1;

    temp_v0 = func_8009BB4C(arg0);
    if ((temp_v0 < 0) || (temp_v0 >= 69)) {
        return NULL;
    }
    temp_a0 = &D_800C21B0_5F050[temp_v0];
    var_v1 = (temp_a0->unk184 == -1) ? NULL : &temp_a0->unk180;
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF710_5C5B0.s")
#endif

void func_800BF780_5C620(s32 arg0) {
    s32 temp_v0;

    temp_v0 = func_8009BB4C(arg0);
    if (temp_v0 >= 0 && temp_v0 < 69) {
        D_800C21B0_5F050[temp_v0].unk_184 = -1;
    }
}

#ifdef NON_EQUIVALENT
void func_800BF7D4_5C674(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8009BB4C(arg0);
    if (temp_v0 >= 0 && temp_v0 < 69) {
        D_800C21B0_5F050[temp_v0].unk6C = arg1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF7D4_5C674.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF818_5C6B8.s")

s32 func_800BF864_5C704(void) {
    s32 i;
    s32 var_s1;

    var_s1 = 0;

    for (i = 1; i < 152; i++) {
        if (func_800BF3D4_5C274(i)) {
            var_s1++;
        }
    }

    return var_s1;
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
                sp28 = &D_800C21B0_5F050[func_8009BB4C()].unk180;
                break;
            }
        }
    }
    return sp28;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF8BC_5C75C.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF954_5C7F4.s")

s32 func_800BF9EC_5C88C(void) {
    return 60;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BF9F4_5C894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BFA44_5C8E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BFABC_5C95C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BFB50_5C9F0.s")

s32 func_800BFB84_5CA24(void) {
    return D_800C20F0_5EF90;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BFB90_5CA30.s")

void func_800BFC18_5CAB8(s32* arg0, s32* arg1) {
    if (arg0 != NULL) {
        *arg0 = D_800C21B0_5F050->unk_64_22 - 76;
    }
    if (arg1 != NULL) {
        *arg1 = D_800C21B0_5F050->unk_64_16 - 36;
    }
}

s32 func_800BFC5C_5CAFC(void) {
    return D_800C21B0_5F050->unk_64_29;
}

void func_800BFC70_5CB10(s32 arg0) {
    if (arg0 >= 0 && arg0 < 7) {
        D_800C21B0_5F050->unk_64_29 = arg0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BFCA0_5CB40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800BFEBC_5CD5C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800C0224_5D0C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800C0254_5D0F4.s")

s32 func_800C027C_5D11C(void) {
    s32 temp_v0;

    temp_v0 = D_800E1500_7E3A0;
    D_800E1500_7E3A0 = 0;
    return temp_v0;
}

s32 func_800C0290_5D130(void) {
    return D_800C21B0_5F050->unk_50;
}

void func_800C02A0_5D140(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 > 6) {
        arg0 = 6;
    }
    D_800C21B0_5F050->unk_50 = arg0;
    if (D_800C21B0_5F050->unk_64_29 < arg0) {
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
        if (temp_v0 && !D_800C21B0_5F050->unk_64_15) {
            D_800E1500_7E3A0 = 1;
        }
        break;
    case 1:
        if (temp_v0 && !D_800C21B0_5F050->unk_64_14) {
            D_800E1500_7E3A0 = 1;
        }
        break;
    case 2:
        if (temp_v0 && !D_800C21B0_5F050->unk_64_13) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/5BF20/func_800C042C_5D2CC.s")

s32 func_800C05D4_5D474(void) {
    s32 temp_v0;

    D_800C21B0_5F050 = (Unk_D_800C21B0_5F050* ) ((s32) (&D_800C21B8_5F058) + 0xF & ~0xF);
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
